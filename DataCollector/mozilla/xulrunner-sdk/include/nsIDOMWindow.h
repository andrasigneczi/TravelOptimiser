/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMWindow.idl
 */

#ifndef __gen_nsIDOMWindow_h__
#define __gen_nsIDOMWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFrameRequestCallback; /* forward declaration */

class nsIControllers; /* forward declaration */

class nsIDOMBlob; /* forward declaration */

class nsIDOMLocation; /* forward declaration */

class nsIDOMOfflineResourceList; /* forward declaration */

class nsIPrompt; /* forward declaration */

class nsISelection; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMWindow */
#define NS_IDOMWINDOW_IID_STR "8146f3fc-9fc1-47c5-85ef-95d686e4ca6d"

#define NS_IDOMWINDOW_IID \
  {0x8146f3fc, 0x9fc1, 0x47c5, \
    { 0x85, 0xef, 0x95, 0xd6, 0x86, 0xe4, 0xca, 0x6d }}

class nsIDOMWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOW_IID)

  /* readonly attribute nsIDOMWindow window; */
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) = 0;

  /* readonly attribute nsIDOMWindow self; */
  NS_IMETHOD GetSelf(nsIDOMWindow * *aSelf) = 0;

  /* readonly attribute nsIDOMDocument document; */
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) = 0;

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* readonly attribute nsIDOMLocation location; */
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) = 0;

  /* readonly attribute nsISupports history; */
  NS_IMETHOD GetHistory(nsISupports * *aHistory) = 0;

  /* readonly attribute nsISupports locationbar; */
  NS_IMETHOD GetLocationbar(nsISupports * *aLocationbar) = 0;

  /* readonly attribute nsISupports menubar; */
  NS_IMETHOD GetMenubar(nsISupports * *aMenubar) = 0;

  /* readonly attribute nsISupports personalbar; */
  NS_IMETHOD GetPersonalbar(nsISupports * *aPersonalbar) = 0;

  /* readonly attribute nsISupports scrollbars; */
  NS_IMETHOD GetScrollbars(nsISupports * *aScrollbars) = 0;

  /* readonly attribute nsISupports statusbar; */
  NS_IMETHOD GetStatusbar(nsISupports * *aStatusbar) = 0;

  /* readonly attribute nsISupports toolbar; */
  NS_IMETHOD GetToolbar(nsISupports * *aToolbar) = 0;

  /* attribute DOMString status; */
  NS_IMETHOD GetStatus(nsAString & aStatus) = 0;
  NS_IMETHOD SetStatus(const nsAString & aStatus) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

  /* void focus (); */
  NS_IMETHOD Focus(void) = 0;

  /* void blur (); */
  NS_IMETHOD Blur(void) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* [binaryname(ScriptableTop)] readonly attribute nsIDOMWindow top; */
  NS_IMETHOD GetScriptableTop(nsIDOMWindow * *aTop) = 0;

  /* [noscript] readonly attribute nsIDOMWindow realTop; */
  NS_IMETHOD GetRealTop(nsIDOMWindow * *aRealTop) = 0;

   nsresult GetTop(nsIDOMWindow **aWindow)
  {
    return GetRealTop(aWindow);
  }
    /* [binaryname(ScriptableParent)] readonly attribute nsIDOMWindow parent; */
  NS_IMETHOD GetScriptableParent(nsIDOMWindow * *aParent) = 0;

  /* [noscript] readonly attribute nsIDOMWindow realParent; */
  NS_IMETHOD GetRealParent(nsIDOMWindow * *aRealParent) = 0;

   inline nsresult GetParent(nsIDOMWindow **aWindow)
  {
    return GetRealParent(aWindow);
  }
    /* [binaryname(ScriptableOpener),implicit_jscontext] attribute jsval opener; */
  NS_IMETHOD GetScriptableOpener(JSContext* cx, JS::MutableHandleValue aOpener) = 0;
  NS_IMETHOD SetScriptableOpener(JSContext* cx, JS::HandleValue aOpener) = 0;

  /* [binaryname(Opener),noscript] attribute nsIDOMWindow openerWindow; */
  NS_IMETHOD GetOpener(nsIDOMWindow * *aOpenerWindow) = 0;
  NS_IMETHOD SetOpener(nsIDOMWindow *aOpenerWindow) = 0;

  /* [binaryname(ScriptableFrameElement)] readonly attribute nsIDOMElement frameElement; */
  NS_IMETHOD GetScriptableFrameElement(nsIDOMElement * *aFrameElement) = 0;

  /* [noscript] readonly attribute nsIDOMElement realFrameElement; */
  NS_IMETHOD GetRealFrameElement(nsIDOMElement * *aRealFrameElement) = 0;

   inline nsresult GetFrameElement(nsIDOMElement **aElement)
  {
    return GetRealFrameElement(aElement);
  }
    /* readonly attribute nsIDOMNavigator navigator; */
  NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) = 0;

  /* readonly attribute nsIDOMOfflineResourceList applicationCache; */
  NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache) = 0;

  /* void alert ([optional, Null (Stringify)] in DOMString text); */
  NS_IMETHOD Alert(const nsAString & text) = 0;

  /* boolean confirm ([optional] in DOMString text); */
  NS_IMETHOD Confirm(const nsAString & text, bool *_retval) = 0;

  /* DOMString prompt ([optional] in DOMString aMessage, [optional] in DOMString aInitial); */
  NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval) = 0;

  /* void print (); */
  NS_IMETHOD Print(void) = 0;

  /* [optional_argc] nsIVariant showModalDialog (in DOMString aURI, [optional] in nsIVariant aArgs, [optional] in DOMString aOptions); */
  NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, uint8_t _argc, nsIVariant * *_retval) = 0;

  /* [binaryname(PostMessageMoz),implicit_jscontext] void postMessage (in jsval message, in DOMString targetOrigin, [optional] in jsval transfer); */
  NS_IMETHOD PostMessageMoz(JS::HandleValue message, const nsAString & targetOrigin, JS::HandleValue transfer, JSContext* cx) = 0;

  /* DOMString atob (in DOMString aAsciiString); */
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) = 0;

  /* DOMString btoa (in DOMString aBase64Data); */
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) = 0;

  /* readonly attribute nsISupports sessionStorage; */
  NS_IMETHOD GetSessionStorage(nsISupports * *aSessionStorage) = 0;

  /* readonly attribute nsISupports localStorage; */
  NS_IMETHOD GetLocalStorage(nsISupports * *aLocalStorage) = 0;

  /* readonly attribute nsISupports indexedDB; */
  NS_IMETHOD GetIndexedDB(nsISupports * *aIndexedDB) = 0;

  /* nsISelection getSelection (); */
  NS_IMETHOD GetSelection(nsISelection * *_retval) = 0;

  /* nsISupports matchMedia (in DOMString media_query_list); */
  NS_IMETHOD MatchMedia(const nsAString & media_query_list, nsISupports * *_retval) = 0;

  /* readonly attribute nsIDOMScreen screen; */
  NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) = 0;

  /* attribute long innerWidth; */
  NS_IMETHOD GetInnerWidth(int32_t *aInnerWidth) = 0;
  NS_IMETHOD SetInnerWidth(int32_t aInnerWidth) = 0;

  /* attribute long innerHeight; */
  NS_IMETHOD GetInnerHeight(int32_t *aInnerHeight) = 0;
  NS_IMETHOD SetInnerHeight(int32_t aInnerHeight) = 0;

  /* readonly attribute long scrollX; */
  NS_IMETHOD GetScrollX(int32_t *aScrollX) = 0;

  /* readonly attribute long pageXOffset; */
  NS_IMETHOD GetPageXOffset(int32_t *aPageXOffset) = 0;

  /* readonly attribute long scrollY; */
  NS_IMETHOD GetScrollY(int32_t *aScrollY) = 0;

  /* readonly attribute long pageYOffset; */
  NS_IMETHOD GetPageYOffset(int32_t *aPageYOffset) = 0;

  /* void scroll (in long xScroll, in long yScroll); */
  NS_IMETHOD Scroll(int32_t xScroll, int32_t yScroll) = 0;

  /* void scrollTo (in long xScroll, in long yScroll); */
  NS_IMETHOD ScrollTo(int32_t xScroll, int32_t yScroll) = 0;

  /* void scrollBy (in long xScrollDif, in long yScrollDif); */
  NS_IMETHOD ScrollBy(int32_t xScrollDif, int32_t yScrollDif) = 0;

  /* attribute long screenX; */
  NS_IMETHOD GetScreenX(int32_t *aScreenX) = 0;
  NS_IMETHOD SetScreenX(int32_t aScreenX) = 0;

  /* attribute long screenY; */
  NS_IMETHOD GetScreenY(int32_t *aScreenY) = 0;
  NS_IMETHOD SetScreenY(int32_t aScreenY) = 0;

  /* attribute long outerWidth; */
  NS_IMETHOD GetOuterWidth(int32_t *aOuterWidth) = 0;
  NS_IMETHOD SetOuterWidth(int32_t aOuterWidth) = 0;

  /* attribute long outerHeight; */
  NS_IMETHOD GetOuterHeight(int32_t *aOuterHeight) = 0;
  NS_IMETHOD SetOuterHeight(int32_t aOuterHeight) = 0;

  /* nsIDOMCSSStyleDeclaration getComputedStyle (in nsIDOMElement elt, [optional] in DOMString pseudoElt); */
  NS_IMETHOD GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) = 0;

  /* nsIDOMCSSStyleDeclaration getDefaultComputedStyle (in nsIDOMElement elt, [optional] in DOMString pseudoElt); */
  NS_IMETHOD GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) = 0;

  /* [noscript] readonly attribute nsIDOMEventTarget windowRoot; */
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget * *aWindowRoot) = 0;

  /* [noscript] readonly attribute nsIDOMWindowCollection frames; */
  NS_IMETHOD GetFrames(nsIDOMWindowCollection * *aFrames) = 0;

  /* [noscript] attribute float textZoom; */
  NS_IMETHOD GetTextZoom(float *aTextZoom) = 0;
  NS_IMETHOD SetTextZoom(float aTextZoom) = 0;

  /* void scrollByLines (in long numLines); */
  NS_IMETHOD ScrollByLines(int32_t numLines) = 0;

  /* void scrollByPages (in long numPages); */
  NS_IMETHOD ScrollByPages(int32_t numPages) = 0;

  /* void sizeToContent (); */
  NS_IMETHOD SizeToContent(void) = 0;

  /* [noscript] readonly attribute nsIDOMWindow content; */
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) = 0;

  /* [noscript] readonly attribute nsIPrompt prompter; */
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) = 0;

  /* readonly attribute boolean closed; */
  NS_IMETHOD GetClosed(bool *aClosed) = 0;

  /* readonly attribute nsIDOMCrypto crypto; */
  NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) = 0;

  /* [noscript] readonly attribute nsIControllers controllers; */
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) = 0;

  /* readonly attribute float mozInnerScreenX; */
  NS_IMETHOD GetMozInnerScreenX(float *aMozInnerScreenX) = 0;

  /* readonly attribute float mozInnerScreenY; */
  NS_IMETHOD GetMozInnerScreenY(float *aMozInnerScreenY) = 0;

  /* readonly attribute float devicePixelRatio; */
  NS_IMETHOD GetDevicePixelRatio(float *aDevicePixelRatio) = 0;

  /* readonly attribute long scrollMaxX; */
  NS_IMETHOD GetScrollMaxX(int32_t *aScrollMaxX) = 0;

  /* readonly attribute long scrollMaxY; */
  NS_IMETHOD GetScrollMaxY(int32_t *aScrollMaxY) = 0;

  /* attribute boolean fullScreen; */
  NS_IMETHOD GetFullScreen(bool *aFullScreen) = 0;
  NS_IMETHOD SetFullScreen(bool aFullScreen) = 0;

  /* void back (); */
  NS_IMETHOD Back(void) = 0;

  /* void forward (); */
  NS_IMETHOD Forward(void) = 0;

  /* void home (); */
  NS_IMETHOD Home(void) = 0;

  /* void moveTo (in long xPos, in long yPos); */
  NS_IMETHOD MoveTo(int32_t xPos, int32_t yPos) = 0;

  /* void moveBy (in long xDif, in long yDif); */
  NS_IMETHOD MoveBy(int32_t xDif, int32_t yDif) = 0;

  /* void resizeTo (in long width, in long height); */
  NS_IMETHOD ResizeTo(int32_t width, int32_t height) = 0;

  /* void resizeBy (in long widthDif, in long heightDif); */
  NS_IMETHOD ResizeBy(int32_t widthDif, int32_t heightDif) = 0;

  /* [noscript] nsIDOMWindow open (in DOMString url, in DOMString name, in DOMString options); */
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) = 0;

  /* [noscript] nsIDOMWindow openDialog (in DOMString url, in DOMString name, in DOMString options, in nsISupports aExtraArgument); */
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval) = 0;

  /* void updateCommands (in DOMString action, [optional] in nsISelection sel, [optional] in short reason); */
  NS_IMETHOD UpdateCommands(const nsAString & action, nsISelection *sel, int16_t reason) = 0;

  /* boolean find ([optional] in DOMString str, [optional] in boolean caseSensitive, [optional] in boolean backwards, [optional] in boolean wrapAround, [optional] in boolean wholeWord, [optional] in boolean searchInFrames, [optional] in boolean showDialog); */
  NS_IMETHOD Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval) = 0;

  /* readonly attribute unsigned long long mozPaintCount; */
  NS_IMETHOD GetMozPaintCount(uint64_t *aMozPaintCount) = 0;

  /* long mozRequestAnimationFrame ([optional] in nsIFrameRequestCallback aCallback); */
  NS_IMETHOD MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval) = 0;

  /* [implicit_jscontext] long requestAnimationFrame (in jsval aCallback); */
  NS_IMETHOD RequestAnimationFrame(JS::HandleValue aCallback, JSContext* cx, int32_t *_retval) = 0;

  /* void mozCancelAnimationFrame (in long aHandle); */
  NS_IMETHOD MozCancelAnimationFrame(int32_t aHandle) = 0;

  /* void mozCancelRequestAnimationFrame (in long aHandle); */
  NS_IMETHOD MozCancelRequestAnimationFrame(int32_t aHandle) = 0;

  /* void cancelAnimationFrame (in long aHandle); */
  NS_IMETHOD CancelAnimationFrame(int32_t aHandle) = 0;

  /* readonly attribute long long mozAnimationStartTime; */
  NS_IMETHOD GetMozAnimationStartTime(int64_t *aMozAnimationStartTime) = 0;

  /* [implicit_jscontext] attribute jsval console; */
  NS_IMETHOD GetConsole(JSContext* cx, JS::MutableHandleValue aConsole) = 0;
  NS_IMETHOD SetConsole(JSContext* cx, JS::HandleValue aConsole) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindow, NS_IDOMWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOW \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override; \
  NS_IMETHOD GetSelf(nsIDOMWindow * *aSelf) override; \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override; \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD SetName(const nsAString & aName) override; \
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) override; \
  NS_IMETHOD GetHistory(nsISupports * *aHistory) override; \
  NS_IMETHOD GetLocationbar(nsISupports * *aLocationbar) override; \
  NS_IMETHOD GetMenubar(nsISupports * *aMenubar) override; \
  NS_IMETHOD GetPersonalbar(nsISupports * *aPersonalbar) override; \
  NS_IMETHOD GetScrollbars(nsISupports * *aScrollbars) override; \
  NS_IMETHOD GetStatusbar(nsISupports * *aStatusbar) override; \
  NS_IMETHOD GetToolbar(nsISupports * *aToolbar) override; \
  NS_IMETHOD GetStatus(nsAString & aStatus) override; \
  NS_IMETHOD SetStatus(const nsAString & aStatus) override; \
  NS_IMETHOD Close(void) override; \
  NS_IMETHOD Stop(void) override; \
  NS_IMETHOD Focus(void) override; \
  NS_IMETHOD Blur(void) override; \
  NS_IMETHOD GetLength(uint32_t *aLength) override; \
  NS_IMETHOD GetScriptableTop(nsIDOMWindow * *aTop) override; \
  NS_IMETHOD GetRealTop(nsIDOMWindow * *aRealTop) override; \
  NS_IMETHOD GetScriptableParent(nsIDOMWindow * *aParent) override; \
  NS_IMETHOD GetRealParent(nsIDOMWindow * *aRealParent) override; \
  NS_IMETHOD GetScriptableOpener(JSContext* cx, JS::MutableHandleValue aOpener) override; \
  NS_IMETHOD SetScriptableOpener(JSContext* cx, JS::HandleValue aOpener) override; \
  NS_IMETHOD GetOpener(nsIDOMWindow * *aOpenerWindow) override; \
  NS_IMETHOD SetOpener(nsIDOMWindow *aOpenerWindow) override; \
  NS_IMETHOD GetScriptableFrameElement(nsIDOMElement * *aFrameElement) override; \
  NS_IMETHOD GetRealFrameElement(nsIDOMElement * *aRealFrameElement) override; \
  NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) override; \
  NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache) override; \
  NS_IMETHOD Alert(const nsAString & text) override; \
  NS_IMETHOD Confirm(const nsAString & text, bool *_retval) override; \
  NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval) override; \
  NS_IMETHOD Print(void) override; \
  NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, uint8_t _argc, nsIVariant * *_retval) override; \
  NS_IMETHOD PostMessageMoz(JS::HandleValue message, const nsAString & targetOrigin, JS::HandleValue transfer, JSContext* cx) override; \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) override; \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) override; \
  NS_IMETHOD GetSessionStorage(nsISupports * *aSessionStorage) override; \
  NS_IMETHOD GetLocalStorage(nsISupports * *aLocalStorage) override; \
  NS_IMETHOD GetIndexedDB(nsISupports * *aIndexedDB) override; \
  NS_IMETHOD GetSelection(nsISelection * *_retval) override; \
  NS_IMETHOD MatchMedia(const nsAString & media_query_list, nsISupports * *_retval) override; \
  NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) override; \
  NS_IMETHOD GetInnerWidth(int32_t *aInnerWidth) override; \
  NS_IMETHOD SetInnerWidth(int32_t aInnerWidth) override; \
  NS_IMETHOD GetInnerHeight(int32_t *aInnerHeight) override; \
  NS_IMETHOD SetInnerHeight(int32_t aInnerHeight) override; \
  NS_IMETHOD GetScrollX(int32_t *aScrollX) override; \
  NS_IMETHOD GetPageXOffset(int32_t *aPageXOffset) override; \
  NS_IMETHOD GetScrollY(int32_t *aScrollY) override; \
  NS_IMETHOD GetPageYOffset(int32_t *aPageYOffset) override; \
  NS_IMETHOD Scroll(int32_t xScroll, int32_t yScroll) override; \
  NS_IMETHOD ScrollTo(int32_t xScroll, int32_t yScroll) override; \
  NS_IMETHOD ScrollBy(int32_t xScrollDif, int32_t yScrollDif) override; \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) override; \
  NS_IMETHOD SetScreenX(int32_t aScreenX) override; \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) override; \
  NS_IMETHOD SetScreenY(int32_t aScreenY) override; \
  NS_IMETHOD GetOuterWidth(int32_t *aOuterWidth) override; \
  NS_IMETHOD SetOuterWidth(int32_t aOuterWidth) override; \
  NS_IMETHOD GetOuterHeight(int32_t *aOuterHeight) override; \
  NS_IMETHOD SetOuterHeight(int32_t aOuterHeight) override; \
  NS_IMETHOD GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) override; \
  NS_IMETHOD GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) override; \
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget * *aWindowRoot) override; \
  NS_IMETHOD GetFrames(nsIDOMWindowCollection * *aFrames) override; \
  NS_IMETHOD GetTextZoom(float *aTextZoom) override; \
  NS_IMETHOD SetTextZoom(float aTextZoom) override; \
  NS_IMETHOD ScrollByLines(int32_t numLines) override; \
  NS_IMETHOD ScrollByPages(int32_t numPages) override; \
  NS_IMETHOD SizeToContent(void) override; \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) override; \
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) override; \
  NS_IMETHOD GetClosed(bool *aClosed) override; \
  NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) override; \
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) override; \
  NS_IMETHOD GetMozInnerScreenX(float *aMozInnerScreenX) override; \
  NS_IMETHOD GetMozInnerScreenY(float *aMozInnerScreenY) override; \
  NS_IMETHOD GetDevicePixelRatio(float *aDevicePixelRatio) override; \
  NS_IMETHOD GetScrollMaxX(int32_t *aScrollMaxX) override; \
  NS_IMETHOD GetScrollMaxY(int32_t *aScrollMaxY) override; \
  NS_IMETHOD GetFullScreen(bool *aFullScreen) override; \
  NS_IMETHOD SetFullScreen(bool aFullScreen) override; \
  NS_IMETHOD Back(void) override; \
  NS_IMETHOD Forward(void) override; \
  NS_IMETHOD Home(void) override; \
  NS_IMETHOD MoveTo(int32_t xPos, int32_t yPos) override; \
  NS_IMETHOD MoveBy(int32_t xDif, int32_t yDif) override; \
  NS_IMETHOD ResizeTo(int32_t width, int32_t height) override; \
  NS_IMETHOD ResizeBy(int32_t widthDif, int32_t heightDif) override; \
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) override; \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval) override; \
  NS_IMETHOD UpdateCommands(const nsAString & action, nsISelection *sel, int16_t reason) override; \
  NS_IMETHOD Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval) override; \
  NS_IMETHOD GetMozPaintCount(uint64_t *aMozPaintCount) override; \
  NS_IMETHOD MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval) override; \
  NS_IMETHOD RequestAnimationFrame(JS::HandleValue aCallback, JSContext* cx, int32_t *_retval) override; \
  NS_IMETHOD MozCancelAnimationFrame(int32_t aHandle) override; \
  NS_IMETHOD MozCancelRequestAnimationFrame(int32_t aHandle) override; \
  NS_IMETHOD CancelAnimationFrame(int32_t aHandle) override; \
  NS_IMETHOD GetMozAnimationStartTime(int64_t *aMozAnimationStartTime) override; \
  NS_IMETHOD GetConsole(JSContext* cx, JS::MutableHandleValue aConsole) override; \
  NS_IMETHOD SetConsole(JSContext* cx, JS::HandleValue aConsole) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOW(_to) \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override { return _to GetWindow(aWindow); } \
  NS_IMETHOD GetSelf(nsIDOMWindow * *aSelf) override { return _to GetSelf(aSelf); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override { return _to GetDocument(aDocument); } \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return _to SetName(aName); } \
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) override { return _to GetLocation(aLocation); } \
  NS_IMETHOD GetHistory(nsISupports * *aHistory) override { return _to GetHistory(aHistory); } \
  NS_IMETHOD GetLocationbar(nsISupports * *aLocationbar) override { return _to GetLocationbar(aLocationbar); } \
  NS_IMETHOD GetMenubar(nsISupports * *aMenubar) override { return _to GetMenubar(aMenubar); } \
  NS_IMETHOD GetPersonalbar(nsISupports * *aPersonalbar) override { return _to GetPersonalbar(aPersonalbar); } \
  NS_IMETHOD GetScrollbars(nsISupports * *aScrollbars) override { return _to GetScrollbars(aScrollbars); } \
  NS_IMETHOD GetStatusbar(nsISupports * *aStatusbar) override { return _to GetStatusbar(aStatusbar); } \
  NS_IMETHOD GetToolbar(nsISupports * *aToolbar) override { return _to GetToolbar(aToolbar); } \
  NS_IMETHOD GetStatus(nsAString & aStatus) override { return _to GetStatus(aStatus); } \
  NS_IMETHOD SetStatus(const nsAString & aStatus) override { return _to SetStatus(aStatus); } \
  NS_IMETHOD Close(void) override { return _to Close(); } \
  NS_IMETHOD Stop(void) override { return _to Stop(); } \
  NS_IMETHOD Focus(void) override { return _to Focus(); } \
  NS_IMETHOD Blur(void) override { return _to Blur(); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return _to GetLength(aLength); } \
  NS_IMETHOD GetScriptableTop(nsIDOMWindow * *aTop) override { return _to GetScriptableTop(aTop); } \
  NS_IMETHOD GetRealTop(nsIDOMWindow * *aRealTop) override { return _to GetRealTop(aRealTop); } \
  NS_IMETHOD GetScriptableParent(nsIDOMWindow * *aParent) override { return _to GetScriptableParent(aParent); } \
  NS_IMETHOD GetRealParent(nsIDOMWindow * *aRealParent) override { return _to GetRealParent(aRealParent); } \
  NS_IMETHOD GetScriptableOpener(JSContext* cx, JS::MutableHandleValue aOpener) override { return _to GetScriptableOpener(cx, aOpener); } \
  NS_IMETHOD SetScriptableOpener(JSContext* cx, JS::HandleValue aOpener) override { return _to SetScriptableOpener(cx, aOpener); } \
  NS_IMETHOD GetOpener(nsIDOMWindow * *aOpenerWindow) override { return _to GetOpener(aOpenerWindow); } \
  NS_IMETHOD SetOpener(nsIDOMWindow *aOpenerWindow) override { return _to SetOpener(aOpenerWindow); } \
  NS_IMETHOD GetScriptableFrameElement(nsIDOMElement * *aFrameElement) override { return _to GetScriptableFrameElement(aFrameElement); } \
  NS_IMETHOD GetRealFrameElement(nsIDOMElement * *aRealFrameElement) override { return _to GetRealFrameElement(aRealFrameElement); } \
  NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) override { return _to GetNavigator(aNavigator); } \
  NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache) override { return _to GetApplicationCache(aApplicationCache); } \
  NS_IMETHOD Alert(const nsAString & text) override { return _to Alert(text); } \
  NS_IMETHOD Confirm(const nsAString & text, bool *_retval) override { return _to Confirm(text, _retval); } \
  NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval) override { return _to Prompt(aMessage, aInitial, _retval); } \
  NS_IMETHOD Print(void) override { return _to Print(); } \
  NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, uint8_t _argc, nsIVariant * *_retval) override { return _to ShowModalDialog(aURI, aArgs, aOptions, _argc, _retval); } \
  NS_IMETHOD PostMessageMoz(JS::HandleValue message, const nsAString & targetOrigin, JS::HandleValue transfer, JSContext* cx) override { return _to PostMessageMoz(message, targetOrigin, transfer, cx); } \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) override { return _to Atob(aAsciiString, _retval); } \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) override { return _to Btoa(aBase64Data, _retval); } \
  NS_IMETHOD GetSessionStorage(nsISupports * *aSessionStorage) override { return _to GetSessionStorage(aSessionStorage); } \
  NS_IMETHOD GetLocalStorage(nsISupports * *aLocalStorage) override { return _to GetLocalStorage(aLocalStorage); } \
  NS_IMETHOD GetIndexedDB(nsISupports * *aIndexedDB) override { return _to GetIndexedDB(aIndexedDB); } \
  NS_IMETHOD GetSelection(nsISelection * *_retval) override { return _to GetSelection(_retval); } \
  NS_IMETHOD MatchMedia(const nsAString & media_query_list, nsISupports * *_retval) override { return _to MatchMedia(media_query_list, _retval); } \
  NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) override { return _to GetScreen(aScreen); } \
  NS_IMETHOD GetInnerWidth(int32_t *aInnerWidth) override { return _to GetInnerWidth(aInnerWidth); } \
  NS_IMETHOD SetInnerWidth(int32_t aInnerWidth) override { return _to SetInnerWidth(aInnerWidth); } \
  NS_IMETHOD GetInnerHeight(int32_t *aInnerHeight) override { return _to GetInnerHeight(aInnerHeight); } \
  NS_IMETHOD SetInnerHeight(int32_t aInnerHeight) override { return _to SetInnerHeight(aInnerHeight); } \
  NS_IMETHOD GetScrollX(int32_t *aScrollX) override { return _to GetScrollX(aScrollX); } \
  NS_IMETHOD GetPageXOffset(int32_t *aPageXOffset) override { return _to GetPageXOffset(aPageXOffset); } \
  NS_IMETHOD GetScrollY(int32_t *aScrollY) override { return _to GetScrollY(aScrollY); } \
  NS_IMETHOD GetPageYOffset(int32_t *aPageYOffset) override { return _to GetPageYOffset(aPageYOffset); } \
  NS_IMETHOD Scroll(int32_t xScroll, int32_t yScroll) override { return _to Scroll(xScroll, yScroll); } \
  NS_IMETHOD ScrollTo(int32_t xScroll, int32_t yScroll) override { return _to ScrollTo(xScroll, yScroll); } \
  NS_IMETHOD ScrollBy(int32_t xScrollDif, int32_t yScrollDif) override { return _to ScrollBy(xScrollDif, yScrollDif); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) override { return _to GetScreenX(aScreenX); } \
  NS_IMETHOD SetScreenX(int32_t aScreenX) override { return _to SetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) override { return _to GetScreenY(aScreenY); } \
  NS_IMETHOD SetScreenY(int32_t aScreenY) override { return _to SetScreenY(aScreenY); } \
  NS_IMETHOD GetOuterWidth(int32_t *aOuterWidth) override { return _to GetOuterWidth(aOuterWidth); } \
  NS_IMETHOD SetOuterWidth(int32_t aOuterWidth) override { return _to SetOuterWidth(aOuterWidth); } \
  NS_IMETHOD GetOuterHeight(int32_t *aOuterHeight) override { return _to GetOuterHeight(aOuterHeight); } \
  NS_IMETHOD SetOuterHeight(int32_t aOuterHeight) override { return _to SetOuterHeight(aOuterHeight); } \
  NS_IMETHOD GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) override { return _to GetComputedStyle(elt, pseudoElt, _retval); } \
  NS_IMETHOD GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) override { return _to GetDefaultComputedStyle(elt, pseudoElt, _retval); } \
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget * *aWindowRoot) override { return _to GetWindowRoot(aWindowRoot); } \
  NS_IMETHOD GetFrames(nsIDOMWindowCollection * *aFrames) override { return _to GetFrames(aFrames); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) override { return _to GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) override { return _to SetTextZoom(aTextZoom); } \
  NS_IMETHOD ScrollByLines(int32_t numLines) override { return _to ScrollByLines(numLines); } \
  NS_IMETHOD ScrollByPages(int32_t numPages) override { return _to ScrollByPages(numPages); } \
  NS_IMETHOD SizeToContent(void) override { return _to SizeToContent(); } \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) override { return _to GetContent(aContent); } \
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) override { return _to GetPrompter(aPrompter); } \
  NS_IMETHOD GetClosed(bool *aClosed) override { return _to GetClosed(aClosed); } \
  NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) override { return _to GetCrypto(aCrypto); } \
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) override { return _to GetControllers(aControllers); } \
  NS_IMETHOD GetMozInnerScreenX(float *aMozInnerScreenX) override { return _to GetMozInnerScreenX(aMozInnerScreenX); } \
  NS_IMETHOD GetMozInnerScreenY(float *aMozInnerScreenY) override { return _to GetMozInnerScreenY(aMozInnerScreenY); } \
  NS_IMETHOD GetDevicePixelRatio(float *aDevicePixelRatio) override { return _to GetDevicePixelRatio(aDevicePixelRatio); } \
  NS_IMETHOD GetScrollMaxX(int32_t *aScrollMaxX) override { return _to GetScrollMaxX(aScrollMaxX); } \
  NS_IMETHOD GetScrollMaxY(int32_t *aScrollMaxY) override { return _to GetScrollMaxY(aScrollMaxY); } \
  NS_IMETHOD GetFullScreen(bool *aFullScreen) override { return _to GetFullScreen(aFullScreen); } \
  NS_IMETHOD SetFullScreen(bool aFullScreen) override { return _to SetFullScreen(aFullScreen); } \
  NS_IMETHOD Back(void) override { return _to Back(); } \
  NS_IMETHOD Forward(void) override { return _to Forward(); } \
  NS_IMETHOD Home(void) override { return _to Home(); } \
  NS_IMETHOD MoveTo(int32_t xPos, int32_t yPos) override { return _to MoveTo(xPos, yPos); } \
  NS_IMETHOD MoveBy(int32_t xDif, int32_t yDif) override { return _to MoveBy(xDif, yDif); } \
  NS_IMETHOD ResizeTo(int32_t width, int32_t height) override { return _to ResizeTo(width, height); } \
  NS_IMETHOD ResizeBy(int32_t widthDif, int32_t heightDif) override { return _to ResizeBy(widthDif, heightDif); } \
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) override { return _to Open(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval) override { return _to OpenDialog(url, name, options, aExtraArgument, _retval); } \
  NS_IMETHOD UpdateCommands(const nsAString & action, nsISelection *sel, int16_t reason) override { return _to UpdateCommands(action, sel, reason); } \
  NS_IMETHOD Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval) override { return _to Find(str, caseSensitive, backwards, wrapAround, wholeWord, searchInFrames, showDialog, _retval); } \
  NS_IMETHOD GetMozPaintCount(uint64_t *aMozPaintCount) override { return _to GetMozPaintCount(aMozPaintCount); } \
  NS_IMETHOD MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval) override { return _to MozRequestAnimationFrame(aCallback, _retval); } \
  NS_IMETHOD RequestAnimationFrame(JS::HandleValue aCallback, JSContext* cx, int32_t *_retval) override { return _to RequestAnimationFrame(aCallback, cx, _retval); } \
  NS_IMETHOD MozCancelAnimationFrame(int32_t aHandle) override { return _to MozCancelAnimationFrame(aHandle); } \
  NS_IMETHOD MozCancelRequestAnimationFrame(int32_t aHandle) override { return _to MozCancelRequestAnimationFrame(aHandle); } \
  NS_IMETHOD CancelAnimationFrame(int32_t aHandle) override { return _to CancelAnimationFrame(aHandle); } \
  NS_IMETHOD GetMozAnimationStartTime(int64_t *aMozAnimationStartTime) override { return _to GetMozAnimationStartTime(aMozAnimationStartTime); } \
  NS_IMETHOD GetConsole(JSContext* cx, JS::MutableHandleValue aConsole) override { return _to GetConsole(cx, aConsole); } \
  NS_IMETHOD SetConsole(JSContext* cx, JS::HandleValue aConsole) override { return _to SetConsole(cx, aConsole); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOW(_to) \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD GetSelf(nsIDOMWindow * *aSelf) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelf(aSelf); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetLocation(nsIDOMLocation * *aLocation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_IMETHOD GetHistory(nsISupports * *aHistory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistory(aHistory); } \
  NS_IMETHOD GetLocationbar(nsISupports * *aLocationbar) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocationbar(aLocationbar); } \
  NS_IMETHOD GetMenubar(nsISupports * *aMenubar) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMenubar(aMenubar); } \
  NS_IMETHOD GetPersonalbar(nsISupports * *aPersonalbar) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersonalbar(aPersonalbar); } \
  NS_IMETHOD GetScrollbars(nsISupports * *aScrollbars) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollbars(aScrollbars); } \
  NS_IMETHOD GetStatusbar(nsISupports * *aStatusbar) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatusbar(aStatusbar); } \
  NS_IMETHOD GetToolbar(nsISupports * *aToolbar) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetToolbar(aToolbar); } \
  NS_IMETHOD GetStatus(nsAString & aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_IMETHOD SetStatus(const nsAString & aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStatus(aStatus); } \
  NS_IMETHOD Close(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Stop(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_IMETHOD Focus(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_IMETHOD Blur(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD GetScriptableTop(nsIDOMWindow * *aTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableTop(aTop); } \
  NS_IMETHOD GetRealTop(nsIDOMWindow * *aRealTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealTop(aRealTop); } \
  NS_IMETHOD GetScriptableParent(nsIDOMWindow * *aParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableParent(aParent); } \
  NS_IMETHOD GetRealParent(nsIDOMWindow * *aRealParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealParent(aRealParent); } \
  NS_IMETHOD GetScriptableOpener(JSContext* cx, JS::MutableHandleValue aOpener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableOpener(cx, aOpener); } \
  NS_IMETHOD SetScriptableOpener(JSContext* cx, JS::HandleValue aOpener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScriptableOpener(cx, aOpener); } \
  NS_IMETHOD GetOpener(nsIDOMWindow * *aOpenerWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOpener(aOpenerWindow); } \
  NS_IMETHOD SetOpener(nsIDOMWindow *aOpenerWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOpener(aOpenerWindow); } \
  NS_IMETHOD GetScriptableFrameElement(nsIDOMElement * *aFrameElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableFrameElement(aFrameElement); } \
  NS_IMETHOD GetRealFrameElement(nsIDOMElement * *aRealFrameElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealFrameElement(aRealFrameElement); } \
  NS_IMETHOD GetNavigator(nsIDOMNavigator * *aNavigator) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNavigator(aNavigator); } \
  NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationCache(aApplicationCache); } \
  NS_IMETHOD Alert(const nsAString & text) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Alert(text); } \
  NS_IMETHOD Confirm(const nsAString & text, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Confirm(text, _retval); } \
  NS_IMETHOD Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Prompt(aMessage, aInitial, _retval); } \
  NS_IMETHOD Print(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Print(); } \
  NS_IMETHOD ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, uint8_t _argc, nsIVariant * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowModalDialog(aURI, aArgs, aOptions, _argc, _retval); } \
  NS_IMETHOD PostMessageMoz(JS::HandleValue message, const nsAString & targetOrigin, JS::HandleValue transfer, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PostMessageMoz(message, targetOrigin, transfer, cx); } \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Atob(aAsciiString, _retval); } \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Btoa(aBase64Data, _retval); } \
  NS_IMETHOD GetSessionStorage(nsISupports * *aSessionStorage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorage(aSessionStorage); } \
  NS_IMETHOD GetLocalStorage(nsISupports * *aLocalStorage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalStorage(aLocalStorage); } \
  NS_IMETHOD GetIndexedDB(nsISupports * *aIndexedDB) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexedDB(aIndexedDB); } \
  NS_IMETHOD GetSelection(nsISelection * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(_retval); } \
  NS_IMETHOD MatchMedia(const nsAString & media_query_list, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MatchMedia(media_query_list, _retval); } \
  NS_IMETHOD GetScreen(nsIDOMScreen * *aScreen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreen(aScreen); } \
  NS_IMETHOD GetInnerWidth(int32_t *aInnerWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerWidth(aInnerWidth); } \
  NS_IMETHOD SetInnerWidth(int32_t aInnerWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInnerWidth(aInnerWidth); } \
  NS_IMETHOD GetInnerHeight(int32_t *aInnerHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerHeight(aInnerHeight); } \
  NS_IMETHOD SetInnerHeight(int32_t aInnerHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInnerHeight(aInnerHeight); } \
  NS_IMETHOD GetScrollX(int32_t *aScrollX) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollX(aScrollX); } \
  NS_IMETHOD GetPageXOffset(int32_t *aPageXOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageXOffset(aPageXOffset); } \
  NS_IMETHOD GetScrollY(int32_t *aScrollY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollY(aScrollY); } \
  NS_IMETHOD GetPageYOffset(int32_t *aPageYOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageYOffset(aPageYOffset); } \
  NS_IMETHOD Scroll(int32_t xScroll, int32_t yScroll) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Scroll(xScroll, yScroll); } \
  NS_IMETHOD ScrollTo(int32_t xScroll, int32_t yScroll) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollTo(xScroll, yScroll); } \
  NS_IMETHOD ScrollBy(int32_t xScrollDif, int32_t yScrollDif) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollBy(xScrollDif, yScrollDif); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenX(aScreenX); } \
  NS_IMETHOD SetScreenX(int32_t aScreenX) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenY(aScreenY); } \
  NS_IMETHOD SetScreenY(int32_t aScreenY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScreenY(aScreenY); } \
  NS_IMETHOD GetOuterWidth(int32_t *aOuterWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWidth(aOuterWidth); } \
  NS_IMETHOD SetOuterWidth(int32_t aOuterWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOuterWidth(aOuterWidth); } \
  NS_IMETHOD GetOuterHeight(int32_t *aOuterHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterHeight(aOuterHeight); } \
  NS_IMETHOD SetOuterHeight(int32_t aOuterHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOuterHeight(aOuterHeight); } \
  NS_IMETHOD GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComputedStyle(elt, pseudoElt, _retval); } \
  NS_IMETHOD GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultComputedStyle(elt, pseudoElt, _retval); } \
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget * *aWindowRoot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowRoot(aWindowRoot); } \
  NS_IMETHOD GetFrames(nsIDOMWindowCollection * *aFrames) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrames(aFrames); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextZoom(aTextZoom); } \
  NS_IMETHOD ScrollByLines(int32_t numLines) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByLines(numLines); } \
  NS_IMETHOD ScrollByPages(int32_t numPages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByPages(numPages); } \
  NS_IMETHOD SizeToContent(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeToContent(); } \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContent(aContent); } \
  NS_IMETHOD GetPrompter(nsIPrompt * *aPrompter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrompter(aPrompter); } \
  NS_IMETHOD GetClosed(bool *aClosed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClosed(aClosed); } \
  NS_IMETHOD GetCrypto(nsIDOMCrypto * *aCrypto) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrypto(aCrypto); } \
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllers(aControllers); } \
  NS_IMETHOD GetMozInnerScreenX(float *aMozInnerScreenX) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozInnerScreenX(aMozInnerScreenX); } \
  NS_IMETHOD GetMozInnerScreenY(float *aMozInnerScreenY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozInnerScreenY(aMozInnerScreenY); } \
  NS_IMETHOD GetDevicePixelRatio(float *aDevicePixelRatio) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDevicePixelRatio(aDevicePixelRatio); } \
  NS_IMETHOD GetScrollMaxX(int32_t *aScrollMaxX) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollMaxX(aScrollMaxX); } \
  NS_IMETHOD GetScrollMaxY(int32_t *aScrollMaxY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollMaxY(aScrollMaxY); } \
  NS_IMETHOD GetFullScreen(bool *aFullScreen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullScreen(aFullScreen); } \
  NS_IMETHOD SetFullScreen(bool aFullScreen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFullScreen(aFullScreen); } \
  NS_IMETHOD Back(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Back(); } \
  NS_IMETHOD Forward(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Forward(); } \
  NS_IMETHOD Home(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Home(); } \
  NS_IMETHOD MoveTo(int32_t xPos, int32_t yPos) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveTo(xPos, yPos); } \
  NS_IMETHOD MoveBy(int32_t xDif, int32_t yDif) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveBy(xDif, yDif); } \
  NS_IMETHOD ResizeTo(int32_t width, int32_t height) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResizeTo(width, height); } \
  NS_IMETHOD ResizeBy(int32_t widthDif, int32_t heightDif) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResizeBy(widthDif, heightDif); } \
  NS_IMETHOD Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDialog(url, name, options, aExtraArgument, _retval); } \
  NS_IMETHOD UpdateCommands(const nsAString & action, nsISelection *sel, int16_t reason) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCommands(action, sel, reason); } \
  NS_IMETHOD Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Find(str, caseSensitive, backwards, wrapAround, wholeWord, searchInFrames, showDialog, _retval); } \
  NS_IMETHOD GetMozPaintCount(uint64_t *aMozPaintCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPaintCount(aMozPaintCount); } \
  NS_IMETHOD MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRequestAnimationFrame(aCallback, _retval); } \
  NS_IMETHOD RequestAnimationFrame(JS::HandleValue aCallback, JSContext* cx, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestAnimationFrame(aCallback, cx, _retval); } \
  NS_IMETHOD MozCancelAnimationFrame(int32_t aHandle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCancelAnimationFrame(aHandle); } \
  NS_IMETHOD MozCancelRequestAnimationFrame(int32_t aHandle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCancelRequestAnimationFrame(aHandle); } \
  NS_IMETHOD CancelAnimationFrame(int32_t aHandle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelAnimationFrame(aHandle); } \
  NS_IMETHOD GetMozAnimationStartTime(int64_t *aMozAnimationStartTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozAnimationStartTime(aMozAnimationStartTime); } \
  NS_IMETHOD GetConsole(JSContext* cx, JS::MutableHandleValue aConsole) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConsole(cx, aConsole); } \
  NS_IMETHOD SetConsole(JSContext* cx, JS::HandleValue aConsole) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConsole(cx, aConsole); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindow : public nsIDOMWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOW

  nsDOMWindow();

