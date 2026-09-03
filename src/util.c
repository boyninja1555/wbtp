#include "wbtp.h"
#include <string.h>
#include <stdio.h>

const char *wbtp_request_type_string(WbtpRequestType type)
{
    switch (type)
    {
    case WBTP_REQUEST:
        return "REQUEST";
    case WBTP_GET:
        return "GET";
    case WBTP_PUT:
        return "PUT";
    default:
        return "NULL";
    }
}

const char *wbtp_response_type_string(WbtpResponseType type)
{
    switch (type)
    {
    case WBTP_RESPONSE:
        return "RESPONSE";
    case WBTP_SUCCESS:
        return "SUCCESS";
    case WBTP_FAILURE:
        return "FAILURE";
    default:
        return "NULL";
    }
}

bool wbtp_request_string(const WbtpRequest request, char *str, uint32_t str_size)
{
    uint32_t buf_size = 32 + WBTP_PATH_MAX + WBTP_PARAMS_MAX + request.payload_size;
    char buf[buf_size];
    int written = snprintf(buf, buf_size, "%s %s\n%s\n\nPayload (%u bytes):\n%.*s", wbtp_request_type_string(request.type), request.path, request.params, request.payload_size, (int)request.payload_size, request.payload);
    if (written < 0 || (uint32_t)written + 1 > str_size)
        return false;

    memcpy(str, buf, (size_t)written + 1);
    return true;
}

bool wbtp_response_string(const WbtpResponse response, char *str, uint32_t str_size)
{
    uint32_t buf_size = 32 + WBTP_PARAMS_MAX + response.payload_size;
    char buf[buf_size];
    int written = snprintf(buf, buf_size, "%s\n%s\n\nPayload (%u bytes):\n%.*s", wbtp_response_type_string(response.type), response.params, response.payload_size, (int)response.payload_size, response.payload);
    if (written < 0 || (uint32_t)written + 1 > str_size)
        return false;

    memcpy(str, buf, (size_t)written + 1);
    return true;
}
