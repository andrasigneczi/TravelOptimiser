/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessiblePivot.idl
 */

#ifndef __gen_nsIAccessiblePivot_h__
#define __gen_nsIAccessiblePivot_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef int16_t  TextBoundaryType;

typedef int16_t  PivotMoveReason;

class nsIAccessible; /* forward declaration */

class nsIAccessibleText; /* forward declaration */

class nsIAccessibleTraversalRule; /* forward declaration */

class nsIAccessiblePivotObserver; /* forward declaration */


/* starting interface:    nsIAccessiblePivot */
#define NS_IACCESSIBLEPIVOT_IID_STR "81fe5144-059b-42db-bd3a-f6ce3158d5e9"

#define NS_IACCESSIBLEPIVOT_IID \
  {0x81fe5144, 0x059b, 0x42db, \
    { 0xbd, 0x3a, 0xf6, 0xce, 0x31, 0x58, 0xd5, 0xe9 }}

class NS_NO_VTABLE nsIAccessiblePivot : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEPIVOT_IID)

  enum {
    CHAR_BOUNDARY = 0,
    WORD_BOUNDARY = 1,
    LINE_BOUNDARY = 2,
    ATTRIBUTE_RANGE_BOUNDARY = 3,
    REASON_NONE = 0,
    REASON_NEXT = 1,
    REASON_PREV = 2,
    REASON_FIRST = 3,
    REASON_LAST = 4,
    REASON_TEXT = 5,
    REASON_POINT = 6
  };

  /* attribute nsIAccessible position; */
  NS_IMETHOD GetPosition(nsIAccessible * *aPosition) = 0;
  NS_IMETHOD SetPosition(nsIAccessible *aPosition) = 0;

  /* readonly attribute nsIAccessible root; */
  NS_IMETHOD GetRoot(nsIAccessible * *aRoot) = 0;

  /* attribute nsIAccessible modalRoot; */
  NS_IMETHOD GetModalRoot(nsIAccessible * *aModalRoot) = 0;
  NS_IMETHOD SetModalRoot(nsIAccessible *aModalRoot) = 0;

  /* readonly attribute long startOffset; */
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) = 0;

  /* readonly attribute long endOffset; */
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) = 0;

  /* [optional_argc] void setTextRange (in nsIAccessibleText aTextAccessible, in long aStartOffset, in long aEndOffset, [optional] in boolean aIsFromUserInput); */
  NS_IMETHOD SetTextRange(nsIAccessibleText *aTextAccessible, int32_t aStartOffset, int32_t aEndOffset, bool aIsFromUserInput, uint8_t _argc) = 0;

  /* [optional_argc] boolean moveNext (in nsIAccessibleTraversalRule aRule, [optional] in nsIAccessible aAnchor, [optional] in boolean aIncludeStart, [optional] in boolean aIsFromUserInput); */
  NS_IMETHOD MoveNext(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval) = 0;

  /* [optional_argc] boolean movePrevious (in nsIAccessibleTraversalRule aRule, [optional] in nsIAccessible aAnchor, [optional] in boolean aIncludeStart, [optional] in boolean aIsFromUserInput); */
  NS_IMETHOD MovePrevious(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval) = 0;

  /* [optional_argc] boolean moveFirst (in nsIAccessibleTraversalRule aRule, [optional] in boolean aIsFromUserInput); */
  NS_IMETHOD MoveFirst(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval) = 0;

  /* [optional_argc] boolean moveLast (in nsIAccessibleTraversalRule aRule, [optional] in boolean aIsFromUserInput); */
  NS_IMETHOD MoveLast(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval) = 0;

  /* [optional_argc] boolean moveNextByText (in TextBoundaryType aBoundary, [optional] in boolean aIsFromUserInput); */
  NS_IMETHOD MoveNextByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval) = 0;

  /* [optional_argc] boolean movePreviousByText (in TextBoundaryType aBoundary, [optional] in boolean aIsFromUserInput); */
  NS_IMETHOD MovePreviousByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval) = 0;

  /* [optional_argc] boolean moveToPoint (in nsIAccessibleTraversalRule aRule, in long aX, in long aY, in boolean aIgnoreNoMatch, [optional] in boolean aIsFromUserInput); */
  NS_IMETHOD MoveToPoint(nsIAccessibleTraversalRule *aRule, int32_t aX, int32_t aY, bool aIgnoreNoMatch, bool aIsFromUserInput, uint8_t _argc, bool *_retval) = 0;

  /* void addObserver (in nsIAccessiblePivotObserver aObserver); */
  NS_IMETHOD AddObserver(nsIAccessiblePivotObserver *aObserver) = 0;

  /* void removeObserver (in nsIAccessiblePivotObserver aObserver); */
  NS_IMETHOD RemoveObserver(nsIAccessiblePivotObserver *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessiblePivot, NS_IACCESSIBLEPIVOT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEPIVOT \
  NS_IMETHOD GetPosition(nsIAccessible * *aPosition) override; \
  NS_IMETHOD SetPosition(nsIAccessible *aPosition) override; \
  NS_IMETHOD GetRoot(nsIAccessible * *aRoot) override; \
  NS_IMETHOD GetModalRoot(nsIAccessible * *aModalRoot) override; \
  NS_IMETHOD SetModalRoot(nsIAccessible *aModalRoot) override; \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) override; \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) override; \
  NS_IMETHOD SetTextRange(nsIAccessibleText *aTextAccessible, int32_t aStartOffset, int32_t aEndOffset, bool aIsFromUserInput, uint8_t _argc) override; \
  NS_IMETHOD MoveNext(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override; \
  NS_IMETHOD MovePrevious(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override; \
  NS_IMETHOD MoveFirst(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override; \
  NS_IMETHOD MoveLast(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override; \
  NS_IMETHOD MoveNextByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override; \
  NS_IMETHOD MovePreviousByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override; \
  NS_IMETHOD MoveToPoint(nsIAccessibleTraversalRule *aRule, int32_t aX, int32_t aY, bool aIgnoreNoMatch, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override; \
  NS_IMETHOD AddObserver(nsIAccessiblePivotObserver *aObserver) override; \
  NS_IMETHOD RemoveObserver(nsIAccessiblePivotObserver *aObserver) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEPIVOT(_to) \
  NS_IMETHOD GetPosition(nsIAccessible * *aPosition) override { return _to GetPosition(aPosition); } \
  NS_IMETHOD SetPosition(nsIAccessible *aPosition) override { return _to SetPosition(aPosition); } \
  NS_IMETHOD GetRoot(nsIAccessible * *aRoot) override { return _to GetRoot(aRoot); } \
  NS_IMETHOD GetModalRoot(nsIAccessible * *aModalRoot) override { return _to GetModalRoot(aModalRoot); } \
  NS_IMETHOD SetModalRoot(nsIAccessible *aModalRoot) override { return _to SetModalRoot(aModalRoot); } \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) override { return _to GetStartOffset(aStartOffset); } \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) override { return _to GetEndOffset(aEndOffset); } \
  NS_IMETHOD SetTextRange(nsIAccessibleText *aTextAccessible, int32_t aStartOffset, int32_t aEndOffset, bool aIsFromUserInput, uint8_t _argc) override { return _to SetTextRange(aTextAccessible, aStartOffset, aEndOffset, aIsFromUserInput, _argc); } \
  NS_IMETHOD MoveNext(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return _to MoveNext(aRule, aAnchor, aIncludeStart, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MovePrevious(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return _to MovePrevious(aRule, aAnchor, aIncludeStart, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MoveFirst(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return _to MoveFirst(aRule, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MoveLast(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return _to MoveLast(aRule, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MoveNextByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return _to MoveNextByText(aBoundary, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MovePreviousByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return _to MovePreviousByText(aBoundary, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MoveToPoint(nsIAccessibleTraversalRule *aRule, int32_t aX, int32_t aY, bool aIgnoreNoMatch, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return _to MoveToPoint(aRule, aX, aY, aIgnoreNoMatch, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD AddObserver(nsIAccessiblePivotObserver *aObserver) override { return _to AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(nsIAccessiblePivotObserver *aObserver) override { return _to RemoveObserver(aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEPIVOT(_to) \
  NS_IMETHOD GetPosition(nsIAccessible * *aPosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPosition(aPosition); } \
  NS_IMETHOD SetPosition(nsIAccessible *aPosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPosition(aPosition); } \
  NS_IMETHOD GetRoot(nsIAccessible * *aRoot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_IMETHOD GetModalRoot(nsIAccessible * *aModalRoot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModalRoot(aModalRoot); } \
  NS_IMETHOD SetModalRoot(nsIAccessible *aModalRoot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetModalRoot(aModalRoot); } \
  NS_IMETHOD GetStartOffset(int32_t *aStartOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartOffset(aStartOffset); } \
  NS_IMETHOD GetEndOffset(int32_t *aEndOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndOffset(aEndOffset); } \
  NS_IMETHOD SetTextRange(nsIAccessibleText *aTextAccessible, int32_t aStartOffset, int32_t aEndOffset, bool aIsFromUserInput, uint8_t _argc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextRange(aTextAccessible, aStartOffset, aEndOffset, aIsFromUserInput, _argc); } \
  NS_IMETHOD MoveNext(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveNext(aRule, aAnchor, aIncludeStart, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MovePrevious(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MovePrevious(aRule, aAnchor, aIncludeStart, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MoveFirst(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveFirst(aRule, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MoveLast(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveLast(aRule, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MoveNextByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveNextByText(aBoundary, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MovePreviousByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MovePreviousByText(aBoundary, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD MoveToPoint(nsIAccessibleTraversalRule *aRule, int32_t aX, int32_t aY, bool aIgnoreNoMatch, bool aIsFromUserInput, uint8_t _argc, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveToPoint(aRule, aX, aY, aIgnoreNoMatch, aIsFromUserInput, _argc, _retval); } \
  NS_IMETHOD AddObserver(nsIAccessiblePivotObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(nsIAccessiblePivotObserver *aObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessiblePivot : public nsIAccessiblePivot
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEPIVOT

  nsAccessiblePivot();

private:
  ~nsAccessiblePivot();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessiblePivot, nsIAccessiblePivot)

nsAccessiblePivot::nsAccessiblePivot()
{
  /* member initializers and constructor code */
}

nsAccessiblePivot::~nsAccessiblePivot()
{
  /* destructor code */
}

/* attribute nsIAccessible position; */
NS_IMETHODIMP nsAccessiblePivot::GetPosition(nsIAccessible * *aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAccessiblePivot::SetPosition(nsIAccessible *aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessible root; */
NS_IMETHODIMP nsAccessiblePivot::GetRoot(nsIAccessible * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIAccessible modalRoot; */
NS_IMETHODIMP nsAccessiblePivot::GetModalRoot(nsIAccessible * *aModalRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAccessiblePivot::SetModalRoot(nsIAccessible *aModalRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long startOffset; */
NS_IMETHODIMP nsAccessiblePivot::GetStartOffset(int32_t *aStartOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long endOffset; */
NS_IMETHODIMP nsAccessiblePivot::GetEndOffset(int32_t *aEndOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void setTextRange (in nsIAccessibleText aTextAccessible, in long aStartOffset, in long aEndOffset, [optional] in boolean aIsFromUserInput); */
NS_IMETHODIMP nsAccessiblePivot::SetTextRange(nsIAccessibleText *aTextAccessible, int32_t aStartOffset, int32_t aEndOffset, bool aIsFromUserInput, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean moveNext (in nsIAccessibleTraversalRule aRule, [optional] in nsIAccessible aAnchor, [optional] in boolean aIncludeStart, [optional] in boolean aIsFromUserInput); */
NS_IMETHODIMP nsAccessiblePivot::MoveNext(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean movePrevious (in nsIAccessibleTraversalRule aRule, [optional] in nsIAccessible aAnchor, [optional] in boolean aIncludeStart, [optional] in boolean aIsFromUserInput); */
NS_IMETHODIMP nsAccessiblePivot::MovePrevious(nsIAccessibleTraversalRule *aRule, nsIAccessible *aAnchor, bool aIncludeStart, bool aIsFromUserInput, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean moveFirst (in nsIAccessibleTraversalRule aRule, [optional] in boolean aIsFromUserInput); */
NS_IMETHODIMP nsAccessiblePivot::MoveFirst(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean moveLast (in nsIAccessibleTraversalRule aRule, [optional] in boolean aIsFromUserInput); */
NS_IMETHODIMP nsAccessiblePivot::MoveLast(nsIAccessibleTraversalRule *aRule, bool aIsFromUserInput, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean moveNextByText (in TextBoundaryType aBoundary, [optional] in boolean aIsFromUserInput); */
NS_IMETHODIMP nsAccessiblePivot::MoveNextByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean movePreviousByText (in TextBoundaryType aBoundary, [optional] in boolean aIsFromUserInput); */
NS_IMETHODIMP nsAccessiblePivot::MovePreviousByText(TextBoundaryType aBoundary, bool aIsFromUserInput, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean moveToPoint (in nsIAccessibleTraversalRule aRule, in long aX, in long aY, in boolean aIgnoreNoMatch, [optional] in boolean aIsFromUserInput); */
NS_IMETHODIMP nsAccessiblePivot::MoveToPoint(nsIAccessibleTraversalRule *aRule, int32_t aX, int32_t aY, bool aIgnoreNoMatch, bool aIsFromUserInput, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsIAccessiblePivotObserver aObserver); */
NS_IMETHODIMP nsAccessiblePivot::AddObserver(nsIAccessiblePivotObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIAccessiblePivotObserver aObserver); */
NS_IMETHODIMP nsAccessiblePivot::RemoveObserver(nsIAccessiblePivotObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccessiblePivotObserver */
#define NS_IACCESSIBLEPIVOTOBSERVER_IID_STR "6006e502-3861-49bd-aba1-fa6d2e74e237"

#define NS_IACCESSIBLEPIVOTOBSERVER_IID \
  {0x6006e502, 0x3861, 0x49bd, \
    { 0xab, 0xa1, 0xfa, 0x6d, 0x2e, 0x74, 0xe2, 0x37 }}

class NS_NO_VTABLE nsIAccessiblePivotObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEPIVOTOBSERVER_IID)

  /* void onPivotChanged (in nsIAccessiblePivot aPivot, in nsIAccessible aOldAccessible, in long aOldStart, in long aOldEnd, in PivotMoveReason aReason, in boolean aIsFromUserInput); */
  NS_IMETHOD OnPivotChanged(nsIAccessiblePivot *aPivot, nsIAccessible *aOldAccessible, int32_t aOldStart, int32_t aOldEnd, PivotMoveReason aReason, bool aIsFromUserInput) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessiblePivotObserver, NS_IACCESSIBLEPIVOTOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEPIVOTOBSERVER \
  NS_IMETHOD OnPivotChanged(nsIAccessiblePivot *aPivot, nsIAccessible *aOldAccessible, int32_t aOldStart, int32_t aOldEnd, PivotMoveReason aReason, bool aIsFromUserInput) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEPIVOTOBSERVER(_to) \
  NS_IMETHOD OnPivotChanged(nsIAccessiblePivot *aPivot, nsIAccessible *aOldAccessible, int32_t aOldStart, int32_t aOldEnd, PivotMoveReason aReason, bool aIsFromUserInput) override { return _to OnPivotChanged(aPivot, aOldAccessible, aOldStart, aOldEnd, aReason, aIsFromUserInput); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEPIVOTOBSERVER(_to) \
  NS_IMETHOD OnPivotChanged(nsIAccessiblePivot *aPivot, nsIAccessible *aOldAccessible, int32_t aOldStart, int32_t aOldEnd, PivotMoveReason aReason, bool aIsFromUserInput) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPivotChanged(aPivot, aOldAccessible, aOldStart, aOldEnd, aReason, aIsFromUserInput); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessiblePivotObserver : public nsIAccessiblePivotObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEPIVOTOBSERVER

  nsAccessiblePivotObserver();

private:
  ~nsAccessiblePivotObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessiblePivotObserver, nsIAccessiblePivotObserver)

nsAccessiblePivotObserver::nsAccessiblePivotObserver()
{
  /* member initializers and constructor code */
}

nsAccessiblePivotObserver::~nsAccessiblePivotObserver()
{
  /* destructor code */
}

/* void onPivotChanged (in nsIAccessiblePivot aPivot, in nsIAccessible aOldAccessible, in long aOldStart, in long aOldEnd, in PivotMoveReason aReason, in boolean aIsFromUserInput); */
NS_IMETHODIMP nsAccessiblePivotObserver::OnPivotChanged(nsIAccessiblePivot *aPivot, nsIAccessible *aOldAccessible, int32_t aOldStart, int32_t aOldEnd, PivotMoveReason aReason, bool aIsFromUserInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccessibleTraversalRule */
#define NS_IACCESSIBLETRAVERSALRULE_IID_STR "e197460d-1eff-4247-b4bb-a43be1840dae"

#define NS_IACCESSIBLETRAVERSALRULE_IID \
  {0xe197460d, 0x1eff, 0x4247, \
    { 0xb4, 0xbb, 0xa4, 0x3b, 0xe1, 0x84, 0x0d, 0xae }}

class NS_NO_VTABLE nsIAccessibleTraversalRule : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLETRAVERSALRULE_IID)

  enum {
    FILTER_IGNORE = 0U,
    FILTER_MATCH = 1U,
    FILTER_IGNORE_SUBTREE = 2U,
    PREFILTER_INVISIBLE = 1U,
    PREFILTER_OFFSCREEN = 2U,
    PREFILTER_NOT_FOCUSABLE = 4U,
    PREFILTER_ARIA_HIDDEN = 8U,
    PREFILTER_TRANSPARENT = 16U
  };

  /* readonly attribute unsigned long preFilter; */
  NS_IMETHOD GetPreFilter(uint32_t *aPreFilter) = 0;

  /* void getMatchRoles ([array, size_is (aCount)] out unsigned long aRoles, [retval] out unsigned long aCount); */
  NS_IMETHOD GetMatchRoles(uint32_t **aRoles, uint32_t *aCount) = 0;

  /* unsigned short match (in nsIAccessible aAccessible); */
  NS_IMETHOD Match(nsIAccessible *aAccessible, uint16_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleTraversalRule, NS_IACCESSIBLETRAVERSALRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLETRAVERSALRULE \
  NS_IMETHOD GetPreFilter(uint32_t *aPreFilter) override; \
  NS_IMETHOD GetMatchRoles(uint32_t **aRoles, uint32_t *aCount) override; \
  NS_IMETHOD Match(nsIAccessible *aAccessible, uint16_t *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLETRAVERSALRULE(_to) \
  NS_IMETHOD GetPreFilter(uint32_t *aPreFilter) override { return _to GetPreFilter(aPreFilter); } \
  NS_IMETHOD GetMatchRoles(uint32_t **aRoles, uint32_t *aCount) override { return _to GetMatchRoles(aRoles, aCount); } \
  NS_IMETHOD Match(nsIAccessible *aAccessible, uint16_t *_retval) override { return _to Match(aAccessible, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLETRAVERSALRULE(_to) \
  NS_IMETHOD GetPreFilter(uint32_t *aPreFilter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreFilter(aPreFilter); } \
  NS_IMETHOD GetMatchRoles(uint32_t **aRoles, uint32_t *aCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatchRoles(aRoles, aCount); } \
  NS_IMETHOD Match(nsIAccessible *aAccessible, uint16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Match(aAccessible, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleTraversalRule : public nsIAccessibleTraversalRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLETRAVERSALRULE

  nsAccessibleTraversalRule();

private:
  ~nsAccessibleTraversalRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessibleTraversalRule, nsIAccessibleTraversalRule)

nsAccessibleTraversalRule::nsAccessibleTraversalRule()
{
  /* member initializers and constructor code */
}

nsAccessibleTraversalRule::~nsAccessibleTraversalRule()
{
  /* destructor code */
}

/* readonly attribute unsigned long preFilter; */
NS_IMETHODIMP nsAccessibleTraversalRule::GetPreFilter(uint32_t *aPreFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMatchRoles ([array, size_is (aCount)] out unsigned long aRoles, [retval] out unsigned long aCount); */
NS_IMETHODIMP nsAccessibleTraversalRule::GetMatchRoles(uint32_t **aRoles, uint32_t *aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short match (in nsIAccessible aAccessible); */
NS_IMETHODIMP nsAccessibleTraversalRule::Match(nsIAccessible *aAccessible, uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessiblePivot_h__ */
