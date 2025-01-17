/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINavHistoryService.idl
 */

#ifndef __gen_nsINavHistoryService_h__
#define __gen_nsINavHistoryService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIFile; /* forward declaration */

class nsINavHistoryContainerResultNode; /* forward declaration */

class nsINavHistoryQueryResultNode; /* forward declaration */

class nsINavHistoryQuery; /* forward declaration */

class nsINavHistoryQueryOptions; /* forward declaration */

class nsINavHistoryResult; /* forward declaration */

class nsINavHistoryBatchCallback; /* forward declaration */


/* starting interface:    nsINavHistoryResultNode */
#define NS_INAVHISTORYRESULTNODE_IID_STR "91d104bb-17ef-404b-9f9a-d9ed8de6824c"

#define NS_INAVHISTORYRESULTNODE_IID \
  {0x91d104bb, 0x17ef, 0x404b, \
    { 0x9f, 0x9a, 0xd9, 0xed, 0x8d, 0xe6, 0x82, 0x4c }}

class NS_NO_VTABLE nsINavHistoryResultNode : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULTNODE_IID)

  /* readonly attribute nsINavHistoryContainerResultNode parent; */
  NS_IMETHOD GetParent(nsINavHistoryContainerResultNode * *aParent) = 0;

  /* readonly attribute nsINavHistoryResult parentResult; */
  NS_IMETHOD GetParentResult(nsINavHistoryResult * *aParentResult) = 0;

  /* readonly attribute AUTF8String uri; */
  NS_IMETHOD GetUri(nsACString & aUri) = 0;

  enum {
    RESULT_TYPE_URI = 0U,
    RESULT_TYPE_QUERY = 5U,
    RESULT_TYPE_FOLDER = 6U,
    RESULT_TYPE_SEPARATOR = 7U,
    RESULT_TYPE_FOLDER_SHORTCUT = 9U
  };

  /* readonly attribute unsigned long type; */
  NS_IMETHOD GetType(uint32_t *aType) = 0;

  /* readonly attribute AUTF8String title; */
  NS_IMETHOD GetTitle(nsACString & aTitle) = 0;

  /* readonly attribute unsigned long accessCount; */
  NS_IMETHOD GetAccessCount(uint32_t *aAccessCount) = 0;

  /* readonly attribute PRTime time; */
  NS_IMETHOD GetTime(PRTime *aTime) = 0;

  /* readonly attribute AUTF8String icon; */
  NS_IMETHOD GetIcon(nsACString & aIcon) = 0;

  /* readonly attribute long indentLevel; */
  NS_IMETHOD GetIndentLevel(int32_t *aIndentLevel) = 0;

  /* readonly attribute long bookmarkIndex; */
  NS_IMETHOD GetBookmarkIndex(int32_t *aBookmarkIndex) = 0;

  /* readonly attribute long long itemId; */
  NS_IMETHOD GetItemId(int64_t *aItemId) = 0;

  /* readonly attribute PRTime dateAdded; */
  NS_IMETHOD GetDateAdded(PRTime *aDateAdded) = 0;

  /* readonly attribute PRTime lastModified; */
  NS_IMETHOD GetLastModified(PRTime *aLastModified) = 0;

  /* readonly attribute AString tags; */
  NS_IMETHOD GetTags(nsAString & aTags) = 0;

  /* readonly attribute ACString pageGuid; */
  NS_IMETHOD GetPageGuid(nsACString & aPageGuid) = 0;

  /* readonly attribute ACString bookmarkGuid; */
  NS_IMETHOD GetBookmarkGuid(nsACString & aBookmarkGuid) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResultNode, NS_INAVHISTORYRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULTNODE \
  NS_IMETHOD GetParent(nsINavHistoryContainerResultNode * *aParent) override; \
  NS_IMETHOD GetParentResult(nsINavHistoryResult * *aParentResult) override; \
  NS_IMETHOD GetUri(nsACString & aUri) override; \
  NS_IMETHOD GetType(uint32_t *aType) override; \
  NS_IMETHOD GetTitle(nsACString & aTitle) override; \
  NS_IMETHOD GetAccessCount(uint32_t *aAccessCount) override; \
  NS_IMETHOD GetTime(PRTime *aTime) override; \
  NS_IMETHOD GetIcon(nsACString & aIcon) override; \
  NS_IMETHOD GetIndentLevel(int32_t *aIndentLevel) override; \
  NS_IMETHOD GetBookmarkIndex(int32_t *aBookmarkIndex) override; \
  NS_IMETHOD GetItemId(int64_t *aItemId) override; \
  NS_IMETHOD GetDateAdded(PRTime *aDateAdded) override; \
  NS_IMETHOD GetLastModified(PRTime *aLastModified) override; \
  NS_IMETHOD GetTags(nsAString & aTags) override; \
  NS_IMETHOD GetPageGuid(nsACString & aPageGuid) override; \
  NS_IMETHOD GetBookmarkGuid(nsACString & aBookmarkGuid) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULTNODE(_to) \
  NS_IMETHOD GetParent(nsINavHistoryContainerResultNode * *aParent) override { return _to GetParent(aParent); } \
  NS_IMETHOD GetParentResult(nsINavHistoryResult * *aParentResult) override { return _to GetParentResult(aParentResult); } \
  NS_IMETHOD GetUri(nsACString & aUri) override { return _to GetUri(aUri); } \
  NS_IMETHOD GetType(uint32_t *aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetTitle(nsACString & aTitle) override { return _to GetTitle(aTitle); } \
  NS_IMETHOD GetAccessCount(uint32_t *aAccessCount) override { return _to GetAccessCount(aAccessCount); } \
  NS_IMETHOD GetTime(PRTime *aTime) override { return _to GetTime(aTime); } \
  NS_IMETHOD GetIcon(nsACString & aIcon) override { return _to GetIcon(aIcon); } \
  NS_IMETHOD GetIndentLevel(int32_t *aIndentLevel) override { return _to GetIndentLevel(aIndentLevel); } \
  NS_IMETHOD GetBookmarkIndex(int32_t *aBookmarkIndex) override { return _to GetBookmarkIndex(aBookmarkIndex); } \
  NS_IMETHOD GetItemId(int64_t *aItemId) override { return _to GetItemId(aItemId); } \
  NS_IMETHOD GetDateAdded(PRTime *aDateAdded) override { return _to GetDateAdded(aDateAdded); } \
  NS_IMETHOD GetLastModified(PRTime *aLastModified) override { return _to GetLastModified(aLastModified); } \
  NS_IMETHOD GetTags(nsAString & aTags) override { return _to GetTags(aTags); } \
  NS_IMETHOD GetPageGuid(nsACString & aPageGuid) override { return _to GetPageGuid(aPageGuid); } \
  NS_IMETHOD GetBookmarkGuid(nsACString & aBookmarkGuid) override { return _to GetBookmarkGuid(aBookmarkGuid); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULTNODE(_to) \
  NS_IMETHOD GetParent(nsINavHistoryContainerResultNode * *aParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_IMETHOD GetParentResult(nsINavHistoryResult * *aParentResult) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentResult(aParentResult); } \
  NS_IMETHOD GetUri(nsACString & aUri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD GetType(uint32_t *aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetTitle(nsACString & aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD GetAccessCount(uint32_t *aAccessCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessCount(aAccessCount); } \
  NS_IMETHOD GetTime(PRTime *aTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTime(aTime); } \
  NS_IMETHOD GetIcon(nsACString & aIcon) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIcon(aIcon); } \
  NS_IMETHOD GetIndentLevel(int32_t *aIndentLevel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndentLevel(aIndentLevel); } \
  NS_IMETHOD GetBookmarkIndex(int32_t *aBookmarkIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkIndex(aBookmarkIndex); } \
  NS_IMETHOD GetItemId(int64_t *aItemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemId(aItemId); } \
  NS_IMETHOD GetDateAdded(PRTime *aDateAdded) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDateAdded(aDateAdded); } \
  NS_IMETHOD GetLastModified(PRTime *aLastModified) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_IMETHOD GetTags(nsAString & aTags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTags(aTags); } \
  NS_IMETHOD GetPageGuid(nsACString & aPageGuid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageGuid(aPageGuid); } \
  NS_IMETHOD GetBookmarkGuid(nsACString & aBookmarkGuid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarkGuid(aBookmarkGuid); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResultNode : public nsINavHistoryResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULTNODE

  nsNavHistoryResultNode();

private:
  ~nsNavHistoryResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryResultNode, nsINavHistoryResultNode)

nsNavHistoryResultNode::nsNavHistoryResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryResultNode::~nsNavHistoryResultNode()
{
  /* destructor code */
}

/* readonly attribute nsINavHistoryContainerResultNode parent; */
NS_IMETHODIMP nsNavHistoryResultNode::GetParent(nsINavHistoryContainerResultNode * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINavHistoryResult parentResult; */
NS_IMETHODIMP nsNavHistoryResultNode::GetParentResult(nsINavHistoryResult * *aParentResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String uri; */
NS_IMETHODIMP nsNavHistoryResultNode::GetUri(nsACString & aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long type; */
NS_IMETHODIMP nsNavHistoryResultNode::GetType(uint32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String title; */
NS_IMETHODIMP nsNavHistoryResultNode::GetTitle(nsACString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long accessCount; */
NS_IMETHODIMP nsNavHistoryResultNode::GetAccessCount(uint32_t *aAccessCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime time; */
NS_IMETHODIMP nsNavHistoryResultNode::GetTime(PRTime *aTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String icon; */
NS_IMETHODIMP nsNavHistoryResultNode::GetIcon(nsACString & aIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long indentLevel; */
NS_IMETHODIMP nsNavHistoryResultNode::GetIndentLevel(int32_t *aIndentLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long bookmarkIndex; */
NS_IMETHODIMP nsNavHistoryResultNode::GetBookmarkIndex(int32_t *aBookmarkIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long itemId; */
NS_IMETHODIMP nsNavHistoryResultNode::GetItemId(int64_t *aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime dateAdded; */
NS_IMETHODIMP nsNavHistoryResultNode::GetDateAdded(PRTime *aDateAdded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModified; */
NS_IMETHODIMP nsNavHistoryResultNode::GetLastModified(PRTime *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString tags; */
NS_IMETHODIMP nsNavHistoryResultNode::GetTags(nsAString & aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString pageGuid; */
NS_IMETHODIMP nsNavHistoryResultNode::GetPageGuid(nsACString & aPageGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString bookmarkGuid; */
NS_IMETHODIMP nsNavHistoryResultNode::GetBookmarkGuid(nsACString & aBookmarkGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryContainerResultNode */
#define NS_INAVHISTORYCONTAINERRESULTNODE_IID_STR "3e9cc95f-0d93-45f1-894f-908eeb9866d7"

#define NS_INAVHISTORYCONTAINERRESULTNODE_IID \
  {0x3e9cc95f, 0x0d93, 0x45f1, \
    { 0x89, 0x4f, 0x90, 0x8e, 0xeb, 0x98, 0x66, 0xd7 }}

class NS_NO_VTABLE nsINavHistoryContainerResultNode : public nsINavHistoryResultNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYCONTAINERRESULTNODE_IID)

  /* attribute boolean containerOpen; */
  NS_IMETHOD GetContainerOpen(bool *aContainerOpen) = 0;
  NS_IMETHOD SetContainerOpen(bool aContainerOpen) = 0;

  /* readonly attribute unsigned short state; */
  NS_IMETHOD GetState(uint16_t *aState) = 0;

  enum {
    STATE_CLOSED = 0U,
    STATE_LOADING = 1U,
    STATE_OPENED = 2U
  };

  /* readonly attribute boolean hasChildren; */
  NS_IMETHOD GetHasChildren(bool *aHasChildren) = 0;

  /* readonly attribute unsigned long childCount; */
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) = 0;

  /* nsINavHistoryResultNode getChild (in unsigned long aIndex); */
  NS_IMETHOD GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval) = 0;

  /* unsigned long getChildIndex (in nsINavHistoryResultNode aNode); */
  NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval) = 0;

  /* nsINavHistoryResultNode findNodeByDetails (in AUTF8String aURIString, in PRTime aTime, in long long aItemId, in boolean aRecursive); */
  NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryContainerResultNode, NS_INAVHISTORYCONTAINERRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYCONTAINERRESULTNODE \
  NS_IMETHOD GetContainerOpen(bool *aContainerOpen) override; \
  NS_IMETHOD SetContainerOpen(bool aContainerOpen) override; \
  NS_IMETHOD GetState(uint16_t *aState) override; \
  NS_IMETHOD GetHasChildren(bool *aHasChildren) override; \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) override; \
  NS_IMETHOD GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval) override; \
  NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval) override; \
  NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYCONTAINERRESULTNODE(_to) \
  NS_IMETHOD GetContainerOpen(bool *aContainerOpen) override { return _to GetContainerOpen(aContainerOpen); } \
  NS_IMETHOD SetContainerOpen(bool aContainerOpen) override { return _to SetContainerOpen(aContainerOpen); } \
  NS_IMETHOD GetState(uint16_t *aState) override { return _to GetState(aState); } \
  NS_IMETHOD GetHasChildren(bool *aHasChildren) override { return _to GetHasChildren(aHasChildren); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) override { return _to GetChildCount(aChildCount); } \
  NS_IMETHOD GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval) override { return _to GetChild(aIndex, _retval); } \
  NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval) override { return _to GetChildIndex(aNode, _retval); } \
  NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval) override { return _to FindNodeByDetails(aURIString, aTime, aItemId, aRecursive, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYCONTAINERRESULTNODE(_to) \
  NS_IMETHOD GetContainerOpen(bool *aContainerOpen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainerOpen(aContainerOpen); } \
  NS_IMETHOD SetContainerOpen(bool aContainerOpen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContainerOpen(aContainerOpen); } \
  NS_IMETHOD GetState(uint16_t *aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD GetHasChildren(bool *aHasChildren) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasChildren(aHasChildren); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_IMETHOD GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChild(aIndex, _retval); } \
  NS_IMETHOD GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildIndex(aNode, _retval); } \
  NS_IMETHOD FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindNodeByDetails(aURIString, aTime, aItemId, aRecursive, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryContainerResultNode : public nsINavHistoryContainerResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYCONTAINERRESULTNODE

  nsNavHistoryContainerResultNode();

private:
  ~nsNavHistoryContainerResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryContainerResultNode, nsINavHistoryContainerResultNode)

nsNavHistoryContainerResultNode::nsNavHistoryContainerResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryContainerResultNode::~nsNavHistoryContainerResultNode()
{
  /* destructor code */
}

/* attribute boolean containerOpen; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetContainerOpen(bool *aContainerOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryContainerResultNode::SetContainerOpen(bool aContainerOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short state; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetState(uint16_t *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasChildren; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetHasChildren(bool *aHasChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childCount; */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChildCount(uint32_t *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResultNode getChild (in unsigned long aIndex); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChild(uint32_t aIndex, nsINavHistoryResultNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getChildIndex (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::GetChildIndex(nsINavHistoryResultNode *aNode, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResultNode findNodeByDetails (in AUTF8String aURIString, in PRTime aTime, in long long aItemId, in boolean aRecursive); */
NS_IMETHODIMP nsNavHistoryContainerResultNode::FindNodeByDetails(const nsACString & aURIString, PRTime aTime, int64_t aItemId, bool aRecursive, nsINavHistoryResultNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryQueryResultNode */
#define NS_INAVHISTORYQUERYRESULTNODE_IID_STR "62817759-4fee-44a3-b58c-3e2f5afc9d0a"

#define NS_INAVHISTORYQUERYRESULTNODE_IID \
  {0x62817759, 0x4fee, 0x44a3, \
    { 0xb5, 0x8c, 0x3e, 0x2f, 0x5a, 0xfc, 0x9d, 0x0a }}

class NS_NO_VTABLE nsINavHistoryQueryResultNode : public nsINavHistoryContainerResultNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYQUERYRESULTNODE_IID)

  /* void getQueries ([optional] out unsigned long queryCount, [array, size_is (queryCount), retval] out nsINavHistoryQuery queries); */
  NS_IMETHOD GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries) = 0;

  /* readonly attribute nsINavHistoryQueryOptions queryOptions; */
  NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions) = 0;

  /* readonly attribute long long folderItemId; */
  NS_IMETHOD GetFolderItemId(int64_t *aFolderItemId) = 0;

  /* readonly attribute ACString targetFolderGuid; */
  NS_IMETHOD GetTargetFolderGuid(nsACString & aTargetFolderGuid) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryQueryResultNode, NS_INAVHISTORYQUERYRESULTNODE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYQUERYRESULTNODE \
  NS_IMETHOD GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries) override; \
  NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions) override; \
  NS_IMETHOD GetFolderItemId(int64_t *aFolderItemId) override; \
  NS_IMETHOD GetTargetFolderGuid(nsACString & aTargetFolderGuid) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYQUERYRESULTNODE(_to) \
  NS_IMETHOD GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries) override { return _to GetQueries(queryCount, queries); } \
  NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions) override { return _to GetQueryOptions(aQueryOptions); } \
  NS_IMETHOD GetFolderItemId(int64_t *aFolderItemId) override { return _to GetFolderItemId(aFolderItemId); } \
  NS_IMETHOD GetTargetFolderGuid(nsACString & aTargetFolderGuid) override { return _to GetTargetFolderGuid(aTargetFolderGuid); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYQUERYRESULTNODE(_to) \
  NS_IMETHOD GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueries(queryCount, queries); } \
  NS_IMETHOD GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueryOptions(aQueryOptions); } \
  NS_IMETHOD GetFolderItemId(int64_t *aFolderItemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolderItemId(aFolderItemId); } \
  NS_IMETHOD GetTargetFolderGuid(nsACString & aTargetFolderGuid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetFolderGuid(aTargetFolderGuid); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryQueryResultNode : public nsINavHistoryQueryResultNode
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYQUERYRESULTNODE

  nsNavHistoryQueryResultNode();

private:
  ~nsNavHistoryQueryResultNode();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryQueryResultNode, nsINavHistoryQueryResultNode)

nsNavHistoryQueryResultNode::nsNavHistoryQueryResultNode()
{
  /* member initializers and constructor code */
}

nsNavHistoryQueryResultNode::~nsNavHistoryQueryResultNode()
{
  /* destructor code */
}

/* void getQueries ([optional] out unsigned long queryCount, [array, size_is (queryCount), retval] out nsINavHistoryQuery queries); */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetQueries(uint32_t *queryCount, nsINavHistoryQuery * **queries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINavHistoryQueryOptions queryOptions; */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetQueryOptions(nsINavHistoryQueryOptions * *aQueryOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long folderItemId; */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetFolderItemId(int64_t *aFolderItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString targetFolderGuid; */
NS_IMETHODIMP nsNavHistoryQueryResultNode::GetTargetFolderGuid(nsACString & aTargetFolderGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryResultObserver */
#define NS_INAVHISTORYRESULTOBSERVER_IID_STR "f62d8b6b-3c4e-4a9f-a897-db605d0b7a0f"

#define NS_INAVHISTORYRESULTOBSERVER_IID \
  {0xf62d8b6b, 0x3c4e, 0x4a9f, \
    { 0xa8, 0x97, 0xdb, 0x60, 0x5d, 0x0b, 0x7a, 0x0f }}

class NS_NO_VTABLE nsINavHistoryResultObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULTOBSERVER_IID)

  /* void nodeInserted (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aNode, in unsigned long aNewIndex); */
  NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex) = 0;

  /* void nodeRemoved (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aItem, in unsigned long aOldIndex); */
  NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex) = 0;

  /* void nodeMoved (in nsINavHistoryResultNode aNode, in nsINavHistoryContainerResultNode aOldParent, in unsigned long aOldIndex, in nsINavHistoryContainerResultNode aNewParent, in unsigned long aNewIndex); */
  NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex) = 0;

  /* void nodeTitleChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewTitle); */
  NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) = 0;

  /* void nodeURIChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewURI); */
  NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) = 0;

  /* void nodeIconChanged (in nsINavHistoryResultNode aNode); */
  NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) = 0;

  /* void nodeHistoryDetailsChanged (in nsINavHistoryResultNode aNode, in PRTime aNewVisitDate, in unsigned long aNewAccessCount); */
  NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount) = 0;

  /* void nodeTagsChanged (in nsINavHistoryResultNode aNode); */
  NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) = 0;

  /* void nodeKeywordChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewKeyword); */
  NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) = 0;

  /* void nodeAnnotationChanged (in nsINavHistoryResultNode aNode, in AUTF8String aAnnoName); */
  NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) = 0;

  /* void nodeDateAddedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
  NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) = 0;

  /* void nodeLastModifiedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
  NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) = 0;

  /* void containerStateChanged (in nsINavHistoryContainerResultNode aContainerNode, in unsigned long aOldState, in unsigned long aNewState); */
  NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState) = 0;

  /* void invalidateContainer (in nsINavHistoryContainerResultNode aContainerNode); */
  NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) = 0;

  /* void sortingChanged (in unsigned short sortingMode); */
  NS_IMETHOD SortingChanged(uint16_t sortingMode) = 0;

  /* void batching (in boolean aToggleMode); */
  NS_IMETHOD Batching(bool aToggleMode) = 0;

  /* attribute nsINavHistoryResult result; */
  NS_IMETHOD GetResult(nsINavHistoryResult * *aResult) = 0;
  NS_IMETHOD SetResult(nsINavHistoryResult *aResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResultObserver, NS_INAVHISTORYRESULTOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULTOBSERVER \
  NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex) override; \
  NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex) override; \
  NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex) override; \
  NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) override; \
  NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) override; \
  NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) override; \
  NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount) override; \
  NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) override; \
  NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) override; \
  NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) override; \
  NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) override; \
  NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) override; \
  NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState) override; \
  NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) override; \
  NS_IMETHOD SortingChanged(uint16_t sortingMode) override; \
  NS_IMETHOD Batching(bool aToggleMode) override; \
  NS_IMETHOD GetResult(nsINavHistoryResult * *aResult) override; \
  NS_IMETHOD SetResult(nsINavHistoryResult *aResult) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULTOBSERVER(_to) \
  NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex) override { return _to NodeInserted(aParent, aNode, aNewIndex); } \
  NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex) override { return _to NodeRemoved(aParent, aItem, aOldIndex); } \
  NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex) override { return _to NodeMoved(aNode, aOldParent, aOldIndex, aNewParent, aNewIndex); } \
  NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) override { return _to NodeTitleChanged(aNode, aNewTitle); } \
  NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) override { return _to NodeURIChanged(aNode, aNewURI); } \
  NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) override { return _to NodeIconChanged(aNode); } \
  NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount) override { return _to NodeHistoryDetailsChanged(aNode, aNewVisitDate, aNewAccessCount); } \
  NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) override { return _to NodeTagsChanged(aNode); } \
  NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) override { return _to NodeKeywordChanged(aNode, aNewKeyword); } \
  NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) override { return _to NodeAnnotationChanged(aNode, aAnnoName); } \
  NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) override { return _to NodeDateAddedChanged(aNode, aNewValue); } \
  NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) override { return _to NodeLastModifiedChanged(aNode, aNewValue); } \
  NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState) override { return _to ContainerStateChanged(aContainerNode, aOldState, aNewState); } \
  NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) override { return _to InvalidateContainer(aContainerNode); } \
  NS_IMETHOD SortingChanged(uint16_t sortingMode) override { return _to SortingChanged(sortingMode); } \
  NS_IMETHOD Batching(bool aToggleMode) override { return _to Batching(aToggleMode); } \
  NS_IMETHOD GetResult(nsINavHistoryResult * *aResult) override { return _to GetResult(aResult); } \
  NS_IMETHOD SetResult(nsINavHistoryResult *aResult) override { return _to SetResult(aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULTOBSERVER(_to) \
  NS_IMETHOD NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeInserted(aParent, aNode, aNewIndex); } \
  NS_IMETHOD NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeRemoved(aParent, aItem, aOldIndex); } \
  NS_IMETHOD NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeMoved(aNode, aOldParent, aOldIndex, aNewParent, aNewIndex); } \
  NS_IMETHOD NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeTitleChanged(aNode, aNewTitle); } \
  NS_IMETHOD NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeURIChanged(aNode, aNewURI); } \
  NS_IMETHOD NodeIconChanged(nsINavHistoryResultNode *aNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeIconChanged(aNode); } \
  NS_IMETHOD NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeHistoryDetailsChanged(aNode, aNewVisitDate, aNewAccessCount); } \
  NS_IMETHOD NodeTagsChanged(nsINavHistoryResultNode *aNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeTagsChanged(aNode); } \
  NS_IMETHOD NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeKeywordChanged(aNode, aNewKeyword); } \
  NS_IMETHOD NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeAnnotationChanged(aNode, aAnnoName); } \
  NS_IMETHOD NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeDateAddedChanged(aNode, aNewValue); } \
  NS_IMETHOD NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeLastModifiedChanged(aNode, aNewValue); } \
  NS_IMETHOD ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainerStateChanged(aContainerNode, aOldState, aNewState); } \
  NS_IMETHOD InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateContainer(aContainerNode); } \
  NS_IMETHOD SortingChanged(uint16_t sortingMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SortingChanged(sortingMode); } \
  NS_IMETHOD Batching(bool aToggleMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Batching(aToggleMode); } \
  NS_IMETHOD GetResult(nsINavHistoryResult * *aResult) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_IMETHOD SetResult(nsINavHistoryResult *aResult) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResult(aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResultObserver : public nsINavHistoryResultObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULTOBSERVER

  nsNavHistoryResultObserver();

private:
  ~nsNavHistoryResultObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryResultObserver, nsINavHistoryResultObserver)

