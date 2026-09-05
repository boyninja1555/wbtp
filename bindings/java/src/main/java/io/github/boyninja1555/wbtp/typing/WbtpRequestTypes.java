package io.github.boyninja1555.wbtp.typing;

public final class WbtpRequestTypes {

    /**
     * Signifies a generic request. Must expect a mirrored RESPONSE response back, but should not pass any payload.
     */
    public static final byte REQUEST = 0x00;

    /**
     * Signifies a request retrieving some resource. Must expect a response back, but should not pass any payload.
     */
    public static final byte GET = 0x01;

    /**
     * Signifies a request pushing some resource onto the server. Must expect a response back and pass a payload.
     */
    public static final byte PUT = 0x02;

    /**
     * Returns the stringified form of a request type.
     *
     * @param type Request type
     * @return Stringified form of request type
     */
    public static String toString(byte type) {
        return switch (type) {
            case REQUEST -> "REQUEST";
            case GET -> "GET";
            case PUT -> "PUT";
            default -> "NULL";
        };
    }
}
