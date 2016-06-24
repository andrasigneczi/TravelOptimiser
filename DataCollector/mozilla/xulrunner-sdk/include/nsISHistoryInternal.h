/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISHistoryInternal.idl
 */

#ifndef __gen_nsISHistoryInternal_h__
#define __gen_nsISHistoryInternal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBFCacheEntry; /* forward declaration */

class nsISHEntry; /* forward declaration */

class nsISHistoryListener; /* forward declaration */

class nsISHTransaction; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIURI; /* forward declaration */

#define NS_SHISTORY_INTERNAL_CID \
{ 0x3dfb2f54, 0x378d, 0x4d3c, \
  { 0xa9, 0xf9, 0x95, 0xdd, 0x26, 0x73, 0x24, 0x8c } }
#define NS_SHISTORY_INTERNAL_CONTRACTID "@mozilla.org/browser/shistory-internal;1"
#include "nsTArrayForwardDeclare.h"

/* starting interface:    nsISHistoryInternal */
#define NS_ISHISTORYINTERNAL_IID_STR "3dfb2f54-378d-4d3c-a9f9-95dd2673248c"

#define NS_ISHISTORYINTERNAL_IID \
  {0x3dfb2f54, 0x378d, 0x4d3c, \
    { 0xa9, 0xf9, 0x95, 0xdd, 0x26, 0x73, 0x24, 0x8c }}

class NS_NO_VTABLE nsISHistoryInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHISTORYINTERNAL_IID)

  /* void addEntry (in nsISHEntry aEntry, in boolean aPersist); */
  NS_IMETHOD AddEntry(nsISHEntry *aEntry, bool aPersist) = 0;

  /* readonly attribute nsISHTransaction rootTransaction; */
  NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) = 0;

  /* void setRootDocShell (in nsIDocShell rootDocShell); */
  NS_IMETHOD SetRootDocShell(nsIDocShell *rootDocShell) = 0;

  /* void updateIndex (); */
  NS_IMETHOD UpdateIndex(void) = 0;

  /* void replaceEntry (in long aIndex, in nsISHEntry aReplaceEntry); */
  NS_IMETHOD ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry) = 0;

  /* boolean notifyOnHistoryReload (in nsIURI aReloadURI, in unsigned long aReloadFlags); */
  NS_IMETHOD NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) = 0;

  /* void evictOutOfRangeContentViewers (in long aIndex); */
  NS_IMETHOD EvictOutOfRangeContentViewers(int32_t aIndex) = 0;

  /* void evictExpiredContentViewerForEntry (in nsIBFCacheEntry aEntry); */
  NS_IMETHOD EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry) = 0;

  /* void evictAllContentViewers (); */
  NS_IMETHOD EvictAllContentViewers(void) = 0;

  /* [noscript,notxpcom] void RemoveEntries (in nsDocshellIDArray aIDs, in long aStartIndex); */
  NS_IMETHOD_(void) RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHistoryInternal, NS_ISHISTORYINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHISTORYINTERNAL \
  NS_IMETHOD AddEntry(nsISHEntry *aEntry, bool aPersist) override; \
  NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) override; \
  NS_IMETHOD SetRootDocShell(nsIDocShell *rootDocShell) override; \
  NS_IMETHOD UpdateIndex(void) override; \
  NS_IMETHOD ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry) override; \
  NS_IMETHOD NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) override; \
  NS_IMETHOD EvictOutOfRangeContentViewers(int32_t aIndex) override; \
  NS_IMETHOD EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry) override; \
  NS_IMETHOD EvictAllContentViewers(void) override; \
  NS_IMETHOD_(void) RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHISTORYINTERNAL(_to) \
  NS_IMETHOD AddEntry(nsISHEntry *aEntry, bool aPersist) override { return _to AddEntry(aEntry, aPersist); } \
  NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) override { return _to GetRootTransaction(aRootTransaction); } \
  NS_IMETHOD SetRootDocShell(nsIDocShell *rootDocShell) override { return _to SetRootDocShell(rootDocShell); } \
  NS_IMETHOD UpdateIndex(void) override { return _to UpdateIndex(); } \
  NS_IMETHOD ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry) override { return _to ReplaceEntry(aIndex, aReplaceEntry); } \
  NS_IMETHOD NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) override { return _to NotifyOnHistoryReload(aReloadURI, aReloadFlags, _retval); } \
  NS_IMETHOD EvictOutOfRangeContentViewers(int32_t aIndex) override { return _to EvictOutOfRangeContentViewers(aIndex); } \
  NS_IMETHOD EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry) override { return _to EvictExpiredContentViewerForEntry(aEntry); } \
  NS_IMETHOD EvictAllContentViewers(void) override { return _to EvictAllContentViewers(); } \
  NS_IMETHOD_(void) RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex) override { return _to RemoveEntries(aIDs, aStartIndex); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHISTORYINTERNAL(_to) \
  NS_IMETHOD AddEntry(nsISHEntry *aEntry, bool aPersist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEntry(aEntry, aPersist); } \
  NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootTransaction(aRootTransaction); } \
  NS_IMETHOD SetRootDocShell(nsIDocShell *rootDocShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRootDocShell(rootDocShell); } \
  NS_IMETHOD UpdateIndex(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateIndex(); } \
  NS_IMETHOD ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceEntry(aIndex, aReplaceEntry); } \
  NS_IMETHOD NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyOnHistoryReload(aReloadURI, aReloadFlags, _retval); } \
  NS_IMETHOD EvictOutOfRangeContentViewers(int32_t aIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictOutOfRangeContentViewers(aIndex); } \
  NS_IMETHOD EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictExpiredContentViewerForEntry(aEntry); } \
  NS_IMETHOD EvictAllContentViewers(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictAllContentViewers(); } \
  NS_IMETHOD_(void) RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHistoryInternal : public nsISHistoryInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHISTORYINTERNAL

  nsSHistoryInternal();

