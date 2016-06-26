/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDocShell.idl
 */

#ifndef __gen_nsIDocShell_h__
#define __gen_nsIDocShell_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDocShellTreeItem_h__
#include "nsIDocShellTreeItem.h"
#endif

#include "js/Value.h"

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "js/TypeDecls.h"
class nsPresContext;
class nsIPresShell;
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIContentViewer; /* forward declaration */

class nsIURIContentListener; /* forward declaration */

class nsIDOMEventTarget; /* forward declaration */

class nsIDocShellLoadInfo; /* forward declaration */

class nsIEditor; /* forward declaration */

class nsIWebNavigation; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsISHEntry; /* forward declaration */

class nsILayoutHistoryState; /* forward declaration */

class nsISecureBrowserUI; /* forward declaration */

class nsIScriptGlobalObject; /* forward declaration */

class nsIDOMStorage; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIWebBrowserPrint; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIPrivacyTransitionObserver; /* forward declaration */

class nsIReflowObserver; /* forward declaration */

class nsIScrollObserver; /* forward declaration */

class nsITabParent; /* forward declaration */

typedef uint32_t  nsLoadFlags;


/* starting interface:    nsIDocShell */
#define NS_IDOCSHELL_IID_STR "b3137b7c-d589-48aa-b89b-e02aa451d42c"

#define NS_IDOCSHELL_IID \
  {0xb3137b7c, 0xd589, 0x48aa, \
    { 0xb8, 0x9b, 0xe0, 0x2a, 0xa4, 0x51, 0xd4, 0x2c }}

