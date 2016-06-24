/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITypeAheadFind.idl
 */

#ifndef __gen_nsITypeAheadFind_h__
#define __gen_nsITypeAheadFind_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */


/* starting interface:    nsITypeAheadFind */
#define NS_ITYPEAHEADFIND_IID_STR "f4411c5b-761b-498c-8050-dcfc8311f69e"

#define NS_ITYPEAHEADFIND_IID \
  {0xf4411c5b, 0x761b, 0x498c, \
    { 0x80, 0x50, 0xdc, 0xfc, 0x83, 0x11, 0xf6, 0x9e }}

class NS_NO_VTABLE nsITypeAheadFind : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITYPEAHEADFIND_IID)

  /* void init (in nsIDocShell aDocShell); */
  NS_IMETHOD Init(nsIDocShell *aDocShell) = 0;

  /* unsigned short find (in AString aSearchString, in boolean aLinksOnly); */
  NS_IMETHOD Find(const nsAString & aSearchString, bool aLinksOnly, uint16_t *_retval) = 0;

  /* unsigned short findAgain (in boolean findBackwards, in boolean aLinksOnly); */
  NS_IMETHOD FindAgain(bool findBackwards, bool aLinksOnly, uint16_t *_retval) = 0;

  /* nsIDOMRange getFoundRange (); */
  NS_IMETHOD GetFoundRange(nsIDOMRange * *_retval) = 0;

  /* void setDocShell (in nsIDocShell aDocShell); */
  NS_IMETHOD SetDocShell(nsIDocShell *aDocShell) = 0;

  /* void setSelectionModeAndRepaint (in short toggle); */
  NS_IMETHOD SetSelectionModeAndRepaint(int16_t toggle) = 0;

  /* void collapseSelection (); */
  NS_IMETHOD CollapseSelection(void) = 0;

  /* boolean isRangeVisible (in nsIDOMRange aRange, in boolean aMustBeInViewPort); */
  NS_IMETHOD IsRangeVisible(nsIDOMRange *aRange, bool aMustBeInViewPort, bool *_retval) = 0;

  /* readonly attribute AString searchString; */
  NS_IMETHOD GetSearchString(nsAString & aSearchString) = 0;

  /* attribute boolean caseSensitive; */
  NS_IMETHOD GetCaseSensitive(bool *aCaseSensitive) = 0;
  NS_IMETHOD SetCaseSensitive(bool aCaseSensitive) = 0;

  /* readonly attribute nsIDOMElement foundLink; */
  NS_IMETHOD GetFoundLink(nsIDOMElement * *aFoundLink) = 0;

  /* readonly attribute nsIDOMElement foundEditable; */
  NS_IMETHOD GetFoundEditable(nsIDOMElement * *aFoundEditable) = 0;

  /* readonly attribute nsIDOMWindow currentWindow; */
  NS_IMETHOD GetCurrentWindow(nsIDOMWindow * *aCurrentWindow) = 0;

  enum {
    FIND_FOUND = 0U,
    FIND_NOTFOUND = 1U,
    FIND_WRAPPED = 2U,
    FIND_PENDING = 3U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITypeAheadFind, NS_ITYPEAHEADFIND_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITYPEAHEADFIND \
  NS_IMETHOD Init(nsIDocShell *aDocShell) override; \
  NS_IMETHOD Find(const nsAString & aSearchString, bool aLinksOnly, uint16_t *_retval) override; \
  NS_IMETHOD FindAgain(bool findBackwards, bool aLinksOnly, uint16_t *_retval) override; \
  NS_IMETHOD GetFoundRange(nsIDOMRange * *_retval) override; \
  NS_IMETHOD SetDocShell(nsIDocShell *aDocShell) override; \
  NS_IMETHOD SetSelectionModeAndRepaint(int16_t toggle) override; \
  NS_IMETHOD CollapseSelection(void) override; \
  NS_IMETHOD IsRangeVisible(nsIDOMRange *aRange, bool aMustBeInViewPort, bool *_retval) override; \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) override; \
  NS_IMETHOD GetCaseSensitive(bool *aCaseSensitive) override; \
  NS_IMETHOD SetCaseSensitive(bool aCaseSensitive) override; \
  NS_IMETHOD GetFoundLink(nsIDOMElement * *aFoundLink) override; \
  NS_IMETHOD GetFoundEditable(nsIDOMElement * *aFoundEditable) override; \
  NS_IMETHOD GetCurrentWindow(nsIDOMWindow * *aCurrentWindow) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITYPEAHEADFIND(_to) \
  NS_IMETHOD Init(nsIDocShell *aDocShell) override { return _to Init(aDocShell); } \
  NS_IMETHOD Find(const nsAString & aSearchString, bool aLinksOnly, uint16_t *_retval) override { return _to Find(aSearchString, aLinksOnly, _retval); } \
  NS_IMETHOD FindAgain(bool findBackwards, bool aLinksOnly, uint16_t *_retval) override { return _to FindAgain(findBackwards, aLinksOnly, _retval); } \
  NS_IMETHOD GetFoundRange(nsIDOMRange * *_retval) override { return _to GetFoundRange(_retval); } \
  NS_IMETHOD SetDocShell(nsIDocShell *aDocShell) override { return _to SetDocShell(aDocShell); } \
  NS_IMETHOD SetSelectionModeAndRepaint(int16_t toggle) override { return _to SetSelectionModeAndRepaint(toggle); } \
  NS_IMETHOD CollapseSelection(void) override { return _to CollapseSelection(); } \
  NS_IMETHOD IsRangeVisible(nsIDOMRange *aRange, bool aMustBeInViewPort, bool *_retval) override { return _to IsRangeVisible(aRange, aMustBeInViewPort, _retval); } \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) override { return _to GetSearchString(aSearchString); } \
  NS_IMETHOD GetCaseSensitive(bool *aCaseSensitive) override { return _to GetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD SetCaseSensitive(bool aCaseSensitive) override { return _to SetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD GetFoundLink(nsIDOMElement * *aFoundLink) override { return _to GetFoundLink(aFoundLink); } \
  NS_IMETHOD GetFoundEditable(nsIDOMElement * *aFoundEditable) override { return _to GetFoundEditable(aFoundEditable); } \
  NS_IMETHOD GetCurrentWindow(nsIDOMWindow * *aCurrentWindow) override { return _to GetCurrentWindow(aCurrentWindow); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITYPEAHEADFIND(_to) \
  NS_IMETHOD Init(nsIDocShell *aDocShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aDocShell); } \
  NS_IMETHOD Find(const nsAString & aSearchString, bool aLinksOnly, uint16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Find(aSearchString, aLinksOnly, _retval); } \
  NS_IMETHOD FindAgain(bool findBackwards, bool aLinksOnly, uint16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindAgain(findBackwards, aLinksOnly, _retval); } \
  NS_IMETHOD GetFoundRange(nsIDOMRange * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFoundRange(_retval); } \
  NS_IMETHOD SetDocShell(nsIDocShell *aDocShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocShell(aDocShell); } \
  NS_IMETHOD SetSelectionModeAndRepaint(int16_t toggle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectionModeAndRepaint(toggle); } \
  NS_IMETHOD CollapseSelection(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CollapseSelection(); } \
  NS_IMETHOD IsRangeVisible(nsIDOMRange *aRange, bool aMustBeInViewPort, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsRangeVisible(aRange, aMustBeInViewPort, _retval); } \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchString(aSearchString); } \
  NS_IMETHOD GetCaseSensitive(bool *aCaseSensitive) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD SetCaseSensitive(bool aCaseSensitive) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaseSensitive(aCaseSensitive); } \
  NS_IMETHOD GetFoundLink(nsIDOMElement * *aFoundLink) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFoundLink(aFoundLink); } \
  NS_IMETHOD GetFoundEditable(nsIDOMElement * *aFoundEditable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFoundEditable(aFoundEditable); } \
  NS_IMETHOD GetCurrentWindow(nsIDOMWindow * *aCurrentWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentWindow(aCurrentWindow); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTypeAheadFind : public nsITypeAheadFind
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITYPEAHEADFIND

  nsTypeAheadFind();

private:
  ~nsTypeAheadFind();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTypeAheadFind, nsITypeAheadFind)

