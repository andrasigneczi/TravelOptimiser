/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIGfxInfo2.idl
 */

#ifndef __gen_nsIGfxInfo2_h__
#define __gen_nsIGfxInfo2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIGfxInfo2 */
#define NS_IGFXINFO2_IID_STR "9c8d8f44-6d52-45aa-8921-734ef4df5dfe"

#define NS_IGFXINFO2_IID \
  {0x9c8d8f44, 0x6d52, 0x45aa, \
    { 0x89, 0x21, 0x73, 0x4e, 0xf4, 0xdf, 0x5d, 0xfe }}

class NS_NO_VTABLE nsIGfxInfo2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGFXINFO2_IID)

  /* readonly attribute DOMString countryCode; */
  NS_IMETHOD GetCountryCode(nsAString & aCountryCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGfxInfo2, NS_IGFXINFO2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGFXINFO2 \
  NS_IMETHOD GetCountryCode(nsAString & aCountryCode) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGFXINFO2(_to) \
  NS_IMETHOD GetCountryCode(nsAString & aCountryCode) override { return _to GetCountryCode(aCountryCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGFXINFO2(_to) \
  NS_IMETHOD GetCountryCode(nsAString & aCountryCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountryCode(aCountryCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGfxInfo2 : public nsIGfxInfo2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGFXINFO2

  nsGfxInfo2();

private:
  ~nsGfxInfo2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsGfxInfo2, nsIGfxInfo2)

nsGfxInfo2::nsGfxInfo2()
{
  /* member initializers and constructor code */
}

nsGfxInfo2::~nsGfxInfo2()
{
  /* destructor code */
}

/* readonly attribute DOMString countryCode; */
NS_IMETHODIMP nsGfxInfo2::GetCountryCode(nsAString & aCountryCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGfxInfo2_h__ */
