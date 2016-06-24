/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUpdateService.idl
 */

#ifndef __gen_nsIUpdateService_h__
#define __gen_nsIUpdateService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsIRequestObserver; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIXMLHttpRequest; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsIUpdatePatch */
#define NS_IUPDATEPATCH_IID_STR "dc8fb8a9-3a53-4031-9469-2a5197ea30e7"

#define NS_IUPDATEPATCH_IID \
  {0xdc8fb8a9, 0x3a53, 0x4031, \
    { 0x94, 0x69, 0x2a, 0x51, 0x97, 0xea, 0x30, 0xe7 }}

class NS_NO_VTABLE nsIUpdatePatch : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATEPATCH_IID)

  /* attribute AString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute AString URL; */
  NS_IMETHOD GetURL(nsAString & aURL) = 0;
  NS_IMETHOD SetURL(const nsAString & aURL) = 0;

  /* attribute AString finalURL; */
  NS_IMETHOD GetFinalURL(nsAString & aFinalURL) = 0;
  NS_IMETHOD SetFinalURL(const nsAString & aFinalURL) = 0;

  /* attribute AString hashFunction; */
  NS_IMETHOD GetHashFunction(nsAString & aHashFunction) = 0;
  NS_IMETHOD SetHashFunction(const nsAString & aHashFunction) = 0;

  /* attribute AString hashValue; */
  NS_IMETHOD GetHashValue(nsAString & aHashValue) = 0;
  NS_IMETHOD SetHashValue(const nsAString & aHashValue) = 0;

  /* attribute unsigned long size; */
  NS_IMETHOD GetSize(uint32_t *aSize) = 0;
  NS_IMETHOD SetSize(uint32_t aSize) = 0;

  /* attribute AString state; */
  NS_IMETHOD GetState(nsAString & aState) = 0;
  NS_IMETHOD SetState(const nsAString & aState) = 0;

  /* attribute boolean selected; */
  NS_IMETHOD GetSelected(bool *aSelected) = 0;
  NS_IMETHOD SetSelected(bool aSelected) = 0;

  /* nsIDOMElement serialize (in nsIDOMDocument updates); */
  NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdatePatch, NS_IUPDATEPATCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATEPATCH \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD SetType(const nsAString & aType) override; \
  NS_IMETHOD GetURL(nsAString & aURL) override; \
  NS_IMETHOD SetURL(const nsAString & aURL) override; \
  NS_IMETHOD GetFinalURL(nsAString & aFinalURL) override; \
  NS_IMETHOD SetFinalURL(const nsAString & aFinalURL) override; \
  NS_IMETHOD GetHashFunction(nsAString & aHashFunction) override; \
  NS_IMETHOD SetHashFunction(const nsAString & aHashFunction) override; \
  NS_IMETHOD GetHashValue(nsAString & aHashValue) override; \
  NS_IMETHOD SetHashValue(const nsAString & aHashValue) override; \
  NS_IMETHOD GetSize(uint32_t *aSize) override; \
  NS_IMETHOD SetSize(uint32_t aSize) override; \
  NS_IMETHOD GetState(nsAString & aState) override; \
  NS_IMETHOD SetState(const nsAString & aState) override; \
  NS_IMETHOD GetSelected(bool *aSelected) override; \
  NS_IMETHOD SetSelected(bool aSelected) override; \
  NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATEPATCH(_to) \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return _to SetType(aType); } \
  NS_IMETHOD GetURL(nsAString & aURL) override { return _to GetURL(aURL); } \
  NS_IMETHOD SetURL(const nsAString & aURL) override { return _to SetURL(aURL); } \
  NS_IMETHOD GetFinalURL(nsAString & aFinalURL) override { return _to GetFinalURL(aFinalURL); } \
  NS_IMETHOD SetFinalURL(const nsAString & aFinalURL) override { return _to SetFinalURL(aFinalURL); } \
  NS_IMETHOD GetHashFunction(nsAString & aHashFunction) override { return _to GetHashFunction(aHashFunction); } \
  NS_IMETHOD SetHashFunction(const nsAString & aHashFunction) override { return _to SetHashFunction(aHashFunction); } \
  NS_IMETHOD GetHashValue(nsAString & aHashValue) override { return _to GetHashValue(aHashValue); } \
  NS_IMETHOD SetHashValue(const nsAString & aHashValue) override { return _to SetHashValue(aHashValue); } \
  NS_IMETHOD GetSize(uint32_t *aSize) override { return _to GetSize(aSize); } \
  NS_IMETHOD SetSize(uint32_t aSize) override { return _to SetSize(aSize); } \
  NS_IMETHOD GetState(nsAString & aState) override { return _to GetState(aState); } \
  NS_IMETHOD SetState(const nsAString & aState) override { return _to SetState(aState); } \
  NS_IMETHOD GetSelected(bool *aSelected) override { return _to GetSelected(aSelected); } \
  NS_IMETHOD SetSelected(bool aSelected) override { return _to SetSelected(aSelected); } \
  NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval) override { return _to Serialize(updates, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATEPATCH(_to) \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetURL(nsAString & aURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURL(aURL); } \
  NS_IMETHOD SetURL(const nsAString & aURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetURL(aURL); } \
  NS_IMETHOD GetFinalURL(nsAString & aFinalURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFinalURL(aFinalURL); } \
  NS_IMETHOD SetFinalURL(const nsAString & aFinalURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFinalURL(aFinalURL); } \
  NS_IMETHOD GetHashFunction(nsAString & aHashFunction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHashFunction(aHashFunction); } \
  NS_IMETHOD SetHashFunction(const nsAString & aHashFunction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHashFunction(aHashFunction); } \
  NS_IMETHOD GetHashValue(nsAString & aHashValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHashValue(aHashValue); } \
  NS_IMETHOD SetHashValue(const nsAString & aHashValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHashValue(aHashValue); } \
  NS_IMETHOD GetSize(uint32_t *aSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_IMETHOD SetSize(uint32_t aSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSize(aSize); } \
  NS_IMETHOD GetState(nsAString & aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD SetState(const nsAString & aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetState(aState); } \
  NS_IMETHOD GetSelected(bool *aSelected) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelected(aSelected); } \
  NS_IMETHOD SetSelected(bool aSelected) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelected(aSelected); } \
  NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Serialize(updates, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdatePatch : public nsIUpdatePatch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATEPATCH

  nsUpdatePatch();

private:
  ~nsUpdatePatch();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUpdatePatch, nsIUpdatePatch)

nsUpdatePatch::nsUpdatePatch()
{
  /* member initializers and constructor code */
}

nsUpdatePatch::~nsUpdatePatch()
{
  /* destructor code */
}

/* attribute AString type; */
NS_IMETHODIMP nsUpdatePatch::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString URL; */
NS_IMETHODIMP nsUpdatePatch::GetURL(nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetURL(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString finalURL; */
NS_IMETHODIMP nsUpdatePatch::GetFinalURL(nsAString & aFinalURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetFinalURL(const nsAString & aFinalURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString hashFunction; */
NS_IMETHODIMP nsUpdatePatch::GetHashFunction(nsAString & aHashFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetHashFunction(const nsAString & aHashFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString hashValue; */
NS_IMETHODIMP nsUpdatePatch::GetHashValue(nsAString & aHashValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetHashValue(const nsAString & aHashValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long size; */
NS_IMETHODIMP nsUpdatePatch::GetSize(uint32_t *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetSize(uint32_t aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString state; */
NS_IMETHODIMP nsUpdatePatch::GetState(nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetState(const nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean selected; */
NS_IMETHODIMP nsUpdatePatch::GetSelected(bool *aSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdatePatch::SetSelected(bool aSelected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement serialize (in nsIDOMDocument updates); */
NS_IMETHODIMP nsUpdatePatch::Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdate */
#define NS_IUPDATE_IID_STR "6b0b7721-6746-443d-8cb0-c6199d7f28a6"

#define NS_IUPDATE_IID \
  {0x6b0b7721, 0x6746, 0x443d, \
    { 0x8c, 0xb0, 0xc6, 0x19, 0x9d, 0x7f, 0x28, 0xa6 }}

class NS_NO_VTABLE nsIUpdate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATE_IID)

  /* attribute AString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute AString displayVersion; */
  NS_IMETHOD GetDisplayVersion(nsAString & aDisplayVersion) = 0;
  NS_IMETHOD SetDisplayVersion(const nsAString & aDisplayVersion) = 0;

  /* attribute AString appVersion; */
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) = 0;
  NS_IMETHOD SetAppVersion(const nsAString & aAppVersion) = 0;

  /* attribute AString platformVersion; */
  NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) = 0;
  NS_IMETHOD SetPlatformVersion(const nsAString & aPlatformVersion) = 0;

  /* attribute AString previousAppVersion; */
  NS_IMETHOD GetPreviousAppVersion(nsAString & aPreviousAppVersion) = 0;
  NS_IMETHOD SetPreviousAppVersion(const nsAString & aPreviousAppVersion) = 0;

  /* attribute AString buildID; */
  NS_IMETHOD GetBuildID(nsAString & aBuildID) = 0;
  NS_IMETHOD SetBuildID(const nsAString & aBuildID) = 0;

  /* attribute AString detailsURL; */
  NS_IMETHOD GetDetailsURL(nsAString & aDetailsURL) = 0;
  NS_IMETHOD SetDetailsURL(const nsAString & aDetailsURL) = 0;

  /* attribute AString billboardURL; */
  NS_IMETHOD GetBillboardURL(nsAString & aBillboardURL) = 0;
  NS_IMETHOD SetBillboardURL(const nsAString & aBillboardURL) = 0;

  /* attribute AString licenseURL; */
  NS_IMETHOD GetLicenseURL(nsAString & aLicenseURL) = 0;
  NS_IMETHOD SetLicenseURL(const nsAString & aLicenseURL) = 0;

  /* attribute AString serviceURL; */
  NS_IMETHOD GetServiceURL(nsAString & aServiceURL) = 0;
  NS_IMETHOD SetServiceURL(const nsAString & aServiceURL) = 0;

  /* attribute AString channel; */
  NS_IMETHOD GetChannel(nsAString & aChannel) = 0;
  NS_IMETHOD SetChannel(const nsAString & aChannel) = 0;

  /* attribute boolean showPrompt; */
  NS_IMETHOD GetShowPrompt(bool *aShowPrompt) = 0;
  NS_IMETHOD SetShowPrompt(bool aShowPrompt) = 0;

  /* attribute boolean showNeverForVersion; */
  NS_IMETHOD GetShowNeverForVersion(bool *aShowNeverForVersion) = 0;
  NS_IMETHOD SetShowNeverForVersion(bool aShowNeverForVersion) = 0;

  /* attribute boolean unsupported; */
  NS_IMETHOD GetUnsupported(bool *aUnsupported) = 0;
  NS_IMETHOD SetUnsupported(bool aUnsupported) = 0;

  /* attribute long long promptWaitTime; */
  NS_IMETHOD GetPromptWaitTime(int64_t *aPromptWaitTime) = 0;
  NS_IMETHOD SetPromptWaitTime(int64_t aPromptWaitTime) = 0;

  /* attribute boolean isCompleteUpdate; */
  NS_IMETHOD GetIsCompleteUpdate(bool *aIsCompleteUpdate) = 0;
  NS_IMETHOD SetIsCompleteUpdate(bool aIsCompleteUpdate) = 0;

  /* attribute boolean isSecurityUpdate; */
  NS_IMETHOD GetIsSecurityUpdate(bool *aIsSecurityUpdate) = 0;
  NS_IMETHOD SetIsSecurityUpdate(bool aIsSecurityUpdate) = 0;

  /* attribute boolean isOSUpdate; */
  NS_IMETHOD GetIsOSUpdate(bool *aIsOSUpdate) = 0;
  NS_IMETHOD SetIsOSUpdate(bool aIsOSUpdate) = 0;

  /* attribute long long installDate; */
  NS_IMETHOD GetInstallDate(int64_t *aInstallDate) = 0;
  NS_IMETHOD SetInstallDate(int64_t aInstallDate) = 0;

  /* attribute AString statusText; */
  NS_IMETHOD GetStatusText(nsAString & aStatusText) = 0;
  NS_IMETHOD SetStatusText(const nsAString & aStatusText) = 0;

  /* readonly attribute nsIUpdatePatch selectedPatch; */
  NS_IMETHOD GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch) = 0;

  /* attribute AString state; */
  NS_IMETHOD GetState(nsAString & aState) = 0;
  NS_IMETHOD SetState(const nsAString & aState) = 0;

  /* attribute long errorCode; */
  NS_IMETHOD GetErrorCode(int32_t *aErrorCode) = 0;
  NS_IMETHOD SetErrorCode(int32_t aErrorCode) = 0;

  /* readonly attribute unsigned long patchCount; */
  NS_IMETHOD GetPatchCount(uint32_t *aPatchCount) = 0;

  /* nsIUpdatePatch getPatchAt (in unsigned long index); */
  NS_IMETHOD GetPatchAt(uint32_t index, nsIUpdatePatch * *_retval) = 0;

  /* nsIDOMElement serialize (in nsIDOMDocument updates); */
  NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdate, NS_IUPDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATE \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD SetType(const nsAString & aType) override; \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD SetName(const nsAString & aName) override; \
  NS_IMETHOD GetDisplayVersion(nsAString & aDisplayVersion) override; \
  NS_IMETHOD SetDisplayVersion(const nsAString & aDisplayVersion) override; \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) override; \
  NS_IMETHOD SetAppVersion(const nsAString & aAppVersion) override; \
  NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) override; \
  NS_IMETHOD SetPlatformVersion(const nsAString & aPlatformVersion) override; \
  NS_IMETHOD GetPreviousAppVersion(nsAString & aPreviousAppVersion) override; \
  NS_IMETHOD SetPreviousAppVersion(const nsAString & aPreviousAppVersion) override; \
  NS_IMETHOD GetBuildID(nsAString & aBuildID) override; \
  NS_IMETHOD SetBuildID(const nsAString & aBuildID) override; \
  NS_IMETHOD GetDetailsURL(nsAString & aDetailsURL) override; \
  NS_IMETHOD SetDetailsURL(const nsAString & aDetailsURL) override; \
  NS_IMETHOD GetBillboardURL(nsAString & aBillboardURL) override; \
  NS_IMETHOD SetBillboardURL(const nsAString & aBillboardURL) override; \
  NS_IMETHOD GetLicenseURL(nsAString & aLicenseURL) override; \
  NS_IMETHOD SetLicenseURL(const nsAString & aLicenseURL) override; \
  NS_IMETHOD GetServiceURL(nsAString & aServiceURL) override; \
  NS_IMETHOD SetServiceURL(const nsAString & aServiceURL) override; \
  NS_IMETHOD GetChannel(nsAString & aChannel) override; \
  NS_IMETHOD SetChannel(const nsAString & aChannel) override; \
  NS_IMETHOD GetShowPrompt(bool *aShowPrompt) override; \
  NS_IMETHOD SetShowPrompt(bool aShowPrompt) override; \
  NS_IMETHOD GetShowNeverForVersion(bool *aShowNeverForVersion) override; \
  NS_IMETHOD SetShowNeverForVersion(bool aShowNeverForVersion) override; \
  NS_IMETHOD GetUnsupported(bool *aUnsupported) override; \
  NS_IMETHOD SetUnsupported(bool aUnsupported) override; \
  NS_IMETHOD GetPromptWaitTime(int64_t *aPromptWaitTime) override; \
  NS_IMETHOD SetPromptWaitTime(int64_t aPromptWaitTime) override; \
  NS_IMETHOD GetIsCompleteUpdate(bool *aIsCompleteUpdate) override; \
  NS_IMETHOD SetIsCompleteUpdate(bool aIsCompleteUpdate) override; \
  NS_IMETHOD GetIsSecurityUpdate(bool *aIsSecurityUpdate) override; \
  NS_IMETHOD SetIsSecurityUpdate(bool aIsSecurityUpdate) override; \
  NS_IMETHOD GetIsOSUpdate(bool *aIsOSUpdate) override; \
  NS_IMETHOD SetIsOSUpdate(bool aIsOSUpdate) override; \
  NS_IMETHOD GetInstallDate(int64_t *aInstallDate) override; \
  NS_IMETHOD SetInstallDate(int64_t aInstallDate) override; \
  NS_IMETHOD GetStatusText(nsAString & aStatusText) override; \
  NS_IMETHOD SetStatusText(const nsAString & aStatusText) override; \
  NS_IMETHOD GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch) override; \
  NS_IMETHOD GetState(nsAString & aState) override; \
  NS_IMETHOD SetState(const nsAString & aState) override; \
  NS_IMETHOD GetErrorCode(int32_t *aErrorCode) override; \
  NS_IMETHOD SetErrorCode(int32_t aErrorCode) override; \
  NS_IMETHOD GetPatchCount(uint32_t *aPatchCount) override; \
  NS_IMETHOD GetPatchAt(uint32_t index, nsIUpdatePatch * *_retval) override; \
  NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATE(_to) \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return _to SetType(aType); } \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return _to SetName(aName); } \
  NS_IMETHOD GetDisplayVersion(nsAString & aDisplayVersion) override { return _to GetDisplayVersion(aDisplayVersion); } \
  NS_IMETHOD SetDisplayVersion(const nsAString & aDisplayVersion) override { return _to SetDisplayVersion(aDisplayVersion); } \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) override { return _to GetAppVersion(aAppVersion); } \
  NS_IMETHOD SetAppVersion(const nsAString & aAppVersion) override { return _to SetAppVersion(aAppVersion); } \
  NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) override { return _to GetPlatformVersion(aPlatformVersion); } \
  NS_IMETHOD SetPlatformVersion(const nsAString & aPlatformVersion) override { return _to SetPlatformVersion(aPlatformVersion); } \
  NS_IMETHOD GetPreviousAppVersion(nsAString & aPreviousAppVersion) override { return _to GetPreviousAppVersion(aPreviousAppVersion); } \
  NS_IMETHOD SetPreviousAppVersion(const nsAString & aPreviousAppVersion) override { return _to SetPreviousAppVersion(aPreviousAppVersion); } \
  NS_IMETHOD GetBuildID(nsAString & aBuildID) override { return _to GetBuildID(aBuildID); } \
  NS_IMETHOD SetBuildID(const nsAString & aBuildID) override { return _to SetBuildID(aBuildID); } \
  NS_IMETHOD GetDetailsURL(nsAString & aDetailsURL) override { return _to GetDetailsURL(aDetailsURL); } \
  NS_IMETHOD SetDetailsURL(const nsAString & aDetailsURL) override { return _to SetDetailsURL(aDetailsURL); } \
  NS_IMETHOD GetBillboardURL(nsAString & aBillboardURL) override { return _to GetBillboardURL(aBillboardURL); } \
  NS_IMETHOD SetBillboardURL(const nsAString & aBillboardURL) override { return _to SetBillboardURL(aBillboardURL); } \
  NS_IMETHOD GetLicenseURL(nsAString & aLicenseURL) override { return _to GetLicenseURL(aLicenseURL); } \
  NS_IMETHOD SetLicenseURL(const nsAString & aLicenseURL) override { return _to SetLicenseURL(aLicenseURL); } \
  NS_IMETHOD GetServiceURL(nsAString & aServiceURL) override { return _to GetServiceURL(aServiceURL); } \
  NS_IMETHOD SetServiceURL(const nsAString & aServiceURL) override { return _to SetServiceURL(aServiceURL); } \
  NS_IMETHOD GetChannel(nsAString & aChannel) override { return _to GetChannel(aChannel); } \
  NS_IMETHOD SetChannel(const nsAString & aChannel) override { return _to SetChannel(aChannel); } \
  NS_IMETHOD GetShowPrompt(bool *aShowPrompt) override { return _to GetShowPrompt(aShowPrompt); } \
  NS_IMETHOD SetShowPrompt(bool aShowPrompt) override { return _to SetShowPrompt(aShowPrompt); } \
  NS_IMETHOD GetShowNeverForVersion(bool *aShowNeverForVersion) override { return _to GetShowNeverForVersion(aShowNeverForVersion); } \
  NS_IMETHOD SetShowNeverForVersion(bool aShowNeverForVersion) override { return _to SetShowNeverForVersion(aShowNeverForVersion); } \
  NS_IMETHOD GetUnsupported(bool *aUnsupported) override { return _to GetUnsupported(aUnsupported); } \
  NS_IMETHOD SetUnsupported(bool aUnsupported) override { return _to SetUnsupported(aUnsupported); } \
  NS_IMETHOD GetPromptWaitTime(int64_t *aPromptWaitTime) override { return _to GetPromptWaitTime(aPromptWaitTime); } \
  NS_IMETHOD SetPromptWaitTime(int64_t aPromptWaitTime) override { return _to SetPromptWaitTime(aPromptWaitTime); } \
  NS_IMETHOD GetIsCompleteUpdate(bool *aIsCompleteUpdate) override { return _to GetIsCompleteUpdate(aIsCompleteUpdate); } \
  NS_IMETHOD SetIsCompleteUpdate(bool aIsCompleteUpdate) override { return _to SetIsCompleteUpdate(aIsCompleteUpdate); } \
  NS_IMETHOD GetIsSecurityUpdate(bool *aIsSecurityUpdate) override { return _to GetIsSecurityUpdate(aIsSecurityUpdate); } \
  NS_IMETHOD SetIsSecurityUpdate(bool aIsSecurityUpdate) override { return _to SetIsSecurityUpdate(aIsSecurityUpdate); } \
  NS_IMETHOD GetIsOSUpdate(bool *aIsOSUpdate) override { return _to GetIsOSUpdate(aIsOSUpdate); } \
  NS_IMETHOD SetIsOSUpdate(bool aIsOSUpdate) override { return _to SetIsOSUpdate(aIsOSUpdate); } \
  NS_IMETHOD GetInstallDate(int64_t *aInstallDate) override { return _to GetInstallDate(aInstallDate); } \
  NS_IMETHOD SetInstallDate(int64_t aInstallDate) override { return _to SetInstallDate(aInstallDate); } \
  NS_IMETHOD GetStatusText(nsAString & aStatusText) override { return _to GetStatusText(aStatusText); } \
  NS_IMETHOD SetStatusText(const nsAString & aStatusText) override { return _to SetStatusText(aStatusText); } \
  NS_IMETHOD GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch) override { return _to GetSelectedPatch(aSelectedPatch); } \
  NS_IMETHOD GetState(nsAString & aState) override { return _to GetState(aState); } \
  NS_IMETHOD SetState(const nsAString & aState) override { return _to SetState(aState); } \
  NS_IMETHOD GetErrorCode(int32_t *aErrorCode) override { return _to GetErrorCode(aErrorCode); } \
  NS_IMETHOD SetErrorCode(int32_t aErrorCode) override { return _to SetErrorCode(aErrorCode); } \
  NS_IMETHOD GetPatchCount(uint32_t *aPatchCount) override { return _to GetPatchCount(aPatchCount); } \
  NS_IMETHOD GetPatchAt(uint32_t index, nsIUpdatePatch * *_retval) override { return _to GetPatchAt(index, _retval); } \
  NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval) override { return _to Serialize(updates, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATE(_to) \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetDisplayVersion(nsAString & aDisplayVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayVersion(aDisplayVersion); } \
  NS_IMETHOD SetDisplayVersion(const nsAString & aDisplayVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayVersion(aDisplayVersion); } \
  NS_IMETHOD GetAppVersion(nsAString & aAppVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppVersion(aAppVersion); } \
  NS_IMETHOD SetAppVersion(const nsAString & aAppVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAppVersion(aAppVersion); } \
  NS_IMETHOD GetPlatformVersion(nsAString & aPlatformVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatformVersion(aPlatformVersion); } \
  NS_IMETHOD SetPlatformVersion(const nsAString & aPlatformVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPlatformVersion(aPlatformVersion); } \
  NS_IMETHOD GetPreviousAppVersion(nsAString & aPreviousAppVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousAppVersion(aPreviousAppVersion); } \
  NS_IMETHOD SetPreviousAppVersion(const nsAString & aPreviousAppVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreviousAppVersion(aPreviousAppVersion); } \
  NS_IMETHOD GetBuildID(nsAString & aBuildID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuildID(aBuildID); } \
  NS_IMETHOD SetBuildID(const nsAString & aBuildID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBuildID(aBuildID); } \
  NS_IMETHOD GetDetailsURL(nsAString & aDetailsURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDetailsURL(aDetailsURL); } \
  NS_IMETHOD SetDetailsURL(const nsAString & aDetailsURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDetailsURL(aDetailsURL); } \
  NS_IMETHOD GetBillboardURL(nsAString & aBillboardURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBillboardURL(aBillboardURL); } \
  NS_IMETHOD SetBillboardURL(const nsAString & aBillboardURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBillboardURL(aBillboardURL); } \
  NS_IMETHOD GetLicenseURL(nsAString & aLicenseURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLicenseURL(aLicenseURL); } \
  NS_IMETHOD SetLicenseURL(const nsAString & aLicenseURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLicenseURL(aLicenseURL); } \
  NS_IMETHOD GetServiceURL(nsAString & aServiceURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceURL(aServiceURL); } \
  NS_IMETHOD SetServiceURL(const nsAString & aServiceURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetServiceURL(aServiceURL); } \
  NS_IMETHOD GetChannel(nsAString & aChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannel(aChannel); } \
  NS_IMETHOD SetChannel(const nsAString & aChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChannel(aChannel); } \
  NS_IMETHOD GetShowPrompt(bool *aShowPrompt) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowPrompt(aShowPrompt); } \
  NS_IMETHOD SetShowPrompt(bool aShowPrompt) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowPrompt(aShowPrompt); } \
  NS_IMETHOD GetShowNeverForVersion(bool *aShowNeverForVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowNeverForVersion(aShowNeverForVersion); } \
  NS_IMETHOD SetShowNeverForVersion(bool aShowNeverForVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowNeverForVersion(aShowNeverForVersion); } \
  NS_IMETHOD GetUnsupported(bool *aUnsupported) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnsupported(aUnsupported); } \
  NS_IMETHOD SetUnsupported(bool aUnsupported) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnsupported(aUnsupported); } \
  NS_IMETHOD GetPromptWaitTime(int64_t *aPromptWaitTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPromptWaitTime(aPromptWaitTime); } \
  NS_IMETHOD SetPromptWaitTime(int64_t aPromptWaitTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPromptWaitTime(aPromptWaitTime); } \
  NS_IMETHOD GetIsCompleteUpdate(bool *aIsCompleteUpdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsCompleteUpdate(aIsCompleteUpdate); } \
  NS_IMETHOD SetIsCompleteUpdate(bool aIsCompleteUpdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsCompleteUpdate(aIsCompleteUpdate); } \
  NS_IMETHOD GetIsSecurityUpdate(bool *aIsSecurityUpdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSecurityUpdate(aIsSecurityUpdate); } \
  NS_IMETHOD SetIsSecurityUpdate(bool aIsSecurityUpdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsSecurityUpdate(aIsSecurityUpdate); } \
  NS_IMETHOD GetIsOSUpdate(bool *aIsOSUpdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsOSUpdate(aIsOSUpdate); } \
  NS_IMETHOD SetIsOSUpdate(bool aIsOSUpdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsOSUpdate(aIsOSUpdate); } \
  NS_IMETHOD GetInstallDate(int64_t *aInstallDate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstallDate(aInstallDate); } \
  NS_IMETHOD SetInstallDate(int64_t aInstallDate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInstallDate(aInstallDate); } \
  NS_IMETHOD GetStatusText(nsAString & aStatusText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatusText(aStatusText); } \
  NS_IMETHOD SetStatusText(const nsAString & aStatusText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStatusText(aStatusText); } \
  NS_IMETHOD GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedPatch(aSelectedPatch); } \
  NS_IMETHOD GetState(nsAString & aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD SetState(const nsAString & aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetState(aState); } \
  NS_IMETHOD GetErrorCode(int32_t *aErrorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorCode(aErrorCode); } \
  NS_IMETHOD SetErrorCode(int32_t aErrorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetErrorCode(aErrorCode); } \
  NS_IMETHOD GetPatchCount(uint32_t *aPatchCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPatchCount(aPatchCount); } \
  NS_IMETHOD GetPatchAt(uint32_t index, nsIUpdatePatch * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPatchAt(index, _retval); } \
  NS_IMETHOD Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Serialize(updates, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdate : public nsIUpdate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATE

  nsUpdate();

private:
  ~nsUpdate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUpdate, nsIUpdate)

nsUpdate::nsUpdate()
{
  /* member initializers and constructor code */
}

nsUpdate::~nsUpdate()
{
  /* destructor code */
}

/* attribute AString type; */
NS_IMETHODIMP nsUpdate::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString name; */
NS_IMETHODIMP nsUpdate::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString displayVersion; */
NS_IMETHODIMP nsUpdate::GetDisplayVersion(nsAString & aDisplayVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetDisplayVersion(const nsAString & aDisplayVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString appVersion; */
NS_IMETHODIMP nsUpdate::GetAppVersion(nsAString & aAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetAppVersion(const nsAString & aAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString platformVersion; */
NS_IMETHODIMP nsUpdate::GetPlatformVersion(nsAString & aPlatformVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetPlatformVersion(const nsAString & aPlatformVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString previousAppVersion; */
NS_IMETHODIMP nsUpdate::GetPreviousAppVersion(nsAString & aPreviousAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetPreviousAppVersion(const nsAString & aPreviousAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString buildID; */
NS_IMETHODIMP nsUpdate::GetBuildID(nsAString & aBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetBuildID(const nsAString & aBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString detailsURL; */
NS_IMETHODIMP nsUpdate::GetDetailsURL(nsAString & aDetailsURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetDetailsURL(const nsAString & aDetailsURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString billboardURL; */
NS_IMETHODIMP nsUpdate::GetBillboardURL(nsAString & aBillboardURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetBillboardURL(const nsAString & aBillboardURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString licenseURL; */
NS_IMETHODIMP nsUpdate::GetLicenseURL(nsAString & aLicenseURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetLicenseURL(const nsAString & aLicenseURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString serviceURL; */
NS_IMETHODIMP nsUpdate::GetServiceURL(nsAString & aServiceURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetServiceURL(const nsAString & aServiceURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString channel; */
NS_IMETHODIMP nsUpdate::GetChannel(nsAString & aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetChannel(const nsAString & aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showPrompt; */
NS_IMETHODIMP nsUpdate::GetShowPrompt(bool *aShowPrompt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetShowPrompt(bool aShowPrompt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showNeverForVersion; */
NS_IMETHODIMP nsUpdate::GetShowNeverForVersion(bool *aShowNeverForVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetShowNeverForVersion(bool aShowNeverForVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean unsupported; */
NS_IMETHODIMP nsUpdate::GetUnsupported(bool *aUnsupported)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetUnsupported(bool aUnsupported)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long long promptWaitTime; */
NS_IMETHODIMP nsUpdate::GetPromptWaitTime(int64_t *aPromptWaitTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetPromptWaitTime(int64_t aPromptWaitTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isCompleteUpdate; */
NS_IMETHODIMP nsUpdate::GetIsCompleteUpdate(bool *aIsCompleteUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetIsCompleteUpdate(bool aIsCompleteUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isSecurityUpdate; */
NS_IMETHODIMP nsUpdate::GetIsSecurityUpdate(bool *aIsSecurityUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetIsSecurityUpdate(bool aIsSecurityUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isOSUpdate; */
NS_IMETHODIMP nsUpdate::GetIsOSUpdate(bool *aIsOSUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetIsOSUpdate(bool aIsOSUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long long installDate; */
NS_IMETHODIMP nsUpdate::GetInstallDate(int64_t *aInstallDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetInstallDate(int64_t aInstallDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString statusText; */
NS_IMETHODIMP nsUpdate::GetStatusText(nsAString & aStatusText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetStatusText(const nsAString & aStatusText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIUpdatePatch selectedPatch; */
NS_IMETHODIMP nsUpdate::GetSelectedPatch(nsIUpdatePatch * *aSelectedPatch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString state; */
NS_IMETHODIMP nsUpdate::GetState(nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetState(const nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long errorCode; */
NS_IMETHODIMP nsUpdate::GetErrorCode(int32_t *aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdate::SetErrorCode(int32_t aErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long patchCount; */
NS_IMETHODIMP nsUpdate::GetPatchCount(uint32_t *aPatchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUpdatePatch getPatchAt (in unsigned long index); */
NS_IMETHODIMP nsUpdate::GetPatchAt(uint32_t index, nsIUpdatePatch * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement serialize (in nsIDOMDocument updates); */
NS_IMETHODIMP nsUpdate::Serialize(nsIDOMDocument *updates, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdateCheckListener */
#define NS_IUPDATECHECKLISTENER_IID_STR "4aa2b4bb-39ea-407b-98ff-89f19134d4c0"

#define NS_IUPDATECHECKLISTENER_IID \
  {0x4aa2b4bb, 0x39ea, 0x407b, \
    { 0x98, 0xff, 0x89, 0xf1, 0x91, 0x34, 0xd4, 0xc0 }}

class NS_NO_VTABLE nsIUpdateCheckListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATECHECKLISTENER_IID)

  /* void onCheckComplete (in nsIXMLHttpRequest request, [array, size_is (updateCount)] in nsIUpdate updates, in unsigned long updateCount); */
  NS_IMETHOD OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, uint32_t updateCount) = 0;

  /* void onError (in nsIXMLHttpRequest request, in nsIUpdate update); */
  NS_IMETHOD OnError(nsIXMLHttpRequest *request, nsIUpdate *update) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateCheckListener, NS_IUPDATECHECKLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATECHECKLISTENER \
  NS_IMETHOD OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, uint32_t updateCount) override; \
  NS_IMETHOD OnError(nsIXMLHttpRequest *request, nsIUpdate *update) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATECHECKLISTENER(_to) \
  NS_IMETHOD OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, uint32_t updateCount) override { return _to OnCheckComplete(request, updates, updateCount); } \
  NS_IMETHOD OnError(nsIXMLHttpRequest *request, nsIUpdate *update) override { return _to OnError(request, update); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATECHECKLISTENER(_to) \
  NS_IMETHOD OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, uint32_t updateCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCheckComplete(request, updates, updateCount); } \
  NS_IMETHOD OnError(nsIXMLHttpRequest *request, nsIUpdate *update) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(request, update); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateCheckListener : public nsIUpdateCheckListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATECHECKLISTENER

  nsUpdateCheckListener();

private:
  ~nsUpdateCheckListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUpdateCheckListener, nsIUpdateCheckListener)

nsUpdateCheckListener::nsUpdateCheckListener()
{
  /* member initializers and constructor code */
}

nsUpdateCheckListener::~nsUpdateCheckListener()
{
  /* destructor code */
}

/* void onCheckComplete (in nsIXMLHttpRequest request, [array, size_is (updateCount)] in nsIUpdate updates, in unsigned long updateCount); */
NS_IMETHODIMP nsUpdateCheckListener::OnCheckComplete(nsIXMLHttpRequest *request, nsIUpdate **updates, uint32_t updateCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onError (in nsIXMLHttpRequest request, in nsIUpdate update); */
NS_IMETHODIMP nsUpdateCheckListener::OnError(nsIXMLHttpRequest *request, nsIUpdate *update)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdateChecker */
#define NS_IUPDATECHECKER_IID_STR "877ace25-8bc5-452a-8586-9c1cf2871994"

#define NS_IUPDATECHECKER_IID \
  {0x877ace25, 0x8bc5, 0x452a, \
    { 0x85, 0x86, 0x9c, 0x1c, 0xf2, 0x87, 0x19, 0x94 }}

class NS_NO_VTABLE nsIUpdateChecker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATECHECKER_IID)

  /* void checkForUpdates (in nsIUpdateCheckListener listener, in boolean force); */
  NS_IMETHOD CheckForUpdates(nsIUpdateCheckListener *listener, bool force) = 0;

  enum {
    CURRENT_CHECK = 1U,
    CURRENT_SESSION = 2U,
    ANY_CHECKS = 3U
  };

  /* void stopChecking (in unsigned short duration); */
  NS_IMETHOD StopChecking(uint16_t duration) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateChecker, NS_IUPDATECHECKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATECHECKER \
  NS_IMETHOD CheckForUpdates(nsIUpdateCheckListener *listener, bool force) override; \
  NS_IMETHOD StopChecking(uint16_t duration) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATECHECKER(_to) \
  NS_IMETHOD CheckForUpdates(nsIUpdateCheckListener *listener, bool force) override { return _to CheckForUpdates(listener, force); } \
  NS_IMETHOD StopChecking(uint16_t duration) override { return _to StopChecking(duration); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATECHECKER(_to) \
  NS_IMETHOD CheckForUpdates(nsIUpdateCheckListener *listener, bool force) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForUpdates(listener, force); } \
  NS_IMETHOD StopChecking(uint16_t duration) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StopChecking(duration); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateChecker : public nsIUpdateChecker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATECHECKER

  nsUpdateChecker();

private:
  ~nsUpdateChecker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUpdateChecker, nsIUpdateChecker)

nsUpdateChecker::nsUpdateChecker()
{
  /* member initializers and constructor code */
}

nsUpdateChecker::~nsUpdateChecker()
{
  /* destructor code */
}

/* void checkForUpdates (in nsIUpdateCheckListener listener, in boolean force); */
NS_IMETHODIMP nsUpdateChecker::CheckForUpdates(nsIUpdateCheckListener *listener, bool force)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopChecking (in unsigned short duration); */
NS_IMETHODIMP nsUpdateChecker::StopChecking(uint16_t duration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIApplicationUpdateService */
#define NS_IAPPLICATIONUPDATESERVICE_IID_STR "9f9b51f5-340e-47ce-85ae-9eb077c6cd39"

#define NS_IAPPLICATIONUPDATESERVICE_IID \
  {0x9f9b51f5, 0x340e, 0x47ce, \
    { 0x85, 0xae, 0x9e, 0xb0, 0x77, 0xc6, 0xcd, 0x39 }}

class NS_NO_VTABLE nsIApplicationUpdateService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONUPDATESERVICE_IID)

  /* void checkForBackgroundUpdates (); */
  NS_IMETHOD CheckForBackgroundUpdates(void) = 0;

  /* readonly attribute nsIUpdateChecker backgroundChecker; */
  NS_IMETHOD GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker) = 0;

  /* nsIUpdate selectUpdate ([array, size_is (updateCount)] in nsIUpdate updates, in unsigned long updateCount); */
  NS_IMETHOD SelectUpdate(nsIUpdate **updates, uint32_t updateCount, nsIUpdate * *_retval) = 0;

  /* void addDownloadListener (in nsIRequestObserver listener); */
  NS_IMETHOD AddDownloadListener(nsIRequestObserver *listener) = 0;

  /* void removeDownloadListener (in nsIRequestObserver listener); */
  NS_IMETHOD RemoveDownloadListener(nsIRequestObserver *listener) = 0;

  /* AString downloadUpdate (in nsIUpdate update, in boolean background); */
  NS_IMETHOD DownloadUpdate(nsIUpdate *update, bool background, nsAString & _retval) = 0;

  /* void applyOsUpdate (in nsIUpdate update); */
  NS_IMETHOD ApplyOsUpdate(nsIUpdate *update) = 0;

  /* nsIFile getUpdatesDirectory (); */
  NS_IMETHOD GetUpdatesDirectory(nsIFile * *_retval) = 0;

  /* void pauseDownload (); */
  NS_IMETHOD PauseDownload(void) = 0;

  /* readonly attribute boolean isDownloading; */
  NS_IMETHOD GetIsDownloading(bool *aIsDownloading) = 0;

  /* readonly attribute boolean canCheckForUpdates; */
  NS_IMETHOD GetCanCheckForUpdates(bool *aCanCheckForUpdates) = 0;

  /* readonly attribute boolean canApplyUpdates; */
  NS_IMETHOD GetCanApplyUpdates(bool *aCanApplyUpdates) = 0;

  /* readonly attribute boolean isOtherInstanceHandlingUpdates; */
  NS_IMETHOD GetIsOtherInstanceHandlingUpdates(bool *aIsOtherInstanceHandlingUpdates) = 0;

  /* readonly attribute boolean canStageUpdates; */
  NS_IMETHOD GetCanStageUpdates(bool *aCanStageUpdates) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationUpdateService, NS_IAPPLICATIONUPDATESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONUPDATESERVICE \
  NS_IMETHOD CheckForBackgroundUpdates(void) override; \
  NS_IMETHOD GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker) override; \
  NS_IMETHOD SelectUpdate(nsIUpdate **updates, uint32_t updateCount, nsIUpdate * *_retval) override; \
  NS_IMETHOD AddDownloadListener(nsIRequestObserver *listener) override; \
  NS_IMETHOD RemoveDownloadListener(nsIRequestObserver *listener) override; \
  NS_IMETHOD DownloadUpdate(nsIUpdate *update, bool background, nsAString & _retval) override; \
  NS_IMETHOD ApplyOsUpdate(nsIUpdate *update) override; \
  NS_IMETHOD GetUpdatesDirectory(nsIFile * *_retval) override; \
  NS_IMETHOD PauseDownload(void) override; \
  NS_IMETHOD GetIsDownloading(bool *aIsDownloading) override; \
  NS_IMETHOD GetCanCheckForUpdates(bool *aCanCheckForUpdates) override; \
  NS_IMETHOD GetCanApplyUpdates(bool *aCanApplyUpdates) override; \
  NS_IMETHOD GetIsOtherInstanceHandlingUpdates(bool *aIsOtherInstanceHandlingUpdates) override; \
  NS_IMETHOD GetCanStageUpdates(bool *aCanStageUpdates) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONUPDATESERVICE(_to) \
  NS_IMETHOD CheckForBackgroundUpdates(void) override { return _to CheckForBackgroundUpdates(); } \
  NS_IMETHOD GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker) override { return _to GetBackgroundChecker(aBackgroundChecker); } \
  NS_IMETHOD SelectUpdate(nsIUpdate **updates, uint32_t updateCount, nsIUpdate * *_retval) override { return _to SelectUpdate(updates, updateCount, _retval); } \
  NS_IMETHOD AddDownloadListener(nsIRequestObserver *listener) override { return _to AddDownloadListener(listener); } \
  NS_IMETHOD RemoveDownloadListener(nsIRequestObserver *listener) override { return _to RemoveDownloadListener(listener); } \
  NS_IMETHOD DownloadUpdate(nsIUpdate *update, bool background, nsAString & _retval) override { return _to DownloadUpdate(update, background, _retval); } \
  NS_IMETHOD ApplyOsUpdate(nsIUpdate *update) override { return _to ApplyOsUpdate(update); } \
  NS_IMETHOD GetUpdatesDirectory(nsIFile * *_retval) override { return _to GetUpdatesDirectory(_retval); } \
  NS_IMETHOD PauseDownload(void) override { return _to PauseDownload(); } \
  NS_IMETHOD GetIsDownloading(bool *aIsDownloading) override { return _to GetIsDownloading(aIsDownloading); } \
  NS_IMETHOD GetCanCheckForUpdates(bool *aCanCheckForUpdates) override { return _to GetCanCheckForUpdates(aCanCheckForUpdates); } \
  NS_IMETHOD GetCanApplyUpdates(bool *aCanApplyUpdates) override { return _to GetCanApplyUpdates(aCanApplyUpdates); } \
  NS_IMETHOD GetIsOtherInstanceHandlingUpdates(bool *aIsOtherInstanceHandlingUpdates) override { return _to GetIsOtherInstanceHandlingUpdates(aIsOtherInstanceHandlingUpdates); } \
  NS_IMETHOD GetCanStageUpdates(bool *aCanStageUpdates) override { return _to GetCanStageUpdates(aCanStageUpdates); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONUPDATESERVICE(_to) \
  NS_IMETHOD CheckForBackgroundUpdates(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForBackgroundUpdates(); } \
  NS_IMETHOD GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBackgroundChecker(aBackgroundChecker); } \
  NS_IMETHOD SelectUpdate(nsIUpdate **updates, uint32_t updateCount, nsIUpdate * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectUpdate(updates, updateCount, _retval); } \
  NS_IMETHOD AddDownloadListener(nsIRequestObserver *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDownloadListener(listener); } \
  NS_IMETHOD RemoveDownloadListener(nsIRequestObserver *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDownloadListener(listener); } \
  NS_IMETHOD DownloadUpdate(nsIUpdate *update, bool background, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DownloadUpdate(update, background, _retval); } \
  NS_IMETHOD ApplyOsUpdate(nsIUpdate *update) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplyOsUpdate(update); } \
  NS_IMETHOD GetUpdatesDirectory(nsIFile * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdatesDirectory(_retval); } \
  NS_IMETHOD PauseDownload(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PauseDownload(); } \
  NS_IMETHOD GetIsDownloading(bool *aIsDownloading) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDownloading(aIsDownloading); } \
  NS_IMETHOD GetCanCheckForUpdates(bool *aCanCheckForUpdates) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanCheckForUpdates(aCanCheckForUpdates); } \
  NS_IMETHOD GetCanApplyUpdates(bool *aCanApplyUpdates) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanApplyUpdates(aCanApplyUpdates); } \
  NS_IMETHOD GetIsOtherInstanceHandlingUpdates(bool *aIsOtherInstanceHandlingUpdates) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsOtherInstanceHandlingUpdates(aIsOtherInstanceHandlingUpdates); } \
  NS_IMETHOD GetCanStageUpdates(bool *aCanStageUpdates) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanStageUpdates(aCanStageUpdates); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationUpdateService : public nsIApplicationUpdateService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONUPDATESERVICE

  nsApplicationUpdateService();

private:
  ~nsApplicationUpdateService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsApplicationUpdateService, nsIApplicationUpdateService)

nsApplicationUpdateService::nsApplicationUpdateService()
{
  /* member initializers and constructor code */
}

nsApplicationUpdateService::~nsApplicationUpdateService()
{
  /* destructor code */
}

/* void checkForBackgroundUpdates (); */
NS_IMETHODIMP nsApplicationUpdateService::CheckForBackgroundUpdates()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIUpdateChecker backgroundChecker; */
NS_IMETHODIMP nsApplicationUpdateService::GetBackgroundChecker(nsIUpdateChecker * *aBackgroundChecker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUpdate selectUpdate ([array, size_is (updateCount)] in nsIUpdate updates, in unsigned long updateCount); */
NS_IMETHODIMP nsApplicationUpdateService::SelectUpdate(nsIUpdate **updates, uint32_t updateCount, nsIUpdate * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDownloadListener (in nsIRequestObserver listener); */
NS_IMETHODIMP nsApplicationUpdateService::AddDownloadListener(nsIRequestObserver *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDownloadListener (in nsIRequestObserver listener); */
NS_IMETHODIMP nsApplicationUpdateService::RemoveDownloadListener(nsIRequestObserver *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString downloadUpdate (in nsIUpdate update, in boolean background); */
NS_IMETHODIMP nsApplicationUpdateService::DownloadUpdate(nsIUpdate *update, bool background, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void applyOsUpdate (in nsIUpdate update); */
NS_IMETHODIMP nsApplicationUpdateService::ApplyOsUpdate(nsIUpdate *update)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile getUpdatesDirectory (); */
NS_IMETHODIMP nsApplicationUpdateService::GetUpdatesDirectory(nsIFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pauseDownload (); */
NS_IMETHODIMP nsApplicationUpdateService::PauseDownload()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDownloading; */
NS_IMETHODIMP nsApplicationUpdateService::GetIsDownloading(bool *aIsDownloading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canCheckForUpdates; */
NS_IMETHODIMP nsApplicationUpdateService::GetCanCheckForUpdates(bool *aCanCheckForUpdates)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canApplyUpdates; */
NS_IMETHODIMP nsApplicationUpdateService::GetCanApplyUpdates(bool *aCanApplyUpdates)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isOtherInstanceHandlingUpdates; */
NS_IMETHODIMP nsApplicationUpdateService::GetIsOtherInstanceHandlingUpdates(bool *aIsOtherInstanceHandlingUpdates)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canStageUpdates; */
NS_IMETHODIMP nsApplicationUpdateService::GetCanStageUpdates(bool *aCanStageUpdates)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdateProcessor */
#define NS_IUPDATEPROCESSOR_IID_STR "74439497-d796-4915-8cef-3dfe43027e4d"

#define NS_IUPDATEPROCESSOR_IID \
  {0x74439497, 0xd796, 0x4915, \
    { 0x8c, 0xef, 0x3d, 0xfe, 0x43, 0x02, 0x7e, 0x4d }}

class NS_NO_VTABLE nsIUpdateProcessor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATEPROCESSOR_IID)

  /* void processUpdate (in nsIUpdate update); */
  NS_IMETHOD ProcessUpdate(nsIUpdate *update) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateProcessor, NS_IUPDATEPROCESSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATEPROCESSOR \
  NS_IMETHOD ProcessUpdate(nsIUpdate *update) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATEPROCESSOR(_to) \
  NS_IMETHOD ProcessUpdate(nsIUpdate *update) override { return _to ProcessUpdate(update); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATEPROCESSOR(_to) \
  NS_IMETHOD ProcessUpdate(nsIUpdate *update) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessUpdate(update); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateProcessor : public nsIUpdateProcessor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATEPROCESSOR

  nsUpdateProcessor();

private:
  ~nsUpdateProcessor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUpdateProcessor, nsIUpdateProcessor)

nsUpdateProcessor::nsUpdateProcessor()
{
  /* member initializers and constructor code */
}

nsUpdateProcessor::~nsUpdateProcessor()
{
  /* destructor code */
}

/* void processUpdate (in nsIUpdate update); */
NS_IMETHODIMP nsUpdateProcessor::ProcessUpdate(nsIUpdate *update)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdateManager */
#define NS_IUPDATEMANAGER_IID_STR "f8371237-10a6-46a5-b23f-f6f7684e9d71"

#define NS_IUPDATEMANAGER_IID \
  {0xf8371237, 0x10a6, 0x46a5, \
    { 0xb2, 0x3f, 0xf6, 0xf7, 0x68, 0x4e, 0x9d, 0x71 }}

class NS_NO_VTABLE nsIUpdateManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATEMANAGER_IID)

  /* nsIUpdate getUpdateAt (in long index); */
  NS_IMETHOD GetUpdateAt(int32_t index, nsIUpdate * *_retval) = 0;

  /* readonly attribute long updateCount; */
  NS_IMETHOD GetUpdateCount(int32_t *aUpdateCount) = 0;

  /* attribute nsIUpdate activeUpdate; */
  NS_IMETHOD GetActiveUpdate(nsIUpdate * *aActiveUpdate) = 0;
  NS_IMETHOD SetActiveUpdate(nsIUpdate *aActiveUpdate) = 0;

  /* void saveUpdates (); */
  NS_IMETHOD SaveUpdates(void) = 0;

  /* void refreshUpdateStatus (); */
  NS_IMETHOD RefreshUpdateStatus(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateManager, NS_IUPDATEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATEMANAGER \
  NS_IMETHOD GetUpdateAt(int32_t index, nsIUpdate * *_retval) override; \
  NS_IMETHOD GetUpdateCount(int32_t *aUpdateCount) override; \
  NS_IMETHOD GetActiveUpdate(nsIUpdate * *aActiveUpdate) override; \
  NS_IMETHOD SetActiveUpdate(nsIUpdate *aActiveUpdate) override; \
  NS_IMETHOD SaveUpdates(void) override; \
  NS_IMETHOD RefreshUpdateStatus(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATEMANAGER(_to) \
  NS_IMETHOD GetUpdateAt(int32_t index, nsIUpdate * *_retval) override { return _to GetUpdateAt(index, _retval); } \
  NS_IMETHOD GetUpdateCount(int32_t *aUpdateCount) override { return _to GetUpdateCount(aUpdateCount); } \
  NS_IMETHOD GetActiveUpdate(nsIUpdate * *aActiveUpdate) override { return _to GetActiveUpdate(aActiveUpdate); } \
  NS_IMETHOD SetActiveUpdate(nsIUpdate *aActiveUpdate) override { return _to SetActiveUpdate(aActiveUpdate); } \
  NS_IMETHOD SaveUpdates(void) override { return _to SaveUpdates(); } \
  NS_IMETHOD RefreshUpdateStatus(void) override { return _to RefreshUpdateStatus(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATEMANAGER(_to) \
  NS_IMETHOD GetUpdateAt(int32_t index, nsIUpdate * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateAt(index, _retval); } \
  NS_IMETHOD GetUpdateCount(int32_t *aUpdateCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateCount(aUpdateCount); } \
  NS_IMETHOD GetActiveUpdate(nsIUpdate * *aActiveUpdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveUpdate(aActiveUpdate); } \
  NS_IMETHOD SetActiveUpdate(nsIUpdate *aActiveUpdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetActiveUpdate(aActiveUpdate); } \
  NS_IMETHOD SaveUpdates(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveUpdates(); } \
  NS_IMETHOD RefreshUpdateStatus(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshUpdateStatus(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateManager : public nsIUpdateManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATEMANAGER

  nsUpdateManager();

private:
  ~nsUpdateManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUpdateManager, nsIUpdateManager)

nsUpdateManager::nsUpdateManager()
{
  /* member initializers and constructor code */
}

nsUpdateManager::~nsUpdateManager()
{
  /* destructor code */
}

/* nsIUpdate getUpdateAt (in long index); */
NS_IMETHODIMP nsUpdateManager::GetUpdateAt(int32_t index, nsIUpdate * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long updateCount; */
NS_IMETHODIMP nsUpdateManager::GetUpdateCount(int32_t *aUpdateCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIUpdate activeUpdate; */
NS_IMETHODIMP nsUpdateManager::GetActiveUpdate(nsIUpdate * *aActiveUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUpdateManager::SetActiveUpdate(nsIUpdate *aActiveUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveUpdates (); */
NS_IMETHODIMP nsUpdateManager::SaveUpdates()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshUpdateStatus (); */
NS_IMETHODIMP nsUpdateManager::RefreshUpdateStatus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUpdatePrompt */
#define NS_IUPDATEPROMPT_IID_STR "599fd3c6-ec68-4499-ada5-2997739c97a6"

#define NS_IUPDATEPROMPT_IID \
  {0x599fd3c6, 0xec68, 0x4499, \
    { 0xad, 0xa5, 0x29, 0x97, 0x73, 0x9c, 0x97, 0xa6 }}

class NS_NO_VTABLE nsIUpdatePrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATEPROMPT_IID)

  /* void checkForUpdates (); */
  NS_IMETHOD CheckForUpdates(void) = 0;

  /* void showUpdateAvailable (in nsIUpdate update); */
  NS_IMETHOD ShowUpdateAvailable(nsIUpdate *update) = 0;

  /* void showUpdateDownloaded (in nsIUpdate update, [optional] in boolean background); */
  NS_IMETHOD ShowUpdateDownloaded(nsIUpdate *update, bool background) = 0;

  /* void showUpdateInstalled (); */
  NS_IMETHOD ShowUpdateInstalled(void) = 0;

  /* void showUpdateError (in nsIUpdate update); */
  NS_IMETHOD ShowUpdateError(nsIUpdate *update) = 0;

  /* void showUpdateHistory (in nsIDOMWindow parent); */
  NS_IMETHOD ShowUpdateHistory(nsIDOMWindow *parent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdatePrompt, NS_IUPDATEPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATEPROMPT \
  NS_IMETHOD CheckForUpdates(void) override; \
  NS_IMETHOD ShowUpdateAvailable(nsIUpdate *update) override; \
  NS_IMETHOD ShowUpdateDownloaded(nsIUpdate *update, bool background) override; \
  NS_IMETHOD ShowUpdateInstalled(void) override; \
  NS_IMETHOD ShowUpdateError(nsIUpdate *update) override; \
  NS_IMETHOD ShowUpdateHistory(nsIDOMWindow *parent) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATEPROMPT(_to) \
  NS_IMETHOD CheckForUpdates(void) override { return _to CheckForUpdates(); } \
  NS_IMETHOD ShowUpdateAvailable(nsIUpdate *update) override { return _to ShowUpdateAvailable(update); } \
  NS_IMETHOD ShowUpdateDownloaded(nsIUpdate *update, bool background) override { return _to ShowUpdateDownloaded(update, background); } \
  NS_IMETHOD ShowUpdateInstalled(void) override { return _to ShowUpdateInstalled(); } \
  NS_IMETHOD ShowUpdateError(nsIUpdate *update) override { return _to ShowUpdateError(update); } \
  NS_IMETHOD ShowUpdateHistory(nsIDOMWindow *parent) override { return _to ShowUpdateHistory(parent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATEPROMPT(_to) \
  NS_IMETHOD CheckForUpdates(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForUpdates(); } \
  NS_IMETHOD ShowUpdateAvailable(nsIUpdate *update) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateAvailable(update); } \
  NS_IMETHOD ShowUpdateDownloaded(nsIUpdate *update, bool background) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateDownloaded(update, background); } \
  NS_IMETHOD ShowUpdateInstalled(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateInstalled(); } \
  NS_IMETHOD ShowUpdateError(nsIUpdate *update) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateError(update); } \
  NS_IMETHOD ShowUpdateHistory(nsIDOMWindow *parent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowUpdateHistory(parent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdatePrompt : public nsIUpdatePrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATEPROMPT

  nsUpdatePrompt();

private:
  ~nsUpdatePrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUpdatePrompt, nsIUpdatePrompt)

nsUpdatePrompt::nsUpdatePrompt()
{
  /* member initializers and constructor code */
}

nsUpdatePrompt::~nsUpdatePrompt()
{
  /* destructor code */
}

/* void checkForUpdates (); */
NS_IMETHODIMP nsUpdatePrompt::CheckForUpdates()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateAvailable (in nsIUpdate update); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateAvailable(nsIUpdate *update)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateDownloaded (in nsIUpdate update, [optional] in boolean background); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateDownloaded(nsIUpdate *update, bool background)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateInstalled (); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateInstalled()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateError (in nsIUpdate update); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateError(nsIUpdate *update)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showUpdateHistory (in nsIDOMWindow parent); */
NS_IMETHODIMP nsUpdatePrompt::ShowUpdateHistory(nsIDOMWindow *parent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUpdateService_h__ */
