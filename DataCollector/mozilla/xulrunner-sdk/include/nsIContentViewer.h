/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContentViewer.idl
 */

#ifndef __gen_nsIContentViewer_h__
#define __gen_nsIContentViewer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsIDocument; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsISHEntry; /* forward declaration */

class nsIPrintSettings; /* forward declaration */

#include "nsTArray.h"
#include "nsRect.h"
class nsIWidget;
class nsIPresShell;
class nsPresContext;
class nsView;
class nsDOMNavigationTiming;

/* starting interface:    nsIContentViewer */
#define NS_ICONTENTVIEWER_IID_STR "702e0a92-7d63-490e-b5ee-d247e6bd4588"

#define NS_ICONTENTVIEWER_IID \
  {0x702e0a92, 0x7d63, 0x490e, \
    { 0xb5, 0xee, 0xd2, 0x47, 0xe6, 0xbd, 0x45, 0x88 }}

class NS_NO_VTABLE nsIContentViewer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWER_IID)

  /* [noscript] void init (in nsIWidgetPtr aParentWidget, [const] in nsIntRectRef aBounds); */
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) = 0;

  /* attribute nsIDocShell container; */
  NS_IMETHOD GetContainer(nsIDocShell * *aContainer) = 0;
  NS_IMETHOD SetContainer(nsIDocShell *aContainer) = 0;

  /* [noscript,nostdcall,notxpcom] void loadStart (in nsIDocument aDoc); */
  virtual void LoadStart(nsIDocument *aDoc) = 0;

  /* void loadComplete (in nsresult aStatus); */
  NS_IMETHOD LoadComplete(nsresult aStatus) = 0;

  /* boolean permitUnload ([optional] in boolean aCallerClosesWindow); */
  NS_IMETHOD PermitUnload(bool aCallerClosesWindow, bool *_retval) = 0;

  /* readonly attribute boolean inPermitUnload; */
  NS_IMETHOD GetInPermitUnload(bool *aInPermitUnload) = 0;

  /* [noscript,nostdcall] boolean permitUnloadInternal (in boolean aCallerClosesWindow, inout boolean aShouldPrompt); */
  virtual nsresult PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval) = 0;

  /* readonly attribute boolean beforeUnloadFiring; */
  NS_IMETHOD GetBeforeUnloadFiring(bool *aBeforeUnloadFiring) = 0;

  /* void resetCloseWindow (); */
  NS_IMETHOD ResetCloseWindow(void) = 0;

  /* void pageHide (in boolean isUnload); */
  NS_IMETHOD PageHide(bool isUnload) = 0;

  /* void close (in nsISHEntry historyEntry); */
  NS_IMETHOD Close(nsISHEntry *historyEntry) = 0;

  /* void destroy (); */
  NS_IMETHOD Destroy(void) = 0;

  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

  /* attribute nsIDOMDocument DOMDocument; */
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) = 0;
  NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) = 0;

  /* [noscript,notxpcom] nsIDocument getDocument (); */
  NS_IMETHOD_(nsIDocument *) GetDocument(void) = 0;

  /* [noscript] void getBounds (in nsIntRectRef aBounds); */
  NS_IMETHOD GetBounds(nsIntRect & aBounds) = 0;

  /* [noscript] void setBounds ([const] in nsIntRectRef aBounds); */
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) = 0;

  /* [noscript] attribute nsIContentViewer previousViewer; */
  NS_IMETHOD GetPreviousViewer(nsIContentViewer * *aPreviousViewer) = 0;
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) = 0;

  /* void move (in long aX, in long aY); */
  NS_IMETHOD Move(int32_t aX, int32_t aY) = 0;

  /* void show (); */
  NS_IMETHOD Show(void) = 0;

  /* void hide (); */
  NS_IMETHOD Hide(void) = 0;

  /* attribute boolean sticky; */
  NS_IMETHOD GetSticky(bool *aSticky) = 0;
  NS_IMETHOD SetSticky(bool aSticky) = 0;

  /* boolean requestWindowClose (); */
  NS_IMETHOD RequestWindowClose(bool *_retval) = 0;

  /* void open (in nsISupports aState, in nsISHEntry aSHEntry); */
  NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) = 0;

  /* void clearHistoryEntry (); */
  NS_IMETHOD ClearHistoryEntry(void) = 0;

  /* void setPageMode (in boolean aPageMode, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings) = 0;

  /* readonly attribute nsISHEntry historyEntry; */
  NS_IMETHOD GetHistoryEntry(nsISHEntry * *aHistoryEntry) = 0;

  /* readonly attribute boolean isTabModalPromptAllowed; */
  NS_IMETHOD GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed) = 0;

  /* attribute boolean isHidden; */
  NS_IMETHOD GetIsHidden(bool *aIsHidden) = 0;
  NS_IMETHOD SetIsHidden(bool aIsHidden) = 0;

  /* [noscript] readonly attribute nsIPresShellPtr presShell; */
  NS_IMETHOD GetPresShell(nsIPresShell **aPresShell) = 0;

  /* [noscript] readonly attribute nsPresContextPtr presContext; */
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) = 0;

  /* [noscript] void setDocumentInternal (in nsIDocument aDocument, in boolean aForceReuseInnerWindow); */
  NS_IMETHOD SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow) = 0;

  /* [noscript,nostdcall,notxpcom] nsViewPtr findContainerView (); */
  virtual nsView * FindContainerView(void) = 0;

  /* [noscript,nostdcall,notxpcom] void setNavigationTiming (in nsDOMNavigationTimingPtr aTiming); */
  virtual void SetNavigationTiming(nsDOMNavigationTiming *aTiming) = 0;

  /* void scrollToNode (in nsIDOMNode node); */
  NS_IMETHOD ScrollToNode(nsIDOMNode *node) = 0;

  /* attribute float textZoom; */
  NS_IMETHOD GetTextZoom(float *aTextZoom) = 0;
  NS_IMETHOD SetTextZoom(float aTextZoom) = 0;

  /* attribute float fullZoom; */
  NS_IMETHOD GetFullZoom(float *aFullZoom) = 0;
  NS_IMETHOD SetFullZoom(float aFullZoom) = 0;

  /* attribute boolean authorStyleDisabled; */
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled) = 0;
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled) = 0;

  /* attribute ACString forceCharacterSet; */
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) = 0;
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) = 0;

  /* attribute ACString hintCharacterSet; */
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) = 0;
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) = 0;

  /* attribute int32_t hintCharacterSetSource; */
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) = 0;
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) = 0;

  /* void getContentSize (out long width, out long height); */
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) = 0;

  /* attribute long minFontSize; */
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) = 0;
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) = 0;

  /* [noscript] void appendSubtree (in nsIContentViewerTArray array); */
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIContentViewer> > & array) = 0;

  /* void changeMaxLineBoxWidth (in int32_t maxLineBoxWidth); */
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) = 0;

  /* void pausePainting (); */
  NS_IMETHOD PausePainting(void) = 0;

  /* void resumePainting (); */
  NS_IMETHOD ResumePainting(void) = 0;

  /* void emulateMedium (in AString aMediaType); */
  NS_IMETHOD EmulateMedium(const nsAString & aMediaType) = 0;

  /* void stopEmulatingMedium (); */
  NS_IMETHOD StopEmulatingMedium(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewer, NS_ICONTENTVIEWER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWER \
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) override; \
  NS_IMETHOD GetContainer(nsIDocShell * *aContainer) override; \
  NS_IMETHOD SetContainer(nsIDocShell *aContainer) override; \
  virtual void LoadStart(nsIDocument *aDoc) override; \
  NS_IMETHOD LoadComplete(nsresult aStatus) override; \
  NS_IMETHOD PermitUnload(bool aCallerClosesWindow, bool *_retval) override; \
  NS_IMETHOD GetInPermitUnload(bool *aInPermitUnload) override; \
  virtual nsresult PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval) override; \
  NS_IMETHOD GetBeforeUnloadFiring(bool *aBeforeUnloadFiring) override; \
  NS_IMETHOD ResetCloseWindow(void) override; \
  NS_IMETHOD PageHide(bool isUnload) override; \
  NS_IMETHOD Close(nsISHEntry *historyEntry) override; \
  NS_IMETHOD Destroy(void) override; \
  NS_IMETHOD Stop(void) override; \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) override; \
  NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) override; \
  NS_IMETHOD_(nsIDocument *) GetDocument(void) override; \
  NS_IMETHOD GetBounds(nsIntRect & aBounds) override; \
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) override; \
  NS_IMETHOD GetPreviousViewer(nsIContentViewer * *aPreviousViewer) override; \
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) override; \
  NS_IMETHOD Move(int32_t aX, int32_t aY) override; \
  NS_IMETHOD Show(void) override; \
  NS_IMETHOD Hide(void) override; \
  NS_IMETHOD GetSticky(bool *aSticky) override; \
  NS_IMETHOD SetSticky(bool aSticky) override; \
  NS_IMETHOD RequestWindowClose(bool *_retval) override; \
  NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) override; \
  NS_IMETHOD ClearHistoryEntry(void) override; \
  NS_IMETHOD SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings) override; \
  NS_IMETHOD GetHistoryEntry(nsISHEntry * *aHistoryEntry) override; \
  NS_IMETHOD GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed) override; \
  NS_IMETHOD GetIsHidden(bool *aIsHidden) override; \
  NS_IMETHOD SetIsHidden(bool aIsHidden) override; \
  NS_IMETHOD GetPresShell(nsIPresShell **aPresShell) override; \
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) override; \
  NS_IMETHOD SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow) override; \
  virtual nsView * FindContainerView(void) override; \
  virtual void SetNavigationTiming(nsDOMNavigationTiming *aTiming) override; \
  NS_IMETHOD ScrollToNode(nsIDOMNode *node) override; \
  NS_IMETHOD GetTextZoom(float *aTextZoom) override; \
  NS_IMETHOD SetTextZoom(float aTextZoom) override; \
  NS_IMETHOD GetFullZoom(float *aFullZoom) override; \
  NS_IMETHOD SetFullZoom(float aFullZoom) override; \
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled) override; \
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled) override; \
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) override; \
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) override; \
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) override; \
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) override; \
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) override; \
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) override; \
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) override; \
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) override; \
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) override; \
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIContentViewer> > & array) override; \
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) override; \
  NS_IMETHOD PausePainting(void) override; \
  NS_IMETHOD ResumePainting(void) override; \
  NS_IMETHOD EmulateMedium(const nsAString & aMediaType) override; \
  NS_IMETHOD StopEmulatingMedium(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWER(_to) \
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) override { return _to Init(aParentWidget, aBounds); } \
  NS_IMETHOD GetContainer(nsIDocShell * *aContainer) override { return _to GetContainer(aContainer); } \
  NS_IMETHOD SetContainer(nsIDocShell *aContainer) override { return _to SetContainer(aContainer); } \
  virtual void LoadStart(nsIDocument *aDoc) override { return _to LoadStart(aDoc); } \
  NS_IMETHOD LoadComplete(nsresult aStatus) override { return _to LoadComplete(aStatus); } \
  NS_IMETHOD PermitUnload(bool aCallerClosesWindow, bool *_retval) override { return _to PermitUnload(aCallerClosesWindow, _retval); } \
  NS_IMETHOD GetInPermitUnload(bool *aInPermitUnload) override { return _to GetInPermitUnload(aInPermitUnload); } \
  virtual nsresult PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval) override { return _to PermitUnloadInternal(aCallerClosesWindow, aShouldPrompt, _retval); } \
  NS_IMETHOD GetBeforeUnloadFiring(bool *aBeforeUnloadFiring) override { return _to GetBeforeUnloadFiring(aBeforeUnloadFiring); } \
  NS_IMETHOD ResetCloseWindow(void) override { return _to ResetCloseWindow(); } \
  NS_IMETHOD PageHide(bool isUnload) override { return _to PageHide(isUnload); } \
  NS_IMETHOD Close(nsISHEntry *historyEntry) override { return _to Close(historyEntry); } \
  NS_IMETHOD Destroy(void) override { return _to Destroy(); } \
  NS_IMETHOD Stop(void) override { return _to Stop(); } \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) override { return _to GetDOMDocument(aDOMDocument); } \
  NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) override { return _to SetDOMDocument(aDOMDocument); } \
  NS_IMETHOD_(nsIDocument *) GetDocument(void) override { return _to GetDocument(); } \
  NS_IMETHOD GetBounds(nsIntRect & aBounds) override { return _to GetBounds(aBounds); } \
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) override { return _to SetBounds(aBounds); } \
  NS_IMETHOD GetPreviousViewer(nsIContentViewer * *aPreviousViewer) override { return _to GetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) override { return _to SetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD Move(int32_t aX, int32_t aY) override { return _to Move(aX, aY); } \
  NS_IMETHOD Show(void) override { return _to Show(); } \
  NS_IMETHOD Hide(void) override { return _to Hide(); } \
  NS_IMETHOD GetSticky(bool *aSticky) override { return _to GetSticky(aSticky); } \
  NS_IMETHOD SetSticky(bool aSticky) override { return _to SetSticky(aSticky); } \
  NS_IMETHOD RequestWindowClose(bool *_retval) override { return _to RequestWindowClose(_retval); } \
  NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) override { return _to Open(aState, aSHEntry); } \
  NS_IMETHOD ClearHistoryEntry(void) override { return _to ClearHistoryEntry(); } \
  NS_IMETHOD SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings) override { return _to SetPageMode(aPageMode, aPrintSettings); } \
  NS_IMETHOD GetHistoryEntry(nsISHEntry * *aHistoryEntry) override { return _to GetHistoryEntry(aHistoryEntry); } \
  NS_IMETHOD GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed) override { return _to GetIsTabModalPromptAllowed(aIsTabModalPromptAllowed); } \
  NS_IMETHOD GetIsHidden(bool *aIsHidden) override { return _to GetIsHidden(aIsHidden); } \
  NS_IMETHOD SetIsHidden(bool aIsHidden) override { return _to SetIsHidden(aIsHidden); } \
  NS_IMETHOD GetPresShell(nsIPresShell **aPresShell) override { return _to GetPresShell(aPresShell); } \
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) override { return _to GetPresContext(aPresContext); } \
  NS_IMETHOD SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow) override { return _to SetDocumentInternal(aDocument, aForceReuseInnerWindow); } \
  virtual nsView * FindContainerView(void) override { return _to FindContainerView(); } \
  virtual void SetNavigationTiming(nsDOMNavigationTiming *aTiming) override { return _to SetNavigationTiming(aTiming); } \
  NS_IMETHOD ScrollToNode(nsIDOMNode *node) override { return _to ScrollToNode(node); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) override { return _to GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) override { return _to SetTextZoom(aTextZoom); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) override { return _to GetFullZoom(aFullZoom); } \
  NS_IMETHOD SetFullZoom(float aFullZoom) override { return _to SetFullZoom(aFullZoom); } \
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled) override { return _to GetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled) override { return _to SetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) override { return _to GetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) override { return _to SetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) override { return _to GetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) override { return _to SetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) override { return _to GetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) override { return _to SetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) override { return _to GetContentSize(width, height); } \
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) override { return _to GetMinFontSize(aMinFontSize); } \
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) override { return _to SetMinFontSize(aMinFontSize); } \
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIContentViewer> > & array) override { return _to AppendSubtree(array); } \
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) override { return _to ChangeMaxLineBoxWidth(maxLineBoxWidth); } \
  NS_IMETHOD PausePainting(void) override { return _to PausePainting(); } \
  NS_IMETHOD ResumePainting(void) override { return _to ResumePainting(); } \
  NS_IMETHOD EmulateMedium(const nsAString & aMediaType) override { return _to EmulateMedium(aMediaType); } \
  NS_IMETHOD StopEmulatingMedium(void) override { return _to StopEmulatingMedium(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWER(_to) \
  NS_IMETHOD Init(nsIWidget *aParentWidget, const nsIntRect & aBounds) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aParentWidget, aBounds); } \
  NS_IMETHOD GetContainer(nsIDocShell * *aContainer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainer(aContainer); } \
  NS_IMETHOD SetContainer(nsIDocShell *aContainer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContainer(aContainer); } \
  virtual void LoadStart(nsIDocument *aDoc) override; \
  NS_IMETHOD LoadComplete(nsresult aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadComplete(aStatus); } \
  NS_IMETHOD PermitUnload(bool aCallerClosesWindow, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PermitUnload(aCallerClosesWindow, _retval); } \
  NS_IMETHOD GetInPermitUnload(bool *aInPermitUnload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInPermitUnload(aInPermitUnload); } \
  virtual nsresult PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PermitUnloadInternal(aCallerClosesWindow, aShouldPrompt, _retval); } \
  NS_IMETHOD GetBeforeUnloadFiring(bool *aBeforeUnloadFiring) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBeforeUnloadFiring(aBeforeUnloadFiring); } \
  NS_IMETHOD ResetCloseWindow(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetCloseWindow(); } \
  NS_IMETHOD PageHide(bool isUnload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PageHide(isUnload); } \
  NS_IMETHOD Close(nsISHEntry *historyEntry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(historyEntry); } \
  NS_IMETHOD Destroy(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_IMETHOD Stop(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMDocument(aDOMDocument); } \
  NS_IMETHOD SetDOMDocument(nsIDOMDocument *aDOMDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDOMDocument(aDOMDocument); } \
  NS_IMETHOD_(nsIDocument *) GetDocument(void) override; \
  NS_IMETHOD GetBounds(nsIntRect & aBounds) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBounds(aBounds); } \
  NS_IMETHOD SetBounds(const nsIntRect & aBounds) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBounds(aBounds); } \
  NS_IMETHOD GetPreviousViewer(nsIContentViewer * *aPreviousViewer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD SetPreviousViewer(nsIContentViewer *aPreviousViewer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreviousViewer(aPreviousViewer); } \
  NS_IMETHOD Move(int32_t aX, int32_t aY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Move(aX, aY); } \
  NS_IMETHOD Show(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(); } \
  NS_IMETHOD Hide(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Hide(); } \
  NS_IMETHOD GetSticky(bool *aSticky) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSticky(aSticky); } \
  NS_IMETHOD SetSticky(bool aSticky) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSticky(aSticky); } \
  NS_IMETHOD RequestWindowClose(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestWindowClose(_retval); } \
  NS_IMETHOD Open(nsISupports *aState, nsISHEntry *aSHEntry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aState, aSHEntry); } \
  NS_IMETHOD ClearHistoryEntry(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearHistoryEntry(); } \
  NS_IMETHOD SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageMode(aPageMode, aPrintSettings); } \
  NS_IMETHOD GetHistoryEntry(nsISHEntry * *aHistoryEntry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHistoryEntry(aHistoryEntry); } \
  NS_IMETHOD GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTabModalPromptAllowed(aIsTabModalPromptAllowed); } \
  NS_IMETHOD GetIsHidden(bool *aIsHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsHidden(aIsHidden); } \
  NS_IMETHOD SetIsHidden(bool aIsHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsHidden(aIsHidden); } \
  NS_IMETHOD GetPresShell(nsIPresShell **aPresShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresShell(aPresShell); } \
  NS_IMETHOD GetPresContext(nsPresContext **aPresContext) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresContext(aPresContext); } \
  NS_IMETHOD SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentInternal(aDocument, aForceReuseInnerWindow); } \
  virtual nsView * FindContainerView(void) override; \
  virtual void SetNavigationTiming(nsDOMNavigationTiming *aTiming) override; \
  NS_IMETHOD ScrollToNode(nsIDOMNode *node) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToNode(node); } \
  NS_IMETHOD GetTextZoom(float *aTextZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextZoom(aTextZoom); } \
  NS_IMETHOD SetTextZoom(float aTextZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextZoom(aTextZoom); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullZoom(aFullZoom); } \
  NS_IMETHOD SetFullZoom(float aFullZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFullZoom(aFullZoom); } \
  NS_IMETHOD GetAuthorStyleDisabled(bool *aAuthorStyleDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD SetAuthorStyleDisabled(bool aAuthorStyleDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAuthorStyleDisabled(aAuthorStyleDisabled); } \
  NS_IMETHOD GetForceCharacterSet(nsACString & aForceCharacterSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD SetForceCharacterSet(const nsACString & aForceCharacterSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForceCharacterSet(aForceCharacterSet); } \
  NS_IMETHOD GetHintCharacterSet(nsACString & aHintCharacterSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD SetHintCharacterSet(const nsACString & aHintCharacterSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHintCharacterSet(aHintCharacterSet); } \
  NS_IMETHOD GetHintCharacterSetSource(int32_t *aHintCharacterSetSource) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD SetHintCharacterSetSource(int32_t aHintCharacterSetSource) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHintCharacterSetSource(aHintCharacterSetSource); } \
  NS_IMETHOD GetContentSize(int32_t *width, int32_t *height) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentSize(width, height); } \
  NS_IMETHOD GetMinFontSize(int32_t *aMinFontSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinFontSize(aMinFontSize); } \
  NS_IMETHOD SetMinFontSize(int32_t aMinFontSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinFontSize(aMinFontSize); } \
  NS_IMETHOD AppendSubtree(nsTArray<nsCOMPtr<nsIContentViewer> > & array) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendSubtree(array); } \
  NS_IMETHOD ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ChangeMaxLineBoxWidth(maxLineBoxWidth); } \
  NS_IMETHOD PausePainting(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PausePainting(); } \
  NS_IMETHOD ResumePainting(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumePainting(); } \
  NS_IMETHOD EmulateMedium(const nsAString & aMediaType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EmulateMedium(aMediaType); } \
  NS_IMETHOD StopEmulatingMedium(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StopEmulatingMedium(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentViewer : public nsIContentViewer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTVIEWER

  nsContentViewer();

private:
  ~nsContentViewer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentViewer, nsIContentViewer)

nsContentViewer::nsContentViewer()
{
  /* member initializers and constructor code */
}

nsContentViewer::~nsContentViewer()
{
  /* destructor code */
}

/* [noscript] void init (in nsIWidgetPtr aParentWidget, [const] in nsIntRectRef aBounds); */
NS_IMETHODIMP nsContentViewer::Init(nsIWidget *aParentWidget, const nsIntRect & aBounds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDocShell container; */
NS_IMETHODIMP nsContentViewer::GetContainer(nsIDocShell * *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetContainer(nsIDocShell *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] void loadStart (in nsIDocument aDoc); */
void nsContentViewer::LoadStart(nsIDocument *aDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadComplete (in nsresult aStatus); */
NS_IMETHODIMP nsContentViewer::LoadComplete(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean permitUnload ([optional] in boolean aCallerClosesWindow); */
NS_IMETHODIMP nsContentViewer::PermitUnload(bool aCallerClosesWindow, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inPermitUnload; */
NS_IMETHODIMP nsContentViewer::GetInPermitUnload(bool *aInPermitUnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall] boolean permitUnloadInternal (in boolean aCallerClosesWindow, inout boolean aShouldPrompt); */
nsresult nsContentViewer::PermitUnloadInternal(bool aCallerClosesWindow, bool *aShouldPrompt, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean beforeUnloadFiring; */
NS_IMETHODIMP nsContentViewer::GetBeforeUnloadFiring(bool *aBeforeUnloadFiring)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetCloseWindow (); */
NS_IMETHODIMP nsContentViewer::ResetCloseWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pageHide (in boolean isUnload); */
NS_IMETHODIMP nsContentViewer::PageHide(bool isUnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (in nsISHEntry historyEntry); */
NS_IMETHODIMP nsContentViewer::Close(nsISHEntry *historyEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroy (); */
NS_IMETHODIMP nsContentViewer::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsContentViewer::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMDocument DOMDocument; */
NS_IMETHODIMP nsContentViewer::GetDOMDocument(nsIDOMDocument * *aDOMDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetDOMDocument(nsIDOMDocument *aDOMDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] nsIDocument getDocument (); */
NS_IMETHODIMP_(nsIDocument *) nsContentViewer::GetDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getBounds (in nsIntRectRef aBounds); */
NS_IMETHODIMP nsContentViewer::GetBounds(nsIntRect & aBounds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setBounds ([const] in nsIntRectRef aBounds); */
NS_IMETHODIMP nsContentViewer::SetBounds(const nsIntRect & aBounds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIContentViewer previousViewer; */
NS_IMETHODIMP nsContentViewer::GetPreviousViewer(nsIContentViewer * *aPreviousViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetPreviousViewer(nsIContentViewer *aPreviousViewer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void move (in long aX, in long aY); */
NS_IMETHODIMP nsContentViewer::Move(int32_t aX, int32_t aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void show (); */
NS_IMETHODIMP nsContentViewer::Show()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hide (); */
NS_IMETHODIMP nsContentViewer::Hide()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean sticky; */
NS_IMETHODIMP nsContentViewer::GetSticky(bool *aSticky)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetSticky(bool aSticky)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean requestWindowClose (); */
NS_IMETHODIMP nsContentViewer::RequestWindowClose(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (in nsISupports aState, in nsISHEntry aSHEntry); */
NS_IMETHODIMP nsContentViewer::Open(nsISupports *aState, nsISHEntry *aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearHistoryEntry (); */
NS_IMETHODIMP nsContentViewer::ClearHistoryEntry()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPageMode (in boolean aPageMode, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsContentViewer::SetPageMode(bool aPageMode, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISHEntry historyEntry; */
NS_IMETHODIMP nsContentViewer::GetHistoryEntry(nsISHEntry * *aHistoryEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isTabModalPromptAllowed; */
NS_IMETHODIMP nsContentViewer::GetIsTabModalPromptAllowed(bool *aIsTabModalPromptAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isHidden; */
NS_IMETHODIMP nsContentViewer::GetIsHidden(bool *aIsHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetIsHidden(bool aIsHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIPresShellPtr presShell; */
NS_IMETHODIMP nsContentViewer::GetPresShell(nsIPresShell **aPresShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsPresContextPtr presContext; */
NS_IMETHODIMP nsContentViewer::GetPresContext(nsPresContext **aPresContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setDocumentInternal (in nsIDocument aDocument, in boolean aForceReuseInnerWindow); */
NS_IMETHODIMP nsContentViewer::SetDocumentInternal(nsIDocument *aDocument, bool aForceReuseInnerWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsViewPtr findContainerView (); */
nsView * nsContentViewer::FindContainerView()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] void setNavigationTiming (in nsDOMNavigationTimingPtr aTiming); */
void nsContentViewer::SetNavigationTiming(nsDOMNavigationTiming *aTiming)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToNode (in nsIDOMNode node); */
NS_IMETHODIMP nsContentViewer::ScrollToNode(nsIDOMNode *node)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float textZoom; */
NS_IMETHODIMP nsContentViewer::GetTextZoom(float *aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetTextZoom(float aTextZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float fullZoom; */
NS_IMETHODIMP nsContentViewer::GetFullZoom(float *aFullZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetFullZoom(float aFullZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean authorStyleDisabled; */
NS_IMETHODIMP nsContentViewer::GetAuthorStyleDisabled(bool *aAuthorStyleDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetAuthorStyleDisabled(bool aAuthorStyleDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString forceCharacterSet; */
NS_IMETHODIMP nsContentViewer::GetForceCharacterSet(nsACString & aForceCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetForceCharacterSet(const nsACString & aForceCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString hintCharacterSet; */
NS_IMETHODIMP nsContentViewer::GetHintCharacterSet(nsACString & aHintCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetHintCharacterSet(const nsACString & aHintCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute int32_t hintCharacterSetSource; */
NS_IMETHODIMP nsContentViewer::GetHintCharacterSetSource(int32_t *aHintCharacterSetSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetHintCharacterSetSource(int32_t aHintCharacterSetSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getContentSize (out long width, out long height); */
NS_IMETHODIMP nsContentViewer::GetContentSize(int32_t *width, int32_t *height)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long minFontSize; */
NS_IMETHODIMP nsContentViewer::GetMinFontSize(int32_t *aMinFontSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentViewer::SetMinFontSize(int32_t aMinFontSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void appendSubtree (in nsIContentViewerTArray array); */
NS_IMETHODIMP nsContentViewer::AppendSubtree(nsTArray<nsCOMPtr<nsIContentViewer> > & array)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void changeMaxLineBoxWidth (in int32_t maxLineBoxWidth); */
NS_IMETHODIMP nsContentViewer::ChangeMaxLineBoxWidth(int32_t maxLineBoxWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pausePainting (); */
NS_IMETHODIMP nsContentViewer::PausePainting()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumePainting (); */
NS_IMETHODIMP nsContentViewer::ResumePainting()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void emulateMedium (in AString aMediaType); */
NS_IMETHODIMP nsContentViewer::EmulateMedium(const nsAString & aMediaType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopEmulatingMedium (); */
NS_IMETHODIMP nsContentViewer::StopEmulatingMedium()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentViewer_h__ */
