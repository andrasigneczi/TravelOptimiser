/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDNSServiceDiscovery.idl
 */

#ifndef __gen_nsIDNSServiceDiscovery_h__
#define __gen_nsIDNSServiceDiscovery_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICancelable; /* forward declaration */

class nsIPropertyBag2; /* forward declaration */


/* starting interface:    nsIDNSServiceInfo */
#define NS_IDNSSERVICEINFO_IID_STR "112bfa89-1b57-4acf-8287-48e5466c1b39"

#define NS_IDNSSERVICEINFO_IID \
  {0x112bfa89, 0x1b57, 0x4acf, \
    { 0x82, 0x87, 0x48, 0xe5, 0x46, 0x6c, 0x1b, 0x39 }}

class NS_NO_VTABLE nsIDNSServiceInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSSERVICEINFO_IID)

  /* attribute AUTF8String host; */
  NS_IMETHOD GetHost(nsACString & aHost) = 0;
  NS_IMETHOD SetHost(const nsACString & aHost) = 0;

  /* attribute unsigned short port; */
  NS_IMETHOD GetPort(uint16_t *aPort) = 0;
  NS_IMETHOD SetPort(uint16_t aPort) = 0;

  /* attribute AUTF8String serviceName; */
  NS_IMETHOD GetServiceName(nsACString & aServiceName) = 0;
  NS_IMETHOD SetServiceName(const nsACString & aServiceName) = 0;

  /* attribute AUTF8String serviceType; */
  NS_IMETHOD GetServiceType(nsACString & aServiceType) = 0;
  NS_IMETHOD SetServiceType(const nsACString & aServiceType) = 0;

  /* attribute AUTF8String domainName; */
  NS_IMETHOD GetDomainName(nsACString & aDomainName) = 0;
  NS_IMETHOD SetDomainName(const nsACString & aDomainName) = 0;

  /* attribute nsIPropertyBag2 attributes; */
  NS_IMETHOD GetAttributes(nsIPropertyBag2 * *aAttributes) = 0;
  NS_IMETHOD SetAttributes(nsIPropertyBag2 *aAttributes) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSServiceInfo, NS_IDNSSERVICEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSSERVICEINFO \
  NS_IMETHOD GetHost(nsACString & aHost) override; \
  NS_IMETHOD SetHost(const nsACString & aHost) override; \
  NS_IMETHOD GetPort(uint16_t *aPort) override; \
  NS_IMETHOD SetPort(uint16_t aPort) override; \
  NS_IMETHOD GetServiceName(nsACString & aServiceName) override; \
  NS_IMETHOD SetServiceName(const nsACString & aServiceName) override; \
  NS_IMETHOD GetServiceType(nsACString & aServiceType) override; \
  NS_IMETHOD SetServiceType(const nsACString & aServiceType) override; \
  NS_IMETHOD GetDomainName(nsACString & aDomainName) override; \
  NS_IMETHOD SetDomainName(const nsACString & aDomainName) override; \
  NS_IMETHOD GetAttributes(nsIPropertyBag2 * *aAttributes) override; \
  NS_IMETHOD SetAttributes(nsIPropertyBag2 *aAttributes) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSSERVICEINFO(_to) \
  NS_IMETHOD GetHost(nsACString & aHost) override { return _to GetHost(aHost); } \
  NS_IMETHOD SetHost(const nsACString & aHost) override { return _to SetHost(aHost); } \
  NS_IMETHOD GetPort(uint16_t *aPort) override { return _to GetPort(aPort); } \
  NS_IMETHOD SetPort(uint16_t aPort) override { return _to SetPort(aPort); } \
  NS_IMETHOD GetServiceName(nsACString & aServiceName) override { return _to GetServiceName(aServiceName); } \
  NS_IMETHOD SetServiceName(const nsACString & aServiceName) override { return _to SetServiceName(aServiceName); } \
  NS_IMETHOD GetServiceType(nsACString & aServiceType) override { return _to GetServiceType(aServiceType); } \
  NS_IMETHOD SetServiceType(const nsACString & aServiceType) override { return _to SetServiceType(aServiceType); } \
  NS_IMETHOD GetDomainName(nsACString & aDomainName) override { return _to GetDomainName(aDomainName); } \
  NS_IMETHOD SetDomainName(const nsACString & aDomainName) override { return _to SetDomainName(aDomainName); } \
  NS_IMETHOD GetAttributes(nsIPropertyBag2 * *aAttributes) override { return _to GetAttributes(aAttributes); } \
  NS_IMETHOD SetAttributes(nsIPropertyBag2 *aAttributes) override { return _to SetAttributes(aAttributes); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSSERVICEINFO(_to) \
  NS_IMETHOD GetHost(nsACString & aHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD SetHost(const nsACString & aHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHost(aHost); } \
  NS_IMETHOD GetPort(uint16_t *aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD SetPort(uint16_t aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPort(aPort); } \
  NS_IMETHOD GetServiceName(nsACString & aServiceName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceName(aServiceName); } \
  NS_IMETHOD SetServiceName(const nsACString & aServiceName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetServiceName(aServiceName); } \
  NS_IMETHOD GetServiceType(nsACString & aServiceType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceType(aServiceType); } \
  NS_IMETHOD SetServiceType(const nsACString & aServiceType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetServiceType(aServiceType); } \
  NS_IMETHOD GetDomainName(nsACString & aDomainName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainName(aDomainName); } \
  NS_IMETHOD SetDomainName(const nsACString & aDomainName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomainName(aDomainName); } \
  NS_IMETHOD GetAttributes(nsIPropertyBag2 * *aAttributes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributes(aAttributes); } \
  NS_IMETHOD SetAttributes(nsIPropertyBag2 *aAttributes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributes(aAttributes); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSServiceInfo : public nsIDNSServiceInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSSERVICEINFO

  nsDNSServiceInfo();

private:
  ~nsDNSServiceInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDNSServiceInfo, nsIDNSServiceInfo)

nsDNSServiceInfo::nsDNSServiceInfo()
{
  /* member initializers and constructor code */
}

nsDNSServiceInfo::~nsDNSServiceInfo()
{
  /* destructor code */
}

/* attribute AUTF8String host; */
NS_IMETHODIMP nsDNSServiceInfo::GetHost(nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDNSServiceInfo::SetHost(const nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short port; */
NS_IMETHODIMP nsDNSServiceInfo::GetPort(uint16_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDNSServiceInfo::SetPort(uint16_t aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String serviceName; */
NS_IMETHODIMP nsDNSServiceInfo::GetServiceName(nsACString & aServiceName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDNSServiceInfo::SetServiceName(const nsACString & aServiceName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String serviceType; */
NS_IMETHODIMP nsDNSServiceInfo::GetServiceType(nsACString & aServiceType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDNSServiceInfo::SetServiceType(const nsACString & aServiceType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String domainName; */
NS_IMETHODIMP nsDNSServiceInfo::GetDomainName(nsACString & aDomainName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDNSServiceInfo::SetDomainName(const nsACString & aDomainName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIPropertyBag2 attributes; */
NS_IMETHODIMP nsDNSServiceInfo::GetAttributes(nsIPropertyBag2 * *aAttributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDNSServiceInfo::SetAttributes(nsIPropertyBag2 *aAttributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDNSServiceDiscoveryListener */
#define NS_IDNSSERVICEDISCOVERYLISTENER_IID_STR "3025b7f2-97bb-435b-b43d-26731b3f5fc4"

#define NS_IDNSSERVICEDISCOVERYLISTENER_IID \
  {0x3025b7f2, 0x97bb, 0x435b, \
    { 0xb4, 0x3d, 0x26, 0x73, 0x1b, 0x3f, 0x5f, 0xc4 }}

class NS_NO_VTABLE nsIDNSServiceDiscoveryListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSSERVICEDISCOVERYLISTENER_IID)

  /* void onDiscoveryStarted (in AUTF8String aServiceType); */
  NS_IMETHOD OnDiscoveryStarted(const nsACString & aServiceType) = 0;

  /* void onDiscoveryStopped (in AUTF8String aServiceType); */
  NS_IMETHOD OnDiscoveryStopped(const nsACString & aServiceType) = 0;

  /* void onServiceFound (in nsIDNSServiceInfo aServiceInfo); */
  NS_IMETHOD OnServiceFound(nsIDNSServiceInfo *aServiceInfo) = 0;

  /* void onServiceLost (in nsIDNSServiceInfo aServiceInfo); */
  NS_IMETHOD OnServiceLost(nsIDNSServiceInfo *aServiceInfo) = 0;

  /* void onStartDiscoveryFailed (in AUTF8String aServiceType, in long aErrorCode); */
  NS_IMETHOD OnStartDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode) = 0;

  /* void onStopDiscoveryFailed (in AUTF8String aServiceType, in long aErrorCode); */
  NS_IMETHOD OnStopDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSServiceDiscoveryListener, NS_IDNSSERVICEDISCOVERYLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSSERVICEDISCOVERYLISTENER \
  NS_IMETHOD OnDiscoveryStarted(const nsACString & aServiceType) override; \
  NS_IMETHOD OnDiscoveryStopped(const nsACString & aServiceType) override; \
  NS_IMETHOD OnServiceFound(nsIDNSServiceInfo *aServiceInfo) override; \
  NS_IMETHOD OnServiceLost(nsIDNSServiceInfo *aServiceInfo) override; \
  NS_IMETHOD OnStartDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode) override; \
  NS_IMETHOD OnStopDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSSERVICEDISCOVERYLISTENER(_to) \
  NS_IMETHOD OnDiscoveryStarted(const nsACString & aServiceType) override { return _to OnDiscoveryStarted(aServiceType); } \
  NS_IMETHOD OnDiscoveryStopped(const nsACString & aServiceType) override { return _to OnDiscoveryStopped(aServiceType); } \
  NS_IMETHOD OnServiceFound(nsIDNSServiceInfo *aServiceInfo) override { return _to OnServiceFound(aServiceInfo); } \
  NS_IMETHOD OnServiceLost(nsIDNSServiceInfo *aServiceInfo) override { return _to OnServiceLost(aServiceInfo); } \
  NS_IMETHOD OnStartDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode) override { return _to OnStartDiscoveryFailed(aServiceType, aErrorCode); } \
  NS_IMETHOD OnStopDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode) override { return _to OnStopDiscoveryFailed(aServiceType, aErrorCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSSERVICEDISCOVERYLISTENER(_to) \
  NS_IMETHOD OnDiscoveryStarted(const nsACString & aServiceType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDiscoveryStarted(aServiceType); } \
  NS_IMETHOD OnDiscoveryStopped(const nsACString & aServiceType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDiscoveryStopped(aServiceType); } \
  NS_IMETHOD OnServiceFound(nsIDNSServiceInfo *aServiceInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnServiceFound(aServiceInfo); } \
  NS_IMETHOD OnServiceLost(nsIDNSServiceInfo *aServiceInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnServiceLost(aServiceInfo); } \
  NS_IMETHOD OnStartDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStartDiscoveryFailed(aServiceType, aErrorCode); } \
  NS_IMETHOD OnStopDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopDiscoveryFailed(aServiceType, aErrorCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSServiceDiscoveryListener : public nsIDNSServiceDiscoveryListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSSERVICEDISCOVERYLISTENER

  nsDNSServiceDiscoveryListener();

private:
  ~nsDNSServiceDiscoveryListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDNSServiceDiscoveryListener, nsIDNSServiceDiscoveryListener)

nsDNSServiceDiscoveryListener::nsDNSServiceDiscoveryListener()
{
  /* member initializers and constructor code */
}

nsDNSServiceDiscoveryListener::~nsDNSServiceDiscoveryListener()
{
  /* destructor code */
}

/* void onDiscoveryStarted (in AUTF8String aServiceType); */
NS_IMETHODIMP nsDNSServiceDiscoveryListener::OnDiscoveryStarted(const nsACString & aServiceType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDiscoveryStopped (in AUTF8String aServiceType); */
NS_IMETHODIMP nsDNSServiceDiscoveryListener::OnDiscoveryStopped(const nsACString & aServiceType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onServiceFound (in nsIDNSServiceInfo aServiceInfo); */
NS_IMETHODIMP nsDNSServiceDiscoveryListener::OnServiceFound(nsIDNSServiceInfo *aServiceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onServiceLost (in nsIDNSServiceInfo aServiceInfo); */
NS_IMETHODIMP nsDNSServiceDiscoveryListener::OnServiceLost(nsIDNSServiceInfo *aServiceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStartDiscoveryFailed (in AUTF8String aServiceType, in long aErrorCode); */
NS_IMETHODIMP nsDNSServiceDiscoveryListener::OnStartDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopDiscoveryFailed (in AUTF8String aServiceType, in long aErrorCode); */
NS_IMETHODIMP nsDNSServiceDiscoveryListener::OnStopDiscoveryFailed(const nsACString & aServiceType, int32_t aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDNSRegistrationListener */
#define NS_IDNSREGISTRATIONLISTENER_IID_STR "e165e4be-abf4-4963-a66d-ed3ca116e5e4"

#define NS_IDNSREGISTRATIONLISTENER_IID \
  {0xe165e4be, 0xabf4, 0x4963, \
    { 0xa6, 0x6d, 0xed, 0x3c, 0xa1, 0x16, 0xe5, 0xe4 }}

class NS_NO_VTABLE nsIDNSRegistrationListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSREGISTRATIONLISTENER_IID)

  enum {
    ERROR_SERVICE_NOT_RUNNING = -65563
  };

  /* void onServiceRegistered (in nsIDNSServiceInfo aServiceInfo); */
  NS_IMETHOD OnServiceRegistered(nsIDNSServiceInfo *aServiceInfo) = 0;

  /* void onServiceUnregistered (in nsIDNSServiceInfo aServiceInfo); */
  NS_IMETHOD OnServiceUnregistered(nsIDNSServiceInfo *aServiceInfo) = 0;

  /* void onRegistrationFailed (in nsIDNSServiceInfo aServiceInfo, in long aErrorCode); */
  NS_IMETHOD OnRegistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) = 0;

  /* void onUnregistrationFailed (in nsIDNSServiceInfo aServiceInfo, in long aErrorCode); */
  NS_IMETHOD OnUnregistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSRegistrationListener, NS_IDNSREGISTRATIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSREGISTRATIONLISTENER \
  NS_IMETHOD OnServiceRegistered(nsIDNSServiceInfo *aServiceInfo) override; \
  NS_IMETHOD OnServiceUnregistered(nsIDNSServiceInfo *aServiceInfo) override; \
  NS_IMETHOD OnRegistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) override; \
  NS_IMETHOD OnUnregistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSREGISTRATIONLISTENER(_to) \
  NS_IMETHOD OnServiceRegistered(nsIDNSServiceInfo *aServiceInfo) override { return _to OnServiceRegistered(aServiceInfo); } \
  NS_IMETHOD OnServiceUnregistered(nsIDNSServiceInfo *aServiceInfo) override { return _to OnServiceUnregistered(aServiceInfo); } \
  NS_IMETHOD OnRegistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) override { return _to OnRegistrationFailed(aServiceInfo, aErrorCode); } \
  NS_IMETHOD OnUnregistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) override { return _to OnUnregistrationFailed(aServiceInfo, aErrorCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSREGISTRATIONLISTENER(_to) \
  NS_IMETHOD OnServiceRegistered(nsIDNSServiceInfo *aServiceInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnServiceRegistered(aServiceInfo); } \
  NS_IMETHOD OnServiceUnregistered(nsIDNSServiceInfo *aServiceInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnServiceUnregistered(aServiceInfo); } \
  NS_IMETHOD OnRegistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRegistrationFailed(aServiceInfo, aErrorCode); } \
  NS_IMETHOD OnUnregistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnUnregistrationFailed(aServiceInfo, aErrorCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSRegistrationListener : public nsIDNSRegistrationListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSREGISTRATIONLISTENER

  nsDNSRegistrationListener();

private:
  ~nsDNSRegistrationListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDNSRegistrationListener, nsIDNSRegistrationListener)

nsDNSRegistrationListener::nsDNSRegistrationListener()
{
  /* member initializers and constructor code */
}

nsDNSRegistrationListener::~nsDNSRegistrationListener()
{
  /* destructor code */
}

/* void onServiceRegistered (in nsIDNSServiceInfo aServiceInfo); */
NS_IMETHODIMP nsDNSRegistrationListener::OnServiceRegistered(nsIDNSServiceInfo *aServiceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onServiceUnregistered (in nsIDNSServiceInfo aServiceInfo); */
NS_IMETHODIMP nsDNSRegistrationListener::OnServiceUnregistered(nsIDNSServiceInfo *aServiceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onRegistrationFailed (in nsIDNSServiceInfo aServiceInfo, in long aErrorCode); */
NS_IMETHODIMP nsDNSRegistrationListener::OnRegistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onUnregistrationFailed (in nsIDNSServiceInfo aServiceInfo, in long aErrorCode); */
NS_IMETHODIMP nsDNSRegistrationListener::OnUnregistrationFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDNSServiceResolveListener */
#define NS_IDNSSERVICERESOLVELISTENER_IID_STR "24ee6408-648e-421d-accf-c6e5adeccf97"

#define NS_IDNSSERVICERESOLVELISTENER_IID \
  {0x24ee6408, 0x648e, 0x421d, \
    { 0xac, 0xcf, 0xc6, 0xe5, 0xad, 0xec, 0xcf, 0x97 }}

class NS_NO_VTABLE nsIDNSServiceResolveListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSSERVICERESOLVELISTENER_IID)

  /* void onServiceResolved (in nsIDNSServiceInfo aServiceInfo); */
  NS_IMETHOD OnServiceResolved(nsIDNSServiceInfo *aServiceInfo) = 0;

  /* void onResolveFailed (in nsIDNSServiceInfo aServiceInfo, in long aErrorCode); */
  NS_IMETHOD OnResolveFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSServiceResolveListener, NS_IDNSSERVICERESOLVELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSSERVICERESOLVELISTENER \
  NS_IMETHOD OnServiceResolved(nsIDNSServiceInfo *aServiceInfo) override; \
  NS_IMETHOD OnResolveFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSSERVICERESOLVELISTENER(_to) \
  NS_IMETHOD OnServiceResolved(nsIDNSServiceInfo *aServiceInfo) override { return _to OnServiceResolved(aServiceInfo); } \
  NS_IMETHOD OnResolveFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) override { return _to OnResolveFailed(aServiceInfo, aErrorCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSSERVICERESOLVELISTENER(_to) \
  NS_IMETHOD OnServiceResolved(nsIDNSServiceInfo *aServiceInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnServiceResolved(aServiceInfo); } \
  NS_IMETHOD OnResolveFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnResolveFailed(aServiceInfo, aErrorCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSServiceResolveListener : public nsIDNSServiceResolveListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSSERVICERESOLVELISTENER

  nsDNSServiceResolveListener();

private:
  ~nsDNSServiceResolveListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDNSServiceResolveListener, nsIDNSServiceResolveListener)

nsDNSServiceResolveListener::nsDNSServiceResolveListener()
{
  /* member initializers and constructor code */
}

nsDNSServiceResolveListener::~nsDNSServiceResolveListener()
{
  /* destructor code */
}

/* void onServiceResolved (in nsIDNSServiceInfo aServiceInfo); */
NS_IMETHODIMP nsDNSServiceResolveListener::OnServiceResolved(nsIDNSServiceInfo *aServiceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onResolveFailed (in nsIDNSServiceInfo aServiceInfo, in long aErrorCode); */
NS_IMETHODIMP nsDNSServiceResolveListener::OnResolveFailed(nsIDNSServiceInfo *aServiceInfo, int32_t aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDNSServiceDiscovery */
#define NS_IDNSSERVICEDISCOVERY_IID_STR "6487899b-beb1-455a-ba65-e4fd465066d7"

#define NS_IDNSSERVICEDISCOVERY_IID \
  {0x6487899b, 0xbeb1, 0x455a, \
    { 0xba, 0x65, 0xe4, 0xfd, 0x46, 0x50, 0x66, 0xd7 }}

class NS_NO_VTABLE nsIDNSServiceDiscovery : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSSERVICEDISCOVERY_IID)

  /* nsICancelable startDiscovery (in AUTF8String aServiceType, in nsIDNSServiceDiscoveryListener aListener); */
  NS_IMETHOD StartDiscovery(const nsACString & aServiceType, nsIDNSServiceDiscoveryListener *aListener, nsICancelable * *_retval) = 0;

  /* nsICancelable registerService (in nsIDNSServiceInfo aServiceInfo, in nsIDNSRegistrationListener aListener); */
  NS_IMETHOD RegisterService(nsIDNSServiceInfo *aServiceInfo, nsIDNSRegistrationListener *aListener, nsICancelable * *_retval) = 0;

  /* void resolveService (in nsIDNSServiceInfo aServiceInfo, in nsIDNSServiceResolveListener aListener); */
  NS_IMETHOD ResolveService(nsIDNSServiceInfo *aServiceInfo, nsIDNSServiceResolveListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSServiceDiscovery, NS_IDNSSERVICEDISCOVERY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSSERVICEDISCOVERY \
  NS_IMETHOD StartDiscovery(const nsACString & aServiceType, nsIDNSServiceDiscoveryListener *aListener, nsICancelable * *_retval) override; \
  NS_IMETHOD RegisterService(nsIDNSServiceInfo *aServiceInfo, nsIDNSRegistrationListener *aListener, nsICancelable * *_retval) override; \
  NS_IMETHOD ResolveService(nsIDNSServiceInfo *aServiceInfo, nsIDNSServiceResolveListener *aListener) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSSERVICEDISCOVERY(_to) \
  NS_IMETHOD StartDiscovery(const nsACString & aServiceType, nsIDNSServiceDiscoveryListener *aListener, nsICancelable * *_retval) override { return _to StartDiscovery(aServiceType, aListener, _retval); } \
  NS_IMETHOD RegisterService(nsIDNSServiceInfo *aServiceInfo, nsIDNSRegistrationListener *aListener, nsICancelable * *_retval) override { return _to RegisterService(aServiceInfo, aListener, _retval); } \
  NS_IMETHOD ResolveService(nsIDNSServiceInfo *aServiceInfo, nsIDNSServiceResolveListener *aListener) override { return _to ResolveService(aServiceInfo, aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSSERVICEDISCOVERY(_to) \
  NS_IMETHOD StartDiscovery(const nsACString & aServiceType, nsIDNSServiceDiscoveryListener *aListener, nsICancelable * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartDiscovery(aServiceType, aListener, _retval); } \
  NS_IMETHOD RegisterService(nsIDNSServiceInfo *aServiceInfo, nsIDNSRegistrationListener *aListener, nsICancelable * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterService(aServiceInfo, aListener, _retval); } \
  NS_IMETHOD ResolveService(nsIDNSServiceInfo *aServiceInfo, nsIDNSServiceResolveListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResolveService(aServiceInfo, aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSServiceDiscovery : public nsIDNSServiceDiscovery
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSSERVICEDISCOVERY

  nsDNSServiceDiscovery();

private:
  ~nsDNSServiceDiscovery();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDNSServiceDiscovery, nsIDNSServiceDiscovery)

nsDNSServiceDiscovery::nsDNSServiceDiscovery()
{
  /* member initializers and constructor code */
}

nsDNSServiceDiscovery::~nsDNSServiceDiscovery()
{
  /* destructor code */
}

/* nsICancelable startDiscovery (in AUTF8String aServiceType, in nsIDNSServiceDiscoveryListener aListener); */
NS_IMETHODIMP nsDNSServiceDiscovery::StartDiscovery(const nsACString & aServiceType, nsIDNSServiceDiscoveryListener *aListener, nsICancelable * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICancelable registerService (in nsIDNSServiceInfo aServiceInfo, in nsIDNSRegistrationListener aListener); */
NS_IMETHODIMP nsDNSServiceDiscovery::RegisterService(nsIDNSServiceInfo *aServiceInfo, nsIDNSRegistrationListener *aListener, nsICancelable * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resolveService (in nsIDNSServiceInfo aServiceInfo, in nsIDNSServiceResolveListener aListener); */
NS_IMETHODIMP nsDNSServiceDiscovery::ResolveService(nsIDNSServiceInfo *aServiceInfo, nsIDNSServiceResolveListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define DNSSERVICEDISCOVERY_CONTRACT_ID \
  "@mozilla.org/toolkit/components/mdnsresponder/dns-sd;1"
#define DNSSERVICEINFO_CONTRACT_ID \
  "@mozilla.org/toolkit/components/mdnsresponder/dns-info;1"

#endif /* __gen_nsIDNSServiceDiscovery_h__ */
