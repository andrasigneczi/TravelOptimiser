/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWeakReference.idl
 */

#ifndef __gen_nsIWeakReference_h__
#define __gen_nsIWeakReference_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "mozilla/MemoryReporting.h"

/* starting interface:    nsIWeakReference */
#define NS_IWEAKREFERENCE_IID_STR "9188bc85-f92e-11d2-81ef-0060083a0bcf"

#define NS_IWEAKREFERENCE_IID \
  {0x9188bc85, 0xf92e, 0x11d2, \
    { 0x81, 0xef, 0x00, 0x60, 0x08, 0x3a, 0x0b, 0xcf }}

class nsIWeakReference : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEAKREFERENCE_IID)

  /* void QueryReferent (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
  NS_IMETHOD QueryReferent(const nsIID & uuid, void **result) = 0;

     virtual size_t SizeOfOnlyThis(mozilla::MallocSizeOf aMallocSizeOf) const = 0;
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWeakReference, NS_IWEAKREFERENCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEAKREFERENCE \
  NS_IMETHOD QueryReferent(const nsIID & uuid, void **result) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEAKREFERENCE(_to) \
  NS_IMETHOD QueryReferent(const nsIID & uuid, void **result) override { return _to QueryReferent(uuid, result); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEAKREFERENCE(_to) \
  NS_IMETHOD QueryReferent(const nsIID & uuid, void **result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryReferent(uuid, result); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWeakReference : public nsIWeakReference
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEAKREFERENCE

  nsWeakReference();

private:
  ~nsWeakReference();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsWeakReference, nsIWeakReference)

nsWeakReference::nsWeakReference()
{
  /* member initializers and constructor code */
}

nsWeakReference::~nsWeakReference()
{
  /* destructor code */
}

/* void QueryReferent (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
NS_IMETHODIMP nsWeakReference::QueryReferent(const nsIID & uuid, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISupportsWeakReference */
#define NS_ISUPPORTSWEAKREFERENCE_IID_STR "9188bc86-f92e-11d2-81ef-0060083a0bcf"

#define NS_ISUPPORTSWEAKREFERENCE_IID \
  {0x9188bc86, 0xf92e, 0x11d2, \
    { 0x81, 0xef, 0x00, 0x60, 0x08, 0x3a, 0x0b, 0xcf }}

class NS_NO_VTABLE nsISupportsWeakReference : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISUPPORTSWEAKREFERENCE_IID)

  /* nsIWeakReference GetWeakReference (); */
  NS_IMETHOD GetWeakReference(nsIWeakReference * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISupportsWeakReference, NS_ISUPPORTSWEAKREFERENCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISUPPORTSWEAKREFERENCE \
  NS_IMETHOD GetWeakReference(nsIWeakReference * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISUPPORTSWEAKREFERENCE(_to) \
  NS_IMETHOD GetWeakReference(nsIWeakReference * *_retval) override { return _to GetWeakReference(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISUPPORTSWEAKREFERENCE(_to) \
  NS_IMETHOD GetWeakReference(nsIWeakReference * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWeakReference(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSupportsWeakReference : public nsISupportsWeakReference
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISUPPORTSWEAKREFERENCE

  nsSupportsWeakReference();

private:
  ~nsSupportsWeakReference();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSupportsWeakReference, nsISupportsWeakReference)

nsSupportsWeakReference::nsSupportsWeakReference()
{
  /* member initializers and constructor code */
}

nsSupportsWeakReference::~nsSupportsWeakReference()
{
  /* destructor code */
}

/* nsIWeakReference GetWeakReference (); */
NS_IMETHODIMP nsSupportsWeakReference::GetWeakReference(nsIWeakReference * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#ifdef MOZILLA_INTERNAL_API
#include "nsIWeakReferenceUtils.h"
#endif

#endif /* __gen_nsIWeakReference_h__ */
