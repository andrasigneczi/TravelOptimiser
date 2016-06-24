/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDNSListener.idl
 */

#ifndef __gen_nsIDNSListener_h__
#define __gen_nsIDNSListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICancelable; /* forward declaration */

class nsIDNSRecord; /* forward declaration */


/* starting interface:    nsIDNSListener */
#define NS_IDNSLISTENER_IID_STR "27d49bfe-280c-49e0-bbaa-f6200c232c3d"

#define NS_IDNSLISTENER_IID \
  {0x27d49bfe, 0x280c, 0x49e0, \
    { 0xbb, 0xaa, 0xf6, 0x20, 0x0c, 0x23, 0x2c, 0x3d }}

class NS_NO_VTABLE nsIDNSListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSLISTENER_IID)

  /* void onLookupComplete (in nsICancelable aRequest, in nsIDNSRecord aRecord, in nsresult aStatus); */
  NS_IMETHOD OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSListener, NS_IDNSLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSLISTENER \
  NS_IMETHOD OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSLISTENER(_to) \
  NS_IMETHOD OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus) override { return _to OnLookupComplete(aRequest, aRecord, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSLISTENER(_to) \
  NS_IMETHOD OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnLookupComplete(aRequest, aRecord, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSListener : public nsIDNSListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSLISTENER

  nsDNSListener();

private:
  ~nsDNSListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDNSListener, nsIDNSListener)

nsDNSListener::nsDNSListener()
{
  /* member initializers and constructor code */
}

nsDNSListener::~nsDNSListener()
{
  /* destructor code */
}

/* void onLookupComplete (in nsICancelable aRequest, in nsIDNSRecord aRecord, in nsresult aStatus); */
NS_IMETHODIMP nsDNSListener::OnLookupComplete(nsICancelable *aRequest, nsIDNSRecord *aRecord, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDNSListenerProxy */
#define NS_IDNSLISTENERPROXY_IID_STR "60eff0e4-6f7c-493c-add9-1cbea59063ad"

#define NS_IDNSLISTENERPROXY_IID \
  {0x60eff0e4, 0x6f7c, 0x493c, \
    { 0xad, 0xd9, 0x1c, 0xbe, 0xa5, 0x90, 0x63, 0xad }}

class NS_NO_VTABLE nsIDNSListenerProxy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSLISTENERPROXY_IID)

  /* readonly attribute nsIDNSListener originalListener; */
  NS_IMETHOD GetOriginalListener(nsIDNSListener * *aOriginalListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSListenerProxy, NS_IDNSLISTENERPROXY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSLISTENERPROXY \
  NS_IMETHOD GetOriginalListener(nsIDNSListener * *aOriginalListener) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSLISTENERPROXY(_to) \
  NS_IMETHOD GetOriginalListener(nsIDNSListener * *aOriginalListener) override { return _to GetOriginalListener(aOriginalListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSLISTENERPROXY(_to) \
  NS_IMETHOD GetOriginalListener(nsIDNSListener * *aOriginalListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginalListener(aOriginalListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSListenerProxy : public nsIDNSListenerProxy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSLISTENERPROXY

  nsDNSListenerProxy();

private:
  ~nsDNSListenerProxy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDNSListenerProxy, nsIDNSListenerProxy)

nsDNSListenerProxy::nsDNSListenerProxy()
{
  /* member initializers and constructor code */
}

nsDNSListenerProxy::~nsDNSListenerProxy()
{
  /* destructor code */
}

/* readonly attribute nsIDNSListener originalListener; */
NS_IMETHODIMP nsDNSListenerProxy::GetOriginalListener(nsIDNSListener * *aOriginalListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDNSListener_h__ */
