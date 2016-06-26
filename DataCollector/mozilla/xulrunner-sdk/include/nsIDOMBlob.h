/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMBlob.idl
 */

#ifndef __gen_nsIDOMBlob_h__
#define __gen_nsIDOMBlob_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMBlob */
#define NS_IDOMBLOB_IID_STR "f344146a-ee1f-417e-8a68-6984ca56f0ae"

#define NS_IDOMBLOB_IID \
  {0xf344146a, 0xee1f, 0x417e, \
    { 0x8a, 0x68, 0x69, 0x84, 0xca, 0x56, 0xf0, 0xae }}

class NS_NO_VTABLE nsIDOMBlob : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMBLOB_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMBlob, NS_IDOMBLOB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMBLOB \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMBLOB(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMBLOB(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMBlob : public nsIDOMBlob
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMBLOB

  nsDOMBlob();

private:
  ~nsDOMBlob();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMBlob, nsIDOMBlob)

nsDOMBlob::nsDOMBlob()
{
  /* member initializers and constructor code */
}

nsDOMBlob::~nsDOMBlob()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMBlob_h__ */
