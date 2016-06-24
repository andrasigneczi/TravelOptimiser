/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMWindowUtils.idl
 */

#ifndef __gen_nsIDOMWindowUtils_h__
#define __gen_nsIDOMWindowUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsColor.h"
class gfxContext;
struct nsRect;
typedef uint64_t  nsViewID;

class nsICycleCollectorListener; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMNodeList; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMHTMLCanvasElement; /* forward declaration */

class nsIDOMEvent; /* forward declaration */

class nsIDOMStyleSheet; /* forward declaration */

class nsITransferable; /* forward declaration */

class nsIQueryContentEventResult; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIDOMClientRect; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMEventTarget; /* forward declaration */

class nsIRunnable; /* forward declaration */

class nsITranslationNodeList; /* forward declaration */

class nsIJSRAIIHelper; /* forward declaration */

class nsIContentPermissionRequest; /* forward declaration */

class nsIObserver; /* forward declaration */


/* starting interface:    nsIDOMWindowUtils */
#define NS_IDOMWINDOWUTILS_IID_STR "42c529d8-54cf-4158-8b09-13ca89d7a88c"

#define NS_IDOMWINDOWUTILS_IID \
  {0x42c529d8, 0x54cf, 0x4158, \
    { 0x8b, 0x09, 0x13, 0xca, 0x89, 0xd7, 0xa8, 0x8c }}

