/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFormAutoComplete.idl
 */

#ifndef __gen_nsIFormAutoComplete_h__
#define __gen_nsIFormAutoComplete_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAutoCompleteResult; /* forward declaration */

class nsIFormAutoCompleteObserver; /* forward declaration */

class nsIDOMHTMLInputElement; /* forward declaration */


/* starting interface:    nsIFormAutoComplete */
#define NS_IFORMAUTOCOMPLETE_IID_STR "bfd9b82b-0ab3-4b6b-9e54-aa961ff4b732"

#define NS_IFORMAUTOCOMPLETE_IID \
  {0xbfd9b82b, 0x0ab3, 0x4b6b, \
    { 0x9e, 0x54, 0xaa, 0x96, 0x1f, 0xf4, 0xb7, 0x32 }}

class NS_NO_VTABLE nsIFormAutoComplete : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMAUTOCOMPLETE_IID)

  /* void autoCompleteSearchAsync (in AString aInputName, in AString aSearchString, in nsIDOMHTMLInputElement aField, in nsIAutoCompleteResult aPreviousResult, in nsIAutoCompleteResult aDatalistResult, in nsIFormAutoCompleteObserver aListener); */
  NS_IMETHOD AutoCompleteSearchAsync(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult *aDatalistResult, nsIFormAutoCompleteObserver *aListener) = 0;

  /* void stopAutoCompleteSearch (); */
  NS_IMETHOD StopAutoCompleteSearch(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormAutoComplete, NS_IFORMAUTOCOMPLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMAUTOCOMPLETE \
  NS_IMETHOD AutoCompleteSearchAsync(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult *aDatalistResult, nsIFormAutoCompleteObserver *aListener) override; \
  NS_IMETHOD StopAutoCompleteSearch(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMAUTOCOMPLETE(_to) \
  NS_IMETHOD AutoCompleteSearchAsync(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult *aDatalistResult, nsIFormAutoCompleteObserver *aListener) override { return _to AutoCompleteSearchAsync(aInputName, aSearchString, aField, aPreviousResult, aDatalistResult, aListener); } \
  NS_IMETHOD StopAutoCompleteSearch(void) override { return _to StopAutoCompleteSearch(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMAUTOCOMPLETE(_to) \
  NS_IMETHOD AutoCompleteSearchAsync(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult *aDatalistResult, nsIFormAutoCompleteObserver *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoCompleteSearchAsync(aInputName, aSearchString, aField, aPreviousResult, aDatalistResult, aListener); } \
  NS_IMETHOD StopAutoCompleteSearch(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StopAutoCompleteSearch(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormAutoComplete : public nsIFormAutoComplete
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMAUTOCOMPLETE

  nsFormAutoComplete();

private:
  ~nsFormAutoComplete();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsFormAutoComplete, nsIFormAutoComplete)

nsFormAutoComplete::nsFormAutoComplete()
{
  /* member initializers and constructor code */
}

nsFormAutoComplete::~nsFormAutoComplete()
{
  /* destructor code */
}

/* void autoCompleteSearchAsync (in AString aInputName, in AString aSearchString, in nsIDOMHTMLInputElement aField, in nsIAutoCompleteResult aPreviousResult, in nsIAutoCompleteResult aDatalistResult, in nsIFormAutoCompleteObserver aListener); */
NS_IMETHODIMP nsFormAutoComplete::AutoCompleteSearchAsync(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult *aDatalistResult, nsIFormAutoCompleteObserver *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopAutoCompleteSearch (); */
NS_IMETHODIMP nsFormAutoComplete::StopAutoCompleteSearch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFormAutoCompleteObserver */
#define NS_IFORMAUTOCOMPLETEOBSERVER_IID_STR "604419ab-55a0-4831-9eca-1b9e67cc4751"

#define NS_IFORMAUTOCOMPLETEOBSERVER_IID \
  {0x604419ab, 0x55a0, 0x4831, \
    { 0x9e, 0xca, 0x1b, 0x9e, 0x67, 0xcc, 0x47, 0x51 }}

class NS_NO_VTABLE nsIFormAutoCompleteObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMAUTOCOMPLETEOBSERVER_IID)

  /* void onSearchCompletion (in nsIAutoCompleteResult result); */
  NS_IMETHOD OnSearchCompletion(nsIAutoCompleteResult *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormAutoCompleteObserver, NS_IFORMAUTOCOMPLETEOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMAUTOCOMPLETEOBSERVER \
  NS_IMETHOD OnSearchCompletion(nsIAutoCompleteResult *result) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMAUTOCOMPLETEOBSERVER(_to) \
  NS_IMETHOD OnSearchCompletion(nsIAutoCompleteResult *result) override { return _to OnSearchCompletion(result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMAUTOCOMPLETEOBSERVER(_to) \
  NS_IMETHOD OnSearchCompletion(nsIAutoCompleteResult *result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSearchCompletion(result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormAutoCompleteObserver : public nsIFormAutoCompleteObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMAUTOCOMPLETEOBSERVER

  nsFormAutoCompleteObserver();

private:
  ~nsFormAutoCompleteObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsFormAutoCompleteObserver, nsIFormAutoCompleteObserver)

nsFormAutoCompleteObserver::nsFormAutoCompleteObserver()
{
  /* member initializers and constructor code */
}

nsFormAutoCompleteObserver::~nsFormAutoCompleteObserver()
{
  /* destructor code */
}

/* void onSearchCompletion (in nsIAutoCompleteResult result); */
NS_IMETHODIMP nsFormAutoCompleteObserver::OnSearchCompletion(nsIAutoCompleteResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFormAutoComplete_h__ */
