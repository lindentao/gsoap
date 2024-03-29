/* soapcalcService.cpp
   Generated by gSOAP 2.8.23 from calc.h

Copyright(C) 2000-2015, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapcalcService.h"

calcService::calcService() : soap(SOAP_IO_DEFAULT)
{	calcService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

calcService::calcService(const struct soap &_soap) : soap(_soap)
{ }

calcService::calcService(soap_mode iomode) : soap(iomode)
{	calcService_init(iomode, iomode);
}

calcService::calcService(soap_mode imode, soap_mode omode) : soap(imode, omode)
{	calcService_init(imode, omode);
}

calcService::~calcService()
{
	this->destroy();
}

void calcService::calcService_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns", "urn:calc", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void calcService::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void calcService::reset()
{	this->destroy();
	soap_done(this);
	soap_initialize(this);
	calcService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
calcService *calcService::copy()
{	calcService *dup = SOAP_NEW_COPY(calcService(*(struct soap*)this));
	return dup;
}
#endif

int calcService::soap_close_socket()
{	return soap_closesock(this);
}

int calcService::soap_force_close_socket()
{	return soap_force_closesock(this);
}

int calcService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this, string, detailXML);
}

int calcService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this, subcodeQName, string, detailXML);
}

int calcService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this, string, detailXML);
}

int calcService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this, subcodeQName, string, detailXML);
}

void calcService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void calcService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *calcService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

void calcService::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *calcService::soap_header()
{	return this->header;
}

int calcService::run(int port)
{	if (soap_valid_socket(this->master) || soap_valid_socket(bind(NULL, port, 100)))
	{	for (;;)
		{	if (!soap_valid_socket(accept()) || serve())
				break;
			soap_destroy(this);
			soap_end(this);
		}
	}
	return this->error;
}

SOAP_SOCKET calcService::bind(const char *host, int port, int backlog)
{	return soap_bind(this, host, port, backlog);
}

SOAP_SOCKET calcService::accept()
{	return soap_accept(this);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int calcService::ssl_accept()
{	return soap_ssl_accept(this);
}
#endif

int calcService::serve()
{
#ifndef WITH_FASTCGI
	unsigned int k = this->max_keep_alive;
#endif
	do
	{

#ifndef WITH_FASTCGI
		if (this->max_keep_alive > 0 && !--k)
			this->keep_alive = 0;
#endif

		if (soap_begin_serve(this))
		{	if (this->error >= SOAP_STOP)
				continue;
			return this->error;
		}
		if (dispatch() || (this->fserveloop && this->fserveloop(this)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this);
#else
			return soap_send_fault(this);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(this);
		soap_end(this);
	} while (1);
#else
	} while (this->keep_alive);
#endif
	return SOAP_OK;
}

static int serve_ns__add(calcService*);
static int serve_ns__sub(calcService*);
static int serve_ns__mul(calcService*);
static int serve_ns__div(calcService*);
static int serve_ns__pow(calcService*);

int calcService::dispatch()
{	soap_peek_element(this);
	if (!soap_match_tag(this, this->tag, "ns:add"))
		return serve_ns__add(this);
	if (!soap_match_tag(this, this->tag, "ns:sub"))
		return serve_ns__sub(this);
	if (!soap_match_tag(this, this->tag, "ns:mul"))
		return serve_ns__mul(this);
	if (!soap_match_tag(this, this->tag, "ns:div"))
		return serve_ns__div(this);
	if (!soap_match_tag(this, this->tag, "ns:pow"))
		return serve_ns__pow(this);
	return this->error = SOAP_NO_METHOD;
}

static int serve_ns__add(calcService *soap)
{	struct ns__add soap_tmp_ns__add;
	struct ns__addResponse soap_tmp_ns__addResponse;
	double soap_tmp_double;
	soap_default_ns__addResponse(soap, &soap_tmp_ns__addResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__addResponse.result = &soap_tmp_double;
	soap_default_ns__add(soap, &soap_tmp_ns__add);
	if (!soap_get_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->add(soap_tmp_ns__add.a, soap_tmp_ns__add.b, soap_tmp_ns__addResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__addResponse(soap, &soap_tmp_ns__addResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__addResponse(soap, &soap_tmp_ns__addResponse, "ns:addResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__addResponse(soap, &soap_tmp_ns__addResponse, "ns:addResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__sub(calcService *soap)
{	struct ns__sub soap_tmp_ns__sub;
	struct ns__subResponse soap_tmp_ns__subResponse;
	double soap_tmp_double;
	soap_default_ns__subResponse(soap, &soap_tmp_ns__subResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__subResponse.result = &soap_tmp_double;
	soap_default_ns__sub(soap, &soap_tmp_ns__sub);
	if (!soap_get_ns__sub(soap, &soap_tmp_ns__sub, "ns:sub", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->sub(soap_tmp_ns__sub.a, soap_tmp_ns__sub.b, soap_tmp_ns__subResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__subResponse(soap, &soap_tmp_ns__subResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__subResponse(soap, &soap_tmp_ns__subResponse, "ns:subResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__subResponse(soap, &soap_tmp_ns__subResponse, "ns:subResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__mul(calcService *soap)
{	struct ns__mul soap_tmp_ns__mul;
	struct ns__mulResponse soap_tmp_ns__mulResponse;
	double soap_tmp_double;
	soap_default_ns__mulResponse(soap, &soap_tmp_ns__mulResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__mulResponse.result = &soap_tmp_double;
	soap_default_ns__mul(soap, &soap_tmp_ns__mul);
	if (!soap_get_ns__mul(soap, &soap_tmp_ns__mul, "ns:mul", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->mul(soap_tmp_ns__mul.a, soap_tmp_ns__mul.b, soap_tmp_ns__mulResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__mulResponse(soap, &soap_tmp_ns__mulResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__mulResponse(soap, &soap_tmp_ns__mulResponse, "ns:mulResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__mulResponse(soap, &soap_tmp_ns__mulResponse, "ns:mulResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__div(calcService *soap)
{	struct ns__div soap_tmp_ns__div;
	struct ns__divResponse soap_tmp_ns__divResponse;
	double soap_tmp_double;
	soap_default_ns__divResponse(soap, &soap_tmp_ns__divResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__divResponse.result = &soap_tmp_double;
	soap_default_ns__div(soap, &soap_tmp_ns__div);
	if (!soap_get_ns__div(soap, &soap_tmp_ns__div, "ns:div", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->div(soap_tmp_ns__div.a, soap_tmp_ns__div.b, soap_tmp_ns__divResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__divResponse(soap, &soap_tmp_ns__divResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__divResponse(soap, &soap_tmp_ns__divResponse, "ns:divResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__divResponse(soap, &soap_tmp_ns__divResponse, "ns:divResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__pow(calcService *soap)
{	struct ns__pow soap_tmp_ns__pow;
	struct ns__powResponse soap_tmp_ns__powResponse;
	double soap_tmp_double;
	soap_default_ns__powResponse(soap, &soap_tmp_ns__powResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__powResponse.result = &soap_tmp_double;
	soap_default_ns__pow(soap, &soap_tmp_ns__pow);
	if (!soap_get_ns__pow(soap, &soap_tmp_ns__pow, "ns:pow", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = soap->pow(soap_tmp_ns__pow.a, soap_tmp_ns__pow.b, soap_tmp_ns__powResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__powResponse(soap, &soap_tmp_ns__powResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__powResponse(soap, &soap_tmp_ns__powResponse, "ns:powResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__powResponse(soap, &soap_tmp_ns__powResponse, "ns:powResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */
