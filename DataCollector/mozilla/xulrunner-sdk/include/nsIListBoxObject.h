/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIListBoxObject.idl
 */

#ifndef __gen_nsIListBoxObject_h__
#define __gen_nsIListBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIListBoxObject */
#define NS_ILISTBOXOBJECT_IID_STR "aa9def4e-2e59-412d-a6df-b76f52167795"

#define NS_ILISTBOXOBJECT_IID \
  {0xaa9def4e, 0x2e59, 0x412d, \
    { 0xa6, 0xdf, 0xb7, 0x6f, 0x52, 0x16, 0x77, 0x95 }}

class NS_NO_VTABLE nsIListBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILISTBOXOBJECT_IID)

  /* long getRowCount (); */
  NS_IMETHOD GetRowCount(int32_t *_retval) = 0;

  /* nsIDOMElement getItemAtIndex (in long index); */
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMElement * *_retval) = 0;

  /* long getIndexOfItem (in nsIDOMElement item); */
  NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIListBoxObject, NS_ILISTBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILISTBOXOBJECT \
  NS_IMETHOD GetRowCount(int32_t *_retval) override; \
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMElement * *_retval) override; \
  NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, int32_t *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILISTBOXOBJECT(_to) \
  NS_IMETHOD GetRowCount(int32_t *_retval) override { return _to GetRowCount(_retval); } \
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMElement * *_retval) override { return _to GetItemAtIndex(index, _retval); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, int32_t *_retval) override { return _to GetIndexOfItem(item, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILISTBOXOBJECT(_to) \
  NS_IMETHOD GetRowCount(int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowCount(_retval); } \
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAtIndex(index, _retval); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfItem(item, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsListBoxObject : public nsIListBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILISTBOXOBJECT

  nsListBoxObject();

private:
  ~nsListBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsListBoxObject, nsIListBoxObject)

nsListBoxObject::nsListBoxObject()
{
  /* member initializers and constructor code */
}

nsListBoxObject::~nsListBoxObject()
{
  /* destructor code */
}

/* long getRowCount (); */
NS_IMETHODIMP nsListBoxObject::GetRowCount(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getItemAtIndex (in long index); */
NS_IMETHODIMP nsListBoxObject::GetItemAtIndex(int32_t index, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfItem (in nsIDOMElement item); */
NS_IMETHODIMP nsListBoxObject::GetIndexOfItem(nsIDOMElement *item, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIListBoxObject_h__ */
