/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITransportSecurityInfo.idl
 */

#ifndef __gen_nsITransportSecurityInfo_h__
#define __gen_nsITransportSecurityInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509CertList; /* forward declaration */


/* starting interface:    nsITransportSecurityInfo */
#define NS_ITRANSPORTSECURITYINFO_IID_STR "216112d3-28bc-4671-b057-f98cc09ba1ea"

#define NS_ITRANSPORTSECURITYINFO_IID \
  {0x216112d3, 0x28bc, 0x4671, \
    { 0xb0, 0x57, 0xf9, 0x8c, 0xc0, 0x9b, 0xa1, 0xea }}

class NS_NO_VTABLE nsITransportSecurityInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSPORTSECURITYINFO_IID)

  /* readonly attribute unsigned long securityState; */
  NS_IMETHOD GetSecurityState(uint32_t *aSecurityState) = 0;

  /* readonly attribute wstring errorMessage; */
  NS_IMETHOD GetErrorMessage(char16_t * *aErrorMessage) = 0;

  /* readonly attribute long errorCode; */
  NS_IMETHOD GetErrorCode(int32_t *aErrorCode) = 0;

  /* readonly attribute nsIX509CertList failedCertChain; */
  NS_IMETHOD GetFailedCertChain(nsIX509CertList * *aFailedCertChain) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransportSecurityInfo, NS_ITRANSPORTSECURITYINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSPORTSECURITYINFO \
  NS_IMETHOD GetSecurityState(uint32_t *aSecurityState) override; \
  NS_IMETHOD GetErrorMessage(char16_t * *aErrorMessage) override; \
  NS_IMETHOD GetErrorCode(int32_t *aErrorCode) override; \
  NS_IMETHOD GetFailedCertChain(nsIX509CertList * *aFailedCertChain) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSPORTSECURITYINFO(_to) \
  NS_IMETHOD GetSecurityState(uint32_t *aSecurityState) override { return _to GetSecurityState(aSecurityState); } \
  NS_IMETHOD GetErrorMessage(char16_t * *aErrorMessage) override { return _to GetErrorMessage(aErrorMessage); } \
  NS_IMETHOD GetErrorCode(int32_t *aErrorCode) override { return _to GetErrorCode(aErrorCode); } \
  NS_IMETHOD GetFailedCertChain(nsIX509CertList * *aFailedCertChain) override { return _to GetFailedCertChain(aFailedCertChain); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSPORTSECURITYINFO(_to) \
  NS_IMETHOD GetSecurityState(uint32_t *aSecurityState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityState(aSecurityState); } \
  NS_IMETHOD GetErrorMessage(char16_t * *aErrorMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorMessage(aErrorMessage); } \
  NS_IMETHOD GetErrorCode(int32_t *aErrorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorCode(aErrorCode); } \
  NS_IMETHOD GetFailedCertChain(nsIX509CertList * *aFailedCertChain) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFailedCertChain(aFailedCertChain); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransportSecurityInfo : public nsITransportSecurityInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSPORTSECURITYINFO

  nsTransportSecurityInfo();

private:
  ~nsTransportSecurityInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTransportSecurityInfo, nsITransportSecurityInfo)

nsTransportSecurityInfo::nsTransportSecurityInfo()
{
  /* member initializers and constructor code */
}

nsTransportSecurityInfo::~nsTransportSecurityInfo()
{
  /* destructor code */
}

/* readonly attribute unsigned long securityState; */
NS_IMETHODIMP nsTransportSecurityInfo::GetSecurityState(uint32_t *aSecurityState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring errorMessage; */
NS_IMETHODIMP nsTransportSecurityInfo::GetErrorMessage(char16_t * *aErrorMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long errorCode; */
NS_IMETHODIMP nsTransportSecurityInfo::GetErrorCode(int32_t *aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIX509CertList failedCertChain; */
NS_IMETHODIMP nsTransportSecurityInfo::GetFailedCertChain(nsIX509CertList * *aFailedCertChain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransportSecurityInfo_h__ */
