/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINavBookmarksService.idl
 */

#ifndef __gen_nsINavBookmarksService_h__
#define __gen_nsINavBookmarksService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIURI; /* forward declaration */

class nsITransaction; /* forward declaration */

class nsINavHistoryBatchCallback; /* forward declaration */


/* starting interface:    nsINavBookmarkObserver */
#define NS_INAVBOOKMARKOBSERVER_IID_STR "8ab925f8-af9b-4837-afa0-ffed507212ce"

#define NS_INAVBOOKMARKOBSERVER_IID \
  {0x8ab925f8, 0xaf9b, 0x4837, \
    { 0xaf, 0xa0, 0xff, 0xed, 0x50, 0x72, 0x12, 0xce }}

class NS_NO_VTABLE nsINavBookmarkObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVBOOKMARKOBSERVER_IID)

  /* void onBeginUpdateBatch (); */
  NS_IMETHOD OnBeginUpdateBatch(void) = 0;

  /* void onEndUpdateBatch (); */
  NS_IMETHOD OnEndUpdateBatch(void) = 0;

  /* void onItemAdded (in long long aItemId, in long long aParentId, in long aIndex, in unsigned short aItemType, in nsIURI aURI, in AUTF8String aTitle, in PRTime aDateAdded, in ACString aGuid, in ACString aParentGuid); */
  NS_IMETHOD OnItemAdded(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aTitle, PRTime aDateAdded, const nsACString & aGuid, const nsACString & aParentGuid) = 0;

  /* void onItemRemoved (in long long aItemId, in long long aParentId, in long aIndex, in unsigned short aItemType, in nsIURI aURI, in ACString aGuid, in ACString aParentGuid); */
  NS_IMETHOD OnItemRemoved(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aGuid, const nsACString & aParentGuid) = 0;

  /* void onItemChanged (in long long aItemId, in ACString aProperty, in boolean aIsAnnotationProperty, in AUTF8String aNewValue, in PRTime aLastModified, in unsigned short aItemType, in long long aParentId, in ACString aGuid, in ACString aParentGuid); */
  NS_IMETHOD OnItemChanged(int64_t aItemId, const nsACString & aProperty, bool aIsAnnotationProperty, const nsACString & aNewValue, PRTime aLastModified, uint16_t aItemType, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid) = 0;

  /* void onItemVisited (in long long aItemId, in long long aVisitId, in PRTime aTime, in unsigned long aTransitionType, in nsIURI aURI, in long long aParentId, in ACString aGuid, in ACString aParentGuid); */
  NS_IMETHOD OnItemVisited(int64_t aItemId, int64_t aVisitId, PRTime aTime, uint32_t aTransitionType, nsIURI *aURI, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid) = 0;

  /* void onItemMoved (in long long aItemId, in long long aOldParentId, in long aOldIndex, in long long aNewParentId, in long aNewIndex, in unsigned short aItemType, in ACString aGuid, in ACString aOldParentGuid, in ACString aNewParentGuid); */
  NS_IMETHOD OnItemMoved(int64_t aItemId, int64_t aOldParentId, int32_t aOldIndex, int64_t aNewParentId, int32_t aNewIndex, uint16_t aItemType, const nsACString & aGuid, const nsACString & aOldParentGuid, const nsACString & aNewParentGuid) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavBookmarkObserver, NS_INAVBOOKMARKOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVBOOKMARKOBSERVER \
  NS_IMETHOD OnBeginUpdateBatch(void) override; \
  NS_IMETHOD OnEndUpdateBatch(void) override; \
  NS_IMETHOD OnItemAdded(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aTitle, PRTime aDateAdded, const nsACString & aGuid, const nsACString & aParentGuid) override; \
  NS_IMETHOD OnItemRemoved(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aGuid, const nsACString & aParentGuid) override; \
  NS_IMETHOD OnItemChanged(int64_t aItemId, const nsACString & aProperty, bool aIsAnnotationProperty, const nsACString & aNewValue, PRTime aLastModified, uint16_t aItemType, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid) override; \
  NS_IMETHOD OnItemVisited(int64_t aItemId, int64_t aVisitId, PRTime aTime, uint32_t aTransitionType, nsIURI *aURI, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid) override; \
  NS_IMETHOD OnItemMoved(int64_t aItemId, int64_t aOldParentId, int32_t aOldIndex, int64_t aNewParentId, int32_t aNewIndex, uint16_t aItemType, const nsACString & aGuid, const nsACString & aOldParentGuid, const nsACString & aNewParentGuid) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVBOOKMARKOBSERVER(_to) \
  NS_IMETHOD OnBeginUpdateBatch(void) override { return _to OnBeginUpdateBatch(); } \
  NS_IMETHOD OnEndUpdateBatch(void) override { return _to OnEndUpdateBatch(); } \
  NS_IMETHOD OnItemAdded(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aTitle, PRTime aDateAdded, const nsACString & aGuid, const nsACString & aParentGuid) override { return _to OnItemAdded(aItemId, aParentId, aIndex, aItemType, aURI, aTitle, aDateAdded, aGuid, aParentGuid); } \
  NS_IMETHOD OnItemRemoved(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aGuid, const nsACString & aParentGuid) override { return _to OnItemRemoved(aItemId, aParentId, aIndex, aItemType, aURI, aGuid, aParentGuid); } \
  NS_IMETHOD OnItemChanged(int64_t aItemId, const nsACString & aProperty, bool aIsAnnotationProperty, const nsACString & aNewValue, PRTime aLastModified, uint16_t aItemType, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid) override { return _to OnItemChanged(aItemId, aProperty, aIsAnnotationProperty, aNewValue, aLastModified, aItemType, aParentId, aGuid, aParentGuid); } \
  NS_IMETHOD OnItemVisited(int64_t aItemId, int64_t aVisitId, PRTime aTime, uint32_t aTransitionType, nsIURI *aURI, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid) override { return _to OnItemVisited(aItemId, aVisitId, aTime, aTransitionType, aURI, aParentId, aGuid, aParentGuid); } \
  NS_IMETHOD OnItemMoved(int64_t aItemId, int64_t aOldParentId, int32_t aOldIndex, int64_t aNewParentId, int32_t aNewIndex, uint16_t aItemType, const nsACString & aGuid, const nsACString & aOldParentGuid, const nsACString & aNewParentGuid) override { return _to OnItemMoved(aItemId, aOldParentId, aOldIndex, aNewParentId, aNewIndex, aItemType, aGuid, aOldParentGuid, aNewParentGuid); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVBOOKMARKOBSERVER(_to) \
  NS_IMETHOD OnBeginUpdateBatch(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeginUpdateBatch(); } \
  NS_IMETHOD OnEndUpdateBatch(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndUpdateBatch(); } \
  NS_IMETHOD OnItemAdded(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aTitle, PRTime aDateAdded, const nsACString & aGuid, const nsACString & aParentGuid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemAdded(aItemId, aParentId, aIndex, aItemType, aURI, aTitle, aDateAdded, aGuid, aParentGuid); } \
  NS_IMETHOD OnItemRemoved(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aGuid, const nsACString & aParentGuid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemRemoved(aItemId, aParentId, aIndex, aItemType, aURI, aGuid, aParentGuid); } \
  NS_IMETHOD OnItemChanged(int64_t aItemId, const nsACString & aProperty, bool aIsAnnotationProperty, const nsACString & aNewValue, PRTime aLastModified, uint16_t aItemType, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemChanged(aItemId, aProperty, aIsAnnotationProperty, aNewValue, aLastModified, aItemType, aParentId, aGuid, aParentGuid); } \
  NS_IMETHOD OnItemVisited(int64_t aItemId, int64_t aVisitId, PRTime aTime, uint32_t aTransitionType, nsIURI *aURI, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemVisited(aItemId, aVisitId, aTime, aTransitionType, aURI, aParentId, aGuid, aParentGuid); } \
  NS_IMETHOD OnItemMoved(int64_t aItemId, int64_t aOldParentId, int32_t aOldIndex, int64_t aNewParentId, int32_t aNewIndex, uint16_t aItemType, const nsACString & aGuid, const nsACString & aOldParentGuid, const nsACString & aNewParentGuid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemMoved(aItemId, aOldParentId, aOldIndex, aNewParentId, aNewIndex, aItemType, aGuid, aOldParentGuid, aNewParentGuid); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavBookmarkObserver : public nsINavBookmarkObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVBOOKMARKOBSERVER

  nsNavBookmarkObserver();

private:
  ~nsNavBookmarkObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavBookmarkObserver, nsINavBookmarkObserver)

nsNavBookmarkObserver::nsNavBookmarkObserver()
{
  /* member initializers and constructor code */
}

nsNavBookmarkObserver::~nsNavBookmarkObserver()
{
  /* destructor code */
}

/* void onBeginUpdateBatch (); */
NS_IMETHODIMP nsNavBookmarkObserver::OnBeginUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEndUpdateBatch (); */
NS_IMETHODIMP nsNavBookmarkObserver::OnEndUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemAdded (in long long aItemId, in long long aParentId, in long aIndex, in unsigned short aItemType, in nsIURI aURI, in AUTF8String aTitle, in PRTime aDateAdded, in ACString aGuid, in ACString aParentGuid); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemAdded(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aTitle, PRTime aDateAdded, const nsACString & aGuid, const nsACString & aParentGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemRemoved (in long long aItemId, in long long aParentId, in long aIndex, in unsigned short aItemType, in nsIURI aURI, in ACString aGuid, in ACString aParentGuid); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemRemoved(int64_t aItemId, int64_t aParentId, int32_t aIndex, uint16_t aItemType, nsIURI *aURI, const nsACString & aGuid, const nsACString & aParentGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemChanged (in long long aItemId, in ACString aProperty, in boolean aIsAnnotationProperty, in AUTF8String aNewValue, in PRTime aLastModified, in unsigned short aItemType, in long long aParentId, in ACString aGuid, in ACString aParentGuid); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemChanged(int64_t aItemId, const nsACString & aProperty, bool aIsAnnotationProperty, const nsACString & aNewValue, PRTime aLastModified, uint16_t aItemType, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemVisited (in long long aItemId, in long long aVisitId, in PRTime aTime, in unsigned long aTransitionType, in nsIURI aURI, in long long aParentId, in ACString aGuid, in ACString aParentGuid); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemVisited(int64_t aItemId, int64_t aVisitId, PRTime aTime, uint32_t aTransitionType, nsIURI *aURI, int64_t aParentId, const nsACString & aGuid, const nsACString & aParentGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemMoved (in long long aItemId, in long long aOldParentId, in long aOldIndex, in long long aNewParentId, in long aNewIndex, in unsigned short aItemType, in ACString aGuid, in ACString aOldParentGuid, in ACString aNewParentGuid); */
NS_IMETHODIMP nsNavBookmarkObserver::OnItemMoved(int64_t aItemId, int64_t aOldParentId, int32_t aOldIndex, int64_t aNewParentId, int32_t aNewIndex, uint16_t aItemType, const nsACString & aGuid, const nsACString & aOldParentGuid, const nsACString & aNewParentGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavBookmarksService */
#define NS_INAVBOOKMARKSSERVICE_IID_STR "24533891-afa6-4663-b72d-3143d03f1b04"

#define NS_INAVBOOKMARKSSERVICE_IID \
  {0x24533891, 0xafa6, 0x4663, \
    { 0xb7, 0x2d, 0x31, 0x43, 0xd0, 0x3f, 0x1b, 0x04 }}

class NS_NO_VTABLE nsINavBookmarksService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVBOOKMARKSSERVICE_IID)

  /* readonly attribute long long placesRoot; */
  NS_IMETHOD GetPlacesRoot(int64_t *aPlacesRoot) = 0;

  /* readonly attribute long long bookmarksMenuFolder; */
  NS_IMETHOD GetBookmarksMenuFolder(int64_t *aBookmarksMenuFolder) = 0;

  /* readonly attribute long long tagsFolder; */
  NS_IMETHOD GetTagsFolder(int64_t *aTagsFolder) = 0;

  /* readonly attribute long long unfiledBookmarksFolder; */
  NS_IMETHOD GetUnfiledBookmarksFolder(int64_t *aUnfiledBookmarksFolder) = 0;

  /* readonly attribute long long toolbarFolder; */
  NS_IMETHOD GetToolbarFolder(int64_t *aToolbarFolder) = 0;

  enum {
    DEFAULT_INDEX = -1,
    TYPE_BOOKMARK = 1U,
    TYPE_FOLDER = 2U,
    TYPE_SEPARATOR = 3U,
    TYPE_DYNAMIC_CONTAINER = 4U
  };

  /* long long insertBookmark (in long long aParentId, in nsIURI aURI, in long aIndex, in AUTF8String aTitle, [optional] in ACString aGuid); */
  NS_IMETHOD InsertBookmark(int64_t aParentId, nsIURI *aURI, int32_t aIndex, const nsACString & aTitle, const nsACString & aGuid, int64_t *_retval) = 0;

  /* void removeItem (in long long aItemId); */
  NS_IMETHOD RemoveItem(int64_t aItemId) = 0;

  /* long long createFolder (in long long aParentFolder, in AUTF8String name, in long index, [optional] in ACString aGuid); */
  NS_IMETHOD CreateFolder(int64_t aParentFolder, const nsACString & name, int32_t index, const nsACString & aGuid, int64_t *_retval) = 0;

  /* nsITransaction getRemoveFolderTransaction (in long long aItemId); */
  NS_IMETHOD GetRemoveFolderTransaction(int64_t aItemId, nsITransaction * *_retval) = 0;

  /* void removeFolderChildren (in long long aItemId); */
  NS_IMETHOD RemoveFolderChildren(int64_t aItemId) = 0;

  /* void moveItem (in long long aItemId, in long long aNewParentId, in long aIndex); */
  NS_IMETHOD MoveItem(int64_t aItemId, int64_t aNewParentId, int32_t aIndex) = 0;

  /* long long insertSeparator (in long long aParentId, in long aIndex, [optional] in ACString aGuid); */
  NS_IMETHOD InsertSeparator(int64_t aParentId, int32_t aIndex, const nsACString & aGuid, int64_t *_retval) = 0;

  /* long long getIdForItemAt (in long long aParentId, in long aIndex); */
  NS_IMETHOD GetIdForItemAt(int64_t aParentId, int32_t aIndex, int64_t *_retval) = 0;

  /* void setItemTitle (in long long aItemId, in AUTF8String aTitle); */
  NS_IMETHOD SetItemTitle(int64_t aItemId, const nsACString & aTitle) = 0;

  /* AUTF8String getItemTitle (in long long aItemId); */
  NS_IMETHOD GetItemTitle(int64_t aItemId, nsACString & _retval) = 0;

  /* void setItemDateAdded (in long long aItemId, in PRTime aDateAdded); */
  NS_IMETHOD SetItemDateAdded(int64_t aItemId, PRTime aDateAdded) = 0;

  /* PRTime getItemDateAdded (in long long aItemId); */
  NS_IMETHOD GetItemDateAdded(int64_t aItemId, PRTime *_retval) = 0;

  /* void setItemLastModified (in long long aItemId, in PRTime aLastModified); */
  NS_IMETHOD SetItemLastModified(int64_t aItemId, PRTime aLastModified) = 0;

  /* PRTime getItemLastModified (in long long aItemId); */
  NS_IMETHOD GetItemLastModified(int64_t aItemId, PRTime *_retval) = 0;

  /* nsIURI getBookmarkURI (in long long aItemId); */
  NS_IMETHOD GetBookmarkURI(int64_t aItemId, nsIURI * *_retval) = 0;

  /* long getItemIndex (in long long aItemId); */
  NS_IMETHOD GetItemIndex(int64_t aItemId, int32_t *_retval) = 0;

  /* void setItemIndex (in long long aItemId, in long aNewIndex); */
  NS_IMETHOD SetItemIndex(int64_t aItemId, int32_t aNewIndex) = 0;

  /* unsigned short getItemType (in long long aItemId); */
  NS_IMETHOD GetItemType(int64_t aItemId, uint16_t *_retval) = 0;

  /* boolean isBookmarked (in nsIURI aURI); */
  NS_IMETHOD IsBookmarked(nsIURI *aURI, bool *_retval) = 0;

  /* nsIURI getBookmarkedURIFor (in nsIURI aURI); */
  NS_IMETHOD GetBookmarkedURIFor(nsIURI *aURI, nsIURI * *_retval) = 0;

  /* void changeBookmarkURI (in long long aItemId, in nsIURI aNewURI); */
  NS_IMETHOD ChangeBookmarkURI(int64_t aItemId, nsIURI *aNewURI) = 0;

  /* long long getFolderIdForItem (in long long aItemId); */
  NS_IMETHOD GetFolderIdForItem(int64_t aItemId, int64_t *_retval) = 0;

  /* void getBookmarkIdsForURI (in nsIURI aURI, [optional] out unsigned long count, [array, size_is (count), retval] out long long bookmarks); */
  NS_IMETHOD GetBookmarkIdsForURI(nsIURI *aURI, uint32_t *count, int64_t **bookmarks) = 0;

  /* void setKeywordForBookmark (in long long aItemId, in AString aKeyword); */
  NS_IMETHOD SetKeywordForBookmark(int64_t aItemId, const nsAString & aKeyword) = 0;

  /* AString getKeywordForBookmark (in long long aItemId); */
  NS_IMETHOD GetKeywordForBookmark(int64_t aItemId, nsAString & _retval) = 0;

  /* nsIURI getURIForKeyword (in AString keyword); */
  NS_IMETHOD GetURIForKeyword(const nsAString & keyword, nsIURI * *_retval) = 0;

  /* void addObserver (in nsINavBookmarkObserver observer, in boolean ownsWeak); */
  NS_IMETHOD AddObserver(nsINavBookmarkObserver *observer, bool ownsWeak) = 0;

  /* void removeObserver (in nsINavBookmarkObserver observer); */
  NS_IMETHOD RemoveObserver(nsINavBookmarkObserver *observer) = 0;

  /* void getObservers ([optional] out unsigned long count, [array, size_is (count), retval] out nsINavBookmarkObserver observers); */
  NS_IMETHOD GetObservers(uint32_t *count, nsINavBookmarkObserver * **observers) = 0;

  /* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aUserData); */
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavBookmarksService, NS_INAVBOOKMARKSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVBOOKMARKSSERVICE \
  NS_IMETHOD GetPlacesRoot(int64_t *aPlacesRoot) override; \
  NS_IMETHOD GetBookmarksMenuFolder(int64_t *aBookmarksMenuFolder) override; \
  NS_IMETHOD GetTagsFolder(int64_t *aTagsFolder) override; \
  NS_IMETHOD GetUnfiledBookmarksFolder(int64_t *aUnfiledBookmarksFolder) override; \
  NS_IMETHOD GetToolbarFolder(int64_t *aToolbarFolder) override; \
  NS_IMETHOD InsertBookmark(int64_t aParentId, nsIURI *aURI, int32_t aIndex, const nsACString & aTitle, const nsACString & aGuid, int64_t *_retval) override; \
  NS_IMETHOD RemoveItem(int64_t aItemId) override; \
  NS_IMETHOD CreateFolder(int64_t aParentFolder, const nsACString & name, int32_t index, const nsACString & aGuid, int64_t *_retval) override; \
  NS_IMETHOD GetRemoveFolderTransaction(int64_t aItemId, nsITransaction * *_retval) override; \
  NS_IMETHOD RemoveFolderChildren(int64_t aItemId) override; \
  NS_IMETHOD MoveItem(int64_t aItemId, int64_t aNewParentId, int32_t aIndex) override; \
  NS_IMETHOD InsertSeparator(int64_t aParentId, int32_t aIndex, const nsACString & aGuid, int64_t *_retval) override; \
  NS_IMETHOD GetIdForItemAt(int64_t aParentId, int32_t aIndex, int64_t *_retval) override; \
  NS_IMETHOD SetItemTitle(int64_t aItemId, const nsACString & aTitle) override; \
  NS_IMETHOD GetItemTitle(int64_t aItemId, nsACString & _retval) override; \
  NS_IMETHOD SetItemDateAdded(int64_t aItemId, PRTime aDateAdded) override; \
  NS_IMETHOD GetItemDateAdded(int64_t aItemId, PRTime *_retval) override; \
  NS_IMETHOD SetItemLastModified(int64_t aItemId, PRTime aLastModified) override; \
  NS_IMETHOD GetItemLastModified(int64_t aItemId, PRTime *_retval) override; \
  NS_IMETHOD GetBookmarkURI(int64_t aItemId, nsIURI * *_retval) override; \
  NS_IMETHOD GetItemIndex(int64_t aItemId, int32_t *_retval) override; \
  NS_IMETHOD SetItemIndex(int64_t aItemId, int32_t aNewIndex) override; \
  NS_IMETHOD GetItemType(int64_t aItemId, uint16_t *_retval) override; \
  NS_IMETHOD IsBookmarked(nsIURI *aURI, bool *_retval) override; \
  NS_IMETHOD GetBookmarkedURIFor(nsIURI *aURI, nsIURI * *_retval) override; \
  NS_IMETHOD ChangeBookmarkURI(int64_t aItemId, nsIURI *aNewURI) override; \
  NS_IMETHOD GetFolderIdForItem(int64_t aItemId, int64_t *_retval) override; \
  NS_IMETHOD GetBookmarkIdsForURI(nsIURI *aURI, uint32_t *count, int64_t **bookmarks) override; \
  NS_IMETHOD SetKeywordForBookmark(int64_t aItemId, const nsAString & aKeyword) override; \
  NS_IMETHOD GetKeywordForBookmark(int64_t aItemId, nsAString & _retval) override; \
  NS_IMETHOD GetURIForKeyword(const nsAString & keyword, nsIURI * *_retval) override; \
  NS_IMETHOD AddObserver(nsINavBookmarkObserver *observer, bool ownsWeak) override; \
  NS_IMETHOD RemoveObserver(nsINavBookmarkObserver *observer) override; \
  NS_IMETHOD GetObservers(uint32_t *count, nsINavBookmarkObserver * **observers) override; \
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVBOOKMARKSSERVICE(_to) \
  NS_IMETHOD GetPlacesRoot(int64_t *aPlacesRoot) override { return _to GetPlacesRoot(aPlacesRoot); } \
  NS_IMETHOD GetBookmarksMenuFolder(int64_t *aBookmarksMenuFolder) override { return _to GetBookmarksMenuFolder(aBookmarksMenuFolder); } \
  NS_IMETHOD GetTagsFolder(int64_t *aTagsFolder) override { return _to GetTagsFolder(aTagsFolder); } \
  NS_IMETHOD GetUnfiledBookmarksFolder(int64_t *aUnfiledBookmarksFolder) override { return _to GetUnfiledBookmarksFolder(aUnfiledBookmarksFolder); } \
  NS_IMETHOD GetToolbarFolder(int64_t *aToolbarFolder) override { return _to GetToolbarFolder(aToolbarFolder); } \
  NS_IMETHOD InsertBookmark(int64_t aParentId, nsIURI *aURI, int32_t aIndex, const nsACString & aTitle, const nsACString & aGuid, int64_t *_retval) override { return _to InsertBookmark(aParentId, aURI, aIndex, aTitle, aGuid, _retval); } \
  NS_IMETHOD RemoveItem(int64_t aItemId) override { return _to RemoveItem(aItemId); } \
  NS_IMETHOD CreateFolder(int64_t aParentFolder, const nsACString & name, int32_t index, const nsACString & aGuid, int64_t *_retval) override { return _to CreateFolder(aParentFolder, name, index, aGuid, _retval); } \
  NS_IMETHOD GetRemoveFolderTransaction(int64_t aItemId, nsITransaction * *_retval) override { return _to GetRemoveFolderTransaction(aItemId, _retval); } \
  NS_IMETHOD RemoveFolderChildren(int64_t aItemId) override { return _to RemoveFolderChildren(aItemId); } \
  NS_IMETHOD MoveItem(int64_t aItemId, int64_t aNewParentId, int32_t aIndex) override { return _to MoveItem(aItemId, aNewParentId, aIndex); } \
  NS_IMETHOD InsertSeparator(int64_t aParentId, int32_t aIndex, const nsACString & aGuid, int64_t *_retval) override { return _to InsertSeparator(aParentId, aIndex, aGuid, _retval); } \
  NS_IMETHOD GetIdForItemAt(int64_t aParentId, int32_t aIndex, int64_t *_retval) override { return _to GetIdForItemAt(aParentId, aIndex, _retval); } \
  NS_IMETHOD SetItemTitle(int64_t aItemId, const nsACString & aTitle) override { return _to SetItemTitle(aItemId, aTitle); } \
  NS_IMETHOD GetItemTitle(int64_t aItemId, nsACString & _retval) override { return _to GetItemTitle(aItemId, _retval); } \
  NS_IMETHOD SetItemDateAdded(int64_t aItemId, PRTime aDateAdded) override { return _to SetItemDateAdded(aItemId, aDateAdded); } \
  NS_IMETHOD GetItemDateAdded(int64_t aItemId, PRTime *_retval) override { return _to GetItemDateAdded(aItemId, _retval); } \
  NS_IMETHOD SetItemLastModified(int64_t aItemId, PRTime aLastModified) override { return _to SetItemLastModified(aItemId, aLastModified); } \
  NS_IMETHOD GetItemLastModified(int64_t aItemId, PRTime *_retval) override { return _to GetItemLastModified(aItemId, _retval); } \
  NS_IMETHOD GetBookmarkURI(int64_t aItemId, nsIURI * *_retval) override { return _to GetBookmarkURI(aItemId, _retval); } \
  NS_IMETHOD GetItemIndex(int64_t aItemId, int32_t *_retval) override { return _to GetItemIndex(aItemId, _retval); } \
  NS_IMETHOD SetItemIndex(int64_t aItemId, int32_t aNewIndex) override { return _to SetItemIndex(aItemId, aNewIndex); } \
  NS_IMETHOD GetItemType(int64_t aItemId, uint16_t *_retval) override { return _to GetItemType(aItemId, _retval); } \
  NS_IMETHOD IsBookmarked(nsIURI *aURI, bool *_retval) override { return _to IsBookmarked(aURI, _retval); } \
  NS_IMETHOD GetBookmarkedURIFor(nsIURI *aURI, nsIURI * *_retval) override { return _to GetBookmarkedURIFor(aURI, _retval); } \
  NS_IMETHOD ChangeBookmarkURI(int64_t aItemId, nsIURI *aNewURI) override { return _to ChangeBookmarkURI(aItemId, aNewURI); } \
  NS_IMETHOD GetFolderIdForItem(int64_t aItemId, int64_t *_retval) override { return _to GetFolderIdForItem(aItemId, _retval); } \
  NS_IMETHOD GetBookmarkIdsForURI(nsIURI *aURI, uint32_t *count, int64_t **bookmarks) override { return _to GetBookmarkIdsForURI(aURI, count, bookmarks); } \
  NS_IMETHOD SetKeywordForBookmark(int64_t aItemId, const nsAString & aKeyword) override { return _to SetKeywordForBookmark(aItemId, aKeyword); } \
  NS_IMETHOD GetKeywordForBookmark(int64_t aItemId, nsAString & _retval) override { return _to GetKeywordForBookmark(aItemId, _retval); } \
  NS_IMETHOD GetURIForKeyword(const nsAString & keyword, nsIURI * *_retval) override { return _to GetURIForKeyword(keyword, _retval); } \
  NS_IMETHOD AddObserver(nsINavBookmarkObserver *observer, bool ownsWeak) override { return _to AddObserver(observer, ownsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavBookmarkObserver *observer) override { return _to RemoveObserver(observer); } \
  NS_IMETHOD GetObservers(uint32_t *count, nsINavBookmarkObserver * **observers) override { return _to GetObservers(count, observers); } \
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData) override { return _to RunInBatchMode(aCallback, aUserData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVBOOKMARKSSERVICE(_to) \
  NS_IMETHOD GetPlacesRoot(int64_t *aPlacesRoot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlacesRoot(aPlacesRoot); } \
  NS_IMETHOD GetBookmarksMenuFolder(int64_t *aBookmarksMenuFolder) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarksMenuFolder(aBookmarksMenuFolder); } \
  NS_IMETHOD GetTagsFolder(int64_t *aTagsFolder) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagsFolder(aTagsFolder); } \
  NS_IMETHOD GetUnfiledBookmarksFolder(int64_t *aUnfiledBookmarksFolder) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnfiledBookmarksFolder(aUnfiledBookmarksFolder); } \
  NS_IMETHOD GetToolbarFolder(int64_t *aToolbarFolder) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetToolbarFolder(aToolbarFolder); } \
  NS_IMETHOD InsertBookmark(int64_t aParentId, nsIURI *aURI, int32_t aIndex, const nsACString & aTitle, const nsACString & aGuid, int64_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertBookmark(aParentId, aURI, aIndex, aTitle, aGuid, _retval); } \
  NS_IMETHOD RemoveItem(int64_t aItemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItem(aItemId); } \
  NS_IMETHOD CreateFolder(int64_t aParentFolder, const nsACString & name, int32_t index, const nsACString & aGuid, int64_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFolder(aParentFolder, name, index, aGuid, _retval); } \
  NS_IMETHOD GetRemoveFolderTransaction(int64_t aItemId, nsITransaction * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemoveFolderTransaction(aItemId, _retval); } \
  NS_IMETHOD RemoveFolderChildren(int64_t aItemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFolderChildren(aItemId); } \
  NS_IMETHOD MoveItem(int64_t aItemId, int64_t aNewParentId, int32_t aIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveItem(aItemId, aNewParentId, aIndex); } \
  NS_IMETHOD InsertSeparator(int64_t aParentId, int32_t aIndex, const nsACString & aGuid, int64_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertSeparator(aParentId, aIndex, aGuid, _retval); } \
  NS_IMETHOD GetIdForItemAt(int64_t aParentId, int32_t aIndex, int64_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdForItemAt(aParentId, aIndex, _retval); } \
  NS_IMETHOD SetItemTitle(int64_t aItemId, const nsACString & aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemTitle(aItemId, aTitle); } \
  NS_IMETHOD GetItemTitle(int64_t aItemId, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemTitle(aItemId, _retval); } \
  NS_IMETHOD SetItemDateAdded(int64_t aItemId, PRTime aDateAdded) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemDateAdded(aItemId, aDateAdded); } \
  NS_IMETHOD GetItemDateAdded(int64_t aItemId, PRTime *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemDateAdded(aItemId, _retval); } \
  NS_IMETHOD SetItemLastModified(int64_t aItemId, PRTime aLastModified) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemLastModified(aItemId, aLastModified); } \
  NS_IMETHOD GetItemLastModified(int64_t aItemId, PRTime *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemLastModified(aItemId, _retval); } \
  NS_IMETHOD GetBookmarkURI(int64_t aItemId, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkURI(aItemId, _retval); } \
  NS_IMETHOD GetItemIndex(int64_t aItemId, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemIndex(aItemId, _retval); } \
  NS_IMETHOD SetItemIndex(int64_t aItemId, int32_t aNewIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemIndex(aItemId, aNewIndex); } \
  NS_IMETHOD GetItemType(int64_t aItemId, uint16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemType(aItemId, _retval); } \
  NS_IMETHOD IsBookmarked(nsIURI *aURI, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsBookmarked(aURI, _retval); } \
  NS_IMETHOD GetBookmarkedURIFor(nsIURI *aURI, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkedURIFor(aURI, _retval); } \
  NS_IMETHOD ChangeBookmarkURI(int64_t aItemId, nsIURI *aNewURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ChangeBookmarkURI(aItemId, aNewURI); } \
  NS_IMETHOD GetFolderIdForItem(int64_t aItemId, int64_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolderIdForItem(aItemId, _retval); } \
  NS_IMETHOD GetBookmarkIdsForURI(nsIURI *aURI, uint32_t *count, int64_t **bookmarks) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkIdsForURI(aURI, count, bookmarks); } \
  NS_IMETHOD SetKeywordForBookmark(int64_t aItemId, const nsAString & aKeyword) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKeywordForBookmark(aItemId, aKeyword); } \
  NS_IMETHOD GetKeywordForBookmark(int64_t aItemId, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeywordForBookmark(aItemId, _retval); } \
  NS_IMETHOD GetURIForKeyword(const nsAString & keyword, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURIForKeyword(keyword, _retval); } \
  NS_IMETHOD AddObserver(nsINavBookmarkObserver *observer, bool ownsWeak) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(observer, ownsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavBookmarkObserver *observer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(observer); } \
  NS_IMETHOD GetObservers(uint32_t *count, nsINavBookmarkObserver * **observers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObservers(count, observers); } \
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RunInBatchMode(aCallback, aUserData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavBookmarksService : public nsINavBookmarksService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVBOOKMARKSSERVICE

  nsNavBookmarksService();

private:
  ~nsNavBookmarksService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavBookmarksService, nsINavBookmarksService)

