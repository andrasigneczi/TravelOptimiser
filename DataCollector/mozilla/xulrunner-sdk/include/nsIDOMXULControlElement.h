/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXULControlElement.idl
 */

#ifndef __gen_nsIDOMXULControlElement_h__
#define __gen_nsIDOMXULControlElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIControllers; /* forward declaration */


/* starting interface:    nsIDOMXULControlElement */
#define NS_IDOMXULCONTROLELEMENT_IID_STR "ea7f92d0-b379-4107-91b4-1e69bdd771e3"

#define NS_IDOMXULCONTROLELEMENT_IID \
  {0xea7f92d0, 0xb379, 0x4107, \
    { 0x91, 0xb4, 0x1e, 0x69, 0xbd, 0xd7, 0x71, 0xe3 }}

class NS_NO_VTABLE nsIDOMXULControlElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTROLELEMENT_IID)

  /* attribute boolean disabled; */
  NS_IMETHOD GetDisabled(bool *aDisabled) = 0;
  NS_IMETHOD SetDisabled(bool aDisabled) = 0;

  /* attribute long tabIndex; */
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) = 0;
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULControlElement, NS_IDOMXULCONTROLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTROLELEMENT \
  NS_IMETHOD GetDisabled(bool *aDisabled) override; \
  NS_IMETHOD SetDisabled(bool aDisabled) override; \
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) override; \
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTROLELEMENT(_to) \
  NS_IMETHOD GetDisabled(bool *aDisabled) override { return _to GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) override { return _to SetDisabled(aDisabled); } \
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) override { return _to GetTabIndex(aTabIndex); } \
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) override { return _to SetTabIndex(aTabIndex); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTROLELEMENT(_to) \
  NS_IMETHOD GetDisabled(bool *aDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_IMETHOD GetTabIndex(int32_t *aTabIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabIndex(aTabIndex); } \
  NS_IMETHOD SetTabIndex(int32_t aTabIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabIndex(aTabIndex); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULControlElement : public nsIDOMXULControlElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTROLELEMENT

  nsDOMXULControlElement();

private:
  ~nsDOMXULControlElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMXULControlElement, nsIDOMXULControlElement)

nsDOMXULControlElement::nsDOMXULControlElement()
{
  /* member initializers and constructor code */
}

nsDOMXULControlElement::~nsDOMXULControlElement()
{
  /* destructor code */
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsDOMXULControlElement::GetDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULControlElement::SetDisabled(bool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long tabIndex; */
NS_IMETHODIMP nsDOMXULControlElement::GetTabIndex(int32_t *aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULControlElement::SetTabIndex(int32_t aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULControlElement_h__ */