nsNavHistoryResultObserver::nsNavHistoryResultObserver()
{
  /* member initializers and constructor code */
}

nsNavHistoryResultObserver::~nsNavHistoryResultObserver()
{
  /* destructor code */
}

/* void nodeInserted (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aNode, in unsigned long aNewIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeInserted(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aNode, uint32_t aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeRemoved (in nsINavHistoryContainerResultNode aParent, in nsINavHistoryResultNode aItem, in unsigned long aOldIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeRemoved(nsINavHistoryContainerResultNode *aParent, nsINavHistoryResultNode *aItem, uint32_t aOldIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeMoved (in nsINavHistoryResultNode aNode, in nsINavHistoryContainerResultNode aOldParent, in unsigned long aOldIndex, in nsINavHistoryContainerResultNode aNewParent, in unsigned long aNewIndex); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeMoved(nsINavHistoryResultNode *aNode, nsINavHistoryContainerResultNode *aOldParent, uint32_t aOldIndex, nsINavHistoryContainerResultNode *aNewParent, uint32_t aNewIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeTitleChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewTitle); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeTitleChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeURIChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewURI); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeURIChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeIconChanged (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeIconChanged(nsINavHistoryResultNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeHistoryDetailsChanged (in nsINavHistoryResultNode aNode, in PRTime aNewVisitDate, in unsigned long aNewAccessCount); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeHistoryDetailsChanged(nsINavHistoryResultNode *aNode, PRTime aNewVisitDate, uint32_t aNewAccessCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeTagsChanged (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeTagsChanged(nsINavHistoryResultNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeKeywordChanged (in nsINavHistoryResultNode aNode, in AUTF8String aNewKeyword); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeKeywordChanged(nsINavHistoryResultNode *aNode, const nsACString & aNewKeyword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeAnnotationChanged (in nsINavHistoryResultNode aNode, in AUTF8String aAnnoName); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeAnnotationChanged(nsINavHistoryResultNode *aNode, const nsACString & aAnnoName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeDateAddedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeDateAddedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void nodeLastModifiedChanged (in nsINavHistoryResultNode aNode, in PRTime aNewValue); */
NS_IMETHODIMP nsNavHistoryResultObserver::NodeLastModifiedChanged(nsINavHistoryResultNode *aNode, PRTime aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void containerStateChanged (in nsINavHistoryContainerResultNode aContainerNode, in unsigned long aOldState, in unsigned long aNewState); */
NS_IMETHODIMP nsNavHistoryResultObserver::ContainerStateChanged(nsINavHistoryContainerResultNode *aContainerNode, uint32_t aOldState, uint32_t aNewState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateContainer (in nsINavHistoryContainerResultNode aContainerNode); */
NS_IMETHODIMP nsNavHistoryResultObserver::InvalidateContainer(nsINavHistoryContainerResultNode *aContainerNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sortingChanged (in unsigned short sortingMode); */
NS_IMETHODIMP nsNavHistoryResultObserver::SortingChanged(uint16_t sortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void batching (in boolean aToggleMode); */
NS_IMETHODIMP nsNavHistoryResultObserver::Batching(bool aToggleMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsINavHistoryResult result; */
NS_IMETHODIMP nsNavHistoryResultObserver::GetResult(nsINavHistoryResult * *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResultObserver::SetResult(nsINavHistoryResult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryResultTreeViewer */
#define NS_INAVHISTORYRESULTTREEVIEWER_IID_STR "f8b518c0-1faf-11df-8a39-0800200c9a66"

#define NS_INAVHISTORYRESULTTREEVIEWER_IID \
  {0xf8b518c0, 0x1faf, 0x11df, \
    { 0x8a, 0x39, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsINavHistoryResultTreeViewer : public nsINavHistoryResultObserver {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULTTREEVIEWER_IID)

  /* nsINavHistoryResultNode nodeForTreeIndex (in unsigned long aIndex); */
  NS_IMETHOD NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval) = 0;

  enum {
    INDEX_INVISIBLE = 4294967295U
  };

  /* unsigned long treeIndexForNode (in nsINavHistoryResultNode aNode); */
  NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResultTreeViewer, NS_INAVHISTORYRESULTTREEVIEWER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULTTREEVIEWER \
  NS_IMETHOD NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval) override; \
  NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULTTREEVIEWER(_to) \
  NS_IMETHOD NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval) override { return _to NodeForTreeIndex(aIndex, _retval); } \
  NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval) override { return _to TreeIndexForNode(aNode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULTTREEVIEWER(_to) \
  NS_IMETHOD NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodeForTreeIndex(aIndex, _retval); } \
  NS_IMETHOD TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TreeIndexForNode(aNode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResultTreeViewer : public nsINavHistoryResultTreeViewer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULTTREEVIEWER

  nsNavHistoryResultTreeViewer();

private:
  ~nsNavHistoryResultTreeViewer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryResultTreeViewer, nsINavHistoryResultTreeViewer)

nsNavHistoryResultTreeViewer::nsNavHistoryResultTreeViewer()
{
  /* member initializers and constructor code */
}

nsNavHistoryResultTreeViewer::~nsNavHistoryResultTreeViewer()
{
  /* destructor code */
}

/* nsINavHistoryResultNode nodeForTreeIndex (in unsigned long aIndex); */
NS_IMETHODIMP nsNavHistoryResultTreeViewer::NodeForTreeIndex(uint32_t aIndex, nsINavHistoryResultNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long treeIndexForNode (in nsINavHistoryResultNode aNode); */
NS_IMETHODIMP nsNavHistoryResultTreeViewer::TreeIndexForNode(nsINavHistoryResultNode *aNode, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryResult */
#define NS_INAVHISTORYRESULT_IID_STR "c2229ce3-2159-4001-859c-7013c52f7619"

#define NS_INAVHISTORYRESULT_IID \
  {0xc2229ce3, 0x2159, 0x4001, \
    { 0x85, 0x9c, 0x70, 0x13, 0xc5, 0x2f, 0x76, 0x19 }}

class NS_NO_VTABLE nsINavHistoryResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYRESULT_IID)

  /* attribute unsigned short sortingMode; */
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) = 0;
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) = 0;

  /* attribute AUTF8String sortingAnnotation; */
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) = 0;
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) = 0;

  /* attribute boolean suppressNotifications; */
  NS_IMETHOD GetSuppressNotifications(bool *aSuppressNotifications) = 0;
  NS_IMETHOD SetSuppressNotifications(bool aSuppressNotifications) = 0;

  /* void addObserver (in nsINavHistoryResultObserver aObserver, in boolean aOwnsWeak); */
  NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak) = 0;

  /* void removeObserver (in nsINavHistoryResultObserver aObserver); */
  NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) = 0;

  /* readonly attribute nsINavHistoryContainerResultNode root; */
  NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode * *aRoot) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryResult, NS_INAVHISTORYRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYRESULT \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) override; \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) override; \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) override; \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) override; \
  NS_IMETHOD GetSuppressNotifications(bool *aSuppressNotifications) override; \
  NS_IMETHOD SetSuppressNotifications(bool aSuppressNotifications) override; \
  NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak) override; \
  NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) override; \
  NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode * *aRoot) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYRESULT(_to) \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) override { return _to GetSortingMode(aSortingMode); } \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) override { return _to SetSortingMode(aSortingMode); } \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) override { return _to GetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) override { return _to SetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD GetSuppressNotifications(bool *aSuppressNotifications) override { return _to GetSuppressNotifications(aSuppressNotifications); } \
  NS_IMETHOD SetSuppressNotifications(bool aSuppressNotifications) override { return _to SetSuppressNotifications(aSuppressNotifications); } \
  NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak) override { return _to AddObserver(aObserver, aOwnsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) override { return _to RemoveObserver(aObserver); } \
  NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode * *aRoot) override { return _to GetRoot(aRoot); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYRESULT(_to) \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingMode(aSortingMode); } \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingMode(aSortingMode); } \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD GetSuppressNotifications(bool *aSuppressNotifications) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuppressNotifications(aSuppressNotifications); } \
  NS_IMETHOD SetSuppressNotifications(bool aSuppressNotifications) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSuppressNotifications(aSuppressNotifications); } \
  NS_IMETHOD AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver, aOwnsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavHistoryResultObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_IMETHOD GetRoot(nsINavHistoryContainerResultNode * *aRoot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryResult : public nsINavHistoryResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYRESULT

  nsNavHistoryResult();

private:
  ~nsNavHistoryResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryResult, nsINavHistoryResult)

