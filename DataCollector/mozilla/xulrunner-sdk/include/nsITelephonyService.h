/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITelephonyService.idl
 */

#ifndef __gen_nsITelephonyService_h__
#define __gen_nsITelephonyService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMobileCallForwardingOptions; /* forward declaration */

class nsITelephonyCallInfo; /* forward declaration */


/* starting interface:    nsITelephonyListener */
#define NS_ITELEPHONYLISTENER_IID_STR "80faf34e-286b-4487-bd55-135bd92668b9"

#define NS_ITELEPHONYLISTENER_IID \
  {0x80faf34e, 0x286b, 0x4487, \
    { 0xbd, 0x55, 0x13, 0x5b, 0xd9, 0x26, 0x68, 0xb9 }}

class NS_NO_VTABLE nsITelephonyListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEPHONYLISTENER_IID)

  /* void enumerateCallStateComplete (); */
  NS_IMETHOD EnumerateCallStateComplete(void) = 0;

  /* void enumerateCallState (in nsITelephonyCallInfo info); */
  NS_IMETHOD EnumerateCallState(nsITelephonyCallInfo *info) = 0;

  /* void callStateChanged (in unsigned long length, [array, size_is (length)] in nsITelephonyCallInfo allInfo); */
  NS_IMETHOD CallStateChanged(uint32_t length, nsITelephonyCallInfo **allInfo) = 0;

  /* void conferenceCallStateChanged (in unsigned short callState); */
  NS_IMETHOD ConferenceCallStateChanged(uint16_t callState) = 0;

  /* void supplementaryServiceNotification (in unsigned long clientId, in long callIndex, in unsigned short notification); */
  NS_IMETHOD SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification) = 0;

  /* void notifyCdmaCallWaiting (in unsigned long clientId, in AString number, in unsigned short numberPresentation, in AString name, in unsigned short namePresentation); */
  NS_IMETHOD NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number, uint16_t numberPresentation, const nsAString & name, uint16_t namePresentation) = 0;

  /* void notifyConferenceError (in AString name, in AString message); */
  NS_IMETHOD NotifyConferenceError(const nsAString & name, const nsAString & message) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelephonyListener, NS_ITELEPHONYLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEPHONYLISTENER \
  NS_IMETHOD EnumerateCallStateComplete(void) override; \
  NS_IMETHOD EnumerateCallState(nsITelephonyCallInfo *info) override; \
  NS_IMETHOD CallStateChanged(uint32_t length, nsITelephonyCallInfo **allInfo) override; \
  NS_IMETHOD ConferenceCallStateChanged(uint16_t callState) override; \
  NS_IMETHOD SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification) override; \
  NS_IMETHOD NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number, uint16_t numberPresentation, const nsAString & name, uint16_t namePresentation) override; \
  NS_IMETHOD NotifyConferenceError(const nsAString & name, const nsAString & message) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEPHONYLISTENER(_to) \
  NS_IMETHOD EnumerateCallStateComplete(void) override { return _to EnumerateCallStateComplete(); } \
  NS_IMETHOD EnumerateCallState(nsITelephonyCallInfo *info) override { return _to EnumerateCallState(info); } \
  NS_IMETHOD CallStateChanged(uint32_t length, nsITelephonyCallInfo **allInfo) override { return _to CallStateChanged(length, allInfo); } \
  NS_IMETHOD ConferenceCallStateChanged(uint16_t callState) override { return _to ConferenceCallStateChanged(callState); } \
  NS_IMETHOD SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification) override { return _to SupplementaryServiceNotification(clientId, callIndex, notification); } \
  NS_IMETHOD NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number, uint16_t numberPresentation, const nsAString & name, uint16_t namePresentation) override { return _to NotifyCdmaCallWaiting(clientId, number, numberPresentation, name, namePresentation); } \
  NS_IMETHOD NotifyConferenceError(const nsAString & name, const nsAString & message) override { return _to NotifyConferenceError(name, message); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEPHONYLISTENER(_to) \
  NS_IMETHOD EnumerateCallStateComplete(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateCallStateComplete(); } \
  NS_IMETHOD EnumerateCallState(nsITelephonyCallInfo *info) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateCallState(info); } \
  NS_IMETHOD CallStateChanged(uint32_t length, nsITelephonyCallInfo **allInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CallStateChanged(length, allInfo); } \
  NS_IMETHOD ConferenceCallStateChanged(uint16_t callState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ConferenceCallStateChanged(callState); } \
  NS_IMETHOD SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SupplementaryServiceNotification(clientId, callIndex, notification); } \
  NS_IMETHOD NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number, uint16_t numberPresentation, const nsAString & name, uint16_t namePresentation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCdmaCallWaiting(clientId, number, numberPresentation, name, namePresentation); } \
  NS_IMETHOD NotifyConferenceError(const nsAString & name, const nsAString & message) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyConferenceError(name, message); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelephonyListener : public nsITelephonyListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEPHONYLISTENER

  nsTelephonyListener();

