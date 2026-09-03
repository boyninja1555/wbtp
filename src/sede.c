#include "wbtp.h"
#include <string.h>

void write_size(uint32_t *i, char *buf, uint32_t size)
{
    memcpy(buf + *i, &size, sizeof(size));
    *i += sizeof(size);
}

void write_str(uint32_t *i, char *buf, const char *str)
{
    uint32_t str_size = strlen(str);
    write_size(i, buf, str_size);
    memcpy(buf + *i, str, str_size);
    *i += str_size;
}

uint32_t read_size(uint32_t *i, const char *buf)
{
    uint32_t size;
    memcpy(&size, buf + *i, sizeof(size));
    *i += sizeof(size);
    return size;
}

void read_str(uint32_t *i, const char *buf, char *strout)
{
    uint32_t str_size = read_size(i, buf);
    memcpy(strout, buf + *i, str_size);
    strout[str_size] = '\0';
    *i += str_size;
}

// Public

void wbtp_request_serialize(const WbtpRequest request, char *buf)
{
    uint32_t i = 0;

    // Header
    buf[i++] = (uint8_t)request.type;
    write_str(&i, buf, request.path);
    write_str(&i, buf, request.params);

    // Payload
    write_size(&i, buf, request.payload_size);
    if (request.payload_size > 0)
    {
        memcpy(buf + i, request.payload, request.payload_size);
        i += request.payload_size;
    }
}

void wbtp_request_deserialize(WbtpRequest *request, const char *buf)
{
    uint32_t i = 0;

    // Header
    request->type = (WbtpRequestType)(uint8_t)buf[i++];
    read_str(&i, buf, request->path);
    read_str(&i, buf, request->params);

    // Payload
    request->payload_size = read_size(&i, buf);
    if (request->payload_size > 0)
    {
        memcpy(request->payload, buf + i, request->payload_size);
        i += request->payload_size;
    }
}

void wbtp_response_serialize(const WbtpResponse response, char *buf)
{
    uint32_t i = 0;

    // Header
    buf[i++] = (uint8_t)response.type;
    write_str(&i, buf, response.params);

    // Payload
    write_size(&i, buf, response.payload_size);
    if (response.payload_size > 0)
    {
        memcpy(buf + i, response.payload, response.payload_size);
        i += response.payload_size;
    }
}

void wbtp_response_deserialize(WbtpResponse *response, const char *buf)
{
    uint32_t i = 0;

    // Header
    response->type = (WbtpResponseType)(uint8_t)buf[i++];
    read_str(&i, buf, response->params);

    // Payload
    response->payload_size = read_size(&i, buf);
    if (response->payload_size > 0)
    {
        memcpy(response->payload, buf + i, response->payload_size);
        i += response->payload_size;
    }
}
