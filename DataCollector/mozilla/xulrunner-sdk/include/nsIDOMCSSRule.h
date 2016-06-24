/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSRule.idl
 */

#ifndef __gen_nsIDOMCSSRule_h__
#define __gen_nsIDOMCSSRule_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace mozilla {
namespace css {
class Rule;
}
}

/* starting interface:    nsIDOMCSSRule */
#define NS_IDOMCSSRULE_IID_STR "4d6b3bad-f53c-4585-82f6-62982e27ede8"

#define NS_IDOMCSSRULE_IID \
  {0x4d6b3bad, 0xf53c, 0x4585, \
    { 0x82, 0xf6, 0x62, 0x98, 0x2e, 0x27, 0xed, 0xe8 }}

class NS_NO_VTABLE nsIDOMCSSRule : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSRULE_IID)

  enum {
    UNKNOWN_RULE = 0U,
    STYLE_RULE = 1U,
    CHARSET_RULE = 2U,
    IMPORT_RULE = 3U,
    MEDIA_RULE = 4U,
    FONT_FACE_RULE = 5U,
    PAGE_RULE = 6U,
    KEYFRAMES_RULE = 7U,
    KEYFRAME_RULE = 8U,
    MOZ_KEYFRAMES_RULE = 7U,
    MOZ_KEYFRAME_RULE = 8U,
    NAMESPACE_RULE = 10U,
    COUNTER_STYLE_RULE = 11U,
    SUPPORTS_RULE = 12U,
    FONT_FEATURE_VALUES_RULE = 14U
  };

  /* readonly attribute unsigned short type; */
  NS_IMETHOD GetType(uint16_t *aType) = 0;

  /* attribute DOMString cssText; */
  NS_IMETHOD GetCssText(nsAString & aCssText) = 0;
  NS_IMETHOD SetCssText(const nsAString & aCssText) = 0;

  /* readonly attribute nsIDOMCSSStyleSheet parentStyleSheet; */
  NS_IMETHOD GetParentStyleSheet(nsIDOMCSSStyleSheet * *aParentStyleSheet) = 0;

  /* readonly attribute nsIDOMCSSRule parentRule; */
  NS_IMETHOD GetParentRule(nsIDOMCSSRule * *aParentRule) = 0;

  /* [noscript,nostdcall,notxpcom] Rule getCSSRule (); */
  virtual mozilla::css::Rule * GetCSSRule(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSRule, NS_IDOMCSSRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSRULE \
  NS_IMETHOD GetType(uint16_t *aType) override; \
  NS_IMETHOD GetCssText(nsAString & aCssText) override; \
  NS_IMETHOD SetCssText(const nsAString & aCssText) override; \
  NS_IMETHOD GetParentStyleSheet(nsIDOMCSSStyleSheet * *aParentStyleSheet) override; \
  NS_IMETHOD GetParentRule(nsIDOMCSSRule * *aParentRule) override; \
  virtual mozilla::css::Rule * GetCSSRule(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSRULE(_to) \
  NS_IMETHOD GetType(uint16_t *aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetCssText(nsAString & aCssText) override { return _to GetCssText(aCssText); } \
  NS_IMETHOD SetCssText(const nsAString & aCssText) override { return _to SetCssText(aCssText); } \
  NS_IMETHOD GetParentStyleSheet(nsIDOMCSSStyleSheet * *aParentStyleSheet) override { return _to GetParentStyleSheet(aParentStyleSheet); } \
  NS_IMETHOD GetParentRule(nsIDOMCSSRule * *aParentRule) override { return _to GetParentRule(aParentRule); } \
  virtual mozilla::css::Rule * GetCSSRule(void) override { return _to GetCSSRule(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSRULE(_to) \
  NS_IMETHOD GetType(uint16_t *aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetCssText(nsAString & aCssText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCssText(aCssText); } \
  NS_IMETHOD SetCssText(const nsAString & aCssText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCssText(aCssText); } \
  NS_IMETHOD GetParentStyleSheet(nsIDOMCSSStyleSheet * *aParentStyleSheet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentStyleSheet(aParentStyleSheet); } \
  NS_IMETHOD GetParentRule(nsIDOMCSSRule * *aParentRule) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentRule(aParentRule); } \
  virtual mozilla::css::Rule * GetCSSRule(void) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSRule : public nsIDOMCSSRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSRULE

  nsDOMCSSRule();

private:
  ~nsDOMCSSRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCSSRule, nsIDOMCSSRule)

nsDOMCSSRule::nsDOMCSSRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSRule::~nsDOMCSSRule()
{
  /* destructor code */
}

/* readonly attribute unsigned short type; */
NS_IMETHODIMP nsDOMCSSRule::GetType(uint16_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString cssText; */
NS_IMETHODIMP nsDOMCSSRule::GetCssText(nsAString & aCssText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSRule::SetCssText(const nsAString & aCssText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSStyleSheet parentStyleSheet; */
NS_IMETHODIMP nsDOMCSSRule::GetParentStyleSheet(nsIDOMCSSStyleSheet * *aParentStyleSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCSSRule parentRule; */
NS_IMETHODIMP nsDOMCSSRule::GetParentRule(nsIDOMCSSRule * *aParentRule)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] Rule getCSSRule (); */
mozilla::css::Rule * nsDOMCSSRule::GetCSSRule()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSRule_h__ */
