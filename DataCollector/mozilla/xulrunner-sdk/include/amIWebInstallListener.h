/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\amIWebInstallListener.idl
 */

#ifndef __gen_amIWebInstallListener_h__
#define __gen_amIWebInstallListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    amIWebInstallInfo */
#define AMIWEBINSTALLINFO_IID_STR "fa0b47a3-f819-47ac-bc66-4bd1d7f67b1d"

#define AMIWEBINSTALLINFO_IID \
  {0xfa0b47a3, 0xf819, 0x47ac, \
    { 0xbc, 0x66, 0x4b, 0xd1, 0xd7, 0xf6, 0x7b, 0x1d }}

class NS_NO_VTABLE amIWebInstallInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLINFO_IID)

  /* readonly attribute nsIDOMElement browser; */
  NS_IMETHOD GetBrowser(nsIDOMElement * *aBrowser) = 0;

  /* readonly attribute nsIURI originatingURI; */
  NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) = 0;

  /* readonly attribute nsIVariant installs; */
  NS_IMETHOD GetInstalls(nsIVariant * *aInstalls) = 0;

  /* void install (); */
  NS_IMETHOD Install(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallInfo, AMIWEBINSTALLINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLINFO \
  NS_IMETHOD GetBrowser(nsIDOMElement * *aBrowser) override; \
  NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) override; \
  NS_IMETHOD GetInstalls(nsIVariant * *aInstalls) override; \
  NS_IMETHOD Install(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLINFO(_to) \
  NS_IMETHOD GetBrowser(nsIDOMElement * *aBrowser) override { return _to GetBrowser(aBrowser); } \
  NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) override { return _to GetOriginatingURI(aOriginatingURI); } \
  NS_IMETHOD GetInstalls(nsIVariant * *aInstalls) override { return _to GetInstalls(aInstalls); } \
  NS_IMETHOD Install(void) override { return _to Install(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLINFO(_to) \
  NS_IMETHOD GetBrowser(nsIDOMElement * *aBrowser) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBrowser(aBrowser); } \
  NS_IMETHOD GetOriginatingURI(nsIURI * *aOriginatingURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginatingURI(aOriginatingURI); } \
  NS_IMETHOD GetInstalls(nsIVariant * *aInstalls) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstalls(aInstalls); } \
  NS_IMETHOD Install(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Install(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amWebInstallInfo : public amIWebInstallInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIWEBINSTALLINFO

  amWebInstallInfo();

private:
  ~amWebInstallInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(amWebInstallInfo, amIWebInstallInfo)

amWebInstallInfo::amWebInstallInfo()
{
  /* member initializers and constructor code */
}

amWebInstallInfo::~amWebInstallInfo()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement browser; */
NS_IMETHODIMP amWebInstallInfo::GetBrowser(nsIDOMElement * *aBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI originatingURI; */
NS_IMETHODIMP amWebInstallInfo::GetOriginatingURI(nsIURI * *aOriginatingURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant installs; */
NS_IMETHODIMP amWebInstallInfo::GetInstalls(nsIVariant * *aInstalls)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void install (); */
NS_IMETHODIMP amWebInstallInfo::Install()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    amIWebInstallListener */
#define AMIWEBINSTALLLISTENER_IID_STR "d9240d4b-6b3a-4cad-b402-de6c93337e0c"

#define AMIWEBINSTALLLISTENER_IID \
  {0xd9240d4b, 0x6b3a, 0x4cad, \
    { 0xb4, 0x02, 0xde, 0x6c, 0x93, 0x33, 0x7e, 0x0c }}

class NS_NO_VTABLE amIWebInstallListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLLISTENER_IID)

  /* void onWebInstallDisabled (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
  NS_IMETHOD OnWebInstallDisabled(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) = 0;

  /* boolean onWebInstallBlocked (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
  NS_IMETHOD OnWebInstallBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) = 0;

  /* boolean onWebInstallRequested (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
  NS_IMETHOD OnWebInstallRequested(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallListener, AMIWEBINSTALLLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLLISTENER \
  NS_IMETHOD OnWebInstallDisabled(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) override; \
  NS_IMETHOD OnWebInstallBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) override; \
  NS_IMETHOD OnWebInstallRequested(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLLISTENER(_to) \
  NS_IMETHOD OnWebInstallDisabled(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) override { return _to OnWebInstallDisabled(aBrowser, aUri, aInstalls, aCount); } \
  NS_IMETHOD OnWebInstallBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) override { return _to OnWebInstallBlocked(aBrowser, aUri, aInstalls, aCount, _retval); } \
  NS_IMETHOD OnWebInstallRequested(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) override { return _to OnWebInstallRequested(aBrowser, aUri, aInstalls, aCount, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLLISTENER(_to) \
  NS_IMETHOD OnWebInstallDisabled(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallDisabled(aBrowser, aUri, aInstalls, aCount); } \
  NS_IMETHOD OnWebInstallBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallBlocked(aBrowser, aUri, aInstalls, aCount, _retval); } \
  NS_IMETHOD OnWebInstallRequested(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallRequested(aBrowser, aUri, aInstalls, aCount, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amWebInstallListener : public amIWebInstallListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIWEBINSTALLLISTENER

  amWebInstallListener();

private:
  ~amWebInstallListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(amWebInstallListener, amIWebInstallListener)

amWebInstallListener::amWebInstallListener()
{
  /* member initializers and constructor code */
}

amWebInstallListener::~amWebInstallListener()
{
  /* destructor code */
}

/* void onWebInstallDisabled (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
NS_IMETHODIMP amWebInstallListener::OnWebInstallDisabled(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onWebInstallBlocked (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
NS_IMETHODIMP amWebInstallListener::OnWebInstallBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onWebInstallRequested (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
NS_IMETHODIMP amWebInstallListener::OnWebInstallRequested(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    amIWebInstallListener2 */
#define AMIWEBINSTALLLISTENER2_IID_STR "a80b89ad-bb1a-4c43-9cb7-3ae656556f78"

#define AMIWEBINSTALLLISTENER2_IID \
  {0xa80b89ad, 0xbb1a, 0x4c43, \
    { 0x9c, 0xb7, 0x3a, 0xe6, 0x56, 0x55, 0x6f, 0x78 }}

class NS_NO_VTABLE amIWebInstallListener2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLLISTENER2_IID)

  /* boolean onWebInstallOriginBlocked (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
  NS_IMETHOD OnWebInstallOriginBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallListener2, AMIWEBINSTALLLISTENER2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLLISTENER2 \
  NS_IMETHOD OnWebInstallOriginBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLLISTENER2(_to) \
  NS_IMETHOD OnWebInstallOriginBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) override { return _to OnWebInstallOriginBlocked(aBrowser, aUri, aInstalls, aCount, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLLISTENER2(_to) \
  NS_IMETHOD OnWebInstallOriginBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnWebInstallOriginBlocked(aBrowser, aUri, aInstalls, aCount, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amWebInstallListener2 : public amIWebInstallListener2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIWEBINSTALLLISTENER2

  amWebInstallListener2();

private:
  ~amWebInstallListener2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(amWebInstallListener2, amIWebInstallListener2)

amWebInstallListener2::amWebInstallListener2()
{
  /* member initializers and constructor code */
}

