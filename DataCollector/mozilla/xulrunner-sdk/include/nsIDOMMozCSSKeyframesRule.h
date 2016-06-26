/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMozCSSKeyframesRule.idl
 */

#ifndef __gen_nsIDOMMozCSSKeyframesRule_h__
#define __gen_nsIDOMMozCSSKeyframesRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozCSSKeyframesRule */
#define NS_IDOMMOZCSSKEYFRAMESRULE_IID_STR "400f4b70-ad0a-4047-aba4-ee8019f6b907"

#define NS_IDOMMOZCSSKEYFRAMESRULE_IID \
  {0x400f4b70, 0xad0a, 0x4047, \
    { 0xab, 0xa4, 0xee, 0x80, 0x19, 0xf6, 0xb9, 0x07 }}

class NS_NO_VTABLE nsIDOMMozCSSKeyframesRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZCSSKEYFRAMESRULE_IID)

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* readonly attribute nsIDOMCSSRuleList cssRules; */
  NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) = 0;

  /* void appendRule (in DOMString rule); */
  NS_IMETHOD AppendRule(const nsAString & rule) = 0;

  /* void deleteRule (in DOMString key); */
  NS_IMETHOD DeleteRule(const nsAString & key) = 0;

  /* nsIDOMMozCSSKeyframeRule findRule (in DOMString key); */
  NS_IMETHOD FindRule(const nsAString & key, nsIDOMMozCSSKeyframeRule * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozCSSKeyframesRule, NS_IDOMMOZCSSKEYFRAMESRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZCSSKEYFRAMESRULE \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD SetName(const nsAString & aName) override; \
  NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) override; \
  NS_IMETHOD AppendRule(const nsAString & rule) override; \
  NS_IMETHOD DeleteRule(const nsAString & key) override; \
  NS_IMETHOD FindRule(const nsAString & key, nsIDOMMozCSSKeyframeRule * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZCSSKEYFRAMESRULE(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return _to SetName(aName); } \
  NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) override { return _to GetCssRules(aCssRules); } \
  NS_IMETHOD AppendRule(const nsAString & rule) override { return _to AppendRule(rule); } \
  NS_IMETHOD DeleteRule(const nsAString & key) override { return _to DeleteRule(key); } \
  NS_IMETHOD FindRule(const nsAString & key, nsIDOMMozCSSKeyframeRule * *_retval) override { return _to FindRule(key, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZCSSKEYFRAMESRULE(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCssRules(aCssRules); } \
  NS_IMETHOD AppendRule(const nsAString & rule) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendRule(rule); } \
  NS_IMETHOD DeleteRule(const nsAString & key) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteRule(key); } \
  NS_IMETHOD FindRule(const nsAString & key, nsIDOMMozCSSKeyframeRule * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindRule(key, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozCSSKeyframesRule : public nsIDOMMozCSSKeyframesRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZCSSKEYFRAMESRULE

  nsDOMMozCSSKeyframesRule();

private:
  ~nsDOMMozCSSKeyframesRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMMozCSSKeyframesRule, nsIDOMMozCSSKeyframesRule)

nsDOMMozCSSKeyframesRule::nsDOMMozCSSKeyframesRule()
{
  /* member initializers and constructor code */
}

nsDOMMozCSSKeyframesRule::~nsDOMMozCSSKeyframesRule()
{
  /* destructor code */
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMMozCSSKeyframesRule::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozCSSKeyframesRule::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSRuleList cssRules; */
NS_IMETHODIMP nsDOMMozCSSKeyframesRule::GetCssRules(nsIDOMCSSRuleList * *aCssRules)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendRule (in DOMString rule); */
NS_IMETHODIMP nsDOMMozCSSKeyframesRule::AppendRule(const nsAString & rule)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteRule (in DOMString key); */
NS_IMETHODIMP nsDOMMozCSSKeyframesRule::DeleteRule(const nsAString & key)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMozCSSKeyframeRule findRule (in DOMString key); */
NS_IMETHODIMP nsDOMMozCSSKeyframesRule::FindRule(const nsAString & key, nsIDOMMozCSSKeyframeRule * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozCSSKeyframesRule_h__ */
