#ifndef   __CoAP_H__
#define   __CoAP_H__

#include "Common.h"



void initialise_resources(coap_context_t* ctx);

void billingprofile_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response);

void clearalarms_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response);

void energyprofile_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response);

void gatewayconfig_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response);

void loadprofile_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response);

void reconnection_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response);

void switchstatus_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response);

#endif