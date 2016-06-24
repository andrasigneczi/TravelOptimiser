/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMenuBoxObject.idl
 */

#ifndef __gen_nsIMenuBoxObject_h__
#define __gen_nsIMenuBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMenuBoxObject */
#define NS_IMENUBOXOBJECT_IID_STR "689ebf3d-0184-450a-9bfa-5a26be0e7a8c"

#define NS_IMENUBOXOBJECT_IID \
  {0x689ebf3d, 0x0184, 0x450a, \
    { 0x9b, 0xfa, 0x5a, 0x26, 0xbe, 0x0e, 0x7a, 0x8c }}

class NS_NO_VTABLE nsIMenuBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMENUBOXOBJECT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMenuBoxObject, NS_IMENUBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMENUBOXOBJECT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMENUBOXOBJECT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMENUBOXOBJECT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMenuBoxObject : public nsIMenuBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMENUBOXOBJECT

  nsMenuBoxObject();

private:
  ~nsMenuBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMenuBoxObject, nsIMenuBoxObject)

nsMenuBoxObject::nsMenuBoxObject()
{
  /* member initializers and constructor code */
}

nsMenuBoxObject::~nsMenuBoxObject()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMenuBoxObject_h__ */
