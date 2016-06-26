/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMobileConnectionService.idl
 */

#ifndef __gen_nsIMobileConnectionService_h__
#define __gen_nsIMobileConnectionService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICellInfoListCallback; /* forward declaration */

class nsIMobileCallForwardingOptions; /* forward declaration */

class nsIMobileConnection; /* forward declaration */

class nsIMobileConnectionInfo; /* forward declaration */

class nsIMobileNetworkInfo; /* forward declaration */

class nsINeighboringCellIdsCallback; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIMobileConnectionListener */
#define NS_IMOBILECONNECTIONLISTENER_IID_STR "d6827b51-61a7-4b7c-8454-42d0cffc1829"

#define NS_IMOBILECONNECTIONLISTENER_IID \
  {0xd6827b51, 0x61a7, 0x4b7c, \
    { 0x84, 0x54, 0x42, 0xd0, 0xcf, 0xfc, 0x18, 0x29 }}

class NS_NO_VTABLE nsIMobileConnectionListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILECONNECTIONLISTENER_IID)

  /* void notifyVoiceChanged (); */
  NS_IMETHOD NotifyVoiceChanged(void) = 0;

  /* void notifyDataChanged (); */
  NS_IMETHOD NotifyDataChanged(void) = 0;

  /* void notifyDataError (in DOMString message); */
  NS_IMETHOD NotifyDataError(const nsAString & message) = 0;

  /* void notifyCFStateChanged (in unsigned short action, in unsigned short reason, in DOMString number, in unsigned short timeSeconds, in unsigned short serviceClass); */
  NS_IMETHOD NotifyCFStateChanged(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass) = 0;

  /* void notifyEmergencyCbModeChanged (in boolean active, in unsigned long timeoutMs); */
  NS_IMETHOD NotifyEmergencyCbModeChanged(bool active, uint32_t timeoutMs) = 0;

  /* void notifyOtaStatusChanged (in DOMString status); */
  NS_IMETHOD NotifyOtaStatusChanged(const nsAString & status) = 0;

  /* void notifyRadioStateChanged (); */
  NS_IMETHOD NotifyRadioStateChanged(void) = 0;

  /* void notifyClirModeChanged (in unsigned long mode); */
  NS_IMETHOD NotifyClirModeChanged(uint32_t mode) = 0;

  /* void notifyLastKnownNetworkChanged (); */
  NS_IMETHOD NotifyLastKnownNetworkChanged(void) = 0;

  /* void notifyLastKnownHomeNetworkChanged (); */
  NS_IMETHOD NotifyLastKnownHomeNetworkChanged(void) = 0;

  /* void notifyNetworkSelectionModeChanged (); */
  NS_IMETHOD NotifyNetworkSelectionModeChanged(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileConnectionListener, NS_IMOBILECONNECTIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILECONNECTIONLISTENER \
  NS_IMETHOD NotifyVoiceChanged(void) override; \
  NS_IMETHOD NotifyDataChanged(void) override; \
  NS_IMETHOD NotifyDataError(const nsAString & message) override; \
  NS_IMETHOD NotifyCFStateChanged(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass) override; \
  NS_IMETHOD NotifyEmergencyCbModeChanged(bool active, uint32_t timeoutMs) override; \
  NS_IMETHOD NotifyOtaStatusChanged(const nsAString & status) override; \
  NS_IMETHOD NotifyRadioStateChanged(void) override; \
  NS_IMETHOD NotifyClirModeChanged(uint32_t mode) override; \
  NS_IMETHOD NotifyLastKnownNetworkChanged(void) override; \
  NS_IMETHOD NotifyLastKnownHomeNetworkChanged(void) override; \
  NS_IMETHOD NotifyNetworkSelectionModeChanged(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILECONNECTIONLISTENER(_to) \
  NS_IMETHOD NotifyVoiceChanged(void) override { return _to NotifyVoiceChanged(); } \
  NS_IMETHOD NotifyDataChanged(void) override { return _to NotifyDataChanged(); } \
  NS_IMETHOD NotifyDataError(const nsAString & message) override { return _to NotifyDataError(message); } \
  NS_IMETHOD NotifyCFStateChanged(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass) override { return _to NotifyCFStateChanged(action, reason, number, timeSeconds, serviceClass); } \
  NS_IMETHOD NotifyEmergencyCbModeChanged(bool active, uint32_t timeoutMs) override { return _to NotifyEmergencyCbModeChanged(active, timeoutMs); } \
  NS_IMETHOD NotifyOtaStatusChanged(const nsAString & status) override { return _to NotifyOtaStatusChanged(status); } \
  NS_IMETHOD NotifyRadioStateChanged(void) override { return _to NotifyRadioStateChanged(); } \
  NS_IMETHOD NotifyClirModeChanged(uint32_t mode) override { return _to NotifyClirModeChanged(mode); } \
  NS_IMETHOD NotifyLastKnownNetworkChanged(void) override { return _to NotifyLastKnownNetworkChanged(); } \
  NS_IMETHOD NotifyLastKnownHomeNetworkChanged(void) override { return _to NotifyLastKnownHomeNetworkChanged(); } \
  NS_IMETHOD NotifyNetworkSelectionModeChanged(void) override { return _to NotifyNetworkSelectionModeChanged(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILECONNECTIONLISTENER(_to) \
  NS_IMETHOD NotifyVoiceChanged(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyVoiceChanged(); } \
  NS_IMETHOD NotifyDataChanged(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDataChanged(); } \
  NS_IMETHOD NotifyDataError(const nsAString & message) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDataError(message); } \
  NS_IMETHOD NotifyCFStateChanged(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCFStateChanged(action, reason, number, timeSeconds, serviceClass); } \
  NS_IMETHOD NotifyEmergencyCbModeChanged(bool active, uint32_t timeoutMs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyEmergencyCbModeChanged(active, timeoutMs); } \
  NS_IMETHOD NotifyOtaStatusChanged(const nsAString & status) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyOtaStatusChanged(status); } \
  NS_IMETHOD NotifyRadioStateChanged(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyRadioStateChanged(); } \
  NS_IMETHOD NotifyClirModeChanged(uint32_t mode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyClirModeChanged(mode); } \
  NS_IMETHOD NotifyLastKnownNetworkChanged(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyLastKnownNetworkChanged(); } \
  NS_IMETHOD NotifyLastKnownHomeNetworkChanged(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyLastKnownHomeNetworkChanged(); } \
  NS_IMETHOD NotifyNetworkSelectionModeChanged(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyNetworkSelectionModeChanged(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileConnectionListener : public nsIMobileConnectionListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILECONNECTIONLISTENER

  nsMobileConnectionListener();

private:
  ~nsMobileConnectionListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileConnectionListener, nsIMobileConnectionListener)

nsMobileConnectionListener::nsMobileConnectionListener()
{
  /* member initializers and constructor code */
}

nsMobileConnectionListener::~nsMobileConnectionListener()
{
  /* destructor code */
}

/* void notifyVoiceChanged (); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyVoiceChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDataChanged (); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyDataChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDataError (in DOMString message); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyDataError(const nsAString & message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyCFStateChanged (in unsigned short action, in unsigned short reason, in DOMString number, in unsigned short timeSeconds, in unsigned short serviceClass); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyCFStateChanged(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyEmergencyCbModeChanged (in boolean active, in unsigned long timeoutMs); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyEmergencyCbModeChanged(bool active, uint32_t timeoutMs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyOtaStatusChanged (in DOMString status); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyOtaStatusChanged(const nsAString & status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyRadioStateChanged (); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyRadioStateChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyClirModeChanged (in unsigned long mode); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyClirModeChanged(uint32_t mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyLastKnownNetworkChanged (); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyLastKnownNetworkChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyLastKnownHomeNetworkChanged (); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyLastKnownHomeNetworkChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyNetworkSelectionModeChanged (); */
NS_IMETHODIMP nsMobileConnectionListener::NotifyNetworkSelectionModeChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NO_ADDITIONAL_INFORMATION 0

/* starting interface:    nsIMobileConnectionCallback */
#define NS_IMOBILECONNECTIONCALLBACK_IID_STR "ef5e02a6-adff-4425-8634-ec49ced1f14f"

#define NS_IMOBILECONNECTIONCALLBACK_IID \
  {0xef5e02a6, 0xadff, 0x4425, \
    { 0x86, 0x34, 0xec, 0x49, 0xce, 0xd1, 0xf1, 0x4f }}

class NS_NO_VTABLE nsIMobileConnectionCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILECONNECTIONCALLBACK_IID)

  /* void notifySuccess (); */
  NS_IMETHOD NotifySuccess(void) = 0;

  /* void notifySuccessWithBoolean (in boolean result); */
  NS_IMETHOD NotifySuccessWithBoolean(bool result) = 0;

  /* void notifyGetNetworksSuccess (in uint32_t count, [array, size_is (count)] in nsIMobileNetworkInfo networks); */
  NS_IMETHOD NotifyGetNetworksSuccess(uint32_t count, nsIMobileNetworkInfo **networks) = 0;

  /* void notifyGetCallForwardingSuccess (in uint32_t count, [array, size_is (count)] in nsIMobileCallForwardingOptions results); */
  NS_IMETHOD NotifyGetCallForwardingSuccess(uint32_t count, nsIMobileCallForwardingOptions **results) = 0;

  /* void notifyGetCallBarringSuccess (in unsigned short program, in boolean enabled, in unsigned short serviceClass); */
  NS_IMETHOD NotifyGetCallBarringSuccess(uint16_t program, bool enabled, uint16_t serviceClass) = 0;

  /* void notifyGetCallWaitingSuccess (in unsigned short serviceClass); */
  NS_IMETHOD NotifyGetCallWaitingSuccess(uint16_t serviceClass) = 0;

  /* void notifyGetClirStatusSuccess (in unsigned short n, in unsigned short m); */
  NS_IMETHOD NotifyGetClirStatusSuccess(uint16_t n, uint16_t m) = 0;

  /* void notifyGetPreferredNetworkTypeSuccess (in long type); */
  NS_IMETHOD NotifyGetPreferredNetworkTypeSuccess(int32_t type) = 0;

  /* void notifyGetRoamingPreferenceSuccess (in long mode); */
  NS_IMETHOD NotifyGetRoamingPreferenceSuccess(int32_t mode) = 0;

  /* void notifyError (in DOMString name); */
  NS_IMETHOD NotifyError(const nsAString & name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileConnectionCallback, NS_IMOBILECONNECTIONCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILECONNECTIONCALLBACK \
  NS_IMETHOD NotifySuccess(void) override; \
  NS_IMETHOD NotifySuccessWithBoolean(bool result) override; \
  NS_IMETHOD NotifyGetNetworksSuccess(uint32_t count, nsIMobileNetworkInfo **networks) override; \
  NS_IMETHOD NotifyGetCallForwardingSuccess(uint32_t count, nsIMobileCallForwardingOptions **results) override; \
  NS_IMETHOD NotifyGetCallBarringSuccess(uint16_t program, bool enabled, uint16_t serviceClass) override; \
  NS_IMETHOD NotifyGetCallWaitingSuccess(uint16_t serviceClass) override; \
  NS_IMETHOD NotifyGetClirStatusSuccess(uint16_t n, uint16_t m) override; \
  NS_IMETHOD NotifyGetPreferredNetworkTypeSuccess(int32_t type) override; \
  NS_IMETHOD NotifyGetRoamingPreferenceSuccess(int32_t mode) override; \
  NS_IMETHOD NotifyError(const nsAString & name) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILECONNECTIONCALLBACK(_to) \
  NS_IMETHOD NotifySuccess(void) override { return _to NotifySuccess(); } \
  NS_IMETHOD NotifySuccessWithBoolean(bool result) override { return _to NotifySuccessWithBoolean(result); } \
  NS_IMETHOD NotifyGetNetworksSuccess(uint32_t count, nsIMobileNetworkInfo **networks) override { return _to NotifyGetNetworksSuccess(count, networks); } \
  NS_IMETHOD NotifyGetCallForwardingSuccess(uint32_t count, nsIMobileCallForwardingOptions **results) override { return _to NotifyGetCallForwardingSuccess(count, results); } \
  NS_IMETHOD NotifyGetCallBarringSuccess(uint16_t program, bool enabled, uint16_t serviceClass) override { return _to NotifyGetCallBarringSuccess(program, enabled, serviceClass); } \
  NS_IMETHOD NotifyGetCallWaitingSuccess(uint16_t serviceClass) override { return _to NotifyGetCallWaitingSuccess(serviceClass); } \
  NS_IMETHOD NotifyGetClirStatusSuccess(uint16_t n, uint16_t m) override { return _to NotifyGetClirStatusSuccess(n, m); } \
  NS_IMETHOD NotifyGetPreferredNetworkTypeSuccess(int32_t type) override { return _to NotifyGetPreferredNetworkTypeSuccess(type); } \
  NS_IMETHOD NotifyGetRoamingPreferenceSuccess(int32_t mode) override { return _to NotifyGetRoamingPreferenceSuccess(mode); } \
  NS_IMETHOD NotifyError(const nsAString & name) override { return _to NotifyError(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILECONNECTIONCALLBACK(_to) \
  NS_IMETHOD NotifySuccess(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySuccess(); } \
  NS_IMETHOD NotifySuccessWithBoolean(bool result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySuccessWithBoolean(result); } \
  NS_IMETHOD NotifyGetNetworksSuccess(uint32_t count, nsIMobileNetworkInfo **networks) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetNetworksSuccess(count, networks); } \
  NS_IMETHOD NotifyGetCallForwardingSuccess(uint32_t count, nsIMobileCallForwardingOptions **results) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetCallForwardingSuccess(count, results); } \
  NS_IMETHOD NotifyGetCallBarringSuccess(uint16_t program, bool enabled, uint16_t serviceClass) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetCallBarringSuccess(program, enabled, serviceClass); } \
  NS_IMETHOD NotifyGetCallWaitingSuccess(uint16_t serviceClass) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetCallWaitingSuccess(serviceClass); } \
  NS_IMETHOD NotifyGetClirStatusSuccess(uint16_t n, uint16_t m) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetClirStatusSuccess(n, m); } \
  NS_IMETHOD NotifyGetPreferredNetworkTypeSuccess(int32_t type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetPreferredNetworkTypeSuccess(type); } \
  NS_IMETHOD NotifyGetRoamingPreferenceSuccess(int32_t mode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetRoamingPreferenceSuccess(mode); } \
  NS_IMETHOD NotifyError(const nsAString & name) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyError(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileConnectionCallback : public nsIMobileConnectionCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILECONNECTIONCALLBACK

  nsMobileConnectionCallback();

private:
  ~nsMobileConnectionCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileConnectionCallback, nsIMobileConnectionCallback)

