/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITaggingService.idl
 */

#ifndef __gen_nsITaggingService_h__
#define __gen_nsITaggingService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsITaggingService */
#define NS_ITAGGINGSERVICE_IID_STR "9759bd0e-78e2-4421-9ed1-c676e1af3513"

#define NS_ITAGGINGSERVICE_IID \
  {0x9759bd0e, 0x78e2, 0x4421, \
    { 0x9e, 0xd1, 0xc6, 0x76, 0xe1, 0xaf, 0x35, 0x13 }}

class NS_NO_VTABLE nsITaggingService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITAGGINGSERVICE_IID)

  enum {
    MAX_TAG_LENGTH = 100U
  };

  /* void tagURI (in nsIURI aURI, in nsIVariant aTags); */
  NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) = 0;

  /* void untagURI (in nsIURI aURI, in nsIVariant aTags); */
  NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) = 0;

  /* nsIVariant getURIsForTag (in AString aTag); */
  NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval) = 0;

  /* void getTagsForURI (in nsIURI aURI, [optional] out unsigned long length, [array, size_is (length), retval] out wstring aTags); */
  NS_IMETHOD GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags) = 0;

  /* readonly attribute nsIVariant allTags; */
  NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) = 0;

  /* readonly attribute boolean hasTags; */
  NS_IMETHOD GetHasTags(bool *aHasTags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaggingService, NS_ITAGGINGSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITAGGINGSERVICE \
  NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) override; \
  NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) override; \
  NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval) override; \
  NS_IMETHOD GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags) override; \
  NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) override; \
  NS_IMETHOD GetHasTags(bool *aHasTags) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITAGGINGSERVICE(_to) \
  NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) override { return _to TagURI(aURI, aTags); } \
  NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) override { return _to UntagURI(aURI, aTags); } \
  NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval) override { return _to GetURIsForTag(aTag, _retval); } \
  NS_IMETHOD GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags) override { return _to GetTagsForURI(aURI, length, aTags); } \
  NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) override { return _to GetAllTags(aAllTags); } \
  NS_IMETHOD GetHasTags(bool *aHasTags) override { return _to GetHasTags(aHasTags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITAGGINGSERVICE(_to) \
  NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TagURI(aURI, aTags); } \
  NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UntagURI(aURI, aTags); } \
  NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURIsForTag(aTag, _retval); } \
  NS_IMETHOD GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagsForURI(aURI, length, aTags); } \
  NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllTags(aAllTags); } \
  NS_IMETHOD GetHasTags(bool *aHasTags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasTags(aHasTags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaggingService : public nsITaggingService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITAGGINGSERVICE

  nsTaggingService();

private:
  ~nsTaggingService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTaggingService, nsITaggingService)

nsTaggingService::nsTaggingService()
{
  /* member initializers and constructor code */
}

nsTaggingService::~nsTaggingService()
{
  /* destructor code */
}

/* void tagURI (in nsIURI aURI, in nsIVariant aTags); */
NS_IMETHODIMP nsTaggingService::TagURI(nsIURI *aURI, nsIVariant *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void untagURI (in nsIURI aURI, in nsIVariant aTags); */
NS_IMETHODIMP nsTaggingService::UntagURI(nsIURI *aURI, nsIVariant *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getURIsForTag (in AString aTag); */
NS_IMETHODIMP nsTaggingService::GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTagsForURI (in nsIURI aURI, [optional] out unsigned long length, [array, size_is (length), retval] out wstring aTags); */
NS_IMETHODIMP nsTaggingService::GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant allTags; */
NS_IMETHODIMP nsTaggingService::GetAllTags(nsIVariant * *aAllTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasTags; */
NS_IMETHODIMP nsTaggingService::GetHasTags(bool *aHasTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define TAGGING_SERVICE_CID "@mozilla.org/browser/tagging-service;1"

#endif /* __gen_nsITaggingService_h__ */
