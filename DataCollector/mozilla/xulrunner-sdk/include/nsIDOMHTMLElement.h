/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLElement.idl
 */

#ifndef __gen_nsIDOMHTMLElement_h__
#define __gen_nsIDOMHTMLElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLMenuElement; /* forward declaration */


/* starting interface:    nsIDOMHTMLElement */
#define NS_IDOMHTMLELEMENT_IID_STR "b0c42392-d0e7-4f6a-beb5-a698ce648945"

#define NS_IDOMHTMLELEMENT_IID \
  {0xb0c42392, 0xd0e7, 0x4f6a, \
    { 0xbe, 0xb5, 0xa6, 0x98, 0xce, 0x64, 0x89, 0x45 }}

class NS_NO_VTABLE nsIDOMHTMLElement : public nsIDOMElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLELEMENT_IID)

  /* attribute DOMString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /* attribute DOMString lang; */
  NS_IMETHOD GetLang(nsAString & aLang) = 0;
  NS_IMETHOD SetLang(const nsAString & aLang) = 0;

  /* attribute DOMString dir; */
  NS_IMETHOD GetDir(nsAString & aDir) = 0;
  NS_IMETHOD SetDir(const nsAString & aDir) = 0;

  /* readonly attribute nsISupports dataset; */
  NS_IMETHOD GetDataset(nsISupports * *aDataset) = 0;

  /* attribute boolean itemScope; */
  NS_IMETHOD GetItemScope(bool *aItemScope) = 0;
  NS_IMETHOD SetItemScope(bool aItemScope) = 0;

  /* attribute nsIVariant itemType; */
  NS_IMETHOD GetItemType(nsIVariant * *aItemType) = 0;
  NS_IMETHOD SetItemType(nsIVariant *aItemType) = 0;

  /* attribute DOMString itemId; */
  NS_IMETHOD GetItemId(nsAString & aItemId) = 0;
  NS_IMETHOD SetItemId(const nsAString & aItemId) = 0;

  /* readonly attribute nsISupports properties; */
  NS_IMETHOD GetProperties(nsISupports * *aProperties) = 0;

  /* attribute nsIVariant itemValue; */
  NS_IMETHOD GetItemValue(nsIVariant * *aItemValue) = 0;
  NS_IMETHOD SetItemValue(nsIVariant *aItemValue) = 0;

  /* attribute nsIVariant itemProp; */
  NS_IMETHOD GetItemProp(nsIVariant * *aItemProp) = 0;
  NS_IMETHOD SetItemProp(nsIVariant *aItemProp) = 0;

  /* attribute nsIVariant itemRef; */
  NS_IMETHOD GetItemRef(nsIVariant * *aItemRef) = 0;
  NS_IMETHOD SetItemRef(nsIVariant *aItemRef) = 0;

  /* attribute boolean hidden; */
  NS_IMETHOD GetHidden(bool *aHidden) = 0;
  NS_IMETHOD SetHidden(bool aHidden) = 0;

  /* [binaryname(DOMClick)] void click (); */
  NS_IMETHOD DOMClick(void) = 0;

  /* attribute long tabIndex; */
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) = 0;
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) = 0;

  /* void focus (); */
  NS_IMETHOD Focus(void) = 0;

  /* [binaryname(DOMBlur)] void blur (); */
  NS_IMETHOD DOMBlur(void) = 0;

  /* attribute DOMString accessKey; */
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) = 0;
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) = 0;

  /* readonly attribute DOMString accessKeyLabel; */
  NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) = 0;

  /* attribute boolean draggable; */
  NS_IMETHOD GetDraggable(bool *aDraggable) = 0;
  NS_IMETHOD SetDraggable(bool aDraggable) = 0;

  /* attribute DOMString contentEditable; */
  NS_IMETHOD GetContentEditable(nsAString & aContentEditable) = 0;
  NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) = 0;

  /* readonly attribute boolean isContentEditable; */
  NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) = 0;

  /* readonly attribute nsIDOMHTMLMenuElement contextMenu; */
  NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) = 0;

  /* attribute boolean spellcheck; */
  NS_IMETHOD GetSpellcheck(bool *aSpellcheck) = 0;
  NS_IMETHOD SetSpellcheck(bool aSpellcheck) = 0;

  /* attribute DOMString innerHTML; */
  NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) = 0;
  NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) = 0;

  /* attribute DOMString outerHTML; */
  NS_IMETHOD GetOuterHTML(nsAString & aOuterHTML) = 0;
  NS_IMETHOD SetOuterHTML(const nsAString & aOuterHTML) = 0;

  /* void insertAdjacentHTML (in DOMString position, in DOMString text); */
  NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) = 0;

  /* [optional_argc] void scrollIntoView ([optional] in boolean top); */
  NS_IMETHOD ScrollIntoView(bool top, uint8_t _argc) = 0;

  /* readonly attribute nsIDOMElement offsetParent; */
  NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) = 0;

  /* readonly attribute long offsetTop; */
  NS_IMETHOD GetOffsetTop(int32_t *aOffsetTop) = 0;

  /* readonly attribute long offsetLeft; */
  NS_IMETHOD GetOffsetLeft(int32_t *aOffsetLeft) = 0;

  /* readonly attribute long offsetWidth; */
  NS_IMETHOD GetOffsetWidth(int32_t *aOffsetWidth) = 0;

  /* readonly attribute long offsetHeight; */
  NS_IMETHOD GetOffsetHeight(int32_t *aOffsetHeight) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLElement, NS_IDOMHTMLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLELEMENT \
  NS_IMETHOD GetTitle(nsAString & aTitle) override; \
  NS_IMETHOD SetTitle(const nsAString & aTitle) override; \
  NS_IMETHOD GetLang(nsAString & aLang) override; \
  NS_IMETHOD SetLang(const nsAString & aLang) override; \
  NS_IMETHOD GetDir(nsAString & aDir) override; \
  NS_IMETHOD SetDir(const nsAString & aDir) override; \
  NS_IMETHOD GetDataset(nsISupports * *aDataset) override; \
  NS_IMETHOD GetItemScope(bool *aItemScope) override; \
  NS_IMETHOD SetItemScope(bool aItemScope) override; \
  NS_IMETHOD GetItemType(nsIVariant * *aItemType) override; \
  NS_IMETHOD SetItemType(nsIVariant *aItemType) override; \
  NS_IMETHOD GetItemId(nsAString & aItemId) override; \
  NS_IMETHOD SetItemId(const nsAString & aItemId) override; \
  NS_IMETHOD GetProperties(nsISupports * *aProperties) override; \
  NS_IMETHOD GetItemValue(nsIVariant * *aItemValue) override; \
  NS_IMETHOD SetItemValue(nsIVariant *aItemValue) override; \
  NS_IMETHOD GetItemProp(nsIVariant * *aItemProp) override; \
  NS_IMETHOD SetItemProp(nsIVariant *aItemProp) override; \
  NS_IMETHOD GetItemRef(nsIVariant * *aItemRef) override; \
  NS_IMETHOD SetItemRef(nsIVariant *aItemRef) override; \
  NS_IMETHOD GetHidden(bool *aHidden) override; \
  NS_IMETHOD SetHidden(bool aHidden) override; \
  NS_IMETHOD DOMClick(void) override; \
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) override; \
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) override; \
  NS_IMETHOD Focus(void) override; \
  NS_IMETHOD DOMBlur(void) override; \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) override; \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) override; \
  NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) override; \
  NS_IMETHOD GetDraggable(bool *aDraggable) override; \
  NS_IMETHOD SetDraggable(bool aDraggable) override; \
  NS_IMETHOD GetContentEditable(nsAString & aContentEditable) override; \
  NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) override; \
  NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) override; \
  NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) override; \
  NS_IMETHOD GetSpellcheck(bool *aSpellcheck) override; \
  NS_IMETHOD SetSpellcheck(bool aSpellcheck) override; \
  NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) override; \
  NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) override; \
  NS_IMETHOD GetOuterHTML(nsAString & aOuterHTML) override; \
  NS_IMETHOD SetOuterHTML(const nsAString & aOuterHTML) override; \
  NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) override; \
  NS_IMETHOD ScrollIntoView(bool top, uint8_t _argc) override; \
  NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) override; \
  NS_IMETHOD GetOffsetTop(int32_t *aOffsetTop) override; \
  NS_IMETHOD GetOffsetLeft(int32_t *aOffsetLeft) override; \
  NS_IMETHOD GetOffsetWidth(int32_t *aOffsetWidth) override; \
  NS_IMETHOD GetOffsetHeight(int32_t *aOffsetHeight) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLELEMENT(_to) \
  NS_IMETHOD GetTitle(nsAString & aTitle) override { return _to GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) override { return _to SetTitle(aTitle); } \
  NS_IMETHOD GetLang(nsAString & aLang) override { return _to GetLang(aLang); } \
  NS_IMETHOD SetLang(const nsAString & aLang) override { return _to SetLang(aLang); } \
  NS_IMETHOD GetDir(nsAString & aDir) override { return _to GetDir(aDir); } \
  NS_IMETHOD SetDir(const nsAString & aDir) override { return _to SetDir(aDir); } \
  NS_IMETHOD GetDataset(nsISupports * *aDataset) override { return _to GetDataset(aDataset); } \
  NS_IMETHOD GetItemScope(bool *aItemScope) override { return _to GetItemScope(aItemScope); } \
  NS_IMETHOD SetItemScope(bool aItemScope) override { return _to SetItemScope(aItemScope); } \
  NS_IMETHOD GetItemType(nsIVariant * *aItemType) override { return _to GetItemType(aItemType); } \
  NS_IMETHOD SetItemType(nsIVariant *aItemType) override { return _to SetItemType(aItemType); } \
  NS_IMETHOD GetItemId(nsAString & aItemId) override { return _to GetItemId(aItemId); } \
  NS_IMETHOD SetItemId(const nsAString & aItemId) override { return _to SetItemId(aItemId); } \
  NS_IMETHOD GetProperties(nsISupports * *aProperties) override { return _to GetProperties(aProperties); } \
  NS_IMETHOD GetItemValue(nsIVariant * *aItemValue) override { return _to GetItemValue(aItemValue); } \
  NS_IMETHOD SetItemValue(nsIVariant *aItemValue) override { return _to SetItemValue(aItemValue); } \
  NS_IMETHOD GetItemProp(nsIVariant * *aItemProp) override { return _to GetItemProp(aItemProp); } \
  NS_IMETHOD SetItemProp(nsIVariant *aItemProp) override { return _to SetItemProp(aItemProp); } \
  NS_IMETHOD GetItemRef(nsIVariant * *aItemRef) override { return _to GetItemRef(aItemRef); } \
  NS_IMETHOD SetItemRef(nsIVariant *aItemRef) override { return _to SetItemRef(aItemRef); } \
  NS_IMETHOD GetHidden(bool *aHidden) override { return _to GetHidden(aHidden); } \
  NS_IMETHOD SetHidden(bool aHidden) override { return _to SetHidden(aHidden); } \
  NS_IMETHOD DOMClick(void) override { return _to DOMClick(); } \
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) override { return _to GetTabIndex(aTabIndex); } \
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) override { return _to SetTabIndex(aTabIndex); } \
  NS_IMETHOD Focus(void) override { return _to Focus(); } \
  NS_IMETHOD DOMBlur(void) override { return _to DOMBlur(); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) override { return _to GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) override { return _to SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) override { return _to GetAccessKeyLabel(aAccessKeyLabel); } \
  NS_IMETHOD GetDraggable(bool *aDraggable) override { return _to GetDraggable(aDraggable); } \
  NS_IMETHOD SetDraggable(bool aDraggable) override { return _to SetDraggable(aDraggable); } \
  NS_IMETHOD GetContentEditable(nsAString & aContentEditable) override { return _to GetContentEditable(aContentEditable); } \
  NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) override { return _to SetContentEditable(aContentEditable); } \
  NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) override { return _to GetIsContentEditable(aIsContentEditable); } \
  NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) override { return _to GetContextMenu(aContextMenu); } \
  NS_IMETHOD GetSpellcheck(bool *aSpellcheck) override { return _to GetSpellcheck(aSpellcheck); } \
  NS_IMETHOD SetSpellcheck(bool aSpellcheck) override { return _to SetSpellcheck(aSpellcheck); } \
  NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) override { return _to GetInnerHTML(aInnerHTML); } \
  NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) override { return _to SetInnerHTML(aInnerHTML); } \
  NS_IMETHOD GetOuterHTML(nsAString & aOuterHTML) override { return _to GetOuterHTML(aOuterHTML); } \
  NS_IMETHOD SetOuterHTML(const nsAString & aOuterHTML) override { return _to SetOuterHTML(aOuterHTML); } \
  NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) override { return _to InsertAdjacentHTML(position, text); } \
  NS_IMETHOD ScrollIntoView(bool top, uint8_t _argc) override { return _to ScrollIntoView(top, _argc); } \
  NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) override { return _to GetOffsetParent(aOffsetParent); } \
  NS_IMETHOD GetOffsetTop(int32_t *aOffsetTop) override { return _to GetOffsetTop(aOffsetTop); } \
  NS_IMETHOD GetOffsetLeft(int32_t *aOffsetLeft) override { return _to GetOffsetLeft(aOffsetLeft); } \
  NS_IMETHOD GetOffsetWidth(int32_t *aOffsetWidth) override { return _to GetOffsetWidth(aOffsetWidth); } \
  NS_IMETHOD GetOffsetHeight(int32_t *aOffsetHeight) override { return _to GetOffsetHeight(aOffsetHeight); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLELEMENT(_to) \
  NS_IMETHOD GetTitle(nsAString & aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const nsAString & aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_IMETHOD GetLang(nsAString & aLang) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLang(aLang); } \
  NS_IMETHOD SetLang(const nsAString & aLang) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLang(aLang); } \
  NS_IMETHOD GetDir(nsAString & aDir) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDir(aDir); } \
  NS_IMETHOD SetDir(const nsAString & aDir) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDir(aDir); } \
  NS_IMETHOD GetDataset(nsISupports * *aDataset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataset(aDataset); } \
  NS_IMETHOD GetItemScope(bool *aItemScope) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemScope(aItemScope); } \
  NS_IMETHOD SetItemScope(bool aItemScope) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemScope(aItemScope); } \
  NS_IMETHOD GetItemType(nsIVariant * *aItemType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemType(aItemType); } \
  NS_IMETHOD SetItemType(nsIVariant *aItemType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemType(aItemType); } \
  NS_IMETHOD GetItemId(nsAString & aItemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemId(aItemId); } \
  NS_IMETHOD SetItemId(const nsAString & aItemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemId(aItemId); } \
  NS_IMETHOD GetProperties(nsISupports * *aProperties) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperties(aProperties); } \
  NS_IMETHOD GetItemValue(nsIVariant * *aItemValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemValue(aItemValue); } \
  NS_IMETHOD SetItemValue(nsIVariant *aItemValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemValue(aItemValue); } \
  NS_IMETHOD GetItemProp(nsIVariant * *aItemProp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemProp(aItemProp); } \
  NS_IMETHOD SetItemProp(nsIVariant *aItemProp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemProp(aItemProp); } \
  NS_IMETHOD GetItemRef(nsIVariant * *aItemRef) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemRef(aItemRef); } \
  NS_IMETHOD SetItemRef(nsIVariant *aItemRef) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemRef(aItemRef); } \
  NS_IMETHOD GetHidden(bool *aHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHidden(aHidden); } \
  NS_IMETHOD SetHidden(bool aHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHidden(aHidden); } \
  NS_IMETHOD DOMClick(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DOMClick(); } \
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabIndex(aTabIndex); } \
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabIndex(aTabIndex); } \
  NS_IMETHOD Focus(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_IMETHOD DOMBlur(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DOMBlur(); } \
  NS_IMETHOD GetAccessKey(nsAString & aAccessKey) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccessKey(aAccessKey); } \
  NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKeyLabel(aAccessKeyLabel); } \
  NS_IMETHOD GetDraggable(bool *aDraggable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDraggable(aDraggable); } \
  NS_IMETHOD SetDraggable(bool aDraggable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDraggable(aDraggable); } \
  NS_IMETHOD GetContentEditable(nsAString & aContentEditable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentEditable(aContentEditable); } \
  NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentEditable(aContentEditable); } \
  NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsContentEditable(aIsContentEditable); } \
  NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContextMenu(aContextMenu); } \
  NS_IMETHOD GetSpellcheck(bool *aSpellcheck) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpellcheck(aSpellcheck); } \
  NS_IMETHOD SetSpellcheck(bool aSpellcheck) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpellcheck(aSpellcheck); } \
  NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerHTML(aInnerHTML); } \
  NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInnerHTML(aInnerHTML); } \
  NS_IMETHOD GetOuterHTML(nsAString & aOuterHTML) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterHTML(aOuterHTML); } \
  NS_IMETHOD SetOuterHTML(const nsAString & aOuterHTML) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOuterHTML(aOuterHTML); } \
  NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertAdjacentHTML(position, text); } \
  NS_IMETHOD ScrollIntoView(bool top, uint8_t _argc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollIntoView(top, _argc); } \
  NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetParent(aOffsetParent); } \
  NS_IMETHOD GetOffsetTop(int32_t *aOffsetTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetTop(aOffsetTop); } \
  NS_IMETHOD GetOffsetLeft(int32_t *aOffsetLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetLeft(aOffsetLeft); } \
  NS_IMETHOD GetOffsetWidth(int32_t *aOffsetWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetWidth(aOffsetWidth); } \
  NS_IMETHOD GetOffsetHeight(int32_t *aOffsetHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetHeight(aOffsetHeight); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLElement : public nsIDOMHTMLElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLELEMENT

  nsDOMHTMLElement();

private:
  ~nsDOMHTMLElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMHTMLElement, nsIDOMHTMLElement)

