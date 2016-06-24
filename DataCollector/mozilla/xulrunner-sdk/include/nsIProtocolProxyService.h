/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProtocolProxyService.idl
 */

#ifndef __gen_nsIProtocolProxyService_h__
#define __gen_nsIProtocolProxyService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICancelable; /* forward declaration */

class nsIProtocolProxyCallback; /* forward declaration */

class nsIProtocolProxyFilter; /* forward declaration */

class nsIProtocolProxyChannelFilter; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIProtocolProxyService */
#define NS_IPROTOCOLPROXYSERVICE_IID_STR "deec8e08-a246-443c-90b6-f655632d1abf"

#define NS_IPROTOCOLPROXYSERVICE_IID \
  {0xdeec8e08, 0xa246, 0x443c, \
    { 0x90, 0xb6, 0xf6, 0x55, 0x63, 0x2d, 0x1a, 0xbf }}

class NS_NO_VTABLE nsIProtocolProxyService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLPROXYSERVICE_IID)

  enum {
    RESOLVE_PREFER_SOCKS_PROXY = 2U,
    RESOLVE_IGNORE_URI_SCHEME = 4U,
    RESOLVE_PREFER_HTTPS_PROXY = 12U,
    RESOLVE_ALWAYS_TUNNEL = 16U
  };

  /* nsICancelable asyncResolve (in nsISupports aChannelOrURI, in unsigned long aFlags, in nsIProtocolProxyCallback aCallback); */
  NS_IMETHOD AsyncResolve(nsISupports *aChannelOrURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval) = 0;

  /* nsIProxyInfo newProxyInfo (in ACString aType, in AUTF8String aHost, in long aPort, in unsigned long aFlags, in unsigned long aFailoverTimeout, in nsIProxyInfo aFailoverProxy); */
  NS_IMETHOD NewProxyInfo(const nsACString & aType, const nsACString & aHost, int32_t aPort, uint32_t aFlags, uint32_t aFailoverTimeout, nsIProxyInfo *aFailoverProxy, nsIProxyInfo * *_retval) = 0;

  /* nsIProxyInfo getFailoverForProxy (in nsIProxyInfo aProxyInfo, in nsIURI aURI, in nsresult aReason); */
  NS_IMETHOD GetFailoverForProxy(nsIProxyInfo *aProxyInfo, nsIURI *aURI, nsresult aReason, nsIProxyInfo * *_retval) = 0;

  /* void registerFilter (in nsIProtocolProxyFilter aFilter, in unsigned long aPosition); */
  NS_IMETHOD RegisterFilter(nsIProtocolProxyFilter *aFilter, uint32_t aPosition) = 0;

  /* void registerChannelFilter (in nsIProtocolProxyChannelFilter aFilter, in unsigned long aPosition); */
  NS_IMETHOD RegisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter, uint32_t aPosition) = 0;

  /* void unregisterFilter (in nsIProtocolProxyFilter aFilter); */
  NS_IMETHOD UnregisterFilter(nsIProtocolProxyFilter *aFilter) = 0;

  /* void unregisterChannelFilter (in nsIProtocolProxyChannelFilter aFilter); */
  NS_IMETHOD UnregisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter) = 0;

  enum {
    PROXYCONFIG_DIRECT = 0U,
    PROXYCONFIG_MANUAL = 1U,
    PROXYCONFIG_PAC = 2U,
    PROXYCONFIG_WPAD = 4U,
    PROXYCONFIG_SYSTEM = 5U
  };

  /* readonly attribute unsigned long proxyConfigType; */
  NS_IMETHOD GetProxyConfigType(uint32_t *aProxyConfigType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolProxyService, NS_IPROTOCOLPROXYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLPROXYSERVICE \
  NS_IMETHOD AsyncResolve(nsISupports *aChannelOrURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval) override; \
  NS_IMETHOD NewProxyInfo(const nsACString & aType, const nsACString & aHost, int32_t aPort, uint32_t aFlags, uint32_t aFailoverTimeout, nsIProxyInfo *aFailoverProxy, nsIProxyInfo * *_retval) override; \
  NS_IMETHOD GetFailoverForProxy(nsIProxyInfo *aProxyInfo, nsIURI *aURI, nsresult aReason, nsIProxyInfo * *_retval) override; \
  NS_IMETHOD RegisterFilter(nsIProtocolProxyFilter *aFilter, uint32_t aPosition) override; \
  NS_IMETHOD RegisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter, uint32_t aPosition) override; \
  NS_IMETHOD UnregisterFilter(nsIProtocolProxyFilter *aFilter) override; \
  NS_IMETHOD UnregisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter) override; \
  NS_IMETHOD GetProxyConfigType(uint32_t *aProxyConfigType) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLPROXYSERVICE(_to) \
  NS_IMETHOD AsyncResolve(nsISupports *aChannelOrURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval) override { return _to AsyncResolve(aChannelOrURI, aFlags, aCallback, _retval); } \
  NS_IMETHOD NewProxyInfo(const nsACString & aType, const nsACString & aHost, int32_t aPort, uint32_t aFlags, uint32_t aFailoverTimeout, nsIProxyInfo *aFailoverProxy, nsIProxyInfo * *_retval) override { return _to NewProxyInfo(aType, aHost, aPort, aFlags, aFailoverTimeout, aFailoverProxy, _retval); } \
  NS_IMETHOD GetFailoverForProxy(nsIProxyInfo *aProxyInfo, nsIURI *aURI, nsresult aReason, nsIProxyInfo * *_retval) override { return _to GetFailoverForProxy(aProxyInfo, aURI, aReason, _retval); } \
  NS_IMETHOD RegisterFilter(nsIProtocolProxyFilter *aFilter, uint32_t aPosition) override { return _to RegisterFilter(aFilter, aPosition); } \
  NS_IMETHOD RegisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter, uint32_t aPosition) override { return _to RegisterChannelFilter(aFilter, aPosition); } \
  NS_IMETHOD UnregisterFilter(nsIProtocolProxyFilter *aFilter) override { return _to UnregisterFilter(aFilter); } \
  NS_IMETHOD UnregisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter) override { return _to UnregisterChannelFilter(aFilter); } \
  NS_IMETHOD GetProxyConfigType(uint32_t *aProxyConfigType) override { return _to GetProxyConfigType(aProxyConfigType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLPROXYSERVICE(_to) \
  NS_IMETHOD AsyncResolve(nsISupports *aChannelOrURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncResolve(aChannelOrURI, aFlags, aCallback, _retval); } \
  NS_IMETHOD NewProxyInfo(const nsACString & aType, const nsACString & aHost, int32_t aPort, uint32_t aFlags, uint32_t aFailoverTimeout, nsIProxyInfo *aFailoverProxy, nsIProxyInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewProxyInfo(aType, aHost, aPort, aFlags, aFailoverTimeout, aFailoverProxy, _retval); } \
  NS_IMETHOD GetFailoverForProxy(nsIProxyInfo *aProxyInfo, nsIURI *aURI, nsresult aReason, nsIProxyInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFailoverForProxy(aProxyInfo, aURI, aReason, _retval); } \
  NS_IMETHOD RegisterFilter(nsIProtocolProxyFilter *aFilter, uint32_t aPosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterFilter(aFilter, aPosition); } \
  NS_IMETHOD RegisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter, uint32_t aPosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterChannelFilter(aFilter, aPosition); } \
  NS_IMETHOD UnregisterFilter(nsIProtocolProxyFilter *aFilter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterFilter(aFilter); } \
  NS_IMETHOD UnregisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterChannelFilter(aFilter); } \
  NS_IMETHOD GetProxyConfigType(uint32_t *aProxyConfigType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProxyConfigType(aProxyConfigType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolProxyService : public nsIProtocolProxyService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLPROXYSERVICE

  nsProtocolProxyService();

private:
  ~nsProtocolProxyService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProtocolProxyService, nsIProtocolProxyService)

nsProtocolProxyService::nsProtocolProxyService()
{
  /* member initializers and constructor code */
}

nsProtocolProxyService::~nsProtocolProxyService()
{
  /* destructor code */
}

/* nsICancelable asyncResolve (in nsISupports aChannelOrURI, in unsigned long aFlags, in nsIProtocolProxyCallback aCallback); */
NS_IMETHODIMP nsProtocolProxyService::AsyncResolve(nsISupports *aChannelOrURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIProxyInfo newProxyInfo (in ACString aType, in AUTF8String aHost, in long aPort, in unsigned long aFlags, in unsigned long aFailoverTimeout, in nsIProxyInfo aFailoverProxy); */
NS_IMETHODIMP nsProtocolProxyService::NewProxyInfo(const nsACString & aType, const nsACString & aHost, int32_t aPort, uint32_t aFlags, uint32_t aFailoverTimeout, nsIProxyInfo *aFailoverProxy, nsIProxyInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIProxyInfo getFailoverForProxy (in nsIProxyInfo aProxyInfo, in nsIURI aURI, in nsresult aReason); */
NS_IMETHODIMP nsProtocolProxyService::GetFailoverForProxy(nsIProxyInfo *aProxyInfo, nsIURI *aURI, nsresult aReason, nsIProxyInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerFilter (in nsIProtocolProxyFilter aFilter, in unsigned long aPosition); */
NS_IMETHODIMP nsProtocolProxyService::RegisterFilter(nsIProtocolProxyFilter *aFilter, uint32_t aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerChannelFilter (in nsIProtocolProxyChannelFilter aFilter, in unsigned long aPosition); */
NS_IMETHODIMP nsProtocolProxyService::RegisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter, uint32_t aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterFilter (in nsIProtocolProxyFilter aFilter); */
NS_IMETHODIMP nsProtocolProxyService::UnregisterFilter(nsIProtocolProxyFilter *aFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterChannelFilter (in nsIProtocolProxyChannelFilter aFilter); */
NS_IMETHODIMP nsProtocolProxyService::UnregisterChannelFilter(nsIProtocolProxyChannelFilter *aFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long proxyConfigType; */
NS_IMETHODIMP nsProtocolProxyService::GetProxyConfigType(uint32_t *aProxyConfigType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProtocolProxyService_h__ */
