/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITelephonyCallInfo.idl
 */

#ifndef __gen_nsITelephonyCallInfo_h__
#define __gen_nsITelephonyCallInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITelephonyCallInfo */
#define NS_ITELEPHONYCALLINFO_IID_STR "e5e1be26-a3d4-49b3-8d9f-c1df5192b364"

#define NS_ITELEPHONYCALLINFO_IID \
  {0xe5e1be26, 0xa3d4, 0x49b3, \
    { 0x8d, 0x9f, 0xc1, 0xdf, 0x51, 0x92, 0xb3, 0x64 }}

class NS_NO_VTABLE nsITelephonyCallInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEPHONYCALLINFO_IID)

  /* readonly attribute unsigned long clientId; */
  NS_IMETHOD GetClientId(uint32_t *aClientId) = 0;

  /* readonly attribute unsigned long callIndex; */
  NS_IMETHOD GetCallIndex(uint32_t *aCallIndex) = 0;

  /* readonly attribute unsigned short callState; */
  NS_IMETHOD GetCallState(uint16_t *aCallState) = 0;

  /* readonly attribute DOMString disconnectedReason; */
  NS_IMETHOD GetDisconnectedReason(nsAString & aDisconnectedReason) = 0;

  /* readonly attribute DOMString number; */
  NS_IMETHOD GetNumber(nsAString & aNumber) = 0;

  /* readonly attribute unsigned short numberPresentation; */
  NS_IMETHOD GetNumberPresentation(uint16_t *aNumberPresentation) = 0;

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute unsigned short namePresentation; */
  NS_IMETHOD GetNamePresentation(uint16_t *aNamePresentation) = 0;

  /* readonly attribute boolean isOutgoing; */
  NS_IMETHOD GetIsOutgoing(bool *aIsOutgoing) = 0;

  /* readonly attribute boolean isEmergency; */
  NS_IMETHOD GetIsEmergency(bool *aIsEmergency) = 0;

  /* readonly attribute boolean isConference; */
  NS_IMETHOD GetIsConference(bool *aIsConference) = 0;

  /* readonly attribute boolean isSwitchable; */
  NS_IMETHOD GetIsSwitchable(bool *aIsSwitchable) = 0;

  /* readonly attribute boolean isMergeable; */
  NS_IMETHOD GetIsMergeable(bool *aIsMergeable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelephonyCallInfo, NS_ITELEPHONYCALLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEPHONYCALLINFO \
  NS_IMETHOD GetClientId(uint32_t *aClientId) override; \
  NS_IMETHOD GetCallIndex(uint32_t *aCallIndex) override; \
  NS_IMETHOD GetCallState(uint16_t *aCallState) override; \
  NS_IMETHOD GetDisconnectedReason(nsAString & aDisconnectedReason) override; \
  NS_IMETHOD GetNumber(nsAString & aNumber) override; \
  NS_IMETHOD GetNumberPresentation(uint16_t *aNumberPresentation) override; \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD GetNamePresentation(uint16_t *aNamePresentation) override; \
  NS_IMETHOD GetIsOutgoing(bool *aIsOutgoing) override; \
  NS_IMETHOD GetIsEmergency(bool *aIsEmergency) override; \
  NS_IMETHOD GetIsConference(bool *aIsConference) override; \
  NS_IMETHOD GetIsSwitchable(bool *aIsSwitchable) override; \
  NS_IMETHOD GetIsMergeable(bool *aIsMergeable) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEPHONYCALLINFO(_to) \
  NS_IMETHOD GetClientId(uint32_t *aClientId) override { return _to GetClientId(aClientId); } \
  NS_IMETHOD GetCallIndex(uint32_t *aCallIndex) override { return _to GetCallIndex(aCallIndex); } \
  NS_IMETHOD GetCallState(uint16_t *aCallState) override { return _to GetCallState(aCallState); } \
  NS_IMETHOD GetDisconnectedReason(nsAString & aDisconnectedReason) override { return _to GetDisconnectedReason(aDisconnectedReason); } \
  NS_IMETHOD GetNumber(nsAString & aNumber) override { return _to GetNumber(aNumber); } \
  NS_IMETHOD GetNumberPresentation(uint16_t *aNumberPresentation) override { return _to GetNumberPresentation(aNumberPresentation); } \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetNamePresentation(uint16_t *aNamePresentation) override { return _to GetNamePresentation(aNamePresentation); } \
  NS_IMETHOD GetIsOutgoing(bool *aIsOutgoing) override { return _to GetIsOutgoing(aIsOutgoing); } \
  NS_IMETHOD GetIsEmergency(bool *aIsEmergency) override { return _to GetIsEmergency(aIsEmergency); } \
  NS_IMETHOD GetIsConference(bool *aIsConference) override { return _to GetIsConference(aIsConference); } \
  NS_IMETHOD GetIsSwitchable(bool *aIsSwitchable) override { return _to GetIsSwitchable(aIsSwitchable); } \
  NS_IMETHOD GetIsMergeable(bool *aIsMergeable) override { return _to GetIsMergeable(aIsMergeable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEPHONYCALLINFO(_to) \
  NS_IMETHOD GetClientId(uint32_t *aClientId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientId(aClientId); } \
  NS_IMETHOD GetCallIndex(uint32_t *aCallIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallIndex(aCallIndex); } \
  NS_IMETHOD GetCallState(uint16_t *aCallState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallState(aCallState); } \
  NS_IMETHOD GetDisconnectedReason(nsAString & aDisconnectedReason) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisconnectedReason(aDisconnectedReason); } \
  NS_IMETHOD GetNumber(nsAString & aNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumber(aNumber); } \
  NS_IMETHOD GetNumberPresentation(uint16_t *aNumberPresentation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberPresentation(aNumberPresentation); } \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetNamePresentation(uint16_t *aNamePresentation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamePresentation(aNamePresentation); } \
  NS_IMETHOD GetIsOutgoing(bool *aIsOutgoing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsOutgoing(aIsOutgoing); } \
  NS_IMETHOD GetIsEmergency(bool *aIsEmergency) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsEmergency(aIsEmergency); } \
  NS_IMETHOD GetIsConference(bool *aIsConference) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsConference(aIsConference); } \
  NS_IMETHOD GetIsSwitchable(bool *aIsSwitchable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSwitchable(aIsSwitchable); } \
  NS_IMETHOD GetIsMergeable(bool *aIsMergeable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsMergeable(aIsMergeable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelephonyCallInfo : public nsITelephonyCallInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEPHONYCALLINFO

  nsTelephonyCallInfo();

private:
  ~nsTelephonyCallInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTelephonyCallInfo, nsITelephonyCallInfo)

nsTelephonyCallInfo::nsTelephonyCallInfo()
{
  /* member initializers and constructor code */
}

nsTelephonyCallInfo::~nsTelephonyCallInfo()
{
  /* destructor code */
}

/* readonly attribute unsigned long clientId; */
NS_IMETHODIMP nsTelephonyCallInfo::GetClientId(uint32_t *aClientId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long callIndex; */
NS_IMETHODIMP nsTelephonyCallInfo::GetCallIndex(uint32_t *aCallIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short callState; */
NS_IMETHODIMP nsTelephonyCallInfo::GetCallState(uint16_t *aCallState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString disconnectedReason; */
NS_IMETHODIMP nsTelephonyCallInfo::GetDisconnectedReason(nsAString & aDisconnectedReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString number; */
NS_IMETHODIMP nsTelephonyCallInfo::GetNumber(nsAString & aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short numberPresentation; */
NS_IMETHODIMP nsTelephonyCallInfo::GetNumberPresentation(uint16_t *aNumberPresentation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsTelephonyCallInfo::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short namePresentation; */
NS_IMETHODIMP nsTelephonyCallInfo::GetNamePresentation(uint16_t *aNamePresentation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isOutgoing; */
NS_IMETHODIMP nsTelephonyCallInfo::GetIsOutgoing(bool *aIsOutgoing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isEmergency; */
NS_IMETHODIMP nsTelephonyCallInfo::GetIsEmergency(bool *aIsEmergency)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isConference; */
NS_IMETHODIMP nsTelephonyCallInfo::GetIsConference(bool *aIsConference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSwitchable; */
NS_IMETHODIMP nsTelephonyCallInfo::GetIsSwitchable(bool *aIsSwitchable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isMergeable; */
NS_IMETHODIMP nsTelephonyCallInfo::GetIsMergeable(bool *aIsMergeable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITelephonyCallInfo_h__ */
