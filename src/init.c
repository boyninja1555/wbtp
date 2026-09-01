#include "wbtp.h"
#include <string.h>

WbtpRequest wbtp_request(WbtpRequestType type, const char *path, uint32_t payload_size, char *payload)
{
    WbtpRequest request = {.type = type, .params = "", .payload_size = payload_size, .payload = payload};
    wbtp_request_path(&request, path);
    return request;
}

void wbtp_request_path(WbtpRequest *request, const char *path)
{
    strcpy(request->path, path);
}

void wbtp_request_payload(WbtpRequest *request, uint32_t payload_size, char *payload)
{
    request->payload_size = payload_size;
    request->payload = payload;
}

void wbtp_request_payload_str(WbtpRequest *request, char *str)
{
    request->payload_size = strlen(str);
    request->payload = str;
}

WbtpResponse wbtp_response(WbtpResponseType type, uint32_t payload_size, char *payload)
{
    return (WbtpResponse){.type = type, .params = "", .payload_size = payload_size, .payload = payload};
}

void wbtp_response_payload(WbtpResponse *response, uint32_t payload_size, char *payload)
{
    response->payload_size = payload_size;
    response->payload = payload;
}

void wbtp_response_payload_str(WbtpResponse *response, char *str)
{
    response->payload_size = strlen(str);
    response->payload = str;
}
