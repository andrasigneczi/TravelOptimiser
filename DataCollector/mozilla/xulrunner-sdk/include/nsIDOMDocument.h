/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDocument.idl
 */

#ifndef __gen_nsIDOMDocument_h__
#define __gen_nsIDOMDocument_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"
// windows.h #defines CreateEvent
#ifdef CreateEvent
#undef CreateEvent
#endif
class nsIDOMNodeIterator; /* forward declaration */

class nsIDOMNodeFilter; /* forward declaration */

class nsIDOMTreeWalker; /* forward declaration */

class nsIDOMLocation; /* forward declaration */


/* starting interface:    nsIDOMDocument */
#define NS_IDOMDOCUMENT_IID_STR "35dc5030-dc83-4291-88a2-0906c549788e"

#define NS_IDOMDOCUMENT_IID \
  {0x35dc5030, 0xdc83, 0x4291, \
    { 0x88, 0xa2, 0x09, 0x06, 0xc5, 0x49, 0x78, 0x8e }}

class NS_NO_VTABLE nsIDOMDocument : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENT_IID)

  /* readonly attribute nsIDOMDocumentType doctype; */
  NS_IMETHOD GetDoctype(nsIDOMDocumentType * *aDoctype) = 0;

  /* readonly attribute nsIDOMDOMImplementation implementation; */
  NS_IMETHOD GetImplementation(nsIDOMDOMImplementation * *aImplementation) = 0;

  /* readonly attribute nsIDOMElement documentElement; */
  NS_IMETHOD GetDocumentElement(nsIDOMElement * *aDocumentElement) = 0;

  /* nsIDOMElement createElement ([Null (Stringify)] in DOMString tagName) raises (DOMException); */
  NS_IMETHOD CreateElement(const nsAString & tagName, nsIDOMElement * *_retval) = 0;

  /* nsIDOMDocumentFragment createDocumentFragment (); */
  NS_IMETHOD CreateDocumentFragment(nsIDOMDocumentFragment * *_retval) = 0;

  /* nsIDOMText createTextNode (in DOMString data); */
  NS_IMETHOD CreateTextNode(const nsAString & data, nsIDOMText * *_retval) = 0;

  /* nsIDOMComment createComment (in DOMString data); */
  NS_IMETHOD CreateComment(const nsAString & data, nsIDOMComment * *_retval) = 0;

  /* nsIDOMCDATASection createCDATASection (in DOMString data) raises (DOMException); */
  NS_IMETHOD CreateCDATASection(const nsAString & data, nsIDOMCDATASection * *_retval) = 0;

  /* nsIDOMProcessingInstruction createProcessingInstruction (in DOMString target, in DOMString data) raises (DOMException); */
  NS_IMETHOD CreateProcessingInstruction(const nsAString & target, const nsAString & data, nsIDOMProcessingInstruction * *_retval) = 0;

  /* nsIDOMAttr createAttribute (in DOMString name) raises (DOMException); */
  NS_IMETHOD CreateAttribute(const nsAString & name, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMNodeList getElementsByTagName (in DOMString tagname); */
  NS_IMETHOD GetElementsByTagName(const nsAString & tagname, nsIDOMNodeList * *_retval) = 0;

  /* [optional_argc] nsIDOMNode importNode (in nsIDOMNode importedNode, [optional] in boolean deep) raises (DOMException); */
  NS_IMETHOD ImportNode(nsIDOMNode *importedNode, bool deep, uint8_t _argc, nsIDOMNode * *_retval) = 0;

  /* nsIDOMElement createElementNS (in DOMString namespaceURI, [Null (Stringify)] in DOMString qualifiedName) raises (DOMException); */
  NS_IMETHOD CreateElementNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMElement * *_retval) = 0;

  /* nsIDOMAttr createAttributeNS (in DOMString namespaceURI, in DOMString qualifiedName) raises (DOMException); */
  NS_IMETHOD CreateAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMNodeList getElementsByTagNameNS (in DOMString namespaceURI, in DOMString localName); */
  NS_IMETHOD GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMNodeList * *_retval) = 0;

  /* nsIDOMElement getElementById (in DOMString elementId); */
  NS_IMETHOD GetElementById(const nsAString & elementId, nsIDOMElement * *_retval) = 0;

  /* readonly attribute DOMString inputEncoding; */
  NS_IMETHOD GetInputEncoding(nsAString & aInputEncoding) = 0;

  /* readonly attribute DOMString documentURI; */
  NS_IMETHOD GetDocumentURI(nsAString & aDocumentURI) = 0;

  /* readonly attribute DOMString URL; */
  NS_IMETHOD GetURL(nsAString & aURL) = 0;

  /* nsIDOMNode adoptNode (in nsIDOMNode source) raises (DOMException); */
  NS_IMETHOD AdoptNode(nsIDOMNode *source, nsIDOMNode * *_retval) = 0;

  /* nsIDOMRange createRange (); */
  NS_IMETHOD CreateRange(nsIDOMRange * *_retval) = 0;

  /* [optional_argc] nsIDOMNodeIterator createNodeIterator (in nsIDOMNode root, [optional] in unsigned long whatToShow, [optional] in nsIDOMNodeFilter filter) raises (DOMException); */
  NS_IMETHOD CreateNodeIterator(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMNodeIterator * *_retval) = 0;

  /* [optional_argc] nsIDOMTreeWalker createTreeWalker (in nsIDOMNode root, [optional] in unsigned long whatToShow, [optional] in nsIDOMNodeFilter filter) raises (DOMException); */
  NS_IMETHOD CreateTreeWalker(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMTreeWalker * *_retval) = 0;

  /* nsIDOMEvent createEvent (in DOMString eventType) raises (DOMException); */
  NS_IMETHOD CreateEvent(const nsAString & eventType, nsIDOMEvent * *_retval) = 0;

  /* readonly attribute nsIDOMWindow defaultView; */
  NS_IMETHOD GetDefaultView(nsIDOMWindow * *aDefaultView) = 0;

  /* readonly attribute DOMString characterSet; */
  NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) = 0;

  /* attribute DOMString dir; */
  NS_IMETHOD GetDir(nsAString & aDir) = 0;
  NS_IMETHOD SetDir(const nsAString & aDir) = 0;

  /* readonly attribute nsIDOMLocation location; */
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) = 0;

  /* attribute DOMString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /* readonly attribute DOMString readyState; */
  NS_IMETHOD GetReadyState(nsAString & aReadyState) = 0;

  /* readonly attribute DOMString lastModified; */
  NS_IMETHOD GetLastModified(nsAString & aLastModified) = 0;

  /* readonly attribute DOMString referrer; */
  NS_IMETHOD GetReferrer(nsAString & aReferrer) = 0;

  /* boolean hasFocus (); */
  NS_IMETHOD HasFocus(bool *_retval) = 0;

  /* readonly attribute nsIDOMElement activeElement; */
  NS_IMETHOD GetActiveElement(nsIDOMElement * *aActiveElement) = 0;

  /* nsIDOMNodeList getElementsByClassName (in DOMString classes); */
  NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList * *_retval) = 0;

  /* readonly attribute nsIDOMStyleSheetList styleSheets; */
  NS_IMETHOD GetStyleSheets(nsIDOMStyleSheetList * *aStyleSheets) = 0;

  /* readonly attribute DOMString preferredStyleSheetSet; */
  NS_IMETHOD GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet) = 0;

  /* [binaryname(MozSelectedStyleSheetSet)] attribute DOMString selectedStyleSheetSet; */
  NS_IMETHOD GetMozSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet) = 0;
  NS_IMETHOD SetMozSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet) = 0;

  /* readonly attribute DOMString lastStyleSheetSet; */
  NS_IMETHOD GetLastStyleSheetSet(nsAString & aLastStyleSheetSet) = 0;

  /* readonly attribute nsISupports styleSheetSets; */
  NS_IMETHOD GetStyleSheetSets(nsISupports * *aStyleSheetSets) = 0;

  /* [binaryname(MozEnableStyleSheetsForSet)] void enableStyleSheetsForSet (in DOMString name); */
  NS_IMETHOD MozEnableStyleSheetsForSet(const nsAString & name) = 0;

  /* nsIDOMElement elementFromPoint (in float x, in float y); */
  NS_IMETHOD ElementFromPoint(float x, float y, nsIDOMElement * *_retval) = 0;

  /* readonly attribute DOMString contentType; */
  NS_IMETHOD GetContentType(nsAString & aContentType) = 0;

  /* readonly attribute boolean mozSyntheticDocument; */
  NS_IMETHOD GetMozSyntheticDocument(bool *aMozSyntheticDocument) = 0;

  /* readonly attribute nsIDOMElement currentScript; */
  NS_IMETHOD GetCurrentScript(nsIDOMElement * *aCurrentScript) = 0;

  /* void releaseCapture (); */
  NS_IMETHOD ReleaseCapture(void) = 0;

  /* void mozSetImageElement (in DOMString aImageElementId, in nsIDOMElement aImageElement); */
  NS_IMETHOD MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement) = 0;

  /* readonly attribute nsIDOMElement mozFullScreenElement; */
  NS_IMETHOD GetMozFullScreenElement(nsIDOMElement * *aMozFullScreenElement) = 0;

  /* void mozCancelFullScreen (); */
  NS_IMETHOD MozCancelFullScreen(void) = 0;

  /* readonly attribute boolean mozFullScreen; */
  NS_IMETHOD GetMozFullScreen(bool *aMozFullScreen) = 0;

  /* readonly attribute boolean mozFullScreenEnabled; */
  NS_IMETHOD GetMozFullScreenEnabled(bool *aMozFullScreenEnabled) = 0;

  /* readonly attribute nsIDOMElement mozPointerLockElement; */
  NS_IMETHOD GetMozPointerLockElement(nsIDOMElement * *aMozPointerLockElement) = 0;

  /* nsISupports caretPositionFromPoint (in float x, in float y); */
  NS_IMETHOD CaretPositionFromPoint(float x, float y, nsISupports * *_retval) = 0;

  /* void mozExitPointerLock (); */
  NS_IMETHOD MozExitPointerLock(void) = 0;

  /* readonly attribute boolean hidden; */
  NS_IMETHOD GetHidden(bool *aHidden) = 0;

  /* readonly attribute boolean mozHidden; */
  NS_IMETHOD GetMozHidden(bool *aMozHidden) = 0;

  /* readonly attribute DOMString visibilityState; */
  NS_IMETHOD GetVisibilityState(nsAString & aVisibilityState) = 0;

  /* readonly attribute DOMString mozVisibilityState; */
  NS_IMETHOD GetMozVisibilityState(nsAString & aMozVisibilityState) = 0;

  /* readonly attribute DOMString compatMode; */
  NS_IMETHOD GetCompatMode(nsAString & aCompatMode) = 0;

  /* nsIDOMElement querySelector ([Null (Stringify)] in DOMString selectors); */
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) = 0;

  /* nsIDOMNodeList querySelectorAll ([Null (Stringify)] in DOMString selectors); */
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocument, NS_IDOMDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENT \
  NS_IMETHOD GetDoctype(nsIDOMDocumentType * *aDoctype) override; \
  NS_IMETHOD GetImplementation(nsIDOMDOMImplementation * *aImplementation) override; \
  NS_IMETHOD GetDocumentElement(nsIDOMElement * *aDocumentElement) override; \
  NS_IMETHOD CreateElement(const nsAString & tagName, nsIDOMElement * *_retval) override; \
  NS_IMETHOD CreateDocumentFragment(nsIDOMDocumentFragment * *_retval) override; \
  NS_IMETHOD CreateTextNode(const nsAString & data, nsIDOMText * *_retval) override; \
  NS_IMETHOD CreateComment(const nsAString & data, nsIDOMComment * *_retval) override; \
  NS_IMETHOD CreateCDATASection(const nsAString & data, nsIDOMCDATASection * *_retval) override; \
  NS_IMETHOD CreateProcessingInstruction(const nsAString & target, const nsAString & data, nsIDOMProcessingInstruction * *_retval) override; \
  NS_IMETHOD CreateAttribute(const nsAString & name, nsIDOMAttr * *_retval) override; \
  NS_IMETHOD GetElementsByTagName(const nsAString & tagname, nsIDOMNodeList * *_retval) override; \
  NS_IMETHOD ImportNode(nsIDOMNode *importedNode, bool deep, uint8_t _argc, nsIDOMNode * *_retval) override; \
  NS_IMETHOD CreateElementNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMElement * *_retval) override; \
  NS_IMETHOD CreateAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMAttr * *_retval) override; \
  NS_IMETHOD GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMNodeList * *_retval) override; \
  NS_IMETHOD GetElementById(const nsAString & elementId, nsIDOMElement * *_retval) override; \
  NS_IMETHOD GetInputEncoding(nsAString & aInputEncoding) override; \
  NS_IMETHOD GetDocumentURI(nsAString & aDocumentURI) override; \
  NS_IMETHOD GetURL(nsAString & aURL) override; \
  NS_IMETHOD AdoptNode(nsIDOMNode *source, nsIDOMNode * *_retval) override; \
  NS_IMETHOD CreateRange(nsIDOMRange * *_retval) override; \
  NS_IMETHOD CreateNodeIterator(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMNodeIterator * *_retval) override; \
  NS_IMETHOD CreateTreeWalker(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMTreeWalker * *_retval) override; \
  NS_IMETHOD CreateEvent(const nsAString & eventType, nsIDOMEvent * *_retval) override; \
  NS_IMETHOD GetDefaultView(nsIDOMWindow * *aDefaultView) override; \
  NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) override; \
  NS_IMETHOD GetDir(nsAString & aDir) override; \
  NS_IMETHOD SetDir(const nsAString & aDir) override; \
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) override; \
  NS_IMETHOD GetTitle(nsAString & aTitle) override; \
  NS_IMETHOD SetTitle(const nsAString & aTitle) override; \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) override; \
  NS_IMETHOD GetLastModified(nsAString & aLastModified) override; \
  NS_IMETHOD GetReferrer(nsAString & aReferrer) override; \
  NS_IMETHOD HasFocus(bool *_retval) override; \
  NS_IMETHOD GetActiveElement(nsIDOMElement * *aActiveElement) override; \
  NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList * *_retval) override; \
  NS_IMETHOD GetStyleSheets(nsIDOMStyleSheetList * *aStyleSheets) override; \
  NS_IMETHOD GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet) override; \
  NS_IMETHOD GetMozSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet) override; \
  NS_IMETHOD SetMozSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet) override; \
  NS_IMETHOD GetLastStyleSheetSet(nsAString & aLastStyleSheetSet) override; \
  NS_IMETHOD GetStyleSheetSets(nsISupports * *aStyleSheetSets) override; \
  NS_IMETHOD MozEnableStyleSheetsForSet(const nsAString & name) override; \
  NS_IMETHOD ElementFromPoint(float x, float y, nsIDOMElement * *_retval) override; \
  NS_IMETHOD GetContentType(nsAString & aContentType) override; \
  NS_IMETHOD GetMozSyntheticDocument(bool *aMozSyntheticDocument) override; \
  NS_IMETHOD GetCurrentScript(nsIDOMElement * *aCurrentScript) override; \
  NS_IMETHOD ReleaseCapture(void) override; \
  NS_IMETHOD MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement) override; \
  NS_IMETHOD GetMozFullScreenElement(nsIDOMElement * *aMozFullScreenElement) override; \
  NS_IMETHOD MozCancelFullScreen(void) override; \
  NS_IMETHOD GetMozFullScreen(bool *aMozFullScreen) override; \
  NS_IMETHOD GetMozFullScreenEnabled(bool *aMozFullScreenEnabled) override; \
  NS_IMETHOD GetMozPointerLockElement(nsIDOMElement * *aMozPointerLockElement) override; \
  NS_IMETHOD CaretPositionFromPoint(float x, float y, nsISupports * *_retval) override; \
  NS_IMETHOD MozExitPointerLock(void) override; \
  NS_IMETHOD GetHidden(bool *aHidden) override; \
  NS_IMETHOD GetMozHidden(bool *aMozHidden) override; \
  NS_IMETHOD GetVisibilityState(nsAString & aVisibilityState) override; \
  NS_IMETHOD GetMozVisibilityState(nsAString & aMozVisibilityState) override; \
  NS_IMETHOD GetCompatMode(nsAString & aCompatMode) override; \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) override; \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENT(_to) \
  NS_IMETHOD GetDoctype(nsIDOMDocumentType * *aDoctype) override { return _to GetDoctype(aDoctype); } \
  NS_IMETHOD GetImplementation(nsIDOMDOMImplementation * *aImplementation) override { return _to GetImplementation(aImplementation); } \
  NS_IMETHOD GetDocumentElement(nsIDOMElement * *aDocumentElement) override { return _to GetDocumentElement(aDocumentElement); } \
  NS_IMETHOD CreateElement(const nsAString & tagName, nsIDOMElement * *_retval) override { return _to CreateElement(tagName, _retval); } \
  NS_IMETHOD CreateDocumentFragment(nsIDOMDocumentFragment * *_retval) override { return _to CreateDocumentFragment(_retval); } \
  NS_IMETHOD CreateTextNode(const nsAString & data, nsIDOMText * *_retval) override { return _to CreateTextNode(data, _retval); } \
  NS_IMETHOD CreateComment(const nsAString & data, nsIDOMComment * *_retval) override { return _to CreateComment(data, _retval); } \
  NS_IMETHOD CreateCDATASection(const nsAString & data, nsIDOMCDATASection * *_retval) override { return _to CreateCDATASection(data, _retval); } \
  NS_IMETHOD CreateProcessingInstruction(const nsAString & target, const nsAString & data, nsIDOMProcessingInstruction * *_retval) override { return _to CreateProcessingInstruction(target, data, _retval); } \
  NS_IMETHOD CreateAttribute(const nsAString & name, nsIDOMAttr * *_retval) override { return _to CreateAttribute(name, _retval); } \
  NS_IMETHOD GetElementsByTagName(const nsAString & tagname, nsIDOMNodeList * *_retval) override { return _to GetElementsByTagName(tagname, _retval); } \
  NS_IMETHOD ImportNode(nsIDOMNode *importedNode, bool deep, uint8_t _argc, nsIDOMNode * *_retval) override { return _to ImportNode(importedNode, deep, _argc, _retval); } \
  NS_IMETHOD CreateElementNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMElement * *_retval) override { return _to CreateElementNS(namespaceURI, qualifiedName, _retval); } \
  NS_IMETHOD CreateAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMAttr * *_retval) override { return _to CreateAttributeNS(namespaceURI, qualifiedName, _retval); } \
  NS_IMETHOD GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMNodeList * *_retval) override { return _to GetElementsByTagNameNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD GetElementById(const nsAString & elementId, nsIDOMElement * *_retval) override { return _to GetElementById(elementId, _retval); } \
  NS_IMETHOD GetInputEncoding(nsAString & aInputEncoding) override { return _to GetInputEncoding(aInputEncoding); } \
  NS_IMETHOD GetDocumentURI(nsAString & aDocumentURI) override { return _to GetDocumentURI(aDocumentURI); } \
  NS_IMETHOD GetURL(nsAString & aURL) override { return _to GetURL(aURL); } \
  NS_IMETHOD AdoptNode(nsIDOMNode *source, nsIDOMNode * *_retval) override { return _to AdoptNode(source, _retval); } \
  NS_IMETHOD CreateRange(nsIDOMRange * *_retval) override { return _to CreateRange(_retval); } \
  NS_IMETHOD CreateNodeIterator(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMNodeIterator * *_retval) override { return _to CreateNodeIterator(root, whatToShow, filter, _argc, _retval); } \
  NS_IMETHOD CreateTreeWalker(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMTreeWalker * *_retval) override { return _to CreateTreeWalker(root, whatToShow, filter, _argc, _retval); } \
  NS_IMETHOD CreateEvent(const nsAString & eventType, nsIDOMEvent * *_retval) override { return _to CreateEvent(eventType, _retval); } \
  NS_IMETHOD GetDefaultView(nsIDOMWindow * *aDefaultView) override { return _to GetDefaultView(aDefaultView); } \
  NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) override { return _to GetCharacterSet(aCharacterSet); } \
  NS_IMETHOD GetDir(nsAString & aDir) override { return _to GetDir(aDir); } \
  NS_IMETHOD SetDir(const nsAString & aDir) override { return _to SetDir(aDir); } \
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) override { return _to GetLocation(aLocation); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) override { return _to GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) override { return _to SetTitle(aTitle); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) override { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetLastModified(nsAString & aLastModified) override { return _to GetLastModified(aLastModified); } \
  NS_IMETHOD GetReferrer(nsAString & aReferrer) override { return _to GetReferrer(aReferrer); } \
  NS_IMETHOD HasFocus(bool *_retval) override { return _to HasFocus(_retval); } \
  NS_IMETHOD GetActiveElement(nsIDOMElement * *aActiveElement) override { return _to GetActiveElement(aActiveElement); } \
  NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList * *_retval) override { return _to GetElementsByClassName(classes, _retval); } \
  NS_IMETHOD GetStyleSheets(nsIDOMStyleSheetList * *aStyleSheets) override { return _to GetStyleSheets(aStyleSheets); } \
  NS_IMETHOD GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet) override { return _to GetPreferredStyleSheetSet(aPreferredStyleSheetSet); } \
  NS_IMETHOD GetMozSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet) override { return _to GetMozSelectedStyleSheetSet(aSelectedStyleSheetSet); } \
  NS_IMETHOD SetMozSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet) override { return _to SetMozSelectedStyleSheetSet(aSelectedStyleSheetSet); } \
  NS_IMETHOD GetLastStyleSheetSet(nsAString & aLastStyleSheetSet) override { return _to GetLastStyleSheetSet(aLastStyleSheetSet); } \
  NS_IMETHOD GetStyleSheetSets(nsISupports * *aStyleSheetSets) override { return _to GetStyleSheetSets(aStyleSheetSets); } \
  NS_IMETHOD MozEnableStyleSheetsForSet(const nsAString & name) override { return _to MozEnableStyleSheetsForSet(name); } \
  NS_IMETHOD ElementFromPoint(float x, float y, nsIDOMElement * *_retval) override { return _to ElementFromPoint(x, y, _retval); } \
  NS_IMETHOD GetContentType(nsAString & aContentType) override { return _to GetContentType(aContentType); } \
  NS_IMETHOD GetMozSyntheticDocument(bool *aMozSyntheticDocument) override { return _to GetMozSyntheticDocument(aMozSyntheticDocument); } \
  NS_IMETHOD GetCurrentScript(nsIDOMElement * *aCurrentScript) override { return _to GetCurrentScript(aCurrentScript); } \
  NS_IMETHOD ReleaseCapture(void) override { return _to ReleaseCapture(); } \
  NS_IMETHOD MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement) override { return _to MozSetImageElement(aImageElementId, aImageElement); } \
  NS_IMETHOD GetMozFullScreenElement(nsIDOMElement * *aMozFullScreenElement) override { return _to GetMozFullScreenElement(aMozFullScreenElement); } \
  NS_IMETHOD MozCancelFullScreen(void) override { return _to MozCancelFullScreen(); } \
  NS_IMETHOD GetMozFullScreen(bool *aMozFullScreen) override { return _to GetMozFullScreen(aMozFullScreen); } \
  NS_IMETHOD GetMozFullScreenEnabled(bool *aMozFullScreenEnabled) override { return _to GetMozFullScreenEnabled(aMozFullScreenEnabled); } \
  NS_IMETHOD GetMozPointerLockElement(nsIDOMElement * *aMozPointerLockElement) override { return _to GetMozPointerLockElement(aMozPointerLockElement); } \
  NS_IMETHOD CaretPositionFromPoint(float x, float y, nsISupports * *_retval) override { return _to CaretPositionFromPoint(x, y, _retval); } \
  NS_IMETHOD MozExitPointerLock(void) override { return _to MozExitPointerLock(); } \
  NS_IMETHOD GetHidden(bool *aHidden) override { return _to GetHidden(aHidden); } \
  NS_IMETHOD GetMozHidden(bool *aMozHidden) override { return _to GetMozHidden(aMozHidden); } \
  NS_IMETHOD GetVisibilityState(nsAString & aVisibilityState) override { return _to GetVisibilityState(aVisibilityState); } \
  NS_IMETHOD GetMozVisibilityState(nsAString & aMozVisibilityState) override { return _to GetMozVisibilityState(aMozVisibilityState); } \
  NS_IMETHOD GetCompatMode(nsAString & aCompatMode) override { return _to GetCompatMode(aCompatMode); } \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) override { return _to QuerySelector(selectors, _retval); } \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) override { return _to QuerySelectorAll(selectors, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENT(_to) \
  NS_IMETHOD GetDoctype(nsIDOMDocumentType * *aDoctype) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoctype(aDoctype); } \
  NS_IMETHOD GetImplementation(nsIDOMDOMImplementation * *aImplementation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImplementation(aImplementation); } \
  NS_IMETHOD GetDocumentElement(nsIDOMElement * *aDocumentElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentElement(aDocumentElement); } \
  NS_IMETHOD CreateElement(const nsAString & tagName, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateElement(tagName, _retval); } \
  NS_IMETHOD CreateDocumentFragment(nsIDOMDocumentFragment * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDocumentFragment(_retval); } \
  NS_IMETHOD CreateTextNode(const nsAString & data, nsIDOMText * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTextNode(data, _retval); } \
  NS_IMETHOD CreateComment(const nsAString & data, nsIDOMComment * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateComment(data, _retval); } \
  NS_IMETHOD CreateCDATASection(const nsAString & data, nsIDOMCDATASection * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateCDATASection(data, _retval); } \
  NS_IMETHOD CreateProcessingInstruction(const nsAString & target, const nsAString & data, nsIDOMProcessingInstruction * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateProcessingInstruction(target, data, _retval); } \
  NS_IMETHOD CreateAttribute(const nsAString & name, nsIDOMAttr * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAttribute(name, _retval); } \
  NS_IMETHOD GetElementsByTagName(const nsAString & tagname, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByTagName(tagname, _retval); } \
  NS_IMETHOD ImportNode(nsIDOMNode *importedNode, bool deep, uint8_t _argc, nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportNode(importedNode, deep, _argc, _retval); } \
  NS_IMETHOD CreateElementNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateElementNS(namespaceURI, qualifiedName, _retval); } \
  NS_IMETHOD CreateAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMAttr * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAttributeNS(namespaceURI, qualifiedName, _retval); } \
  NS_IMETHOD GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByTagNameNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD GetElementById(const nsAString & elementId, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementById(elementId, _retval); } \
  NS_IMETHOD GetInputEncoding(nsAString & aInputEncoding) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputEncoding(aInputEncoding); } \
  NS_IMETHOD GetDocumentURI(nsAString & aDocumentURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentURI(aDocumentURI); } \
  NS_IMETHOD GetURL(nsAString & aURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURL(aURL); } \
  NS_IMETHOD AdoptNode(nsIDOMNode *source, nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AdoptNode(source, _retval); } \
  NS_IMETHOD CreateRange(nsIDOMRange * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateRange(_retval); } \
  NS_IMETHOD CreateNodeIterator(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMNodeIterator * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNodeIterator(root, whatToShow, filter, _argc, _retval); } \
  NS_IMETHOD CreateTreeWalker(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMTreeWalker * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTreeWalker(root, whatToShow, filter, _argc, _retval); } \
  NS_IMETHOD CreateEvent(const nsAString & eventType, nsIDOMEvent * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateEvent(eventType, _retval); } \
  NS_IMETHOD GetDefaultView(nsIDOMWindow * *aDefaultView) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultView(aDefaultView); } \
  NS_IMETHOD GetCharacterSet(nsAString & aCharacterSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharacterSet(aCharacterSet); } \
  NS_IMETHOD GetDir(nsAString & aDir) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDir(aDir); } \
  NS_IMETHOD SetDir(const nsAString & aDir) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDir(aDir); } \
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetLastModified(nsAString & aLastModified) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_IMETHOD GetReferrer(nsAString & aReferrer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_IMETHOD HasFocus(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasFocus(_retval); } \
  NS_IMETHOD GetActiveElement(nsIDOMElement * *aActiveElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveElement(aActiveElement); } \
  NS_IMETHOD GetElementsByClassName(const nsAString & classes, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByClassName(classes, _retval); } \
  NS_IMETHOD GetStyleSheets(nsIDOMStyleSheetList * *aStyleSheets) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleSheets(aStyleSheets); } \
  NS_IMETHOD GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferredStyleSheetSet(aPreferredStyleSheetSet); } \
  NS_IMETHOD GetMozSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozSelectedStyleSheetSet(aSelectedStyleSheetSet); } \
  NS_IMETHOD SetMozSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozSelectedStyleSheetSet(aSelectedStyleSheetSet); } \
  NS_IMETHOD GetLastStyleSheetSet(nsAString & aLastStyleSheetSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastStyleSheetSet(aLastStyleSheetSet); } \
  NS_IMETHOD GetStyleSheetSets(nsISupports * *aStyleSheetSets) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleSheetSets(aStyleSheetSets); } \
  NS_IMETHOD MozEnableStyleSheetsForSet(const nsAString & name) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozEnableStyleSheetsForSet(name); } \
  NS_IMETHOD ElementFromPoint(float x, float y, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ElementFromPoint(x, y, _retval); } \
  NS_IMETHOD GetContentType(nsAString & aContentType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_IMETHOD GetMozSyntheticDocument(bool *aMozSyntheticDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozSyntheticDocument(aMozSyntheticDocument); } \
  NS_IMETHOD GetCurrentScript(nsIDOMElement * *aCurrentScript) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentScript(aCurrentScript); } \
  NS_IMETHOD ReleaseCapture(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseCapture(); } \
  NS_IMETHOD MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozSetImageElement(aImageElementId, aImageElement); } \
  NS_IMETHOD GetMozFullScreenElement(nsIDOMElement * *aMozFullScreenElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFullScreenElement(aMozFullScreenElement); } \
  NS_IMETHOD MozCancelFullScreen(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCancelFullScreen(); } \
  NS_IMETHOD GetMozFullScreen(bool *aMozFullScreen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFullScreen(aMozFullScreen); } \
  NS_IMETHOD GetMozFullScreenEnabled(bool *aMozFullScreenEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFullScreenEnabled(aMozFullScreenEnabled); } \
  NS_IMETHOD GetMozPointerLockElement(nsIDOMElement * *aMozPointerLockElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPointerLockElement(aMozPointerLockElement); } \
  NS_IMETHOD CaretPositionFromPoint(float x, float y, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CaretPositionFromPoint(x, y, _retval); } \
  NS_IMETHOD MozExitPointerLock(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozExitPointerLock(); } \
  NS_IMETHOD GetHidden(bool *aHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHidden(aHidden); } \
  NS_IMETHOD GetMozHidden(bool *aMozHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozHidden(aMozHidden); } \
  NS_IMETHOD GetVisibilityState(nsAString & aVisibilityState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisibilityState(aVisibilityState); } \
  NS_IMETHOD GetMozVisibilityState(nsAString & aMozVisibilityState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozVisibilityState(aMozVisibilityState); } \
  NS_IMETHOD GetCompatMode(nsAString & aCompatMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompatMode(aCompatMode); } \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QuerySelector(selectors, _retval); } \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QuerySelectorAll(selectors, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocument : public nsIDOMDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENT

  nsDOMDocument();

private:
  ~nsDOMDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMDocument, nsIDOMDocument)

