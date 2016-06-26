/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIccInfo.idl
 */

#ifndef __gen_nsIIccInfo_h__
#define __gen_nsIIccInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIccInfo */
#define NS_IICCINFO_IID_STR "3ba11a90-34e0-11e4-8c21-0800200c9a66"

#define NS_IICCINFO_IID \
  {0x3ba11a90, 0x34e0, 0x11e4, \
    { 0x8c, 0x21, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIIccInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IICCINFO_IID)

  /* readonly attribute DOMString iccType; */
  NS_IMETHOD GetIccType(nsAString & aIccType) = 0;

  /* readonly attribute DOMString iccid; */
  NS_IMETHOD GetIccid(nsAString & aIccid) = 0;

  /* readonly attribute DOMString mcc; */
  NS_IMETHOD GetMcc(nsAString & aMcc) = 0;

  /* readonly attribute DOMString mnc; */
  NS_IMETHOD GetMnc(nsAString & aMnc) = 0;

  /* readonly attribute DOMString spn; */
  NS_IMETHOD GetSpn(nsAString & aSpn) = 0;

  /* readonly attribute boolean isDisplayNetworkNameRequired; */
  NS_IMETHOD GetIsDisplayNetworkNameRequired(bool *aIsDisplayNetworkNameRequired) = 0;

  /* readonly attribute boolean isDisplaySpnRequired; */
  NS_IMETHOD GetIsDisplaySpnRequired(bool *aIsDisplaySpnRequired) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIccInfo, NS_IICCINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIICCINFO \
  NS_IMETHOD GetIccType(nsAString & aIccType) override; \
  NS_IMETHOD GetIccid(nsAString & aIccid) override; \
  NS_IMETHOD GetMcc(nsAString & aMcc) override; \
  NS_IMETHOD GetMnc(nsAString & aMnc) override; \
  NS_IMETHOD GetSpn(nsAString & aSpn) override; \
  NS_IMETHOD GetIsDisplayNetworkNameRequired(bool *aIsDisplayNetworkNameRequired) override; \
  NS_IMETHOD GetIsDisplaySpnRequired(bool *aIsDisplaySpnRequired) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIICCINFO(_to) \
  NS_IMETHOD GetIccType(nsAString & aIccType) override { return _to GetIccType(aIccType); } \
  NS_IMETHOD GetIccid(nsAString & aIccid) override { return _to GetIccid(aIccid); } \
  NS_IMETHOD GetMcc(nsAString & aMcc) override { return _to GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(nsAString & aMnc) override { return _to GetMnc(aMnc); } \
  NS_IMETHOD GetSpn(nsAString & aSpn) override { return _to GetSpn(aSpn); } \
  NS_IMETHOD GetIsDisplayNetworkNameRequired(bool *aIsDisplayNetworkNameRequired) override { return _to GetIsDisplayNetworkNameRequired(aIsDisplayNetworkNameRequired); } \
  NS_IMETHOD GetIsDisplaySpnRequired(bool *aIsDisplaySpnRequired) override { return _to GetIsDisplaySpnRequired(aIsDisplaySpnRequired); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIICCINFO(_to) \
  NS_IMETHOD GetIccType(nsAString & aIccType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIccType(aIccType); } \
  NS_IMETHOD GetIccid(nsAString & aIccid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIccid(aIccid); } \
  NS_IMETHOD GetMcc(nsAString & aMcc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(nsAString & aMnc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMnc(aMnc); } \
  NS_IMETHOD GetSpn(nsAString & aSpn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpn(aSpn); } \
  NS_IMETHOD GetIsDisplayNetworkNameRequired(bool *aIsDisplayNetworkNameRequired) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDisplayNetworkNameRequired(aIsDisplayNetworkNameRequired); } \
  NS_IMETHOD GetIsDisplaySpnRequired(bool *aIsDisplaySpnRequired) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDisplaySpnRequired(aIsDisplaySpnRequired); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIccInfo : public nsIIccInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIICCINFO

  nsIccInfo();

private:
  ~nsIccInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsIccInfo, nsIIccInfo)

nsIccInfo::nsIccInfo()
{
  /* member initializers and constructor code */
}

nsIccInfo::~nsIccInfo()
{
  /* destructor code */
}

/* readonly attribute DOMString iccType; */
NS_IMETHODIMP nsIccInfo::GetIccType(nsAString & aIccType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString iccid; */
NS_IMETHODIMP nsIccInfo::GetIccid(nsAString & aIccid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mcc; */
NS_IMETHODIMP nsIccInfo::GetMcc(nsAString & aMcc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mnc; */
NS_IMETHODIMP nsIccInfo::GetMnc(nsAString & aMnc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString spn; */
NS_IMETHODIMP nsIccInfo::GetSpn(nsAString & aSpn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDisplayNetworkNameRequired; */
NS_IMETHODIMP nsIccInfo::GetIsDisplayNetworkNameRequired(bool *aIsDisplayNetworkNameRequired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDisplaySpnRequired; */
NS_IMETHODIMP nsIccInfo::GetIsDisplaySpnRequired(bool *aIsDisplaySpnRequired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGsmIccInfo */
#define NS_IGSMICCINFO_IID_STR "6c9c78b0-34e0-11e4-8c21-0800200c9a66"

#define NS_IGSMICCINFO_IID \
  {0x6c9c78b0, 0x34e0, 0x11e4, \
    { 0x8c, 0x21, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIGsmIccInfo : public nsIIccInfo {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGSMICCINFO_IID)

  /* readonly attribute DOMString msisdn; */
  NS_IMETHOD GetMsisdn(nsAString & aMsisdn) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGsmIccInfo, NS_IGSMICCINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGSMICCINFO \
  NS_IMETHOD GetMsisdn(nsAString & aMsisdn) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGSMICCINFO(_to) \
  NS_IMETHOD GetMsisdn(nsAString & aMsisdn) override { return _to GetMsisdn(aMsisdn); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGSMICCINFO(_to) \
  NS_IMETHOD GetMsisdn(nsAString & aMsisdn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMsisdn(aMsisdn); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGsmIccInfo : public nsIGsmIccInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGSMICCINFO

  nsGsmIccInfo();

private:
  ~nsGsmIccInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsGsmIccInfo, nsIGsmIccInfo)

nsGsmIccInfo::nsGsmIccInfo()
{
  /* member initializers and constructor code */
}

nsGsmIccInfo::~nsGsmIccInfo()
{
  /* destructor code */
}

/* readonly attribute DOMString msisdn; */
NS_IMETHODIMP nsGsmIccInfo::GetMsisdn(nsAString & aMsisdn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICdmaIccInfo */
#define NS_ICDMAICCINFO_IID_STR "7452f570-34e0-11e4-8c21-0800200c9a66"

#define NS_ICDMAICCINFO_IID \
  {0x7452f570, 0x34e0, 0x11e4, \
    { 0x8c, 0x21, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsICdmaIccInfo : public nsIIccInfo {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICDMAICCINFO_IID)

  /* readonly attribute DOMString mdn; */
  NS_IMETHOD GetMdn(nsAString & aMdn) = 0;

  /* readonly attribute long prlVersion; */
  NS_IMETHOD GetPrlVersion(int32_t *aPrlVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICdmaIccInfo, NS_ICDMAICCINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICDMAICCINFO \
  NS_IMETHOD GetMdn(nsAString & aMdn) override; \
  NS_IMETHOD GetPrlVersion(int32_t *aPrlVersion) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICDMAICCINFO(_to) \
  NS_IMETHOD GetMdn(nsAString & aMdn) override { return _to GetMdn(aMdn); } \
  NS_IMETHOD GetPrlVersion(int32_t *aPrlVersion) override { return _to GetPrlVersion(aPrlVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICDMAICCINFO(_to) \
  NS_IMETHOD GetMdn(nsAString & aMdn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMdn(aMdn); } \
  NS_IMETHOD GetPrlVersion(int32_t *aPrlVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrlVersion(aPrlVersion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCdmaIccInfo : public nsICdmaIccInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICDMAICCINFO

  nsCdmaIccInfo();

private:
  ~nsCdmaIccInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCdmaIccInfo, nsICdmaIccInfo)

nsCdmaIccInfo::nsCdmaIccInfo()
{
  /* member initializers and constructor code */
}

nsCdmaIccInfo::~nsCdmaIccInfo()
{
  /* destructor code */
}

/* readonly attribute DOMString mdn; */
NS_IMETHODIMP nsCdmaIccInfo::GetMdn(nsAString & aMdn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long prlVersion; */
NS_IMETHODIMP nsCdmaIccInfo::GetPrlVersion(int32_t *aPrlVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIccInfo_h__ */
