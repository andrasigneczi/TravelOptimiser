/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProtocolProxyCallback.idl
 */

#ifndef __gen_nsIProtocolProxyCallback_h__
#define __gen_nsIProtocolProxyCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsICancelable; /* forward declaration */


/* starting interface:    nsIProtocolProxyCallback */
#define NS_IPROTOCOLPROXYCALLBACK_IID_STR "fbb6eff6-0cc2-4d99-8d6f-0a12b462bdeb"

#define NS_IPROTOCOLPROXYCALLBACK_IID \
  {0xfbb6eff6, 0x0cc2, 0x4d99, \
    { 0x8d, 0x6f, 0x0a, 0x12, 0xb4, 0x62, 0xbd, 0xeb }}

class NS_NO_VTABLE nsIProtocolProxyCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLPROXYCALLBACK_IID)

  /* void onProxyAvailable (in nsICancelable aRequest, in nsIChannel aChannel, in nsIProxyInfo aProxyInfo, in nsresult aStatus); */
  NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIChannel *aChannel, nsIProxyInfo *aProxyInfo, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolProxyCallback, NS_IPROTOCOLPROXYCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLPROXYCALLBACK \
  NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIChannel *aChannel, nsIProxyInfo *aProxyInfo, nsresult aStatus) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLPROXYCALLBACK(_to) \
  NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIChannel *aChannel, nsIProxyInfo *aProxyInfo, nsresult aStatus) override { return _to OnProxyAvailable(aRequest, aChannel, aProxyInfo, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLPROXYCALLBACK(_to) \
  NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIChannel *aChannel, nsIProxyInfo *aProxyInfo, nsresult aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProxyAvailable(aRequest, aChannel, aProxyInfo, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolProxyCallback : public nsIProtocolProxyCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLPROXYCALLBACK

  nsProtocolProxyCallback();

private:
  ~nsProtocolProxyCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProtocolProxyCallback, nsIProtocolProxyCallback)

nsProtocolProxyCallback::nsProtocolProxyCallback()
{
  /* member initializers and constructor code */
}

nsProtocolProxyCallback::~nsProtocolProxyCallback()
{
  /* destructor code */
}

/* void onProxyAvailable (in nsICancelable aRequest, in nsIChannel aChannel, in nsIProxyInfo aProxyInfo, in nsresult aStatus); */
NS_IMETHODIMP nsProtocolProxyCallback::OnProxyAvailable(nsICancelable *aRequest, nsIChannel *aChannel, nsIProxyInfo *aProxyInfo, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProtocolProxyCallback_h__ */
