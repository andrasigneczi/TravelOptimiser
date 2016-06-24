/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFxAccountsUIGlue.idl
 */

#ifndef __gen_nsIFxAccountsUIGlue_h__
#define __gen_nsIFxAccountsUIGlue_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFxAccountsUIGlue */
#define NS_IFXACCOUNTSUIGLUE_IID_STR "ab8d0700-9577-11e3-a5e2-0800200c9a66"

#define NS_IFXACCOUNTSUIGLUE_IID \
  {0xab8d0700, 0x9577, 0x11e3, \
    { 0xa5, 0xe2, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIFxAccountsUIGlue : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFXACCOUNTSUIGLUE_IID)

  /* jsval signInFlow (); */
  NS_IMETHOD SignInFlow(JS::MutableHandleValue _retval) = 0;

  /* jsval refreshAuthentication (in DOMString email); */
  NS_IMETHOD RefreshAuthentication(const nsAString & email, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFxAccountsUIGlue, NS_IFXACCOUNTSUIGLUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFXACCOUNTSUIGLUE \
  NS_IMETHOD SignInFlow(JS::MutableHandleValue _retval) override; \
  NS_IMETHOD RefreshAuthentication(const nsAString & email, JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFXACCOUNTSUIGLUE(_to) \
  NS_IMETHOD SignInFlow(JS::MutableHandleValue _retval) override { return _to SignInFlow(_retval); } \
  NS_IMETHOD RefreshAuthentication(const nsAString & email, JS::MutableHandleValue _retval) override { return _to RefreshAuthentication(email, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFXACCOUNTSUIGLUE(_to) \
  NS_IMETHOD SignInFlow(JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SignInFlow(_retval); } \
  NS_IMETHOD RefreshAuthentication(const nsAString & email, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshAuthentication(email, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFxAccountsUIGlue : public nsIFxAccountsUIGlue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFXACCOUNTSUIGLUE

  nsFxAccountsUIGlue();

private:
  ~nsFxAccountsUIGlue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsFxAccountsUIGlue, nsIFxAccountsUIGlue)

nsFxAccountsUIGlue::nsFxAccountsUIGlue()
{
  /* member initializers and constructor code */
}

nsFxAccountsUIGlue::~nsFxAccountsUIGlue()
{
  /* destructor code */
}

/* jsval signInFlow (); */
NS_IMETHODIMP nsFxAccountsUIGlue::SignInFlow(JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval refreshAuthentication (in DOMString email); */
NS_IMETHODIMP nsFxAccountsUIGlue::RefreshAuthentication(const nsAString & email, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFxAccountsUIGlue_h__ */
