/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIChannelEventSink.idl
 */

#ifndef __gen_nsIChannelEventSink_h__
#define __gen_nsIChannelEventSink_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIAsyncVerifyRedirectCallback; /* forward declaration */


/* starting interface:    nsIChannelEventSink */
#define NS_ICHANNELEVENTSINK_IID_STR "0197720d-37ed-4e75-8956-d0d296e4d8a6"

#define NS_ICHANNELEVENTSINK_IID \
  {0x0197720d, 0x37ed, 0x4e75, \
    { 0x89, 0x56, 0xd0, 0xd2, 0x96, 0xe4, 0xd8, 0xa6 }}

class NS_NO_VTABLE nsIChannelEventSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICHANNELEVENTSINK_IID)

  enum {
    REDIRECT_TEMPORARY = 1U,
    REDIRECT_PERMANENT = 2U,
    REDIRECT_INTERNAL = 4U,
    REDIRECT_STS_UPGRADE = 8U
  };

  /* void asyncOnChannelRedirect (in nsIChannel oldChannel, in nsIChannel newChannel, in unsigned long flags, in nsIAsyncVerifyRedirectCallback callback); */
  NS_IMETHOD AsyncOnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, uint32_t flags, nsIAsyncVerifyRedirectCallback *callback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIChannelEventSink, NS_ICHANNELEVENTSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICHANNELEVENTSINK \
  NS_IMETHOD AsyncOnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, uint32_t flags, nsIAsyncVerifyRedirectCallback *callback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICHANNELEVENTSINK(_to) \
  NS_IMETHOD AsyncOnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, uint32_t flags, nsIAsyncVerifyRedirectCallback *callback) override { return _to AsyncOnChannelRedirect(oldChannel, newChannel, flags, callback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICHANNELEVENTSINK(_to) \
  NS_IMETHOD AsyncOnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, uint32_t flags, nsIAsyncVerifyRedirectCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncOnChannelRedirect(oldChannel, newChannel, flags, callback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsChannelEventSink : public nsIChannelEventSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICHANNELEVENTSINK

  nsChannelEventSink();

private:
  ~nsChannelEventSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsChannelEventSink, nsIChannelEventSink)

nsChannelEventSink::nsChannelEventSink()
{
  /* member initializers and constructor code */
}

nsChannelEventSink::~nsChannelEventSink()
{
  /* destructor code */
}

/* void asyncOnChannelRedirect (in nsIChannel oldChannel, in nsIChannel newChannel, in unsigned long flags, in nsIAsyncVerifyRedirectCallback callback); */
NS_IMETHODIMP nsChannelEventSink::AsyncOnChannelRedirect(nsIChannel *oldChannel, nsIChannel *newChannel, uint32_t flags, nsIAsyncVerifyRedirectCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIChannelEventSink_h__ */
