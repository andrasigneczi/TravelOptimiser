/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXULElement.idl
 */

#ifndef __gen_nsIDOMXULElement_h__
#define __gen_nsIDOMXULElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRDFCompositeDataSource; /* forward declaration */

class nsIXULTemplateBuilder; /* forward declaration */

class nsIRDFResource; /* forward declaration */

class nsIControllers; /* forward declaration */

class nsIBoxObject; /* forward declaration */


/* starting interface:    nsIDOMXULElement */
#define NS_IDOMXULELEMENT_IID_STR "75435ab3-6863-42a1-ade3-025393d9e80e"

#define NS_IDOMXULELEMENT_IID \
  {0x75435ab3, 0x6863, 0x42a1, \
    { 0xad, 0xe3, 0x02, 0x53, 0x93, 0xd9, 0xe8, 0x0e }}

class NS_NO_VTABLE nsIDOMXULElement : public nsIDOMElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULELEMENT_IID)

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

  /* attribute DOMString dir; */
  NS_IMETHOD GetDir(nsAString & aDir) = 0;
  NS_IMETHOD SetDir(const nsAString & aDir) = 0;

  /* attribute DOMString flex; */
  NS_IMETHOD GetFlex(nsAString & aFlex) = 0;
  NS_IMETHOD SetFlex(const nsAString & aFlex) = 0;

  /* attribute DOMString flexGroup; */
  NS_IMETHOD GetFlexGroup(nsAString & aFlexGroup) = 0;
  NS_IMETHOD SetFlexGroup(const nsAString & aFlexGroup) = 0;

  /* attribute DOMString ordinal; */
  NS_IMETHOD GetOrdinal(nsAString & aOrdinal) = 0;
  NS_IMETHOD SetOrdinal(const nsAString & aOrdinal) = 0;

  /* attribute DOMString orient; */
  NS_IMETHOD GetOrient(nsAString & aOrient) = 0;
  NS_IMETHOD SetOrient(const nsAString & aOrient) = 0;

  /* attribute DOMString pack; */
  NS_IMETHOD GetPack(nsAString & aPack) = 0;
  NS_IMETHOD SetPack(const nsAString & aPack) = 0;

  /* attribute boolean hidden; */
  NS_IMETHOD GetHidden(bool *aHidden) = 0;
  NS_IMETHOD SetHidden(bool aHidden) = 0;

  /* attribute boolean collapsed; */
  NS_IMETHOD GetCollapsed(bool *aCollapsed) = 0;
  NS_IMETHOD SetCollapsed(bool aCollapsed) = 0;

  /* attribute DOMString observes; */
  NS_IMETHOD GetObserves(nsAString & aObserves) = 0;
  NS_IMETHOD SetObserves(const nsAString & aObserves) = 0;

  /* attribute DOMString menu; */
  NS_IMETHOD GetMenu(nsAString & aMenu) = 0;
  NS_IMETHOD SetMenu(const nsAString & aMenu) = 0;

  /* attribute DOMString contextMenu; */
  NS_IMETHOD GetContextMenu(nsAString & aContextMenu) = 0;
  NS_IMETHOD SetContextMenu(const nsAString & aContextMenu) = 0;

  /* attribute DOMString tooltip; */
  NS_IMETHOD GetTooltip(nsAString & aTooltip) = 0;
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) = 0;

  /* attribute DOMString width; */
  NS_IMETHOD GetWidth(nsAString & aWidth) = 0;
  NS_IMETHOD SetWidth(const nsAString & aWidth) = 0;

  /* attribute DOMString height; */
  NS_IMETHOD GetHeight(nsAString & aHeight) = 0;
  NS_IMETHOD SetHeight(const nsAString & aHeight) = 0;

  /* attribute DOMString minWidth; */
  NS_IMETHOD GetMinWidth(nsAString & aMinWidth) = 0;
  NS_IMETHOD SetMinWidth(const nsAString & aMinWidth) = 0;

  /* attribute DOMString minHeight; */
  NS_IMETHOD GetMinHeight(nsAString & aMinHeight) = 0;
  NS_IMETHOD SetMinHeight(const nsAString & aMinHeight) = 0;

  /* attribute DOMString maxWidth; */
  NS_IMETHOD GetMaxWidth(nsAString & aMaxWidth) = 0;
  NS_IMETHOD SetMaxWidth(const nsAString & aMaxWidth) = 0;

  /* attribute DOMString maxHeight; */
  NS_IMETHOD GetMaxHeight(nsAString & aMaxHeight) = 0;
  NS_IMETHOD SetMaxHeight(const nsAString & aMaxHeight) = 0;

  /* attribute DOMString persist; */
  NS_IMETHOD GetPersist(nsAString & aPersist) = 0;
  NS_IMETHOD SetPersist(const nsAString & aPersist) = 0;

  /* attribute DOMString left; */
  NS_IMETHOD GetLeft(nsAString & aLeft) = 0;
  NS_IMETHOD SetLeft(const nsAString & aLeft) = 0;

  /* attribute DOMString top; */
  NS_IMETHOD GetTop(nsAString & aTop) = 0;
  NS_IMETHOD SetTop(const nsAString & aTop) = 0;

  /* attribute DOMString datasources; */
  NS_IMETHOD GetDatasources(nsAString & aDatasources) = 0;
  NS_IMETHOD SetDatasources(const nsAString & aDatasources) = 0;

  /* attribute DOMString ref; */
  NS_IMETHOD GetRef(nsAString & aRef) = 0;
  NS_IMETHOD SetRef(const nsAString & aRef) = 0;

  /* attribute DOMString tooltipText; */
  NS_IMETHOD GetTooltipText(nsAString & aTooltipText) = 0;
  NS_IMETHOD SetTooltipText(const nsAString & aTooltipText) = 0;

  /* attribute DOMString statusText; */
  NS_IMETHOD GetStatusText(nsAString & aStatusText) = 0;
  NS_IMETHOD SetStatusText(const nsAString & aStatusText) = 0;

  /* attribute boolean allowEvents; */
  NS_IMETHOD GetAllowEvents(bool *aAllowEvents) = 0;
  NS_IMETHOD SetAllowEvents(bool aAllowEvents) = 0;

  /* readonly attribute nsIRDFCompositeDataSource database; */
  NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) = 0;

  /* readonly attribute nsIXULTemplateBuilder builder; */
  NS_IMETHOD GetBuilder(nsIXULTemplateBuilder * *aBuilder) = 0;

  /* readonly attribute nsIRDFResource resource; */
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) = 0;

  /* readonly attribute nsIControllers controllers; */
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) = 0;

  /* readonly attribute nsIBoxObject boxObject; */
  NS_IMETHOD GetBoxObject(nsIBoxObject * *aBoxObject) = 0;

  /* void focus (); */
  NS_IMETHOD Focus(void) = 0;

  /* void blur (); */
  NS_IMETHOD Blur(void) = 0;

  /* void click (); */
  NS_IMETHOD Click(void) = 0;

  /* void doCommand (); */
  NS_IMETHOD DoCommand(void) = 0;

  /* nsIDOMNodeList getElementsByAttribute (in DOMString name, in DOMString value); */
  NS_IMETHOD GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval) = 0;

  /* nsIDOMNodeList getElementsByAttributeNS (in DOMString namespaceURI, in DOMString name, in DOMString value); */
  NS_IMETHOD GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULElement, NS_IDOMXULELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULELEMENT \
  NS_IMETHOD GetAlign(nsAString & aAlign) override; \
  NS_IMETHOD SetAlign(const nsAString & aAlign) override; \
  NS_IMETHOD GetDir(nsAString & aDir) override; \
  NS_IMETHOD SetDir(const nsAString & aDir) override; \
  NS_IMETHOD GetFlex(nsAString & aFlex) override; \
  NS_IMETHOD SetFlex(const nsAString & aFlex) override; \
  NS_IMETHOD GetFlexGroup(nsAString & aFlexGroup) override; \
  NS_IMETHOD SetFlexGroup(const nsAString & aFlexGroup) override; \
  NS_IMETHOD GetOrdinal(nsAString & aOrdinal) override; \
  NS_IMETHOD SetOrdinal(const nsAString & aOrdinal) override; \
  NS_IMETHOD GetOrient(nsAString & aOrient) override; \
  NS_IMETHOD SetOrient(const nsAString & aOrient) override; \
  NS_IMETHOD GetPack(nsAString & aPack) override; \
  NS_IMETHOD SetPack(const nsAString & aPack) override; \
  NS_IMETHOD GetHidden(bool *aHidden) override; \
  NS_IMETHOD SetHidden(bool aHidden) override; \
  NS_IMETHOD GetCollapsed(bool *aCollapsed) override; \
  NS_IMETHOD SetCollapsed(bool aCollapsed) override; \
  NS_IMETHOD GetObserves(nsAString & aObserves) override; \
  NS_IMETHOD SetObserves(const nsAString & aObserves) override; \
  NS_IMETHOD GetMenu(nsAString & aMenu) override; \
  NS_IMETHOD SetMenu(const nsAString & aMenu) override; \
  NS_IMETHOD GetContextMenu(nsAString & aContextMenu) override; \
  NS_IMETHOD SetContextMenu(const nsAString & aContextMenu) override; \
  NS_IMETHOD GetTooltip(nsAString & aTooltip) override; \
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) override; \
  NS_IMETHOD GetWidth(nsAString & aWidth) override; \
  NS_IMETHOD SetWidth(const nsAString & aWidth) override; \
  NS_IMETHOD GetHeight(nsAString & aHeight) override; \
  NS_IMETHOD SetHeight(const nsAString & aHeight) override; \
  NS_IMETHOD GetMinWidth(nsAString & aMinWidth) override; \
  NS_IMETHOD SetMinWidth(const nsAString & aMinWidth) override; \
  NS_IMETHOD GetMinHeight(nsAString & aMinHeight) override; \
  NS_IMETHOD SetMinHeight(const nsAString & aMinHeight) override; \
  NS_IMETHOD GetMaxWidth(nsAString & aMaxWidth) override; \
  NS_IMETHOD SetMaxWidth(const nsAString & aMaxWidth) override; \
  NS_IMETHOD GetMaxHeight(nsAString & aMaxHeight) override; \
  NS_IMETHOD SetMaxHeight(const nsAString & aMaxHeight) override; \
  NS_IMETHOD GetPersist(nsAString & aPersist) override; \
  NS_IMETHOD SetPersist(const nsAString & aPersist) override; \
  NS_IMETHOD GetLeft(nsAString & aLeft) override; \
  NS_IMETHOD SetLeft(const nsAString & aLeft) override; \
  NS_IMETHOD GetTop(nsAString & aTop) override; \
  NS_IMETHOD SetTop(const nsAString & aTop) override; \
  NS_IMETHOD GetDatasources(nsAString & aDatasources) override; \
  NS_IMETHOD SetDatasources(const nsAString & aDatasources) override; \
  NS_IMETHOD GetRef(nsAString & aRef) override; \
  NS_IMETHOD SetRef(const nsAString & aRef) override; \
  NS_IMETHOD GetTooltipText(nsAString & aTooltipText) override; \
  NS_IMETHOD SetTooltipText(const nsAString & aTooltipText) override; \
  NS_IMETHOD GetStatusText(nsAString & aStatusText) override; \
  NS_IMETHOD SetStatusText(const nsAString & aStatusText) override; \
  NS_IMETHOD GetAllowEvents(bool *aAllowEvents) override; \
  NS_IMETHOD SetAllowEvents(bool aAllowEvents) override; \
  NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) override; \
  NS_IMETHOD GetBuilder(nsIXULTemplateBuilder * *aBuilder) override; \
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) override; \
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) override; \
  NS_IMETHOD GetBoxObject(nsIBoxObject * *aBoxObject) override; \
  NS_IMETHOD Focus(void) override; \
  NS_IMETHOD Blur(void) override; \
  NS_IMETHOD Click(void) override; \
  NS_IMETHOD DoCommand(void) override; \
  NS_IMETHOD GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval) override; \
  NS_IMETHOD GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) override { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) override { return _to SetAlign(aAlign); } \
  NS_IMETHOD GetDir(nsAString & aDir) override { return _to GetDir(aDir); } \
  NS_IMETHOD SetDir(const nsAString & aDir) override { return _to SetDir(aDir); } \
  NS_IMETHOD GetFlex(nsAString & aFlex) override { return _to GetFlex(aFlex); } \
  NS_IMETHOD SetFlex(const nsAString & aFlex) override { return _to SetFlex(aFlex); } \
  NS_IMETHOD GetFlexGroup(nsAString & aFlexGroup) override { return _to GetFlexGroup(aFlexGroup); } \
  NS_IMETHOD SetFlexGroup(const nsAString & aFlexGroup) override { return _to SetFlexGroup(aFlexGroup); } \
  NS_IMETHOD GetOrdinal(nsAString & aOrdinal) override { return _to GetOrdinal(aOrdinal); } \
  NS_IMETHOD SetOrdinal(const nsAString & aOrdinal) override { return _to SetOrdinal(aOrdinal); } \
  NS_IMETHOD GetOrient(nsAString & aOrient) override { return _to GetOrient(aOrient); } \
  NS_IMETHOD SetOrient(const nsAString & aOrient) override { return _to SetOrient(aOrient); } \
  NS_IMETHOD GetPack(nsAString & aPack) override { return _to GetPack(aPack); } \
  NS_IMETHOD SetPack(const nsAString & aPack) override { return _to SetPack(aPack); } \
  NS_IMETHOD GetHidden(bool *aHidden) override { return _to GetHidden(aHidden); } \
  NS_IMETHOD SetHidden(bool aHidden) override { return _to SetHidden(aHidden); } \
  NS_IMETHOD GetCollapsed(bool *aCollapsed) override { return _to GetCollapsed(aCollapsed); } \
  NS_IMETHOD SetCollapsed(bool aCollapsed) override { return _to SetCollapsed(aCollapsed); } \
  NS_IMETHOD GetObserves(nsAString & aObserves) override { return _to GetObserves(aObserves); } \
  NS_IMETHOD SetObserves(const nsAString & aObserves) override { return _to SetObserves(aObserves); } \
  NS_IMETHOD GetMenu(nsAString & aMenu) override { return _to GetMenu(aMenu); } \
  NS_IMETHOD SetMenu(const nsAString & aMenu) override { return _to SetMenu(aMenu); } \
  NS_IMETHOD GetContextMenu(nsAString & aContextMenu) override { return _to GetContextMenu(aContextMenu); } \
  NS_IMETHOD SetContextMenu(const nsAString & aContextMenu) override { return _to SetContextMenu(aContextMenu); } \
  NS_IMETHOD GetTooltip(nsAString & aTooltip) override { return _to GetTooltip(aTooltip); } \
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) override { return _to SetTooltip(aTooltip); } \
  NS_IMETHOD GetWidth(nsAString & aWidth) override { return _to GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(const nsAString & aWidth) override { return _to SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsAString & aHeight) override { return _to GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(const nsAString & aHeight) override { return _to SetHeight(aHeight); } \
  NS_IMETHOD GetMinWidth(nsAString & aMinWidth) override { return _to GetMinWidth(aMinWidth); } \
  NS_IMETHOD SetMinWidth(const nsAString & aMinWidth) override { return _to SetMinWidth(aMinWidth); } \
  NS_IMETHOD GetMinHeight(nsAString & aMinHeight) override { return _to GetMinHeight(aMinHeight); } \
  NS_IMETHOD SetMinHeight(const nsAString & aMinHeight) override { return _to SetMinHeight(aMinHeight); } \
  NS_IMETHOD GetMaxWidth(nsAString & aMaxWidth) override { return _to GetMaxWidth(aMaxWidth); } \
  NS_IMETHOD SetMaxWidth(const nsAString & aMaxWidth) override { return _to SetMaxWidth(aMaxWidth); } \
  NS_IMETHOD GetMaxHeight(nsAString & aMaxHeight) override { return _to GetMaxHeight(aMaxHeight); } \
  NS_IMETHOD SetMaxHeight(const nsAString & aMaxHeight) override { return _to SetMaxHeight(aMaxHeight); } \
  NS_IMETHOD GetPersist(nsAString & aPersist) override { return _to GetPersist(aPersist); } \
  NS_IMETHOD SetPersist(const nsAString & aPersist) override { return _to SetPersist(aPersist); } \
  NS_IMETHOD GetLeft(nsAString & aLeft) override { return _to GetLeft(aLeft); } \
  NS_IMETHOD SetLeft(const nsAString & aLeft) override { return _to SetLeft(aLeft); } \
  NS_IMETHOD GetTop(nsAString & aTop) override { return _to GetTop(aTop); } \
  NS_IMETHOD SetTop(const nsAString & aTop) override { return _to SetTop(aTop); } \
  NS_IMETHOD GetDatasources(nsAString & aDatasources) override { return _to GetDatasources(aDatasources); } \
  NS_IMETHOD SetDatasources(const nsAString & aDatasources) override { return _to SetDatasources(aDatasources); } \
  NS_IMETHOD GetRef(nsAString & aRef) override { return _to GetRef(aRef); } \
  NS_IMETHOD SetRef(const nsAString & aRef) override { return _to SetRef(aRef); } \
  NS_IMETHOD GetTooltipText(nsAString & aTooltipText) override { return _to GetTooltipText(aTooltipText); } \
  NS_IMETHOD SetTooltipText(const nsAString & aTooltipText) override { return _to SetTooltipText(aTooltipText); } \
  NS_IMETHOD GetStatusText(nsAString & aStatusText) override { return _to GetStatusText(aStatusText); } \
  NS_IMETHOD SetStatusText(const nsAString & aStatusText) override { return _to SetStatusText(aStatusText); } \
  NS_IMETHOD GetAllowEvents(bool *aAllowEvents) override { return _to GetAllowEvents(aAllowEvents); } \
  NS_IMETHOD SetAllowEvents(bool aAllowEvents) override { return _to SetAllowEvents(aAllowEvents); } \
  NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) override { return _to GetDatabase(aDatabase); } \
  NS_IMETHOD GetBuilder(nsIXULTemplateBuilder * *aBuilder) override { return _to GetBuilder(aBuilder); } \
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) override { return _to GetResource(aResource); } \
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) override { return _to GetControllers(aControllers); } \
  NS_IMETHOD GetBoxObject(nsIBoxObject * *aBoxObject) override { return _to GetBoxObject(aBoxObject); } \
  NS_IMETHOD Focus(void) override { return _to Focus(); } \
  NS_IMETHOD Blur(void) override { return _to Blur(); } \
  NS_IMETHOD Click(void) override { return _to Click(); } \
  NS_IMETHOD DoCommand(void) override { return _to DoCommand(); } \
  NS_IMETHOD GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval) override { return _to GetElementsByAttribute(name, value, _retval); } \
  NS_IMETHOD GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval) override { return _to GetElementsByAttributeNS(namespaceURI, name, value, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } \
  NS_IMETHOD GetDir(nsAString & aDir) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDir(aDir); } \
  NS_IMETHOD SetDir(const nsAString & aDir) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDir(aDir); } \
  NS_IMETHOD GetFlex(nsAString & aFlex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlex(aFlex); } \
  NS_IMETHOD SetFlex(const nsAString & aFlex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlex(aFlex); } \
  NS_IMETHOD GetFlexGroup(nsAString & aFlexGroup) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlexGroup(aFlexGroup); } \
  NS_IMETHOD SetFlexGroup(const nsAString & aFlexGroup) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlexGroup(aFlexGroup); } \
  NS_IMETHOD GetOrdinal(nsAString & aOrdinal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrdinal(aOrdinal); } \
  NS_IMETHOD SetOrdinal(const nsAString & aOrdinal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOrdinal(aOrdinal); } \
  NS_IMETHOD GetOrient(nsAString & aOrient) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrient(aOrient); } \
  NS_IMETHOD SetOrient(const nsAString & aOrient) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOrient(aOrient); } \
  NS_IMETHOD GetPack(nsAString & aPack) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPack(aPack); } \
  NS_IMETHOD SetPack(const nsAString & aPack) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPack(aPack); } \
  NS_IMETHOD GetHidden(bool *aHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHidden(aHidden); } \
  NS_IMETHOD SetHidden(bool aHidden) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHidden(aHidden); } \
  NS_IMETHOD GetCollapsed(bool *aCollapsed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCollapsed(aCollapsed); } \
  NS_IMETHOD SetCollapsed(bool aCollapsed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCollapsed(aCollapsed); } \
  NS_IMETHOD GetObserves(nsAString & aObserves) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObserves(aObserves); } \
  NS_IMETHOD SetObserves(const nsAString & aObserves) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObserves(aObserves); } \
  NS_IMETHOD GetMenu(nsAString & aMenu) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMenu(aMenu); } \
  NS_IMETHOD SetMenu(const nsAString & aMenu) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMenu(aMenu); } \
  NS_IMETHOD GetContextMenu(nsAString & aContextMenu) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContextMenu(aContextMenu); } \
  NS_IMETHOD SetContextMenu(const nsAString & aContextMenu) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContextMenu(aContextMenu); } \
  NS_IMETHOD GetTooltip(nsAString & aTooltip) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooltip(aTooltip); } \
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTooltip(aTooltip); } \
  NS_IMETHOD GetWidth(nsAString & aWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(const nsAString & aWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(nsAString & aHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(const nsAString & aHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_IMETHOD GetMinWidth(nsAString & aMinWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinWidth(aMinWidth); } \
  NS_IMETHOD SetMinWidth(const nsAString & aMinWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinWidth(aMinWidth); } \
  NS_IMETHOD GetMinHeight(nsAString & aMinHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinHeight(aMinHeight); } \
  NS_IMETHOD SetMinHeight(const nsAString & aMinHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinHeight(aMinHeight); } \
  NS_IMETHOD GetMaxWidth(nsAString & aMaxWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxWidth(aMaxWidth); } \
  NS_IMETHOD SetMaxWidth(const nsAString & aMaxWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxWidth(aMaxWidth); } \
  NS_IMETHOD GetMaxHeight(nsAString & aMaxHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxHeight(aMaxHeight); } \
  NS_IMETHOD SetMaxHeight(const nsAString & aMaxHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxHeight(aMaxHeight); } \
  NS_IMETHOD GetPersist(nsAString & aPersist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersist(aPersist); } \
  NS_IMETHOD SetPersist(const nsAString & aPersist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPersist(aPersist); } \
  NS_IMETHOD GetLeft(nsAString & aLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLeft(aLeft); } \
  NS_IMETHOD SetLeft(const nsAString & aLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLeft(aLeft); } \
  NS_IMETHOD GetTop(nsAString & aTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTop(aTop); } \
  NS_IMETHOD SetTop(const nsAString & aTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTop(aTop); } \
  NS_IMETHOD GetDatasources(nsAString & aDatasources) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatasources(aDatasources); } \
  NS_IMETHOD SetDatasources(const nsAString & aDatasources) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDatasources(aDatasources); } \
  NS_IMETHOD GetRef(nsAString & aRef) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRef(aRef); } \
  NS_IMETHOD SetRef(const nsAString & aRef) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRef(aRef); } \
  NS_IMETHOD GetTooltipText(nsAString & aTooltipText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooltipText(aTooltipText); } \
  NS_IMETHOD SetTooltipText(const nsAString & aTooltipText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTooltipText(aTooltipText); } \
  NS_IMETHOD GetStatusText(nsAString & aStatusText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatusText(aStatusText); } \
  NS_IMETHOD SetStatusText(const nsAString & aStatusText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStatusText(aStatusText); } \
  NS_IMETHOD GetAllowEvents(bool *aAllowEvents) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowEvents(aAllowEvents); } \
  NS_IMETHOD SetAllowEvents(bool aAllowEvents) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowEvents(aAllowEvents); } \
  NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabase(aDatabase); } \
  NS_IMETHOD GetBuilder(nsIXULTemplateBuilder * *aBuilder) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuilder(aBuilder); } \
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResource(aResource); } \
  NS_IMETHOD GetControllers(nsIControllers * *aControllers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControllers(aControllers); } \
  NS_IMETHOD GetBoxObject(nsIBoxObject * *aBoxObject) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoxObject(aBoxObject); } \
  NS_IMETHOD Focus(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_IMETHOD Blur(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } \
  NS_IMETHOD Click(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Click(); } \
  NS_IMETHOD DoCommand(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(); } \
  NS_IMETHOD GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByAttribute(name, value, _retval); } \
  NS_IMETHOD GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElementsByAttributeNS(namespaceURI, name, value, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULElement : public nsIDOMXULElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULELEMENT

  nsDOMXULElement();

private:
  ~nsDOMXULElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMXULElement, nsIDOMXULElement)

