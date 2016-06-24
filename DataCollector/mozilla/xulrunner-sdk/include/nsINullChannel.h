/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINullChannel.idl
 */

#ifndef __gen_nsINullChannel_h__
#define __gen_nsINullChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINullChannel */
#define NS_INULLCHANNEL_IID_STR "4610b901-df41-4bb4-bd3f-fd4d6b6d8d68"

#define NS_INULLCHANNEL_IID \
  {0x4610b901, 0xdf41, 0x4bb4, \
    { 0xbd, 0x3f, 0xfd, 0x4d, 0x6b, 0x6d, 0x8d, 0x68 }}

class NS_NO_VTABLE nsINullChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INULLCHANNEL_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINullChannel, NS_INULLCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINULLCHANNEL \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINULLCHANNEL(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINULLCHANNEL(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNullChannel : public nsINullChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINULLCHANNEL

  nsNullChannel();

private:
  ~nsNullChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNullChannel, nsINullChannel)

nsNullChannel::nsNullChannel()
{
  /* member initializers and constructor code */
}

nsNullChannel::~nsNullChannel()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINullChannel_h__ */
