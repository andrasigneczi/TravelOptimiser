/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIChromeRegistry.idl
 */

#ifndef __gen_nsIChromeRegistry_h__
#define __gen_nsIChromeRegistry_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIChromeRegistry */
#define NS_ICHROMEREGISTRY_IID_STR "249fb5ad-ae29-4e2c-a728-ba5cf464d188"

#define NS_ICHROMEREGISTRY_IID \
  {0x249fb5ad, 0xae29, 0x4e2c, \
    { 0xa7, 0x28, 0xba, 0x5c, 0xf4, 0x64, 0xd1, 0x88 }}

class NS_NO_VTABLE nsIChromeRegistry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHROMEREGISTRY_IID)

  enum {
    NONE = 0,
    PARTIAL = 1,
    FULL = 2
  };

  /* nsIURI convertChromeURL (in nsIURI aChromeURL); */
  NS_IMETHOD ConvertChromeURL(nsIURI *aChromeURL, nsIURI * *_retval) = 0;

  /* void checkForNewChrome (); */
  NS_IMETHOD CheckForNewChrome(void) = 0;

  /* [notxpcom] boolean wrappersEnabled (in nsIURI aURI); */
  NS_IMETHOD_(bool) WrappersEnabled(nsIURI *aURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIChromeRegistry, NS_ICHROMEREGISTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHROMEREGISTRY \
  NS_IMETHOD ConvertChromeURL(nsIURI *aChromeURL, nsIURI * *_retval) override; \
  NS_IMETHOD CheckForNewChrome(void) override; \
  NS_IMETHOD_(bool) WrappersEnabled(nsIURI *aURI) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHROMEREGISTRY(_to) \
  NS_IMETHOD ConvertChromeURL(nsIURI *aChromeURL, nsIURI * *_retval) override { return _to ConvertChromeURL(aChromeURL, _retval); } \
  NS_IMETHOD CheckForNewChrome(void) override { return _to CheckForNewChrome(); } \
  NS_IMETHOD_(bool) WrappersEnabled(nsIURI *aURI) override { return _to WrappersEnabled(aURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHROMEREGISTRY(_to) \
  NS_IMETHOD ConvertChromeURL(nsIURI *aChromeURL, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertChromeURL(aChromeURL, _retval); } \
  NS_IMETHOD CheckForNewChrome(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForNewChrome(); } \
  NS_IMETHOD_(bool) WrappersEnabled(nsIURI *aURI) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsChromeRegistry : public nsIChromeRegistry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHROMEREGISTRY

  nsChromeRegistry();

private:
  ~nsChromeRegistry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsChromeRegistry, nsIChromeRegistry)

nsChromeRegistry::nsChromeRegistry()
{
  /* member initializers and constructor code */
}

nsChromeRegistry::~nsChromeRegistry()
{
  /* destructor code */
}

/* nsIURI convertChromeURL (in nsIURI aChromeURL); */
NS_IMETHODIMP nsChromeRegistry::ConvertChromeURL(nsIURI *aChromeURL, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkForNewChrome (); */
NS_IMETHODIMP nsChromeRegistry::CheckForNewChrome()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean wrappersEnabled (in nsIURI aURI); */
NS_IMETHODIMP_(bool) nsChromeRegistry::WrappersEnabled(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXULChromeRegistry */
#define NS_IXULCHROMEREGISTRY_IID_STR "93251ddf-5e85-4172-ac2a-31780562974f"

#define NS_IXULCHROMEREGISTRY_IID \
  {0x93251ddf, 0x5e85, 0x4172, \
    { 0xac, 0x2a, 0x31, 0x78, 0x05, 0x62, 0x97, 0x4f }}

class NS_NO_VTABLE nsIXULChromeRegistry : public nsIChromeRegistry {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULCHROMEREGISTRY_IID)

  /* void reloadChrome (); */
  NS_IMETHOD ReloadChrome(void) = 0;

  /* ACString getSelectedLocale (in ACString packageName); */
  NS_IMETHOD GetSelectedLocale(const nsACString & packageName, nsACString & _retval) = 0;

  /* boolean isLocaleRTL (in ACString package); */
  NS_IMETHOD IsLocaleRTL(const nsACString & package, bool *_retval) = 0;

  /* void refreshSkins (); */
  NS_IMETHOD RefreshSkins(void) = 0;

  /* boolean allowScriptsForPackage (in nsIURI url); */
  NS_IMETHOD AllowScriptsForPackage(nsIURI *url, bool *_retval) = 0;

  /* boolean allowContentToAccess (in nsIURI url); */
  NS_IMETHOD AllowContentToAccess(nsIURI *url, bool *_retval) = 0;

  /* boolean canLoadURLRemotely (in nsIURI url); */
  NS_IMETHOD CanLoadURLRemotely(nsIURI *url, bool *_retval) = 0;

  /* boolean mustLoadURLRemotely (in nsIURI url); */
  NS_IMETHOD MustLoadURLRemotely(nsIURI *url, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULChromeRegistry, NS_IXULCHROMEREGISTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULCHROMEREGISTRY \
  NS_IMETHOD ReloadChrome(void) override; \
  NS_IMETHOD GetSelectedLocale(const nsACString & packageName, nsACString & _retval) override; \
  NS_IMETHOD IsLocaleRTL(const nsACString & package, bool *_retval) override; \
  NS_IMETHOD RefreshSkins(void) override; \
  NS_IMETHOD AllowScriptsForPackage(nsIURI *url, bool *_retval) override; \
  NS_IMETHOD AllowContentToAccess(nsIURI *url, bool *_retval) override; \
  NS_IMETHOD CanLoadURLRemotely(nsIURI *url, bool *_retval) override; \
  NS_IMETHOD MustLoadURLRemotely(nsIURI *url, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULCHROMEREGISTRY(_to) \
  NS_IMETHOD ReloadChrome(void) override { return _to ReloadChrome(); } \
  NS_IMETHOD GetSelectedLocale(const nsACString & packageName, nsACString & _retval) override { return _to GetSelectedLocale(packageName, _retval); } \
  NS_IMETHOD IsLocaleRTL(const nsACString & package, bool *_retval) override { return _to IsLocaleRTL(package, _retval); } \
  NS_IMETHOD RefreshSkins(void) override { return _to RefreshSkins(); } \
  NS_IMETHOD AllowScriptsForPackage(nsIURI *url, bool *_retval) override { return _to AllowScriptsForPackage(url, _retval); } \
  NS_IMETHOD AllowContentToAccess(nsIURI *url, bool *_retval) override { return _to AllowContentToAccess(url, _retval); } \
  NS_IMETHOD CanLoadURLRemotely(nsIURI *url, bool *_retval) override { return _to CanLoadURLRemotely(url, _retval); } \
  NS_IMETHOD MustLoadURLRemotely(nsIURI *url, bool *_retval) override { return _to MustLoadURLRemotely(url, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULCHROMEREGISTRY(_to) \
  NS_IMETHOD ReloadChrome(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadChrome(); } \
  NS_IMETHOD GetSelectedLocale(const nsACString & packageName, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedLocale(packageName, _retval); } \
  NS_IMETHOD IsLocaleRTL(const nsACString & package, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLocaleRTL(package, _retval); } \
  NS_IMETHOD RefreshSkins(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshSkins(); } \
  NS_IMETHOD AllowScriptsForPackage(nsIURI *url, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AllowScriptsForPackage(url, _retval); } \
  NS_IMETHOD AllowContentToAccess(nsIURI *url, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AllowContentToAccess(url, _retval); } \
  NS_IMETHOD CanLoadURLRemotely(nsIURI *url, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanLoadURLRemotely(url, _retval); } \
  NS_IMETHOD MustLoadURLRemotely(nsIURI *url, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MustLoadURLRemotely(url, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULChromeRegistry : public nsIXULChromeRegistry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULCHROMEREGISTRY

  nsXULChromeRegistry();

private:
  ~nsXULChromeRegistry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXULChromeRegistry, nsIXULChromeRegistry)

nsXULChromeRegistry::nsXULChromeRegistry()
{
  /* member initializers and constructor code */
}

nsXULChromeRegistry::~nsXULChromeRegistry()
{
  /* destructor code */
}

/* void reloadChrome (); */
NS_IMETHODIMP nsXULChromeRegistry::ReloadChrome()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getSelectedLocale (in ACString packageName); */
NS_IMETHODIMP nsXULChromeRegistry::GetSelectedLocale(const nsACString & packageName, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLocaleRTL (in ACString package); */
NS_IMETHODIMP nsXULChromeRegistry::IsLocaleRTL(const nsACString & package, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshSkins (); */
NS_IMETHODIMP nsXULChromeRegistry::RefreshSkins()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean allowScriptsForPackage (in nsIURI url); */
NS_IMETHODIMP nsXULChromeRegistry::AllowScriptsForPackage(nsIURI *url, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean allowContentToAccess (in nsIURI url); */
NS_IMETHODIMP nsXULChromeRegistry::AllowContentToAccess(nsIURI *url, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canLoadURLRemotely (in nsIURI url); */
NS_IMETHODIMP nsXULChromeRegistry::CanLoadURLRemotely(nsIURI *url, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean mustLoadURLRemotely (in nsIURI url); */
NS_IMETHODIMP nsXULChromeRegistry::MustLoadURLRemotely(nsIURI *url, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_CHROMEREGISTRY_CONTRACTID \
  "@mozilla.org/chrome/chrome-registry;1"
/**
 * Chrome registry will notify various caches that all chrome files need
 * flushing.
 */
#define NS_CHROME_FLUSH_TOPIC \
  "chrome-flush-caches"
/**
 * Chrome registry will notify various caches that skin files need flushing.
 * If "chrome-flush-caches" is notified, this topic will *not* be notified.
 */
#define NS_CHROME_FLUSH_SKINS_TOPIC \
  "chrome-flush-skin-caches"

#endif /* __gen_nsIChromeRegistry_h__ */
