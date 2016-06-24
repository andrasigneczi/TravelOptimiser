/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILocalCertService.idl
 */

#ifndef __gen_nsILocalCertService_h__
#define __gen_nsILocalCertService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */

class nsILocalCertGetCallback; /* forward declaration */

class nsILocalCertCallback; /* forward declaration */


/* starting interface:    nsILocalCertService */
#define NS_ILOCALCERTSERVICE_IID_STR "9702fdd4-4c2c-439c-ba2e-19cda018eb99"

#define NS_ILOCALCERTSERVICE_IID \
  {0x9702fdd4, 0x4c2c, 0x439c, \
    { 0xba, 0x2e, 0x19, 0xcd, 0xa0, 0x18, 0xeb, 0x99 }}

class NS_NO_VTABLE nsILocalCertService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALCERTSERVICE_IID)

  /* void getOrCreateCert (in ACString nickname, in nsILocalCertGetCallback cb); */
  NS_IMETHOD GetOrCreateCert(const nsACString & nickname, nsILocalCertGetCallback *cb) = 0;

  /* void removeCert (in ACString nickname, in nsILocalCertCallback cb); */
  NS_IMETHOD RemoveCert(const nsACString & nickname, nsILocalCertCallback *cb) = 0;

  /* readonly attribute boolean loginPromptRequired; */
  NS_IMETHOD GetLoginPromptRequired(bool *aLoginPromptRequired) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalCertService, NS_ILOCALCERTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALCERTSERVICE \
  NS_IMETHOD GetOrCreateCert(const nsACString & nickname, nsILocalCertGetCallback *cb) override; \
  NS_IMETHOD RemoveCert(const nsACString & nickname, nsILocalCertCallback *cb) override; \
  NS_IMETHOD GetLoginPromptRequired(bool *aLoginPromptRequired) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALCERTSERVICE(_to) \
  NS_IMETHOD GetOrCreateCert(const nsACString & nickname, nsILocalCertGetCallback *cb) override { return _to GetOrCreateCert(nickname, cb); } \
  NS_IMETHOD RemoveCert(const nsACString & nickname, nsILocalCertCallback *cb) override { return _to RemoveCert(nickname, cb); } \
  NS_IMETHOD GetLoginPromptRequired(bool *aLoginPromptRequired) override { return _to GetLoginPromptRequired(aLoginPromptRequired); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALCERTSERVICE(_to) \
  NS_IMETHOD GetOrCreateCert(const nsACString & nickname, nsILocalCertGetCallback *cb) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrCreateCert(nickname, cb); } \
  NS_IMETHOD RemoveCert(const nsACString & nickname, nsILocalCertCallback *cb) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveCert(nickname, cb); } \
  NS_IMETHOD GetLoginPromptRequired(bool *aLoginPromptRequired) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoginPromptRequired(aLoginPromptRequired); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalCertService : public nsILocalCertService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALCERTSERVICE

  nsLocalCertService();

private:
  ~nsLocalCertService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLocalCertService, nsILocalCertService)

nsLocalCertService::nsLocalCertService()
{
  /* member initializers and constructor code */
}

nsLocalCertService::~nsLocalCertService()
{
  /* destructor code */
}

/* void getOrCreateCert (in ACString nickname, in nsILocalCertGetCallback cb); */
NS_IMETHODIMP nsLocalCertService::GetOrCreateCert(const nsACString & nickname, nsILocalCertGetCallback *cb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeCert (in ACString nickname, in nsILocalCertCallback cb); */
NS_IMETHODIMP nsLocalCertService::RemoveCert(const nsACString & nickname, nsILocalCertCallback *cb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean loginPromptRequired; */
NS_IMETHODIMP nsLocalCertService::GetLoginPromptRequired(bool *aLoginPromptRequired)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsILocalCertGetCallback */
#define NS_ILOCALCERTGETCALLBACK_IID_STR "cc09633e-7c70-4093-a9cf-79ab676ca8a9"

#define NS_ILOCALCERTGETCALLBACK_IID \
  {0xcc09633e, 0x7c70, 0x4093, \
    { 0xa9, 0xcf, 0x79, 0xab, 0x67, 0x6c, 0xa8, 0xa9 }}

class NS_NO_VTABLE nsILocalCertGetCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALCERTGETCALLBACK_IID)

  /* void handleCert (in nsIX509Cert cert, in nsresult result); */
  NS_IMETHOD HandleCert(nsIX509Cert *cert, nsresult result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalCertGetCallback, NS_ILOCALCERTGETCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALCERTGETCALLBACK \
  NS_IMETHOD HandleCert(nsIX509Cert *cert, nsresult result) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALCERTGETCALLBACK(_to) \
  NS_IMETHOD HandleCert(nsIX509Cert *cert, nsresult result) override { return _to HandleCert(cert, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALCERTGETCALLBACK(_to) \
  NS_IMETHOD HandleCert(nsIX509Cert *cert, nsresult result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCert(cert, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalCertGetCallback : public nsILocalCertGetCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALCERTGETCALLBACK

  nsLocalCertGetCallback();

private:
  ~nsLocalCertGetCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLocalCertGetCallback, nsILocalCertGetCallback)

nsLocalCertGetCallback::nsLocalCertGetCallback()
{
  /* member initializers and constructor code */
}

nsLocalCertGetCallback::~nsLocalCertGetCallback()
{
  /* destructor code */
}

/* void handleCert (in nsIX509Cert cert, in nsresult result); */
NS_IMETHODIMP nsLocalCertGetCallback::HandleCert(nsIX509Cert *cert, nsresult result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsILocalCertCallback */
#define NS_ILOCALCERTCALLBACK_IID_STR "518124e9-55e6-4e23-97c0-4995b3a1bec6"

#define NS_ILOCALCERTCALLBACK_IID \
  {0x518124e9, 0x55e6, 0x4e23, \
    { 0x97, 0xc0, 0x49, 0x95, 0xb3, 0xa1, 0xbe, 0xc6 }}

class NS_NO_VTABLE nsILocalCertCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALCERTCALLBACK_IID)

  /* void handleResult (in nsresult result); */
  NS_IMETHOD HandleResult(nsresult result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalCertCallback, NS_ILOCALCERTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALCERTCALLBACK \
  NS_IMETHOD HandleResult(nsresult result) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALCERTCALLBACK(_to) \
  NS_IMETHOD HandleResult(nsresult result) override { return _to HandleResult(result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALCERTCALLBACK(_to) \
  NS_IMETHOD HandleResult(nsresult result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleResult(result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalCertCallback : public nsILocalCertCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALCERTCALLBACK

  nsLocalCertCallback();

private:
  ~nsLocalCertCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLocalCertCallback, nsILocalCertCallback)

nsLocalCertCallback::nsLocalCertCallback()
{
  /* member initializers and constructor code */
}

nsLocalCertCallback::~nsLocalCertCallback()
{
  /* destructor code */
}

/* void handleResult (in nsresult result); */
NS_IMETHODIMP nsLocalCertCallback::HandleResult(nsresult result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define LOCALCERTSERVICE_CONTRACTID \
  "@mozilla.org/security/local-cert-service;1"

#endif /* __gen_nsILocalCertService_h__ */
