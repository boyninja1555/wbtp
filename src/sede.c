#include "wbtp.h"
#include <string.h>

void write_size(uint32_t *i, char *buf, uint32_t size)
{
    memcpy(buf + (*i += sizeof(size)), &size, sizeof(size));
}

void write_str(uint32_t *i, char *buf, const char *str)
{
    uint32_t str_size = strlen(str);
    write_size(i, buf, str_size);
    memcpy(buf + (*i += str_size), str, str_size);
}

uint32_t read_size(uint32_t *i, const char *buf)
{
    uint32_t size;
    memcpy(&size, buf + (*i += sizeof(size)), sizeof(size));
    return size;
}

void read_str(uint32_t *i, const char *buf, char *strout)
{
    uint32_t str_size = read_size(i, buf);
    memcpy(strout, buf + (*i += str_size), str_size);
}

// Public

void wbtp_request_serialize(const WbtpRequest request, char *buf)
{
    uint32_t i = 0;

    // Header
    buf[i++] = (unsigned char)request.type;
    write_str(&i, buf, request.path);
    write_str(&i, buf, request.params);

    // Payload
    write_size(&i, buf, request.payload_size);
    memcpy(buf + (i += request.payload_size), request.payload, request.payload_size);
}

void wbtp_request_deserialize(WbtpRequest *request, const char *buf)
{
    uint32_t i = 0;

    // Header
    request->type = read_size(&i, buf);
    read_str(&i, buf, request->path);
    read_str(&i, buf, request->params);

    // Payload
    request->payload_size = read_size(&i, buf);
    memcpy(request->payload, buf + (i += request->payload_size), request->payload_size);
}

void wbtp_response_serialize(const WbtpResponse response, char *buf)
{
    uint32_t i = 0;

    // Header
    buf[i++] = (unsigned char)response.type;
    write_str(&i, buf, response.params);

    // Payload
    write_size(&i, buf, response.payload_size);
    memcpy(buf + (i += response.payload_size), response.payload, response.payload_size);
}

void wbtp_response_deserialize(WbtpResponse *response, const char *buf)
{
    uint32_t i = 0;

    // Header
    response->type = read_size(&i, buf);
    read_str(&i, buf, response->params);

    // Payload
    response->payload_size = read_size(&i, buf);
    memcpy(response->payload, buf + (i += response->payload_size), response->payload_size);
}
