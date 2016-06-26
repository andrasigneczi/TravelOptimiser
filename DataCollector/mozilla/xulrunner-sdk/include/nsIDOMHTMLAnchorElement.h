/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLAnchorElement.idl
 */

#ifndef __gen_nsIDOMHTMLAnchorElement_h__
#define __gen_nsIDOMHTMLAnchorElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLAnchorElement */
#define NS_IDOMHTMLANCHORELEMENT_IID_STR "339c01c8-2d41-4626-b231-eec63f0241b6"

#define NS_IDOMHTMLANCHORELEMENT_IID \
  {0x339c01c8, 0x2d41, 0x4626, \
    { 0xb2, 0x31, 0xee, 0xc6, 0x3f, 0x02, 0x41, 0xb6 }}

class NS_NO_VTABLE nsIDOMHTMLAnchorElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLANCHORELEMENT_IID)

  /* attribute DOMString href; */
  NS_IMETHOD GetHref(nsAString & aHref) = 0;
  NS_IMETHOD SetHref(const nsAString & aHref) = 0;

  /* attribute DOMString target; */
  NS_IMETHOD GetTarget(nsAString & aTarget) = 0;
  NS_IMETHOD SetTarget(const nsAString & aTarget) = 0;

  /* attribute DOMString ping; */
  NS_IMETHOD GetPing(nsAString & aPing) = 0;
  NS_IMETHOD SetPing(const nsAString & aPing) = 0;

  /* attribute DOMString download; */
  NS_IMETHOD GetDownload(nsAString & aDownload) = 0;
  NS_IMETHOD SetDownload(const nsAString & aDownload) = 0;

  /* attribute DOMString rel; */
  NS_IMETHOD GetRel(nsAString & aRel) = 0;
  NS_IMETHOD SetRel(const nsAString & aRel) = 0;

  /* attribute DOMString hreflang; */
  NS_IMETHOD GetHreflang(nsAString & aHreflang) = 0;
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* [Null(Stringify)] attribute DOMString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;
  NS_IMETHOD SetText(const nsAString & aText) = 0;

  /* attribute DOMString protocol; */
  NS_IMETHOD GetProtocol(nsAString & aProtocol) = 0;
  NS_IMETHOD SetProtocol(const nsAString & aProtocol) = 0;

  /* attribute DOMString host; */
  NS_IMETHOD GetHost(nsAString & aHost) = 0;
  NS_IMETHOD SetHost(const nsAString & aHost) = 0;

  /* attribute DOMString hostname; */
  NS_IMETHOD GetHostname(nsAString & aHostname) = 0;
  NS_IMETHOD SetHostname(const nsAString & aHostname) = 0;

  /* attribute DOMString port; */
  NS_IMETHOD GetPort(nsAString & aPort) = 0;
  NS_IMETHOD SetPort(const nsAString & aPort) = 0;

  /* attribute DOMString pathname; */
  NS_IMETHOD GetPathname(nsAString & aPathname) = 0;
  NS_IMETHOD SetPathname(const nsAString & aPathname) = 0;

  /* attribute DOMString search; */
  NS_IMETHOD GetSearch(nsAString & aSearch) = 0;
  NS_IMETHOD SetSearch(const nsAString & aSearch) = 0;

  /* attribute DOMString hash; */
  NS_IMETHOD GetHash(nsAString & aHash) = 0;
  NS_IMETHOD SetHash(const nsAString & aHash) = 0;

  /* attribute DOMString charset; */
  NS_IMETHOD GetCharset(nsAString & aCharset) = 0;
  NS_IMETHOD SetCharset(const nsAString & aCharset) = 0;

  /* attribute DOMString coords; */
  NS_IMETHOD GetCoords(nsAString & aCoords) = 0;
  NS_IMETHOD SetCoords(const nsAString & aCoords) = 0;

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute DOMString rev; */
  NS_IMETHOD GetRev(nsAString & aRev) = 0;
  NS_IMETHOD SetRev(const nsAString & aRev) = 0;

  /* attribute DOMString shape; */
  NS_IMETHOD GetShape(nsAString & aShape) = 0;
  NS_IMETHOD SetShape(const nsAString & aShape) = 0;

  /* DOMString toString (); */
  NS_IMETHOD ToString(nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLAnchorElement, NS_IDOMHTMLANCHORELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLANCHORELEMENT \
  NS_IMETHOD GetHref(nsAString & aHref) override; \
  NS_IMETHOD SetHref(const nsAString & aHref) override; \
  NS_IMETHOD GetTarget(nsAString & aTarget) override; \
  NS_IMETHOD SetTarget(const nsAString & aTarget) override; \
  NS_IMETHOD GetPing(nsAString & aPing) override; \
  NS_IMETHOD SetPing(const nsAString & aPing) override; \
  NS_IMETHOD GetDownload(nsAString & aDownload) override; \
  NS_IMETHOD SetDownload(const nsAString & aDownload) override; \
  NS_IMETHOD GetRel(nsAString & aRel) override; \
  NS_IMETHOD SetRel(const nsAString & aRel) override; \
  NS_IMETHOD GetHreflang(nsAString & aHreflang) override; \
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) override; \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD SetType(const nsAString & aType) override; \
  NS_IMETHOD GetText(nsAString & aText) override; \
  NS_IMETHOD SetText(const nsAString & aText) override; \
  NS_IMETHOD GetProtocol(nsAString & aProtocol) override; \
  NS_IMETHOD SetProtocol(const nsAString & aProtocol) override; \
  NS_IMETHOD GetHost(nsAString & aHost) override; \
  NS_IMETHOD SetHost(const nsAString & aHost) override; \
  NS_IMETHOD GetHostname(nsAString & aHostname) override; \
  NS_IMETHOD SetHostname(const nsAString & aHostname) override; \
  NS_IMETHOD GetPort(nsAString & aPort) override; \
  NS_IMETHOD SetPort(const nsAString & aPort) override; \
  NS_IMETHOD GetPathname(nsAString & aPathname) override; \
  NS_IMETHOD SetPathname(const nsAString & aPathname) override; \
  NS_IMETHOD GetSearch(nsAString & aSearch) override; \
  NS_IMETHOD SetSearch(const nsAString & aSearch) override; \
  NS_IMETHOD GetHash(nsAString & aHash) override; \
  NS_IMETHOD SetHash(const nsAString & aHash) override; \
  NS_IMETHOD GetCharset(nsAString & aCharset) override; \
  NS_IMETHOD SetCharset(const nsAString & aCharset) override; \
  NS_IMETHOD GetCoords(nsAString & aCoords) override; \
  NS_IMETHOD SetCoords(const nsAString & aCoords) override; \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD SetName(const nsAString & aName) override; \
  NS_IMETHOD GetRev(nsAString & aRev) override; \
  NS_IMETHOD SetRev(const nsAString & aRev) override; \
  NS_IMETHOD GetShape(nsAString & aShape) override; \
  NS_IMETHOD SetShape(const nsAString & aShape) override; \
  NS_IMETHOD ToString(nsAString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLANCHORELEMENT(_to) \
  NS_IMETHOD GetHref(nsAString & aHref) override { return _to GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) override { return _to SetHref(aHref); } \
  NS_IMETHOD GetTarget(nsAString & aTarget) override { return _to GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const nsAString & aTarget) override { return _to SetTarget(aTarget); } \
  NS_IMETHOD GetPing(nsAString & aPing) override { return _to GetPing(aPing); } \
  NS_IMETHOD SetPing(const nsAString & aPing) override { return _to SetPing(aPing); } \
  NS_IMETHOD GetDownload(nsAString & aDownload) override { return _to GetDownload(aDownload); } \
  NS_IMETHOD SetDownload(const nsAString & aDownload) override { return _to SetDownload(aDownload); } \
  NS_IMETHOD GetRel(nsAString & aRel) override { return _to GetRel(aRel); } \
  NS_IMETHOD SetRel(const nsAString & aRel) override { return _to SetRel(aRel); } \
  NS_IMETHOD GetHreflang(nsAString & aHreflang) override { return _to GetHreflang(aHreflang); } \
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) override { return _to SetHreflang(aHreflang); } \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return _to SetType(aType); } \
  NS_IMETHOD GetText(nsAString & aText) override { return _to GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) override { return _to SetText(aText); } \
  NS_IMETHOD GetProtocol(nsAString & aProtocol) override { return _to GetProtocol(aProtocol); } \
  NS_IMETHOD SetProtocol(const nsAString & aProtocol) override { return _to SetProtocol(aProtocol); } \
  NS_IMETHOD GetHost(nsAString & aHost) override { return _to GetHost(aHost); } \
  NS_IMETHOD SetHost(const nsAString & aHost) override { return _to SetHost(aHost); } \
  NS_IMETHOD GetHostname(nsAString & aHostname) override { return _to GetHostname(aHostname); } \
  NS_IMETHOD SetHostname(const nsAString & aHostname) override { return _to SetHostname(aHostname); } \
  NS_IMETHOD GetPort(nsAString & aPort) override { return _to GetPort(aPort); } \
  NS_IMETHOD SetPort(const nsAString & aPort) override { return _to SetPort(aPort); } \
  NS_IMETHOD GetPathname(nsAString & aPathname) override { return _to GetPathname(aPathname); } \
  NS_IMETHOD SetPathname(const nsAString & aPathname) override { return _to SetPathname(aPathname); } \
  NS_IMETHOD GetSearch(nsAString & aSearch) override { return _to GetSearch(aSearch); } \
  NS_IMETHOD SetSearch(const nsAString & aSearch) override { return _to SetSearch(aSearch); } \
  NS_IMETHOD GetHash(nsAString & aHash) override { return _to GetHash(aHash); } \
  NS_IMETHOD SetHash(const nsAString & aHash) override { return _to SetHash(aHash); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) override { return _to GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) override { return _to SetCharset(aCharset); } \
  NS_IMETHOD GetCoords(nsAString & aCoords) override { return _to GetCoords(aCoords); } \
  NS_IMETHOD SetCoords(const nsAString & aCoords) override { return _to SetCoords(aCoords); } \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return _to SetName(aName); } \
  NS_IMETHOD GetRev(nsAString & aRev) override { return _to GetRev(aRev); } \
  NS_IMETHOD SetRev(const nsAString & aRev) override { return _to SetRev(aRev); } \
  NS_IMETHOD GetShape(nsAString & aShape) override { return _to GetShape(aShape); } \
  NS_IMETHOD SetShape(const nsAString & aShape) override { return _to SetShape(aShape); } \
  NS_IMETHOD ToString(nsAString & _retval) override { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLANCHORELEMENT(_to) \
  NS_IMETHOD GetHref(nsAString & aHref) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHref(aHref); } \
  NS_IMETHOD GetTarget(nsAString & aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const nsAString & aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget); } \
  NS_IMETHOD GetPing(nsAString & aPing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPing(aPing); } \
  NS_IMETHOD SetPing(const nsAString & aPing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPing(aPing); } \
  NS_IMETHOD GetDownload(nsAString & aDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownload(aDownload); } \
  NS_IMETHOD SetDownload(const nsAString & aDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDownload(aDownload); } \
  NS_IMETHOD GetRel(nsAString & aRel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRel(aRel); } \
  NS_IMETHOD SetRel(const nsAString & aRel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRel(aRel); } \
  NS_IMETHOD GetHreflang(nsAString & aHreflang) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHreflang(aHreflang); } \
  NS_IMETHOD SetHreflang(const nsAString & aHreflang) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHreflang(aHreflang); } \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetText(nsAString & aText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetText(aText); } \
  NS_IMETHOD GetProtocol(nsAString & aProtocol) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocol(aProtocol); } \
  NS_IMETHOD SetProtocol(const nsAString & aProtocol) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProtocol(aProtocol); } \
  NS_IMETHOD GetHost(nsAString & aHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD SetHost(const nsAString & aHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHost(aHost); } \
  NS_IMETHOD GetHostname(nsAString & aHostname) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostname(aHostname); } \
  NS_IMETHOD SetHostname(const nsAString & aHostname) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHostname(aHostname); } \
  NS_IMETHOD GetPort(nsAString & aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD SetPort(const nsAString & aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPort(aPort); } \
  NS_IMETHOD GetPathname(nsAString & aPathname) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPathname(aPathname); } \
  NS_IMETHOD SetPathname(const nsAString & aPathname) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPathname(aPathname); } \
  NS_IMETHOD GetSearch(nsAString & aSearch) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearch(aSearch); } \
  NS_IMETHOD SetSearch(const nsAString & aSearch) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearch(aSearch); } \
  NS_IMETHOD GetHash(nsAString & aHash) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHash(aHash); } \
  NS_IMETHOD SetHash(const nsAString & aHash) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHash(aHash); } \
  NS_IMETHOD GetCharset(nsAString & aCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsAString & aCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } \
  NS_IMETHOD GetCoords(nsAString & aCoords) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoords(aCoords); } \
  NS_IMETHOD SetCoords(const nsAString & aCoords) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCoords(aCoords); } \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetRev(nsAString & aRev) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRev(aRev); } \
  NS_IMETHOD SetRev(const nsAString & aRev) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRev(aRev); } \
  NS_IMETHOD GetShape(nsAString & aShape) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShape(aShape); } \
  NS_IMETHOD SetShape(const nsAString & aShape) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShape(aShape); } \
  NS_IMETHOD ToString(nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLAnchorElement : public nsIDOMHTMLAnchorElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLANCHORELEMENT

  nsDOMHTMLAnchorElement();

private:
  ~nsDOMHTMLAnchorElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMHTMLAnchorElement, nsIDOMHTMLAnchorElement)

