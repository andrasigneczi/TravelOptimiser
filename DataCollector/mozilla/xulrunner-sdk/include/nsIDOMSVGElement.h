/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMSVGElement.idl
 */

#ifndef __gen_nsIDOMSVGElement_h__
#define __gen_nsIDOMSVGElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMCSSStyleDeclaration; /* forward declaration */

class nsIDOMCSSValue; /* forward declaration */


/* starting interface:    nsIDOMSVGElement */
#define NS_IDOMSVGELEMENT_IID_STR "c63517c5-8bab-4cd1-8694-bccafc32a195"

#define NS_IDOMSVGELEMENT_IID \
  {0xc63517c5, 0x8bab, 0x4cd1, \
    { 0x86, 0x94, 0xbc, 0xca, 0xfc, 0x32, 0xa1, 0x95 }}

class NS_NO_VTABLE nsIDOMSVGElement : public nsIDOMElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGELEMENT_IID)

  /* readonly attribute nsIDOMSVGElement ownerSVGElement; */
  NS_IMETHOD GetOwnerSVGElement(nsIDOMSVGElement * *aOwnerSVGElement) = 0;

  /* readonly attribute nsIDOMSVGElement viewportElement; */
  NS_IMETHOD GetViewportElement(nsIDOMSVGElement * *aViewportElement) = 0;

  /* [binaryname(SVGClassName)] readonly attribute nsISupports className; */
  NS_IMETHOD GetSVGClassName(nsISupports * *aClassName) = 0;

  /* readonly attribute nsIDOMCSSStyleDeclaration style; */
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGElement, NS_IDOMSVGELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGELEMENT \
  NS_IMETHOD GetOwnerSVGElement(nsIDOMSVGElement * *aOwnerSVGElement) override; \
  NS_IMETHOD GetViewportElement(nsIDOMSVGElement * *aViewportElement) override; \
  NS_IMETHOD GetSVGClassName(nsISupports * *aClassName) override; \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGELEMENT(_to) \
  NS_IMETHOD GetOwnerSVGElement(nsIDOMSVGElement * *aOwnerSVGElement) override { return _to GetOwnerSVGElement(aOwnerSVGElement); } \
  NS_IMETHOD GetViewportElement(nsIDOMSVGElement * *aViewportElement) override { return _to GetViewportElement(aViewportElement); } \
  NS_IMETHOD GetSVGClassName(nsISupports * *aClassName) override { return _to GetSVGClassName(aClassName); } \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) override { return _to GetStyle(aStyle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGELEMENT(_to) \
  NS_IMETHOD GetOwnerSVGElement(nsIDOMSVGElement * *aOwnerSVGElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerSVGElement(aOwnerSVGElement); } \
  NS_IMETHOD GetViewportElement(nsIDOMSVGElement * *aViewportElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewportElement(aViewportElement); } \
  NS_IMETHOD GetSVGClassName(nsISupports * *aClassName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSVGClassName(aClassName); } \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyle(aStyle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGElement : public nsIDOMSVGElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGELEMENT

  nsDOMSVGElement();

private:
  ~nsDOMSVGElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMSVGElement, nsIDOMSVGElement)

nsDOMSVGElement::nsDOMSVGElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGElement::~nsDOMSVGElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGElement ownerSVGElement; */
NS_IMETHODIMP nsDOMSVGElement::GetOwnerSVGElement(nsIDOMSVGElement * *aOwnerSVGElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGElement viewportElement; */
NS_IMETHODIMP nsDOMSVGElement::GetViewportElement(nsIDOMSVGElement * *aViewportElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(SVGClassName)] readonly attribute nsISupports className; */
NS_IMETHODIMP nsDOMSVGElement::GetSVGClassName(nsISupports * *aClassName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSStyleDeclaration style; */
NS_IMETHODIMP nsDOMSVGElement::GetStyle(nsIDOMCSSStyleDeclaration * *aStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGElement_h__ */
