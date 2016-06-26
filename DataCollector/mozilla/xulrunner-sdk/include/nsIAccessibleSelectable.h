/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleSelectable.idl
 */

#ifndef __gen_nsIAccessibleSelectable_h__
#define __gen_nsIAccessibleSelectable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIAccessibleSelectable */
#define NS_IACCESSIBLESELECTABLE_IID_STR "8efb03d4-1354-4875-94cf-261336057626"

#define NS_IACCESSIBLESELECTABLE_IID \
  {0x8efb03d4, 0x1354, 0x4875, \
    { 0x94, 0xcf, 0x26, 0x13, 0x36, 0x05, 0x76, 0x26 }}

class NS_NO_VTABLE nsIAccessibleSelectable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLESELECTABLE_IID)

  /* readonly attribute nsIArray selectedItems; */
  NS_IMETHOD GetSelectedItems(nsIArray * *aSelectedItems) = 0;

  /* readonly attribute unsigned long selectedItemCount; */
  NS_IMETHOD GetSelectedItemCount(uint32_t *aSelectedItemCount) = 0;

  /* nsIAccessible getSelectedItemAt (in unsigned long index); */
  NS_IMETHOD GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval) = 0;

  /* boolean isItemSelected (in unsigned long index); */
  NS_IMETHOD IsItemSelected(uint32_t index, bool *_retval) = 0;

  /* void addItemToSelection (in unsigned long index); */
  NS_IMETHOD AddItemToSelection(uint32_t index) = 0;

  /* void removeItemFromSelection (in unsigned long index); */
  NS_IMETHOD RemoveItemFromSelection(uint32_t index) = 0;

  /* boolean selectAll (); */
  NS_IMETHOD SelectAll(bool *_retval) = 0;

  /* void unselectAll (); */
  NS_IMETHOD UnselectAll(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleSelectable, NS_IACCESSIBLESELECTABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLESELECTABLE \
  NS_IMETHOD GetSelectedItems(nsIArray * *aSelectedItems) override; \
  NS_IMETHOD GetSelectedItemCount(uint32_t *aSelectedItemCount) override; \
  NS_IMETHOD GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval) override; \
  NS_IMETHOD IsItemSelected(uint32_t index, bool *_retval) override; \
  NS_IMETHOD AddItemToSelection(uint32_t index) override; \
  NS_IMETHOD RemoveItemFromSelection(uint32_t index) override; \
  NS_IMETHOD SelectAll(bool *_retval) override; \
  NS_IMETHOD UnselectAll(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLESELECTABLE(_to) \
  NS_IMETHOD GetSelectedItems(nsIArray * *aSelectedItems) override { return _to GetSelectedItems(aSelectedItems); } \
  NS_IMETHOD GetSelectedItemCount(uint32_t *aSelectedItemCount) override { return _to GetSelectedItemCount(aSelectedItemCount); } \
  NS_IMETHOD GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval) override { return _to GetSelectedItemAt(index, _retval); } \
  NS_IMETHOD IsItemSelected(uint32_t index, bool *_retval) override { return _to IsItemSelected(index, _retval); } \
  NS_IMETHOD AddItemToSelection(uint32_t index) override { return _to AddItemToSelection(index); } \
  NS_IMETHOD RemoveItemFromSelection(uint32_t index) override { return _to RemoveItemFromSelection(index); } \
  NS_IMETHOD SelectAll(bool *_retval) override { return _to SelectAll(_retval); } \
  NS_IMETHOD UnselectAll(void) override { return _to UnselectAll(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLESELECTABLE(_to) \
  NS_IMETHOD GetSelectedItems(nsIArray * *aSelectedItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItems(aSelectedItems); } \
  NS_IMETHOD GetSelectedItemCount(uint32_t *aSelectedItemCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItemCount(aSelectedItemCount); } \
  NS_IMETHOD GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItemAt(index, _retval); } \
  NS_IMETHOD IsItemSelected(uint32_t index, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsItemSelected(index, _retval); } \
  NS_IMETHOD AddItemToSelection(uint32_t index) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddItemToSelection(index); } \
  NS_IMETHOD RemoveItemFromSelection(uint32_t index) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemFromSelection(index); } \
  NS_IMETHOD SelectAll(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(_retval); } \
  NS_IMETHOD UnselectAll(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnselectAll(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleSelectable : public nsIAccessibleSelectable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLESELECTABLE

  nsAccessibleSelectable();

private:
  ~nsAccessibleSelectable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessibleSelectable, nsIAccessibleSelectable)

nsAccessibleSelectable::nsAccessibleSelectable()
{
  /* member initializers and constructor code */
}

nsAccessibleSelectable::~nsAccessibleSelectable()
{
  /* destructor code */
}

/* readonly attribute nsIArray selectedItems; */
NS_IMETHODIMP nsAccessibleSelectable::GetSelectedItems(nsIArray * *aSelectedItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedItemCount; */
NS_IMETHODIMP nsAccessibleSelectable::GetSelectedItemCount(uint32_t *aSelectedItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getSelectedItemAt (in unsigned long index); */
NS_IMETHODIMP nsAccessibleSelectable::GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isItemSelected (in unsigned long index); */
NS_IMETHODIMP nsAccessibleSelectable::IsItemSelected(uint32_t index, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addItemToSelection (in unsigned long index); */
NS_IMETHODIMP nsAccessibleSelectable::AddItemToSelection(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItemFromSelection (in unsigned long index); */
NS_IMETHODIMP nsAccessibleSelectable::RemoveItemFromSelection(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean selectAll (); */
NS_IMETHODIMP nsAccessibleSelectable::SelectAll(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unselectAll (); */
NS_IMETHODIMP nsAccessibleSelectable::UnselectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleSelectable_h__ */
