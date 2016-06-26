/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUrlClassifierStreamUpdater.idl
 */

#ifndef __gen_nsIUrlClassifierStreamUpdater_h__
#define __gen_nsIUrlClassifierStreamUpdater_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIUrlClassifierDBService_h__
#include "nsIUrlClassifierDBService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUrlClassifierStreamUpdater */
#define NS_IURLCLASSIFIERSTREAMUPDATER_IID_STR "e1797597-f4d6-4dd3-a1e1-745ad352cd80"

#define NS_IURLCLASSIFIERSTREAMUPDATER_IID \
  {0xe1797597, 0xf4d6, 0x4dd3, \
    { 0xa1, 0xe1, 0x74, 0x5a, 0xd3, 0x52, 0xcd, 0x80 }}

class NS_NO_VTABLE nsIUrlClassifierStreamUpdater : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERSTREAMUPDATER_IID)

  /* boolean downloadUpdates (in ACString aRequestTables, in ACString aRequestBody, in ACString aUpdateUrl, in nsIUrlClassifierCallback aSuccessCallback, in nsIUrlClassifierCallback aUpdateErrorCallback, in nsIUrlClassifierCallback aDownloadErrorCallback); */
  NS_IMETHOD DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, const nsACString & aUpdateUrl, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierStreamUpdater, NS_IURLCLASSIFIERSTREAMUPDATER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERSTREAMUPDATER \
  NS_IMETHOD DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, const nsACString & aUpdateUrl, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERSTREAMUPDATER(_to) \
  NS_IMETHOD DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, const nsACString & aUpdateUrl, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval) override { return _to DownloadUpdates(aRequestTables, aRequestBody, aUpdateUrl, aSuccessCallback, aUpdateErrorCallback, aDownloadErrorCallback, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERSTREAMUPDATER(_to) \
  NS_IMETHOD DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, const nsACString & aUpdateUrl, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DownloadUpdates(aRequestTables, aRequestBody, aUpdateUrl, aSuccessCallback, aUpdateErrorCallback, aDownloadErrorCallback, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierStreamUpdater : public nsIUrlClassifierStreamUpdater
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERSTREAMUPDATER

  nsUrlClassifierStreamUpdater();

private:
  ~nsUrlClassifierStreamUpdater();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUrlClassifierStreamUpdater, nsIUrlClassifierStreamUpdater)

nsUrlClassifierStreamUpdater::nsUrlClassifierStreamUpdater()
{
  /* member initializers and constructor code */
}

nsUrlClassifierStreamUpdater::~nsUrlClassifierStreamUpdater()
{
  /* destructor code */
}

/* boolean downloadUpdates (in ACString aRequestTables, in ACString aRequestBody, in ACString aUpdateUrl, in nsIUrlClassifierCallback aSuccessCallback, in nsIUrlClassifierCallback aUpdateErrorCallback, in nsIUrlClassifierCallback aDownloadErrorCallback); */
NS_IMETHODIMP nsUrlClassifierStreamUpdater::DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, const nsACString & aUpdateUrl, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUrlClassifierStreamUpdater_h__ */
