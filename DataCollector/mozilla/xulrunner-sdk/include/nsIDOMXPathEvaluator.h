/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXPathEvaluator.idl
 */

#ifndef __gen_nsIDOMXPathEvaluator_h__
#define __gen_nsIDOMXPathEvaluator_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class XPathException; /* forward declaration */


/* starting interface:    nsIDOMXPathEvaluator */
#define NS_IDOMXPATHEVALUATOR_IID_STR "92584002-d0e2-4b88-9af9-fa6ff59ee002"

#define NS_IDOMXPATHEVALUATOR_IID \
  {0x92584002, 0xd0e2, 0x4b88, \
    { 0x9a, 0xf9, 0xfa, 0x6f, 0xf5, 0x9e, 0xe0, 0x02 }}

class NS_NO_VTABLE nsIDOMXPathEvaluator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXPATHEVALUATOR_IID)

  /* nsISupports evaluate (in DOMString expression, in nsIDOMNode contextNode, in nsIDOMNode resolver, in unsigned short type, in nsISupports result) raises (XPathException,DOMException); */
  NS_IMETHOD Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMNode *resolver, uint16_t type, nsISupports *result, nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXPathEvaluator, NS_IDOMXPATHEVALUATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXPATHEVALUATOR \
  NS_IMETHOD Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMNode *resolver, uint16_t type, nsISupports *result, nsISupports * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXPATHEVALUATOR(_to) \
  NS_IMETHOD Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMNode *resolver, uint16_t type, nsISupports *result, nsISupports * *_retval) override { return _to Evaluate(expression, contextNode, resolver, type, result, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXPATHEVALUATOR(_to) \
  NS_IMETHOD Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMNode *resolver, uint16_t type, nsISupports *result, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Evaluate(expression, contextNode, resolver, type, result, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXPathEvaluator : public nsIDOMXPathEvaluator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXPATHEVALUATOR

  nsDOMXPathEvaluator();

private:
  ~nsDOMXPathEvaluator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMXPathEvaluator, nsIDOMXPathEvaluator)

nsDOMXPathEvaluator::nsDOMXPathEvaluator()
{
  /* member initializers and constructor code */
}

nsDOMXPathEvaluator::~nsDOMXPathEvaluator()
{
  /* destructor code */
}

/* nsISupports evaluate (in DOMString expression, in nsIDOMNode contextNode, in nsIDOMNode resolver, in unsigned short type, in nsISupports result) raises (XPathException,DOMException); */
NS_IMETHODIMP nsDOMXPathEvaluator::Evaluate(const nsAString & expression, nsIDOMNode *contextNode, nsIDOMNode *resolver, uint16_t type, nsISupports *result, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXPathEvaluator_h__ */
