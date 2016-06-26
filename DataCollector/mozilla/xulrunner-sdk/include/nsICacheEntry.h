/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICacheEntry.idl
 */

#ifndef __gen_nsICacheEntry_h__
#define __gen_nsICacheEntry_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsICacheEntryDoomCallback; /* forward declaration */

typedef int32_t  nsCacheAccessMode;

typedef int32_t  nsCacheStoragePolicy;

class nsICacheListener; /* forward declaration */

class nsIFile; /* forward declaration */

class nsICacheEntryMetaDataVisitor; /* forward declaration */


/* starting interface:    nsICacheEntry */
#define NS_ICACHEENTRY_IID_STR "607c2a2c-0a48-40b9-a956-8cf2bb9857cf"

#define NS_ICACHEENTRY_IID \
  {0x607c2a2c, 0x0a48, 0x40b9, \
    { 0xa9, 0x56, 0x8c, 0xf2, 0xbb, 0x98, 0x57, 0xcf }}

class NS_NO_VTABLE nsICacheEntry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEENTRY_IID)

  enum {
    NO_EXPIRATION_TIME = 4294967295U
  };

  /* readonly attribute ACString key; */
  NS_IMETHOD GetKey(nsACString & aKey) = 0;

  /* readonly attribute boolean persistent; */
  NS_IMETHOD GetPersistent(bool *aPersistent) = 0;

  /* readonly attribute long fetchCount; */
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) = 0;

  /* readonly attribute uint32_t lastFetched; */
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) = 0;

  /* readonly attribute uint32_t lastModified; */
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) = 0;

  /* readonly attribute uint32_t expirationTime; */
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) = 0;

  /* void setExpirationTime (in uint32_t expirationTime); */
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) = 0;

  /* void forceValidFor (in unsigned long aSecondsToTheFuture); */
  NS_IMETHOD ForceValidFor(uint32_t aSecondsToTheFuture) = 0;

  /* readonly attribute boolean isForcedValid; */
  NS_IMETHOD GetIsForcedValid(bool *aIsForcedValid) = 0;

  /* nsIInputStream openInputStream (in long long offset); */
  NS_IMETHOD OpenInputStream(int64_t offset, nsIInputStream * *_retval) = 0;

  /* nsIOutputStream openOutputStream (in long long offset); */
  NS_IMETHOD OpenOutputStream(int64_t offset, nsIOutputStream * *_retval) = 0;

  /* attribute int64_t predictedDataSize; */
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) = 0;
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) = 0;

  /* attribute nsISupports securityInfo; */
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) = 0;
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) = 0;

  /* readonly attribute unsigned long storageDataSize; */
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) = 0;

  /* void asyncDoom (in nsICacheEntryDoomCallback listener); */
  NS_IMETHOD AsyncDoom(nsICacheEntryDoomCallback *listener) = 0;

  /* string getMetaDataElement (in string key); */
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) = 0;

  /* void setMetaDataElement (in string key, in string value); */
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) = 0;

  /* void visitMetaData (in nsICacheEntryMetaDataVisitor visitor); */
  NS_IMETHOD VisitMetaData(nsICacheEntryMetaDataVisitor *visitor) = 0;

  /* void metaDataReady (); */
  NS_IMETHOD MetaDataReady(void) = 0;

  /* void setValid (); */
  NS_IMETHOD SetValid(void) = 0;

  /* nsICacheEntry recreate ([optional] in boolean aMemoryOnly); */
  NS_IMETHOD Recreate(bool aMemoryOnly, nsICacheEntry * *_retval) = 0;

  /* readonly attribute long long dataSize; */
  NS_IMETHOD GetDataSize(int64_t *aDataSize) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void markValid (); */
  NS_IMETHOD MarkValid(void) = 0;

  /* void maybeMarkValid (); */
  NS_IMETHOD MaybeMarkValid(void) = 0;

  /* boolean hasWriteAccess (in boolean aWriteAllowed); */
  NS_IMETHOD HasWriteAccess(bool aWriteAllowed, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheEntry, NS_ICACHEENTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEENTRY \
  NS_IMETHOD GetKey(nsACString & aKey) override; \
  NS_IMETHOD GetPersistent(bool *aPersistent) override; \
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) override; \
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) override; \
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) override; \
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) override; \
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) override; \
  NS_IMETHOD ForceValidFor(uint32_t aSecondsToTheFuture) override; \
  NS_IMETHOD GetIsForcedValid(bool *aIsForcedValid) override; \
  NS_IMETHOD OpenInputStream(int64_t offset, nsIInputStream * *_retval) override; \
  NS_IMETHOD OpenOutputStream(int64_t offset, nsIOutputStream * *_retval) override; \
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) override; \
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) override; \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) override; \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) override; \
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) override; \
  NS_IMETHOD AsyncDoom(nsICacheEntryDoomCallback *listener) override; \
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) override; \
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) override; \
  NS_IMETHOD VisitMetaData(nsICacheEntryMetaDataVisitor *visitor) override; \
  NS_IMETHOD MetaDataReady(void) override; \
  NS_IMETHOD SetValid(void) override; \
  NS_IMETHOD Recreate(bool aMemoryOnly, nsICacheEntry * *_retval) override; \
  NS_IMETHOD GetDataSize(int64_t *aDataSize) override; \
  NS_IMETHOD Close(void) override; \
  NS_IMETHOD MarkValid(void) override; \
  NS_IMETHOD MaybeMarkValid(void) override; \
  NS_IMETHOD HasWriteAccess(bool aWriteAllowed, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEENTRY(_to) \
  NS_IMETHOD GetKey(nsACString & aKey) override { return _to GetKey(aKey); } \
  NS_IMETHOD GetPersistent(bool *aPersistent) override { return _to GetPersistent(aPersistent); } \
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) override { return _to GetFetchCount(aFetchCount); } \
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) override { return _to GetLastFetched(aLastFetched); } \
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) override { return _to GetLastModified(aLastModified); } \
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) override { return _to GetExpirationTime(aExpirationTime); } \
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) override { return _to SetExpirationTime(expirationTime); } \
  NS_IMETHOD ForceValidFor(uint32_t aSecondsToTheFuture) override { return _to ForceValidFor(aSecondsToTheFuture); } \
  NS_IMETHOD GetIsForcedValid(bool *aIsForcedValid) override { return _to GetIsForcedValid(aIsForcedValid); } \
  NS_IMETHOD OpenInputStream(int64_t offset, nsIInputStream * *_retval) override { return _to OpenInputStream(offset, _retval); } \
  NS_IMETHOD OpenOutputStream(int64_t offset, nsIOutputStream * *_retval) override { return _to OpenOutputStream(offset, _retval); } \
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) override { return _to GetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) override { return _to SetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) override { return _to GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) override { return _to SetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) override { return _to GetStorageDataSize(aStorageDataSize); } \
  NS_IMETHOD AsyncDoom(nsICacheEntryDoomCallback *listener) override { return _to AsyncDoom(listener); } \
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) override { return _to GetMetaDataElement(key, _retval); } \
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) override { return _to SetMetaDataElement(key, value); } \
  NS_IMETHOD VisitMetaData(nsICacheEntryMetaDataVisitor *visitor) override { return _to VisitMetaData(visitor); } \
  NS_IMETHOD MetaDataReady(void) override { return _to MetaDataReady(); } \
  NS_IMETHOD SetValid(void) override { return _to SetValid(); } \
  NS_IMETHOD Recreate(bool aMemoryOnly, nsICacheEntry * *_retval) override { return _to Recreate(aMemoryOnly, _retval); } \
  NS_IMETHOD GetDataSize(int64_t *aDataSize) override { return _to GetDataSize(aDataSize); } \
  NS_IMETHOD Close(void) override { return _to Close(); } \
  NS_IMETHOD MarkValid(void) override { return _to MarkValid(); } \
  NS_IMETHOD MaybeMarkValid(void) override { return _to MaybeMarkValid(); } \
  NS_IMETHOD HasWriteAccess(bool aWriteAllowed, bool *_retval) override { return _to HasWriteAccess(aWriteAllowed, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEENTRY(_to) \
  NS_IMETHOD GetKey(nsACString & aKey) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_IMETHOD GetPersistent(bool *aPersistent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersistent(aPersistent); } \
  NS_IMETHOD GetFetchCount(int32_t *aFetchCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFetchCount(aFetchCount); } \
  NS_IMETHOD GetLastFetched(uint32_t *aLastFetched) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastFetched(aLastFetched); } \
  NS_IMETHOD GetLastModified(uint32_t *aLastModified) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_IMETHOD GetExpirationTime(uint32_t *aExpirationTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpirationTime(aExpirationTime); } \
  NS_IMETHOD SetExpirationTime(uint32_t expirationTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExpirationTime(expirationTime); } \
  NS_IMETHOD ForceValidFor(uint32_t aSecondsToTheFuture) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceValidFor(aSecondsToTheFuture); } \
  NS_IMETHOD GetIsForcedValid(bool *aIsForcedValid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsForcedValid(aIsForcedValid); } \
  NS_IMETHOD OpenInputStream(int64_t offset, nsIInputStream * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenInputStream(offset, _retval); } \
  NS_IMETHOD OpenOutputStream(int64_t offset, nsIOutputStream * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenOutputStream(offset, _retval); } \
  NS_IMETHOD GetPredictedDataSize(int64_t *aPredictedDataSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD SetPredictedDataSize(int64_t aPredictedDataSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPredictedDataSize(aPredictedDataSize); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD SetSecurityInfo(nsISupports *aSecurityInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetStorageDataSize(uint32_t *aStorageDataSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorageDataSize(aStorageDataSize); } \
  NS_IMETHOD AsyncDoom(nsICacheEntryDoomCallback *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncDoom(listener); } \
  NS_IMETHOD GetMetaDataElement(const char * key, char * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetaDataElement(key, _retval); } \
  NS_IMETHOD SetMetaDataElement(const char * key, const char * value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMetaDataElement(key, value); } \
  NS_IMETHOD VisitMetaData(nsICacheEntryMetaDataVisitor *visitor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitMetaData(visitor); } \
  NS_IMETHOD MetaDataReady(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MetaDataReady(); } \
  NS_IMETHOD SetValid(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValid(); } \
  NS_IMETHOD Recreate(bool aMemoryOnly, nsICacheEntry * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Recreate(aMemoryOnly, _retval); } \
  NS_IMETHOD GetDataSize(int64_t *aDataSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataSize(aDataSize); } \
  NS_IMETHOD Close(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD MarkValid(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkValid(); } \
  NS_IMETHOD MaybeMarkValid(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MaybeMarkValid(); } \
  NS_IMETHOD HasWriteAccess(bool aWriteAllowed, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasWriteAccess(aWriteAllowed, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheEntry : public nsICacheEntry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEENTRY

  nsCacheEntry();

private:
  ~nsCacheEntry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCacheEntry, nsICacheEntry)

nsCacheEntry::nsCacheEntry()
{
  /* member initializers and constructor code */
}

nsCacheEntry::~nsCacheEntry()
{
  /* destructor code */
}

/* readonly attribute ACString key; */
NS_IMETHODIMP nsCacheEntry::GetKey(nsACString & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean persistent; */
NS_IMETHODIMP nsCacheEntry::GetPersistent(bool *aPersistent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long fetchCount; */
NS_IMETHODIMP nsCacheEntry::GetFetchCount(int32_t *aFetchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lastFetched; */
NS_IMETHODIMP nsCacheEntry::GetLastFetched(uint32_t *aLastFetched)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lastModified; */
NS_IMETHODIMP nsCacheEntry::GetLastModified(uint32_t *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t expirationTime; */
NS_IMETHODIMP nsCacheEntry::GetExpirationTime(uint32_t *aExpirationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setExpirationTime (in uint32_t expirationTime); */
NS_IMETHODIMP nsCacheEntry::SetExpirationTime(uint32_t expirationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceValidFor (in unsigned long aSecondsToTheFuture); */
NS_IMETHODIMP nsCacheEntry::ForceValidFor(uint32_t aSecondsToTheFuture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isForcedValid; */
NS_IMETHODIMP nsCacheEntry::GetIsForcedValid(bool *aIsForcedValid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream openInputStream (in long long offset); */
NS_IMETHODIMP nsCacheEntry::OpenInputStream(int64_t offset, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOutputStream openOutputStream (in long long offset); */
NS_IMETHODIMP nsCacheEntry::OpenOutputStream(int64_t offset, nsIOutputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute int64_t predictedDataSize; */
NS_IMETHODIMP nsCacheEntry::GetPredictedDataSize(int64_t *aPredictedDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheEntry::SetPredictedDataSize(int64_t aPredictedDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports securityInfo; */
NS_IMETHODIMP nsCacheEntry::GetSecurityInfo(nsISupports * *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCacheEntry::SetSecurityInfo(nsISupports *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long storageDataSize; */
NS_IMETHODIMP nsCacheEntry::GetStorageDataSize(uint32_t *aStorageDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncDoom (in nsICacheEntryDoomCallback listener); */
NS_IMETHODIMP nsCacheEntry::AsyncDoom(nsICacheEntryDoomCallback *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getMetaDataElement (in string key); */
NS_IMETHODIMP nsCacheEntry::GetMetaDataElement(const char * key, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setMetaDataElement (in string key, in string value); */
NS_IMETHODIMP nsCacheEntry::SetMetaDataElement(const char * key, const char * value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void visitMetaData (in nsICacheEntryMetaDataVisitor visitor); */
NS_IMETHODIMP nsCacheEntry::VisitMetaData(nsICacheEntryMetaDataVisitor *visitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void metaDataReady (); */
NS_IMETHODIMP nsCacheEntry::MetaDataReady()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setValid (); */
NS_IMETHODIMP nsCacheEntry::SetValid()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICacheEntry recreate ([optional] in boolean aMemoryOnly); */
NS_IMETHODIMP nsCacheEntry::Recreate(bool aMemoryOnly, nsICacheEntry * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long dataSize; */
NS_IMETHODIMP nsCacheEntry::GetDataSize(int64_t *aDataSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsCacheEntry::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markValid (); */
NS_IMETHODIMP nsCacheEntry::MarkValid()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void maybeMarkValid (); */
NS_IMETHODIMP nsCacheEntry::MaybeMarkValid()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasWriteAccess (in boolean aWriteAllowed); */
NS_IMETHODIMP nsCacheEntry::HasWriteAccess(bool aWriteAllowed, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICacheEntryMetaDataVisitor */
#define NS_ICACHEENTRYMETADATAVISITOR_IID_STR "fea3e276-6ba5-4ceb-a581-807d1f43f6d0"

#define NS_ICACHEENTRYMETADATAVISITOR_IID \
  {0xfea3e276, 0x6ba5, 0x4ceb, \
    { 0xa5, 0x81, 0x80, 0x7d, 0x1f, 0x43, 0xf6, 0xd0 }}

class NS_NO_VTABLE nsICacheEntryMetaDataVisitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEENTRYMETADATAVISITOR_IID)

  /* void onMetaDataElement (in string key, in string value); */
  NS_IMETHOD OnMetaDataElement(const char * key, const char * value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheEntryMetaDataVisitor, NS_ICACHEENTRYMETADATAVISITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEENTRYMETADATAVISITOR \
  NS_IMETHOD OnMetaDataElement(const char * key, const char * value) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEENTRYMETADATAVISITOR(_to) \
  NS_IMETHOD OnMetaDataElement(const char * key, const char * value) override { return _to OnMetaDataElement(key, value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEENTRYMETADATAVISITOR(_to) \
  NS_IMETHOD OnMetaDataElement(const char * key, const char * value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnMetaDataElement(key, value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheEntryMetaDataVisitor : public nsICacheEntryMetaDataVisitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEENTRYMETADATAVISITOR

  nsCacheEntryMetaDataVisitor();

private:
  ~nsCacheEntryMetaDataVisitor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCacheEntryMetaDataVisitor, nsICacheEntryMetaDataVisitor)

nsCacheEntryMetaDataVisitor::nsCacheEntryMetaDataVisitor()
{
  /* member initializers and constructor code */
}

nsCacheEntryMetaDataVisitor::~nsCacheEntryMetaDataVisitor()
{
  /* destructor code */
}

/* void onMetaDataElement (in string key, in string value); */
NS_IMETHODIMP nsCacheEntryMetaDataVisitor::OnMetaDataElement(const char * key, const char * value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheEntry_h__ */
