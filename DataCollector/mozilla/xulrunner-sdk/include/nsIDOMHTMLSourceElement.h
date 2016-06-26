/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLSourceElement.idl
 */

#ifndef __gen_nsIDOMHTMLSourceElement_h__
#define __gen_nsIDOMHTMLSourceElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLSourceElement */
#define NS_IDOMHTMLSOURCEELEMENT_IID_STR "1deb68f8-2ed6-4a41-b8c8-e0f86510f799"

#define NS_IDOMHTMLSOURCEELEMENT_IID \
  {0x1deb68f8, 0x2ed6, 0x4a41, \
    { 0xb8, 0xc8, 0xe0, 0xf8, 0x65, 0x10, 0xf7, 0x99 }}

class NS_NO_VTABLE nsIDOMHTMLSourceElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLSOURCEELEMENT_IID)

  /* attribute DOMString src; */
  NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString srcset; */
  NS_IMETHOD GetSrcset(nsAString & aSrcset) = 0;
  NS_IMETHOD SetSrcset(const nsAString & aSrcset) = 0;

  /* attribute DOMString sizes; */
  NS_IMETHOD GetSizes(nsAString & aSizes) = 0;
  NS_IMETHOD SetSizes(const nsAString & aSizes) = 0;

  /* attribute DOMString media; */
  NS_IMETHOD GetMedia(nsAString & aMedia) = 0;
  NS_IMETHOD SetMedia(const nsAString & aMedia) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLSourceElement, NS_IDOMHTMLSOURCEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLSOURCEELEMENT \
  NS_IMETHOD GetSrc(nsAString & aSrc) override; \
  NS_IMETHOD SetSrc(const nsAString & aSrc) override; \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD SetType(const nsAString & aType) override; \
  NS_IMETHOD GetSrcset(nsAString & aSrcset) override; \
  NS_IMETHOD SetSrcset(const nsAString & aSrcset) override; \
  NS_IMETHOD GetSizes(nsAString & aSizes) override; \
  NS_IMETHOD SetSizes(const nsAString & aSizes) override; \
  NS_IMETHOD GetMedia(nsAString & aMedia) override; \
  NS_IMETHOD SetMedia(const nsAString & aMedia) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLSOURCEELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) override { return _to GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) override { return _to SetSrc(aSrc); } \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return _to SetType(aType); } \
  NS_IMETHOD GetSrcset(nsAString & aSrcset) override { return _to GetSrcset(aSrcset); } \
  NS_IMETHOD SetSrcset(const nsAString & aSrcset) override { return _to SetSrcset(aSrcset); } \
  NS_IMETHOD GetSizes(nsAString & aSizes) override { return _to GetSizes(aSizes); } \
  NS_IMETHOD SetSizes(const nsAString & aSizes) override { return _to SetSizes(aSizes); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) override { return _to GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) override { return _to SetMedia(aMedia); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLSOURCEELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetSrcset(nsAString & aSrcset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrcset(aSrcset); } \
  NS_IMETHOD SetSrcset(const nsAString & aSrcset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrcset(aSrcset); } \
  NS_IMETHOD GetSizes(nsAString & aSizes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSizes(aSizes); } \
  NS_IMETHOD SetSizes(const nsAString & aSizes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSizes(aSizes); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMedia(aMedia); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLSourceElement : public nsIDOMHTMLSourceElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLSOURCEELEMENT

  nsDOMHTMLSourceElement();

private:
  ~nsDOMHTMLSourceElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMHTMLSourceElement, nsIDOMHTMLSourceElement)

nsDOMHTMLSourceElement::nsDOMHTMLSourceElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLSourceElement::~nsDOMHTMLSourceElement()
{
  /* destructor code */
}

/* attribute DOMString src; */
NS_IMETHODIMP nsDOMHTMLSourceElement::GetSrc(nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSourceElement::SetSrc(const nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLSourceElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSourceElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString srcset; */
NS_IMETHODIMP nsDOMHTMLSourceElement::GetSrcset(nsAString & aSrcset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSourceElement::SetSrcset(const nsAString & aSrcset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString sizes; */
NS_IMETHODIMP nsDOMHTMLSourceElement::GetSizes(nsAString & aSizes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSourceElement::SetSizes(const nsAString & aSizes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString media; */
NS_IMETHODIMP nsDOMHTMLSourceElement::GetMedia(nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLSourceElement::SetMedia(const nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLSourceElement_h__ */