private:
  ~nsDOMWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMWindow, nsIDOMWindow)

nsDOMWindow::nsDOMWindow()
{
  /* member initializers and constructor code */
}

nsDOMWindow::~nsDOMWindow()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow window; */
NS_IMETHODIMP nsDOMWindow::GetWindow(nsIDOMWindow * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow self; */
NS_IMETHODIMP nsDOMWindow::GetSelf(nsIDOMWindow * *aSelf)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument document; */
NS_IMETHODIMP nsDOMWindow::GetDocument(nsIDOMDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMWindow::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMLocation location; */
NS_IMETHODIMP nsDOMWindow::GetLocation(nsIDOMLocation * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports history; */
NS_IMETHODIMP nsDOMWindow::GetHistory(nsISupports * *aHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports locationbar; */
NS_IMETHODIMP nsDOMWindow::GetLocationbar(nsISupports * *aLocationbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports menubar; */
NS_IMETHODIMP nsDOMWindow::GetMenubar(nsISupports * *aMenubar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports personalbar; */
NS_IMETHODIMP nsDOMWindow::GetPersonalbar(nsISupports * *aPersonalbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports scrollbars; */
NS_IMETHODIMP nsDOMWindow::GetScrollbars(nsISupports * *aScrollbars)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports statusbar; */
NS_IMETHODIMP nsDOMWindow::GetStatusbar(nsISupports * *aStatusbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports toolbar; */
NS_IMETHODIMP nsDOMWindow::GetToolbar(nsISupports * *aToolbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString status; */
NS_IMETHODIMP nsDOMWindow::GetStatus(nsAString & aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetStatus(const nsAString & aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDOMWindow::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsDOMWindow::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMWindow::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blur (); */
NS_IMETHODIMP nsDOMWindow::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMWindow::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableTop)] readonly attribute nsIDOMWindow top; */
NS_IMETHODIMP nsDOMWindow::GetScriptableTop(nsIDOMWindow * *aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMWindow realTop; */
NS_IMETHODIMP nsDOMWindow::GetRealTop(nsIDOMWindow * *aRealTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableParent)] readonly attribute nsIDOMWindow parent; */
NS_IMETHODIMP nsDOMWindow::GetScriptableParent(nsIDOMWindow * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMWindow realParent; */
NS_IMETHODIMP nsDOMWindow::GetRealParent(nsIDOMWindow * *aRealParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableOpener),implicit_jscontext] attribute jsval opener; */
NS_IMETHODIMP nsDOMWindow::GetScriptableOpener(JSContext* cx, JS::MutableHandleValue aOpener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetScriptableOpener(JSContext* cx, JS::HandleValue aOpener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(Opener),noscript] attribute nsIDOMWindow openerWindow; */
NS_IMETHODIMP nsDOMWindow::GetOpener(nsIDOMWindow * *aOpenerWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOpener(nsIDOMWindow *aOpenerWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableFrameElement)] readonly attribute nsIDOMElement frameElement; */
NS_IMETHODIMP nsDOMWindow::GetScriptableFrameElement(nsIDOMElement * *aFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMElement realFrameElement; */
NS_IMETHODIMP nsDOMWindow::GetRealFrameElement(nsIDOMElement * *aRealFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNavigator navigator; */
NS_IMETHODIMP nsDOMWindow::GetNavigator(nsIDOMNavigator * *aNavigator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMOfflineResourceList applicationCache; */
NS_IMETHODIMP nsDOMWindow::GetApplicationCache(nsIDOMOfflineResourceList * *aApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void alert ([optional, Null (Stringify)] in DOMString text); */
NS_IMETHODIMP nsDOMWindow::Alert(const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean confirm ([optional] in DOMString text); */
NS_IMETHODIMP nsDOMWindow::Confirm(const nsAString & text, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString prompt ([optional] in DOMString aMessage, [optional] in DOMString aInitial); */
NS_IMETHODIMP nsDOMWindow::Prompt(const nsAString & aMessage, const nsAString & aInitial, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void print (); */
NS_IMETHODIMP nsDOMWindow::Print()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIVariant showModalDialog (in DOMString aURI, [optional] in nsIVariant aArgs, [optional] in DOMString aOptions); */
NS_IMETHODIMP nsDOMWindow::ShowModalDialog(const nsAString & aURI, nsIVariant *aArgs, const nsAString & aOptions, uint8_t _argc, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(PostMessageMoz),implicit_jscontext] void postMessage (in jsval message, in DOMString targetOrigin, [optional] in jsval transfer); */
NS_IMETHODIMP nsDOMWindow::PostMessageMoz(JS::HandleValue message, const nsAString & targetOrigin, JS::HandleValue transfer, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString atob (in DOMString aAsciiString); */
NS_IMETHODIMP nsDOMWindow::Atob(const nsAString & aAsciiString, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString btoa (in DOMString aBase64Data); */
NS_IMETHODIMP nsDOMWindow::Btoa(const nsAString & aBase64Data, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports sessionStorage; */
NS_IMETHODIMP nsDOMWindow::GetSessionStorage(nsISupports * *aSessionStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports localStorage; */
NS_IMETHODIMP nsDOMWindow::GetLocalStorage(nsISupports * *aLocalStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports indexedDB; */
NS_IMETHODIMP nsDOMWindow::GetIndexedDB(nsISupports * *aIndexedDB)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISelection getSelection (); */
NS_IMETHODIMP nsDOMWindow::GetSelection(nsISelection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports matchMedia (in DOMString media_query_list); */
NS_IMETHODIMP nsDOMWindow::MatchMedia(const nsAString & media_query_list, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMScreen screen; */
NS_IMETHODIMP nsDOMWindow::GetScreen(nsIDOMScreen * *aScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long innerWidth; */
NS_IMETHODIMP nsDOMWindow::GetInnerWidth(int32_t *aInnerWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetInnerWidth(int32_t aInnerWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long innerHeight; */
NS_IMETHODIMP nsDOMWindow::GetInnerHeight(int32_t *aInnerHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetInnerHeight(int32_t aInnerHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollX; */
NS_IMETHODIMP nsDOMWindow::GetScrollX(int32_t *aScrollX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageXOffset; */
NS_IMETHODIMP nsDOMWindow::GetPageXOffset(int32_t *aPageXOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollY; */
NS_IMETHODIMP nsDOMWindow::GetScrollY(int32_t *aScrollY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageYOffset; */
NS_IMETHODIMP nsDOMWindow::GetPageYOffset(int32_t *aPageYOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scroll (in long xScroll, in long yScroll); */
NS_IMETHODIMP nsDOMWindow::Scroll(int32_t xScroll, int32_t yScroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollTo (in long xScroll, in long yScroll); */
NS_IMETHODIMP nsDOMWindow::ScrollTo(int32_t xScroll, int32_t yScroll)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollBy (in long xScrollDif, in long yScrollDif); */
NS_IMETHODIMP nsDOMWindow::ScrollBy(int32_t xScrollDif, int32_t yScrollDif)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long screenX; */
NS_IMETHODIMP nsDOMWindow::GetScreenX(int32_t *aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetScreenX(int32_t aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long screenY; */
NS_IMETHODIMP nsDOMWindow::GetScreenY(int32_t *aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetScreenY(int32_t aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long outerWidth; */
NS_IMETHODIMP nsDOMWindow::GetOuterWidth(int32_t *aOuterWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOuterWidth(int32_t aOuterWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long outerHeight; */
NS_IMETHODIMP nsDOMWindow::GetOuterHeight(int32_t *aOuterHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetOuterHeight(int32_t aOuterHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCSSStyleDeclaration getComputedStyle (in nsIDOMElement elt, [optional] in DOMString pseudoElt); */
NS_IMETHODIMP nsDOMWindow::GetComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCSSStyleDeclaration getDefaultComputedStyle (in nsIDOMElement elt, [optional] in DOMString pseudoElt); */
NS_IMETHODIMP nsDOMWindow::GetDefaultComputedStyle(nsIDOMElement *elt, const nsAString & pseudoElt, nsIDOMCSSStyleDeclaration * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMEventTarget windowRoot; */
NS_IMETHODIMP nsDOMWindow::GetWindowRoot(nsIDOMEventTarget * *aWindowRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMWindowCollection frames; */
NS_IMETHODIMP nsDOMWindow::GetFrames(nsIDOMWindowCollection * *aFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute float textZoom; */
NS_IMETHODIMP nsDOMWindow::GetTextZoom(float *aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetTextZoom(float aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByLines (in long numLines); */
NS_IMETHODIMP nsDOMWindow::ScrollByLines(int32_t numLines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByPages (in long numPages); */
NS_IMETHODIMP nsDOMWindow::ScrollByPages(int32_t numPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeToContent (); */
NS_IMETHODIMP nsDOMWindow::SizeToContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMWindow content; */
NS_IMETHODIMP nsDOMWindow::GetContent(nsIDOMWindow * *aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIPrompt prompter; */
NS_IMETHODIMP nsDOMWindow::GetPrompter(nsIPrompt * *aPrompter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean closed; */
NS_IMETHODIMP nsDOMWindow::GetClosed(bool *aClosed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMCrypto crypto; */
NS_IMETHODIMP nsDOMWindow::GetCrypto(nsIDOMCrypto * *aCrypto)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIControllers controllers; */
NS_IMETHODIMP nsDOMWindow::GetControllers(nsIControllers * *aControllers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float mozInnerScreenX; */
NS_IMETHODIMP nsDOMWindow::GetMozInnerScreenX(float *aMozInnerScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float mozInnerScreenY; */
NS_IMETHODIMP nsDOMWindow::GetMozInnerScreenY(float *aMozInnerScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float devicePixelRatio; */
NS_IMETHODIMP nsDOMWindow::GetDevicePixelRatio(float *aDevicePixelRatio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollMaxX; */
NS_IMETHODIMP nsDOMWindow::GetScrollMaxX(int32_t *aScrollMaxX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long scrollMaxY; */
NS_IMETHODIMP nsDOMWindow::GetScrollMaxY(int32_t *aScrollMaxY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean fullScreen; */
NS_IMETHODIMP nsDOMWindow::GetFullScreen(bool *aFullScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetFullScreen(bool aFullScreen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void back (); */
NS_IMETHODIMP nsDOMWindow::Back()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forward (); */
NS_IMETHODIMP nsDOMWindow::Forward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void home (); */
NS_IMETHODIMP nsDOMWindow::Home()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveTo (in long xPos, in long yPos); */
NS_IMETHODIMP nsDOMWindow::MoveTo(int32_t xPos, int32_t yPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveBy (in long xDif, in long yDif); */
NS_IMETHODIMP nsDOMWindow::MoveBy(int32_t xDif, int32_t yDif)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resizeTo (in long width, in long height); */
NS_IMETHODIMP nsDOMWindow::ResizeTo(int32_t width, int32_t height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resizeBy (in long widthDif, in long heightDif); */
NS_IMETHODIMP nsDOMWindow::ResizeBy(int32_t widthDif, int32_t heightDif)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMWindow open (in DOMString url, in DOMString name, in DOMString options); */
NS_IMETHODIMP nsDOMWindow::Open(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDOMWindow openDialog (in DOMString url, in DOMString name, in DOMString options, in nsISupports aExtraArgument); */
NS_IMETHODIMP nsDOMWindow::OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsISupports *aExtraArgument, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateCommands (in DOMString action, [optional] in nsISelection sel, [optional] in short reason); */
NS_IMETHODIMP nsDOMWindow::UpdateCommands(const nsAString & action, nsISelection *sel, int16_t reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean find ([optional] in DOMString str, [optional] in boolean caseSensitive, [optional] in boolean backwards, [optional] in boolean wrapAround, [optional] in boolean wholeWord, [optional] in boolean searchInFrames, [optional] in boolean showDialog); */
NS_IMETHODIMP nsDOMWindow::Find(const nsAString & str, bool caseSensitive, bool backwards, bool wrapAround, bool wholeWord, bool searchInFrames, bool showDialog, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long mozPaintCount; */
NS_IMETHODIMP nsDOMWindow::GetMozPaintCount(uint64_t *aMozPaintCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long mozRequestAnimationFrame ([optional] in nsIFrameRequestCallback aCallback); */
NS_IMETHODIMP nsDOMWindow::MozRequestAnimationFrame(nsIFrameRequestCallback *aCallback, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] long requestAnimationFrame (in jsval aCallback); */
NS_IMETHODIMP nsDOMWindow::RequestAnimationFrame(JS::HandleValue aCallback, JSContext* cx, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozCancelAnimationFrame (in long aHandle); */
NS_IMETHODIMP nsDOMWindow::MozCancelAnimationFrame(int32_t aHandle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozCancelRequestAnimationFrame (in long aHandle); */
NS_IMETHODIMP nsDOMWindow::MozCancelRequestAnimationFrame(int32_t aHandle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelAnimationFrame (in long aHandle); */
NS_IMETHODIMP nsDOMWindow::CancelAnimationFrame(int32_t aHandle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long mozAnimationStartTime; */
NS_IMETHODIMP nsDOMWindow::GetMozAnimationStartTime(int64_t *aMozAnimationStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval console; */
NS_IMETHODIMP nsDOMWindow::GetConsole(JSContext* cx, JS::MutableHandleValue aConsole)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindow::SetConsole(JSContext* cx, JS::HandleValue aConsole)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMWindowInternal */
#define NS_IDOMWINDOWINTERNAL_IID_STR "2ec49e81-b2ba-4633-991a-f48f1e1d8800"

#define NS_IDOMWINDOWINTERNAL_IID \
  {0x2ec49e81, 0xb2ba, 0x4633, \
    { 0x99, 0x1a, 0xf4, 0x8f, 0x1e, 0x1d, 0x88, 0x00 }}

class NS_NO_VTABLE nsIDOMWindowInternal : public nsIDOMWindow {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOWINTERNAL_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindowInternal, NS_IDOMWINDOWINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOWINTERNAL \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOWINTERNAL(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOWINTERNAL(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindowInternal : public nsIDOMWindowInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOWINTERNAL

  nsDOMWindowInternal();

private:
  ~nsDOMWindowInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMWindowInternal, nsIDOMWindowInternal)

nsDOMWindowInternal::nsDOMWindowInternal()
{
  /* member initializers and constructor code */
}

nsDOMWindowInternal::~nsDOMWindowInternal()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWindow_h__ */
