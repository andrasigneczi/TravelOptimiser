/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINeighboringCellInfo.idl
 */

#ifndef __gen_nsINeighboringCellInfo_h__
#define __gen_nsINeighboringCellInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsINeighboringCellInfo; /* forward declaration */


/* starting interface:    nsINeighboringCellIdsCallback */
#define NS_INEIGHBORINGCELLIDSCALLBACK_IID_STR "0941cb79-36e5-41e0-b05f-cdb854c53f03"

#define NS_INEIGHBORINGCELLIDSCALLBACK_IID \
  {0x0941cb79, 0x36e5, 0x41e0, \
    { 0xb0, 0x5f, 0xcd, 0xb8, 0x54, 0xc5, 0x3f, 0x03 }}

class NS_NO_VTABLE nsINeighboringCellIdsCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INEIGHBORINGCELLIDSCALLBACK_IID)

  /* void notifyGetNeighboringCellIds (in uint32_t count, [array, size_is (count)] in nsINeighboringCellInfo result); */
  NS_IMETHOD NotifyGetNeighboringCellIds(uint32_t count, nsINeighboringCellInfo **result) = 0;

  /* void notifyGetNeighboringCellIdsFailed (in DOMString error); */
  NS_IMETHOD NotifyGetNeighboringCellIdsFailed(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINeighboringCellIdsCallback, NS_INEIGHBORINGCELLIDSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINEIGHBORINGCELLIDSCALLBACK \
  NS_IMETHOD NotifyGetNeighboringCellIds(uint32_t count, nsINeighboringCellInfo **result) override; \
  NS_IMETHOD NotifyGetNeighboringCellIdsFailed(const nsAString & error) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINEIGHBORINGCELLIDSCALLBACK(_to) \
  NS_IMETHOD NotifyGetNeighboringCellIds(uint32_t count, nsINeighboringCellInfo **result) override { return _to NotifyGetNeighboringCellIds(count, result); } \
  NS_IMETHOD NotifyGetNeighboringCellIdsFailed(const nsAString & error) override { return _to NotifyGetNeighboringCellIdsFailed(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINEIGHBORINGCELLIDSCALLBACK(_to) \
  NS_IMETHOD NotifyGetNeighboringCellIds(uint32_t count, nsINeighboringCellInfo **result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetNeighboringCellIds(count, result); } \
  NS_IMETHOD NotifyGetNeighboringCellIdsFailed(const nsAString & error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetNeighboringCellIdsFailed(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNeighboringCellIdsCallback : public nsINeighboringCellIdsCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINEIGHBORINGCELLIDSCALLBACK

  nsNeighboringCellIdsCallback();

private:
  ~nsNeighboringCellIdsCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNeighboringCellIdsCallback, nsINeighboringCellIdsCallback)

nsNeighboringCellIdsCallback::nsNeighboringCellIdsCallback()
{
  /* member initializers and constructor code */
}

nsNeighboringCellIdsCallback::~nsNeighboringCellIdsCallback()
{
  /* destructor code */
}

/* void notifyGetNeighboringCellIds (in uint32_t count, [array, size_is (count)] in nsINeighboringCellInfo result); */
NS_IMETHODIMP nsNeighboringCellIdsCallback::NotifyGetNeighboringCellIds(uint32_t count, nsINeighboringCellInfo **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetNeighboringCellIdsFailed (in DOMString error); */
NS_IMETHODIMP nsNeighboringCellIdsCallback::NotifyGetNeighboringCellIdsFailed(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINeighboringCellInfo */
#define NS_INEIGHBORINGCELLINFO_IID_STR "87dc222e-abb3-4342-95bf-626aa19fa20e"

#define NS_INEIGHBORINGCELLINFO_IID \
  {0x87dc222e, 0xabb3, 0x4342, \
    { 0x95, 0xbf, 0x62, 0x6a, 0xa1, 0x9f, 0xa2, 0x0e }}

class NS_NO_VTABLE nsINeighboringCellInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INEIGHBORINGCELLINFO_IID)

  /* readonly attribute DOMString networkType; */
  NS_IMETHOD GetNetworkType(nsAString & aNetworkType) = 0;

  /* readonly attribute long gsmLocationAreaCode; */
  NS_IMETHOD GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode) = 0;

  /* readonly attribute long long gsmCellId; */
  NS_IMETHOD GetGsmCellId(int64_t *aGsmCellId) = 0;

  /* readonly attribute long wcdmaPsc; */
  NS_IMETHOD GetWcdmaPsc(int32_t *aWcdmaPsc) = 0;

  /* readonly attribute long signalStrength; */
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINeighboringCellInfo, NS_INEIGHBORINGCELLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINEIGHBORINGCELLINFO \
  NS_IMETHOD GetNetworkType(nsAString & aNetworkType) override; \
  NS_IMETHOD GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode) override; \
  NS_IMETHOD GetGsmCellId(int64_t *aGsmCellId) override; \
  NS_IMETHOD GetWcdmaPsc(int32_t *aWcdmaPsc) override; \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINEIGHBORINGCELLINFO(_to) \
  NS_IMETHOD GetNetworkType(nsAString & aNetworkType) override { return _to GetNetworkType(aNetworkType); } \
  NS_IMETHOD GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode) override { return _to GetGsmLocationAreaCode(aGsmLocationAreaCode); } \
  NS_IMETHOD GetGsmCellId(int64_t *aGsmCellId) override { return _to GetGsmCellId(aGsmCellId); } \
  NS_IMETHOD GetWcdmaPsc(int32_t *aWcdmaPsc) override { return _to GetWcdmaPsc(aWcdmaPsc); } \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override { return _to GetSignalStrength(aSignalStrength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINEIGHBORINGCELLINFO(_to) \
  NS_IMETHOD GetNetworkType(nsAString & aNetworkType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetworkType(aNetworkType); } \
  NS_IMETHOD GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGsmLocationAreaCode(aGsmLocationAreaCode); } \
  NS_IMETHOD GetGsmCellId(int64_t *aGsmCellId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGsmCellId(aGsmCellId); } \
  NS_IMETHOD GetWcdmaPsc(int32_t *aWcdmaPsc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWcdmaPsc(aWcdmaPsc); } \
  NS_IMETHOD GetSignalStrength(int32_t *aSignalStrength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSignalStrength(aSignalStrength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNeighboringCellInfo : public nsINeighboringCellInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINEIGHBORINGCELLINFO

  nsNeighboringCellInfo();

private:
  ~nsNeighboringCellInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNeighboringCellInfo, nsINeighboringCellInfo)

nsNeighboringCellInfo::nsNeighboringCellInfo()
{
  /* member initializers and constructor code */
}

nsNeighboringCellInfo::~nsNeighboringCellInfo()
{
  /* destructor code */
}

/* readonly attribute DOMString networkType; */
NS_IMETHODIMP nsNeighboringCellInfo::GetNetworkType(nsAString & aNetworkType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long gsmLocationAreaCode; */
NS_IMETHODIMP nsNeighboringCellInfo::GetGsmLocationAreaCode(int32_t *aGsmLocationAreaCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long gsmCellId; */
NS_IMETHODIMP nsNeighboringCellInfo::GetGsmCellId(int64_t *aGsmCellId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long wcdmaPsc; */
NS_IMETHODIMP nsNeighboringCellInfo::GetWcdmaPsc(int32_t *aWcdmaPsc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long signalStrength; */
NS_IMETHODIMP nsNeighboringCellInfo::GetSignalStrength(int32_t *aSignalStrength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINeighboringCellInfo_h__ */
