/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMobileNetworkInfo.idl
 */

#ifndef __gen_nsIMobileNetworkInfo_h__
#define __gen_nsIMobileNetworkInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMobileNetworkInfo */
#define NS_IMOBILENETWORKINFO_IID_STR "d7e1364c-61a0-4cf1-bae3-a960e87064e1"

#define NS_IMOBILENETWORKINFO_IID \
  {0xd7e1364c, 0x61a0, 0x4cf1, \
    { 0xba, 0xe3, 0xa9, 0x60, 0xe8, 0x70, 0x64, 0xe1 }}

class NS_NO_VTABLE nsIMobileNetworkInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILENETWORKINFO_IID)

  /* readonly attribute DOMString shortName; */
  NS_IMETHOD GetShortName(nsAString & aShortName) = 0;

  /* readonly attribute DOMString longName; */
  NS_IMETHOD GetLongName(nsAString & aLongName) = 0;

  /* readonly attribute DOMString mcc; */
  NS_IMETHOD GetMcc(nsAString & aMcc) = 0;

  /* readonly attribute DOMString mnc; */
  NS_IMETHOD GetMnc(nsAString & aMnc) = 0;

  /* readonly attribute DOMString state; */
  NS_IMETHOD GetState(nsAString & aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileNetworkInfo, NS_IMOBILENETWORKINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILENETWORKINFO \
  NS_IMETHOD GetShortName(nsAString & aShortName) override; \
  NS_IMETHOD GetLongName(nsAString & aLongName) override; \
  NS_IMETHOD GetMcc(nsAString & aMcc) override; \
  NS_IMETHOD GetMnc(nsAString & aMnc) override; \
  NS_IMETHOD GetState(nsAString & aState) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILENETWORKINFO(_to) \
  NS_IMETHOD GetShortName(nsAString & aShortName) override { return _to GetShortName(aShortName); } \
  NS_IMETHOD GetLongName(nsAString & aLongName) override { return _to GetLongName(aLongName); } \
  NS_IMETHOD GetMcc(nsAString & aMcc) override { return _to GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(nsAString & aMnc) override { return _to GetMnc(aMnc); } \
  NS_IMETHOD GetState(nsAString & aState) override { return _to GetState(aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILENETWORKINFO(_to) \
  NS_IMETHOD GetShortName(nsAString & aShortName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShortName(aShortName); } \
  NS_IMETHOD GetLongName(nsAString & aLongName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLongName(aLongName); } \
  NS_IMETHOD GetMcc(nsAString & aMcc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(nsAString & aMnc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMnc(aMnc); } \
  NS_IMETHOD GetState(nsAString & aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileNetworkInfo : public nsIMobileNetworkInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILENETWORKINFO

  nsMobileNetworkInfo();

private:
  ~nsMobileNetworkInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileNetworkInfo, nsIMobileNetworkInfo)

nsMobileNetworkInfo::nsMobileNetworkInfo()
{
  /* member initializers and constructor code */
}

nsMobileNetworkInfo::~nsMobileNetworkInfo()
{
  /* destructor code */
}

/* readonly attribute DOMString shortName; */
NS_IMETHODIMP nsMobileNetworkInfo::GetShortName(nsAString & aShortName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString longName; */
NS_IMETHODIMP nsMobileNetworkInfo::GetLongName(nsAString & aLongName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mcc; */
NS_IMETHODIMP nsMobileNetworkInfo::GetMcc(nsAString & aMcc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mnc; */
NS_IMETHODIMP nsMobileNetworkInfo::GetMnc(nsAString & aMnc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString state; */
NS_IMETHODIMP nsMobileNetworkInfo::GetState(nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileNetworkInfo_h__ */
