/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINetworkInterceptController.idl
 */

#ifndef __gen_nsINetworkInterceptController_h__
#define __gen_nsINetworkInterceptController_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsIURI; /* forward declaration */

namespace mozilla {
namespace dom {
class ChannelInfo;
}
}

/* starting interface:    nsIInterceptedChannel */
#define NS_IINTERCEPTEDCHANNEL_IID_STR "f2c07a6b-366d-4ef4-85ab-a77f4bcb1646"

#define NS_IINTERCEPTEDCHANNEL_IID \
  {0xf2c07a6b, 0x366d, 0x4ef4, \
    { 0x85, 0xab, 0xa7, 0x7f, 0x4b, 0xcb, 0x16, 0x46 }}

class NS_NO_VTABLE nsIInterceptedChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINTERCEPTEDCHANNEL_IID)

  /* void resetInterception (); */
  NS_IMETHOD ResetInterception(void) = 0;

  /* void synthesizeStatus (in uint16_t status, in ACString reason); */
  NS_IMETHOD SynthesizeStatus(uint16_t status, const nsACString & reason) = 0;

  /* void synthesizeHeader (in ACString name, in ACString value); */
  NS_IMETHOD SynthesizeHeader(const nsACString & name, const nsACString & value) = 0;

  /* void finishSynthesizedResponse (); */
  NS_IMETHOD FinishSynthesizedResponse(void) = 0;

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

  /* readonly attribute nsIOutputStream responseBody; */
  NS_IMETHOD GetResponseBody(nsIOutputStream * *aResponseBody) = 0;

  /* readonly attribute nsIChannel channel; */
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) = 0;

  /* readonly attribute bool isNavigation; */
  NS_IMETHOD GetIsNavigation(bool *aIsNavigation) = 0;

  /* [noscript] void setChannelInfo (in ChannelInfo channelInfo); */
  NS_IMETHOD SetChannelInfo(mozilla::dom::ChannelInfo *channelInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInterceptedChannel, NS_IINTERCEPTEDCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINTERCEPTEDCHANNEL \
  NS_IMETHOD ResetInterception(void) override; \
  NS_IMETHOD SynthesizeStatus(uint16_t status, const nsACString & reason) override; \
  NS_IMETHOD SynthesizeHeader(const nsACString & name, const nsACString & value) override; \
  NS_IMETHOD FinishSynthesizedResponse(void) override; \
  NS_IMETHOD Cancel(void) override; \
  NS_IMETHOD GetResponseBody(nsIOutputStream * *aResponseBody) override; \
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) override; \
  NS_IMETHOD GetIsNavigation(bool *aIsNavigation) override; \
  NS_IMETHOD SetChannelInfo(mozilla::dom::ChannelInfo *channelInfo) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINTERCEPTEDCHANNEL(_to) \
  NS_IMETHOD ResetInterception(void) override { return _to ResetInterception(); } \
  NS_IMETHOD SynthesizeStatus(uint16_t status, const nsACString & reason) override { return _to SynthesizeStatus(status, reason); } \
  NS_IMETHOD SynthesizeHeader(const nsACString & name, const nsACString & value) override { return _to SynthesizeHeader(name, value); } \
  NS_IMETHOD FinishSynthesizedResponse(void) override { return _to FinishSynthesizedResponse(); } \
  NS_IMETHOD Cancel(void) override { return _to Cancel(); } \
  NS_IMETHOD GetResponseBody(nsIOutputStream * *aResponseBody) override { return _to GetResponseBody(aResponseBody); } \
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) override { return _to GetChannel(aChannel); } \
  NS_IMETHOD GetIsNavigation(bool *aIsNavigation) override { return _to GetIsNavigation(aIsNavigation); } \
  NS_IMETHOD SetChannelInfo(mozilla::dom::ChannelInfo *channelInfo) override { return _to SetChannelInfo(channelInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINTERCEPTEDCHANNEL(_to) \
  NS_IMETHOD ResetInterception(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetInterception(); } \
  NS_IMETHOD SynthesizeStatus(uint16_t status, const nsACString & reason) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SynthesizeStatus(status, reason); } \
  NS_IMETHOD SynthesizeHeader(const nsACString & name, const nsACString & value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SynthesizeHeader(name, value); } \
  NS_IMETHOD FinishSynthesizedResponse(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FinishSynthesizedResponse(); } \
  NS_IMETHOD Cancel(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } \
  NS_IMETHOD GetResponseBody(nsIOutputStream * *aResponseBody) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseBody(aResponseBody); } \
  NS_IMETHOD GetChannel(nsIChannel * *aChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannel(aChannel); } \
  NS_IMETHOD GetIsNavigation(bool *aIsNavigation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNavigation(aIsNavigation); } \
  NS_IMETHOD SetChannelInfo(mozilla::dom::ChannelInfo *channelInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChannelInfo(channelInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInterceptedChannel : public nsIInterceptedChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINTERCEPTEDCHANNEL

  nsInterceptedChannel();

private:
  ~nsInterceptedChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInterceptedChannel, nsIInterceptedChannel)

nsInterceptedChannel::nsInterceptedChannel()
{
  /* member initializers and constructor code */
}

nsInterceptedChannel::~nsInterceptedChannel()
{
  /* destructor code */
}

/* void resetInterception (); */
NS_IMETHODIMP nsInterceptedChannel::ResetInterception()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void synthesizeStatus (in uint16_t status, in ACString reason); */
NS_IMETHODIMP nsInterceptedChannel::SynthesizeStatus(uint16_t status, const nsACString & reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void synthesizeHeader (in ACString name, in ACString value); */
NS_IMETHODIMP nsInterceptedChannel::SynthesizeHeader(const nsACString & name, const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finishSynthesizedResponse (); */
NS_IMETHODIMP nsInterceptedChannel::FinishSynthesizedResponse()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsInterceptedChannel::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIOutputStream responseBody; */
NS_IMETHODIMP nsInterceptedChannel::GetResponseBody(nsIOutputStream * *aResponseBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIChannel channel; */
NS_IMETHODIMP nsInterceptedChannel::GetChannel(nsIChannel * *aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool isNavigation; */
NS_IMETHODIMP nsInterceptedChannel::GetIsNavigation(bool *aIsNavigation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setChannelInfo (in ChannelInfo channelInfo); */
NS_IMETHODIMP nsInterceptedChannel::SetChannelInfo(mozilla::dom::ChannelInfo *channelInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINetworkInterceptController */
#define NS_INETWORKINTERCEPTCONTROLLER_IID_STR "69150b77-b561-43a2-bfba-7301dd5a35d0"

#define NS_INETWORKINTERCEPTCONTROLLER_IID \
  {0x69150b77, 0xb561, 0x43a2, \
    { 0xbf, 0xba, 0x73, 0x01, 0xdd, 0x5a, 0x35, 0xd0 }}

class NS_NO_VTABLE nsINetworkInterceptController : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETWORKINTERCEPTCONTROLLER_IID)

  /* bool shouldPrepareForIntercept (in nsIURI aURI, in bool aIsNavigate); */
  NS_IMETHOD ShouldPrepareForIntercept(nsIURI *aURI, bool aIsNavigate, bool *_retval) = 0;

  /* void channelIntercepted (in nsIInterceptedChannel aChannel); */
  NS_IMETHOD ChannelIntercepted(nsIInterceptedChannel *aChannel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetworkInterceptController, NS_INETWORKINTERCEPTCONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETWORKINTERCEPTCONTROLLER \
  NS_IMETHOD ShouldPrepareForIntercept(nsIURI *aURI, bool aIsNavigate, bool *_retval) override; \
  NS_IMETHOD ChannelIntercepted(nsIInterceptedChannel *aChannel) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETWORKINTERCEPTCONTROLLER(_to) \
  NS_IMETHOD ShouldPrepareForIntercept(nsIURI *aURI, bool aIsNavigate, bool *_retval) override { return _to ShouldPrepareForIntercept(aURI, aIsNavigate, _retval); } \
  NS_IMETHOD ChannelIntercepted(nsIInterceptedChannel *aChannel) override { return _to ChannelIntercepted(aChannel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETWORKINTERCEPTCONTROLLER(_to) \
  NS_IMETHOD ShouldPrepareForIntercept(nsIURI *aURI, bool aIsNavigate, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldPrepareForIntercept(aURI, aIsNavigate, _retval); } \
  NS_IMETHOD ChannelIntercepted(nsIInterceptedChannel *aChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ChannelIntercepted(aChannel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetworkInterceptController : public nsINetworkInterceptController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETWORKINTERCEPTCONTROLLER

  nsNetworkInterceptController();

private:
  ~nsNetworkInterceptController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNetworkInterceptController, nsINetworkInterceptController)

nsNetworkInterceptController::nsNetworkInterceptController()
{
  /* member initializers and constructor code */
}

nsNetworkInterceptController::~nsNetworkInterceptController()
{
  /* destructor code */
}

/* bool shouldPrepareForIntercept (in nsIURI aURI, in bool aIsNavigate); */
NS_IMETHODIMP nsNetworkInterceptController::ShouldPrepareForIntercept(nsIURI *aURI, bool aIsNavigate, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void channelIntercepted (in nsIInterceptedChannel aChannel); */
NS_IMETHODIMP nsNetworkInterceptController::ChannelIntercepted(nsIInterceptedChannel *aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINetworkInterceptController_h__ */