nsMobileConnectionCallback::nsMobileConnectionCallback()
{
  /* member initializers and constructor code */
}

nsMobileConnectionCallback::~nsMobileConnectionCallback()
{
  /* destructor code */
}

/* void notifySuccess (); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifySuccess()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifySuccessWithBoolean (in boolean result); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifySuccessWithBoolean(bool result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetNetworksSuccess (in uint32_t count, [array, size_is (count)] in nsIMobileNetworkInfo networks); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifyGetNetworksSuccess(uint32_t count, nsIMobileNetworkInfo **networks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetCallForwardingSuccess (in uint32_t count, [array, size_is (count)] in nsIMobileCallForwardingOptions results); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifyGetCallForwardingSuccess(uint32_t count, nsIMobileCallForwardingOptions **results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetCallBarringSuccess (in unsigned short program, in boolean enabled, in unsigned short serviceClass); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifyGetCallBarringSuccess(uint16_t program, bool enabled, uint16_t serviceClass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetCallWaitingSuccess (in unsigned short serviceClass); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifyGetCallWaitingSuccess(uint16_t serviceClass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetClirStatusSuccess (in unsigned short n, in unsigned short m); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifyGetClirStatusSuccess(uint16_t n, uint16_t m)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetPreferredNetworkTypeSuccess (in long type); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifyGetPreferredNetworkTypeSuccess(int32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetRoamingPreferenceSuccess (in long mode); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifyGetRoamingPreferenceSuccess(int32_t mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyError (in DOMString name); */
NS_IMETHODIMP nsMobileConnectionCallback::NotifyError(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_MOBILE_CONNECTION_SERVICE_CID \
  { 0xc6f229d4, 0x16e2, 0x4600, \
    { 0x87, 0x2a, 0x3d, 0x3d, 0xc5, 0xb8, 0x55, 0x41 } }
#define NS_MOBILE_CONNECTION_SERVICE_CONTRACTID \
  "@mozilla.org/mobileconnection/mobileconnectionservice;1"

/* starting interface:    nsIMobileConnectionService */
#define NS_IMOBILECONNECTIONSERVICE_IID_STR "eaba3c4a-0dd5-4919-b1a2-7812e49dbbcb"

#define NS_IMOBILECONNECTIONSERVICE_IID \
  {0xeaba3c4a, 0x0dd5, 0x4919, \
    { 0xb1, 0xa2, 0x78, 0x12, 0xe4, 0x9d, 0xbb, 0xcb }}

class NS_NO_VTABLE nsIMobileConnectionService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILECONNECTIONSERVICE_IID)

  /* readonly attribute unsigned long numItems; */
  NS_IMETHOD GetNumItems(uint32_t *aNumItems) = 0;

  /* nsIMobileConnection getItemByServiceId (in unsigned long serviceId); */
  NS_IMETHOD GetItemByServiceId(uint32_t serviceId, nsIMobileConnection * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileConnectionService, NS_IMOBILECONNECTIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILECONNECTIONSERVICE \
  NS_IMETHOD GetNumItems(uint32_t *aNumItems) override; \
  NS_IMETHOD GetItemByServiceId(uint32_t serviceId, nsIMobileConnection * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILECONNECTIONSERVICE(_to) \
  NS_IMETHOD GetNumItems(uint32_t *aNumItems) override { return _to GetNumItems(aNumItems); } \
  NS_IMETHOD GetItemByServiceId(uint32_t serviceId, nsIMobileConnection * *_retval) override { return _to GetItemByServiceId(serviceId, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILECONNECTIONSERVICE(_to) \
  NS_IMETHOD GetNumItems(uint32_t *aNumItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumItems(aNumItems); } \
  NS_IMETHOD GetItemByServiceId(uint32_t serviceId, nsIMobileConnection * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemByServiceId(serviceId, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileConnectionService : public nsIMobileConnectionService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILECONNECTIONSERVICE

  nsMobileConnectionService();

private:
  ~nsMobileConnectionService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileConnectionService, nsIMobileConnectionService)

nsMobileConnectionService::nsMobileConnectionService()
{
  /* member initializers and constructor code */
}

nsMobileConnectionService::~nsMobileConnectionService()
{
  /* destructor code */
}

/* readonly attribute unsigned long numItems; */
NS_IMETHODIMP nsMobileConnectionService::GetNumItems(uint32_t *aNumItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMobileConnection getItemByServiceId (in unsigned long serviceId); */
NS_IMETHODIMP nsMobileConnectionService::GetItemByServiceId(uint32_t serviceId, nsIMobileConnection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

template<typename T> struct already_AddRefed;
already_AddRefed<nsIMobileConnectionService>
NS_CreateMobileConnectionService();

/* starting interface:    nsIMobileConnection */
#define NS_IMOBILECONNECTION_IID_STR "d7173ff3-a8da-41c1-a976-440e5402b856"

#define NS_IMOBILECONNECTION_IID \
  {0xd7173ff3, 0xa8da, 0x41c1, \
    { 0xa9, 0x76, 0x44, 0x0e, 0x54, 0x02, 0xb8, 0x56 }}

class NS_NO_VTABLE nsIMobileConnection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILECONNECTION_IID)

  enum {
    ICC_SERVICE_CLASS_NONE = 0,
    ICC_SERVICE_CLASS_VOICE = 1,
    ICC_SERVICE_CLASS_DATA = 2,
    ICC_SERVICE_CLASS_FAX = 4,
    ICC_SERVICE_CLASS_SMS = 8,
    ICC_SERVICE_CLASS_DATA_SYNC = 16,
    ICC_SERVICE_CLASS_DATA_ASYNC = 32,
    ICC_SERVICE_CLASS_PACKET = 64,
    ICC_SERVICE_CLASS_PAD = 128,
    ICC_SERVICE_CLASS_MAX = 128,
    CALL_FORWARD_ACTION_UNKNOWN = -1,
    CALL_FORWARD_ACTION_DISABLE = 0,
    CALL_FORWARD_ACTION_ENABLE = 1,
    CALL_FORWARD_ACTION_QUERY_STATUS = 2,
    CALL_FORWARD_ACTION_REGISTRATION = 3,
    CALL_FORWARD_ACTION_ERASURE = 4,
    CALL_FORWARD_REASON_UNKNOWN = -1,
    CALL_FORWARD_REASON_UNCONDITIONAL = 0,
    CALL_FORWARD_REASON_MOBILE_BUSY = 1,
    CALL_FORWARD_REASON_NO_REPLY = 2,
    CALL_FORWARD_REASON_NOT_REACHABLE = 3,
    CALL_FORWARD_REASON_ALL_CALL_FORWARDING = 4,
    CALL_FORWARD_REASON_ALL_CONDITIONAL_CALL_FORWARDING = 5,
    CALL_BARRING_PROGRAM_UNKNOWN = -1,
    CALL_BARRING_PROGRAM_ALL_OUTGOING = 0,
    CALL_BARRING_PROGRAM_OUTGOING_INTERNATIONAL = 1,
    CALL_BARRING_PROGRAM_OUTGOING_INTERNATIONAL_EXCEPT_HOME = 2,
    CALL_BARRING_PROGRAM_ALL_INCOMING = 3,
    CALL_BARRING_PROGRAM_INCOMING_ROAMING = 4,
    CALL_BARRING_PROGRAM_ALL_SERVICE = 5,
    CALL_BARRING_PROGRAM_OUTGOING_SERVICE = 6,
    CALL_BARRING_PROGRAM_INCOMING_SERVICE = 7,
    CLIR_DEFAULT = 0,
    CLIR_INVOCATION = 1,
    CLIR_SUPPRESSION = 2,
    NETWORK_SELECTION_MODE_UNKNOWN = -1,
    NETWORK_SELECTION_MODE_AUTOMATIC = 0,
    NETWORK_SELECTION_MODE_MANUAL = 1,
    MOBILE_RADIO_STATE_UNKNOWN = -1,
    MOBILE_RADIO_STATE_ENABLING = 0,
    MOBILE_RADIO_STATE_ENABLED = 1,
    MOBILE_RADIO_STATE_DISABLING = 2,
    MOBILE_RADIO_STATE_DISABLED = 3,
    PREFERRED_NETWORK_TYPE_WCDMA_GSM = 0,
    PREFERRED_NETWORK_TYPE_GSM_ONLY = 1,
    PREFERRED_NETWORK_TYPE_WCDMA_ONLY = 2,
    PREFERRED_NETWORK_TYPE_WCDMA_GSM_AUTO = 3,
    PREFERRED_NETWORK_TYPE_CDMA_EVDO = 4,
    PREFERRED_NETWORK_TYPE_CDMA_ONLY = 5,
    PREFERRED_NETWORK_TYPE_EVDO_ONLY = 6,
    PREFERRED_NETWORK_TYPE_WCDMA_GSM_CDMA_EVDO = 7,
    PREFERRED_NETWORK_TYPE_LTE_CDMA_EVDO = 8,
    PREFERRED_NETWORK_TYPE_LTE_WCDMA_GSM = 9,
    PREFERRED_NETWORK_TYPE_LTE_WCDMA_GSM_CDMA_EVDO = 10,
    PREFERRED_NETWORK_TYPE_LTE_ONLY = 11,
    CDMA_ROAMING_PREFERENCE_HOME = 0,
    CDMA_ROAMING_PREFERENCE_AFFILIATED = 1,
    CDMA_ROAMING_PREFERENCE_ANY = 2,
    MOBILE_NETWORK_TYPE_GSM = 0,
    MOBILE_NETWORK_TYPE_WCDMA = 1,
    MOBILE_NETWORK_TYPE_CDMA = 2,
    MOBILE_NETWORK_TYPE_EVDO = 3,
    MOBILE_NETWORK_TYPE_LTE = 4
  };

  /* readonly attribute unsigned long serviceId; */
  NS_IMETHOD GetServiceId(uint32_t *aServiceId) = 0;

  /* void registerListener (in nsIMobileConnectionListener listener); */
  NS_IMETHOD RegisterListener(nsIMobileConnectionListener *listener) = 0;

  /* void unregisterListener (in nsIMobileConnectionListener listener); */
  NS_IMETHOD UnregisterListener(nsIMobileConnectionListener *listener) = 0;

  /* readonly attribute DOMString lastKnownNetwork; */
  NS_IMETHOD GetLastKnownNetwork(nsAString & aLastKnownNetwork) = 0;

  /* readonly attribute DOMString lastKnownHomeNetwork; */
  NS_IMETHOD GetLastKnownHomeNetwork(nsAString & aLastKnownHomeNetwork) = 0;

  /* readonly attribute nsIMobileConnectionInfo voice; */
  NS_IMETHOD GetVoice(nsIMobileConnectionInfo * *aVoice) = 0;

  /* readonly attribute nsIMobileConnectionInfo data; */
  NS_IMETHOD GetData(nsIMobileConnectionInfo * *aData) = 0;

  /* readonly attribute long networkSelectionMode; */
  NS_IMETHOD GetNetworkSelectionMode(int32_t *aNetworkSelectionMode) = 0;

  /* readonly attribute long radioState; */
  NS_IMETHOD GetRadioState(int32_t *aRadioState) = 0;

  /* void getSupportedNetworkTypes ([array, size_is (length)] out long types, [retval] out unsigned long length); */
  NS_IMETHOD GetSupportedNetworkTypes(int32_t **types, uint32_t *length) = 0;

  /* void getNetworks (in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD GetNetworks(nsIMobileConnectionCallback *requestCallback) = 0;

  /* void selectNetwork (in nsIMobileNetworkInfo network, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SelectNetwork(nsIMobileNetworkInfo *network, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void selectNetworkAutomatically (in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SelectNetworkAutomatically(nsIMobileConnectionCallback *requestCallback) = 0;

  /* void setPreferredNetworkType (in long type, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SetPreferredNetworkType(int32_t type, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void getPreferredNetworkType (in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD GetPreferredNetworkType(nsIMobileConnectionCallback *requestCallback) = 0;

  /* void setRoamingPreference (in long mode, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SetRoamingPreference(int32_t mode, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void getRoamingPreference (in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD GetRoamingPreference(nsIMobileConnectionCallback *requestCallback) = 0;

  /* void setVoicePrivacyMode (in bool enabled, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SetVoicePrivacyMode(bool enabled, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void getVoicePrivacyMode (in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD GetVoicePrivacyMode(nsIMobileConnectionCallback *requestCallback) = 0;

  /* void getCallForwarding (in unsigned short reason, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD GetCallForwarding(uint16_t reason, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void setCallForwarding (in unsigned short action, in unsigned short reason, in DOMString number, in unsigned short timeSeconds, in unsigned short serviceClass, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SetCallForwarding(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void getCallBarring (in unsigned short program, in DOMString password, in unsigned short serviceClass, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD GetCallBarring(uint16_t program, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void setCallBarring (in unsigned short program, in bool enabled, in DOMString password, in unsigned short serviceClass, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SetCallBarring(uint16_t program, bool enabled, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void changeCallBarringPassword (in DOMString pin, in DOMString newPin, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD ChangeCallBarringPassword(const nsAString & pin, const nsAString & newPin, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void setCallWaiting (in bool enabled, in unsigned short serviceClass, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SetCallWaiting(bool enabled, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void getCallWaiting (in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD GetCallWaiting(nsIMobileConnectionCallback *requestCallback) = 0;

  /* void setCallingLineIdRestriction (in unsigned short clirMode, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SetCallingLineIdRestriction(uint16_t clirMode, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void getCallingLineIdRestriction (in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD GetCallingLineIdRestriction(nsIMobileConnectionCallback *requestCallback) = 0;

  /* void exitEmergencyCbMode (in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD ExitEmergencyCbMode(nsIMobileConnectionCallback *requestCallback) = 0;

  /* void setRadioEnabled (in bool enabled, in nsIMobileConnectionCallback requestCallback); */
  NS_IMETHOD SetRadioEnabled(bool enabled, nsIMobileConnectionCallback *requestCallback) = 0;

  /* void getNeighboringCellIds (in nsINeighboringCellIdsCallback callback); */
  NS_IMETHOD GetNeighboringCellIds(nsINeighboringCellIdsCallback *callback) = 0;

  /* void getCellInfoList (in nsICellInfoListCallback callback); */
  NS_IMETHOD GetCellInfoList(nsICellInfoListCallback *callback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileConnection, NS_IMOBILECONNECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILECONNECTION \
  NS_IMETHOD GetServiceId(uint32_t *aServiceId) override; \
  NS_IMETHOD RegisterListener(nsIMobileConnectionListener *listener) override; \
  NS_IMETHOD UnregisterListener(nsIMobileConnectionListener *listener) override; \
  NS_IMETHOD GetLastKnownNetwork(nsAString & aLastKnownNetwork) override; \
  NS_IMETHOD GetLastKnownHomeNetwork(nsAString & aLastKnownHomeNetwork) override; \
  NS_IMETHOD GetVoice(nsIMobileConnectionInfo * *aVoice) override; \
  NS_IMETHOD GetData(nsIMobileConnectionInfo * *aData) override; \
  NS_IMETHOD GetNetworkSelectionMode(int32_t *aNetworkSelectionMode) override; \
  NS_IMETHOD GetRadioState(int32_t *aRadioState) override; \
  NS_IMETHOD GetSupportedNetworkTypes(int32_t **types, uint32_t *length) override; \
  NS_IMETHOD GetNetworks(nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SelectNetwork(nsIMobileNetworkInfo *network, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SelectNetworkAutomatically(nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SetPreferredNetworkType(int32_t type, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD GetPreferredNetworkType(nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SetRoamingPreference(int32_t mode, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD GetRoamingPreference(nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SetVoicePrivacyMode(bool enabled, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD GetVoicePrivacyMode(nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD GetCallForwarding(uint16_t reason, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SetCallForwarding(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD GetCallBarring(uint16_t program, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SetCallBarring(uint16_t program, bool enabled, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD ChangeCallBarringPassword(const nsAString & pin, const nsAString & newPin, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SetCallWaiting(bool enabled, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD GetCallWaiting(nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SetCallingLineIdRestriction(uint16_t clirMode, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD GetCallingLineIdRestriction(nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD ExitEmergencyCbMode(nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD SetRadioEnabled(bool enabled, nsIMobileConnectionCallback *requestCallback) override; \
  NS_IMETHOD GetNeighboringCellIds(nsINeighboringCellIdsCallback *callback) override; \
  NS_IMETHOD GetCellInfoList(nsICellInfoListCallback *callback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILECONNECTION(_to) \
  NS_IMETHOD GetServiceId(uint32_t *aServiceId) override { return _to GetServiceId(aServiceId); } \
  NS_IMETHOD RegisterListener(nsIMobileConnectionListener *listener) override { return _to RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsIMobileConnectionListener *listener) override { return _to UnregisterListener(listener); } \
  NS_IMETHOD GetLastKnownNetwork(nsAString & aLastKnownNetwork) override { return _to GetLastKnownNetwork(aLastKnownNetwork); } \
  NS_IMETHOD GetLastKnownHomeNetwork(nsAString & aLastKnownHomeNetwork) override { return _to GetLastKnownHomeNetwork(aLastKnownHomeNetwork); } \
  NS_IMETHOD GetVoice(nsIMobileConnectionInfo * *aVoice) override { return _to GetVoice(aVoice); } \
  NS_IMETHOD GetData(nsIMobileConnectionInfo * *aData) override { return _to GetData(aData); } \
  NS_IMETHOD GetNetworkSelectionMode(int32_t *aNetworkSelectionMode) override { return _to GetNetworkSelectionMode(aNetworkSelectionMode); } \
  NS_IMETHOD GetRadioState(int32_t *aRadioState) override { return _to GetRadioState(aRadioState); } \
  NS_IMETHOD GetSupportedNetworkTypes(int32_t **types, uint32_t *length) override { return _to GetSupportedNetworkTypes(types, length); } \
  NS_IMETHOD GetNetworks(nsIMobileConnectionCallback *requestCallback) override { return _to GetNetworks(requestCallback); } \
  NS_IMETHOD SelectNetwork(nsIMobileNetworkInfo *network, nsIMobileConnectionCallback *requestCallback) override { return _to SelectNetwork(network, requestCallback); } \
  NS_IMETHOD SelectNetworkAutomatically(nsIMobileConnectionCallback *requestCallback) override { return _to SelectNetworkAutomatically(requestCallback); } \
  NS_IMETHOD SetPreferredNetworkType(int32_t type, nsIMobileConnectionCallback *requestCallback) override { return _to SetPreferredNetworkType(type, requestCallback); } \
  NS_IMETHOD GetPreferredNetworkType(nsIMobileConnectionCallback *requestCallback) override { return _to GetPreferredNetworkType(requestCallback); } \
  NS_IMETHOD SetRoamingPreference(int32_t mode, nsIMobileConnectionCallback *requestCallback) override { return _to SetRoamingPreference(mode, requestCallback); } \
  NS_IMETHOD GetRoamingPreference(nsIMobileConnectionCallback *requestCallback) override { return _to GetRoamingPreference(requestCallback); } \
  NS_IMETHOD SetVoicePrivacyMode(bool enabled, nsIMobileConnectionCallback *requestCallback) override { return _to SetVoicePrivacyMode(enabled, requestCallback); } \
  NS_IMETHOD GetVoicePrivacyMode(nsIMobileConnectionCallback *requestCallback) override { return _to GetVoicePrivacyMode(requestCallback); } \
  NS_IMETHOD GetCallForwarding(uint16_t reason, nsIMobileConnectionCallback *requestCallback) override { return _to GetCallForwarding(reason, requestCallback); } \
  NS_IMETHOD SetCallForwarding(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override { return _to SetCallForwarding(action, reason, number, timeSeconds, serviceClass, requestCallback); } \
  NS_IMETHOD GetCallBarring(uint16_t program, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override { return _to GetCallBarring(program, password, serviceClass, requestCallback); } \
  NS_IMETHOD SetCallBarring(uint16_t program, bool enabled, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override { return _to SetCallBarring(program, enabled, password, serviceClass, requestCallback); } \
  NS_IMETHOD ChangeCallBarringPassword(const nsAString & pin, const nsAString & newPin, nsIMobileConnectionCallback *requestCallback) override { return _to ChangeCallBarringPassword(pin, newPin, requestCallback); } \
  NS_IMETHOD SetCallWaiting(bool enabled, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override { return _to SetCallWaiting(enabled, serviceClass, requestCallback); } \
  NS_IMETHOD GetCallWaiting(nsIMobileConnectionCallback *requestCallback) override { return _to GetCallWaiting(requestCallback); } \
  NS_IMETHOD SetCallingLineIdRestriction(uint16_t clirMode, nsIMobileConnectionCallback *requestCallback) override { return _to SetCallingLineIdRestriction(clirMode, requestCallback); } \
  NS_IMETHOD GetCallingLineIdRestriction(nsIMobileConnectionCallback *requestCallback) override { return _to GetCallingLineIdRestriction(requestCallback); } \
  NS_IMETHOD ExitEmergencyCbMode(nsIMobileConnectionCallback *requestCallback) override { return _to ExitEmergencyCbMode(requestCallback); } \
  NS_IMETHOD SetRadioEnabled(bool enabled, nsIMobileConnectionCallback *requestCallback) override { return _to SetRadioEnabled(enabled, requestCallback); } \
  NS_IMETHOD GetNeighboringCellIds(nsINeighboringCellIdsCallback *callback) override { return _to GetNeighboringCellIds(callback); } \
  NS_IMETHOD GetCellInfoList(nsICellInfoListCallback *callback) override { return _to GetCellInfoList(callback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILECONNECTION(_to) \
  NS_IMETHOD GetServiceId(uint32_t *aServiceId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceId(aServiceId); } \
  NS_IMETHOD RegisterListener(nsIMobileConnectionListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsIMobileConnectionListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterListener(listener); } \
  NS_IMETHOD GetLastKnownNetwork(nsAString & aLastKnownNetwork) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastKnownNetwork(aLastKnownNetwork); } \
  NS_IMETHOD GetLastKnownHomeNetwork(nsAString & aLastKnownHomeNetwork) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastKnownHomeNetwork(aLastKnownHomeNetwork); } \
  NS_IMETHOD GetVoice(nsIMobileConnectionInfo * *aVoice) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVoice(aVoice); } \
  NS_IMETHOD GetData(nsIMobileConnectionInfo * *aData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD GetNetworkSelectionMode(int32_t *aNetworkSelectionMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetworkSelectionMode(aNetworkSelectionMode); } \
  NS_IMETHOD GetRadioState(int32_t *aRadioState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRadioState(aRadioState); } \
  NS_IMETHOD GetSupportedNetworkTypes(int32_t **types, uint32_t *length) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSupportedNetworkTypes(types, length); } \
  NS_IMETHOD GetNetworks(nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetworks(requestCallback); } \
  NS_IMETHOD SelectNetwork(nsIMobileNetworkInfo *network, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectNetwork(network, requestCallback); } \
  NS_IMETHOD SelectNetworkAutomatically(nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectNetworkAutomatically(requestCallback); } \
  NS_IMETHOD SetPreferredNetworkType(int32_t type, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreferredNetworkType(type, requestCallback); } \
  NS_IMETHOD GetPreferredNetworkType(nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferredNetworkType(requestCallback); } \
  NS_IMETHOD SetRoamingPreference(int32_t mode, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRoamingPreference(mode, requestCallback); } \
  NS_IMETHOD GetRoamingPreference(nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoamingPreference(requestCallback); } \
  NS_IMETHOD SetVoicePrivacyMode(bool enabled, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVoicePrivacyMode(enabled, requestCallback); } \
  NS_IMETHOD GetVoicePrivacyMode(nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVoicePrivacyMode(requestCallback); } \
  NS_IMETHOD GetCallForwarding(uint16_t reason, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallForwarding(reason, requestCallback); } \
  NS_IMETHOD SetCallForwarding(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCallForwarding(action, reason, number, timeSeconds, serviceClass, requestCallback); } \
  NS_IMETHOD GetCallBarring(uint16_t program, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallBarring(program, password, serviceClass, requestCallback); } \
  NS_IMETHOD SetCallBarring(uint16_t program, bool enabled, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCallBarring(program, enabled, password, serviceClass, requestCallback); } \
  NS_IMETHOD ChangeCallBarringPassword(const nsAString & pin, const nsAString & newPin, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ChangeCallBarringPassword(pin, newPin, requestCallback); } \
  NS_IMETHOD SetCallWaiting(bool enabled, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCallWaiting(enabled, serviceClass, requestCallback); } \
  NS_IMETHOD GetCallWaiting(nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallWaiting(requestCallback); } \
  NS_IMETHOD SetCallingLineIdRestriction(uint16_t clirMode, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCallingLineIdRestriction(clirMode, requestCallback); } \
  NS_IMETHOD GetCallingLineIdRestriction(nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallingLineIdRestriction(requestCallback); } \
  NS_IMETHOD ExitEmergencyCbMode(nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExitEmergencyCbMode(requestCallback); } \
  NS_IMETHOD SetRadioEnabled(bool enabled, nsIMobileConnectionCallback *requestCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRadioEnabled(enabled, requestCallback); } \
  NS_IMETHOD GetNeighboringCellIds(nsINeighboringCellIdsCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNeighboringCellIds(callback); } \
  NS_IMETHOD GetCellInfoList(nsICellInfoListCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCellInfoList(callback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileConnection : public nsIMobileConnection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILECONNECTION

  nsMobileConnection();

private:
  ~nsMobileConnection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileConnection, nsIMobileConnection)

nsMobileConnection::nsMobileConnection()
{
  /* member initializers and constructor code */
}

nsMobileConnection::~nsMobileConnection()
{
  /* destructor code */
}

/* readonly attribute unsigned long serviceId; */
NS_IMETHODIMP nsMobileConnection::GetServiceId(uint32_t *aServiceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerListener (in nsIMobileConnectionListener listener); */
NS_IMETHODIMP nsMobileConnection::RegisterListener(nsIMobileConnectionListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterListener (in nsIMobileConnectionListener listener); */
NS_IMETHODIMP nsMobileConnection::UnregisterListener(nsIMobileConnectionListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastKnownNetwork; */
NS_IMETHODIMP nsMobileConnection::GetLastKnownNetwork(nsAString & aLastKnownNetwork)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastKnownHomeNetwork; */
NS_IMETHODIMP nsMobileConnection::GetLastKnownHomeNetwork(nsAString & aLastKnownHomeNetwork)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMobileConnectionInfo voice; */
NS_IMETHODIMP nsMobileConnection::GetVoice(nsIMobileConnectionInfo * *aVoice)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMobileConnectionInfo data; */
NS_IMETHODIMP nsMobileConnection::GetData(nsIMobileConnectionInfo * *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long networkSelectionMode; */
NS_IMETHODIMP nsMobileConnection::GetNetworkSelectionMode(int32_t *aNetworkSelectionMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long radioState; */
NS_IMETHODIMP nsMobileConnection::GetRadioState(int32_t *aRadioState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSupportedNetworkTypes ([array, size_is (length)] out long types, [retval] out unsigned long length); */
NS_IMETHODIMP nsMobileConnection::GetSupportedNetworkTypes(int32_t **types, uint32_t *length)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNetworks (in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::GetNetworks(nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectNetwork (in nsIMobileNetworkInfo network, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SelectNetwork(nsIMobileNetworkInfo *network, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectNetworkAutomatically (in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SelectNetworkAutomatically(nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPreferredNetworkType (in long type, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SetPreferredNetworkType(int32_t type, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPreferredNetworkType (in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::GetPreferredNetworkType(nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRoamingPreference (in long mode, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SetRoamingPreference(int32_t mode, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRoamingPreference (in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::GetRoamingPreference(nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setVoicePrivacyMode (in bool enabled, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SetVoicePrivacyMode(bool enabled, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getVoicePrivacyMode (in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::GetVoicePrivacyMode(nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCallForwarding (in unsigned short reason, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::GetCallForwarding(uint16_t reason, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCallForwarding (in unsigned short action, in unsigned short reason, in DOMString number, in unsigned short timeSeconds, in unsigned short serviceClass, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SetCallForwarding(uint16_t action, uint16_t reason, const nsAString & number, uint16_t timeSeconds, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCallBarring (in unsigned short program, in DOMString password, in unsigned short serviceClass, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::GetCallBarring(uint16_t program, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCallBarring (in unsigned short program, in bool enabled, in DOMString password, in unsigned short serviceClass, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SetCallBarring(uint16_t program, bool enabled, const nsAString & password, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void changeCallBarringPassword (in DOMString pin, in DOMString newPin, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::ChangeCallBarringPassword(const nsAString & pin, const nsAString & newPin, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCallWaiting (in bool enabled, in unsigned short serviceClass, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SetCallWaiting(bool enabled, uint16_t serviceClass, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCallWaiting (in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::GetCallWaiting(nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCallingLineIdRestriction (in unsigned short clirMode, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SetCallingLineIdRestriction(uint16_t clirMode, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCallingLineIdRestriction (in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::GetCallingLineIdRestriction(nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exitEmergencyCbMode (in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::ExitEmergencyCbMode(nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRadioEnabled (in bool enabled, in nsIMobileConnectionCallback requestCallback); */
NS_IMETHODIMP nsMobileConnection::SetRadioEnabled(bool enabled, nsIMobileConnectionCallback *requestCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNeighboringCellIds (in nsINeighboringCellIdsCallback callback); */
NS_IMETHODIMP nsMobileConnection::GetNeighboringCellIds(nsINeighboringCellIdsCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCellInfoList (in nsICellInfoListCallback callback); */
NS_IMETHODIMP nsMobileConnection::GetCellInfoList(nsICellInfoListCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileConnectionService_h__ */
