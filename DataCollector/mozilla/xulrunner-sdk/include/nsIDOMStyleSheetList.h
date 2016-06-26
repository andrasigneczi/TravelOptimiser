/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMStyleSheetList.idl
 */

#ifndef __gen_nsIDOMStyleSheetList_h__
#define __gen_nsIDOMStyleSheetList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMStyleSheetList */
#define NS_IDOMSTYLESHEETLIST_IID_STR "0e424250-ac2a-4fe2-bccd-a45824af090e"

#define NS_IDOMSTYLESHEETLIST_IID \
  {0x0e424250, 0xac2a, 0x4fe2, \
    { 0xbc, 0xcd, 0xa4, 0x58, 0x24, 0xaf, 0x09, 0x0e }}

class NS_NO_VTABLE nsIDOMStyleSheetList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTYLESHEETLIST_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* [binaryname(SlowItem)] nsIDOMStyleSheet item (in unsigned long index); */
  NS_IMETHOD SlowItem(uint32_t index, nsIDOMStyleSheet * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStyleSheetList, NS_IDOMSTYLESHEETLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTYLESHEETLIST \
  NS_IMETHOD GetLength(uint32_t *aLength) override; \
  NS_IMETHOD SlowItem(uint32_t index, nsIDOMStyleSheet * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTYLESHEETLIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return _to GetLength(aLength); } \
  NS_IMETHOD SlowItem(uint32_t index, nsIDOMStyleSheet * *_retval) override { return _to SlowItem(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTYLESHEETLIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD SlowItem(uint32_t index, nsIDOMStyleSheet * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SlowItem(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStyleSheetList : public nsIDOMStyleSheetList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTYLESHEETLIST

  nsDOMStyleSheetList();

private:
  ~nsDOMStyleSheetList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMStyleSheetList, nsIDOMStyleSheetList)

nsDOMStyleSheetList::nsDOMStyleSheetList()
{
  /* member initializers and constructor code */
}

nsDOMStyleSheetList::~nsDOMStyleSheetList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMStyleSheetList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(SlowItem)] nsIDOMStyleSheet item (in unsigned long index); */
NS_IMETHODIMP nsDOMStyleSheetList::SlowItem(uint32_t index, nsIDOMStyleSheet * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStyleSheetList_h__ */
