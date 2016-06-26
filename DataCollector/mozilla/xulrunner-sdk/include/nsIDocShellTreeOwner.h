/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDocShellTreeOwner.idl
 */

#ifndef __gen_nsIDocShellTreeOwner_h__
#define __gen_nsIDocShellTreeOwner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShellTreeItem; /* forward declaration */


/* starting interface:    nsIDocShellTreeOwner */
#define NS_IDOCSHELLTREEOWNER_IID_STR "05b5b240-1f61-11e4-8c21-0800200c9a66"

#define NS_IDOCSHELLTREEOWNER_IID \
  {0x05b5b240, 0x1f61, 0x11e4, \
    { 0x8c, 0x21, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIDocShellTreeOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLTREEOWNER_IID)

  /* nsIDocShellTreeItem findItemWithName (in wstring name, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
  NS_IMETHOD FindItemWithName(const char16_t * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) = 0;

  /* void contentShellAdded (in nsIDocShellTreeItem aContentShell, in boolean aPrimary, in boolean aTargetable, in AString aID); */
  NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID) = 0;

  /* void contentShellRemoved (in nsIDocShellTreeItem aContentShell); */
  NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) = 0;

  /* readonly attribute nsIDocShellTreeItem primaryContentShell; */
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) = 0;

  /* void sizeShellTo (in nsIDocShellTreeItem shell, in long cx, in long cy); */
  NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy) = 0;

  /* void setPersistence (in boolean aPersistPosition, in boolean aPersistSize, in boolean aPersistSizeMode); */
  NS_IMETHOD SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode) = 0;

  /* void getPersistence (out boolean aPersistPosition, out boolean aPersistSize, out boolean aPersistSizeMode); */
  NS_IMETHOD GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode) = 0;

  /* readonly attribute unsigned long targetableShellCount; */
  NS_IMETHOD GetTargetableShellCount(uint32_t *aTargetableShellCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellTreeOwner, NS_IDOCSHELLTREEOWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLTREEOWNER \
  NS_IMETHOD FindItemWithName(const char16_t * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) override; \
  NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID) override; \
  NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) override; \
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) override; \
  NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy) override; \
  NS_IMETHOD SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode) override; \
  NS_IMETHOD GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode) override; \
  NS_IMETHOD GetTargetableShellCount(uint32_t *aTargetableShellCount) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLTREEOWNER(_to) \
  NS_IMETHOD FindItemWithName(const char16_t * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) override { return _to FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID) override { return _to ContentShellAdded(aContentShell, aPrimary, aTargetable, aID); } \
  NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) override { return _to ContentShellRemoved(aContentShell); } \
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) override { return _to GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy) override { return _to SizeShellTo(shell, cx, cy); } \
  NS_IMETHOD SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode) override { return _to SetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_IMETHOD GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode) override { return _to GetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_IMETHOD GetTargetableShellCount(uint32_t *aTargetableShellCount) override { return _to GetTargetableShellCount(aTargetableShellCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLTREEOWNER(_to) \
  NS_IMETHOD FindItemWithName(const char16_t * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindItemWithName(name, aRequestor, aOriginalRequestor, _retval); } \
  NS_IMETHOD ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ContentShellAdded(aContentShell, aPrimary, aTargetable, aID); } \
  NS_IMETHOD ContentShellRemoved(nsIDocShellTreeItem *aContentShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ContentShellRemoved(aContentShell); } \
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_IMETHOD SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeShellTo(shell, cx, cy); } \
  NS_IMETHOD SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_IMETHOD GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersistence(aPersistPosition, aPersistSize, aPersistSizeMode); } \
  NS_IMETHOD GetTargetableShellCount(uint32_t *aTargetableShellCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetableShellCount(aTargetableShellCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellTreeOwner : public nsIDocShellTreeOwner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLTREEOWNER

  nsDocShellTreeOwner();

private:
  ~nsDocShellTreeOwner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDocShellTreeOwner, nsIDocShellTreeOwner)

nsDocShellTreeOwner::nsDocShellTreeOwner()
{
  /* member initializers and constructor code */
}

nsDocShellTreeOwner::~nsDocShellTreeOwner()
{
  /* destructor code */
}

/* nsIDocShellTreeItem findItemWithName (in wstring name, in nsIDocShellTreeItem aRequestor, in nsIDocShellTreeItem aOriginalRequestor); */
NS_IMETHODIMP nsDocShellTreeOwner::FindItemWithName(const char16_t * name, nsIDocShellTreeItem *aRequestor, nsIDocShellTreeItem *aOriginalRequestor, nsIDocShellTreeItem * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void contentShellAdded (in nsIDocShellTreeItem aContentShell, in boolean aPrimary, in boolean aTargetable, in AString aID); */
NS_IMETHODIMP nsDocShellTreeOwner::ContentShellAdded(nsIDocShellTreeItem *aContentShell, bool aPrimary, bool aTargetable, const nsAString & aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void contentShellRemoved (in nsIDocShellTreeItem aContentShell); */
NS_IMETHODIMP nsDocShellTreeOwner::ContentShellRemoved(nsIDocShellTreeItem *aContentShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem primaryContentShell; */
NS_IMETHODIMP nsDocShellTreeOwner::GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeShellTo (in nsIDocShellTreeItem shell, in long cx, in long cy); */
NS_IMETHODIMP nsDocShellTreeOwner::SizeShellTo(nsIDocShellTreeItem *shell, int32_t cx, int32_t cy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPersistence (in boolean aPersistPosition, in boolean aPersistSize, in boolean aPersistSizeMode); */
NS_IMETHODIMP nsDocShellTreeOwner::SetPersistence(bool aPersistPosition, bool aPersistSize, bool aPersistSizeMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPersistence (out boolean aPersistPosition, out boolean aPersistSize, out boolean aPersistSizeMode); */
NS_IMETHODIMP nsDocShellTreeOwner::GetPersistence(bool *aPersistPosition, bool *aPersistSize, bool *aPersistSizeMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long targetableShellCount; */
NS_IMETHODIMP nsDocShellTreeOwner::GetTargetableShellCount(uint32_t *aTargetableShellCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellTreeOwner_h__ */
