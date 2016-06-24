/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleTextRange.idl
 */

#ifndef __gen_nsIAccessibleTextRange_h__
#define __gen_nsIAccessibleTextRange_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */

class nsIAccessibleText; /* forward declaration */

class nsIArray; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsIAccessibleTextRange */
#define NS_IACCESSIBLETEXTRANGE_IID_STR "525b3401-8a67-4822-b35d-661065767cd8"

#define NS_IACCESSIBLETEXTRANGE_IID \
  {0x525b3401, 0x8a67, 0x4822, \
    { 0xb3, 0x5d, 0x66, 0x10, 0x65, 0x76, 0x7c, 0xd8 }}

class NS_NO_VTABLE nsIAccessibleTextRange : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETEXTRANGE_IID)

  /* readonly attribute nsIAccessibleText startContainer; */
  NS_IMETHOD GetStartContainer(nsIAccessibleText * *aStartContainer) = 0;

  /* readonly attribute long startOffset; */
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) = 0;

  /* readonly attribute nsIAccessibleText endContainer; */
  NS_IMETHOD GetEndContainer(nsIAccessibleText * *aEndContainer) = 0;

  /* readonly attribute long endOffset; */
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) = 0;

  /* readonly attribute nsIAccessible container; */
  NS_IMETHOD GetContainer(nsIAccessible * *aContainer) = 0;

  /* readonly attribute nsIArray embeddedChildren; */
  NS_IMETHOD GetEmbeddedChildren(nsIArray * *aEmbeddedChildren) = 0;

  /* boolean compare (in nsIAccessibleTextRange aOtherRange); */
  NS_IMETHOD Compare(nsIAccessibleTextRange *aOtherRange, bool *_retval) = 0;

  enum {
    EndPoint_Start = 1U,
    EndPoint_End = 2U
  };

  /* long compareEndPoints (in unsigned long aEndPoint, in nsIAccessibleTextRange aOtherRange, in unsigned long aOtherRangeEndPoint); */
  NS_IMETHOD CompareEndPoints(uint32_t aEndPoint, nsIAccessibleTextRange *aOtherRange, uint32_t aOtherRangeEndPoint, int32_t *_retval) = 0;

  /* readonly attribute AString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;

  /* readonly attribute nsIArray bounds; */
  NS_IMETHOD GetBounds(nsIArray * *aBounds) = 0;

  enum {
    FormatUnit = 0U,
    WordUnit = 1U,
    LineUnit = 2U,
    ParagraphUnit = 3U,
    PageUnit = 4U,
    DocumentUnit = 5U
  };

  /* void move (in unsigned long aUnit, in long aCount); */
  NS_IMETHOD Move(uint32_t aUnit, int32_t aCount) = 0;

  /* void moveStart (in unsigned long aUnit, in long aCount); */
  NS_IMETHOD MoveStart(uint32_t aUnit, int32_t aCount) = 0;

  /* void moveEnd (in unsigned long aUnit, in long aCount); */
  NS_IMETHOD MoveEnd(uint32_t aUnit, int32_t aCount) = 0;

  /* void normalize (in unsigned long aUnit); */
  NS_IMETHOD Normalize(uint32_t aUnit) = 0;

  /* nsIAccessibleTextRange findText (in AString aText, in boolean aIsBackward, in boolean aIsIgnoreCase); */
  NS_IMETHOD FindText(const nsAString & aText, bool aIsBackward, bool aIsIgnoreCase, nsIAccessibleTextRange * *_retval) = 0;

  enum {
    AnimationStyleAttr = 0U,
    AnnotationObjectsAttr = 1U,
    AnnotationTypesAttr = 2U,
    BackgroundColorAttr = 3U,
    BulletStyleAttr = 4U,
    CapStyleAttr = 5U,
    CaretBidiModeAttr = 6U,
    CaretPositionAttr = 7U,
    CultureAttr = 8U,
    FontNameAttr = 9U,
    FontSizeAttr = 10U,
    FontWeightAttr = 11U,
    ForegroundColorAttr = 12U,
    HorizontalTextAlignmentAttr = 13U,
    IndentationFirstLineAttr = 14U,
    IndentationLeadingAttr = 15U,
    IndentationTrailingAttr = 16U,
    IsActiveAttr = 17U,
    IsHiddenAttr = 18U,
    IsItalicAttr = 19U,
    IsReadOnlyAttr = 20U,
    IsSubscriptAttr = 21U,
    IsSuperscriptAttr = 22U,
    LinkAttr = 23U,
    MarginBottomAttr = 24U,
    MarginLeadingAttr = 25U,
    MarginTopAttr = 26U,
    MarginTrailingAttr = 27U,
    OutlineStylesAttr = 28U,
    OverlineColorAttr = 29U,
    OverlineStyleAttr = 30U,
    SelectionActiveEndAttr = 31U,
    StrikethroughColorAttr = 32U,
    StrikethroughStyleAttr = 33U,
    StyleIdAttr = 34U,
    StyleNameAttr = 35U,
    TabsAttr = 36U,
    TextFlowDirectionsAttr = 37U,
    UnderlineColorAttr = 38U,
    UnderlineStyleAttr = 39U
  };

  /* nsIAccessibleTextRange findAttr (in unsigned long aAttr, in nsIVariant aValue, in boolean aIsBackward); */
  NS_IMETHOD FindAttr(uint32_t aAttr, nsIVariant *aValue, bool aIsBackward, nsIAccessibleTextRange * *_retval) = 0;

  /* void addToSelection (); */
  NS_IMETHOD AddToSelection(void) = 0;

  /* void removeFromSelection (); */
  NS_IMETHOD RemoveFromSelection(void) = 0;

  /* void select (); */
  NS_IMETHOD Select(void) = 0;

  enum {
    AlignToTop = 0U,
    AlignToBottom = 1U
  };

  /* void scrollIntoView (in unsigned long aHow); */
  NS_IMETHOD ScrollIntoView(uint32_t aHow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTextRange, NS_IACCESSIBLETEXTRANGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETEXTRANGE \
  NS_IMETHOD GetStartContainer(nsIAccessibleText * *aStartContainer) override; \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) override; \
  NS_IMETHOD GetEndContainer(nsIAccessibleText * *aEndContainer) override; \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) override; \
  NS_IMETHOD GetContainer(nsIAccessible * *aContainer) override; \
  NS_IMETHOD GetEmbeddedChildren(nsIArray * *aEmbeddedChildren) override; \
  NS_IMETHOD Compare(nsIAccessibleTextRange *aOtherRange, bool *_retval) override; \
  NS_IMETHOD CompareEndPoints(uint32_t aEndPoint, nsIAccessibleTextRange *aOtherRange, uint32_t aOtherRangeEndPoint, int32_t *_retval) override; \
  NS_IMETHOD GetText(nsAString & aText) override; \
  NS_IMETHOD GetBounds(nsIArray * *aBounds) override; \
  NS_IMETHOD Move(uint32_t aUnit, int32_t aCount) override; \
  NS_IMETHOD MoveStart(uint32_t aUnit, int32_t aCount) override; \
  NS_IMETHOD MoveEnd(uint32_t aUnit, int32_t aCount) override; \
  NS_IMETHOD Normalize(uint32_t aUnit) override; \
  NS_IMETHOD FindText(const nsAString & aText, bool aIsBackward, bool aIsIgnoreCase, nsIAccessibleTextRange * *_retval) override; \
  NS_IMETHOD FindAttr(uint32_t aAttr, nsIVariant *aValue, bool aIsBackward, nsIAccessibleTextRange * *_retval) override; \
  NS_IMETHOD AddToSelection(void) override; \
  NS_IMETHOD RemoveFromSelection(void) override; \
  NS_IMETHOD Select(void) override; \
  NS_IMETHOD ScrollIntoView(uint32_t aHow) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETEXTRANGE(_to) \
  NS_IMETHOD GetStartContainer(nsIAccessibleText * *aStartContainer) override { return _to GetStartContainer(aStartContainer); } \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) override { return _to GetStartOffset(aStartOffset); } \
  NS_IMETHOD GetEndContainer(nsIAccessibleText * *aEndContainer) override { return _to GetEndContainer(aEndContainer); } \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) override { return _to GetEndOffset(aEndOffset); } \
  NS_IMETHOD GetContainer(nsIAccessible * *aContainer) override { return _to GetContainer(aContainer); } \
  NS_IMETHOD GetEmbeddedChildren(nsIArray * *aEmbeddedChildren) override { return _to GetEmbeddedChildren(aEmbeddedChildren); } \
  NS_IMETHOD Compare(nsIAccessibleTextRange *aOtherRange, bool *_retval) override { return _to Compare(aOtherRange, _retval); } \
  NS_IMETHOD CompareEndPoints(uint32_t aEndPoint, nsIAccessibleTextRange *aOtherRange, uint32_t aOtherRangeEndPoint, int32_t *_retval) override { return _to CompareEndPoints(aEndPoint, aOtherRange, aOtherRangeEndPoint, _retval); } \
  NS_IMETHOD GetText(nsAString & aText) override { return _to GetText(aText); } \
  NS_IMETHOD GetBounds(nsIArray * *aBounds) override { return _to GetBounds(aBounds); } \
  NS_IMETHOD Move(uint32_t aUnit, int32_t aCount) override { return _to Move(aUnit, aCount); } \
  NS_IMETHOD MoveStart(uint32_t aUnit, int32_t aCount) override { return _to MoveStart(aUnit, aCount); } \
  NS_IMETHOD MoveEnd(uint32_t aUnit, int32_t aCount) override { return _to MoveEnd(aUnit, aCount); } \
  NS_IMETHOD Normalize(uint32_t aUnit) override { return _to Normalize(aUnit); } \
  NS_IMETHOD FindText(const nsAString & aText, bool aIsBackward, bool aIsIgnoreCase, nsIAccessibleTextRange * *_retval) override { return _to FindText(aText, aIsBackward, aIsIgnoreCase, _retval); } \
  NS_IMETHOD FindAttr(uint32_t aAttr, nsIVariant *aValue, bool aIsBackward, nsIAccessibleTextRange * *_retval) override { return _to FindAttr(aAttr, aValue, aIsBackward, _retval); } \
  NS_IMETHOD AddToSelection(void) override { return _to AddToSelection(); } \
  NS_IMETHOD RemoveFromSelection(void) override { return _to RemoveFromSelection(); } \
  NS_IMETHOD Select(void) override { return _to Select(); } \
  NS_IMETHOD ScrollIntoView(uint32_t aHow) override { return _to ScrollIntoView(aHow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETEXTRANGE(_to) \
  NS_IMETHOD GetStartContainer(nsIAccessibleText * *aStartContainer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartContainer(aStartContainer); } \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartOffset(aStartOffset); } \
  NS_IMETHOD GetEndContainer(nsIAccessibleText * *aEndContainer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndContainer(aEndContainer); } \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndOffset(aEndOffset); } \
  NS_IMETHOD GetContainer(nsIAccessible * *aContainer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainer(aContainer); } \
  NS_IMETHOD GetEmbeddedChildren(nsIArray * *aEmbeddedChildren) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmbeddedChildren(aEmbeddedChildren); } \
  NS_IMETHOD Compare(nsIAccessibleTextRange *aOtherRange, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Compare(aOtherRange, _retval); } \
  NS_IMETHOD CompareEndPoints(uint32_t aEndPoint, nsIAccessibleTextRange *aOtherRange, uint32_t aOtherRangeEndPoint, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareEndPoints(aEndPoint, aOtherRange, aOtherRangeEndPoint, _retval); } \
  NS_IMETHOD GetText(nsAString & aText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD GetBounds(nsIArray * *aBounds) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBounds(aBounds); } \
  NS_IMETHOD Move(uint32_t aUnit, int32_t aCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Move(aUnit, aCount); } \
  NS_IMETHOD MoveStart(uint32_t aUnit, int32_t aCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveStart(aUnit, aCount); } \
  NS_IMETHOD MoveEnd(uint32_t aUnit, int32_t aCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveEnd(aUnit, aCount); } \
  NS_IMETHOD Normalize(uint32_t aUnit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Normalize(aUnit); } \
  NS_IMETHOD FindText(const nsAString & aText, bool aIsBackward, bool aIsIgnoreCase, nsIAccessibleTextRange * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindText(aText, aIsBackward, aIsIgnoreCase, _retval); } \
  NS_IMETHOD FindAttr(uint32_t aAttr, nsIVariant *aValue, bool aIsBackward, nsIAccessibleTextRange * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindAttr(aAttr, aValue, aIsBackward, _retval); } \
  NS_IMETHOD AddToSelection(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddToSelection(); } \
  NS_IMETHOD RemoveFromSelection(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFromSelection(); } \
  NS_IMETHOD Select(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Select(); } \
  NS_IMETHOD ScrollIntoView(uint32_t aHow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollIntoView(aHow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTextRange : public nsIAccessibleTextRange
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETEXTRANGE

  nsAccessibleTextRange();

private:
  ~nsAccessibleTextRange();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessibleTextRange, nsIAccessibleTextRange)

nsAccessibleTextRange::nsAccessibleTextRange()
{
  /* member initializers and constructor code */
}

nsAccessibleTextRange::~nsAccessibleTextRange()
{
  /* destructor code */
}

/* readonly attribute nsIAccessibleText startContainer; */
NS_IMETHODIMP nsAccessibleTextRange::GetStartContainer(nsIAccessibleText * *aStartContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long startOffset; */
NS_IMETHODIMP nsAccessibleTextRange::GetStartOffset(int32_t *aStartOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleText endContainer; */
NS_IMETHODIMP nsAccessibleTextRange::GetEndContainer(nsIAccessibleText * *aEndContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long endOffset; */
NS_IMETHODIMP nsAccessibleTextRange::GetEndOffset(int32_t *aEndOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible container; */
NS_IMETHODIMP nsAccessibleTextRange::GetContainer(nsIAccessible * *aContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray embeddedChildren; */
NS_IMETHODIMP nsAccessibleTextRange::GetEmbeddedChildren(nsIArray * *aEmbeddedChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean compare (in nsIAccessibleTextRange aOtherRange); */
NS_IMETHODIMP nsAccessibleTextRange::Compare(nsIAccessibleTextRange *aOtherRange, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long compareEndPoints (in unsigned long aEndPoint, in nsIAccessibleTextRange aOtherRange, in unsigned long aOtherRangeEndPoint); */
NS_IMETHODIMP nsAccessibleTextRange::CompareEndPoints(uint32_t aEndPoint, nsIAccessibleTextRange *aOtherRange, uint32_t aOtherRangeEndPoint, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString text; */
NS_IMETHODIMP nsAccessibleTextRange::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray bounds; */
NS_IMETHODIMP nsAccessibleTextRange::GetBounds(nsIArray * *aBounds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void move (in unsigned long aUnit, in long aCount); */
NS_IMETHODIMP nsAccessibleTextRange::Move(uint32_t aUnit, int32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveStart (in unsigned long aUnit, in long aCount); */
NS_IMETHODIMP nsAccessibleTextRange::MoveStart(uint32_t aUnit, int32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveEnd (in unsigned long aUnit, in long aCount); */
NS_IMETHODIMP nsAccessibleTextRange::MoveEnd(uint32_t aUnit, int32_t aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void normalize (in unsigned long aUnit); */
NS_IMETHODIMP nsAccessibleTextRange::Normalize(uint32_t aUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleTextRange findText (in AString aText, in boolean aIsBackward, in boolean aIsIgnoreCase); */
NS_IMETHODIMP nsAccessibleTextRange::FindText(const nsAString & aText, bool aIsBackward, bool aIsIgnoreCase, nsIAccessibleTextRange * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleTextRange findAttr (in unsigned long aAttr, in nsIVariant aValue, in boolean aIsBackward); */
NS_IMETHODIMP nsAccessibleTextRange::FindAttr(uint32_t aAttr, nsIVariant *aValue, bool aIsBackward, nsIAccessibleTextRange * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addToSelection (); */
NS_IMETHODIMP nsAccessibleTextRange::AddToSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFromSelection (); */
NS_IMETHODIMP nsAccessibleTextRange::RemoveFromSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void select (); */
NS_IMETHODIMP nsAccessibleTextRange::Select()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollIntoView (in unsigned long aHow); */
NS_IMETHODIMP nsAccessibleTextRange::ScrollIntoView(uint32_t aHow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleTextRange_h__ */
