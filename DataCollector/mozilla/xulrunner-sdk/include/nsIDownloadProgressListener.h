/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDownloadProgressListener.idl
 */

#ifndef __gen_nsIDownloadProgressListener_h__
#define __gen_nsIDownloadProgressListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIWebProgress; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDownload; /* forward declaration */

class nsIDOMDocument; /* forward declaration */


/* starting interface:    nsIDownloadProgressListener */
#define NS_IDOWNLOADPROGRESSLISTENER_IID_STR "7acb07ea-cac2-4c15-a3ad-23aaa789ed51"

#define NS_IDOWNLOADPROGRESSLISTENER_IID \
  {0x7acb07ea, 0xcac2, 0x4c15, \
    { 0xa3, 0xad, 0x23, 0xaa, 0xa7, 0x89, 0xed, 0x51 }}

class NS_NO_VTABLE nsIDownloadProgressListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADPROGRESSLISTENER_IID)

  /* attribute nsIDOMDocument document; */
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) = 0;
  NS_IMETHOD SetDocument(nsIDOMDocument *aDocument) = 0;

  /* void onDownloadStateChange (in short aState, in nsIDownload aDownload); */
  NS_IMETHOD OnDownloadStateChange(int16_t aState, nsIDownload *aDownload) = 0;

  /* void onStateChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in unsigned long aStateFlags, in nsresult aStatus, in nsIDownload aDownload); */
  NS_IMETHOD OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus, nsIDownload *aDownload) = 0;

  /* void onProgressChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in long long aCurSelfProgress, in long long aMaxSelfProgress, in long long aCurTotalProgress, in long long aMaxTotalProgress, in nsIDownload aDownload); */
  NS_IMETHOD OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress, nsIDownload *aDownload) = 0;

  /* void onSecurityChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in unsigned long aState, in nsIDownload aDownload); */
  NS_IMETHOD OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState, nsIDownload *aDownload) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloadProgressListener, NS_IDOWNLOADPROGRESSLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADPROGRESSLISTENER \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override; \
  NS_IMETHOD SetDocument(nsIDOMDocument *aDocument) override; \
  NS_IMETHOD OnDownloadStateChange(int16_t aState, nsIDownload *aDownload) override; \
  NS_IMETHOD OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus, nsIDownload *aDownload) override; \
  NS_IMETHOD OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress, nsIDownload *aDownload) override; \
  NS_IMETHOD OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState, nsIDownload *aDownload) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADPROGRESSLISTENER(_to) \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override { return _to GetDocument(aDocument); } \
  NS_IMETHOD SetDocument(nsIDOMDocument *aDocument) override { return _to SetDocument(aDocument); } \
  NS_IMETHOD OnDownloadStateChange(int16_t aState, nsIDownload *aDownload) override { return _to OnDownloadStateChange(aState, aDownload); } \
  NS_IMETHOD OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus, nsIDownload *aDownload) override { return _to OnStateChange(aWebProgress, aRequest, aStateFlags, aStatus, aDownload); } \
  NS_IMETHOD OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress, nsIDownload *aDownload) override { return _to OnProgressChange(aWebProgress, aRequest, aCurSelfProgress, aMaxSelfProgress, aCurTotalProgress, aMaxTotalProgress, aDownload); } \
  NS_IMETHOD OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState, nsIDownload *aDownload) override { return _to OnSecurityChange(aWebProgress, aRequest, aState, aDownload); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADPROGRESSLISTENER(_to) \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD SetDocument(nsIDOMDocument *aDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocument(aDocument); } \
  NS_IMETHOD OnDownloadStateChange(int16_t aState, nsIDownload *aDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDownloadStateChange(aState, aDownload); } \
  NS_IMETHOD OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus, nsIDownload *aDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStateChange(aWebProgress, aRequest, aStateFlags, aStatus, aDownload); } \
  NS_IMETHOD OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress, nsIDownload *aDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProgressChange(aWebProgress, aRequest, aCurSelfProgress, aMaxSelfProgress, aCurTotalProgress, aMaxTotalProgress, aDownload); } \
  NS_IMETHOD OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState, nsIDownload *aDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSecurityChange(aWebProgress, aRequest, aState, aDownload); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloadProgressListener : public nsIDownloadProgressListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADPROGRESSLISTENER

  nsDownloadProgressListener();

private:
  ~nsDownloadProgressListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDownloadProgressListener, nsIDownloadProgressListener)

nsDownloadProgressListener::nsDownloadProgressListener()
{
  /* member initializers and constructor code */
}

nsDownloadProgressListener::~nsDownloadProgressListener()
{
  /* destructor code */
}

/* attribute nsIDOMDocument document; */
NS_IMETHODIMP nsDownloadProgressListener::GetDocument(nsIDOMDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDownloadProgressListener::SetDocument(nsIDOMDocument *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDownloadStateChange (in short aState, in nsIDownload aDownload); */
NS_IMETHODIMP nsDownloadProgressListener::OnDownloadStateChange(int16_t aState, nsIDownload *aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStateChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in unsigned long aStateFlags, in nsresult aStatus, in nsIDownload aDownload); */
NS_IMETHODIMP nsDownloadProgressListener::OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus, nsIDownload *aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onProgressChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in long long aCurSelfProgress, in long long aMaxSelfProgress, in long long aCurTotalProgress, in long long aMaxTotalProgress, in nsIDownload aDownload); */
NS_IMETHODIMP nsDownloadProgressListener::OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int64_t aCurSelfProgress, int64_t aMaxSelfProgress, int64_t aCurTotalProgress, int64_t aMaxTotalProgress, nsIDownload *aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSecurityChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in unsigned long aState, in nsIDownload aDownload); */
NS_IMETHODIMP nsDownloadProgressListener::OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState, nsIDownload *aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDownloadProgressListener_h__ */
