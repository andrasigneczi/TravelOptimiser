/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPACGenerator.idl
 */

#ifndef __gen_nsIPACGenerator_h__
#define __gen_nsIPACGenerator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPACGenerator */
#define NS_IPACGENERATOR_IID_STR "4b3eeeea-1108-4aa0-8f26-e3ebdeb0454c"

#define NS_IPACGENERATOR_IID \
  {0x4b3eeeea, 0x1108, 0x4aa0, \
    { 0x8f, 0x26, 0xe3, 0xeb, 0xde, 0xb0, 0x45, 0x4c }}

class NS_NO_VTABLE nsIPACGenerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPACGENERATOR_IID)

  /* DOMString generate (); */
  NS_IMETHOD Generate(nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPACGenerator, NS_IPACGENERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPACGENERATOR \
  NS_IMETHOD Generate(nsAString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPACGENERATOR(_to) \
  NS_IMETHOD Generate(nsAString & _retval) override { return _to Generate(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPACGENERATOR(_to) \
  NS_IMETHOD Generate(nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Generate(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPACGenerator : public nsIPACGenerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPACGENERATOR

  nsPACGenerator();

private:
  ~nsPACGenerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPACGenerator, nsIPACGenerator)

nsPACGenerator::nsPACGenerator()
{
  /* member initializers and constructor code */
}

nsPACGenerator::~nsPACGenerator()
{
  /* destructor code */
}

/* DOMString generate (); */
NS_IMETHODIMP nsPACGenerator::Generate(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPACGenerator_h__ */
