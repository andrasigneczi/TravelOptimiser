/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSImportRule.idl
 */

#ifndef __gen_nsIDOMCSSImportRule_h__
#define __gen_nsIDOMCSSImportRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSImportRule */
#define NS_IDOMCSSIMPORTRULE_IID_STR "d3b2b914-01ef-4663-beda-a6475a26f491"

#define NS_IDOMCSSIMPORTRULE_IID \
  {0xd3b2b914, 0x01ef, 0x4663, \
    { 0xbe, 0xda, 0xa6, 0x47, 0x5a, 0x26, 0xf4, 0x91 }}

class NS_NO_VTABLE nsIDOMCSSImportRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSIMPORTRULE_IID)

  /* readonly attribute DOMString href; */
  NS_IMETHOD GetHref(nsAString & aHref) = 0;

  /* readonly attribute nsIDOMMediaList media; */
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) = 0;

  /* readonly attribute nsIDOMCSSStyleSheet styleSheet; */
  NS_IMETHOD GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSImportRule, NS_IDOMCSSIMPORTRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSIMPORTRULE \
  NS_IMETHOD GetHref(nsAString & aHref) override; \
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) override; \
  NS_IMETHOD GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSIMPORTRULE(_to) \
  NS_IMETHOD GetHref(nsAString & aHref) override { return _to GetHref(aHref); } \
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) override { return _to GetMedia(aMedia); } \
  NS_IMETHOD GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet) override { return _to GetStyleSheet(aStyleSheet); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSIMPORTRULE(_to) \
  NS_IMETHOD GetHref(nsAString & aHref) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } \
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_IMETHOD GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleSheet(aStyleSheet); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSImportRule : public nsIDOMCSSImportRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSIMPORTRULE

  nsDOMCSSImportRule();

private:
  ~nsDOMCSSImportRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCSSImportRule, nsIDOMCSSImportRule)

nsDOMCSSImportRule::nsDOMCSSImportRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSImportRule::~nsDOMCSSImportRule()
{
  /* destructor code */
}

/* readonly attribute DOMString href; */
NS_IMETHODIMP nsDOMCSSImportRule::GetHref(nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMMediaList media; */
NS_IMETHODIMP nsDOMCSSImportRule::GetMedia(nsIDOMMediaList * *aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSStyleSheet styleSheet; */
NS_IMETHODIMP nsDOMCSSImportRule::GetStyleSheet(nsIDOMCSSStyleSheet * *aStyleSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSImportRule_h__ */
