/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLLinkElement.idl
 */

#ifndef __gen_nsIDOMHTMLLinkElement_h__
#define __gen_nsIDOMHTMLLinkElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLLinkElement */
#define NS_IDOMHTMLLINKELEMENT_IID_STR "ee50b7ab-0015-4fbe-89e0-e3feacd4ffde"

#define NS_IDOMHTMLLINKELEMENT_IID \
  {0xee50b7ab, 0x0015, 0x4fbe, \
    { 0x89, 0xe0, 0xe3, 0xfe, 0xac, 0xd4, 0xff, 0xde }}

class NS_NO_VTABLE nsIDOMHTMLLinkElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLLINKELEMENT_IID)

  /* [binaryname(MozDisabled)] attribute boolean disabled; */
  NS_IMETHOD GetMozDisabled(bool *aDisabled) = 0;
  NS_IMETHOD SetMozDisabled(bool aDisabled) = 0;

  /* attribute DOMString charset; */
  NS_IMETHOD GetCharset(nsAString & aCharset) = 0;
  NS_IMETHOD SetCharset(const nsAString & aCharset) = 0;

  /* attribute DOMString href; */
  NS_IMETHOD GetHref(nsAString & aHref) = 0;
  NS_IMETHOD SetHref(const nsAString & aHref) = 0;

  /* attribute DOMString hreflang; */
  NS_IMETHOD GetHreflang(nsAString & aHreflang) = 0;
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) = 0;

  /* attribute DOMString media; */
  NS_IMETHOD GetMedia(nsAString & aMedia) = 0;
  NS_IMETHOD SetMedia(const nsAString & aMedia) = 0;

  /* attribute DOMString rel; */
  NS_IMETHOD GetRel(nsAString & aRel) = 0;
  NS_IMETHOD SetRel(const nsAString & aRel) = 0;

  /* attribute DOMString rev; */
  NS_IMETHOD GetRev(nsAString & aRev) = 0;
  NS_IMETHOD SetRev(const nsAString & aRev) = 0;

  /* attribute DOMString target; */
  NS_IMETHOD GetTarget(nsAString & aTarget) = 0;
  NS_IMETHOD SetTarget(const nsAString & aTarget) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLLinkElement, NS_IDOMHTMLLINKELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLLINKELEMENT \
  NS_IMETHOD GetMozDisabled(bool *aDisabled) override; \
  NS_IMETHOD SetMozDisabled(bool aDisabled) override; \
  NS_IMETHOD GetCharset(nsAString & aCharset) override; \
  NS_IMETHOD SetCharset(const nsAString & aCharset) override; \
  NS_IMETHOD GetHref(nsAString & aHref) override; \
  NS_IMETHOD SetHref(const nsAString & aHref) override; \
  NS_IMETHOD GetHreflang(nsAString & aHreflang) override; \
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) override; \
  NS_IMETHOD GetMedia(nsAString & aMedia) override; \
  NS_IMETHOD SetMedia(const nsAString & aMedia) override; \
  NS_IMETHOD GetRel(nsAString & aRel) override; \
  NS_IMETHOD SetRel(const nsAString & aRel) override; \
  NS_IMETHOD GetRev(nsAString & aRev) override; \
  NS_IMETHOD SetRev(const nsAString & aRev) override; \
  NS_IMETHOD GetTarget(nsAString & aTarget) override; \
  NS_IMETHOD SetTarget(const nsAString & aTarget) override; \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD SetType(const nsAString & aType) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLLINKELEMENT(_to) \
  NS_IMETHOD GetMozDisabled(bool *aDisabled) override { return _to GetMozDisabled(aDisabled); } \
  NS_IMETHOD SetMozDisabled(bool aDisabled) override { return _to SetMozDisabled(aDisabled); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) override { return _to GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) override { return _to SetCharset(aCharset); } \
  NS_IMETHOD GetHref(nsAString & aHref) override { return _to GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) override { return _to SetHref(aHref); } \
  NS_IMETHOD GetHreflang(nsAString & aHreflang) override { return _to GetHreflang(aHreflang); } \
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) override { return _to SetHreflang(aHreflang); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) override { return _to GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) override { return _to SetMedia(aMedia); } \
  NS_IMETHOD GetRel(nsAString & aRel) override { return _to GetRel(aRel); } \
  NS_IMETHOD SetRel(const nsAString & aRel) override { return _to SetRel(aRel); } \
  NS_IMETHOD GetRev(nsAString & aRev) override { return _to GetRev(aRev); } \
  NS_IMETHOD SetRev(const nsAString & aRev) override { return _to SetRev(aRev); } \
  NS_IMETHOD GetTarget(nsAString & aTarget) override { return _to GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const nsAString & aTarget) override { return _to SetTarget(aTarget); } \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return _to SetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLLINKELEMENT(_to) \
  NS_IMETHOD GetMozDisabled(bool *aDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozDisabled(aDisabled); } \
  NS_IMETHOD SetMozDisabled(bool aDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozDisabled(aDisabled); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } \
  NS_IMETHOD GetHref(nsAString & aHref) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHref(aHref); } \
  NS_IMETHOD GetHreflang(nsAString & aHreflang) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHreflang(aHreflang); } \
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHreflang(aHreflang); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMedia(aMedia); } \
  NS_IMETHOD GetRel(nsAString & aRel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRel(aRel); } \
  NS_IMETHOD SetRel(const nsAString & aRel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRel(aRel); } \
  NS_IMETHOD GetRev(nsAString & aRev) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRev(aRev); } \
  NS_IMETHOD SetRev(const nsAString & aRev) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRev(aRev); } \
  NS_IMETHOD GetTarget(nsAString & aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const nsAString & aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget); } \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLLinkElement : public nsIDOMHTMLLinkElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLLINKELEMENT

  nsDOMHTMLLinkElement();

private:
  ~nsDOMHTMLLinkElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMHTMLLinkElement, nsIDOMHTMLLinkElement)

nsDOMHTMLLinkElement::nsDOMHTMLLinkElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLLinkElement::~nsDOMHTMLLinkElement()
{
  /* destructor code */
}

/* [binaryname(MozDisabled)] attribute boolean disabled; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetMozDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetMozDisabled(bool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString charset; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetCharset(nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetCharset(const nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString href; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetHref(nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetHref(const nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hreflang; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetHreflang(nsAString & aHreflang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetHreflang(const nsAString & aHreflang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString media; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetMedia(nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetMedia(const nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString rel; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetRel(nsAString & aRel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetRel(const nsAString & aRel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString rev; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetRev(nsAString & aRev)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetRev(const nsAString & aRev)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString target; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetTarget(nsAString & aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetTarget(const nsAString & aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLLinkElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLLinkElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLLinkElement_h__ */
