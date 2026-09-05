package io.github.boyninja1555.wbtp.typing;

import static io.github.boyninja1555.wbtp.typing.WbtpConstants.WBTP_PARAMS_MAX;
import static io.github.boyninja1555.wbtp.typing.WbtpConstants.WBTP_PATH_MAX;

/**
 * Data describing a request.
 */
public final class WbtpRequestData {
    public byte type = WbtpRequestTypes.REQUEST;
    public final char[] path = new char[WBTP_PATH_MAX];
    public final char[] params = new char[WBTP_PARAMS_MAX];
    public byte[] payload = new byte[0];
}
