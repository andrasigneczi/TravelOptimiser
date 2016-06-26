/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAsyncStreamCopier2.idl
 */

#ifndef __gen_nsIAsyncStreamCopier2_h__
#define __gen_nsIAsyncStreamCopier2_h__


#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsIRequestObserver; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsIAsyncStreamCopier2 */
#define NS_IASYNCSTREAMCOPIER2_IID_STR "a5b2decf-4ede-4801-8b38-e5fe5db46bf2"

#define NS_IASYNCSTREAMCOPIER2_IID \
  {0xa5b2decf, 0x4ede, 0x4801, \
    { 0x8b, 0x38, 0xe5, 0xfe, 0x5d, 0xb4, 0x6b, 0xf2 }}

class NS_NO_VTABLE nsIAsyncStreamCopier2 : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCSTREAMCOPIER2_IID)

  /* void init (in nsIInputStream aSource, in nsIOutputStream aSink, in nsIEventTarget aTarget, in unsigned long aChunkSize, in boolean aCloseSource, in boolean aCloseSink); */
  NS_IMETHOD Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, uint32_t aChunkSize, bool aCloseSource, bool aCloseSink) = 0;

  /* void asyncCopy (in nsIRequestObserver aObserver, in nsISupports aObserverContext); */
  NS_IMETHOD AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncStreamCopier2, NS_IASYNCSTREAMCOPIER2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCSTREAMCOPIER2 \
  NS_IMETHOD Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, uint32_t aChunkSize, bool aCloseSource, bool aCloseSink) override; \
  NS_IMETHOD AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCSTREAMCOPIER2(_to) \
  NS_IMETHOD Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, uint32_t aChunkSize, bool aCloseSource, bool aCloseSink) override { return _to Init(aSource, aSink, aTarget, aChunkSize, aCloseSource, aCloseSink); } \
  NS_IMETHOD AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext) override { return _to AsyncCopy(aObserver, aObserverContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCSTREAMCOPIER2(_to) \
  NS_IMETHOD Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, uint32_t aChunkSize, bool aCloseSource, bool aCloseSink) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aSource, aSink, aTarget, aChunkSize, aCloseSource, aCloseSink); } \
  NS_IMETHOD AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncCopy(aObserver, aObserverContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncStreamCopier2 : public nsIAsyncStreamCopier2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCSTREAMCOPIER2

  nsAsyncStreamCopier2();

private:
  ~nsAsyncStreamCopier2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAsyncStreamCopier2, nsIAsyncStreamCopier2)

nsAsyncStreamCopier2::nsAsyncStreamCopier2()
{
  /* member initializers and constructor code */
}

nsAsyncStreamCopier2::~nsAsyncStreamCopier2()
{
  /* destructor code */
}

/* void init (in nsIInputStream aSource, in nsIOutputStream aSink, in nsIEventTarget aTarget, in unsigned long aChunkSize, in boolean aCloseSource, in boolean aCloseSink); */
NS_IMETHODIMP nsAsyncStreamCopier2::Init(nsIInputStream *aSource, nsIOutputStream *aSink, nsIEventTarget *aTarget, uint32_t aChunkSize, bool aCloseSource, bool aCloseSink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncCopy (in nsIRequestObserver aObserver, in nsISupports aObserverContext); */
NS_IMETHODIMP nsAsyncStreamCopier2::AsyncCopy(nsIRequestObserver *aObserver, nsISupports *aObserverContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAsyncStreamCopier2_h__ */
