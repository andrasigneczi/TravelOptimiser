/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSRuleList.idl
 */

#ifndef __gen_nsIDOMCSSRuleList_h__
#define __gen_nsIDOMCSSRuleList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSRuleList */
#define NS_IDOMCSSRULELIST_IID_STR "a6cf90c0-15b3-11d2-932e-00805f8add32"

#define NS_IDOMCSSRULELIST_IID \
  {0xa6cf90c0, 0x15b3, 0x11d2, \
    { 0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32 }}

class NS_NO_VTABLE nsIDOMCSSRuleList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSRULELIST_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsIDOMCSSRule item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMCSSRule * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSRuleList, NS_IDOMCSSRULELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSRULELIST \
  NS_IMETHOD GetLength(uint32_t *aLength) override; \
  NS_IMETHOD Item(uint32_t index, nsIDOMCSSRule * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSRULELIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMCSSRule * *_retval) override { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSRULELIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMCSSRule * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSRuleList : public nsIDOMCSSRuleList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSRULELIST

  nsDOMCSSRuleList();

private:
  ~nsDOMCSSRuleList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCSSRuleList, nsIDOMCSSRuleList)

nsDOMCSSRuleList::nsDOMCSSRuleList()
{
  /* member initializers and constructor code */
}

nsDOMCSSRuleList::~nsDOMCSSRuleList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMCSSRuleList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMCSSRule item (in unsigned long index); */
NS_IMETHODIMP nsDOMCSSRuleList::Item(uint32_t index, nsIDOMCSSRule * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSRuleList_h__ */
