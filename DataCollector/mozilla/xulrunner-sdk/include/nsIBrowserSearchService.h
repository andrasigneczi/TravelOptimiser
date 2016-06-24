/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBrowserSearchService.idl
 */

#ifndef __gen_nsIBrowserSearchService_h__
#define __gen_nsIBrowserSearchService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */


/* starting interface:    nsISearchSubmission */
#define NS_ISEARCHSUBMISSION_IID_STR "5799251f-5b55-4df7-a9e7-0c27812c469a"

#define NS_ISEARCHSUBMISSION_IID \
  {0x5799251f, 0x5b55, 0x4df7, \
    { 0xa9, 0xe7, 0x0c, 0x27, 0x81, 0x2c, 0x46, 0x9a }}

class NS_NO_VTABLE nsISearchSubmission : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEARCHSUBMISSION_IID)

  /* readonly attribute nsIInputStream postData; */
  NS_IMETHOD GetPostData(nsIInputStream * *aPostData) = 0;

  /* readonly attribute nsIURI uri; */
  NS_IMETHOD GetUri(nsIURI * *aUri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISearchSubmission, NS_ISEARCHSUBMISSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEARCHSUBMISSION \
  NS_IMETHOD GetPostData(nsIInputStream * *aPostData) override; \
  NS_IMETHOD GetUri(nsIURI * *aUri) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEARCHSUBMISSION(_to) \
  NS_IMETHOD GetPostData(nsIInputStream * *aPostData) override { return _to GetPostData(aPostData); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) override { return _to GetUri(aUri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEARCHSUBMISSION(_to) \
  NS_IMETHOD GetPostData(nsIInputStream * *aPostData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPostData(aPostData); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSearchSubmission : public nsISearchSubmission
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEARCHSUBMISSION

  nsSearchSubmission();

private:
  ~nsSearchSubmission();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSearchSubmission, nsISearchSubmission)

nsSearchSubmission::nsSearchSubmission()
{
  /* member initializers and constructor code */
}

nsSearchSubmission::~nsSearchSubmission()
{
  /* destructor code */
}

/* readonly attribute nsIInputStream postData; */
NS_IMETHODIMP nsSearchSubmission::GetPostData(nsIInputStream * *aPostData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI uri; */
NS_IMETHODIMP nsSearchSubmission::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISearchEngine */
#define NS_ISEARCHENGINE_IID_STR "65fd517b-6bda-4bac-bbe1-42de1b3a7df6"

#define NS_ISEARCHENGINE_IID \
  {0x65fd517b, 0x6bda, 0x4bac, \
    { 0xbb, 0xe1, 0x42, 0xde, 0x1b, 0x3a, 0x7d, 0xf6 }}

class NS_NO_VTABLE nsISearchEngine : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEARCHENGINE_IID)

  /* nsISearchSubmission getSubmission (in AString data, [optional] in AString responseType, [optional] in AString purpose); */
  NS_IMETHOD GetSubmission(const nsAString & data, const nsAString & responseType, const nsAString & purpose, nsISearchSubmission * *_retval) = 0;

  /* void addParam (in AString name, in AString value, in AString responseType); */
  NS_IMETHOD AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType) = 0;

  /* boolean supportsResponseType (in AString responseType); */
  NS_IMETHOD SupportsResponseType(const nsAString & responseType, bool *_retval) = 0;

  /* AString getIconURLBySize (in long width, in long height); */
  NS_IMETHOD GetIconURLBySize(int32_t width, int32_t height, nsAString & _retval) = 0;

  /* jsval getIcons (); */
  NS_IMETHOD GetIcons(JS::MutableHandleValue _retval) = 0;

  /* void speculativeConnect (in jsval options); */
  NS_IMETHOD SpeculativeConnect(JS::HandleValue options) = 0;

  enum {
    TYPE_MOZSEARCH = 1U,
    TYPE_SHERLOCK = 2U,
    TYPE_OPENSEARCH = 3U,
    DATA_XML = 1U,
    DATA_TEXT = 2U
  };

  /* attribute AString alias; */
  NS_IMETHOD GetAlias(nsAString & aAlias) = 0;
  NS_IMETHOD SetAlias(const nsAString & aAlias) = 0;

  /* readonly attribute AString description; */
  NS_IMETHOD GetDescription(nsAString & aDescription) = 0;

  /* attribute boolean hidden; */
  NS_IMETHOD GetHidden(bool *aHidden) = 0;
  NS_IMETHOD SetHidden(bool aHidden) = 0;

  /* readonly attribute nsIURI iconURI; */
  NS_IMETHOD GetIconURI(nsIURI * *aIconURI) = 0;

  /* readonly attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute AString searchForm; */
  NS_IMETHOD GetSearchForm(nsAString & aSearchForm) = 0;

  /* readonly attribute long type; */
  NS_IMETHOD GetType(int32_t *aType) = 0;

  /* readonly attribute AString identifier; */
  NS_IMETHOD GetIdentifier(nsAString & aIdentifier) = 0;

  /* AString getResultDomain ([optional] in AString responseType); */
  NS_IMETHOD GetResultDomain(const nsAString & responseType, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISearchEngine, NS_ISEARCHENGINE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEARCHENGINE \
  NS_IMETHOD GetSubmission(const nsAString & data, const nsAString & responseType, const nsAString & purpose, nsISearchSubmission * *_retval) override; \
  NS_IMETHOD AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType) override; \
  NS_IMETHOD SupportsResponseType(const nsAString & responseType, bool *_retval) override; \
  NS_IMETHOD GetIconURLBySize(int32_t width, int32_t height, nsAString & _retval) override; \
  NS_IMETHOD GetIcons(JS::MutableHandleValue _retval) override; \
  NS_IMETHOD SpeculativeConnect(JS::HandleValue options) override; \
  NS_IMETHOD GetAlias(nsAString & aAlias) override; \
  NS_IMETHOD SetAlias(const nsAString & aAlias) override; \
  NS_IMETHOD GetDescription(nsAString & aDescription) override; \
  NS_IMETHOD GetHidden(bool *aHidden) override; \
  NS_IMETHOD SetHidden(bool aHidden) override; \
  NS_IMETHOD GetIconURI(nsIURI * *aIconURI) override; \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD GetSearchForm(nsAString & aSearchForm) override; \
  NS_IMETHOD GetType(int32_t *aType) override; \
  NS_IMETHOD GetIdentifier(nsAString & aIdentifier) override; \
  NS_IMETHOD GetResultDomain(const nsAString & responseType, nsAString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEARCHENGINE(_to) \
  NS_IMETHOD GetSubmission(const nsAString & data, const nsAString & responseType, const nsAString & purpose, nsISearchSubmission * *_retval) override { return _to GetSubmission(data, responseType, purpose, _retval); } \
  NS_IMETHOD AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType) override { return _to AddParam(name, value, responseType); } \
  NS_IMETHOD SupportsResponseType(const nsAString & responseType, bool *_retval) override { return _to SupportsResponseType(responseType, _retval); } \
  NS_IMETHOD GetIconURLBySize(int32_t width, int32_t height, nsAString & _retval) override { return _to GetIconURLBySize(width, height, _retval); } \
  NS_IMETHOD GetIcons(JS::MutableHandleValue _retval) override { return _to GetIcons(_retval); } \
  NS_IMETHOD SpeculativeConnect(JS::HandleValue options) override { return _to SpeculativeConnect(options); } \
  NS_IMETHOD GetAlias(nsAString & aAlias) override { return _to GetAlias(aAlias); } \
  NS_IMETHOD SetAlias(const nsAString & aAlias) override { return _to SetAlias(aAlias); } \
  NS_IMETHOD GetDescription(nsAString & aDescription) override { return _to GetDescription(aDescription); } \
  NS_IMETHOD GetHidden(bool *aHidden) override { return _to GetHidden(aHidden); } \
  NS_IMETHOD SetHidden(bool aHidden) override { return _to SetHidden(aHidden); } \
  NS_IMETHOD GetIconURI(nsIURI * *aIconURI) override { return _to GetIconURI(aIconURI); } \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetSearchForm(nsAString & aSearchForm) override { return _to GetSearchForm(aSearchForm); } \
  NS_IMETHOD GetType(int32_t *aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetIdentifier(nsAString & aIdentifier) override { return _to GetIdentifier(aIdentifier); } \
  NS_IMETHOD GetResultDomain(const nsAString & responseType, nsAString & _retval) override { return _to GetResultDomain(responseType, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEARCHENGINE(_to) \
  NS_IMETHOD GetSubmission(const nsAString & data, const nsAString & responseType, const nsAString & purpose, nsISearchSubmission * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubmission(data, responseType, purpose, _retval); } \
  NS_IMETHOD AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddParam(name, value, responseType); } \
  NS_IMETHOD SupportsResponseType(const nsAString & responseType, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SupportsResponseType(responseType, _retval); } \
  NS_IMETHOD GetIconURLBySize(int32_t width, int32_t height, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconURLBySize(width, height, _retval); } \
  NS_IMETHOD GetIcons(JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIcons(_retval); } \
  NS_IMETHOD SpeculativeConnect(JS::HandleValue options) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SpeculativeConnect(options); } \
  NS_IMETHOD GetAlias(nsAString & aAlias) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlias(aAlias); } \
  NS_IMETHOD SetAlias(const nsAString & aAlias) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlias(aAlias); } \
  NS_IMETHOD GetDescription(nsAString & aDescription) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_IMETHOD GetHidden(bool *aHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHidden(aHidden); } \
  NS_IMETHOD SetHidden(bool aHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHidden(aHidden); } \
  NS_IMETHOD GetIconURI(nsIURI * *aIconURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconURI(aIconURI); } \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetSearchForm(nsAString & aSearchForm) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchForm(aSearchForm); } \
  NS_IMETHOD GetType(int32_t *aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetIdentifier(nsAString & aIdentifier) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdentifier(aIdentifier); } \
  NS_IMETHOD GetResultDomain(const nsAString & responseType, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultDomain(responseType, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSearchEngine : public nsISearchEngine
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEARCHENGINE

  nsSearchEngine();

private:
  ~nsSearchEngine();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSearchEngine, nsISearchEngine)

nsSearchEngine::nsSearchEngine()
{
  /* member initializers and constructor code */
}

nsSearchEngine::~nsSearchEngine()
{
  /* destructor code */
}

/* nsISearchSubmission getSubmission (in AString data, [optional] in AString responseType, [optional] in AString purpose); */
NS_IMETHODIMP nsSearchEngine::GetSubmission(const nsAString & data, const nsAString & responseType, const nsAString & purpose, nsISearchSubmission * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addParam (in AString name, in AString value, in AString responseType); */
NS_IMETHODIMP nsSearchEngine::AddParam(const nsAString & name, const nsAString & value, const nsAString & responseType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean supportsResponseType (in AString responseType); */
NS_IMETHODIMP nsSearchEngine::SupportsResponseType(const nsAString & responseType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getIconURLBySize (in long width, in long height); */
NS_IMETHODIMP nsSearchEngine::GetIconURLBySize(int32_t width, int32_t height, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval getIcons (); */
NS_IMETHODIMP nsSearchEngine::GetIcons(JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void speculativeConnect (in jsval options); */
NS_IMETHODIMP nsSearchEngine::SpeculativeConnect(JS::HandleValue options)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString alias; */
NS_IMETHODIMP nsSearchEngine::GetAlias(nsAString & aAlias)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchEngine::SetAlias(const nsAString & aAlias)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString description; */
NS_IMETHODIMP nsSearchEngine::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hidden; */
NS_IMETHODIMP nsSearchEngine::GetHidden(bool *aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSearchEngine::SetHidden(bool aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI iconURI; */
NS_IMETHODIMP nsSearchEngine::GetIconURI(nsIURI * *aIconURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsSearchEngine::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString searchForm; */
NS_IMETHODIMP nsSearchEngine::GetSearchForm(nsAString & aSearchForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long type; */
NS_IMETHODIMP nsSearchEngine::GetType(int32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString identifier; */
NS_IMETHODIMP nsSearchEngine::GetIdentifier(nsAString & aIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getResultDomain ([optional] in AString responseType); */
NS_IMETHODIMP nsSearchEngine::GetResultDomain(const nsAString & responseType, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISearchParseSubmissionResult */
#define NS_ISEARCHPARSESUBMISSIONRESULT_IID_STR "0dc93e51-a7bf-4a16-862d-4b3469ff6206"

#define NS_ISEARCHPARSESUBMISSIONRESULT_IID \
  {0x0dc93e51, 0xa7bf, 0x4a16, \
    { 0x86, 0x2d, 0x4b, 0x34, 0x69, 0xff, 0x62, 0x06 }}

class NS_NO_VTABLE nsISearchParseSubmissionResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEARCHPARSESUBMISSIONRESULT_IID)

  /* readonly attribute nsISearchEngine engine; */
  NS_IMETHOD GetEngine(nsISearchEngine * *aEngine) = 0;

  /* readonly attribute AString terms; */
  NS_IMETHOD GetTerms(nsAString & aTerms) = 0;

  /* readonly attribute long termsOffset; */
  NS_IMETHOD GetTermsOffset(int32_t *aTermsOffset) = 0;

  /* readonly attribute long termsLength; */
  NS_IMETHOD GetTermsLength(int32_t *aTermsLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISearchParseSubmissionResult, NS_ISEARCHPARSESUBMISSIONRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEARCHPARSESUBMISSIONRESULT \
  NS_IMETHOD GetEngine(nsISearchEngine * *aEngine) override; \
  NS_IMETHOD GetTerms(nsAString & aTerms) override; \
  NS_IMETHOD GetTermsOffset(int32_t *aTermsOffset) override; \
  NS_IMETHOD GetTermsLength(int32_t *aTermsLength) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEARCHPARSESUBMISSIONRESULT(_to) \
  NS_IMETHOD GetEngine(nsISearchEngine * *aEngine) override { return _to GetEngine(aEngine); } \
  NS_IMETHOD GetTerms(nsAString & aTerms) override { return _to GetTerms(aTerms); } \
  NS_IMETHOD GetTermsOffset(int32_t *aTermsOffset) override { return _to GetTermsOffset(aTermsOffset); } \
  NS_IMETHOD GetTermsLength(int32_t *aTermsLength) override { return _to GetTermsLength(aTermsLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEARCHPARSESUBMISSIONRESULT(_to) \
  NS_IMETHOD GetEngine(nsISearchEngine * *aEngine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEngine(aEngine); } \
  NS_IMETHOD GetTerms(nsAString & aTerms) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTerms(aTerms); } \
  NS_IMETHOD GetTermsOffset(int32_t *aTermsOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTermsOffset(aTermsOffset); } \
  NS_IMETHOD GetTermsLength(int32_t *aTermsLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTermsLength(aTermsLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSearchParseSubmissionResult : public nsISearchParseSubmissionResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEARCHPARSESUBMISSIONRESULT

  nsSearchParseSubmissionResult();

private:
  ~nsSearchParseSubmissionResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSearchParseSubmissionResult, nsISearchParseSubmissionResult)

nsSearchParseSubmissionResult::nsSearchParseSubmissionResult()
{
  /* member initializers and constructor code */
}

nsSearchParseSubmissionResult::~nsSearchParseSubmissionResult()
{
  /* destructor code */
}

/* readonly attribute nsISearchEngine engine; */
NS_IMETHODIMP nsSearchParseSubmissionResult::GetEngine(nsISearchEngine * *aEngine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString terms; */
NS_IMETHODIMP nsSearchParseSubmissionResult::GetTerms(nsAString & aTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long termsOffset; */
NS_IMETHODIMP nsSearchParseSubmissionResult::GetTermsOffset(int32_t *aTermsOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long termsLength; */
NS_IMETHODIMP nsSearchParseSubmissionResult::GetTermsLength(int32_t *aTermsLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISearchInstallCallback */
#define NS_ISEARCHINSTALLCALLBACK_IID_STR "9fc39136-f08b-46d3-b232-96f4b7b0e235"

#define NS_ISEARCHINSTALLCALLBACK_IID \
  {0x9fc39136, 0xf08b, 0x46d3, \
    { 0xb2, 0x32, 0x96, 0xf4, 0xb7, 0xb0, 0xe2, 0x35 }}

class NS_NO_VTABLE nsISearchInstallCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEARCHINSTALLCALLBACK_IID)

  enum {
    ERROR_UNKNOWN_FAILURE = 1U,
    ERROR_DUPLICATE_ENGINE = 2U
  };

  /* void onSuccess (in nsISearchEngine engine); */
  NS_IMETHOD OnSuccess(nsISearchEngine *engine) = 0;

  /* void onError (in unsigned long errorCode); */
  NS_IMETHOD OnError(uint32_t errorCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISearchInstallCallback, NS_ISEARCHINSTALLCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEARCHINSTALLCALLBACK \
  NS_IMETHOD OnSuccess(nsISearchEngine *engine) override; \
  NS_IMETHOD OnError(uint32_t errorCode) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEARCHINSTALLCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsISearchEngine *engine) override { return _to OnSuccess(engine); } \
  NS_IMETHOD OnError(uint32_t errorCode) override { return _to OnError(errorCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEARCHINSTALLCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsISearchEngine *engine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSuccess(engine); } \
  NS_IMETHOD OnError(uint32_t errorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(errorCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSearchInstallCallback : public nsISearchInstallCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEARCHINSTALLCALLBACK

  nsSearchInstallCallback();

private:
  ~nsSearchInstallCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSearchInstallCallback, nsISearchInstallCallback)

nsSearchInstallCallback::nsSearchInstallCallback()
{
  /* member initializers and constructor code */
}

nsSearchInstallCallback::~nsSearchInstallCallback()
{
  /* destructor code */
}

/* void onSuccess (in nsISearchEngine engine); */
NS_IMETHODIMP nsSearchInstallCallback::OnSuccess(nsISearchEngine *engine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onError (in unsigned long errorCode); */
NS_IMETHODIMP nsSearchInstallCallback::OnError(uint32_t errorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBrowserSearchInitObserver */
#define NS_IBROWSERSEARCHINITOBSERVER_IID_STR "02256156-16e4-47f1-9979-76ff98ceb590"

#define NS_IBROWSERSEARCHINITOBSERVER_IID \
  {0x02256156, 0x16e4, 0x47f1, \
    { 0x99, 0x79, 0x76, 0xff, 0x98, 0xce, 0xb5, 0x90 }}

class NS_NO_VTABLE nsIBrowserSearchInitObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERSEARCHINITOBSERVER_IID)

  /* void onInitComplete (in nsresult aStatus); */
  NS_IMETHOD OnInitComplete(nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserSearchInitObserver, NS_IBROWSERSEARCHINITOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERSEARCHINITOBSERVER \
  NS_IMETHOD OnInitComplete(nsresult aStatus) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERSEARCHINITOBSERVER(_to) \
  NS_IMETHOD OnInitComplete(nsresult aStatus) override { return _to OnInitComplete(aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERSEARCHINITOBSERVER(_to) \
  NS_IMETHOD OnInitComplete(nsresult aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnInitComplete(aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserSearchInitObserver : public nsIBrowserSearchInitObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERSEARCHINITOBSERVER

  nsBrowserSearchInitObserver();

private:
  ~nsBrowserSearchInitObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsBrowserSearchInitObserver, nsIBrowserSearchInitObserver)

nsBrowserSearchInitObserver::nsBrowserSearchInitObserver()
{
  /* member initializers and constructor code */
}

nsBrowserSearchInitObserver::~nsBrowserSearchInitObserver()
{
  /* destructor code */
}

/* void onInitComplete (in nsresult aStatus); */
NS_IMETHODIMP nsBrowserSearchInitObserver::OnInitComplete(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBrowserSearchService */
#define NS_IBROWSERSEARCHSERVICE_IID_STR "150ef720-bbe2-4169-b9f3-ef7ec0654ced"

#define NS_IBROWSERSEARCHSERVICE_IID \
  {0x150ef720, 0xbbe2, 0x4169, \
    { 0xb9, 0xf3, 0xef, 0x7e, 0xc0, 0x65, 0x4c, 0xed }}

class NS_NO_VTABLE nsIBrowserSearchService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERSEARCHSERVICE_IID)

  /* void init ([optional] in nsIBrowserSearchInitObserver aObserver); */
  NS_IMETHOD Init(nsIBrowserSearchInitObserver *aObserver) = 0;

  /* readonly attribute bool isInitialized; */
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) = 0;

  /* void resetToOriginalDefaultEngine (); */
  NS_IMETHOD ResetToOriginalDefaultEngine(void) = 0;

  /* void addEngine (in AString engineURL, in long dataType, in AString iconURL, in boolean confirm, [optional] in nsISearchInstallCallback callback); */
  NS_IMETHOD AddEngine(const nsAString & engineURL, int32_t dataType, const nsAString & iconURL, bool confirm, nsISearchInstallCallback *callback) = 0;

  /* void addEngineWithDetails (in AString name, in AString iconURL, in AString alias, in AString description, in AString method, in AString url, [optional] in AString extensionID); */
  NS_IMETHOD AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url, const nsAString & extensionID) = 0;

  /* void restoreDefaultEngines (); */
  NS_IMETHOD RestoreDefaultEngines(void) = 0;

  /* nsISearchEngine getEngineByAlias (in AString alias); */
  NS_IMETHOD GetEngineByAlias(const nsAString & alias, nsISearchEngine * *_retval) = 0;

  /* nsISearchEngine getEngineByName (in AString aEngineName); */
  NS_IMETHOD GetEngineByName(const nsAString & aEngineName, nsISearchEngine * *_retval) = 0;

  /* void getEngines ([optional] out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
  NS_IMETHOD GetEngines(uint32_t *engineCount, nsISearchEngine * **engines) = 0;

  /* void getVisibleEngines ([optional] out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
  NS_IMETHOD GetVisibleEngines(uint32_t *engineCount, nsISearchEngine * **engines) = 0;

  /* void getDefaultEngines ([optional] out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
  NS_IMETHOD GetDefaultEngines(uint32_t *engineCount, nsISearchEngine * **engines) = 0;

  /* void moveEngine (in nsISearchEngine engine, in long newIndex); */
  NS_IMETHOD MoveEngine(nsISearchEngine *engine, int32_t newIndex) = 0;

  /* void removeEngine (in nsISearchEngine engine); */
  NS_IMETHOD RemoveEngine(nsISearchEngine *engine) = 0;

  /* attribute nsISearchEngine defaultEngine; */
  NS_IMETHOD GetDefaultEngine(nsISearchEngine * *aDefaultEngine) = 0;
  NS_IMETHOD SetDefaultEngine(nsISearchEngine *aDefaultEngine) = 0;

  /* attribute nsISearchEngine currentEngine; */
  NS_IMETHOD GetCurrentEngine(nsISearchEngine * *aCurrentEngine) = 0;
  NS_IMETHOD SetCurrentEngine(nsISearchEngine *aCurrentEngine) = 0;

  /* jsval getDefaultEngineInfo (); */
  NS_IMETHOD GetDefaultEngineInfo(JS::MutableHandleValue _retval) = 0;

  /* nsISearchParseSubmissionResult parseSubmissionURL (in AString url); */
  NS_IMETHOD ParseSubmissionURL(const nsAString & url, nsISearchParseSubmissionResult * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserSearchService, NS_IBROWSERSEARCHSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERSEARCHSERVICE \
  NS_IMETHOD Init(nsIBrowserSearchInitObserver *aObserver) override; \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) override; \
  NS_IMETHOD ResetToOriginalDefaultEngine(void) override; \
  NS_IMETHOD AddEngine(const nsAString & engineURL, int32_t dataType, const nsAString & iconURL, bool confirm, nsISearchInstallCallback *callback) override; \
  NS_IMETHOD AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url, const nsAString & extensionID) override; \
  NS_IMETHOD RestoreDefaultEngines(void) override; \
  NS_IMETHOD GetEngineByAlias(const nsAString & alias, nsISearchEngine * *_retval) override; \
  NS_IMETHOD GetEngineByName(const nsAString & aEngineName, nsISearchEngine * *_retval) override; \
  NS_IMETHOD GetEngines(uint32_t *engineCount, nsISearchEngine * **engines) override; \
  NS_IMETHOD GetVisibleEngines(uint32_t *engineCount, nsISearchEngine * **engines) override; \
  NS_IMETHOD GetDefaultEngines(uint32_t *engineCount, nsISearchEngine * **engines) override; \
  NS_IMETHOD MoveEngine(nsISearchEngine *engine, int32_t newIndex) override; \
  NS_IMETHOD RemoveEngine(nsISearchEngine *engine) override; \
  NS_IMETHOD GetDefaultEngine(nsISearchEngine * *aDefaultEngine) override; \
  NS_IMETHOD SetDefaultEngine(nsISearchEngine *aDefaultEngine) override; \
  NS_IMETHOD GetCurrentEngine(nsISearchEngine * *aCurrentEngine) override; \
  NS_IMETHOD SetCurrentEngine(nsISearchEngine *aCurrentEngine) override; \
  NS_IMETHOD GetDefaultEngineInfo(JS::MutableHandleValue _retval) override; \
  NS_IMETHOD ParseSubmissionURL(const nsAString & url, nsISearchParseSubmissionResult * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERSEARCHSERVICE(_to) \
  NS_IMETHOD Init(nsIBrowserSearchInitObserver *aObserver) override { return _to Init(aObserver); } \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) override { return _to GetIsInitialized(aIsInitialized); } \
  NS_IMETHOD ResetToOriginalDefaultEngine(void) override { return _to ResetToOriginalDefaultEngine(); } \
  NS_IMETHOD AddEngine(const nsAString & engineURL, int32_t dataType, const nsAString & iconURL, bool confirm, nsISearchInstallCallback *callback) override { return _to AddEngine(engineURL, dataType, iconURL, confirm, callback); } \
  NS_IMETHOD AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url, const nsAString & extensionID) override { return _to AddEngineWithDetails(name, iconURL, alias, description, method, url, extensionID); } \
  NS_IMETHOD RestoreDefaultEngines(void) override { return _to RestoreDefaultEngines(); } \
  NS_IMETHOD GetEngineByAlias(const nsAString & alias, nsISearchEngine * *_retval) override { return _to GetEngineByAlias(alias, _retval); } \
  NS_IMETHOD GetEngineByName(const nsAString & aEngineName, nsISearchEngine * *_retval) override { return _to GetEngineByName(aEngineName, _retval); } \
  NS_IMETHOD GetEngines(uint32_t *engineCount, nsISearchEngine * **engines) override { return _to GetEngines(engineCount, engines); } \
  NS_IMETHOD GetVisibleEngines(uint32_t *engineCount, nsISearchEngine * **engines) override { return _to GetVisibleEngines(engineCount, engines); } \
  NS_IMETHOD GetDefaultEngines(uint32_t *engineCount, nsISearchEngine * **engines) override { return _to GetDefaultEngines(engineCount, engines); } \
  NS_IMETHOD MoveEngine(nsISearchEngine *engine, int32_t newIndex) override { return _to MoveEngine(engine, newIndex); } \
  NS_IMETHOD RemoveEngine(nsISearchEngine *engine) override { return _to RemoveEngine(engine); } \
  NS_IMETHOD GetDefaultEngine(nsISearchEngine * *aDefaultEngine) override { return _to GetDefaultEngine(aDefaultEngine); } \
  NS_IMETHOD SetDefaultEngine(nsISearchEngine *aDefaultEngine) override { return _to SetDefaultEngine(aDefaultEngine); } \
  NS_IMETHOD GetCurrentEngine(nsISearchEngine * *aCurrentEngine) override { return _to GetCurrentEngine(aCurrentEngine); } \
  NS_IMETHOD SetCurrentEngine(nsISearchEngine *aCurrentEngine) override { return _to SetCurrentEngine(aCurrentEngine); } \
  NS_IMETHOD GetDefaultEngineInfo(JS::MutableHandleValue _retval) override { return _to GetDefaultEngineInfo(_retval); } \
  NS_IMETHOD ParseSubmissionURL(const nsAString & url, nsISearchParseSubmissionResult * *_retval) override { return _to ParseSubmissionURL(url, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERSEARCHSERVICE(_to) \
  NS_IMETHOD Init(nsIBrowserSearchInitObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aObserver); } \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInitialized(aIsInitialized); } \
  NS_IMETHOD ResetToOriginalDefaultEngine(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetToOriginalDefaultEngine(); } \
  NS_IMETHOD AddEngine(const nsAString & engineURL, int32_t dataType, const nsAString & iconURL, bool confirm, nsISearchInstallCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEngine(engineURL, dataType, iconURL, confirm, callback); } \
  NS_IMETHOD AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url, const nsAString & extensionID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEngineWithDetails(name, iconURL, alias, description, method, url, extensionID); } \
  NS_IMETHOD RestoreDefaultEngines(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreDefaultEngines(); } \
  NS_IMETHOD GetEngineByAlias(const nsAString & alias, nsISearchEngine * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEngineByAlias(alias, _retval); } \
  NS_IMETHOD GetEngineByName(const nsAString & aEngineName, nsISearchEngine * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEngineByName(aEngineName, _retval); } \
  NS_IMETHOD GetEngines(uint32_t *engineCount, nsISearchEngine * **engines) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEngines(engineCount, engines); } \
  NS_IMETHOD GetVisibleEngines(uint32_t *engineCount, nsISearchEngine * **engines) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisibleEngines(engineCount, engines); } \
  NS_IMETHOD GetDefaultEngines(uint32_t *engineCount, nsISearchEngine * **engines) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultEngines(engineCount, engines); } \
  NS_IMETHOD MoveEngine(nsISearchEngine *engine, int32_t newIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveEngine(engine, newIndex); } \
  NS_IMETHOD RemoveEngine(nsISearchEngine *engine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEngine(engine); } \
  NS_IMETHOD GetDefaultEngine(nsISearchEngine * *aDefaultEngine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultEngine(aDefaultEngine); } \
  NS_IMETHOD SetDefaultEngine(nsISearchEngine *aDefaultEngine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultEngine(aDefaultEngine); } \
  NS_IMETHOD GetCurrentEngine(nsISearchEngine * *aCurrentEngine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentEngine(aCurrentEngine); } \
  NS_IMETHOD SetCurrentEngine(nsISearchEngine *aCurrentEngine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentEngine(aCurrentEngine); } \
  NS_IMETHOD GetDefaultEngineInfo(JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultEngineInfo(_retval); } \
  NS_IMETHOD ParseSubmissionURL(const nsAString & url, nsISearchParseSubmissionResult * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseSubmissionURL(url, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserSearchService : public nsIBrowserSearchService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERSEARCHSERVICE

  nsBrowserSearchService();

private:
  ~nsBrowserSearchService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsBrowserSearchService, nsIBrowserSearchService)

nsBrowserSearchService::nsBrowserSearchService()
{
  /* member initializers and constructor code */
}

nsBrowserSearchService::~nsBrowserSearchService()
{
  /* destructor code */
}

/* void init ([optional] in nsIBrowserSearchInitObserver aObserver); */
NS_IMETHODIMP nsBrowserSearchService::Init(nsIBrowserSearchInitObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool isInitialized; */
NS_IMETHODIMP nsBrowserSearchService::GetIsInitialized(bool *aIsInitialized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetToOriginalDefaultEngine (); */
NS_IMETHODIMP nsBrowserSearchService::ResetToOriginalDefaultEngine()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEngine (in AString engineURL, in long dataType, in AString iconURL, in boolean confirm, [optional] in nsISearchInstallCallback callback); */
NS_IMETHODIMP nsBrowserSearchService::AddEngine(const nsAString & engineURL, int32_t dataType, const nsAString & iconURL, bool confirm, nsISearchInstallCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEngineWithDetails (in AString name, in AString iconURL, in AString alias, in AString description, in AString method, in AString url, [optional] in AString extensionID); */
NS_IMETHODIMP nsBrowserSearchService::AddEngineWithDetails(const nsAString & name, const nsAString & iconURL, const nsAString & alias, const nsAString & description, const nsAString & method, const nsAString & url, const nsAString & extensionID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreDefaultEngines (); */
NS_IMETHODIMP nsBrowserSearchService::RestoreDefaultEngines()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISearchEngine getEngineByAlias (in AString alias); */
NS_IMETHODIMP nsBrowserSearchService::GetEngineByAlias(const nsAString & alias, nsISearchEngine * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISearchEngine getEngineByName (in AString aEngineName); */
NS_IMETHODIMP nsBrowserSearchService::GetEngineByName(const nsAString & aEngineName, nsISearchEngine * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getEngines ([optional] out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
NS_IMETHODIMP nsBrowserSearchService::GetEngines(uint32_t *engineCount, nsISearchEngine * **engines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getVisibleEngines ([optional] out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
NS_IMETHODIMP nsBrowserSearchService::GetVisibleEngines(uint32_t *engineCount, nsISearchEngine * **engines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDefaultEngines ([optional] out unsigned long engineCount, [array, size_is (engineCount), retval] out nsISearchEngine engines); */
NS_IMETHODIMP nsBrowserSearchService::GetDefaultEngines(uint32_t *engineCount, nsISearchEngine * **engines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveEngine (in nsISearchEngine engine, in long newIndex); */
NS_IMETHODIMP nsBrowserSearchService::MoveEngine(nsISearchEngine *engine, int32_t newIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEngine (in nsISearchEngine engine); */
NS_IMETHODIMP nsBrowserSearchService::RemoveEngine(nsISearchEngine *engine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISearchEngine defaultEngine; */
NS_IMETHODIMP nsBrowserSearchService::GetDefaultEngine(nsISearchEngine * *aDefaultEngine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBrowserSearchService::SetDefaultEngine(nsISearchEngine *aDefaultEngine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISearchEngine currentEngine; */
NS_IMETHODIMP nsBrowserSearchService::GetCurrentEngine(nsISearchEngine * *aCurrentEngine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsBrowserSearchService::SetCurrentEngine(nsISearchEngine *aCurrentEngine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval getDefaultEngineInfo (); */
NS_IMETHODIMP nsBrowserSearchService::GetDefaultEngineInfo(JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISearchParseSubmissionResult parseSubmissionURL (in AString url); */
NS_IMETHODIMP nsBrowserSearchService::ParseSubmissionURL(const nsAString & url, nsISearchParseSubmissionResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * The observer topic to listen to for actions performed on installed
 * search engines.
 */
#define SEARCH_ENGINE_TOPIC "browser-search-engine-modified"
/**
 * Sent when an engine is removed from the data store.
 */
#define SEARCH_ENGINE_REMOVED      "engine-removed"
/**
 * Sent when an engine is changed. This includes when the engine's "hidden"
 * property is changed.
 */
#define SEARCH_ENGINE_CHANGED      "engine-changed"
/**
 * Sent when an engine is added to the list of available engines.
 */
#define SEARCH_ENGINE_ADDED        "engine-added"
/**
 * Sent when a search engine being installed from a remote plugin description
 * file is completely loaded. This is used internally by the search service as
 * an indication of when the engine can be added to the internal store, and
 * therefore should not be used to detect engine availability. It is always
 * followed by an "added" notification.
 */
#define SEARCH_ENGINE_LOADED       "engine-loaded"
/**
 * Sent when the "current" engine is changed.
 */
#define SEARCH_ENGINE_CURRENT      "engine-current";
/**
 * Sent when the "default" engine is changed.
 */
#define SEARCH_ENGINE_DEFAULT      "engine-default";

#endif /* __gen_nsIBrowserSearchService_h__ */
