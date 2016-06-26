/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLAreaElement.idl
 */

#ifndef __gen_nsIDOMHTMLAreaElement_h__
#define __gen_nsIDOMHTMLAreaElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLAreaElement */
#define NS_IDOMHTMLAREAELEMENT_IID_STR "40c78026-36dc-40ca-9221-de73267e9e99"

#define NS_IDOMHTMLAREAELEMENT_IID \
  {0x40c78026, 0x36dc, 0x40ca, \
    { 0x92, 0x21, 0xde, 0x73, 0x26, 0x7e, 0x9e, 0x99 }}

class NS_NO_VTABLE nsIDOMHTMLAreaElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLAREAELEMENT_IID)

  /* attribute DOMString alt; */
  NS_IMETHOD GetAlt(nsAString & aAlt) = 0;
  NS_IMETHOD SetAlt(const nsAString & aAlt) = 0;

  /* attribute DOMString coords; */
  NS_IMETHOD GetCoords(nsAString & aCoords) = 0;
  NS_IMETHOD SetCoords(const nsAString & aCoords) = 0;

  /* attribute DOMString shape; */
  NS_IMETHOD GetShape(nsAString & aShape) = 0;
  NS_IMETHOD SetShape(const nsAString & aShape) = 0;

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

  /* attribute boolean noHref; */
  NS_IMETHOD GetNoHref(bool *aNoHref) = 0;
  NS_IMETHOD SetNoHref(bool aNoHref) = 0;

  /* DOMString toString (); */
  NS_IMETHOD ToString(nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLAreaElement, NS_IDOMHTMLAREAELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLAREAELEMENT \
  NS_IMETHOD GetAlt(nsAString & aAlt) override; \
  NS_IMETHOD SetAlt(const nsAString & aAlt) override; \
  NS_IMETHOD GetCoords(nsAString & aCoords) override; \
  NS_IMETHOD SetCoords(const nsAString & aCoords) override; \
  NS_IMETHOD GetShape(nsAString & aShape) override; \
  NS_IMETHOD SetShape(const nsAString & aShape) override; \
  NS_IMETHOD GetHref(nsAString & aHref) override; \
  NS_IMETHOD SetHref(const nsAString & aHref) override; \
  NS_IMETHOD GetTarget(nsAString & aTarget) override; \
  NS_IMETHOD SetTarget(const nsAString & aTarget) override; \
  NS_IMETHOD GetPing(nsAString & aPing) override; \
  NS_IMETHOD SetPing(const nsAString & aPing) override; \
  NS_IMETHOD GetDownload(nsAString & aDownload) override; \
  NS_IMETHOD SetDownload(const nsAString & aDownload) override; \
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
  NS_IMETHOD GetNoHref(bool *aNoHref) override; \
  NS_IMETHOD SetNoHref(bool aNoHref) override; \
  NS_IMETHOD ToString(nsAString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLAREAELEMENT(_to) \
  NS_IMETHOD GetAlt(nsAString & aAlt) override { return _to GetAlt(aAlt); } \
  NS_IMETHOD SetAlt(const nsAString & aAlt) override { return _to SetAlt(aAlt); } \
  NS_IMETHOD GetCoords(nsAString & aCoords) override { return _to GetCoords(aCoords); } \
  NS_IMETHOD SetCoords(const nsAString & aCoords) override { return _to SetCoords(aCoords); } \
  NS_IMETHOD GetShape(nsAString & aShape) override { return _to GetShape(aShape); } \
  NS_IMETHOD SetShape(const nsAString & aShape) override { return _to SetShape(aShape); } \
  NS_IMETHOD GetHref(nsAString & aHref) override { return _to GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) override { return _to SetHref(aHref); } \
  NS_IMETHOD GetTarget(nsAString & aTarget) override { return _to GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const nsAString & aTarget) override { return _to SetTarget(aTarget); } \
  NS_IMETHOD GetPing(nsAString & aPing) override { return _to GetPing(aPing); } \
  NS_IMETHOD SetPing(const nsAString & aPing) override { return _to SetPing(aPing); } \
  NS_IMETHOD GetDownload(nsAString & aDownload) override { return _to GetDownload(aDownload); } \
  NS_IMETHOD SetDownload(const nsAString & aDownload) override { return _to SetDownload(aDownload); } \
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
  NS_IMETHOD GetNoHref(bool *aNoHref) override { return _to GetNoHref(aNoHref); } \
  NS_IMETHOD SetNoHref(bool aNoHref) override { return _to SetNoHref(aNoHref); } \
  NS_IMETHOD ToString(nsAString & _retval) override { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLAREAELEMENT(_to) \
  NS_IMETHOD GetAlt(nsAString & aAlt) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlt(aAlt); } \
  NS_IMETHOD SetAlt(const nsAString & aAlt) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlt(aAlt); } \
  NS_IMETHOD GetCoords(nsAString & aCoords) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoords(aCoords); } \
  NS_IMETHOD SetCoords(const nsAString & aCoords) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCoords(aCoords); } \
  NS_IMETHOD GetShape(nsAString & aShape) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShape(aShape); } \
  NS_IMETHOD SetShape(const nsAString & aShape) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShape(aShape); } \
  NS_IMETHOD GetHref(nsAString & aHref) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHref(aHref); } \
  NS_IMETHOD GetTarget(nsAString & aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const nsAString & aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget); } \
  NS_IMETHOD GetPing(nsAString & aPing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPing(aPing); } \
  NS_IMETHOD SetPing(const nsAString & aPing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPing(aPing); } \
  NS_IMETHOD GetDownload(nsAString & aDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownload(aDownload); } \
  NS_IMETHOD SetDownload(const nsAString & aDownload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDownload(aDownload); } \
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
  NS_IMETHOD GetNoHref(bool *aNoHref) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNoHref(aNoHref); } \
  NS_IMETHOD SetNoHref(bool aNoHref) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNoHref(aNoHref); } \
  NS_IMETHOD ToString(nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLAreaElement : public nsIDOMHTMLAreaElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLAREAELEMENT

  nsDOMHTMLAreaElement();

private:
  ~nsDOMHTMLAreaElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMHTMLAreaElement, nsIDOMHTMLAreaElement)

nsDOMHTMLAreaElement::nsDOMHTMLAreaElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLAreaElement::~nsDOMHTMLAreaElement()
{
  /* destructor code */
}

/* attribute DOMString alt; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetAlt(nsAString & aAlt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetAlt(const nsAString & aAlt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString coords; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetCoords(nsAString & aCoords)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetCoords(const nsAString & aCoords)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString shape; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetShape(nsAString & aShape)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetShape(const nsAString & aShape)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString href; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetHref(nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetHref(const nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString target; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetTarget(nsAString & aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetTarget(const nsAString & aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString ping; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetPing(nsAString & aPing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetPing(const nsAString & aPing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString download; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetDownload(nsAString & aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetDownload(const nsAString & aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString protocol; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetProtocol(nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetProtocol(const nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString host; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetHost(nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetHost(const nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hostname; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetHostname(nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetHostname(const nsAString & aHostname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString port; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetPort(nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetPort(const nsAString & aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString pathname; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetPathname(nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetPathname(const nsAString & aPathname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString search; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetSearch(nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetSearch(const nsAString & aSearch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString hash; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetHash(nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetHash(const nsAString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean noHref; */
NS_IMETHODIMP nsDOMHTMLAreaElement::GetNoHref(bool *aNoHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLAreaElement::SetNoHref(bool aNoHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toString (); */
NS_IMETHODIMP nsDOMHTMLAreaElement::ToString(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLAreaElement_h__ */
