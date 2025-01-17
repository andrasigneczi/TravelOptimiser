/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIResProtocolHandler.idl
 */

#ifndef __gen_nsIResProtocolHandler_h__
#define __gen_nsIResProtocolHandler_h__


#ifndef __gen_nsIProtocolHandler_h__
#include "nsIProtocolHandler.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIResProtocolHandler */
#define NS_IRESPROTOCOLHANDLER_IID_STR "067ca872-e947-4bd6-8946-a479cb6ba5dd"

#define NS_IRESPROTOCOLHANDLER_IID \
  {0x067ca872, 0xe947, 0x4bd6, \
    { 0x89, 0x46, 0xa4, 0x79, 0xcb, 0x6b, 0xa5, 0xdd }}

class NS_NO_VTABLE nsIResProtocolHandler : public nsIProtocolHandler {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRESPROTOCOLHANDLER_IID)

  /* void setSubstitution (in ACString root, in nsIURI baseURI); */
  NS_IMETHOD SetSubstitution(const nsACString & root, nsIURI *baseURI) = 0;

  /* nsIURI getSubstitution (in ACString root); */
  NS_IMETHOD GetSubstitution(const nsACString & root, nsIURI * *_retval) = 0;

  /* boolean hasSubstitution (in ACString root); */
  NS_IMETHOD HasSubstitution(const nsACString & root, bool *_retval) = 0;

  /* AUTF8String resolveURI (in nsIURI resURI); */
  NS_IMETHOD ResolveURI(nsIURI *resURI, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIResProtocolHandler, NS_IRESPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRESPROTOCOLHANDLER \
  NS_IMETHOD SetSubstitution(const nsACString & root, nsIURI *baseURI) override; \
  NS_IMETHOD GetSubstitution(const nsACString & root, nsIURI * *_retval) override; \
  NS_IMETHOD HasSubstitution(const nsACString & root, bool *_retval) override; \
  NS_IMETHOD ResolveURI(nsIURI *resURI, nsACString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRESPROTOCOLHANDLER(_to) \
  NS_IMETHOD SetSubstitution(const nsACString & root, nsIURI *baseURI) override { return _to SetSubstitution(root, baseURI); } \
  NS_IMETHOD GetSubstitution(const nsACString & root, nsIURI * *_retval) override { return _to GetSubstitution(root, _retval); } \
  NS_IMETHOD HasSubstitution(const nsACString & root, bool *_retval) override { return _to HasSubstitution(root, _retval); } \
  NS_IMETHOD ResolveURI(nsIURI *resURI, nsACString & _retval) override { return _to ResolveURI(resURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRESPROTOCOLHANDLER(_to) \
  NS_IMETHOD SetSubstitution(const nsACString & root, nsIURI *baseURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSubstitution(root, baseURI); } \
  NS_IMETHOD GetSubstitution(const nsACString & root, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubstitution(root, _retval); } \
  NS_IMETHOD HasSubstitution(const nsACString & root, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasSubstitution(root, _retval); } \
  NS_IMETHOD ResolveURI(nsIURI *resURI, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResolveURI(resURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsResProtocolHandler : public nsIResProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRESPROTOCOLHANDLER

  nsResProtocolHandler();

private:
  ~nsResProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsResProtocolHandler, nsIResProtocolHandler)

nsResProtocolHandler::nsResProtocolHandler()
{
  /* member initializers and constructor code */
}

nsResProtocolHandler::~nsResProtocolHandler()
{
  /* destructor code */
}

/* void setSubstitution (in ACString root, in nsIURI baseURI); */
NS_IMETHODIMP nsResProtocolHandler::SetSubstitution(const nsACString & root, nsIURI *baseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI getSubstitution (in ACString root); */
NS_IMETHODIMP nsResProtocolHandler::GetSubstitution(const nsACString & root, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasSubstitution (in ACString root); */
NS_IMETHODIMP nsResProtocolHandler::HasSubstitution(const nsACString & root, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String resolveURI (in nsIURI resURI); */
NS_IMETHODIMP nsResProtocolHandler::ResolveURI(nsIURI *resURI, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIResProtocolHandler_h__ */
