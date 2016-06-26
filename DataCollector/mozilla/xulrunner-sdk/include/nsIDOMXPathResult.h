/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXPathResult.idl
 */

#ifndef __gen_nsIDOMXPathResult_h__
#define __gen_nsIDOMXPathResult_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXPathResult */
#define NS_IDOMXPATHRESULT_IID_STR "75506f84-b504-11d5-a7f2-ca108ab8b6fc"

#define NS_IDOMXPATHRESULT_IID \
  {0x75506f84, 0xb504, 0x11d5, \
    { 0xa7, 0xf2, 0xca, 0x10, 0x8a, 0xb8, 0xb6, 0xfc }}

class NS_NO_VTABLE nsIDOMXPathResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXPATHRESULT_IID)

  enum {
    ANY_TYPE = 0U,
    NUMBER_TYPE = 1U,
    STRING_TYPE = 2U,
    BOOLEAN_TYPE = 3U,
    UNORDERED_NODE_ITERATOR_TYPE = 4U,
    ORDERED_NODE_ITERATOR_TYPE = 5U,
    UNORDERED_NODE_SNAPSHOT_TYPE = 6U,
    ORDERED_NODE_SNAPSHOT_TYPE = 7U,
    ANY_UNORDERED_NODE_TYPE = 8U,
    FIRST_ORDERED_NODE_TYPE = 9U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXPathResult, NS_IDOMXPATHRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXPATHRESULT \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXPATHRESULT(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXPATHRESULT(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXPathResult : public nsIDOMXPathResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXPATHRESULT

  nsDOMXPathResult();

private:
  ~nsDOMXPathResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMXPathResult, nsIDOMXPathResult)

nsDOMXPathResult::nsDOMXPathResult()
{
  /* member initializers and constructor code */
}

nsDOMXPathResult::~nsDOMXPathResult()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXPathResult_h__ */
