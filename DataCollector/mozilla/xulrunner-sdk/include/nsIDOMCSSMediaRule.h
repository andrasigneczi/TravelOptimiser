/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSMediaRule.idl
 */

#ifndef __gen_nsIDOMCSSMediaRule_h__
#define __gen_nsIDOMCSSMediaRule_h__


#ifndef __gen_nsIDOMCSSConditionRule_h__
#include "nsIDOMCSSConditionRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSMediaRule */
#define NS_IDOMCSSMEDIARULE_IID_STR "6cf9c5b2-fa0f-43c0-aa50-ef85b4756e3a"

#define NS_IDOMCSSMEDIARULE_IID \
  {0x6cf9c5b2, 0xfa0f, 0x43c0, \
    { 0xaa, 0x50, 0xef, 0x85, 0xb4, 0x75, 0x6e, 0x3a }}

class NS_NO_VTABLE nsIDOMCSSMediaRule : public nsIDOMCSSConditionRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSMEDIARULE_IID)

  /* readonly attribute nsIDOMMediaList media; */
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSMediaRule, NS_IDOMCSSMEDIARULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSMEDIARULE \
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSMEDIARULE(_to) \
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) override { return _to GetMedia(aMedia); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSMEDIARULE(_to) \
  NS_IMETHOD GetMedia(nsIDOMMediaList * *aMedia) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSMediaRule : public nsIDOMCSSMediaRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSMEDIARULE

  nsDOMCSSMediaRule();

private:
  ~nsDOMCSSMediaRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCSSMediaRule, nsIDOMCSSMediaRule)

nsDOMCSSMediaRule::nsDOMCSSMediaRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSMediaRule::~nsDOMCSSMediaRule()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMediaList media; */
NS_IMETHODIMP nsDOMCSSMediaRule::GetMedia(nsIDOMMediaList * *aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSMediaRule_h__ */
