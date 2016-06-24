/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITimedChannel.idl
 */

#ifndef __gen_nsITimedChannel_h__
#define __gen_nsITimedChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrincipal; /* forward declaration */

namespace mozilla {
class TimeStamp;
}

/* starting interface:    nsITimedChannel */
#define NS_ITIMEDCHANNEL_IID_STR "ca63784d-959c-4c3a-9a59-234a2a520de0"

#define NS_ITIMEDCHANNEL_IID \
  {0xca63784d, 0x959c, 0x4c3a, \
    { 0x9a, 0x59, 0x23, 0x4a, 0x2a, 0x52, 0x0d, 0xe0 }}

class nsITimedChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITIMEDCHANNEL_IID)

  /* attribute boolean timingEnabled; */
  NS_IMETHOD GetTimingEnabled(bool *aTimingEnabled) = 0;
  NS_IMETHOD SetTimingEnabled(bool aTimingEnabled) = 0;

  /* attribute uint16_t redirectCount; */
  NS_IMETHOD GetRedirectCount(uint16_t *aRedirectCount) = 0;
  NS_IMETHOD SetRedirectCount(uint16_t aRedirectCount) = 0;

  /* [noscript] readonly attribute TimeStamp channelCreation; */
  NS_IMETHOD GetChannelCreation(mozilla::TimeStamp *aChannelCreation) = 0;

  /* [noscript] readonly attribute TimeStamp asyncOpen; */
  NS_IMETHOD GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen) = 0;

  /* [noscript] readonly attribute TimeStamp domainLookupStart; */
  NS_IMETHOD GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart) = 0;

  /* [noscript] readonly attribute TimeStamp domainLookupEnd; */
  NS_IMETHOD GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd) = 0;

  /* [noscript] readonly attribute TimeStamp connectStart; */
  NS_IMETHOD GetConnectStart(mozilla::TimeStamp *aConnectStart) = 0;

  /* [noscript] readonly attribute TimeStamp connectEnd; */
  NS_IMETHOD GetConnectEnd(mozilla::TimeStamp *aConnectEnd) = 0;

  /* [noscript] readonly attribute TimeStamp requestStart; */
  NS_IMETHOD GetRequestStart(mozilla::TimeStamp *aRequestStart) = 0;

  /* [noscript] readonly attribute TimeStamp responseStart; */
  NS_IMETHOD GetResponseStart(mozilla::TimeStamp *aResponseStart) = 0;

  /* [noscript] readonly attribute TimeStamp responseEnd; */
  NS_IMETHOD GetResponseEnd(mozilla::TimeStamp *aResponseEnd) = 0;

  /* [noscript] attribute TimeStamp redirectStart; */
  NS_IMETHOD GetRedirectStart(mozilla::TimeStamp *aRedirectStart) = 0;
  NS_IMETHOD SetRedirectStart(mozilla::TimeStamp aRedirectStart) = 0;

  /* [noscript] attribute TimeStamp redirectEnd; */
  NS_IMETHOD GetRedirectEnd(mozilla::TimeStamp *aRedirectEnd) = 0;
  NS_IMETHOD SetRedirectEnd(mozilla::TimeStamp aRedirectEnd) = 0;

  /* [noscript] attribute AString initiatorType; */
  NS_IMETHOD GetInitiatorType(nsAString & aInitiatorType) = 0;
  NS_IMETHOD SetInitiatorType(const nsAString & aInitiatorType) = 0;

  /* [noscript] attribute boolean allRedirectsSameOrigin; */
  NS_IMETHOD GetAllRedirectsSameOrigin(bool *aAllRedirectsSameOrigin) = 0;
  NS_IMETHOD SetAllRedirectsSameOrigin(bool aAllRedirectsSameOrigin) = 0;

  /* [noscript] attribute boolean allRedirectsPassTimingAllowCheck; */
  NS_IMETHOD GetAllRedirectsPassTimingAllowCheck(bool *aAllRedirectsPassTimingAllowCheck) = 0;
  NS_IMETHOD SetAllRedirectsPassTimingAllowCheck(bool aAllRedirectsPassTimingAllowCheck) = 0;

  /* [noscript] boolean timingAllowCheck (in nsIPrincipal origin); */
  NS_IMETHOD TimingAllowCheck(nsIPrincipal *origin, bool *_retval) = 0;

   inline bool TimingAllowCheck(nsIPrincipal* aOrigin) {
    bool allowed = false;
    return NS_SUCCEEDED(TimingAllowCheck(aOrigin, &allowed)) && allowed;
  }
    /* [noscript] readonly attribute TimeStamp cacheReadStart; */
  NS_IMETHOD GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart) = 0;

  /* [noscript] readonly attribute TimeStamp cacheReadEnd; */
  NS_IMETHOD GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd) = 0;

  /* readonly attribute PRTime channelCreationTime; */
  NS_IMETHOD GetChannelCreationTime(PRTime *aChannelCreationTime) = 0;

  /* readonly attribute PRTime asyncOpenTime; */
  NS_IMETHOD GetAsyncOpenTime(PRTime *aAsyncOpenTime) = 0;

  /* readonly attribute PRTime domainLookupStartTime; */
  NS_IMETHOD GetDomainLookupStartTime(PRTime *aDomainLookupStartTime) = 0;

  /* readonly attribute PRTime domainLookupEndTime; */
  NS_IMETHOD GetDomainLookupEndTime(PRTime *aDomainLookupEndTime) = 0;

  /* readonly attribute PRTime connectStartTime; */
  NS_IMETHOD GetConnectStartTime(PRTime *aConnectStartTime) = 0;

  /* readonly attribute PRTime connectEndTime; */
  NS_IMETHOD GetConnectEndTime(PRTime *aConnectEndTime) = 0;

  /* readonly attribute PRTime requestStartTime; */
  NS_IMETHOD GetRequestStartTime(PRTime *aRequestStartTime) = 0;

  /* readonly attribute PRTime responseStartTime; */
  NS_IMETHOD GetResponseStartTime(PRTime *aResponseStartTime) = 0;

  /* readonly attribute PRTime responseEndTime; */
  NS_IMETHOD GetResponseEndTime(PRTime *aResponseEndTime) = 0;

  /* readonly attribute PRTime cacheReadStartTime; */
  NS_IMETHOD GetCacheReadStartTime(PRTime *aCacheReadStartTime) = 0;

  /* readonly attribute PRTime cacheReadEndTime; */
  NS_IMETHOD GetCacheReadEndTime(PRTime *aCacheReadEndTime) = 0;

  /* readonly attribute PRTime redirectStartTime; */
  NS_IMETHOD GetRedirectStartTime(PRTime *aRedirectStartTime) = 0;

  /* readonly attribute PRTime redirectEndTime; */
  NS_IMETHOD GetRedirectEndTime(PRTime *aRedirectEndTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITimedChannel, NS_ITIMEDCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITIMEDCHANNEL \
  NS_IMETHOD GetTimingEnabled(bool *aTimingEnabled) override; \
  NS_IMETHOD SetTimingEnabled(bool aTimingEnabled) override; \
  NS_IMETHOD GetRedirectCount(uint16_t *aRedirectCount) override; \
  NS_IMETHOD SetRedirectCount(uint16_t aRedirectCount) override; \
  NS_IMETHOD GetChannelCreation(mozilla::TimeStamp *aChannelCreation) override; \
  NS_IMETHOD GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen) override; \
  NS_IMETHOD GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart) override; \
  NS_IMETHOD GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd) override; \
  NS_IMETHOD GetConnectStart(mozilla::TimeStamp *aConnectStart) override; \
  NS_IMETHOD GetConnectEnd(mozilla::TimeStamp *aConnectEnd) override; \
  NS_IMETHOD GetRequestStart(mozilla::TimeStamp *aRequestStart) override; \
  NS_IMETHOD GetResponseStart(mozilla::TimeStamp *aResponseStart) override; \
  NS_IMETHOD GetResponseEnd(mozilla::TimeStamp *aResponseEnd) override; \
  NS_IMETHOD GetRedirectStart(mozilla::TimeStamp *aRedirectStart) override; \
  NS_IMETHOD SetRedirectStart(mozilla::TimeStamp aRedirectStart) override; \
  NS_IMETHOD GetRedirectEnd(mozilla::TimeStamp *aRedirectEnd) override; \
  NS_IMETHOD SetRedirectEnd(mozilla::TimeStamp aRedirectEnd) override; \
  NS_IMETHOD GetInitiatorType(nsAString & aInitiatorType) override; \
  NS_IMETHOD SetInitiatorType(const nsAString & aInitiatorType) override; \
  NS_IMETHOD GetAllRedirectsSameOrigin(bool *aAllRedirectsSameOrigin) override; \
  NS_IMETHOD SetAllRedirectsSameOrigin(bool aAllRedirectsSameOrigin) override; \
  NS_IMETHOD GetAllRedirectsPassTimingAllowCheck(bool *aAllRedirectsPassTimingAllowCheck) override; \
  NS_IMETHOD SetAllRedirectsPassTimingAllowCheck(bool aAllRedirectsPassTimingAllowCheck) override; \
  NS_IMETHOD TimingAllowCheck(nsIPrincipal *origin, bool *_retval) override; \
  NS_IMETHOD GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart) override; \
  NS_IMETHOD GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd) override; \
  NS_IMETHOD GetChannelCreationTime(PRTime *aChannelCreationTime) override; \
  NS_IMETHOD GetAsyncOpenTime(PRTime *aAsyncOpenTime) override; \
  NS_IMETHOD GetDomainLookupStartTime(PRTime *aDomainLookupStartTime) override; \
  NS_IMETHOD GetDomainLookupEndTime(PRTime *aDomainLookupEndTime) override; \
  NS_IMETHOD GetConnectStartTime(PRTime *aConnectStartTime) override; \
  NS_IMETHOD GetConnectEndTime(PRTime *aConnectEndTime) override; \
  NS_IMETHOD GetRequestStartTime(PRTime *aRequestStartTime) override; \
  NS_IMETHOD GetResponseStartTime(PRTime *aResponseStartTime) override; \
  NS_IMETHOD GetResponseEndTime(PRTime *aResponseEndTime) override; \
  NS_IMETHOD GetCacheReadStartTime(PRTime *aCacheReadStartTime) override; \
  NS_IMETHOD GetCacheReadEndTime(PRTime *aCacheReadEndTime) override; \
  NS_IMETHOD GetRedirectStartTime(PRTime *aRedirectStartTime) override; \
  NS_IMETHOD GetRedirectEndTime(PRTime *aRedirectEndTime) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITIMEDCHANNEL(_to) \
  NS_IMETHOD GetTimingEnabled(bool *aTimingEnabled) override { return _to GetTimingEnabled(aTimingEnabled); } \
  NS_IMETHOD SetTimingEnabled(bool aTimingEnabled) override { return _to SetTimingEnabled(aTimingEnabled); } \
  NS_IMETHOD GetRedirectCount(uint16_t *aRedirectCount) override { return _to GetRedirectCount(aRedirectCount); } \
  NS_IMETHOD SetRedirectCount(uint16_t aRedirectCount) override { return _to SetRedirectCount(aRedirectCount); } \
  NS_IMETHOD GetChannelCreation(mozilla::TimeStamp *aChannelCreation) override { return _to GetChannelCreation(aChannelCreation); } \
  NS_IMETHOD GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen) override { return _to GetAsyncOpen(aAsyncOpen); } \
  NS_IMETHOD GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart) override { return _to GetDomainLookupStart(aDomainLookupStart); } \
  NS_IMETHOD GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd) override { return _to GetDomainLookupEnd(aDomainLookupEnd); } \
  NS_IMETHOD GetConnectStart(mozilla::TimeStamp *aConnectStart) override { return _to GetConnectStart(aConnectStart); } \
  NS_IMETHOD GetConnectEnd(mozilla::TimeStamp *aConnectEnd) override { return _to GetConnectEnd(aConnectEnd); } \
  NS_IMETHOD GetRequestStart(mozilla::TimeStamp *aRequestStart) override { return _to GetRequestStart(aRequestStart); } \
  NS_IMETHOD GetResponseStart(mozilla::TimeStamp *aResponseStart) override { return _to GetResponseStart(aResponseStart); } \
  NS_IMETHOD GetResponseEnd(mozilla::TimeStamp *aResponseEnd) override { return _to GetResponseEnd(aResponseEnd); } \
  NS_IMETHOD GetRedirectStart(mozilla::TimeStamp *aRedirectStart) override { return _to GetRedirectStart(aRedirectStart); } \
  NS_IMETHOD SetRedirectStart(mozilla::TimeStamp aRedirectStart) override { return _to SetRedirectStart(aRedirectStart); } \
  NS_IMETHOD GetRedirectEnd(mozilla::TimeStamp *aRedirectEnd) override { return _to GetRedirectEnd(aRedirectEnd); } \
  NS_IMETHOD SetRedirectEnd(mozilla::TimeStamp aRedirectEnd) override { return _to SetRedirectEnd(aRedirectEnd); } \
  NS_IMETHOD GetInitiatorType(nsAString & aInitiatorType) override { return _to GetInitiatorType(aInitiatorType); } \
  NS_IMETHOD SetInitiatorType(const nsAString & aInitiatorType) override { return _to SetInitiatorType(aInitiatorType); } \
  NS_IMETHOD GetAllRedirectsSameOrigin(bool *aAllRedirectsSameOrigin) override { return _to GetAllRedirectsSameOrigin(aAllRedirectsSameOrigin); } \
  NS_IMETHOD SetAllRedirectsSameOrigin(bool aAllRedirectsSameOrigin) override { return _to SetAllRedirectsSameOrigin(aAllRedirectsSameOrigin); } \
  NS_IMETHOD GetAllRedirectsPassTimingAllowCheck(bool *aAllRedirectsPassTimingAllowCheck) override { return _to GetAllRedirectsPassTimingAllowCheck(aAllRedirectsPassTimingAllowCheck); } \
  NS_IMETHOD SetAllRedirectsPassTimingAllowCheck(bool aAllRedirectsPassTimingAllowCheck) override { return _to SetAllRedirectsPassTimingAllowCheck(aAllRedirectsPassTimingAllowCheck); } \
  NS_IMETHOD TimingAllowCheck(nsIPrincipal *origin, bool *_retval) override { return _to TimingAllowCheck(origin, _retval); } \
  NS_IMETHOD GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart) override { return _to GetCacheReadStart(aCacheReadStart); } \
  NS_IMETHOD GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd) override { return _to GetCacheReadEnd(aCacheReadEnd); } \
  NS_IMETHOD GetChannelCreationTime(PRTime *aChannelCreationTime) override { return _to GetChannelCreationTime(aChannelCreationTime); } \
  NS_IMETHOD GetAsyncOpenTime(PRTime *aAsyncOpenTime) override { return _to GetAsyncOpenTime(aAsyncOpenTime); } \
  NS_IMETHOD GetDomainLookupStartTime(PRTime *aDomainLookupStartTime) override { return _to GetDomainLookupStartTime(aDomainLookupStartTime); } \
  NS_IMETHOD GetDomainLookupEndTime(PRTime *aDomainLookupEndTime) override { return _to GetDomainLookupEndTime(aDomainLookupEndTime); } \
  NS_IMETHOD GetConnectStartTime(PRTime *aConnectStartTime) override { return _to GetConnectStartTime(aConnectStartTime); } \
  NS_IMETHOD GetConnectEndTime(PRTime *aConnectEndTime) override { return _to GetConnectEndTime(aConnectEndTime); } \
  NS_IMETHOD GetRequestStartTime(PRTime *aRequestStartTime) override { return _to GetRequestStartTime(aRequestStartTime); } \
  NS_IMETHOD GetResponseStartTime(PRTime *aResponseStartTime) override { return _to GetResponseStartTime(aResponseStartTime); } \
  NS_IMETHOD GetResponseEndTime(PRTime *aResponseEndTime) override { return _to GetResponseEndTime(aResponseEndTime); } \
  NS_IMETHOD GetCacheReadStartTime(PRTime *aCacheReadStartTime) override { return _to GetCacheReadStartTime(aCacheReadStartTime); } \
  NS_IMETHOD GetCacheReadEndTime(PRTime *aCacheReadEndTime) override { return _to GetCacheReadEndTime(aCacheReadEndTime); } \
  NS_IMETHOD GetRedirectStartTime(PRTime *aRedirectStartTime) override { return _to GetRedirectStartTime(aRedirectStartTime); } \
  NS_IMETHOD GetRedirectEndTime(PRTime *aRedirectEndTime) override { return _to GetRedirectEndTime(aRedirectEndTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITIMEDCHANNEL(_to) \
  NS_IMETHOD GetTimingEnabled(bool *aTimingEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimingEnabled(aTimingEnabled); } \
  NS_IMETHOD SetTimingEnabled(bool aTimingEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimingEnabled(aTimingEnabled); } \
  NS_IMETHOD GetRedirectCount(uint16_t *aRedirectCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirectCount(aRedirectCount); } \
  NS_IMETHOD SetRedirectCount(uint16_t aRedirectCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRedirectCount(aRedirectCount); } \
  NS_IMETHOD GetChannelCreation(mozilla::TimeStamp *aChannelCreation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelCreation(aChannelCreation); } \
  NS_IMETHOD GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncOpen(aAsyncOpen); } \
  NS_IMETHOD GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainLookupStart(aDomainLookupStart); } \
  NS_IMETHOD GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainLookupEnd(aDomainLookupEnd); } \
  NS_IMETHOD GetConnectStart(mozilla::TimeStamp *aConnectStart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectStart(aConnectStart); } \
  NS_IMETHOD GetConnectEnd(mozilla::TimeStamp *aConnectEnd) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectEnd(aConnectEnd); } \
  NS_IMETHOD GetRequestStart(mozilla::TimeStamp *aRequestStart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestStart(aRequestStart); } \
  NS_IMETHOD GetResponseStart(mozilla::TimeStamp *aResponseStart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseStart(aResponseStart); } \
  NS_IMETHOD GetResponseEnd(mozilla::TimeStamp *aResponseEnd) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseEnd(aResponseEnd); } \
  NS_IMETHOD GetRedirectStart(mozilla::TimeStamp *aRedirectStart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirectStart(aRedirectStart); } \
  NS_IMETHOD SetRedirectStart(mozilla::TimeStamp aRedirectStart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRedirectStart(aRedirectStart); } \
  NS_IMETHOD GetRedirectEnd(mozilla::TimeStamp *aRedirectEnd) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirectEnd(aRedirectEnd); } \
  NS_IMETHOD SetRedirectEnd(mozilla::TimeStamp aRedirectEnd) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRedirectEnd(aRedirectEnd); } \
  NS_IMETHOD GetInitiatorType(nsAString & aInitiatorType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInitiatorType(aInitiatorType); } \
  NS_IMETHOD SetInitiatorType(const nsAString & aInitiatorType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInitiatorType(aInitiatorType); } \
  NS_IMETHOD GetAllRedirectsSameOrigin(bool *aAllRedirectsSameOrigin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllRedirectsSameOrigin(aAllRedirectsSameOrigin); } \
  NS_IMETHOD SetAllRedirectsSameOrigin(bool aAllRedirectsSameOrigin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllRedirectsSameOrigin(aAllRedirectsSameOrigin); } \
  NS_IMETHOD GetAllRedirectsPassTimingAllowCheck(bool *aAllRedirectsPassTimingAllowCheck) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllRedirectsPassTimingAllowCheck(aAllRedirectsPassTimingAllowCheck); } \
  NS_IMETHOD SetAllRedirectsPassTimingAllowCheck(bool aAllRedirectsPassTimingAllowCheck) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllRedirectsPassTimingAllowCheck(aAllRedirectsPassTimingAllowCheck); } \
  NS_IMETHOD TimingAllowCheck(nsIPrincipal *origin, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TimingAllowCheck(origin, _retval); } \
  NS_IMETHOD GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheReadStart(aCacheReadStart); } \
  NS_IMETHOD GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheReadEnd(aCacheReadEnd); } \
  NS_IMETHOD GetChannelCreationTime(PRTime *aChannelCreationTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelCreationTime(aChannelCreationTime); } \
  NS_IMETHOD GetAsyncOpenTime(PRTime *aAsyncOpenTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncOpenTime(aAsyncOpenTime); } \
  NS_IMETHOD GetDomainLookupStartTime(PRTime *aDomainLookupStartTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainLookupStartTime(aDomainLookupStartTime); } \
  NS_IMETHOD GetDomainLookupEndTime(PRTime *aDomainLookupEndTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainLookupEndTime(aDomainLookupEndTime); } \
  NS_IMETHOD GetConnectStartTime(PRTime *aConnectStartTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectStartTime(aConnectStartTime); } \
  NS_IMETHOD GetConnectEndTime(PRTime *aConnectEndTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectEndTime(aConnectEndTime); } \
  NS_IMETHOD GetRequestStartTime(PRTime *aRequestStartTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestStartTime(aRequestStartTime); } \
  NS_IMETHOD GetResponseStartTime(PRTime *aResponseStartTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseStartTime(aResponseStartTime); } \
  NS_IMETHOD GetResponseEndTime(PRTime *aResponseEndTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseEndTime(aResponseEndTime); } \
  NS_IMETHOD GetCacheReadStartTime(PRTime *aCacheReadStartTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheReadStartTime(aCacheReadStartTime); } \
  NS_IMETHOD GetCacheReadEndTime(PRTime *aCacheReadEndTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheReadEndTime(aCacheReadEndTime); } \
  NS_IMETHOD GetRedirectStartTime(PRTime *aRedirectStartTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirectStartTime(aRedirectStartTime); } \
  NS_IMETHOD GetRedirectEndTime(PRTime *aRedirectEndTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirectEndTime(aRedirectEndTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTimedChannel : public nsITimedChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITIMEDCHANNEL

  nsTimedChannel();

private:
  ~nsTimedChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTimedChannel, nsITimedChannel)

nsTimedChannel::nsTimedChannel()
{
  /* member initializers and constructor code */
}

nsTimedChannel::~nsTimedChannel()
{
  /* destructor code */
}

/* attribute boolean timingEnabled; */
NS_IMETHODIMP nsTimedChannel::GetTimingEnabled(bool *aTimingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimedChannel::SetTimingEnabled(bool aTimingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute uint16_t redirectCount; */
NS_IMETHODIMP nsTimedChannel::GetRedirectCount(uint16_t *aRedirectCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimedChannel::SetRedirectCount(uint16_t aRedirectCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp channelCreation; */
NS_IMETHODIMP nsTimedChannel::GetChannelCreation(mozilla::TimeStamp *aChannelCreation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp asyncOpen; */
NS_IMETHODIMP nsTimedChannel::GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp domainLookupStart; */
NS_IMETHODIMP nsTimedChannel::GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp domainLookupEnd; */
NS_IMETHODIMP nsTimedChannel::GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp connectStart; */
NS_IMETHODIMP nsTimedChannel::GetConnectStart(mozilla::TimeStamp *aConnectStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp connectEnd; */
NS_IMETHODIMP nsTimedChannel::GetConnectEnd(mozilla::TimeStamp *aConnectEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp requestStart; */
NS_IMETHODIMP nsTimedChannel::GetRequestStart(mozilla::TimeStamp *aRequestStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp responseStart; */
NS_IMETHODIMP nsTimedChannel::GetResponseStart(mozilla::TimeStamp *aResponseStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp responseEnd; */
NS_IMETHODIMP nsTimedChannel::GetResponseEnd(mozilla::TimeStamp *aResponseEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute TimeStamp redirectStart; */
NS_IMETHODIMP nsTimedChannel::GetRedirectStart(mozilla::TimeStamp *aRedirectStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimedChannel::SetRedirectStart(mozilla::TimeStamp aRedirectStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute TimeStamp redirectEnd; */
NS_IMETHODIMP nsTimedChannel::GetRedirectEnd(mozilla::TimeStamp *aRedirectEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimedChannel::SetRedirectEnd(mozilla::TimeStamp aRedirectEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute AString initiatorType; */
NS_IMETHODIMP nsTimedChannel::GetInitiatorType(nsAString & aInitiatorType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimedChannel::SetInitiatorType(const nsAString & aInitiatorType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute boolean allRedirectsSameOrigin; */
NS_IMETHODIMP nsTimedChannel::GetAllRedirectsSameOrigin(bool *aAllRedirectsSameOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimedChannel::SetAllRedirectsSameOrigin(bool aAllRedirectsSameOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute boolean allRedirectsPassTimingAllowCheck; */
NS_IMETHODIMP nsTimedChannel::GetAllRedirectsPassTimingAllowCheck(bool *aAllRedirectsPassTimingAllowCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimedChannel::SetAllRedirectsPassTimingAllowCheck(bool aAllRedirectsPassTimingAllowCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean timingAllowCheck (in nsIPrincipal origin); */
NS_IMETHODIMP nsTimedChannel::TimingAllowCheck(nsIPrincipal *origin, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp cacheReadStart; */
NS_IMETHODIMP nsTimedChannel::GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp cacheReadEnd; */
NS_IMETHODIMP nsTimedChannel::GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime channelCreationTime; */
NS_IMETHODIMP nsTimedChannel::GetChannelCreationTime(PRTime *aChannelCreationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime asyncOpenTime; */
NS_IMETHODIMP nsTimedChannel::GetAsyncOpenTime(PRTime *aAsyncOpenTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime domainLookupStartTime; */
NS_IMETHODIMP nsTimedChannel::GetDomainLookupStartTime(PRTime *aDomainLookupStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime domainLookupEndTime; */
NS_IMETHODIMP nsTimedChannel::GetDomainLookupEndTime(PRTime *aDomainLookupEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime connectStartTime; */
NS_IMETHODIMP nsTimedChannel::GetConnectStartTime(PRTime *aConnectStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime connectEndTime; */
NS_IMETHODIMP nsTimedChannel::GetConnectEndTime(PRTime *aConnectEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime requestStartTime; */
NS_IMETHODIMP nsTimedChannel::GetRequestStartTime(PRTime *aRequestStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime responseStartTime; */
NS_IMETHODIMP nsTimedChannel::GetResponseStartTime(PRTime *aResponseStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime responseEndTime; */
NS_IMETHODIMP nsTimedChannel::GetResponseEndTime(PRTime *aResponseEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime cacheReadStartTime; */
NS_IMETHODIMP nsTimedChannel::GetCacheReadStartTime(PRTime *aCacheReadStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime cacheReadEndTime; */
NS_IMETHODIMP nsTimedChannel::GetCacheReadEndTime(PRTime *aCacheReadEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime redirectStartTime; */
NS_IMETHODIMP nsTimedChannel::GetRedirectStartTime(PRTime *aRedirectStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime redirectEndTime; */
NS_IMETHODIMP nsTimedChannel::GetRedirectEndTime(PRTime *aRedirectEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITimedChannel_h__ */