private:
  ~nsSHistoryInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSHistoryInternal, nsISHistoryInternal)

nsSHistoryInternal::nsSHistoryInternal()
{
  /* member initializers and constructor code */
}

nsSHistoryInternal::~nsSHistoryInternal()
{
  /* destructor code */
}

/* void addEntry (in nsISHEntry aEntry, in boolean aPersist); */
NS_IMETHODIMP nsSHistoryInternal::AddEntry(nsISHEntry *aEntry, bool aPersist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISHTransaction rootTransaction; */
NS_IMETHODIMP nsSHistoryInternal::GetRootTransaction(nsISHTransaction * *aRootTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRootDocShell (in nsIDocShell rootDocShell); */
NS_IMETHODIMP nsSHistoryInternal::SetRootDocShell(nsIDocShell *rootDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateIndex (); */
NS_IMETHODIMP nsSHistoryInternal::UpdateIndex()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceEntry (in long aIndex, in nsISHEntry aReplaceEntry); */
NS_IMETHODIMP nsSHistoryInternal::ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean notifyOnHistoryReload (in nsIURI aReloadURI, in unsigned long aReloadFlags); */
NS_IMETHODIMP nsSHistoryInternal::NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictOutOfRangeContentViewers (in long aIndex); */
NS_IMETHODIMP nsSHistoryInternal::EvictOutOfRangeContentViewers(int32_t aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictExpiredContentViewerForEntry (in nsIBFCacheEntry aEntry); */
NS_IMETHODIMP nsSHistoryInternal::EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictAllContentViewers (); */
NS_IMETHODIMP nsSHistoryInternal::EvictAllContentViewers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void RemoveEntries (in nsDocshellIDArray aIDs, in long aStartIndex); */
NS_IMETHODIMP_(void) nsSHistoryInternal::RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISHistoryInternal_h__ */