nsTypeAheadFind::nsTypeAheadFind()
{
  /* member initializers and constructor code */
}

nsTypeAheadFind::~nsTypeAheadFind()
{
  /* destructor code */
}

/* void init (in nsIDocShell aDocShell); */
NS_IMETHODIMP nsTypeAheadFind::Init(nsIDocShell *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short find (in AString aSearchString, in boolean aLinksOnly); */
NS_IMETHODIMP nsTypeAheadFind::Find(const nsAString & aSearchString, bool aLinksOnly, uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short findAgain (in boolean findBackwards, in boolean aLinksOnly); */
NS_IMETHODIMP nsTypeAheadFind::FindAgain(bool findBackwards, bool aLinksOnly, uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMRange getFoundRange (); */
NS_IMETHODIMP nsTypeAheadFind::GetFoundRange(nsIDOMRange * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDocShell (in nsIDocShell aDocShell); */
NS_IMETHODIMP nsTypeAheadFind::SetDocShell(nsIDocShell *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSelectionModeAndRepaint (in short toggle); */
NS_IMETHODIMP nsTypeAheadFind::SetSelectionModeAndRepaint(int16_t toggle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void collapseSelection (); */
NS_IMETHODIMP nsTypeAheadFind::CollapseSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isRangeVisible (in nsIDOMRange aRange, in boolean aMustBeInViewPort); */
NS_IMETHODIMP nsTypeAheadFind::IsRangeVisible(nsIDOMRange *aRange, bool aMustBeInViewPort, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString searchString; */
NS_IMETHODIMP nsTypeAheadFind::GetSearchString(nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean caseSensitive; */
NS_IMETHODIMP nsTypeAheadFind::GetCaseSensitive(bool *aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTypeAheadFind::SetCaseSensitive(bool aCaseSensitive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement foundLink; */
NS_IMETHODIMP nsTypeAheadFind::GetFoundLink(nsIDOMElement * *aFoundLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement foundEditable; */
NS_IMETHODIMP nsTypeAheadFind::GetFoundEditable(nsIDOMElement * *aFoundEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow currentWindow; */
NS_IMETHODIMP nsTypeAheadFind::GetCurrentWindow(nsIDOMWindow * *aCurrentWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITypeAheadFind_h__ */
