/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSStyleDeclaration.idl
 */

#ifndef __gen_nsIDOMCSSStyleDeclaration_h__
#define __gen_nsIDOMCSSStyleDeclaration_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSStyleDeclaration */
#define NS_IDOMCSSSTYLEDECLARATION_IID_STR "a6cf90be-15b3-11d2-932e-00805f8add32"

#define NS_IDOMCSSSTYLEDECLARATION_IID \
  {0xa6cf90be, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE nsIDOMCSSStyleDeclaration : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSSTYLEDECLARATION_IID)

  /* attribute DOMString cssText; */
  NS_IMETHOD GetCssText(nsAString & aCssText) = 0;
  NS_IMETHOD SetCssText(const nsAString & aCssText) = 0;

  /* DOMString getPropertyValue (in DOMString propertyName); */
  NS_IMETHOD GetPropertyValue(const nsAString & propertyName, nsAString & _retval) = 0;

  /* nsIDOMCSSValue getPropertyCSSValue (in DOMString propertyName); */
  NS_IMETHOD GetPropertyCSSValue(const nsAString & propertyName, nsIDOMCSSValue * *_retval) = 0;

  /* DOMString removeProperty (in DOMString propertyName) raises (DOMException); */
  NS_IMETHOD RemoveProperty(const nsAString & propertyName, nsAString & _retval) = 0;

  /* DOMString getPropertyPriority (in DOMString propertyName); */
  NS_IMETHOD GetPropertyPriority(const nsAString & propertyName, nsAString & _retval) = 0;

  /* void setProperty (in DOMString propertyName, in DOMString value, [optional] in DOMString priority) raises (DOMException); */
  NS_IMETHOD SetProperty(const nsAString & propertyName, const nsAString & value, const nsAString & priority) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* DOMString item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) = 0;

  /* readonly attribute nsIDOMCSSRule parentRule; */
  NS_IMETHOD GetParentRule(nsIDOMCSSRule * *aParentRule) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSStyleDeclaration, NS_IDOMCSSSTYLEDECLARATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSSTYLEDECLARATION \
  NS_IMETHOD GetCssText(nsAString & aCssText) override; \
  NS_IMETHOD SetCssText(const nsAString & aCssText) override; \
  NS_IMETHOD GetPropertyValue(const nsAString & propertyName, nsAString & _retval) override; \
  NS_IMETHOD GetPropertyCSSValue(const nsAString & propertyName, nsIDOMCSSValue * *_retval) override; \
  NS_IMETHOD RemoveProperty(const nsAString & propertyName, nsAString & _retval) override; \
  NS_IMETHOD GetPropertyPriority(const nsAString & propertyName, nsAString & _retval) override; \
  NS_IMETHOD SetProperty(const nsAString & propertyName, const nsAString & value, const nsAString & priority) override; \
  NS_IMETHOD GetLength(uint32_t *aLength) override; \
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) override; \
  NS_IMETHOD GetParentRule(nsIDOMCSSRule * *aParentRule) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSSTYLEDECLARATION(_to) \
  NS_IMETHOD GetCssText(nsAString & aCssText) override { return _to GetCssText(aCssText); } \
  NS_IMETHOD SetCssText(const nsAString & aCssText) override { return _to SetCssText(aCssText); } \
  NS_IMETHOD GetPropertyValue(const nsAString & propertyName, nsAString & _retval) override { return _to GetPropertyValue(propertyName, _retval); } \
  NS_IMETHOD GetPropertyCSSValue(const nsAString & propertyName, nsIDOMCSSValue * *_retval) override { return _to GetPropertyCSSValue(propertyName, _retval); } \
  NS_IMETHOD RemoveProperty(const nsAString & propertyName, nsAString & _retval) override { return _to RemoveProperty(propertyName, _retval); } \
  NS_IMETHOD GetPropertyPriority(const nsAString & propertyName, nsAString & _retval) override { return _to GetPropertyPriority(propertyName, _retval); } \
  NS_IMETHOD SetProperty(const nsAString & propertyName, const nsAString & value, const nsAString & priority) override { return _to SetProperty(propertyName, value, priority); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) override { return _to Item(index, _retval); } \
  NS_IMETHOD GetParentRule(nsIDOMCSSRule * *aParentRule) override { return _to GetParentRule(aParentRule); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSSTYLEDECLARATION(_to) \
  NS_IMETHOD GetCssText(nsAString & aCssText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCssText(aCssText); } \
  NS_IMETHOD SetCssText(const nsAString & aCssText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCssText(aCssText); } \
  NS_IMETHOD GetPropertyValue(const nsAString & propertyName, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyValue(propertyName, _retval); } \
  NS_IMETHOD GetPropertyCSSValue(const nsAString & propertyName, nsIDOMCSSValue * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyCSSValue(propertyName, _retval); } \
  NS_IMETHOD RemoveProperty(const nsAString & propertyName, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveProperty(propertyName, _retval); } \
  NS_IMETHOD GetPropertyPriority(const nsAString & propertyName, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyPriority(propertyName, _retval); } \
  NS_IMETHOD SetProperty(const nsAString & propertyName, const nsAString & value, const nsAString & priority) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProperty(propertyName, value, priority); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD GetParentRule(nsIDOMCSSRule * *aParentRule) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentRule(aParentRule); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSStyleDeclaration : public nsIDOMCSSStyleDeclaration
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSSTYLEDECLARATION

  nsDOMCSSStyleDeclaration();

private:
  ~nsDOMCSSStyleDeclaration();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCSSStyleDeclaration, nsIDOMCSSStyleDeclaration)

nsDOMCSSStyleDeclaration::nsDOMCSSStyleDeclaration()
{
  /* member initializers and constructor code */
}

nsDOMCSSStyleDeclaration::~nsDOMCSSStyleDeclaration()
{
  /* destructor code */
}

/* attribute DOMString cssText; */
NS_IMETHODIMP nsDOMCSSStyleDeclaration::GetCssText(nsAString & aCssText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSStyleDeclaration::SetCssText(const nsAString & aCssText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getPropertyValue (in DOMString propertyName); */
NS_IMETHODIMP nsDOMCSSStyleDeclaration::GetPropertyValue(const nsAString & propertyName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCSSValue getPropertyCSSValue (in DOMString propertyName); */
NS_IMETHODIMP nsDOMCSSStyleDeclaration::GetPropertyCSSValue(const nsAString & propertyName, nsIDOMCSSValue * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString removeProperty (in DOMString propertyName) raises (DOMException); */
NS_IMETHODIMP nsDOMCSSStyleDeclaration::RemoveProperty(const nsAString & propertyName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getPropertyPriority (in DOMString propertyName); */
NS_IMETHODIMP nsDOMCSSStyleDeclaration::GetPropertyPriority(const nsAString & propertyName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setProperty (in DOMString propertyName, in DOMString value, [optional] in DOMString priority) raises (DOMException); */
NS_IMETHODIMP nsDOMCSSStyleDeclaration::SetProperty(const nsAString & propertyName, const nsAString & value, const nsAString & priority)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMCSSStyleDeclaration::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString item (in unsigned long index); */
NS_IMETHODIMP nsDOMCSSStyleDeclaration::Item(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSRule parentRule; */
NS_IMETHODIMP nsDOMCSSStyleDeclaration::GetParentRule(nsIDOMCSSRule * *aParentRule)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSStyleDeclaration_h__ */
