/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebContentHandlerRegistrar.idl
 */

#ifndef __gen_nsIWebContentHandlerRegistrar_h__
#define __gen_nsIWebContentHandlerRegistrar_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIWebContentHandlerRegistrar */
#define NS_IWEBCONTENTHANDLERREGISTRAR_IID_STR "e6a75410-c93e-42bf-84ca-a5c3ec34a2f1"

#define NS_IWEBCONTENTHANDLERREGISTRAR_IID \
  {0xe6a75410, 0xc93e, 0x42bf, \
    { 0x84, 0xca, 0xa5, 0xc3, 0xec, 0x34, 0xa2, 0xf1 }}

class NS_NO_VTABLE nsIWebContentHandlerRegistrar : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBCONTENTHANDLERREGISTRAR_IID)

  /* void registerContentHandler (in DOMString mimeType, in DOMString uri, in DOMString title, in nsIDOMWindow contentWindow); */
  NS_IMETHOD RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow) = 0;

  /* void registerProtocolHandler (in DOMString protocol, in DOMString uri, in DOMString title, in nsIDOMWindow contentWindow); */
  NS_IMETHOD RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebContentHandlerRegistrar, NS_IWEBCONTENTHANDLERREGISTRAR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBCONTENTHANDLERREGISTRAR \
  NS_IMETHOD RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow) override; \
  NS_IMETHOD RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBCONTENTHANDLERREGISTRAR(_to) \
  NS_IMETHOD RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow) override { return _to RegisterContentHandler(mimeType, uri, title, contentWindow); } \
  NS_IMETHOD RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow) override { return _to RegisterProtocolHandler(protocol, uri, title, contentWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBCONTENTHANDLERREGISTRAR(_to) \
  NS_IMETHOD RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterContentHandler(mimeType, uri, title, contentWindow); } \
  NS_IMETHOD RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterProtocolHandler(protocol, uri, title, contentWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebContentHandlerRegistrar : public nsIWebContentHandlerRegistrar
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBCONTENTHANDLERREGISTRAR

  nsWebContentHandlerRegistrar();

private:
  ~nsWebContentHandlerRegistrar();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsWebContentHandlerRegistrar, nsIWebContentHandlerRegistrar)

nsWebContentHandlerRegistrar::nsWebContentHandlerRegistrar()
{
  /* member initializers and constructor code */
}

nsWebContentHandlerRegistrar::~nsWebContentHandlerRegistrar()
{
  /* destructor code */
}

/* void registerContentHandler (in DOMString mimeType, in DOMString uri, in DOMString title, in nsIDOMWindow contentWindow); */
NS_IMETHODIMP nsWebContentHandlerRegistrar::RegisterContentHandler(const nsAString & mimeType, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerProtocolHandler (in DOMString protocol, in DOMString uri, in DOMString title, in nsIDOMWindow contentWindow); */
NS_IMETHODIMP nsWebContentHandlerRegistrar::RegisterProtocolHandler(const nsAString & protocol, const nsAString & uri, const nsAString & title, nsIDOMWindow *contentWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_WEBCONTENTHANDLERREGISTRAR_CONTRACTID "@mozilla.org/embeddor.implemented/web-content-handler-registrar;1"

#endif /* __gen_nsIWebContentHandlerRegistrar_h__ */
