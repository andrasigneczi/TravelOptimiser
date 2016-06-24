/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXULDescriptionElement.idl
 */

#ifndef __gen_nsIDOMXULDescriptionElement_h__
#define __gen_nsIDOMXULDescriptionElement_h__


#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULDescriptionElement */
#define NS_IDOMXULDESCRIPTIONELEMENT_IID_STR "64c3500e-e258-4d49-b7ca-c93ab0931ce4"

#define NS_IDOMXULDESCRIPTIONELEMENT_IID \
  {0x64c3500e, 0xe258, 0x4d49, \
    { 0xb7, 0xca, 0xc9, 0x3a, 0xb0, 0x93, 0x1c, 0xe4 }}

class NS_NO_VTABLE nsIDOMXULDescriptionElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULDESCRIPTIONELEMENT_IID)

  /* attribute boolean disabled; */
  NS_IMETHOD GetDisabled(bool *aDisabled) = 0;
  NS_IMETHOD SetDisabled(bool aDisabled) = 0;

  /* attribute boolean crop; */
  NS_IMETHOD GetCrop(bool *aCrop) = 0;
  NS_IMETHOD SetCrop(bool aCrop) = 0;

  /* attribute DOMString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_IMETHOD SetValue(const nsAString & aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULDescriptionElement, NS_IDOMXULDESCRIPTIONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULDESCRIPTIONELEMENT \
  NS_IMETHOD GetDisabled(bool *aDisabled) override; \
  NS_IMETHOD SetDisabled(bool aDisabled) override; \
  NS_IMETHOD GetCrop(bool *aCrop) override; \
  NS_IMETHOD SetCrop(bool aCrop) override; \
  NS_IMETHOD GetValue(nsAString & aValue) override; \
  NS_IMETHOD SetValue(const nsAString & aValue) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULDESCRIPTIONELEMENT(_to) \
  NS_IMETHOD GetDisabled(bool *aDisabled) override { return _to GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) override { return _to SetDisabled(aDisabled); } \
  NS_IMETHOD GetCrop(bool *aCrop) override { return _to GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(bool aCrop) override { return _to SetCrop(aCrop); } \
  NS_IMETHOD GetValue(nsAString & aValue) override { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) override { return _to SetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULDESCRIPTIONELEMENT(_to) \
  NS_IMETHOD GetDisabled(bool *aDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_IMETHOD GetCrop(bool *aCrop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrop(aCrop); } \
  NS_IMETHOD SetCrop(bool aCrop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrop(aCrop); } \
  NS_IMETHOD GetValue(nsAString & aValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULDescriptionElement : public nsIDOMXULDescriptionElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULDESCRIPTIONELEMENT

  nsDOMXULDescriptionElement();

private:
  ~nsDOMXULDescriptionElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMXULDescriptionElement, nsIDOMXULDescriptionElement)

nsDOMXULDescriptionElement::nsDOMXULDescriptionElement()
{
  /* member initializers and constructor code */
}

nsDOMXULDescriptionElement::~nsDOMXULDescriptionElement()
{
  /* destructor code */
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsDOMXULDescriptionElement::GetDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDescriptionElement::SetDisabled(bool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean crop; */
NS_IMETHODIMP nsDOMXULDescriptionElement::GetCrop(bool *aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDescriptionElement::SetCrop(bool aCrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMXULDescriptionElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULDescriptionElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULDescriptionElement_h__ */
