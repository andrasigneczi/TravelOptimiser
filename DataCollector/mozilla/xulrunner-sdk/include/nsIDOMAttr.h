/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMAttr.idl
 */

#ifndef __gen_nsIDOMAttr_h__
#define __gen_nsIDOMAttr_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMAttr */
#define NS_IDOMATTR_IID_STR "7db491e8-a3a3-4432-ad67-e6c33e24ac6d"

#define NS_IDOMATTR_IID \
  {0x7db491e8, 0xa3a3, 0x4432, \
    { 0xad, 0x67, 0xe6, 0xc3, 0x3e, 0x24, 0xac, 0x6d }}

class NS_NO_VTABLE nsIDOMAttr : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMATTR_IID)

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute boolean specified; */
  NS_IMETHOD GetSpecified(bool *aSpecified) = 0;

  /* attribute DOMString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* readonly attribute nsIDOMElement ownerElement; */
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) = 0;

  /* readonly attribute boolean isId; */
  NS_IMETHOD GetIsId(bool *aIsId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMAttr, NS_IDOMATTR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMATTR \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD GetSpecified(bool *aSpecified) override; \
  NS_IMETHOD GetValue(nsAString & aValue) override; \
  NS_IMETHOD SetValue(const nsAString & aValue) override; \
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) override; \
  NS_IMETHOD GetIsId(bool *aIsId) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMATTR(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetSpecified(bool *aSpecified) override { return _to GetSpecified(aSpecified); } \
  NS_IMETHOD GetValue(nsAString & aValue) override { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) override { return _to SetValue(aValue); } \
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) override { return _to GetOwnerElement(aOwnerElement); } \
  NS_IMETHOD GetIsId(bool *aIsId) override { return _to GetIsId(aIsId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMATTR(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetSpecified(bool *aSpecified) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpecified(aSpecified); } \
  NS_IMETHOD GetValue(nsAString & aValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerElement(aOwnerElement); } \
  NS_IMETHOD GetIsId(bool *aIsId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsId(aIsId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMAttr : public nsIDOMAttr
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMATTR

  nsDOMAttr();

private:
  ~nsDOMAttr();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMAttr, nsIDOMAttr)

nsDOMAttr::nsDOMAttr()
{
  /* member initializers and constructor code */
}

nsDOMAttr::~nsDOMAttr()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMAttr::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean specified; */
NS_IMETHODIMP nsDOMAttr::GetSpecified(bool *aSpecified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMAttr::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMAttr::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement ownerElement; */
NS_IMETHODIMP nsDOMAttr::GetOwnerElement(nsIDOMElement * *aOwnerElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isId; */
NS_IMETHODIMP nsDOMAttr::GetIsId(bool *aIsId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMAttr_h__ */
