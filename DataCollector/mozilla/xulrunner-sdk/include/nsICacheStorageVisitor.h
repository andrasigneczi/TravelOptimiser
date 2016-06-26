/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICacheStorageVisitor.idl
 */

#ifndef __gen_nsICacheStorageVisitor_h__
#define __gen_nsICacheStorageVisitor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsICacheStorageVisitor */
#define NS_ICACHESTORAGEVISITOR_IID_STR "946bd799-9410-4945-9085-79c7fe019e83"

#define NS_ICACHESTORAGEVISITOR_IID \
  {0x946bd799, 0x9410, 0x4945, \
    { 0x90, 0x85, 0x79, 0xc7, 0xfe, 0x01, 0x9e, 0x83 }}

class NS_NO_VTABLE nsICacheStorageVisitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESTORAGEVISITOR_IID)

  /* void onCacheStorageInfo (in uint32_t aEntryCount, in uint64_t aConsumption, in uint64_t aCapacity, in nsIFile aDiskDirectory); */
  NS_IMETHOD OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption, uint64_t aCapacity, nsIFile *aDiskDirectory) = 0;

  /* void onCacheEntryInfo (in nsIURI aURI, in ACString aIdEnhance, in int64_t aDataSize, in long aFetchCount, in uint32_t aLastModifiedTime, in uint32_t aExpirationTime); */
  NS_IMETHOD OnCacheEntryInfo(nsIURI *aURI, const nsACString & aIdEnhance, int64_t aDataSize, int32_t aFetchCount, uint32_t aLastModifiedTime, uint32_t aExpirationTime) = 0;

  /* void onCacheEntryVisitCompleted (); */
  NS_IMETHOD OnCacheEntryVisitCompleted(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheStorageVisitor, NS_ICACHESTORAGEVISITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESTORAGEVISITOR \
  NS_IMETHOD OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption, uint64_t aCapacity, nsIFile *aDiskDirectory) override; \
  NS_IMETHOD OnCacheEntryInfo(nsIURI *aURI, const nsACString & aIdEnhance, int64_t aDataSize, int32_t aFetchCount, uint32_t aLastModifiedTime, uint32_t aExpirationTime) override; \
  NS_IMETHOD OnCacheEntryVisitCompleted(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESTORAGEVISITOR(_to) \
  NS_IMETHOD OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption, uint64_t aCapacity, nsIFile *aDiskDirectory) override { return _to OnCacheStorageInfo(aEntryCount, aConsumption, aCapacity, aDiskDirectory); } \
  NS_IMETHOD OnCacheEntryInfo(nsIURI *aURI, const nsACString & aIdEnhance, int64_t aDataSize, int32_t aFetchCount, uint32_t aLastModifiedTime, uint32_t aExpirationTime) override { return _to OnCacheEntryInfo(aURI, aIdEnhance, aDataSize, aFetchCount, aLastModifiedTime, aExpirationTime); } \
  NS_IMETHOD OnCacheEntryVisitCompleted(void) override { return _to OnCacheEntryVisitCompleted(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESTORAGEVISITOR(_to) \
  NS_IMETHOD OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption, uint64_t aCapacity, nsIFile *aDiskDirectory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheStorageInfo(aEntryCount, aConsumption, aCapacity, aDiskDirectory); } \
  NS_IMETHOD OnCacheEntryInfo(nsIURI *aURI, const nsACString & aIdEnhance, int64_t aDataSize, int32_t aFetchCount, uint32_t aLastModifiedTime, uint32_t aExpirationTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryInfo(aURI, aIdEnhance, aDataSize, aFetchCount, aLastModifiedTime, aExpirationTime); } \
  NS_IMETHOD OnCacheEntryVisitCompleted(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryVisitCompleted(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheStorageVisitor : public nsICacheStorageVisitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESTORAGEVISITOR

  nsCacheStorageVisitor();

private:
  ~nsCacheStorageVisitor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCacheStorageVisitor, nsICacheStorageVisitor)

nsCacheStorageVisitor::nsCacheStorageVisitor()
{
  /* member initializers and constructor code */
}

nsCacheStorageVisitor::~nsCacheStorageVisitor()
{
  /* destructor code */
}

/* void onCacheStorageInfo (in uint32_t aEntryCount, in uint64_t aConsumption, in uint64_t aCapacity, in nsIFile aDiskDirectory); */
NS_IMETHODIMP nsCacheStorageVisitor::OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption, uint64_t aCapacity, nsIFile *aDiskDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCacheEntryInfo (in nsIURI aURI, in ACString aIdEnhance, in int64_t aDataSize, in long aFetchCount, in uint32_t aLastModifiedTime, in uint32_t aExpirationTime); */
NS_IMETHODIMP nsCacheStorageVisitor::OnCacheEntryInfo(nsIURI *aURI, const nsACString & aIdEnhance, int64_t aDataSize, int32_t aFetchCount, uint32_t aLastModifiedTime, uint32_t aExpirationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCacheEntryVisitCompleted (); */
NS_IMETHODIMP nsCacheStorageVisitor::OnCacheEntryVisitCompleted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheStorageVisitor_h__ */
