package io.github.boyninja1555.wbtp.typing;

import static io.github.boyninja1555.wbtp.typing.WbtpConstants.WBTP_PARAMS_MAX;

/**
 * Data describing a response.
 */
public final class WbtpResponseData {
    public byte type = WbtpResponseTypes.RESPONSE;
    public final char[] params = new char[WBTP_PARAMS_MAX];
    public byte[] payload = new byte[0];
}
