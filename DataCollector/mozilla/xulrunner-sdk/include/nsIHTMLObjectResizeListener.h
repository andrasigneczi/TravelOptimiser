/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHTMLObjectResizeListener.idl
 */

#ifndef __gen_nsIHTMLObjectResizeListener_h__
#define __gen_nsIHTMLObjectResizeListener_h__


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

/* starting interface:    nsIHTMLObjectResizeListener */
#define NS_IHTMLOBJECTRESIZELISTENER_IID_STR "27b00295-349c-429f-ad0c-87b859e77130"

#define NS_IHTMLOBJECTRESIZELISTENER_IID \
  {0x27b00295, 0x349c, 0x429f, \
    { 0xad, 0x0c, 0x87, 0xb8, 0x59, 0xe7, 0x71, 0x30 }}

class NS_NO_VTABLE nsIHTMLObjectResizeListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLOBJECTRESIZELISTENER_IID)

  /* void onStartResizing (in nsIDOMElement aElement); */
  NS_IMETHOD OnStartResizing(nsIDOMElement *aElement) = 0;

  /* void onEndResizing (in nsIDOMElement aElement, in long aOldWidth, in long aOldHeight, in long aNewWidth, in long aNewHeight); */
  NS_IMETHOD OnEndResizing(nsIDOMElement *aElement, int32_t aOldWidth, int32_t aOldHeight, int32_t aNewWidth, int32_t aNewHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLObjectResizeListener, NS_IHTMLOBJECTRESIZELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLOBJECTRESIZELISTENER \
  NS_IMETHOD OnStartResizing(nsIDOMElement *aElement) override; \
  NS_IMETHOD OnEndResizing(nsIDOMElement *aElement, int32_t aOldWidth, int32_t aOldHeight, int32_t aNewWidth, int32_t aNewHeight) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLOBJECTRESIZELISTENER(_to) \
  NS_IMETHOD OnStartResizing(nsIDOMElement *aElement) override { return _to OnStartResizing(aElement); } \
  NS_IMETHOD OnEndResizing(nsIDOMElement *aElement, int32_t aOldWidth, int32_t aOldHeight, int32_t aNewWidth, int32_t aNewHeight) override { return _to OnEndResizing(aElement, aOldWidth, aOldHeight, aNewWidth, aNewHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLOBJECTRESIZELISTENER(_to) \
  NS_IMETHOD OnStartResizing(nsIDOMElement *aElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStartResizing(aElement); } \
  NS_IMETHOD OnEndResizing(nsIDOMElement *aElement, int32_t aOldWidth, int32_t aOldHeight, int32_t aNewWidth, int32_t aNewHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnEndResizing(aElement, aOldWidth, aOldHeight, aNewWidth, aNewHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLObjectResizeListener : public nsIHTMLObjectResizeListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLOBJECTRESIZELISTENER

  nsHTMLObjectResizeListener();

private:
  ~nsHTMLObjectResizeListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsHTMLObjectResizeListener, nsIHTMLObjectResizeListener)

nsHTMLObjectResizeListener::nsHTMLObjectResizeListener()
{
  /* member initializers and constructor code */
}

nsHTMLObjectResizeListener::~nsHTMLObjectResizeListener()
{
  /* destructor code */
}

/* void onStartResizing (in nsIDOMElement aElement); */
NS_IMETHODIMP nsHTMLObjectResizeListener::OnStartResizing(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onEndResizing (in nsIDOMElement aElement, in long aOldWidth, in long aOldHeight, in long aNewWidth, in long aNewHeight); */
NS_IMETHODIMP nsHTMLObjectResizeListener::OnEndResizing(nsIDOMElement *aElement, int32_t aOldWidth, int32_t aOldHeight, int32_t aNewWidth, int32_t aNewHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLObjectResizeListener_h__ */
