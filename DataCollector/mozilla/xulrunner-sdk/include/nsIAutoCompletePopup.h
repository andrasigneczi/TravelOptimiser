/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAutoCompletePopup.idl
 */

#ifndef __gen_nsIAutoCompletePopup_h__
#define __gen_nsIAutoCompletePopup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIAutoCompleteInput; /* forward declaration */


/* starting interface:    nsIAutoCompletePopup */
#define NS_IAUTOCOMPLETEPOPUP_IID_STR "1b9d7d8a-6dd0-11dc-8314-0800200c9a66"

#define NS_IAUTOCOMPLETEPOPUP_IID \
  {0x1b9d7d8a, 0x6dd0, 0x11dc, \
    { 0x83, 0x14, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIAutoCompletePopup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTOCOMPLETEPOPUP_IID)

  /* readonly attribute nsIAutoCompleteInput input; */
  NS_IMETHOD GetInput(nsIAutoCompleteInput * *aInput) = 0;

  /* readonly attribute AString overrideValue; */
  NS_IMETHOD GetOverrideValue(nsAString & aOverrideValue) = 0;

  /* attribute long selectedIndex; */
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) = 0;
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) = 0;

  /* readonly attribute boolean popupOpen; */
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) = 0;

  /* void openAutocompletePopup (in nsIAutoCompleteInput input, in nsIDOMElement element); */
  NS_IMETHOD OpenAutocompletePopup(nsIAutoCompleteInput *input, nsIDOMElement *element) = 0;

  /* void closePopup (); */
  NS_IMETHOD ClosePopup(void) = 0;

  /* void invalidate (); */
  NS_IMETHOD Invalidate(void) = 0;

  /* void selectBy (in boolean reverse, in boolean page); */
  NS_IMETHOD SelectBy(bool reverse, bool page) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAutoCompletePopup, NS_IAUTOCOMPLETEPOPUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTOCOMPLETEPOPUP \
  NS_IMETHOD GetInput(nsIAutoCompleteInput * *aInput) override; \
  NS_IMETHOD GetOverrideValue(nsAString & aOverrideValue) override; \
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) override; \
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) override; \
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) override; \
  NS_IMETHOD OpenAutocompletePopup(nsIAutoCompleteInput *input, nsIDOMElement *element) override; \
  NS_IMETHOD ClosePopup(void) override; \
  NS_IMETHOD Invalidate(void) override; \
  NS_IMETHOD SelectBy(bool reverse, bool page) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTOCOMPLETEPOPUP(_to) \
  NS_IMETHOD GetInput(nsIAutoCompleteInput * *aInput) override { return _to GetInput(aInput); } \
  NS_IMETHOD GetOverrideValue(nsAString & aOverrideValue) override { return _to GetOverrideValue(aOverrideValue); } \
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) override { return _to GetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) override { return _to SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) override { return _to GetPopupOpen(aPopupOpen); } \
  NS_IMETHOD OpenAutocompletePopup(nsIAutoCompleteInput *input, nsIDOMElement *element) override { return _to OpenAutocompletePopup(input, element); } \
  NS_IMETHOD ClosePopup(void) override { return _to ClosePopup(); } \
  NS_IMETHOD Invalidate(void) override { return _to Invalidate(); } \
  NS_IMETHOD SelectBy(bool reverse, bool page) override { return _to SelectBy(reverse, page); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTOCOMPLETEPOPUP(_to) \
  NS_IMETHOD GetInput(nsIAutoCompleteInput * *aInput) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInput(aInput); } \
  NS_IMETHOD GetOverrideValue(nsAString & aOverrideValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOverrideValue(aOverrideValue); } \
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD GetPopupOpen(bool *aPopupOpen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPopupOpen(aPopupOpen); } \
  NS_IMETHOD OpenAutocompletePopup(nsIAutoCompleteInput *input, nsIDOMElement *element) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenAutocompletePopup(input, element); } \
  NS_IMETHOD ClosePopup(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClosePopup(); } \
  NS_IMETHOD Invalidate(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Invalidate(); } \
  NS_IMETHOD SelectBy(bool reverse, bool page) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectBy(reverse, page); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAutoCompletePopup : public nsIAutoCompletePopup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETEPOPUP

  nsAutoCompletePopup();

private:
  ~nsAutoCompletePopup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAutoCompletePopup, nsIAutoCompletePopup)

nsAutoCompletePopup::nsAutoCompletePopup()
{
  /* member initializers and constructor code */
}

nsAutoCompletePopup::~nsAutoCompletePopup()
{
  /* destructor code */
}

/* readonly attribute nsIAutoCompleteInput input; */
NS_IMETHODIMP nsAutoCompletePopup::GetInput(nsIAutoCompleteInput * *aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString overrideValue; */
NS_IMETHODIMP nsAutoCompletePopup::GetOverrideValue(nsAString & aOverrideValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectedIndex; */
NS_IMETHODIMP nsAutoCompletePopup::GetSelectedIndex(int32_t *aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAutoCompletePopup::SetSelectedIndex(int32_t aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean popupOpen; */
NS_IMETHODIMP nsAutoCompletePopup::GetPopupOpen(bool *aPopupOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openAutocompletePopup (in nsIAutoCompleteInput input, in nsIDOMElement element); */
NS_IMETHODIMP nsAutoCompletePopup::OpenAutocompletePopup(nsIAutoCompleteInput *input, nsIDOMElement *element)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closePopup (); */
NS_IMETHODIMP nsAutoCompletePopup::ClosePopup()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidate (); */
NS_IMETHODIMP nsAutoCompletePopup::Invalidate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectBy (in boolean reverse, in boolean page); */
NS_IMETHODIMP nsAutoCompletePopup::SelectBy(bool reverse, bool page)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAutoCompletePopup_h__ */
