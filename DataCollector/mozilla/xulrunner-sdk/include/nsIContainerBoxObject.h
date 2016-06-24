/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContainerBoxObject.idl
 */

#ifndef __gen_nsIContainerBoxObject_h__
#define __gen_nsIContainerBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIContainerBoxObject */
#define NS_ICONTAINERBOXOBJECT_IID_STR "35d4c04b-3bd3-4375-92e2-a818b4b4acb6"

#define NS_ICONTAINERBOXOBJECT_IID \
  {0x35d4c04b, 0x3bd3, 0x4375, \
    { 0x92, 0xe2, 0xa8, 0x18, 0xb4, 0xb4, 0xac, 0xb6 }}

class NS_NO_VTABLE nsIContainerBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTAINERBOXOBJECT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContainerBoxObject, NS_ICONTAINERBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTAINERBOXOBJECT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTAINERBOXOBJECT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTAINERBOXOBJECT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContainerBoxObject : public nsIContainerBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTAINERBOXOBJECT

  nsContainerBoxObject();

private:
  ~nsContainerBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContainerBoxObject, nsIContainerBoxObject)

nsContainerBoxObject::nsContainerBoxObject()
{
  /* member initializers and constructor code */
}

nsContainerBoxObject::~nsContainerBoxObject()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContainerBoxObject_h__ */
