/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMNavigator.idl
 */

#ifndef __gen_nsIDOMNavigator_h__
#define __gen_nsIDOMNavigator_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIdleObserver; /* forward declaration */


/* starting interface:    nsIDOMNavigator */
#define NS_IDOMNAVIGATOR_IID_STR "f1101fbb-d119-4cb8-845b-6bbae8a151c7"

#define NS_IDOMNAVIGATOR_IID \
  {0xf1101fbb, 0xd119, 0x4cb8, \
    { 0x84, 0x5b, 0x6b, 0xba, 0xe8, 0xa1, 0x51, 0xc7 }}

class NS_NO_VTABLE nsIDOMNavigator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATOR_IID)

  /* readonly attribute DOMString appCodeName; */
  NS_IMETHOD GetAppCodeName(nsAString & aAppCodeName) = 0;

  /* readonly attribute DOMString appName; */
  NS_IMETHOD GetAppName(nsAString & aAppName) = 0;

  /* readonly attribute DOMString appVersion; */
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) = 0;

  /* readonly attribute DOMString language; */
  NS_IMETHOD GetLanguage(nsAString & aLanguage) = 0;

  /* readonly attribute DOMString platform; */
  NS_IMETHOD GetPlatform(nsAString & aPlatform) = 0;

  /* readonly attribute DOMString oscpu; */
  NS_IMETHOD GetOscpu(nsAString & aOscpu) = 0;

  /* readonly attribute DOMString vendor; */
  NS_IMETHOD GetVendor(nsAString & aVendor) = 0;

  /* readonly attribute DOMString vendorSub; */
  NS_IMETHOD GetVendorSub(nsAString & aVendorSub) = 0;

  /* readonly attribute DOMString product; */
  NS_IMETHOD GetProduct(nsAString & aProduct) = 0;

  /* readonly attribute DOMString productSub; */
  NS_IMETHOD GetProductSub(nsAString & aProductSub) = 0;

  /* readonly attribute DOMString userAgent; */
  NS_IMETHOD GetUserAgent(nsAString & aUserAgent) = 0;

  /* readonly attribute DOMString buildID; */
  NS_IMETHOD GetBuildID(nsAString & aBuildID) = 0;

  /* readonly attribute DOMString doNotTrack; */
  NS_IMETHOD GetDoNotTrack(nsAString & aDoNotTrack) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigator, NS_IDOMNAVIGATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATOR \
  NS_IMETHOD GetAppCodeName(nsAString & aAppCodeName) override; \
  NS_IMETHOD GetAppName(nsAString & aAppName) override; \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) override; \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) override; \
  NS_IMETHOD GetPlatform(nsAString & aPlatform) override; \
  NS_IMETHOD GetOscpu(nsAString & aOscpu) override; \
  NS_IMETHOD GetVendor(nsAString & aVendor) override; \
  NS_IMETHOD GetVendorSub(nsAString & aVendorSub) override; \
  NS_IMETHOD GetProduct(nsAString & aProduct) override; \
  NS_IMETHOD GetProductSub(nsAString & aProductSub) override; \
  NS_IMETHOD GetUserAgent(nsAString & aUserAgent) override; \
  NS_IMETHOD GetBuildID(nsAString & aBuildID) override; \
  NS_IMETHOD GetDoNotTrack(nsAString & aDoNotTrack) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATOR(_to) \
  NS_IMETHOD GetAppCodeName(nsAString & aAppCodeName) override { return _to GetAppCodeName(aAppCodeName); } \
  NS_IMETHOD GetAppName(nsAString & aAppName) override { return _to GetAppName(aAppName); } \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) override { return _to GetAppVersion(aAppVersion); } \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) override { return _to GetLanguage(aLanguage); } \
  NS_IMETHOD GetPlatform(nsAString & aPlatform) override { return _to GetPlatform(aPlatform); } \
  NS_IMETHOD GetOscpu(nsAString & aOscpu) override { return _to GetOscpu(aOscpu); } \
  NS_IMETHOD GetVendor(nsAString & aVendor) override { return _to GetVendor(aVendor); } \
  NS_IMETHOD GetVendorSub(nsAString & aVendorSub) override { return _to GetVendorSub(aVendorSub); } \
  NS_IMETHOD GetProduct(nsAString & aProduct) override { return _to GetProduct(aProduct); } \
  NS_IMETHOD GetProductSub(nsAString & aProductSub) override { return _to GetProductSub(aProductSub); } \
  NS_IMETHOD GetUserAgent(nsAString & aUserAgent) override { return _to GetUserAgent(aUserAgent); } \
  NS_IMETHOD GetBuildID(nsAString & aBuildID) override { return _to GetBuildID(aBuildID); } \
  NS_IMETHOD GetDoNotTrack(nsAString & aDoNotTrack) override { return _to GetDoNotTrack(aDoNotTrack); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATOR(_to) \
  NS_IMETHOD GetAppCodeName(nsAString & aAppCodeName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppCodeName(aAppCodeName); } \
  NS_IMETHOD GetAppName(nsAString & aAppName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppName(aAppName); } \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppVersion(aAppVersion); } \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } \
  NS_IMETHOD GetPlatform(nsAString & aPlatform) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatform(aPlatform); } \
  NS_IMETHOD GetOscpu(nsAString & aOscpu) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOscpu(aOscpu); } \
  NS_IMETHOD GetVendor(nsAString & aVendor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVendor(aVendor); } \
  NS_IMETHOD GetVendorSub(nsAString & aVendorSub) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVendorSub(aVendorSub); } \
  NS_IMETHOD GetProduct(nsAString & aProduct) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProduct(aProduct); } \
  NS_IMETHOD GetProductSub(nsAString & aProductSub) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProductSub(aProductSub); } \
  NS_IMETHOD GetUserAgent(nsAString & aUserAgent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserAgent(aUserAgent); } \
  NS_IMETHOD GetBuildID(nsAString & aBuildID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuildID(aBuildID); } \
  NS_IMETHOD GetDoNotTrack(nsAString & aDoNotTrack) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoNotTrack(aDoNotTrack); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigator : public nsIDOMNavigator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATOR

  nsDOMNavigator();

