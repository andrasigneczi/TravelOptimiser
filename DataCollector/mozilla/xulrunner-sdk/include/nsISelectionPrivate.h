/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISelectionPrivate.idl
 */

#ifndef __gen_nsISelectionPrivate_h__
#define __gen_nsISelectionPrivate_h__


#ifndef __gen_nsISelection_h__
#include "nsISelection.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsRange; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsISelectionListener; /* forward declaration */

class nsIContent; /* forward declaration */

class nsINode; /* forward declaration */

class nsIFrame;
struct nsPoint;
struct ScrollAxis;
template<class T> class nsTArray;
#include "nsDirection.h"
#include "nsIPresShell.h" // TODO: Remove this include
#include "mozilla/EventForwards.h"

/* starting interface:    nsISelectionPrivate */
#define NS_ISELECTIONPRIVATE_IID_STR "5a82ee9a-35ce-11e4-8c3e-b7043d68ad70"

#define NS_ISELECTIONPRIVATE_IID \
  {0x5a82ee9a, 0x35ce, 0x11e4, \
    { 0x8c, 0x3e, 0xb7, 0x04, 0x3d, 0x68, 0xad, 0x70 }}

class NS_NO_VTABLE nsISelectionPrivate : public nsISelection {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTIONPRIVATE_IID)

  enum {
    ENDOFPRECEDINGLINE = 0,
    STARTOFNEXTLINE = 1
  };

  /* attribute boolean interlinePosition; */
  NS_IMETHOD GetInterlinePosition(bool *aInterlinePosition) = 0;
  NS_IMETHOD SetInterlinePosition(bool aInterlinePosition) = 0;

  /* [noscript] attribute nsIContent ancestorLimiter; */
  NS_IMETHOD GetAncestorLimiter(nsIContent * *aAncestorLimiter) = 0;
  NS_IMETHOD SetAncestorLimiter(nsIContent *aAncestorLimiter) = 0;

  /* [noscript] void startBatchChanges (); */
  NS_IMETHOD StartBatchChanges(void) = 0;

  /* [noscript] void endBatchChanges (); */
  NS_IMETHOD EndBatchChanges(void) = 0;

  /* DOMString toStringWithFormat (in string formatType, in unsigned long flags, in int32_t wrapColumn); */
  NS_IMETHOD ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval) = 0;

  /* void addSelectionListener (in nsISelectionListener newListener); */
  NS_IMETHOD AddSelectionListener(nsISelectionListener *newListener) = 0;

  /* void removeSelectionListener (in nsISelectionListener listenerToRemove); */
  NS_IMETHOD RemoveSelectionListener(nsISelectionListener *listenerToRemove) = 0;

  enum {
    TABLESELECTION_NONE = 0,
    TABLESELECTION_CELL = 1,
    TABLESELECTION_ROW = 2,
    TABLESELECTION_COLUMN = 3,
    TABLESELECTION_TABLE = 4,
    TABLESELECTION_ALLCELLS = 5
  };

  /* [noscript] long getTableSelectionType (in nsIDOMRange range); */
  NS_IMETHOD GetTableSelectionType(nsIDOMRange *range, int32_t *_retval) = 0;

  /* [noscript] attribute boolean canCacheFrameOffset; */
  NS_IMETHOD GetCanCacheFrameOffset(bool *aCanCacheFrameOffset) = 0;
  NS_IMETHOD SetCanCacheFrameOffset(bool aCanCacheFrameOffset) = 0;

  /* [noscript] void getCachedFrameOffset (in nsIFrame aFrame, in int32_t inOffset, in nsPointRef aPoint); */
  NS_IMETHOD GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint) = 0;

  /* [noscript] void setTextRangeStyle (in nsIDOMRange range, in constTextRangeStyleRef textRangeStyle); */
  NS_IMETHOD SetTextRangeStyle(nsIDOMRange *range, const mozilla::TextRangeStyle & textRangeStyle) = 0;

  /* [noscript,notxpcom] nsDirection getSelectionDirection (); */
  NS_IMETHOD_(nsDirection) GetSelectionDirection(void) = 0;

  /* [noscript,notxpcom] void setSelectionDirection (in nsDirection aDirection); */
  NS_IMETHOD_(void) SetSelectionDirection(nsDirection aDirection) = 0;

  /* readonly attribute short type; */
  NS_IMETHOD GetType(int16_t *aType) = 0;

  /* void GetRangesForInterval (in nsIDOMNode beginNode, in int32_t beginOffset, in nsIDOMNode endNode, in int32_t endOffset, in boolean allowAdjacent, out uint32_t resultCount, [array, size_is (resultCount), retval] out nsIDOMRange results); */
  NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results) = 0;

  /* [noscript] void GetRangesForIntervalArray (in nsINode beginNode, in int32_t beginOffset, in nsINode endNode, in int32_t endOffset, in boolean allowAdjacent, in RangeArray results); */
  NS_IMETHOD GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results) = 0;

  /* void scrollIntoView (in short aRegion, in boolean aIsSynchronous, in int16_t aVPercent, in int16_t aHPercent); */
  NS_IMETHOD ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent) = 0;

  /* [noscript] void scrollIntoViewInternal (in short aRegion, in boolean aIsSynchronous, in ScrollAxis aVertical, in ScrollAxis aHorizontal); */
  NS_IMETHOD ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal) = 0;

  /* [noscript] void selectionLanguageChange (in boolean langRTL); */
  NS_IMETHOD SelectionLanguageChange(bool langRTL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelectionPrivate, NS_ISELECTIONPRIVATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTIONPRIVATE \
  NS_IMETHOD GetInterlinePosition(bool *aInterlinePosition) override; \
  NS_IMETHOD SetInterlinePosition(bool aInterlinePosition) override; \
  NS_IMETHOD GetAncestorLimiter(nsIContent * *aAncestorLimiter) override; \
  NS_IMETHOD SetAncestorLimiter(nsIContent *aAncestorLimiter) override; \
  NS_IMETHOD StartBatchChanges(void) override; \
  NS_IMETHOD EndBatchChanges(void) override; \
  NS_IMETHOD ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval) override; \
  NS_IMETHOD AddSelectionListener(nsISelectionListener *newListener) override; \
  NS_IMETHOD RemoveSelectionListener(nsISelectionListener *listenerToRemove) override; \
  NS_IMETHOD GetTableSelectionType(nsIDOMRange *range, int32_t *_retval) override; \
  NS_IMETHOD GetCanCacheFrameOffset(bool *aCanCacheFrameOffset) override; \
  NS_IMETHOD SetCanCacheFrameOffset(bool aCanCacheFrameOffset) override; \
  NS_IMETHOD GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint) override; \
  NS_IMETHOD SetTextRangeStyle(nsIDOMRange *range, const mozilla::TextRangeStyle & textRangeStyle) override; \
  NS_IMETHOD_(nsDirection) GetSelectionDirection(void) override; \
  NS_IMETHOD_(void) SetSelectionDirection(nsDirection aDirection) override; \
  NS_IMETHOD GetType(int16_t *aType) override; \
  NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results) override; \
  NS_IMETHOD GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results) override; \
  NS_IMETHOD ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent) override; \
  NS_IMETHOD ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal) override; \
  NS_IMETHOD SelectionLanguageChange(bool langRTL) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTIONPRIVATE(_to) \
  NS_IMETHOD GetInterlinePosition(bool *aInterlinePosition) override { return _to GetInterlinePosition(aInterlinePosition); } \
  NS_IMETHOD SetInterlinePosition(bool aInterlinePosition) override { return _to SetInterlinePosition(aInterlinePosition); } \
  NS_IMETHOD GetAncestorLimiter(nsIContent * *aAncestorLimiter) override { return _to GetAncestorLimiter(aAncestorLimiter); } \
  NS_IMETHOD SetAncestorLimiter(nsIContent *aAncestorLimiter) override { return _to SetAncestorLimiter(aAncestorLimiter); } \
  NS_IMETHOD StartBatchChanges(void) override { return _to StartBatchChanges(); } \
  NS_IMETHOD EndBatchChanges(void) override { return _to EndBatchChanges(); } \
  NS_IMETHOD ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval) override { return _to ToStringWithFormat(formatType, flags, wrapColumn, _retval); } \
  NS_IMETHOD AddSelectionListener(nsISelectionListener *newListener) override { return _to AddSelectionListener(newListener); } \
  NS_IMETHOD RemoveSelectionListener(nsISelectionListener *listenerToRemove) override { return _to RemoveSelectionListener(listenerToRemove); } \
  NS_IMETHOD GetTableSelectionType(nsIDOMRange *range, int32_t *_retval) override { return _to GetTableSelectionType(range, _retval); } \
  NS_IMETHOD GetCanCacheFrameOffset(bool *aCanCacheFrameOffset) override { return _to GetCanCacheFrameOffset(aCanCacheFrameOffset); } \
  NS_IMETHOD SetCanCacheFrameOffset(bool aCanCacheFrameOffset) override { return _to SetCanCacheFrameOffset(aCanCacheFrameOffset); } \
  NS_IMETHOD GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint) override { return _to GetCachedFrameOffset(aFrame, inOffset, aPoint); } \
  NS_IMETHOD SetTextRangeStyle(nsIDOMRange *range, const mozilla::TextRangeStyle & textRangeStyle) override { return _to SetTextRangeStyle(range, textRangeStyle); } \
  NS_IMETHOD_(nsDirection) GetSelectionDirection(void) override { return _to GetSelectionDirection(); } \
  NS_IMETHOD_(void) SetSelectionDirection(nsDirection aDirection) override { return _to SetSelectionDirection(aDirection); } \
  NS_IMETHOD GetType(int16_t *aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results) override { return _to GetRangesForInterval(beginNode, beginOffset, endNode, endOffset, allowAdjacent, resultCount, results); } \
  NS_IMETHOD GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results) override { return _to GetRangesForIntervalArray(beginNode, beginOffset, endNode, endOffset, allowAdjacent, results); } \
  NS_IMETHOD ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent) override { return _to ScrollIntoView(aRegion, aIsSynchronous, aVPercent, aHPercent); } \
  NS_IMETHOD ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal) override { return _to ScrollIntoViewInternal(aRegion, aIsSynchronous, aVertical, aHorizontal); } \
  NS_IMETHOD SelectionLanguageChange(bool langRTL) override { return _to SelectionLanguageChange(langRTL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTIONPRIVATE(_to) \
  NS_IMETHOD GetInterlinePosition(bool *aInterlinePosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterlinePosition(aInterlinePosition); } \
  NS_IMETHOD SetInterlinePosition(bool aInterlinePosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInterlinePosition(aInterlinePosition); } \
  NS_IMETHOD GetAncestorLimiter(nsIContent * *aAncestorLimiter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAncestorLimiter(aAncestorLimiter); } \
  NS_IMETHOD SetAncestorLimiter(nsIContent *aAncestorLimiter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAncestorLimiter(aAncestorLimiter); } \
  NS_IMETHOD StartBatchChanges(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartBatchChanges(); } \
  NS_IMETHOD EndBatchChanges(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EndBatchChanges(); } \
  NS_IMETHOD ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ToStringWithFormat(formatType, flags, wrapColumn, _retval); } \
  NS_IMETHOD AddSelectionListener(nsISelectionListener *newListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSelectionListener(newListener); } \
  NS_IMETHOD RemoveSelectionListener(nsISelectionListener *listenerToRemove) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSelectionListener(listenerToRemove); } \
  NS_IMETHOD GetTableSelectionType(nsIDOMRange *range, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTableSelectionType(range, _retval); } \
  NS_IMETHOD GetCanCacheFrameOffset(bool *aCanCacheFrameOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanCacheFrameOffset(aCanCacheFrameOffset); } \
  NS_IMETHOD SetCanCacheFrameOffset(bool aCanCacheFrameOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCanCacheFrameOffset(aCanCacheFrameOffset); } \
  NS_IMETHOD GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedFrameOffset(aFrame, inOffset, aPoint); } \
  NS_IMETHOD SetTextRangeStyle(nsIDOMRange *range, const mozilla::TextRangeStyle & textRangeStyle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextRangeStyle(range, textRangeStyle); } \
  NS_IMETHOD_(nsDirection) GetSelectionDirection(void) override; \
  NS_IMETHOD_(void) SetSelectionDirection(nsDirection aDirection) override; \
  NS_IMETHOD GetType(int16_t *aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangesForInterval(beginNode, beginOffset, endNode, endOffset, allowAdjacent, resultCount, results); } \
  NS_IMETHOD GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRangesForIntervalArray(beginNode, beginOffset, endNode, endOffset, allowAdjacent, results); } \
  NS_IMETHOD ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollIntoView(aRegion, aIsSynchronous, aVPercent, aHPercent); } \
  NS_IMETHOD ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollIntoViewInternal(aRegion, aIsSynchronous, aVertical, aHorizontal); } \
  NS_IMETHOD SelectionLanguageChange(bool langRTL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectionLanguageChange(langRTL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelectionPrivate : public nsISelectionPrivate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTIONPRIVATE

  nsSelectionPrivate();

private:
  ~nsSelectionPrivate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSelectionPrivate, nsISelectionPrivate)

nsSelectionPrivate::nsSelectionPrivate()
{
  /* member initializers and constructor code */
}

nsSelectionPrivate::~nsSelectionPrivate()
{
  /* destructor code */
}

/* attribute boolean interlinePosition; */
NS_IMETHODIMP nsSelectionPrivate::GetInterlinePosition(bool *aInterlinePosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSelectionPrivate::SetInterlinePosition(bool aInterlinePosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIContent ancestorLimiter; */
NS_IMETHODIMP nsSelectionPrivate::GetAncestorLimiter(nsIContent * *aAncestorLimiter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSelectionPrivate::SetAncestorLimiter(nsIContent *aAncestorLimiter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void startBatchChanges (); */
NS_IMETHODIMP nsSelectionPrivate::StartBatchChanges()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void endBatchChanges (); */
NS_IMETHODIMP nsSelectionPrivate::EndBatchChanges()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toStringWithFormat (in string formatType, in unsigned long flags, in int32_t wrapColumn); */
NS_IMETHODIMP nsSelectionPrivate::ToStringWithFormat(const char * formatType, uint32_t flags, int32_t wrapColumn, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSelectionListener (in nsISelectionListener newListener); */
NS_IMETHODIMP nsSelectionPrivate::AddSelectionListener(nsISelectionListener *newListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSelectionListener (in nsISelectionListener listenerToRemove); */
NS_IMETHODIMP nsSelectionPrivate::RemoveSelectionListener(nsISelectionListener *listenerToRemove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long getTableSelectionType (in nsIDOMRange range); */
NS_IMETHODIMP nsSelectionPrivate::GetTableSelectionType(nsIDOMRange *range, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute boolean canCacheFrameOffset; */
NS_IMETHODIMP nsSelectionPrivate::GetCanCacheFrameOffset(bool *aCanCacheFrameOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSelectionPrivate::SetCanCacheFrameOffset(bool aCanCacheFrameOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getCachedFrameOffset (in nsIFrame aFrame, in int32_t inOffset, in nsPointRef aPoint); */
NS_IMETHODIMP nsSelectionPrivate::GetCachedFrameOffset(nsIFrame *aFrame, int32_t inOffset, nsPoint & aPoint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setTextRangeStyle (in nsIDOMRange range, in constTextRangeStyleRef textRangeStyle); */
NS_IMETHODIMP nsSelectionPrivate::SetTextRangeStyle(nsIDOMRange *range, const mozilla::TextRangeStyle & textRangeStyle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] nsDirection getSelectionDirection (); */
NS_IMETHODIMP_(nsDirection) nsSelectionPrivate::GetSelectionDirection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void setSelectionDirection (in nsDirection aDirection); */
NS_IMETHODIMP_(void) nsSelectionPrivate::SetSelectionDirection(nsDirection aDirection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short type; */
NS_IMETHODIMP nsSelectionPrivate::GetType(int16_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetRangesForInterval (in nsIDOMNode beginNode, in int32_t beginOffset, in nsIDOMNode endNode, in int32_t endOffset, in boolean allowAdjacent, out uint32_t resultCount, [array, size_is (resultCount), retval] out nsIDOMRange results); */
NS_IMETHODIMP nsSelectionPrivate::GetRangesForInterval(nsIDOMNode *beginNode, int32_t beginOffset, nsIDOMNode *endNode, int32_t endOffset, bool allowAdjacent, uint32_t *resultCount, nsIDOMRange * **results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetRangesForIntervalArray (in nsINode beginNode, in int32_t beginOffset, in nsINode endNode, in int32_t endOffset, in boolean allowAdjacent, in RangeArray results); */
NS_IMETHODIMP nsSelectionPrivate::GetRangesForIntervalArray(nsINode *beginNode, int32_t beginOffset, nsINode *endNode, int32_t endOffset, bool allowAdjacent, nsTArray<nsRange*> *results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollIntoView (in short aRegion, in boolean aIsSynchronous, in int16_t aVPercent, in int16_t aHPercent); */
NS_IMETHODIMP nsSelectionPrivate::ScrollIntoView(int16_t aRegion, bool aIsSynchronous, int16_t aVPercent, int16_t aHPercent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void scrollIntoViewInternal (in short aRegion, in boolean aIsSynchronous, in ScrollAxis aVertical, in ScrollAxis aHorizontal); */
NS_IMETHODIMP nsSelectionPrivate::ScrollIntoViewInternal(int16_t aRegion, bool aIsSynchronous, nsIPresShell::ScrollAxis aVertical, nsIPresShell::ScrollAxis aHorizontal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void selectionLanguageChange (in boolean langRTL); */
NS_IMETHODIMP nsSelectionPrivate::SelectionLanguageChange(bool langRTL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISelectionPrivate_h__ */
