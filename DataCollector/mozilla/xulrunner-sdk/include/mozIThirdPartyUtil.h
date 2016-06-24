/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIThirdPartyUtil.idl
 */

#ifndef __gen_mozIThirdPartyUtil_h__
#define __gen_mozIThirdPartyUtil_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIChannel; /* forward declaration */


/* starting interface:    mozIThirdPartyUtil */
#define MOZITHIRDPARTYUTIL_IID_STR "b711bd7f-0674-49be-ae77-f221db5f7b6c"

#define MOZITHIRDPARTYUTIL_IID \
  {0xb711bd7f, 0x0674, 0x49be, \
    { 0xae, 0x77, 0xf2, 0x21, 0xdb, 0x5f, 0x7b, 0x6c }}

class NS_NO_VTABLE mozIThirdPartyUtil : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZITHIRDPARTYUTIL_IID)

  /* boolean isThirdPartyURI (in nsIURI aFirstURI, in nsIURI aSecondURI); */
  NS_IMETHOD IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, bool *_retval) = 0;

  /* boolean isThirdPartyWindow (in nsIDOMWindow aWindow, [optional] in nsIURI aURI); */
  NS_IMETHOD IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, bool *_retval) = 0;

  /* boolean isThirdPartyChannel (in nsIChannel aChannel, [optional] in nsIURI aURI); */
  NS_IMETHOD IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, bool *_retval) = 0;

  /* AUTF8String getBaseDomain (in nsIURI aHostURI); */
  NS_IMETHOD GetBaseDomain(nsIURI *aHostURI, nsACString & _retval) = 0;

  /* nsIURI getURIFromWindow (in nsIDOMWindow aWindow); */
  NS_IMETHOD GetURIFromWindow(nsIDOMWindow *aWindow, nsIURI * *_retval) = 0;

  /* nsIDOMWindow getTopWindowForChannel (in nsIChannel aChannel); */
  NS_IMETHOD GetTopWindowForChannel(nsIChannel *aChannel, nsIDOMWindow * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIThirdPartyUtil, MOZITHIRDPARTYUTIL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZITHIRDPARTYUTIL \
  NS_IMETHOD IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, bool *_retval) override; \
  NS_IMETHOD IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, bool *_retval) override; \
  NS_IMETHOD IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, bool *_retval) override; \
  NS_IMETHOD GetBaseDomain(nsIURI *aHostURI, nsACString & _retval) override; \
  NS_IMETHOD GetURIFromWindow(nsIDOMWindow *aWindow, nsIURI * *_retval) override; \
  NS_IMETHOD GetTopWindowForChannel(nsIChannel *aChannel, nsIDOMWindow * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZITHIRDPARTYUTIL(_to) \
  NS_IMETHOD IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, bool *_retval) override { return _to IsThirdPartyURI(aFirstURI, aSecondURI, _retval); } \
  NS_IMETHOD IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, bool *_retval) override { return _to IsThirdPartyWindow(aWindow, aURI, _retval); } \
  NS_IMETHOD IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, bool *_retval) override { return _to IsThirdPartyChannel(aChannel, aURI, _retval); } \
  NS_IMETHOD GetBaseDomain(nsIURI *aHostURI, nsACString & _retval) override { return _to GetBaseDomain(aHostURI, _retval); } \
  NS_IMETHOD GetURIFromWindow(nsIDOMWindow *aWindow, nsIURI * *_retval) override { return _to GetURIFromWindow(aWindow, _retval); } \
  NS_IMETHOD GetTopWindowForChannel(nsIChannel *aChannel, nsIDOMWindow * *_retval) override { return _to GetTopWindowForChannel(aChannel, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZITHIRDPARTYUTIL(_to) \
  NS_IMETHOD IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsThirdPartyURI(aFirstURI, aSecondURI, _retval); } \
  NS_IMETHOD IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsThirdPartyWindow(aWindow, aURI, _retval); } \
  NS_IMETHOD IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsThirdPartyChannel(aChannel, aURI, _retval); } \
  NS_IMETHOD GetBaseDomain(nsIURI *aHostURI, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseDomain(aHostURI, _retval); } \
  NS_IMETHOD GetURIFromWindow(nsIDOMWindow *aWindow, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURIFromWindow(aWindow, _retval); } \
  NS_IMETHOD GetTopWindowForChannel(nsIChannel *aChannel, nsIDOMWindow * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTopWindowForChannel(aChannel, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIThirdPartyUtil
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZITHIRDPARTYUTIL

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, mozIThirdPartyUtil)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean isThirdPartyURI (in nsIURI aFirstURI, in nsIURI aSecondURI); */
NS_IMETHODIMP _MYCLASS_::IsThirdPartyURI(nsIURI *aFirstURI, nsIURI *aSecondURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isThirdPartyWindow (in nsIDOMWindow aWindow, [optional] in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::IsThirdPartyWindow(nsIDOMWindow *aWindow, nsIURI *aURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isThirdPartyChannel (in nsIChannel aChannel, [optional] in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::IsThirdPartyChannel(nsIChannel *aChannel, nsIURI *aURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getBaseDomain (in nsIURI aHostURI); */
NS_IMETHODIMP _MYCLASS_::GetBaseDomain(nsIURI *aHostURI, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getURIFromWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP _MYCLASS_::GetURIFromWindow(nsIDOMWindow *aWindow, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow getTopWindowForChannel (in nsIChannel aChannel); */
NS_IMETHODIMP _MYCLASS_::GetTopWindowForChannel(nsIChannel *aChannel, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * The mozIThirdPartyUtil implementation is an XPCOM service registered
 * under the ContractID:
 */
#define THIRDPARTYUTIL_CONTRACTID "@mozilla.org/thirdpartyutil;1"

#endif /* __gen_mozIThirdPartyUtil_h__ */