nsDOMHTMLElement::nsDOMHTMLElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLElement::~nsDOMHTMLElement()
{
  /* destructor code */
}

/* attribute DOMString title; */
NS_IMETHODIMP nsDOMHTMLElement::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString lang; */
NS_IMETHODIMP nsDOMHTMLElement::GetLang(nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetLang(const nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString dir; */
NS_IMETHODIMP nsDOMHTMLElement::GetDir(nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetDir(const nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports dataset; */
NS_IMETHODIMP nsDOMHTMLElement::GetDataset(nsISupports * *aDataset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean itemScope; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemScope(bool *aItemScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemScope(bool aItemScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant itemType; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemType(nsIVariant * *aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemType(nsIVariant *aItemType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString itemId; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemId(nsAString & aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemId(const nsAString & aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports properties; */
NS_IMETHODIMP nsDOMHTMLElement::GetProperties(nsISupports * *aProperties)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant itemValue; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemValue(nsIVariant * *aItemValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemValue(nsIVariant *aItemValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant itemProp; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemProp(nsIVariant * *aItemProp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemProp(nsIVariant *aItemProp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant itemRef; */
NS_IMETHODIMP nsDOMHTMLElement::GetItemRef(nsIVariant * *aItemRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetItemRef(nsIVariant *aItemRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hidden; */
NS_IMETHODIMP nsDOMHTMLElement::GetHidden(bool *aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetHidden(bool aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMClick)] void click (); */
NS_IMETHODIMP nsDOMHTMLElement::DOMClick()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long tabIndex; */
NS_IMETHODIMP nsDOMHTMLElement::GetTabIndex(int32_t *aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetTabIndex(int32_t aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMHTMLElement::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(DOMBlur)] void blur (); */
NS_IMETHODIMP nsDOMHTMLElement::DOMBlur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString accessKey; */
NS_IMETHODIMP nsDOMHTMLElement::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetAccessKey(const nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString accessKeyLabel; */
NS_IMETHODIMP nsDOMHTMLElement::GetAccessKeyLabel(nsAString & aAccessKeyLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean draggable; */
NS_IMETHODIMP nsDOMHTMLElement::GetDraggable(bool *aDraggable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetDraggable(bool aDraggable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString contentEditable; */
NS_IMETHODIMP nsDOMHTMLElement::GetContentEditable(nsAString & aContentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetContentEditable(const nsAString & aContentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isContentEditable; */
NS_IMETHODIMP nsDOMHTMLElement::GetIsContentEditable(bool *aIsContentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLMenuElement contextMenu; */
NS_IMETHODIMP nsDOMHTMLElement::GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean spellcheck; */
NS_IMETHODIMP nsDOMHTMLElement::GetSpellcheck(bool *aSpellcheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetSpellcheck(bool aSpellcheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString innerHTML; */
NS_IMETHODIMP nsDOMHTMLElement::GetInnerHTML(nsAString & aInnerHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetInnerHTML(const nsAString & aInnerHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString outerHTML; */
NS_IMETHODIMP nsDOMHTMLElement::GetOuterHTML(nsAString & aOuterHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetOuterHTML(const nsAString & aOuterHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertAdjacentHTML (in DOMString position, in DOMString text); */
NS_IMETHODIMP nsDOMHTMLElement::InsertAdjacentHTML(const nsAString & position, const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void scrollIntoView ([optional] in boolean top); */
NS_IMETHODIMP nsDOMHTMLElement::ScrollIntoView(bool top, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement offsetParent; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetParent(nsIDOMElement * *aOffsetParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetTop; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetTop(int32_t *aOffsetTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetLeft; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetLeft(int32_t *aOffsetLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetWidth; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetWidth(int32_t *aOffsetWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetHeight; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetHeight(int32_t *aOffsetHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLElement_h__ */
