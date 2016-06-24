/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIScrollBoxObject.idl
 */

#ifndef __gen_nsIScrollBoxObject_h__
#define __gen_nsIScrollBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIScrollBoxObject */
#define NS_ISCROLLBOXOBJECT_IID_STR "56e2ada8-4631-11d4-ba11-001083023c1e"

#define NS_ISCROLLBOXOBJECT_IID \
  {0x56e2ada8, 0x4631, 0x11d4, \
    { 0xba, 0x11, 0x00, 0x10, 0x83, 0x02, 0x3c, 0x1e }}

class NS_NO_VTABLE nsIScrollBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCROLLBOXOBJECT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScrollBoxObject, NS_ISCROLLBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCROLLBOXOBJECT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCROLLBOXOBJECT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCROLLBOXOBJECT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScrollBoxObject : public nsIScrollBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCROLLBOXOBJECT

  nsScrollBoxObject();

private:
  ~nsScrollBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsScrollBoxObject, nsIScrollBoxObject)

nsScrollBoxObject::nsScrollBoxObject()
{
  /* member initializers and constructor code */
}

nsScrollBoxObject::~nsScrollBoxObject()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScrollBoxObject_h__ */
