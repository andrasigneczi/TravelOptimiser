/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLDocument.idl
 */

#ifndef __gen_nsIDOMHTMLDocument_h__
#define __gen_nsIDOMHTMLDocument_h__


#ifndef __gen_nsIDOMDocument_h__
#include "nsIDOMDocument.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISelection; /* forward declaration */


/* starting interface:    nsIDOMHTMLDocument */
#define NS_IDOMHTMLDOCUMENT_IID_STR "bd2a0a46-17e4-46ea-9e5d-6a97cf5e3b28"

#define NS_IDOMHTMLDOCUMENT_IID \
  {0xbd2a0a46, 0x17e4, 0x46ea, \
    { 0x9e, 0x5d, 0x6a, 0x97, 0xcf, 0x5e, 0x3b, 0x28 }}

class NS_NO_VTABLE nsIDOMHTMLDocument : public nsIDOMDocument {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLDOCUMENT_IID)

  /* attribute DOMString domain; */
  NS_IMETHOD GetDomain(nsAString & aDomain) = 0;
  NS_IMETHOD SetDomain(const nsAString & aDomain) = 0;

  /* attribute DOMString cookie; */
  NS_IMETHOD GetCookie(nsAString & aCookie) = 0;
  NS_IMETHOD SetCookie(const nsAString & aCookie) = 0;

  /* readonly attribute nsIDOMHTMLHeadElement head; */
  NS_IMETHOD GetHead(nsIDOMHTMLHeadElement * *aHead) = 0;

  /* attribute nsIDOMHTMLElement body; */
  NS_IMETHOD GetBody(nsIDOMHTMLElement * *aBody) = 0;
  NS_IMETHOD SetBody(nsIDOMHTMLElement *aBody) = 0;

  /* readonly attribute nsIDOMHTMLCollection images; */
  NS_IMETHOD GetImages(nsIDOMHTMLCollection * *aImages) = 0;

  /* readonly attribute nsIDOMHTMLCollection embeds; */
  NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) = 0;

  /* readonly attribute nsIDOMHTMLCollection plugins; */
  NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) = 0;

  /* readonly attribute nsIDOMHTMLCollection links; */
  NS_IMETHOD GetLinks(nsIDOMHTMLCollection * *aLinks) = 0;

  /* readonly attribute nsIDOMHTMLCollection forms; */
  NS_IMETHOD GetForms(nsIDOMHTMLCollection * *aForms) = 0;

  /* readonly attribute nsIDOMHTMLCollection scripts; */
  NS_IMETHOD GetScripts(nsIDOMHTMLCollection * *aScripts) = 0;

  /* nsIDOMNodeList getElementsByName (in DOMString elementName); */
  NS_IMETHOD GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval) = 0;

  /* nsIDOMNodeList getItems ([optional] in DOMString types); */
  NS_IMETHOD GetItems(const nsAString & types, nsIDOMNodeList * *_retval) = 0;

  /* [implicit_jscontext,optional_argc] nsISupports open ([optional] in DOMString aContentTypeOrUrl, [optional] in DOMString aReplaceOrName, [optional] in DOMString aFeatures); */
  NS_IMETHOD Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* [implicit_jscontext] void write ([optional, Null (Stringify)] in DOMString text); */
  NS_IMETHOD Write(const nsAString & text, JSContext* cx) = 0;

  /* [implicit_jscontext] void writeln ([optional, Null (Stringify)] in DOMString text); */
  NS_IMETHOD Writeln(const nsAString & text, JSContext* cx) = 0;

  /* attribute DOMString designMode; */
  NS_IMETHOD GetDesignMode(nsAString & aDesignMode) = 0;
  NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) = 0;

  /* boolean execCommand (in DOMString commandID, [optional] in boolean doShowUI, [optional] in DOMString value); */
  NS_IMETHOD ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval) = 0;

  /* boolean queryCommandEnabled (in DOMString commandID); */
  NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, bool *_retval) = 0;

  /* boolean queryCommandIndeterm (in DOMString commandID); */
  NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, bool *_retval) = 0;

  /* boolean queryCommandState (in DOMString commandID); */
  NS_IMETHOD QueryCommandState(const nsAString & commandID, bool *_retval) = 0;

  /* boolean queryCommandSupported (in DOMString commandID); */
  NS_IMETHOD QueryCommandSupported(const nsAString & commandID, bool *_retval) = 0;

  /* DOMString queryCommandValue (in DOMString commandID); */
  NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval) = 0;

  /* attribute DOMString fgColor; */
  NS_IMETHOD GetFgColor(nsAString & aFgColor) = 0;
  NS_IMETHOD SetFgColor(const nsAString & aFgColor) = 0;

  /* attribute DOMString bgColor; */
  NS_IMETHOD GetBgColor(nsAString & aBgColor) = 0;
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) = 0;

  /* attribute DOMString linkColor; */
  NS_IMETHOD GetLinkColor(nsAString & aLinkColor) = 0;
  NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) = 0;

  /* attribute DOMString vlinkColor; */
  NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) = 0;
  NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) = 0;

  /* attribute DOMString alinkColor; */
  NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) = 0;
  NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) = 0;

  /* readonly attribute nsIDOMHTMLCollection anchors; */
  NS_IMETHOD GetAnchors(nsIDOMHTMLCollection * *aAnchors) = 0;

  /* readonly attribute nsIDOMHTMLCollection applets; */
  NS_IMETHOD GetApplets(nsIDOMHTMLCollection * *aApplets) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  /* nsISelection getSelection (); */
  NS_IMETHOD GetSelection(nsISelection * *_retval) = 0;

  /* void captureEvents (); */
  NS_IMETHOD CaptureEvents(void) = 0;

  /* void releaseEvents (); */
  NS_IMETHOD ReleaseEvents(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLDocument, NS_IDOMHTMLDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLDOCUMENT \
  NS_IMETHOD GetDomain(nsAString & aDomain) override; \
  NS_IMETHOD SetDomain(const nsAString & aDomain) override; \
  NS_IMETHOD GetCookie(nsAString & aCookie) override; \
  NS_IMETHOD SetCookie(const nsAString & aCookie) override; \
  NS_IMETHOD GetHead(nsIDOMHTMLHeadElement * *aHead) override; \
  NS_IMETHOD GetBody(nsIDOMHTMLElement * *aBody) override; \
  NS_IMETHOD SetBody(nsIDOMHTMLElement *aBody) override; \
  NS_IMETHOD GetImages(nsIDOMHTMLCollection * *aImages) override; \
  NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) override; \
  NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) override; \
  NS_IMETHOD GetLinks(nsIDOMHTMLCollection * *aLinks) override; \
  NS_IMETHOD GetForms(nsIDOMHTMLCollection * *aForms) override; \
  NS_IMETHOD GetScripts(nsIDOMHTMLCollection * *aScripts) override; \
  NS_IMETHOD GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval) override; \
  NS_IMETHOD GetItems(const nsAString & types, nsIDOMNodeList * *_retval) override; \
  NS_IMETHOD Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval) override; \
  NS_IMETHOD Close(void) override; \
  NS_IMETHOD Write(const nsAString & text, JSContext* cx) override; \
  NS_IMETHOD Writeln(const nsAString & text, JSContext* cx) override; \
  NS_IMETHOD GetDesignMode(nsAString & aDesignMode) override; \
  NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) override; \
  NS_IMETHOD ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval) override; \
  NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, bool *_retval) override; \
  NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, bool *_retval) override; \
  NS_IMETHOD QueryCommandState(const nsAString & commandID, bool *_retval) override; \
  NS_IMETHOD QueryCommandSupported(const nsAString & commandID, bool *_retval) override; \
  NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval) override; \
  NS_IMETHOD GetFgColor(nsAString & aFgColor) override; \
  NS_IMETHOD SetFgColor(const nsAString & aFgColor) override; \
  NS_IMETHOD GetBgColor(nsAString & aBgColor) override; \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) override; \
  NS_IMETHOD GetLinkColor(nsAString & aLinkColor) override; \
  NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) override; \
  NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) override; \
  NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) override; \
  NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) override; \
  NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) override; \
  NS_IMETHOD GetAnchors(nsIDOMHTMLCollection * *aAnchors) override; \
  NS_IMETHOD GetApplets(nsIDOMHTMLCollection * *aApplets) override; \
  NS_IMETHOD Clear(void) override; \
  NS_IMETHOD GetSelection(nsISelection * *_retval) override; \
  NS_IMETHOD CaptureEvents(void) override; \
  NS_IMETHOD ReleaseEvents(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLDOCUMENT(_to) \
  NS_IMETHOD GetDomain(nsAString & aDomain) override { return _to GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsAString & aDomain) override { return _to SetDomain(aDomain); } \
  NS_IMETHOD GetCookie(nsAString & aCookie) override { return _to GetCookie(aCookie); } \
  NS_IMETHOD SetCookie(const nsAString & aCookie) override { return _to SetCookie(aCookie); } \
  NS_IMETHOD GetHead(nsIDOMHTMLHeadElement * *aHead) override { return _to GetHead(aHead); } \
  NS_IMETHOD GetBody(nsIDOMHTMLElement * *aBody) override { return _to GetBody(aBody); } \
  NS_IMETHOD SetBody(nsIDOMHTMLElement *aBody) override { return _to SetBody(aBody); } \
  NS_IMETHOD GetImages(nsIDOMHTMLCollection * *aImages) override { return _to GetImages(aImages); } \
  NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) override { return _to GetEmbeds(aEmbeds); } \
  NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) override { return _to GetPlugins(aPlugins); } \
  NS_IMETHOD GetLinks(nsIDOMHTMLCollection * *aLinks) override { return _to GetLinks(aLinks); } \
  NS_IMETHOD GetForms(nsIDOMHTMLCollection * *aForms) override { return _to GetForms(aForms); } \
  NS_IMETHOD GetScripts(nsIDOMHTMLCollection * *aScripts) override { return _to GetScripts(aScripts); } \
  NS_IMETHOD GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval) override { return _to GetElementsByName(elementName, _retval); } \
  NS_IMETHOD GetItems(const nsAString & types, nsIDOMNodeList * *_retval) override { return _to GetItems(types, _retval); } \
  NS_IMETHOD Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval) override { return _to Open(aContentTypeOrUrl, aReplaceOrName, aFeatures, cx, _argc, _retval); } \
  NS_IMETHOD Close(void) override { return _to Close(); } \
  NS_IMETHOD Write(const nsAString & text, JSContext* cx) override { return _to Write(text, cx); } \
  NS_IMETHOD Writeln(const nsAString & text, JSContext* cx) override { return _to Writeln(text, cx); } \
  NS_IMETHOD GetDesignMode(nsAString & aDesignMode) override { return _to GetDesignMode(aDesignMode); } \
  NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) override { return _to SetDesignMode(aDesignMode); } \
  NS_IMETHOD ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval) override { return _to ExecCommand(commandID, doShowUI, value, _retval); } \
  NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, bool *_retval) override { return _to QueryCommandEnabled(commandID, _retval); } \
  NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, bool *_retval) override { return _to QueryCommandIndeterm(commandID, _retval); } \
  NS_IMETHOD QueryCommandState(const nsAString & commandID, bool *_retval) override { return _to QueryCommandState(commandID, _retval); } \
  NS_IMETHOD QueryCommandSupported(const nsAString & commandID, bool *_retval) override { return _to QueryCommandSupported(commandID, _retval); } \
  NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval) override { return _to QueryCommandValue(commandID, _retval); } \
  NS_IMETHOD GetFgColor(nsAString & aFgColor) override { return _to GetFgColor(aFgColor); } \
  NS_IMETHOD SetFgColor(const nsAString & aFgColor) override { return _to SetFgColor(aFgColor); } \
  NS_IMETHOD GetBgColor(nsAString & aBgColor) override { return _to GetBgColor(aBgColor); } \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) override { return _to SetBgColor(aBgColor); } \
  NS_IMETHOD GetLinkColor(nsAString & aLinkColor) override { return _to GetLinkColor(aLinkColor); } \
  NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) override { return _to SetLinkColor(aLinkColor); } \
  NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) override { return _to GetVlinkColor(aVlinkColor); } \
  NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) override { return _to SetVlinkColor(aVlinkColor); } \
  NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) override { return _to GetAlinkColor(aAlinkColor); } \
  NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) override { return _to SetAlinkColor(aAlinkColor); } \
  NS_IMETHOD GetAnchors(nsIDOMHTMLCollection * *aAnchors) override { return _to GetAnchors(aAnchors); } \
  NS_IMETHOD GetApplets(nsIDOMHTMLCollection * *aApplets) override { return _to GetApplets(aApplets); } \
  NS_IMETHOD Clear(void) override { return _to Clear(); } \
  NS_IMETHOD GetSelection(nsISelection * *_retval) override { return _to GetSelection(_retval); } \
  NS_IMETHOD CaptureEvents(void) override { return _to CaptureEvents(); } \
  NS_IMETHOD ReleaseEvents(void) override { return _to ReleaseEvents(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLDOCUMENT(_to) \
  NS_IMETHOD GetDomain(nsAString & aDomain) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsAString & aDomain) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } \
  NS_IMETHOD GetCookie(nsAString & aCookie) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCookie(aCookie); } \
  NS_IMETHOD SetCookie(const nsAString & aCookie) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCookie(aCookie); } \
  NS_IMETHOD GetHead(nsIDOMHTMLHeadElement * *aHead) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHead(aHead); } \
  NS_IMETHOD GetBody(nsIDOMHTMLElement * *aBody) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBody(aBody); } \
  NS_IMETHOD SetBody(nsIDOMHTMLElement *aBody) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBody(aBody); } \
  NS_IMETHOD GetImages(nsIDOMHTMLCollection * *aImages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImages(aImages); } \
  NS_IMETHOD GetEmbeds(nsIDOMHTMLCollection * *aEmbeds) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmbeds(aEmbeds); } \
  NS_IMETHOD GetPlugins(nsIDOMHTMLCollection * *aPlugins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlugins(aPlugins); } \
  NS_IMETHOD GetLinks(nsIDOMHTMLCollection * *aLinks) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinks(aLinks); } \
  NS_IMETHOD GetForms(nsIDOMHTMLCollection * *aForms) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForms(aForms); } \
  NS_IMETHOD GetScripts(nsIDOMHTMLCollection * *aScripts) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScripts(aScripts); } \
  NS_IMETHOD GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByName(elementName, _retval); } \
  NS_IMETHOD GetItems(const nsAString & types, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItems(types, _retval); } \
  NS_IMETHOD Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aContentTypeOrUrl, aReplaceOrName, aFeatures, cx, _argc, _retval); } \
  NS_IMETHOD Close(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Write(const nsAString & text, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(text, cx); } \
  NS_IMETHOD Writeln(const nsAString & text, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Writeln(text, cx); } \
  NS_IMETHOD GetDesignMode(nsAString & aDesignMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDesignMode(aDesignMode); } \
  NS_IMETHOD SetDesignMode(const nsAString & aDesignMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDesignMode(aDesignMode); } \
  NS_IMETHOD ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecCommand(commandID, doShowUI, value, _retval); } \
  NS_IMETHOD QueryCommandEnabled(const nsAString & commandID, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandEnabled(commandID, _retval); } \
  NS_IMETHOD QueryCommandIndeterm(const nsAString & commandID, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandIndeterm(commandID, _retval); } \
  NS_IMETHOD QueryCommandState(const nsAString & commandID, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandState(commandID, _retval); } \
  NS_IMETHOD QueryCommandSupported(const nsAString & commandID, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandSupported(commandID, _retval); } \
  NS_IMETHOD QueryCommandValue(const nsAString & commandID, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryCommandValue(commandID, _retval); } \
  NS_IMETHOD GetFgColor(nsAString & aFgColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFgColor(aFgColor); } \
  NS_IMETHOD SetFgColor(const nsAString & aFgColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFgColor(aFgColor); } \
  NS_IMETHOD GetBgColor(nsAString & aBgColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBgColor(aBgColor); } \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBgColor(aBgColor); } \
  NS_IMETHOD GetLinkColor(nsAString & aLinkColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkColor(aLinkColor); } \
  NS_IMETHOD SetLinkColor(const nsAString & aLinkColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLinkColor(aLinkColor); } \
  NS_IMETHOD GetVlinkColor(nsAString & aVlinkColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVlinkColor(aVlinkColor); } \
  NS_IMETHOD SetVlinkColor(const nsAString & aVlinkColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVlinkColor(aVlinkColor); } \
  NS_IMETHOD GetAlinkColor(nsAString & aAlinkColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlinkColor(aAlinkColor); } \
  NS_IMETHOD SetAlinkColor(const nsAString & aAlinkColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlinkColor(aAlinkColor); } \
  NS_IMETHOD GetAnchors(nsIDOMHTMLCollection * *aAnchors) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnchors(aAnchors); } \
  NS_IMETHOD GetApplets(nsIDOMHTMLCollection * *aApplets) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplets(aApplets); } \
  NS_IMETHOD Clear(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD GetSelection(nsISelection * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(_retval); } \
  NS_IMETHOD CaptureEvents(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CaptureEvents(); } \
  NS_IMETHOD ReleaseEvents(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseEvents(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLDocument : public nsIDOMHTMLDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLDOCUMENT

  nsDOMHTMLDocument();

private:
  ~nsDOMHTMLDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMHTMLDocument, nsIDOMHTMLDocument)

nsDOMHTMLDocument::nsDOMHTMLDocument()
{
  /* member initializers and constructor code */
}

nsDOMHTMLDocument::~nsDOMHTMLDocument()
{
  /* destructor code */
}

/* attribute DOMString domain; */
NS_IMETHODIMP nsDOMHTMLDocument::GetDomain(nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetDomain(const nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString cookie; */
NS_IMETHODIMP nsDOMHTMLDocument::GetCookie(nsAString & aCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetCookie(const nsAString & aCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLHeadElement head; */
NS_IMETHODIMP nsDOMHTMLDocument::GetHead(nsIDOMHTMLHeadElement * *aHead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMHTMLElement body; */
NS_IMETHODIMP nsDOMHTMLDocument::GetBody(nsIDOMHTMLElement * *aBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetBody(nsIDOMHTMLElement *aBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection images; */
NS_IMETHODIMP nsDOMHTMLDocument::GetImages(nsIDOMHTMLCollection * *aImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection embeds; */
NS_IMETHODIMP nsDOMHTMLDocument::GetEmbeds(nsIDOMHTMLCollection * *aEmbeds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection plugins; */
NS_IMETHODIMP nsDOMHTMLDocument::GetPlugins(nsIDOMHTMLCollection * *aPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection links; */
NS_IMETHODIMP nsDOMHTMLDocument::GetLinks(nsIDOMHTMLCollection * *aLinks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection forms; */
NS_IMETHODIMP nsDOMHTMLDocument::GetForms(nsIDOMHTMLCollection * *aForms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection scripts; */
NS_IMETHODIMP nsDOMHTMLDocument::GetScripts(nsIDOMHTMLCollection * *aScripts)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByName (in DOMString elementName); */
NS_IMETHODIMP nsDOMHTMLDocument::GetElementsByName(const nsAString & elementName, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getItems ([optional] in DOMString types); */
NS_IMETHODIMP nsDOMHTMLDocument::GetItems(const nsAString & types, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsISupports open ([optional] in DOMString aContentTypeOrUrl, [optional] in DOMString aReplaceOrName, [optional] in DOMString aFeatures); */
NS_IMETHODIMP nsDOMHTMLDocument::Open(const nsAString & aContentTypeOrUrl, const nsAString & aReplaceOrName, const nsAString & aFeatures, JSContext* cx, uint8_t _argc, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDOMHTMLDocument::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void write ([optional, Null (Stringify)] in DOMString text); */
NS_IMETHODIMP nsDOMHTMLDocument::Write(const nsAString & text, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void writeln ([optional, Null (Stringify)] in DOMString text); */
NS_IMETHODIMP nsDOMHTMLDocument::Writeln(const nsAString & text, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString designMode; */
NS_IMETHODIMP nsDOMHTMLDocument::GetDesignMode(nsAString & aDesignMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetDesignMode(const nsAString & aDesignMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean execCommand (in DOMString commandID, [optional] in boolean doShowUI, [optional] in DOMString value); */
NS_IMETHODIMP nsDOMHTMLDocument::ExecCommand(const nsAString & commandID, bool doShowUI, const nsAString & value, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandEnabled (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandEnabled(const nsAString & commandID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandIndeterm (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandIndeterm(const nsAString & commandID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandState (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandState(const nsAString & commandID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean queryCommandSupported (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandSupported(const nsAString & commandID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString queryCommandValue (in DOMString commandID); */
NS_IMETHODIMP nsDOMHTMLDocument::QueryCommandValue(const nsAString & commandID, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString fgColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetFgColor(nsAString & aFgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetFgColor(const nsAString & aFgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString bgColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetBgColor(nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetBgColor(const nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString linkColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetLinkColor(nsAString & aLinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetLinkColor(const nsAString & aLinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString vlinkColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetVlinkColor(nsAString & aVlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetVlinkColor(const nsAString & aVlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString alinkColor; */
NS_IMETHODIMP nsDOMHTMLDocument::GetAlinkColor(nsAString & aAlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDocument::SetAlinkColor(const nsAString & aAlinkColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection anchors; */
NS_IMETHODIMP nsDOMHTMLDocument::GetAnchors(nsIDOMHTMLCollection * *aAnchors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection applets; */
NS_IMETHODIMP nsDOMHTMLDocument::GetApplets(nsIDOMHTMLCollection * *aApplets)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDOMHTMLDocument::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISelection getSelection (); */
NS_IMETHODIMP nsDOMHTMLDocument::GetSelection(nsISelection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void captureEvents (); */
NS_IMETHODIMP nsDOMHTMLDocument::CaptureEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseEvents (); */
NS_IMETHODIMP nsDOMHTMLDocument::ReleaseEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLDocument_h__ */