class NS_NO_VTABLE nsIDocShell : public nsIDocShellTreeItem {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELL_IID)

  /* [noscript] void loadURI (in nsIURI uri, in nsIDocShellLoadInfo loadInfo, in unsigned long aLoadFlags, in boolean firstParty); */
  NS_IMETHOD LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, uint32_t aLoadFlags, bool firstParty) = 0;

  /* [noscript] void loadStream (in nsIInputStream aStream, in nsIURI aURI, in ACString aContentType, in ACString aContentCharset, in nsIDocShellLoadInfo aLoadInfo); */
  NS_IMETHOD LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo) = 0;

  enum {
    INTERNAL_LOAD_FLAGS_NONE = 0,
    INTERNAL_LOAD_FLAGS_INHERIT_OWNER = 1,
    INTERNAL_LOAD_FLAGS_DONT_SEND_REFERRER = 2,
    INTERNAL_LOAD_FLAGS_ALLOW_THIRD_PARTY_FIXUP = 4,
    INTERNAL_LOAD_FLAGS_FIRST_LOAD = 8,
    INTERNAL_LOAD_FLAGS_BYPASS_CLASSIFIER = 16,
    INTERNAL_LOAD_FLAGS_FORCE_ALLOW_COOKIES = 32,
    INTERNAL_LOAD_FLAGS_IS_SRCDOC = 64,
    INTERNAL_LOAD_FLAGS_NO_OPENER = 256
  };

  /* [noscript] void internalLoad (in nsIURI aURI, in nsIURI aReferrer, in unsigned long aReferrerPolicy, in nsISupports aOwner, in uint32_t aFlags, in wstring aWindowTarget, in string aTypeHint, in AString aFileName, in nsIInputStream aPostDataStream, in nsIInputStream aHeadersStream, in unsigned long aLoadFlags, in nsISHEntry aSHEntry, in boolean firstParty, in AString aSrcdoc, in nsIDocShell aSourceDocShell, in nsIURI aBaseURI, out nsIDocShell aDocShell, out nsIRequest aRequest); */
  NS_IMETHOD InternalLoad(nsIURI *aURI, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsISupports *aOwner, uint32_t aFlags, const char16_t * aWindowTarget, const char * aTypeHint, const nsAString & aFileName, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, uint32_t aLoadFlags, nsISHEntry *aSHEntry, bool firstParty, const nsAString & aSrcdoc, nsIDocShell *aSourceDocShell, nsIURI *aBaseURI, nsIDocShell * *aDocShell, nsIRequest * *aRequest) = 0;

  /* [implicit_jscontext] void addState (in jsval aData, in DOMString aTitle, in DOMString aURL, in boolean aReplace); */
  NS_IMETHOD AddState(JS::HandleValue aData, const nsAString & aTitle, const nsAString & aURL, bool aReplace, JSContext* cx) = 0;

  /* void createLoadInfo (out nsIDocShellLoadInfo loadInfo); */
  NS_IMETHOD CreateLoadInfo(nsIDocShellLoadInfo * *loadInfo) = 0;

  /* void prepareForNewContentModel (); */
  NS_IMETHOD PrepareForNewContentModel(void) = 0;

  /* void setCurrentURI (in nsIURI aURI); */
  NS_IMETHOD SetCurrentURI(nsIURI *aURI) = 0;

  /* [noscript] void firePageHideNotification (in boolean isUnload); */
  NS_IMETHOD FirePageHideNotification(bool isUnload) = 0;

  /* [noscript] readonly attribute nsPresContext presContext; */
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) = 0;

  /* [noscript,notxpcom] nsIPresShell GetPresShell (); */
  NS_IMETHOD_(nsIPresShell *) GetPresShell(void) = 0;

  /* [noscript] readonly attribute nsIPresShell eldestPresShell; */
  NS_IMETHOD GetEldestPresShell(nsIPresShell **aEldestPresShell) = 0;

  /* readonly attribute nsIContentViewer contentViewer; */
  NS_IMETHOD GetContentViewer(nsIContentViewer * *aContentViewer) = 0;

  /* attribute nsIDOMEventTarget chromeEventHandler; */
  NS_IMETHOD GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler) = 0;
  NS_IMETHOD SetChromeEventHandler(nsIDOMEventTarget *aChromeEventHandler) = 0;

  /* attribute boolean allowPlugins; */
  NS_IMETHOD GetAllowPlugins(bool *aAllowPlugins) = 0;
  NS_IMETHOD SetAllowPlugins(bool aAllowPlugins) = 0;

  /* attribute boolean allowJavascript; */
  NS_IMETHOD GetAllowJavascript(bool *aAllowJavascript) = 0;
  NS_IMETHOD SetAllowJavascript(bool aAllowJavascript) = 0;

  /* attribute boolean allowMetaRedirects; */
  NS_IMETHOD GetAllowMetaRedirects(bool *aAllowMetaRedirects) = 0;
  NS_IMETHOD SetAllowMetaRedirects(bool aAllowMetaRedirects) = 0;

  /* attribute boolean allowSubframes; */
  NS_IMETHOD GetAllowSubframes(bool *aAllowSubframes) = 0;
  NS_IMETHOD SetAllowSubframes(bool aAllowSubframes) = 0;

  /* attribute boolean allowImages; */
  NS_IMETHOD GetAllowImages(bool *aAllowImages) = 0;
  NS_IMETHOD SetAllowImages(bool aAllowImages) = 0;

  /* [infallible] attribute boolean allowMedia; */
  NS_IMETHOD GetAllowMedia(bool *aAllowMedia) = 0;
  inline bool GetAllowMedia()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetAllowMedia(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  NS_IMETHOD SetAllowMedia(bool aAllowMedia) = 0;

  /* attribute boolean allowDNSPrefetch; */
  NS_IMETHOD GetAllowDNSPrefetch(bool *aAllowDNSPrefetch) = 0;
  NS_IMETHOD SetAllowDNSPrefetch(bool aAllowDNSPrefetch) = 0;

  /* attribute boolean allowWindowControl; */
  NS_IMETHOD GetAllowWindowControl(bool *aAllowWindowControl) = 0;
  NS_IMETHOD SetAllowWindowControl(bool aAllowWindowControl) = 0;

  /* [infallible] attribute boolean allowContentRetargeting; */
  NS_IMETHOD GetAllowContentRetargeting(bool *aAllowContentRetargeting) = 0;
  inline bool GetAllowContentRetargeting()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetAllowContentRetargeting(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  NS_IMETHOD SetAllowContentRetargeting(bool aAllowContentRetargeting) = 0;

  /* [infallible] attribute boolean allowContentRetargetingOnChildren; */
  NS_IMETHOD GetAllowContentRetargetingOnChildren(bool *aAllowContentRetargetingOnChildren) = 0;
  inline bool GetAllowContentRetargetingOnChildren()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetAllowContentRetargetingOnChildren(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  NS_IMETHOD SetAllowContentRetargetingOnChildren(bool aAllowContentRetargetingOnChildren) = 0;

  enum {
    ENUMERATE_FORWARDS = 0,
    ENUMERATE_BACKWARDS = 1
  };

  /* nsISimpleEnumerator getDocShellEnumerator (in long aItemType, in long aDirection); */
  NS_IMETHOD GetDocShellEnumerator(int32_t aItemType, int32_t aDirection, nsISimpleEnumerator * *_retval) = 0;

  enum {
    APP_TYPE_UNKNOWN = 0U,
    APP_TYPE_MAIL = 1U,
    APP_TYPE_EDITOR = 2U
  };

  /* attribute unsigned long appType; */
  NS_IMETHOD GetAppType(uint32_t *aAppType) = 0;
  NS_IMETHOD SetAppType(uint32_t aAppType) = 0;

  /* attribute boolean allowAuth; */
  NS_IMETHOD GetAllowAuth(bool *aAllowAuth) = 0;
  NS_IMETHOD SetAllowAuth(bool aAllowAuth) = 0;

  /* attribute float zoom; */
  NS_IMETHOD GetZoom(float *aZoom) = 0;
  NS_IMETHOD SetZoom(float aZoom) = 0;

  /* attribute long marginWidth; */
  NS_IMETHOD GetMarginWidth(int32_t *aMarginWidth) = 0;
  NS_IMETHOD SetMarginWidth(int32_t aMarginWidth) = 0;

  /* attribute long marginHeight; */
  NS_IMETHOD GetMarginHeight(int32_t *aMarginHeight) = 0;
  NS_IMETHOD SetMarginHeight(int32_t aMarginHeight) = 0;

  /* void tabToTreeOwner (in boolean forward, out boolean tookFocus); */
  NS_IMETHOD TabToTreeOwner(bool forward, bool *tookFocus) = 0;

  enum {
    BUSY_FLAGS_NONE = 0U,
    BUSY_FLAGS_BUSY = 1U,
    BUSY_FLAGS_BEFORE_PAGE_LOAD = 2U,
    BUSY_FLAGS_PAGE_LOADING = 4U,
    LOAD_CMD_NORMAL = 1U,
    LOAD_CMD_RELOAD = 2U,
    LOAD_CMD_HISTORY = 4U,
    LOAD_CMD_PUSHSTATE = 8U
  };

  /* readonly attribute unsigned long busyFlags; */
  NS_IMETHOD GetBusyFlags(uint32_t *aBusyFlags) = 0;

  /* attribute unsigned long loadType; */
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) = 0;
  NS_IMETHOD SetLoadType(uint32_t aLoadType) = 0;

  /* attribute nsLoadFlags defaultLoadFlags; */
  NS_IMETHOD GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags) = 0;
  NS_IMETHOD SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags) = 0;

  /* boolean isBeingDestroyed (); */
  NS_IMETHOD IsBeingDestroyed(bool *_retval) = 0;

  /* readonly attribute boolean isExecutingOnLoadHandler; */
  NS_IMETHOD GetIsExecutingOnLoadHandler(bool *aIsExecutingOnLoadHandler) = 0;

  /* attribute nsILayoutHistoryState layoutHistoryState; */
  NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState) = 0;
  NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState) = 0;

  /* readonly attribute boolean shouldSaveLayoutState; */
  NS_IMETHOD GetShouldSaveLayoutState(bool *aShouldSaveLayoutState) = 0;

  /* attribute nsISecureBrowserUI securityUI; */
  NS_IMETHOD GetSecurityUI(nsISecureBrowserUI * *aSecurityUI) = 0;
  NS_IMETHOD SetSecurityUI(nsISecureBrowserUI *aSecurityUI) = 0;

  /* void suspendRefreshURIs (); */
  NS_IMETHOD SuspendRefreshURIs(void) = 0;

  /* void resumeRefreshURIs (); */
  NS_IMETHOD ResumeRefreshURIs(void) = 0;

  /* void beginRestore (in nsIContentViewer viewer, in boolean top); */
  NS_IMETHOD BeginRestore(nsIContentViewer *viewer, bool top) = 0;

  /* void finishRestore (); */
  NS_IMETHOD FinishRestore(void) = 0;

  /* readonly attribute boolean restoringDocument; */
  NS_IMETHOD GetRestoringDocument(bool *aRestoringDocument) = 0;

  /* attribute boolean useErrorPages; */
  NS_IMETHOD GetUseErrorPages(bool *aUseErrorPages) = 0;
  NS_IMETHOD SetUseErrorPages(bool aUseErrorPages) = 0;

  /* void displayLoadError (in nsresult aError, in nsIURI aURI, in wstring aURL, [optional] in nsIChannel aFailedChannel); */
  NS_IMETHOD DisplayLoadError(nsresult aError, nsIURI *aURI, const char16_t * aURL, nsIChannel *aFailedChannel) = 0;

  /* readonly attribute nsIChannel failedChannel; */
  NS_IMETHOD GetFailedChannel(nsIChannel * *aFailedChannel) = 0;

  /* readonly attribute long previousTransIndex; */
  NS_IMETHOD GetPreviousTransIndex(int32_t *aPreviousTransIndex) = 0;

  /* readonly attribute long loadedTransIndex; */
  NS_IMETHOD GetLoadedTransIndex(int32_t *aLoadedTransIndex) = 0;

  /* void historyPurged (in long numEntries); */
  NS_IMETHOD HistoryPurged(int32_t numEntries) = 0;

  /* nsIDOMStorage getSessionStorageForPrincipal (in nsIPrincipal principal, in DOMString documentURI, in boolean create); */
  NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, const nsAString & documentURI, bool create, nsIDOMStorage * *_retval) = 0;

  /* void addSessionStorage (in nsIPrincipal principal, in nsIDOMStorage storage); */
  NS_IMETHOD AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage *storage) = 0;

  /* readonly attribute nsIChannel currentDocumentChannel; */
  NS_IMETHOD GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel) = 0;

  /* [noscript] void setChildOffset (in unsigned long offset); */
  NS_IMETHOD SetChildOffset(uint32_t offset) = 0;

  /* readonly attribute boolean isInUnload; */
  NS_IMETHOD GetIsInUnload(bool *aIsInUnload) = 0;

  /* readonly attribute boolean channelIsUnsafe; */
  NS_IMETHOD GetChannelIsUnsafe(bool *aChannelIsUnsafe) = 0;

  /* [infallible] readonly attribute boolean hasMixedActiveContentLoaded; */
  NS_IMETHOD GetHasMixedActiveContentLoaded(bool *aHasMixedActiveContentLoaded) = 0;
  inline bool GetHasMixedActiveContentLoaded()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetHasMixedActiveContentLoaded(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean hasMixedActiveContentBlocked; */
  NS_IMETHOD GetHasMixedActiveContentBlocked(bool *aHasMixedActiveContentBlocked) = 0;
  inline bool GetHasMixedActiveContentBlocked()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetHasMixedActiveContentBlocked(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean hasMixedDisplayContentLoaded; */
  NS_IMETHOD GetHasMixedDisplayContentLoaded(bool *aHasMixedDisplayContentLoaded) = 0;
  inline bool GetHasMixedDisplayContentLoaded()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetHasMixedDisplayContentLoaded(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean hasMixedDisplayContentBlocked; */
  NS_IMETHOD GetHasMixedDisplayContentBlocked(bool *aHasMixedDisplayContentBlocked) = 0;
  inline bool GetHasMixedDisplayContentBlocked()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetHasMixedDisplayContentBlocked(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean hasTrackingContentBlocked; */
  NS_IMETHOD GetHasTrackingContentBlocked(bool *aHasTrackingContentBlocked) = 0;
  inline bool GetHasTrackingContentBlocked()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetHasTrackingContentBlocked(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean hasTrackingContentLoaded; */
  NS_IMETHOD GetHasTrackingContentLoaded(bool *aHasTrackingContentLoaded) = 0;
  inline bool GetHasTrackingContentLoaded()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetHasTrackingContentLoaded(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [noscript,notxpcom] void DetachEditorFromWindow (); */
  NS_IMETHOD_(void) DetachEditorFromWindow(void) = 0;

  /* attribute boolean isOffScreenBrowser; */
  NS_IMETHOD GetIsOffScreenBrowser(bool *aIsOffScreenBrowser) = 0;
  NS_IMETHOD SetIsOffScreenBrowser(bool aIsOffScreenBrowser) = 0;

  /* readonly attribute nsIWebBrowserPrint printPreview; */
  NS_IMETHOD GetPrintPreview(nsIWebBrowserPrint * *aPrintPreview) = 0;

  /* [infallible] readonly attribute boolean canExecuteScripts; */
  NS_IMETHOD GetCanExecuteScripts(bool *aCanExecuteScripts) = 0;
  inline bool GetCanExecuteScripts()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetCanExecuteScripts(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* attribute boolean isActive; */
  NS_IMETHOD GetIsActive(bool *aIsActive) = 0;
  NS_IMETHOD SetIsActive(bool aIsActive) = 0;

  /* [noscript] void SetIsPrerendered (in boolean prerendered); */
  NS_IMETHOD SetIsPrerendered(bool prerendered) = 0;

  /* [infallible] readonly attribute boolean isPrerendered; */
  NS_IMETHOD GetIsPrerendered(bool *aIsPrerendered) = 0;
  inline bool GetIsPrerendered()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsPrerendered(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* readonly attribute unsigned long long historyID; */
  NS_IMETHOD GetHistoryID(uint64_t *aHistoryID) = 0;

  /* attribute boolean isAppTab; */
  NS_IMETHOD GetIsAppTab(bool *aIsAppTab) = 0;
  NS_IMETHOD SetIsAppTab(bool aIsAppTab) = 0;

  /* void createAboutBlankContentViewer (in nsIPrincipal aPrincipal); */
  NS_IMETHOD CreateAboutBlankContentViewer(nsIPrincipal *aPrincipal) = 0;

  /* attribute ACString charset; */
  NS_IMETHOD GetCharset(nsACString & aCharset) = 0;
  NS_IMETHOD SetCharset(const nsACString & aCharset) = 0;

  /* void gatherCharsetMenuTelemetry (); */
  NS_IMETHOD GatherCharsetMenuTelemetry(void) = 0;

  /* attribute ACString forcedCharset; */
  NS_IMETHOD GetForcedCharset(nsACString & aForcedCharset) = 0;
  NS_IMETHOD SetForcedCharset(const nsACString & aForcedCharset) = 0;

  /* [noscript,nostdcall,notxpcom] void setParentCharset (in ACString parentCharset, in int32_t parentCharsetSource, in nsIPrincipal parentCharsetPrincipal); */
  virtual void SetParentCharset(const nsACString & parentCharset, int32_t parentCharsetSource, nsIPrincipal *parentCharsetPrincipal) = 0;

  /* [noscript,nostdcall,notxpcom] void getParentCharset (out ACString parentCharset, out int32_t parentCharsetSource, out nsIPrincipal parentCharsetPrincipal); */
  virtual void GetParentCharset(nsACString & parentCharset, int32_t *parentCharsetSource, nsIPrincipal * *parentCharsetPrincipal) = 0;

  /* [infallible] attribute boolean recordProfileTimelineMarkers; */
  NS_IMETHOD GetRecordProfileTimelineMarkers(bool *aRecordProfileTimelineMarkers) = 0;
  inline bool GetRecordProfileTimelineMarkers()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetRecordProfileTimelineMarkers(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  NS_IMETHOD SetRecordProfileTimelineMarkers(bool aRecordProfileTimelineMarkers) = 0;

  /* DOMHighResTimeStamp now (); */
  NS_IMETHOD Now(DOMHighResTimeStamp *_retval) = 0;

  /* [implicit_jscontext] jsval popProfileTimelineMarkers (); */
  NS_IMETHOD PopProfileTimelineMarkers(JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* void addWeakPrivacyTransitionObserver (in nsIPrivacyTransitionObserver obs); */
  NS_IMETHOD AddWeakPrivacyTransitionObserver(nsIPrivacyTransitionObserver *obs) = 0;

  /* void addWeakReflowObserver (in nsIReflowObserver obs); */
  NS_IMETHOD AddWeakReflowObserver(nsIReflowObserver *obs) = 0;

  /* void removeWeakReflowObserver (in nsIReflowObserver obs); */
  NS_IMETHOD RemoveWeakReflowObserver(nsIReflowObserver *obs) = 0;

  /* [noscript] void notifyReflowObservers (in bool interruptible, in DOMHighResTimeStamp start, in DOMHighResTimeStamp end); */
  NS_IMETHOD NotifyReflowObservers(bool interruptible, DOMHighResTimeStamp start, DOMHighResTimeStamp end) = 0;

  /* [noscript] void addWeakScrollObserver (in nsIScrollObserver obs); */
  NS_IMETHOD AddWeakScrollObserver(nsIScrollObserver *obs) = 0;

  /* [noscript] void removeWeakScrollObserver (in nsIScrollObserver obs); */
  NS_IMETHOD RemoveWeakScrollObserver(nsIScrollObserver *obs) = 0;

  /* [noscript] void notifyScrollObservers (); */
  NS_IMETHOD NotifyScrollObservers(void) = 0;

  /* [infallible] readonly attribute boolean isBrowserElement; */
  NS_IMETHOD GetIsBrowserElement(bool *aIsBrowserElement) = 0;
  inline bool GetIsBrowserElement()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsBrowserElement(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean isApp; */
  NS_IMETHOD GetIsApp(bool *aIsApp) = 0;
  inline bool GetIsApp()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsApp(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean isBrowserOrApp; */
  NS_IMETHOD GetIsBrowserOrApp(bool *aIsBrowserOrApp) = 0;
  inline bool GetIsBrowserOrApp()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsBrowserOrApp(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean isInBrowserElement; */
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) = 0;
  inline bool GetIsInBrowserElement()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsInBrowserElement(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean isInBrowserOrApp; */
  NS_IMETHOD GetIsInBrowserOrApp(bool *aIsInBrowserOrApp) = 0;
  inline bool GetIsInBrowserOrApp()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsInBrowserOrApp(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* void setIsApp (in unsigned long ownAppId); */
  NS_IMETHOD SetIsApp(uint32_t ownAppId) = 0;

  /* void setIsBrowserInsideApp (in unsigned long containingAppId); */
  NS_IMETHOD SetIsBrowserInsideApp(uint32_t containingAppId) = 0;

  /* [infallible] readonly attribute unsigned long appId; */
  NS_IMETHOD GetAppId(uint32_t *aAppId) = 0;
  inline uint32_t GetAppId()
  {
    uint32_t result;
    mozilla::DebugOnly<nsresult> rv = GetAppId(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* readonly attribute DOMString appManifestURL; */
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) = 0;

  /* nsIDocShell getSameTypeParentIgnoreBrowserAndAppBoundaries (); */
  NS_IMETHOD GetSameTypeParentIgnoreBrowserAndAppBoundaries(nsIDocShell * *_retval) = 0;

  /* readonly attribute bool asyncPanZoomEnabled; */
  NS_IMETHOD GetAsyncPanZoomEnabled(bool *aAsyncPanZoomEnabled) = 0;

  /* attribute unsigned long sandboxFlags; */
  NS_IMETHOD GetSandboxFlags(uint32_t *aSandboxFlags) = 0;
  NS_IMETHOD SetSandboxFlags(uint32_t aSandboxFlags) = 0;

  /* attribute nsIDocShell onePermittedSandboxedNavigator; */
  NS_IMETHOD GetOnePermittedSandboxedNavigator(nsIDocShell * *aOnePermittedSandboxedNavigator) = 0;
  NS_IMETHOD SetOnePermittedSandboxedNavigator(nsIDocShell *aOnePermittedSandboxedNavigator) = 0;

  /* [noscript,nostdcall,notxpcom] bool isSandboxedFrom (in nsIDocShell aTargetDocShell); */
  virtual bool IsSandboxedFrom(nsIDocShell *aTargetDocShell) = 0;

  /* attribute nsIChannel mixedContentChannel; */
  NS_IMETHOD GetMixedContentChannel(nsIChannel * *aMixedContentChannel) = 0;
  NS_IMETHOD SetMixedContentChannel(nsIChannel *aMixedContentChannel) = 0;

  /* void GetAllowMixedContentAndConnectionData (out boolean rootHasSecureConnection, out boolean allowMixedContent, out boolean isRootDocShell); */
  NS_IMETHOD GetAllowMixedContentAndConnectionData(bool *rootHasSecureConnection, bool *allowMixedContent, bool *isRootDocShell) = 0;

  /* [noscript,notxpcom] bool pluginsAllowedInCurrentDoc (); */
  NS_IMETHOD_(bool) PluginsAllowedInCurrentDoc(void) = 0;

  /* [infallible] readonly attribute boolean fullscreenAllowed; */
  NS_IMETHOD GetFullscreenAllowed(bool *aFullscreenAllowed) = 0;
  inline bool GetFullscreenAllowed()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetFullscreenAllowed(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* void setFullscreenAllowed (in boolean allowed); */
  NS_IMETHOD SetFullscreenAllowed(bool allowed) = 0;

  /* [infallible,noscript] attribute boolean affectPrivateSessionLifetime; */
  NS_IMETHOD GetAffectPrivateSessionLifetime(bool *aAffectPrivateSessionLifetime) = 0;
  inline bool GetAffectPrivateSessionLifetime()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetAffectPrivateSessionLifetime(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  NS_IMETHOD SetAffectPrivateSessionLifetime(bool aAffectPrivateSessionLifetime) = 0;

  /* [infallible] readonly attribute boolean mayEnableCharacterEncodingMenu; */
  NS_IMETHOD GetMayEnableCharacterEncodingMenu(bool *aMayEnableCharacterEncodingMenu) = 0;
  inline bool GetMayEnableCharacterEncodingMenu()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetMayEnableCharacterEncodingMenu(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* attribute nsIEditor editor; */
  NS_IMETHOD GetEditor(nsIEditor * *aEditor) = 0;
  NS_IMETHOD SetEditor(nsIEditor *aEditor) = 0;

  /* readonly attribute boolean editable; */
  NS_IMETHOD GetEditable(bool *aEditable) = 0;

  /* readonly attribute boolean hasEditingSession; */
  NS_IMETHOD GetHasEditingSession(bool *aHasEditingSession) = 0;

  /* void makeEditable (in boolean inWaitForUriLoad); */
  NS_IMETHOD MakeEditable(bool inWaitForUriLoad) = 0;

  /* nsISHEntry getChildSHEntry (in long aChildOffset); */
  NS_IMETHOD GetChildSHEntry(int32_t aChildOffset, nsISHEntry * *_retval) = 0;

  /* void addChildSHEntry (in nsISHEntry aCloneReference, in nsISHEntry aHistoryEntry, in long aChildOffset, in unsigned long aLoadType, in boolean aCloneChilden); */
  NS_IMETHOD AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, int32_t aChildOffset, uint32_t aLoadType, bool aCloneChilden) = 0;

  /* attribute boolean useGlobalHistory; */
  NS_IMETHOD GetUseGlobalHistory(bool *aUseGlobalHistory) = 0;
  NS_IMETHOD SetUseGlobalHistory(bool aUseGlobalHistory) = 0;

  /* void removeFromSessionHistory (); */
  NS_IMETHOD RemoveFromSessionHistory(void) = 0;

  /* attribute boolean createdDynamically; */
  NS_IMETHOD GetCreatedDynamically(bool *aCreatedDynamically) = 0;
  NS_IMETHOD SetCreatedDynamically(bool aCreatedDynamically) = 0;

  /* boolean getCurrentSHEntry (out nsISHEntry aEntry); */
  NS_IMETHOD GetCurrentSHEntry(nsISHEntry * *aEntry, bool *_retval) = 0;

  /* boolean isCommandEnabled (in string command); */
  NS_IMETHOD IsCommandEnabled(const char * command, bool *_retval) = 0;

  /* void doCommand (in string command); */
  NS_IMETHOD DoCommand(const char * command) = 0;

  /* [noscript,notxpcom] bool IsInvisible (); */
  NS_IMETHOD_(bool) IsInvisible(void) = 0;

  /* [noscript,notxpcom] void SetInvisible (in bool aIsInvisibleDochsell); */
  NS_IMETHOD_(void) SetInvisible(bool aIsInvisibleDochsell) = 0;

  /* [noscript,nostdcall,notxpcom] nsIScriptGlobalObject GetScriptGlobalObject (); */
  virtual nsIScriptGlobalObject * GetScriptGlobalObject(void) = 0;

  /* [infallible] attribute boolean deviceSizeIsPageSize; */
  NS_IMETHOD GetDeviceSizeIsPageSize(bool *aDeviceSizeIsPageSize) = 0;
  inline bool GetDeviceSizeIsPageSize()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetDeviceSizeIsPageSize(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  NS_IMETHOD SetDeviceSizeIsPageSize(bool aDeviceSizeIsPageSize) = 0;

  /* [noscript,nostdcall,notxpcom] void setOpener (in nsITabParent aOpener); */
  virtual void SetOpener(nsITabParent *aOpener) = 0;

  /* [noscript,nostdcall,notxpcom] nsITabParent getOpener (); */
  virtual nsITabParent * GetOpener(void) = 0;

  /* [noscript,nostdcall,notxpcom] void notifyJSRunToCompletionStart (in string aReason, in wstring functionName, in wstring fileName, in unsigned long lineNumber); */
  virtual void NotifyJSRunToCompletionStart(const char * aReason, const char16_t * functionName, const char16_t * fileName, uint32_t lineNumber) = 0;

  /* [noscript,nostdcall,notxpcom] void notifyJSRunToCompletionStop (); */
  virtual void NotifyJSRunToCompletionStop(void) = 0;

  /* [infallible] readonly attribute boolean hasLoadedNonBlankURI; */
  NS_IMETHOD GetHasLoadedNonBlankURI(bool *aHasLoadedNonBlankURI) = 0;
  inline bool GetHasLoadedNonBlankURI()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetHasLoadedNonBlankURI(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* attribute DOMString paymentRequestId; */
  NS_IMETHOD GetPaymentRequestId(nsAString & aPaymentRequestId) = 0;
  NS_IMETHOD SetPaymentRequestId(const nsAString & aPaymentRequestId) = 0;

  /* attribute boolean windowDraggingAllowed; */
  NS_IMETHOD GetWindowDraggingAllowed(bool *aWindowDraggingAllowed) = 0;
  NS_IMETHOD SetWindowDraggingAllowed(bool aWindowDraggingAllowed) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShell, NS_IDOCSHELL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELL \
  NS_IMETHOD LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, uint32_t aLoadFlags, bool firstParty) override; \
  NS_IMETHOD LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo) override; \
  NS_IMETHOD InternalLoad(nsIURI *aURI, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsISupports *aOwner, uint32_t aFlags, const char16_t * aWindowTarget, const char * aTypeHint, const nsAString & aFileName, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, uint32_t aLoadFlags, nsISHEntry *aSHEntry, bool firstParty, const nsAString & aSrcdoc, nsIDocShell *aSourceDocShell, nsIURI *aBaseURI, nsIDocShell * *aDocShell, nsIRequest * *aRequest) override; \
  NS_IMETHOD AddState(JS::HandleValue aData, const nsAString & aTitle, const nsAString & aURL, bool aReplace, JSContext* cx) override; \
  NS_IMETHOD CreateLoadInfo(nsIDocShellLoadInfo * *loadInfo) override; \
  NS_IMETHOD PrepareForNewContentModel(void) override; \
  NS_IMETHOD SetCurrentURI(nsIURI *aURI) override; \
  NS_IMETHOD FirePageHideNotification(bool isUnload) override; \
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) override; \
  NS_IMETHOD_(nsIPresShell *) GetPresShell(void) override; \
  NS_IMETHOD GetEldestPresShell(nsIPresShell **aEldestPresShell) override; \
  NS_IMETHOD GetContentViewer(nsIContentViewer * *aContentViewer) override; \
  NS_IMETHOD GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler) override; \
  NS_IMETHOD SetChromeEventHandler(nsIDOMEventTarget *aChromeEventHandler) override; \
  NS_IMETHOD GetAllowPlugins(bool *aAllowPlugins) override; \
  NS_IMETHOD SetAllowPlugins(bool aAllowPlugins) override; \
  NS_IMETHOD GetAllowJavascript(bool *aAllowJavascript) override; \
  NS_IMETHOD SetAllowJavascript(bool aAllowJavascript) override; \
  NS_IMETHOD GetAllowMetaRedirects(bool *aAllowMetaRedirects) override; \
  NS_IMETHOD SetAllowMetaRedirects(bool aAllowMetaRedirects) override; \
  NS_IMETHOD GetAllowSubframes(bool *aAllowSubframes) override; \
  NS_IMETHOD SetAllowSubframes(bool aAllowSubframes) override; \
  NS_IMETHOD GetAllowImages(bool *aAllowImages) override; \
  NS_IMETHOD SetAllowImages(bool aAllowImages) override; \
  using nsIDocShell::GetAllowMedia; \
  NS_IMETHOD GetAllowMedia(bool *aAllowMedia) override; \
  NS_IMETHOD SetAllowMedia(bool aAllowMedia) override; \
  NS_IMETHOD GetAllowDNSPrefetch(bool *aAllowDNSPrefetch) override; \
  NS_IMETHOD SetAllowDNSPrefetch(bool aAllowDNSPrefetch) override; \
  NS_IMETHOD GetAllowWindowControl(bool *aAllowWindowControl) override; \
  NS_IMETHOD SetAllowWindowControl(bool aAllowWindowControl) override; \
  using nsIDocShell::GetAllowContentRetargeting; \
  NS_IMETHOD GetAllowContentRetargeting(bool *aAllowContentRetargeting) override; \
  NS_IMETHOD SetAllowContentRetargeting(bool aAllowContentRetargeting) override; \
  using nsIDocShell::GetAllowContentRetargetingOnChildren; \
  NS_IMETHOD GetAllowContentRetargetingOnChildren(bool *aAllowContentRetargetingOnChildren) override; \
  NS_IMETHOD SetAllowContentRetargetingOnChildren(bool aAllowContentRetargetingOnChildren) override; \
  NS_IMETHOD GetDocShellEnumerator(int32_t aItemType, int32_t aDirection, nsISimpleEnumerator * *_retval) override; \
  NS_IMETHOD GetAppType(uint32_t *aAppType) override; \
  NS_IMETHOD SetAppType(uint32_t aAppType) override; \
  NS_IMETHOD GetAllowAuth(bool *aAllowAuth) override; \
  NS_IMETHOD SetAllowAuth(bool aAllowAuth) override; \
  NS_IMETHOD GetZoom(float *aZoom) override; \
  NS_IMETHOD SetZoom(float aZoom) override; \
  NS_IMETHOD GetMarginWidth(int32_t *aMarginWidth) override; \
  NS_IMETHOD SetMarginWidth(int32_t aMarginWidth) override; \
  NS_IMETHOD GetMarginHeight(int32_t *aMarginHeight) override; \
  NS_IMETHOD SetMarginHeight(int32_t aMarginHeight) override; \
  NS_IMETHOD TabToTreeOwner(bool forward, bool *tookFocus) override; \
  NS_IMETHOD GetBusyFlags(uint32_t *aBusyFlags) override; \
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) override; \
  NS_IMETHOD SetLoadType(uint32_t aLoadType) override; \
  NS_IMETHOD GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags) override; \
  NS_IMETHOD SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags) override; \
  NS_IMETHOD IsBeingDestroyed(bool *_retval) override; \
  NS_IMETHOD GetIsExecutingOnLoadHandler(bool *aIsExecutingOnLoadHandler) override; \
  NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState) override; \
  NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState) override; \
  NS_IMETHOD GetShouldSaveLayoutState(bool *aShouldSaveLayoutState) override; \
  NS_IMETHOD GetSecurityUI(nsISecureBrowserUI * *aSecurityUI) override; \
  NS_IMETHOD SetSecurityUI(nsISecureBrowserUI *aSecurityUI) override; \
  NS_IMETHOD SuspendRefreshURIs(void) override; \
  NS_IMETHOD ResumeRefreshURIs(void) override; \
  NS_IMETHOD BeginRestore(nsIContentViewer *viewer, bool top) override; \
  NS_IMETHOD FinishRestore(void) override; \
  NS_IMETHOD GetRestoringDocument(bool *aRestoringDocument) override; \
  NS_IMETHOD GetUseErrorPages(bool *aUseErrorPages) override; \
  NS_IMETHOD SetUseErrorPages(bool aUseErrorPages) override; \
  NS_IMETHOD DisplayLoadError(nsresult aError, nsIURI *aURI, const char16_t * aURL, nsIChannel *aFailedChannel) override; \
  NS_IMETHOD GetFailedChannel(nsIChannel * *aFailedChannel) override; \
  NS_IMETHOD GetPreviousTransIndex(int32_t *aPreviousTransIndex) override; \
  NS_IMETHOD GetLoadedTransIndex(int32_t *aLoadedTransIndex) override; \
  NS_IMETHOD HistoryPurged(int32_t numEntries) override; \
  NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, const nsAString & documentURI, bool create, nsIDOMStorage * *_retval) override; \
  NS_IMETHOD AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage *storage) override; \
  NS_IMETHOD GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel) override; \
  NS_IMETHOD SetChildOffset(uint32_t offset) override; \
  NS_IMETHOD GetIsInUnload(bool *aIsInUnload) override; \
  NS_IMETHOD GetChannelIsUnsafe(bool *aChannelIsUnsafe) override; \
  using nsIDocShell::GetHasMixedActiveContentLoaded; \
  NS_IMETHOD GetHasMixedActiveContentLoaded(bool *aHasMixedActiveContentLoaded) override; \
  using nsIDocShell::GetHasMixedActiveContentBlocked; \
  NS_IMETHOD GetHasMixedActiveContentBlocked(bool *aHasMixedActiveContentBlocked) override; \
  using nsIDocShell::GetHasMixedDisplayContentLoaded; \
  NS_IMETHOD GetHasMixedDisplayContentLoaded(bool *aHasMixedDisplayContentLoaded) override; \
  using nsIDocShell::GetHasMixedDisplayContentBlocked; \
  NS_IMETHOD GetHasMixedDisplayContentBlocked(bool *aHasMixedDisplayContentBlocked) override; \
  using nsIDocShell::GetHasTrackingContentBlocked; \
  NS_IMETHOD GetHasTrackingContentBlocked(bool *aHasTrackingContentBlocked) override; \
  using nsIDocShell::GetHasTrackingContentLoaded; \
  NS_IMETHOD GetHasTrackingContentLoaded(bool *aHasTrackingContentLoaded) override; \
  NS_IMETHOD_(void) DetachEditorFromWindow(void) override; \
  NS_IMETHOD GetIsOffScreenBrowser(bool *aIsOffScreenBrowser) override; \
  NS_IMETHOD SetIsOffScreenBrowser(bool aIsOffScreenBrowser) override; \
  NS_IMETHOD GetPrintPreview(nsIWebBrowserPrint * *aPrintPreview) override; \
  using nsIDocShell::GetCanExecuteScripts; \
  NS_IMETHOD GetCanExecuteScripts(bool *aCanExecuteScripts) override; \
  NS_IMETHOD GetIsActive(bool *aIsActive) override; \
  NS_IMETHOD SetIsActive(bool aIsActive) override; \
  NS_IMETHOD SetIsPrerendered(bool prerendered) override; \
  using nsIDocShell::GetIsPrerendered; \
  NS_IMETHOD GetIsPrerendered(bool *aIsPrerendered) override; \
  NS_IMETHOD GetHistoryID(uint64_t *aHistoryID) override; \
  NS_IMETHOD GetIsAppTab(bool *aIsAppTab) override; \
  NS_IMETHOD SetIsAppTab(bool aIsAppTab) override; \
  NS_IMETHOD CreateAboutBlankContentViewer(nsIPrincipal *aPrincipal) override; \
  NS_IMETHOD GetCharset(nsACString & aCharset) override; \
  NS_IMETHOD SetCharset(const nsACString & aCharset) override; \
  NS_IMETHOD GatherCharsetMenuTelemetry(void) override; \
  NS_IMETHOD GetForcedCharset(nsACString & aForcedCharset) override; \
  NS_IMETHOD SetForcedCharset(const nsACString & aForcedCharset) override; \
  virtual void SetParentCharset(const nsACString & parentCharset, int32_t parentCharsetSource, nsIPrincipal *parentCharsetPrincipal) override; \
  virtual void GetParentCharset(nsACString & parentCharset, int32_t *parentCharsetSource, nsIPrincipal * *parentCharsetPrincipal) override; \
  using nsIDocShell::GetRecordProfileTimelineMarkers; \
  NS_IMETHOD GetRecordProfileTimelineMarkers(bool *aRecordProfileTimelineMarkers) override; \
  NS_IMETHOD SetRecordProfileTimelineMarkers(bool aRecordProfileTimelineMarkers) override; \
  NS_IMETHOD Now(DOMHighResTimeStamp *_retval) override; \
  NS_IMETHOD PopProfileTimelineMarkers(JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD AddWeakPrivacyTransitionObserver(nsIPrivacyTransitionObserver *obs) override; \
  NS_IMETHOD AddWeakReflowObserver(nsIReflowObserver *obs) override; \
  NS_IMETHOD RemoveWeakReflowObserver(nsIReflowObserver *obs) override; \
  NS_IMETHOD NotifyReflowObservers(bool interruptible, DOMHighResTimeStamp start, DOMHighResTimeStamp end) override; \
  NS_IMETHOD AddWeakScrollObserver(nsIScrollObserver *obs) override; \
  NS_IMETHOD RemoveWeakScrollObserver(nsIScrollObserver *obs) override; \
  NS_IMETHOD NotifyScrollObservers(void) override; \
  using nsIDocShell::GetIsBrowserElement; \
  NS_IMETHOD GetIsBrowserElement(bool *aIsBrowserElement) override; \
  using nsIDocShell::GetIsApp; \
  NS_IMETHOD GetIsApp(bool *aIsApp) override; \
  using nsIDocShell::GetIsBrowserOrApp; \
  NS_IMETHOD GetIsBrowserOrApp(bool *aIsBrowserOrApp) override; \
  using nsIDocShell::GetIsInBrowserElement; \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) override; \
  using nsIDocShell::GetIsInBrowserOrApp; \
  NS_IMETHOD GetIsInBrowserOrApp(bool *aIsInBrowserOrApp) override; \
  NS_IMETHOD SetIsApp(uint32_t ownAppId) override; \
  NS_IMETHOD SetIsBrowserInsideApp(uint32_t containingAppId) override; \
  using nsIDocShell::GetAppId; \
  NS_IMETHOD GetAppId(uint32_t *aAppId) override; \
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) override; \
  NS_IMETHOD GetSameTypeParentIgnoreBrowserAndAppBoundaries(nsIDocShell * *_retval) override; \
  NS_IMETHOD GetAsyncPanZoomEnabled(bool *aAsyncPanZoomEnabled) override; \
  NS_IMETHOD GetSandboxFlags(uint32_t *aSandboxFlags) override; \
  NS_IMETHOD SetSandboxFlags(uint32_t aSandboxFlags) override; \
  NS_IMETHOD GetOnePermittedSandboxedNavigator(nsIDocShell * *aOnePermittedSandboxedNavigator) override; \
  NS_IMETHOD SetOnePermittedSandboxedNavigator(nsIDocShell *aOnePermittedSandboxedNavigator) override; \
  virtual bool IsSandboxedFrom(nsIDocShell *aTargetDocShell) override; \
  NS_IMETHOD GetMixedContentChannel(nsIChannel * *aMixedContentChannel) override; \
  NS_IMETHOD SetMixedContentChannel(nsIChannel *aMixedContentChannel) override; \
  NS_IMETHOD GetAllowMixedContentAndConnectionData(bool *rootHasSecureConnection, bool *allowMixedContent, bool *isRootDocShell) override; \
  NS_IMETHOD_(bool) PluginsAllowedInCurrentDoc(void) override; \
  using nsIDocShell::GetFullscreenAllowed; \
  NS_IMETHOD GetFullscreenAllowed(bool *aFullscreenAllowed) override; \
  NS_IMETHOD SetFullscreenAllowed(bool allowed) override; \
  using nsIDocShell::GetAffectPrivateSessionLifetime; \
  NS_IMETHOD GetAffectPrivateSessionLifetime(bool *aAffectPrivateSessionLifetime) override; \
  NS_IMETHOD SetAffectPrivateSessionLifetime(bool aAffectPrivateSessionLifetime) override; \
  using nsIDocShell::GetMayEnableCharacterEncodingMenu; \
  NS_IMETHOD GetMayEnableCharacterEncodingMenu(bool *aMayEnableCharacterEncodingMenu) override; \
  NS_IMETHOD GetEditor(nsIEditor * *aEditor) override; \
  NS_IMETHOD SetEditor(nsIEditor *aEditor) override; \
  NS_IMETHOD GetEditable(bool *aEditable) override; \
  NS_IMETHOD GetHasEditingSession(bool *aHasEditingSession) override; \
  NS_IMETHOD MakeEditable(bool inWaitForUriLoad) override; \
  NS_IMETHOD GetChildSHEntry(int32_t aChildOffset, nsISHEntry * *_retval) override; \
  NS_IMETHOD AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, int32_t aChildOffset, uint32_t aLoadType, bool aCloneChilden) override; \
  NS_IMETHOD GetUseGlobalHistory(bool *aUseGlobalHistory) override; \
  NS_IMETHOD SetUseGlobalHistory(bool aUseGlobalHistory) override; \
  NS_IMETHOD RemoveFromSessionHistory(void) override; \
  NS_IMETHOD GetCreatedDynamically(bool *aCreatedDynamically) override; \
  NS_IMETHOD SetCreatedDynamically(bool aCreatedDynamically) override; \
  NS_IMETHOD GetCurrentSHEntry(nsISHEntry * *aEntry, bool *_retval) override; \
  NS_IMETHOD IsCommandEnabled(const char * command, bool *_retval) override; \
  NS_IMETHOD DoCommand(const char * command) override; \
  NS_IMETHOD_(bool) IsInvisible(void) override; \
  NS_IMETHOD_(void) SetInvisible(bool aIsInvisibleDochsell) override; \
  virtual nsIScriptGlobalObject * GetScriptGlobalObject(void) override; \
  using nsIDocShell::GetDeviceSizeIsPageSize; \
  NS_IMETHOD GetDeviceSizeIsPageSize(bool *aDeviceSizeIsPageSize) override; \
  NS_IMETHOD SetDeviceSizeIsPageSize(bool aDeviceSizeIsPageSize) override; \
  virtual void SetOpener(nsITabParent *aOpener) override; \
  virtual nsITabParent * GetOpener(void) override; \
  virtual void NotifyJSRunToCompletionStart(const char * aReason, const char16_t * functionName, const char16_t * fileName, uint32_t lineNumber) override; \
  virtual void NotifyJSRunToCompletionStop(void) override; \
  using nsIDocShell::GetHasLoadedNonBlankURI; \
  NS_IMETHOD GetHasLoadedNonBlankURI(bool *aHasLoadedNonBlankURI) override; \
  NS_IMETHOD GetPaymentRequestId(nsAString & aPaymentRequestId) override; \
  NS_IMETHOD SetPaymentRequestId(const nsAString & aPaymentRequestId) override; \
  NS_IMETHOD GetWindowDraggingAllowed(bool *aWindowDraggingAllowed) override; \
  NS_IMETHOD SetWindowDraggingAllowed(bool aWindowDraggingAllowed) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELL(_to) \
  NS_IMETHOD LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, uint32_t aLoadFlags, bool firstParty) override { return _to LoadURI(uri, loadInfo, aLoadFlags, firstParty); } \
  NS_IMETHOD LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo) override { return _to LoadStream(aStream, aURI, aContentType, aContentCharset, aLoadInfo); } \
  NS_IMETHOD InternalLoad(nsIURI *aURI, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsISupports *aOwner, uint32_t aFlags, const char16_t * aWindowTarget, const char * aTypeHint, const nsAString & aFileName, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, uint32_t aLoadFlags, nsISHEntry *aSHEntry, bool firstParty, const nsAString & aSrcdoc, nsIDocShell *aSourceDocShell, nsIURI *aBaseURI, nsIDocShell * *aDocShell, nsIRequest * *aRequest) override { return _to InternalLoad(aURI, aReferrer, aReferrerPolicy, aOwner, aFlags, aWindowTarget, aTypeHint, aFileName, aPostDataStream, aHeadersStream, aLoadFlags, aSHEntry, firstParty, aSrcdoc, aSourceDocShell, aBaseURI, aDocShell, aRequest); } \
  NS_IMETHOD AddState(JS::HandleValue aData, const nsAString & aTitle, const nsAString & aURL, bool aReplace, JSContext* cx) override { return _to AddState(aData, aTitle, aURL, aReplace, cx); } \
  NS_IMETHOD CreateLoadInfo(nsIDocShellLoadInfo * *loadInfo) override { return _to CreateLoadInfo(loadInfo); } \
  NS_IMETHOD PrepareForNewContentModel(void) override { return _to PrepareForNewContentModel(); } \
  NS_IMETHOD SetCurrentURI(nsIURI *aURI) override { return _to SetCurrentURI(aURI); } \
  NS_IMETHOD FirePageHideNotification(bool isUnload) override { return _to FirePageHideNotification(isUnload); } \
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) override { return _to GetPresContext(aPresContext); } \
  NS_IMETHOD_(nsIPresShell *) GetPresShell(void) override { return _to GetPresShell(); } \
  NS_IMETHOD GetEldestPresShell(nsIPresShell **aEldestPresShell) override { return _to GetEldestPresShell(aEldestPresShell); } \
  NS_IMETHOD GetContentViewer(nsIContentViewer * *aContentViewer) override { return _to GetContentViewer(aContentViewer); } \
  NS_IMETHOD GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler) override { return _to GetChromeEventHandler(aChromeEventHandler); } \
  NS_IMETHOD SetChromeEventHandler(nsIDOMEventTarget *aChromeEventHandler) override { return _to SetChromeEventHandler(aChromeEventHandler); } \
  NS_IMETHOD GetAllowPlugins(bool *aAllowPlugins) override { return _to GetAllowPlugins(aAllowPlugins); } \
  NS_IMETHOD SetAllowPlugins(bool aAllowPlugins) override { return _to SetAllowPlugins(aAllowPlugins); } \
  NS_IMETHOD GetAllowJavascript(bool *aAllowJavascript) override { return _to GetAllowJavascript(aAllowJavascript); } \
  NS_IMETHOD SetAllowJavascript(bool aAllowJavascript) override { return _to SetAllowJavascript(aAllowJavascript); } \
  NS_IMETHOD GetAllowMetaRedirects(bool *aAllowMetaRedirects) override { return _to GetAllowMetaRedirects(aAllowMetaRedirects); } \
  NS_IMETHOD SetAllowMetaRedirects(bool aAllowMetaRedirects) override { return _to SetAllowMetaRedirects(aAllowMetaRedirects); } \
  NS_IMETHOD GetAllowSubframes(bool *aAllowSubframes) override { return _to GetAllowSubframes(aAllowSubframes); } \
  NS_IMETHOD SetAllowSubframes(bool aAllowSubframes) override { return _to SetAllowSubframes(aAllowSubframes); } \
  NS_IMETHOD GetAllowImages(bool *aAllowImages) override { return _to GetAllowImages(aAllowImages); } \
  NS_IMETHOD SetAllowImages(bool aAllowImages) override { return _to SetAllowImages(aAllowImages); } \
  using nsIDocShell::GetAllowMedia; \
  NS_IMETHOD GetAllowMedia(bool *aAllowMedia) override { return _to GetAllowMedia(aAllowMedia); } \
  NS_IMETHOD SetAllowMedia(bool aAllowMedia) override { return _to SetAllowMedia(aAllowMedia); } \
  NS_IMETHOD GetAllowDNSPrefetch(bool *aAllowDNSPrefetch) override { return _to GetAllowDNSPrefetch(aAllowDNSPrefetch); } \
  NS_IMETHOD SetAllowDNSPrefetch(bool aAllowDNSPrefetch) override { return _to SetAllowDNSPrefetch(aAllowDNSPrefetch); } \
  NS_IMETHOD GetAllowWindowControl(bool *aAllowWindowControl) override { return _to GetAllowWindowControl(aAllowWindowControl); } \
  NS_IMETHOD SetAllowWindowControl(bool aAllowWindowControl) override { return _to SetAllowWindowControl(aAllowWindowControl); } \
  using nsIDocShell::GetAllowContentRetargeting; \
  NS_IMETHOD GetAllowContentRetargeting(bool *aAllowContentRetargeting) override { return _to GetAllowContentRetargeting(aAllowContentRetargeting); } \
  NS_IMETHOD SetAllowContentRetargeting(bool aAllowContentRetargeting) override { return _to SetAllowContentRetargeting(aAllowContentRetargeting); } \
  using nsIDocShell::GetAllowContentRetargetingOnChildren; \
  NS_IMETHOD GetAllowContentRetargetingOnChildren(bool *aAllowContentRetargetingOnChildren) override { return _to GetAllowContentRetargetingOnChildren(aAllowContentRetargetingOnChildren); } \
  NS_IMETHOD SetAllowContentRetargetingOnChildren(bool aAllowContentRetargetingOnChildren) override { return _to SetAllowContentRetargetingOnChildren(aAllowContentRetargetingOnChildren); } \
  NS_IMETHOD GetDocShellEnumerator(int32_t aItemType, int32_t aDirection, nsISimpleEnumerator * *_retval) override { return _to GetDocShellEnumerator(aItemType, aDirection, _retval); } \
  NS_IMETHOD GetAppType(uint32_t *aAppType) override { return _to GetAppType(aAppType); } \
  NS_IMETHOD SetAppType(uint32_t aAppType) override { return _to SetAppType(aAppType); } \
  NS_IMETHOD GetAllowAuth(bool *aAllowAuth) override { return _to GetAllowAuth(aAllowAuth); } \
  NS_IMETHOD SetAllowAuth(bool aAllowAuth) override { return _to SetAllowAuth(aAllowAuth); } \
  NS_IMETHOD GetZoom(float *aZoom) override { return _to GetZoom(aZoom); } \
  NS_IMETHOD SetZoom(float aZoom) override { return _to SetZoom(aZoom); } \
  NS_IMETHOD GetMarginWidth(int32_t *aMarginWidth) override { return _to GetMarginWidth(aMarginWidth); } \
  NS_IMETHOD SetMarginWidth(int32_t aMarginWidth) override { return _to SetMarginWidth(aMarginWidth); } \
  NS_IMETHOD GetMarginHeight(int32_t *aMarginHeight) override { return _to GetMarginHeight(aMarginHeight); } \
  NS_IMETHOD SetMarginHeight(int32_t aMarginHeight) override { return _to SetMarginHeight(aMarginHeight); } \
  NS_IMETHOD TabToTreeOwner(bool forward, bool *tookFocus) override { return _to TabToTreeOwner(forward, tookFocus); } \
  NS_IMETHOD GetBusyFlags(uint32_t *aBusyFlags) override { return _to GetBusyFlags(aBusyFlags); } \
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) override { return _to GetLoadType(aLoadType); } \
  NS_IMETHOD SetLoadType(uint32_t aLoadType) override { return _to SetLoadType(aLoadType); } \
  NS_IMETHOD GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags) override { return _to GetDefaultLoadFlags(aDefaultLoadFlags); } \
  NS_IMETHOD SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags) override { return _to SetDefaultLoadFlags(aDefaultLoadFlags); } \
  NS_IMETHOD IsBeingDestroyed(bool *_retval) override { return _to IsBeingDestroyed(_retval); } \
  NS_IMETHOD GetIsExecutingOnLoadHandler(bool *aIsExecutingOnLoadHandler) override { return _to GetIsExecutingOnLoadHandler(aIsExecutingOnLoadHandler); } \
  NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState) override { return _to GetLayoutHistoryState(aLayoutHistoryState); } \
  NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState) override { return _to SetLayoutHistoryState(aLayoutHistoryState); } \
  NS_IMETHOD GetShouldSaveLayoutState(bool *aShouldSaveLayoutState) override { return _to GetShouldSaveLayoutState(aShouldSaveLayoutState); } \
  NS_IMETHOD GetSecurityUI(nsISecureBrowserUI * *aSecurityUI) override { return _to GetSecurityUI(aSecurityUI); } \
  NS_IMETHOD SetSecurityUI(nsISecureBrowserUI *aSecurityUI) override { return _to SetSecurityUI(aSecurityUI); } \
  NS_IMETHOD SuspendRefreshURIs(void) override { return _to SuspendRefreshURIs(); } \
  NS_IMETHOD ResumeRefreshURIs(void) override { return _to ResumeRefreshURIs(); } \
  NS_IMETHOD BeginRestore(nsIContentViewer *viewer, bool top) override { return _to BeginRestore(viewer, top); } \
  NS_IMETHOD FinishRestore(void) override { return _to FinishRestore(); } \
  NS_IMETHOD GetRestoringDocument(bool *aRestoringDocument) override { return _to GetRestoringDocument(aRestoringDocument); } \
  NS_IMETHOD GetUseErrorPages(bool *aUseErrorPages) override { return _to GetUseErrorPages(aUseErrorPages); } \
  NS_IMETHOD SetUseErrorPages(bool aUseErrorPages) override { return _to SetUseErrorPages(aUseErrorPages); } \
  NS_IMETHOD DisplayLoadError(nsresult aError, nsIURI *aURI, const char16_t * aURL, nsIChannel *aFailedChannel) override { return _to DisplayLoadError(aError, aURI, aURL, aFailedChannel); } \
  NS_IMETHOD GetFailedChannel(nsIChannel * *aFailedChannel) override { return _to GetFailedChannel(aFailedChannel); } \
  NS_IMETHOD GetPreviousTransIndex(int32_t *aPreviousTransIndex) override { return _to GetPreviousTransIndex(aPreviousTransIndex); } \
  NS_IMETHOD GetLoadedTransIndex(int32_t *aLoadedTransIndex) override { return _to GetLoadedTransIndex(aLoadedTransIndex); } \
  NS_IMETHOD HistoryPurged(int32_t numEntries) override { return _to HistoryPurged(numEntries); } \
  NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, const nsAString & documentURI, bool create, nsIDOMStorage * *_retval) override { return _to GetSessionStorageForPrincipal(principal, documentURI, create, _retval); } \
  NS_IMETHOD AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage *storage) override { return _to AddSessionStorage(principal, storage); } \
  NS_IMETHOD GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel) override { return _to GetCurrentDocumentChannel(aCurrentDocumentChannel); } \
  NS_IMETHOD SetChildOffset(uint32_t offset) override { return _to SetChildOffset(offset); } \
  NS_IMETHOD GetIsInUnload(bool *aIsInUnload) override { return _to GetIsInUnload(aIsInUnload); } \
  NS_IMETHOD GetChannelIsUnsafe(bool *aChannelIsUnsafe) override { return _to GetChannelIsUnsafe(aChannelIsUnsafe); } \
  using nsIDocShell::GetHasMixedActiveContentLoaded; \
  NS_IMETHOD GetHasMixedActiveContentLoaded(bool *aHasMixedActiveContentLoaded) override { return _to GetHasMixedActiveContentLoaded(aHasMixedActiveContentLoaded); } \
  using nsIDocShell::GetHasMixedActiveContentBlocked; \
  NS_IMETHOD GetHasMixedActiveContentBlocked(bool *aHasMixedActiveContentBlocked) override { return _to GetHasMixedActiveContentBlocked(aHasMixedActiveContentBlocked); } \
  using nsIDocShell::GetHasMixedDisplayContentLoaded; \
  NS_IMETHOD GetHasMixedDisplayContentLoaded(bool *aHasMixedDisplayContentLoaded) override { return _to GetHasMixedDisplayContentLoaded(aHasMixedDisplayContentLoaded); } \
  using nsIDocShell::GetHasMixedDisplayContentBlocked; \
  NS_IMETHOD GetHasMixedDisplayContentBlocked(bool *aHasMixedDisplayContentBlocked) override { return _to GetHasMixedDisplayContentBlocked(aHasMixedDisplayContentBlocked); } \
  using nsIDocShell::GetHasTrackingContentBlocked; \
  NS_IMETHOD GetHasTrackingContentBlocked(bool *aHasTrackingContentBlocked) override { return _to GetHasTrackingContentBlocked(aHasTrackingContentBlocked); } \
  using nsIDocShell::GetHasTrackingContentLoaded; \
  NS_IMETHOD GetHasTrackingContentLoaded(bool *aHasTrackingContentLoaded) override { return _to GetHasTrackingContentLoaded(aHasTrackingContentLoaded); } \
  NS_IMETHOD_(void) DetachEditorFromWindow(void) override { return _to DetachEditorFromWindow(); } \
  NS_IMETHOD GetIsOffScreenBrowser(bool *aIsOffScreenBrowser) override { return _to GetIsOffScreenBrowser(aIsOffScreenBrowser); } \
  NS_IMETHOD SetIsOffScreenBrowser(bool aIsOffScreenBrowser) override { return _to SetIsOffScreenBrowser(aIsOffScreenBrowser); } \
  NS_IMETHOD GetPrintPreview(nsIWebBrowserPrint * *aPrintPreview) override { return _to GetPrintPreview(aPrintPreview); } \
  using nsIDocShell::GetCanExecuteScripts; \
  NS_IMETHOD GetCanExecuteScripts(bool *aCanExecuteScripts) override { return _to GetCanExecuteScripts(aCanExecuteScripts); } \
  NS_IMETHOD GetIsActive(bool *aIsActive) override { return _to GetIsActive(aIsActive); } \
  NS_IMETHOD SetIsActive(bool aIsActive) override { return _to SetIsActive(aIsActive); } \
  NS_IMETHOD SetIsPrerendered(bool prerendered) override { return _to SetIsPrerendered(prerendered); } \
  using nsIDocShell::GetIsPrerendered; \
  NS_IMETHOD GetIsPrerendered(bool *aIsPrerendered) override { return _to GetIsPrerendered(aIsPrerendered); } \
  NS_IMETHOD GetHistoryID(uint64_t *aHistoryID) override { return _to GetHistoryID(aHistoryID); } \
  NS_IMETHOD GetIsAppTab(bool *aIsAppTab) override { return _to GetIsAppTab(aIsAppTab); } \
  NS_IMETHOD SetIsAppTab(bool aIsAppTab) override { return _to SetIsAppTab(aIsAppTab); } \
  NS_IMETHOD CreateAboutBlankContentViewer(nsIPrincipal *aPrincipal) override { return _to CreateAboutBlankContentViewer(aPrincipal); } \
  NS_IMETHOD GetCharset(nsACString & aCharset) override { return _to GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsACString & aCharset) override { return _to SetCharset(aCharset); } \
  NS_IMETHOD GatherCharsetMenuTelemetry(void) override { return _to GatherCharsetMenuTelemetry(); } \
  NS_IMETHOD GetForcedCharset(nsACString & aForcedCharset) override { return _to GetForcedCharset(aForcedCharset); } \
  NS_IMETHOD SetForcedCharset(const nsACString & aForcedCharset) override { return _to SetForcedCharset(aForcedCharset); } \
  virtual void SetParentCharset(const nsACString & parentCharset, int32_t parentCharsetSource, nsIPrincipal *parentCharsetPrincipal) override { return _to SetParentCharset(parentCharset, parentCharsetSource, parentCharsetPrincipal); } \
  virtual void GetParentCharset(nsACString & parentCharset, int32_t *parentCharsetSource, nsIPrincipal * *parentCharsetPrincipal) override { return _to GetParentCharset(parentCharset, parentCharsetSource, parentCharsetPrincipal); } \
  using nsIDocShell::GetRecordProfileTimelineMarkers; \
  NS_IMETHOD GetRecordProfileTimelineMarkers(bool *aRecordProfileTimelineMarkers) override { return _to GetRecordProfileTimelineMarkers(aRecordProfileTimelineMarkers); } \
  NS_IMETHOD SetRecordProfileTimelineMarkers(bool aRecordProfileTimelineMarkers) override { return _to SetRecordProfileTimelineMarkers(aRecordProfileTimelineMarkers); } \
  NS_IMETHOD Now(DOMHighResTimeStamp *_retval) override { return _to Now(_retval); } \
  NS_IMETHOD PopProfileTimelineMarkers(JSContext* cx, JS::MutableHandleValue _retval) override { return _to PopProfileTimelineMarkers(cx, _retval); } \
  NS_IMETHOD AddWeakPrivacyTransitionObserver(nsIPrivacyTransitionObserver *obs) override { return _to AddWeakPrivacyTransitionObserver(obs); } \
  NS_IMETHOD AddWeakReflowObserver(nsIReflowObserver *obs) override { return _to AddWeakReflowObserver(obs); } \
  NS_IMETHOD RemoveWeakReflowObserver(nsIReflowObserver *obs) override { return _to RemoveWeakReflowObserver(obs); } \
  NS_IMETHOD NotifyReflowObservers(bool interruptible, DOMHighResTimeStamp start, DOMHighResTimeStamp end) override { return _to NotifyReflowObservers(interruptible, start, end); } \
  NS_IMETHOD AddWeakScrollObserver(nsIScrollObserver *obs) override { return _to AddWeakScrollObserver(obs); } \
  NS_IMETHOD RemoveWeakScrollObserver(nsIScrollObserver *obs) override { return _to RemoveWeakScrollObserver(obs); } \
  NS_IMETHOD NotifyScrollObservers(void) override { return _to NotifyScrollObservers(); } \
  using nsIDocShell::GetIsBrowserElement; \
  NS_IMETHOD GetIsBrowserElement(bool *aIsBrowserElement) override { return _to GetIsBrowserElement(aIsBrowserElement); } \
  using nsIDocShell::GetIsApp; \
  NS_IMETHOD GetIsApp(bool *aIsApp) override { return _to GetIsApp(aIsApp); } \
  using nsIDocShell::GetIsBrowserOrApp; \
  NS_IMETHOD GetIsBrowserOrApp(bool *aIsBrowserOrApp) override { return _to GetIsBrowserOrApp(aIsBrowserOrApp); } \
  using nsIDocShell::GetIsInBrowserElement; \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) override { return _to GetIsInBrowserElement(aIsInBrowserElement); } \
  using nsIDocShell::GetIsInBrowserOrApp; \
  NS_IMETHOD GetIsInBrowserOrApp(bool *aIsInBrowserOrApp) override { return _to GetIsInBrowserOrApp(aIsInBrowserOrApp); } \
  NS_IMETHOD SetIsApp(uint32_t ownAppId) override { return _to SetIsApp(ownAppId); } \
  NS_IMETHOD SetIsBrowserInsideApp(uint32_t containingAppId) override { return _to SetIsBrowserInsideApp(containingAppId); } \
  using nsIDocShell::GetAppId; \
  NS_IMETHOD GetAppId(uint32_t *aAppId) override { return _to GetAppId(aAppId); } \
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) override { return _to GetAppManifestURL(aAppManifestURL); } \
  NS_IMETHOD GetSameTypeParentIgnoreBrowserAndAppBoundaries(nsIDocShell * *_retval) override { return _to GetSameTypeParentIgnoreBrowserAndAppBoundaries(_retval); } \
  NS_IMETHOD GetAsyncPanZoomEnabled(bool *aAsyncPanZoomEnabled) override { return _to GetAsyncPanZoomEnabled(aAsyncPanZoomEnabled); } \
  NS_IMETHOD GetSandboxFlags(uint32_t *aSandboxFlags) override { return _to GetSandboxFlags(aSandboxFlags); } \
  NS_IMETHOD SetSandboxFlags(uint32_t aSandboxFlags) override { return _to SetSandboxFlags(aSandboxFlags); } \
  NS_IMETHOD GetOnePermittedSandboxedNavigator(nsIDocShell * *aOnePermittedSandboxedNavigator) override { return _to GetOnePermittedSandboxedNavigator(aOnePermittedSandboxedNavigator); } \
  NS_IMETHOD SetOnePermittedSandboxedNavigator(nsIDocShell *aOnePermittedSandboxedNavigator) override { return _to SetOnePermittedSandboxedNavigator(aOnePermittedSandboxedNavigator); } \
  virtual bool IsSandboxedFrom(nsIDocShell *aTargetDocShell) override { return _to IsSandboxedFrom(aTargetDocShell); } \
  NS_IMETHOD GetMixedContentChannel(nsIChannel * *aMixedContentChannel) override { return _to GetMixedContentChannel(aMixedContentChannel); } \
  NS_IMETHOD SetMixedContentChannel(nsIChannel *aMixedContentChannel) override { return _to SetMixedContentChannel(aMixedContentChannel); } \
  NS_IMETHOD GetAllowMixedContentAndConnectionData(bool *rootHasSecureConnection, bool *allowMixedContent, bool *isRootDocShell) override { return _to GetAllowMixedContentAndConnectionData(rootHasSecureConnection, allowMixedContent, isRootDocShell); } \
  NS_IMETHOD_(bool) PluginsAllowedInCurrentDoc(void) override { return _to PluginsAllowedInCurrentDoc(); } \
  using nsIDocShell::GetFullscreenAllowed; \
  NS_IMETHOD GetFullscreenAllowed(bool *aFullscreenAllowed) override { return _to GetFullscreenAllowed(aFullscreenAllowed); } \
  NS_IMETHOD SetFullscreenAllowed(bool allowed) override { return _to SetFullscreenAllowed(allowed); } \
  using nsIDocShell::GetAffectPrivateSessionLifetime; \
  NS_IMETHOD GetAffectPrivateSessionLifetime(bool *aAffectPrivateSessionLifetime) override { return _to GetAffectPrivateSessionLifetime(aAffectPrivateSessionLifetime); } \
  NS_IMETHOD SetAffectPrivateSessionLifetime(bool aAffectPrivateSessionLifetime) override { return _to SetAffectPrivateSessionLifetime(aAffectPrivateSessionLifetime); } \
  using nsIDocShell::GetMayEnableCharacterEncodingMenu; \
  NS_IMETHOD GetMayEnableCharacterEncodingMenu(bool *aMayEnableCharacterEncodingMenu) override { return _to GetMayEnableCharacterEncodingMenu(aMayEnableCharacterEncodingMenu); } \
  NS_IMETHOD GetEditor(nsIEditor * *aEditor) override { return _to GetEditor(aEditor); } \
  NS_IMETHOD SetEditor(nsIEditor *aEditor) override { return _to SetEditor(aEditor); } \
  NS_IMETHOD GetEditable(bool *aEditable) override { return _to GetEditable(aEditable); } \
  NS_IMETHOD GetHasEditingSession(bool *aHasEditingSession) override { return _to GetHasEditingSession(aHasEditingSession); } \
  NS_IMETHOD MakeEditable(bool inWaitForUriLoad) override { return _to MakeEditable(inWaitForUriLoad); } \
  NS_IMETHOD GetChildSHEntry(int32_t aChildOffset, nsISHEntry * *_retval) override { return _to GetChildSHEntry(aChildOffset, _retval); } \
  NS_IMETHOD AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, int32_t aChildOffset, uint32_t aLoadType, bool aCloneChilden) override { return _to AddChildSHEntry(aCloneReference, aHistoryEntry, aChildOffset, aLoadType, aCloneChilden); } \
  NS_IMETHOD GetUseGlobalHistory(bool *aUseGlobalHistory) override { return _to GetUseGlobalHistory(aUseGlobalHistory); } \
  NS_IMETHOD SetUseGlobalHistory(bool aUseGlobalHistory) override { return _to SetUseGlobalHistory(aUseGlobalHistory); } \
  NS_IMETHOD RemoveFromSessionHistory(void) override { return _to RemoveFromSessionHistory(); } \
  NS_IMETHOD GetCreatedDynamically(bool *aCreatedDynamically) override { return _to GetCreatedDynamically(aCreatedDynamically); } \
  NS_IMETHOD SetCreatedDynamically(bool aCreatedDynamically) override { return _to SetCreatedDynamically(aCreatedDynamically); } \
  NS_IMETHOD GetCurrentSHEntry(nsISHEntry * *aEntry, bool *_retval) override { return _to GetCurrentSHEntry(aEntry, _retval); } \
  NS_IMETHOD IsCommandEnabled(const char * command, bool *_retval) override { return _to IsCommandEnabled(command, _retval); } \
  NS_IMETHOD DoCommand(const char * command) override { return _to DoCommand(command); } \
  NS_IMETHOD_(bool) IsInvisible(void) override { return _to IsInvisible(); } \
  NS_IMETHOD_(void) SetInvisible(bool aIsInvisibleDochsell) override { return _to SetInvisible(aIsInvisibleDochsell); } \
  virtual nsIScriptGlobalObject * GetScriptGlobalObject(void) override { return _to GetScriptGlobalObject(); } \
  using nsIDocShell::GetDeviceSizeIsPageSize; \
  NS_IMETHOD GetDeviceSizeIsPageSize(bool *aDeviceSizeIsPageSize) override { return _to GetDeviceSizeIsPageSize(aDeviceSizeIsPageSize); } \
  NS_IMETHOD SetDeviceSizeIsPageSize(bool aDeviceSizeIsPageSize) override { return _to SetDeviceSizeIsPageSize(aDeviceSizeIsPageSize); } \
  virtual void SetOpener(nsITabParent *aOpener) override { return _to SetOpener(aOpener); } \
  virtual nsITabParent * GetOpener(void) override { return _to GetOpener(); } \
  virtual void NotifyJSRunToCompletionStart(const char * aReason, const char16_t * functionName, const char16_t * fileName, uint32_t lineNumber) override { return _to NotifyJSRunToCompletionStart(aReason, functionName, fileName, lineNumber); } \
  virtual void NotifyJSRunToCompletionStop(void) override { return _to NotifyJSRunToCompletionStop(); } \
  using nsIDocShell::GetHasLoadedNonBlankURI; \
  NS_IMETHOD GetHasLoadedNonBlankURI(bool *aHasLoadedNonBlankURI) override { return _to GetHasLoadedNonBlankURI(aHasLoadedNonBlankURI); } \
  NS_IMETHOD GetPaymentRequestId(nsAString & aPaymentRequestId) override { return _to GetPaymentRequestId(aPaymentRequestId); } \
  NS_IMETHOD SetPaymentRequestId(const nsAString & aPaymentRequestId) override { return _to SetPaymentRequestId(aPaymentRequestId); } \
  NS_IMETHOD GetWindowDraggingAllowed(bool *aWindowDraggingAllowed) override { return _to GetWindowDraggingAllowed(aWindowDraggingAllowed); } \
  NS_IMETHOD SetWindowDraggingAllowed(bool aWindowDraggingAllowed) override { return _to SetWindowDraggingAllowed(aWindowDraggingAllowed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELL(_to) \
  NS_IMETHOD LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, uint32_t aLoadFlags, bool firstParty) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURI(uri, loadInfo, aLoadFlags, firstParty); } \
  NS_IMETHOD LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadStream(aStream, aURI, aContentType, aContentCharset, aLoadInfo); } \
  NS_IMETHOD InternalLoad(nsIURI *aURI, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsISupports *aOwner, uint32_t aFlags, const char16_t * aWindowTarget, const char * aTypeHint, const nsAString & aFileName, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, uint32_t aLoadFlags, nsISHEntry *aSHEntry, bool firstParty, const nsAString & aSrcdoc, nsIDocShell *aSourceDocShell, nsIURI *aBaseURI, nsIDocShell * *aDocShell, nsIRequest * *aRequest) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InternalLoad(aURI, aReferrer, aReferrerPolicy, aOwner, aFlags, aWindowTarget, aTypeHint, aFileName, aPostDataStream, aHeadersStream, aLoadFlags, aSHEntry, firstParty, aSrcdoc, aSourceDocShell, aBaseURI, aDocShell, aRequest); } \
  NS_IMETHOD AddState(JS::HandleValue aData, const nsAString & aTitle, const nsAString & aURL, bool aReplace, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddState(aData, aTitle, aURL, aReplace, cx); } \
  NS_IMETHOD CreateLoadInfo(nsIDocShellLoadInfo * *loadInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLoadInfo(loadInfo); } \
  NS_IMETHOD PrepareForNewContentModel(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PrepareForNewContentModel(); } \
  NS_IMETHOD SetCurrentURI(nsIURI *aURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentURI(aURI); } \
  NS_IMETHOD FirePageHideNotification(bool isUnload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FirePageHideNotification(isUnload); } \
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresContext(aPresContext); } \
  NS_IMETHOD_(nsIPresShell *) GetPresShell(void) override; \
  NS_IMETHOD GetEldestPresShell(nsIPresShell **aEldestPresShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEldestPresShell(aEldestPresShell); } \
  NS_IMETHOD GetContentViewer(nsIContentViewer * *aContentViewer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentViewer(aContentViewer); } \
  NS_IMETHOD GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeEventHandler(aChromeEventHandler); } \
  NS_IMETHOD SetChromeEventHandler(nsIDOMEventTarget *aChromeEventHandler) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChromeEventHandler(aChromeEventHandler); } \
  NS_IMETHOD GetAllowPlugins(bool *aAllowPlugins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowPlugins(aAllowPlugins); } \
  NS_IMETHOD SetAllowPlugins(bool aAllowPlugins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowPlugins(aAllowPlugins); } \
  NS_IMETHOD GetAllowJavascript(bool *aAllowJavascript) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowJavascript(aAllowJavascript); } \
  NS_IMETHOD SetAllowJavascript(bool aAllowJavascript) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowJavascript(aAllowJavascript); } \
  NS_IMETHOD GetAllowMetaRedirects(bool *aAllowMetaRedirects) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowMetaRedirects(aAllowMetaRedirects); } \
  NS_IMETHOD SetAllowMetaRedirects(bool aAllowMetaRedirects) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowMetaRedirects(aAllowMetaRedirects); } \
  NS_IMETHOD GetAllowSubframes(bool *aAllowSubframes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowSubframes(aAllowSubframes); } \
  NS_IMETHOD SetAllowSubframes(bool aAllowSubframes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowSubframes(aAllowSubframes); } \
  NS_IMETHOD GetAllowImages(bool *aAllowImages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowImages(aAllowImages); } \
  NS_IMETHOD SetAllowImages(bool aAllowImages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowImages(aAllowImages); } \
  NS_IMETHOD GetAllowMedia(bool *aAllowMedia) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowMedia(aAllowMedia); } \
  NS_IMETHOD SetAllowMedia(bool aAllowMedia) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowMedia(aAllowMedia); } \
  NS_IMETHOD GetAllowDNSPrefetch(bool *aAllowDNSPrefetch) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowDNSPrefetch(aAllowDNSPrefetch); } \
  NS_IMETHOD SetAllowDNSPrefetch(bool aAllowDNSPrefetch) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowDNSPrefetch(aAllowDNSPrefetch); } \
  NS_IMETHOD GetAllowWindowControl(bool *aAllowWindowControl) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowWindowControl(aAllowWindowControl); } \
  NS_IMETHOD SetAllowWindowControl(bool aAllowWindowControl) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowWindowControl(aAllowWindowControl); } \
  NS_IMETHOD GetAllowContentRetargeting(bool *aAllowContentRetargeting) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowContentRetargeting(aAllowContentRetargeting); } \
  NS_IMETHOD SetAllowContentRetargeting(bool aAllowContentRetargeting) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowContentRetargeting(aAllowContentRetargeting); } \
  NS_IMETHOD GetAllowContentRetargetingOnChildren(bool *aAllowContentRetargetingOnChildren) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowContentRetargetingOnChildren(aAllowContentRetargetingOnChildren); } \
  NS_IMETHOD SetAllowContentRetargetingOnChildren(bool aAllowContentRetargetingOnChildren) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowContentRetargetingOnChildren(aAllowContentRetargetingOnChildren); } \
  NS_IMETHOD GetDocShellEnumerator(int32_t aItemType, int32_t aDirection, nsISimpleEnumerator * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShellEnumerator(aItemType, aDirection, _retval); } \
  NS_IMETHOD GetAppType(uint32_t *aAppType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppType(aAppType); } \
  NS_IMETHOD SetAppType(uint32_t aAppType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAppType(aAppType); } \
  NS_IMETHOD GetAllowAuth(bool *aAllowAuth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowAuth(aAllowAuth); } \
  NS_IMETHOD SetAllowAuth(bool aAllowAuth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowAuth(aAllowAuth); } \
  NS_IMETHOD GetZoom(float *aZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZoom(aZoom); } \
  NS_IMETHOD SetZoom(float aZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZoom(aZoom); } \
  NS_IMETHOD GetMarginWidth(int32_t *aMarginWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginWidth(aMarginWidth); } \
  NS_IMETHOD SetMarginWidth(int32_t aMarginWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginWidth(aMarginWidth); } \
  NS_IMETHOD GetMarginHeight(int32_t *aMarginHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginHeight(aMarginHeight); } \
  NS_IMETHOD SetMarginHeight(int32_t aMarginHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginHeight(aMarginHeight); } \
  NS_IMETHOD TabToTreeOwner(bool forward, bool *tookFocus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TabToTreeOwner(forward, tookFocus); } \
  NS_IMETHOD GetBusyFlags(uint32_t *aBusyFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBusyFlags(aBusyFlags); } \
  NS_IMETHOD GetLoadType(uint32_t *aLoadType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadType(aLoadType); } \
  NS_IMETHOD SetLoadType(uint32_t aLoadType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadType(aLoadType); } \
  NS_IMETHOD GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultLoadFlags(aDefaultLoadFlags); } \
  NS_IMETHOD SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultLoadFlags(aDefaultLoadFlags); } \
  NS_IMETHOD IsBeingDestroyed(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsBeingDestroyed(_retval); } \
  NS_IMETHOD GetIsExecutingOnLoadHandler(bool *aIsExecutingOnLoadHandler) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExecutingOnLoadHandler(aIsExecutingOnLoadHandler); } \
  NS_IMETHOD GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayoutHistoryState(aLayoutHistoryState); } \
  NS_IMETHOD SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLayoutHistoryState(aLayoutHistoryState); } \
  NS_IMETHOD GetShouldSaveLayoutState(bool *aShouldSaveLayoutState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShouldSaveLayoutState(aShouldSaveLayoutState); } \
  NS_IMETHOD GetSecurityUI(nsISecureBrowserUI * *aSecurityUI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityUI(aSecurityUI); } \
  NS_IMETHOD SetSecurityUI(nsISecureBrowserUI *aSecurityUI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityUI(aSecurityUI); } \
  NS_IMETHOD SuspendRefreshURIs(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SuspendRefreshURIs(); } \
  NS_IMETHOD ResumeRefreshURIs(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeRefreshURIs(); } \
  NS_IMETHOD BeginRestore(nsIContentViewer *viewer, bool top) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginRestore(viewer, top); } \
  NS_IMETHOD FinishRestore(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FinishRestore(); } \
  NS_IMETHOD GetRestoringDocument(bool *aRestoringDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRestoringDocument(aRestoringDocument); } \
  NS_IMETHOD GetUseErrorPages(bool *aUseErrorPages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseErrorPages(aUseErrorPages); } \
  NS_IMETHOD SetUseErrorPages(bool aUseErrorPages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUseErrorPages(aUseErrorPages); } \
  NS_IMETHOD DisplayLoadError(nsresult aError, nsIURI *aURI, const char16_t * aURL, nsIChannel *aFailedChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DisplayLoadError(aError, aURI, aURL, aFailedChannel); } \
  NS_IMETHOD GetFailedChannel(nsIChannel * *aFailedChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFailedChannel(aFailedChannel); } \
  NS_IMETHOD GetPreviousTransIndex(int32_t *aPreviousTransIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousTransIndex(aPreviousTransIndex); } \
  NS_IMETHOD GetLoadedTransIndex(int32_t *aLoadedTransIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadedTransIndex(aLoadedTransIndex); } \
  NS_IMETHOD HistoryPurged(int32_t numEntries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HistoryPurged(numEntries); } \
  NS_IMETHOD GetSessionStorageForPrincipal(nsIPrincipal *principal, const nsAString & documentURI, bool create, nsIDOMStorage * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorageForPrincipal(principal, documentURI, create, _retval); } \
  NS_IMETHOD AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage *storage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSessionStorage(principal, storage); } \
  NS_IMETHOD GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentDocumentChannel(aCurrentDocumentChannel); } \
  NS_IMETHOD SetChildOffset(uint32_t offset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChildOffset(offset); } \
  NS_IMETHOD GetIsInUnload(bool *aIsInUnload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInUnload(aIsInUnload); } \
  NS_IMETHOD GetChannelIsUnsafe(bool *aChannelIsUnsafe) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelIsUnsafe(aChannelIsUnsafe); } \
  NS_IMETHOD GetHasMixedActiveContentLoaded(bool *aHasMixedActiveContentLoaded) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasMixedActiveContentLoaded(aHasMixedActiveContentLoaded); } \
  NS_IMETHOD GetHasMixedActiveContentBlocked(bool *aHasMixedActiveContentBlocked) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasMixedActiveContentBlocked(aHasMixedActiveContentBlocked); } \
  NS_IMETHOD GetHasMixedDisplayContentLoaded(bool *aHasMixedDisplayContentLoaded) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasMixedDisplayContentLoaded(aHasMixedDisplayContentLoaded); } \
  NS_IMETHOD GetHasMixedDisplayContentBlocked(bool *aHasMixedDisplayContentBlocked) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasMixedDisplayContentBlocked(aHasMixedDisplayContentBlocked); } \
  NS_IMETHOD GetHasTrackingContentBlocked(bool *aHasTrackingContentBlocked) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasTrackingContentBlocked(aHasTrackingContentBlocked); } \
  NS_IMETHOD GetHasTrackingContentLoaded(bool *aHasTrackingContentLoaded) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasTrackingContentLoaded(aHasTrackingContentLoaded); } \
  NS_IMETHOD_(void) DetachEditorFromWindow(void) override; \
  NS_IMETHOD GetIsOffScreenBrowser(bool *aIsOffScreenBrowser) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsOffScreenBrowser(aIsOffScreenBrowser); } \
  NS_IMETHOD SetIsOffScreenBrowser(bool aIsOffScreenBrowser) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsOffScreenBrowser(aIsOffScreenBrowser); } \
  NS_IMETHOD GetPrintPreview(nsIWebBrowserPrint * *aPrintPreview) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintPreview(aPrintPreview); } \
  NS_IMETHOD GetCanExecuteScripts(bool *aCanExecuteScripts) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanExecuteScripts(aCanExecuteScripts); } \
  NS_IMETHOD GetIsActive(bool *aIsActive) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsActive(aIsActive); } \
  NS_IMETHOD SetIsActive(bool aIsActive) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsActive(aIsActive); } \
  NS_IMETHOD SetIsPrerendered(bool prerendered) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsPrerendered(prerendered); } \
  NS_IMETHOD GetIsPrerendered(bool *aIsPrerendered) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsPrerendered(aIsPrerendered); } \
  NS_IMETHOD GetHistoryID(uint64_t *aHistoryID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistoryID(aHistoryID); } \
  NS_IMETHOD GetIsAppTab(bool *aIsAppTab) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsAppTab(aIsAppTab); } \
  NS_IMETHOD SetIsAppTab(bool aIsAppTab) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsAppTab(aIsAppTab); } \
  NS_IMETHOD CreateAboutBlankContentViewer(nsIPrincipal *aPrincipal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAboutBlankContentViewer(aPrincipal); } \
  NS_IMETHOD GetCharset(nsACString & aCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_IMETHOD SetCharset(const nsACString & aCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCharset(aCharset); } \
  NS_IMETHOD GatherCharsetMenuTelemetry(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GatherCharsetMenuTelemetry(); } \
  NS_IMETHOD GetForcedCharset(nsACString & aForcedCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForcedCharset(aForcedCharset); } \
  NS_IMETHOD SetForcedCharset(const nsACString & aForcedCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForcedCharset(aForcedCharset); } \
  virtual void SetParentCharset(const nsACString & parentCharset, int32_t parentCharsetSource, nsIPrincipal *parentCharsetPrincipal) override; \
  virtual void GetParentCharset(nsACString & parentCharset, int32_t *parentCharsetSource, nsIPrincipal * *parentCharsetPrincipal) override; \
  NS_IMETHOD GetRecordProfileTimelineMarkers(bool *aRecordProfileTimelineMarkers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRecordProfileTimelineMarkers(aRecordProfileTimelineMarkers); } \
  NS_IMETHOD SetRecordProfileTimelineMarkers(bool aRecordProfileTimelineMarkers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRecordProfileTimelineMarkers(aRecordProfileTimelineMarkers); } \
  NS_IMETHOD Now(DOMHighResTimeStamp *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Now(_retval); } \
  NS_IMETHOD PopProfileTimelineMarkers(JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PopProfileTimelineMarkers(cx, _retval); } \
  NS_IMETHOD AddWeakPrivacyTransitionObserver(nsIPrivacyTransitionObserver *obs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWeakPrivacyTransitionObserver(obs); } \
  NS_IMETHOD AddWeakReflowObserver(nsIReflowObserver *obs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWeakReflowObserver(obs); } \
  NS_IMETHOD RemoveWeakReflowObserver(nsIReflowObserver *obs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWeakReflowObserver(obs); } \
  NS_IMETHOD NotifyReflowObservers(bool interruptible, DOMHighResTimeStamp start, DOMHighResTimeStamp end) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyReflowObservers(interruptible, start, end); } \
  NS_IMETHOD AddWeakScrollObserver(nsIScrollObserver *obs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWeakScrollObserver(obs); } \
  NS_IMETHOD RemoveWeakScrollObserver(nsIScrollObserver *obs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWeakScrollObserver(obs); } \
  NS_IMETHOD NotifyScrollObservers(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyScrollObservers(); } \
  NS_IMETHOD GetIsBrowserElement(bool *aIsBrowserElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsBrowserElement(aIsBrowserElement); } \
  NS_IMETHOD GetIsApp(bool *aIsApp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsApp(aIsApp); } \
  NS_IMETHOD GetIsBrowserOrApp(bool *aIsBrowserOrApp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsBrowserOrApp(aIsBrowserOrApp); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetIsInBrowserOrApp(bool *aIsInBrowserOrApp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInBrowserOrApp(aIsInBrowserOrApp); } \
  NS_IMETHOD SetIsApp(uint32_t ownAppId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsApp(ownAppId); } \
  NS_IMETHOD SetIsBrowserInsideApp(uint32_t containingAppId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsBrowserInsideApp(containingAppId); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppId(aAppId); } \
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppManifestURL(aAppManifestURL); } \
  NS_IMETHOD GetSameTypeParentIgnoreBrowserAndAppBoundaries(nsIDocShell * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSameTypeParentIgnoreBrowserAndAppBoundaries(_retval); } \
  NS_IMETHOD GetAsyncPanZoomEnabled(bool *aAsyncPanZoomEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncPanZoomEnabled(aAsyncPanZoomEnabled); } \
  NS_IMETHOD GetSandboxFlags(uint32_t *aSandboxFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSandboxFlags(aSandboxFlags); } \
  NS_IMETHOD SetSandboxFlags(uint32_t aSandboxFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSandboxFlags(aSandboxFlags); } \
  NS_IMETHOD GetOnePermittedSandboxedNavigator(nsIDocShell * *aOnePermittedSandboxedNavigator) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnePermittedSandboxedNavigator(aOnePermittedSandboxedNavigator); } \
  NS_IMETHOD SetOnePermittedSandboxedNavigator(nsIDocShell *aOnePermittedSandboxedNavigator) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnePermittedSandboxedNavigator(aOnePermittedSandboxedNavigator); } \
  virtual bool IsSandboxedFrom(nsIDocShell *aTargetDocShell) override; \
  NS_IMETHOD GetMixedContentChannel(nsIChannel * *aMixedContentChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMixedContentChannel(aMixedContentChannel); } \
  NS_IMETHOD SetMixedContentChannel(nsIChannel *aMixedContentChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMixedContentChannel(aMixedContentChannel); } \
  NS_IMETHOD GetAllowMixedContentAndConnectionData(bool *rootHasSecureConnection, bool *allowMixedContent, bool *isRootDocShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowMixedContentAndConnectionData(rootHasSecureConnection, allowMixedContent, isRootDocShell); } \
  NS_IMETHOD_(bool) PluginsAllowedInCurrentDoc(void) override; \
  NS_IMETHOD GetFullscreenAllowed(bool *aFullscreenAllowed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullscreenAllowed(aFullscreenAllowed); } \
  NS_IMETHOD SetFullscreenAllowed(bool allowed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFullscreenAllowed(allowed); } \
  NS_IMETHOD GetAffectPrivateSessionLifetime(bool *aAffectPrivateSessionLifetime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAffectPrivateSessionLifetime(aAffectPrivateSessionLifetime); } \
  NS_IMETHOD SetAffectPrivateSessionLifetime(bool aAffectPrivateSessionLifetime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAffectPrivateSessionLifetime(aAffectPrivateSessionLifetime); } \
  NS_IMETHOD GetMayEnableCharacterEncodingMenu(bool *aMayEnableCharacterEncodingMenu) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMayEnableCharacterEncodingMenu(aMayEnableCharacterEncodingMenu); } \
  NS_IMETHOD GetEditor(nsIEditor * *aEditor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditor(aEditor); } \
  NS_IMETHOD SetEditor(nsIEditor *aEditor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEditor(aEditor); } \
  NS_IMETHOD GetEditable(bool *aEditable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEditable(aEditable); } \
  NS_IMETHOD GetHasEditingSession(bool *aHasEditingSession) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasEditingSession(aHasEditingSession); } \
  NS_IMETHOD MakeEditable(bool inWaitForUriLoad) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeEditable(inWaitForUriLoad); } \
  NS_IMETHOD GetChildSHEntry(int32_t aChildOffset, nsISHEntry * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildSHEntry(aChildOffset, _retval); } \
  NS_IMETHOD AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, int32_t aChildOffset, uint32_t aLoadType, bool aCloneChilden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddChildSHEntry(aCloneReference, aHistoryEntry, aChildOffset, aLoadType, aCloneChilden); } \
  NS_IMETHOD GetUseGlobalHistory(bool *aUseGlobalHistory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseGlobalHistory(aUseGlobalHistory); } \
  NS_IMETHOD SetUseGlobalHistory(bool aUseGlobalHistory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUseGlobalHistory(aUseGlobalHistory); } \
  NS_IMETHOD RemoveFromSessionHistory(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFromSessionHistory(); } \
  NS_IMETHOD GetCreatedDynamically(bool *aCreatedDynamically) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCreatedDynamically(aCreatedDynamically); } \
  NS_IMETHOD SetCreatedDynamically(bool aCreatedDynamically) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCreatedDynamically(aCreatedDynamically); } \
  NS_IMETHOD GetCurrentSHEntry(nsISHEntry * *aEntry, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentSHEntry(aEntry, _retval); } \
  NS_IMETHOD IsCommandEnabled(const char * command, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandEnabled(command, _retval); } \
  NS_IMETHOD DoCommand(const char * command) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(command); } \
  NS_IMETHOD_(bool) IsInvisible(void) override; \
  NS_IMETHOD_(void) SetInvisible(bool aIsInvisibleDochsell) override; \
  virtual nsIScriptGlobalObject * GetScriptGlobalObject(void) override; \
  NS_IMETHOD GetDeviceSizeIsPageSize(bool *aDeviceSizeIsPageSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeviceSizeIsPageSize(aDeviceSizeIsPageSize); } \
  NS_IMETHOD SetDeviceSizeIsPageSize(bool aDeviceSizeIsPageSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDeviceSizeIsPageSize(aDeviceSizeIsPageSize); } \
  virtual void SetOpener(nsITabParent *aOpener) override; \
  virtual nsITabParent * GetOpener(void) override; \
  virtual void NotifyJSRunToCompletionStart(const char * aReason, const char16_t * functionName, const char16_t * fileName, uint32_t lineNumber) override; \
  virtual void NotifyJSRunToCompletionStop(void) override; \
  NS_IMETHOD GetHasLoadedNonBlankURI(bool *aHasLoadedNonBlankURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasLoadedNonBlankURI(aHasLoadedNonBlankURI); } \
  NS_IMETHOD GetPaymentRequestId(nsAString & aPaymentRequestId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaymentRequestId(aPaymentRequestId); } \
  NS_IMETHOD SetPaymentRequestId(const nsAString & aPaymentRequestId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaymentRequestId(aPaymentRequestId); } \
  NS_IMETHOD GetWindowDraggingAllowed(bool *aWindowDraggingAllowed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowDraggingAllowed(aWindowDraggingAllowed); } \
  NS_IMETHOD SetWindowDraggingAllowed(bool aWindowDraggingAllowed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindowDraggingAllowed(aWindowDraggingAllowed); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShell : public nsIDocShell
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELL

  nsDocShell();

private:
  ~nsDocShell();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDocShell, nsIDocShell)

