/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICellInfo.idl
 */

#ifndef __gen_nsICellInfo_h__
#define __gen_nsICellInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICellInfo; /* forward declaration */


/* starting interface:    nsICellInfoListCallback */
#define NS_ICELLINFOLISTCALLBACK_IID_STR "d8fae631-7ade-4024-b288-7efe75e6b091"

#define NS_ICELLINFOLISTCALLBACK_IID \
  {0xd8fae631, 0x7ade, 0x4024, \
    { 0xb2, 0x88, 0x7e, 0xfe, 0x75, 0xe6, 0xb0, 0x91 }}

class NS_NO_VTABLE nsICellInfoListCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICELLINFOLISTCALLBACK_IID)

  /* void notifyGetCellInfoList (in uint32_t count, [array, size_is (count)] in nsICellInfo result); */
  NS_IMETHOD NotifyGetCellInfoList(uint32_t count, nsICellInfo **result) = 0;

  /* void notifyGetCellInfoListFailed (in DOMString error); */
  NS_IMETHOD NotifyGetCellInfoListFailed(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICellInfoListCallback, NS_ICELLINFOLISTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICELLINFOLISTCALLBACK \
  NS_IMETHOD NotifyGetCellInfoList(uint32_t count, nsICellInfo **result) override; \
  NS_IMETHOD NotifyGetCellInfoListFailed(const nsAString & error) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICELLINFOLISTCALLBACK(_to) \
  NS_IMETHOD NotifyGetCellInfoList(uint32_t count, nsICellInfo **result) override { return _to NotifyGetCellInfoList(count, result); } \
  NS_IMETHOD NotifyGetCellInfoListFailed(const nsAString & error) override { return _to NotifyGetCellInfoListFailed(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICELLINFOLISTCALLBACK(_to) \
  NS_IMETHOD NotifyGetCellInfoList(uint32_t count, nsICellInfo **result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetCellInfoList(count, result); } \
  NS_IMETHOD NotifyGetCellInfoListFailed(const nsAString & error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetCellInfoListFailed(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCellInfoListCallback : public nsICellInfoListCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICELLINFOLISTCALLBACK

  nsCellInfoListCallback();

private:
  ~nsCellInfoListCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCellInfoListCallback, nsICellInfoListCallback)

nsCellInfoListCallback::nsCellInfoListCallback()
{
  /* member initializers and constructor code */
}

nsCellInfoListCallback::~nsCellInfoListCallback()
{
  /* destructor code */
}

/* void notifyGetCellInfoList (in uint32_t count, [array, size_is (count)] in nsICellInfo result); */
NS_IMETHODIMP nsCellInfoListCallback::NotifyGetCellInfoList(uint32_t count, nsICellInfo **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetCellInfoListFailed (in DOMString error); */
NS_IMETHODIMP nsCellInfoListCallback::NotifyGetCellInfoListFailed(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICellInfo */
#define NS_ICELLINFO_IID_STR "a9a34341-5a33-4e0a-98e1-13e7ea4228be"

#define NS_ICELLINFO_IID \
  {0xa9a34341, 0x5a33, 0x4e0a, \
    { 0x98, 0xe1, 0x13, 0xe7, 0xea, 0x42, 0x28, 0xbe }}

class NS_NO_VTABLE nsICellInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICELLINFO_IID)

  enum {
    CELL_INFO_TYPE_GSM = 1,
    CELL_INFO_TYPE_CDMA = 2,
    CELL_INFO_TYPE_LTE = 3,
    CELL_INFO_TYPE_WCDMA = 4,
    TIMESTAMP_TYPE_UNKNOWN = 0,
    TIMESTAMP_TYPE_ANTENNA = 1,
    TIMESTAMP_TYPE_MODEM = 2,
    TIMESTAMP_TYPE_OEM_RIL = 3,
    TIMESTAMP_TYPE_JAVA_RIL = 4,
    UNKNOWN_VALUE = 2147483647
  };

  /* readonly attribute long type; */
  NS_IMETHOD GetType(int32_t *aType) = 0;

  /* readonly attribute boolean registered; */
  NS_IMETHOD GetRegistered(bool *aRegistered) = 0;

  /* readonly attribute long timestampType; */
  NS_IMETHOD GetTimestampType(int32_t *aTimestampType) = 0;

  /* readonly attribute long long timestamp; */
  NS_IMETHOD GetTimestamp(int64_t *aTimestamp) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICellInfo, NS_ICELLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICELLINFO \
  NS_IMETHOD GetType(int32_t *aType) override; \
  NS_IMETHOD GetRegistered(bool *aRegistered) override; \
  NS_IMETHOD GetTimestampType(int32_t *aTimestampType) override; \
  NS_IMETHOD GetTimestamp(int64_t *aTimestamp) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICELLINFO(_to) \
  NS_IMETHOD GetType(int32_t *aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetRegistered(bool *aRegistered) override { return _to GetRegistered(aRegistered); } \
  NS_IMETHOD GetTimestampType(int32_t *aTimestampType) override { return _to GetTimestampType(aTimestampType); } \
  NS_IMETHOD GetTimestamp(int64_t *aTimestamp) override { return _to GetTimestamp(aTimestamp); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICELLINFO(_to) \
  NS_IMETHOD GetType(int32_t *aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetRegistered(bool *aRegistered) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRegistered(aRegistered); } \
  NS_IMETHOD GetTimestampType(int32_t *aTimestampType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimestampType(aTimestampType); } \
  NS_IMETHOD GetTimestamp(int64_t *aTimestamp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimestamp(aTimestamp); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCellInfo : public nsICellInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICELLINFO

  nsCellInfo();

private:
  ~nsCellInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCellInfo, nsICellInfo)

nsCellInfo::nsCellInfo()
{
  /* member initializers and constructor code */
}

nsCellInfo::~nsCellInfo()
{
  /* destructor code */
}

/* readonly attribute long type; */
NS_IMETHODIMP nsCellInfo::GetType(int32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean registered; */
NS_IMETHODIMP nsCellInfo::GetRegistered(bool *aRegistered)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long timestampType; */
NS_IMETHODIMP nsCellInfo::GetTimestampType(int32_t *aTimestampType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long timestamp; */
NS_IMETHODIMP nsCellInfo::GetTimestamp(int64_t *aTimestamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGsmCellInfo */
#define NS_IGSMCELLINFO_IID_STR "cc476ded-350f-4c25-9a57-6a876e32f092"

#define NS_IGSMCELLINFO_IID \
  {0xcc476ded, 0x350f, 0x4c25, \
    { 0x9a, 0x57, 0x6a, 0x87, 0x6e, 0x32, 0xf0, 0x92 }}

class NS_NO_VTABLE nsIGsmCellInfo : public nsICellInfo {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGSMCELLINFO_IID)

  /* readonly attribute long mcc; */
  NS_IMETHOD GetMcc(int32_t *aMcc) = 0;

  /* readonly attribute long mnc; */
  NS_IMETHOD GetMnc(int32_t *aMnc) = 0;

  /* readonly attribute long lac; */
  NS_IMETHOD GetLac(int32_t *aLac) = 0;

  /* readonly attribute long cid; */
  NS_IMETHOD GetCid(int32_t *aCid) = 0;

  /* readonly attribute long signalStrength; */
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) = 0;

  /* readonly attribute long bitErrorRate; */
  NS_IMETHOD GetBitErrorRate(int32_t *aBitErrorRate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGsmCellInfo, NS_IGSMCELLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGSMCELLINFO \
  NS_IMETHOD GetMcc(int32_t *aMcc) override; \
  NS_IMETHOD GetMnc(int32_t *aMnc) override; \
  NS_IMETHOD GetLac(int32_t *aLac) override; \
  NS_IMETHOD GetCid(int32_t *aCid) override; \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override; \
  NS_IMETHOD GetBitErrorRate(int32_t *aBitErrorRate) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGSMCELLINFO(_to) \
  NS_IMETHOD GetMcc(int32_t *aMcc) override { return _to GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(int32_t *aMnc) override { return _to GetMnc(aMnc); } \
  NS_IMETHOD GetLac(int32_t *aLac) override { return _to GetLac(aLac); } \
  NS_IMETHOD GetCid(int32_t *aCid) override { return _to GetCid(aCid); } \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override { return _to GetSignalStrength(aSignalStrength); } \
  NS_IMETHOD GetBitErrorRate(int32_t *aBitErrorRate) override { return _to GetBitErrorRate(aBitErrorRate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGSMCELLINFO(_to) \
  NS_IMETHOD GetMcc(int32_t *aMcc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(int32_t *aMnc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMnc(aMnc); } \
  NS_IMETHOD GetLac(int32_t *aLac) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLac(aLac); } \
  NS_IMETHOD GetCid(int32_t *aCid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCid(aCid); } \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSignalStrength(aSignalStrength); } \
  NS_IMETHOD GetBitErrorRate(int32_t *aBitErrorRate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBitErrorRate(aBitErrorRate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGsmCellInfo : public nsIGsmCellInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGSMCELLINFO

  nsGsmCellInfo();

private:
  ~nsGsmCellInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsGsmCellInfo, nsIGsmCellInfo)

nsGsmCellInfo::nsGsmCellInfo()
{
  /* member initializers and constructor code */
}

nsGsmCellInfo::~nsGsmCellInfo()
{
  /* destructor code */
}

/* readonly attribute long mcc; */
NS_IMETHODIMP nsGsmCellInfo::GetMcc(int32_t *aMcc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long mnc; */
NS_IMETHODIMP nsGsmCellInfo::GetMnc(int32_t *aMnc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long lac; */
NS_IMETHODIMP nsGsmCellInfo::GetLac(int32_t *aLac)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cid; */
NS_IMETHODIMP nsGsmCellInfo::GetCid(int32_t *aCid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long signalStrength; */
NS_IMETHODIMP nsGsmCellInfo::GetSignalStrength(int32_t *aSignalStrength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long bitErrorRate; */
NS_IMETHODIMP nsGsmCellInfo::GetBitErrorRate(int32_t *aBitErrorRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWcdmaCellInfo */
#define NS_IWCDMACELLINFO_IID_STR "aa52647b-38dd-487c-be36-b46ed2e99554"

#define NS_IWCDMACELLINFO_IID \
  {0xaa52647b, 0x38dd, 0x487c, \
    { 0xbe, 0x36, 0xb4, 0x6e, 0xd2, 0xe9, 0x95, 0x54 }}

class NS_NO_VTABLE nsIWcdmaCellInfo : public nsICellInfo {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWCDMACELLINFO_IID)

  /* readonly attribute long mcc; */
  NS_IMETHOD GetMcc(int32_t *aMcc) = 0;

  /* readonly attribute long mnc; */
  NS_IMETHOD GetMnc(int32_t *aMnc) = 0;

  /* readonly attribute long lac; */
  NS_IMETHOD GetLac(int32_t *aLac) = 0;

  /* readonly attribute long cid; */
  NS_IMETHOD GetCid(int32_t *aCid) = 0;

  /* readonly attribute long psc; */
  NS_IMETHOD GetPsc(int32_t *aPsc) = 0;

  /* readonly attribute long signalStrength; */
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) = 0;

  /* readonly attribute long bitErrorRate; */
  NS_IMETHOD GetBitErrorRate(int32_t *aBitErrorRate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWcdmaCellInfo, NS_IWCDMACELLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWCDMACELLINFO \
  NS_IMETHOD GetMcc(int32_t *aMcc) override; \
  NS_IMETHOD GetMnc(int32_t *aMnc) override; \
  NS_IMETHOD GetLac(int32_t *aLac) override; \
  NS_IMETHOD GetCid(int32_t *aCid) override; \
  NS_IMETHOD GetPsc(int32_t *aPsc) override; \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override; \
  NS_IMETHOD GetBitErrorRate(int32_t *aBitErrorRate) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWCDMACELLINFO(_to) \
  NS_IMETHOD GetMcc(int32_t *aMcc) override { return _to GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(int32_t *aMnc) override { return _to GetMnc(aMnc); } \
  NS_IMETHOD GetLac(int32_t *aLac) override { return _to GetLac(aLac); } \
  NS_IMETHOD GetCid(int32_t *aCid) override { return _to GetCid(aCid); } \
  NS_IMETHOD GetPsc(int32_t *aPsc) override { return _to GetPsc(aPsc); } \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override { return _to GetSignalStrength(aSignalStrength); } \
  NS_IMETHOD GetBitErrorRate(int32_t *aBitErrorRate) override { return _to GetBitErrorRate(aBitErrorRate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWCDMACELLINFO(_to) \
  NS_IMETHOD GetMcc(int32_t *aMcc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(int32_t *aMnc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMnc(aMnc); } \
  NS_IMETHOD GetLac(int32_t *aLac) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLac(aLac); } \
  NS_IMETHOD GetCid(int32_t *aCid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCid(aCid); } \
  NS_IMETHOD GetPsc(int32_t *aPsc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPsc(aPsc); } \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSignalStrength(aSignalStrength); } \
  NS_IMETHOD GetBitErrorRate(int32_t *aBitErrorRate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBitErrorRate(aBitErrorRate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWcdmaCellInfo : public nsIWcdmaCellInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWCDMACELLINFO

  nsWcdmaCellInfo();

private:
  ~nsWcdmaCellInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsWcdmaCellInfo, nsIWcdmaCellInfo)

nsWcdmaCellInfo::nsWcdmaCellInfo()
{
  /* member initializers and constructor code */
}

nsWcdmaCellInfo::~nsWcdmaCellInfo()
{
  /* destructor code */
}

/* readonly attribute long mcc; */
NS_IMETHODIMP nsWcdmaCellInfo::GetMcc(int32_t *aMcc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long mnc; */
NS_IMETHODIMP nsWcdmaCellInfo::GetMnc(int32_t *aMnc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long lac; */
NS_IMETHODIMP nsWcdmaCellInfo::GetLac(int32_t *aLac)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cid; */
NS_IMETHODIMP nsWcdmaCellInfo::GetCid(int32_t *aCid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long psc; */
NS_IMETHODIMP nsWcdmaCellInfo::GetPsc(int32_t *aPsc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long signalStrength; */
NS_IMETHODIMP nsWcdmaCellInfo::GetSignalStrength(int32_t *aSignalStrength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long bitErrorRate; */
NS_IMETHODIMP nsWcdmaCellInfo::GetBitErrorRate(int32_t *aBitErrorRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICdmaCellInfo */
#define NS_ICDMACELLINFO_IID_STR "60a38ca7-ca62-4384-aa07-eac7d4893786"

#define NS_ICDMACELLINFO_IID \
  {0x60a38ca7, 0xca62, 0x4384, \
    { 0xaa, 0x07, 0xea, 0xc7, 0xd4, 0x89, 0x37, 0x86 }}

class NS_NO_VTABLE nsICdmaCellInfo : public nsICellInfo {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICDMACELLINFO_IID)

  /* readonly attribute long networkId; */
  NS_IMETHOD GetNetworkId(int32_t *aNetworkId) = 0;

  /* readonly attribute long systemId; */
  NS_IMETHOD GetSystemId(int32_t *aSystemId) = 0;

  /* readonly attribute long baseStationId; */
  NS_IMETHOD GetBaseStationId(int32_t *aBaseStationId) = 0;

  /* readonly attribute long longitude; */
  NS_IMETHOD GetLongitude(int32_t *aLongitude) = 0;

  /* readonly attribute long latitude; */
  NS_IMETHOD GetLatitude(int32_t *aLatitude) = 0;

  /* readonly attribute long cdmaDbm; */
  NS_IMETHOD GetCdmaDbm(int32_t *aCdmaDbm) = 0;

  /* readonly attribute long cdmaEcio; */
  NS_IMETHOD GetCdmaEcio(int32_t *aCdmaEcio) = 0;

  /* readonly attribute long evdoDbm; */
  NS_IMETHOD GetEvdoDbm(int32_t *aEvdoDbm) = 0;

  /* readonly attribute long evdoEcio; */
  NS_IMETHOD GetEvdoEcio(int32_t *aEvdoEcio) = 0;

  /* readonly attribute long evdoSnr; */
  NS_IMETHOD GetEvdoSnr(int32_t *aEvdoSnr) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICdmaCellInfo, NS_ICDMACELLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICDMACELLINFO \
  NS_IMETHOD GetNetworkId(int32_t *aNetworkId) override; \
  NS_IMETHOD GetSystemId(int32_t *aSystemId) override; \
  NS_IMETHOD GetBaseStationId(int32_t *aBaseStationId) override; \
  NS_IMETHOD GetLongitude(int32_t *aLongitude) override; \
  NS_IMETHOD GetLatitude(int32_t *aLatitude) override; \
  NS_IMETHOD GetCdmaDbm(int32_t *aCdmaDbm) override; \
  NS_IMETHOD GetCdmaEcio(int32_t *aCdmaEcio) override; \
  NS_IMETHOD GetEvdoDbm(int32_t *aEvdoDbm) override; \
  NS_IMETHOD GetEvdoEcio(int32_t *aEvdoEcio) override; \
  NS_IMETHOD GetEvdoSnr(int32_t *aEvdoSnr) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICDMACELLINFO(_to) \
  NS_IMETHOD GetNetworkId(int32_t *aNetworkId) override { return _to GetNetworkId(aNetworkId); } \
  NS_IMETHOD GetSystemId(int32_t *aSystemId) override { return _to GetSystemId(aSystemId); } \
  NS_IMETHOD GetBaseStationId(int32_t *aBaseStationId) override { return _to GetBaseStationId(aBaseStationId); } \
  NS_IMETHOD GetLongitude(int32_t *aLongitude) override { return _to GetLongitude(aLongitude); } \
  NS_IMETHOD GetLatitude(int32_t *aLatitude) override { return _to GetLatitude(aLatitude); } \
  NS_IMETHOD GetCdmaDbm(int32_t *aCdmaDbm) override { return _to GetCdmaDbm(aCdmaDbm); } \
  NS_IMETHOD GetCdmaEcio(int32_t *aCdmaEcio) override { return _to GetCdmaEcio(aCdmaEcio); } \
  NS_IMETHOD GetEvdoDbm(int32_t *aEvdoDbm) override { return _to GetEvdoDbm(aEvdoDbm); } \
  NS_IMETHOD GetEvdoEcio(int32_t *aEvdoEcio) override { return _to GetEvdoEcio(aEvdoEcio); } \
  NS_IMETHOD GetEvdoSnr(int32_t *aEvdoSnr) override { return _to GetEvdoSnr(aEvdoSnr); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICDMACELLINFO(_to) \
  NS_IMETHOD GetNetworkId(int32_t *aNetworkId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetworkId(aNetworkId); } \
  NS_IMETHOD GetSystemId(int32_t *aSystemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemId(aSystemId); } \
  NS_IMETHOD GetBaseStationId(int32_t *aBaseStationId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseStationId(aBaseStationId); } \
  NS_IMETHOD GetLongitude(int32_t *aLongitude) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLongitude(aLongitude); } \
  NS_IMETHOD GetLatitude(int32_t *aLatitude) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLatitude(aLatitude); } \
  NS_IMETHOD GetCdmaDbm(int32_t *aCdmaDbm) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCdmaDbm(aCdmaDbm); } \
  NS_IMETHOD GetCdmaEcio(int32_t *aCdmaEcio) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCdmaEcio(aCdmaEcio); } \
  NS_IMETHOD GetEvdoDbm(int32_t *aEvdoDbm) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvdoDbm(aEvdoDbm); } \
  NS_IMETHOD GetEvdoEcio(int32_t *aEvdoEcio) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvdoEcio(aEvdoEcio); } \
  NS_IMETHOD GetEvdoSnr(int32_t *aEvdoSnr) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvdoSnr(aEvdoSnr); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCdmaCellInfo : public nsICdmaCellInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICDMACELLINFO

  nsCdmaCellInfo();

private:
  ~nsCdmaCellInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCdmaCellInfo, nsICdmaCellInfo)

nsCdmaCellInfo::nsCdmaCellInfo()
{
  /* member initializers and constructor code */
}

nsCdmaCellInfo::~nsCdmaCellInfo()
{
  /* destructor code */
}

/* readonly attribute long networkId; */
NS_IMETHODIMP nsCdmaCellInfo::GetNetworkId(int32_t *aNetworkId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long systemId; */
NS_IMETHODIMP nsCdmaCellInfo::GetSystemId(int32_t *aSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long baseStationId; */
NS_IMETHODIMP nsCdmaCellInfo::GetBaseStationId(int32_t *aBaseStationId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long longitude; */
NS_IMETHODIMP nsCdmaCellInfo::GetLongitude(int32_t *aLongitude)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long latitude; */
NS_IMETHODIMP nsCdmaCellInfo::GetLatitude(int32_t *aLatitude)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cdmaDbm; */
NS_IMETHODIMP nsCdmaCellInfo::GetCdmaDbm(int32_t *aCdmaDbm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cdmaEcio; */
NS_IMETHODIMP nsCdmaCellInfo::GetCdmaEcio(int32_t *aCdmaEcio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long evdoDbm; */
NS_IMETHODIMP nsCdmaCellInfo::GetEvdoDbm(int32_t *aEvdoDbm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long evdoEcio; */
NS_IMETHODIMP nsCdmaCellInfo::GetEvdoEcio(int32_t *aEvdoEcio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long evdoSnr; */
NS_IMETHODIMP nsCdmaCellInfo::GetEvdoSnr(int32_t *aEvdoSnr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsILteCellInfo */
#define NS_ILTECELLINFO_IID_STR "e7b3e826-bb85-49b2-a2f1-70af46c47733"

#define NS_ILTECELLINFO_IID \
  {0xe7b3e826, 0xbb85, 0x49b2, \
    { 0xa2, 0xf1, 0x70, 0xaf, 0x46, 0xc4, 0x77, 0x33 }}

class NS_NO_VTABLE nsILteCellInfo : public nsICellInfo {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILTECELLINFO_IID)

  /* readonly attribute long mcc; */
  NS_IMETHOD GetMcc(int32_t *aMcc) = 0;

  /* readonly attribute long mnc; */
  NS_IMETHOD GetMnc(int32_t *aMnc) = 0;

  /* readonly attribute long cid; */
  NS_IMETHOD GetCid(int32_t *aCid) = 0;

  /* readonly attribute long pcid; */
  NS_IMETHOD GetPcid(int32_t *aPcid) = 0;

  /* readonly attribute long tac; */
  NS_IMETHOD GetTac(int32_t *aTac) = 0;

  /* readonly attribute long signalStrength; */
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) = 0;

  /* readonly attribute long rsrp; */
  NS_IMETHOD GetRsrp(int32_t *aRsrp) = 0;

  /* readonly attribute long rsrq; */
  NS_IMETHOD GetRsrq(int32_t *aRsrq) = 0;

  /* readonly attribute long rssnr; */
  NS_IMETHOD GetRssnr(int32_t *aRssnr) = 0;

  /* readonly attribute long cqi; */
  NS_IMETHOD GetCqi(int32_t *aCqi) = 0;

  /* readonly attribute long timingAdvance; */
  NS_IMETHOD GetTimingAdvance(int32_t *aTimingAdvance) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILteCellInfo, NS_ILTECELLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILTECELLINFO \
  NS_IMETHOD GetMcc(int32_t *aMcc) override; \
  NS_IMETHOD GetMnc(int32_t *aMnc) override; \
  NS_IMETHOD GetCid(int32_t *aCid) override; \
  NS_IMETHOD GetPcid(int32_t *aPcid) override; \
  NS_IMETHOD GetTac(int32_t *aTac) override; \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override; \
  NS_IMETHOD GetRsrp(int32_t *aRsrp) override; \
  NS_IMETHOD GetRsrq(int32_t *aRsrq) override; \
  NS_IMETHOD GetRssnr(int32_t *aRssnr) override; \
  NS_IMETHOD GetCqi(int32_t *aCqi) override; \
  NS_IMETHOD GetTimingAdvance(int32_t *aTimingAdvance) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILTECELLINFO(_to) \
  NS_IMETHOD GetMcc(int32_t *aMcc) override { return _to GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(int32_t *aMnc) override { return _to GetMnc(aMnc); } \
  NS_IMETHOD GetCid(int32_t *aCid) override { return _to GetCid(aCid); } \
  NS_IMETHOD GetPcid(int32_t *aPcid) override { return _to GetPcid(aPcid); } \
  NS_IMETHOD GetTac(int32_t *aTac) override { return _to GetTac(aTac); } \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override { return _to GetSignalStrength(aSignalStrength); } \
  NS_IMETHOD GetRsrp(int32_t *aRsrp) override { return _to GetRsrp(aRsrp); } \
  NS_IMETHOD GetRsrq(int32_t *aRsrq) override { return _to GetRsrq(aRsrq); } \
  NS_IMETHOD GetRssnr(int32_t *aRssnr) override { return _to GetRssnr(aRssnr); } \
  NS_IMETHOD GetCqi(int32_t *aCqi) override { return _to GetCqi(aCqi); } \
  NS_IMETHOD GetTimingAdvance(int32_t *aTimingAdvance) override { return _to GetTimingAdvance(aTimingAdvance); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILTECELLINFO(_to) \
  NS_IMETHOD GetMcc(int32_t *aMcc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(int32_t *aMnc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMnc(aMnc); } \
  NS_IMETHOD GetCid(int32_t *aCid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCid(aCid); } \
  NS_IMETHOD GetPcid(int32_t *aPcid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPcid(aPcid); } \
  NS_IMETHOD GetTac(int32_t *aTac) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTac(aTac); } \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSignalStrength(aSignalStrength); } \
  NS_IMETHOD GetRsrp(int32_t *aRsrp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRsrp(aRsrp); } \
  NS_IMETHOD GetRsrq(int32_t *aRsrq) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRsrq(aRsrq); } \
  NS_IMETHOD GetRssnr(int32_t *aRssnr) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRssnr(aRssnr); } \
  NS_IMETHOD GetCqi(int32_t *aCqi) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCqi(aCqi); } \
  NS_IMETHOD GetTimingAdvance(int32_t *aTimingAdvance) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimingAdvance(aTimingAdvance); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLteCellInfo : public nsILteCellInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILTECELLINFO

  nsLteCellInfo();

private:
  ~nsLteCellInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLteCellInfo, nsILteCellInfo)

nsLteCellInfo::nsLteCellInfo()
{
  /* member initializers and constructor code */
}

nsLteCellInfo::~nsLteCellInfo()
{
  /* destructor code */
}

/* readonly attribute long mcc; */
NS_IMETHODIMP nsLteCellInfo::GetMcc(int32_t *aMcc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long mnc; */
NS_IMETHODIMP nsLteCellInfo::GetMnc(int32_t *aMnc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cid; */
NS_IMETHODIMP nsLteCellInfo::GetCid(int32_t *aCid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pcid; */
NS_IMETHODIMP nsLteCellInfo::GetPcid(int32_t *aPcid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long tac; */
NS_IMETHODIMP nsLteCellInfo::GetTac(int32_t *aTac)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long signalStrength; */
NS_IMETHODIMP nsLteCellInfo::GetSignalStrength(int32_t *aSignalStrength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rsrp; */
NS_IMETHODIMP nsLteCellInfo::GetRsrp(int32_t *aRsrp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rsrq; */
NS_IMETHODIMP nsLteCellInfo::GetRsrq(int32_t *aRsrq)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long rssnr; */
NS_IMETHODIMP nsLteCellInfo::GetRssnr(int32_t *aRssnr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cqi; */
NS_IMETHODIMP nsLteCellInfo::GetCqi(int32_t *aCqi)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long timingAdvance; */
NS_IMETHODIMP nsLteCellInfo::GetTimingAdvance(int32_t *aTimingAdvance)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICellInfo_h__ */
