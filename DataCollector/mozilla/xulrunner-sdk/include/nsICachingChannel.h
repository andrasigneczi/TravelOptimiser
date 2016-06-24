/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICachingChannel.idl
 */

#ifndef __gen_nsICachingChannel_h__
#define __gen_nsICachingChannel_h__


#ifndef __gen_nsICacheInfoChannel_h__
#include "nsICacheInfoChannel.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsICachingChannel */
#define NS_ICACHINGCHANNEL_IID_STR "436b939d-e391-48e5-ba64-ab0e496e3400"

#define NS_ICACHINGCHANNEL_IID \
  {0x436b939d, 0xe391, 0x48e5, \
    { 0xba, 0x64, 0xab, 0x0e, 0x49, 0x6e, 0x34, 0x00 }}

class NS_NO_VTABLE nsICachingChannel : public nsICacheInfoChannel {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHINGCHANNEL_IID)

  /* attribute nsISupports cacheToken; */
  NS_IMETHOD GetCacheToken(nsISupports * *aCacheToken) = 0;
  NS_IMETHOD SetCacheToken(nsISupports *aCacheToken) = 0;

  /* attribute nsISupports offlineCacheToken; */
  NS_IMETHOD GetOfflineCacheToken(nsISupports * *aOfflineCacheToken) = 0;
  NS_IMETHOD SetOfflineCacheToken(nsISupports *aOfflineCacheToken) = 0;

  /* attribute boolean cacheOnlyMetadata; */
  NS_IMETHOD GetCacheOnlyMetadata(bool *aCacheOnlyMetadata) = 0;
  NS_IMETHOD SetCacheOnlyMetadata(bool aCacheOnlyMetadata) = 0;

  enum {
    LOAD_NO_NETWORK_IO = 67108864U,
    LOAD_CHECK_OFFLINE_CACHE = 134217728U,
    LOAD_BYPASS_LOCAL_CACHE = 268435456U,
    LOAD_BYPASS_LOCAL_CACHE_IF_BUSY = 536870912U,
    LOAD_ONLY_FROM_CACHE = 1073741824U,
    LOAD_ONLY_IF_MODIFIED = 2147483648U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICachingChannel, NS_ICACHINGCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHINGCHANNEL \
  NS_IMETHOD GetCacheToken(nsISupports * *aCacheToken) override; \
  NS_IMETHOD SetCacheToken(nsISupports *aCacheToken) override; \
  NS_IMETHOD GetOfflineCacheToken(nsISupports * *aOfflineCacheToken) override; \
  NS_IMETHOD SetOfflineCacheToken(nsISupports *aOfflineCacheToken) override; \
  NS_IMETHOD GetCacheOnlyMetadata(bool *aCacheOnlyMetadata) override; \
  NS_IMETHOD SetCacheOnlyMetadata(bool aCacheOnlyMetadata) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHINGCHANNEL(_to) \
  NS_IMETHOD GetCacheToken(nsISupports * *aCacheToken) override { return _to GetCacheToken(aCacheToken); } \
  NS_IMETHOD SetCacheToken(nsISupports *aCacheToken) override { return _to SetCacheToken(aCacheToken); } \
  NS_IMETHOD GetOfflineCacheToken(nsISupports * *aOfflineCacheToken) override { return _to GetOfflineCacheToken(aOfflineCacheToken); } \
  NS_IMETHOD SetOfflineCacheToken(nsISupports *aOfflineCacheToken) override { return _to SetOfflineCacheToken(aOfflineCacheToken); } \
  NS_IMETHOD GetCacheOnlyMetadata(bool *aCacheOnlyMetadata) override { return _to GetCacheOnlyMetadata(aCacheOnlyMetadata); } \
  NS_IMETHOD SetCacheOnlyMetadata(bool aCacheOnlyMetadata) override { return _to SetCacheOnlyMetadata(aCacheOnlyMetadata); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHINGCHANNEL(_to) \
  NS_IMETHOD GetCacheToken(nsISupports * *aCacheToken) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheToken(aCacheToken); } \
  NS_IMETHOD SetCacheToken(nsISupports *aCacheToken) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheToken(aCacheToken); } \
  NS_IMETHOD GetOfflineCacheToken(nsISupports * *aOfflineCacheToken) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOfflineCacheToken(aOfflineCacheToken); } \
  NS_IMETHOD SetOfflineCacheToken(nsISupports *aOfflineCacheToken) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOfflineCacheToken(aOfflineCacheToken); } \
  NS_IMETHOD GetCacheOnlyMetadata(bool *aCacheOnlyMetadata) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheOnlyMetadata(aCacheOnlyMetadata); } \
  NS_IMETHOD SetCacheOnlyMetadata(bool aCacheOnlyMetadata) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheOnlyMetadata(aCacheOnlyMetadata); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCachingChannel : public nsICachingChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHINGCHANNEL

  nsCachingChannel();

private:
  ~nsCachingChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCachingChannel, nsICachingChannel)

nsCachingChannel::nsCachingChannel()
{
  /* member initializers and constructor code */
}

nsCachingChannel::~nsCachingChannel()
{
  /* destructor code */
}

/* attribute nsISupports cacheToken; */
NS_IMETHODIMP nsCachingChannel::GetCacheToken(nsISupports * *aCacheToken)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCachingChannel::SetCacheToken(nsISupports *aCacheToken)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports offlineCacheToken; */
NS_IMETHODIMP nsCachingChannel::GetOfflineCacheToken(nsISupports * *aOfflineCacheToken)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCachingChannel::SetOfflineCacheToken(nsISupports *aOfflineCacheToken)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean cacheOnlyMetadata; */
NS_IMETHODIMP nsCachingChannel::GetCacheOnlyMetadata(bool *aCacheOnlyMetadata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCachingChannel::SetCacheOnlyMetadata(bool aCacheOnlyMetadata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICachingChannel_h__ */
