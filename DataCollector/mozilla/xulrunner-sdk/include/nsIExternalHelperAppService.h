/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIExternalHelperAppService.idl
 */

#ifndef __gen_nsIExternalHelperAppService_h__
#define __gen_nsIExternalHelperAppService_h__


#ifndef __gen_nsICancelable_h__
#include "nsICancelable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsIStreamListener; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIMIMEInfo; /* forward declaration */

class nsIWebProgressListener2; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIExternalHelperAppService */
#define NS_IEXTERNALHELPERAPPSERVICE_IID_STR "1e4f3ae1-b737-431f-a95d-31fa8da70199"

#define NS_IEXTERNALHELPERAPPSERVICE_IID \
  {0x1e4f3ae1, 0xb737, 0x431f, \
    { 0xa9, 0x5d, 0x31, 0xfa, 0x8d, 0xa7, 0x01, 0x99 }}

class NS_NO_VTABLE nsIExternalHelperAppService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXTERNALHELPERAPPSERVICE_IID)

  /* nsIStreamListener doContent (in ACString aMimeContentType, in nsIRequest aRequest, in nsIInterfaceRequestor aContentContext, in boolean aForceSave, [optional] in nsIInterfaceRequestor aWindowContext); */
  NS_IMETHOD DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aContentContext, bool aForceSave, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval) = 0;

  /* boolean applyDecodingForExtension (in AUTF8String aExtension, in ACString aEncodingType); */
  NS_IMETHOD ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExternalHelperAppService, NS_IEXTERNALHELPERAPPSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXTERNALHELPERAPPSERVICE \
  NS_IMETHOD DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aContentContext, bool aForceSave, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval) override; \
  NS_IMETHOD ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXTERNALHELPERAPPSERVICE(_to) \
  NS_IMETHOD DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aContentContext, bool aForceSave, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval) override { return _to DoContent(aMimeContentType, aRequest, aContentContext, aForceSave, aWindowContext, _retval); } \
  NS_IMETHOD ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, bool *_retval) override { return _to ApplyDecodingForExtension(aExtension, aEncodingType, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXTERNALHELPERAPPSERVICE(_to) \
  NS_IMETHOD DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aContentContext, bool aForceSave, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DoContent(aMimeContentType, aRequest, aContentContext, aForceSave, aWindowContext, _retval); } \
  NS_IMETHOD ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplyDecodingForExtension(aExtension, aEncodingType, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExternalHelperAppService : public nsIExternalHelperAppService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXTERNALHELPERAPPSERVICE

  nsExternalHelperAppService();

private:
  ~nsExternalHelperAppService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsExternalHelperAppService, nsIExternalHelperAppService)

nsExternalHelperAppService::nsExternalHelperAppService()
{
  /* member initializers and constructor code */
}

nsExternalHelperAppService::~nsExternalHelperAppService()
{
  /* destructor code */
}

/* nsIStreamListener doContent (in ACString aMimeContentType, in nsIRequest aRequest, in nsIInterfaceRequestor aContentContext, in boolean aForceSave, [optional] in nsIInterfaceRequestor aWindowContext); */
NS_IMETHODIMP nsExternalHelperAppService::DoContent(const nsACString & aMimeContentType, nsIRequest *aRequest, nsIInterfaceRequestor *aContentContext, bool aForceSave, nsIInterfaceRequestor *aWindowContext, nsIStreamListener * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean applyDecodingForExtension (in AUTF8String aExtension, in ACString aEncodingType); */
NS_IMETHODIMP nsExternalHelperAppService::ApplyDecodingForExtension(const nsACString & aExtension, const nsACString & aEncodingType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsPIExternalAppLauncher */
#define NS_PIEXTERNALAPPLAUNCHER_IID_STR "6613e2e7-feab-4e3a-bb1f-b03200d544ec"

#define NS_PIEXTERNALAPPLAUNCHER_IID \
  {0x6613e2e7, 0xfeab, 0x4e3a, \
    { 0xbb, 0x1f, 0xb0, 0x32, 0x00, 0xd5, 0x44, 0xec }}

class NS_NO_VTABLE nsPIExternalAppLauncher : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIEXTERNALAPPLAUNCHER_IID)

  /* void deleteTemporaryFileOnExit (in nsIFile aTemporaryFile); */
  NS_IMETHOD DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile) = 0;

  /* void deleteTemporaryPrivateFileWhenPossible (in nsIFile aTemporaryFile); */
  NS_IMETHOD DeleteTemporaryPrivateFileWhenPossible(nsIFile *aTemporaryFile) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIExternalAppLauncher, NS_PIEXTERNALAPPLAUNCHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIEXTERNALAPPLAUNCHER \
  NS_IMETHOD DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile) override; \
  NS_IMETHOD DeleteTemporaryPrivateFileWhenPossible(nsIFile *aTemporaryFile) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIEXTERNALAPPLAUNCHER(_to) \
  NS_IMETHOD DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile) override { return _to DeleteTemporaryFileOnExit(aTemporaryFile); } \
  NS_IMETHOD DeleteTemporaryPrivateFileWhenPossible(nsIFile *aTemporaryFile) override { return _to DeleteTemporaryPrivateFileWhenPossible(aTemporaryFile); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIEXTERNALAPPLAUNCHER(_to) \
  NS_IMETHOD DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTemporaryFileOnExit(aTemporaryFile); } \
  NS_IMETHOD DeleteTemporaryPrivateFileWhenPossible(nsIFile *aTemporaryFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTemporaryPrivateFileWhenPossible(aTemporaryFile); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIExternalAppLauncher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIEXTERNALAPPLAUNCHER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, nsPIExternalAppLauncher)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void deleteTemporaryFileOnExit (in nsIFile aTemporaryFile); */
