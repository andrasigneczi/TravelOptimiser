/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIParentChannel.idl
 */

#ifndef __gen_nsIParentChannel_h__
#define __gen_nsIParentChannel_h__


#ifndef __gen_nsIStreamListener_h__
#include "nsIStreamListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITabParent; /* forward declaration */

namespace mozilla {
namespace net {
class HttpChannelParentListener;
}
}

/* starting interface:    nsIParentChannel */
#define NS_IPARENTCHANNEL_IID_STR "e0fc4801-6030-4653-a59f-1fb282bd1a04"

#define NS_IPARENTCHANNEL_IID \
  {0xe0fc4801, 0x6030, 0x4653, \
    { 0xa5, 0x9f, 0x1f, 0xb2, 0x82, 0xbd, 0x1a, 0x04 }}

class NS_NO_VTABLE nsIParentChannel : public nsIStreamListener {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPARENTCHANNEL_IID)

  /* [noscript] void setParentListener (in HttpChannelParentListener listener); */
  NS_IMETHOD SetParentListener(mozilla::net::HttpChannelParentListener *listener) = 0;

  /* [noscript] void notifyTrackingProtectionDisabled (); */
  NS_IMETHOD NotifyTrackingProtectionDisabled(void) = 0;

  /* void delete (); */
  NS_IMETHOD Delete(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIParentChannel, NS_IPARENTCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPARENTCHANNEL \
  NS_IMETHOD SetParentListener(mozilla::net::HttpChannelParentListener *listener) override; \
  NS_IMETHOD NotifyTrackingProtectionDisabled(void) override; \
  NS_IMETHOD Delete(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPARENTCHANNEL(_to) \
  NS_IMETHOD SetParentListener(mozilla::net::HttpChannelParentListener *listener) override { return _to SetParentListener(listener); } \
  NS_IMETHOD NotifyTrackingProtectionDisabled(void) override { return _to NotifyTrackingProtectionDisabled(); } \
  NS_IMETHOD Delete(void) override { return _to Delete(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPARENTCHANNEL(_to) \
  NS_IMETHOD SetParentListener(mozilla::net::HttpChannelParentListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParentListener(listener); } \
  NS_IMETHOD NotifyTrackingProtectionDisabled(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyTrackingProtectionDisabled(); } \
  NS_IMETHOD Delete(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsParentChannel : public nsIParentChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPARENTCHANNEL

  nsParentChannel();

private:
  ~nsParentChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsParentChannel, nsIParentChannel)

nsParentChannel::nsParentChannel()
{
  /* member initializers and constructor code */
}

nsParentChannel::~nsParentChannel()
{
  /* destructor code */
}

/* [noscript] void setParentListener (in HttpChannelParentListener listener); */
NS_IMETHODIMP nsParentChannel::SetParentListener(mozilla::net::HttpChannelParentListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void notifyTrackingProtectionDisabled (); */
NS_IMETHODIMP nsParentChannel::NotifyTrackingProtectionDisabled()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void delete (); */
NS_IMETHODIMP nsParentChannel::Delete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIParentChannel_h__ */