class NS_NO_VTABLE nsIDOMWindowUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOWUTILS_IID)

  /* attribute unsigned short imageAnimationMode; */
  NS_IMETHOD GetImageAnimationMode(uint16_t *aImageAnimationMode) = 0;
  NS_IMETHOD SetImageAnimationMode(uint16_t aImageAnimationMode) = 0;

  /* readonly attribute boolean docCharsetIsForced; */
  NS_IMETHOD GetDocCharsetIsForced(bool *aDocCharsetIsForced) = 0;

  /* short getCursorType (); */
  NS_IMETHOD GetCursorType(int16_t *_retval) = 0;

  /* AString getDocumentMetadata (in AString aName); */
  NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval) = 0;

  /* unsigned long redraw ([optional] in unsigned long aCount); */
  NS_IMETHOD Redraw(uint32_t aCount, uint32_t *_retval) = 0;

  /* void updateLayerTree (); */
  NS_IMETHOD UpdateLayerTree(void) = 0;

  /* void setCSSViewport (in float aWidthPx, in float aHeightPx); */
  NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) = 0;

  /* void getViewportInfo (in uint32_t aDisplayWidth, in uint32_t aDisplayHeight, out double aDefaultZoom, out boolean aAllowZoom, out double aMinZoom, out double aMaxZoom, out uint32_t aWidth, out uint32_t aHeight, out boolean aAutoSize); */
  NS_IMETHOD GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize) = 0;

  /* void setDisplayPortForElement (in float aXPx, in float aYPx, in float aWidthPx, in float aHeightPx, in nsIDOMElement aElement, in uint32_t aPriority); */
  NS_IMETHOD SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority) = 0;

  /* void setDisplayPortMarginsForElement (in float aLeftMargin, in float aTopMargin, in float aRightMargin, in float aBottomMargin, in nsIDOMElement aElement, in uint32_t aPriority); */
  NS_IMETHOD SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, nsIDOMElement *aElement, uint32_t aPriority) = 0;

  /* void setDisplayPortBaseForElement (in int32_t aX, in int32_t aY, in int32_t aWidth, in int32_t aHeight, in nsIDOMElement aElement); */
  NS_IMETHOD SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement) = 0;

  /* void setResolution (in float aResolution); */
  NS_IMETHOD SetResolution(float aResolution) = 0;

  /* void getResolution (out float aResolution); */
  NS_IMETHOD GetResolution(float *aResolution) = 0;

  /* void setResolutionAndScaleTo (in float aResolution); */
  NS_IMETHOD SetResolutionAndScaleTo(float aResolution) = 0;

  /* readonly attribute boolean isResolutionSet; */
  NS_IMETHOD GetIsResolutionSet(bool *aIsResolutionSet) = 0;

  /* attribute boolean isFirstPaint; */
  NS_IMETHOD GetIsFirstPaint(bool *aIsFirstPaint) = 0;
  NS_IMETHOD SetIsFirstPaint(bool aIsFirstPaint) = 0;

  /* void getPresShellId (out uint32_t aPresShellId); */
  NS_IMETHOD GetPresShellId(uint32_t *aPresShellId) = 0;

  enum {
    MODIFIER_ALT = 1,
    MODIFIER_CONTROL = 2,
    MODIFIER_SHIFT = 4,
    MODIFIER_META = 8,
    MODIFIER_ALTGRAPH = 16,
    MODIFIER_CAPSLOCK = 32,
    MODIFIER_FN = 64,
    MODIFIER_FNLOCK = 128,
    MODIFIER_NUMLOCK = 256,
    MODIFIER_SCROLLLOCK = 512,
    MODIFIER_SYMBOL = 1024,
    MODIFIER_SYMBOLLOCK = 2048,
    MODIFIER_OS = 4096
  };

  /* [optional_argc] boolean sendMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in boolean aIsSynthesized); */
  NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval) = 0;

  /* [optional_argc] boolean sendPointerEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in long aPointerId, [optional] in long aWidth, [optional] in long aHeight, [optional] in long aTiltX, [optional] in long aTiltY, [optional] in boolean aIsPrimary, [optional] in boolean aIsSynthesized); */
  NS_IMETHOD SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval) = 0;

  /* boolean sendTouchEvent (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
  NS_IMETHOD SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) = 0;

  /* [optional_argc] void sendMouseEventToWindow (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in boolean aIsSynthesized); */
  NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc) = 0;

  /* [optional_argc] void sendPointerEventToWindow (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in long aPointerId, [optional] in long aWidth, [optional] in long aHeight, [optional] in long aTiltX, [optional] in long aTiltY, [optional] in boolean aIsPrimary, [optional] in boolean aIsSynthesized); */
  NS_IMETHOD SendPointerEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc) = 0;

  /* boolean sendTouchEventToWindow (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
  NS_IMETHOD SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) = 0;

  enum {
    WHEEL_EVENT_CAUSED_BY_NO_LINE_OR_PAGE_DELTA_DEVICE = 1U,
    WHEEL_EVENT_CAUSED_BY_PIXEL_ONLY_DEVICE = 1U,
    WHEEL_EVENT_CAUSED_BY_MOMENTUM = 2U,
    WHEEL_EVENT_CUSTOMIZED_BY_USER_PREFS = 4U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_X_ZERO = 16U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_X_POSITIVE = 32U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_X_NEGATIVE = 64U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_Y_ZERO = 256U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_Y_POSITIVE = 512U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_Y_NEGATIVE = 1024U
  };

  /* void sendWheelEvent (in float aX, in float aY, in double aDeltaX, in double aDeltaY, in double aDeltaZ, in unsigned long aDeltaMode, in long aModifiers, in long aLineOrPageDeltaX, in long aLineOrPageDeltaY, in unsigned long aOptions); */
  NS_IMETHOD SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions) = 0;

  enum {
    KEY_FLAG_PREVENT_DEFAULT = 1U,
    KEY_FLAG_NOT_SYNTHESIZED_FOR_TESTS = 2U,
    KEY_FLAG_LOCATION_STANDARD = 16U,
    KEY_FLAG_LOCATION_LEFT = 32U,
    KEY_FLAG_LOCATION_RIGHT = 64U,
    KEY_FLAG_LOCATION_NUMPAD = 128U
  };

  /* boolean sendKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in unsigned long aAdditionalFlags); */
  NS_IMETHOD SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval) = 0;

  /* void sendNativeKeyEvent (in long aNativeKeyboardLayout, in long aNativeKeyCode, in long aModifierFlags, in AString aCharacters, in AString aUnmodifiedCharacters, [optional] in nsIObserver aObserver); */
  NS_IMETHOD SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters, nsIObserver *aObserver) = 0;

  /* void sendNativeMouseEvent (in long aScreenX, in long aScreenY, in long aNativeMessage, in long aModifierFlags, in nsIDOMElement aElement, [optional] in nsIObserver aObserver); */
  NS_IMETHOD SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement, nsIObserver *aObserver) = 0;

  enum {
    MOUSESCROLL_PREFER_WIDGET_AT_POINT = 1U,
    MOUSESCROLL_SCROLL_LINES = 2U,
    MOUSESCROLL_WIN_SCROLL_LPARAM_NOT_NULL = 65536U
  };

  /* void sendNativeMouseScrollEvent (in long aScreenX, in long aScreenY, in unsigned long aNativeMessage, in double aDeltaX, in double aDeltaY, in double aDeltaZ, in unsigned long aModifierFlags, in unsigned long aAdditionalFlags, in nsIDOMElement aElement, [optional] in nsIObserver aObserver); */
  NS_IMETHOD SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement, nsIObserver *aObserver) = 0;

  enum {
    TOUCH_HOVER = 1,
    TOUCH_CONTACT = 2,
    TOUCH_REMOVE = 4,
    TOUCH_CANCEL = 8
  };

  /* void sendNativeTouchPoint (in unsigned long aPointerId, in unsigned long aTouchState, in long aScreenX, in long aScreenY, in double aPressure, in unsigned long aOrientation, [optional] in nsIObserver aObserver); */
  NS_IMETHOD SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation, nsIObserver *aObserver) = 0;

  /* void sendNativeTouchTap (in long aScreenX, in long aScreenY, in boolean aLongTap, [optional] in nsIObserver aObserver); */
  NS_IMETHOD SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap, nsIObserver *aObserver) = 0;

  /* void clearNativeTouchSequence ([optional] in nsIObserver aObserver); */
  NS_IMETHOD ClearNativeTouchSequence(nsIObserver *aObserver) = 0;

  /* void activateNativeMenuItemAt (in AString indexString); */
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) = 0;

  /* void forceUpdateNativeMenuAt (in AString indexString); */
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) = 0;

  /* void focus (in nsIDOMElement aElement); */
  NS_IMETHOD Focus(nsIDOMElement *aElement) = 0;

  /* void garbageCollect ([optional] in nsICycleCollectorListener aListener, [optional] in long aExtraForgetSkippableCalls); */
  NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) = 0;

  /* void cycleCollect ([optional] in nsICycleCollectorListener aListener, [optional] in long aExtraForgetSkippableCalls); */
  NS_IMETHOD CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) = 0;

  /* void runNextCollectorTimer (); */
  NS_IMETHOD RunNextCollectorTimer(void) = 0;

  /* void sendSimpleGestureEvent (in AString aType, in float aX, in float aY, in unsigned long aDirection, in double aDelta, in long aModifiers, [optional] in unsigned long aClickCount); */
  NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount) = 0;

  /* nsIDOMElement elementFromPoint (in float aX, in float aY, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
  NS_IMETHOD ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval) = 0;

  /* nsIDOMNodeList nodesFromRect (in float aX, in float aY, in float aTopSize, in float aRightSize, in float aBottomSize, in float aLeftSize, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
  NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval) = 0;

  /* nsITranslationNodeList getTranslationNodes (in nsIDOMNode aRoot); */
  NS_IMETHOD GetTranslationNodes(nsIDOMNode *aRoot, nsITranslationNodeList * *_retval) = 0;

  /* uint32_t compareCanvases (in nsIDOMHTMLCanvasElement aCanvas1, in nsIDOMHTMLCanvasElement aCanvas2, out unsigned long aMaxDifference); */
  NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval) = 0;

  /* readonly attribute boolean isMozAfterPaintPending; */
  NS_IMETHOD GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending) = 0;

  /* void suppressEventHandling (in boolean aSuppress); */
  NS_IMETHOD SuppressEventHandling(bool aSuppress) = 0;

  /* void clearMozAfterPaintEvents (); */
  NS_IMETHOD ClearMozAfterPaintEvents(void) = 0;

  /* void disableNonTestMouseEvents (in boolean aDisable); */
  NS_IMETHOD DisableNonTestMouseEvents(bool aDisable) = 0;

  /* void getScrollXY (in boolean aFlushLayout, out long aScrollX, out long aScrollY); */
  NS_IMETHOD GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY) = 0;

  /* void getScrollXYFloat (in boolean aFlushLayout, out float aScrollX, out float aScrollY); */
  NS_IMETHOD GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY) = 0;

  /* void getScrollbarSize (in boolean aFlushLayout, out long aWidth, out long aHeight); */
  NS_IMETHOD GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight) = 0;

  /* nsIDOMClientRect getBoundsWithoutFlushing (in nsIDOMElement aElement); */
  NS_IMETHOD GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval) = 0;

  /* nsIDOMClientRect getRootBounds (); */
  NS_IMETHOD GetRootBounds(nsIDOMClientRect * *_retval) = 0;

  /* readonly attribute boolean IMEIsOpen; */
  NS_IMETHOD GetIMEIsOpen(bool *aIMEIsOpen) = 0;

  enum {
    IME_STATUS_DISABLED = 0U,
    IME_STATUS_ENABLED = 1U,
    IME_STATUS_PASSWORD = 2U,
    IME_STATUS_PLUGIN = 3U
  };

  /* readonly attribute unsigned long IMEStatus; */
  NS_IMETHOD GetIMEStatus(uint32_t *aIMEStatus) = 0;

  /* readonly attribute float screenPixelsPerCSSPixel; */
  NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) = 0;

  /* readonly attribute float fullZoom; */
  NS_IMETHOD GetFullZoom(float *aFullZoom) = 0;

  /* boolean dispatchDOMEventViaPresShell (in nsIDOMNode aTarget, in nsIDOMEvent aEvent, in boolean aTrusted); */
  NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval) = 0;

  /* boolean dispatchEventToChromeOnly (in nsIDOMEventTarget aTarget, in nsIDOMEvent aEvent); */
  NS_IMETHOD DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval) = 0;

  /* [implicit_jscontext] string getClassName (in jsval aObject); */
  NS_IMETHOD GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval) = 0;

  /* void sendContentCommandEvent (in AString aType, [optional] in nsITransferable aTransferable); */
  NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) = 0;

  enum {
    QUERY_CONTENT_FLAG_USE_NATIVE_LINE_BREAK = 0U,
    QUERY_CONTENT_FLAG_USE_XP_LINE_BREAK = 1U
  };

  /* nsIQueryContentEventResult sendQueryContentEvent (in unsigned long aType, in unsigned long aOffset, in unsigned long aLength, in long aX, in long aY, [optional] in unsigned long aAdditionalFlags); */
  NS_IMETHOD SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, uint32_t aAdditionalFlags, nsIQueryContentEventResult * *_retval) = 0;

  enum {
    QUERY_SELECTED_TEXT = 3200U,
    QUERY_TEXT_CONTENT = 3201U,
    QUERY_CARET_RECT = 3203U,
    QUERY_TEXT_RECT = 3204U,
    QUERY_EDITOR_RECT = 3205U,
    QUERY_CHARACTER_AT_POINT = 3208U
  };

  /* void remoteFrameFullscreenChanged (in nsIDOMElement aFrameElement); */
  NS_IMETHOD RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement) = 0;

  /* void remoteFrameFullscreenReverted (); */
  NS_IMETHOD RemoteFrameFullscreenReverted(void) = 0;

  /* boolean handleFullscreenRequests (); */
  NS_IMETHOD HandleFullscreenRequests(bool *_retval) = 0;

  /* void exitFullscreen (); */
  NS_IMETHOD ExitFullscreen(void) = 0;

  enum {
    SELECTION_SET_FLAG_USE_NATIVE_LINE_BREAK = 0U,
    SELECTION_SET_FLAG_USE_XP_LINE_BREAK = 1U,
    SELECTION_SET_FLAG_REVERSE = 2U
  };

  /* boolean sendSelectionSetEvent (in unsigned long aOffset, in unsigned long aLength, [optional] in unsigned long aAdditionalFlags); */
  NS_IMETHOD SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, uint32_t aAdditionalFlags, bool *_retval) = 0;

  enum {
    SELECT_CHARACTER = 0U,
    SELECT_CLUSTER = 1U,
    SELECT_WORD = 2U,
    SELECT_LINE = 3U,
    SELECT_BEGINLINE = 4U,
    SELECT_ENDLINE = 5U,
    SELECT_PARAGRAPH = 6U,
    SELECT_WORDNOSPACE = 7U
  };

  /* boolean selectAtPoint (in float aX, in float aY, in unsigned long aSelectBehavior); */
  NS_IMETHOD SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval) = 0;

  /* AString getVisitedDependentComputedStyle (in nsIDOMElement aElement, in AString aPseudoElement, in AString aPropertyName); */
  NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval) = 0;

  /* readonly attribute unsigned long long outerWindowID; */
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) = 0;

  /* readonly attribute unsigned long long currentInnerWindowID; */
  NS_IMETHOD GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID) = 0;

  /* void enterModalState (); */
  NS_IMETHOD EnterModalState(void) = 0;

  /* void leaveModalState (); */
  NS_IMETHOD LeaveModalState(void) = 0;

  /* [noscript] boolean isInModalState (); */
  NS_IMETHOD IsInModalState(bool *_retval) = 0;

  /* void setDesktopModeViewport (in boolean aDesktopModeViewport); */
  NS_IMETHOD SetDesktopModeViewport(bool aDesktopModeViewport) = 0;

  /* void suspendTimeouts (); */
  NS_IMETHOD SuspendTimeouts(void) = 0;

  /* void resumeTimeouts (); */
  NS_IMETHOD ResumeTimeouts(void) = 0;

  /* readonly attribute AString layerManagerType; */
  NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) = 0;

  /* readonly attribute boolean layerManagerRemote; */
  NS_IMETHOD GetLayerManagerRemote(bool *aLayerManagerRemote) = 0;

  /* readonly attribute boolean supportsHardwareH264Decoding; */
  NS_IMETHOD GetSupportsHardwareH264Decoding(bool *aSupportsHardwareH264Decoding) = 0;

  /* void startFrameTimeRecording ([retval] out unsigned long startIndex); */
  NS_IMETHOD StartFrameTimeRecording(uint32_t *startIndex) = 0;

  /* void stopFrameTimeRecording (in unsigned long startIndex, [optional] out unsigned long frameCount, [array, size_is (frameCount), retval] out float frameIntervals); */
  NS_IMETHOD StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals) = 0;

  /* void beginTabSwitch (); */
  NS_IMETHOD BeginTabSwitch(void) = 0;

  /* readonly attribute float displayDPI; */
  NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) = 0;

  /* nsIDOMWindow getOuterWindowWithId (in unsigned long long aOuterWindowID); */
  NS_IMETHOD GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval) = 0;

  /* readonly attribute nsIDOMElement containerElement; */
  NS_IMETHOD GetContainerElement(nsIDOMElement * *aContainerElement) = 0;

  /* [noscript] void RenderDocument (in nsConstRect aRect, in uint32_t aFlags, in nscolor aBackgroundColor, in gfxContext aThebesContext); */
  NS_IMETHOD RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) = 0;

  /* void advanceTimeAndRefresh (in long long aMilliseconds); */
  NS_IMETHOD AdvanceTimeAndRefresh(int64_t aMilliseconds) = 0;

  /* void restoreNormalRefresh (); */
  NS_IMETHOD RestoreNormalRefresh(void) = 0;

  /* readonly attribute bool isTestControllingRefreshes; */
  NS_IMETHOD GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes) = 0;

  /* void setAsyncScrollOffset (in nsIDOMNode aNode, in int32_t aX, in int32_t aY); */
  NS_IMETHOD SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY) = 0;

  /* void setAsyncZoom (in nsIDOMNode aRootElement, in float aValue); */
  NS_IMETHOD SetAsyncZoom(nsIDOMNode *aRootElement, float aValue) = 0;

  /* bool flushApzRepaints (); */
  NS_IMETHOD FlushApzRepaints(bool *_retval) = 0;

  /* double computeAnimationDistance (in nsIDOMElement element, in AString property, in AString value1, in AString value2); */
  NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval) = 0;

  /* nsISupports wrapDOMFile (in nsIFile aFile); */
  NS_IMETHOD WrapDOMFile(nsIFile *aFile, nsISupports * *_retval) = 0;

  /* readonly attribute string focusedInputType; */
  NS_IMETHOD GetFocusedInputType(char * *aFocusedInputType) = 0;

  /* nsIDOMElement findElementWithViewId (in nsViewID aId); */
  NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval) = 0;

  /* nsViewID getViewId (in nsIDOMElement aElement); */
  NS_IMETHOD GetViewId(nsIDOMElement *aElement, nsViewID *_retval) = 0;

  /* boolean leafLayersPartitionWindow (); */
  NS_IMETHOD LeafLayersPartitionWindow(bool *_retval) = 0;

  /* boolean checkAndClearPaintedState (in nsIDOMElement aElement); */
  NS_IMETHOD CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval) = 0;

  /* boolean isPartOfOpaqueLayer (in nsIDOMElement aElement); */
  NS_IMETHOD IsPartOfOpaqueLayer(nsIDOMElement *aElement, bool *_retval) = 0;

  /* unsigned long numberOfAssignedPaintedLayers ([array, size_is (count)] in nsIDOMElement aElements, in uint32_t count); */
  NS_IMETHOD NumberOfAssignedPaintedLayers(nsIDOMElement **aElements, uint32_t count, uint32_t *_retval) = 0;

  /* [implicit_jscontext] long long getFileId (in jsval aFile); */
  NS_IMETHOD GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval) = 0;

  /* [implicit_jscontext] AString getFilePath (in jsval aFile); */
  NS_IMETHOD GetFilePath(JS::HandleValue aFile, JSContext* cx, nsAString & _retval) = 0;

  /* [implicit_jscontext] boolean getFileReferences (in AString aDatabaseName, in long long aId, [optional] in jsval aOptions, [optional] out long aRefCnt, [optional] out long aDBRefCnt, [optional] out long aSliceRefCnt); */
  NS_IMETHOD GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval) = 0;

  /* [implicit_jscontext] boolean isIncrementalGCEnabled (); */
  NS_IMETHOD IsIncrementalGCEnabled(JSContext* cx, bool *_retval) = 0;

  /* [implicit_jscontext] void startPCCountProfiling (); */
  NS_IMETHOD StartPCCountProfiling(JSContext* cx) = 0;

  /* [implicit_jscontext] void stopPCCountProfiling (); */
  NS_IMETHOD StopPCCountProfiling(JSContext* cx) = 0;

  /* [implicit_jscontext] void purgePCCounts (); */
  NS_IMETHOD PurgePCCounts(JSContext* cx) = 0;

  /* [implicit_jscontext] long getPCCountScriptCount (); */
  NS_IMETHOD GetPCCountScriptCount(JSContext* cx, int32_t *_retval) = 0;

  /* [implicit_jscontext] AString getPCCountScriptSummary (in long script); */
  NS_IMETHOD GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval) = 0;

  /* [implicit_jscontext] AString getPCCountScriptContents (in long script); */
  NS_IMETHOD GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval) = 0;

  /* readonly attribute boolean paintingSuppressed; */
  NS_IMETHOD GetPaintingSuppressed(bool *aPaintingSuppressed) = 0;

  /* [implicit_jscontext] readonly attribute jsval plugins; */
  NS_IMETHOD GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins) = 0;

  /* void setScrollPositionClampingScrollPortSize (in float aWidth, in float aHeight); */
  NS_IMETHOD SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight) = 0;

  /* void setContentDocumentFixedPositionMargins (in float aTop, in float aRight, in float aBottom, in float aLeft); */
  NS_IMETHOD SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft) = 0;

  /* void disableDialogs (); */
  NS_IMETHOD DisableDialogs(void) = 0;

  /* void enableDialogs (); */
  NS_IMETHOD EnableDialogs(void) = 0;

  /* bool areDialogsEnabled (); */
  NS_IMETHOD AreDialogsEnabled(bool *_retval) = 0;

  enum {
    AGENT_SHEET = 0U,
    USER_SHEET = 1U,
    AUTHOR_SHEET = 2U
  };

  /* void loadSheet (in nsIURI sheetURI, in unsigned long type); */
  NS_IMETHOD LoadSheet(nsIURI *sheetURI, uint32_t type) = 0;

  /* void loadSheetUsingURIString (in ACString sheetURI, in unsigned long type); */
  NS_IMETHOD LoadSheetUsingURIString(const nsACString & sheetURI, uint32_t type) = 0;

  /* void addSheet (in nsIDOMStyleSheet sheet, in unsigned long type); */
  NS_IMETHOD AddSheet(nsIDOMStyleSheet *sheet, uint32_t type) = 0;

  /* void removeSheet (in nsIURI sheetURI, in unsigned long type); */
  NS_IMETHOD RemoveSheet(nsIURI *sheetURI, uint32_t type) = 0;

  /* void removeSheetUsingURIString (in ACString sheetURI, in unsigned long type); */
  NS_IMETHOD RemoveSheetUsingURIString(const nsACString & sheetURI, uint32_t type) = 0;

  /* readonly attribute boolean isHandlingUserInput; */
  NS_IMETHOD GetIsHandlingUserInput(bool *aIsHandlingUserInput) = 0;

  /* void allowScriptsToClose (); */
  NS_IMETHOD AllowScriptsToClose(void) = 0;

  /* readonly attribute boolean isParentWindowMainWidgetVisible; */
  NS_IMETHOD GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible) = 0;

  /* boolean isNodeDisabledForEvents (in nsIDOMNode aNode); */
  NS_IMETHOD IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval) = 0;

  /* attribute boolean paintFlashing; */
  NS_IMETHOD GetPaintFlashing(bool *aPaintFlashing) = 0;
  NS_IMETHOD SetPaintFlashing(bool aPaintFlashing) = 0;

  /* void runInStableState (in nsIRunnable runnable); */
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) = 0;

  /* void runBeforeNextEvent (in nsIRunnable runnable); */
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) = 0;

  /* AString getOMTAStyle (in nsIDOMElement aElement, in AString aProperty); */
  NS_IMETHOD GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) = 0;

  /* float requestCompositorProperty (in AString aProperty); */
  NS_IMETHOD RequestCompositorProperty(const nsAString & aProperty, float *_retval) = 0;

  /* nsIJSRAIIHelper setHandlingUserInput (in boolean aHandlingInput); */
  NS_IMETHOD SetHandlingUserInput(bool aHandlingInput, nsIJSRAIIHelper * *_retval) = 0;

  /* [implicit_jscontext] jsval getContentAPZTestData (); */
  NS_IMETHOD GetContentAPZTestData(JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval getCompositorAPZTestData (); */
  NS_IMETHOD GetCompositorAPZTestData(JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* void postRestyleSelfEvent (in nsIDOMElement aElement); */
  NS_IMETHOD PostRestyleSelfEvent(nsIDOMElement *aElement) = 0;

  /* attribute boolean audioMuted; */
  NS_IMETHOD GetAudioMuted(bool *aAudioMuted) = 0;
  NS_IMETHOD SetAudioMuted(bool aAudioMuted) = 0;

  /* attribute float audioVolume; */
  NS_IMETHOD GetAudioVolume(float *aAudioVolume) = 0;
  NS_IMETHOD SetAudioVolume(float aAudioVolume) = 0;

  /* void xpconnectArgument (in nsIDOMWindowUtils aThis); */
  NS_IMETHOD XpconnectArgument(nsIDOMWindowUtils *aThis) = 0;

  /* void askPermission (in nsIContentPermissionRequest aRequest); */
  NS_IMETHOD AskPermission(nsIContentPermissionRequest *aRequest) = 0;

  /* readonly attribute unsigned long long framesConstructed; */
  NS_IMETHOD GetFramesConstructed(uint64_t *aFramesConstructed) = 0;

  /* readonly attribute unsigned long long framesReflowed; */
  NS_IMETHOD GetFramesReflowed(uint64_t *aFramesReflowed) = 0;

  /* void setChromeMargin (in int32_t aTop, in int32_t aRight, in int32_t aBottom, in int32_t aLeft); */
  NS_IMETHOD SetChromeMargin(int32_t aTop, int32_t aRight, int32_t aBottom, int32_t aLeft) = 0;

  /* attribute boolean serviceWorkersTestingEnabled; */
  NS_IMETHOD GetServiceWorkersTestingEnabled(bool *aServiceWorkersTestingEnabled) = 0;
  NS_IMETHOD SetServiceWorkersTestingEnabled(bool aServiceWorkersTestingEnabled) = 0;

  /* [implicit_jscontext] jsval getFrameUniformityTestData (); */
  NS_IMETHOD GetFrameUniformityTestData(JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* void enterChaosMode (); */
  NS_IMETHOD EnterChaosMode(void) = 0;

  /* void leaveChaosMode (); */
  NS_IMETHOD LeaveChaosMode(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindowUtils, NS_IDOMWINDOWUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOWUTILS \
  NS_IMETHOD GetImageAnimationMode(uint16_t *aImageAnimationMode) override; \
  NS_IMETHOD SetImageAnimationMode(uint16_t aImageAnimationMode) override; \
  NS_IMETHOD GetDocCharsetIsForced(bool *aDocCharsetIsForced) override; \
  NS_IMETHOD GetCursorType(int16_t *_retval) override; \
  NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval) override; \
  NS_IMETHOD Redraw(uint32_t aCount, uint32_t *_retval) override; \
  NS_IMETHOD UpdateLayerTree(void) override; \
  NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) override; \
  NS_IMETHOD GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize) override; \
  NS_IMETHOD SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority) override; \
  NS_IMETHOD SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, nsIDOMElement *aElement, uint32_t aPriority) override; \
  NS_IMETHOD SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement) override; \
  NS_IMETHOD SetResolution(float aResolution) override; \
  NS_IMETHOD GetResolution(float *aResolution) override; \
  NS_IMETHOD SetResolutionAndScaleTo(float aResolution) override; \
  NS_IMETHOD GetIsResolutionSet(bool *aIsResolutionSet) override; \
  NS_IMETHOD GetIsFirstPaint(bool *aIsFirstPaint) override; \
  NS_IMETHOD SetIsFirstPaint(bool aIsFirstPaint) override; \
  NS_IMETHOD GetPresShellId(uint32_t *aPresShellId) override; \
  NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval) override; \
  NS_IMETHOD SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval) override; \
  NS_IMETHOD SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) override; \
  NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc) override; \
  NS_IMETHOD SendPointerEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc) override; \
  NS_IMETHOD SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) override; \
  NS_IMETHOD SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions) override; \
  NS_IMETHOD SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval) override; \
  NS_IMETHOD SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters, nsIObserver *aObserver) override; \
  NS_IMETHOD SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement, nsIObserver *aObserver) override; \
  NS_IMETHOD SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement, nsIObserver *aObserver) override; \
  NS_IMETHOD SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation, nsIObserver *aObserver) override; \
  NS_IMETHOD SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap, nsIObserver *aObserver) override; \
  NS_IMETHOD ClearNativeTouchSequence(nsIObserver *aObserver) override; \
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) override; \
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) override; \
  NS_IMETHOD Focus(nsIDOMElement *aElement) override; \
  NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) override; \
  NS_IMETHOD CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) override; \
  NS_IMETHOD RunNextCollectorTimer(void) override; \
  NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount) override; \
  NS_IMETHOD ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval) override; \
  NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval) override; \
  NS_IMETHOD GetTranslationNodes(nsIDOMNode *aRoot, nsITranslationNodeList * *_retval) override; \
  NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval) override; \
  NS_IMETHOD GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending) override; \
  NS_IMETHOD SuppressEventHandling(bool aSuppress) override; \
  NS_IMETHOD ClearMozAfterPaintEvents(void) override; \
  NS_IMETHOD DisableNonTestMouseEvents(bool aDisable) override; \
  NS_IMETHOD GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY) override; \
  NS_IMETHOD GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY) override; \
  NS_IMETHOD GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight) override; \
  NS_IMETHOD GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval) override; \
  NS_IMETHOD GetRootBounds(nsIDOMClientRect * *_retval) override; \
  NS_IMETHOD GetIMEIsOpen(bool *aIMEIsOpen) override; \
  NS_IMETHOD GetIMEStatus(uint32_t *aIMEStatus) override; \
  NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) override; \
  NS_IMETHOD GetFullZoom(float *aFullZoom) override; \
  NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval) override; \
  NS_IMETHOD DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval) override; \
  NS_IMETHOD GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval) override; \
  NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) override; \
  NS_IMETHOD SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, uint32_t aAdditionalFlags, nsIQueryContentEventResult * *_retval) override; \
  NS_IMETHOD RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement) override; \
  NS_IMETHOD RemoteFrameFullscreenReverted(void) override; \
  NS_IMETHOD HandleFullscreenRequests(bool *_retval) override; \
  NS_IMETHOD ExitFullscreen(void) override; \
  NS_IMETHOD SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, uint32_t aAdditionalFlags, bool *_retval) override; \
  NS_IMETHOD SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval) override; \
  NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval) override; \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) override; \
  NS_IMETHOD GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID) override; \
  NS_IMETHOD EnterModalState(void) override; \
  NS_IMETHOD LeaveModalState(void) override; \
  NS_IMETHOD IsInModalState(bool *_retval) override; \
  NS_IMETHOD SetDesktopModeViewport(bool aDesktopModeViewport) override; \
  NS_IMETHOD SuspendTimeouts(void) override; \
  NS_IMETHOD ResumeTimeouts(void) override; \
  NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) override; \
  NS_IMETHOD GetLayerManagerRemote(bool *aLayerManagerRemote) override; \
  NS_IMETHOD GetSupportsHardwareH264Decoding(bool *aSupportsHardwareH264Decoding) override; \
  NS_IMETHOD StartFrameTimeRecording(uint32_t *startIndex) override; \
  NS_IMETHOD StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals) override; \
  NS_IMETHOD BeginTabSwitch(void) override; \
  NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) override; \
  NS_IMETHOD GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval) override; \
  NS_IMETHOD GetContainerElement(nsIDOMElement * *aContainerElement) override; \
  NS_IMETHOD RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) override; \
  NS_IMETHOD AdvanceTimeAndRefresh(int64_t aMilliseconds) override; \
  NS_IMETHOD RestoreNormalRefresh(void) override; \
  NS_IMETHOD GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes) override; \
  NS_IMETHOD SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY) override; \
  NS_IMETHOD SetAsyncZoom(nsIDOMNode *aRootElement, float aValue) override; \
  NS_IMETHOD FlushApzRepaints(bool *_retval) override; \
  NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval) override; \
  NS_IMETHOD WrapDOMFile(nsIFile *aFile, nsISupports * *_retval) override; \
  NS_IMETHOD GetFocusedInputType(char * *aFocusedInputType) override; \
  NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval) override; \
  NS_IMETHOD GetViewId(nsIDOMElement *aElement, nsViewID *_retval) override; \
  NS_IMETHOD LeafLayersPartitionWindow(bool *_retval) override; \
  NS_IMETHOD CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval) override; \
  NS_IMETHOD IsPartOfOpaqueLayer(nsIDOMElement *aElement, bool *_retval) override; \
  NS_IMETHOD NumberOfAssignedPaintedLayers(nsIDOMElement **aElements, uint32_t count, uint32_t *_retval) override; \
  NS_IMETHOD GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval) override; \
  NS_IMETHOD GetFilePath(JS::HandleValue aFile, JSContext* cx, nsAString & _retval) override; \
  NS_IMETHOD GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval) override; \
  NS_IMETHOD IsIncrementalGCEnabled(JSContext* cx, bool *_retval) override; \
  NS_IMETHOD StartPCCountProfiling(JSContext* cx) override; \
  NS_IMETHOD StopPCCountProfiling(JSContext* cx) override; \
  NS_IMETHOD PurgePCCounts(JSContext* cx) override; \
  NS_IMETHOD GetPCCountScriptCount(JSContext* cx, int32_t *_retval) override; \
  NS_IMETHOD GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval) override; \
  NS_IMETHOD GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval) override; \
  NS_IMETHOD GetPaintingSuppressed(bool *aPaintingSuppressed) override; \
  NS_IMETHOD GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins) override; \
  NS_IMETHOD SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight) override; \
  NS_IMETHOD SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft) override; \
  NS_IMETHOD DisableDialogs(void) override; \
  NS_IMETHOD EnableDialogs(void) override; \
  NS_IMETHOD AreDialogsEnabled(bool *_retval) override; \
  NS_IMETHOD LoadSheet(nsIURI *sheetURI, uint32_t type) override; \
  NS_IMETHOD LoadSheetUsingURIString(const nsACString & sheetURI, uint32_t type) override; \
  NS_IMETHOD AddSheet(nsIDOMStyleSheet *sheet, uint32_t type) override; \
  NS_IMETHOD RemoveSheet(nsIURI *sheetURI, uint32_t type) override; \
  NS_IMETHOD RemoveSheetUsingURIString(const nsACString & sheetURI, uint32_t type) override; \
  NS_IMETHOD GetIsHandlingUserInput(bool *aIsHandlingUserInput) override; \
  NS_IMETHOD AllowScriptsToClose(void) override; \
  NS_IMETHOD GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible) override; \
  NS_IMETHOD IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval) override; \
  NS_IMETHOD GetPaintFlashing(bool *aPaintFlashing) override; \
  NS_IMETHOD SetPaintFlashing(bool aPaintFlashing) override; \
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) override; \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) override; \
  NS_IMETHOD GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) override; \
  NS_IMETHOD RequestCompositorProperty(const nsAString & aProperty, float *_retval) override; \
  NS_IMETHOD SetHandlingUserInput(bool aHandlingInput, nsIJSRAIIHelper * *_retval) override; \
  NS_IMETHOD GetContentAPZTestData(JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetCompositorAPZTestData(JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD PostRestyleSelfEvent(nsIDOMElement *aElement) override; \
  NS_IMETHOD GetAudioMuted(bool *aAudioMuted) override; \
  NS_IMETHOD SetAudioMuted(bool aAudioMuted) override; \
  NS_IMETHOD GetAudioVolume(float *aAudioVolume) override; \
  NS_IMETHOD SetAudioVolume(float aAudioVolume) override; \
  NS_IMETHOD XpconnectArgument(nsIDOMWindowUtils *aThis) override; \
  NS_IMETHOD AskPermission(nsIContentPermissionRequest *aRequest) override; \
  NS_IMETHOD GetFramesConstructed(uint64_t *aFramesConstructed) override; \
  NS_IMETHOD GetFramesReflowed(uint64_t *aFramesReflowed) override; \
  NS_IMETHOD SetChromeMargin(int32_t aTop, int32_t aRight, int32_t aBottom, int32_t aLeft) override; \
  NS_IMETHOD GetServiceWorkersTestingEnabled(bool *aServiceWorkersTestingEnabled) override; \
  NS_IMETHOD SetServiceWorkersTestingEnabled(bool aServiceWorkersTestingEnabled) override; \
  NS_IMETHOD GetFrameUniformityTestData(JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD EnterChaosMode(void) override; \
  NS_IMETHOD LeaveChaosMode(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOWUTILS(_to) \
  NS_IMETHOD GetImageAnimationMode(uint16_t *aImageAnimationMode) override { return _to GetImageAnimationMode(aImageAnimationMode); } \
  NS_IMETHOD SetImageAnimationMode(uint16_t aImageAnimationMode) override { return _to SetImageAnimationMode(aImageAnimationMode); } \
  NS_IMETHOD GetDocCharsetIsForced(bool *aDocCharsetIsForced) override { return _to GetDocCharsetIsForced(aDocCharsetIsForced); } \
  NS_IMETHOD GetCursorType(int16_t *_retval) override { return _to GetCursorType(_retval); } \
  NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval) override { return _to GetDocumentMetadata(aName, _retval); } \
  NS_IMETHOD Redraw(uint32_t aCount, uint32_t *_retval) override { return _to Redraw(aCount, _retval); } \
  NS_IMETHOD UpdateLayerTree(void) override { return _to UpdateLayerTree(); } \
  NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) override { return _to SetCSSViewport(aWidthPx, aHeightPx); } \
  NS_IMETHOD GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize) override { return _to GetViewportInfo(aDisplayWidth, aDisplayHeight, aDefaultZoom, aAllowZoom, aMinZoom, aMaxZoom, aWidth, aHeight, aAutoSize); } \
  NS_IMETHOD SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority) override { return _to SetDisplayPortForElement(aXPx, aYPx, aWidthPx, aHeightPx, aElement, aPriority); } \
  NS_IMETHOD SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, nsIDOMElement *aElement, uint32_t aPriority) override { return _to SetDisplayPortMarginsForElement(aLeftMargin, aTopMargin, aRightMargin, aBottomMargin, aElement, aPriority); } \
  NS_IMETHOD SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement) override { return _to SetDisplayPortBaseForElement(aX, aY, aWidth, aHeight, aElement); } \
  NS_IMETHOD SetResolution(float aResolution) override { return _to SetResolution(aResolution); } \
  NS_IMETHOD GetResolution(float *aResolution) override { return _to GetResolution(aResolution); } \
  NS_IMETHOD SetResolutionAndScaleTo(float aResolution) override { return _to SetResolutionAndScaleTo(aResolution); } \
  NS_IMETHOD GetIsResolutionSet(bool *aIsResolutionSet) override { return _to GetIsResolutionSet(aIsResolutionSet); } \
  NS_IMETHOD GetIsFirstPaint(bool *aIsFirstPaint) override { return _to GetIsFirstPaint(aIsFirstPaint); } \
  NS_IMETHOD SetIsFirstPaint(bool aIsFirstPaint) override { return _to SetIsFirstPaint(aIsFirstPaint); } \
  NS_IMETHOD GetPresShellId(uint32_t *aPresShellId) override { return _to GetPresShellId(aPresShellId); } \
  NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval) override { return _to SendMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aIsSynthesized, _argc, _retval); } \
  NS_IMETHOD SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval) override { return _to SendPointerEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aPointerId, aWidth, aHeight, aTiltX, aTiltY, aIsPrimary, aIsSynthesized, _argc, _retval); } \
  NS_IMETHOD SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) override { return _to SendTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers, aIgnoreRootScrollFrame, _retval); } \
  NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc) override { return _to SendMouseEventToWindow(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aIsSynthesized, _argc); } \
  NS_IMETHOD SendPointerEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc) override { return _to SendPointerEventToWindow(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aPointerId, aWidth, aHeight, aTiltX, aTiltY, aIsPrimary, aIsSynthesized, _argc); } \
  NS_IMETHOD SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) override { return _to SendTouchEventToWindow(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers, aIgnoreRootScrollFrame, _retval); } \
  NS_IMETHOD SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions) override { return _to SendWheelEvent(aX, aY, aDeltaX, aDeltaY, aDeltaZ, aDeltaMode, aModifiers, aLineOrPageDeltaX, aLineOrPageDeltaY, aOptions); } \
  NS_IMETHOD SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval) override { return _to SendKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aAdditionalFlags, _retval); } \
  NS_IMETHOD SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters, nsIObserver *aObserver) override { return _to SendNativeKeyEvent(aNativeKeyboardLayout, aNativeKeyCode, aModifierFlags, aCharacters, aUnmodifiedCharacters, aObserver); } \
  NS_IMETHOD SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement, nsIObserver *aObserver) override { return _to SendNativeMouseEvent(aScreenX, aScreenY, aNativeMessage, aModifierFlags, aElement, aObserver); } \
  NS_IMETHOD SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement, nsIObserver *aObserver) override { return _to SendNativeMouseScrollEvent(aScreenX, aScreenY, aNativeMessage, aDeltaX, aDeltaY, aDeltaZ, aModifierFlags, aAdditionalFlags, aElement, aObserver); } \
  NS_IMETHOD SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation, nsIObserver *aObserver) override { return _to SendNativeTouchPoint(aPointerId, aTouchState, aScreenX, aScreenY, aPressure, aOrientation, aObserver); } \
  NS_IMETHOD SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap, nsIObserver *aObserver) override { return _to SendNativeTouchTap(aScreenX, aScreenY, aLongTap, aObserver); } \
  NS_IMETHOD ClearNativeTouchSequence(nsIObserver *aObserver) override { return _to ClearNativeTouchSequence(aObserver); } \
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) override { return _to ActivateNativeMenuItemAt(indexString); } \
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) override { return _to ForceUpdateNativeMenuAt(indexString); } \
  NS_IMETHOD Focus(nsIDOMElement *aElement) override { return _to Focus(aElement); } \
  NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) override { return _to GarbageCollect(aListener, aExtraForgetSkippableCalls); } \
  NS_IMETHOD CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) override { return _to CycleCollect(aListener, aExtraForgetSkippableCalls); } \
  NS_IMETHOD RunNextCollectorTimer(void) override { return _to RunNextCollectorTimer(); } \
  NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount) override { return _to SendSimpleGestureEvent(aType, aX, aY, aDirection, aDelta, aModifiers, aClickCount); } \
  NS_IMETHOD ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval) override { return _to ElementFromPoint(aX, aY, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval) override { return _to NodesFromRect(aX, aY, aTopSize, aRightSize, aBottomSize, aLeftSize, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_IMETHOD GetTranslationNodes(nsIDOMNode *aRoot, nsITranslationNodeList * *_retval) override { return _to GetTranslationNodes(aRoot, _retval); } \
  NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval) override { return _to CompareCanvases(aCanvas1, aCanvas2, aMaxDifference, _retval); } \
  NS_IMETHOD GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending) override { return _to GetIsMozAfterPaintPending(aIsMozAfterPaintPending); } \
  NS_IMETHOD SuppressEventHandling(bool aSuppress) override { return _to SuppressEventHandling(aSuppress); } \
  NS_IMETHOD ClearMozAfterPaintEvents(void) override { return _to ClearMozAfterPaintEvents(); } \
  NS_IMETHOD DisableNonTestMouseEvents(bool aDisable) override { return _to DisableNonTestMouseEvents(aDisable); } \
  NS_IMETHOD GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY) override { return _to GetScrollXY(aFlushLayout, aScrollX, aScrollY); } \
  NS_IMETHOD GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY) override { return _to GetScrollXYFloat(aFlushLayout, aScrollX, aScrollY); } \
  NS_IMETHOD GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight) override { return _to GetScrollbarSize(aFlushLayout, aWidth, aHeight); } \
  NS_IMETHOD GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval) override { return _to GetBoundsWithoutFlushing(aElement, _retval); } \
  NS_IMETHOD GetRootBounds(nsIDOMClientRect * *_retval) override { return _to GetRootBounds(_retval); } \
  NS_IMETHOD GetIMEIsOpen(bool *aIMEIsOpen) override { return _to GetIMEIsOpen(aIMEIsOpen); } \
  NS_IMETHOD GetIMEStatus(uint32_t *aIMEStatus) override { return _to GetIMEStatus(aIMEStatus); } \
  NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) override { return _to GetScreenPixelsPerCSSPixel(aScreenPixelsPerCSSPixel); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) override { return _to GetFullZoom(aFullZoom); } \
  NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval) override { return _to DispatchDOMEventViaPresShell(aTarget, aEvent, aTrusted, _retval); } \
  NS_IMETHOD DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval) override { return _to DispatchEventToChromeOnly(aTarget, aEvent, _retval); } \
  NS_IMETHOD GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval) override { return _to GetClassName(aObject, cx, _retval); } \
  NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) override { return _to SendContentCommandEvent(aType, aTransferable); } \
  NS_IMETHOD SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, uint32_t aAdditionalFlags, nsIQueryContentEventResult * *_retval) override { return _to SendQueryContentEvent(aType, aOffset, aLength, aX, aY, aAdditionalFlags, _retval); } \
  NS_IMETHOD RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement) override { return _to RemoteFrameFullscreenChanged(aFrameElement); } \
  NS_IMETHOD RemoteFrameFullscreenReverted(void) override { return _to RemoteFrameFullscreenReverted(); } \
  NS_IMETHOD HandleFullscreenRequests(bool *_retval) override { return _to HandleFullscreenRequests(_retval); } \
  NS_IMETHOD ExitFullscreen(void) override { return _to ExitFullscreen(); } \
  NS_IMETHOD SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, uint32_t aAdditionalFlags, bool *_retval) override { return _to SendSelectionSetEvent(aOffset, aLength, aAdditionalFlags, _retval); } \
  NS_IMETHOD SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval) override { return _to SelectAtPoint(aX, aY, aSelectBehavior, _retval); } \
  NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval) override { return _to GetVisitedDependentComputedStyle(aElement, aPseudoElement, aPropertyName, _retval); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) override { return _to GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID) override { return _to GetCurrentInnerWindowID(aCurrentInnerWindowID); } \
  NS_IMETHOD EnterModalState(void) override { return _to EnterModalState(); } \
  NS_IMETHOD LeaveModalState(void) override { return _to LeaveModalState(); } \
  NS_IMETHOD IsInModalState(bool *_retval) override { return _to IsInModalState(_retval); } \
  NS_IMETHOD SetDesktopModeViewport(bool aDesktopModeViewport) override { return _to SetDesktopModeViewport(aDesktopModeViewport); } \
  NS_IMETHOD SuspendTimeouts(void) override { return _to SuspendTimeouts(); } \
  NS_IMETHOD ResumeTimeouts(void) override { return _to ResumeTimeouts(); } \
  NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) override { return _to GetLayerManagerType(aLayerManagerType); } \
  NS_IMETHOD GetLayerManagerRemote(bool *aLayerManagerRemote) override { return _to GetLayerManagerRemote(aLayerManagerRemote); } \
  NS_IMETHOD GetSupportsHardwareH264Decoding(bool *aSupportsHardwareH264Decoding) override { return _to GetSupportsHardwareH264Decoding(aSupportsHardwareH264Decoding); } \
  NS_IMETHOD StartFrameTimeRecording(uint32_t *startIndex) override { return _to StartFrameTimeRecording(startIndex); } \
  NS_IMETHOD StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals) override { return _to StopFrameTimeRecording(startIndex, frameCount, frameIntervals); } \
  NS_IMETHOD BeginTabSwitch(void) override { return _to BeginTabSwitch(); } \
  NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) override { return _to GetDisplayDPI(aDisplayDPI); } \
  NS_IMETHOD GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval) override { return _to GetOuterWindowWithId(aOuterWindowID, _retval); } \
  NS_IMETHOD GetContainerElement(nsIDOMElement * *aContainerElement) override { return _to GetContainerElement(aContainerElement); } \
  NS_IMETHOD RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) override { return _to RenderDocument(aRect, aFlags, aBackgroundColor, aThebesContext); } \
  NS_IMETHOD AdvanceTimeAndRefresh(int64_t aMilliseconds) override { return _to AdvanceTimeAndRefresh(aMilliseconds); } \
  NS_IMETHOD RestoreNormalRefresh(void) override { return _to RestoreNormalRefresh(); } \
  NS_IMETHOD GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes) override { return _to GetIsTestControllingRefreshes(aIsTestControllingRefreshes); } \
  NS_IMETHOD SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY) override { return _to SetAsyncScrollOffset(aNode, aX, aY); } \
  NS_IMETHOD SetAsyncZoom(nsIDOMNode *aRootElement, float aValue) override { return _to SetAsyncZoom(aRootElement, aValue); } \
  NS_IMETHOD FlushApzRepaints(bool *_retval) override { return _to FlushApzRepaints(_retval); } \
  NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval) override { return _to ComputeAnimationDistance(element, property, value1, value2, _retval); } \
  NS_IMETHOD WrapDOMFile(nsIFile *aFile, nsISupports * *_retval) override { return _to WrapDOMFile(aFile, _retval); } \
  NS_IMETHOD GetFocusedInputType(char * *aFocusedInputType) override { return _to GetFocusedInputType(aFocusedInputType); } \
  NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval) override { return _to FindElementWithViewId(aId, _retval); } \
  NS_IMETHOD GetViewId(nsIDOMElement *aElement, nsViewID *_retval) override { return _to GetViewId(aElement, _retval); } \
  NS_IMETHOD LeafLayersPartitionWindow(bool *_retval) override { return _to LeafLayersPartitionWindow(_retval); } \
  NS_IMETHOD CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval) override { return _to CheckAndClearPaintedState(aElement, _retval); } \
  NS_IMETHOD IsPartOfOpaqueLayer(nsIDOMElement *aElement, bool *_retval) override { return _to IsPartOfOpaqueLayer(aElement, _retval); } \
  NS_IMETHOD NumberOfAssignedPaintedLayers(nsIDOMElement **aElements, uint32_t count, uint32_t *_retval) override { return _to NumberOfAssignedPaintedLayers(aElements, count, _retval); } \
  NS_IMETHOD GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval) override { return _to GetFileId(aFile, cx, _retval); } \
  NS_IMETHOD GetFilePath(JS::HandleValue aFile, JSContext* cx, nsAString & _retval) override { return _to GetFilePath(aFile, cx, _retval); } \
  NS_IMETHOD GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval) override { return _to GetFileReferences(aDatabaseName, aId, aOptions, aRefCnt, aDBRefCnt, aSliceRefCnt, cx, _retval); } \
  NS_IMETHOD IsIncrementalGCEnabled(JSContext* cx, bool *_retval) override { return _to IsIncrementalGCEnabled(cx, _retval); } \
  NS_IMETHOD StartPCCountProfiling(JSContext* cx) override { return _to StartPCCountProfiling(cx); } \
  NS_IMETHOD StopPCCountProfiling(JSContext* cx) override { return _to StopPCCountProfiling(cx); } \
  NS_IMETHOD PurgePCCounts(JSContext* cx) override { return _to PurgePCCounts(cx); } \
  NS_IMETHOD GetPCCountScriptCount(JSContext* cx, int32_t *_retval) override { return _to GetPCCountScriptCount(cx, _retval); } \
  NS_IMETHOD GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval) override { return _to GetPCCountScriptSummary(script, cx, _retval); } \
  NS_IMETHOD GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval) override { return _to GetPCCountScriptContents(script, cx, _retval); } \
  NS_IMETHOD GetPaintingSuppressed(bool *aPaintingSuppressed) override { return _to GetPaintingSuppressed(aPaintingSuppressed); } \
  NS_IMETHOD GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins) override { return _to GetPlugins(cx, aPlugins); } \
  NS_IMETHOD SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight) override { return _to SetScrollPositionClampingScrollPortSize(aWidth, aHeight); } \
  NS_IMETHOD SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft) override { return _to SetContentDocumentFixedPositionMargins(aTop, aRight, aBottom, aLeft); } \
  NS_IMETHOD DisableDialogs(void) override { return _to DisableDialogs(); } \
  NS_IMETHOD EnableDialogs(void) override { return _to EnableDialogs(); } \
  NS_IMETHOD AreDialogsEnabled(bool *_retval) override { return _to AreDialogsEnabled(_retval); } \
  NS_IMETHOD LoadSheet(nsIURI *sheetURI, uint32_t type) override { return _to LoadSheet(sheetURI, type); } \
  NS_IMETHOD LoadSheetUsingURIString(const nsACString & sheetURI, uint32_t type) override { return _to LoadSheetUsingURIString(sheetURI, type); } \
  NS_IMETHOD AddSheet(nsIDOMStyleSheet *sheet, uint32_t type) override { return _to AddSheet(sheet, type); } \
  NS_IMETHOD RemoveSheet(nsIURI *sheetURI, uint32_t type) override { return _to RemoveSheet(sheetURI, type); } \
  NS_IMETHOD RemoveSheetUsingURIString(const nsACString & sheetURI, uint32_t type) override { return _to RemoveSheetUsingURIString(sheetURI, type); } \
  NS_IMETHOD GetIsHandlingUserInput(bool *aIsHandlingUserInput) override { return _to GetIsHandlingUserInput(aIsHandlingUserInput); } \
  NS_IMETHOD AllowScriptsToClose(void) override { return _to AllowScriptsToClose(); } \
  NS_IMETHOD GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible) override { return _to GetIsParentWindowMainWidgetVisible(aIsParentWindowMainWidgetVisible); } \
  NS_IMETHOD IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval) override { return _to IsNodeDisabledForEvents(aNode, _retval); } \
  NS_IMETHOD GetPaintFlashing(bool *aPaintFlashing) override { return _to GetPaintFlashing(aPaintFlashing); } \
  NS_IMETHOD SetPaintFlashing(bool aPaintFlashing) override { return _to SetPaintFlashing(aPaintFlashing); } \
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) override { return _to RunInStableState(runnable); } \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) override { return _to RunBeforeNextEvent(runnable); } \
  NS_IMETHOD GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) override { return _to GetOMTAStyle(aElement, aProperty, _retval); } \
  NS_IMETHOD RequestCompositorProperty(const nsAString & aProperty, float *_retval) override { return _to RequestCompositorProperty(aProperty, _retval); } \
  NS_IMETHOD SetHandlingUserInput(bool aHandlingInput, nsIJSRAIIHelper * *_retval) override { return _to SetHandlingUserInput(aHandlingInput, _retval); } \
  NS_IMETHOD GetContentAPZTestData(JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetContentAPZTestData(cx, _retval); } \
  NS_IMETHOD GetCompositorAPZTestData(JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetCompositorAPZTestData(cx, _retval); } \
  NS_IMETHOD PostRestyleSelfEvent(nsIDOMElement *aElement) override { return _to PostRestyleSelfEvent(aElement); } \
  NS_IMETHOD GetAudioMuted(bool *aAudioMuted) override { return _to GetAudioMuted(aAudioMuted); } \
  NS_IMETHOD SetAudioMuted(bool aAudioMuted) override { return _to SetAudioMuted(aAudioMuted); } \
  NS_IMETHOD GetAudioVolume(float *aAudioVolume) override { return _to GetAudioVolume(aAudioVolume); } \
  NS_IMETHOD SetAudioVolume(float aAudioVolume) override { return _to SetAudioVolume(aAudioVolume); } \
  NS_IMETHOD XpconnectArgument(nsIDOMWindowUtils *aThis) override { return _to XpconnectArgument(aThis); } \
  NS_IMETHOD AskPermission(nsIContentPermissionRequest *aRequest) override { return _to AskPermission(aRequest); } \
  NS_IMETHOD GetFramesConstructed(uint64_t *aFramesConstructed) override { return _to GetFramesConstructed(aFramesConstructed); } \
  NS_IMETHOD GetFramesReflowed(uint64_t *aFramesReflowed) override { return _to GetFramesReflowed(aFramesReflowed); } \
  NS_IMETHOD SetChromeMargin(int32_t aTop, int32_t aRight, int32_t aBottom, int32_t aLeft) override { return _to SetChromeMargin(aTop, aRight, aBottom, aLeft); } \
  NS_IMETHOD GetServiceWorkersTestingEnabled(bool *aServiceWorkersTestingEnabled) override { return _to GetServiceWorkersTestingEnabled(aServiceWorkersTestingEnabled); } \
  NS_IMETHOD SetServiceWorkersTestingEnabled(bool aServiceWorkersTestingEnabled) override { return _to SetServiceWorkersTestingEnabled(aServiceWorkersTestingEnabled); } \
  NS_IMETHOD GetFrameUniformityTestData(JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetFrameUniformityTestData(cx, _retval); } \
  NS_IMETHOD EnterChaosMode(void) override { return _to EnterChaosMode(); } \
  NS_IMETHOD LeaveChaosMode(void) override { return _to LeaveChaosMode(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOWUTILS(_to) \
  NS_IMETHOD GetImageAnimationMode(uint16_t *aImageAnimationMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageAnimationMode(aImageAnimationMode); } \
  NS_IMETHOD SetImageAnimationMode(uint16_t aImageAnimationMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImageAnimationMode(aImageAnimationMode); } \
  NS_IMETHOD GetDocCharsetIsForced(bool *aDocCharsetIsForced) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocCharsetIsForced(aDocCharsetIsForced); } \
  NS_IMETHOD GetCursorType(int16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCursorType(_retval); } \
  NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentMetadata(aName, _retval); } \
  NS_IMETHOD Redraw(uint32_t aCount, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Redraw(aCount, _retval); } \
  NS_IMETHOD UpdateLayerTree(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateLayerTree(); } \
  NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCSSViewport(aWidthPx, aHeightPx); } \
  NS_IMETHOD GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewportInfo(aDisplayWidth, aDisplayHeight, aDefaultZoom, aAllowZoom, aMinZoom, aMaxZoom, aWidth, aHeight, aAutoSize); } \
  NS_IMETHOD SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayPortForElement(aXPx, aYPx, aWidthPx, aHeightPx, aElement, aPriority); } \
  NS_IMETHOD SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, nsIDOMElement *aElement, uint32_t aPriority) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayPortMarginsForElement(aLeftMargin, aTopMargin, aRightMargin, aBottomMargin, aElement, aPriority); } \
  NS_IMETHOD SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayPortBaseForElement(aX, aY, aWidth, aHeight, aElement); } \
  NS_IMETHOD SetResolution(float aResolution) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResolution(aResolution); } \
  NS_IMETHOD GetResolution(float *aResolution) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResolution(aResolution); } \
  NS_IMETHOD SetResolutionAndScaleTo(float aResolution) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResolutionAndScaleTo(aResolution); } \
  NS_IMETHOD GetIsResolutionSet(bool *aIsResolutionSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsResolutionSet(aIsResolutionSet); } \
  NS_IMETHOD GetIsFirstPaint(bool *aIsFirstPaint) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFirstPaint(aIsFirstPaint); } \
  NS_IMETHOD SetIsFirstPaint(bool aIsFirstPaint) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsFirstPaint(aIsFirstPaint); } \
  NS_IMETHOD GetPresShellId(uint32_t *aPresShellId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresShellId(aPresShellId); } \
  NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aIsSynthesized, _argc, _retval); } \
  NS_IMETHOD SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendPointerEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aPointerId, aWidth, aHeight, aTiltX, aTiltY, aIsPrimary, aIsSynthesized, _argc, _retval); } \
  NS_IMETHOD SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers, aIgnoreRootScrollFrame, _retval); } \
  NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseEventToWindow(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aIsSynthesized, _argc); } \
  NS_IMETHOD SendPointerEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendPointerEventToWindow(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aPointerId, aWidth, aHeight, aTiltX, aTiltY, aIsPrimary, aIsSynthesized, _argc); } \
  NS_IMETHOD SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendTouchEventToWindow(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers, aIgnoreRootScrollFrame, _retval); } \
  NS_IMETHOD SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWheelEvent(aX, aY, aDeltaX, aDeltaY, aDeltaZ, aDeltaMode, aModifiers, aLineOrPageDeltaX, aLineOrPageDeltaY, aOptions); } \
  NS_IMETHOD SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aAdditionalFlags, _retval); } \
  NS_IMETHOD SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters, nsIObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeKeyEvent(aNativeKeyboardLayout, aNativeKeyCode, aModifierFlags, aCharacters, aUnmodifiedCharacters, aObserver); } \
  NS_IMETHOD SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement, nsIObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeMouseEvent(aScreenX, aScreenY, aNativeMessage, aModifierFlags, aElement, aObserver); } \
  NS_IMETHOD SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement, nsIObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeMouseScrollEvent(aScreenX, aScreenY, aNativeMessage, aDeltaX, aDeltaY, aDeltaZ, aModifierFlags, aAdditionalFlags, aElement, aObserver); } \
  NS_IMETHOD SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation, nsIObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeTouchPoint(aPointerId, aTouchState, aScreenX, aScreenY, aPressure, aOrientation, aObserver); } \
  NS_IMETHOD SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap, nsIObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeTouchTap(aScreenX, aScreenY, aLongTap, aObserver); } \
  NS_IMETHOD ClearNativeTouchSequence(nsIObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearNativeTouchSequence(aObserver); } \
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateNativeMenuItemAt(indexString); } \
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceUpdateNativeMenuAt(indexString); } \
  NS_IMETHOD Focus(nsIDOMElement *aElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(aElement); } \
  NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GarbageCollect(aListener, aExtraForgetSkippableCalls); } \
  NS_IMETHOD CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CycleCollect(aListener, aExtraForgetSkippableCalls); } \
  NS_IMETHOD RunNextCollectorTimer(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RunNextCollectorTimer(); } \
  NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSimpleGestureEvent(aType, aX, aY, aDirection, aDelta, aModifiers, aClickCount); } \
  NS_IMETHOD ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ElementFromPoint(aX, aY, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NodesFromRect(aX, aY, aTopSize, aRightSize, aBottomSize, aLeftSize, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_IMETHOD GetTranslationNodes(nsIDOMNode *aRoot, nsITranslationNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTranslationNodes(aRoot, _retval); } \
  NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareCanvases(aCanvas1, aCanvas2, aMaxDifference, _retval); } \
  NS_IMETHOD GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsMozAfterPaintPending(aIsMozAfterPaintPending); } \
  NS_IMETHOD SuppressEventHandling(bool aSuppress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SuppressEventHandling(aSuppress); } \
  NS_IMETHOD ClearMozAfterPaintEvents(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearMozAfterPaintEvents(); } \
  NS_IMETHOD DisableNonTestMouseEvents(bool aDisable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableNonTestMouseEvents(aDisable); } \
  NS_IMETHOD GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollXY(aFlushLayout, aScrollX, aScrollY); } \
  NS_IMETHOD GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollXYFloat(aFlushLayout, aScrollX, aScrollY); } \
  NS_IMETHOD GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollbarSize(aFlushLayout, aWidth, aHeight); } \
  NS_IMETHOD GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundsWithoutFlushing(aElement, _retval); } \
  NS_IMETHOD GetRootBounds(nsIDOMClientRect * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootBounds(_retval); } \
  NS_IMETHOD GetIMEIsOpen(bool *aIMEIsOpen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIMEIsOpen(aIMEIsOpen); } \
  NS_IMETHOD GetIMEStatus(uint32_t *aIMEStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIMEStatus(aIMEStatus); } \
  NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenPixelsPerCSSPixel(aScreenPixelsPerCSSPixel); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullZoom(aFullZoom); } \
  NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchDOMEventViaPresShell(aTarget, aEvent, aTrusted, _retval); } \
  NS_IMETHOD DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchEventToChromeOnly(aTarget, aEvent, _retval); } \
  NS_IMETHOD GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassName(aObject, cx, _retval); } \
  NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendContentCommandEvent(aType, aTransferable); } \
  NS_IMETHOD SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, uint32_t aAdditionalFlags, nsIQueryContentEventResult * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendQueryContentEvent(aType, aOffset, aLength, aX, aY, aAdditionalFlags, _retval); } \
  NS_IMETHOD RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoteFrameFullscreenChanged(aFrameElement); } \
  NS_IMETHOD RemoteFrameFullscreenReverted(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoteFrameFullscreenReverted(); } \
  NS_IMETHOD HandleFullscreenRequests(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleFullscreenRequests(_retval); } \
  NS_IMETHOD ExitFullscreen(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExitFullscreen(); } \
  NS_IMETHOD SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, uint32_t aAdditionalFlags, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSelectionSetEvent(aOffset, aLength, aAdditionalFlags, _retval); } \
  NS_IMETHOD SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAtPoint(aX, aY, aSelectBehavior, _retval); } \
  NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisitedDependentComputedStyle(aElement, aPseudoElement, aPropertyName, _retval); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentInnerWindowID(aCurrentInnerWindowID); } \
  NS_IMETHOD EnterModalState(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnterModalState(); } \
  NS_IMETHOD LeaveModalState(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LeaveModalState(); } \
  NS_IMETHOD IsInModalState(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsInModalState(_retval); } \
  NS_IMETHOD SetDesktopModeViewport(bool aDesktopModeViewport) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDesktopModeViewport(aDesktopModeViewport); } \
  NS_IMETHOD SuspendTimeouts(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SuspendTimeouts(); } \
  NS_IMETHOD ResumeTimeouts(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeTimeouts(); } \
  NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayerManagerType(aLayerManagerType); } \
  NS_IMETHOD GetLayerManagerRemote(bool *aLayerManagerRemote) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayerManagerRemote(aLayerManagerRemote); } \
  NS_IMETHOD GetSupportsHardwareH264Decoding(bool *aSupportsHardwareH264Decoding) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSupportsHardwareH264Decoding(aSupportsHardwareH264Decoding); } \
  NS_IMETHOD StartFrameTimeRecording(uint32_t *startIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartFrameTimeRecording(startIndex); } \
  NS_IMETHOD StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StopFrameTimeRecording(startIndex, frameCount, frameIntervals); } \
  NS_IMETHOD BeginTabSwitch(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginTabSwitch(); } \
  NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayDPI(aDisplayDPI); } \
  NS_IMETHOD GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWindowWithId(aOuterWindowID, _retval); } \
  NS_IMETHOD GetContainerElement(nsIDOMElement * *aContainerElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainerElement(aContainerElement); } \
  NS_IMETHOD RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RenderDocument(aRect, aFlags, aBackgroundColor, aThebesContext); } \
  NS_IMETHOD AdvanceTimeAndRefresh(int64_t aMilliseconds) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AdvanceTimeAndRefresh(aMilliseconds); } \
  NS_IMETHOD RestoreNormalRefresh(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreNormalRefresh(); } \
  NS_IMETHOD GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTestControllingRefreshes(aIsTestControllingRefreshes); } \
  NS_IMETHOD SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsyncScrollOffset(aNode, aX, aY); } \
  NS_IMETHOD SetAsyncZoom(nsIDOMNode *aRootElement, float aValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsyncZoom(aRootElement, aValue); } \
  NS_IMETHOD FlushApzRepaints(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FlushApzRepaints(_retval); } \
  NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ComputeAnimationDistance(element, property, value1, value2, _retval); } \
  NS_IMETHOD WrapDOMFile(nsIFile *aFile, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapDOMFile(aFile, _retval); } \
  NS_IMETHOD GetFocusedInputType(char * *aFocusedInputType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedInputType(aFocusedInputType); } \
  NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindElementWithViewId(aId, _retval); } \
  NS_IMETHOD GetViewId(nsIDOMElement *aElement, nsViewID *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewId(aElement, _retval); } \
  NS_IMETHOD LeafLayersPartitionWindow(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LeafLayersPartitionWindow(_retval); } \
  NS_IMETHOD CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckAndClearPaintedState(aElement, _retval); } \
  NS_IMETHOD IsPartOfOpaqueLayer(nsIDOMElement *aElement, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPartOfOpaqueLayer(aElement, _retval); } \
  NS_IMETHOD NumberOfAssignedPaintedLayers(nsIDOMElement **aElements, uint32_t count, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NumberOfAssignedPaintedLayers(aElements, count, _retval); } \
  NS_IMETHOD GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileId(aFile, cx, _retval); } \
  NS_IMETHOD GetFilePath(JS::HandleValue aFile, JSContext* cx, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilePath(aFile, cx, _retval); } \
  NS_IMETHOD GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileReferences(aDatabaseName, aId, aOptions, aRefCnt, aDBRefCnt, aSliceRefCnt, cx, _retval); } \
  NS_IMETHOD IsIncrementalGCEnabled(JSContext* cx, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsIncrementalGCEnabled(cx, _retval); } \
  NS_IMETHOD StartPCCountProfiling(JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartPCCountProfiling(cx); } \
  NS_IMETHOD StopPCCountProfiling(JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StopPCCountProfiling(cx); } \
  NS_IMETHOD PurgePCCounts(JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PurgePCCounts(cx); } \
  NS_IMETHOD GetPCCountScriptCount(JSContext* cx, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPCCountScriptCount(cx, _retval); } \
  NS_IMETHOD GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPCCountScriptSummary(script, cx, _retval); } \
  NS_IMETHOD GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPCCountScriptContents(script, cx, _retval); } \
  NS_IMETHOD GetPaintingSuppressed(bool *aPaintingSuppressed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaintingSuppressed(aPaintingSuppressed); } \
  NS_IMETHOD GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlugins(cx, aPlugins); } \
  NS_IMETHOD SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrollPositionClampingScrollPortSize(aWidth, aHeight); } \
  NS_IMETHOD SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentDocumentFixedPositionMargins(aTop, aRight, aBottom, aLeft); } \
  NS_IMETHOD DisableDialogs(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableDialogs(); } \
  NS_IMETHOD EnableDialogs(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableDialogs(); } \
  NS_IMETHOD AreDialogsEnabled(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AreDialogsEnabled(_retval); } \
  NS_IMETHOD LoadSheet(nsIURI *sheetURI, uint32_t type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadSheet(sheetURI, type); } \
  NS_IMETHOD LoadSheetUsingURIString(const nsACString & sheetURI, uint32_t type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadSheetUsingURIString(sheetURI, type); } \
  NS_IMETHOD AddSheet(nsIDOMStyleSheet *sheet, uint32_t type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSheet(sheet, type); } \
  NS_IMETHOD RemoveSheet(nsIURI *sheetURI, uint32_t type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSheet(sheetURI, type); } \
  NS_IMETHOD RemoveSheetUsingURIString(const nsACString & sheetURI, uint32_t type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSheetUsingURIString(sheetURI, type); } \
  NS_IMETHOD GetIsHandlingUserInput(bool *aIsHandlingUserInput) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsHandlingUserInput(aIsHandlingUserInput); } \
  NS_IMETHOD AllowScriptsToClose(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AllowScriptsToClose(); } \
  NS_IMETHOD GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsParentWindowMainWidgetVisible(aIsParentWindowMainWidgetVisible); } \
  NS_IMETHOD IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsNodeDisabledForEvents(aNode, _retval); } \
  NS_IMETHOD GetPaintFlashing(bool *aPaintFlashing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaintFlashing(aPaintFlashing); } \
  NS_IMETHOD SetPaintFlashing(bool aPaintFlashing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaintFlashing(aPaintFlashing); } \
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RunInStableState(runnable); } \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RunBeforeNextEvent(runnable); } \
  NS_IMETHOD GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOMTAStyle(aElement, aProperty, _retval); } \
  NS_IMETHOD RequestCompositorProperty(const nsAString & aProperty, float *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestCompositorProperty(aProperty, _retval); } \
  NS_IMETHOD SetHandlingUserInput(bool aHandlingInput, nsIJSRAIIHelper * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHandlingUserInput(aHandlingInput, _retval); } \
  NS_IMETHOD GetContentAPZTestData(JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentAPZTestData(cx, _retval); } \
  NS_IMETHOD GetCompositorAPZTestData(JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompositorAPZTestData(cx, _retval); } \
  NS_IMETHOD PostRestyleSelfEvent(nsIDOMElement *aElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PostRestyleSelfEvent(aElement); } \
  NS_IMETHOD GetAudioMuted(bool *aAudioMuted) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAudioMuted(aAudioMuted); } \
  NS_IMETHOD SetAudioMuted(bool aAudioMuted) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAudioMuted(aAudioMuted); } \
  NS_IMETHOD GetAudioVolume(float *aAudioVolume) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAudioVolume(aAudioVolume); } \
  NS_IMETHOD SetAudioVolume(float aAudioVolume) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAudioVolume(aAudioVolume); } \
  NS_IMETHOD XpconnectArgument(nsIDOMWindowUtils *aThis) override { return !_to ? NS_ERROR_NULL_POINTER : _to->XpconnectArgument(aThis); } \
  NS_IMETHOD AskPermission(nsIContentPermissionRequest *aRequest) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AskPermission(aRequest); } \
  NS_IMETHOD GetFramesConstructed(uint64_t *aFramesConstructed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFramesConstructed(aFramesConstructed); } \
  NS_IMETHOD GetFramesReflowed(uint64_t *aFramesReflowed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFramesReflowed(aFramesReflowed); } \
  NS_IMETHOD SetChromeMargin(int32_t aTop, int32_t aRight, int32_t aBottom, int32_t aLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChromeMargin(aTop, aRight, aBottom, aLeft); } \
  NS_IMETHOD GetServiceWorkersTestingEnabled(bool *aServiceWorkersTestingEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceWorkersTestingEnabled(aServiceWorkersTestingEnabled); } \
  NS_IMETHOD SetServiceWorkersTestingEnabled(bool aServiceWorkersTestingEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetServiceWorkersTestingEnabled(aServiceWorkersTestingEnabled); } \
  NS_IMETHOD GetFrameUniformityTestData(JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameUniformityTestData(cx, _retval); } \
  NS_IMETHOD EnterChaosMode(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnterChaosMode(); } \
  NS_IMETHOD LeaveChaosMode(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LeaveChaosMode(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindowUtils : public nsIDOMWindowUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOWUTILS

  nsDOMWindowUtils();

private:
  ~nsDOMWindowUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMWindowUtils, nsIDOMWindowUtils)

nsDOMWindowUtils::nsDOMWindowUtils()
{
  /* member initializers and constructor code */
}

nsDOMWindowUtils::~nsDOMWindowUtils()
{
  /* destructor code */
}

/* attribute unsigned short imageAnimationMode; */
NS_IMETHODIMP nsDOMWindowUtils::GetImageAnimationMode(uint16_t *aImageAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetImageAnimationMode(uint16_t aImageAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean docCharsetIsForced; */
NS_IMETHODIMP nsDOMWindowUtils::GetDocCharsetIsForced(bool *aDocCharsetIsForced)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short getCursorType (); */
NS_IMETHODIMP nsDOMWindowUtils::GetCursorType(int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getDocumentMetadata (in AString aName); */
NS_IMETHODIMP nsDOMWindowUtils::GetDocumentMetadata(const nsAString & aName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long redraw ([optional] in unsigned long aCount); */
NS_IMETHODIMP nsDOMWindowUtils::Redraw(uint32_t aCount, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateLayerTree (); */
NS_IMETHODIMP nsDOMWindowUtils::UpdateLayerTree()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCSSViewport (in float aWidthPx, in float aHeightPx); */
NS_IMETHODIMP nsDOMWindowUtils::SetCSSViewport(float aWidthPx, float aHeightPx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getViewportInfo (in uint32_t aDisplayWidth, in uint32_t aDisplayHeight, out double aDefaultZoom, out boolean aAllowZoom, out double aMinZoom, out double aMaxZoom, out uint32_t aWidth, out uint32_t aHeight, out boolean aAutoSize); */
NS_IMETHODIMP nsDOMWindowUtils::GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDisplayPortForElement (in float aXPx, in float aYPx, in float aWidthPx, in float aHeightPx, in nsIDOMElement aElement, in uint32_t aPriority); */
NS_IMETHODIMP nsDOMWindowUtils::SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDisplayPortMarginsForElement (in float aLeftMargin, in float aTopMargin, in float aRightMargin, in float aBottomMargin, in nsIDOMElement aElement, in uint32_t aPriority); */
NS_IMETHODIMP nsDOMWindowUtils::SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, nsIDOMElement *aElement, uint32_t aPriority)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDisplayPortBaseForElement (in int32_t aX, in int32_t aY, in int32_t aWidth, in int32_t aHeight, in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setResolution (in float aResolution); */
NS_IMETHODIMP nsDOMWindowUtils::SetResolution(float aResolution)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getResolution (out float aResolution); */
NS_IMETHODIMP nsDOMWindowUtils::GetResolution(float *aResolution)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setResolutionAndScaleTo (in float aResolution); */
NS_IMETHODIMP nsDOMWindowUtils::SetResolutionAndScaleTo(float aResolution)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isResolutionSet; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsResolutionSet(bool *aIsResolutionSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isFirstPaint; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsFirstPaint(bool *aIsFirstPaint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetIsFirstPaint(bool aIsFirstPaint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPresShellId (out uint32_t aPresShellId); */
NS_IMETHODIMP nsDOMWindowUtils::GetPresShellId(uint32_t *aPresShellId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean sendMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in boolean aIsSynthesized); */
NS_IMETHODIMP nsDOMWindowUtils::SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean sendPointerEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in long aPointerId, [optional] in long aWidth, [optional] in long aHeight, [optional] in long aTiltX, [optional] in long aTiltY, [optional] in boolean aIsPrimary, [optional] in boolean aIsSynthesized); */
NS_IMETHODIMP nsDOMWindowUtils::SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendTouchEvent (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
NS_IMETHODIMP nsDOMWindowUtils::SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void sendMouseEventToWindow (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in boolean aIsSynthesized); */
NS_IMETHODIMP nsDOMWindowUtils::SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void sendPointerEventToWindow (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in long aPointerId, [optional] in long aWidth, [optional] in long aHeight, [optional] in long aTiltX, [optional] in long aTiltY, [optional] in boolean aIsPrimary, [optional] in boolean aIsSynthesized); */
NS_IMETHODIMP nsDOMWindowUtils::SendPointerEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t aTiltX, int32_t aTiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendTouchEventToWindow (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
NS_IMETHODIMP nsDOMWindowUtils::SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendWheelEvent (in float aX, in float aY, in double aDeltaX, in double aDeltaY, in double aDeltaZ, in unsigned long aDeltaMode, in long aModifiers, in long aLineOrPageDeltaX, in long aLineOrPageDeltaY, in unsigned long aOptions); */
NS_IMETHODIMP nsDOMWindowUtils::SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in unsigned long aAdditionalFlags); */
NS_IMETHODIMP nsDOMWindowUtils::SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeKeyEvent (in long aNativeKeyboardLayout, in long aNativeKeyCode, in long aModifierFlags, in AString aCharacters, in AString aUnmodifiedCharacters, [optional] in nsIObserver aObserver); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters, nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeMouseEvent (in long aScreenX, in long aScreenY, in long aNativeMessage, in long aModifierFlags, in nsIDOMElement aElement, [optional] in nsIObserver aObserver); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement, nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeMouseScrollEvent (in long aScreenX, in long aScreenY, in unsigned long aNativeMessage, in double aDeltaX, in double aDeltaY, in double aDeltaZ, in unsigned long aModifierFlags, in unsigned long aAdditionalFlags, in nsIDOMElement aElement, [optional] in nsIObserver aObserver); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement, nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeTouchPoint (in unsigned long aPointerId, in unsigned long aTouchState, in long aScreenX, in long aScreenY, in double aPressure, in unsigned long aOrientation, [optional] in nsIObserver aObserver); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation, nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeTouchTap (in long aScreenX, in long aScreenY, in boolean aLongTap, [optional] in nsIObserver aObserver); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap, nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearNativeTouchSequence ([optional] in nsIObserver aObserver); */
NS_IMETHODIMP nsDOMWindowUtils::ClearNativeTouchSequence(nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activateNativeMenuItemAt (in AString indexString); */
NS_IMETHODIMP nsDOMWindowUtils::ActivateNativeMenuItemAt(const nsAString & indexString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceUpdateNativeMenuAt (in AString indexString); */
NS_IMETHODIMP nsDOMWindowUtils::ForceUpdateNativeMenuAt(const nsAString & indexString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::Focus(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void garbageCollect ([optional] in nsICycleCollectorListener aListener, [optional] in long aExtraForgetSkippableCalls); */
NS_IMETHODIMP nsDOMWindowUtils::GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cycleCollect ([optional] in nsICycleCollectorListener aListener, [optional] in long aExtraForgetSkippableCalls); */
NS_IMETHODIMP nsDOMWindowUtils::CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runNextCollectorTimer (); */
NS_IMETHODIMP nsDOMWindowUtils::RunNextCollectorTimer()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendSimpleGestureEvent (in AString aType, in float aX, in float aY, in unsigned long aDirection, in double aDelta, in long aModifiers, [optional] in unsigned long aClickCount); */
NS_IMETHODIMP nsDOMWindowUtils::SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement elementFromPoint (in float aX, in float aY, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
NS_IMETHODIMP nsDOMWindowUtils::ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList nodesFromRect (in float aX, in float aY, in float aTopSize, in float aRightSize, in float aBottomSize, in float aLeftSize, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
NS_IMETHODIMP nsDOMWindowUtils::NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITranslationNodeList getTranslationNodes (in nsIDOMNode aRoot); */
NS_IMETHODIMP nsDOMWindowUtils::GetTranslationNodes(nsIDOMNode *aRoot, nsITranslationNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t compareCanvases (in nsIDOMHTMLCanvasElement aCanvas1, in nsIDOMHTMLCanvasElement aCanvas2, out unsigned long aMaxDifference); */
NS_IMETHODIMP nsDOMWindowUtils::CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isMozAfterPaintPending; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suppressEventHandling (in boolean aSuppress); */
NS_IMETHODIMP nsDOMWindowUtils::SuppressEventHandling(bool aSuppress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearMozAfterPaintEvents (); */
NS_IMETHODIMP nsDOMWindowUtils::ClearMozAfterPaintEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableNonTestMouseEvents (in boolean aDisable); */
NS_IMETHODIMP nsDOMWindowUtils::DisableNonTestMouseEvents(bool aDisable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollXY (in boolean aFlushLayout, out long aScrollX, out long aScrollY); */
NS_IMETHODIMP nsDOMWindowUtils::GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollXYFloat (in boolean aFlushLayout, out float aScrollX, out float aScrollY); */
NS_IMETHODIMP nsDOMWindowUtils::GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollbarSize (in boolean aFlushLayout, out long aWidth, out long aHeight); */
NS_IMETHODIMP nsDOMWindowUtils::GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect getBoundsWithoutFlushing (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect getRootBounds (); */
NS_IMETHODIMP nsDOMWindowUtils::GetRootBounds(nsIDOMClientRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean IMEIsOpen; */
NS_IMETHODIMP nsDOMWindowUtils::GetIMEIsOpen(bool *aIMEIsOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long IMEStatus; */
NS_IMETHODIMP nsDOMWindowUtils::GetIMEStatus(uint32_t *aIMEStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float screenPixelsPerCSSPixel; */
NS_IMETHODIMP nsDOMWindowUtils::GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float fullZoom; */
NS_IMETHODIMP nsDOMWindowUtils::GetFullZoom(float *aFullZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean dispatchDOMEventViaPresShell (in nsIDOMNode aTarget, in nsIDOMEvent aEvent, in boolean aTrusted); */
NS_IMETHODIMP nsDOMWindowUtils::DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean dispatchEventToChromeOnly (in nsIDOMEventTarget aTarget, in nsIDOMEvent aEvent); */
NS_IMETHODIMP nsDOMWindowUtils::DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] string getClassName (in jsval aObject); */
NS_IMETHODIMP nsDOMWindowUtils::GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendContentCommandEvent (in AString aType, [optional] in nsITransferable aTransferable); */
NS_IMETHODIMP nsDOMWindowUtils::SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIQueryContentEventResult sendQueryContentEvent (in unsigned long aType, in unsigned long aOffset, in unsigned long aLength, in long aX, in long aY, [optional] in unsigned long aAdditionalFlags); */
NS_IMETHODIMP nsDOMWindowUtils::SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, uint32_t aAdditionalFlags, nsIQueryContentEventResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remoteFrameFullscreenChanged (in nsIDOMElement aFrameElement); */
NS_IMETHODIMP nsDOMWindowUtils::RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remoteFrameFullscreenReverted (); */
NS_IMETHODIMP nsDOMWindowUtils::RemoteFrameFullscreenReverted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handleFullscreenRequests (); */
NS_IMETHODIMP nsDOMWindowUtils::HandleFullscreenRequests(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exitFullscreen (); */
NS_IMETHODIMP nsDOMWindowUtils::ExitFullscreen()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendSelectionSetEvent (in unsigned long aOffset, in unsigned long aLength, [optional] in unsigned long aAdditionalFlags); */
NS_IMETHODIMP nsDOMWindowUtils::SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, uint32_t aAdditionalFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean selectAtPoint (in float aX, in float aY, in unsigned long aSelectBehavior); */
NS_IMETHODIMP nsDOMWindowUtils::SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getVisitedDependentComputedStyle (in nsIDOMElement aElement, in AString aPseudoElement, in AString aPropertyName); */
NS_IMETHODIMP nsDOMWindowUtils::GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long outerWindowID; */
NS_IMETHODIMP nsDOMWindowUtils::GetOuterWindowID(uint64_t *aOuterWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long currentInnerWindowID; */
NS_IMETHODIMP nsDOMWindowUtils::GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enterModalState (); */
NS_IMETHODIMP nsDOMWindowUtils::EnterModalState()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void leaveModalState (); */
NS_IMETHODIMP nsDOMWindowUtils::LeaveModalState()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean isInModalState (); */
NS_IMETHODIMP nsDOMWindowUtils::IsInModalState(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDesktopModeViewport (in boolean aDesktopModeViewport); */
NS_IMETHODIMP nsDOMWindowUtils::SetDesktopModeViewport(bool aDesktopModeViewport)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspendTimeouts (); */
NS_IMETHODIMP nsDOMWindowUtils::SuspendTimeouts()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeTimeouts (); */
NS_IMETHODIMP nsDOMWindowUtils::ResumeTimeouts()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString layerManagerType; */
NS_IMETHODIMP nsDOMWindowUtils::GetLayerManagerType(nsAString & aLayerManagerType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean layerManagerRemote; */
NS_IMETHODIMP nsDOMWindowUtils::GetLayerManagerRemote(bool *aLayerManagerRemote)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean supportsHardwareH264Decoding; */
NS_IMETHODIMP nsDOMWindowUtils::GetSupportsHardwareH264Decoding(bool *aSupportsHardwareH264Decoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startFrameTimeRecording ([retval] out unsigned long startIndex); */
NS_IMETHODIMP nsDOMWindowUtils::StartFrameTimeRecording(uint32_t *startIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopFrameTimeRecording (in unsigned long startIndex, [optional] out unsigned long frameCount, [array, size_is (frameCount), retval] out float frameIntervals); */
NS_IMETHODIMP nsDOMWindowUtils::StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginTabSwitch (); */
NS_IMETHODIMP nsDOMWindowUtils::BeginTabSwitch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float displayDPI; */
NS_IMETHODIMP nsDOMWindowUtils::GetDisplayDPI(float *aDisplayDPI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow getOuterWindowWithId (in unsigned long long aOuterWindowID); */
NS_IMETHODIMP nsDOMWindowUtils::GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement containerElement; */
NS_IMETHODIMP nsDOMWindowUtils::GetContainerElement(nsIDOMElement * *aContainerElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void RenderDocument (in nsConstRect aRect, in uint32_t aFlags, in nscolor aBackgroundColor, in gfxContext aThebesContext); */
NS_IMETHODIMP nsDOMWindowUtils::RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void advanceTimeAndRefresh (in long long aMilliseconds); */
NS_IMETHODIMP nsDOMWindowUtils::AdvanceTimeAndRefresh(int64_t aMilliseconds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreNormalRefresh (); */
NS_IMETHODIMP nsDOMWindowUtils::RestoreNormalRefresh()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool isTestControllingRefreshes; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsyncScrollOffset (in nsIDOMNode aNode, in int32_t aX, in int32_t aY); */
NS_IMETHODIMP nsDOMWindowUtils::SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsyncZoom (in nsIDOMNode aRootElement, in float aValue); */
NS_IMETHODIMP nsDOMWindowUtils::SetAsyncZoom(nsIDOMNode *aRootElement, float aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool flushApzRepaints (); */
NS_IMETHODIMP nsDOMWindowUtils::FlushApzRepaints(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double computeAnimationDistance (in nsIDOMElement element, in AString property, in AString value1, in AString value2); */
NS_IMETHODIMP nsDOMWindowUtils::ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports wrapDOMFile (in nsIFile aFile); */
NS_IMETHODIMP nsDOMWindowUtils::WrapDOMFile(nsIFile *aFile, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string focusedInputType; */
NS_IMETHODIMP nsDOMWindowUtils::GetFocusedInputType(char * *aFocusedInputType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement findElementWithViewId (in nsViewID aId); */
NS_IMETHODIMP nsDOMWindowUtils::FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsViewID getViewId (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::GetViewId(nsIDOMElement *aElement, nsViewID *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean leafLayersPartitionWindow (); */
NS_IMETHODIMP nsDOMWindowUtils::LeafLayersPartitionWindow(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkAndClearPaintedState (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isPartOfOpaqueLayer (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::IsPartOfOpaqueLayer(nsIDOMElement *aElement, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long numberOfAssignedPaintedLayers ([array, size_is (count)] in nsIDOMElement aElements, in uint32_t count); */
NS_IMETHODIMP nsDOMWindowUtils::NumberOfAssignedPaintedLayers(nsIDOMElement **aElements, uint32_t count, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] long long getFileId (in jsval aFile); */
NS_IMETHODIMP nsDOMWindowUtils::GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] AString getFilePath (in jsval aFile); */
NS_IMETHODIMP nsDOMWindowUtils::GetFilePath(JS::HandleValue aFile, JSContext* cx, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] boolean getFileReferences (in AString aDatabaseName, in long long aId, [optional] in jsval aOptions, [optional] out long aRefCnt, [optional] out long aDBRefCnt, [optional] out long aSliceRefCnt); */
NS_IMETHODIMP nsDOMWindowUtils::GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] boolean isIncrementalGCEnabled (); */
NS_IMETHODIMP nsDOMWindowUtils::IsIncrementalGCEnabled(JSContext* cx, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void startPCCountProfiling (); */
NS_IMETHODIMP nsDOMWindowUtils::StartPCCountProfiling(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void stopPCCountProfiling (); */
NS_IMETHODIMP nsDOMWindowUtils::StopPCCountProfiling(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void purgePCCounts (); */
NS_IMETHODIMP nsDOMWindowUtils::PurgePCCounts(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] long getPCCountScriptCount (); */
NS_IMETHODIMP nsDOMWindowUtils::GetPCCountScriptCount(JSContext* cx, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] AString getPCCountScriptSummary (in long script); */
NS_IMETHODIMP nsDOMWindowUtils::GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] AString getPCCountScriptContents (in long script); */
NS_IMETHODIMP nsDOMWindowUtils::GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean paintingSuppressed; */
NS_IMETHODIMP nsDOMWindowUtils::GetPaintingSuppressed(bool *aPaintingSuppressed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval plugins; */
NS_IMETHODIMP nsDOMWindowUtils::GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setScrollPositionClampingScrollPortSize (in float aWidth, in float aHeight); */
NS_IMETHODIMP nsDOMWindowUtils::SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setContentDocumentFixedPositionMargins (in float aTop, in float aRight, in float aBottom, in float aLeft); */
NS_IMETHODIMP nsDOMWindowUtils::SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableDialogs (); */
NS_IMETHODIMP nsDOMWindowUtils::DisableDialogs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableDialogs (); */
NS_IMETHODIMP nsDOMWindowUtils::EnableDialogs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool areDialogsEnabled (); */
NS_IMETHODIMP nsDOMWindowUtils::AreDialogsEnabled(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadSheet (in nsIURI sheetURI, in unsigned long type); */
NS_IMETHODIMP nsDOMWindowUtils::LoadSheet(nsIURI *sheetURI, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadSheetUsingURIString (in ACString sheetURI, in unsigned long type); */
NS_IMETHODIMP nsDOMWindowUtils::LoadSheetUsingURIString(const nsACString & sheetURI, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSheet (in nsIDOMStyleSheet sheet, in unsigned long type); */
NS_IMETHODIMP nsDOMWindowUtils::AddSheet(nsIDOMStyleSheet *sheet, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSheet (in nsIURI sheetURI, in unsigned long type); */
NS_IMETHODIMP nsDOMWindowUtils::RemoveSheet(nsIURI *sheetURI, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSheetUsingURIString (in ACString sheetURI, in unsigned long type); */
NS_IMETHODIMP nsDOMWindowUtils::RemoveSheetUsingURIString(const nsACString & sheetURI, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isHandlingUserInput; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsHandlingUserInput(bool *aIsHandlingUserInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void allowScriptsToClose (); */
NS_IMETHODIMP nsDOMWindowUtils::AllowScriptsToClose()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isParentWindowMainWidgetVisible; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isNodeDisabledForEvents (in nsIDOMNode aNode); */
NS_IMETHODIMP nsDOMWindowUtils::IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean paintFlashing; */
NS_IMETHODIMP nsDOMWindowUtils::GetPaintFlashing(bool *aPaintFlashing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetPaintFlashing(bool aPaintFlashing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runInStableState (in nsIRunnable runnable); */
NS_IMETHODIMP nsDOMWindowUtils::RunInStableState(nsIRunnable *runnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runBeforeNextEvent (in nsIRunnable runnable); */
NS_IMETHODIMP nsDOMWindowUtils::RunBeforeNextEvent(nsIRunnable *runnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getOMTAStyle (in nsIDOMElement aElement, in AString aProperty); */
NS_IMETHODIMP nsDOMWindowUtils::GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float requestCompositorProperty (in AString aProperty); */
NS_IMETHODIMP nsDOMWindowUtils::RequestCompositorProperty(const nsAString & aProperty, float *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIJSRAIIHelper setHandlingUserInput (in boolean aHandlingInput); */
NS_IMETHODIMP nsDOMWindowUtils::SetHandlingUserInput(bool aHandlingInput, nsIJSRAIIHelper * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getContentAPZTestData (); */
NS_IMETHODIMP nsDOMWindowUtils::GetContentAPZTestData(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getCompositorAPZTestData (); */
NS_IMETHODIMP nsDOMWindowUtils::GetCompositorAPZTestData(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void postRestyleSelfEvent (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::PostRestyleSelfEvent(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean audioMuted; */
NS_IMETHODIMP nsDOMWindowUtils::GetAudioMuted(bool *aAudioMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetAudioMuted(bool aAudioMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float audioVolume; */
NS_IMETHODIMP nsDOMWindowUtils::GetAudioVolume(float *aAudioVolume)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetAudioVolume(float aAudioVolume)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void xpconnectArgument (in nsIDOMWindowUtils aThis); */
NS_IMETHODIMP nsDOMWindowUtils::XpconnectArgument(nsIDOMWindowUtils *aThis)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void askPermission (in nsIContentPermissionRequest aRequest); */
NS_IMETHODIMP nsDOMWindowUtils::AskPermission(nsIContentPermissionRequest *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long framesConstructed; */
NS_IMETHODIMP nsDOMWindowUtils::GetFramesConstructed(uint64_t *aFramesConstructed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long framesReflowed; */
NS_IMETHODIMP nsDOMWindowUtils::GetFramesReflowed(uint64_t *aFramesReflowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setChromeMargin (in int32_t aTop, in int32_t aRight, in int32_t aBottom, in int32_t aLeft); */
NS_IMETHODIMP nsDOMWindowUtils::SetChromeMargin(int32_t aTop, int32_t aRight, int32_t aBottom, int32_t aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean serviceWorkersTestingEnabled; */
NS_IMETHODIMP nsDOMWindowUtils::GetServiceWorkersTestingEnabled(bool *aServiceWorkersTestingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetServiceWorkersTestingEnabled(bool aServiceWorkersTestingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getFrameUniformityTestData (); */
NS_IMETHODIMP nsDOMWindowUtils::GetFrameUniformityTestData(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enterChaosMode (); */
NS_IMETHODIMP nsDOMWindowUtils::EnterChaosMode()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void leaveChaosMode (); */
NS_IMETHODIMP nsDOMWindowUtils::LeaveChaosMode()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITranslationNodeList */
#define NS_ITRANSLATIONNODELIST_IID_STR "c694e359-7227-4392-a138-33c0cc1f15a6"

#define NS_ITRANSLATIONNODELIST_IID \
  {0xc694e359, 0x7227, 0x4392, \
    { 0xa1, 0x38, 0x33, 0xc0, 0xcc, 0x1f, 0x15, 0xa6 }}

class NS_NO_VTABLE nsITranslationNodeList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSLATIONNODELIST_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsIDOMNode item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) = 0;

  /* boolean isTranslationRootAtIndex (in unsigned long index); */
  NS_IMETHOD IsTranslationRootAtIndex(uint32_t index, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITranslationNodeList, NS_ITRANSLATIONNODELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSLATIONNODELIST \
  NS_IMETHOD GetLength(uint32_t *aLength) override; \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) override; \
  NS_IMETHOD IsTranslationRootAtIndex(uint32_t index, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSLATIONNODELIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) override { return _to Item(index, _retval); } \
  NS_IMETHOD IsTranslationRootAtIndex(uint32_t index, bool *_retval) override { return _to IsTranslationRootAtIndex(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSLATIONNODELIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD IsTranslationRootAtIndex(uint32_t index, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsTranslationRootAtIndex(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTranslationNodeList : public nsITranslationNodeList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSLATIONNODELIST

  nsTranslationNodeList();

private:
  ~nsTranslationNodeList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTranslationNodeList, nsITranslationNodeList)

nsTranslationNodeList::nsTranslationNodeList()
{
  /* member initializers and constructor code */
}

nsTranslationNodeList::~nsTranslationNodeList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsTranslationNodeList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP nsTranslationNodeList::Item(uint32_t index, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isTranslationRootAtIndex (in unsigned long index); */
NS_IMETHODIMP nsTranslationNodeList::IsTranslationRootAtIndex(uint32_t index, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJSRAIIHelper */
#define NS_IJSRAIIHELPER_IID_STR "52e5a996-d0a9-4efc-a6fa-24489c532b19"

#define NS_IJSRAIIHELPER_IID \
  {0x52e5a996, 0xd0a9, 0x4efc, \
    { 0xa6, 0xfa, 0x24, 0x48, 0x9c, 0x53, 0x2b, 0x19 }}

class NS_NO_VTABLE nsIJSRAIIHelper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSRAIIHELPER_IID)

  /* void destruct (); */
  NS_IMETHOD Destruct(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSRAIIHelper, NS_IJSRAIIHELPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSRAIIHELPER \
  NS_IMETHOD Destruct(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSRAIIHELPER(_to) \
  NS_IMETHOD Destruct(void) override { return _to Destruct(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSRAIIHELPER(_to) \
  NS_IMETHOD Destruct(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Destruct(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSRAIIHelper : public nsIJSRAIIHelper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSRAIIHELPER

  nsJSRAIIHelper();

private:
  ~nsJSRAIIHelper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsJSRAIIHelper, nsIJSRAIIHelper)

nsJSRAIIHelper::nsJSRAIIHelper()
{
  /* member initializers and constructor code */
}

nsJSRAIIHelper::~nsJSRAIIHelper()
{
  /* destructor code */
}

/* void destruct (); */
NS_IMETHODIMP nsJSRAIIHelper::Destruct()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWindowUtils_h__ */
