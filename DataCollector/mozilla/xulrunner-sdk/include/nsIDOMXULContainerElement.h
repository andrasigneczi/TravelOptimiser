/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXULContainerElement.idl
 */

#ifndef __gen_nsIDOMXULContainerElement_h__
#define __gen_nsIDOMXULContainerElement_h__


#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULContainerElement; /* forward declaration */


/* starting interface:    nsIDOMXULContainerItemElement */
#define NS_IDOMXULCONTAINERITEMELEMENT_IID_STR "800a68c7-b854-4597-a436-3055ce5c5c96"

#define NS_IDOMXULCONTAINERITEMELEMENT_IID \
  {0x800a68c7, 0xb854, 0x4597, \
    { 0xa4, 0x36, 0x30, 0x55, 0xce, 0x5c, 0x5c, 0x96 }}

class NS_NO_VTABLE nsIDOMXULContainerItemElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTAINERITEMELEMENT_IID)

  /* readonly attribute nsIDOMXULContainerElement parentContainer; */
  NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULContainerItemElement, NS_IDOMXULCONTAINERITEMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTAINERITEMELEMENT \
  NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTAINERITEMELEMENT(_to) \
  NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) override { return _to GetParentContainer(aParentContainer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTAINERITEMELEMENT(_to) \
  NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentContainer(aParentContainer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULContainerItemElement : public nsIDOMXULContainerItemElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTAINERITEMELEMENT

  nsDOMXULContainerItemElement();

private:
  ~nsDOMXULContainerItemElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMXULContainerItemElement, nsIDOMXULContainerItemElement)

nsDOMXULContainerItemElement::nsDOMXULContainerItemElement()
{
  /* member initializers and constructor code */
}

nsDOMXULContainerItemElement::~nsDOMXULContainerItemElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMXULContainerElement parentContainer; */
NS_IMETHODIMP nsDOMXULContainerItemElement::GetParentContainer(nsIDOMXULContainerElement * *aParentContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMXULContainerElement */
#define NS_IDOMXULCONTAINERELEMENT_IID_STR "b2bc96b8-31fc-42f4-937a-bd27291af40b"

#define NS_IDOMXULCONTAINERELEMENT_IID \
  {0xb2bc96b8, 0x31fc, 0x42f4, \
    { 0x93, 0x7a, 0xbd, 0x27, 0x29, 0x1a, 0xf4, 0x0b }}

class NS_NO_VTABLE nsIDOMXULContainerElement : public nsIDOMXULContainerItemElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTAINERELEMENT_IID)

  /* nsIDOMXULElement appendItem (in DOMString aLabel, in DOMString aValue); */
  NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) = 0;

  /* nsIDOMXULElement insertItemAt (in long aIndex, in DOMString aLabel, in DOMString aValue); */
  NS_IMETHOD InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) = 0;

  /* nsIDOMXULElement removeItemAt (in long aIndex); */
  NS_IMETHOD RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval) = 0;

  /* readonly attribute unsigned long itemCount; */
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) = 0;

  /* long getIndexOfItem (in nsIDOMXULElement aItem); */
  NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval) = 0;

  /* nsIDOMXULElement getItemAtIndex (in long aIndex); */
  NS_IMETHOD GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULContainerElement, NS_IDOMXULCONTAINERELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTAINERELEMENT \
  NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) override; \
  NS_IMETHOD InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) override; \
  NS_IMETHOD RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval) override; \
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) override; \
  NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval) override; \
  NS_IMETHOD GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTAINERELEMENT(_to) \
  NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) override { return _to AppendItem(aLabel, aValue, _retval); } \
  NS_IMETHOD InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) override { return _to InsertItemAt(aIndex, aLabel, aValue, _retval); } \
  NS_IMETHOD RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval) override { return _to RemoveItemAt(aIndex, _retval); } \
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) override { return _to GetItemCount(aItemCount); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval) override { return _to GetIndexOfItem(aItem, _retval); } \
  NS_IMETHOD GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval) override { return _to GetItemAtIndex(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTAINERELEMENT(_to) \
  NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(aLabel, aValue, _retval); } \
  NS_IMETHOD InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemAt(aIndex, aLabel, aValue, _retval); } \
  NS_IMETHOD RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAt(aIndex, _retval); } \
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemCount(aItemCount); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfItem(aItem, _retval); } \
  NS_IMETHOD GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAtIndex(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULContainerElement : public nsIDOMXULContainerElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTAINERELEMENT

  nsDOMXULContainerElement();

private:
  ~nsDOMXULContainerElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMXULContainerElement, nsIDOMXULContainerElement)

nsDOMXULContainerElement::nsDOMXULContainerElement()
{
  /* member initializers and constructor code */
}

nsDOMXULContainerElement::~nsDOMXULContainerElement()
{
  /* destructor code */
}

/* nsIDOMXULElement appendItem (in DOMString aLabel, in DOMString aValue); */
NS_IMETHODIMP nsDOMXULContainerElement::AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement insertItemAt (in long aIndex, in DOMString aLabel, in DOMString aValue); */
NS_IMETHODIMP nsDOMXULContainerElement::InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement removeItemAt (in long aIndex); */
NS_IMETHODIMP nsDOMXULContainerElement::RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long itemCount; */
NS_IMETHODIMP nsDOMXULContainerElement::GetItemCount(uint32_t *aItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfItem (in nsIDOMXULElement aItem); */
NS_IMETHODIMP nsDOMXULContainerElement::GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement getItemAtIndex (in long aIndex); */
NS_IMETHODIMP nsDOMXULContainerElement::GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULContainerElement_h__ */
