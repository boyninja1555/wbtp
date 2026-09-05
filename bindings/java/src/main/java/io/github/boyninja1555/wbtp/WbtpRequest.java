package io.github.boyninja1555.wbtp;

import io.github.boyninja1555.wbtp.typing.WbtpRequestData;
import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

/**
 * Object-oriented instance-based wrapper for WbtpRequests.
 */
public class WbtpRequest {
    private final WbtpRequestData data;

    /**
     * Underlying request data.
     *
     * @return Mutable underlying request data
     */
    public WbtpRequestData _data() {
        return this.data;
    }

    public WbtpRequest(byte type, @NotNull String path, byte[] payload) {
        this.data = new WbtpRequestData();
        setType(type);
        WbtpRequests.setPath(this.data, path);
        WbtpRequests.setPayload(this.data, payload);
    }

    public WbtpRequest(byte type, @NotNull String path, @NotNull String payload) {
        this.data = new WbtpRequestData();
        setType(type);
        WbtpRequests.setPath(this.data, path);
        WbtpRequests.setPayloadString(this.data, payload);
    }

    public WbtpRequest(byte type, @NotNull String path) {
        this.data = new WbtpRequestData();
        setType(type);
        WbtpRequests.setPath(this.data, path);
    }

    /**
     * Returns type of request.
     *
     * @return Type of request
     */
    public byte getType() {
        return this.data.type;
    }

    /**
     * Sets type of request.
     *
     * @param type Type of request
     */
    public @Contract(mutates = "this") WbtpRequest setType(byte type) {
        this.data.type = type;
        return this;
    }

    /**
     * Returns request path.
     *
     * @return Request path
     */
    public String getPath() {
        return new String(this.data.path);
    }

    /**
     * Sets request path.
     *
     * @param path Request path
     */
    public @Contract(mutates = "this") WbtpRequest setPath(@NotNull String path) {
        WbtpRequests.setPath(this.data, path);
        return this;
    }

    /**
     * Returns request params.
     *
     * @return Request params
     */
    public String getParams() {
        return new String(this.data.params);
    }

    /**
     * Sets request params.
     *
     * @param params Request params
     */
    public @Contract(mutates = "this") WbtpRequest setParams(@NotNull String params) {
        WbtpRequests.setParams(this.data, params);
        return this;
    }

    /**
     * Returns request payload.
     *
     * @return Request payload
     */
    public byte[] getPayload() {
        return this.data.payload.clone();
    }

    /**
     * Clears request payload.
     */
    public @Contract(mutates = "this") WbtpRequest clearPayload() {
        WbtpRequests.clearPayload(this.data);
        return this;
    }

    /**
     * Copies and sets request payload directly.
     *
     * @param payload Request payload
     */
    public @Contract(mutates = "this") WbtpRequest setPayload(byte[] payload) {
        WbtpRequests.setPayload(this.data, payload);
        return this;
    }

    /**
     * Sets request payload to a string.
     *
     * @param payload Request payload (string)
     */
    public @Contract(mutates = "this") WbtpRequest setPayloadString(@NotNull String payload) {
        WbtpRequests.setPayloadString(this.data, payload);
        return this;
    }

    /**
     * Serializes this request to an output stream.
     *
     * @param out Output stream
     * @throws IOException When thrown, describes what went wrong during serialization
     */
    public void serialize(@NotNull OutputStream out) throws IOException {
        WbtpRequests.serialize(this.data, out);
    }

    /**
     * Deserializes an input stream into this request.
     *
     * @param in Input stream
     * @throws IOException When thrown, describes what went wrong during deserialization
     */
    public void deserialize(@NotNull InputStream in) throws IOException {
        WbtpRequests.deserialize(this.data, in);
    }
}
