/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContentPolicy.idl
 */

#ifndef __gen_nsIContentPolicy_h__
#define __gen_nsIContentPolicy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIContentPolicyBase_h__
#include "nsIContentPolicyBase.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIContentPolicy */
#define NS_ICONTENTPOLICY_IID_STR "b545899e-42bd-434c-8fec-a0af3448ea15"

#define NS_ICONTENTPOLICY_IID \
  {0xb545899e, 0x42bd, 0x434c, \
    { 0x8f, 0xec, 0xa0, 0xaf, 0x34, 0x48, 0xea, 0x15 }}

class NS_NO_VTABLE nsIContentPolicy : public nsIContentPolicyBase {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPOLICY_IID)

  /* short shouldLoad (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra, [optional] in nsIPrincipal aRequestPrincipal); */
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) = 0;

  /* short shouldProcess (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra, [optional] in nsIPrincipal aRequestPrincipal); */
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPolicy, NS_ICONTENTPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPOLICY \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override; \
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPOLICY(_to) \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override { return _to ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, aRequestPrincipal, _retval); } \
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override { return _to ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, aRequestPrincipal, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPOLICY(_to) \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, aRequestPrincipal, _retval); } \
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, aRequestPrincipal, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPolicy : public nsIContentPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPOLICY

  nsContentPolicy();

private:
  ~nsContentPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentPolicy, nsIContentPolicy)

nsContentPolicy::nsContentPolicy()
{
  /* member initializers and constructor code */
}

nsContentPolicy::~nsContentPolicy()
{
  /* destructor code */
}

/* short shouldLoad (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra, [optional] in nsIPrincipal aRequestPrincipal); */
NS_IMETHODIMP nsContentPolicy::ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short shouldProcess (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra, [optional] in nsIPrincipal aRequestPrincipal); */
NS_IMETHODIMP nsContentPolicy::ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentPolicy_h__ */