nsDOMDocument::nsDOMDocument()
{
  /* member initializers and constructor code */
}

nsDOMDocument::~nsDOMDocument()
{
  /* destructor code */
}

/* readonly attribute nsIDOMDocumentType doctype; */
NS_IMETHODIMP nsDOMDocument::GetDoctype(nsIDOMDocumentType * *aDoctype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMImplementation implementation; */
NS_IMETHODIMP nsDOMDocument::GetImplementation(nsIDOMDOMImplementation * *aImplementation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement documentElement; */
NS_IMETHODIMP nsDOMDocument::GetDocumentElement(nsIDOMElement * *aDocumentElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement createElement ([Null (Stringify)] in DOMString tagName) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::CreateElement(const nsAString & tagName, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment createDocumentFragment (); */
NS_IMETHODIMP nsDOMDocument::CreateDocumentFragment(nsIDOMDocumentFragment * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMText createTextNode (in DOMString data); */
NS_IMETHODIMP nsDOMDocument::CreateTextNode(const nsAString & data, nsIDOMText * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMComment createComment (in DOMString data); */
NS_IMETHODIMP nsDOMDocument::CreateComment(const nsAString & data, nsIDOMComment * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCDATASection createCDATASection (in DOMString data) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::CreateCDATASection(const nsAString & data, nsIDOMCDATASection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMProcessingInstruction createProcessingInstruction (in DOMString target, in DOMString data) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::CreateProcessingInstruction(const nsAString & target, const nsAString & data, nsIDOMProcessingInstruction * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr createAttribute (in DOMString name) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::CreateAttribute(const nsAString & name, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByTagName (in DOMString tagname); */
NS_IMETHODIMP nsDOMDocument::GetElementsByTagName(const nsAString & tagname, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIDOMNode importNode (in nsIDOMNode importedNode, [optional] in boolean deep) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::ImportNode(nsIDOMNode *importedNode, bool deep, uint8_t _argc, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement createElementNS (in DOMString namespaceURI, [Null (Stringify)] in DOMString qualifiedName) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::CreateElementNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr createAttributeNS (in DOMString namespaceURI, in DOMString qualifiedName) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::CreateAttributeNS(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByTagNameNS (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsDOMDocument::GetElementsByTagNameNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getElementById (in DOMString elementId); */
NS_IMETHODIMP nsDOMDocument::GetElementById(const nsAString & elementId, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString inputEncoding; */
NS_IMETHODIMP nsDOMDocument::GetInputEncoding(nsAString & aInputEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString documentURI; */
NS_IMETHODIMP nsDOMDocument::GetDocumentURI(nsAString & aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString URL; */
NS_IMETHODIMP nsDOMDocument::GetURL(nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode adoptNode (in nsIDOMNode source) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::AdoptNode(nsIDOMNode *source, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMRange createRange (); */
NS_IMETHODIMP nsDOMDocument::CreateRange(nsIDOMRange * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIDOMNodeIterator createNodeIterator (in nsIDOMNode root, [optional] in unsigned long whatToShow, [optional] in nsIDOMNodeFilter filter) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::CreateNodeIterator(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMNodeIterator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIDOMTreeWalker createTreeWalker (in nsIDOMNode root, [optional] in unsigned long whatToShow, [optional] in nsIDOMNodeFilter filter) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::CreateTreeWalker(nsIDOMNode *root, uint32_t whatToShow, nsIDOMNodeFilter *filter, uint8_t _argc, nsIDOMTreeWalker * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMEvent createEvent (in DOMString eventType) raises (DOMException); */
NS_IMETHODIMP nsDOMDocument::CreateEvent(const nsAString & eventType, nsIDOMEvent * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow defaultView; */
NS_IMETHODIMP nsDOMDocument::GetDefaultView(nsIDOMWindow * *aDefaultView)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString characterSet; */
NS_IMETHODIMP nsDOMDocument::GetCharacterSet(nsAString & aCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString dir; */
NS_IMETHODIMP nsDOMDocument::GetDir(nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDocument::SetDir(const nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMLocation location; */
NS_IMETHODIMP nsDOMDocument::GetLocation(nsIDOMLocation * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString title; */
NS_IMETHODIMP nsDOMDocument::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDocument::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString readyState; */
NS_IMETHODIMP nsDOMDocument::GetReadyState(nsAString & aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastModified; */
NS_IMETHODIMP nsDOMDocument::GetLastModified(nsAString & aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString referrer; */
NS_IMETHODIMP nsDOMDocument::GetReferrer(nsAString & aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasFocus (); */
NS_IMETHODIMP nsDOMDocument::HasFocus(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement activeElement; */
NS_IMETHODIMP nsDOMDocument::GetActiveElement(nsIDOMElement * *aActiveElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByClassName (in DOMString classes); */
NS_IMETHODIMP nsDOMDocument::GetElementsByClassName(const nsAString & classes, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMStyleSheetList styleSheets; */
NS_IMETHODIMP nsDOMDocument::GetStyleSheets(nsIDOMStyleSheetList * *aStyleSheets)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString preferredStyleSheetSet; */
NS_IMETHODIMP nsDOMDocument::GetPreferredStyleSheetSet(nsAString & aPreferredStyleSheetSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(MozSelectedStyleSheetSet)] attribute DOMString selectedStyleSheetSet; */
NS_IMETHODIMP nsDOMDocument::GetMozSelectedStyleSheetSet(nsAString & aSelectedStyleSheetSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDocument::SetMozSelectedStyleSheetSet(const nsAString & aSelectedStyleSheetSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastStyleSheetSet; */
NS_IMETHODIMP nsDOMDocument::GetLastStyleSheetSet(nsAString & aLastStyleSheetSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports styleSheetSets; */
NS_IMETHODIMP nsDOMDocument::GetStyleSheetSets(nsISupports * *aStyleSheetSets)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(MozEnableStyleSheetsForSet)] void enableStyleSheetsForSet (in DOMString name); */
NS_IMETHODIMP nsDOMDocument::MozEnableStyleSheetsForSet(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement elementFromPoint (in float x, in float y); */
NS_IMETHODIMP nsDOMDocument::ElementFromPoint(float x, float y, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString contentType; */
NS_IMETHODIMP nsDOMDocument::GetContentType(nsAString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozSyntheticDocument; */
NS_IMETHODIMP nsDOMDocument::GetMozSyntheticDocument(bool *aMozSyntheticDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement currentScript; */
NS_IMETHODIMP nsDOMDocument::GetCurrentScript(nsIDOMElement * *aCurrentScript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseCapture (); */
NS_IMETHODIMP nsDOMDocument::ReleaseCapture()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozSetImageElement (in DOMString aImageElementId, in nsIDOMElement aImageElement); */
NS_IMETHODIMP nsDOMDocument::MozSetImageElement(const nsAString & aImageElementId, nsIDOMElement *aImageElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement mozFullScreenElement; */
NS_IMETHODIMP nsDOMDocument::GetMozFullScreenElement(nsIDOMElement * *aMozFullScreenElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozCancelFullScreen (); */
NS_IMETHODIMP nsDOMDocument::MozCancelFullScreen()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozFullScreen; */
NS_IMETHODIMP nsDOMDocument::GetMozFullScreen(bool *aMozFullScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozFullScreenEnabled; */
NS_IMETHODIMP nsDOMDocument::GetMozFullScreenEnabled(bool *aMozFullScreenEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement mozPointerLockElement; */
NS_IMETHODIMP nsDOMDocument::GetMozPointerLockElement(nsIDOMElement * *aMozPointerLockElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports caretPositionFromPoint (in float x, in float y); */
NS_IMETHODIMP nsDOMDocument::CaretPositionFromPoint(float x, float y, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozExitPointerLock (); */
NS_IMETHODIMP nsDOMDocument::MozExitPointerLock()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hidden; */
NS_IMETHODIMP nsDOMDocument::GetHidden(bool *aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozHidden; */
NS_IMETHODIMP nsDOMDocument::GetMozHidden(bool *aMozHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString visibilityState; */
NS_IMETHODIMP nsDOMDocument::GetVisibilityState(nsAString & aVisibilityState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mozVisibilityState; */
NS_IMETHODIMP nsDOMDocument::GetMozVisibilityState(nsAString & aMozVisibilityState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString compatMode; */
NS_IMETHODIMP nsDOMDocument::GetCompatMode(nsAString & aCompatMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement querySelector ([Null (Stringify)] in DOMString selectors); */
NS_IMETHODIMP nsDOMDocument::QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList querySelectorAll ([Null (Stringify)] in DOMString selectors); */
NS_IMETHODIMP nsDOMDocument::QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocument_h__ */
