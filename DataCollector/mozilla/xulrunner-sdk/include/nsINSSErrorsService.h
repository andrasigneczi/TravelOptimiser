/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINSSErrorsService.idl
 */

#ifndef __gen_nsINSSErrorsService_h__
#define __gen_nsINSSErrorsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINSSErrorsService */
#define NS_INSSERRORSSERVICE_IID_STR "12f60021-e14b-4020-99d1-ed2c795be66a"

#define NS_INSSERRORSSERVICE_IID \
  {0x12f60021, 0xe14b, 0x4020, \
    { 0x99, 0xd1, 0xed, 0x2c, 0x79, 0x5b, 0xe6, 0x6a }}

class NS_NO_VTABLE nsINSSErrorsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INSSERRORSSERVICE_IID)

  /* boolean isNSSErrorCode (in int32_t aNSPRCode); */
  NS_IMETHOD IsNSSErrorCode(int32_t aNSPRCode, bool *_retval) = 0;

  /* nsresult getXPCOMFromNSSError (in int32_t aNSPRCode); */
  NS_IMETHOD GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval) = 0;

  /* AString getErrorMessage (in nsresult aXPCOMErrorCode); */
  NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval) = 0;

  /* uint32_t getErrorClass (in nsresult aXPCOMErrorCode); */
  NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval) = 0;

  enum {
    ERROR_CLASS_SSL_PROTOCOL = 1U,
    ERROR_CLASS_BAD_CERT = 2U,
    NSS_SEC_ERROR_BASE = -8192,
    NSS_SEC_ERROR_LIMIT = -7192,
    NSS_SSL_ERROR_BASE = -12288,
    NSS_SSL_ERROR_LIMIT = -11288,
    MOZILLA_PKIX_ERROR_BASE = -16384,
    MOZILLA_PKIX_ERROR_LIMIT = -15384
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINSSErrorsService, NS_INSSERRORSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINSSERRORSSERVICE \
  NS_IMETHOD IsNSSErrorCode(int32_t aNSPRCode, bool *_retval) override; \
  NS_IMETHOD GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval) override; \
  NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval) override; \
  NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINSSERRORSSERVICE(_to) \
  NS_IMETHOD IsNSSErrorCode(int32_t aNSPRCode, bool *_retval) override { return _to IsNSSErrorCode(aNSPRCode, _retval); } \
  NS_IMETHOD GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval) override { return _to GetXPCOMFromNSSError(aNSPRCode, _retval); } \
  NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval) override { return _to GetErrorMessage(aXPCOMErrorCode, _retval); } \
  NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval) override { return _to GetErrorClass(aXPCOMErrorCode, _retval); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINSSERRORSSERVICE(_to) \
  NS_IMETHOD IsNSSErrorCode(int32_t aNSPRCode, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsNSSErrorCode(aNSPRCode, _retval); } \
  NS_IMETHOD GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXPCOMFromNSSError(aNSPRCode, _retval); } \
  NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorMessage(aXPCOMErrorCode, _retval); } \
  NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorClass(aXPCOMErrorCode, _retval); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNSSErrorsService : public nsINSSErrorsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINSSERRORSSERVICE

  nsNSSErrorsService();

private:
  ~nsNSSErrorsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNSSErrorsService, nsINSSErrorsService)

nsNSSErrorsService::nsNSSErrorsService()
{
  /* member initializers and constructor code */
}

nsNSSErrorsService::~nsNSSErrorsService()
{
  /* destructor code */
}

/* boolean isNSSErrorCode (in int32_t aNSPRCode); */
NS_IMETHODIMP nsNSSErrorsService::IsNSSErrorCode(int32_t aNSPRCode, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsresult getXPCOMFromNSSError (in int32_t aNSPRCode); */
NS_IMETHODIMP nsNSSErrorsService::GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getErrorMessage (in nsresult aXPCOMErrorCode); */
NS_IMETHODIMP nsNSSErrorsService::GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t getErrorClass (in nsresult aXPCOMErrorCode); */
NS_IMETHODIMP nsNSSErrorsService::GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINSSErrorsService_h__ */