nsDOMHTMLAnchorElement::nsDOMHTMLAnchorElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLAnchorElement::~nsDOMHTMLAnchorElement()
{
  /* destructor code */
}

/* attribute DOMString href; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetHref(nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetHref(const nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString target; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetTarget(nsAString & aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetTarget(const nsAString & aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString ping; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetPing(nsAString & aPing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetPing(const nsAString & aPing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString download; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetDownload(nsAString & aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetDownload(const nsAString & aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString rel; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetRel(nsAString & aRel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetRel(const nsAString & aRel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hreflang; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetHreflang(nsAString & aHreflang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetHreflang(const nsAString & aHreflang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [Null(Stringify)] attribute DOMString text; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetText(const nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString protocol; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetProtocol(nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetProtocol(const nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString host; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetHost(nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetHost(const nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hostname; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetHostname(nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetHostname(const nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString port; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetPort(nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetPort(const nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString pathname; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetPathname(nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetPathname(const nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString search; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetSearch(nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetSearch(const nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hash; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetHash(nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetHash(const nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString charset; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetCharset(nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetCharset(const nsAString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString coords; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetCoords(nsAString & aCoords)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetCoords(const nsAString & aCoords)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString rev; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetRev(nsAString & aRev)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetRev(const nsAString & aRev)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString shape; */
NS_IMETHODIMP nsDOMHTMLAnchorElement::GetShape(nsAString & aShape)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAnchorElement::SetShape(const nsAString & aShape)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toString (); */
NS_IMETHODIMP nsDOMHTMLAnchorElement::ToString(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLAnchorElement_h__ */