nsDOMXULElement::nsDOMXULElement()
{
  /* member initializers and constructor code */
}

nsDOMXULElement::~nsDOMXULElement()
{
  /* destructor code */
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMXULElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString dir; */
NS_IMETHODIMP nsDOMXULElement::GetDir(nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetDir(const nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString flex; */
NS_IMETHODIMP nsDOMXULElement::GetFlex(nsAString & aFlex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetFlex(const nsAString & aFlex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString flexGroup; */
NS_IMETHODIMP nsDOMXULElement::GetFlexGroup(nsAString & aFlexGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetFlexGroup(const nsAString & aFlexGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString ordinal; */
NS_IMETHODIMP nsDOMXULElement::GetOrdinal(nsAString & aOrdinal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetOrdinal(const nsAString & aOrdinal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString orient; */
NS_IMETHODIMP nsDOMXULElement::GetOrient(nsAString & aOrient)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetOrient(const nsAString & aOrient)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString pack; */
NS_IMETHODIMP nsDOMXULElement::GetPack(nsAString & aPack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetPack(const nsAString & aPack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hidden; */
NS_IMETHODIMP nsDOMXULElement::GetHidden(bool *aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetHidden(bool aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean collapsed; */
NS_IMETHODIMP nsDOMXULElement::GetCollapsed(bool *aCollapsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetCollapsed(bool aCollapsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString observes; */
NS_IMETHODIMP nsDOMXULElement::GetObserves(nsAString & aObserves)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetObserves(const nsAString & aObserves)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString menu; */
NS_IMETHODIMP nsDOMXULElement::GetMenu(nsAString & aMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetMenu(const nsAString & aMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString contextMenu; */
NS_IMETHODIMP nsDOMXULElement::GetContextMenu(nsAString & aContextMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetContextMenu(const nsAString & aContextMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString tooltip; */
NS_IMETHODIMP nsDOMXULElement::GetTooltip(nsAString & aTooltip)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetTooltip(const nsAString & aTooltip)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString width; */
NS_IMETHODIMP nsDOMXULElement::GetWidth(nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetWidth(const nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString height; */
NS_IMETHODIMP nsDOMXULElement::GetHeight(nsAString & aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetHeight(const nsAString & aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString minWidth; */
NS_IMETHODIMP nsDOMXULElement::GetMinWidth(nsAString & aMinWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetMinWidth(const nsAString & aMinWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString minHeight; */
NS_IMETHODIMP nsDOMXULElement::GetMinHeight(nsAString & aMinHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetMinHeight(const nsAString & aMinHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString maxWidth; */
NS_IMETHODIMP nsDOMXULElement::GetMaxWidth(nsAString & aMaxWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetMaxWidth(const nsAString & aMaxWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString maxHeight; */
NS_IMETHODIMP nsDOMXULElement::GetMaxHeight(nsAString & aMaxHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetMaxHeight(const nsAString & aMaxHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString persist; */
NS_IMETHODIMP nsDOMXULElement::GetPersist(nsAString & aPersist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetPersist(const nsAString & aPersist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString left; */
NS_IMETHODIMP nsDOMXULElement::GetLeft(nsAString & aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetLeft(const nsAString & aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString top; */
NS_IMETHODIMP nsDOMXULElement::GetTop(nsAString & aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetTop(const nsAString & aTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString datasources; */
NS_IMETHODIMP nsDOMXULElement::GetDatasources(nsAString & aDatasources)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetDatasources(const nsAString & aDatasources)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString ref; */
NS_IMETHODIMP nsDOMXULElement::GetRef(nsAString & aRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetRef(const nsAString & aRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString tooltipText; */
NS_IMETHODIMP nsDOMXULElement::GetTooltipText(nsAString & aTooltipText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetTooltipText(const nsAString & aTooltipText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString statusText; */
NS_IMETHODIMP nsDOMXULElement::GetStatusText(nsAString & aStatusText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetStatusText(const nsAString & aStatusText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowEvents; */
NS_IMETHODIMP nsDOMXULElement::GetAllowEvents(bool *aAllowEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULElement::SetAllowEvents(bool aAllowEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRDFCompositeDataSource database; */
NS_IMETHODIMP nsDOMXULElement::GetDatabase(nsIRDFCompositeDataSource * *aDatabase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXULTemplateBuilder builder; */
NS_IMETHODIMP nsDOMXULElement::GetBuilder(nsIXULTemplateBuilder * *aBuilder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRDFResource resource; */
NS_IMETHODIMP nsDOMXULElement::GetResource(nsIRDFResource * *aResource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIControllers controllers; */
NS_IMETHODIMP nsDOMXULElement::GetControllers(nsIControllers * *aControllers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIBoxObject boxObject; */
NS_IMETHODIMP nsDOMXULElement::GetBoxObject(nsIBoxObject * *aBoxObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMXULElement::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blur (); */
NS_IMETHODIMP nsDOMXULElement::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void click (); */
NS_IMETHODIMP nsDOMXULElement::Click()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommand (); */
NS_IMETHODIMP nsDOMXULElement::DoCommand()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByAttribute (in DOMString name, in DOMString value); */
NS_IMETHODIMP nsDOMXULElement::GetElementsByAttribute(const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getElementsByAttributeNS (in DOMString namespaceURI, in DOMString name, in DOMString value); */
NS_IMETHODIMP nsDOMXULElement::GetElementsByAttributeNS(const nsAString & namespaceURI, const nsAString & name, const nsAString & value, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULElement_h__ */
