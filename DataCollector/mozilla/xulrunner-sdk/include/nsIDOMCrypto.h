/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCrypto.idl
 */

#ifndef __gen_nsIDOMCrypto_h__
#define __gen_nsIDOMCrypto_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIGlobalObject; /* forward declaration */


/* starting interface:    nsIDOMCrypto */
#define NS_IDOMCRYPTO_IID_STR "48d7f7fd-bb85-4c04-9b8b-5cd9131acdef"

#define NS_IDOMCRYPTO_IID \
  {0x48d7f7fd, 0xbb85, 0x4c04, \
    { 0x9b, 0x8b, 0x5c, 0xd9, 0x13, 0x1a, 0xcd, 0xef }}

class NS_NO_VTABLE nsIDOMCrypto : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCRYPTO_IID)

  /* [notxpcom] void init (in nsIGlobalObject parent); */
  NS_IMETHOD_(void) Init(nsIGlobalObject *parent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCrypto, NS_IDOMCRYPTO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCRYPTO \
  NS_IMETHOD_(void) Init(nsIGlobalObject *parent) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCRYPTO(_to) \
  NS_IMETHOD_(void) Init(nsIGlobalObject *parent) override { return _to Init(parent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCRYPTO(_to) \
  NS_IMETHOD_(void) Init(nsIGlobalObject *parent) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCrypto : public nsIDOMCrypto
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCRYPTO

  nsDOMCrypto();

private:
  ~nsDOMCrypto();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCrypto, nsIDOMCrypto)

nsDOMCrypto::nsDOMCrypto()
{
  /* member initializers and constructor code */
}

nsDOMCrypto::~nsDOMCrypto()
{
  /* destructor code */
}

/* [notxpcom] void init (in nsIGlobalObject parent); */
NS_IMETHODIMP_(void) nsDOMCrypto::Init(nsIGlobalObject *parent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCrypto_h__ */
