/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMemory.idl
 */

#ifndef __gen_nsIMemory_h__
#define __gen_nsIMemory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMemory */
#define NS_IMEMORY_IID_STR "1e004834-6d8f-425a-bc9c-a2812ed43bb7"

#define NS_IMEMORY_IID \
  {0x1e004834, 0x6d8f, 0x425a, \
    { 0xbc, 0x9c, 0xa2, 0x81, 0x2e, 0xd4, 0x3b, 0xb7 }}

class NS_NO_VTABLE nsIMemory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORY_IID)

  /* void heapMinimize (in boolean immediate); */
  NS_IMETHOD HeapMinimize(bool immediate) = 0;

  /* boolean isLowMemory (); */
  NS_IMETHOD IsLowMemory(bool *_retval) = 0;

  /* boolean isLowMemoryPlatform (); */
  NS_IMETHOD IsLowMemoryPlatform(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemory, NS_IMEMORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORY \
  NS_IMETHOD HeapMinimize(bool immediate) override; \
  NS_IMETHOD IsLowMemory(bool *_retval) override; \
  NS_IMETHOD IsLowMemoryPlatform(bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORY(_to) \
  NS_IMETHOD HeapMinimize(bool immediate) override { return _to HeapMinimize(immediate); } \
  NS_IMETHOD IsLowMemory(bool *_retval) override { return _to IsLowMemory(_retval); } \
  NS_IMETHOD IsLowMemoryPlatform(bool *_retval) override { return _to IsLowMemoryPlatform(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORY(_to) \
  NS_IMETHOD HeapMinimize(bool immediate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HeapMinimize(immediate); } \
  NS_IMETHOD IsLowMemory(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLowMemory(_retval); } \
  NS_IMETHOD IsLowMemoryPlatform(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLowMemoryPlatform(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemory : public nsIMemory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORY

  nsMemory();

private:
  ~nsMemory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMemory, nsIMemory)

nsMemory::nsMemory()
{
  /* member initializers and constructor code */
}

nsMemory::~nsMemory()
{
  /* destructor code */
}

/* void heapMinimize (in boolean immediate); */
NS_IMETHODIMP nsMemory::HeapMinimize(bool immediate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLowMemory (); */
NS_IMETHODIMP nsMemory::IsLowMemory(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLowMemoryPlatform (); */
NS_IMETHODIMP nsMemory::IsLowMemoryPlatform(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMemory_h__ */
