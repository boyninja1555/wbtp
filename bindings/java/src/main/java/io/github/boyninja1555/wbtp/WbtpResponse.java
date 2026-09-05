package io.github.boyninja1555.wbtp;

import io.github.boyninja1555.wbtp.typing.WbtpResponseData;
import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/**
 * Object-oriented instance-based wrapper for WbtpRequests.
 */
public class WbtpResponse {
    private final WbtpResponseData data;

    /**
     * Underlying response data.
     *
     * @return Mutable underlying response data
     */
    public WbtpResponseData _data() {
        return this.data;
    }

    public WbtpResponse(byte type, byte[] payload) {
        this.data = new WbtpResponseData();
        setType(type);
        WbtpResponses.setPayload(this.data, payload);
    }

    public WbtpResponse(byte type, @NotNull String payload) {
        this.data = new WbtpResponseData();
        setType(type);
        WbtpResponses.setPayloadString(this.data, payload);
    }

    /**
     * Returns type of response.
     *
     * @return Type of response
     */
    public byte getType() {
        return this.data.type;
    }

    /**
     * Sets type of response.
     *
     * @param type Type of response
     */
    public @Contract(mutates = "this") WbtpResponse setType(byte type) {
        this.data.type = type;
        return this;
    }

    /**
     * Returns response params.
     *
     * @return Response params
     */
    public String getParams() {
        return new String(this.data.params);
    }

    /**
     * Sets response params.
     *
     * @param params Response params
     */
    public @Contract(mutates = "this") WbtpResponse setParams(@NotNull String params) {
        WbtpResponses.setParams(this.data, params);
        return this;
    }

    /**
     * Returns response payload.
     *
     * @return Response payload
     */
    public byte[] getPayload() {
        return this.data.payload.clone();
    }

    /**
     * Clears response payload.
     */
    public @Contract(mutates = "this") WbtpResponse clearPayload() {
        WbtpResponses.clearPayload(this.data);
        return this;
    }

    /**
     * Copies and sets response payload directly.
     *
     * @param payload Response payload
     */
    public @Contract(mutates = "this") WbtpResponse setPayload(byte[] payload) {
        WbtpResponses.setPayload(this.data, payload);
        return this;
    }

    /**
     * Sets response payload to a string.
     *
     * @param payload Response payload (string)
     */
    public @Contract(mutates = "this") WbtpResponse setPayloadString(@NotNull String payload) {
        WbtpResponses.setPayloadString(this.data, payload);
        return this;
    }

    /**
     * Serializes this response to an output stream.
     *
     * @param out Output stream
     * @throws IOException When thrown, describes what went wrong during serialization
     */
    public void serialize(@NotNull OutputStream out) throws IOException {
        WbtpResponses.serialize(this.data, out);
    }

    /**
     * Deserializes an input stream into this response.
     *
     * @param in Input stream
     * @throws IOException When thrown, describes what went wrong during deserialization
     */
    public void deserialize(@NotNull InputStream in) throws IOException {
        WbtpResponses.deserialize(this.data, in);
    }
}
