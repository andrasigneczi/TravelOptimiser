/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHttpChannelInternal.idl
 */

#ifndef __gen_nsIHttpChannelInternal_h__
#define __gen_nsIHttpChannelInternal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
template<class T> class nsTArray;
template<class T> class nsCOMArray;
class nsCString;
class nsIAsyncInputStream; /* forward declaration */

class nsIAsyncOutputStream; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsISecurityConsoleMessage; /* forward declaration */

class nsISocketTransport; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIHttpUpgradeListener */
#define NS_IHTTPUPGRADELISTENER_IID_STR "7b48d081-1dc1-4d08-b7a5-81491bf28c0e"

#define NS_IHTTPUPGRADELISTENER_IID \
  {0x7b48d081, 0x1dc1, 0x4d08, \
    { 0xb7, 0xa5, 0x81, 0x49, 0x1b, 0xf2, 0x8c, 0x0e }}

class NS_NO_VTABLE nsIHttpUpgradeListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPUPGRADELISTENER_IID)

  /* void onTransportAvailable (in nsISocketTransport aTransport, in nsIAsyncInputStream aSocketIn, in nsIAsyncOutputStream aSocketOut); */
  NS_IMETHOD OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpUpgradeListener, NS_IHTTPUPGRADELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPUPGRADELISTENER \
  NS_IMETHOD OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPUPGRADELISTENER(_to) \
  NS_IMETHOD OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut) override { return _to OnTransportAvailable(aTransport, aSocketIn, aSocketOut); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPUPGRADELISTENER(_to) \
  NS_IMETHOD OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTransportAvailable(aTransport, aSocketIn, aSocketOut); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpUpgradeListener : public nsIHttpUpgradeListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPUPGRADELISTENER

  nsHttpUpgradeListener();

private:
  ~nsHttpUpgradeListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsHttpUpgradeListener, nsIHttpUpgradeListener)

nsHttpUpgradeListener::nsHttpUpgradeListener()
{
  /* member initializers and constructor code */
}

nsHttpUpgradeListener::~nsHttpUpgradeListener()
{
  /* destructor code */
}

/* void onTransportAvailable (in nsISocketTransport aTransport, in nsIAsyncInputStream aSocketIn, in nsIAsyncOutputStream aSocketOut); */
NS_IMETHODIMP nsHttpUpgradeListener::OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHttpChannelInternal */
#define NS_IHTTPCHANNELINTERNAL_IID_STR "26833ec7-4555-4f23-9281-3a12d4b76db1"

#define NS_IHTTPCHANNELINTERNAL_IID \
  {0x26833ec7, 0x4555, 0x4f23, \
    { 0x92, 0x81, 0x3a, 0x12, 0xd4, 0xb7, 0x6d, 0xb1 }}

