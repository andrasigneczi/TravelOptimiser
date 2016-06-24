/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISelectionController.idl
 */

#ifndef __gen_nsISelectionController_h__
#define __gen_nsISelectionController_h__


#ifndef __gen_nsISelectionDisplay_h__
#include "nsISelectionDisplay.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef short SelectionType;
typedef short SelectionRegion;
class nsIContent; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsISelection; /* forward declaration */

class nsISelectionDisplay; /* forward declaration */


/* starting interface:    nsISelectionController */
#define NS_ISELECTIONCONTROLLER_IID_STR "82c3a9df-9bd6-4da2-b561-d85a9eec5caa"

#define NS_ISELECTIONCONTROLLER_IID \
  {0x82c3a9df, 0x9bd6, 0x4da2, \
    { 0xb5, 0x61, 0xd8, 0x5a, 0x9e, 0xec, 0x5c, 0xaa }}

class NS_NO_VTABLE nsISelectionController : public nsISelectionDisplay {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTIONCONTROLLER_IID)

  enum {
    SELECTION_NONE = 0,
    SELECTION_NORMAL = 1,
    SELECTION_SPELLCHECK = 2,
    SELECTION_IME_RAWINPUT = 4,
    SELECTION_IME_SELECTEDRAWTEXT = 8,
    SELECTION_IME_CONVERTEDTEXT = 16,
    SELECTION_IME_SELECTEDCONVERTEDTEXT = 32,
    SELECTION_ACCESSIBILITY = 64,
    SELECTION_FIND = 128,
    SELECTION_URLSECONDARY = 256,
    NUM_SELECTIONTYPES = 10,
    SELECTION_ANCHOR_REGION = 0,
    SELECTION_FOCUS_REGION = 1,
    SELECTION_WHOLE_SELECTION = 2,
    NUM_SELECTION_REGIONS = 3,
    SELECTION_OFF = 0,
    SELECTION_HIDDEN = 1,
    SELECTION_ON = 2,
    SELECTION_DISABLED = 3,
    SELECTION_ATTENTION = 4
  };

  /* void setDisplaySelection (in short toggle); */
  NS_IMETHOD SetDisplaySelection(int16_t toggle) = 0;

  /* short getDisplaySelection (); */
  NS_IMETHOD GetDisplaySelection(int16_t *_retval) = 0;

  /* nsISelection getSelection (in short type); */
  NS_IMETHOD GetSelection(int16_t type, nsISelection * *_retval) = 0;

  enum {
    SCROLL_SYNCHRONOUS = 2,
    SCROLL_FIRST_ANCESTOR_ONLY = 4,
    SCROLL_CENTER_VERTICALLY = 16,
    SCROLL_OVERFLOW_HIDDEN = 32
  };

  /* void scrollSelectionIntoView (in short type, in short region, in short flags); */
  NS_IMETHOD ScrollSelectionIntoView(int16_t type, int16_t region, int16_t flags) = 0;

  /* void repaintSelection (in short type); */
  NS_IMETHOD RepaintSelection(int16_t type) = 0;

  /* void setCaretEnabled (in boolean enabled); */
  NS_IMETHOD SetCaretEnabled(bool enabled) = 0;

  /* void setCaretReadOnly (in boolean readOnly); */
  NS_IMETHOD SetCaretReadOnly(bool readOnly) = 0;

  /* boolean getCaretEnabled (); */
  NS_IMETHOD GetCaretEnabled(bool *_retval) = 0;

  /* readonly attribute boolean caretVisible; */
  NS_IMETHOD GetCaretVisible(bool *aCaretVisible) = 0;

  /* void setCaretVisibilityDuringSelection (in boolean visibility); */
  NS_IMETHOD SetCaretVisibilityDuringSelection(bool visibility) = 0;

  /* void characterMove (in boolean forward, in boolean extend); */
  NS_IMETHOD CharacterMove(bool forward, bool extend) = 0;

  /* void physicalMove (in short direction, in short amount, in boolean extend); */
  NS_IMETHOD PhysicalMove(int16_t direction, int16_t amount, bool extend) = 0;

  enum {
    MOVE_LEFT = 0,
    MOVE_RIGHT = 1,
    MOVE_UP = 2,
    MOVE_DOWN = 3
  };

  /* [noscript] void characterExtendForDelete (); */
  NS_IMETHOD CharacterExtendForDelete(void) = 0;

  /* [noscript] void characterExtendForBackspace (); */
  NS_IMETHOD CharacterExtendForBackspace(void) = 0;

  /* void wordMove (in boolean forward, in boolean extend); */
  NS_IMETHOD WordMove(bool forward, bool extend) = 0;

  /* [noscript] void wordExtendForDelete (in boolean forward); */
  NS_IMETHOD WordExtendForDelete(bool forward) = 0;

  /* void lineMove (in boolean forward, in boolean extend); */
  NS_IMETHOD LineMove(bool forward, bool extend) = 0;

  /* void intraLineMove (in boolean forward, in boolean extend); */
  NS_IMETHOD IntraLineMove(bool forward, bool extend) = 0;

  /* void pageMove (in boolean forward, in boolean extend); */
  NS_IMETHOD PageMove(bool forward, bool extend) = 0;

  /* void completeScroll (in boolean forward); */
  NS_IMETHOD CompleteScroll(bool forward) = 0;

  /* void completeMove (in boolean forward, in boolean extend); */
  NS_IMETHOD CompleteMove(bool forward, bool extend) = 0;

  /* void scrollPage (in boolean forward); */
  NS_IMETHOD ScrollPage(bool forward) = 0;

  /* void scrollLine (in boolean forward); */
  NS_IMETHOD ScrollLine(bool forward) = 0;

  /* void scrollCharacter (in boolean right); */
  NS_IMETHOD ScrollCharacter(bool right) = 0;

  /* void selectAll (); */
  NS_IMETHOD SelectAll(void) = 0;

  /* boolean checkVisibility (in nsIDOMNode node, in short startOffset, in short endOffset); */
  NS_IMETHOD CheckVisibility(nsIDOMNode *node, int16_t startOffset, int16_t endOffset, bool *_retval) = 0;

  /* [noscript,nostdcall] boolean checkVisibilityContent (in nsIContent node, in short startOffset, in short endOffset); */
  virtual nsresult CheckVisibilityContent(nsIContent *node, int16_t startOffset, int16_t endOffset, bool *_retval) = 0;

  /* attribute boolean selectionCaretsVisibility; */
  NS_IMETHOD GetSelectionCaretsVisibility(bool *aSelectionCaretsVisibility) = 0;
  NS_IMETHOD SetSelectionCaretsVisibility(bool aSelectionCaretsVisibility) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelectionController, NS_ISELECTIONCONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTIONCONTROLLER \
  NS_IMETHOD SetDisplaySelection(int16_t toggle) override; \
  NS_IMETHOD GetDisplaySelection(int16_t *_retval) override; \
  NS_IMETHOD GetSelection(int16_t type, nsISelection * *_retval) override; \
  NS_IMETHOD ScrollSelectionIntoView(int16_t type, int16_t region, int16_t flags) override; \
  NS_IMETHOD RepaintSelection(int16_t type) override; \
  NS_IMETHOD SetCaretEnabled(bool enabled) override; \
  NS_IMETHOD SetCaretReadOnly(bool readOnly) override; \
  NS_IMETHOD GetCaretEnabled(bool *_retval) override; \
  NS_IMETHOD GetCaretVisible(bool *aCaretVisible) override; \
  NS_IMETHOD SetCaretVisibilityDuringSelection(bool visibility) override; \
  NS_IMETHOD CharacterMove(bool forward, bool extend) override; \
  NS_IMETHOD PhysicalMove(int16_t direction, int16_t amount, bool extend) override; \
  NS_IMETHOD CharacterExtendForDelete(void) override; \
  NS_IMETHOD CharacterExtendForBackspace(void) override; \
  NS_IMETHOD WordMove(bool forward, bool extend) override; \
  NS_IMETHOD WordExtendForDelete(bool forward) override; \
  NS_IMETHOD LineMove(bool forward, bool extend) override; \
  NS_IMETHOD IntraLineMove(bool forward, bool extend) override; \
  NS_IMETHOD PageMove(bool forward, bool extend) override; \
  NS_IMETHOD CompleteScroll(bool forward) override; \
  NS_IMETHOD CompleteMove(bool forward, bool extend) override; \
  NS_IMETHOD ScrollPage(bool forward) override; \
  NS_IMETHOD ScrollLine(bool forward) override; \
  NS_IMETHOD ScrollCharacter(bool right) override; \
  NS_IMETHOD SelectAll(void) override; \
  NS_IMETHOD CheckVisibility(nsIDOMNode *node, int16_t startOffset, int16_t endOffset, bool *_retval) override; \
  virtual nsresult CheckVisibilityContent(nsIContent *node, int16_t startOffset, int16_t endOffset, bool *_retval) override; \
  NS_IMETHOD GetSelectionCaretsVisibility(bool *aSelectionCaretsVisibility) override; \
  NS_IMETHOD SetSelectionCaretsVisibility(bool aSelectionCaretsVisibility) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTIONCONTROLLER(_to) \
  NS_IMETHOD SetDisplaySelection(int16_t toggle) override { return _to SetDisplaySelection(toggle); } \
  NS_IMETHOD GetDisplaySelection(int16_t *_retval) override { return _to GetDisplaySelection(_retval); } \
  NS_IMETHOD GetSelection(int16_t type, nsISelection * *_retval) override { return _to GetSelection(type, _retval); } \
  NS_IMETHOD ScrollSelectionIntoView(int16_t type, int16_t region, int16_t flags) override { return _to ScrollSelectionIntoView(type, region, flags); } \
  NS_IMETHOD RepaintSelection(int16_t type) override { return _to RepaintSelection(type); } \
  NS_IMETHOD SetCaretEnabled(bool enabled) override { return _to SetCaretEnabled(enabled); } \
  NS_IMETHOD SetCaretReadOnly(bool readOnly) override { return _to SetCaretReadOnly(readOnly); } \
  NS_IMETHOD GetCaretEnabled(bool *_retval) override { return _to GetCaretEnabled(_retval); } \
  NS_IMETHOD GetCaretVisible(bool *aCaretVisible) override { return _to GetCaretVisible(aCaretVisible); } \
  NS_IMETHOD SetCaretVisibilityDuringSelection(bool visibility) override { return _to SetCaretVisibilityDuringSelection(visibility); } \
  NS_IMETHOD CharacterMove(bool forward, bool extend) override { return _to CharacterMove(forward, extend); } \
  NS_IMETHOD PhysicalMove(int16_t direction, int16_t amount, bool extend) override { return _to PhysicalMove(direction, amount, extend); } \
  NS_IMETHOD CharacterExtendForDelete(void) override { return _to CharacterExtendForDelete(); } \
  NS_IMETHOD CharacterExtendForBackspace(void) override { return _to CharacterExtendForBackspace(); } \
  NS_IMETHOD WordMove(bool forward, bool extend) override { return _to WordMove(forward, extend); } \
  NS_IMETHOD WordExtendForDelete(bool forward) override { return _to WordExtendForDelete(forward); } \
  NS_IMETHOD LineMove(bool forward, bool extend) override { return _to LineMove(forward, extend); } \
  NS_IMETHOD IntraLineMove(bool forward, bool extend) override { return _to IntraLineMove(forward, extend); } \
  NS_IMETHOD PageMove(bool forward, bool extend) override { return _to PageMove(forward, extend); } \
  NS_IMETHOD CompleteScroll(bool forward) override { return _to CompleteScroll(forward); } \
  NS_IMETHOD CompleteMove(bool forward, bool extend) override { return _to CompleteMove(forward, extend); } \
  NS_IMETHOD ScrollPage(bool forward) override { return _to ScrollPage(forward); } \
  NS_IMETHOD ScrollLine(bool forward) override { return _to ScrollLine(forward); } \
  NS_IMETHOD ScrollCharacter(bool right) override { return _to ScrollCharacter(right); } \
  NS_IMETHOD SelectAll(void) override { return _to SelectAll(); } \
  NS_IMETHOD CheckVisibility(nsIDOMNode *node, int16_t startOffset, int16_t endOffset, bool *_retval) override { return _to CheckVisibility(node, startOffset, endOffset, _retval); } \
  virtual nsresult CheckVisibilityContent(nsIContent *node, int16_t startOffset, int16_t endOffset, bool *_retval) override { return _to CheckVisibilityContent(node, startOffset, endOffset, _retval); } \
  NS_IMETHOD GetSelectionCaretsVisibility(bool *aSelectionCaretsVisibility) override { return _to GetSelectionCaretsVisibility(aSelectionCaretsVisibility); } \
  NS_IMETHOD SetSelectionCaretsVisibility(bool aSelectionCaretsVisibility) override { return _to SetSelectionCaretsVisibility(aSelectionCaretsVisibility); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTIONCONTROLLER(_to) \
  NS_IMETHOD SetDisplaySelection(int16_t toggle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplaySelection(toggle); } \
  NS_IMETHOD GetDisplaySelection(int16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplaySelection(_retval); } \
  NS_IMETHOD GetSelection(int16_t type, nsISelection * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(type, _retval); } \
  NS_IMETHOD ScrollSelectionIntoView(int16_t type, int16_t region, int16_t flags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollSelectionIntoView(type, region, flags); } \
  NS_IMETHOD RepaintSelection(int16_t type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RepaintSelection(type); } \
  NS_IMETHOD SetCaretEnabled(bool enabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretEnabled(enabled); } \
  NS_IMETHOD SetCaretReadOnly(bool readOnly) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretReadOnly(readOnly); } \
  NS_IMETHOD GetCaretEnabled(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaretEnabled(_retval); } \
  NS_IMETHOD GetCaretVisible(bool *aCaretVisible) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaretVisible(aCaretVisible); } \
  NS_IMETHOD SetCaretVisibilityDuringSelection(bool visibility) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretVisibilityDuringSelection(visibility); } \
  NS_IMETHOD CharacterMove(bool forward, bool extend) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CharacterMove(forward, extend); } \
  NS_IMETHOD PhysicalMove(int16_t direction, int16_t amount, bool extend) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PhysicalMove(direction, amount, extend); } \
  NS_IMETHOD CharacterExtendForDelete(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CharacterExtendForDelete(); } \
  NS_IMETHOD CharacterExtendForBackspace(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CharacterExtendForBackspace(); } \
  NS_IMETHOD WordMove(bool forward, bool extend) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WordMove(forward, extend); } \
  NS_IMETHOD WordExtendForDelete(bool forward) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WordExtendForDelete(forward); } \
  NS_IMETHOD LineMove(bool forward, bool extend) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LineMove(forward, extend); } \
  NS_IMETHOD IntraLineMove(bool forward, bool extend) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IntraLineMove(forward, extend); } \
  NS_IMETHOD PageMove(bool forward, bool extend) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PageMove(forward, extend); } \
  NS_IMETHOD CompleteScroll(bool forward) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CompleteScroll(forward); } \
  NS_IMETHOD CompleteMove(bool forward, bool extend) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CompleteMove(forward, extend); } \
  NS_IMETHOD ScrollPage(bool forward) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollPage(forward); } \
  NS_IMETHOD ScrollLine(bool forward) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollLine(forward); } \
  NS_IMETHOD ScrollCharacter(bool right) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollCharacter(right); } \
  NS_IMETHOD SelectAll(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_IMETHOD CheckVisibility(nsIDOMNode *node, int16_t startOffset, int16_t endOffset, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckVisibility(node, startOffset, endOffset, _retval); } \
  virtual nsresult CheckVisibilityContent(nsIContent *node, int16_t startOffset, int16_t endOffset, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckVisibilityContent(node, startOffset, endOffset, _retval); } \
  NS_IMETHOD GetSelectionCaretsVisibility(bool *aSelectionCaretsVisibility) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionCaretsVisibility(aSelectionCaretsVisibility); } \
  NS_IMETHOD SetSelectionCaretsVisibility(bool aSelectionCaretsVisibility) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionCaretsVisibility(aSelectionCaretsVisibility); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelectionController : public nsISelectionController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTIONCONTROLLER

  nsSelectionController();

