/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISHistory.idl
 */

#ifndef __gen_nsISHistory_h__
#define __gen_nsISHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISHEntry; /* forward declaration */

class nsISHistoryListener; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

#define NS_SHISTORY_CID \
{0x7b807041, 0xe60a, 0x4384, {0x93, 0x5f, 0xaf, 0x30, 0x61, 0xd8, 0xb8, 0x15}}
#define NS_SHISTORY_CONTRACTID "@mozilla.org/browser/shistory;1"

/* starting interface:    nsISHistory */
#define NS_ISHISTORY_IID_STR "7b807041-e60a-4384-935f-af3061d8b815"

#define NS_ISHISTORY_IID \
  {0x7b807041, 0xe60a, 0x4384, \
    { 0x93, 0x5f, 0xaf, 0x30, 0x61, 0xd8, 0xb8, 0x15 }}

class NS_NO_VTABLE nsISHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHISTORY_IID)

  /* readonly attribute long count; */
  NS_IMETHOD GetCount(int32_t *aCount) = 0;

  /* readonly attribute long index; */
  NS_IMETHOD GetIndex(int32_t *aIndex) = 0;

  /* readonly attribute long requestedIndex; */
  NS_IMETHOD GetRequestedIndex(int32_t *aRequestedIndex) = 0;

  /* attribute long maxLength; */
  NS_IMETHOD GetMaxLength(int32_t *aMaxLength) = 0;
  NS_IMETHOD SetMaxLength(int32_t aMaxLength) = 0;

  /* nsISHEntry getEntryAtIndex (in long index, in boolean modifyIndex); */
  NS_IMETHOD GetEntryAtIndex(int32_t index, bool modifyIndex, nsISHEntry * *_retval) = 0;

  /* void PurgeHistory (in long numEntries); */
  NS_IMETHOD PurgeHistory(int32_t numEntries) = 0;

  /* void addSHistoryListener (in nsISHistoryListener aListener); */
  NS_IMETHOD AddSHistoryListener(nsISHistoryListener *aListener) = 0;

  /* void removeSHistoryListener (in nsISHistoryListener aListener); */
  NS_IMETHOD RemoveSHistoryListener(nsISHistoryListener *aListener) = 0;

  /* readonly attribute nsISimpleEnumerator SHistoryEnumerator; */
  NS_IMETHOD GetSHistoryEnumerator(nsISimpleEnumerator * *aSHistoryEnumerator) = 0;

  /* void reloadCurrentEntry (); */
  NS_IMETHOD ReloadCurrentEntry(void) = 0;

  /* long getIndexOfEntry (in nsISHEntry aEntry); */
  NS_IMETHOD GetIndexOfEntry(nsISHEntry *aEntry, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHistory, NS_ISHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHISTORY \
  NS_IMETHOD GetCount(int32_t *aCount) override; \
  NS_IMETHOD GetIndex(int32_t *aIndex) override; \
  NS_IMETHOD GetRequestedIndex(int32_t *aRequestedIndex) override; \
  NS_IMETHOD GetMaxLength(int32_t *aMaxLength) override; \
  NS_IMETHOD SetMaxLength(int32_t aMaxLength) override; \
  NS_IMETHOD GetEntryAtIndex(int32_t index, bool modifyIndex, nsISHEntry * *_retval) override; \
  NS_IMETHOD PurgeHistory(int32_t numEntries) override; \
  NS_IMETHOD AddSHistoryListener(nsISHistoryListener *aListener) override; \
  NS_IMETHOD RemoveSHistoryListener(nsISHistoryListener *aListener) override; \
  NS_IMETHOD GetSHistoryEnumerator(nsISimpleEnumerator * *aSHistoryEnumerator) override; \
  NS_IMETHOD ReloadCurrentEntry(void) override; \
  NS_IMETHOD GetIndexOfEntry(nsISHEntry *aEntry, int32_t *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHISTORY(_to) \
  NS_IMETHOD GetCount(int32_t *aCount) override { return _to GetCount(aCount); } \
  NS_IMETHOD GetIndex(int32_t *aIndex) override { return _to GetIndex(aIndex); } \
  NS_IMETHOD GetRequestedIndex(int32_t *aRequestedIndex) override { return _to GetRequestedIndex(aRequestedIndex); } \
  NS_IMETHOD GetMaxLength(int32_t *aMaxLength) override { return _to GetMaxLength(aMaxLength); } \
  NS_IMETHOD SetMaxLength(int32_t aMaxLength) override { return _to SetMaxLength(aMaxLength); } \
  NS_IMETHOD GetEntryAtIndex(int32_t index, bool modifyIndex, nsISHEntry * *_retval) override { return _to GetEntryAtIndex(index, modifyIndex, _retval); } \
  NS_IMETHOD PurgeHistory(int32_t numEntries) override { return _to PurgeHistory(numEntries); } \
  NS_IMETHOD AddSHistoryListener(nsISHistoryListener *aListener) override { return _to AddSHistoryListener(aListener); } \
  NS_IMETHOD RemoveSHistoryListener(nsISHistoryListener *aListener) override { return _to RemoveSHistoryListener(aListener); } \
  NS_IMETHOD GetSHistoryEnumerator(nsISimpleEnumerator * *aSHistoryEnumerator) override { return _to GetSHistoryEnumerator(aSHistoryEnumerator); } \
  NS_IMETHOD ReloadCurrentEntry(void) override { return _to ReloadCurrentEntry(); } \
  NS_IMETHOD GetIndexOfEntry(nsISHEntry *aEntry, int32_t *_retval) override { return _to GetIndexOfEntry(aEntry, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHISTORY(_to) \
  NS_IMETHOD GetCount(int32_t *aCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(aCount); } \
  NS_IMETHOD GetIndex(int32_t *aIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndex(aIndex); } \
  NS_IMETHOD GetRequestedIndex(int32_t *aRequestedIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestedIndex(aRequestedIndex); } \
  NS_IMETHOD GetMaxLength(int32_t *aMaxLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxLength(aMaxLength); } \
  NS_IMETHOD SetMaxLength(int32_t aMaxLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxLength(aMaxLength); } \
  NS_IMETHOD GetEntryAtIndex(int32_t index, bool modifyIndex, nsISHEntry * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntryAtIndex(index, modifyIndex, _retval); } \
  NS_IMETHOD PurgeHistory(int32_t numEntries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PurgeHistory(numEntries); } \
  NS_IMETHOD AddSHistoryListener(nsISHistoryListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSHistoryListener(aListener); } \
  NS_IMETHOD RemoveSHistoryListener(nsISHistoryListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSHistoryListener(aListener); } \
  NS_IMETHOD GetSHistoryEnumerator(nsISimpleEnumerator * *aSHistoryEnumerator) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSHistoryEnumerator(aSHistoryEnumerator); } \
  NS_IMETHOD ReloadCurrentEntry(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadCurrentEntry(); } \
  NS_IMETHOD GetIndexOfEntry(nsISHEntry *aEntry, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfEntry(aEntry, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHistory : public nsISHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHISTORY

  nsSHistory();

private:
  ~nsSHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSHistory, nsISHistory)

nsSHistory::nsSHistory()
{
  /* member initializers and constructor code */
}

nsSHistory::~nsSHistory()
{
  /* destructor code */
}

/* readonly attribute long count; */
NS_IMETHODIMP nsSHistory::GetCount(int32_t *aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long index; */
NS_IMETHODIMP nsSHistory::GetIndex(int32_t *aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long requestedIndex; */
NS_IMETHODIMP nsSHistory::GetRequestedIndex(int32_t *aRequestedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxLength; */
NS_IMETHODIMP nsSHistory::GetMaxLength(int32_t *aMaxLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHistory::SetMaxLength(int32_t aMaxLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISHEntry getEntryAtIndex (in long index, in boolean modifyIndex); */
NS_IMETHODIMP nsSHistory::GetEntryAtIndex(int32_t index, bool modifyIndex, nsISHEntry * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void PurgeHistory (in long numEntries); */
NS_IMETHODIMP nsSHistory::PurgeHistory(int32_t numEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSHistoryListener (in nsISHistoryListener aListener); */
NS_IMETHODIMP nsSHistory::AddSHistoryListener(nsISHistoryListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSHistoryListener (in nsISHistoryListener aListener); */
NS_IMETHODIMP nsSHistory::RemoveSHistoryListener(nsISHistoryListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator SHistoryEnumerator; */
NS_IMETHODIMP nsSHistory::GetSHistoryEnumerator(nsISimpleEnumerator * *aSHistoryEnumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reloadCurrentEntry (); */
NS_IMETHODIMP nsSHistory::ReloadCurrentEntry()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfEntry (in nsISHEntry aEntry); */
NS_IMETHODIMP nsSHistory::GetIndexOfEntry(nsISHEntry *aEntry, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISHistory_h__ */
