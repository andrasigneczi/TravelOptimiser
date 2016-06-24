/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIApplicationReputation.idl
 */

#ifndef __gen_nsIApplicationReputation_h__
#define __gen_nsIApplicationReputation_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIApplicationReputationCallback; /* forward declaration */

class nsIApplicationReputationQuery; /* forward declaration */

class nsIArray; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIApplicationReputationService */
#define NS_IAPPLICATIONREPUTATIONSERVICE_IID_STR "c9f03479-fd68-4393-acb2-c88d4f563174"

#define NS_IAPPLICATIONREPUTATIONSERVICE_IID \
  {0xc9f03479, 0xfd68, 0x4393, \
    { 0xac, 0xb2, 0xc8, 0x8d, 0x4f, 0x56, 0x31, 0x74 }}

class NS_NO_VTABLE nsIApplicationReputationService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONREPUTATIONSERVICE_IID)

  /* void queryReputation (in nsIApplicationReputationQuery aQuery, in nsIApplicationReputationCallback aCallback); */
  NS_IMETHOD QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationReputationService, NS_IAPPLICATIONREPUTATIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONREPUTATIONSERVICE \
  NS_IMETHOD QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONREPUTATIONSERVICE(_to) \
  NS_IMETHOD QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback) override { return _to QueryReputation(aQuery, aCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONREPUTATIONSERVICE(_to) \
  NS_IMETHOD QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryReputation(aQuery, aCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationReputationService : public nsIApplicationReputationService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONREPUTATIONSERVICE

  nsApplicationReputationService();

private:
  ~nsApplicationReputationService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsApplicationReputationService, nsIApplicationReputationService)

nsApplicationReputationService::nsApplicationReputationService()
{
  /* member initializers and constructor code */
}

nsApplicationReputationService::~nsApplicationReputationService()
{
  /* destructor code */
}

/* void queryReputation (in nsIApplicationReputationQuery aQuery, in nsIApplicationReputationCallback aCallback); */
NS_IMETHODIMP nsApplicationReputationService::QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIApplicationReputationQuery */
#define NS_IAPPLICATIONREPUTATIONQUERY_IID_STR "812d7509-a9a3-446e-a66f-3ed8cc91ebd0"

#define NS_IAPPLICATIONREPUTATIONQUERY_IID \
  {0x812d7509, 0xa9a3, 0x446e, \
    { 0xa6, 0x6f, 0x3e, 0xd8, 0xcc, 0x91, 0xeb, 0xd0 }}

class NS_NO_VTABLE nsIApplicationReputationQuery : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONREPUTATIONQUERY_IID)

  /* readonly attribute nsIURI sourceURI; */
  NS_IMETHOD GetSourceURI(nsIURI * *aSourceURI) = 0;

  /* readonly attribute nsIURI referrerURI; */
  NS_IMETHOD GetReferrerURI(nsIURI * *aReferrerURI) = 0;

  /* readonly attribute AString suggestedFileName; */
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) = 0;

  /* readonly attribute unsigned long fileSize; */
  NS_IMETHOD GetFileSize(uint32_t *aFileSize) = 0;

  /* readonly attribute ACString sha256Hash; */
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) = 0;

  /* readonly attribute nsIArray signatureInfo; */
  NS_IMETHOD GetSignatureInfo(nsIArray * *aSignatureInfo) = 0;

  /* readonly attribute nsIArray redirects; */
  NS_IMETHOD GetRedirects(nsIArray * *aRedirects) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationReputationQuery, NS_IAPPLICATIONREPUTATIONQUERY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONREPUTATIONQUERY \
  NS_IMETHOD GetSourceURI(nsIURI * *aSourceURI) override; \
  NS_IMETHOD GetReferrerURI(nsIURI * *aReferrerURI) override; \
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) override; \
  NS_IMETHOD GetFileSize(uint32_t *aFileSize) override; \
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) override; \
  NS_IMETHOD GetSignatureInfo(nsIArray * *aSignatureInfo) override; \
  NS_IMETHOD GetRedirects(nsIArray * *aRedirects) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONREPUTATIONQUERY(_to) \
  NS_IMETHOD GetSourceURI(nsIURI * *aSourceURI) override { return _to GetSourceURI(aSourceURI); } \
  NS_IMETHOD GetReferrerURI(nsIURI * *aReferrerURI) override { return _to GetReferrerURI(aReferrerURI); } \
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) override { return _to GetSuggestedFileName(aSuggestedFileName); } \
  NS_IMETHOD GetFileSize(uint32_t *aFileSize) override { return _to GetFileSize(aFileSize); } \
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) override { return _to GetSha256Hash(aSha256Hash); } \
  NS_IMETHOD GetSignatureInfo(nsIArray * *aSignatureInfo) override { return _to GetSignatureInfo(aSignatureInfo); } \
  NS_IMETHOD GetRedirects(nsIArray * *aRedirects) override { return _to GetRedirects(aRedirects); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONREPUTATIONQUERY(_to) \
  NS_IMETHOD GetSourceURI(nsIURI * *aSourceURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceURI(aSourceURI); } \
  NS_IMETHOD GetReferrerURI(nsIURI * *aReferrerURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrerURI(aReferrerURI); } \
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuggestedFileName(aSuggestedFileName); } \
  NS_IMETHOD GetFileSize(uint32_t *aFileSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileSize(aFileSize); } \
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSha256Hash(aSha256Hash); } \
  NS_IMETHOD GetSignatureInfo(nsIArray * *aSignatureInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSignatureInfo(aSignatureInfo); } \
  NS_IMETHOD GetRedirects(nsIArray * *aRedirects) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirects(aRedirects); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationReputationQuery : public nsIApplicationReputationQuery
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONREPUTATIONQUERY

  nsApplicationReputationQuery();

