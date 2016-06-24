/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLScriptElement.idl
 */

#ifndef __gen_nsIDOMHTMLScriptElement_h__
#define __gen_nsIDOMHTMLScriptElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLScriptElement */
#define NS_IDOMHTMLSCRIPTELEMENT_IID_STR "fe96dc1c-40e4-4974-9354-e3fce663c3d5"

#define NS_IDOMHTMLSCRIPTELEMENT_IID \
  {0xfe96dc1c, 0x40e4, 0x4974, \
    { 0x93, 0x54, 0xe3, 0xfc, 0xe6, 0x63, 0xc3, 0xd5 }}

class NS_NO_VTABLE nsIDOMHTMLScriptElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLSCRIPTELEMENT_IID)

  /* attribute DOMString src; */
  NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

  /* attribute boolean async; */
  NS_IMETHOD GetAsync(bool *aAsync) = 0;
  NS_IMETHOD SetAsync(bool aAsync) = 0;

  /* attribute boolean defer; */
  NS_IMETHOD GetDefer(bool *aDefer) = 0;
  NS_IMETHOD SetDefer(bool aDefer) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString charset; */
  NS_IMETHOD GetCharset(nsAString & aCharset) = 0;
  NS_IMETHOD SetCharset(const nsAString & aCharset) = 0;

  /* attribute DOMString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;
  NS_IMETHOD SetText(const nsAString & aText) = 0;

  /* attribute DOMString htmlFor; */
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) = 0;
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) = 0;

  /* attribute DOMString event; */
  NS_IMETHOD GetEvent(nsAString & aEvent) = 0;
  NS_IMETHOD SetEvent(const nsAString & aEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLScriptElement, NS_IDOMHTMLSCRIPTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLSCRIPTELEMENT \
  NS_IMETHOD GetSrc(nsAString & aSrc) override; \
  NS_IMETHOD SetSrc(const nsAString & aSrc) override; \
  NS_IMETHOD GetAsync(bool *aAsync) override; \
  NS_IMETHOD SetAsync(bool aAsync) override; \
  NS_IMETHOD GetDefer(bool *aDefer) override; \
  NS_IMETHOD SetDefer(bool aDefer) override; \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD SetType(const nsAString & aType) override; \
  NS_IMETHOD GetCharset(nsAString & aCharset) override; \
  NS_IMETHOD SetCharset(const nsAString & aCharset) override; \
  NS_IMETHOD GetText(nsAString & aText) override; \
  NS_IMETHOD SetText(const nsAString & aText) override; \
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) override; \
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) override; \
  NS_IMETHOD GetEvent(nsAString & aEvent) override; \
  NS_IMETHOD SetEvent(const nsAString & aEvent) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLSCRIPTELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) override { return _to GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) override { return _to SetSrc(aSrc); } \
  NS_IMETHOD GetAsync(bool *aAsync) override { return _to GetAsync(aAsync); } \
  NS_IMETHOD SetAsync(bool aAsync) override { return _to SetAsync(aAsync); } \
  NS_IMETHOD GetDefer(bool *aDefer) override { return _to GetDefer(aDefer); } \
  NS_IMETHOD SetDefer(bool aDefer) override { return _to SetDefer(aDefer); } \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return _to SetType(aType); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) override { return _to GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) override { return _to SetCharset(aCharset); } \
  NS_IMETHOD GetText(nsAString & aText) override { return _to GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) override { return _to SetText(aText); } \
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) override { return _to GetHtmlFor(aHtmlFor); } \
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) override { return _to SetHtmlFor(aHtmlFor); } \
  NS_IMETHOD GetEvent(nsAString & aEvent) override { return _to GetEvent(aEvent); } \
  NS_IMETHOD SetEvent(const nsAString & aEvent) override { return _to SetEvent(aEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLSCRIPTELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } \
  NS_IMETHOD GetAsync(bool *aAsync) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsync(aAsync); } \
  NS_IMETHOD SetAsync(bool aAsync) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsync(aAsync); } \
  NS_IMETHOD GetDefer(bool *aDefer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefer(aDefer); } \
  NS_IMETHOD SetDefer(bool aDefer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefer(aDefer); } \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } \
  NS_IMETHOD GetText(nsAString & aText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetText(aText); } \
  NS_IMETHOD GetHtmlFor(nsAString & aHtmlFor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHtmlFor(aHtmlFor); } \
  NS_IMETHOD SetHtmlFor(const nsAString & aHtmlFor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHtmlFor(aHtmlFor); } \
  NS_IMETHOD GetEvent(nsAString & aEvent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvent(aEvent); } \
  NS_IMETHOD SetEvent(const nsAString & aEvent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEvent(aEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLScriptElement : public nsIDOMHTMLScriptElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLSCRIPTELEMENT

  nsDOMHTMLScriptElement();

private:
  ~nsDOMHTMLScriptElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMHTMLScriptElement, nsIDOMHTMLScriptElement)

nsDOMHTMLScriptElement::nsDOMHTMLScriptElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLScriptElement::~nsDOMHTMLScriptElement()
{
  /* destructor code */
}

/* attribute DOMString src; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetSrc(nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetSrc(const nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean async; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetAsync(bool *aAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetAsync(bool aAsync)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean defer; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetDefer(bool *aDefer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetDefer(bool aDefer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString charset; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetCharset(nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetCharset(const nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString text; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetText(const nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString htmlFor; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetHtmlFor(nsAString & aHtmlFor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetHtmlFor(const nsAString & aHtmlFor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString event; */
NS_IMETHODIMP nsDOMHTMLScriptElement::GetEvent(nsAString & aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLScriptElement::SetEvent(const nsAString & aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLScriptElement_h__ */
