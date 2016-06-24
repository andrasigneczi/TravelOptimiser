/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISecCheckWrapChannel.idl
 */

#ifndef __gen_nsISecCheckWrapChannel_h__
#define __gen_nsISecCheckWrapChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */


/* starting interface:    nsISecCheckWrapChannel */
#define NS_ISECCHECKWRAPCHANNEL_IID_STR "9446c5d5-c9fb-4a6e-acf9-ca4fc666efe0"

#define NS_ISECCHECKWRAPCHANNEL_IID \
  {0x9446c5d5, 0xc9fb, 0x4a6e, \
    { 0xac, 0xf9, 0xca, 0x4f, 0xc6, 0x66, 0xef, 0xe0 }}

class NS_NO_VTABLE nsISecCheckWrapChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECCHECKWRAPCHANNEL_IID)

  /* readonly attribute nsIChannel innerChannel; */
  NS_IMETHOD GetInnerChannel(nsIChannel * *aInnerChannel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecCheckWrapChannel, NS_ISECCHECKWRAPCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECCHECKWRAPCHANNEL \
  NS_IMETHOD GetInnerChannel(nsIChannel * *aInnerChannel) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECCHECKWRAPCHANNEL(_to) \
  NS_IMETHOD GetInnerChannel(nsIChannel * *aInnerChannel) override { return _to GetInnerChannel(aInnerChannel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECCHECKWRAPCHANNEL(_to) \
  NS_IMETHOD GetInnerChannel(nsIChannel * *aInnerChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerChannel(aInnerChannel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecCheckWrapChannel : public nsISecCheckWrapChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECCHECKWRAPCHANNEL

  nsSecCheckWrapChannel();

private:
  ~nsSecCheckWrapChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSecCheckWrapChannel, nsISecCheckWrapChannel)

nsSecCheckWrapChannel::nsSecCheckWrapChannel()
{
  /* member initializers and constructor code */
}

nsSecCheckWrapChannel::~nsSecCheckWrapChannel()
{
  /* destructor code */
}

/* readonly attribute nsIChannel innerChannel; */
NS_IMETHODIMP nsSecCheckWrapChannel::GetInnerChannel(nsIChannel * *aInnerChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISecCheckWrapChannel_h__ */
