/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSGroupingRule.idl
 */

#ifndef __gen_nsIDOMCSSGroupingRule_h__
#define __gen_nsIDOMCSSGroupingRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSGroupingRule */
#define NS_IDOMCSSGROUPINGRULE_IID_STR "a0e3324a-f911-4baf-9591-5322c76cbb0d"

#define NS_IDOMCSSGROUPINGRULE_IID \
  {0xa0e3324a, 0xf911, 0x4baf, \
    { 0x95, 0x91, 0x53, 0x22, 0xc7, 0x6c, 0xbb, 0x0d }}

class NS_NO_VTABLE nsIDOMCSSGroupingRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSGROUPINGRULE_IID)

  /* readonly attribute nsIDOMCSSRuleList cssRules; */
  NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) = 0;

  /* unsigned long insertRule (in DOMString rule, in unsigned long index) raises (DOMException); */
  NS_IMETHOD InsertRule(const nsAString & rule, uint32_t index, uint32_t *_retval) = 0;

  /* void deleteRule (in unsigned long index) raises (DOMException); */
  NS_IMETHOD DeleteRule(uint32_t index) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSGroupingRule, NS_IDOMCSSGROUPINGRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSGROUPINGRULE \
  NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) override; \
  NS_IMETHOD InsertRule(const nsAString & rule, uint32_t index, uint32_t *_retval) override; \
  NS_IMETHOD DeleteRule(uint32_t index) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSGROUPINGRULE(_to) \
  NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) override { return _to GetCssRules(aCssRules); } \
  NS_IMETHOD InsertRule(const nsAString & rule, uint32_t index, uint32_t *_retval) override { return _to InsertRule(rule, index, _retval); } \
  NS_IMETHOD DeleteRule(uint32_t index) override { return _to DeleteRule(index); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSGROUPINGRULE(_to) \
  NS_IMETHOD GetCssRules(nsIDOMCSSRuleList * *aCssRules) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCssRules(aCssRules); } \
  NS_IMETHOD InsertRule(const nsAString & rule, uint32_t index, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertRule(rule, index, _retval); } \
  NS_IMETHOD DeleteRule(uint32_t index) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteRule(index); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSGroupingRule : public nsIDOMCSSGroupingRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSGROUPINGRULE

  nsDOMCSSGroupingRule();

private:
  ~nsDOMCSSGroupingRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCSSGroupingRule, nsIDOMCSSGroupingRule)

nsDOMCSSGroupingRule::nsDOMCSSGroupingRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSGroupingRule::~nsDOMCSSGroupingRule()
{
  /* destructor code */
}

/* readonly attribute nsIDOMCSSRuleList cssRules; */
NS_IMETHODIMP nsDOMCSSGroupingRule::GetCssRules(nsIDOMCSSRuleList * *aCssRules)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long insertRule (in DOMString rule, in unsigned long index) raises (DOMException); */
NS_IMETHODIMP nsDOMCSSGroupingRule::InsertRule(const nsAString & rule, uint32_t index, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteRule (in unsigned long index) raises (DOMException); */
NS_IMETHODIMP nsDOMCSSGroupingRule::DeleteRule(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSGroupingRule_h__ */
