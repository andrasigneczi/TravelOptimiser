/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\amIWebInstaller.idl
 */

#ifndef __gen_amIWebInstaller_h__
#define __gen_amIWebInstaller_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    amIInstallCallback */
#define AMIINSTALLCALLBACK_IID_STR "bb22f5c0-3ca1-48f6-873c-54e87987700f"

#define AMIINSTALLCALLBACK_IID \
  {0xbb22f5c0, 0x3ca1, 0x48f6, \
    { 0x87, 0x3c, 0x54, 0xe8, 0x79, 0x87, 0x70, 0x0f }}

class NS_NO_VTABLE amIInstallCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIINSTALLCALLBACK_IID)

  /* void onInstallEnded (in AString aUrl, in int32_t aStatus); */
  NS_IMETHOD OnInstallEnded(const nsAString & aUrl, int32_t aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIInstallCallback, AMIINSTALLCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIINSTALLCALLBACK \
  NS_IMETHOD OnInstallEnded(const nsAString & aUrl, int32_t aStatus) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIINSTALLCALLBACK(_to) \
  NS_IMETHOD OnInstallEnded(const nsAString & aUrl, int32_t aStatus) override { return _to OnInstallEnded(aUrl, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIINSTALLCALLBACK(_to) \
  NS_IMETHOD OnInstallEnded(const nsAString & aUrl, int32_t aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnInstallEnded(aUrl, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amInstallCallback : public amIInstallCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIINSTALLCALLBACK

  amInstallCallback();

private:
  ~amInstallCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(amInstallCallback, amIInstallCallback)

amInstallCallback::amInstallCallback()
{
  /* member initializers and constructor code */
}

amInstallCallback::~amInstallCallback()
{
  /* destructor code */
}

/* void onInstallEnded (in AString aUrl, in int32_t aStatus); */
NS_IMETHODIMP amInstallCallback::OnInstallEnded(const nsAString & aUrl, int32_t aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    amIWebInstaller */
#define AMIWEBINSTALLER_IID_STR "658d6c09-15e0-4688-bee8-8551030472a9"

#define AMIWEBINSTALLER_IID \
  {0x658d6c09, 0x15e0, 0x4688, \
    { 0xbe, 0xe8, 0x85, 0x51, 0x03, 0x04, 0x72, 0xa9 }}

class NS_NO_VTABLE amIWebInstaller : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLER_IID)

  /* boolean isInstallEnabled (in AString aMimetype, in nsIURI aReferer); */
  NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval) = 0;

  /* boolean installAddonsFromWebpage (in AString aMimetype, in nsIDOMElement aBrowser, in nsIURI aReferer, [array, size_is (aInstallCount)] in wstring aUris, [array, size_is (aInstallCount)] in wstring aHashes, [array, size_is (aInstallCount)] in wstring aNames, [array, size_is (aInstallCount)] in wstring aIcons, [optional] in amIInstallCallback aCallback, [optional] in uint32_t aInstallCount); */
  NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMElement *aBrowser, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstaller, AMIWEBINSTALLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLER \
  NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval) override; \
  NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMElement *aBrowser, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLER(_to) \
  NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval) override { return _to IsInstallEnabled(aMimetype, aReferer, _retval); } \
  NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMElement *aBrowser, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval) override { return _to InstallAddonsFromWebpage(aMimetype, aBrowser, aReferer, aUris, aHashes, aNames, aIcons, aCallback, aInstallCount, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLER(_to) \
  NS_IMETHOD IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsInstallEnabled(aMimetype, aReferer, _retval); } \
  NS_IMETHOD InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMElement *aBrowser, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallAddonsFromWebpage(aMimetype, aBrowser, aReferer, aUris, aHashes, aNames, aIcons, aCallback, aInstallCount, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amWebInstaller : public amIWebInstaller
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIWEBINSTALLER

  amWebInstaller();

private:
  ~amWebInstaller();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(amWebInstaller, amIWebInstaller)

amWebInstaller::amWebInstaller()
{
  /* member initializers and constructor code */
}

amWebInstaller::~amWebInstaller()
{
  /* destructor code */
}

/* boolean isInstallEnabled (in AString aMimetype, in nsIURI aReferer); */
NS_IMETHODIMP amWebInstaller::IsInstallEnabled(const nsAString & aMimetype, nsIURI *aReferer, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean installAddonsFromWebpage (in AString aMimetype, in nsIDOMElement aBrowser, in nsIURI aReferer, [array, size_is (aInstallCount)] in wstring aUris, [array, size_is (aInstallCount)] in wstring aHashes, [array, size_is (aInstallCount)] in wstring aNames, [array, size_is (aInstallCount)] in wstring aIcons, [optional] in amIInstallCallback aCallback, [optional] in uint32_t aInstallCount); */
NS_IMETHODIMP amWebInstaller::InstallAddonsFromWebpage(const nsAString & aMimetype, nsIDOMElement *aBrowser, nsIURI *aReferer, const char16_t * *aUris, const char16_t * *aHashes, const char16_t * *aNames, const char16_t * *aIcons, amIInstallCallback *aCallback, uint32_t aInstallCount, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_amIWebInstaller_h__ */
