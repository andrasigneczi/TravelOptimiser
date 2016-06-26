/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIActivityProxy.idl
 */

#ifndef __gen_nsIActivityProxy_h__
#define __gen_nsIActivityProxy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIActivityProxy */
#define NS_IACTIVITYPROXY_IID_STR "e04c0bbc-ab7d-41ba-b801-1068dd58660b"

#define NS_IACTIVITYPROXY_IID \
  {0xe04c0bbc, 0xab7d, 0x41ba, \
    { 0xb8, 0x01, 0x10, 0x68, 0xdd, 0x58, 0x66, 0x0b }}

class NS_NO_VTABLE nsIActivityProxy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACTIVITYPROXY_IID)

  /* void startActivity (in nsISupports activity, in jsval options, in nsIDOMWindow window, in unsigned long long childID); */
  NS_IMETHOD StartActivity(nsISupports *activity, JS::HandleValue options, nsIDOMWindow *window, uint64_t childID) = 0;

  /* void cleanup (); */
  NS_IMETHOD Cleanup(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIActivityProxy, NS_IACTIVITYPROXY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACTIVITYPROXY \
  NS_IMETHOD StartActivity(nsISupports *activity, JS::HandleValue options, nsIDOMWindow *window, uint64_t childID) override; \
  NS_IMETHOD Cleanup(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACTIVITYPROXY(_to) \
  NS_IMETHOD StartActivity(nsISupports *activity, JS::HandleValue options, nsIDOMWindow *window, uint64_t childID) override { return _to StartActivity(activity, options, window, childID); } \
  NS_IMETHOD Cleanup(void) override { return _to Cleanup(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACTIVITYPROXY(_to) \
  NS_IMETHOD StartActivity(nsISupports *activity, JS::HandleValue options, nsIDOMWindow *window, uint64_t childID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartActivity(activity, options, window, childID); } \
  NS_IMETHOD Cleanup(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Cleanup(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsActivityProxy : public nsIActivityProxy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACTIVITYPROXY

  nsActivityProxy();

private:
  ~nsActivityProxy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsActivityProxy, nsIActivityProxy)

nsActivityProxy::nsActivityProxy()
{
  /* member initializers and constructor code */
}

nsActivityProxy::~nsActivityProxy()
{
  /* destructor code */
}

/* void startActivity (in nsISupports activity, in jsval options, in nsIDOMWindow window, in unsigned long long childID); */
NS_IMETHODIMP nsActivityProxy::StartActivity(nsISupports *activity, JS::HandleValue options, nsIDOMWindow *window, uint64_t childID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cleanup (); */
NS_IMETHODIMP nsActivityProxy::Cleanup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIActivityProxy_h__ */
