#include "Common.h"
#include "CoAP.h"

void initialise_resources(coap_context_t* context)
{
	coap_resource_t* resource;

	resource = coap_resource_init(coap_make_str_const("billingprofile"), 0);
	coap_register_handler(resource, COAP_REQUEST_POST, billingprofile_post);
	coap_add_resource(context, resource);

	resource = coap_resource_init(coap_make_str_const("clearalarms"), 0);
	coap_register_handler(resource, COAP_REQUEST_POST, clearalarms_post);
	coap_add_resource(context, resource);

	resource = coap_resource_init(coap_make_str_const("energyprofile"), 0);
	coap_register_handler(resource, COAP_REQUEST_POST, energyprofile_post);
	coap_add_resource(context, resource);

	resource = coap_resource_init(coap_make_str_const("gatewayconfig"), 0);
	coap_register_handler(resource, COAP_REQUEST_POST, gatewayconfig_post);
	coap_add_resource(context, resource);

	resource = coap_resource_init(coap_make_str_const("loadprofile"), 0);
	coap_register_handler(resource, COAP_REQUEST_POST, loadprofile_post);
	coap_add_resource(context, resource);

	resource = coap_resource_init(coap_make_str_const("reconnection"), 0);
	coap_register_handler(resource, COAP_REQUEST_POST, reconnection_post);
	coap_add_resource(context, resource);

	resource = coap_resource_init(coap_make_str_const("switchstatus"), 0);
	coap_register_handler(resource, COAP_REQUEST_POST, switchstatus_post);
	coap_add_resource(context, resource);

}


void billingprofile_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response)
{
	size_t	data_len;
	const uint8_t* data;

	if (coap_get_data(request, &data_len, &data))
	{
		/*const coap_address_t* remote_address = coap_session_get_addr_remote(session);*/
		if (LoggingType == 0)
			printf("Received Billing Profile from Client: %s\n", data);
		else
			syslog(LOG_DEBUG, "Received Billing Profile from Client: %s\n", data);

		coap_pdu_set_code(response, COAP_RESPONSE_CODE_CREATED);
	}

	//const uint8_t* billingprofiledata;
	//size_t billingprofilesize;

	//coap_show_pdu(LOG_WARNING, request);
	//(void)coap_get_data(request, &billingprofilesize, &billingprofiledata);
	//if (LoggingType == 0)
	//	printf("Billing Profile Request: %s\n", billingprofiledata);
	//else
	//	syslog(LOG_DEBUG, "Billing Profile Request: %s\n", billingprofiledata);

	//coap_pdu_set_code(response, COAP_RESPONSE_CODE_CREATED);
}

void clearalarms_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response)
{
	size_t	data_len;
	const uint8_t* data;

	if (coap_get_data(request, &data_len, &data))
	{
		if (LoggingType == 0)
			printf("Received Clear Alarms from Client: %s\n", data);
		else
			syslog(LOG_DEBUG, "Received Clear Alarms Profile from Client: %s\n", data);

		coap_pdu_set_code(response, COAP_RESPONSE_CODE_CREATED);
	}
}

void energyprofile_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response)
{
	size_t	data_len;
	const uint8_t* data;

	if (coap_get_data(request, &data_len, &data))
	{
		if (LoggingType == 0)
			printf("Received Energy Profile from Client: %s\n", data);
		else
			syslog(LOG_DEBUG, "Received Energy Profile from Client: %s\n", data);

		coap_pdu_set_code(response, COAP_RESPONSE_CODE_CREATED);
	}
}

void gatewayconfig_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response)
{
	size_t	data_len;
	const uint8_t* data;

	if (coap_get_data(request, &data_len, &data))
	{
		if (LoggingType == 0)
			printf("Received Gateway Config from Client: %s\n", data);
		else
			syslog(LOG_DEBUG, "Received Gateway Config from Client: %s\n", data);

		coap_pdu_set_code(response, COAP_RESPONSE_CODE_CREATED);
	}
}

void loadprofile_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response)
{
	size_t	data_len;
	const uint8_t* data;

	if (coap_get_data(request, &data_len, &data))
	{
		if (LoggingType == 0)
			printf("Received Load Profile from Client: %s\n", data);
		else
			syslog(LOG_DEBUG, "Received Load Profile from Client: %s\n", data);

		coap_pdu_set_code(response, COAP_RESPONSE_CODE_CREATED);
	}
}

void reconnection_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response)
{
	size_t	data_len;
	const uint8_t* data;

	if (coap_get_data(request, &data_len, &data))
	{
		if (LoggingType == 0)
			printf("Received Reconnect/Disconnect from Client: %s\n", data);
		else
			syslog(LOG_DEBUG, "Received Reconnect/Disconnect from Client: %s\n", data);

		coap_pdu_set_code(response, COAP_RESPONSE_CODE_CREATED);
	}
}

void switchstatus_post(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response)
{
	size_t	data_len;
	const uint8_t* data;

	if (coap_get_data(request, &data_len, &data))
	{
		if (LoggingType == 0)
			printf("Received Switch Status from Client: %s\n", data);
		else
			syslog(LOG_DEBUG, "Received Switch Status from Client: %s\n", data);

		coap_pdu_set_code(response, COAP_RESPONSE_CODE_CREATED);
	}
}
