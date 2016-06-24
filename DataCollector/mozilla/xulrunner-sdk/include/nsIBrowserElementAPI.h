/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBrowserElementAPI.idl
 */

#ifndef __gen_nsIBrowserElementAPI_h__
#define __gen_nsIBrowserElementAPI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMRequest; /* forward declaration */

class nsIFrameLoader; /* forward declaration */


/* starting interface:    nsIBrowserElementNextPaintListener */
#define NS_IBROWSERELEMENTNEXTPAINTLISTENER_IID_STR "c0c2dd9b-41ef-42dd-a4c1-e456619c1941"

#define NS_IBROWSERELEMENTNEXTPAINTLISTENER_IID \
  {0xc0c2dd9b, 0x41ef, 0x42dd, \
    { 0xa4, 0xc1, 0xe4, 0x56, 0x61, 0x9c, 0x19, 0x41 }}

class NS_NO_VTABLE nsIBrowserElementNextPaintListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERELEMENTNEXTPAINTLISTENER_IID)

  /* void recvNextPaint (); */
  NS_IMETHOD RecvNextPaint(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserElementNextPaintListener, NS_IBROWSERELEMENTNEXTPAINTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERELEMENTNEXTPAINTLISTENER \
  NS_IMETHOD RecvNextPaint(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERELEMENTNEXTPAINTLISTENER(_to) \
  NS_IMETHOD RecvNextPaint(void) override { return _to RecvNextPaint(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERELEMENTNEXTPAINTLISTENER(_to) \
  NS_IMETHOD RecvNextPaint(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RecvNextPaint(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserElementNextPaintListener : public nsIBrowserElementNextPaintListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERELEMENTNEXTPAINTLISTENER

  nsBrowserElementNextPaintListener();

private:
  ~nsBrowserElementNextPaintListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsBrowserElementNextPaintListener, nsIBrowserElementNextPaintListener)

nsBrowserElementNextPaintListener::nsBrowserElementNextPaintListener()
{
  /* member initializers and constructor code */
}

nsBrowserElementNextPaintListener::~nsBrowserElementNextPaintListener()
{
  /* destructor code */
}

/* void recvNextPaint (); */
NS_IMETHODIMP nsBrowserElementNextPaintListener::RecvNextPaint()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define BROWSER_ELEMENT_API_CONTRACTID "@mozilla.org/dom/browser-element-api;1"
#define BROWSER_ELEMENT_API_CID                                 \
    { 0x651db7e3, 0x1734, 0x4536,                               \
      { 0xb1, 0x5a, 0x5b, 0x3a, 0xe6, 0x44, 0x13, 0x4c } }

/* starting interface:    nsIBrowserElementAPI */
#define NS_IBROWSERELEMENTAPI_IID_STR "8ecb598c-f886-11e4-9915-778f934fbf93"

#define NS_IBROWSERELEMENTAPI_IID \
  {0x8ecb598c, 0xf886, 0x11e4, \
    { 0x99, 0x15, 0x77, 0x8f, 0x93, 0x4f, 0xbf, 0x93 }}

class NS_NO_VTABLE nsIBrowserElementAPI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERELEMENTAPI_IID)

  enum {
    FIND_CASE_SENSITIVE = 0,
    FIND_CASE_INSENSITIVE = 1,
    FIND_FORWARD = 0,
    FIND_BACKWARD = 1
  };

  /* void setFrameLoader (in nsIFrameLoader frameLoader); */
  NS_IMETHOD SetFrameLoader(nsIFrameLoader *frameLoader) = 0;

  /* void setVisible (in boolean visible); */
  NS_IMETHOD SetVisible(bool visible) = 0;

  /* nsIDOMDOMRequest getVisible (); */
  NS_IMETHOD GetVisible(nsIDOMDOMRequest * *_retval) = 0;

  /* void setActive (in boolean active); */
  NS_IMETHOD SetActive(bool active) = 0;

  /* boolean getActive (); */
  NS_IMETHOD GetActive(bool *_retval) = 0;

  /* void sendMouseEvent (in DOMString type, in uint32_t x, in uint32_t y, in uint32_t button, in uint32_t clickCount, in uint32_t mifiers); */
  NS_IMETHOD SendMouseEvent(const nsAString & type, uint32_t x, uint32_t y, uint32_t button, uint32_t clickCount, uint32_t mifiers) = 0;

  /* void sendTouchEvent (in DOMString aType, [array, size_is (count), const] in uint32_t aIdentifiers, [array, size_is (count), const] in int32_t aXs, [array, size_is (count), const] in int32_t aYs, [array, size_is (count), const] in uint32_t aRxs, [array, size_is (count), const] in uint32_t aRys, [array, size_is (count), const] in float aRotationAngles, [array, size_is (count), const] in float aForces, in uint32_t count, in long aModifiers); */
  NS_IMETHOD SendTouchEvent(const nsAString & aType, const uint32_t *aIdentifiers, const int32_t *aXs, const int32_t *aYs, const uint32_t *aRxs, const uint32_t *aRys, const float *aRotationAngles, const float *aForces, uint32_t count, int32_t aModifiers) = 0;

  /* void goBack (); */
  NS_IMETHOD GoBack(void) = 0;

  /* void goForward (); */
  NS_IMETHOD GoForward(void) = 0;

  /* void reload (in boolean hardReload); */
  NS_IMETHOD Reload(bool hardReload) = 0;

  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

  /* nsIDOMDOMRequest download (in DOMString url, [optional] in jsval options); */
  NS_IMETHOD Download(const nsAString & url, JS::HandleValue options, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest purgeHistory (); */
  NS_IMETHOD PurgeHistory(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest getScreenshot (in uint32_t width, in uint32_t height, [optional] in DOMString mimeType); */
  NS_IMETHOD GetScreenshot(uint32_t width, uint32_t height, const nsAString & mimeType, nsIDOMDOMRequest * *_retval) = 0;

  /* void zoom (in float zoom); */
  NS_IMETHOD Zoom(float zoom) = 0;

  /* nsIDOMDOMRequest getCanGoBack (); */
  NS_IMETHOD GetCanGoBack(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest getCanGoForward (); */
  NS_IMETHOD GetCanGoForward(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest getContentDimensions (); */
  NS_IMETHOD GetContentDimensions(nsIDOMDOMRequest * *_retval) = 0;

  /* void findAll (in DOMString searchString, in long caseSensitivity); */
  NS_IMETHOD FindAll(const nsAString & searchString, int32_t caseSensitivity) = 0;

  /* void findNext (in long direction); */
  NS_IMETHOD FindNext(int32_t direction) = 0;

  /* void clearMatch (); */
  NS_IMETHOD ClearMatch(void) = 0;

  /* void addNextPaintListener (in nsIBrowserElementNextPaintListener listener); */
  NS_IMETHOD AddNextPaintListener(nsIBrowserElementNextPaintListener *listener) = 0;

  /* void removeNextPaintListener (in nsIBrowserElementNextPaintListener listener); */
  NS_IMETHOD RemoveNextPaintListener(nsIBrowserElementNextPaintListener *listener) = 0;

  /* nsIDOMDOMRequest setInputMethodActive (in boolean isActive); */
  NS_IMETHOD SetInputMethodActive(bool isActive, nsIDOMDOMRequest * *_retval) = 0;

  /* void setNFCFocus (in boolean isFocus); */
  NS_IMETHOD SetNFCFocus(bool isFocus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserElementAPI, NS_IBROWSERELEMENTAPI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERELEMENTAPI \
  NS_IMETHOD SetFrameLoader(nsIFrameLoader *frameLoader) override; \
  NS_IMETHOD SetVisible(bool visible) override; \
  NS_IMETHOD GetVisible(nsIDOMDOMRequest * *_retval) override; \
  NS_IMETHOD SetActive(bool active) override; \
  NS_IMETHOD GetActive(bool *_retval) override; \
  NS_IMETHOD SendMouseEvent(const nsAString & type, uint32_t x, uint32_t y, uint32_t button, uint32_t clickCount, uint32_t mifiers) override; \
  NS_IMETHOD SendTouchEvent(const nsAString & aType, const uint32_t *aIdentifiers, const int32_t *aXs, const int32_t *aYs, const uint32_t *aRxs, const uint32_t *aRys, const float *aRotationAngles, const float *aForces, uint32_t count, int32_t aModifiers) override; \
  NS_IMETHOD GoBack(void) override; \
  NS_IMETHOD GoForward(void) override; \
  NS_IMETHOD Reload(bool hardReload) override; \
  NS_IMETHOD Stop(void) override; \
  NS_IMETHOD Download(const nsAString & url, JS::HandleValue options, nsIDOMDOMRequest * *_retval) override; \
  NS_IMETHOD PurgeHistory(nsIDOMDOMRequest * *_retval) override; \
  NS_IMETHOD GetScreenshot(uint32_t width, uint32_t height, const nsAString & mimeType, nsIDOMDOMRequest * *_retval) override; \
  NS_IMETHOD Zoom(float zoom) override; \
  NS_IMETHOD GetCanGoBack(nsIDOMDOMRequest * *_retval) override; \
  NS_IMETHOD GetCanGoForward(nsIDOMDOMRequest * *_retval) override; \
  NS_IMETHOD GetContentDimensions(nsIDOMDOMRequest * *_retval) override; \
  NS_IMETHOD FindAll(const nsAString & searchString, int32_t caseSensitivity) override; \
  NS_IMETHOD FindNext(int32_t direction) override; \
  NS_IMETHOD ClearMatch(void) override; \
  NS_IMETHOD AddNextPaintListener(nsIBrowserElementNextPaintListener *listener) override; \
  NS_IMETHOD RemoveNextPaintListener(nsIBrowserElementNextPaintListener *listener) override; \
  NS_IMETHOD SetInputMethodActive(bool isActive, nsIDOMDOMRequest * *_retval) override; \
  NS_IMETHOD SetNFCFocus(bool isFocus) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERELEMENTAPI(_to) \
  NS_IMETHOD SetFrameLoader(nsIFrameLoader *frameLoader) override { return _to SetFrameLoader(frameLoader); } \
  NS_IMETHOD SetVisible(bool visible) override { return _to SetVisible(visible); } \
  NS_IMETHOD GetVisible(nsIDOMDOMRequest * *_retval) override { return _to GetVisible(_retval); } \
  NS_IMETHOD SetActive(bool active) override { return _to SetActive(active); } \
  NS_IMETHOD GetActive(bool *_retval) override { return _to GetActive(_retval); } \
  NS_IMETHOD SendMouseEvent(const nsAString & type, uint32_t x, uint32_t y, uint32_t button, uint32_t clickCount, uint32_t mifiers) override { return _to SendMouseEvent(type, x, y, button, clickCount, mifiers); } \
  NS_IMETHOD SendTouchEvent(const nsAString & aType, const uint32_t *aIdentifiers, const int32_t *aXs, const int32_t *aYs, const uint32_t *aRxs, const uint32_t *aRys, const float *aRotationAngles, const float *aForces, uint32_t count, int32_t aModifiers) override { return _to SendTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers); } \
  NS_IMETHOD GoBack(void) override { return _to GoBack(); } \
  NS_IMETHOD GoForward(void) override { return _to GoForward(); } \
  NS_IMETHOD Reload(bool hardReload) override { return _to Reload(hardReload); } \
  NS_IMETHOD Stop(void) override { return _to Stop(); } \
  NS_IMETHOD Download(const nsAString & url, JS::HandleValue options, nsIDOMDOMRequest * *_retval) override { return _to Download(url, options, _retval); } \
  NS_IMETHOD PurgeHistory(nsIDOMDOMRequest * *_retval) override { return _to PurgeHistory(_retval); } \
  NS_IMETHOD GetScreenshot(uint32_t width, uint32_t height, const nsAString & mimeType, nsIDOMDOMRequest * *_retval) override { return _to GetScreenshot(width, height, mimeType, _retval); } \
  NS_IMETHOD Zoom(float zoom) override { return _to Zoom(zoom); } \
  NS_IMETHOD GetCanGoBack(nsIDOMDOMRequest * *_retval) override { return _to GetCanGoBack(_retval); } \
  NS_IMETHOD GetCanGoForward(nsIDOMDOMRequest * *_retval) override { return _to GetCanGoForward(_retval); } \
  NS_IMETHOD GetContentDimensions(nsIDOMDOMRequest * *_retval) override { return _to GetContentDimensions(_retval); } \
  NS_IMETHOD FindAll(const nsAString & searchString, int32_t caseSensitivity) override { return _to FindAll(searchString, caseSensitivity); } \
  NS_IMETHOD FindNext(int32_t direction) override { return _to FindNext(direction); } \
  NS_IMETHOD ClearMatch(void) override { return _to ClearMatch(); } \
  NS_IMETHOD AddNextPaintListener(nsIBrowserElementNextPaintListener *listener) override { return _to AddNextPaintListener(listener); } \
  NS_IMETHOD RemoveNextPaintListener(nsIBrowserElementNextPaintListener *listener) override { return _to RemoveNextPaintListener(listener); } \
  NS_IMETHOD SetInputMethodActive(bool isActive, nsIDOMDOMRequest * *_retval) override { return _to SetInputMethodActive(isActive, _retval); } \
  NS_IMETHOD SetNFCFocus(bool isFocus) override { return _to SetNFCFocus(isFocus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERELEMENTAPI(_to) \
  NS_IMETHOD SetFrameLoader(nsIFrameLoader *frameLoader) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFrameLoader(frameLoader); } \
  NS_IMETHOD SetVisible(bool visible) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisible(visible); } \
  NS_IMETHOD GetVisible(nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisible(_retval); } \
  NS_IMETHOD SetActive(bool active) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetActive(active); } \
  NS_IMETHOD GetActive(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActive(_retval); } \
  NS_IMETHOD SendMouseEvent(const nsAString & type, uint32_t x, uint32_t y, uint32_t button, uint32_t clickCount, uint32_t mifiers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseEvent(type, x, y, button, clickCount, mifiers); } \
  NS_IMETHOD SendTouchEvent(const nsAString & aType, const uint32_t *aIdentifiers, const int32_t *aXs, const int32_t *aYs, const uint32_t *aRxs, const uint32_t *aRys, const float *aRotationAngles, const float *aForces, uint32_t count, int32_t aModifiers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers); } \
  NS_IMETHOD GoBack(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GoBack(); } \
  NS_IMETHOD GoForward(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GoForward(); } \
  NS_IMETHOD Reload(bool hardReload) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Reload(hardReload); } \
  NS_IMETHOD Stop(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_IMETHOD Download(const nsAString & url, JS::HandleValue options, nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Download(url, options, _retval); } \
  NS_IMETHOD PurgeHistory(nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PurgeHistory(_retval); } \
  NS_IMETHOD GetScreenshot(uint32_t width, uint32_t height, const nsAString & mimeType, nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenshot(width, height, mimeType, _retval); } \
  NS_IMETHOD Zoom(float zoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Zoom(zoom); } \
  NS_IMETHOD GetCanGoBack(nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanGoBack(_retval); } \
  NS_IMETHOD GetCanGoForward(nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanGoForward(_retval); } \
  NS_IMETHOD GetContentDimensions(nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDimensions(_retval); } \
  NS_IMETHOD FindAll(const nsAString & searchString, int32_t caseSensitivity) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindAll(searchString, caseSensitivity); } \
  NS_IMETHOD FindNext(int32_t direction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindNext(direction); } \
  NS_IMETHOD ClearMatch(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearMatch(); } \
  NS_IMETHOD AddNextPaintListener(nsIBrowserElementNextPaintListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddNextPaintListener(listener); } \
  NS_IMETHOD RemoveNextPaintListener(nsIBrowserElementNextPaintListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveNextPaintListener(listener); } \
  NS_IMETHOD SetInputMethodActive(bool isActive, nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInputMethodActive(isActive, _retval); } \
  NS_IMETHOD SetNFCFocus(bool isFocus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNFCFocus(isFocus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserElementAPI : public nsIBrowserElementAPI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERELEMENTAPI

  nsBrowserElementAPI();

private:
  ~nsBrowserElementAPI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsBrowserElementAPI, nsIBrowserElementAPI)

nsBrowserElementAPI::nsBrowserElementAPI()
{
  /* member initializers and constructor code */
}

nsBrowserElementAPI::~nsBrowserElementAPI()
{
  /* destructor code */
}

/* void setFrameLoader (in nsIFrameLoader frameLoader); */
NS_IMETHODIMP nsBrowserElementAPI::SetFrameLoader(nsIFrameLoader *frameLoader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setVisible (in boolean visible); */
NS_IMETHODIMP nsBrowserElementAPI::SetVisible(bool visible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getVisible (); */
NS_IMETHODIMP nsBrowserElementAPI::GetVisible(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setActive (in boolean active); */
NS_IMETHODIMP nsBrowserElementAPI::SetActive(bool active)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getActive (); */
NS_IMETHODIMP nsBrowserElementAPI::GetActive(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendMouseEvent (in DOMString type, in uint32_t x, in uint32_t y, in uint32_t button, in uint32_t clickCount, in uint32_t mifiers); */
NS_IMETHODIMP nsBrowserElementAPI::SendMouseEvent(const nsAString & type, uint32_t x, uint32_t y, uint32_t button, uint32_t clickCount, uint32_t mifiers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendTouchEvent (in DOMString aType, [array, size_is (count), const] in uint32_t aIdentifiers, [array, size_is (count), const] in int32_t aXs, [array, size_is (count), const] in int32_t aYs, [array, size_is (count), const] in uint32_t aRxs, [array, size_is (count), const] in uint32_t aRys, [array, size_is (count), const] in float aRotationAngles, [array, size_is (count), const] in float aForces, in uint32_t count, in long aModifiers); */
NS_IMETHODIMP nsBrowserElementAPI::SendTouchEvent(const nsAString & aType, const uint32_t *aIdentifiers, const int32_t *aXs, const int32_t *aYs, const uint32_t *aRxs, const uint32_t *aRys, const float *aRotationAngles, const float *aForces, uint32_t count, int32_t aModifiers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void goBack (); */
NS_IMETHODIMP nsBrowserElementAPI::GoBack()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void goForward (); */
NS_IMETHODIMP nsBrowserElementAPI::GoForward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reload (in boolean hardReload); */
NS_IMETHODIMP nsBrowserElementAPI::Reload(bool hardReload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsBrowserElementAPI::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest download (in DOMString url, [optional] in jsval options); */
NS_IMETHODIMP nsBrowserElementAPI::Download(const nsAString & url, JS::HandleValue options, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest purgeHistory (); */
NS_IMETHODIMP nsBrowserElementAPI::PurgeHistory(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getScreenshot (in uint32_t width, in uint32_t height, [optional] in DOMString mimeType); */
NS_IMETHODIMP nsBrowserElementAPI::GetScreenshot(uint32_t width, uint32_t height, const nsAString & mimeType, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void zoom (in float zoom); */
NS_IMETHODIMP nsBrowserElementAPI::Zoom(float zoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getCanGoBack (); */
NS_IMETHODIMP nsBrowserElementAPI::GetCanGoBack(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getCanGoForward (); */
NS_IMETHODIMP nsBrowserElementAPI::GetCanGoForward(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getContentDimensions (); */
NS_IMETHODIMP nsBrowserElementAPI::GetContentDimensions(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findAll (in DOMString searchString, in long caseSensitivity); */
NS_IMETHODIMP nsBrowserElementAPI::FindAll(const nsAString & searchString, int32_t caseSensitivity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findNext (in long direction); */
NS_IMETHODIMP nsBrowserElementAPI::FindNext(int32_t direction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearMatch (); */
NS_IMETHODIMP nsBrowserElementAPI::ClearMatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addNextPaintListener (in nsIBrowserElementNextPaintListener listener); */
NS_IMETHODIMP nsBrowserElementAPI::AddNextPaintListener(nsIBrowserElementNextPaintListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeNextPaintListener (in nsIBrowserElementNextPaintListener listener); */
NS_IMETHODIMP nsBrowserElementAPI::RemoveNextPaintListener(nsIBrowserElementNextPaintListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest setInputMethodActive (in boolean isActive); */
NS_IMETHODIMP nsBrowserElementAPI::SetInputMethodActive(bool isActive, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setNFCFocus (in boolean isFocus); */
NS_IMETHODIMP nsBrowserElementAPI::SetNFCFocus(bool isFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserElementAPI_h__ */