private:
  ~nsApplicationReputationQuery();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsApplicationReputationQuery, nsIApplicationReputationQuery)

nsApplicationReputationQuery::nsApplicationReputationQuery()
{
  /* member initializers and constructor code */
}

nsApplicationReputationQuery::~nsApplicationReputationQuery()
{
  /* destructor code */
}

/* readonly attribute nsIURI sourceURI; */
NS_IMETHODIMP nsApplicationReputationQuery::GetSourceURI(nsIURI * *aSourceURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI referrerURI; */
NS_IMETHODIMP nsApplicationReputationQuery::GetReferrerURI(nsIURI * *aReferrerURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString suggestedFileName; */
NS_IMETHODIMP nsApplicationReputationQuery::GetSuggestedFileName(nsAString & aSuggestedFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long fileSize; */
NS_IMETHODIMP nsApplicationReputationQuery::GetFileSize(uint32_t *aFileSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString sha256Hash; */
NS_IMETHODIMP nsApplicationReputationQuery::GetSha256Hash(nsACString & aSha256Hash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray signatureInfo; */
NS_IMETHODIMP nsApplicationReputationQuery::GetSignatureInfo(nsIArray * *aSignatureInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray redirects; */
NS_IMETHODIMP nsApplicationReputationQuery::GetRedirects(nsIArray * *aRedirects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIApplicationReputationCallback */
#define NS_IAPPLICATIONREPUTATIONCALLBACK_IID_STR "9a228470-cfe5-11e2-8b8b-0800200c9a66"

#define NS_IAPPLICATIONREPUTATIONCALLBACK_IID \
  {0x9a228470, 0xcfe5, 0x11e2, \
    { 0x8b, 0x8b, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIApplicationReputationCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONREPUTATIONCALLBACK_IID)

  /* void onComplete (in bool aShouldBlock, in nsresult aStatus); */
  NS_IMETHOD OnComplete(bool aShouldBlock, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationReputationCallback, NS_IAPPLICATIONREPUTATIONCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONREPUTATIONCALLBACK \
  NS_IMETHOD OnComplete(bool aShouldBlock, nsresult aStatus) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONREPUTATIONCALLBACK(_to) \
  NS_IMETHOD OnComplete(bool aShouldBlock, nsresult aStatus) override { return _to OnComplete(aShouldBlock, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONREPUTATIONCALLBACK(_to) \
  NS_IMETHOD OnComplete(bool aShouldBlock, nsresult aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnComplete(aShouldBlock, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationReputationCallback : public nsIApplicationReputationCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONREPUTATIONCALLBACK

  nsApplicationReputationCallback();

private:
  ~nsApplicationReputationCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsApplicationReputationCallback, nsIApplicationReputationCallback)

nsApplicationReputationCallback::nsApplicationReputationCallback()
{
  /* member initializers and constructor code */
}

nsApplicationReputationCallback::~nsApplicationReputationCallback()
{
  /* destructor code */
}

/* void onComplete (in bool aShouldBlock, in nsresult aStatus); */
NS_IMETHODIMP nsApplicationReputationCallback::OnComplete(bool aShouldBlock, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIApplicationReputation_h__ */
