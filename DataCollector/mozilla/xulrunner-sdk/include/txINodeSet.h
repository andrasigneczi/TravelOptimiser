/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\txINodeSet.idl
 */

#ifndef __gen_txINodeSet_h__
#define __gen_txINodeSet_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    txINodeSet */
#define TXINODESET_IID_STR "15d424c0-6b47-11d9-9791-000a95dc234c"

#define TXINODESET_IID \
  {0x15d424c0, 0x6b47, 0x11d9, \
    { 0x97, 0x91, 0x00, 0x0a, 0x95, 0xdc, 0x23, 0x4c }}

class NS_NO_VTABLE txINodeSet : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(TXINODESET_IID)

  /* nsIDOMNode item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) = 0;

  /* double itemAsNumber (in unsigned long index); */
  NS_IMETHOD ItemAsNumber(uint32_t index, double *_retval) = 0;

  /* DOMString itemAsString (in unsigned long index); */
  NS_IMETHOD ItemAsString(uint32_t index, nsAString & _retval) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* void add (in nsIDOMNode node); */
  NS_IMETHOD Add(nsIDOMNode *node) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(txINodeSet, TXINODESET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_TXINODESET \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) override; \
  NS_IMETHOD ItemAsNumber(uint32_t index, double *_retval) override; \
  NS_IMETHOD ItemAsString(uint32_t index, nsAString & _retval) override; \
  NS_IMETHOD GetLength(uint32_t *aLength) override; \
  NS_IMETHOD Add(nsIDOMNode *node) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_TXINODESET(_to) \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) override { return _to Item(index, _retval); } \
  NS_IMETHOD ItemAsNumber(uint32_t index, double *_retval) override { return _to ItemAsNumber(index, _retval); } \
  NS_IMETHOD ItemAsString(uint32_t index, nsAString & _retval) override { return _to ItemAsString(index, _retval); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return _to GetLength(aLength); } \
  NS_IMETHOD Add(nsIDOMNode *node) override { return _to Add(node); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_TXINODESET(_to) \
  NS_IMETHOD Item(uint32_t index, nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD ItemAsNumber(uint32_t index, double *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ItemAsNumber(index, _retval); } \
  NS_IMETHOD ItemAsString(uint32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ItemAsString(index, _retval); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Add(nsIDOMNode *node) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(node); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class txNodeSet : public txINodeSet
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_TXINODESET

  txNodeSet();

private:
  ~txNodeSet();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(txNodeSet, txINodeSet)

txNodeSet::txNodeSet()
{
  /* member initializers and constructor code */
}

txNodeSet::~txNodeSet()
{
  /* destructor code */
}

/* nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP txNodeSet::Item(uint32_t index, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double itemAsNumber (in unsigned long index); */
NS_IMETHODIMP txNodeSet::ItemAsNumber(uint32_t index, double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString itemAsString (in unsigned long index); */
NS_IMETHODIMP txNodeSet::ItemAsString(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP txNodeSet::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void add (in nsIDOMNode node); */
NS_IMETHODIMP txNodeSet::Add(nsIDOMNode *node)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_txINodeSet_h__ */
