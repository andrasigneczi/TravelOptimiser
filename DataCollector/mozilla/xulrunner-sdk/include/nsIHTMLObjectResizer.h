/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHTMLObjectResizer.idl
 */

#ifndef __gen_nsIHTMLObjectResizer_h__
#define __gen_nsIHTMLObjectResizer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHTMLObjectResizeListener; /* forward declaration */


/* starting interface:    nsIHTMLObjectResizer */
#define NS_IHTMLOBJECTRESIZER_IID_STR "8b396020-69d3-451f-80c1-1a96a7da25a9"

#define NS_IHTMLOBJECTRESIZER_IID \
  {0x8b396020, 0x69d3, 0x451f, \
    { 0x80, 0xc1, 0x1a, 0x96, 0xa7, 0xda, 0x25, 0xa9 }}

class nsIHTMLObjectResizer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLOBJECTRESIZER_IID)

   typedef short EResizerLocation;
  enum {
    eTopLeft = 0,
    eTop = 1,
    eTopRight = 2,
    eLeft = 3,
    eRight = 4,
    eBottomLeft = 5,
    eBottom = 6,
    eBottomRight = 7
  };

  /* readonly attribute nsIDOMElement resizedObject; */
  NS_IMETHOD GetResizedObject(nsIDOMElement * *aResizedObject) = 0;

  /* attribute boolean objectResizingEnabled; */
  NS_IMETHOD GetObjectResizingEnabled(bool *aObjectResizingEnabled) = 0;
  NS_IMETHOD SetObjectResizingEnabled(bool aObjectResizingEnabled) = 0;

  /* void showResizers (in nsIDOMElement aResizedElement); */
  NS_IMETHOD ShowResizers(nsIDOMElement *aResizedElement) = 0;

  /* void hideResizers (); */
  NS_IMETHOD HideResizers(void) = 0;

  /* void refreshResizers (); */
  NS_IMETHOD RefreshResizers(void) = 0;

  /* void mouseDown (in long aX, in long aY, in nsIDOMElement aTarget, in nsIDOMEvent aMouseEvent); */
  NS_IMETHOD MouseDown(int32_t aX, int32_t aY, nsIDOMElement *aTarget, nsIDOMEvent *aMouseEvent) = 0;

  /* void mouseUp (in long aX, in long aY, in nsIDOMElement aTarget); */
  NS_IMETHOD MouseUp(int32_t aX, int32_t aY, nsIDOMElement *aTarget) = 0;

  /* void mouseMove (in nsIDOMEvent aMouseEvent); */
  NS_IMETHOD MouseMove(nsIDOMEvent *aMouseEvent) = 0;

  /* void addObjectResizeEventListener (in nsIHTMLObjectResizeListener aListener); */
  NS_IMETHOD AddObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener) = 0;

  /* void removeObjectResizeEventListener (in nsIHTMLObjectResizeListener aListener); */
  NS_IMETHOD RemoveObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLObjectResizer, NS_IHTMLOBJECTRESIZER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLOBJECTRESIZER \
  NS_IMETHOD GetResizedObject(nsIDOMElement * *aResizedObject) override; \
  NS_IMETHOD GetObjectResizingEnabled(bool *aObjectResizingEnabled) override; \
  NS_IMETHOD SetObjectResizingEnabled(bool aObjectResizingEnabled) override; \
  NS_IMETHOD ShowResizers(nsIDOMElement *aResizedElement) override; \
  NS_IMETHOD HideResizers(void) override; \
  NS_IMETHOD RefreshResizers(void) override; \
  NS_IMETHOD MouseDown(int32_t aX, int32_t aY, nsIDOMElement *aTarget, nsIDOMEvent *aMouseEvent) override; \
  NS_IMETHOD MouseUp(int32_t aX, int32_t aY, nsIDOMElement *aTarget) override; \
  NS_IMETHOD MouseMove(nsIDOMEvent *aMouseEvent) override; \
  NS_IMETHOD AddObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener) override; \
  NS_IMETHOD RemoveObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLOBJECTRESIZER(_to) \
  NS_IMETHOD GetResizedObject(nsIDOMElement * *aResizedObject) override { return _to GetResizedObject(aResizedObject); } \
  NS_IMETHOD GetObjectResizingEnabled(bool *aObjectResizingEnabled) override { return _to GetObjectResizingEnabled(aObjectResizingEnabled); } \
  NS_IMETHOD SetObjectResizingEnabled(bool aObjectResizingEnabled) override { return _to SetObjectResizingEnabled(aObjectResizingEnabled); } \
  NS_IMETHOD ShowResizers(nsIDOMElement *aResizedElement) override { return _to ShowResizers(aResizedElement); } \
  NS_IMETHOD HideResizers(void) override { return _to HideResizers(); } \
  NS_IMETHOD RefreshResizers(void) override { return _to RefreshResizers(); } \
  NS_IMETHOD MouseDown(int32_t aX, int32_t aY, nsIDOMElement *aTarget, nsIDOMEvent *aMouseEvent) override { return _to MouseDown(aX, aY, aTarget, aMouseEvent); } \
  NS_IMETHOD MouseUp(int32_t aX, int32_t aY, nsIDOMElement *aTarget) override { return _to MouseUp(aX, aY, aTarget); } \
  NS_IMETHOD MouseMove(nsIDOMEvent *aMouseEvent) override { return _to MouseMove(aMouseEvent); } \
  NS_IMETHOD AddObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener) override { return _to AddObjectResizeEventListener(aListener); } \
  NS_IMETHOD RemoveObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener) override { return _to RemoveObjectResizeEventListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLOBJECTRESIZER(_to) \
  NS_IMETHOD GetResizedObject(nsIDOMElement * *aResizedObject) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResizedObject(aResizedObject); } \
  NS_IMETHOD GetObjectResizingEnabled(bool *aObjectResizingEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectResizingEnabled(aObjectResizingEnabled); } \
  NS_IMETHOD SetObjectResizingEnabled(bool aObjectResizingEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObjectResizingEnabled(aObjectResizingEnabled); } \
  NS_IMETHOD ShowResizers(nsIDOMElement *aResizedElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowResizers(aResizedElement); } \
  NS_IMETHOD HideResizers(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HideResizers(); } \
  NS_IMETHOD RefreshResizers(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshResizers(); } \
  NS_IMETHOD MouseDown(int32_t aX, int32_t aY, nsIDOMElement *aTarget, nsIDOMEvent *aMouseEvent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MouseDown(aX, aY, aTarget, aMouseEvent); } \
  NS_IMETHOD MouseUp(int32_t aX, int32_t aY, nsIDOMElement *aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MouseUp(aX, aY, aTarget); } \
  NS_IMETHOD MouseMove(nsIDOMEvent *aMouseEvent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MouseMove(aMouseEvent); } \
  NS_IMETHOD AddObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObjectResizeEventListener(aListener); } \
  NS_IMETHOD RemoveObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObjectResizeEventListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLObjectResizer : public nsIHTMLObjectResizer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLOBJECTRESIZER

  nsHTMLObjectResizer();

