/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFrameLoader.idl
 */

#ifndef __gen_nsIFrameLoader_h__
#define __gen_nsIFrameLoader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsFrameLoader; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIFrame; /* forward declaration */

class nsSubDocumentFrame; /* forward declaration */

class nsIMessageSender; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsITabParent; /* forward declaration */

class nsILoadContext; /* forward declaration */


/* starting interface:    nsIFrameLoader */
#define NS_IFRAMELOADER_IID_STR "d24f9330-ae4e-11e4-ab27-0800200c9a66"

#define NS_IFRAMELOADER_IID \
  {0xd24f9330, 0xae4e, 0x11e4, \
    { 0xab, 0x27, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIFrameLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMELOADER_IID)

  /* readonly attribute nsIDocShell docShell; */
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) = 0;

  /* readonly attribute nsITabParent tabParent; */
  NS_IMETHOD GetTabParent(nsITabParent * *aTabParent) = 0;

  /* readonly attribute nsILoadContext loadContext; */
  NS_IMETHOD GetLoadContext(nsILoadContext * *aLoadContext) = 0;

  /* void loadFrame (); */
  NS_IMETHOD LoadFrame(void) = 0;

  /* void loadURI (in nsIURI aURI); */
  NS_IMETHOD LoadURI(nsIURI *aURI) = 0;

  /* void setIsPrerendered (); */
  NS_IMETHOD SetIsPrerendered(void) = 0;

  /* void destroy (); */
  NS_IMETHOD Destroy(void) = 0;

  /* readonly attribute boolean depthTooGreat; */
  NS_IMETHOD GetDepthTooGreat(bool *aDepthTooGreat) = 0;

  /* [noscript] void updatePositionAndSize (in nsSubDocumentFrame aIFrame); */
  NS_IMETHOD UpdatePositionAndSize(nsSubDocumentFrame *aIFrame) = 0;

  /* void activateRemoteFrame (); */
  NS_IMETHOD ActivateRemoteFrame(void) = 0;

  /* void deactivateRemoteFrame (); */
  NS_IMETHOD DeactivateRemoteFrame(void) = 0;

  /* void sendCrossProcessMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
  NS_IMETHOD SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame) = 0;

  /* void activateFrameEvent (in AString aType, in boolean capture); */
  NS_IMETHOD ActivateFrameEvent(const nsAString & aType, bool capture) = 0;

  /* readonly attribute nsIMessageSender messageManager; */
  NS_IMETHOD GetMessageManager(nsIMessageSender * *aMessageManager) = 0;

  /* void sendCrossProcessKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in boolean aPreventDefault); */
  NS_IMETHOD SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault) = 0;

  /* void requestNotifyAfterRemotePaint (); */
  NS_IMETHOD RequestNotifyAfterRemotePaint(void) = 0;

  /* void requestNotifyLayerTreeReady (); */
  NS_IMETHOD RequestNotifyLayerTreeReady(void) = 0;

  /* void requestNotifyLayerTreeCleared (); */
  NS_IMETHOD RequestNotifyLayerTreeCleared(void) = 0;

  enum {
    EVENT_MODE_NORMAL_DISPATCH = 0U,
    EVENT_MODE_DONT_FORWARD_TO_CHILD = 1U
  };

  /* attribute unsigned long eventMode; */
  NS_IMETHOD GetEventMode(uint32_t *aEventMode) = 0;
  NS_IMETHOD SetEventMode(uint32_t aEventMode) = 0;

  /* attribute boolean clipSubdocument; */
  NS_IMETHOD GetClipSubdocument(bool *aClipSubdocument) = 0;
  NS_IMETHOD SetClipSubdocument(bool aClipSubdocument) = 0;

  /* attribute boolean clampScrollPosition; */
  NS_IMETHOD GetClampScrollPosition(bool *aClampScrollPosition) = 0;
  NS_IMETHOD SetClampScrollPosition(bool aClampScrollPosition) = 0;

  /* readonly attribute nsIDOMElement ownerElement; */
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) = 0;

  /* readonly attribute unsigned long long childID; */
  NS_IMETHOD GetChildID(uint64_t *aChildID) = 0;

  /* [infallible] attribute boolean visible; */
  NS_IMETHOD GetVisible(bool *aVisible) = 0;
  inline bool GetVisible()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetVisible(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  NS_IMETHOD SetVisible(bool aVisible) = 0;

  /* readonly attribute boolean ownerIsBrowserOrAppFrame; */
  NS_IMETHOD GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame) = 0;

  /* readonly attribute boolean ownerIsWidget; */
  NS_IMETHOD GetOwnerIsWidget(bool *aOwnerIsWidget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameLoader, NS_IFRAMELOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMELOADER \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) override; \
  NS_IMETHOD GetTabParent(nsITabParent * *aTabParent) override; \
  NS_IMETHOD GetLoadContext(nsILoadContext * *aLoadContext) override; \
  NS_IMETHOD LoadFrame(void) override; \
  NS_IMETHOD LoadURI(nsIURI *aURI) override; \
  NS_IMETHOD SetIsPrerendered(void) override; \
  NS_IMETHOD Destroy(void) override; \
  NS_IMETHOD GetDepthTooGreat(bool *aDepthTooGreat) override; \
  NS_IMETHOD UpdatePositionAndSize(nsSubDocumentFrame *aIFrame) override; \
  NS_IMETHOD ActivateRemoteFrame(void) override; \
  NS_IMETHOD DeactivateRemoteFrame(void) override; \
  NS_IMETHOD SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame) override; \
  NS_IMETHOD ActivateFrameEvent(const nsAString & aType, bool capture) override; \
  NS_IMETHOD GetMessageManager(nsIMessageSender * *aMessageManager) override; \
  NS_IMETHOD SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault) override; \
  NS_IMETHOD RequestNotifyAfterRemotePaint(void) override; \
  NS_IMETHOD RequestNotifyLayerTreeReady(void) override; \
  NS_IMETHOD RequestNotifyLayerTreeCleared(void) override; \
  NS_IMETHOD GetEventMode(uint32_t *aEventMode) override; \
  NS_IMETHOD SetEventMode(uint32_t aEventMode) override; \
  NS_IMETHOD GetClipSubdocument(bool *aClipSubdocument) override; \
  NS_IMETHOD SetClipSubdocument(bool aClipSubdocument) override; \
  NS_IMETHOD GetClampScrollPosition(bool *aClampScrollPosition) override; \
  NS_IMETHOD SetClampScrollPosition(bool aClampScrollPosition) override; \
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) override; \
  NS_IMETHOD GetChildID(uint64_t *aChildID) override; \
  using nsIFrameLoader::GetVisible; \
  NS_IMETHOD GetVisible(bool *aVisible) override; \
  NS_IMETHOD SetVisible(bool aVisible) override; \
  NS_IMETHOD GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame) override; \
  NS_IMETHOD GetOwnerIsWidget(bool *aOwnerIsWidget) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMELOADER(_to) \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) override { return _to GetDocShell(aDocShell); } \
  NS_IMETHOD GetTabParent(nsITabParent * *aTabParent) override { return _to GetTabParent(aTabParent); } \
  NS_IMETHOD GetLoadContext(nsILoadContext * *aLoadContext) override { return _to GetLoadContext(aLoadContext); } \
  NS_IMETHOD LoadFrame(void) override { return _to LoadFrame(); } \
  NS_IMETHOD LoadURI(nsIURI *aURI) override { return _to LoadURI(aURI); } \
  NS_IMETHOD SetIsPrerendered(void) override { return _to SetIsPrerendered(); } \
  NS_IMETHOD Destroy(void) override { return _to Destroy(); } \
  NS_IMETHOD GetDepthTooGreat(bool *aDepthTooGreat) override { return _to GetDepthTooGreat(aDepthTooGreat); } \
  NS_IMETHOD UpdatePositionAndSize(nsSubDocumentFrame *aIFrame) override { return _to UpdatePositionAndSize(aIFrame); } \
  NS_IMETHOD ActivateRemoteFrame(void) override { return _to ActivateRemoteFrame(); } \
  NS_IMETHOD DeactivateRemoteFrame(void) override { return _to DeactivateRemoteFrame(); } \
  NS_IMETHOD SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame) override { return _to SendCrossProcessMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_IMETHOD ActivateFrameEvent(const nsAString & aType, bool capture) override { return _to ActivateFrameEvent(aType, capture); } \
  NS_IMETHOD GetMessageManager(nsIMessageSender * *aMessageManager) override { return _to GetMessageManager(aMessageManager); } \
  NS_IMETHOD SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault) override { return _to SendCrossProcessKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aPreventDefault); } \
  NS_IMETHOD RequestNotifyAfterRemotePaint(void) override { return _to RequestNotifyAfterRemotePaint(); } \
  NS_IMETHOD RequestNotifyLayerTreeReady(void) override { return _to RequestNotifyLayerTreeReady(); } \
  NS_IMETHOD RequestNotifyLayerTreeCleared(void) override { return _to RequestNotifyLayerTreeCleared(); } \
  NS_IMETHOD GetEventMode(uint32_t *aEventMode) override { return _to GetEventMode(aEventMode); } \
  NS_IMETHOD SetEventMode(uint32_t aEventMode) override { return _to SetEventMode(aEventMode); } \
  NS_IMETHOD GetClipSubdocument(bool *aClipSubdocument) override { return _to GetClipSubdocument(aClipSubdocument); } \
  NS_IMETHOD SetClipSubdocument(bool aClipSubdocument) override { return _to SetClipSubdocument(aClipSubdocument); } \
  NS_IMETHOD GetClampScrollPosition(bool *aClampScrollPosition) override { return _to GetClampScrollPosition(aClampScrollPosition); } \
  NS_IMETHOD SetClampScrollPosition(bool aClampScrollPosition) override { return _to SetClampScrollPosition(aClampScrollPosition); } \
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) override { return _to GetOwnerElement(aOwnerElement); } \
  NS_IMETHOD GetChildID(uint64_t *aChildID) override { return _to GetChildID(aChildID); } \
  using nsIFrameLoader::GetVisible; \
  NS_IMETHOD GetVisible(bool *aVisible) override { return _to GetVisible(aVisible); } \
  NS_IMETHOD SetVisible(bool aVisible) override { return _to SetVisible(aVisible); } \
  NS_IMETHOD GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame) override { return _to GetOwnerIsBrowserOrAppFrame(aOwnerIsBrowserOrAppFrame); } \
  NS_IMETHOD GetOwnerIsWidget(bool *aOwnerIsWidget) override { return _to GetOwnerIsWidget(aOwnerIsWidget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMELOADER(_to) \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShell(aDocShell); } \
  NS_IMETHOD GetTabParent(nsITabParent * *aTabParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabParent(aTabParent); } \
  NS_IMETHOD GetLoadContext(nsILoadContext * *aLoadContext) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadContext(aLoadContext); } \
  NS_IMETHOD LoadFrame(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadFrame(); } \
  NS_IMETHOD LoadURI(nsIURI *aURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadURI(aURI); } \
  NS_IMETHOD SetIsPrerendered(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsPrerendered(); } \
  NS_IMETHOD Destroy(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Destroy(); } \
  NS_IMETHOD GetDepthTooGreat(bool *aDepthTooGreat) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDepthTooGreat(aDepthTooGreat); } \
  NS_IMETHOD UpdatePositionAndSize(nsSubDocumentFrame *aIFrame) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdatePositionAndSize(aIFrame); } \
  NS_IMETHOD ActivateRemoteFrame(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateRemoteFrame(); } \
  NS_IMETHOD DeactivateRemoteFrame(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeactivateRemoteFrame(); } \
  NS_IMETHOD SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCrossProcessMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_IMETHOD ActivateFrameEvent(const nsAString & aType, bool capture) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateFrameEvent(aType, capture); } \
  NS_IMETHOD GetMessageManager(nsIMessageSender * *aMessageManager) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageManager(aMessageManager); } \
  NS_IMETHOD SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCrossProcessKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aPreventDefault); } \
  NS_IMETHOD RequestNotifyAfterRemotePaint(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestNotifyAfterRemotePaint(); } \
  NS_IMETHOD RequestNotifyLayerTreeReady(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestNotifyLayerTreeReady(); } \
  NS_IMETHOD RequestNotifyLayerTreeCleared(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestNotifyLayerTreeCleared(); } \
  NS_IMETHOD GetEventMode(uint32_t *aEventMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventMode(aEventMode); } \
  NS_IMETHOD SetEventMode(uint32_t aEventMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEventMode(aEventMode); } \
  NS_IMETHOD GetClipSubdocument(bool *aClipSubdocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClipSubdocument(aClipSubdocument); } \
  NS_IMETHOD SetClipSubdocument(bool aClipSubdocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetClipSubdocument(aClipSubdocument); } \
  NS_IMETHOD GetClampScrollPosition(bool *aClampScrollPosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClampScrollPosition(aClampScrollPosition); } \
  NS_IMETHOD SetClampScrollPosition(bool aClampScrollPosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetClampScrollPosition(aClampScrollPosition); } \
  NS_IMETHOD GetOwnerElement(nsIDOMElement * *aOwnerElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerElement(aOwnerElement); } \
  NS_IMETHOD GetChildID(uint64_t *aChildID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildID(aChildID); } \
  NS_IMETHOD GetVisible(bool *aVisible) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisible(aVisible); } \
  NS_IMETHOD SetVisible(bool aVisible) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisible(aVisible); } \
  NS_IMETHOD GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerIsBrowserOrAppFrame(aOwnerIsBrowserOrAppFrame); } \
  NS_IMETHOD GetOwnerIsWidget(bool *aOwnerIsWidget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerIsWidget(aOwnerIsWidget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameLoader : public nsIFrameLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMELOADER

  nsFrameLoader();

private:
  ~nsFrameLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsFrameLoader, nsIFrameLoader)

nsFrameLoader::nsFrameLoader()
{
  /* member initializers and constructor code */
}

nsFrameLoader::~nsFrameLoader()
{
  /* destructor code */
}

/* readonly attribute nsIDocShell docShell; */
NS_IMETHODIMP nsFrameLoader::GetDocShell(nsIDocShell * *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsITabParent tabParent; */
NS_IMETHODIMP nsFrameLoader::GetTabParent(nsITabParent * *aTabParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsILoadContext loadContext; */
NS_IMETHODIMP nsFrameLoader::GetLoadContext(nsILoadContext * *aLoadContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadFrame (); */
NS_IMETHODIMP nsFrameLoader::LoadFrame()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadURI (in nsIURI aURI); */
NS_IMETHODIMP nsFrameLoader::LoadURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIsPrerendered (); */
NS_IMETHODIMP nsFrameLoader::SetIsPrerendered()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroy (); */
NS_IMETHODIMP nsFrameLoader::Destroy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean depthTooGreat; */
NS_IMETHODIMP nsFrameLoader::GetDepthTooGreat(bool *aDepthTooGreat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void updatePositionAndSize (in nsSubDocumentFrame aIFrame); */
NS_IMETHODIMP nsFrameLoader::UpdatePositionAndSize(nsSubDocumentFrame *aIFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activateRemoteFrame (); */
NS_IMETHODIMP nsFrameLoader::ActivateRemoteFrame()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deactivateRemoteFrame (); */
NS_IMETHODIMP nsFrameLoader::DeactivateRemoteFrame()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendCrossProcessMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
NS_IMETHODIMP nsFrameLoader::SendCrossProcessMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activateFrameEvent (in AString aType, in boolean capture); */
NS_IMETHODIMP nsFrameLoader::ActivateFrameEvent(const nsAString & aType, bool capture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMessageSender messageManager; */
NS_IMETHODIMP nsFrameLoader::GetMessageManager(nsIMessageSender * *aMessageManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendCrossProcessKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in boolean aPreventDefault); */
NS_IMETHODIMP nsFrameLoader::SendCrossProcessKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, bool aPreventDefault)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestNotifyAfterRemotePaint (); */
NS_IMETHODIMP nsFrameLoader::RequestNotifyAfterRemotePaint()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestNotifyLayerTreeReady (); */
NS_IMETHODIMP nsFrameLoader::RequestNotifyLayerTreeReady()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestNotifyLayerTreeCleared (); */
NS_IMETHODIMP nsFrameLoader::RequestNotifyLayerTreeCleared()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long eventMode; */
NS_IMETHODIMP nsFrameLoader::GetEventMode(uint32_t *aEventMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFrameLoader::SetEventMode(uint32_t aEventMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean clipSubdocument; */
NS_IMETHODIMP nsFrameLoader::GetClipSubdocument(bool *aClipSubdocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFrameLoader::SetClipSubdocument(bool aClipSubdocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean clampScrollPosition; */
NS_IMETHODIMP nsFrameLoader::GetClampScrollPosition(bool *aClampScrollPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFrameLoader::SetClampScrollPosition(bool aClampScrollPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement ownerElement; */
NS_IMETHODIMP nsFrameLoader::GetOwnerElement(nsIDOMElement * *aOwnerElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long childID; */
NS_IMETHODIMP nsFrameLoader::GetChildID(uint64_t *aChildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] attribute boolean visible; */
NS_IMETHODIMP nsFrameLoader::GetVisible(bool *aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFrameLoader::SetVisible(bool aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ownerIsBrowserOrAppFrame; */
NS_IMETHODIMP nsFrameLoader::GetOwnerIsBrowserOrAppFrame(bool *aOwnerIsBrowserOrAppFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ownerIsWidget; */
NS_IMETHODIMP nsFrameLoader::GetOwnerIsWidget(bool *aOwnerIsWidget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsFrameLoader;

/* starting interface:    nsIFrameLoaderOwner */
#define NS_IFRAMELOADEROWNER_IID_STR "c4abebcf-55f3-47d4-af15-151311971255"

#define NS_IFRAMELOADEROWNER_IID \
  {0xc4abebcf, 0x55f3, 0x47d4, \
    { 0xaf, 0x15, 0x15, 0x13, 0x11, 0x97, 0x12, 0x55 }}

class NS_NO_VTABLE nsIFrameLoaderOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMELOADEROWNER_IID)

  /* readonly attribute nsIFrameLoader frameLoader; */
  NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) = 0;

  /* [noscript,notxpcom] alreadyAddRefed_nsFrameLoader GetFrameLoader (); */
  NS_IMETHOD_(already_AddRefed<nsFrameLoader>) GetFrameLoader(void) = 0;

  /* void setIsPrerendered (); */
  NS_IMETHOD SetIsPrerendered(void) = 0;

  /* void swapFrameLoaders (in nsIFrameLoaderOwner aOtherOwner); */
  NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameLoaderOwner, NS_IFRAMELOADEROWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMELOADEROWNER \
  NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) override; \
  NS_IMETHOD_(already_AddRefed<nsFrameLoader>) GetFrameLoader(void) override; \
  NS_IMETHOD SetIsPrerendered(void) override; \
  NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMELOADEROWNER(_to) \
  NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) override { return _to GetFrameLoader(aFrameLoader); } \
  NS_IMETHOD_(already_AddRefed<nsFrameLoader>) GetFrameLoader(void) override { return _to GetFrameLoader(); } \
  NS_IMETHOD SetIsPrerendered(void) override { return _to SetIsPrerendered(); } \
  NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) override { return _to SwapFrameLoaders(aOtherOwner); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMELOADEROWNER(_to) \
  NS_IMETHOD GetFrameLoader(nsIFrameLoader * *aFrameLoader) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameLoader(aFrameLoader); } \
  NS_IMETHOD_(already_AddRefed<nsFrameLoader>) GetFrameLoader(void) override; \
  NS_IMETHOD SetIsPrerendered(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsPrerendered(); } \
  NS_IMETHOD SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SwapFrameLoaders(aOtherOwner); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameLoaderOwner : public nsIFrameLoaderOwner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMELOADEROWNER

  nsFrameLoaderOwner();

private:
  ~nsFrameLoaderOwner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsFrameLoaderOwner, nsIFrameLoaderOwner)

nsFrameLoaderOwner::nsFrameLoaderOwner()
{
  /* member initializers and constructor code */
}

nsFrameLoaderOwner::~nsFrameLoaderOwner()
{
  /* destructor code */
}

/* readonly attribute nsIFrameLoader frameLoader; */
NS_IMETHODIMP nsFrameLoaderOwner::GetFrameLoader(nsIFrameLoader * *aFrameLoader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] alreadyAddRefed_nsFrameLoader GetFrameLoader (); */
NS_IMETHODIMP_(already_AddRefed<nsFrameLoader>) nsFrameLoaderOwner::GetFrameLoader()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIsPrerendered (); */
NS_IMETHODIMP nsFrameLoaderOwner::SetIsPrerendered()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void swapFrameLoaders (in nsIFrameLoaderOwner aOtherOwner); */
NS_IMETHODIMP nsFrameLoaderOwner::SwapFrameLoaders(nsIFrameLoaderOwner *aOtherOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFrameLoader_h__ */
