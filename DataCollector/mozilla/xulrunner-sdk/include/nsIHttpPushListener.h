/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHttpPushListener.idl
 */

#ifndef __gen_nsIHttpPushListener_h__
#define __gen_nsIHttpPushListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHttpChannel; /* forward declaration */


/* starting interface:    nsIHttpPushListener */
#define NS_IHTTPPUSHLISTENER_IID_STR "0d6ce59c-ad5d-4520-b4d3-09664868f279"

#define NS_IHTTPPUSHLISTENER_IID \
  {0x0d6ce59c, 0xad5d, 0x4520, \
    { 0xb4, 0xd3, 0x09, 0x66, 0x48, 0x68, 0xf2, 0x79 }}

class NS_NO_VTABLE nsIHttpPushListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPPUSHLISTENER_IID)

  /* void onPush (in nsIHttpChannel associatedChannel, in nsIHttpChannel pushChannel); */
  NS_IMETHOD OnPush(nsIHttpChannel *associatedChannel, nsIHttpChannel *pushChannel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpPushListener, NS_IHTTPPUSHLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPPUSHLISTENER \
  NS_IMETHOD OnPush(nsIHttpChannel *associatedChannel, nsIHttpChannel *pushChannel) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPPUSHLISTENER(_to) \
  NS_IMETHOD OnPush(nsIHttpChannel *associatedChannel, nsIHttpChannel *pushChannel) override { return _to OnPush(associatedChannel, pushChannel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPPUSHLISTENER(_to) \
  NS_IMETHOD OnPush(nsIHttpChannel *associatedChannel, nsIHttpChannel *pushChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPush(associatedChannel, pushChannel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpPushListener : public nsIHttpPushListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPPUSHLISTENER

  nsHttpPushListener();

private:
  ~nsHttpPushListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsHttpPushListener, nsIHttpPushListener)

nsHttpPushListener::nsHttpPushListener()
{
  /* member initializers and constructor code */
}

nsHttpPushListener::~nsHttpPushListener()
{
  /* destructor code */
}

/* void onPush (in nsIHttpChannel associatedChannel, in nsIHttpChannel pushChannel); */
NS_IMETHODIMP nsHttpPushListener::OnPush(nsIHttpChannel *associatedChannel, nsIHttpChannel *pushChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpPushListener_h__ */
