/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDocShellTreeItem.idl
 */

#ifndef __gen_nsIDocShellTreeItem_h__
#define __gen_nsIDocShellTreeItem_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShellTreeOwner; /* forward declaration */

class nsIDocument; /* forward declaration */

class nsPIDOMWindow; /* forward declaration */


/* starting interface:    nsIDocShellTreeItem */
#define NS_IDOCSHELLTREEITEM_IID_STR "edb99640-8378-4106-8673-e701a086eb1c"

#define NS_IDOCSHELLTREEITEM_IID \
  {0xedb99640, 0x8378, 0x4106, \
    { 0x86, 0x73, 0xe7, 0x01, 0xa0, 0x86, 0xeb, 0x1c }}

class NS_NO_VTABLE nsIDocShellTreeItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLTREEITEM_IID)

  /* attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* boolean nameEquals (in wstring name); */
  NS_IMETHOD NameEquals(const char16_t * name, bool *_retval) = 0;

  enum {
    typeChrome = 0,
    typeContent = 1,
    typeContentWrapper = 2,
    typeChromeWrapper = 3,
    typeAll = 2147483647
  };

  /* attribute long itemType; */
  NS_IMETHOD GetItemType(int32_t *aItemType) = 0;
  NS_IMETHOD SetItemType(int32_t aItemType) = 0;

  /* [noscript,nostdcall,notxpcom] long ItemType (); */
  virtual int32_t ItemType(void) = 0;

  /* readonly attribute nsIDocShellTreeItem parent; */
  NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) = 0;

  /* readonly attribute nsIDocShellTreeItem sameTypeParent; */
  NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) = 0;

  /* readonly attribute nsIDocShellTreeItem rootTreeItem; */
  NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) = 0;

  /* readonly attribute nsIDocShellTreeItem sameTypeRootTreeItem; */
  NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) = 0;

  /* nsIDocShellTreeItem findItemWithName (in wstring name, in nsISupports aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_IMETHOD FindItemWithName(const char16_t * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) = 0;

  /* readonly attribute nsIDocShellTreeOwner treeOwner; */
  NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) = 0;

  /* [noscript] void setTreeOwner (in nsIDocShellTreeOwner treeOwner); */
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) = 0;

  /* readonly attribute long childCount; */
  NS_IMETHOD GetChildCount(int32_t *aChildCount) = 0;

  /* void addChild (in nsIDocShellTreeItem child); */
  NS_IMETHOD AddChild(nsIDocShellTreeItem *child) = 0;

  /* void removeChild (in nsIDocShellTreeItem child); */
  NS_IMETHOD RemoveChild(nsIDocShellTreeItem *child) = 0;

  /* nsIDocShellTreeItem getChildAt (in long index); */
  NS_IMETHOD GetChildAt(int32_t index, nsIDocShellTreeItem * *_retval) = 0;

  /* nsIDocShellTreeItem findChildWithName (in wstring aName, in boolean aRecurse, in boolean aSameType, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_IMETHOD FindChildWithName(const char16_t * aName, bool aRecurse, bool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) = 0;

  /* [noscript,nostdcall,notxpcom] nsIDocument getDocument (); */
  virtual nsIDocument * GetDocument(void) = 0;

  /* [noscript,nostdcall,notxpcom] nsPIDOMWindow getWindow (); */
  virtual nsPIDOMWindow * GetWindow(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellTreeItem, NS_IDOCSHELLTREEITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLTREEITEM \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD SetName(const nsAString & aName) override; \
  NS_IMETHOD NameEquals(const char16_t * name, bool *_retval) override; \
  NS_IMETHOD GetItemType(int32_t *aItemType) override; \
  NS_IMETHOD SetItemType(int32_t aItemType) override; \
  virtual int32_t ItemType(void) override; \
  NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) override; \
  NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) override; \
  NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) override; \
  NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) override; \
  NS_IMETHOD FindItemWithName(const char16_t * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) override; \
  NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) override; \
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) override; \
  NS_IMETHOD GetChildCount(int32_t *aChildCount) override; \
  NS_IMETHOD AddChild(nsIDocShellTreeItem *child) override; \
  NS_IMETHOD RemoveChild(nsIDocShellTreeItem *child) override; \
  NS_IMETHOD GetChildAt(int32_t index, nsIDocShellTreeItem * *_retval) override; \
  NS_IMETHOD FindChildWithName(const char16_t * aName, bool aRecurse, bool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) override; \
  virtual nsIDocument * GetDocument(void) override; \
  virtual nsPIDOMWindow * GetWindow(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLTREEITEM(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return _to SetName(aName); } \
  NS_IMETHOD NameEquals(const char16_t * name, bool *_retval) override { return _to NameEquals(name, _retval); } \
  NS_IMETHOD GetItemType(int32_t *aItemType) override { return _to GetItemType(aItemType); } \
  NS_IMETHOD SetItemType(int32_t aItemType) override { return _to SetItemType(aItemType); } \
  virtual int32_t ItemType(void) override { return _to ItemType(); } \
  NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) override { return _to GetParent(aParent); } \
  NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) override { return _to GetSameTypeParent(aSameTypeParent); } \
  NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) override { return _to GetRootTreeItem(aRootTreeItem); } \
  NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) override { return _to GetSameTypeRootTreeItem(aSameTypeRootTreeItem); } \
  NS_IMETHOD FindItemWithName(const char16_t * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) override { return _to FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) override { return _to GetTreeOwner(aTreeOwner); } \
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) override { return _to SetTreeOwner(treeOwner); } \
  NS_IMETHOD GetChildCount(int32_t *aChildCount) override { return _to GetChildCount(aChildCount); } \
  NS_IMETHOD AddChild(nsIDocShellTreeItem *child) override { return _to AddChild(child); } \
  NS_IMETHOD RemoveChild(nsIDocShellTreeItem *child) override { return _to RemoveChild(child); } \
  NS_IMETHOD GetChildAt(int32_t index, nsIDocShellTreeItem * *_retval) override { return _to GetChildAt(index, _retval); } \
  NS_IMETHOD FindChildWithName(const char16_t * aName, bool aRecurse, bool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) override { return _to FindChildWithName(aName, aRecurse, aSameType, aRequestor, aOriginalRequestor, _retval); } \
  virtual nsIDocument * GetDocument(void) override { return _to GetDocument(); } \
  virtual nsPIDOMWindow * GetWindow(void) override { return _to GetWindow(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLTREEITEM(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD NameEquals(const char16_t * name, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NameEquals(name, _retval); } \
  NS_IMETHOD GetItemType(int32_t *aItemType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemType(aItemType); } \
  NS_IMETHOD SetItemType(int32_t aItemType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemType(aItemType); } \
  virtual int32_t ItemType(void) override; \
  NS_IMETHOD GetParent(nsIDocShellTreeItem * *aParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_IMETHOD GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSameTypeParent(aSameTypeParent); } \
  NS_IMETHOD GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootTreeItem(aRootTreeItem); } \
  NS_IMETHOD GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSameTypeRootTreeItem(aSameTypeRootTreeItem); } \
  NS_IMETHOD FindItemWithName(const char16_t * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_IMETHOD GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTreeOwner(aTreeOwner); } \
  NS_IMETHOD SetTreeOwner(nsIDocShellTreeOwner *treeOwner) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTreeOwner(treeOwner); } \
  NS_IMETHOD GetChildCount(int32_t *aChildCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_IMETHOD AddChild(nsIDocShellTreeItem *child) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddChild(child); } \
  NS_IMETHOD RemoveChild(nsIDocShellTreeItem *child) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChild(child); } \
  NS_IMETHOD GetChildAt(int32_t index, nsIDocShellTreeItem * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAt(index, _retval); } \
  NS_IMETHOD FindChildWithName(const char16_t * aName, bool aRecurse, bool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindChildWithName(aName, aRecurse, aSameType, aRequestor, aOriginalRequestor, _retval); } \
  virtual nsIDocument * GetDocument(void) override; \
  virtual nsPIDOMWindow * GetWindow(void) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellTreeItem : public nsIDocShellTreeItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLTREEITEM

  nsDocShellTreeItem();