nsNavHistoryResult::nsNavHistoryResult()
{
  /* member initializers and constructor code */
}

nsNavHistoryResult::~nsNavHistoryResult()
{
  /* destructor code */
}

/* attribute unsigned short sortingMode; */
NS_IMETHODIMP nsNavHistoryResult::GetSortingMode(uint16_t *aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResult::SetSortingMode(uint16_t aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String sortingAnnotation; */
NS_IMETHODIMP nsNavHistoryResult::GetSortingAnnotation(nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResult::SetSortingAnnotation(const nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean suppressNotifications; */
NS_IMETHODIMP nsNavHistoryResult::GetSuppressNotifications(bool *aSuppressNotifications)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryResult::SetSuppressNotifications(bool aSuppressNotifications)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsINavHistoryResultObserver aObserver, in boolean aOwnsWeak); */
NS_IMETHODIMP nsNavHistoryResult::AddObserver(nsINavHistoryResultObserver *aObserver, bool aOwnsWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsINavHistoryResultObserver aObserver); */
NS_IMETHODIMP nsNavHistoryResult::RemoveObserver(nsINavHistoryResultObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINavHistoryContainerResultNode root; */
NS_IMETHODIMP nsNavHistoryResult::GetRoot(nsINavHistoryContainerResultNode * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryObserver */
#define NS_INAVHISTORYOBSERVER_IID_STR "0f0f45b0-13a1-44ae-a0ab-c6046ec6d4da"

#define NS_INAVHISTORYOBSERVER_IID \
  {0x0f0f45b0, 0x13a1, 0x44ae, \
    { 0xa0, 0xab, 0xc6, 0x04, 0x6e, 0xc6, 0xd4, 0xda }}

class NS_NO_VTABLE nsINavHistoryObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYOBSERVER_IID)

  /* void onBeginUpdateBatch (); */
  NS_IMETHOD OnBeginUpdateBatch(void) = 0;

  /* void onEndUpdateBatch (); */
  NS_IMETHOD OnEndUpdateBatch(void) = 0;

  /* void onVisit (in nsIURI aURI, in long long aVisitID, in PRTime aTime, in long long aSessionID, in long long aReferringID, in unsigned long aTransitionType, in ACString aGUID, in boolean aHidden); */
  NS_IMETHOD OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden) = 0;

  /* void onTitleChanged (in nsIURI aURI, in AString aPageTitle, in ACString aGUID); */
  NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID) = 0;

  /* void onFrecencyChanged (in nsIURI aURI, in long aNewFrecency, in ACString aGUID, in boolean aHidden, in PRTime aVisitDate); */
  NS_IMETHOD OnFrecencyChanged(nsIURI *aURI, int32_t aNewFrecency, const nsACString & aGUID, bool aHidden, PRTime aVisitDate) = 0;

  /* void onManyFrecenciesChanged (); */
  NS_IMETHOD OnManyFrecenciesChanged(void) = 0;

  enum {
    REASON_DELETED = 0U,
    REASON_EXPIRED = 1U
  };

  /* void onDeleteURI (in nsIURI aURI, in ACString aGUID, in unsigned short aReason); */
  NS_IMETHOD OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason) = 0;

  /* void onClearHistory (); */
  NS_IMETHOD OnClearHistory(void) = 0;

  enum {
    ATTRIBUTE_FAVICON = 3U
  };

  /* void onPageChanged (in nsIURI aURI, in unsigned long aChangedAttribute, in AString aNewValue, in ACString aGUID); */
  NS_IMETHOD OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID) = 0;

  /* void onDeleteVisits (in nsIURI aURI, in PRTime aVisitTime, in ACString aGUID, in unsigned short aReason, in unsigned long aTransitionType); */
  NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryObserver, NS_INAVHISTORYOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYOBSERVER \
  NS_IMETHOD OnBeginUpdateBatch(void) override; \
  NS_IMETHOD OnEndUpdateBatch(void) override; \
  NS_IMETHOD OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden) override; \
  NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID) override; \
  NS_IMETHOD OnFrecencyChanged(nsIURI *aURI, int32_t aNewFrecency, const nsACString & aGUID, bool aHidden, PRTime aVisitDate) override; \
  NS_IMETHOD OnManyFrecenciesChanged(void) override; \
  NS_IMETHOD OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason) override; \
  NS_IMETHOD OnClearHistory(void) override; \
  NS_IMETHOD OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID) override; \
  NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYOBSERVER(_to) \
  NS_IMETHOD OnBeginUpdateBatch(void) override { return _to OnBeginUpdateBatch(); } \
  NS_IMETHOD OnEndUpdateBatch(void) override { return _to OnEndUpdateBatch(); } \
  NS_IMETHOD OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden) override { return _to OnVisit(aURI, aVisitID, aTime, aSessionID, aReferringID, aTransitionType, aGUID, aHidden); } \
  NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID) override { return _to OnTitleChanged(aURI, aPageTitle, aGUID); } \
  NS_IMETHOD OnFrecencyChanged(nsIURI *aURI, int32_t aNewFrecency, const nsACString & aGUID, bool aHidden, PRTime aVisitDate) override { return _to OnFrecencyChanged(aURI, aNewFrecency, aGUID, aHidden, aVisitDate); } \
  NS_IMETHOD OnManyFrecenciesChanged(void) override { return _to OnManyFrecenciesChanged(); } \
  NS_IMETHOD OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason) override { return _to OnDeleteURI(aURI, aGUID, aReason); } \
  NS_IMETHOD OnClearHistory(void) override { return _to OnClearHistory(); } \
  NS_IMETHOD OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID) override { return _to OnPageChanged(aURI, aChangedAttribute, aNewValue, aGUID); } \
  NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) override { return _to OnDeleteVisits(aURI, aVisitTime, aGUID, aReason, aTransitionType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYOBSERVER(_to) \
  NS_IMETHOD OnBeginUpdateBatch(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeginUpdateBatch(); } \
  NS_IMETHOD OnEndUpdateBatch(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndUpdateBatch(); } \
  NS_IMETHOD OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnVisit(aURI, aVisitID, aTime, aSessionID, aReferringID, aTransitionType, aGUID, aHidden); } \
  NS_IMETHOD OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTitleChanged(aURI, aPageTitle, aGUID); } \
  NS_IMETHOD OnFrecencyChanged(nsIURI *aURI, int32_t aNewFrecency, const nsACString & aGUID, bool aHidden, PRTime aVisitDate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnFrecencyChanged(aURI, aNewFrecency, aGUID, aHidden, aVisitDate); } \
  NS_IMETHOD OnManyFrecenciesChanged(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnManyFrecenciesChanged(); } \
  NS_IMETHOD OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDeleteURI(aURI, aGUID, aReason); } \
  NS_IMETHOD OnClearHistory(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnClearHistory(); } \
  NS_IMETHOD OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPageChanged(aURI, aChangedAttribute, aNewValue, aGUID); } \
  NS_IMETHOD OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDeleteVisits(aURI, aVisitTime, aGUID, aReason, aTransitionType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryObserver : public nsINavHistoryObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYOBSERVER

  nsNavHistoryObserver();

private:
  ~nsNavHistoryObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryObserver, nsINavHistoryObserver)

