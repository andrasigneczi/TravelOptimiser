/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMobileConnectionInfo.idl
 */

#ifndef __gen_nsIMobileConnectionInfo_h__
#define __gen_nsIMobileConnectionInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMobileCellInfo; /* forward declaration */

class nsIMobileNetworkInfo; /* forward declaration */


/* starting interface:    nsIMobileConnectionInfo */
#define NS_IMOBILECONNECTIONINFO_IID_STR "d5208e13-42dc-4dce-9427-2572fa252751"

#define NS_IMOBILECONNECTIONINFO_IID \
  {0xd5208e13, 0x42dc, 0x4dce, \
    { 0x94, 0x27, 0x25, 0x72, 0xfa, 0x25, 0x27, 0x51 }}

class NS_NO_VTABLE nsIMobileConnectionInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILECONNECTIONINFO_IID)

  /* readonly attribute DOMString state; */
  NS_IMETHOD GetState(nsAString & aState) = 0;

  /* readonly attribute bool connected; */
  NS_IMETHOD GetConnected(bool *aConnected) = 0;

  /* readonly attribute bool emergencyCallsOnly; */
  NS_IMETHOD GetEmergencyCallsOnly(bool *aEmergencyCallsOnly) = 0;

  /* readonly attribute bool roaming; */
  NS_IMETHOD GetRoaming(bool *aRoaming) = 0;

  /* readonly attribute nsIMobileNetworkInfo network; */
  NS_IMETHOD GetNetwork(nsIMobileNetworkInfo * *aNetwork) = 0;

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute jsval signalStrength; */
  NS_IMETHOD GetSignalStrength(JS::MutableHandleValue aSignalStrength) = 0;

  /* readonly attribute jsval relSignalStrength; */
  NS_IMETHOD GetRelSignalStrength(JS::MutableHandleValue aRelSignalStrength) = 0;

  /* readonly attribute nsIMobileCellInfo cell; */
  NS_IMETHOD GetCell(nsIMobileCellInfo * *aCell) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileConnectionInfo, NS_IMOBILECONNECTIONINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILECONNECTIONINFO \
  NS_IMETHOD GetState(nsAString & aState) override; \
  NS_IMETHOD GetConnected(bool *aConnected) override; \
  NS_IMETHOD GetEmergencyCallsOnly(bool *aEmergencyCallsOnly) override; \
  NS_IMETHOD GetRoaming(bool *aRoaming) override; \
  NS_IMETHOD GetNetwork(nsIMobileNetworkInfo * *aNetwork) override; \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD GetSignalStrength(JS::MutableHandleValue aSignalStrength) override; \
  NS_IMETHOD GetRelSignalStrength(JS::MutableHandleValue aRelSignalStrength) override; \
  NS_IMETHOD GetCell(nsIMobileCellInfo * *aCell) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILECONNECTIONINFO(_to) \
  NS_IMETHOD GetState(nsAString & aState) override { return _to GetState(aState); } \
  NS_IMETHOD GetConnected(bool *aConnected) override { return _to GetConnected(aConnected); } \
  NS_IMETHOD GetEmergencyCallsOnly(bool *aEmergencyCallsOnly) override { return _to GetEmergencyCallsOnly(aEmergencyCallsOnly); } \
  NS_IMETHOD GetRoaming(bool *aRoaming) override { return _to GetRoaming(aRoaming); } \
  NS_IMETHOD GetNetwork(nsIMobileNetworkInfo * *aNetwork) override { return _to GetNetwork(aNetwork); } \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetSignalStrength(JS::MutableHandleValue aSignalStrength) override { return _to GetSignalStrength(aSignalStrength); } \
  NS_IMETHOD GetRelSignalStrength(JS::MutableHandleValue aRelSignalStrength) override { return _to GetRelSignalStrength(aRelSignalStrength); } \
  NS_IMETHOD GetCell(nsIMobileCellInfo * *aCell) override { return _to GetCell(aCell); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILECONNECTIONINFO(_to) \
  NS_IMETHOD GetState(nsAString & aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD GetConnected(bool *aConnected) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnected(aConnected); } \
  NS_IMETHOD GetEmergencyCallsOnly(bool *aEmergencyCallsOnly) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmergencyCallsOnly(aEmergencyCallsOnly); } \
  NS_IMETHOD GetRoaming(bool *aRoaming) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoaming(aRoaming); } \
  NS_IMETHOD GetNetwork(nsIMobileNetworkInfo * *aNetwork) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetwork(aNetwork); } \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetSignalStrength(JS::MutableHandleValue aSignalStrength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSignalStrength(aSignalStrength); } \
  NS_IMETHOD GetRelSignalStrength(JS::MutableHandleValue aRelSignalStrength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelSignalStrength(aRelSignalStrength); } \
  NS_IMETHOD GetCell(nsIMobileCellInfo * *aCell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCell(aCell); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileConnectionInfo : public nsIMobileConnectionInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILECONNECTIONINFO

  nsMobileConnectionInfo();

private:
  ~nsMobileConnectionInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileConnectionInfo, nsIMobileConnectionInfo)

nsMobileConnectionInfo::nsMobileConnectionInfo()
{
  /* member initializers and constructor code */
}

nsMobileConnectionInfo::~nsMobileConnectionInfo()
{
  /* destructor code */
}

/* readonly attribute DOMString state; */
NS_IMETHODIMP nsMobileConnectionInfo::GetState(nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool connected; */
NS_IMETHODIMP nsMobileConnectionInfo::GetConnected(bool *aConnected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool emergencyCallsOnly; */
NS_IMETHODIMP nsMobileConnectionInfo::GetEmergencyCallsOnly(bool *aEmergencyCallsOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool roaming; */
NS_IMETHODIMP nsMobileConnectionInfo::GetRoaming(bool *aRoaming)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMobileNetworkInfo network; */
NS_IMETHODIMP nsMobileConnectionInfo::GetNetwork(nsIMobileNetworkInfo * *aNetwork)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsMobileConnectionInfo::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval signalStrength; */
NS_IMETHODIMP nsMobileConnectionInfo::GetSignalStrength(JS::MutableHandleValue aSignalStrength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval relSignalStrength; */
NS_IMETHODIMP nsMobileConnectionInfo::GetRelSignalStrength(JS::MutableHandleValue aRelSignalStrength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMobileCellInfo cell; */
NS_IMETHODIMP nsMobileConnectionInfo::GetCell(nsIMobileCellInfo * *aCell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileConnectionInfo_h__ */
