/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIOService.idl
 */

#ifndef __gen_nsIIOService_h__
#define __gen_nsIIOService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIProtocolHandler; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsILoadInfo; /* forward declaration */


/* starting interface:    nsIIOService */
#define NS_IIOSERVICE_IID_STR "4286de5a-b2ea-446f-8f70-e2a461f42694"

#define NS_IIOSERVICE_IID \
  {0x4286de5a, 0xb2ea, 0x446f, \
    { 0x8f, 0x70, 0xe2, 0xa4, 0x61, 0xf4, 0x26, 0x94 }}

class NS_NO_VTABLE nsIIOService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIOSERVICE_IID)

  /* nsIProtocolHandler getProtocolHandler (in string aScheme); */
  NS_IMETHOD GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval) = 0;

  /* unsigned long getProtocolFlags (in string aScheme); */
  NS_IMETHOD GetProtocolFlags(const char * aScheme, uint32_t *_retval) = 0;

  /* nsIURI newURI (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) = 0;

  /* nsIURI newFileURI (in nsIFile aFile); */
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) = 0;

  /* nsIChannel newChannelFromURI2 (in nsIURI aURI, in nsIDOMNode aLoadingNode, in nsIPrincipal aLoadingPrincipal, in nsIPrincipal aTriggeringPrincipal, in unsigned long aSecurityFlags, in unsigned long aContentPolicyType); */
  NS_IMETHOD NewChannelFromURI2(nsIURI *aURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) = 0;

  /* nsIChannel newChannelFromURIWithLoadInfo (in nsIURI aURI, in nsILoadInfo aLoadInfo); */
  NS_IMETHOD NewChannelFromURIWithLoadInfo(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) = 0;

  /* nsIChannel newChannelFromURI (in nsIURI aURI); */
  NS_IMETHOD NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval) = 0;

  /* nsIChannel newChannel2 (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI, in nsIDOMNode aLoadingNode, in nsIPrincipal aLoadingPrincipal, in nsIPrincipal aTriggeringPrincipal, in unsigned long aSecurityFlags, in unsigned long aContentPolicyType); */
  NS_IMETHOD NewChannel2(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) = 0;

  /* nsIChannel newChannel (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
  NS_IMETHOD NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval) = 0;

  /* attribute boolean offline; */
  NS_IMETHOD GetOffline(bool *aOffline) = 0;
  NS_IMETHOD SetOffline(bool aOffline) = 0;

  /* readonly attribute boolean connectivity; */
  NS_IMETHOD GetConnectivity(bool *aConnectivity) = 0;

  /* void setAppOffline (in uint32_t appId, in long state); */
  NS_IMETHOD SetAppOffline(uint32_t appId, int32_t state) = 0;

  /* boolean isAppOffline (in uint32_t appId); */
  NS_IMETHOD IsAppOffline(uint32_t appId, bool *_retval) = 0;

  /* long getAppOfflineState (in uint32_t appId); */
  NS_IMETHOD GetAppOfflineState(uint32_t appId, int32_t *_retval) = 0;

  /* boolean allowPort (in long aPort, in string aScheme); */
  NS_IMETHOD AllowPort(int32_t aPort, const char * aScheme, bool *_retval) = 0;

  /* ACString extractScheme (in AUTF8String urlString); */
  NS_IMETHOD ExtractScheme(const nsACString & urlString, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIOService, NS_IIOSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIOSERVICE \
  NS_IMETHOD GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval) override; \
  NS_IMETHOD GetProtocolFlags(const char * aScheme, uint32_t *_retval) override; \
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) override; \
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) override; \
  NS_IMETHOD NewChannelFromURI2(nsIURI *aURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) override; \
  NS_IMETHOD NewChannelFromURIWithLoadInfo(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) override; \
  NS_IMETHOD NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval) override; \
  NS_IMETHOD NewChannel2(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) override; \
  NS_IMETHOD NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval) override; \
  NS_IMETHOD GetOffline(bool *aOffline) override; \
  NS_IMETHOD SetOffline(bool aOffline) override; \
  NS_IMETHOD GetConnectivity(bool *aConnectivity) override; \
  NS_IMETHOD SetAppOffline(uint32_t appId, int32_t state) override; \
  NS_IMETHOD IsAppOffline(uint32_t appId, bool *_retval) override; \
  NS_IMETHOD GetAppOfflineState(uint32_t appId, int32_t *_retval) override; \
  NS_IMETHOD AllowPort(int32_t aPort, const char * aScheme, bool *_retval) override; \
  NS_IMETHOD ExtractScheme(const nsACString & urlString, nsACString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIOSERVICE(_to) \
  NS_IMETHOD GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval) override { return _to GetProtocolHandler(aScheme, _retval); } \
  NS_IMETHOD GetProtocolFlags(const char * aScheme, uint32_t *_retval) override { return _to GetProtocolFlags(aScheme, _retval); } \
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) override { return _to NewURI(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) override { return _to NewFileURI(aFile, _retval); } \
  NS_IMETHOD NewChannelFromURI2(nsIURI *aURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) override { return _to NewChannelFromURI2(aURI, aLoadingNode, aLoadingPrincipal, aTriggeringPrincipal, aSecurityFlags, aContentPolicyType, _retval); } \
  NS_IMETHOD NewChannelFromURIWithLoadInfo(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) override { return _to NewChannelFromURIWithLoadInfo(aURI, aLoadInfo, _retval); } \
  NS_IMETHOD NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval) override { return _to NewChannelFromURI(aURI, _retval); } \
  NS_IMETHOD NewChannel2(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) override { return _to NewChannel2(aSpec, aOriginCharset, aBaseURI, aLoadingNode, aLoadingPrincipal, aTriggeringPrincipal, aSecurityFlags, aContentPolicyType, _retval); } \
  NS_IMETHOD NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval) override { return _to NewChannel(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD GetOffline(bool *aOffline) override { return _to GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) override { return _to SetOffline(aOffline); } \
  NS_IMETHOD GetConnectivity(bool *aConnectivity) override { return _to GetConnectivity(aConnectivity); } \
  NS_IMETHOD SetAppOffline(uint32_t appId, int32_t state) override { return _to SetAppOffline(appId, state); } \
  NS_IMETHOD IsAppOffline(uint32_t appId, bool *_retval) override { return _to IsAppOffline(appId, _retval); } \
  NS_IMETHOD GetAppOfflineState(uint32_t appId, int32_t *_retval) override { return _to GetAppOfflineState(appId, _retval); } \
  NS_IMETHOD AllowPort(int32_t aPort, const char * aScheme, bool *_retval) override { return _to AllowPort(aPort, aScheme, _retval); } \
  NS_IMETHOD ExtractScheme(const nsACString & urlString, nsACString & _retval) override { return _to ExtractScheme(urlString, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIOSERVICE(_to) \
  NS_IMETHOD GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocolHandler(aScheme, _retval); } \
  NS_IMETHOD GetProtocolFlags(const char * aScheme, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocolFlags(aScheme, _retval); } \
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewURI(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewFileURI(aFile, _retval); } \
  NS_IMETHOD NewChannelFromURI2(nsIURI *aURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannelFromURI2(aURI, aLoadingNode, aLoadingPrincipal, aTriggeringPrincipal, aSecurityFlags, aContentPolicyType, _retval); } \
  NS_IMETHOD NewChannelFromURIWithLoadInfo(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannelFromURIWithLoadInfo(aURI, aLoadInfo, _retval); } \
  NS_IMETHOD NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannelFromURI(aURI, _retval); } \
  NS_IMETHOD NewChannel2(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannel2(aSpec, aOriginCharset, aBaseURI, aLoadingNode, aLoadingPrincipal, aTriggeringPrincipal, aSecurityFlags, aContentPolicyType, _retval); } \
  NS_IMETHOD NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannel(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD GetOffline(bool *aOffline) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOffline(aOffline); } \
  NS_IMETHOD GetConnectivity(bool *aConnectivity) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectivity(aConnectivity); } \
  NS_IMETHOD SetAppOffline(uint32_t appId, int32_t state) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAppOffline(appId, state); } \
  NS_IMETHOD IsAppOffline(uint32_t appId, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAppOffline(appId, _retval); } \
  NS_IMETHOD GetAppOfflineState(uint32_t appId, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppOfflineState(appId, _retval); } \
  NS_IMETHOD AllowPort(int32_t aPort, const char * aScheme, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AllowPort(aPort, aScheme, _retval); } \
  NS_IMETHOD ExtractScheme(const nsACString & urlString, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtractScheme(urlString, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIOService : public nsIIOService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIOSERVICE

  nsIOService();

private:
  ~nsIOService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsIOService, nsIIOService)

nsIOService::nsIOService()
{
  /* member initializers and constructor code */
}

nsIOService::~nsIOService()
{
  /* destructor code */
}

/* nsIProtocolHandler getProtocolHandler (in string aScheme); */
NS_IMETHODIMP nsIOService::GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getProtocolFlags (in string aScheme); */
NS_IMETHODIMP nsIOService::GetProtocolFlags(const char * aScheme, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI newURI (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
NS_IMETHODIMP nsIOService::NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI newFileURI (in nsIFile aFile); */
NS_IMETHODIMP nsIOService::NewFileURI(nsIFile *aFile, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannelFromURI2 (in nsIURI aURI, in nsIDOMNode aLoadingNode, in nsIPrincipal aLoadingPrincipal, in nsIPrincipal aTriggeringPrincipal, in unsigned long aSecurityFlags, in unsigned long aContentPolicyType); */
NS_IMETHODIMP nsIOService::NewChannelFromURI2(nsIURI *aURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannelFromURIWithLoadInfo (in nsIURI aURI, in nsILoadInfo aLoadInfo); */
NS_IMETHODIMP nsIOService::NewChannelFromURIWithLoadInfo(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannelFromURI (in nsIURI aURI); */
NS_IMETHODIMP nsIOService::NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannel2 (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI, in nsIDOMNode aLoadingNode, in nsIPrincipal aLoadingPrincipal, in nsIPrincipal aTriggeringPrincipal, in unsigned long aSecurityFlags, in unsigned long aContentPolicyType); */
NS_IMETHODIMP nsIOService::NewChannel2(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannel (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
NS_IMETHODIMP nsIOService::NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean offline; */
NS_IMETHODIMP nsIOService::GetOffline(bool *aOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIOService::SetOffline(bool aOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean connectivity; */
NS_IMETHODIMP nsIOService::GetConnectivity(bool *aConnectivity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAppOffline (in uint32_t appId, in long state); */
NS_IMETHODIMP nsIOService::SetAppOffline(uint32_t appId, int32_t state)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isAppOffline (in uint32_t appId); */
NS_IMETHODIMP nsIOService::IsAppOffline(uint32_t appId, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getAppOfflineState (in uint32_t appId); */
NS_IMETHODIMP nsIOService::GetAppOfflineState(uint32_t appId, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean allowPort (in long aPort, in string aScheme); */
NS_IMETHODIMP nsIOService::AllowPort(int32_t aPort, const char * aScheme, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString extractScheme (in AUTF8String urlString); */
NS_IMETHODIMP nsIOService::ExtractScheme(const nsACString & urlString, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAppOfflineInfo */
#define NS_IAPPOFFLINEINFO_IID_STR "4ac296a0-ca1b-44f4-8787-117a88cb70fb"

#define NS_IAPPOFFLINEINFO_IID \
  {0x4ac296a0, 0xca1b, 0x44f4, \
    { 0x87, 0x87, 0x11, 0x7a, 0x88, 0xcb, 0x70, 0xfb }}

class NS_NO_VTABLE nsIAppOfflineInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPOFFLINEINFO_IID)

  /* readonly attribute unsigned long appId; */
  NS_IMETHOD GetAppId(uint32_t *aAppId) = 0;

  enum {
    ONLINE = 1,
    OFFLINE = 2,
    WIFI_ONLY = 3
  };

  /* readonly attribute long mode; */
  NS_IMETHOD GetMode(int32_t *aMode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppOfflineInfo, NS_IAPPOFFLINEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPOFFLINEINFO \
  NS_IMETHOD GetAppId(uint32_t *aAppId) override; \
  NS_IMETHOD GetMode(int32_t *aMode) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPOFFLINEINFO(_to) \
  NS_IMETHOD GetAppId(uint32_t *aAppId) override { return _to GetAppId(aAppId); } \
  NS_IMETHOD GetMode(int32_t *aMode) override { return _to GetMode(aMode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPOFFLINEINFO(_to) \
  NS_IMETHOD GetAppId(uint32_t *aAppId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppId(aAppId); } \
  NS_IMETHOD GetMode(int32_t *aMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppOfflineInfo : public nsIAppOfflineInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPOFFLINEINFO

  nsAppOfflineInfo();

private:
  ~nsAppOfflineInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAppOfflineInfo, nsIAppOfflineInfo)

nsAppOfflineInfo::nsAppOfflineInfo()
{
  /* member initializers and constructor code */
}

nsAppOfflineInfo::~nsAppOfflineInfo()
{
  /* destructor code */
}

/* readonly attribute unsigned long appId; */
NS_IMETHODIMP nsAppOfflineInfo::GetAppId(uint32_t *aAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long mode; */
NS_IMETHODIMP nsAppOfflineInfo::GetMode(int32_t *aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * We send notifications through nsIObserverService with topic
 * NS_IOSERVICE_GOING_OFFLINE_TOPIC and data NS_IOSERVICE_OFFLINE
 * when 'offline' has changed from false to true, and we are about
 * to shut down network services such as DNS. When those
 * services have been shut down, we send a notification with
 * topic NS_IOSERVICE_OFFLINE_STATUS_TOPIC and data
 * NS_IOSERVICE_OFFLINE.
 *
 * When 'offline' changes from true to false, then after
 * network services have been restarted, we send a notification
 * with topic NS_IOSERVICE_OFFLINE_STATUS_TOPIC and data
 * NS_IOSERVICE_ONLINE.
 */
#define NS_IOSERVICE_GOING_OFFLINE_TOPIC  "network:offline-about-to-go-offline"
#define NS_IOSERVICE_OFFLINE_STATUS_TOPIC "network:offline-status-changed"
#define NS_IOSERVICE_OFFLINE              "offline"
#define NS_IOSERVICE_ONLINE               "online"
/**
 * When network:app-offline-status-changed is fired,
 * the 'Subject' argument is a nsIOfflineAppInfo.
 */
#define NS_IOSERVICE_APP_OFFLINE_STATUS_TOPIC "network:app-offline-status-changed"

/* starting interface:    nsIIOServiceInternal */
#define NS_IIOSERVICEINTERNAL_IID_STR "cd66ffef-3bc3-40de-841a-e2dcbea213a2"

#define NS_IIOSERVICEINTERNAL_IID \
  {0xcd66ffef, 0x3bc3, 0x40de, \
    { 0x84, 0x1a, 0xe2, 0xdc, 0xbe, 0xa2, 0x13, 0xa2 }}

class NS_NO_VTABLE nsIIOServiceInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIOSERVICEINTERNAL_IID)

  /* void SetConnectivity (in boolean connectivity); */
  NS_IMETHOD SetConnectivity(bool connectivity) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIOServiceInternal, NS_IIOSERVICEINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIOSERVICEINTERNAL \
  NS_IMETHOD SetConnectivity(bool connectivity) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIOSERVICEINTERNAL(_to) \
  NS_IMETHOD SetConnectivity(bool connectivity) override { return _to SetConnectivity(connectivity); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIOSERVICEINTERNAL(_to) \
  NS_IMETHOD SetConnectivity(bool connectivity) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConnectivity(connectivity); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIOServiceInternal : public nsIIOServiceInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIOSERVICEINTERNAL

  nsIOServiceInternal();

private:
  ~nsIOServiceInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsIOServiceInternal, nsIIOServiceInternal)

nsIOServiceInternal::nsIOServiceInternal()
{
  /* member initializers and constructor code */
}

nsIOServiceInternal::~nsIOServiceInternal()
{
  /* destructor code */
}

/* void SetConnectivity (in boolean connectivity); */
NS_IMETHODIMP nsIOServiceInternal::SetConnectivity(bool connectivity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIOService_h__ */
