/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMobileCellInfo.idl
 */

#ifndef __gen_nsIMobileCellInfo_h__
#define __gen_nsIMobileCellInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMobileCellInfo */
#define NS_IMOBILECELLINFO_IID_STR "286a96fe-5519-459b-9ef8-2e34b9c1f9f2"

#define NS_IMOBILECELLINFO_IID \
  {0x286a96fe, 0x5519, 0x459b, \
    { 0x9e, 0xf8, 0x2e, 0x34, 0xb9, 0xc1, 0xf9, 0xf2 }}

class NS_NO_VTABLE nsIMobileCellInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILECELLINFO_IID)

  /* readonly attribute long gsmLocationAreaCode; */
  NS_IMETHOD GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode) = 0;

  /* readonly attribute long long gsmCellId; */
  NS_IMETHOD GetGsmCellId(int64_t *aGsmCellId) = 0;

  /* readonly attribute long cdmaBaseStationId; */
  NS_IMETHOD GetCdmaBaseStationId(int32_t *aCdmaBaseStationId) = 0;

  /* readonly attribute long cdmaBaseStationLatitude; */
  NS_IMETHOD GetCdmaBaseStationLatitude(int32_t *aCdmaBaseStationLatitude) = 0;

  /* readonly attribute long cdmaBaseStationLongitude; */
  NS_IMETHOD GetCdmaBaseStationLongitude(int32_t *aCdmaBaseStationLongitude) = 0;

  /* readonly attribute long cdmaSystemId; */
  NS_IMETHOD GetCdmaSystemId(int32_t *aCdmaSystemId) = 0;

  /* readonly attribute long cdmaNetworkId; */
  NS_IMETHOD GetCdmaNetworkId(int32_t *aCdmaNetworkId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileCellInfo, NS_IMOBILECELLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILECELLINFO \
  NS_IMETHOD GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode) override; \
  NS_IMETHOD GetGsmCellId(int64_t *aGsmCellId) override; \
  NS_IMETHOD GetCdmaBaseStationId(int32_t *aCdmaBaseStationId) override; \
  NS_IMETHOD GetCdmaBaseStationLatitude(int32_t *aCdmaBaseStationLatitude) override; \
  NS_IMETHOD GetCdmaBaseStationLongitude(int32_t *aCdmaBaseStationLongitude) override; \
  NS_IMETHOD GetCdmaSystemId(int32_t *aCdmaSystemId) override; \
  NS_IMETHOD GetCdmaNetworkId(int32_t *aCdmaNetworkId) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILECELLINFO(_to) \
  NS_IMETHOD GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode) override { return _to GetGsmLocationAreaCode(aGsmLocationAreaCode); } \
  NS_IMETHOD GetGsmCellId(int64_t *aGsmCellId) override { return _to GetGsmCellId(aGsmCellId); } \
  NS_IMETHOD GetCdmaBaseStationId(int32_t *aCdmaBaseStationId) override { return _to GetCdmaBaseStationId(aCdmaBaseStationId); } \
  NS_IMETHOD GetCdmaBaseStationLatitude(int32_t *aCdmaBaseStationLatitude) override { return _to GetCdmaBaseStationLatitude(aCdmaBaseStationLatitude); } \
  NS_IMETHOD GetCdmaBaseStationLongitude(int32_t *aCdmaBaseStationLongitude) override { return _to GetCdmaBaseStationLongitude(aCdmaBaseStationLongitude); } \
  NS_IMETHOD GetCdmaSystemId(int32_t *aCdmaSystemId) override { return _to GetCdmaSystemId(aCdmaSystemId); } \
  NS_IMETHOD GetCdmaNetworkId(int32_t *aCdmaNetworkId) override { return _to GetCdmaNetworkId(aCdmaNetworkId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILECELLINFO(_to) \
  NS_IMETHOD GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGsmLocationAreaCode(aGsmLocationAreaCode); } \
  NS_IMETHOD GetGsmCellId(int64_t *aGsmCellId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGsmCellId(aGsmCellId); } \
  NS_IMETHOD GetCdmaBaseStationId(int32_t *aCdmaBaseStationId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCdmaBaseStationId(aCdmaBaseStationId); } \
  NS_IMETHOD GetCdmaBaseStationLatitude(int32_t *aCdmaBaseStationLatitude) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCdmaBaseStationLatitude(aCdmaBaseStationLatitude); } \
  NS_IMETHOD GetCdmaBaseStationLongitude(int32_t *aCdmaBaseStationLongitude) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCdmaBaseStationLongitude(aCdmaBaseStationLongitude); } \
  NS_IMETHOD GetCdmaSystemId(int32_t *aCdmaSystemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCdmaSystemId(aCdmaSystemId); } \
  NS_IMETHOD GetCdmaNetworkId(int32_t *aCdmaNetworkId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCdmaNetworkId(aCdmaNetworkId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileCellInfo : public nsIMobileCellInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILECELLINFO

  nsMobileCellInfo();

private:
  ~nsMobileCellInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileCellInfo, nsIMobileCellInfo)

nsMobileCellInfo::nsMobileCellInfo()
{
  /* member initializers and constructor code */
}

nsMobileCellInfo::~nsMobileCellInfo()
{
  /* destructor code */
}

/* readonly attribute long gsmLocationAreaCode; */
NS_IMETHODIMP nsMobileCellInfo::GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long gsmCellId; */
NS_IMETHODIMP nsMobileCellInfo::GetGsmCellId(int64_t *aGsmCellId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cdmaBaseStationId; */
NS_IMETHODIMP nsMobileCellInfo::GetCdmaBaseStationId(int32_t *aCdmaBaseStationId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cdmaBaseStationLatitude; */
NS_IMETHODIMP nsMobileCellInfo::GetCdmaBaseStationLatitude(int32_t *aCdmaBaseStationLatitude)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cdmaBaseStationLongitude; */
NS_IMETHODIMP nsMobileCellInfo::GetCdmaBaseStationLongitude(int32_t *aCdmaBaseStationLongitude)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cdmaSystemId; */
NS_IMETHODIMP nsMobileCellInfo::GetCdmaSystemId(int32_t *aCdmaSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long cdmaNetworkId; */
NS_IMETHODIMP nsMobileCellInfo::GetCdmaNetworkId(int32_t *aCdmaNetworkId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileCellInfo_h__ */
