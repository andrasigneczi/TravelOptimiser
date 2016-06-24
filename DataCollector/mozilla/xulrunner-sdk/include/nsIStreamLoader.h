/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStreamLoader.idl
 */

#ifndef __gen_nsIStreamLoader_h__
#define __gen_nsIStreamLoader_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */

class nsIStreamLoader; /* forward declaration */


/* starting interface:    nsIStreamLoaderObserver */
#define NS_ISTREAMLOADEROBSERVER_IID_STR "359f7990-d4e9-11d3-a1a5-0050041caf44"

#define NS_ISTREAMLOADEROBSERVER_IID \
  {0x359f7990, 0xd4e9, 0x11d3, \
    { 0xa1, 0xa5, 0x00, 0x50, 0x04, 0x1c, 0xaf, 0x44 }}

class NS_NO_VTABLE nsIStreamLoaderObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMLOADEROBSERVER_IID)

  /* void onStreamComplete (in nsIStreamLoader loader, in nsISupports ctxt, in nsresult status, in unsigned long resultLength, [array, size_is (resultLength), const] in octet result); */
  NS_IMETHOD OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, uint32_t resultLength, const uint8_t *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamLoaderObserver, NS_ISTREAMLOADEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMLOADEROBSERVER \
  NS_IMETHOD OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, uint32_t resultLength, const uint8_t *result) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMLOADEROBSERVER(_to) \
  NS_IMETHOD OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, uint32_t resultLength, const uint8_t *result) override { return _to OnStreamComplete(loader, ctxt, status, resultLength, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMLOADEROBSERVER(_to) \
  NS_IMETHOD OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, uint32_t resultLength, const uint8_t *result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStreamComplete(loader, ctxt, status, resultLength, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamLoaderObserver : public nsIStreamLoaderObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMLOADEROBSERVER

  nsStreamLoaderObserver();

private:
  ~nsStreamLoaderObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStreamLoaderObserver, nsIStreamLoaderObserver)

nsStreamLoaderObserver::nsStreamLoaderObserver()
{
  /* member initializers and constructor code */
}

nsStreamLoaderObserver::~nsStreamLoaderObserver()
{
  /* destructor code */
}

/* void onStreamComplete (in nsIStreamLoader loader, in nsISupports ctxt, in nsresult status, in unsigned long resultLength, [array, size_is (resultLength), const] in octet result); */
NS_IMETHODIMP nsStreamLoaderObserver::OnStreamComplete(nsIStreamLoader *loader, nsISupports *ctxt, nsresult status, uint32_t resultLength, const uint8_t *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStreamLoader */
#define NS_ISTREAMLOADER_IID_STR "323bcff1-7513-4e1f-a541-1c9213c2ed1b"

#define NS_ISTREAMLOADER_IID \
  {0x323bcff1, 0x7513, 0x4e1f, \
    { 0xa5, 0x41, 0x1c, 0x92, 0x13, 0xc2, 0xed, 0x1b }}

class NS_NO_VTABLE nsIStreamLoader : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMLOADER_IID)

  /* void init (in nsIStreamLoaderObserver aStreamObserver, [optional] in nsIRequestObserver aRequestObserver); */
  NS_IMETHOD Init(nsIStreamLoaderObserver *aStreamObserver, nsIRequestObserver *aRequestObserver) = 0;

  /* readonly attribute unsigned long numBytesRead; */
  NS_IMETHOD GetNumBytesRead(uint32_t *aNumBytesRead) = 0;

  /* readonly attribute nsIRequest request; */
  NS_IMETHOD GetRequest(nsIRequest * *aRequest) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamLoader, NS_ISTREAMLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMLOADER \
  NS_IMETHOD Init(nsIStreamLoaderObserver *aStreamObserver, nsIRequestObserver *aRequestObserver) override; \
  NS_IMETHOD GetNumBytesRead(uint32_t *aNumBytesRead) override; \
  NS_IMETHOD GetRequest(nsIRequest * *aRequest) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMLOADER(_to) \
  NS_IMETHOD Init(nsIStreamLoaderObserver *aStreamObserver, nsIRequestObserver *aRequestObserver) override { return _to Init(aStreamObserver, aRequestObserver); } \
  NS_IMETHOD GetNumBytesRead(uint32_t *aNumBytesRead) override { return _to GetNumBytesRead(aNumBytesRead); } \
  NS_IMETHOD GetRequest(nsIRequest * *aRequest) override { return _to GetRequest(aRequest); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMLOADER(_to) \
  NS_IMETHOD Init(nsIStreamLoaderObserver *aStreamObserver, nsIRequestObserver *aRequestObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aStreamObserver, aRequestObserver); } \
  NS_IMETHOD GetNumBytesRead(uint32_t *aNumBytesRead) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumBytesRead(aNumBytesRead); } \
  NS_IMETHOD GetRequest(nsIRequest * *aRequest) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequest(aRequest); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamLoader : public nsIStreamLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMLOADER

  nsStreamLoader();

private:
  ~nsStreamLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStreamLoader, nsIStreamLoader)

nsStreamLoader::nsStreamLoader()
{
  /* member initializers and constructor code */
}

nsStreamLoader::~nsStreamLoader()
{
  /* destructor code */
}

/* void init (in nsIStreamLoaderObserver aStreamObserver, [optional] in nsIRequestObserver aRequestObserver); */
NS_IMETHODIMP nsStreamLoader::Init(nsIStreamLoaderObserver *aStreamObserver, nsIRequestObserver *aRequestObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long numBytesRead; */
NS_IMETHODIMP nsStreamLoader::GetNumBytesRead(uint32_t *aNumBytesRead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRequest request; */
NS_IMETHODIMP nsStreamLoader::GetRequest(nsIRequest * *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamLoader_h__ */
