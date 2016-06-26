/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAutoCompleteController.idl
 */

#ifndef __gen_nsIAutoCompleteController_h__
#define __gen_nsIAutoCompleteController_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAutoCompleteInput; /* forward declaration */


/* starting interface:    nsIAutoCompleteController */
#define NS_IAUTOCOMPLETECONTROLLER_IID_STR "ff9f8465-204a-47a6-b3c9-0628b3856684"

#define NS_IAUTOCOMPLETECONTROLLER_IID \
  {0xff9f8465, 0x204a, 0x47a6, \
    { 0xb3, 0xc9, 0x06, 0x28, 0xb3, 0x85, 0x66, 0x84 }}

class NS_NO_VTABLE nsIAutoCompleteController : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETECONTROLLER_IID)

  enum {
    STATUS_NONE = 1U,
    STATUS_SEARCHING = 2U,
    STATUS_COMPLETE_NO_MATCH = 3U,
    STATUS_COMPLETE_MATCH = 4U
  };

  /* attribute nsIAutoCompleteInput input; */
  NS_IMETHOD GetInput(nsIAutoCompleteInput * *aInput) = 0;
  NS_IMETHOD SetInput(nsIAutoCompleteInput *aInput) = 0;

  /* readonly attribute unsigned short searchStatus; */
  NS_IMETHOD GetSearchStatus(uint16_t *aSearchStatus) = 0;

  /* readonly attribute unsigned long matchCount; */
  NS_IMETHOD GetMatchCount(uint32_t *aMatchCount) = 0;

  /* void startSearch (in AString searchString); */
  NS_IMETHOD StartSearch(const nsAString & searchString) = 0;

  /* void stopSearch (); */
  NS_IMETHOD StopSearch(void) = 0;

  /* void handleText (); */
  NS_IMETHOD HandleText(void) = 0;

  /* boolean handleEnter (in boolean aIsPopupSelection); */
  NS_IMETHOD HandleEnter(bool aIsPopupSelection, bool *_retval) = 0;

  /* boolean handleEscape (); */
  NS_IMETHOD HandleEscape(bool *_retval) = 0;

  /* void handleStartComposition (); */
  NS_IMETHOD HandleStartComposition(void) = 0;

  /* void handleEndComposition (); */
  NS_IMETHOD HandleEndComposition(void) = 0;

  /* void handleTab (); */
  NS_IMETHOD HandleTab(void) = 0;

  /* boolean handleKeyNavigation (in unsigned long key); */
  NS_IMETHOD HandleKeyNavigation(uint32_t key, bool *_retval) = 0;

  /* boolean handleDelete (); */
  NS_IMETHOD HandleDelete(bool *_retval) = 0;

  /* AString getValueAt (in long index); */
  NS_IMETHOD GetValueAt(int32_t index, nsAString & _retval) = 0;

  /* AString getLabelAt (in long index); */
  NS_IMETHOD GetLabelAt(int32_t index, nsAString & _retval) = 0;

  /* AString getCommentAt (in long index); */
  NS_IMETHOD GetCommentAt(int32_t index, nsAString & _retval) = 0;

  /* AString getStyleAt (in long index); */
  NS_IMETHOD GetStyleAt(int32_t index, nsAString & _retval) = 0;

  /* AString getImageAt (in long index); */
  NS_IMETHOD GetImageAt(int32_t index, nsAString & _retval) = 0;

  /* AString getFinalCompleteValueAt (in long index); */
  NS_IMETHOD GetFinalCompleteValueAt(int32_t index, nsAString & _retval) = 0;

  /* attribute AString searchString; */
  NS_IMETHOD GetSearchString(nsAString & aSearchString) = 0;
  NS_IMETHOD SetSearchString(const nsAString & aSearchString) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteController, NS_IAUTOCOMPLETECONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETECONTROLLER \
  NS_IMETHOD GetInput(nsIAutoCompleteInput * *aInput) override; \
  NS_IMETHOD SetInput(nsIAutoCompleteInput *aInput) override; \
  NS_IMETHOD GetSearchStatus(uint16_t *aSearchStatus) override; \
  NS_IMETHOD GetMatchCount(uint32_t *aMatchCount) override; \
  NS_IMETHOD StartSearch(const nsAString & searchString) override; \
  NS_IMETHOD StopSearch(void) override; \
  NS_IMETHOD HandleText(void) override; \
  NS_IMETHOD HandleEnter(bool aIsPopupSelection, bool *_retval) override; \
  NS_IMETHOD HandleEscape(bool *_retval) override; \
  NS_IMETHOD HandleStartComposition(void) override; \
  NS_IMETHOD HandleEndComposition(void) override; \
  NS_IMETHOD HandleTab(void) override; \
  NS_IMETHOD HandleKeyNavigation(uint32_t key, bool *_retval) override; \
  NS_IMETHOD HandleDelete(bool *_retval) override; \
  NS_IMETHOD GetValueAt(int32_t index, nsAString & _retval) override; \
  NS_IMETHOD GetLabelAt(int32_t index, nsAString & _retval) override; \
  NS_IMETHOD GetCommentAt(int32_t index, nsAString & _retval) override; \
  NS_IMETHOD GetStyleAt(int32_t index, nsAString & _retval) override; \
  NS_IMETHOD GetImageAt(int32_t index, nsAString & _retval) override; \
  NS_IMETHOD GetFinalCompleteValueAt(int32_t index, nsAString & _retval) override; \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) override; \
  NS_IMETHOD SetSearchString(const nsAString & aSearchString) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETECONTROLLER(_to) \
  NS_IMETHOD GetInput(nsIAutoCompleteInput * *aInput) override { return _to GetInput(aInput); } \
  NS_IMETHOD SetInput(nsIAutoCompleteInput *aInput) override { return _to SetInput(aInput); } \
  NS_IMETHOD GetSearchStatus(uint16_t *aSearchStatus) override { return _to GetSearchStatus(aSearchStatus); } \
  NS_IMETHOD GetMatchCount(uint32_t *aMatchCount) override { return _to GetMatchCount(aMatchCount); } \
  NS_IMETHOD StartSearch(const nsAString & searchString) override { return _to StartSearch(searchString); } \
  NS_IMETHOD StopSearch(void) override { return _to StopSearch(); } \
  NS_IMETHOD HandleText(void) override { return _to HandleText(); } \
  NS_IMETHOD HandleEnter(bool aIsPopupSelection, bool *_retval) override { return _to HandleEnter(aIsPopupSelection, _retval); } \
  NS_IMETHOD HandleEscape(bool *_retval) override { return _to HandleEscape(_retval); } \
  NS_IMETHOD HandleStartComposition(void) override { return _to HandleStartComposition(); } \
  NS_IMETHOD HandleEndComposition(void) override { return _to HandleEndComposition(); } \
  NS_IMETHOD HandleTab(void) override { return _to HandleTab(); } \
  NS_IMETHOD HandleKeyNavigation(uint32_t key, bool *_retval) override { return _to HandleKeyNavigation(key, _retval); } \
  NS_IMETHOD HandleDelete(bool *_retval) override { return _to HandleDelete(_retval); } \
  NS_IMETHOD GetValueAt(int32_t index, nsAString & _retval) override { return _to GetValueAt(index, _retval); } \
  NS_IMETHOD GetLabelAt(int32_t index, nsAString & _retval) override { return _to GetLabelAt(index, _retval); } \
  NS_IMETHOD GetCommentAt(int32_t index, nsAString & _retval) override { return _to GetCommentAt(index, _retval); } \
  NS_IMETHOD GetStyleAt(int32_t index, nsAString & _retval) override { return _to GetStyleAt(index, _retval); } \
  NS_IMETHOD GetImageAt(int32_t index, nsAString & _retval) override { return _to GetImageAt(index, _retval); } \
  NS_IMETHOD GetFinalCompleteValueAt(int32_t index, nsAString & _retval) override { return _to GetFinalCompleteValueAt(index, _retval); } \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) override { return _to GetSearchString(aSearchString); } \
  NS_IMETHOD SetSearchString(const nsAString & aSearchString) override { return _to SetSearchString(aSearchString); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETECONTROLLER(_to) \
  NS_IMETHOD GetInput(nsIAutoCompleteInput * *aInput) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInput(aInput); } \
  NS_IMETHOD SetInput(nsIAutoCompleteInput *aInput) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInput(aInput); } \
  NS_IMETHOD GetSearchStatus(uint16_t *aSearchStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchStatus(aSearchStatus); } \
  NS_IMETHOD GetMatchCount(uint32_t *aMatchCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMatchCount(aMatchCount); } \
  NS_IMETHOD StartSearch(const nsAString & searchString) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartSearch(searchString); } \
  NS_IMETHOD StopSearch(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StopSearch(); } \
  NS_IMETHOD HandleText(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleText(); } \
  NS_IMETHOD HandleEnter(bool aIsPopupSelection, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEnter(aIsPopupSelection, _retval); } \
  NS_IMETHOD HandleEscape(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEscape(_retval); } \
  NS_IMETHOD HandleStartComposition(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleStartComposition(); } \
  NS_IMETHOD HandleEndComposition(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEndComposition(); } \
  NS_IMETHOD HandleTab(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleTab(); } \
  NS_IMETHOD HandleKeyNavigation(uint32_t key, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleKeyNavigation(key, _retval); } \
  NS_IMETHOD HandleDelete(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleDelete(_retval); } \
  NS_IMETHOD GetValueAt(int32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueAt(index, _retval); } \
  NS_IMETHOD GetLabelAt(int32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabelAt(index, _retval); } \
  NS_IMETHOD GetCommentAt(int32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommentAt(index, _retval); } \
  NS_IMETHOD GetStyleAt(int32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleAt(index, _retval); } \
  NS_IMETHOD GetImageAt(int32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageAt(index, _retval); } \
  NS_IMETHOD GetFinalCompleteValueAt(int32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFinalCompleteValueAt(index, _retval); } \
  NS_IMETHOD GetSearchString(nsAString & aSearchString) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchString(aSearchString); } \
  NS_IMETHOD SetSearchString(const nsAString & aSearchString) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchString(aSearchString); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteController : public nsIAutoCompleteController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETECONTROLLER

  nsAutoCompleteController();

