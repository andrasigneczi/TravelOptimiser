/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSStyleRule.idl
 */

#ifndef __gen_nsIDOMCSSStyleRule_h__
#define __gen_nsIDOMCSSStyleRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSStyleRule */
#define NS_IDOMCSSSTYLERULE_IID_STR "b5e9af48-a7c2-4f88-aae3-58307af4b5a5"

#define NS_IDOMCSSSTYLERULE_IID \
  {0xb5e9af48, 0xa7c2, 0x4f88, \
    { 0xaa, 0xe3, 0x58, 0x30, 0x7a, 0xf4, 0xb5, 0xa5 }}

class NS_NO_VTABLE nsIDOMCSSStyleRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSSTYLERULE_IID)

  /* attribute DOMString selectorText; */
  NS_IMETHOD GetSelectorText(nsAString & aSelectorText) = 0;
  NS_IMETHOD SetSelectorText(const nsAString & aSelectorText) = 0;

  /* readonly attribute nsIDOMCSSStyleDeclaration style; */
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSStyleRule, NS_IDOMCSSSTYLERULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSSTYLERULE \
  NS_IMETHOD GetSelectorText(nsAString & aSelectorText) override; \
  NS_IMETHOD SetSelectorText(const nsAString & aSelectorText) override; \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSSTYLERULE(_to) \
  NS_IMETHOD GetSelectorText(nsAString & aSelectorText) override { return _to GetSelectorText(aSelectorText); } \
  NS_IMETHOD SetSelectorText(const nsAString & aSelectorText) override { return _to SetSelectorText(aSelectorText); } \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) override { return _to GetStyle(aStyle); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSSTYLERULE(_to) \
  NS_IMETHOD GetSelectorText(nsAString & aSelectorText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectorText(aSelectorText); } \
  NS_IMETHOD SetSelectorText(const nsAString & aSelectorText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectorText(aSelectorText); } \
  NS_IMETHOD GetStyle(nsIDOMCSSStyleDeclaration * *aStyle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyle(aStyle); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSStyleRule : public nsIDOMCSSStyleRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSSTYLERULE

  nsDOMCSSStyleRule();

private:
  ~nsDOMCSSStyleRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCSSStyleRule, nsIDOMCSSStyleRule)

nsDOMCSSStyleRule::nsDOMCSSStyleRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSStyleRule::~nsDOMCSSStyleRule()
{
  /* destructor code */
}

/* attribute DOMString selectorText; */
NS_IMETHODIMP nsDOMCSSStyleRule::GetSelectorText(nsAString & aSelectorText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSStyleRule::SetSelectorText(const nsAString & aSelectorText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSStyleDeclaration style; */
NS_IMETHODIMP nsDOMCSSStyleRule::GetStyle(nsIDOMCSSStyleDeclaration * *aStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSStyleRule_h__ */
