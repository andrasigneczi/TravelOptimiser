/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIForcePendingChannel.idl
 */

#ifndef __gen_nsIForcePendingChannel_h__
#define __gen_nsIForcePendingChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIForcePendingChannel */
#define NS_IFORCEPENDINGCHANNEL_IID_STR "225ab092-1554-423a-9492-606f6db3b4fb"

#define NS_IFORCEPENDINGCHANNEL_IID \
  {0x225ab092, 0x1554, 0x423a, \
    { 0x94, 0x92, 0x60, 0x6f, 0x6d, 0xb3, 0xb4, 0xfb }}

class NS_NO_VTABLE nsIForcePendingChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORCEPENDINGCHANNEL_IID)

  /* void forcePending (in boolean aForcePending); */
  NS_IMETHOD ForcePending(bool aForcePending) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIForcePendingChannel, NS_IFORCEPENDINGCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORCEPENDINGCHANNEL \
  NS_IMETHOD ForcePending(bool aForcePending) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORCEPENDINGCHANNEL(_to) \
  NS_IMETHOD ForcePending(bool aForcePending) override { return _to ForcePending(aForcePending); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORCEPENDINGCHANNEL(_to) \
  NS_IMETHOD ForcePending(bool aForcePending) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForcePending(aForcePending); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsForcePendingChannel : public nsIForcePendingChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORCEPENDINGCHANNEL

  nsForcePendingChannel();

private:
  ~nsForcePendingChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsForcePendingChannel, nsIForcePendingChannel)

nsForcePendingChannel::nsForcePendingChannel()
{
  /* member initializers and constructor code */
}

nsForcePendingChannel::~nsForcePendingChannel()
{
  /* destructor code */
}

/* void forcePending (in boolean aForcePending); */
NS_IMETHODIMP nsForcePendingChannel::ForcePending(bool aForcePending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIForcePendingChannel_h__ */
