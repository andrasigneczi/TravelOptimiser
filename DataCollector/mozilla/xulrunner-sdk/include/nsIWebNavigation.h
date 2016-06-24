/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebNavigation.idl
 */

#ifndef __gen_nsIWebNavigation_h__
#define __gen_nsIWebNavigation_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsISHistory; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIWebNavigation */
#define NS_IWEBNAVIGATION_IID_STR "0e92d522-53a5-4af6-9a24-4eccdcbf4f91"

#define NS_IWEBNAVIGATION_IID \
  {0x0e92d522, 0x53a5, 0x4af6, \
    { 0x9a, 0x24, 0x4e, 0xcc, 0xdc, 0xbf, 0x4f, 0x91 }}

class NS_NO_VTABLE nsIWebNavigation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBNAVIGATION_IID)

  /* readonly attribute boolean canGoBack; */
  NS_IMETHOD GetCanGoBack(bool *aCanGoBack) = 0;

  /* readonly attribute boolean canGoForward; */
  NS_IMETHOD GetCanGoForward(bool *aCanGoForward) = 0;

  /* void goBack (); */
  NS_IMETHOD GoBack(void) = 0;

  /* void goForward (); */
  NS_IMETHOD GoForward(void) = 0;

  /* void gotoIndex (in long index); */
  NS_IMETHOD GotoIndex(int32_t index) = 0;

  enum {
    LOAD_FLAGS_MASK = 65535U,
    LOAD_FLAGS_NONE = 0U,
    LOAD_FLAGS_IS_REFRESH = 16U,
    LOAD_FLAGS_IS_LINK = 32U,
    LOAD_FLAGS_BYPASS_HISTORY = 64U,
    LOAD_FLAGS_REPLACE_HISTORY = 128U,
    LOAD_FLAGS_BYPASS_CACHE = 256U,
    LOAD_FLAGS_BYPASS_PROXY = 512U,
    LOAD_FLAGS_CHARSET_CHANGE = 1024U,
    LOAD_FLAGS_STOP_CONTENT = 2048U,
    LOAD_FLAGS_FROM_EXTERNAL = 4096U,
    LOAD_FLAGS_ALLOW_MIXED_CONTENT = 8192U,
    LOAD_FLAGS_FIRST_LOAD = 16384U,
    LOAD_FLAGS_ALLOW_POPUPS = 32768U,
    LOAD_FLAGS_BYPASS_CLASSIFIER = 65536U,
    LOAD_FLAGS_FORCE_ALLOW_COOKIES = 131072U,
    LOAD_FLAGS_DISALLOW_INHERIT_OWNER = 262144U,
    LOAD_FLAGS_ALLOW_THIRD_PARTY_FIXUP = 1048576U,
    LOAD_FLAGS_FIXUP_SCHEME_TYPOS = 2097152U
  };

  /* void loadURI (in wstring aURI, in unsigned long aLoadFlags, in nsIURI aReferrer, in nsIInputStream aPostData, in nsIInputStream aHeaders); */
  NS_IMETHOD LoadURI(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders) = 0;

  /* void loadURIWithOptions (in wstring aURI, in unsigned long aLoadFlags, in nsIURI aReferrer, in unsigned long aReferrerPolicy, in nsIInputStream aPostData, in nsIInputStream aHeaders, in nsIURI aBaseURI); */
  NS_IMETHOD LoadURIWithOptions(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsIInputStream *aPostData, nsIInputStream *aHeaders, nsIURI *aBaseURI) = 0;

  /* void reload (in unsigned long aReloadFlags); */
  NS_IMETHOD Reload(uint32_t aReloadFlags) = 0;

  enum {
    STOP_NETWORK = 1U,
    STOP_CONTENT = 2U,
    STOP_ALL = 3U
  };

  /* void stop (in unsigned long aStopFlags); */
  NS_IMETHOD Stop(uint32_t aStopFlags) = 0;

  /* readonly attribute nsIDOMDocument document; */
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) = 0;

  /* readonly attribute nsIURI currentURI; */
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) = 0;

  /* readonly attribute nsIURI referringURI; */
  NS_IMETHOD GetReferringURI(nsIURI * *aReferringURI) = 0;

  /* attribute nsISHistory sessionHistory; */
  NS_IMETHOD GetSessionHistory(nsISHistory * *aSessionHistory) = 0;
  NS_IMETHOD SetSessionHistory(nsISHistory *aSessionHistory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebNavigation, NS_IWEBNAVIGATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBNAVIGATION \
  NS_IMETHOD GetCanGoBack(bool *aCanGoBack) override; \
  NS_IMETHOD GetCanGoForward(bool *aCanGoForward) override; \
  NS_IMETHOD GoBack(void) override; \
  NS_IMETHOD GoForward(void) override; \
  NS_IMETHOD GotoIndex(int32_t index) override; \
  NS_IMETHOD LoadURI(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders) override; \
  NS_IMETHOD LoadURIWithOptions(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsIInputStream *aPostData, nsIInputStream *aHeaders, nsIURI *aBaseURI) override; \
  NS_IMETHOD Reload(uint32_t aReloadFlags) override; \
  NS_IMETHOD Stop(uint32_t aStopFlags) override; \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override; \
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) override; \
  NS_IMETHOD GetReferringURI(nsIURI * *aReferringURI) override; \
  NS_IMETHOD GetSessionHistory(nsISHistory * *aSessionHistory) override; \
  NS_IMETHOD SetSessionHistory(nsISHistory *aSessionHistory) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBNAVIGATION(_to) \
  NS_IMETHOD GetCanGoBack(bool *aCanGoBack) override { return _to GetCanGoBack(aCanGoBack); } \
  NS_IMETHOD GetCanGoForward(bool *aCanGoForward) override { return _to GetCanGoForward(aCanGoForward); } \
  NS_IMETHOD GoBack(void) override { return _to GoBack(); } \
  NS_IMETHOD GoForward(void) override { return _to GoForward(); } \
  NS_IMETHOD GotoIndex(int32_t index) override { return _to GotoIndex(index); } \
  NS_IMETHOD LoadURI(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders) override { return _to LoadURI(aURI, aLoadFlags, aReferrer, aPostData, aHeaders); } \
  NS_IMETHOD LoadURIWithOptions(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsIInputStream *aPostData, nsIInputStream *aHeaders, nsIURI *aBaseURI) override { return _to LoadURIWithOptions(aURI, aLoadFlags, aReferrer, aReferrerPolicy, aPostData, aHeaders, aBaseURI); } \
  NS_IMETHOD Reload(uint32_t aReloadFlags) override { return _to Reload(aReloadFlags); } \
  NS_IMETHOD Stop(uint32_t aStopFlags) override { return _to Stop(aStopFlags); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override { return _to GetDocument(aDocument); } \
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) override { return _to GetCurrentURI(aCurrentURI); } \
  NS_IMETHOD GetReferringURI(nsIURI * *aReferringURI) override { return _to GetReferringURI(aReferringURI); } \
  NS_IMETHOD GetSessionHistory(nsISHistory * *aSessionHistory) override { return _to GetSessionHistory(aSessionHistory); } \
  NS_IMETHOD SetSessionHistory(nsISHistory *aSessionHistory) override { return _to SetSessionHistory(aSessionHistory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBNAVIGATION(_to) \
  NS_IMETHOD GetCanGoBack(bool *aCanGoBack) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanGoBack(aCanGoBack); } \
  NS_IMETHOD GetCanGoForward(bool *aCanGoForward) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanGoForward(aCanGoForward); } \
  NS_IMETHOD GoBack(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GoBack(); } \
  NS_IMETHOD GoForward(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GoForward(); } \
  NS_IMETHOD GotoIndex(int32_t index) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GotoIndex(index); } \
  NS_IMETHOD LoadURI(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURI(aURI, aLoadFlags, aReferrer, aPostData, aHeaders); } \
  NS_IMETHOD LoadURIWithOptions(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsIInputStream *aPostData, nsIInputStream *aHeaders, nsIURI *aBaseURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURIWithOptions(aURI, aLoadFlags, aReferrer, aReferrerPolicy, aPostData, aHeaders, aBaseURI); } \
  NS_IMETHOD Reload(uint32_t aReloadFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Reload(aReloadFlags); } \
  NS_IMETHOD Stop(uint32_t aStopFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(aStopFlags); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentURI(aCurrentURI); } \
  NS_IMETHOD GetReferringURI(nsIURI * *aReferringURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferringURI(aReferringURI); } \
  NS_IMETHOD GetSessionHistory(nsISHistory * *aSessionHistory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionHistory(aSessionHistory); } \
  NS_IMETHOD SetSessionHistory(nsISHistory *aSessionHistory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSessionHistory(aSessionHistory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebNavigation : public nsIWebNavigation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBNAVIGATION

  nsWebNavigation();

private:
  ~nsWebNavigation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsWebNavigation, nsIWebNavigation)

nsWebNavigation::nsWebNavigation()
{
  /* member initializers and constructor code */
}

nsWebNavigation::~nsWebNavigation()
{
  /* destructor code */
}

/* readonly attribute boolean canGoBack; */
NS_IMETHODIMP nsWebNavigation::GetCanGoBack(bool *aCanGoBack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canGoForward; */
NS_IMETHODIMP nsWebNavigation::GetCanGoForward(bool *aCanGoForward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void goBack (); */
NS_IMETHODIMP nsWebNavigation::GoBack()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void goForward (); */
NS_IMETHODIMP nsWebNavigation::GoForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void gotoIndex (in long index); */
NS_IMETHODIMP nsWebNavigation::GotoIndex(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadURI (in wstring aURI, in unsigned long aLoadFlags, in nsIURI aReferrer, in nsIInputStream aPostData, in nsIInputStream aHeaders); */
NS_IMETHODIMP nsWebNavigation::LoadURI(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, nsIInputStream *aPostData, nsIInputStream *aHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadURIWithOptions (in wstring aURI, in unsigned long aLoadFlags, in nsIURI aReferrer, in unsigned long aReferrerPolicy, in nsIInputStream aPostData, in nsIInputStream aHeaders, in nsIURI aBaseURI); */
NS_IMETHODIMP nsWebNavigation::LoadURIWithOptions(const char16_t * aURI, uint32_t aLoadFlags, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsIInputStream *aPostData, nsIInputStream *aHeaders, nsIURI *aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reload (in unsigned long aReloadFlags); */
NS_IMETHODIMP nsWebNavigation::Reload(uint32_t aReloadFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (in unsigned long aStopFlags); */
NS_IMETHODIMP nsWebNavigation::Stop(uint32_t aStopFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument document; */
NS_IMETHODIMP nsWebNavigation::GetDocument(nsIDOMDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI currentURI; */
NS_IMETHODIMP nsWebNavigation::GetCurrentURI(nsIURI * *aCurrentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI referringURI; */
NS_IMETHODIMP nsWebNavigation::GetReferringURI(nsIURI * *aReferringURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISHistory sessionHistory; */
NS_IMETHODIMP nsWebNavigation::GetSessionHistory(nsISHistory * *aSessionHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebNavigation::SetSessionHistory(nsISHistory *aSessionHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebNavigation_h__ */
