/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDocumentFragment.idl
 */

#ifndef __gen_nsIDOMDocumentFragment_h__
#define __gen_nsIDOMDocumentFragment_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDocumentFragment */
#define NS_IDOMDOCUMENTFRAGMENT_IID_STR "48eb8d72-95bb-402e-a8fc-f2b187abcbdb"

#define NS_IDOMDOCUMENTFRAGMENT_IID \
  {0x48eb8d72, 0x95bb, 0x402e, \
    { 0xa8, 0xfc, 0xf2, 0xb1, 0x87, 0xab, 0xcb, 0xdb }}

class NS_NO_VTABLE nsIDOMDocumentFragment : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTFRAGMENT_IID)

  /* nsIDOMElement querySelector ([Null (Stringify)] in DOMString selectors); */
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) = 0;

  /* nsIDOMNodeList querySelectorAll ([Null (Stringify)] in DOMString selectors); */
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentFragment, NS_IDOMDOCUMENTFRAGMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTFRAGMENT \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) override; \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTFRAGMENT(_to) \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) override { return _to QuerySelector(selectors, _retval); } \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) override { return _to QuerySelectorAll(selectors, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTFRAGMENT(_to) \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QuerySelector(selectors, _retval); } \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QuerySelectorAll(selectors, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentFragment : public nsIDOMDocumentFragment
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTFRAGMENT

  nsDOMDocumentFragment();

private:
  ~nsDOMDocumentFragment();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMDocumentFragment, nsIDOMDocumentFragment)

nsDOMDocumentFragment::nsDOMDocumentFragment()
{
  /* member initializers and constructor code */
}

nsDOMDocumentFragment::~nsDOMDocumentFragment()
{
  /* destructor code */
}

/* nsIDOMElement querySelector ([Null (Stringify)] in DOMString selectors); */
NS_IMETHODIMP nsDOMDocumentFragment::QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList querySelectorAll ([Null (Stringify)] in DOMString selectors); */
NS_IMETHODIMP nsDOMDocumentFragment::QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentFragment_h__ */
