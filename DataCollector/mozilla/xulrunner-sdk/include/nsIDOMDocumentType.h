/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDocumentType.idl
 */

#ifndef __gen_nsIDOMDocumentType_h__
#define __gen_nsIDOMDocumentType_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDocumentType */
#define NS_IDOMDOCUMENTTYPE_IID_STR "cd7467b9-0f26-4787-a359-66e80ba8db92"

#define NS_IDOMDOCUMENTTYPE_IID \
  {0xcd7467b9, 0x0f26, 0x4787, \
    { 0xa3, 0x59, 0x66, 0xe8, 0x0b, 0xa8, 0xdb, 0x92 }}

class NS_NO_VTABLE nsIDOMDocumentType : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTTYPE_IID)

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString publicId; */
  NS_IMETHOD GetPublicId(nsAString & aPublicId) = 0;

  /* readonly attribute DOMString systemId; */
  NS_IMETHOD GetSystemId(nsAString & aSystemId) = 0;

  /* readonly attribute DOMString internalSubset; */
  NS_IMETHOD GetInternalSubset(nsAString & aInternalSubset) = 0;

  /* [binaryname(MozRemove)] void remove (); */
  NS_IMETHOD MozRemove(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentType, NS_IDOMDOCUMENTTYPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTTYPE \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD GetPublicId(nsAString & aPublicId) override; \
  NS_IMETHOD GetSystemId(nsAString & aSystemId) override; \
  NS_IMETHOD GetInternalSubset(nsAString & aInternalSubset) override; \
  NS_IMETHOD MozRemove(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTTYPE(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetPublicId(nsAString & aPublicId) override { return _to GetPublicId(aPublicId); } \
  NS_IMETHOD GetSystemId(nsAString & aSystemId) override { return _to GetSystemId(aSystemId); } \
  NS_IMETHOD GetInternalSubset(nsAString & aInternalSubset) override { return _to GetInternalSubset(aInternalSubset); } \
  NS_IMETHOD MozRemove(void) override { return _to MozRemove(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTTYPE(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetPublicId(nsAString & aPublicId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublicId(aPublicId); } \
  NS_IMETHOD GetSystemId(nsAString & aSystemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemId(aSystemId); } \
  NS_IMETHOD GetInternalSubset(nsAString & aInternalSubset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalSubset(aInternalSubset); } \
  NS_IMETHOD MozRemove(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRemove(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentType : public nsIDOMDocumentType
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTTYPE

  nsDOMDocumentType();

private:
  ~nsDOMDocumentType();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMDocumentType, nsIDOMDocumentType)

nsDOMDocumentType::nsDOMDocumentType()
{
  /* member initializers and constructor code */
}

nsDOMDocumentType::~nsDOMDocumentType()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMDocumentType::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString publicId; */
NS_IMETHODIMP nsDOMDocumentType::GetPublicId(nsAString & aPublicId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString systemId; */
NS_IMETHODIMP nsDOMDocumentType::GetSystemId(nsAString & aSystemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString internalSubset; */
NS_IMETHODIMP nsDOMDocumentType::GetInternalSubset(nsAString & aInternalSubset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(MozRemove)] void remove (); */
NS_IMETHODIMP nsDOMDocumentType::MozRemove()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentType_h__ */
