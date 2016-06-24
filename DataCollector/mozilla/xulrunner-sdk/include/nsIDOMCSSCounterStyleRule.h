/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSCounterStyleRule.idl
 */

#ifndef __gen_nsIDOMCSSCounterStyleRule_h__
#define __gen_nsIDOMCSSCounterStyleRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSCounterStyleRule */
#define NS_IDOMCSSCOUNTERSTYLERULE_IID_STR "9b5e48ce-d84c-4e31-aff5-34e9f4141313"

#define NS_IDOMCSSCOUNTERSTYLERULE_IID \
  {0x9b5e48ce, 0xd84c, 0x4e31, \
    { 0xaf, 0xf5, 0x34, 0xe9, 0xf4, 0x14, 0x13, 0x13 }}

class NS_NO_VTABLE nsIDOMCSSCounterStyleRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSCOUNTERSTYLERULE_IID)

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute DOMString system; */
  NS_IMETHOD GetSystem(nsAString & aSystem) = 0;
  NS_IMETHOD SetSystem(const nsAString & aSystem) = 0;

  /* attribute DOMString symbols; */
  NS_IMETHOD GetSymbols(nsAString & aSymbols) = 0;
  NS_IMETHOD SetSymbols(const nsAString & aSymbols) = 0;

  /* attribute DOMString additiveSymbols; */
  NS_IMETHOD GetAdditiveSymbols(nsAString & aAdditiveSymbols) = 0;
  NS_IMETHOD SetAdditiveSymbols(const nsAString & aAdditiveSymbols) = 0;

  /* attribute DOMString negative; */
  NS_IMETHOD GetNegative(nsAString & aNegative) = 0;
  NS_IMETHOD SetNegative(const nsAString & aNegative) = 0;

  /* attribute DOMString prefix; */
  NS_IMETHOD GetPrefix(nsAString & aPrefix) = 0;
  NS_IMETHOD SetPrefix(const nsAString & aPrefix) = 0;

  /* attribute DOMString suffix; */
  NS_IMETHOD GetSuffix(nsAString & aSuffix) = 0;
  NS_IMETHOD SetSuffix(const nsAString & aSuffix) = 0;

  /* attribute DOMString range; */
  NS_IMETHOD GetRange(nsAString & aRange) = 0;
  NS_IMETHOD SetRange(const nsAString & aRange) = 0;

  /* attribute DOMString pad; */
  NS_IMETHOD GetPad(nsAString & aPad) = 0;
  NS_IMETHOD SetPad(const nsAString & aPad) = 0;

  /* attribute DOMString speakAs; */
  NS_IMETHOD GetSpeakAs(nsAString & aSpeakAs) = 0;
  NS_IMETHOD SetSpeakAs(const nsAString & aSpeakAs) = 0;

  /* attribute DOMString fallback; */
  NS_IMETHOD GetFallback(nsAString & aFallback) = 0;
  NS_IMETHOD SetFallback(const nsAString & aFallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSCounterStyleRule, NS_IDOMCSSCOUNTERSTYLERULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSCOUNTERSTYLERULE \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD SetName(const nsAString & aName) override; \
  NS_IMETHOD GetSystem(nsAString & aSystem) override; \
  NS_IMETHOD SetSystem(const nsAString & aSystem) override; \
  NS_IMETHOD GetSymbols(nsAString & aSymbols) override; \
  NS_IMETHOD SetSymbols(const nsAString & aSymbols) override; \
  NS_IMETHOD GetAdditiveSymbols(nsAString & aAdditiveSymbols) override; \
  NS_IMETHOD SetAdditiveSymbols(const nsAString & aAdditiveSymbols) override; \
  NS_IMETHOD GetNegative(nsAString & aNegative) override; \
  NS_IMETHOD SetNegative(const nsAString & aNegative) override; \
  NS_IMETHOD GetPrefix(nsAString & aPrefix) override; \
  NS_IMETHOD SetPrefix(const nsAString & aPrefix) override; \
  NS_IMETHOD GetSuffix(nsAString & aSuffix) override; \
  NS_IMETHOD SetSuffix(const nsAString & aSuffix) override; \
  NS_IMETHOD GetRange(nsAString & aRange) override; \
  NS_IMETHOD SetRange(const nsAString & aRange) override; \
  NS_IMETHOD GetPad(nsAString & aPad) override; \
  NS_IMETHOD SetPad(const nsAString & aPad) override; \
  NS_IMETHOD GetSpeakAs(nsAString & aSpeakAs) override; \
  NS_IMETHOD SetSpeakAs(const nsAString & aSpeakAs) override; \
  NS_IMETHOD GetFallback(nsAString & aFallback) override; \
  NS_IMETHOD SetFallback(const nsAString & aFallback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSCOUNTERSTYLERULE(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return _to SetName(aName); } \
  NS_IMETHOD GetSystem(nsAString & aSystem) override { return _to GetSystem(aSystem); } \
  NS_IMETHOD SetSystem(const nsAString & aSystem) override { return _to SetSystem(aSystem); } \
  NS_IMETHOD GetSymbols(nsAString & aSymbols) override { return _to GetSymbols(aSymbols); } \
  NS_IMETHOD SetSymbols(const nsAString & aSymbols) override { return _to SetSymbols(aSymbols); } \
  NS_IMETHOD GetAdditiveSymbols(nsAString & aAdditiveSymbols) override { return _to GetAdditiveSymbols(aAdditiveSymbols); } \
  NS_IMETHOD SetAdditiveSymbols(const nsAString & aAdditiveSymbols) override { return _to SetAdditiveSymbols(aAdditiveSymbols); } \
  NS_IMETHOD GetNegative(nsAString & aNegative) override { return _to GetNegative(aNegative); } \
  NS_IMETHOD SetNegative(const nsAString & aNegative) override { return _to SetNegative(aNegative); } \
  NS_IMETHOD GetPrefix(nsAString & aPrefix) override { return _to GetPrefix(aPrefix); } \
  NS_IMETHOD SetPrefix(const nsAString & aPrefix) override { return _to SetPrefix(aPrefix); } \
  NS_IMETHOD GetSuffix(nsAString & aSuffix) override { return _to GetSuffix(aSuffix); } \
  NS_IMETHOD SetSuffix(const nsAString & aSuffix) override { return _to SetSuffix(aSuffix); } \
  NS_IMETHOD GetRange(nsAString & aRange) override { return _to GetRange(aRange); } \
  NS_IMETHOD SetRange(const nsAString & aRange) override { return _to SetRange(aRange); } \
  NS_IMETHOD GetPad(nsAString & aPad) override { return _to GetPad(aPad); } \
  NS_IMETHOD SetPad(const nsAString & aPad) override { return _to SetPad(aPad); } \
  NS_IMETHOD GetSpeakAs(nsAString & aSpeakAs) override { return _to GetSpeakAs(aSpeakAs); } \
  NS_IMETHOD SetSpeakAs(const nsAString & aSpeakAs) override { return _to SetSpeakAs(aSpeakAs); } \
  NS_IMETHOD GetFallback(nsAString & aFallback) override { return _to GetFallback(aFallback); } \
  NS_IMETHOD SetFallback(const nsAString & aFallback) override { return _to SetFallback(aFallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSCOUNTERSTYLERULE(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetSystem(nsAString & aSystem) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystem(aSystem); } \
  NS_IMETHOD SetSystem(const nsAString & aSystem) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSystem(aSystem); } \
  NS_IMETHOD GetSymbols(nsAString & aSymbols) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSymbols(aSymbols); } \
  NS_IMETHOD SetSymbols(const nsAString & aSymbols) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSymbols(aSymbols); } \
  NS_IMETHOD GetAdditiveSymbols(nsAString & aAdditiveSymbols) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdditiveSymbols(aAdditiveSymbols); } \
  NS_IMETHOD SetAdditiveSymbols(const nsAString & aAdditiveSymbols) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAdditiveSymbols(aAdditiveSymbols); } \
  NS_IMETHOD GetNegative(nsAString & aNegative) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNegative(aNegative); } \
  NS_IMETHOD SetNegative(const nsAString & aNegative) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNegative(aNegative); } \
  NS_IMETHOD GetPrefix(nsAString & aPrefix) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefix(aPrefix); } \
  NS_IMETHOD SetPrefix(const nsAString & aPrefix) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrefix(aPrefix); } \
  NS_IMETHOD GetSuffix(nsAString & aSuffix) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuffix(aSuffix); } \
  NS_IMETHOD SetSuffix(const nsAString & aSuffix) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSuffix(aSuffix); } \
  NS_IMETHOD GetRange(nsAString & aRange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRange(aRange); } \
  NS_IMETHOD SetRange(const nsAString & aRange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRange(aRange); } \
  NS_IMETHOD GetPad(nsAString & aPad) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPad(aPad); } \
  NS_IMETHOD SetPad(const nsAString & aPad) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPad(aPad); } \
  NS_IMETHOD GetSpeakAs(nsAString & aSpeakAs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpeakAs(aSpeakAs); } \
  NS_IMETHOD SetSpeakAs(const nsAString & aSpeakAs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpeakAs(aSpeakAs); } \
  NS_IMETHOD GetFallback(nsAString & aFallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFallback(aFallback); } \
  NS_IMETHOD SetFallback(const nsAString & aFallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFallback(aFallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSCounterStyleRule : public nsIDOMCSSCounterStyleRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSCOUNTERSTYLERULE

  nsDOMCSSCounterStyleRule();

private:
  ~nsDOMCSSCounterStyleRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCSSCounterStyleRule, nsIDOMCSSCounterStyleRule)

nsDOMCSSCounterStyleRule::nsDOMCSSCounterStyleRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSCounterStyleRule::~nsDOMCSSCounterStyleRule()
{
  /* destructor code */
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString system; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetSystem(nsAString & aSystem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetSystem(const nsAString & aSystem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString symbols; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetSymbols(nsAString & aSymbols)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetSymbols(const nsAString & aSymbols)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString additiveSymbols; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetAdditiveSymbols(nsAString & aAdditiveSymbols)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetAdditiveSymbols(const nsAString & aAdditiveSymbols)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString negative; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetNegative(nsAString & aNegative)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetNegative(const nsAString & aNegative)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString prefix; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetPrefix(nsAString & aPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetPrefix(const nsAString & aPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString suffix; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetSuffix(nsAString & aSuffix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetSuffix(const nsAString & aSuffix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString range; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetRange(nsAString & aRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetRange(const nsAString & aRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString pad; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetPad(nsAString & aPad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetPad(const nsAString & aPad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString speakAs; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetSpeakAs(nsAString & aSpeakAs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetSpeakAs(const nsAString & aSpeakAs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString fallback; */
NS_IMETHODIMP nsDOMCSSCounterStyleRule::GetFallback(nsAString & aFallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMCSSCounterStyleRule::SetFallback(const nsAString & aFallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSCounterStyleRule_h__ */