private:
  ~nsAutoCompleteController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAutoCompleteController, nsIAutoCompleteController)

nsAutoCompleteController::nsAutoCompleteController()
{
  /* member initializers and constructor code */
}

nsAutoCompleteController::~nsAutoCompleteController()
{
  /* destructor code */
}

/* attribute nsIAutoCompleteInput input; */
NS_IMETHODIMP nsAutoCompleteController::GetInput(nsIAutoCompleteInput * *aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteController::SetInput(nsIAutoCompleteInput *aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short searchStatus; */
NS_IMETHODIMP nsAutoCompleteController::GetSearchStatus(uint16_t *aSearchStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long matchCount; */
NS_IMETHODIMP nsAutoCompleteController::GetMatchCount(uint32_t *aMatchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startSearch (in AString searchString); */
NS_IMETHODIMP nsAutoCompleteController::StartSearch(const nsAString & searchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopSearch (); */
NS_IMETHODIMP nsAutoCompleteController::StopSearch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleText (); */
NS_IMETHODIMP nsAutoCompleteController::HandleText()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handleEnter (in boolean aIsPopupSelection); */
NS_IMETHODIMP nsAutoCompleteController::HandleEnter(bool aIsPopupSelection, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handleEscape (); */
NS_IMETHODIMP nsAutoCompleteController::HandleEscape(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleStartComposition (); */
NS_IMETHODIMP nsAutoCompleteController::HandleStartComposition()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleEndComposition (); */
NS_IMETHODIMP nsAutoCompleteController::HandleEndComposition()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleTab (); */
NS_IMETHODIMP nsAutoCompleteController::HandleTab()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handleKeyNavigation (in unsigned long key); */
NS_IMETHODIMP nsAutoCompleteController::HandleKeyNavigation(uint32_t key, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean handleDelete (); */
NS_IMETHODIMP nsAutoCompleteController::HandleDelete(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getValueAt (in long index); */
NS_IMETHODIMP nsAutoCompleteController::GetValueAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getLabelAt (in long index); */
NS_IMETHODIMP nsAutoCompleteController::GetLabelAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getCommentAt (in long index); */
NS_IMETHODIMP nsAutoCompleteController::GetCommentAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStyleAt (in long index); */
NS_IMETHODIMP nsAutoCompleteController::GetStyleAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getImageAt (in long index); */
NS_IMETHODIMP nsAutoCompleteController::GetImageAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getFinalCompleteValueAt (in long index); */
NS_IMETHODIMP nsAutoCompleteController::GetFinalCompleteValueAt(int32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString searchString; */
NS_IMETHODIMP nsAutoCompleteController::GetSearchString(nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteController::SetSearchString(const nsAString & aSearchString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAutoCompleteController_h__ */