private:
  ~nsSelectionController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSelectionController, nsISelectionController)

nsSelectionController::nsSelectionController()
{
  /* member initializers and constructor code */
}

nsSelectionController::~nsSelectionController()
{
  /* destructor code */
}

/* void setDisplaySelection (in short toggle); */
NS_IMETHODIMP nsSelectionController::SetDisplaySelection(int16_t toggle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short getDisplaySelection (); */
NS_IMETHODIMP nsSelectionController::GetDisplaySelection(int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISelection getSelection (in short type); */
NS_IMETHODIMP nsSelectionController::GetSelection(int16_t type, nsISelection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollSelectionIntoView (in short type, in short region, in short flags); */
NS_IMETHODIMP nsSelectionController::ScrollSelectionIntoView(int16_t type, int16_t region, int16_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void repaintSelection (in short type); */
NS_IMETHODIMP nsSelectionController::RepaintSelection(int16_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretEnabled (in boolean enabled); */
NS_IMETHODIMP nsSelectionController::SetCaretEnabled(bool enabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretReadOnly (in boolean readOnly); */
NS_IMETHODIMP nsSelectionController::SetCaretReadOnly(bool readOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getCaretEnabled (); */
NS_IMETHODIMP nsSelectionController::GetCaretEnabled(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean caretVisible; */
NS_IMETHODIMP nsSelectionController::GetCaretVisible(bool *aCaretVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretVisibilityDuringSelection (in boolean visibility); */
NS_IMETHODIMP nsSelectionController::SetCaretVisibilityDuringSelection(bool visibility)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void characterMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::CharacterMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void physicalMove (in short direction, in short amount, in boolean extend); */
NS_IMETHODIMP nsSelectionController::PhysicalMove(int16_t direction, int16_t amount, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void characterExtendForDelete (); */
NS_IMETHODIMP nsSelectionController::CharacterExtendForDelete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void characterExtendForBackspace (); */
NS_IMETHODIMP nsSelectionController::CharacterExtendForBackspace()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wordMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::WordMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void wordExtendForDelete (in boolean forward); */
NS_IMETHODIMP nsSelectionController::WordExtendForDelete(bool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lineMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::LineMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void intraLineMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::IntraLineMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pageMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::PageMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completeScroll (in boolean forward); */
NS_IMETHODIMP nsSelectionController::CompleteScroll(bool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completeMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::CompleteMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollPage (in boolean forward); */
NS_IMETHODIMP nsSelectionController::ScrollPage(bool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollLine (in boolean forward); */
NS_IMETHODIMP nsSelectionController::ScrollLine(bool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollCharacter (in boolean right); */
NS_IMETHODIMP nsSelectionController::ScrollCharacter(bool right)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsSelectionController::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkVisibility (in nsIDOMNode node, in short startOffset, in short endOffset); */
NS_IMETHODIMP nsSelectionController::CheckVisibility(nsIDOMNode *node, int16_t startOffset, int16_t endOffset, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall] boolean checkVisibilityContent (in nsIContent node, in short startOffset, in short endOffset); */
nsresult nsSelectionController::CheckVisibilityContent(nsIContent *node, int16_t startOffset, int16_t endOffset, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean selectionCaretsVisibility; */
NS_IMETHODIMP nsSelectionController::GetSelectionCaretsVisibility(bool *aSelectionCaretsVisibility)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSelectionController::SetSelectionCaretsVisibility(bool aSelectionCaretsVisibility)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

   #define NS_ISELECTIONCONTROLLER_CID \
   { 0x513b9460, 0xd56a, 0x4c4e, \
   { 0xb6, 0xf9, 0x0b, 0x8a, 0xe4, 0x37, 0x2a, 0x3b }}

#endif /* __gen_nsISelectionController_h__ */
