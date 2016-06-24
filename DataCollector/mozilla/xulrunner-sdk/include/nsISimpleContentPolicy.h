/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISimpleContentPolicy.idl
 */

#ifndef __gen_nsISimpleContentPolicy_h__
#define __gen_nsISimpleContentPolicy_h__


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

class nsIDOMElement; /* forward declaration */


/* starting interface:    nsISimpleContentPolicy */
#define NS_ISIMPLECONTENTPOLICY_IID_STR "b181c97c-9d67-4da1-95a0-e0a202e1807c"

#define NS_ISIMPLECONTENTPOLICY_IID \
  {0xb181c97c, 0x9d67, 0x4da1, \
    { 0x95, 0xa0, 0xe0, 0xa2, 0x02, 0xe1, 0x80, 0x7c }}

class NS_NO_VTABLE nsISimpleContentPolicy : public nsIContentPolicyBase {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISIMPLECONTENTPOLICY_IID)

  /* short shouldLoad (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsIDOMElement aTopFrameElement, in boolean aIsTopLevel, in ACString aMimeTypeGuess, in nsISupports aExtra, in nsIPrincipal aRequestPrincipal); */
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) = 0;

  /* short shouldProcess (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsIDOMElement aTopFrameElement, in boolean aIsTopLevel, in ACString aMimeType, in nsISupports aExtra, in nsIPrincipal aRequestPrincipal); */
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISimpleContentPolicy, NS_ISIMPLECONTENTPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISIMPLECONTENTPOLICY \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override; \
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISIMPLECONTENTPOLICY(_to) \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override { return _to ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aTopFrameElement, aIsTopLevel, aMimeTypeGuess, aExtra, aRequestPrincipal, _retval); } \
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override { return _to ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aTopFrameElement, aIsTopLevel, aMimeType, aExtra, aRequestPrincipal, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISIMPLECONTENTPOLICY(_to) \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aTopFrameElement, aIsTopLevel, aMimeTypeGuess, aExtra, aRequestPrincipal, _retval); } \
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aTopFrameElement, aIsTopLevel, aMimeType, aExtra, aRequestPrincipal, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSimpleContentPolicy : public nsISimpleContentPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISIMPLECONTENTPOLICY

  nsSimpleContentPolicy();

private:
  ~nsSimpleContentPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSimpleContentPolicy, nsISimpleContentPolicy)

nsSimpleContentPolicy::nsSimpleContentPolicy()
{
  /* member initializers and constructor code */
}

nsSimpleContentPolicy::~nsSimpleContentPolicy()
{
  /* destructor code */
}

/* short shouldLoad (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsIDOMElement aTopFrameElement, in boolean aIsTopLevel, in ACString aMimeTypeGuess, in nsISupports aExtra, in nsIPrincipal aRequestPrincipal); */
NS_IMETHODIMP nsSimpleContentPolicy::ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short shouldProcess (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsIDOMElement aTopFrameElement, in boolean aIsTopLevel, in ACString aMimeType, in nsISupports aExtra, in nsIPrincipal aRequestPrincipal); */
NS_IMETHODIMP nsSimpleContentPolicy::ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsIDOMElement *aTopFrameElement, bool aIsTopLevel, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISimpleContentPolicy_h__ */