NS_IMETHODIMP _MYCLASS_::DeleteTemporaryFileOnExit(nsIFile *aTemporaryFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTemporaryPrivateFileWhenPossible (in nsIFile aTemporaryFile); */
NS_IMETHODIMP _MYCLASS_::DeleteTemporaryPrivateFileWhenPossible(nsIFile *aTemporaryFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHelperAppLauncher */
#define NS_IHELPERAPPLAUNCHER_IID_STR "acf2a516-7d7f-4771-8b22-6c4a559c088e"

#define NS_IHELPERAPPLAUNCHER_IID \
  {0xacf2a516, 0x7d7f, 0x4771, \
    { 0x8b, 0x22, 0x6c, 0x4a, 0x55, 0x9c, 0x08, 0x8e }}

class NS_NO_VTABLE nsIHelperAppLauncher : public nsICancelable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHELPERAPPLAUNCHER_IID)

  /* readonly attribute nsIMIMEInfo MIMEInfo; */
  NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) = 0;

  /* readonly attribute nsIURI source; */
  NS_IMETHOD GetSource(nsIURI * *aSource) = 0;

  /* readonly attribute AString suggestedFileName; */
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) = 0;

  /* void saveToDisk (in nsIFile aNewFileLocation, in boolean aRememberThisPreference); */
  NS_IMETHOD SaveToDisk(nsIFile *aNewFileLocation, bool aRememberThisPreference) = 0;

  /* void launchWithApplication (in nsIFile aApplication, in boolean aRememberThisPreference); */
  NS_IMETHOD LaunchWithApplication(nsIFile *aApplication, bool aRememberThisPreference) = 0;

  /* void saveDestinationAvailable (in nsIFile aFile); */
  NS_IMETHOD SaveDestinationAvailable(nsIFile *aFile) = 0;

  /* void setWebProgressListener (in nsIWebProgressListener2 aWebProgressListener); */
  NS_IMETHOD SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener) = 0;

  /* readonly attribute nsIFile targetFile; */
  NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) = 0;

  /* readonly attribute boolean targetFileIsExecutable; */
  NS_IMETHOD GetTargetFileIsExecutable(bool *aTargetFileIsExecutable) = 0;

  /* readonly attribute PRTime timeDownloadStarted; */
  NS_IMETHOD GetTimeDownloadStarted(PRTime *aTimeDownloadStarted) = 0;

  /* readonly attribute int64_t contentLength; */
  NS_IMETHOD GetContentLength(int64_t *aContentLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHelperAppLauncher, NS_IHELPERAPPLAUNCHER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHELPERAPPLAUNCHER \
  NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) override; \
  NS_IMETHOD GetSource(nsIURI * *aSource) override; \
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) override; \
  NS_IMETHOD SaveToDisk(nsIFile *aNewFileLocation, bool aRememberThisPreference) override; \
  NS_IMETHOD LaunchWithApplication(nsIFile *aApplication, bool aRememberThisPreference) override; \
  NS_IMETHOD SaveDestinationAvailable(nsIFile *aFile) override; \
  NS_IMETHOD SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener) override; \
  NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) override; \
  NS_IMETHOD GetTargetFileIsExecutable(bool *aTargetFileIsExecutable) override; \
  NS_IMETHOD GetTimeDownloadStarted(PRTime *aTimeDownloadStarted) override; \
  NS_IMETHOD GetContentLength(int64_t *aContentLength) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHELPERAPPLAUNCHER(_to) \
  NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) override { return _to GetMIMEInfo(aMIMEInfo); } \
  NS_IMETHOD GetSource(nsIURI * *aSource) override { return _to GetSource(aSource); } \
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) override { return _to GetSuggestedFileName(aSuggestedFileName); } \
  NS_IMETHOD SaveToDisk(nsIFile *aNewFileLocation, bool aRememberThisPreference) override { return _to SaveToDisk(aNewFileLocation, aRememberThisPreference); } \
  NS_IMETHOD LaunchWithApplication(nsIFile *aApplication, bool aRememberThisPreference) override { return _to LaunchWithApplication(aApplication, aRememberThisPreference); } \
  NS_IMETHOD SaveDestinationAvailable(nsIFile *aFile) override { return _to SaveDestinationAvailable(aFile); } \
  NS_IMETHOD SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener) override { return _to SetWebProgressListener(aWebProgressListener); } \
  NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) override { return _to GetTargetFile(aTargetFile); } \
  NS_IMETHOD GetTargetFileIsExecutable(bool *aTargetFileIsExecutable) override { return _to GetTargetFileIsExecutable(aTargetFileIsExecutable); } \
  NS_IMETHOD GetTimeDownloadStarted(PRTime *aTimeDownloadStarted) override { return _to GetTimeDownloadStarted(aTimeDownloadStarted); } \
  NS_IMETHOD GetContentLength(int64_t *aContentLength) override { return _to GetContentLength(aContentLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHELPERAPPLAUNCHER(_to) \
  NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMEInfo(aMIMEInfo); } \
  NS_IMETHOD GetSource(nsIURI * *aSource) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuggestedFileName(aSuggestedFileName); } \
  NS_IMETHOD SaveToDisk(nsIFile *aNewFileLocation, bool aRememberThisPreference) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveToDisk(aNewFileLocation, aRememberThisPreference); } \
  NS_IMETHOD LaunchWithApplication(nsIFile *aApplication, bool aRememberThisPreference) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LaunchWithApplication(aApplication, aRememberThisPreference); } \
  NS_IMETHOD SaveDestinationAvailable(nsIFile *aFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveDestinationAvailable(aFile); } \
  NS_IMETHOD SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWebProgressListener(aWebProgressListener); } \
  NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetFile(aTargetFile); } \
  NS_IMETHOD GetTargetFileIsExecutable(bool *aTargetFileIsExecutable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetFileIsExecutable(aTargetFileIsExecutable); } \
  NS_IMETHOD GetTimeDownloadStarted(PRTime *aTimeDownloadStarted) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeDownloadStarted(aTimeDownloadStarted); } \
  NS_IMETHOD GetContentLength(int64_t *aContentLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentLength(aContentLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHelperAppLauncher : public nsIHelperAppLauncher
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHELPERAPPLAUNCHER

  nsHelperAppLauncher();

private:
  ~nsHelperAppLauncher();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsHelperAppLauncher, nsIHelperAppLauncher)

nsHelperAppLauncher::nsHelperAppLauncher()
{
  /* member initializers and constructor code */
}

nsHelperAppLauncher::~nsHelperAppLauncher()
{
  /* destructor code */
}

/* readonly attribute nsIMIMEInfo MIMEInfo; */
NS_IMETHODIMP nsHelperAppLauncher::GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI source; */
NS_IMETHODIMP nsHelperAppLauncher::GetSource(nsIURI * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString suggestedFileName; */
NS_IMETHODIMP nsHelperAppLauncher::GetSuggestedFileName(nsAString & aSuggestedFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveToDisk (in nsIFile aNewFileLocation, in boolean aRememberThisPreference); */
NS_IMETHODIMP nsHelperAppLauncher::SaveToDisk(nsIFile *aNewFileLocation, bool aRememberThisPreference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void launchWithApplication (in nsIFile aApplication, in boolean aRememberThisPreference); */
NS_IMETHODIMP nsHelperAppLauncher::LaunchWithApplication(nsIFile *aApplication, bool aRememberThisPreference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveDestinationAvailable (in nsIFile aFile); */
NS_IMETHODIMP nsHelperAppLauncher::SaveDestinationAvailable(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWebProgressListener (in nsIWebProgressListener2 aWebProgressListener); */
NS_IMETHODIMP nsHelperAppLauncher::SetWebProgressListener(nsIWebProgressListener2 *aWebProgressListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile targetFile; */
NS_IMETHODIMP nsHelperAppLauncher::GetTargetFile(nsIFile * *aTargetFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean targetFileIsExecutable; */
NS_IMETHODIMP nsHelperAppLauncher::GetTargetFileIsExecutable(bool *aTargetFileIsExecutable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime timeDownloadStarted; */
NS_IMETHODIMP nsHelperAppLauncher::GetTimeDownloadStarted(PRTime *aTimeDownloadStarted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t contentLength; */
NS_IMETHODIMP nsHelperAppLauncher::GetContentLength(int64_t *aContentLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExternalHelperAppService_h__ */