private:
  ~nsDOMNavigator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMNavigator, nsIDOMNavigator)

nsDOMNavigator::nsDOMNavigator()
{
  /* member initializers and constructor code */
}

nsDOMNavigator::~nsDOMNavigator()
{
  /* destructor code */
}

/* readonly attribute DOMString appCodeName; */
NS_IMETHODIMP nsDOMNavigator::GetAppCodeName(nsAString & aAppCodeName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString appName; */
NS_IMETHODIMP nsDOMNavigator::GetAppName(nsAString & aAppName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString appVersion; */
NS_IMETHODIMP nsDOMNavigator::GetAppVersion(nsAString & aAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString language; */
NS_IMETHODIMP nsDOMNavigator::GetLanguage(nsAString & aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString platform; */
NS_IMETHODIMP nsDOMNavigator::GetPlatform(nsAString & aPlatform)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString oscpu; */
NS_IMETHODIMP nsDOMNavigator::GetOscpu(nsAString & aOscpu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString vendor; */
NS_IMETHODIMP nsDOMNavigator::GetVendor(nsAString & aVendor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString vendorSub; */
NS_IMETHODIMP nsDOMNavigator::GetVendorSub(nsAString & aVendorSub)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString product; */
NS_IMETHODIMP nsDOMNavigator::GetProduct(nsAString & aProduct)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString productSub; */
NS_IMETHODIMP nsDOMNavigator::GetProductSub(nsAString & aProductSub)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString userAgent; */
NS_IMETHODIMP nsDOMNavigator::GetUserAgent(nsAString & aUserAgent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString buildID; */
NS_IMETHODIMP nsDOMNavigator::GetBuildID(nsAString & aBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString doNotTrack; */
NS_IMETHODIMP nsDOMNavigator::GetDoNotTrack(nsAString & aDoNotTrack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigator_h__ */
