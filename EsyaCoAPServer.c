#include "Common.h"
#include "CoAP.h"

/*
 * The resource handler
 */
 //void hello_handler(coap_context_t* ctx, struct coap_resource_t* resource, const coap_endpoint_t* local_interface, coap_address_t* peer,	coap_pdu_t* request, coap_string_t* token, coap_pdu_t* response)
void hellohandlerss_put(coap_resource_t* resource, coap_session_t* session, const coap_pdu_t* request, const coap_string_t* query, coap_pdu_t* response)
{
	printf("Inside hellohandlerss_put\n");

	const uint8_t* data;
	size_t         data_len;
	if (coap_get_data(request, &data_len, &data))
	{
		printf("Received from Client: %s\n", data);
		coap_pdu_set_code(response, /*COAP_RESPONSE_CODE_CONTENT*/ COAP_RESPONSE_CODE_CREATED);
	}
}

int main(int argc, char* argv[])
{
	coap_context_t* context;
	coap_address_t listen_addr;

	coap_endpoint_t* endpoint;
	int result = EXIT_FAILURE;

	if (!uci_match("EsyaCoAPServer.enable", "true"))
	{
		return -1;
	}

	coap_startup();

	coap_address_init(&listen_addr);
	listen_addr.addr.sa.sa_family = AF_INET;
	listen_addr.addr.sin.sin_port = htons(5683);

	context = coap_new_context(NULL);

	if (!context || !(endpoint = coap_new_endpoint(context, &listen_addr, COAP_PROTO_UDP)))
	{
		if (LoggingType == 0)
			printf("Cannot initialize CoAP Context\n");
		else
			printf("Cannot initialize CoAP Context\n");
		goto finish;
	}

	initialise_resources(context);

	while (1) { coap_io_process(context, COAP_IO_WAIT); }

	result = EXIT_SUCCESS;
finish:

	coap_free_context(context);
	coap_cleanup();

	return result;
}