nsNavBookmarksService::nsNavBookmarksService()
{
  /* member initializers and constructor code */
}

nsNavBookmarksService::~nsNavBookmarksService()
{
  /* destructor code */
}

/* readonly attribute long long placesRoot; */
NS_IMETHODIMP nsNavBookmarksService::GetPlacesRoot(int64_t *aPlacesRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long bookmarksMenuFolder; */
NS_IMETHODIMP nsNavBookmarksService::GetBookmarksMenuFolder(int64_t *aBookmarksMenuFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long tagsFolder; */
NS_IMETHODIMP nsNavBookmarksService::GetTagsFolder(int64_t *aTagsFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long unfiledBookmarksFolder; */
NS_IMETHODIMP nsNavBookmarksService::GetUnfiledBookmarksFolder(int64_t *aUnfiledBookmarksFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long toolbarFolder; */
NS_IMETHODIMP nsNavBookmarksService::GetToolbarFolder(int64_t *aToolbarFolder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long insertBookmark (in long long aParentId, in nsIURI aURI, in long aIndex, in AUTF8String aTitle, [optional] in ACString aGuid); */
NS_IMETHODIMP nsNavBookmarksService::InsertBookmark(int64_t aParentId, nsIURI *aURI, int32_t aIndex, const nsACString & aTitle, const nsACString & aGuid, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItem (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::RemoveItem(int64_t aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long createFolder (in long long aParentFolder, in AUTF8String name, in long index, [optional] in ACString aGuid); */
NS_IMETHODIMP nsNavBookmarksService::CreateFolder(int64_t aParentFolder, const nsACString & name, int32_t index, const nsACString & aGuid, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransaction getRemoveFolderTransaction (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetRemoveFolderTransaction(int64_t aItemId, nsITransaction * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFolderChildren (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::RemoveFolderChildren(int64_t aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveItem (in long long aItemId, in long long aNewParentId, in long aIndex); */
NS_IMETHODIMP nsNavBookmarksService::MoveItem(int64_t aItemId, int64_t aNewParentId, int32_t aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long insertSeparator (in long long aParentId, in long aIndex, [optional] in ACString aGuid); */
NS_IMETHODIMP nsNavBookmarksService::InsertSeparator(int64_t aParentId, int32_t aIndex, const nsACString & aGuid, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long getIdForItemAt (in long long aParentId, in long aIndex); */
NS_IMETHODIMP nsNavBookmarksService::GetIdForItemAt(int64_t aParentId, int32_t aIndex, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemTitle (in long long aItemId, in AUTF8String aTitle); */
NS_IMETHODIMP nsNavBookmarksService::SetItemTitle(int64_t aItemId, const nsACString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getItemTitle (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemTitle(int64_t aItemId, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemDateAdded (in long long aItemId, in PRTime aDateAdded); */
NS_IMETHODIMP nsNavBookmarksService::SetItemDateAdded(int64_t aItemId, PRTime aDateAdded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRTime getItemDateAdded (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemDateAdded(int64_t aItemId, PRTime *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemLastModified (in long long aItemId, in PRTime aLastModified); */
NS_IMETHODIMP nsNavBookmarksService::SetItemLastModified(int64_t aItemId, PRTime aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRTime getItemLastModified (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemLastModified(int64_t aItemId, PRTime *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getBookmarkURI (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetBookmarkURI(int64_t aItemId, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getItemIndex (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemIndex(int64_t aItemId, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemIndex (in long long aItemId, in long aNewIndex); */
NS_IMETHODIMP nsNavBookmarksService::SetItemIndex(int64_t aItemId, int32_t aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short getItemType (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetItemType(int64_t aItemId, uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isBookmarked (in nsIURI aURI); */
NS_IMETHODIMP nsNavBookmarksService::IsBookmarked(nsIURI *aURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getBookmarkedURIFor (in nsIURI aURI); */
NS_IMETHODIMP nsNavBookmarksService::GetBookmarkedURIFor(nsIURI *aURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void changeBookmarkURI (in long long aItemId, in nsIURI aNewURI); */
NS_IMETHODIMP nsNavBookmarksService::ChangeBookmarkURI(int64_t aItemId, nsIURI *aNewURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long getFolderIdForItem (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetFolderIdForItem(int64_t aItemId, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBookmarkIdsForURI (in nsIURI aURI, [optional] out unsigned long count, [array, size_is (count), retval] out long long bookmarks); */
NS_IMETHODIMP nsNavBookmarksService::GetBookmarkIdsForURI(nsIURI *aURI, uint32_t *count, int64_t **bookmarks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setKeywordForBookmark (in long long aItemId, in AString aKeyword); */
NS_IMETHODIMP nsNavBookmarksService::SetKeywordForBookmark(int64_t aItemId, const nsAString & aKeyword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getKeywordForBookmark (in long long aItemId); */
NS_IMETHODIMP nsNavBookmarksService::GetKeywordForBookmark(int64_t aItemId, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getURIForKeyword (in AString keyword); */
NS_IMETHODIMP nsNavBookmarksService::GetURIForKeyword(const nsAString & keyword, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsINavBookmarkObserver observer, in boolean ownsWeak); */
NS_IMETHODIMP nsNavBookmarksService::AddObserver(nsINavBookmarkObserver *observer, bool ownsWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsINavBookmarkObserver observer); */
NS_IMETHODIMP nsNavBookmarksService::RemoveObserver(nsINavBookmarkObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getObservers ([optional] out unsigned long count, [array, size_is (count), retval] out nsINavBookmarkObserver observers); */
NS_IMETHODIMP nsNavBookmarksService::GetObservers(uint32_t *count, nsINavBookmarkObserver * **observers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aUserData); */
NS_IMETHODIMP nsNavBookmarksService::RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aUserData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINavBookmarksService_h__ */
