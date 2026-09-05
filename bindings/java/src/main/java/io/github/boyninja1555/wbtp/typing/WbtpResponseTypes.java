package io.github.boyninja1555.wbtp.typing;

public final class WbtpResponseTypes {

    /**
     * Signifies a generic response. The payload is ignored and failure/success must not be assumed. Must be sent back directly after receiving a REQUEST request.
     */
    public static final byte RESPONSE = 0x00;

    /**
     * Signifies a completed request. The payload is not ignored.
     */
    public static final byte SUCCESS = 0x01;

    /**
     * Signifies a failed request. A string error may be provided somewhere inside params, with a template value of "error=%s". This error behavior must be handled if possible. The payload is not ignored.
     */
    public static final byte FAILURE = 0x02;

    /**
     * Returns the stringified form of a response type.
     *
     * @param type Response type
     * @return Stringified form of response type
     */
    public static String toString(byte type) {
        return switch (type) {
            case RESPONSE -> "RESPONSE";
            case SUCCESS -> "SUCCESS";
            case FAILURE -> "FAILURE";
            default -> "NULL";
        };
    }
}
