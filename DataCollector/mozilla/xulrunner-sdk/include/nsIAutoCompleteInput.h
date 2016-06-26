/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAutoCompleteInput.idl
 */

#ifndef __gen_nsIAutoCompleteInput_h__
#define __gen_nsIAutoCompleteInput_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIAutoCompleteController_h__
#include "nsIAutoCompleteController.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAutoCompletePopup; /* forward declaration */


/* starting interface:    nsIAutoCompleteInput */
#define NS_IAUTOCOMPLETEINPUT_IID_STR "b068e70f-f82c-4c12-ad87-82e271c5c180"

#define NS_IAUTOCOMPLETEINPUT_IID \
  {0xb068e70f, 0xf82c, 0x4c12, \
    { 0xad, 0x87, 0x82, 0xe2, 0x71, 0xc5, 0xc1, 0x80 }}

class NS_NO_VTABLE nsIAutoCompleteInput : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETEINPUT_IID)

  /* readonly attribute nsIAutoCompletePopup popup; */
  NS_IMETHOD GetPopup(nsIAutoCompletePopup * *aPopup) = 0;

  /* readonly attribute nsIAutoCompleteController controller; */
  NS_IMETHOD GetController(nsIAutoCompleteController * *aController) = 0;

  /* attribute boolean popupOpen; */
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) = 0;
  NS_IMETHOD SetPopupOpen(bool aPopupOpen) = 0;

  /* attribute boolean disableAutoComplete; */
  NS_IMETHOD GetDisableAutoComplete(bool *aDisableAutoComplete) = 0;
  NS_IMETHOD SetDisableAutoComplete(bool aDisableAutoComplete) = 0;

  /* attribute boolean completeDefaultIndex; */
  NS_IMETHOD GetCompleteDefaultIndex(bool *aCompleteDefaultIndex) = 0;
  NS_IMETHOD SetCompleteDefaultIndex(bool aCompleteDefaultIndex) = 0;

  /* attribute boolean completeSelectedIndex; */
  NS_IMETHOD GetCompleteSelectedIndex(bool *aCompleteSelectedIndex) = 0;
  NS_IMETHOD SetCompleteSelectedIndex(bool aCompleteSelectedIndex) = 0;

  /* attribute boolean forceComplete; */
  NS_IMETHOD GetForceComplete(bool *aForceComplete) = 0;
  NS_IMETHOD SetForceComplete(bool aForceComplete) = 0;

  /* attribute unsigned long minResultsForPopup; */
  NS_IMETHOD GetMinResultsForPopup(uint32_t *aMinResultsForPopup) = 0;
  NS_IMETHOD SetMinResultsForPopup(uint32_t aMinResultsForPopup) = 0;

  /* attribute unsigned long maxRows; */
  NS_IMETHOD GetMaxRows(uint32_t *aMaxRows) = 0;
  NS_IMETHOD SetMaxRows(uint32_t aMaxRows) = 0;

  /* attribute boolean showCommentColumn; */
  NS_IMETHOD GetShowCommentColumn(bool *aShowCommentColumn) = 0;
  NS_IMETHOD SetShowCommentColumn(bool aShowCommentColumn) = 0;

  /* attribute boolean showImageColumn; */
  NS_IMETHOD GetShowImageColumn(bool *aShowImageColumn) = 0;
  NS_IMETHOD SetShowImageColumn(bool aShowImageColumn) = 0;

  /* attribute unsigned long timeout; */
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) = 0;
  NS_IMETHOD SetTimeout(uint32_t aTimeout) = 0;

  /* attribute AString searchParam; */
  NS_IMETHOD GetSearchParam(nsAString & aSearchParam) = 0;
  NS_IMETHOD SetSearchParam(const nsAString & aSearchParam) = 0;

  /* readonly attribute unsigned long searchCount; */
  NS_IMETHOD GetSearchCount(uint32_t *aSearchCount) = 0;

  /* ACString getSearchAt (in unsigned long index); */
  NS_IMETHOD GetSearchAt(uint32_t index, nsACString & _retval) = 0;

  /* attribute AString textValue; */
  NS_IMETHOD GetTextValue(nsAString & aTextValue) = 0;
  NS_IMETHOD SetTextValue(const nsAString & aTextValue) = 0;

  /* readonly attribute long selectionStart; */
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) = 0;

  /* readonly attribute long selectionEnd; */
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) = 0;

  /* void selectTextRange (in long startIndex, in long endIndex); */
  NS_IMETHOD SelectTextRange(int32_t startIndex, int32_t endIndex) = 0;

  /* void onSearchBegin (); */
  NS_IMETHOD OnSearchBegin(void) = 0;

  /* void onSearchComplete (); */
  NS_IMETHOD OnSearchComplete(void) = 0;

  /* boolean onTextEntered (); */
  NS_IMETHOD OnTextEntered(bool *_retval) = 0;

  /* boolean onTextReverted (); */
  NS_IMETHOD OnTextReverted(bool *_retval) = 0;

  /* readonly attribute boolean consumeRollupEvent; */
  NS_IMETHOD GetConsumeRollupEvent(bool *aConsumeRollupEvent) = 0;

  /* readonly attribute boolean inPrivateContext; */
  NS_IMETHOD GetInPrivateContext(bool *aInPrivateContext) = 0;

  /* readonly attribute boolean noRollupOnCaretMove; */
  NS_IMETHOD GetNoRollupOnCaretMove(bool *aNoRollupOnCaretMove) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompleteInput, NS_IAUTOCOMPLETEINPUT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETEINPUT \
  NS_IMETHOD GetPopup(nsIAutoCompletePopup * *aPopup) override; \
  NS_IMETHOD GetController(nsIAutoCompleteController * *aController) override; \
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) override; \
  NS_IMETHOD SetPopupOpen(bool aPopupOpen) override; \
  NS_IMETHOD GetDisableAutoComplete(bool *aDisableAutoComplete) override; \
  NS_IMETHOD SetDisableAutoComplete(bool aDisableAutoComplete) override; \
  NS_IMETHOD GetCompleteDefaultIndex(bool *aCompleteDefaultIndex) override; \
  NS_IMETHOD SetCompleteDefaultIndex(bool aCompleteDefaultIndex) override; \
  NS_IMETHOD GetCompleteSelectedIndex(bool *aCompleteSelectedIndex) override; \
  NS_IMETHOD SetCompleteSelectedIndex(bool aCompleteSelectedIndex) override; \
  NS_IMETHOD GetForceComplete(bool *aForceComplete) override; \
  NS_IMETHOD SetForceComplete(bool aForceComplete) override; \
  NS_IMETHOD GetMinResultsForPopup(uint32_t *aMinResultsForPopup) override; \
  NS_IMETHOD SetMinResultsForPopup(uint32_t aMinResultsForPopup) override; \
  NS_IMETHOD GetMaxRows(uint32_t *aMaxRows) override; \
  NS_IMETHOD SetMaxRows(uint32_t aMaxRows) override; \
  NS_IMETHOD GetShowCommentColumn(bool *aShowCommentColumn) override; \
  NS_IMETHOD SetShowCommentColumn(bool aShowCommentColumn) override; \
  NS_IMETHOD GetShowImageColumn(bool *aShowImageColumn) override; \
  NS_IMETHOD SetShowImageColumn(bool aShowImageColumn) override; \
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) override; \
  NS_IMETHOD SetTimeout(uint32_t aTimeout) override; \
  NS_IMETHOD GetSearchParam(nsAString & aSearchParam) override; \
  NS_IMETHOD SetSearchParam(const nsAString & aSearchParam) override; \
  NS_IMETHOD GetSearchCount(uint32_t *aSearchCount) override; \
  NS_IMETHOD GetSearchAt(uint32_t index, nsACString & _retval) override; \
  NS_IMETHOD GetTextValue(nsAString & aTextValue) override; \
  NS_IMETHOD SetTextValue(const nsAString & aTextValue) override; \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) override; \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) override; \
  NS_IMETHOD SelectTextRange(int32_t startIndex, int32_t endIndex) override; \
  NS_IMETHOD OnSearchBegin(void) override; \
  NS_IMETHOD OnSearchComplete(void) override; \
  NS_IMETHOD OnTextEntered(bool *_retval) override; \
  NS_IMETHOD OnTextReverted(bool *_retval) override; \
  NS_IMETHOD GetConsumeRollupEvent(bool *aConsumeRollupEvent) override; \
  NS_IMETHOD GetInPrivateContext(bool *aInPrivateContext) override; \
  NS_IMETHOD GetNoRollupOnCaretMove(bool *aNoRollupOnCaretMove) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETEINPUT(_to) \
  NS_IMETHOD GetPopup(nsIAutoCompletePopup * *aPopup) override { return _to GetPopup(aPopup); } \
  NS_IMETHOD GetController(nsIAutoCompleteController * *aController) override { return _to GetController(aController); } \
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) override { return _to GetPopupOpen(aPopupOpen); } \
  NS_IMETHOD SetPopupOpen(bool aPopupOpen) override { return _to SetPopupOpen(aPopupOpen); } \
  NS_IMETHOD GetDisableAutoComplete(bool *aDisableAutoComplete) override { return _to GetDisableAutoComplete(aDisableAutoComplete); } \
  NS_IMETHOD SetDisableAutoComplete(bool aDisableAutoComplete) override { return _to SetDisableAutoComplete(aDisableAutoComplete); } \
  NS_IMETHOD GetCompleteDefaultIndex(bool *aCompleteDefaultIndex) override { return _to GetCompleteDefaultIndex(aCompleteDefaultIndex); } \
  NS_IMETHOD SetCompleteDefaultIndex(bool aCompleteDefaultIndex) override { return _to SetCompleteDefaultIndex(aCompleteDefaultIndex); } \
  NS_IMETHOD GetCompleteSelectedIndex(bool *aCompleteSelectedIndex) override { return _to GetCompleteSelectedIndex(aCompleteSelectedIndex); } \
  NS_IMETHOD SetCompleteSelectedIndex(bool aCompleteSelectedIndex) override { return _to SetCompleteSelectedIndex(aCompleteSelectedIndex); } \
  NS_IMETHOD GetForceComplete(bool *aForceComplete) override { return _to GetForceComplete(aForceComplete); } \
  NS_IMETHOD SetForceComplete(bool aForceComplete) override { return _to SetForceComplete(aForceComplete); } \
  NS_IMETHOD GetMinResultsForPopup(uint32_t *aMinResultsForPopup) override { return _to GetMinResultsForPopup(aMinResultsForPopup); } \
  NS_IMETHOD SetMinResultsForPopup(uint32_t aMinResultsForPopup) override { return _to SetMinResultsForPopup(aMinResultsForPopup); } \
  NS_IMETHOD GetMaxRows(uint32_t *aMaxRows) override { return _to GetMaxRows(aMaxRows); } \
  NS_IMETHOD SetMaxRows(uint32_t aMaxRows) override { return _to SetMaxRows(aMaxRows); } \
  NS_IMETHOD GetShowCommentColumn(bool *aShowCommentColumn) override { return _to GetShowCommentColumn(aShowCommentColumn); } \
  NS_IMETHOD SetShowCommentColumn(bool aShowCommentColumn) override { return _to SetShowCommentColumn(aShowCommentColumn); } \
  NS_IMETHOD GetShowImageColumn(bool *aShowImageColumn) override { return _to GetShowImageColumn(aShowImageColumn); } \
  NS_IMETHOD SetShowImageColumn(bool aShowImageColumn) override { return _to SetShowImageColumn(aShowImageColumn); } \
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) override { return _to GetTimeout(aTimeout); } \
  NS_IMETHOD SetTimeout(uint32_t aTimeout) override { return _to SetTimeout(aTimeout); } \
  NS_IMETHOD GetSearchParam(nsAString & aSearchParam) override { return _to GetSearchParam(aSearchParam); } \
  NS_IMETHOD SetSearchParam(const nsAString & aSearchParam) override { return _to SetSearchParam(aSearchParam); } \
  NS_IMETHOD GetSearchCount(uint32_t *aSearchCount) override { return _to GetSearchCount(aSearchCount); } \
  NS_IMETHOD GetSearchAt(uint32_t index, nsACString & _retval) override { return _to GetSearchAt(index, _retval); } \
  NS_IMETHOD GetTextValue(nsAString & aTextValue) override { return _to GetTextValue(aTextValue); } \
  NS_IMETHOD SetTextValue(const nsAString & aTextValue) override { return _to SetTextValue(aTextValue); } \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) override { return _to GetSelectionStart(aSelectionStart); } \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) override { return _to GetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD SelectTextRange(int32_t startIndex, int32_t endIndex) override { return _to SelectTextRange(startIndex, endIndex); } \
  NS_IMETHOD OnSearchBegin(void) override { return _to OnSearchBegin(); } \
  NS_IMETHOD OnSearchComplete(void) override { return _to OnSearchComplete(); } \
  NS_IMETHOD OnTextEntered(bool *_retval) override { return _to OnTextEntered(_retval); } \
  NS_IMETHOD OnTextReverted(bool *_retval) override { return _to OnTextReverted(_retval); } \
  NS_IMETHOD GetConsumeRollupEvent(bool *aConsumeRollupEvent) override { return _to GetConsumeRollupEvent(aConsumeRollupEvent); } \
  NS_IMETHOD GetInPrivateContext(bool *aInPrivateContext) override { return _to GetInPrivateContext(aInPrivateContext); } \
  NS_IMETHOD GetNoRollupOnCaretMove(bool *aNoRollupOnCaretMove) override { return _to GetNoRollupOnCaretMove(aNoRollupOnCaretMove); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETEINPUT(_to) \
  NS_IMETHOD GetPopup(nsIAutoCompletePopup * *aPopup) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopup(aPopup); } \
  NS_IMETHOD GetController(nsIAutoCompleteController * *aController) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetController(aController); } \
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupOpen(aPopupOpen); } \
  NS_IMETHOD SetPopupOpen(bool aPopupOpen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPopupOpen(aPopupOpen); } \
  NS_IMETHOD GetDisableAutoComplete(bool *aDisableAutoComplete) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisableAutoComplete(aDisableAutoComplete); } \
  NS_IMETHOD SetDisableAutoComplete(bool aDisableAutoComplete) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisableAutoComplete(aDisableAutoComplete); } \
  NS_IMETHOD GetCompleteDefaultIndex(bool *aCompleteDefaultIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompleteDefaultIndex(aCompleteDefaultIndex); } \
  NS_IMETHOD SetCompleteDefaultIndex(bool aCompleteDefaultIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompleteDefaultIndex(aCompleteDefaultIndex); } \
  NS_IMETHOD GetCompleteSelectedIndex(bool *aCompleteSelectedIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompleteSelectedIndex(aCompleteSelectedIndex); } \
  NS_IMETHOD SetCompleteSelectedIndex(bool aCompleteSelectedIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompleteSelectedIndex(aCompleteSelectedIndex); } \
  NS_IMETHOD GetForceComplete(bool *aForceComplete) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceComplete(aForceComplete); } \
  NS_IMETHOD SetForceComplete(bool aForceComplete) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForceComplete(aForceComplete); } \
  NS_IMETHOD GetMinResultsForPopup(uint32_t *aMinResultsForPopup) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinResultsForPopup(aMinResultsForPopup); } \
  NS_IMETHOD SetMinResultsForPopup(uint32_t aMinResultsForPopup) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinResultsForPopup(aMinResultsForPopup); } \
  NS_IMETHOD GetMaxRows(uint32_t *aMaxRows) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxRows(aMaxRows); } \
  NS_IMETHOD SetMaxRows(uint32_t aMaxRows) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMaxRows(aMaxRows); } \
  NS_IMETHOD GetShowCommentColumn(bool *aShowCommentColumn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowCommentColumn(aShowCommentColumn); } \
  NS_IMETHOD SetShowCommentColumn(bool aShowCommentColumn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowCommentColumn(aShowCommentColumn); } \
  NS_IMETHOD GetShowImageColumn(bool *aShowImageColumn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowImageColumn(aShowImageColumn); } \
  NS_IMETHOD SetShowImageColumn(bool aShowImageColumn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowImageColumn(aShowImageColumn); } \
  NS_IMETHOD GetTimeout(uint32_t *aTimeout) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeout(aTimeout); } \
  NS_IMETHOD SetTimeout(uint32_t aTimeout) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeout(aTimeout); } \
  NS_IMETHOD GetSearchParam(nsAString & aSearchParam) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchParam(aSearchParam); } \
  NS_IMETHOD SetSearchParam(const nsAString & aSearchParam) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSearchParam(aSearchParam); } \
  NS_IMETHOD GetSearchCount(uint32_t *aSearchCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchCount(aSearchCount); } \
  NS_IMETHOD GetSearchAt(uint32_t index, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSearchAt(index, _retval); } \
  NS_IMETHOD GetTextValue(nsAString & aTextValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextValue(aTextValue); } \
  NS_IMETHOD SetTextValue(const nsAString & aTextValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextValue(aTextValue); } \
  NS_IMETHOD GetSelectionStart(int32_t *aSelectionStart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionStart(aSelectionStart); } \
  NS_IMETHOD GetSelectionEnd(int32_t *aSelectionEnd) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionEnd(aSelectionEnd); } \
  NS_IMETHOD SelectTextRange(int32_t startIndex, int32_t endIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectTextRange(startIndex, endIndex); } \
  NS_IMETHOD OnSearchBegin(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchBegin(); } \
  NS_IMETHOD OnSearchComplete(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchComplete(); } \
  NS_IMETHOD OnTextEntered(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTextEntered(_retval); } \
  NS_IMETHOD OnTextReverted(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTextReverted(_retval); } \
  NS_IMETHOD GetConsumeRollupEvent(bool *aConsumeRollupEvent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConsumeRollupEvent(aConsumeRollupEvent); } \
  NS_IMETHOD GetInPrivateContext(bool *aInPrivateContext) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInPrivateContext(aInPrivateContext); } \
  NS_IMETHOD GetNoRollupOnCaretMove(bool *aNoRollupOnCaretMove) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNoRollupOnCaretMove(aNoRollupOnCaretMove); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompleteInput : public nsIAutoCompleteInput
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETEINPUT

  nsAutoCompleteInput();

