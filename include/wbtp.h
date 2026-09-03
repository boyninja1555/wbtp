#pragma once

#include "wbtp/winshit.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define WBTP_PATH_MAX 512
#define WBTP_PARAMS_MAX 512

    /**
     * WBTP request types.
     */
    typedef enum
    {
        /**
         * Signifies a generic request. Must expect a mirrored WBTP_RESPONSE response back, but should not pass any payload.
         */
        WBTP_REQUEST = 0x00,

        /**
         * Signifies a request retrieving some resource. Must expect a response back, but should not pass any payload.
         */
        WBTP_GET = 0x01,

        /**
         * Signifies a request pushing some resource onto the server. Must expect a response back and pass a payload.
         */
        WBTP_PUT = 0x02,
    } WbtpRequestType;

    /**
     * Unserialized WBTP request object.
     */
    typedef struct
    {
        /**
         * Type of request.
         */
        WbtpRequestType type;

        /**
         * String signifying a subpath on the server. This should not contain data specific to a request, those can go either in params or payload.
         */
        char path[WBTP_PATH_MAX];

        /**
         * String containing data useful to the server. We standardize a format equivalent to "key=value;key=value" where each key-value pair is separated by a semicolon, and each key ends with a equals sign to signify the value. Values may contain equal signs and must be treated as part of the value.
         */
        char params[WBTP_PARAMS_MAX];

        /**
         * Size of payload in bytes.
         */
        uint32_t payload_size;

        /**
         * Payload in bytes.
         */
        char *payload;
    } WbtpRequest;

    /**
     * Quickly initializes a request object. Due to the fact that WBTP does not allocate or free any memory, payload is referenced instead of copied!
     */
    WBTP_API WbtpRequest wbtp_request(WbtpRequestType type, const char *path, uint32_t payload_size, char *payload);

    /**
     * Duplicates and sets the path of a request object.
     */
    WBTP_API void wbtp_request_path(WbtpRequest *request, const char *path);

    /**
     * Sets the payload of a request object. Due to the fact that WBTP does not allocate or free any memory, payload is referenced instead of copied!
     */
    WBTP_API void wbtp_request_payload(WbtpRequest *request, uint32_t payload_size, char *payload);

    /**
     * Sets the payload of a request object to a string automatically. Due to the fact that WBTP does not allocate or free any memory, payload is referenced instead of copied!
     */
    WBTP_API void wbtp_request_payload_str(WbtpRequest *request, char *str);

    /**
     * Serializes an immutable request object into a byte buffer. We recommend the buffer to be sized similar to the source buffer's size for some breathing room! This is due to the fact that WBTP does not allocate or free any heap memory.
     *
     * Returns how many bytes were written. Will only ever return 0 if serialization failed!
     */
    WBTP_API uint32_t wbtp_request_serialize(const WbtpRequest request, char *buf, uint32_t buf_size);

    /**
     * Deserializes an immutable byte buffer into a preset request object. We recommend the default payload to be sized similar to the source buffer's size for some breathing room! This is due to the fact that WBTP does not allocate or free any memory.
     *
     * Returns how many bytes were read. Will only ever return 0 if deserialization failed!
     */
    WBTP_API uint32_t wbtp_request_deserialize(WbtpRequest *request, const char *buf, uint32_t buf_size);

    /**
     * WBTP response types.
     */
    typedef enum
    {
        /**
         * Signifies a generic response. The payload is ignored and failure/success must not be assumed. Must be sent back directly after receiving a WBTP_REQUEST request.
         */
        WBTP_RESPONSE = 0x00,

        /**
         * Signifies a completed request. The payload is not ignored.
         */
        WBTP_SUCCESS = 0x01,

        /**
         * Signifies a failed request. A string error may be provided somewhere inside params, with a template value of "error=%s". This error behavior must be handled if possible. The payload is not ingored.
         */
        WBTP_FAILURE = 0x02,
    } WbtpResponseType;

    /**
     * Unserialized WBTP response object.
     */
    typedef struct
    {
        /**
         * Type of response.
         */
        WbtpResponseType type;

        /**
         * String containing data useful to the client. We standardize a format equivalent to "key=value;key=value" where each key-value pair is separated by a semicolon, and each key ends with a equals sign to signify the value. Values may contain equal signs and must be treated as part of the value.
         */
        char params[WBTP_PARAMS_MAX];

        /**
         * Size of payload in bytes.
         */
        uint32_t payload_size;

        /**
         * Payload in bytes.
         */
        char *payload;
    } WbtpResponse;

    /**
     * Quickly initializes a response object. Due to the fact that WBTP does not allocate or free any memory, payload is referenced instead of copied!
     */
    WBTP_API WbtpResponse wbtp_response(WbtpResponseType type, uint32_t payload_size, char *payload);

    /**
     * Sets the payload of a response object. Due to the fact that WBTP does not allocate or free any memory, payload is referenced instead of copied!
     */
    WBTP_API void wbtp_response_payload(WbtpResponse *response, uint32_t payload_size, char *payload);

    /**
     * Sets the payload of a response object to a string automatically. Due to the fact that WBTP does not allocate or free any memory, payload is referenced instead of copied!
     */
    WBTP_API void wbtp_response_payload_str(WbtpResponse *response, char *str);

    /**
     * Serializes an immutable response object into a byte buffer. We recommend the buffer to be sized similar to the source buffer's size for some breathing room! This is due to the fact that WBTP does not allocate or free any heap memory.
     *
     * Returns how many bytes were written. Will only ever return 0 if serialization failed!
     */
    WBTP_API uint32_t wbtp_response_serialize(const WbtpResponse response, char *buf, uint32_t buf_size);

    /**
     * Deserializes an immutable byte buffer into a preset response object. We recommend the default payload to be sized similar to the source buffer's size for some breathing room! This is due to the fact that WBTP does not allocate or free any memory.
     *
     * Returns how many bytes were read. Will only ever return 0 if deserialization failed!
     */
    WBTP_API uint32_t wbtp_response_deserialize(WbtpResponse *response, const char *buf, uint32_t buf_size);

#ifdef __cplusplus
}
#endif
