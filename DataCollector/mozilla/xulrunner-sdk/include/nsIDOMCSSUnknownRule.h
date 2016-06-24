/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMCSSUnknownRule.idl
 */

#ifndef __gen_nsIDOMCSSUnknownRule_h__
#define __gen_nsIDOMCSSUnknownRule_h__


#ifndef __gen_nsIDOMCSSRule_h__
#include "nsIDOMCSSRule.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMCSSUnknownRule */
#define NS_IDOMCSSUNKNOWNRULE_IID_STR "98f4c27b-fb35-4355-8fd9-546c4697d71a"

#define NS_IDOMCSSUNKNOWNRULE_IID \
  {0x98f4c27b, 0xfb35, 0x4355, \
    { 0x8f, 0xd9, 0x54, 0x6c, 0x46, 0x97, 0xd7, 0x1a }}

class NS_NO_VTABLE nsIDOMCSSUnknownRule : public nsIDOMCSSRule {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCSSUNKNOWNRULE_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMCSSUnknownRule, NS_IDOMCSSUNKNOWNRULE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCSSUNKNOWNRULE \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCSSUNKNOWNRULE(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCSSUNKNOWNRULE(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMCSSUnknownRule : public nsIDOMCSSUnknownRule
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCSSUNKNOWNRULE

  nsDOMCSSUnknownRule();

private:
  ~nsDOMCSSUnknownRule();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMCSSUnknownRule, nsIDOMCSSUnknownRule)

nsDOMCSSUnknownRule::nsDOMCSSUnknownRule()
{
  /* member initializers and constructor code */
}

nsDOMCSSUnknownRule::~nsDOMCSSUnknownRule()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMCSSUnknownRule_h__ */