amWebInstallListener2::~amWebInstallListener2()
{
  /* destructor code */
}

/* boolean onWebInstallOriginBlocked (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
NS_IMETHODIMP amWebInstallListener2::OnWebInstallOriginBlocked(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    amIWebInstallPrompt */
#define AMIWEBINSTALLPROMPT_IID_STR "386906f1-4d18-45bf-bc81-5dcd68e42c3b"

#define AMIWEBINSTALLPROMPT_IID \
  {0x386906f1, 0x4d18, 0x45bf, \
    { 0xbc, 0x81, 0x5d, 0xcd, 0x68, 0xe4, 0x2c, 0x3b }}

class NS_NO_VTABLE amIWebInstallPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIWEBINSTALLPROMPT_IID)

  /* void confirm (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
  NS_IMETHOD Confirm(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIWebInstallPrompt, AMIWEBINSTALLPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIWEBINSTALLPROMPT \
  NS_IMETHOD Confirm(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIWEBINSTALLPROMPT(_to) \
  NS_IMETHOD Confirm(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) override { return _to Confirm(aBrowser, aUri, aInstalls, aCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIWEBINSTALLPROMPT(_to) \
  NS_IMETHOD Confirm(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Confirm(aBrowser, aUri, aInstalls, aCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amWebInstallPrompt : public amIWebInstallPrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIWEBINSTALLPROMPT

  amWebInstallPrompt();

private:
  ~amWebInstallPrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(amWebInstallPrompt, amIWebInstallPrompt)

amWebInstallPrompt::amWebInstallPrompt()
{
  /* member initializers and constructor code */
}

amWebInstallPrompt::~amWebInstallPrompt()
{
  /* destructor code */
}

/* void confirm (in nsIDOMElement aBrowser, in nsIURI aUri, [array, size_is (aCount)] in nsIVariant aInstalls, [optional] in uint32_t aCount); */
NS_IMETHODIMP amWebInstallPrompt::Confirm(nsIDOMElement *aBrowser, nsIURI *aUri, nsIVariant **aInstalls, uint32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_amIWebInstallListener_h__ */
