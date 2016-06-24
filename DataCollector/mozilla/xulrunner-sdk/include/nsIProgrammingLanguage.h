/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProgrammingLanguage.idl
 */

#ifndef __gen_nsIProgrammingLanguage_h__
#define __gen_nsIProgrammingLanguage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIProgrammingLanguage */
#define NS_IPROGRAMMINGLANGUAGE_IID_STR "02ad9f22-3c98-46f3-be4e-2f5c9299e29a"

#define NS_IPROGRAMMINGLANGUAGE_IID \
  {0x02ad9f22, 0x3c98, 0x46f3, \
    { 0xbe, 0x4e, 0x2f, 0x5c, 0x92, 0x99, 0xe2, 0x9a }}

class NS_NO_VTABLE nsIProgrammingLanguage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROGRAMMINGLANGUAGE_IID)

  enum {
    UNKNOWN = 0U,
    JAVASCRIPT = 2U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProgrammingLanguage, NS_IPROGRAMMINGLANGUAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROGRAMMINGLANGUAGE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROGRAMMINGLANGUAGE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROGRAMMINGLANGUAGE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProgrammingLanguage : public nsIProgrammingLanguage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROGRAMMINGLANGUAGE

  nsProgrammingLanguage();

private:
  ~nsProgrammingLanguage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProgrammingLanguage, nsIProgrammingLanguage)

nsProgrammingLanguage::nsProgrammingLanguage()
{
  /* member initializers and constructor code */
}

nsProgrammingLanguage::~nsProgrammingLanguage()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProgrammingLanguage_h__ */