class NS_NO_VTABLE nsIHttpChannelInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPCHANNELINTERNAL_IID)

  /* attribute nsIURI documentURI; */
  NS_IMETHOD GetDocumentURI(nsIURI * *aDocumentURI) = 0;
  NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) = 0;

  /* void getRequestVersion (out unsigned long major, out unsigned long minor); */
  NS_IMETHOD GetRequestVersion(uint32_t *major, uint32_t *minor) = 0;

  /* void getResponseVersion (out unsigned long major, out unsigned long minor); */
  NS_IMETHOD GetResponseVersion(uint32_t *major, uint32_t *minor) = 0;

  /* [noscript] void takeAllSecurityMessages (in securityMessagesArray aMessages); */
  NS_IMETHOD TakeAllSecurityMessages(nsCOMArray<nsISecurityConsoleMessage> & aMessages) = 0;

  /* void setCookie (in string aCookieHeader); */
  NS_IMETHOD SetCookie(const char * aCookieHeader) = 0;

  /* void setupFallbackChannel (in string aFallbackKey); */
  NS_IMETHOD SetupFallbackChannel(const char * aFallbackKey) = 0;

  enum {
    THIRD_PARTY_FORCE_ALLOW = 1U,
    THIRD_PARTY_PARENT_IS_THIRD_PARTY = 2U,
    THIRD_PARTY_PARENT_IS_SAME_PARTY = 4U
  };

  /* attribute unsigned long thirdPartyFlags; */
  NS_IMETHOD GetThirdPartyFlags(uint32_t *aThirdPartyFlags) = 0;
  NS_IMETHOD SetThirdPartyFlags(uint32_t aThirdPartyFlags) = 0;

  /* attribute boolean forceAllowThirdPartyCookie; */
  NS_IMETHOD GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie) = 0;
  NS_IMETHOD SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie) = 0;

  /* readonly attribute boolean canceled; */
  NS_IMETHOD GetCanceled(bool *aCanceled) = 0;

  /* attribute boolean channelIsForDownload; */
  NS_IMETHOD GetChannelIsForDownload(bool *aChannelIsForDownload) = 0;
  NS_IMETHOD SetChannelIsForDownload(bool aChannelIsForDownload) = 0;

  /* readonly attribute AUTF8String localAddress; */
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) = 0;

  /* readonly attribute int32_t localPort; */
  NS_IMETHOD GetLocalPort(int32_t *aLocalPort) = 0;

  /* readonly attribute AUTF8String remoteAddress; */
  NS_IMETHOD GetRemoteAddress(nsACString & aRemoteAddress) = 0;

  /* readonly attribute int32_t remotePort; */
  NS_IMETHOD GetRemotePort(int32_t *aRemotePort) = 0;

  /* [noscript] void setCacheKeysRedirectChain (in StringArray cacheKeys); */
  NS_IMETHOD SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys) = 0;

  /* void HTTPUpgrade (in ACString aProtocolName, in nsIHttpUpgradeListener aListener); */
  NS_IMETHOD HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener) = 0;

  /* attribute boolean allowSpdy; */
  NS_IMETHOD GetAllowSpdy(bool *aAllowSpdy) = 0;
  NS_IMETHOD SetAllowSpdy(bool aAllowSpdy) = 0;

  /* attribute boolean responseTimeoutEnabled; */
  NS_IMETHOD GetResponseTimeoutEnabled(bool *aResponseTimeoutEnabled) = 0;
  NS_IMETHOD SetResponseTimeoutEnabled(bool aResponseTimeoutEnabled) = 0;

  /* readonly attribute nsIURI apiRedirectToURI; */
  NS_IMETHOD GetApiRedirectToURI(nsIURI * *aApiRedirectToURI) = 0;

  /* attribute boolean allowAltSvc; */
  NS_IMETHOD GetAllowAltSvc(bool *aAllowAltSvc) = 0;
  NS_IMETHOD SetAllowAltSvc(bool aAllowAltSvc) = 0;

  /* void addRedirect (in nsIPrincipal aPrincipal); */
  NS_IMETHOD AddRedirect(nsIPrincipal *aPrincipal) = 0;

  /* readonly attribute PRTime lastModifiedTime; */
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) = 0;

  /* void forceNoIntercept (); */
  NS_IMETHOD ForceNoIntercept(void) = 0;

  /* attribute boolean corsIncludeCredentials; */
  NS_IMETHOD GetCorsIncludeCredentials(bool *aCorsIncludeCredentials) = 0;
  NS_IMETHOD SetCorsIncludeCredentials(bool aCorsIncludeCredentials) = 0;

  enum {
    CORS_MODE_SAME_ORIGIN = 0U,
    CORS_MODE_NO_CORS = 1U,
    CORS_MODE_CORS = 2U,
    CORS_MODE_CORS_WITH_FORCED_PREFLIGHT = 3U
  };

  /* attribute unsigned long corsMode; */
  NS_IMETHOD GetCorsMode(uint32_t *aCorsMode) = 0;
  NS_IMETHOD SetCorsMode(uint32_t aCorsMode) = 0;

  /* readonly attribute nsIURI topWindowURI; */
  NS_IMETHOD GetTopWindowURI(nsIURI * *aTopWindowURI) = 0;

  /* attribute ACString networkInterfaceId; */
  NS_IMETHOD GetNetworkInterfaceId(nsACString & aNetworkInterfaceId) = 0;
  NS_IMETHOD SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId) = 0;

  /* void continueBeginConnect (); */
  NS_IMETHOD ContinueBeginConnect(void) = 0;

  /* readonly attribute nsIURI proxyURI; */
  NS_IMETHOD GetProxyURI(nsIURI * *aProxyURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpChannelInternal, NS_IHTTPCHANNELINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPCHANNELINTERNAL \
  NS_IMETHOD GetDocumentURI(nsIURI * *aDocumentURI) override; \
  NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) override; \
  NS_IMETHOD GetRequestVersion(uint32_t *major, uint32_t *minor) override; \
  NS_IMETHOD GetResponseVersion(uint32_t *major, uint32_t *minor) override; \
  NS_IMETHOD TakeAllSecurityMessages(nsCOMArray<nsISecurityConsoleMessage> & aMessages) override; \
  NS_IMETHOD SetCookie(const char * aCookieHeader) override; \
  NS_IMETHOD SetupFallbackChannel(const char * aFallbackKey) override; \
  NS_IMETHOD GetThirdPartyFlags(uint32_t *aThirdPartyFlags) override; \
  NS_IMETHOD SetThirdPartyFlags(uint32_t aThirdPartyFlags) override; \
  NS_IMETHOD GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie) override; \
  NS_IMETHOD SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie) override; \
  NS_IMETHOD GetCanceled(bool *aCanceled) override; \
  NS_IMETHOD GetChannelIsForDownload(bool *aChannelIsForDownload) override; \
  NS_IMETHOD SetChannelIsForDownload(bool aChannelIsForDownload) override; \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) override; \
  NS_IMETHOD GetLocalPort(int32_t *aLocalPort) override; \
  NS_IMETHOD GetRemoteAddress(nsACString & aRemoteAddress) override; \
  NS_IMETHOD GetRemotePort(int32_t *aRemotePort) override; \
  NS_IMETHOD SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys) override; \
  NS_IMETHOD HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener) override; \
  NS_IMETHOD GetAllowSpdy(bool *aAllowSpdy) override; \
  NS_IMETHOD SetAllowSpdy(bool aAllowSpdy) override; \
  NS_IMETHOD GetResponseTimeoutEnabled(bool *aResponseTimeoutEnabled) override; \
  NS_IMETHOD SetResponseTimeoutEnabled(bool aResponseTimeoutEnabled) override; \
  NS_IMETHOD GetApiRedirectToURI(nsIURI * *aApiRedirectToURI) override; \
  NS_IMETHOD GetAllowAltSvc(bool *aAllowAltSvc) override; \
  NS_IMETHOD SetAllowAltSvc(bool aAllowAltSvc) override; \
  NS_IMETHOD AddRedirect(nsIPrincipal *aPrincipal) override; \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) override; \
  NS_IMETHOD ForceNoIntercept(void) override; \
  NS_IMETHOD GetCorsIncludeCredentials(bool *aCorsIncludeCredentials) override; \
  NS_IMETHOD SetCorsIncludeCredentials(bool aCorsIncludeCredentials) override; \
  NS_IMETHOD GetCorsMode(uint32_t *aCorsMode) override; \
  NS_IMETHOD SetCorsMode(uint32_t aCorsMode) override; \
  NS_IMETHOD GetTopWindowURI(nsIURI * *aTopWindowURI) override; \
  NS_IMETHOD GetNetworkInterfaceId(nsACString & aNetworkInterfaceId) override; \
  NS_IMETHOD SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId) override; \
  NS_IMETHOD ContinueBeginConnect(void) override; \
  NS_IMETHOD GetProxyURI(nsIURI * *aProxyURI) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPCHANNELINTERNAL(_to) \
  NS_IMETHOD GetDocumentURI(nsIURI * *aDocumentURI) override { return _to GetDocumentURI(aDocumentURI); } \
  NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) override { return _to SetDocumentURI(aDocumentURI); } \
  NS_IMETHOD GetRequestVersion(uint32_t *major, uint32_t *minor) override { return _to GetRequestVersion(major, minor); } \
  NS_IMETHOD GetResponseVersion(uint32_t *major, uint32_t *minor) override { return _to GetResponseVersion(major, minor); } \
  NS_IMETHOD TakeAllSecurityMessages(nsCOMArray<nsISecurityConsoleMessage> & aMessages) override { return _to TakeAllSecurityMessages(aMessages); } \
  NS_IMETHOD SetCookie(const char * aCookieHeader) override { return _to SetCookie(aCookieHeader); } \
  NS_IMETHOD SetupFallbackChannel(const char * aFallbackKey) override { return _to SetupFallbackChannel(aFallbackKey); } \
  NS_IMETHOD GetThirdPartyFlags(uint32_t *aThirdPartyFlags) override { return _to GetThirdPartyFlags(aThirdPartyFlags); } \
  NS_IMETHOD SetThirdPartyFlags(uint32_t aThirdPartyFlags) override { return _to SetThirdPartyFlags(aThirdPartyFlags); } \
  NS_IMETHOD GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie) override { return _to GetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_IMETHOD SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie) override { return _to SetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_IMETHOD GetCanceled(bool *aCanceled) override { return _to GetCanceled(aCanceled); } \
  NS_IMETHOD GetChannelIsForDownload(bool *aChannelIsForDownload) override { return _to GetChannelIsForDownload(aChannelIsForDownload); } \
  NS_IMETHOD SetChannelIsForDownload(bool aChannelIsForDownload) override { return _to SetChannelIsForDownload(aChannelIsForDownload); } \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) override { return _to GetLocalAddress(aLocalAddress); } \
  NS_IMETHOD GetLocalPort(int32_t *aLocalPort) override { return _to GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetRemoteAddress(nsACString & aRemoteAddress) override { return _to GetRemoteAddress(aRemoteAddress); } \
  NS_IMETHOD GetRemotePort(int32_t *aRemotePort) override { return _to GetRemotePort(aRemotePort); } \
  NS_IMETHOD SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys) override { return _to SetCacheKeysRedirectChain(cacheKeys); } \
  NS_IMETHOD HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener) override { return _to HTTPUpgrade(aProtocolName, aListener); } \
  NS_IMETHOD GetAllowSpdy(bool *aAllowSpdy) override { return _to GetAllowSpdy(aAllowSpdy); } \
  NS_IMETHOD SetAllowSpdy(bool aAllowSpdy) override { return _to SetAllowSpdy(aAllowSpdy); } \
  NS_IMETHOD GetResponseTimeoutEnabled(bool *aResponseTimeoutEnabled) override { return _to GetResponseTimeoutEnabled(aResponseTimeoutEnabled); } \
  NS_IMETHOD SetResponseTimeoutEnabled(bool aResponseTimeoutEnabled) override { return _to SetResponseTimeoutEnabled(aResponseTimeoutEnabled); } \
  NS_IMETHOD GetApiRedirectToURI(nsIURI * *aApiRedirectToURI) override { return _to GetApiRedirectToURI(aApiRedirectToURI); } \
  NS_IMETHOD GetAllowAltSvc(bool *aAllowAltSvc) override { return _to GetAllowAltSvc(aAllowAltSvc); } \
  NS_IMETHOD SetAllowAltSvc(bool aAllowAltSvc) override { return _to SetAllowAltSvc(aAllowAltSvc); } \
  NS_IMETHOD AddRedirect(nsIPrincipal *aPrincipal) override { return _to AddRedirect(aPrincipal); } \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) override { return _to GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD ForceNoIntercept(void) override { return _to ForceNoIntercept(); } \
  NS_IMETHOD GetCorsIncludeCredentials(bool *aCorsIncludeCredentials) override { return _to GetCorsIncludeCredentials(aCorsIncludeCredentials); } \
  NS_IMETHOD SetCorsIncludeCredentials(bool aCorsIncludeCredentials) override { return _to SetCorsIncludeCredentials(aCorsIncludeCredentials); } \
  NS_IMETHOD GetCorsMode(uint32_t *aCorsMode) override { return _to GetCorsMode(aCorsMode); } \
  NS_IMETHOD SetCorsMode(uint32_t aCorsMode) override { return _to SetCorsMode(aCorsMode); } \
  NS_IMETHOD GetTopWindowURI(nsIURI * *aTopWindowURI) override { return _to GetTopWindowURI(aTopWindowURI); } \
  NS_IMETHOD GetNetworkInterfaceId(nsACString & aNetworkInterfaceId) override { return _to GetNetworkInterfaceId(aNetworkInterfaceId); } \
  NS_IMETHOD SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId) override { return _to SetNetworkInterfaceId(aNetworkInterfaceId); } \
  NS_IMETHOD ContinueBeginConnect(void) override { return _to ContinueBeginConnect(); } \
  NS_IMETHOD GetProxyURI(nsIURI * *aProxyURI) override { return _to GetProxyURI(aProxyURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPCHANNELINTERNAL(_to) \
  NS_IMETHOD GetDocumentURI(nsIURI * *aDocumentURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentURI(aDocumentURI); } \
  NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentURI(aDocumentURI); } \
  NS_IMETHOD GetRequestVersion(uint32_t *major, uint32_t *minor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestVersion(major, minor); } \
  NS_IMETHOD GetResponseVersion(uint32_t *major, uint32_t *minor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseVersion(major, minor); } \
  NS_IMETHOD TakeAllSecurityMessages(nsCOMArray<nsISecurityConsoleMessage> & aMessages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TakeAllSecurityMessages(aMessages); } \
  NS_IMETHOD SetCookie(const char * aCookieHeader) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCookie(aCookieHeader); } \
  NS_IMETHOD SetupFallbackChannel(const char * aFallbackKey) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetupFallbackChannel(aFallbackKey); } \
  NS_IMETHOD GetThirdPartyFlags(uint32_t *aThirdPartyFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThirdPartyFlags(aThirdPartyFlags); } \
  NS_IMETHOD SetThirdPartyFlags(uint32_t aThirdPartyFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetThirdPartyFlags(aThirdPartyFlags); } \
  NS_IMETHOD GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_IMETHOD SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_IMETHOD GetCanceled(bool *aCanceled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanceled(aCanceled); } \
  NS_IMETHOD GetChannelIsForDownload(bool *aChannelIsForDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelIsForDownload(aChannelIsForDownload); } \
  NS_IMETHOD SetChannelIsForDownload(bool aChannelIsForDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChannelIsForDownload(aChannelIsForDownload); } \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalAddress(aLocalAddress); } \
  NS_IMETHOD GetLocalPort(int32_t *aLocalPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetRemoteAddress(nsACString & aRemoteAddress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemoteAddress(aRemoteAddress); } \
  NS_IMETHOD GetRemotePort(int32_t *aRemotePort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemotePort(aRemotePort); } \
  NS_IMETHOD SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheKeysRedirectChain(cacheKeys); } \
  NS_IMETHOD HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HTTPUpgrade(aProtocolName, aListener); } \
  NS_IMETHOD GetAllowSpdy(bool *aAllowSpdy) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowSpdy(aAllowSpdy); } \
  NS_IMETHOD SetAllowSpdy(bool aAllowSpdy) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowSpdy(aAllowSpdy); } \
  NS_IMETHOD GetResponseTimeoutEnabled(bool *aResponseTimeoutEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseTimeoutEnabled(aResponseTimeoutEnabled); } \
  NS_IMETHOD SetResponseTimeoutEnabled(bool aResponseTimeoutEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResponseTimeoutEnabled(aResponseTimeoutEnabled); } \
  NS_IMETHOD GetApiRedirectToURI(nsIURI * *aApiRedirectToURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApiRedirectToURI(aApiRedirectToURI); } \
  NS_IMETHOD GetAllowAltSvc(bool *aAllowAltSvc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowAltSvc(aAllowAltSvc); } \
  NS_IMETHOD SetAllowAltSvc(bool aAllowAltSvc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowAltSvc(aAllowAltSvc); } \
  NS_IMETHOD AddRedirect(nsIPrincipal *aPrincipal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddRedirect(aPrincipal); } \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD ForceNoIntercept(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceNoIntercept(); } \
  NS_IMETHOD GetCorsIncludeCredentials(bool *aCorsIncludeCredentials) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCorsIncludeCredentials(aCorsIncludeCredentials); } \
  NS_IMETHOD SetCorsIncludeCredentials(bool aCorsIncludeCredentials) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCorsIncludeCredentials(aCorsIncludeCredentials); } \
  NS_IMETHOD GetCorsMode(uint32_t *aCorsMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCorsMode(aCorsMode); } \
  NS_IMETHOD SetCorsMode(uint32_t aCorsMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCorsMode(aCorsMode); } \
  NS_IMETHOD GetTopWindowURI(nsIURI * *aTopWindowURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTopWindowURI(aTopWindowURI); } \
  NS_IMETHOD GetNetworkInterfaceId(nsACString & aNetworkInterfaceId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetworkInterfaceId(aNetworkInterfaceId); } \
  NS_IMETHOD SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNetworkInterfaceId(aNetworkInterfaceId); } \
  NS_IMETHOD ContinueBeginConnect(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ContinueBeginConnect(); } \
  NS_IMETHOD GetProxyURI(nsIURI * *aProxyURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProxyURI(aProxyURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpChannelInternal : public nsIHttpChannelInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPCHANNELINTERNAL

  nsHttpChannelInternal();

private:
  ~nsHttpChannelInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsHttpChannelInternal, nsIHttpChannelInternal)

nsHttpChannelInternal::nsHttpChannelInternal()
{
  /* member initializers and constructor code */
}

nsHttpChannelInternal::~nsHttpChannelInternal()
{
  /* destructor code */
}

/* attribute nsIURI documentURI; */
NS_IMETHODIMP nsHttpChannelInternal::GetDocumentURI(nsIURI * *aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetDocumentURI(nsIURI *aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRequestVersion (out unsigned long major, out unsigned long minor); */
NS_IMETHODIMP nsHttpChannelInternal::GetRequestVersion(uint32_t *major, uint32_t *minor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getResponseVersion (out unsigned long major, out unsigned long minor); */
NS_IMETHODIMP nsHttpChannelInternal::GetResponseVersion(uint32_t *major, uint32_t *minor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void takeAllSecurityMessages (in securityMessagesArray aMessages); */
NS_IMETHODIMP nsHttpChannelInternal::TakeAllSecurityMessages(nsCOMArray<nsISecurityConsoleMessage> & aMessages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCookie (in string aCookieHeader); */
NS_IMETHODIMP nsHttpChannelInternal::SetCookie(const char * aCookieHeader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setupFallbackChannel (in string aFallbackKey); */
NS_IMETHODIMP nsHttpChannelInternal::SetupFallbackChannel(const char * aFallbackKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long thirdPartyFlags; */
NS_IMETHODIMP nsHttpChannelInternal::GetThirdPartyFlags(uint32_t *aThirdPartyFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetThirdPartyFlags(uint32_t aThirdPartyFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean forceAllowThirdPartyCookie; */
NS_IMETHODIMP nsHttpChannelInternal::GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canceled; */
NS_IMETHODIMP nsHttpChannelInternal::GetCanceled(bool *aCanceled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean channelIsForDownload; */
NS_IMETHODIMP nsHttpChannelInternal::GetChannelIsForDownload(bool *aChannelIsForDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetChannelIsForDownload(bool aChannelIsForDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String localAddress; */
NS_IMETHODIMP nsHttpChannelInternal::GetLocalAddress(nsACString & aLocalAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t localPort; */
NS_IMETHODIMP nsHttpChannelInternal::GetLocalPort(int32_t *aLocalPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String remoteAddress; */
NS_IMETHODIMP nsHttpChannelInternal::GetRemoteAddress(nsACString & aRemoteAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t remotePort; */
NS_IMETHODIMP nsHttpChannelInternal::GetRemotePort(int32_t *aRemotePort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setCacheKeysRedirectChain (in StringArray cacheKeys); */
NS_IMETHODIMP nsHttpChannelInternal::SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HTTPUpgrade (in ACString aProtocolName, in nsIHttpUpgradeListener aListener); */
NS_IMETHODIMP nsHttpChannelInternal::HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowSpdy; */
NS_IMETHODIMP nsHttpChannelInternal::GetAllowSpdy(bool *aAllowSpdy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetAllowSpdy(bool aAllowSpdy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean responseTimeoutEnabled; */
NS_IMETHODIMP nsHttpChannelInternal::GetResponseTimeoutEnabled(bool *aResponseTimeoutEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetResponseTimeoutEnabled(bool aResponseTimeoutEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI apiRedirectToURI; */
NS_IMETHODIMP nsHttpChannelInternal::GetApiRedirectToURI(nsIURI * *aApiRedirectToURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowAltSvc; */
NS_IMETHODIMP nsHttpChannelInternal::GetAllowAltSvc(bool *aAllowAltSvc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetAllowAltSvc(bool aAllowAltSvc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addRedirect (in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsHttpChannelInternal::AddRedirect(nsIPrincipal *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModifiedTime; */
NS_IMETHODIMP nsHttpChannelInternal::GetLastModifiedTime(PRTime *aLastModifiedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceNoIntercept (); */
NS_IMETHODIMP nsHttpChannelInternal::ForceNoIntercept()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean corsIncludeCredentials; */
NS_IMETHODIMP nsHttpChannelInternal::GetCorsIncludeCredentials(bool *aCorsIncludeCredentials)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetCorsIncludeCredentials(bool aCorsIncludeCredentials)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long corsMode; */
NS_IMETHODIMP nsHttpChannelInternal::GetCorsMode(uint32_t *aCorsMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetCorsMode(uint32_t aCorsMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI topWindowURI; */
NS_IMETHODIMP nsHttpChannelInternal::GetTopWindowURI(nsIURI * *aTopWindowURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString networkInterfaceId; */
NS_IMETHODIMP nsHttpChannelInternal::GetNetworkInterfaceId(nsACString & aNetworkInterfaceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void continueBeginConnect (); */
NS_IMETHODIMP nsHttpChannelInternal::ContinueBeginConnect()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI proxyURI; */
NS_IMETHODIMP nsHttpChannelInternal::GetProxyURI(nsIURI * *aProxyURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpChannelInternal_h__ */
