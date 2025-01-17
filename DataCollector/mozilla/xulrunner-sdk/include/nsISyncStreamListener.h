/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISyncStreamListener.idl
 */

#ifndef __gen_nsISyncStreamListener_h__
#define __gen_nsISyncStreamListener_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISyncStreamListener */
#define NS_ISYNCSTREAMLISTENER_IID_STR "7e1aa658-6e3f-4521-9946-9685a169f764"

#define NS_ISYNCSTREAMLISTENER_IID \
  {0x7e1aa658, 0x6e3f, 0x4521, \
    { 0x99, 0x46, 0x96, 0x85, 0xa1, 0x69, 0xf7, 0x64 }}

class NS_NO_VTABLE nsISyncStreamListener : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYNCSTREAMLISTENER_IID)

  /* readonly attribute nsIInputStream inputStream; */
  NS_IMETHOD GetInputStream(nsIInputStream * *aInputStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISyncStreamListener, NS_ISYNCSTREAMLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYNCSTREAMLISTENER \
  NS_IMETHOD GetInputStream(nsIInputStream * *aInputStream) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYNCSTREAMLISTENER(_to) \
  NS_IMETHOD GetInputStream(nsIInputStream * *aInputStream) override { return _to GetInputStream(aInputStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYNCSTREAMLISTENER(_to) \
  NS_IMETHOD GetInputStream(nsIInputStream * *aInputStream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStream(aInputStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSyncStreamListener : public nsISyncStreamListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYNCSTREAMLISTENER

  nsSyncStreamListener();

private:
  ~nsSyncStreamListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSyncStreamListener, nsISyncStreamListener)

nsSyncStreamListener::nsSyncStreamListener()
{
  /* member initializers and constructor code */
}

nsSyncStreamListener::~nsSyncStreamListener()
{
  /* destructor code */
}

/* readonly attribute nsIInputStream inputStream; */
NS_IMETHODIMP nsSyncStreamListener::GetInputStream(nsIInputStream * *aInputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISyncStreamListener_h__ */
