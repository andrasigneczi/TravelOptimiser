/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMFileList.idl
 */

#ifndef __gen_nsIDOMFileList_h__
#define __gen_nsIDOMFileList_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMFileList */
#define NS_IDOMFILELIST_IID_STR "57128a85-34de-42db-a252-84dd57724a59"

#define NS_IDOMFILELIST_IID \
  {0x57128a85, 0x34de, 0x42db, \
    { 0xa2, 0x52, 0x84, 0xdd, 0x57, 0x72, 0x4a, 0x59 }}

class NS_NO_VTABLE nsIDOMFileList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILELIST_IID)

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsISupports item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFileList, NS_IDOMFILELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILELIST \
  NS_IMETHOD GetLength(uint32_t *aLength) override; \
  NS_IMETHOD Item(uint32_t index, nsISupports * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILELIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsISupports * *_retval) override { return _to Item(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILELIST(_to) \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFileList : public nsIDOMFileList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFILELIST

  nsDOMFileList();

private:
  ~nsDOMFileList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMFileList, nsIDOMFileList)

nsDOMFileList::nsDOMFileList()
{
  /* member initializers and constructor code */
}

nsDOMFileList::~nsDOMFileList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMFileList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports item (in unsigned long index); */
NS_IMETHODIMP nsDOMFileList::Item(uint32_t index, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMFileList_h__ */
