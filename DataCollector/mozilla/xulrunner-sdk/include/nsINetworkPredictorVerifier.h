/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINetworkPredictorVerifier.idl
 */

#ifndef __gen_nsINetworkPredictorVerifier_h__
#define __gen_nsINetworkPredictorVerifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsINetworkPredictorVerifier */
#define NS_INETWORKPREDICTORVERIFIER_IID_STR "00360c7d-a046-4f8d-a1fc-8bdc0f0fb444"

#define NS_INETWORKPREDICTORVERIFIER_IID \
  {0x00360c7d, 0xa046, 0x4f8d, \
    { 0xa1, 0xfc, 0x8b, 0xdc, 0x0f, 0x0f, 0xb4, 0x44 }}

class NS_NO_VTABLE nsINetworkPredictorVerifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETWORKPREDICTORVERIFIER_IID)

  /* void onPredictPreconnect (in nsIURI uri); */
  NS_IMETHOD OnPredictPreconnect(nsIURI *uri) = 0;

  /* void onPredictDNS (in nsIURI uri); */
  NS_IMETHOD OnPredictDNS(nsIURI *uri) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetworkPredictorVerifier, NS_INETWORKPREDICTORVERIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETWORKPREDICTORVERIFIER \
  NS_IMETHOD OnPredictPreconnect(nsIURI *uri) override; \
  NS_IMETHOD OnPredictDNS(nsIURI *uri) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETWORKPREDICTORVERIFIER(_to) \
  NS_IMETHOD OnPredictPreconnect(nsIURI *uri) override { return _to OnPredictPreconnect(uri); } \
  NS_IMETHOD OnPredictDNS(nsIURI *uri) override { return _to OnPredictDNS(uri); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETWORKPREDICTORVERIFIER(_to) \
  NS_IMETHOD OnPredictPreconnect(nsIURI *uri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPredictPreconnect(uri); } \
  NS_IMETHOD OnPredictDNS(nsIURI *uri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPredictDNS(uri); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetworkPredictorVerifier : public nsINetworkPredictorVerifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETWORKPREDICTORVERIFIER

  nsNetworkPredictorVerifier();

private:
  ~nsNetworkPredictorVerifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNetworkPredictorVerifier, nsINetworkPredictorVerifier)

nsNetworkPredictorVerifier::nsNetworkPredictorVerifier()
{
  /* member initializers and constructor code */
}

nsNetworkPredictorVerifier::~nsNetworkPredictorVerifier()
{
  /* destructor code */
}

/* void onPredictPreconnect (in nsIURI uri); */
NS_IMETHODIMP nsNetworkPredictorVerifier::OnPredictPreconnect(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPredictDNS (in nsIURI uri); */
NS_IMETHODIMP nsNetworkPredictorVerifier::OnPredictDNS(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINetworkPredictorVerifier_h__ */
