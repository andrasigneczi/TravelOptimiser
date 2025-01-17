/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXULPopupElement.idl
 */

#ifndef __gen_nsIDOMXULPopupElement_h__
#define __gen_nsIDOMXULPopupElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULPopupElement */
#define NS_IDOMXULPOPUPELEMENT_IID_STR "cb7eaa79-45d5-4ea3-ae17-b65fdcfe5e30"

#define NS_IDOMXULPOPUPELEMENT_IID \
  {0xcb7eaa79, 0x45d5, 0x4ea3, \
    { 0xae, 0x17, 0xb6, 0x5f, 0xdc, 0xfe, 0x5e, 0x30 }}

class NS_NO_VTABLE nsIDOMXULPopupElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULPOPUPELEMENT_IID)

  enum {
    BEFORE_START = 1U,
    BEFORE_END = 2U,
    AFTER_START = 3U,
    AFTER_END = 4U,
    START_BEFORE = 5U,
    START_AFTER = 6U,
    END_BEFORE = 7U,
    END_AFTER = 8U,
    OVERLAP = 9U,
    AT_POINTER = 10U,
    AFTER_POINTER = 11U
  };

  /* attribute DOMString position; */
  NS_IMETHOD GetPosition(nsAString & aPosition) = 0;
  NS_IMETHOD SetPosition(const nsAString & aPosition) = 0;

  /* void showPopup (in unsigned short alignment, in nsIDOMElement target, in nsIDOMElement anchor); */
  NS_IMETHOD ShowPopup(uint16_t alignment, nsIDOMElement *target, nsIDOMElement *anchor) = 0;

  /* void hidePopup (); */
  NS_IMETHOD HidePopup(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULPopupElement, NS_IDOMXULPOPUPELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULPOPUPELEMENT \
  NS_IMETHOD GetPosition(nsAString & aPosition) override; \
  NS_IMETHOD SetPosition(const nsAString & aPosition) override; \
  NS_IMETHOD ShowPopup(uint16_t alignment, nsIDOMElement *target, nsIDOMElement *anchor) override; \
  NS_IMETHOD HidePopup(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULPOPUPELEMENT(_to) \
  NS_IMETHOD GetPosition(nsAString & aPosition) override { return _to GetPosition(aPosition); } \
  NS_IMETHOD SetPosition(const nsAString & aPosition) override { return _to SetPosition(aPosition); } \
  NS_IMETHOD ShowPopup(uint16_t alignment, nsIDOMElement *target, nsIDOMElement *anchor) override { return _to ShowPopup(alignment, target, anchor); } \
  NS_IMETHOD HidePopup(void) override { return _to HidePopup(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULPOPUPELEMENT(_to) \
  NS_IMETHOD GetPosition(nsAString & aPosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPosition(aPosition); } \
  NS_IMETHOD SetPosition(const nsAString & aPosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPosition(aPosition); } \
  NS_IMETHOD ShowPopup(uint16_t alignment, nsIDOMElement *target, nsIDOMElement *anchor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPopup(alignment, target, anchor); } \
  NS_IMETHOD HidePopup(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HidePopup(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULPopupElement : public nsIDOMXULPopupElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULPOPUPELEMENT

  nsDOMXULPopupElement();

private:
  ~nsDOMXULPopupElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMXULPopupElement, nsIDOMXULPopupElement)

nsDOMXULPopupElement::nsDOMXULPopupElement()
{
  /* member initializers and constructor code */
}

nsDOMXULPopupElement::~nsDOMXULPopupElement()
{
  /* destructor code */
}

/* attribute DOMString position; */
NS_IMETHODIMP nsDOMXULPopupElement::GetPosition(nsAString & aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULPopupElement::SetPosition(const nsAString & aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showPopup (in unsigned short alignment, in nsIDOMElement target, in nsIDOMElement anchor); */
NS_IMETHODIMP nsDOMXULPopupElement::ShowPopup(uint16_t alignment, nsIDOMElement *target, nsIDOMElement *anchor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hidePopup (); */
NS_IMETHODIMP nsDOMXULPopupElement::HidePopup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULPopupElement_h__ */
