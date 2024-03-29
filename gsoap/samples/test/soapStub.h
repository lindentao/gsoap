/* soapStub.h
   Generated by gSOAP 2.8.23 from calc.h

Copyright(C) 2000-2015, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapStub_H
#define soapStub_H
#include <vector>
#define SOAP_NAMESPACE_OF_ns2	"urn:calc"
#include "stdsoap2.h"
#if GSOAP_VERSION != 20823
# error "GSOAP VERSION 20823 MISMATCH IN GENERATED CODE VERSUS LIBRARY CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_ns2__addResponse
#define SOAP_TYPE_ns2__addResponse (11)
/* ns2:addResponse */
struct ns2__addResponse
{
public:
	double result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:double */
public:
	int soap_type() const { return 11; } /* = unique type id SOAP_TYPE_ns2__addResponse */
};
#endif

#ifndef SOAP_TYPE_ns2__add
#define SOAP_TYPE_ns2__add (12)
/* ns2:add */
struct ns2__add
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
public:
	int soap_type() const { return 12; } /* = unique type id SOAP_TYPE_ns2__add */
};
#endif

#ifndef SOAP_TYPE_ns2__subResponse
#define SOAP_TYPE_ns2__subResponse (14)
/* ns2:subResponse */
struct ns2__subResponse
{
public:
	double result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:double */
public:
	int soap_type() const { return 14; } /* = unique type id SOAP_TYPE_ns2__subResponse */
};
#endif

#ifndef SOAP_TYPE_ns2__sub
#define SOAP_TYPE_ns2__sub (15)
/* ns2:sub */
struct ns2__sub
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
public:
	int soap_type() const { return 15; } /* = unique type id SOAP_TYPE_ns2__sub */
};
#endif

#ifndef SOAP_TYPE_ns2__mulResponse
#define SOAP_TYPE_ns2__mulResponse (17)
/* ns2:mulResponse */
struct ns2__mulResponse
{
public:
	double result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:double */
public:
	int soap_type() const { return 17; } /* = unique type id SOAP_TYPE_ns2__mulResponse */
};
#endif

#ifndef SOAP_TYPE_ns2__mul
#define SOAP_TYPE_ns2__mul (18)
/* ns2:mul */
struct ns2__mul
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
public:
	int soap_type() const { return 18; } /* = unique type id SOAP_TYPE_ns2__mul */
};
#endif

#ifndef SOAP_TYPE_ns2__divResponse
#define SOAP_TYPE_ns2__divResponse (20)
/* ns2:divResponse */
struct ns2__divResponse
{
public:
	double result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:double */
public:
	int soap_type() const { return 20; } /* = unique type id SOAP_TYPE_ns2__divResponse */
};
#endif

#ifndef SOAP_TYPE_ns2__div
#define SOAP_TYPE_ns2__div (21)
/* ns2:div */
struct ns2__div
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
public:
	int soap_type() const { return 21; } /* = unique type id SOAP_TYPE_ns2__div */
};
#endif

#ifndef SOAP_TYPE_ns2__powResponse
#define SOAP_TYPE_ns2__powResponse (23)
/* ns2:powResponse */
struct ns2__powResponse
{
public:
	double result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:double */
public:
	int soap_type() const { return 23; } /* = unique type id SOAP_TYPE_ns2__powResponse */
};
#endif

#ifndef SOAP_TYPE_ns2__pow
#define SOAP_TYPE_ns2__pow (24)
/* ns2:pow */
struct ns2__pow
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
public:
	int soap_type() const { return 24; } /* = unique type id SOAP_TYPE_ns2__pow */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (25)
/* SOAP Header: */
struct SOAP_ENV__Header
{
public:
	int soap_type() const { return 25; } /* = unique type id SOAP_TYPE_SOAP_ENV__Header */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (26)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
public:
	int soap_type() const { return 26; } /* = unique type id SOAP_TYPE_SOAP_ENV__Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (28)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
public:
	int soap_type() const { return 28; } /* = unique type id SOAP_TYPE_SOAP_ENV__Detail */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (31)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
public:
	int soap_type() const { return 31; } /* = unique type id SOAP_TYPE_SOAP_ENV__Reason */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (32)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
public:
	int soap_type() const { return 32; } /* = unique type id SOAP_TYPE_SOAP_ENV__Fault */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
