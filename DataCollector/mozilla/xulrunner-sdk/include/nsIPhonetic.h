/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPhonetic.idl
 */

#ifndef __gen_nsIPhonetic_h__
#define __gen_nsIPhonetic_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPhonetic */
#define NS_IPHONETIC_IID_STR "bc6ea726-ab56-46b6-a21a-aa7b76d6818f"

#define NS_IPHONETIC_IID \
  {0xbc6ea726, 0xab56, 0x46b6, \
    { 0xa2, 0x1a, 0xaa, 0x7b, 0x76, 0xd6, 0x81, 0x8f }}

class NS_NO_VTABLE nsIPhonetic : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPHONETIC_IID)

  /* readonly attribute DOMString phonetic; */
  NS_IMETHOD GetPhonetic(nsAString & aPhonetic) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPhonetic, NS_IPHONETIC_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPHONETIC \
  NS_IMETHOD GetPhonetic(nsAString & aPhonetic) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPHONETIC(_to) \
  NS_IMETHOD GetPhonetic(nsAString & aPhonetic) override { return _to GetPhonetic(aPhonetic); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPHONETIC(_to) \
  NS_IMETHOD GetPhonetic(nsAString & aPhonetic) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPhonetic(aPhonetic); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPhonetic : public nsIPhonetic
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPHONETIC

  nsPhonetic();

private:
  ~nsPhonetic();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPhonetic, nsIPhonetic)

nsPhonetic::nsPhonetic()
{
  /* member initializers and constructor code */
}

nsPhonetic::~nsPhonetic()
{
  /* destructor code */
}

/* readonly attribute DOMString phonetic; */
NS_IMETHODIMP nsPhonetic::GetPhonetic(nsAString & aPhonetic)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPhonetic_h__ */
