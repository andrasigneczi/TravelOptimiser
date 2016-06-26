/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProxiedProtocolHandler.idl
 */

#ifndef __gen_nsIProxiedProtocolHandler_h__
#define __gen_nsIProxiedProtocolHandler_h__


#ifndef __gen_nsIProtocolHandler_h__
#include "nsIProtocolHandler.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsILoadInfo; /* forward declaration */


/* starting interface:    nsIProxiedProtocolHandler */
#define NS_IPROXIEDPROTOCOLHANDLER_IID_STR "3756047a-fa2b-4b45-9948-3b5f8fc375e7"

#define NS_IPROXIEDPROTOCOLHANDLER_IID \
  {0x3756047a, 0xfa2b, 0x4b45, \
    { 0x99, 0x48, 0x3b, 0x5f, 0x8f, 0xc3, 0x75, 0xe7 }}

class NS_NO_VTABLE nsIProxiedProtocolHandler : public nsIProtocolHandler {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROXIEDPROTOCOLHANDLER_IID)

  /* nsIChannel newProxiedChannel2 (in nsIURI uri, in nsIProxyInfo proxyInfo, in unsigned long proxyResolveFlags, in nsIURI proxyURI, in nsILoadInfo aLoadInfo); */
  NS_IMETHOD NewProxiedChannel2(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) = 0;

  /* nsIChannel newProxiedChannel (in nsIURI uri, in nsIProxyInfo proxyInfo, in unsigned long proxyResolveFlags, in nsIURI proxyURI); */
  NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProxiedProtocolHandler, NS_IPROXIEDPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROXIEDPROTOCOLHANDLER \
  NS_IMETHOD NewProxiedChannel2(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) override; \
  NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROXIEDPROTOCOLHANDLER(_to) \
  NS_IMETHOD NewProxiedChannel2(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) override { return _to NewProxiedChannel2(uri, proxyInfo, proxyResolveFlags, proxyURI, aLoadInfo, _retval); } \
  NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval) override { return _to NewProxiedChannel(uri, proxyInfo, proxyResolveFlags, proxyURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROXIEDPROTOCOLHANDLER(_to) \
  NS_IMETHOD NewProxiedChannel2(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewProxiedChannel2(uri, proxyInfo, proxyResolveFlags, proxyURI, aLoadInfo, _retval); } \
  NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewProxiedChannel(uri, proxyInfo, proxyResolveFlags, proxyURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProxiedProtocolHandler : public nsIProxiedProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROXIEDPROTOCOLHANDLER

  nsProxiedProtocolHandler();

private:
  ~nsProxiedProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProxiedProtocolHandler, nsIProxiedProtocolHandler)

nsProxiedProtocolHandler::nsProxiedProtocolHandler()
{
  /* member initializers and constructor code */
}

nsProxiedProtocolHandler::~nsProxiedProtocolHandler()
{
  /* destructor code */
}

/* nsIChannel newProxiedChannel2 (in nsIURI uri, in nsIProxyInfo proxyInfo, in unsigned long proxyResolveFlags, in nsIURI proxyURI, in nsILoadInfo aLoadInfo); */
NS_IMETHODIMP nsProxiedProtocolHandler::NewProxiedChannel2(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newProxiedChannel (in nsIURI uri, in nsIProxyInfo proxyInfo, in unsigned long proxyResolveFlags, in nsIURI proxyURI); */
NS_IMETHODIMP nsProxiedProtocolHandler::NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProxiedProtocolHandler_h__ */