nsDocShell::nsDocShell()
{
  /* member initializers and constructor code */
}

nsDocShell::~nsDocShell()
{
  /* destructor code */
}

/* [noscript] void loadURI (in nsIURI uri, in nsIDocShellLoadInfo loadInfo, in unsigned long aLoadFlags, in boolean firstParty); */
NS_IMETHODIMP nsDocShell::LoadURI(nsIURI *uri, nsIDocShellLoadInfo *loadInfo, uint32_t aLoadFlags, bool firstParty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void loadStream (in nsIInputStream aStream, in nsIURI aURI, in ACString aContentType, in ACString aContentCharset, in nsIDocShellLoadInfo aLoadInfo); */
NS_IMETHODIMP nsDocShell::LoadStream(nsIInputStream *aStream, nsIURI *aURI, const nsACString & aContentType, const nsACString & aContentCharset, nsIDocShellLoadInfo *aLoadInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void internalLoad (in nsIURI aURI, in nsIURI aReferrer, in unsigned long aReferrerPolicy, in nsISupports aOwner, in uint32_t aFlags, in wstring aWindowTarget, in string aTypeHint, in AString aFileName, in nsIInputStream aPostDataStream, in nsIInputStream aHeadersStream, in unsigned long aLoadFlags, in nsISHEntry aSHEntry, in boolean firstParty, in AString aSrcdoc, in nsIDocShell aSourceDocShell, in nsIURI aBaseURI, out nsIDocShell aDocShell, out nsIRequest aRequest); */
NS_IMETHODIMP nsDocShell::InternalLoad(nsIURI *aURI, nsIURI *aReferrer, uint32_t aReferrerPolicy, nsISupports *aOwner, uint32_t aFlags, const char16_t * aWindowTarget, const char * aTypeHint, const nsAString & aFileName, nsIInputStream *aPostDataStream, nsIInputStream *aHeadersStream, uint32_t aLoadFlags, nsISHEntry *aSHEntry, bool firstParty, const nsAString & aSrcdoc, nsIDocShell *aSourceDocShell, nsIURI *aBaseURI, nsIDocShell * *aDocShell, nsIRequest * *aRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void addState (in jsval aData, in DOMString aTitle, in DOMString aURL, in boolean aReplace); */
NS_IMETHODIMP nsDocShell::AddState(JS::HandleValue aData, const nsAString & aTitle, const nsAString & aURL, bool aReplace, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createLoadInfo (out nsIDocShellLoadInfo loadInfo); */
NS_IMETHODIMP nsDocShell::CreateLoadInfo(nsIDocShellLoadInfo * *loadInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void prepareForNewContentModel (); */
NS_IMETHODIMP nsDocShell::PrepareForNewContentModel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCurrentURI (in nsIURI aURI); */
NS_IMETHODIMP nsDocShell::SetCurrentURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void firePageHideNotification (in boolean isUnload); */
NS_IMETHODIMP nsDocShell::FirePageHideNotification(bool isUnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsPresContext presContext; */
NS_IMETHODIMP nsDocShell::GetPresContext(nsPresContext **aPresContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] nsIPresShell GetPresShell (); */
NS_IMETHODIMP_(nsIPresShell *) nsDocShell::GetPresShell()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIPresShell eldestPresShell; */
NS_IMETHODIMP nsDocShell::GetEldestPresShell(nsIPresShell **aEldestPresShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIContentViewer contentViewer; */
NS_IMETHODIMP nsDocShell::GetContentViewer(nsIContentViewer * *aContentViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventTarget chromeEventHandler; */
NS_IMETHODIMP nsDocShell::GetChromeEventHandler(nsIDOMEventTarget * *aChromeEventHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetChromeEventHandler(nsIDOMEventTarget *aChromeEventHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowPlugins; */
NS_IMETHODIMP nsDocShell::GetAllowPlugins(bool *aAllowPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowPlugins(bool aAllowPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowJavascript; */
NS_IMETHODIMP nsDocShell::GetAllowJavascript(bool *aAllowJavascript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowJavascript(bool aAllowJavascript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowMetaRedirects; */
NS_IMETHODIMP nsDocShell::GetAllowMetaRedirects(bool *aAllowMetaRedirects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowMetaRedirects(bool aAllowMetaRedirects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowSubframes; */
NS_IMETHODIMP nsDocShell::GetAllowSubframes(bool *aAllowSubframes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowSubframes(bool aAllowSubframes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowImages; */
NS_IMETHODIMP nsDocShell::GetAllowImages(bool *aAllowImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowImages(bool aAllowImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] attribute boolean allowMedia; */
NS_IMETHODIMP nsDocShell::GetAllowMedia(bool *aAllowMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowMedia(bool aAllowMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowDNSPrefetch; */
NS_IMETHODIMP nsDocShell::GetAllowDNSPrefetch(bool *aAllowDNSPrefetch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowDNSPrefetch(bool aAllowDNSPrefetch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowWindowControl; */
NS_IMETHODIMP nsDocShell::GetAllowWindowControl(bool *aAllowWindowControl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowWindowControl(bool aAllowWindowControl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] attribute boolean allowContentRetargeting; */
NS_IMETHODIMP nsDocShell::GetAllowContentRetargeting(bool *aAllowContentRetargeting)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowContentRetargeting(bool aAllowContentRetargeting)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] attribute boolean allowContentRetargetingOnChildren; */
NS_IMETHODIMP nsDocShell::GetAllowContentRetargetingOnChildren(bool *aAllowContentRetargetingOnChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowContentRetargetingOnChildren(bool aAllowContentRetargetingOnChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getDocShellEnumerator (in long aItemType, in long aDirection); */
NS_IMETHODIMP nsDocShell::GetDocShellEnumerator(int32_t aItemType, int32_t aDirection, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long appType; */
NS_IMETHODIMP nsDocShell::GetAppType(uint32_t *aAppType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAppType(uint32_t aAppType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowAuth; */
NS_IMETHODIMP nsDocShell::GetAllowAuth(bool *aAllowAuth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAllowAuth(bool aAllowAuth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float zoom; */
NS_IMETHODIMP nsDocShell::GetZoom(float *aZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetZoom(float aZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long marginWidth; */
NS_IMETHODIMP nsDocShell::GetMarginWidth(int32_t *aMarginWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetMarginWidth(int32_t aMarginWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long marginHeight; */
NS_IMETHODIMP nsDocShell::GetMarginHeight(int32_t *aMarginHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetMarginHeight(int32_t aMarginHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void tabToTreeOwner (in boolean forward, out boolean tookFocus); */
NS_IMETHODIMP nsDocShell::TabToTreeOwner(bool forward, bool *tookFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long busyFlags; */
NS_IMETHODIMP nsDocShell::GetBusyFlags(uint32_t *aBusyFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long loadType; */
NS_IMETHODIMP nsDocShell::GetLoadType(uint32_t *aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetLoadType(uint32_t aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsLoadFlags defaultLoadFlags; */
NS_IMETHODIMP nsDocShell::GetDefaultLoadFlags(nsLoadFlags *aDefaultLoadFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetDefaultLoadFlags(nsLoadFlags aDefaultLoadFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isBeingDestroyed (); */
NS_IMETHODIMP nsDocShell::IsBeingDestroyed(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isExecutingOnLoadHandler; */
NS_IMETHODIMP nsDocShell::GetIsExecutingOnLoadHandler(bool *aIsExecutingOnLoadHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsILayoutHistoryState layoutHistoryState; */
NS_IMETHODIMP nsDocShell::GetLayoutHistoryState(nsILayoutHistoryState * *aLayoutHistoryState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetLayoutHistoryState(nsILayoutHistoryState *aLayoutHistoryState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shouldSaveLayoutState; */
NS_IMETHODIMP nsDocShell::GetShouldSaveLayoutState(bool *aShouldSaveLayoutState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISecureBrowserUI securityUI; */
NS_IMETHODIMP nsDocShell::GetSecurityUI(nsISecureBrowserUI * *aSecurityUI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetSecurityUI(nsISecureBrowserUI *aSecurityUI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspendRefreshURIs (); */
NS_IMETHODIMP nsDocShell::SuspendRefreshURIs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeRefreshURIs (); */
NS_IMETHODIMP nsDocShell::ResumeRefreshURIs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginRestore (in nsIContentViewer viewer, in boolean top); */
NS_IMETHODIMP nsDocShell::BeginRestore(nsIContentViewer *viewer, bool top)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finishRestore (); */
NS_IMETHODIMP nsDocShell::FinishRestore()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean restoringDocument; */
NS_IMETHODIMP nsDocShell::GetRestoringDocument(bool *aRestoringDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean useErrorPages; */
NS_IMETHODIMP nsDocShell::GetUseErrorPages(bool *aUseErrorPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetUseErrorPages(bool aUseErrorPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void displayLoadError (in nsresult aError, in nsIURI aURI, in wstring aURL, [optional] in nsIChannel aFailedChannel); */
NS_IMETHODIMP nsDocShell::DisplayLoadError(nsresult aError, nsIURI *aURI, const char16_t * aURL, nsIChannel *aFailedChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIChannel failedChannel; */
NS_IMETHODIMP nsDocShell::GetFailedChannel(nsIChannel * *aFailedChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long previousTransIndex; */
NS_IMETHODIMP nsDocShell::GetPreviousTransIndex(int32_t *aPreviousTransIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long loadedTransIndex; */
NS_IMETHODIMP nsDocShell::GetLoadedTransIndex(int32_t *aLoadedTransIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void historyPurged (in long numEntries); */
NS_IMETHODIMP nsDocShell::HistoryPurged(int32_t numEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMStorage getSessionStorageForPrincipal (in nsIPrincipal principal, in DOMString documentURI, in boolean create); */
NS_IMETHODIMP nsDocShell::GetSessionStorageForPrincipal(nsIPrincipal *principal, const nsAString & documentURI, bool create, nsIDOMStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSessionStorage (in nsIPrincipal principal, in nsIDOMStorage storage); */
NS_IMETHODIMP nsDocShell::AddSessionStorage(nsIPrincipal *principal, nsIDOMStorage *storage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIChannel currentDocumentChannel; */
NS_IMETHODIMP nsDocShell::GetCurrentDocumentChannel(nsIChannel * *aCurrentDocumentChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setChildOffset (in unsigned long offset); */
NS_IMETHODIMP nsDocShell::SetChildOffset(uint32_t offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isInUnload; */
NS_IMETHODIMP nsDocShell::GetIsInUnload(bool *aIsInUnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean channelIsUnsafe; */
NS_IMETHODIMP nsDocShell::GetChannelIsUnsafe(bool *aChannelIsUnsafe)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean hasMixedActiveContentLoaded; */
NS_IMETHODIMP nsDocShell::GetHasMixedActiveContentLoaded(bool *aHasMixedActiveContentLoaded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean hasMixedActiveContentBlocked; */
NS_IMETHODIMP nsDocShell::GetHasMixedActiveContentBlocked(bool *aHasMixedActiveContentBlocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean hasMixedDisplayContentLoaded; */
NS_IMETHODIMP nsDocShell::GetHasMixedDisplayContentLoaded(bool *aHasMixedDisplayContentLoaded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean hasMixedDisplayContentBlocked; */
NS_IMETHODIMP nsDocShell::GetHasMixedDisplayContentBlocked(bool *aHasMixedDisplayContentBlocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean hasTrackingContentBlocked; */
NS_IMETHODIMP nsDocShell::GetHasTrackingContentBlocked(bool *aHasTrackingContentBlocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean hasTrackingContentLoaded; */
NS_IMETHODIMP nsDocShell::GetHasTrackingContentLoaded(bool *aHasTrackingContentLoaded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void DetachEditorFromWindow (); */
NS_IMETHODIMP_(void) nsDocShell::DetachEditorFromWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isOffScreenBrowser; */
NS_IMETHODIMP nsDocShell::GetIsOffScreenBrowser(bool *aIsOffScreenBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetIsOffScreenBrowser(bool aIsOffScreenBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIWebBrowserPrint printPreview; */
NS_IMETHODIMP nsDocShell::GetPrintPreview(nsIWebBrowserPrint * *aPrintPreview)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean canExecuteScripts; */
NS_IMETHODIMP nsDocShell::GetCanExecuteScripts(bool *aCanExecuteScripts)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isActive; */
NS_IMETHODIMP nsDocShell::GetIsActive(bool *aIsActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetIsActive(bool aIsActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetIsPrerendered (in boolean prerendered); */
NS_IMETHODIMP nsDocShell::SetIsPrerendered(bool prerendered)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isPrerendered; */
NS_IMETHODIMP nsDocShell::GetIsPrerendered(bool *aIsPrerendered)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long historyID; */
NS_IMETHODIMP nsDocShell::GetHistoryID(uint64_t *aHistoryID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isAppTab; */
NS_IMETHODIMP nsDocShell::GetIsAppTab(bool *aIsAppTab)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetIsAppTab(bool aIsAppTab)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createAboutBlankContentViewer (in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsDocShell::CreateAboutBlankContentViewer(nsIPrincipal *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString charset; */
NS_IMETHODIMP nsDocShell::GetCharset(nsACString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetCharset(const nsACString & aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void gatherCharsetMenuTelemetry (); */
NS_IMETHODIMP nsDocShell::GatherCharsetMenuTelemetry()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString forcedCharset; */
NS_IMETHODIMP nsDocShell::GetForcedCharset(nsACString & aForcedCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetForcedCharset(const nsACString & aForcedCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] void setParentCharset (in ACString parentCharset, in int32_t parentCharsetSource, in nsIPrincipal parentCharsetPrincipal); */
void nsDocShell::SetParentCharset(const nsACString & parentCharset, int32_t parentCharsetSource, nsIPrincipal *parentCharsetPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] void getParentCharset (out ACString parentCharset, out int32_t parentCharsetSource, out nsIPrincipal parentCharsetPrincipal); */
void nsDocShell::GetParentCharset(nsACString & parentCharset, int32_t *parentCharsetSource, nsIPrincipal * *parentCharsetPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] attribute boolean recordProfileTimelineMarkers; */
NS_IMETHODIMP nsDocShell::GetRecordProfileTimelineMarkers(bool *aRecordProfileTimelineMarkers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetRecordProfileTimelineMarkers(bool aRecordProfileTimelineMarkers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMHighResTimeStamp now (); */
NS_IMETHODIMP nsDocShell::Now(DOMHighResTimeStamp *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval popProfileTimelineMarkers (); */
NS_IMETHODIMP nsDocShell::PopProfileTimelineMarkers(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addWeakPrivacyTransitionObserver (in nsIPrivacyTransitionObserver obs); */
NS_IMETHODIMP nsDocShell::AddWeakPrivacyTransitionObserver(nsIPrivacyTransitionObserver *obs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addWeakReflowObserver (in nsIReflowObserver obs); */
NS_IMETHODIMP nsDocShell::AddWeakReflowObserver(nsIReflowObserver *obs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWeakReflowObserver (in nsIReflowObserver obs); */
NS_IMETHODIMP nsDocShell::RemoveWeakReflowObserver(nsIReflowObserver *obs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void notifyReflowObservers (in bool interruptible, in DOMHighResTimeStamp start, in DOMHighResTimeStamp end); */
NS_IMETHODIMP nsDocShell::NotifyReflowObservers(bool interruptible, DOMHighResTimeStamp start, DOMHighResTimeStamp end)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void addWeakScrollObserver (in nsIScrollObserver obs); */
NS_IMETHODIMP nsDocShell::AddWeakScrollObserver(nsIScrollObserver *obs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void removeWeakScrollObserver (in nsIScrollObserver obs); */
NS_IMETHODIMP nsDocShell::RemoveWeakScrollObserver(nsIScrollObserver *obs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void notifyScrollObservers (); */
NS_IMETHODIMP nsDocShell::NotifyScrollObservers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isBrowserElement; */
NS_IMETHODIMP nsDocShell::GetIsBrowserElement(bool *aIsBrowserElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isApp; */
NS_IMETHODIMP nsDocShell::GetIsApp(bool *aIsApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isBrowserOrApp; */
NS_IMETHODIMP nsDocShell::GetIsBrowserOrApp(bool *aIsBrowserOrApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isInBrowserElement; */
NS_IMETHODIMP nsDocShell::GetIsInBrowserElement(bool *aIsInBrowserElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isInBrowserOrApp; */
NS_IMETHODIMP nsDocShell::GetIsInBrowserOrApp(bool *aIsInBrowserOrApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIsApp (in unsigned long ownAppId); */
NS_IMETHODIMP nsDocShell::SetIsApp(uint32_t ownAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIsBrowserInsideApp (in unsigned long containingAppId); */
NS_IMETHODIMP nsDocShell::SetIsBrowserInsideApp(uint32_t containingAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute unsigned long appId; */
NS_IMETHODIMP nsDocShell::GetAppId(uint32_t *aAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString appManifestURL; */
NS_IMETHODIMP nsDocShell::GetAppManifestURL(nsAString & aAppManifestURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShell getSameTypeParentIgnoreBrowserAndAppBoundaries (); */
NS_IMETHODIMP nsDocShell::GetSameTypeParentIgnoreBrowserAndAppBoundaries(nsIDocShell * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool asyncPanZoomEnabled; */
NS_IMETHODIMP nsDocShell::GetAsyncPanZoomEnabled(bool *aAsyncPanZoomEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long sandboxFlags; */
NS_IMETHODIMP nsDocShell::GetSandboxFlags(uint32_t *aSandboxFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetSandboxFlags(uint32_t aSandboxFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDocShell onePermittedSandboxedNavigator; */
NS_IMETHODIMP nsDocShell::GetOnePermittedSandboxedNavigator(nsIDocShell * *aOnePermittedSandboxedNavigator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetOnePermittedSandboxedNavigator(nsIDocShell *aOnePermittedSandboxedNavigator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] bool isSandboxedFrom (in nsIDocShell aTargetDocShell); */
bool nsDocShell::IsSandboxedFrom(nsIDocShell *aTargetDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIChannel mixedContentChannel; */
NS_IMETHODIMP nsDocShell::GetMixedContentChannel(nsIChannel * *aMixedContentChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetMixedContentChannel(nsIChannel *aMixedContentChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetAllowMixedContentAndConnectionData (out boolean rootHasSecureConnection, out boolean allowMixedContent, out boolean isRootDocShell); */
NS_IMETHODIMP nsDocShell::GetAllowMixedContentAndConnectionData(bool *rootHasSecureConnection, bool *allowMixedContent, bool *isRootDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] bool pluginsAllowedInCurrentDoc (); */
NS_IMETHODIMP_(bool) nsDocShell::PluginsAllowedInCurrentDoc()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean fullscreenAllowed; */
NS_IMETHODIMP nsDocShell::GetFullscreenAllowed(bool *aFullscreenAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFullscreenAllowed (in boolean allowed); */
NS_IMETHODIMP nsDocShell::SetFullscreenAllowed(bool allowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible,noscript] attribute boolean affectPrivateSessionLifetime; */
NS_IMETHODIMP nsDocShell::GetAffectPrivateSessionLifetime(bool *aAffectPrivateSessionLifetime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetAffectPrivateSessionLifetime(bool aAffectPrivateSessionLifetime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean mayEnableCharacterEncodingMenu; */
NS_IMETHODIMP nsDocShell::GetMayEnableCharacterEncodingMenu(bool *aMayEnableCharacterEncodingMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIEditor editor; */
NS_IMETHODIMP nsDocShell::GetEditor(nsIEditor * *aEditor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetEditor(nsIEditor *aEditor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean editable; */
NS_IMETHODIMP nsDocShell::GetEditable(bool *aEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasEditingSession; */
NS_IMETHODIMP nsDocShell::GetHasEditingSession(bool *aHasEditingSession)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void makeEditable (in boolean inWaitForUriLoad); */
NS_IMETHODIMP nsDocShell::MakeEditable(bool inWaitForUriLoad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISHEntry getChildSHEntry (in long aChildOffset); */
NS_IMETHODIMP nsDocShell::GetChildSHEntry(int32_t aChildOffset, nsISHEntry * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addChildSHEntry (in nsISHEntry aCloneReference, in nsISHEntry aHistoryEntry, in long aChildOffset, in unsigned long aLoadType, in boolean aCloneChilden); */
NS_IMETHODIMP nsDocShell::AddChildSHEntry(nsISHEntry *aCloneReference, nsISHEntry *aHistoryEntry, int32_t aChildOffset, uint32_t aLoadType, bool aCloneChilden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean useGlobalHistory; */
NS_IMETHODIMP nsDocShell::GetUseGlobalHistory(bool *aUseGlobalHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetUseGlobalHistory(bool aUseGlobalHistory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFromSessionHistory (); */
NS_IMETHODIMP nsDocShell::RemoveFromSessionHistory()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean createdDynamically; */
NS_IMETHODIMP nsDocShell::GetCreatedDynamically(bool *aCreatedDynamically)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetCreatedDynamically(bool aCreatedDynamically)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getCurrentSHEntry (out nsISHEntry aEntry); */
NS_IMETHODIMP nsDocShell::GetCurrentSHEntry(nsISHEntry * *aEntry, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCommandEnabled (in string command); */
NS_IMETHODIMP nsDocShell::IsCommandEnabled(const char * command, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommand (in string command); */
NS_IMETHODIMP nsDocShell::DoCommand(const char * command)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] bool IsInvisible (); */
NS_IMETHODIMP_(bool) nsDocShell::IsInvisible()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void SetInvisible (in bool aIsInvisibleDochsell); */
NS_IMETHODIMP_(void) nsDocShell::SetInvisible(bool aIsInvisibleDochsell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsIScriptGlobalObject GetScriptGlobalObject (); */
nsIScriptGlobalObject * nsDocShell::GetScriptGlobalObject()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] attribute boolean deviceSizeIsPageSize; */
NS_IMETHODIMP nsDocShell::GetDeviceSizeIsPageSize(bool *aDeviceSizeIsPageSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetDeviceSizeIsPageSize(bool aDeviceSizeIsPageSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] void setOpener (in nsITabParent aOpener); */
void nsDocShell::SetOpener(nsITabParent *aOpener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsITabParent getOpener (); */
nsITabParent * nsDocShell::GetOpener()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] void notifyJSRunToCompletionStart (in string aReason, in wstring functionName, in wstring fileName, in unsigned long lineNumber); */
void nsDocShell::NotifyJSRunToCompletionStart(const char * aReason, const char16_t * functionName, const char16_t * fileName, uint32_t lineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] void notifyJSRunToCompletionStop (); */
void nsDocShell::NotifyJSRunToCompletionStop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean hasLoadedNonBlankURI; */
NS_IMETHODIMP nsDocShell::GetHasLoadedNonBlankURI(bool *aHasLoadedNonBlankURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString paymentRequestId; */
NS_IMETHODIMP nsDocShell::GetPaymentRequestId(nsAString & aPaymentRequestId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetPaymentRequestId(const nsAString & aPaymentRequestId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean windowDraggingAllowed; */
NS_IMETHODIMP nsDocShell::GetWindowDraggingAllowed(bool *aWindowDraggingAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShell::SetWindowDraggingAllowed(bool aWindowDraggingAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShell_h__ */