private:
  ~nsTelephonyListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTelephonyListener, nsITelephonyListener)

nsTelephonyListener::nsTelephonyListener()
{
  /* member initializers and constructor code */
}

nsTelephonyListener::~nsTelephonyListener()
{
  /* destructor code */
}

/* void enumerateCallStateComplete (); */
NS_IMETHODIMP nsTelephonyListener::EnumerateCallStateComplete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enumerateCallState (in nsITelephonyCallInfo info); */
NS_IMETHODIMP nsTelephonyListener::EnumerateCallState(nsITelephonyCallInfo *info)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callStateChanged (in unsigned long length, [array, size_is (length)] in nsITelephonyCallInfo allInfo); */
NS_IMETHODIMP nsTelephonyListener::CallStateChanged(uint32_t length, nsITelephonyCallInfo **allInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void conferenceCallStateChanged (in unsigned short callState); */
NS_IMETHODIMP nsTelephonyListener::ConferenceCallStateChanged(uint16_t callState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void supplementaryServiceNotification (in unsigned long clientId, in long callIndex, in unsigned short notification); */
NS_IMETHODIMP nsTelephonyListener::SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyCdmaCallWaiting (in unsigned long clientId, in AString number, in unsigned short numberPresentation, in AString name, in unsigned short namePresentation); */
NS_IMETHODIMP nsTelephonyListener::NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number, uint16_t numberPresentation, const nsAString & name, uint16_t namePresentation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyConferenceError (in AString name, in AString message); */
NS_IMETHODIMP nsTelephonyListener::NotifyConferenceError(const nsAString & name, const nsAString & message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITelephonyCallback */
#define NS_ITELEPHONYCALLBACK_IID_STR "cffc3f9d-2c88-4a14-8ebc-f216caf0cc1d"

#define NS_ITELEPHONYCALLBACK_IID \
  {0xcffc3f9d, 0x2c88, 0x4a14, \
    { 0x8e, 0xbc, 0xf2, 0x16, 0xca, 0xf0, 0xcc, 0x1d }}

class NS_NO_VTABLE nsITelephonyCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEPHONYCALLBACK_IID)

  /* void notifySuccess (); */
  NS_IMETHOD NotifySuccess(void) = 0;

  /* void notifyError (in AString error); */
  NS_IMETHOD NotifyError(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelephonyCallback, NS_ITELEPHONYCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEPHONYCALLBACK \
  NS_IMETHOD NotifySuccess(void) override; \
  NS_IMETHOD NotifyError(const nsAString & error) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEPHONYCALLBACK(_to) \
  NS_IMETHOD NotifySuccess(void) override { return _to NotifySuccess(); } \
  NS_IMETHOD NotifyError(const nsAString & error) override { return _to NotifyError(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEPHONYCALLBACK(_to) \
  NS_IMETHOD NotifySuccess(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySuccess(); } \
  NS_IMETHOD NotifyError(const nsAString & error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyError(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelephonyCallback : public nsITelephonyCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEPHONYCALLBACK

  nsTelephonyCallback();

private:
  ~nsTelephonyCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTelephonyCallback, nsITelephonyCallback)

nsTelephonyCallback::nsTelephonyCallback()
{
  /* member initializers and constructor code */
}

nsTelephonyCallback::~nsTelephonyCallback()
{
  /* destructor code */
}

/* void notifySuccess (); */
NS_IMETHODIMP nsTelephonyCallback::NotifySuccess()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyError (in AString error); */
NS_IMETHODIMP nsTelephonyCallback::NotifyError(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITelephonyDialCallback */
#define NS_ITELEPHONYDIALCALLBACK_IID_STR "e16c6e6f-93c6-4e1e-99bf-592b98f67e15"

#define NS_ITELEPHONYDIALCALLBACK_IID \
  {0xe16c6e6f, 0x93c6, 0x4e1e, \
    { 0x99, 0xbf, 0x59, 0x2b, 0x98, 0xf6, 0x7e, 0x15 }}

class NS_NO_VTABLE nsITelephonyDialCallback : public nsITelephonyCallback {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEPHONYDIALCALLBACK_IID)

  /* void notifyDialMMI (in AString serviceCode); */
  NS_IMETHOD NotifyDialMMI(const nsAString & serviceCode) = 0;

  /* void notifyDialCallSuccess (in unsigned long cliendId, in unsigned long callIndex, in AString number); */
  NS_IMETHOD NotifyDialCallSuccess(uint32_t cliendId, uint32_t callIndex, const nsAString & number) = 0;

  /* void notifyDialMMISuccess (in AString statusMessage); */
  NS_IMETHOD NotifyDialMMISuccess(const nsAString & statusMessage) = 0;

  /* void notifyDialMMISuccessWithInteger (in AString statusMessage, in unsigned short aAdditionalInformation); */
  NS_IMETHOD NotifyDialMMISuccessWithInteger(const nsAString & statusMessage, uint16_t aAdditionalInformation) = 0;

  /* void notifyDialMMISuccessWithStrings (in AString statusMessage, in unsigned long aLength, [array, size_is (aLength)] in wstring aAdditionalInformation); */
  NS_IMETHOD NotifyDialMMISuccessWithStrings(const nsAString & statusMessage, uint32_t aLength, const char16_t * *aAdditionalInformation) = 0;

  /* void notifyDialMMISuccessWithCallForwardingOptions (in AString statusMessage, in unsigned long aLength, [array, size_is (aLength)] in nsIMobileCallForwardingOptions aAdditionalInformation); */
  NS_IMETHOD NotifyDialMMISuccessWithCallForwardingOptions(const nsAString & statusMessage, uint32_t aLength, nsIMobileCallForwardingOptions **aAdditionalInformation) = 0;

  /* void notifyDialMMIError (in AString error); */
  NS_IMETHOD NotifyDialMMIError(const nsAString & error) = 0;

  /* void notifyDialMMIErrorWithInfo (in AString error, in unsigned short info); */
  NS_IMETHOD NotifyDialMMIErrorWithInfo(const nsAString & error, uint16_t info) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelephonyDialCallback, NS_ITELEPHONYDIALCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEPHONYDIALCALLBACK \
  NS_IMETHOD NotifyDialMMI(const nsAString & serviceCode) override; \
  NS_IMETHOD NotifyDialCallSuccess(uint32_t cliendId, uint32_t callIndex, const nsAString & number) override; \
  NS_IMETHOD NotifyDialMMISuccess(const nsAString & statusMessage) override; \
  NS_IMETHOD NotifyDialMMISuccessWithInteger(const nsAString & statusMessage, uint16_t aAdditionalInformation) override; \
  NS_IMETHOD NotifyDialMMISuccessWithStrings(const nsAString & statusMessage, uint32_t aLength, const char16_t * *aAdditionalInformation) override; \
  NS_IMETHOD NotifyDialMMISuccessWithCallForwardingOptions(const nsAString & statusMessage, uint32_t aLength, nsIMobileCallForwardingOptions **aAdditionalInformation) override; \
  NS_IMETHOD NotifyDialMMIError(const nsAString & error) override; \
  NS_IMETHOD NotifyDialMMIErrorWithInfo(const nsAString & error, uint16_t info) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEPHONYDIALCALLBACK(_to) \
  NS_IMETHOD NotifyDialMMI(const nsAString & serviceCode) override { return _to NotifyDialMMI(serviceCode); } \
  NS_IMETHOD NotifyDialCallSuccess(uint32_t cliendId, uint32_t callIndex, const nsAString & number) override { return _to NotifyDialCallSuccess(cliendId, callIndex, number); } \
  NS_IMETHOD NotifyDialMMISuccess(const nsAString & statusMessage) override { return _to NotifyDialMMISuccess(statusMessage); } \
  NS_IMETHOD NotifyDialMMISuccessWithInteger(const nsAString & statusMessage, uint16_t aAdditionalInformation) override { return _to NotifyDialMMISuccessWithInteger(statusMessage, aAdditionalInformation); } \
  NS_IMETHOD NotifyDialMMISuccessWithStrings(const nsAString & statusMessage, uint32_t aLength, const char16_t * *aAdditionalInformation) override { return _to NotifyDialMMISuccessWithStrings(statusMessage, aLength, aAdditionalInformation); } \
  NS_IMETHOD NotifyDialMMISuccessWithCallForwardingOptions(const nsAString & statusMessage, uint32_t aLength, nsIMobileCallForwardingOptions **aAdditionalInformation) override { return _to NotifyDialMMISuccessWithCallForwardingOptions(statusMessage, aLength, aAdditionalInformation); } \
  NS_IMETHOD NotifyDialMMIError(const nsAString & error) override { return _to NotifyDialMMIError(error); } \
  NS_IMETHOD NotifyDialMMIErrorWithInfo(const nsAString & error, uint16_t info) override { return _to NotifyDialMMIErrorWithInfo(error, info); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEPHONYDIALCALLBACK(_to) \
  NS_IMETHOD NotifyDialMMI(const nsAString & serviceCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialMMI(serviceCode); } \
  NS_IMETHOD NotifyDialCallSuccess(uint32_t cliendId, uint32_t callIndex, const nsAString & number) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialCallSuccess(cliendId, callIndex, number); } \
  NS_IMETHOD NotifyDialMMISuccess(const nsAString & statusMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialMMISuccess(statusMessage); } \
  NS_IMETHOD NotifyDialMMISuccessWithInteger(const nsAString & statusMessage, uint16_t aAdditionalInformation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialMMISuccessWithInteger(statusMessage, aAdditionalInformation); } \
  NS_IMETHOD NotifyDialMMISuccessWithStrings(const nsAString & statusMessage, uint32_t aLength, const char16_t * *aAdditionalInformation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialMMISuccessWithStrings(statusMessage, aLength, aAdditionalInformation); } \
  NS_IMETHOD NotifyDialMMISuccessWithCallForwardingOptions(const nsAString & statusMessage, uint32_t aLength, nsIMobileCallForwardingOptions **aAdditionalInformation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialMMISuccessWithCallForwardingOptions(statusMessage, aLength, aAdditionalInformation); } \
  NS_IMETHOD NotifyDialMMIError(const nsAString & error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialMMIError(error); } \
  NS_IMETHOD NotifyDialMMIErrorWithInfo(const nsAString & error, uint16_t info) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialMMIErrorWithInfo(error, info); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelephonyDialCallback : public nsITelephonyDialCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEPHONYDIALCALLBACK

  nsTelephonyDialCallback();

private:
  ~nsTelephonyDialCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTelephonyDialCallback, nsITelephonyDialCallback)

nsTelephonyDialCallback::nsTelephonyDialCallback()
{
  /* member initializers and constructor code */
}

nsTelephonyDialCallback::~nsTelephonyDialCallback()
{
  /* destructor code */
}

/* void notifyDialMMI (in AString serviceCode); */
NS_IMETHODIMP nsTelephonyDialCallback::NotifyDialMMI(const nsAString & serviceCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDialCallSuccess (in unsigned long cliendId, in unsigned long callIndex, in AString number); */
NS_IMETHODIMP nsTelephonyDialCallback::NotifyDialCallSuccess(uint32_t cliendId, uint32_t callIndex, const nsAString & number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDialMMISuccess (in AString statusMessage); */
NS_IMETHODIMP nsTelephonyDialCallback::NotifyDialMMISuccess(const nsAString & statusMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDialMMISuccessWithInteger (in AString statusMessage, in unsigned short aAdditionalInformation); */
NS_IMETHODIMP nsTelephonyDialCallback::NotifyDialMMISuccessWithInteger(const nsAString & statusMessage, uint16_t aAdditionalInformation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDialMMISuccessWithStrings (in AString statusMessage, in unsigned long aLength, [array, size_is (aLength)] in wstring aAdditionalInformation); */
NS_IMETHODIMP nsTelephonyDialCallback::NotifyDialMMISuccessWithStrings(const nsAString & statusMessage, uint32_t aLength, const char16_t * *aAdditionalInformation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDialMMISuccessWithCallForwardingOptions (in AString statusMessage, in unsigned long aLength, [array, size_is (aLength)] in nsIMobileCallForwardingOptions aAdditionalInformation); */
NS_IMETHODIMP nsTelephonyDialCallback::NotifyDialMMISuccessWithCallForwardingOptions(const nsAString & statusMessage, uint32_t aLength, nsIMobileCallForwardingOptions **aAdditionalInformation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDialMMIError (in AString error); */
NS_IMETHODIMP nsTelephonyDialCallback::NotifyDialMMIError(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDialMMIErrorWithInfo (in AString error, in unsigned short info); */
NS_IMETHODIMP nsTelephonyDialCallback::NotifyDialMMIErrorWithInfo(const nsAString & error, uint16_t info)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define TELEPHONY_SERVICE_CID \
  { 0x9cf8aa52, 0x7c1c, 0x4cde, { 0x97, 0x4e, 0xed, 0x2a, 0xa0, 0xe7, 0x35, 0xfa } }
#define TELEPHONY_SERVICE_CONTRACTID \
  "@mozilla.org/telephony/telephonyservice;1"

/* starting interface:    nsITelephonyService */
#define NS_ITELEPHONYSERVICE_IID_STR "75e4b5e3-6710-4156-bdaa-ba1081f390f4"

#define NS_ITELEPHONYSERVICE_IID \
  {0x75e4b5e3, 0x6710, 0x4156, \
    { 0xbd, 0xaa, 0xba, 0x10, 0x81, 0xf3, 0x90, 0xf4 }}

class NS_NO_VTABLE nsITelephonyService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEPHONYSERVICE_IID)

  enum {
    CALL_STATE_UNKNOWN = 0U,
    CALL_STATE_DIALING = 1U,
    CALL_STATE_ALERTING = 2U,
    CALL_STATE_CONNECTED = 3U,
    CALL_STATE_HELD = 4U,
    CALL_STATE_DISCONNECTED = 5U,
    CALL_STATE_INCOMING = 6U,
    NOTIFICATION_REMOTE_HELD = 0U,
    NOTIFICATION_REMOTE_RESUMED = 1U,
    CALL_PRESENTATION_ALLOWED = 0U,
    CALL_PRESENTATION_RESTRICTED = 1U,
    CALL_PRESENTATION_UNKNOWN = 2U,
    CALL_PRESENTATION_PAYPHONE = 3U
  };

  /* readonly attribute unsigned long defaultServiceId; */
  NS_IMETHOD GetDefaultServiceId(uint32_t *aDefaultServiceId) = 0;

  /* void registerListener (in nsITelephonyListener listener); */
  NS_IMETHOD RegisterListener(nsITelephonyListener *listener) = 0;

  /* void unregisterListener (in nsITelephonyListener listener); */
  NS_IMETHOD UnregisterListener(nsITelephonyListener *listener) = 0;

  /* void enumerateCalls (in nsITelephonyListener listener); */
  NS_IMETHOD EnumerateCalls(nsITelephonyListener *listener) = 0;

  /* void dial (in unsigned long clientId, in DOMString number, in boolean isEmergency, in nsITelephonyDialCallback callback); */
  NS_IMETHOD Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyDialCallback *callback) = 0;

  /* void sendTones (in unsigned long clientId, in DOMString dtmfChars, in unsigned long pauseDuration, in unsigned long toneDuration, in nsITelephonyCallback callback); */
  NS_IMETHOD SendTones(uint32_t clientId, const nsAString & dtmfChars, uint32_t pauseDuration, uint32_t toneDuration, nsITelephonyCallback *callback) = 0;

  /* void startTone (in unsigned long clientId, in DOMString dtmfChar); */
  NS_IMETHOD StartTone(uint32_t clientId, const nsAString & dtmfChar) = 0;

  /* void stopTone (in unsigned long clientId); */
  NS_IMETHOD StopTone(uint32_t clientId) = 0;

  /* void answerCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
  NS_IMETHOD AnswerCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) = 0;

  /* void rejectCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
  NS_IMETHOD RejectCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) = 0;

  /* void hangUpCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
  NS_IMETHOD HangUpCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) = 0;

  /* void holdCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
  NS_IMETHOD HoldCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) = 0;

  /* void resumeCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
  NS_IMETHOD ResumeCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) = 0;

  /* void conferenceCall (in unsigned long clientId, in nsITelephonyCallback callback); */
  NS_IMETHOD ConferenceCall(uint32_t clientId, nsITelephonyCallback *callback) = 0;

  /* void separateCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
  NS_IMETHOD SeparateCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) = 0;

  /* void hangUpConference (in unsigned long clientId, in nsITelephonyCallback callback); */
  NS_IMETHOD HangUpConference(uint32_t clientId, nsITelephonyCallback *callback) = 0;

  /* void holdConference (in unsigned long clientId, in nsITelephonyCallback callback); */
  NS_IMETHOD HoldConference(uint32_t clientId, nsITelephonyCallback *callback) = 0;

  /* void resumeConference (in unsigned long clientId, in nsITelephonyCallback callback); */
  NS_IMETHOD ResumeConference(uint32_t clientId, nsITelephonyCallback *callback) = 0;

  /* void sendUSSD (in unsigned long clientId, in DOMString ussd, in nsITelephonyCallback callback); */
  NS_IMETHOD SendUSSD(uint32_t clientId, const nsAString & ussd, nsITelephonyCallback *callback) = 0;

  /* void cancelUSSD (in unsigned long cliendId, in nsITelephonyCallback callback); */
  NS_IMETHOD CancelUSSD(uint32_t cliendId, nsITelephonyCallback *callback) = 0;

  /* attribute bool microphoneMuted; */
  NS_IMETHOD GetMicrophoneMuted(bool *aMicrophoneMuted) = 0;
  NS_IMETHOD SetMicrophoneMuted(bool aMicrophoneMuted) = 0;

  /* attribute bool speakerEnabled; */
  NS_IMETHOD GetSpeakerEnabled(bool *aSpeakerEnabled) = 0;
  NS_IMETHOD SetSpeakerEnabled(bool aSpeakerEnabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelephonyService, NS_ITELEPHONYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEPHONYSERVICE \
  NS_IMETHOD GetDefaultServiceId(uint32_t *aDefaultServiceId) override; \
  NS_IMETHOD RegisterListener(nsITelephonyListener *listener) override; \
  NS_IMETHOD UnregisterListener(nsITelephonyListener *listener) override; \
  NS_IMETHOD EnumerateCalls(nsITelephonyListener *listener) override; \
  NS_IMETHOD Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyDialCallback *callback) override; \
  NS_IMETHOD SendTones(uint32_t clientId, const nsAString & dtmfChars, uint32_t pauseDuration, uint32_t toneDuration, nsITelephonyCallback *callback) override; \
  NS_IMETHOD StartTone(uint32_t clientId, const nsAString & dtmfChar) override; \
  NS_IMETHOD StopTone(uint32_t clientId) override; \
  NS_IMETHOD AnswerCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override; \
  NS_IMETHOD RejectCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override; \
  NS_IMETHOD HangUpCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override; \
  NS_IMETHOD HoldCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override; \
  NS_IMETHOD ResumeCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override; \
  NS_IMETHOD ConferenceCall(uint32_t clientId, nsITelephonyCallback *callback) override; \
  NS_IMETHOD SeparateCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override; \
  NS_IMETHOD HangUpConference(uint32_t clientId, nsITelephonyCallback *callback) override; \
  NS_IMETHOD HoldConference(uint32_t clientId, nsITelephonyCallback *callback) override; \
  NS_IMETHOD ResumeConference(uint32_t clientId, nsITelephonyCallback *callback) override; \
  NS_IMETHOD SendUSSD(uint32_t clientId, const nsAString & ussd, nsITelephonyCallback *callback) override; \
  NS_IMETHOD CancelUSSD(uint32_t cliendId, nsITelephonyCallback *callback) override; \
  NS_IMETHOD GetMicrophoneMuted(bool *aMicrophoneMuted) override; \
  NS_IMETHOD SetMicrophoneMuted(bool aMicrophoneMuted) override; \
  NS_IMETHOD GetSpeakerEnabled(bool *aSpeakerEnabled) override; \
  NS_IMETHOD SetSpeakerEnabled(bool aSpeakerEnabled) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEPHONYSERVICE(_to) \
  NS_IMETHOD GetDefaultServiceId(uint32_t *aDefaultServiceId) override { return _to GetDefaultServiceId(aDefaultServiceId); } \
  NS_IMETHOD RegisterListener(nsITelephonyListener *listener) override { return _to RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsITelephonyListener *listener) override { return _to UnregisterListener(listener); } \
  NS_IMETHOD EnumerateCalls(nsITelephonyListener *listener) override { return _to EnumerateCalls(listener); } \
  NS_IMETHOD Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyDialCallback *callback) override { return _to Dial(clientId, number, isEmergency, callback); } \
  NS_IMETHOD SendTones(uint32_t clientId, const nsAString & dtmfChars, uint32_t pauseDuration, uint32_t toneDuration, nsITelephonyCallback *callback) override { return _to SendTones(clientId, dtmfChars, pauseDuration, toneDuration, callback); } \
  NS_IMETHOD StartTone(uint32_t clientId, const nsAString & dtmfChar) override { return _to StartTone(clientId, dtmfChar); } \
  NS_IMETHOD StopTone(uint32_t clientId) override { return _to StopTone(clientId); } \
  NS_IMETHOD AnswerCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return _to AnswerCall(clientId, callIndex, callback); } \
  NS_IMETHOD RejectCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return _to RejectCall(clientId, callIndex, callback); } \
  NS_IMETHOD HangUpCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return _to HangUpCall(clientId, callIndex, callback); } \
  NS_IMETHOD HoldCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return _to HoldCall(clientId, callIndex, callback); } \
  NS_IMETHOD ResumeCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return _to ResumeCall(clientId, callIndex, callback); } \
  NS_IMETHOD ConferenceCall(uint32_t clientId, nsITelephonyCallback *callback) override { return _to ConferenceCall(clientId, callback); } \
  NS_IMETHOD SeparateCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return _to SeparateCall(clientId, callIndex, callback); } \
  NS_IMETHOD HangUpConference(uint32_t clientId, nsITelephonyCallback *callback) override { return _to HangUpConference(clientId, callback); } \
  NS_IMETHOD HoldConference(uint32_t clientId, nsITelephonyCallback *callback) override { return _to HoldConference(clientId, callback); } \
  NS_IMETHOD ResumeConference(uint32_t clientId, nsITelephonyCallback *callback) override { return _to ResumeConference(clientId, callback); } \
  NS_IMETHOD SendUSSD(uint32_t clientId, const nsAString & ussd, nsITelephonyCallback *callback) override { return _to SendUSSD(clientId, ussd, callback); } \
  NS_IMETHOD CancelUSSD(uint32_t cliendId, nsITelephonyCallback *callback) override { return _to CancelUSSD(cliendId, callback); } \
  NS_IMETHOD GetMicrophoneMuted(bool *aMicrophoneMuted) override { return _to GetMicrophoneMuted(aMicrophoneMuted); } \
  NS_IMETHOD SetMicrophoneMuted(bool aMicrophoneMuted) override { return _to SetMicrophoneMuted(aMicrophoneMuted); } \
  NS_IMETHOD GetSpeakerEnabled(bool *aSpeakerEnabled) override { return _to GetSpeakerEnabled(aSpeakerEnabled); } \
  NS_IMETHOD SetSpeakerEnabled(bool aSpeakerEnabled) override { return _to SetSpeakerEnabled(aSpeakerEnabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEPHONYSERVICE(_to) \
  NS_IMETHOD GetDefaultServiceId(uint32_t *aDefaultServiceId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultServiceId(aDefaultServiceId); } \
  NS_IMETHOD RegisterListener(nsITelephonyListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsITelephonyListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterListener(listener); } \
  NS_IMETHOD EnumerateCalls(nsITelephonyListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateCalls(listener); } \
  NS_IMETHOD Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyDialCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Dial(clientId, number, isEmergency, callback); } \
  NS_IMETHOD SendTones(uint32_t clientId, const nsAString & dtmfChars, uint32_t pauseDuration, uint32_t toneDuration, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendTones(clientId, dtmfChars, pauseDuration, toneDuration, callback); } \
  NS_IMETHOD StartTone(uint32_t clientId, const nsAString & dtmfChar) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartTone(clientId, dtmfChar); } \
  NS_IMETHOD StopTone(uint32_t clientId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StopTone(clientId); } \
  NS_IMETHOD AnswerCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AnswerCall(clientId, callIndex, callback); } \
  NS_IMETHOD RejectCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RejectCall(clientId, callIndex, callback); } \
  NS_IMETHOD HangUpCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HangUpCall(clientId, callIndex, callback); } \
  NS_IMETHOD HoldCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HoldCall(clientId, callIndex, callback); } \
  NS_IMETHOD ResumeCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeCall(clientId, callIndex, callback); } \
  NS_IMETHOD ConferenceCall(uint32_t clientId, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ConferenceCall(clientId, callback); } \
  NS_IMETHOD SeparateCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SeparateCall(clientId, callIndex, callback); } \
  NS_IMETHOD HangUpConference(uint32_t clientId, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HangUpConference(clientId, callback); } \
  NS_IMETHOD HoldConference(uint32_t clientId, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HoldConference(clientId, callback); } \
  NS_IMETHOD ResumeConference(uint32_t clientId, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeConference(clientId, callback); } \
  NS_IMETHOD SendUSSD(uint32_t clientId, const nsAString & ussd, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendUSSD(clientId, ussd, callback); } \
  NS_IMETHOD CancelUSSD(uint32_t cliendId, nsITelephonyCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelUSSD(cliendId, callback); } \
  NS_IMETHOD GetMicrophoneMuted(bool *aMicrophoneMuted) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMicrophoneMuted(aMicrophoneMuted); } \
  NS_IMETHOD SetMicrophoneMuted(bool aMicrophoneMuted) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMicrophoneMuted(aMicrophoneMuted); } \
  NS_IMETHOD GetSpeakerEnabled(bool *aSpeakerEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpeakerEnabled(aSpeakerEnabled); } \
  NS_IMETHOD SetSpeakerEnabled(bool aSpeakerEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpeakerEnabled(aSpeakerEnabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelephonyService : public nsITelephonyService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEPHONYSERVICE

  nsTelephonyService();

private:
  ~nsTelephonyService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTelephonyService, nsITelephonyService)

nsTelephonyService::nsTelephonyService()
{
  /* member initializers and constructor code */
}

nsTelephonyService::~nsTelephonyService()
{
  /* destructor code */
}

/* readonly attribute unsigned long defaultServiceId; */
NS_IMETHODIMP nsTelephonyService::GetDefaultServiceId(uint32_t *aDefaultServiceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerListener (in nsITelephonyListener listener); */
NS_IMETHODIMP nsTelephonyService::RegisterListener(nsITelephonyListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterListener (in nsITelephonyListener listener); */
NS_IMETHODIMP nsTelephonyService::UnregisterListener(nsITelephonyListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enumerateCalls (in nsITelephonyListener listener); */
NS_IMETHODIMP nsTelephonyService::EnumerateCalls(nsITelephonyListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dial (in unsigned long clientId, in DOMString number, in boolean isEmergency, in nsITelephonyDialCallback callback); */
NS_IMETHODIMP nsTelephonyService::Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyDialCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendTones (in unsigned long clientId, in DOMString dtmfChars, in unsigned long pauseDuration, in unsigned long toneDuration, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::SendTones(uint32_t clientId, const nsAString & dtmfChars, uint32_t pauseDuration, uint32_t toneDuration, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startTone (in unsigned long clientId, in DOMString dtmfChar); */
NS_IMETHODIMP nsTelephonyService::StartTone(uint32_t clientId, const nsAString & dtmfChar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopTone (in unsigned long clientId); */
NS_IMETHODIMP nsTelephonyService::StopTone(uint32_t clientId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void answerCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::AnswerCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rejectCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::RejectCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hangUpCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::HangUpCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void holdCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::HoldCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::ResumeCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void conferenceCall (in unsigned long clientId, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::ConferenceCall(uint32_t clientId, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void separateCall (in unsigned long clientId, in unsigned long callIndex, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::SeparateCall(uint32_t clientId, uint32_t callIndex, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hangUpConference (in unsigned long clientId, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::HangUpConference(uint32_t clientId, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void holdConference (in unsigned long clientId, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::HoldConference(uint32_t clientId, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeConference (in unsigned long clientId, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::ResumeConference(uint32_t clientId, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendUSSD (in unsigned long clientId, in DOMString ussd, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::SendUSSD(uint32_t clientId, const nsAString & ussd, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelUSSD (in unsigned long cliendId, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyService::CancelUSSD(uint32_t cliendId, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute bool microphoneMuted; */
NS_IMETHODIMP nsTelephonyService::GetMicrophoneMuted(bool *aMicrophoneMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTelephonyService::SetMicrophoneMuted(bool aMicrophoneMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute bool speakerEnabled; */
NS_IMETHODIMP nsTelephonyService::GetSpeakerEnabled(bool *aSpeakerEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTelephonyService::SetSpeakerEnabled(bool aSpeakerEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

template<typename T> struct already_AddRefed;
already_AddRefed<nsITelephonyService>
NS_CreateTelephonyService();

#endif /* __gen_nsITelephonyService_h__ */