private:
  ~nsDocShellTreeItem();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDocShellTreeItem, nsIDocShellTreeItem)

nsDocShellTreeItem::nsDocShellTreeItem()
{
  /* member initializers and constructor code */
}

nsDocShellTreeItem::~nsDocShellTreeItem()
{
  /* destructor code */
}

/* attribute AString name; */
NS_IMETHODIMP nsDocShellTreeItem::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellTreeItem::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean nameEquals (in wstring name); */
NS_IMETHODIMP nsDocShellTreeItem::NameEquals(const char16_t * name, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long itemType; */
NS_IMETHODIMP nsDocShellTreeItem::GetItemType(int32_t *aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellTreeItem::SetItemType(int32_t aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] long ItemType (); */
int32_t nsDocShellTreeItem::ItemType()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem parent; */
NS_IMETHODIMP nsDocShellTreeItem::GetParent(nsIDocShellTreeItem * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem sameTypeParent; */
NS_IMETHODIMP nsDocShellTreeItem::GetSameTypeParent(nsIDocShellTreeItem * *aSameTypeParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem rootTreeItem; */
NS_IMETHODIMP nsDocShellTreeItem::GetRootTreeItem(nsIDocShellTreeItem * *aRootTreeItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem sameTypeRootTreeItem; */
NS_IMETHODIMP nsDocShellTreeItem::GetSameTypeRootTreeItem(nsIDocShellTreeItem * *aSameTypeRootTreeItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem findItemWithName (in wstring name, in nsISupports aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP nsDocShellTreeItem::FindItemWithName(const char16_t * name, nsISupports *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeOwner treeOwner; */
NS_IMETHODIMP nsDocShellTreeItem::GetTreeOwner(nsIDocShellTreeOwner * *aTreeOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setTreeOwner (in nsIDocShellTreeOwner treeOwner); */
NS_IMETHODIMP nsDocShellTreeItem::SetTreeOwner(nsIDocShellTreeOwner *treeOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long childCount; */
NS_IMETHODIMP nsDocShellTreeItem::GetChildCount(int32_t *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addChild (in nsIDocShellTreeItem child); */
NS_IMETHODIMP nsDocShellTreeItem::AddChild(nsIDocShellTreeItem *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeChild (in nsIDocShellTreeItem child); */
NS_IMETHODIMP nsDocShellTreeItem::RemoveChild(nsIDocShellTreeItem *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem getChildAt (in long index); */
NS_IMETHODIMP nsDocShellTreeItem::GetChildAt(int32_t index, nsIDocShellTreeItem * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem findChildWithName (in wstring aName, in boolean aRecurse, in boolean aSameType, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP nsDocShellTreeItem::FindChildWithName(const char16_t * aName, bool aRecurse, bool aSameType, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsIDocument getDocument (); */
nsIDocument * nsDocShellTreeItem::GetDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsPIDOMWindow getWindow (); */
nsPIDOMWindow * nsDocShellTreeItem::GetWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellTreeItem_h__ */
