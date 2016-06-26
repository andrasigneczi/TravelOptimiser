/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIDownloadPlatform.idl
 */

#ifndef __gen_mozIDownloadPlatform_h__
#define __gen_mozIDownloadPlatform_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    mozIDownloadPlatform */
#define MOZIDOWNLOADPLATFORM_IID_STR "9f556e4a-d9b3-46c3-9f8f-d0db1ac6c8c1"

#define MOZIDOWNLOADPLATFORM_IID \
  {0x9f556e4a, 0xd9b3, 0x46c3, \
    { 0x9f, 0x8f, 0xd0, 0xdb, 0x1a, 0xc6, 0xc8, 0xc1 }}

class NS_NO_VTABLE mozIDownloadPlatform : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIDOWNLOADPLATFORM_IID)

  /* void downloadDone (in nsIURI aSource, in nsIFile aTarget, in ACString aContentType, in boolean aIsPrivate); */
  NS_IMETHOD DownloadDone(nsIURI *aSource, nsIFile *aTarget, const nsACString & aContentType, bool aIsPrivate) = 0;

  enum {
    ZONE_MY_COMPUTER = 0U,
    ZONE_INTRANET = 1U,
    ZONE_TRUSTED = 2U,
    ZONE_INTERNET = 3U,
    ZONE_RESTRICTED = 4U
  };

  /* unsigned long mapUrlToZone (in AString aURL); */
  NS_IMETHOD MapUrlToZone(const nsAString & aURL, uint32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIDownloadPlatform, MOZIDOWNLOADPLATFORM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIDOWNLOADPLATFORM \
  NS_IMETHOD DownloadDone(nsIURI *aSource, nsIFile *aTarget, const nsACString & aContentType, bool aIsPrivate) override; \
  NS_IMETHOD MapUrlToZone(const nsAString & aURL, uint32_t *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIDOWNLOADPLATFORM(_to) \
  NS_IMETHOD DownloadDone(nsIURI *aSource, nsIFile *aTarget, const nsACString & aContentType, bool aIsPrivate) override { return _to DownloadDone(aSource, aTarget, aContentType, aIsPrivate); } \
  NS_IMETHOD MapUrlToZone(const nsAString & aURL, uint32_t *_retval) override { return _to MapUrlToZone(aURL, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIDOWNLOADPLATFORM(_to) \
  NS_IMETHOD DownloadDone(nsIURI *aSource, nsIFile *aTarget, const nsACString & aContentType, bool aIsPrivate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DownloadDone(aSource, aTarget, aContentType, aIsPrivate); } \
  NS_IMETHOD MapUrlToZone(const nsAString & aURL, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MapUrlToZone(aURL, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIDownloadPlatform
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIDOWNLOADPLATFORM

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, mozIDownloadPlatform)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void downloadDone (in nsIURI aSource, in nsIFile aTarget, in ACString aContentType, in boolean aIsPrivate); */
NS_IMETHODIMP _MYCLASS_::DownloadDone(nsIURI *aSource, nsIFile *aTarget, const nsACString & aContentType, bool aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long mapUrlToZone (in AString aURL); */
NS_IMETHODIMP _MYCLASS_::MapUrlToZone(const nsAString & aURL, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIDownloadPlatform_h__ */