private:
  ~nsHTMLObjectResizer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsHTMLObjectResizer, nsIHTMLObjectResizer)

nsHTMLObjectResizer::nsHTMLObjectResizer()
{
  /* member initializers and constructor code */
}

nsHTMLObjectResizer::~nsHTMLObjectResizer()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement resizedObject; */
NS_IMETHODIMP nsHTMLObjectResizer::GetResizedObject(nsIDOMElement * *aResizedObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean objectResizingEnabled; */
NS_IMETHODIMP nsHTMLObjectResizer::GetObjectResizingEnabled(bool *aObjectResizingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHTMLObjectResizer::SetObjectResizingEnabled(bool aObjectResizingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showResizers (in nsIDOMElement aResizedElement); */
NS_IMETHODIMP nsHTMLObjectResizer::ShowResizers(nsIDOMElement *aResizedElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hideResizers (); */
NS_IMETHODIMP nsHTMLObjectResizer::HideResizers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshResizers (); */
NS_IMETHODIMP nsHTMLObjectResizer::RefreshResizers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mouseDown (in long aX, in long aY, in nsIDOMElement aTarget, in nsIDOMEvent aMouseEvent); */
NS_IMETHODIMP nsHTMLObjectResizer::MouseDown(int32_t aX, int32_t aY, nsIDOMElement *aTarget, nsIDOMEvent *aMouseEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mouseUp (in long aX, in long aY, in nsIDOMElement aTarget); */
NS_IMETHODIMP nsHTMLObjectResizer::MouseUp(int32_t aX, int32_t aY, nsIDOMElement *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mouseMove (in nsIDOMEvent aMouseEvent); */
NS_IMETHODIMP nsHTMLObjectResizer::MouseMove(nsIDOMEvent *aMouseEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObjectResizeEventListener (in nsIHTMLObjectResizeListener aListener); */
NS_IMETHODIMP nsHTMLObjectResizer::AddObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObjectResizeEventListener (in nsIHTMLObjectResizeListener aListener); */
NS_IMETHODIMP nsHTMLObjectResizer::RemoveObjectResizeEventListener(nsIHTMLObjectResizeListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLObjectResizer_h__ */