nsNavHistoryObserver::nsNavHistoryObserver()
{
  /* member initializers and constructor code */
}

nsNavHistoryObserver::~nsNavHistoryObserver()
{
  /* destructor code */
}

/* void onBeginUpdateBatch (); */
NS_IMETHODIMP nsNavHistoryObserver::OnBeginUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEndUpdateBatch (); */
NS_IMETHODIMP nsNavHistoryObserver::OnEndUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onVisit (in nsIURI aURI, in long long aVisitID, in PRTime aTime, in long long aSessionID, in long long aReferringID, in unsigned long aTransitionType, in ACString aGUID, in boolean aHidden); */
NS_IMETHODIMP nsNavHistoryObserver::OnVisit(nsIURI *aURI, int64_t aVisitID, PRTime aTime, int64_t aSessionID, int64_t aReferringID, uint32_t aTransitionType, const nsACString & aGUID, bool aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onTitleChanged (in nsIURI aURI, in AString aPageTitle, in ACString aGUID); */
NS_IMETHODIMP nsNavHistoryObserver::OnTitleChanged(nsIURI *aURI, const nsAString & aPageTitle, const nsACString & aGUID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onFrecencyChanged (in nsIURI aURI, in long aNewFrecency, in ACString aGUID, in boolean aHidden, in PRTime aVisitDate); */
NS_IMETHODIMP nsNavHistoryObserver::OnFrecencyChanged(nsIURI *aURI, int32_t aNewFrecency, const nsACString & aGUID, bool aHidden, PRTime aVisitDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onManyFrecenciesChanged (); */
NS_IMETHODIMP nsNavHistoryObserver::OnManyFrecenciesChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDeleteURI (in nsIURI aURI, in ACString aGUID, in unsigned short aReason); */
NS_IMETHODIMP nsNavHistoryObserver::OnDeleteURI(nsIURI *aURI, const nsACString & aGUID, uint16_t aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onClearHistory (); */
NS_IMETHODIMP nsNavHistoryObserver::OnClearHistory()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPageChanged (in nsIURI aURI, in unsigned long aChangedAttribute, in AString aNewValue, in ACString aGUID); */
NS_IMETHODIMP nsNavHistoryObserver::OnPageChanged(nsIURI *aURI, uint32_t aChangedAttribute, const nsAString & aNewValue, const nsACString & aGUID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDeleteVisits (in nsIURI aURI, in PRTime aVisitTime, in ACString aGUID, in unsigned short aReason, in unsigned long aTransitionType); */
NS_IMETHODIMP nsNavHistoryObserver::OnDeleteVisits(nsIURI *aURI, PRTime aVisitTime, const nsACString & aGUID, uint16_t aReason, uint32_t aTransitionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryQuery */
#define NS_INAVHISTORYQUERY_IID_STR "dc87ae79-22f1-4dcf-975b-852b01d210cb"

#define NS_INAVHISTORYQUERY_IID \
  {0xdc87ae79, 0x22f1, 0x4dcf, \
    { 0x97, 0x5b, 0x85, 0x2b, 0x01, 0xd2, 0x10, 0xcb }}

class NS_NO_VTABLE nsINavHistoryQuery : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYQUERY_IID)

  enum {
    TIME_RELATIVE_EPOCH = 0U,
    TIME_RELATIVE_TODAY = 1U,
    TIME_RELATIVE_NOW = 2U
  };

  /* attribute PRTime beginTime; */
  NS_IMETHOD GetBeginTime(PRTime *aBeginTime) = 0;
  NS_IMETHOD SetBeginTime(PRTime aBeginTime) = 0;

  /* attribute unsigned long beginTimeReference; */
  NS_IMETHOD GetBeginTimeReference(uint32_t *aBeginTimeReference) = 0;
  NS_IMETHOD SetBeginTimeReference(uint32_t aBeginTimeReference) = 0;

  /* readonly attribute boolean hasBeginTime; */
  NS_IMETHOD GetHasBeginTime(bool *aHasBeginTime) = 0;

  /* readonly attribute PRTime absoluteBeginTime; */
  NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) = 0;

  /* attribute PRTime endTime; */
  NS_IMETHOD GetEndTime(PRTime *aEndTime) = 0;
  NS_IMETHOD SetEndTime(PRTime aEndTime) = 0;

  /* attribute unsigned long endTimeReference; */
  NS_IMETHOD GetEndTimeReference(uint32_t *aEndTimeReference) = 0;
  NS_IMETHOD SetEndTimeReference(uint32_t aEndTimeReference) = 0;

  /* readonly attribute boolean hasEndTime; */
  NS_IMETHOD GetHasEndTime(bool *aHasEndTime) = 0;

  /* readonly attribute PRTime absoluteEndTime; */
  NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) = 0;

  /* attribute AString searchTerms; */
  NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) = 0;
  NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) = 0;

  /* readonly attribute boolean hasSearchTerms; */
  NS_IMETHOD GetHasSearchTerms(bool *aHasSearchTerms) = 0;

  /* attribute long minVisits; */
  NS_IMETHOD GetMinVisits(int32_t *aMinVisits) = 0;
  NS_IMETHOD SetMinVisits(int32_t aMinVisits) = 0;

  /* attribute long maxVisits; */
  NS_IMETHOD GetMaxVisits(int32_t *aMaxVisits) = 0;
  NS_IMETHOD SetMaxVisits(int32_t aMaxVisits) = 0;

  /* void setTransitions ([array, size_is (count), const] in unsigned long transitions, in unsigned long count); */
  NS_IMETHOD SetTransitions(const uint32_t *transitions, uint32_t count) = 0;

  /* void getTransitions ([optional] out unsigned long count, [array, size_is (count), retval] out unsigned long transitions); */
  NS_IMETHOD GetTransitions(uint32_t *count, uint32_t **transitions) = 0;

  /* readonly attribute unsigned long transitionCount; */
  NS_IMETHOD GetTransitionCount(uint32_t *aTransitionCount) = 0;

  /* attribute boolean onlyBookmarked; */
  NS_IMETHOD GetOnlyBookmarked(bool *aOnlyBookmarked) = 0;
  NS_IMETHOD SetOnlyBookmarked(bool aOnlyBookmarked) = 0;

  /* attribute boolean domainIsHost; */
  NS_IMETHOD GetDomainIsHost(bool *aDomainIsHost) = 0;
  NS_IMETHOD SetDomainIsHost(bool aDomainIsHost) = 0;

  /* attribute AUTF8String domain; */
  NS_IMETHOD GetDomain(nsACString & aDomain) = 0;
  NS_IMETHOD SetDomain(const nsACString & aDomain) = 0;

  /* readonly attribute boolean hasDomain; */
  NS_IMETHOD GetHasDomain(bool *aHasDomain) = 0;

  /* attribute boolean uriIsPrefix; */
  NS_IMETHOD GetUriIsPrefix(bool *aUriIsPrefix) = 0;
  NS_IMETHOD SetUriIsPrefix(bool aUriIsPrefix) = 0;

  /* attribute nsIURI uri; */
  NS_IMETHOD GetUri(nsIURI * *aUri) = 0;
  NS_IMETHOD SetUri(nsIURI *aUri) = 0;

  /* readonly attribute boolean hasUri; */
  NS_IMETHOD GetHasUri(bool *aHasUri) = 0;

  /* attribute boolean annotationIsNot; */
  NS_IMETHOD GetAnnotationIsNot(bool *aAnnotationIsNot) = 0;
  NS_IMETHOD SetAnnotationIsNot(bool aAnnotationIsNot) = 0;

  /* attribute AUTF8String annotation; */
  NS_IMETHOD GetAnnotation(nsACString & aAnnotation) = 0;
  NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) = 0;

  /* readonly attribute boolean hasAnnotation; */
  NS_IMETHOD GetHasAnnotation(bool *aHasAnnotation) = 0;

  /* attribute nsIVariant tags; */
  NS_IMETHOD GetTags(nsIVariant * *aTags) = 0;
  NS_IMETHOD SetTags(nsIVariant *aTags) = 0;

  /* attribute boolean tagsAreNot; */
  NS_IMETHOD GetTagsAreNot(bool *aTagsAreNot) = 0;
  NS_IMETHOD SetTagsAreNot(bool aTagsAreNot) = 0;

  /* void getFolders ([optional] out unsigned long count, [array, size_is (count), retval] out long long folders); */
  NS_IMETHOD GetFolders(uint32_t *count, int64_t **folders) = 0;

  /* readonly attribute unsigned long folderCount; */
  NS_IMETHOD GetFolderCount(uint32_t *aFolderCount) = 0;

  /* void setFolders ([array, size_is (folderCount), const] in long long folders, in unsigned long folderCount); */
  NS_IMETHOD SetFolders(const int64_t *folders, uint32_t folderCount) = 0;

  /* nsINavHistoryQuery clone (); */
  NS_IMETHOD Clone(nsINavHistoryQuery * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryQuery, NS_INAVHISTORYQUERY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYQUERY \
  NS_IMETHOD GetBeginTime(PRTime *aBeginTime) override; \
  NS_IMETHOD SetBeginTime(PRTime aBeginTime) override; \
  NS_IMETHOD GetBeginTimeReference(uint32_t *aBeginTimeReference) override; \
  NS_IMETHOD SetBeginTimeReference(uint32_t aBeginTimeReference) override; \
  NS_IMETHOD GetHasBeginTime(bool *aHasBeginTime) override; \
  NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) override; \
  NS_IMETHOD GetEndTime(PRTime *aEndTime) override; \
  NS_IMETHOD SetEndTime(PRTime aEndTime) override; \
  NS_IMETHOD GetEndTimeReference(uint32_t *aEndTimeReference) override; \
  NS_IMETHOD SetEndTimeReference(uint32_t aEndTimeReference) override; \
  NS_IMETHOD GetHasEndTime(bool *aHasEndTime) override; \
  NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) override; \
  NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) override; \
  NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) override; \
  NS_IMETHOD GetHasSearchTerms(bool *aHasSearchTerms) override; \
  NS_IMETHOD GetMinVisits(int32_t *aMinVisits) override; \
  NS_IMETHOD SetMinVisits(int32_t aMinVisits) override; \
  NS_IMETHOD GetMaxVisits(int32_t *aMaxVisits) override; \
  NS_IMETHOD SetMaxVisits(int32_t aMaxVisits) override; \
  NS_IMETHOD SetTransitions(const uint32_t *transitions, uint32_t count) override; \
  NS_IMETHOD GetTransitions(uint32_t *count, uint32_t **transitions) override; \
  NS_IMETHOD GetTransitionCount(uint32_t *aTransitionCount) override; \
  NS_IMETHOD GetOnlyBookmarked(bool *aOnlyBookmarked) override; \
  NS_IMETHOD SetOnlyBookmarked(bool aOnlyBookmarked) override; \
  NS_IMETHOD GetDomainIsHost(bool *aDomainIsHost) override; \
  NS_IMETHOD SetDomainIsHost(bool aDomainIsHost) override; \
  NS_IMETHOD GetDomain(nsACString & aDomain) override; \
  NS_IMETHOD SetDomain(const nsACString & aDomain) override; \
  NS_IMETHOD GetHasDomain(bool *aHasDomain) override; \
  NS_IMETHOD GetUriIsPrefix(bool *aUriIsPrefix) override; \
  NS_IMETHOD SetUriIsPrefix(bool aUriIsPrefix) override; \
  NS_IMETHOD GetUri(nsIURI * *aUri) override; \
  NS_IMETHOD SetUri(nsIURI *aUri) override; \
  NS_IMETHOD GetHasUri(bool *aHasUri) override; \
  NS_IMETHOD GetAnnotationIsNot(bool *aAnnotationIsNot) override; \
  NS_IMETHOD SetAnnotationIsNot(bool aAnnotationIsNot) override; \
  NS_IMETHOD GetAnnotation(nsACString & aAnnotation) override; \
  NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) override; \
  NS_IMETHOD GetHasAnnotation(bool *aHasAnnotation) override; \
  NS_IMETHOD GetTags(nsIVariant * *aTags) override; \
  NS_IMETHOD SetTags(nsIVariant *aTags) override; \
  NS_IMETHOD GetTagsAreNot(bool *aTagsAreNot) override; \
  NS_IMETHOD SetTagsAreNot(bool aTagsAreNot) override; \
  NS_IMETHOD GetFolders(uint32_t *count, int64_t **folders) override; \
  NS_IMETHOD GetFolderCount(uint32_t *aFolderCount) override; \
  NS_IMETHOD SetFolders(const int64_t *folders, uint32_t folderCount) override; \
  NS_IMETHOD Clone(nsINavHistoryQuery * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYQUERY(_to) \
  NS_IMETHOD GetBeginTime(PRTime *aBeginTime) override { return _to GetBeginTime(aBeginTime); } \
  NS_IMETHOD SetBeginTime(PRTime aBeginTime) override { return _to SetBeginTime(aBeginTime); } \
  NS_IMETHOD GetBeginTimeReference(uint32_t *aBeginTimeReference) override { return _to GetBeginTimeReference(aBeginTimeReference); } \
  NS_IMETHOD SetBeginTimeReference(uint32_t aBeginTimeReference) override { return _to SetBeginTimeReference(aBeginTimeReference); } \
  NS_IMETHOD GetHasBeginTime(bool *aHasBeginTime) override { return _to GetHasBeginTime(aHasBeginTime); } \
  NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) override { return _to GetAbsoluteBeginTime(aAbsoluteBeginTime); } \
  NS_IMETHOD GetEndTime(PRTime *aEndTime) override { return _to GetEndTime(aEndTime); } \
  NS_IMETHOD SetEndTime(PRTime aEndTime) override { return _to SetEndTime(aEndTime); } \
  NS_IMETHOD GetEndTimeReference(uint32_t *aEndTimeReference) override { return _to GetEndTimeReference(aEndTimeReference); } \
  NS_IMETHOD SetEndTimeReference(uint32_t aEndTimeReference) override { return _to SetEndTimeReference(aEndTimeReference); } \
  NS_IMETHOD GetHasEndTime(bool *aHasEndTime) override { return _to GetHasEndTime(aHasEndTime); } \
  NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) override { return _to GetAbsoluteEndTime(aAbsoluteEndTime); } \
  NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) override { return _to GetSearchTerms(aSearchTerms); } \
  NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) override { return _to SetSearchTerms(aSearchTerms); } \
  NS_IMETHOD GetHasSearchTerms(bool *aHasSearchTerms) override { return _to GetHasSearchTerms(aHasSearchTerms); } \
  NS_IMETHOD GetMinVisits(int32_t *aMinVisits) override { return _to GetMinVisits(aMinVisits); } \
  NS_IMETHOD SetMinVisits(int32_t aMinVisits) override { return _to SetMinVisits(aMinVisits); } \
  NS_IMETHOD GetMaxVisits(int32_t *aMaxVisits) override { return _to GetMaxVisits(aMaxVisits); } \
  NS_IMETHOD SetMaxVisits(int32_t aMaxVisits) override { return _to SetMaxVisits(aMaxVisits); } \
  NS_IMETHOD SetTransitions(const uint32_t *transitions, uint32_t count) override { return _to SetTransitions(transitions, count); } \
  NS_IMETHOD GetTransitions(uint32_t *count, uint32_t **transitions) override { return _to GetTransitions(count, transitions); } \
  NS_IMETHOD GetTransitionCount(uint32_t *aTransitionCount) override { return _to GetTransitionCount(aTransitionCount); } \
  NS_IMETHOD GetOnlyBookmarked(bool *aOnlyBookmarked) override { return _to GetOnlyBookmarked(aOnlyBookmarked); } \
  NS_IMETHOD SetOnlyBookmarked(bool aOnlyBookmarked) override { return _to SetOnlyBookmarked(aOnlyBookmarked); } \
  NS_IMETHOD GetDomainIsHost(bool *aDomainIsHost) override { return _to GetDomainIsHost(aDomainIsHost); } \
  NS_IMETHOD SetDomainIsHost(bool aDomainIsHost) override { return _to SetDomainIsHost(aDomainIsHost); } \
  NS_IMETHOD GetDomain(nsACString & aDomain) override { return _to GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsACString & aDomain) override { return _to SetDomain(aDomain); } \
  NS_IMETHOD GetHasDomain(bool *aHasDomain) override { return _to GetHasDomain(aHasDomain); } \
  NS_IMETHOD GetUriIsPrefix(bool *aUriIsPrefix) override { return _to GetUriIsPrefix(aUriIsPrefix); } \
  NS_IMETHOD SetUriIsPrefix(bool aUriIsPrefix) override { return _to SetUriIsPrefix(aUriIsPrefix); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) override { return _to GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) override { return _to SetUri(aUri); } \
  NS_IMETHOD GetHasUri(bool *aHasUri) override { return _to GetHasUri(aHasUri); } \
  NS_IMETHOD GetAnnotationIsNot(bool *aAnnotationIsNot) override { return _to GetAnnotationIsNot(aAnnotationIsNot); } \
  NS_IMETHOD SetAnnotationIsNot(bool aAnnotationIsNot) override { return _to SetAnnotationIsNot(aAnnotationIsNot); } \
  NS_IMETHOD GetAnnotation(nsACString & aAnnotation) override { return _to GetAnnotation(aAnnotation); } \
  NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) override { return _to SetAnnotation(aAnnotation); } \
  NS_IMETHOD GetHasAnnotation(bool *aHasAnnotation) override { return _to GetHasAnnotation(aHasAnnotation); } \
  NS_IMETHOD GetTags(nsIVariant * *aTags) override { return _to GetTags(aTags); } \
  NS_IMETHOD SetTags(nsIVariant *aTags) override { return _to SetTags(aTags); } \
  NS_IMETHOD GetTagsAreNot(bool *aTagsAreNot) override { return _to GetTagsAreNot(aTagsAreNot); } \
  NS_IMETHOD SetTagsAreNot(bool aTagsAreNot) override { return _to SetTagsAreNot(aTagsAreNot); } \
  NS_IMETHOD GetFolders(uint32_t *count, int64_t **folders) override { return _to GetFolders(count, folders); } \
  NS_IMETHOD GetFolderCount(uint32_t *aFolderCount) override { return _to GetFolderCount(aFolderCount); } \
  NS_IMETHOD SetFolders(const int64_t *folders, uint32_t folderCount) override { return _to SetFolders(folders, folderCount); } \
  NS_IMETHOD Clone(nsINavHistoryQuery * *_retval) override { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYQUERY(_to) \
  NS_IMETHOD GetBeginTime(PRTime *aBeginTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeginTime(aBeginTime); } \
  NS_IMETHOD SetBeginTime(PRTime aBeginTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBeginTime(aBeginTime); } \
  NS_IMETHOD GetBeginTimeReference(uint32_t *aBeginTimeReference) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeginTimeReference(aBeginTimeReference); } \
  NS_IMETHOD SetBeginTimeReference(uint32_t aBeginTimeReference) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBeginTimeReference(aBeginTimeReference); } \
  NS_IMETHOD GetHasBeginTime(bool *aHasBeginTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasBeginTime(aHasBeginTime); } \
  NS_IMETHOD GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsoluteBeginTime(aAbsoluteBeginTime); } \
  NS_IMETHOD GetEndTime(PRTime *aEndTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndTime(aEndTime); } \
  NS_IMETHOD SetEndTime(PRTime aEndTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndTime(aEndTime); } \
  NS_IMETHOD GetEndTimeReference(uint32_t *aEndTimeReference) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndTimeReference(aEndTimeReference); } \
  NS_IMETHOD SetEndTimeReference(uint32_t aEndTimeReference) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndTimeReference(aEndTimeReference); } \
  NS_IMETHOD GetHasEndTime(bool *aHasEndTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasEndTime(aHasEndTime); } \
  NS_IMETHOD GetAbsoluteEndTime(PRTime *aAbsoluteEndTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAbsoluteEndTime(aAbsoluteEndTime); } \
  NS_IMETHOD GetSearchTerms(nsAString & aSearchTerms) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchTerms(aSearchTerms); } \
  NS_IMETHOD SetSearchTerms(const nsAString & aSearchTerms) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchTerms(aSearchTerms); } \
  NS_IMETHOD GetHasSearchTerms(bool *aHasSearchTerms) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasSearchTerms(aHasSearchTerms); } \
  NS_IMETHOD GetMinVisits(int32_t *aMinVisits) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinVisits(aMinVisits); } \
  NS_IMETHOD SetMinVisits(int32_t aMinVisits) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinVisits(aMinVisits); } \
  NS_IMETHOD GetMaxVisits(int32_t *aMaxVisits) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxVisits(aMaxVisits); } \
  NS_IMETHOD SetMaxVisits(int32_t aMaxVisits) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxVisits(aMaxVisits); } \
  NS_IMETHOD SetTransitions(const uint32_t *transitions, uint32_t count) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTransitions(transitions, count); } \
  NS_IMETHOD GetTransitions(uint32_t *count, uint32_t **transitions) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransitions(count, transitions); } \
  NS_IMETHOD GetTransitionCount(uint32_t *aTransitionCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransitionCount(aTransitionCount); } \
  NS_IMETHOD GetOnlyBookmarked(bool *aOnlyBookmarked) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnlyBookmarked(aOnlyBookmarked); } \
  NS_IMETHOD SetOnlyBookmarked(bool aOnlyBookmarked) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnlyBookmarked(aOnlyBookmarked); } \
  NS_IMETHOD GetDomainIsHost(bool *aDomainIsHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainIsHost(aDomainIsHost); } \
  NS_IMETHOD SetDomainIsHost(bool aDomainIsHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomainIsHost(aDomainIsHost); } \
  NS_IMETHOD GetDomain(nsACString & aDomain) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsACString & aDomain) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } \
  NS_IMETHOD GetHasDomain(bool *aHasDomain) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasDomain(aHasDomain); } \
  NS_IMETHOD GetUriIsPrefix(bool *aUriIsPrefix) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUriIsPrefix(aUriIsPrefix); } \
  NS_IMETHOD SetUriIsPrefix(bool aUriIsPrefix) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUriIsPrefix(aUriIsPrefix); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD SetUri(nsIURI *aUri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUri(aUri); } \
  NS_IMETHOD GetHasUri(bool *aHasUri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasUri(aHasUri); } \
  NS_IMETHOD GetAnnotationIsNot(bool *aAnnotationIsNot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotationIsNot(aAnnotationIsNot); } \
  NS_IMETHOD SetAnnotationIsNot(bool aAnnotationIsNot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAnnotationIsNot(aAnnotationIsNot); } \
  NS_IMETHOD GetAnnotation(nsACString & aAnnotation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotation(aAnnotation); } \
  NS_IMETHOD SetAnnotation(const nsACString & aAnnotation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAnnotation(aAnnotation); } \
  NS_IMETHOD GetHasAnnotation(bool *aHasAnnotation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasAnnotation(aHasAnnotation); } \
  NS_IMETHOD GetTags(nsIVariant * *aTags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTags(aTags); } \
  NS_IMETHOD SetTags(nsIVariant *aTags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTags(aTags); } \
  NS_IMETHOD GetTagsAreNot(bool *aTagsAreNot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagsAreNot(aTagsAreNot); } \
  NS_IMETHOD SetTagsAreNot(bool aTagsAreNot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTagsAreNot(aTagsAreNot); } \
  NS_IMETHOD GetFolders(uint32_t *count, int64_t **folders) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolders(count, folders); } \
  NS_IMETHOD GetFolderCount(uint32_t *aFolderCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFolderCount(aFolderCount); } \
  NS_IMETHOD SetFolders(const int64_t *folders, uint32_t folderCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFolders(folders, folderCount); } \
  NS_IMETHOD Clone(nsINavHistoryQuery * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryQuery : public nsINavHistoryQuery
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYQUERY

  nsNavHistoryQuery();

private:
  ~nsNavHistoryQuery();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryQuery, nsINavHistoryQuery)

