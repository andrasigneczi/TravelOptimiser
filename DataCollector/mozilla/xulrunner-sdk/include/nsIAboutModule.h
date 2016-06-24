/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAboutModule.idl
 */

#ifndef __gen_nsIAboutModule_h__
#define __gen_nsIAboutModule_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsILoadInfo; /* forward declaration */


/* starting interface:    nsIAboutModule */
#define NS_IABOUTMODULE_IID_STR "c0c19db9-1b5a-4ac5-b656-ed6f8149fa48"

#define NS_IABOUTMODULE_IID \
  {0xc0c19db9, 0x1b5a, 0x4ac5, \
    { 0xb6, 0x56, 0xed, 0x6f, 0x81, 0x49, 0xfa, 0x48 }}

class NS_NO_VTABLE nsIAboutModule : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IABOUTMODULE_IID)

  /* nsIChannel newChannel (in nsIURI aURI, in nsILoadInfo aLoadInfo); */
  NS_IMETHOD NewChannel(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) = 0;

  enum {
    URI_SAFE_FOR_UNTRUSTED_CONTENT = 1U,
    ALLOW_SCRIPT = 2U,
    HIDE_FROM_ABOUTABOUT = 4U,
    ENABLE_INDEXED_DB = 8U,
    URI_CAN_LOAD_IN_CHILD = 16U,
    URI_MUST_LOAD_IN_CHILD = 32U,
    MAKE_UNLINKABLE = 64U
  };

  /* unsigned long getURIFlags (in nsIURI aURI); */
  NS_IMETHOD GetURIFlags(nsIURI *aURI, uint32_t *_retval) = 0;

  /* DOMString getIndexedDBOriginPostfix (in nsIURI aURI); */
  NS_IMETHOD GetIndexedDBOriginPostfix(nsIURI *aURI, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAboutModule, NS_IABOUTMODULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIABOUTMODULE \
  NS_IMETHOD NewChannel(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) override; \
  NS_IMETHOD GetURIFlags(nsIURI *aURI, uint32_t *_retval) override; \
  NS_IMETHOD GetIndexedDBOriginPostfix(nsIURI *aURI, nsAString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIABOUTMODULE(_to) \
  NS_IMETHOD NewChannel(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) override { return _to NewChannel(aURI, aLoadInfo, _retval); } \
  NS_IMETHOD GetURIFlags(nsIURI *aURI, uint32_t *_retval) override { return _to GetURIFlags(aURI, _retval); } \
  NS_IMETHOD GetIndexedDBOriginPostfix(nsIURI *aURI, nsAString & _retval) override { return _to GetIndexedDBOriginPostfix(aURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIABOUTMODULE(_to) \
  NS_IMETHOD NewChannel(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannel(aURI, aLoadInfo, _retval); } \
  NS_IMETHOD GetURIFlags(nsIURI *aURI, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURIFlags(aURI, _retval); } \
  NS_IMETHOD GetIndexedDBOriginPostfix(nsIURI *aURI, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexedDBOriginPostfix(aURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAboutModule : public nsIAboutModule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIABOUTMODULE

  nsAboutModule();

private:
  ~nsAboutModule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAboutModule, nsIAboutModule)

nsAboutModule::nsAboutModule()
{
  /* member initializers and constructor code */
}

nsAboutModule::~nsAboutModule()
{
  /* destructor code */
}

/* nsIChannel newChannel (in nsIURI aURI, in nsILoadInfo aLoadInfo); */
NS_IMETHODIMP nsAboutModule::NewChannel(nsIURI *aURI, nsILoadInfo *aLoadInfo, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getURIFlags (in nsIURI aURI); */
NS_IMETHODIMP nsAboutModule::GetURIFlags(nsIURI *aURI, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getIndexedDBOriginPostfix (in nsIURI aURI); */
NS_IMETHODIMP nsAboutModule::GetIndexedDBOriginPostfix(nsIURI *aURI, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_ABOUT_MODULE_CONTRACTID        "@mozilla.org/network/protocol/about;1" 
#define NS_ABOUT_MODULE_CONTRACTID_PREFIX NS_ABOUT_MODULE_CONTRACTID "?what=" 
#define NS_ABOUT_MODULE_CONTRACTID_LENGTH 49      // strlen(NS_ABOUT_MODULE_CONTRACTID_PREFIX)

#endif /* __gen_nsIAboutModule_h__ */
