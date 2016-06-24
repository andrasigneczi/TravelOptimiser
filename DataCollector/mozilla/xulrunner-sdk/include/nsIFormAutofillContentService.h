/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFormAutofillContentService.idl
 */

#ifndef __gen_nsIFormAutofillContentService_h__
#define __gen_nsIFormAutofillContentService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLFormElement; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIFormAutofillContentService */
#define NS_IFORMAUTOFILLCONTENTSERVICE_IID_STR "1db29340-99df-4845-9102-0c5d281b2fe8"

#define NS_IFORMAUTOFILLCONTENTSERVICE_IID \
  {0x1db29340, 0x99df, 0x4845, \
    { 0x91, 0x02, 0x0c, 0x5d, 0x28, 0x1b, 0x2f, 0xe8 }}

class NS_NO_VTABLE nsIFormAutofillContentService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMAUTOFILLCONTENTSERVICE_IID)

  /* void requestAutocomplete (in nsIDOMHTMLFormElement aForm, in nsIDOMWindow aWindow); */
  NS_IMETHOD RequestAutocomplete(nsIDOMHTMLFormElement *aForm, nsIDOMWindow *aWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormAutofillContentService, NS_IFORMAUTOFILLCONTENTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMAUTOFILLCONTENTSERVICE \
  NS_IMETHOD RequestAutocomplete(nsIDOMHTMLFormElement *aForm, nsIDOMWindow *aWindow) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMAUTOFILLCONTENTSERVICE(_to) \
  NS_IMETHOD RequestAutocomplete(nsIDOMHTMLFormElement *aForm, nsIDOMWindow *aWindow) override { return _to RequestAutocomplete(aForm, aWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMAUTOFILLCONTENTSERVICE(_to) \
  NS_IMETHOD RequestAutocomplete(nsIDOMHTMLFormElement *aForm, nsIDOMWindow *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestAutocomplete(aForm, aWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormAutofillContentService : public nsIFormAutofillContentService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMAUTOFILLCONTENTSERVICE

  nsFormAutofillContentService();

private:
  ~nsFormAutofillContentService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsFormAutofillContentService, nsIFormAutofillContentService)

nsFormAutofillContentService::nsFormAutofillContentService()
{
  /* member initializers and constructor code */
}

nsFormAutofillContentService::~nsFormAutofillContentService()
{
  /* destructor code */
}

/* void requestAutocomplete (in nsIDOMHTMLFormElement aForm, in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFormAutofillContentService::RequestAutocomplete(nsIDOMHTMLFormElement *aForm, nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFormAutofillContentService_h__ */
