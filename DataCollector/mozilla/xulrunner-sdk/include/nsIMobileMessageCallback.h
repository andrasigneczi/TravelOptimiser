/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMobileMessageCallback.idl
 */

#ifndef __gen_nsIMobileMessageCallback_h__
#define __gen_nsIMobileMessageCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMobileMessageCallback */
#define NS_IMOBILEMESSAGECALLBACK_IID_STR "b1367554-51c6-4153-b20a-effec50ca827"

#define NS_IMOBILEMESSAGECALLBACK_IID \
  {0xb1367554, 0x51c6, 0x4153, \
    { 0xb2, 0x0a, 0xef, 0xfe, 0xc5, 0x0c, 0xa8, 0x27 }}

class NS_NO_VTABLE nsIMobileMessageCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILEMESSAGECALLBACK_IID)

  enum {
    SUCCESS_NO_ERROR = 0U,
    NO_SIGNAL_ERROR = 1U,
    NOT_FOUND_ERROR = 2U,
    UNKNOWN_ERROR = 3U,
    INTERNAL_ERROR = 4U,
    NO_SIM_CARD_ERROR = 5U,
    RADIO_DISABLED_ERROR = 6U,
    INVALID_ADDRESS_ERROR = 7U,
    FDN_CHECK_ERROR = 8U,
    NON_ACTIVE_SIM_CARD_ERROR = 9U,
    STORAGE_FULL_ERROR = 10U,
    SIM_NOT_MATCHED_ERROR = 11U
  };

  /* void notifyMessageSent (in nsISupports message); */
  NS_IMETHOD NotifyMessageSent(nsISupports *message) = 0;

  /* void notifySendMessageFailed (in long error, in nsISupports message); */
  NS_IMETHOD NotifySendMessageFailed(int32_t error, nsISupports *message) = 0;

  /* void notifyMessageGot (in nsISupports message); */
  NS_IMETHOD NotifyMessageGot(nsISupports *message) = 0;

  /* void notifyGetMessageFailed (in long error); */
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) = 0;

  /* void notifyMessageDeleted ([array, size_is (count)] in boolean deleted, in uint32_t count); */
  NS_IMETHOD NotifyMessageDeleted(bool *deleted, uint32_t count) = 0;

  /* void notifyDeleteMessageFailed (in long error); */
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) = 0;

  /* void notifyMessageMarkedRead (in boolean read); */
  NS_IMETHOD NotifyMessageMarkedRead(bool read) = 0;

  /* void notifyMarkMessageReadFailed (in long error); */
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) = 0;

  /* void notifySegmentInfoForTextGot (in long segments, in long charsPerSegment, in long charsAvailableInLastSegment); */
  NS_IMETHOD NotifySegmentInfoForTextGot(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment) = 0;

  /* void notifyGetSegmentInfoForTextFailed (in long error); */
  NS_IMETHOD NotifyGetSegmentInfoForTextFailed(int32_t error) = 0;

  /* void notifyGetSmscAddress (in DOMString aSmscAddress); */
  NS_IMETHOD NotifyGetSmscAddress(const nsAString & aSmscAddress) = 0;

  /* void notifyGetSmscAddressFailed (in long error); */
  NS_IMETHOD NotifyGetSmscAddressFailed(int32_t error) = 0;

  /* void notifySetSmscAddress (); */
  NS_IMETHOD NotifySetSmscAddress(void) = 0;

  /* void notifySetSmscAddressFailed (in long error); */
  NS_IMETHOD NotifySetSmscAddressFailed(int32_t error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileMessageCallback, NS_IMOBILEMESSAGECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILEMESSAGECALLBACK \
  NS_IMETHOD NotifyMessageSent(nsISupports *message) override; \
  NS_IMETHOD NotifySendMessageFailed(int32_t error, nsISupports *message) override; \
  NS_IMETHOD NotifyMessageGot(nsISupports *message) override; \
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) override; \
  NS_IMETHOD NotifyMessageDeleted(bool *deleted, uint32_t count) override; \
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) override; \
  NS_IMETHOD NotifyMessageMarkedRead(bool read) override; \
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) override; \
  NS_IMETHOD NotifySegmentInfoForTextGot(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment) override; \
  NS_IMETHOD NotifyGetSegmentInfoForTextFailed(int32_t error) override; \
  NS_IMETHOD NotifyGetSmscAddress(const nsAString & aSmscAddress) override; \
  NS_IMETHOD NotifyGetSmscAddressFailed(int32_t error) override; \
  NS_IMETHOD NotifySetSmscAddress(void) override; \
  NS_IMETHOD NotifySetSmscAddressFailed(int32_t error) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILEMESSAGECALLBACK(_to) \
  NS_IMETHOD NotifyMessageSent(nsISupports *message) override { return _to NotifyMessageSent(message); } \
  NS_IMETHOD NotifySendMessageFailed(int32_t error, nsISupports *message) override { return _to NotifySendMessageFailed(error, message); } \
  NS_IMETHOD NotifyMessageGot(nsISupports *message) override { return _to NotifyMessageGot(message); } \
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) override { return _to NotifyGetMessageFailed(error); } \
  NS_IMETHOD NotifyMessageDeleted(bool *deleted, uint32_t count) override { return _to NotifyMessageDeleted(deleted, count); } \
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) override { return _to NotifyDeleteMessageFailed(error); } \
  NS_IMETHOD NotifyMessageMarkedRead(bool read) override { return _to NotifyMessageMarkedRead(read); } \
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) override { return _to NotifyMarkMessageReadFailed(error); } \
  NS_IMETHOD NotifySegmentInfoForTextGot(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment) override { return _to NotifySegmentInfoForTextGot(segments, charsPerSegment, charsAvailableInLastSegment); } \
  NS_IMETHOD NotifyGetSegmentInfoForTextFailed(int32_t error) override { return _to NotifyGetSegmentInfoForTextFailed(error); } \
  NS_IMETHOD NotifyGetSmscAddress(const nsAString & aSmscAddress) override { return _to NotifyGetSmscAddress(aSmscAddress); } \
  NS_IMETHOD NotifyGetSmscAddressFailed(int32_t error) override { return _to NotifyGetSmscAddressFailed(error); } \
  NS_IMETHOD NotifySetSmscAddress(void) override { return _to NotifySetSmscAddress(); } \
  NS_IMETHOD NotifySetSmscAddressFailed(int32_t error) override { return _to NotifySetSmscAddressFailed(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILEMESSAGECALLBACK(_to) \
  NS_IMETHOD NotifyMessageSent(nsISupports *message) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageSent(message); } \
  NS_IMETHOD NotifySendMessageFailed(int32_t error, nsISupports *message) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySendMessageFailed(error, message); } \
  NS_IMETHOD NotifyMessageGot(nsISupports *message) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageGot(message); } \
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetMessageFailed(error); } \
  NS_IMETHOD NotifyMessageDeleted(bool *deleted, uint32_t count) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageDeleted(deleted, count); } \
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDeleteMessageFailed(error); } \
  NS_IMETHOD NotifyMessageMarkedRead(bool read) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageMarkedRead(read); } \
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMarkMessageReadFailed(error); } \
  NS_IMETHOD NotifySegmentInfoForTextGot(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySegmentInfoForTextGot(segments, charsPerSegment, charsAvailableInLastSegment); } \
  NS_IMETHOD NotifyGetSegmentInfoForTextFailed(int32_t error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetSegmentInfoForTextFailed(error); } \
  NS_IMETHOD NotifyGetSmscAddress(const nsAString & aSmscAddress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetSmscAddress(aSmscAddress); } \
  NS_IMETHOD NotifyGetSmscAddressFailed(int32_t error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetSmscAddressFailed(error); } \
  NS_IMETHOD NotifySetSmscAddress(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySetSmscAddress(); } \
  NS_IMETHOD NotifySetSmscAddressFailed(int32_t error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySetSmscAddressFailed(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileMessageCallback : public nsIMobileMessageCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILEMESSAGECALLBACK

  nsMobileMessageCallback();

private:
  ~nsMobileMessageCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileMessageCallback, nsIMobileMessageCallback)

nsMobileMessageCallback::nsMobileMessageCallback()
{
  /* member initializers and constructor code */
}

nsMobileMessageCallback::~nsMobileMessageCallback()
{
  /* destructor code */
}

/* void notifyMessageSent (in nsISupports message); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageSent(nsISupports *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifySendMessageFailed (in long error, in nsISupports message); */
NS_IMETHODIMP nsMobileMessageCallback::NotifySendMessageFailed(int32_t error, nsISupports *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageGot (in nsISupports message); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageGot(nsISupports *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetMessageFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyGetMessageFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageDeleted ([array, size_is (count)] in boolean deleted, in uint32_t count); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageDeleted(bool *deleted, uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDeleteMessageFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyDeleteMessageFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageMarkedRead (in boolean read); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageMarkedRead(bool read)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMarkMessageReadFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMarkMessageReadFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifySegmentInfoForTextGot (in long segments, in long charsPerSegment, in long charsAvailableInLastSegment); */
NS_IMETHODIMP nsMobileMessageCallback::NotifySegmentInfoForTextGot(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetSegmentInfoForTextFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyGetSegmentInfoForTextFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetSmscAddress (in DOMString aSmscAddress); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyGetSmscAddress(const nsAString & aSmscAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetSmscAddressFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyGetSmscAddressFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifySetSmscAddress (); */
NS_IMETHODIMP nsMobileMessageCallback::NotifySetSmscAddress()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifySetSmscAddressFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifySetSmscAddressFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileMessageCallback_h__ */