nsNavHistoryQuery::nsNavHistoryQuery()
{
  /* member initializers and constructor code */
}

nsNavHistoryQuery::~nsNavHistoryQuery()
{
  /* destructor code */
}

/* attribute PRTime beginTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetBeginTime(PRTime *aBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetBeginTime(PRTime aBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long beginTimeReference; */
NS_IMETHODIMP nsNavHistoryQuery::GetBeginTimeReference(uint32_t *aBeginTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetBeginTimeReference(uint32_t aBeginTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasBeginTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasBeginTime(bool *aHasBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime absoluteBeginTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetAbsoluteBeginTime(PRTime *aAbsoluteBeginTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute PRTime endTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetEndTime(PRTime *aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetEndTime(PRTime aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long endTimeReference; */
NS_IMETHODIMP nsNavHistoryQuery::GetEndTimeReference(uint32_t *aEndTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetEndTimeReference(uint32_t aEndTimeReference)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasEndTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasEndTime(bool *aHasEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime absoluteEndTime; */
NS_IMETHODIMP nsNavHistoryQuery::GetAbsoluteEndTime(PRTime *aAbsoluteEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString searchTerms; */
NS_IMETHODIMP nsNavHistoryQuery::GetSearchTerms(nsAString & aSearchTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetSearchTerms(const nsAString & aSearchTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasSearchTerms; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasSearchTerms(bool *aHasSearchTerms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long minVisits; */
NS_IMETHODIMP nsNavHistoryQuery::GetMinVisits(int32_t *aMinVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetMinVisits(int32_t aMinVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long maxVisits; */
NS_IMETHODIMP nsNavHistoryQuery::GetMaxVisits(int32_t *aMaxVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetMaxVisits(int32_t aMaxVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTransitions ([array, size_is (count), const] in unsigned long transitions, in unsigned long count); */
NS_IMETHODIMP nsNavHistoryQuery::SetTransitions(const uint32_t *transitions, uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTransitions ([optional] out unsigned long count, [array, size_is (count), retval] out unsigned long transitions); */
NS_IMETHODIMP nsNavHistoryQuery::GetTransitions(uint32_t *count, uint32_t **transitions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long transitionCount; */
NS_IMETHODIMP nsNavHistoryQuery::GetTransitionCount(uint32_t *aTransitionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean onlyBookmarked; */
NS_IMETHODIMP nsNavHistoryQuery::GetOnlyBookmarked(bool *aOnlyBookmarked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetOnlyBookmarked(bool aOnlyBookmarked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean domainIsHost; */
NS_IMETHODIMP nsNavHistoryQuery::GetDomainIsHost(bool *aDomainIsHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetDomainIsHost(bool aDomainIsHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String domain; */
NS_IMETHODIMP nsNavHistoryQuery::GetDomain(nsACString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetDomain(const nsACString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasDomain; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasDomain(bool *aHasDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean uriIsPrefix; */
NS_IMETHODIMP nsNavHistoryQuery::GetUriIsPrefix(bool *aUriIsPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetUriIsPrefix(bool aUriIsPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI uri; */
NS_IMETHODIMP nsNavHistoryQuery::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetUri(nsIURI *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasUri; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasUri(bool *aHasUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean annotationIsNot; */
NS_IMETHODIMP nsNavHistoryQuery::GetAnnotationIsNot(bool *aAnnotationIsNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetAnnotationIsNot(bool aAnnotationIsNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String annotation; */
NS_IMETHODIMP nsNavHistoryQuery::GetAnnotation(nsACString & aAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetAnnotation(const nsACString & aAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasAnnotation; */
NS_IMETHODIMP nsNavHistoryQuery::GetHasAnnotation(bool *aHasAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant tags; */
NS_IMETHODIMP nsNavHistoryQuery::GetTags(nsIVariant * *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetTags(nsIVariant *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean tagsAreNot; */
NS_IMETHODIMP nsNavHistoryQuery::GetTagsAreNot(bool *aTagsAreNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQuery::SetTagsAreNot(bool aTagsAreNot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getFolders ([optional] out unsigned long count, [array, size_is (count), retval] out long long folders); */
NS_IMETHODIMP nsNavHistoryQuery::GetFolders(uint32_t *count, int64_t **folders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long folderCount; */
NS_IMETHODIMP nsNavHistoryQuery::GetFolderCount(uint32_t *aFolderCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFolders ([array, size_is (folderCount), const] in long long folders, in unsigned long folderCount); */
NS_IMETHODIMP nsNavHistoryQuery::SetFolders(const int64_t *folders, uint32_t folderCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQuery clone (); */
NS_IMETHODIMP nsNavHistoryQuery::Clone(nsINavHistoryQuery * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryQueryOptions */
#define NS_INAVHISTORYQUERYOPTIONS_IID_STR "8198dfa7-8061-4766-95cb-fa86b3c00a47"

#define NS_INAVHISTORYQUERYOPTIONS_IID \
  {0x8198dfa7, 0x8061, 0x4766, \
    { 0x95, 0xcb, 0xfa, 0x86, 0xb3, 0xc0, 0x0a, 0x47 }}

class NS_NO_VTABLE nsINavHistoryQueryOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYQUERYOPTIONS_IID)

  enum {
    SORT_BY_NONE = 0U,
    SORT_BY_TITLE_ASCENDING = 1U,
    SORT_BY_TITLE_DESCENDING = 2U,
    SORT_BY_DATE_ASCENDING = 3U,
    SORT_BY_DATE_DESCENDING = 4U,
    SORT_BY_URI_ASCENDING = 5U,
    SORT_BY_URI_DESCENDING = 6U,
    SORT_BY_VISITCOUNT_ASCENDING = 7U,
    SORT_BY_VISITCOUNT_DESCENDING = 8U,
    SORT_BY_KEYWORD_ASCENDING = 9U,
    SORT_BY_KEYWORD_DESCENDING = 10U,
    SORT_BY_DATEADDED_ASCENDING = 11U,
    SORT_BY_DATEADDED_DESCENDING = 12U,
    SORT_BY_LASTMODIFIED_ASCENDING = 13U,
    SORT_BY_LASTMODIFIED_DESCENDING = 14U,
    SORT_BY_TAGS_ASCENDING = 17U,
    SORT_BY_TAGS_DESCENDING = 18U,
    SORT_BY_ANNOTATION_ASCENDING = 19U,
    SORT_BY_ANNOTATION_DESCENDING = 20U,
    SORT_BY_FRECENCY_ASCENDING = 21U,
    SORT_BY_FRECENCY_DESCENDING = 22U,
    RESULTS_AS_URI = 0U,
    RESULTS_AS_VISIT = 1U,
    RESULTS_AS_FULL_VISIT = 2U,
    RESULTS_AS_DATE_QUERY = 3U,
    RESULTS_AS_SITE_QUERY = 4U,
    RESULTS_AS_DATE_SITE_QUERY = 5U,
    RESULTS_AS_TAG_QUERY = 6U,
    RESULTS_AS_TAG_CONTENTS = 7U
  };

  /* attribute unsigned short sortingMode; */
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) = 0;
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) = 0;

  /* attribute AUTF8String sortingAnnotation; */
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) = 0;
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) = 0;

  /* attribute unsigned short resultType; */
  NS_IMETHOD GetResultType(uint16_t *aResultType) = 0;
  NS_IMETHOD SetResultType(uint16_t aResultType) = 0;

  /* attribute boolean excludeItems; */
  NS_IMETHOD GetExcludeItems(bool *aExcludeItems) = 0;
  NS_IMETHOD SetExcludeItems(bool aExcludeItems) = 0;

  /* attribute boolean excludeQueries; */
  NS_IMETHOD GetExcludeQueries(bool *aExcludeQueries) = 0;
  NS_IMETHOD SetExcludeQueries(bool aExcludeQueries) = 0;

  /* attribute boolean excludeReadOnlyFolders; */
  NS_IMETHOD GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders) = 0;
  NS_IMETHOD SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders) = 0;

  /* attribute boolean expandQueries; */
  NS_IMETHOD GetExpandQueries(bool *aExpandQueries) = 0;
  NS_IMETHOD SetExpandQueries(bool aExpandQueries) = 0;

  /* attribute boolean includeHidden; */
  NS_IMETHOD GetIncludeHidden(bool *aIncludeHidden) = 0;
  NS_IMETHOD SetIncludeHidden(bool aIncludeHidden) = 0;

  /* attribute unsigned long maxResults; */
  NS_IMETHOD GetMaxResults(uint32_t *aMaxResults) = 0;
  NS_IMETHOD SetMaxResults(uint32_t aMaxResults) = 0;

  enum {
    QUERY_TYPE_HISTORY = 0U,
    QUERY_TYPE_BOOKMARKS = 1U,
    QUERY_TYPE_UNIFIED = 2U
  };

  /* attribute unsigned short queryType; */
  NS_IMETHOD GetQueryType(uint16_t *aQueryType) = 0;
  NS_IMETHOD SetQueryType(uint16_t aQueryType) = 0;

  /* attribute boolean asyncEnabled; */
  NS_IMETHOD GetAsyncEnabled(bool *aAsyncEnabled) = 0;
  NS_IMETHOD SetAsyncEnabled(bool aAsyncEnabled) = 0;

  /* nsINavHistoryQueryOptions clone (); */
  NS_IMETHOD Clone(nsINavHistoryQueryOptions * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryQueryOptions, NS_INAVHISTORYQUERYOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYQUERYOPTIONS \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) override; \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) override; \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) override; \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) override; \
  NS_IMETHOD GetResultType(uint16_t *aResultType) override; \
  NS_IMETHOD SetResultType(uint16_t aResultType) override; \
  NS_IMETHOD GetExcludeItems(bool *aExcludeItems) override; \
  NS_IMETHOD SetExcludeItems(bool aExcludeItems) override; \
  NS_IMETHOD GetExcludeQueries(bool *aExcludeQueries) override; \
  NS_IMETHOD SetExcludeQueries(bool aExcludeQueries) override; \
  NS_IMETHOD GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders) override; \
  NS_IMETHOD SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders) override; \
  NS_IMETHOD GetExpandQueries(bool *aExpandQueries) override; \
  NS_IMETHOD SetExpandQueries(bool aExpandQueries) override; \
  NS_IMETHOD GetIncludeHidden(bool *aIncludeHidden) override; \
  NS_IMETHOD SetIncludeHidden(bool aIncludeHidden) override; \
  NS_IMETHOD GetMaxResults(uint32_t *aMaxResults) override; \
  NS_IMETHOD SetMaxResults(uint32_t aMaxResults) override; \
  NS_IMETHOD GetQueryType(uint16_t *aQueryType) override; \
  NS_IMETHOD SetQueryType(uint16_t aQueryType) override; \
  NS_IMETHOD GetAsyncEnabled(bool *aAsyncEnabled) override; \
  NS_IMETHOD SetAsyncEnabled(bool aAsyncEnabled) override; \
  NS_IMETHOD Clone(nsINavHistoryQueryOptions * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYQUERYOPTIONS(_to) \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) override { return _to GetSortingMode(aSortingMode); } \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) override { return _to SetSortingMode(aSortingMode); } \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) override { return _to GetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) override { return _to SetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD GetResultType(uint16_t *aResultType) override { return _to GetResultType(aResultType); } \
  NS_IMETHOD SetResultType(uint16_t aResultType) override { return _to SetResultType(aResultType); } \
  NS_IMETHOD GetExcludeItems(bool *aExcludeItems) override { return _to GetExcludeItems(aExcludeItems); } \
  NS_IMETHOD SetExcludeItems(bool aExcludeItems) override { return _to SetExcludeItems(aExcludeItems); } \
  NS_IMETHOD GetExcludeQueries(bool *aExcludeQueries) override { return _to GetExcludeQueries(aExcludeQueries); } \
  NS_IMETHOD SetExcludeQueries(bool aExcludeQueries) override { return _to SetExcludeQueries(aExcludeQueries); } \
  NS_IMETHOD GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders) override { return _to GetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_IMETHOD SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders) override { return _to SetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_IMETHOD GetExpandQueries(bool *aExpandQueries) override { return _to GetExpandQueries(aExpandQueries); } \
  NS_IMETHOD SetExpandQueries(bool aExpandQueries) override { return _to SetExpandQueries(aExpandQueries); } \
  NS_IMETHOD GetIncludeHidden(bool *aIncludeHidden) override { return _to GetIncludeHidden(aIncludeHidden); } \
  NS_IMETHOD SetIncludeHidden(bool aIncludeHidden) override { return _to SetIncludeHidden(aIncludeHidden); } \
  NS_IMETHOD GetMaxResults(uint32_t *aMaxResults) override { return _to GetMaxResults(aMaxResults); } \
  NS_IMETHOD SetMaxResults(uint32_t aMaxResults) override { return _to SetMaxResults(aMaxResults); } \
  NS_IMETHOD GetQueryType(uint16_t *aQueryType) override { return _to GetQueryType(aQueryType); } \
  NS_IMETHOD SetQueryType(uint16_t aQueryType) override { return _to SetQueryType(aQueryType); } \
  NS_IMETHOD GetAsyncEnabled(bool *aAsyncEnabled) override { return _to GetAsyncEnabled(aAsyncEnabled); } \
  NS_IMETHOD SetAsyncEnabled(bool aAsyncEnabled) override { return _to SetAsyncEnabled(aAsyncEnabled); } \
  NS_IMETHOD Clone(nsINavHistoryQueryOptions * *_retval) override { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYQUERYOPTIONS(_to) \
  NS_IMETHOD GetSortingMode(uint16_t *aSortingMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingMode(aSortingMode); } \
  NS_IMETHOD SetSortingMode(uint16_t aSortingMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingMode(aSortingMode); } \
  NS_IMETHOD GetSortingAnnotation(nsACString & aSortingAnnotation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD SetSortingAnnotation(const nsACString & aSortingAnnotation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortingAnnotation(aSortingAnnotation); } \
  NS_IMETHOD GetResultType(uint16_t *aResultType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultType(aResultType); } \
  NS_IMETHOD SetResultType(uint16_t aResultType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResultType(aResultType); } \
  NS_IMETHOD GetExcludeItems(bool *aExcludeItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeItems(aExcludeItems); } \
  NS_IMETHOD SetExcludeItems(bool aExcludeItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeItems(aExcludeItems); } \
  NS_IMETHOD GetExcludeQueries(bool *aExcludeQueries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeQueries(aExcludeQueries); } \
  NS_IMETHOD SetExcludeQueries(bool aExcludeQueries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeQueries(aExcludeQueries); } \
  NS_IMETHOD GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_IMETHOD SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExcludeReadOnlyFolders(aExcludeReadOnlyFolders); } \
  NS_IMETHOD GetExpandQueries(bool *aExpandQueries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpandQueries(aExpandQueries); } \
  NS_IMETHOD SetExpandQueries(bool aExpandQueries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetExpandQueries(aExpandQueries); } \
  NS_IMETHOD GetIncludeHidden(bool *aIncludeHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIncludeHidden(aIncludeHidden); } \
  NS_IMETHOD SetIncludeHidden(bool aIncludeHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIncludeHidden(aIncludeHidden); } \
  NS_IMETHOD GetMaxResults(uint32_t *aMaxResults) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxResults(aMaxResults); } \
  NS_IMETHOD SetMaxResults(uint32_t aMaxResults) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxResults(aMaxResults); } \
  NS_IMETHOD GetQueryType(uint16_t *aQueryType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueryType(aQueryType); } \
  NS_IMETHOD SetQueryType(uint16_t aQueryType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetQueryType(aQueryType); } \
  NS_IMETHOD GetAsyncEnabled(bool *aAsyncEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncEnabled(aAsyncEnabled); } \
  NS_IMETHOD SetAsyncEnabled(bool aAsyncEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsyncEnabled(aAsyncEnabled); } \
  NS_IMETHOD Clone(nsINavHistoryQueryOptions * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryQueryOptions : public nsINavHistoryQueryOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYQUERYOPTIONS

  nsNavHistoryQueryOptions();

private:
  ~nsNavHistoryQueryOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryQueryOptions, nsINavHistoryQueryOptions)

nsNavHistoryQueryOptions::nsNavHistoryQueryOptions()
{
  /* member initializers and constructor code */
}

nsNavHistoryQueryOptions::~nsNavHistoryQueryOptions()
{
  /* destructor code */
}

/* attribute unsigned short sortingMode; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetSortingMode(uint16_t *aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetSortingMode(uint16_t aSortingMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String sortingAnnotation; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetSortingAnnotation(nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetSortingAnnotation(const nsACString & aSortingAnnotation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short resultType; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetResultType(uint16_t *aResultType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetResultType(uint16_t aResultType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean excludeItems; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeItems(bool *aExcludeItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeItems(bool aExcludeItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean excludeQueries; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeQueries(bool *aExcludeQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeQueries(bool aExcludeQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean excludeReadOnlyFolders; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExcludeReadOnlyFolders(bool *aExcludeReadOnlyFolders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExcludeReadOnlyFolders(bool aExcludeReadOnlyFolders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean expandQueries; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetExpandQueries(bool *aExpandQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetExpandQueries(bool aExpandQueries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean includeHidden; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetIncludeHidden(bool *aIncludeHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetIncludeHidden(bool aIncludeHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long maxResults; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetMaxResults(uint32_t *aMaxResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetMaxResults(uint32_t aMaxResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short queryType; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetQueryType(uint16_t *aQueryType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetQueryType(uint16_t aQueryType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean asyncEnabled; */
NS_IMETHODIMP nsNavHistoryQueryOptions::GetAsyncEnabled(bool *aAsyncEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsNavHistoryQueryOptions::SetAsyncEnabled(bool aAsyncEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQueryOptions clone (); */
NS_IMETHODIMP nsNavHistoryQueryOptions::Clone(nsINavHistoryQueryOptions * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryService */
#define NS_INAVHISTORYSERVICE_IID_STR "8a1f527e-c9d7-4a51-bf0c-d86f0379b701"

#define NS_INAVHISTORYSERVICE_IID \
  {0x8a1f527e, 0xc9d7, 0x4a51, \
    { 0xbf, 0x0c, 0xd8, 0x6f, 0x03, 0x79, 0xb7, 0x01 }}

class NS_NO_VTABLE nsINavHistoryService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYSERVICE_IID)

  enum {
    TRANSITION_LINK = 1U,
    TRANSITION_TYPED = 2U,
    TRANSITION_BOOKMARK = 3U,
    TRANSITION_EMBED = 4U,
    TRANSITION_REDIRECT_PERMANENT = 5U,
    TRANSITION_REDIRECT_TEMPORARY = 6U,
    TRANSITION_DOWNLOAD = 7U,
    TRANSITION_FRAMED_LINK = 8U,
    DATABASE_STATUS_OK = 0U,
    DATABASE_STATUS_CREATE = 1U,
    DATABASE_STATUS_CORRUPT = 2U,
    DATABASE_STATUS_UPGRADED = 3U
  };

  /* readonly attribute unsigned short databaseStatus; */
  NS_IMETHOD GetDatabaseStatus(uint16_t *aDatabaseStatus) = 0;

  /* readonly attribute boolean hasHistoryEntries; */
  NS_IMETHOD GetHasHistoryEntries(bool *aHasHistoryEntries) = 0;

  /* AString getPageTitle (in nsIURI aURI); */
  NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval) = 0;

  /* void markPageAsFollowedBookmark (in nsIURI aURI); */
  NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) = 0;

  /* void markPageAsTyped (in nsIURI aURI); */
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) = 0;

  /* void markPageAsFollowedLink (in nsIURI aURI); */
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) = 0;

  /* boolean canAddURI (in nsIURI aURI); */
  NS_IMETHOD CanAddURI(nsIURI *aURI, bool *_retval) = 0;

  /* nsINavHistoryQuery getNewQuery (); */
  NS_IMETHOD GetNewQuery(nsINavHistoryQuery * *_retval) = 0;

  /* nsINavHistoryQueryOptions getNewQueryOptions (); */
  NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval) = 0;

  /* nsINavHistoryResult executeQuery (in nsINavHistoryQuery aQuery, in nsINavHistoryQueryOptions options); */
  NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) = 0;

  /* nsINavHistoryResult executeQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
  NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) = 0;

  /* void queryStringToQueries (in AUTF8String aQueryString, [array, size_is (aResultCount)] out nsINavHistoryQuery aQueries, out unsigned long aResultCount, out nsINavHistoryQueryOptions options); */
  NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options) = 0;

  /* AUTF8String queriesToQueryString ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
  NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval) = 0;

  /* void addObserver (in nsINavHistoryObserver observer, in boolean ownsWeak); */
  NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, bool ownsWeak) = 0;

  /* void removeObserver (in nsINavHistoryObserver observer); */
  NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) = 0;

  /* void getObservers ([optional] out unsigned long count, [array, size_is (count), retval] out nsINavHistoryObserver observers); */
  NS_IMETHOD GetObservers(uint32_t *count, nsINavHistoryObserver * **observers) = 0;

  /* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aClosure); */
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) = 0;

  /* readonly attribute boolean historyDisabled; */
  NS_IMETHOD GetHistoryDisabled(bool *aHistoryDisabled) = 0;

  /* void clearEmbedVisits (); */
  NS_IMETHOD ClearEmbedVisits(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryService, NS_INAVHISTORYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYSERVICE \
  NS_IMETHOD GetDatabaseStatus(uint16_t *aDatabaseStatus) override; \
  NS_IMETHOD GetHasHistoryEntries(bool *aHasHistoryEntries) override; \
  NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval) override; \
  NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) override; \
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) override; \
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) override; \
  NS_IMETHOD CanAddURI(nsIURI *aURI, bool *_retval) override; \
  NS_IMETHOD GetNewQuery(nsINavHistoryQuery * *_retval) override; \
  NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval) override; \
  NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) override; \
  NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) override; \
  NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options) override; \
  NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval) override; \
  NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, bool ownsWeak) override; \
  NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) override; \
  NS_IMETHOD GetObservers(uint32_t *count, nsINavHistoryObserver * **observers) override; \
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) override; \
  NS_IMETHOD GetHistoryDisabled(bool *aHistoryDisabled) override; \
  NS_IMETHOD ClearEmbedVisits(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYSERVICE(_to) \
  NS_IMETHOD GetDatabaseStatus(uint16_t *aDatabaseStatus) override { return _to GetDatabaseStatus(aDatabaseStatus); } \
  NS_IMETHOD GetHasHistoryEntries(bool *aHasHistoryEntries) override { return _to GetHasHistoryEntries(aHasHistoryEntries); } \
  NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval) override { return _to GetPageTitle(aURI, _retval); } \
  NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) override { return _to MarkPageAsFollowedBookmark(aURI); } \
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) override { return _to MarkPageAsTyped(aURI); } \
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) override { return _to MarkPageAsFollowedLink(aURI); } \
  NS_IMETHOD CanAddURI(nsIURI *aURI, bool *_retval) override { return _to CanAddURI(aURI, _retval); } \
  NS_IMETHOD GetNewQuery(nsINavHistoryQuery * *_retval) override { return _to GetNewQuery(_retval); } \
  NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval) override { return _to GetNewQueryOptions(_retval); } \
  NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) override { return _to ExecuteQuery(aQuery, options, _retval); } \
  NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) override { return _to ExecuteQueries(aQueries, aQueryCount, options, _retval); } \
  NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options) override { return _to QueryStringToQueries(aQueryString, aQueries, aResultCount, options); } \
  NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval) override { return _to QueriesToQueryString(aQueries, aQueryCount, options, _retval); } \
  NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, bool ownsWeak) override { return _to AddObserver(observer, ownsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) override { return _to RemoveObserver(observer); } \
  NS_IMETHOD GetObservers(uint32_t *count, nsINavHistoryObserver * **observers) override { return _to GetObservers(count, observers); } \
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) override { return _to RunInBatchMode(aCallback, aClosure); } \
  NS_IMETHOD GetHistoryDisabled(bool *aHistoryDisabled) override { return _to GetHistoryDisabled(aHistoryDisabled); } \
  NS_IMETHOD ClearEmbedVisits(void) override { return _to ClearEmbedVisits(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYSERVICE(_to) \
  NS_IMETHOD GetDatabaseStatus(uint16_t *aDatabaseStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabaseStatus(aDatabaseStatus); } \
  NS_IMETHOD GetHasHistoryEntries(bool *aHasHistoryEntries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasHistoryEntries(aHasHistoryEntries); } \
  NS_IMETHOD GetPageTitle(nsIURI *aURI, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageTitle(aURI, _retval); } \
  NS_IMETHOD MarkPageAsFollowedBookmark(nsIURI *aURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsFollowedBookmark(aURI); } \
  NS_IMETHOD MarkPageAsTyped(nsIURI *aURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsTyped(aURI); } \
  NS_IMETHOD MarkPageAsFollowedLink(nsIURI *aURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkPageAsFollowedLink(aURI); } \
  NS_IMETHOD CanAddURI(nsIURI *aURI, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanAddURI(aURI, _retval); } \
  NS_IMETHOD GetNewQuery(nsINavHistoryQuery * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewQuery(_retval); } \
  NS_IMETHOD GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewQueryOptions(_retval); } \
  NS_IMETHOD ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteQuery(aQuery, options, _retval); } \
  NS_IMETHOD ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteQueries(aQueries, aQueryCount, options, _retval); } \
  NS_IMETHOD QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryStringToQueries(aQueryString, aQueries, aResultCount, options); } \
  NS_IMETHOD QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QueriesToQueryString(aQueries, aQueryCount, options, _retval); } \
  NS_IMETHOD AddObserver(nsINavHistoryObserver *observer, bool ownsWeak) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(observer, ownsWeak); } \
  NS_IMETHOD RemoveObserver(nsINavHistoryObserver *observer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(observer); } \
  NS_IMETHOD GetObservers(uint32_t *count, nsINavHistoryObserver * **observers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObservers(count, observers); } \
  NS_IMETHOD RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RunInBatchMode(aCallback, aClosure); } \
  NS_IMETHOD GetHistoryDisabled(bool *aHistoryDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistoryDisabled(aHistoryDisabled); } \
  NS_IMETHOD ClearEmbedVisits(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearEmbedVisits(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryService : public nsINavHistoryService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYSERVICE

  nsNavHistoryService();

private:
  ~nsNavHistoryService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryService, nsINavHistoryService)

nsNavHistoryService::nsNavHistoryService()
{
  /* member initializers and constructor code */
}

nsNavHistoryService::~nsNavHistoryService()
{
  /* destructor code */
}

/* readonly attribute unsigned short databaseStatus; */
NS_IMETHODIMP nsNavHistoryService::GetDatabaseStatus(uint16_t *aDatabaseStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasHistoryEntries; */
NS_IMETHODIMP nsNavHistoryService::GetHasHistoryEntries(bool *aHasHistoryEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getPageTitle (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::GetPageTitle(nsIURI *aURI, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsFollowedBookmark (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::MarkPageAsFollowedBookmark(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsTyped (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::MarkPageAsTyped(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markPageAsFollowedLink (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::MarkPageAsFollowedLink(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canAddURI (in nsIURI aURI); */
NS_IMETHODIMP nsNavHistoryService::CanAddURI(nsIURI *aURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQuery getNewQuery (); */
NS_IMETHODIMP nsNavHistoryService::GetNewQuery(nsINavHistoryQuery * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryQueryOptions getNewQueryOptions (); */
NS_IMETHODIMP nsNavHistoryService::GetNewQueryOptions(nsINavHistoryQueryOptions * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResult executeQuery (in nsINavHistoryQuery aQuery, in nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::ExecuteQuery(nsINavHistoryQuery *aQuery, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINavHistoryResult executeQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::ExecuteQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsINavHistoryResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void queryStringToQueries (in AUTF8String aQueryString, [array, size_is (aResultCount)] out nsINavHistoryQuery aQueries, out unsigned long aResultCount, out nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::QueryStringToQueries(const nsACString & aQueryString, nsINavHistoryQuery * **aQueries, uint32_t *aResultCount, nsINavHistoryQueryOptions * *options)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String queriesToQueryString ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions options); */
NS_IMETHODIMP nsNavHistoryService::QueriesToQueryString(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *options, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsINavHistoryObserver observer, in boolean ownsWeak); */
NS_IMETHODIMP nsNavHistoryService::AddObserver(nsINavHistoryObserver *observer, bool ownsWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsINavHistoryObserver observer); */
NS_IMETHODIMP nsNavHistoryService::RemoveObserver(nsINavHistoryObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getObservers ([optional] out unsigned long count, [array, size_is (count), retval] out nsINavHistoryObserver observers); */
NS_IMETHODIMP nsNavHistoryService::GetObservers(uint32_t *count, nsINavHistoryObserver * **observers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runInBatchMode (in nsINavHistoryBatchCallback aCallback, in nsISupports aClosure); */
NS_IMETHODIMP nsNavHistoryService::RunInBatchMode(nsINavHistoryBatchCallback *aCallback, nsISupports *aClosure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean historyDisabled; */
NS_IMETHODIMP nsNavHistoryService::GetHistoryDisabled(bool *aHistoryDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearEmbedVisits (); */
NS_IMETHODIMP nsNavHistoryService::ClearEmbedVisits()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINavHistoryBatchCallback */
#define NS_INAVHISTORYBATCHCALLBACK_IID_STR "5a5a9154-95ac-4e3d-90df-558816297407"

#define NS_INAVHISTORYBATCHCALLBACK_IID \
  {0x5a5a9154, 0x95ac, 0x4e3d, \
    { 0x90, 0xdf, 0x55, 0x88, 0x16, 0x29, 0x74, 0x07 }}

class NS_NO_VTABLE nsINavHistoryBatchCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVHISTORYBATCHCALLBACK_IID)

  /* void runBatched (in nsISupports aUserData); */
  NS_IMETHOD RunBatched(nsISupports *aUserData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavHistoryBatchCallback, NS_INAVHISTORYBATCHCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVHISTORYBATCHCALLBACK \
  NS_IMETHOD RunBatched(nsISupports *aUserData) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVHISTORYBATCHCALLBACK(_to) \
  NS_IMETHOD RunBatched(nsISupports *aUserData) override { return _to RunBatched(aUserData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVHISTORYBATCHCALLBACK(_to) \
  NS_IMETHOD RunBatched(nsISupports *aUserData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RunBatched(aUserData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavHistoryBatchCallback : public nsINavHistoryBatchCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVHISTORYBATCHCALLBACK

  nsNavHistoryBatchCallback();

private:
  ~nsNavHistoryBatchCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNavHistoryBatchCallback, nsINavHistoryBatchCallback)

nsNavHistoryBatchCallback::nsNavHistoryBatchCallback()
{
  /* member initializers and constructor code */
}

nsNavHistoryBatchCallback::~nsNavHistoryBatchCallback()
{
  /* destructor code */
}

/* void runBatched (in nsISupports aUserData); */
NS_IMETHODIMP nsNavHistoryBatchCallback::RunBatched(nsISupports *aUserData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINavHistoryService_h__ */
