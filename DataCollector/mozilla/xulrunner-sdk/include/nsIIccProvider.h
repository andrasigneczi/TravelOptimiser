/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIccProvider.idl
 */

#ifndef __gen_nsIIccProvider_h__
#define __gen_nsIIccProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIIccProvider */
#define NS_IICCPROVIDER_IID_STR "09f29ef0-006f-11e5-a0e1-fbef06958398"

#define NS_IICCPROVIDER_IID \
  {0x09f29ef0, 0x006f, 0x11e5, \
    { 0xa0, 0xe1, 0xfb, 0xef, 0x06, 0x95, 0x83, 0x98 }}

class NS_NO_VTABLE nsIIccProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IICCPROVIDER_IID)

  /* nsIDOMDOMRequest readContacts (in unsigned long clientId, in nsIDOMWindow window, in unsigned long contactType); */
  NS_IMETHOD ReadContacts(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest updateContact (in unsigned long clientId, in nsIDOMWindow window, in unsigned long contactType, in jsval contact, in DOMString pin2); */
  NS_IMETHOD UpdateContact(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, JS::HandleValue contact, const nsAString & pin2, nsIDOMDOMRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIccProvider, NS_IICCPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIICCPROVIDER \
  NS_IMETHOD ReadContacts(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, nsIDOMDOMRequest * *_retval) override; \
  NS_IMETHOD UpdateContact(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, JS::HandleValue contact, const nsAString & pin2, nsIDOMDOMRequest * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIICCPROVIDER(_to) \
  NS_IMETHOD ReadContacts(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, nsIDOMDOMRequest * *_retval) override { return _to ReadContacts(clientId, window, contactType, _retval); } \
  NS_IMETHOD UpdateContact(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, JS::HandleValue contact, const nsAString & pin2, nsIDOMDOMRequest * *_retval) override { return _to UpdateContact(clientId, window, contactType, contact, pin2, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIICCPROVIDER(_to) \
  NS_IMETHOD ReadContacts(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadContacts(clientId, window, contactType, _retval); } \
  NS_IMETHOD UpdateContact(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, JS::HandleValue contact, const nsAString & pin2, nsIDOMDOMRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateContact(clientId, window, contactType, contact, pin2, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIccProvider : public nsIIccProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIICCPROVIDER

  nsIccProvider();

private:
  ~nsIccProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsIccProvider, nsIIccProvider)

nsIccProvider::nsIccProvider()
{
  /* member initializers and constructor code */
}

nsIccProvider::~nsIccProvider()
{
  /* destructor code */
}

/* nsIDOMDOMRequest readContacts (in unsigned long clientId, in nsIDOMWindow window, in unsigned long contactType); */
NS_IMETHODIMP nsIccProvider::ReadContacts(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest updateContact (in unsigned long clientId, in nsIDOMWindow window, in unsigned long contactType, in jsval contact, in DOMString pin2); */
NS_IMETHODIMP nsIccProvider::UpdateContact(uint32_t clientId, nsIDOMWindow *window, uint32_t contactType, JS::HandleValue contact, const nsAString & pin2, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIccProvider_h__ */
