/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProtocolHandler.idl
 */

#ifndef __gen_nsIProtocolHandler_h__
#define __gen_nsIProtocolHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsILoadInfo; /* forward declaration */


/* starting interface:    nsIProtocolHandler */
#define NS_IPROTOCOLHANDLER_IID_STR "a7aad716-e72c-435d-82f1-7582dffae661"

#define NS_IPROTOCOLHANDLER_IID \
  {0xa7aad716, 0xe72c, 0x435d, \
    { 0x82, 0xf1, 0x75, 0x82, 0xdf, 0xfa, 0xe6, 0x61 }}

class NS_NO_VTABLE nsIProtocolHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLHANDLER_IID)

  /* readonly attribute ACString scheme; */
  NS_IMETHOD GetScheme(nsACString & aScheme) = 0;

  /* readonly attribute long defaultPort; */
  NS_IMETHOD GetDefaultPort(int32_t *aDefaultPort) = 0;

  /* readonly attribute unsigned long protocolFlags; */
  NS_IMETHOD GetProtocolFlags(uint32_t *aProtocolFlags) = 0;

  /* nsIURI newURI (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) = 0;

  /* nsIChannel newChannel2 (in nsIURI aURI, in nsILoadInfo aLoadinfo); */
  NS_IMETHOD NewChannel2(nsIURI *aURI, nsILoadInfo *aLoadinfo, nsIChannel * *_retval) = 0;

  /* nsIChannel newChannel (in nsIURI aURI); */
  NS_IMETHOD NewChannel(nsIURI *aURI, nsIChannel * *_retval) = 0;

  /* boolean allowPort (in long port, in string scheme); */
  NS_IMETHOD AllowPort(int32_t port, const char * scheme, bool *_retval) = 0;

  enum {
    URI_STD = 0U,
    URI_NORELATIVE = 1U,
    URI_NOAUTH = 2U,
    ALLOWS_PROXY = 4U,
    ALLOWS_PROXY_HTTP = 8U,
    URI_INHERITS_SECURITY_CONTEXT = 16U,
    URI_FORBIDS_AUTOMATIC_DOCUMENT_REPLACEMENT = 32U,
    URI_LOADABLE_BY_ANYONE = 64U,
    URI_DANGEROUS_TO_LOAD = 128U,
    URI_IS_UI_RESOURCE = 256U,
    URI_IS_LOCAL_FILE = 512U,
    URI_LOADABLE_BY_SUBSUMERS = 1024U,
    URI_DOES_NOT_RETURN_DATA = 2048U,
    URI_IS_LOCAL_RESOURCE = 4096U,
    URI_OPENING_EXECUTES_SCRIPT = 8192U,
    URI_NON_PERSISTABLE = 16384U,
    URI_FORBIDS_COOKIE_ACCESS = 32768U,
    URI_CROSS_ORIGIN_NEEDS_WEBAPPS_PERM = 65536U,
    URI_SYNC_LOAD_IS_OK = 131072U,
    URI_SAFE_TO_LOAD_IN_SECURE_CONTEXT = 262144U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolHandler, NS_IPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLHANDLER \
  NS_IMETHOD GetScheme(nsACString & aScheme) override; \
  NS_IMETHOD GetDefaultPort(int32_t *aDefaultPort) override; \
  NS_IMETHOD GetProtocolFlags(uint32_t *aProtocolFlags) override; \
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) override; \
  NS_IMETHOD NewChannel2(nsIURI *aURI, nsILoadInfo *aLoadinfo, nsIChannel * *_retval) override; \
  NS_IMETHOD NewChannel(nsIURI *aURI, nsIChannel * *_retval) override; \
  NS_IMETHOD AllowPort(int32_t port, const char * scheme, bool *_retval) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLHANDLER(_to) \
  NS_IMETHOD GetScheme(nsACString & aScheme) override { return _to GetScheme(aScheme); } \
  NS_IMETHOD GetDefaultPort(int32_t *aDefaultPort) override { return _to GetDefaultPort(aDefaultPort); } \
  NS_IMETHOD GetProtocolFlags(uint32_t *aProtocolFlags) override { return _to GetProtocolFlags(aProtocolFlags); } \
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) override { return _to NewURI(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD NewChannel2(nsIURI *aURI, nsILoadInfo *aLoadinfo, nsIChannel * *_retval) override { return _to NewChannel2(aURI, aLoadinfo, _retval); } \
  NS_IMETHOD NewChannel(nsIURI *aURI, nsIChannel * *_retval) override { return _to NewChannel(aURI, _retval); } \
  NS_IMETHOD AllowPort(int32_t port, const char * scheme, bool *_retval) override { return _to AllowPort(port, scheme, _retval); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLHANDLER(_to) \
  NS_IMETHOD GetScheme(nsACString & aScheme) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScheme(aScheme); } \
  NS_IMETHOD GetDefaultPort(int32_t *aDefaultPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultPort(aDefaultPort); } \
  NS_IMETHOD GetProtocolFlags(uint32_t *aProtocolFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocolFlags(aProtocolFlags); } \
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewURI(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD NewChannel2(nsIURI *aURI, nsILoadInfo *aLoadinfo, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannel2(aURI, aLoadinfo, _retval); } \
  NS_IMETHOD NewChannel(nsIURI *aURI, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannel(aURI, _retval); } \
  NS_IMETHOD AllowPort(int32_t port, const char * scheme, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AllowPort(port, scheme, _retval); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolHandler : public nsIProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLHANDLER

  nsProtocolHandler();

private:
  ~nsProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProtocolHandler, nsIProtocolHandler)

nsProtocolHandler::nsProtocolHandler()
{
  /* member initializers and constructor code */
}

nsProtocolHandler::~nsProtocolHandler()
{
  /* destructor code */
}

/* readonly attribute ACString scheme; */
NS_IMETHODIMP nsProtocolHandler::GetScheme(nsACString & aScheme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long defaultPort; */
NS_IMETHODIMP nsProtocolHandler::GetDefaultPort(int32_t *aDefaultPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long protocolFlags; */
NS_IMETHODIMP nsProtocolHandler::GetProtocolFlags(uint32_t *aProtocolFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI newURI (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
NS_IMETHODIMP nsProtocolHandler::NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannel2 (in nsIURI aURI, in nsILoadInfo aLoadinfo); */
NS_IMETHODIMP nsProtocolHandler::NewChannel2(nsIURI *aURI, nsILoadInfo *aLoadinfo, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannel (in nsIURI aURI); */
NS_IMETHODIMP nsProtocolHandler::NewChannel(nsIURI *aURI, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean allowPort (in long port, in string scheme); */
NS_IMETHODIMP nsProtocolHandler::AllowPort(int32_t port, const char * scheme, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * Protocol handlers are registered with XPCOM under the following CONTRACTID prefix:
 */
#define NS_NETWORK_PROTOCOL_CONTRACTID_PREFIX "@mozilla.org/network/protocol;1?name="
/**
 * For example, "@mozilla.org/network/protocol;1?name=http"
 */

#endif /* __gen_nsIProtocolHandler_h__ */
