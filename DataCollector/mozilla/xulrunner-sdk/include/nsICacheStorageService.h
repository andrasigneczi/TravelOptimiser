/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICacheStorageService.idl
 */

#ifndef __gen_nsICacheStorageService_h__
#define __gen_nsICacheStorageService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICacheStorage; /* forward declaration */

class nsILoadContextInfo; /* forward declaration */

class nsIApplicationCache; /* forward declaration */

class nsIEventTarget; /* forward declaration */

class nsICacheStorageConsumptionObserver; /* forward declaration */


/* starting interface:    nsICacheStorageService */
#define NS_ICACHESTORAGESERVICE_IID_STR "44de2fa4-1b0e-4cd3-9e32-211e936f721e"

#define NS_ICACHESTORAGESERVICE_IID \
  {0x44de2fa4, 0x1b0e, 0x4cd3, \
    { 0x9e, 0x32, 0x21, 0x1e, 0x93, 0x6f, 0x72, 0x1e }}

class NS_NO_VTABLE nsICacheStorageService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESTORAGESERVICE_IID)

  /* nsICacheStorage memoryCacheStorage (in nsILoadContextInfo aLoadContextInfo); */
  NS_IMETHOD MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval) = 0;

  /* nsICacheStorage diskCacheStorage (in nsILoadContextInfo aLoadContextInfo, in bool aLookupAppCache); */
  NS_IMETHOD DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval) = 0;

  /* nsICacheStorage appCacheStorage (in nsILoadContextInfo aLoadContextInfo, in nsIApplicationCache aApplicationCache); */
  NS_IMETHOD AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  enum {
    PURGE_DISK_DATA_ONLY = 1U,
    PURGE_DISK_ALL = 2U,
    PURGE_EVERYTHING = 3U
  };

  /* void purgeFromMemory (in uint32_t aWhat); */
  NS_IMETHOD PurgeFromMemory(uint32_t aWhat) = 0;

  /* readonly attribute nsIEventTarget ioTarget; */
  NS_IMETHOD GetIoTarget(nsIEventTarget * *aIoTarget) = 0;

  /* void asyncGetDiskConsumption (in nsICacheStorageConsumptionObserver aObserver); */
  NS_IMETHOD AsyncGetDiskConsumption(nsICacheStorageConsumptionObserver *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheStorageService, NS_ICACHESTORAGESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESTORAGESERVICE \
  NS_IMETHOD MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval) override; \
  NS_IMETHOD DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval) override; \
  NS_IMETHOD AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval) override; \
  NS_IMETHOD Clear(void) override; \
  NS_IMETHOD PurgeFromMemory(uint32_t aWhat) override; \
  NS_IMETHOD GetIoTarget(nsIEventTarget * *aIoTarget) override; \
  NS_IMETHOD AsyncGetDiskConsumption(nsICacheStorageConsumptionObserver *aObserver) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESTORAGESERVICE(_to) \
  NS_IMETHOD MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval) override { return _to MemoryCacheStorage(aLoadContextInfo, _retval); } \
  NS_IMETHOD DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval) override { return _to DiskCacheStorage(aLoadContextInfo, aLookupAppCache, _retval); } \
  NS_IMETHOD AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval) override { return _to AppCacheStorage(aLoadContextInfo, aApplicationCache, _retval); } \
  NS_IMETHOD Clear(void) override { return _to Clear(); } \
  NS_IMETHOD PurgeFromMemory(uint32_t aWhat) override { return _to PurgeFromMemory(aWhat); } \
  NS_IMETHOD GetIoTarget(nsIEventTarget * *aIoTarget) override { return _to GetIoTarget(aIoTarget); } \
  NS_IMETHOD AsyncGetDiskConsumption(nsICacheStorageConsumptionObserver *aObserver) override { return _to AsyncGetDiskConsumption(aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESTORAGESERVICE(_to) \
  NS_IMETHOD MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MemoryCacheStorage(aLoadContextInfo, _retval); } \
  NS_IMETHOD DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DiskCacheStorage(aLoadContextInfo, aLookupAppCache, _retval); } \
  NS_IMETHOD AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AppCacheStorage(aLoadContextInfo, aApplicationCache, _retval); } \
  NS_IMETHOD Clear(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD PurgeFromMemory(uint32_t aWhat) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PurgeFromMemory(aWhat); } \
  NS_IMETHOD GetIoTarget(nsIEventTarget * *aIoTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIoTarget(aIoTarget); } \
  NS_IMETHOD AsyncGetDiskConsumption(nsICacheStorageConsumptionObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncGetDiskConsumption(aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheStorageService : public nsICacheStorageService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESTORAGESERVICE

  nsCacheStorageService();

private:
  ~nsCacheStorageService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCacheStorageService, nsICacheStorageService)

nsCacheStorageService::nsCacheStorageService()
{
  /* member initializers and constructor code */
}

nsCacheStorageService::~nsCacheStorageService()
{
  /* destructor code */
}

/* nsICacheStorage memoryCacheStorage (in nsILoadContextInfo aLoadContextInfo); */
NS_IMETHODIMP nsCacheStorageService::MemoryCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsICacheStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICacheStorage diskCacheStorage (in nsILoadContextInfo aLoadContextInfo, in bool aLookupAppCache); */
NS_IMETHODIMP nsCacheStorageService::DiskCacheStorage(nsILoadContextInfo *aLoadContextInfo, bool aLookupAppCache, nsICacheStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICacheStorage appCacheStorage (in nsILoadContextInfo aLoadContextInfo, in nsIApplicationCache aApplicationCache); */
NS_IMETHODIMP nsCacheStorageService::AppCacheStorage(nsILoadContextInfo *aLoadContextInfo, nsIApplicationCache *aApplicationCache, nsICacheStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsCacheStorageService::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void purgeFromMemory (in uint32_t aWhat); */
NS_IMETHODIMP nsCacheStorageService::PurgeFromMemory(uint32_t aWhat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIEventTarget ioTarget; */
NS_IMETHODIMP nsCacheStorageService::GetIoTarget(nsIEventTarget * *aIoTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncGetDiskConsumption (in nsICacheStorageConsumptionObserver aObserver); */
NS_IMETHODIMP nsCacheStorageService::AsyncGetDiskConsumption(nsICacheStorageConsumptionObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICacheStorageConsumptionObserver */
#define NS_ICACHESTORAGECONSUMPTIONOBSERVER_IID_STR "7728ab5b-4c01-4483-a606-32bf5b8136cb"

#define NS_ICACHESTORAGECONSUMPTIONOBSERVER_IID \
  {0x7728ab5b, 0x4c01, 0x4483, \
    { 0xa6, 0x06, 0x32, 0xbf, 0x5b, 0x81, 0x36, 0xcb }}

class NS_NO_VTABLE nsICacheStorageConsumptionObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESTORAGECONSUMPTIONOBSERVER_IID)

  /* void onNetworkCacheDiskConsumption (in int64_t aDiskSize); */
  NS_IMETHOD OnNetworkCacheDiskConsumption(int64_t aDiskSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheStorageConsumptionObserver, NS_ICACHESTORAGECONSUMPTIONOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESTORAGECONSUMPTIONOBSERVER \
  NS_IMETHOD OnNetworkCacheDiskConsumption(int64_t aDiskSize) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESTORAGECONSUMPTIONOBSERVER(_to) \
  NS_IMETHOD OnNetworkCacheDiskConsumption(int64_t aDiskSize) override { return _to OnNetworkCacheDiskConsumption(aDiskSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESTORAGECONSUMPTIONOBSERVER(_to) \
  NS_IMETHOD OnNetworkCacheDiskConsumption(int64_t aDiskSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnNetworkCacheDiskConsumption(aDiskSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheStorageConsumptionObserver : public nsICacheStorageConsumptionObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESTORAGECONSUMPTIONOBSERVER

  nsCacheStorageConsumptionObserver();

private:
  ~nsCacheStorageConsumptionObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCacheStorageConsumptionObserver, nsICacheStorageConsumptionObserver)

nsCacheStorageConsumptionObserver::nsCacheStorageConsumptionObserver()
{
  /* member initializers and constructor code */
}

nsCacheStorageConsumptionObserver::~nsCacheStorageConsumptionObserver()
{
  /* destructor code */
}

/* void onNetworkCacheDiskConsumption (in int64_t aDiskSize); */
NS_IMETHODIMP nsCacheStorageConsumptionObserver::OnNetworkCacheDiskConsumption(int64_t aDiskSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheStorageService_h__ */