private:
  ~nsAutoCompleteInput();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAutoCompleteInput, nsIAutoCompleteInput)

nsAutoCompleteInput::nsAutoCompleteInput()
{
  /* member initializers and constructor code */
}

nsAutoCompleteInput::~nsAutoCompleteInput()
{
  /* destructor code */
}

/* readonly attribute nsIAutoCompletePopup popup; */
NS_IMETHODIMP nsAutoCompleteInput::GetPopup(nsIAutoCompletePopup * *aPopup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAutoCompleteController controller; */
NS_IMETHODIMP nsAutoCompleteInput::GetController(nsIAutoCompleteController * *aController)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean popupOpen; */
NS_IMETHODIMP nsAutoCompleteInput::GetPopupOpen(bool *aPopupOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetPopupOpen(bool aPopupOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean disableAutoComplete; */
NS_IMETHODIMP nsAutoCompleteInput::GetDisableAutoComplete(bool *aDisableAutoComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetDisableAutoComplete(bool aDisableAutoComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean completeDefaultIndex; */
NS_IMETHODIMP nsAutoCompleteInput::GetCompleteDefaultIndex(bool *aCompleteDefaultIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetCompleteDefaultIndex(bool aCompleteDefaultIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean completeSelectedIndex; */
NS_IMETHODIMP nsAutoCompleteInput::GetCompleteSelectedIndex(bool *aCompleteSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetCompleteSelectedIndex(bool aCompleteSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean forceComplete; */
NS_IMETHODIMP nsAutoCompleteInput::GetForceComplete(bool *aForceComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetForceComplete(bool aForceComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long minResultsForPopup; */
NS_IMETHODIMP nsAutoCompleteInput::GetMinResultsForPopup(uint32_t *aMinResultsForPopup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetMinResultsForPopup(uint32_t aMinResultsForPopup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long maxRows; */
NS_IMETHODIMP nsAutoCompleteInput::GetMaxRows(uint32_t *aMaxRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetMaxRows(uint32_t aMaxRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showCommentColumn; */
NS_IMETHODIMP nsAutoCompleteInput::GetShowCommentColumn(bool *aShowCommentColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetShowCommentColumn(bool aShowCommentColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showImageColumn; */
NS_IMETHODIMP nsAutoCompleteInput::GetShowImageColumn(bool *aShowImageColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetShowImageColumn(bool aShowImageColumn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long timeout; */
NS_IMETHODIMP nsAutoCompleteInput::GetTimeout(uint32_t *aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetTimeout(uint32_t aTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString searchParam; */
NS_IMETHODIMP nsAutoCompleteInput::GetSearchParam(nsAString & aSearchParam)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetSearchParam(const nsAString & aSearchParam)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long searchCount; */
NS_IMETHODIMP nsAutoCompleteInput::GetSearchCount(uint32_t *aSearchCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getSearchAt (in unsigned long index); */
NS_IMETHODIMP nsAutoCompleteInput::GetSearchAt(uint32_t index, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString textValue; */
NS_IMETHODIMP nsAutoCompleteInput::GetTextValue(nsAString & aTextValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompleteInput::SetTextValue(const nsAString & aTextValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long selectionStart; */
NS_IMETHODIMP nsAutoCompleteInput::GetSelectionStart(int32_t *aSelectionStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long selectionEnd; */
NS_IMETHODIMP nsAutoCompleteInput::GetSelectionEnd(int32_t *aSelectionEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectTextRange (in long startIndex, in long endIndex); */
NS_IMETHODIMP nsAutoCompleteInput::SelectTextRange(int32_t startIndex, int32_t endIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSearchBegin (); */
NS_IMETHODIMP nsAutoCompleteInput::OnSearchBegin()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSearchComplete (); */
NS_IMETHODIMP nsAutoCompleteInput::OnSearchComplete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onTextEntered (); */
NS_IMETHODIMP nsAutoCompleteInput::OnTextEntered(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean onTextReverted (); */
NS_IMETHODIMP nsAutoCompleteInput::OnTextReverted(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean consumeRollupEvent; */
NS_IMETHODIMP nsAutoCompleteInput::GetConsumeRollupEvent(bool *aConsumeRollupEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inPrivateContext; */
NS_IMETHODIMP nsAutoCompleteInput::GetInPrivateContext(bool *aInPrivateContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean noRollupOnCaretMove; */
NS_IMETHODIMP nsAutoCompleteInput::GetNoRollupOnCaretMove(bool *aNoRollupOnCaretMove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAutoCompleteInput_h__ */
