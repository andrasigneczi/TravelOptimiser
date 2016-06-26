/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMStorage.idl
 */

#ifndef __gen_nsIDOMStorage_h__
#define __gen_nsIDOMStorage_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMStorage */
#define NS_IDOMSTORAGE_IID_STR "425a33f0-e0e9-45e7-a95f-9908bd6ae988"

#define NS_IDOMSTORAGE_IID \
  {0x425a33f0, 0xe0e9, 0x45e7, \
    { 0xa9, 0x5f, 0x99, 0x08, 0xbd, 0x6a, 0xe9, 0x88 }}

class NS_NO_VTABLE nsIDOMStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGE_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorage, NS_IDOMSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGE \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGE(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGE(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorage : public nsIDOMStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGE

  nsDOMStorage();

private:
  ~nsDOMStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMStorage, nsIDOMStorage)

nsDOMStorage::nsDOMStorage()
{
  /* member initializers and constructor code */
}

nsDOMStorage::~nsDOMStorage()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorage_h__ */
