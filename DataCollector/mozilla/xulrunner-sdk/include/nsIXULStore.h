/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXULStore.idl
 */

#ifndef __gen_nsIXULStore_h__
#define __gen_nsIXULStore_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIStringEnumerator; /* forward declaration */


/* starting interface:    nsIXULStore */
#define NS_IXULSTORE_IID_STR "987c4b35-c426-4dd7-ad49-3c9fa4c65d20"

#define NS_IXULSTORE_IID \
  {0x987c4b35, 0xc426, 0x4dd7, \
    { 0xad, 0x49, 0x3c, 0x9f, 0xa4, 0xc6, 0x5d, 0x20 }}

class NS_NO_VTABLE nsIXULStore : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULSTORE_IID)

  /* void setValue (in AString doc, in AString id, in AString attr, in AString value); */
  NS_IMETHOD SetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, const nsAString & value) = 0;

  /* bool hasValue (in AString doc, in AString id, in AString attr); */
  NS_IMETHOD HasValue(const nsAString & doc, const nsAString & id, const nsAString & attr, bool *_retval) = 0;

  /* AString getValue (in AString doc, in AString id, in AString attr); */
  NS_IMETHOD GetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, nsAString & _retval) = 0;

  /* void removeValue (in AString doc, in AString id, in AString attr); */
  NS_IMETHOD RemoveValue(const nsAString & doc, const nsAString & id, const nsAString & attr) = 0;

  /* nsIStringEnumerator getIDsEnumerator (in AString doc); */
  NS_IMETHOD GetIDsEnumerator(const nsAString & doc, nsIStringEnumerator * *_retval) = 0;

  /* nsIStringEnumerator getAttributeEnumerator (in AString doc, in AString id); */
  NS_IMETHOD GetAttributeEnumerator(const nsAString & doc, const nsAString & id, nsIStringEnumerator * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULStore, NS_IXULSTORE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULSTORE \
  NS_IMETHOD SetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, const nsAString & value) override; \
  NS_IMETHOD HasValue(const nsAString & doc, const nsAString & id, const nsAString & attr, bool *_retval) override; \
  NS_IMETHOD GetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, nsAString & _retval) override; \
  NS_IMETHOD RemoveValue(const nsAString & doc, const nsAString & id, const nsAString & attr) override; \
  NS_IMETHOD GetIDsEnumerator(const nsAString & doc, nsIStringEnumerator * *_retval) override; \
  NS_IMETHOD GetAttributeEnumerator(const nsAString & doc, const nsAString & id, nsIStringEnumerator * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULSTORE(_to) \
  NS_IMETHOD SetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, const nsAString & value) override { return _to SetValue(doc, id, attr, value); } \
  NS_IMETHOD HasValue(const nsAString & doc, const nsAString & id, const nsAString & attr, bool *_retval) override { return _to HasValue(doc, id, attr, _retval); } \
  NS_IMETHOD GetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, nsAString & _retval) override { return _to GetValue(doc, id, attr, _retval); } \
  NS_IMETHOD RemoveValue(const nsAString & doc, const nsAString & id, const nsAString & attr) override { return _to RemoveValue(doc, id, attr); } \
  NS_IMETHOD GetIDsEnumerator(const nsAString & doc, nsIStringEnumerator * *_retval) override { return _to GetIDsEnumerator(doc, _retval); } \
  NS_IMETHOD GetAttributeEnumerator(const nsAString & doc, const nsAString & id, nsIStringEnumerator * *_retval) override { return _to GetAttributeEnumerator(doc, id, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULSTORE(_to) \
  NS_IMETHOD SetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, const nsAString & value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(doc, id, attr, value); } \
  NS_IMETHOD HasValue(const nsAString & doc, const nsAString & id, const nsAString & attr, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasValue(doc, id, attr, _retval); } \
  NS_IMETHOD GetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(doc, id, attr, _retval); } \
  NS_IMETHOD RemoveValue(const nsAString & doc, const nsAString & id, const nsAString & attr) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveValue(doc, id, attr); } \
  NS_IMETHOD GetIDsEnumerator(const nsAString & doc, nsIStringEnumerator * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIDsEnumerator(doc, _retval); } \
  NS_IMETHOD GetAttributeEnumerator(const nsAString & doc, const nsAString & id, nsIStringEnumerator * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributeEnumerator(doc, id, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULStore : public nsIXULStore
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULSTORE

  nsXULStore();

private:
  ~nsXULStore();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXULStore, nsIXULStore)

nsXULStore::nsXULStore()
{
  /* member initializers and constructor code */
}

nsXULStore::~nsXULStore()
{
  /* destructor code */
}

/* void setValue (in AString doc, in AString id, in AString attr, in AString value); */
NS_IMETHODIMP nsXULStore::SetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool hasValue (in AString doc, in AString id, in AString attr); */
NS_IMETHODIMP nsXULStore::HasValue(const nsAString & doc, const nsAString & id, const nsAString & attr, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValue (in AString doc, in AString id, in AString attr); */
NS_IMETHODIMP nsXULStore::GetValue(const nsAString & doc, const nsAString & id, const nsAString & attr, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeValue (in AString doc, in AString id, in AString attr); */
NS_IMETHODIMP nsXULStore::RemoveValue(const nsAString & doc, const nsAString & id, const nsAString & attr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStringEnumerator getIDsEnumerator (in AString doc); */
NS_IMETHODIMP nsXULStore::GetIDsEnumerator(const nsAString & doc, nsIStringEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStringEnumerator getAttributeEnumerator (in AString doc, in AString id); */
NS_IMETHODIMP nsXULStore::GetAttributeEnumerator(const nsAString & doc, const nsAString & id, nsIStringEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULStore_h__ */
