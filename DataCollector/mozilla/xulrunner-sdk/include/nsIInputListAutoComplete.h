/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInputListAutoComplete.idl
 */

#ifndef __gen_nsIInputListAutoComplete_h__
#define __gen_nsIInputListAutoComplete_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAutoCompleteResult; /* forward declaration */

class nsIDOMHTMLInputElement; /* forward declaration */


/* starting interface:    nsIInputListAutoComplete */
#define NS_IINPUTLISTAUTOCOMPLETE_IID_STR "0e33de3e-4faf-4a1a-b96e-24115b8bfd45"

#define NS_IINPUTLISTAUTOCOMPLETE_IID \
  {0x0e33de3e, 0x4faf, 0x4a1a, \
    { 0xb9, 0x6e, 0x24, 0x11, 0x5b, 0x8b, 0xfd, 0x45 }}

class NS_NO_VTABLE nsIInputListAutoComplete : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTLISTAUTOCOMPLETE_IID)

  /* nsIAutoCompleteResult autoCompleteSearch (in AString aSearchString, in nsIDOMHTMLInputElement aField); */
  NS_IMETHOD AutoCompleteSearch(const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputListAutoComplete, NS_IINPUTLISTAUTOCOMPLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTLISTAUTOCOMPLETE \
  NS_IMETHOD AutoCompleteSearch(const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTLISTAUTOCOMPLETE(_to) \
  NS_IMETHOD AutoCompleteSearch(const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult * *_retval) override { return _to AutoCompleteSearch(aSearchString, aField, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTLISTAUTOCOMPLETE(_to) \
  NS_IMETHOD AutoCompleteSearch(const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoCompleteSearch(aSearchString, aField, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputListAutoComplete : public nsIInputListAutoComplete
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTLISTAUTOCOMPLETE

  nsInputListAutoComplete();

private:
  ~nsInputListAutoComplete();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInputListAutoComplete, nsIInputListAutoComplete)

nsInputListAutoComplete::nsInputListAutoComplete()
{
  /* member initializers and constructor code */
}

nsInputListAutoComplete::~nsInputListAutoComplete()
{
  /* destructor code */
}

/* nsIAutoCompleteResult autoCompleteSearch (in AString aSearchString, in nsIDOMHTMLInputElement aField); */
NS_IMETHODIMP nsInputListAutoComplete::AutoCompleteSearch(const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInputListAutoComplete_h__ */
