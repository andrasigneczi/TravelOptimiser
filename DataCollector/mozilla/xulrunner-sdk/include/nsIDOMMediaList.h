/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMediaList.idl
 */

#ifndef __gen_nsIDOMMediaList_h__
#define __gen_nsIDOMMediaList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMediaList */
#define NS_IDOMMEDIALIST_IID_STR "9b0c2ed7-111c-4824-adf9-ef0da6dad371"

#define NS_IDOMMEDIALIST_IID \
  {0x9b0c2ed7, 0x111c, 0x4824, \
    { 0xad, 0xf9, 0xef, 0x0d, 0xa6, 0xda, 0xd3, 0x71 }}

class NS_NO_VTABLE nsIDOMMediaList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMEDIALIST_IID)

  /* attribute DOMString mediaText; */
  NS_IMETHOD GetMediaText(nsAString & aMediaText) = 0;
  NS_IMETHOD SetMediaText(const nsAString & aMediaText) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* DOMString item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) = 0;

  /* void deleteMedium (in DOMString oldMedium) raises (DOMException); */
  NS_IMETHOD DeleteMedium(const nsAString & oldMedium) = 0;

  /* void appendMedium (in DOMString newMedium) raises (DOMException); */
  NS_IMETHOD AppendMedium(const nsAString & newMedium) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMediaList, NS_IDOMMEDIALIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMEDIALIST \
  NS_IMETHOD GetMediaText(nsAString & aMediaText) override; \
  NS_IMETHOD SetMediaText(const nsAString & aMediaText) override; \
  NS_IMETHOD GetLength(uint32_t *aLength) override; \
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) override; \
  NS_IMETHOD DeleteMedium(const nsAString & oldMedium) override; \
  NS_IMETHOD AppendMedium(const nsAString & newMedium) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMEDIALIST(_to) \
  NS_IMETHOD GetMediaText(nsAString & aMediaText) override { return _to GetMediaText(aMediaText); } \
  NS_IMETHOD SetMediaText(const nsAString & aMediaText) override { return _to SetMediaText(aMediaText); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return _to GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) override { return _to Item(index, _retval); } \
  NS_IMETHOD DeleteMedium(const nsAString & oldMedium) override { return _to DeleteMedium(oldMedium); } \
  NS_IMETHOD AppendMedium(const nsAString & newMedium) override { return _to AppendMedium(newMedium); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMEDIALIST(_to) \
  NS_IMETHOD GetMediaText(nsAString & aMediaText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMediaText(aMediaText); } \
  NS_IMETHOD SetMediaText(const nsAString & aMediaText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMediaText(aMediaText); } \
  NS_IMETHOD GetLength(uint32_t *aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD DeleteMedium(const nsAString & oldMedium) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteMedium(oldMedium); } \
  NS_IMETHOD AppendMedium(const nsAString & newMedium) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendMedium(newMedium); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMediaList : public nsIDOMMediaList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMEDIALIST

  nsDOMMediaList();

private:
  ~nsDOMMediaList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMMediaList, nsIDOMMediaList)

nsDOMMediaList::nsDOMMediaList()
{
  /* member initializers and constructor code */
}

nsDOMMediaList::~nsDOMMediaList()
{
  /* destructor code */
}

/* attribute DOMString mediaText; */
NS_IMETHODIMP nsDOMMediaList::GetMediaText(nsAString & aMediaText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMediaList::SetMediaText(const nsAString & aMediaText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMMediaList::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString item (in unsigned long index); */
NS_IMETHODIMP nsDOMMediaList::Item(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteMedium (in DOMString oldMedium) raises (DOMException); */
NS_IMETHODIMP nsDOMMediaList::DeleteMedium(const nsAString & oldMedium)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendMedium (in DOMString newMedium) raises (DOMException); */
NS_IMETHODIMP nsDOMMediaList::AppendMedium(const nsAString & newMedium)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMediaList_h__ */
