/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMobileMessageCursorCallback.idl
 */

#ifndef __gen_nsIMobileMessageCursorCallback_h__
#define __gen_nsIMobileMessageCursorCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMobileMessageCursorCallback */
#define NS_IMOBILEMESSAGECURSORCALLBACK_IID_STR "134a6958-543b-46e2-b419-4631a2314164"

#define NS_IMOBILEMESSAGECURSORCALLBACK_IID \
  {0x134a6958, 0x543b, 0x46e2, \
    { 0xb4, 0x19, 0x46, 0x31, 0xa2, 0x31, 0x41, 0x64 }}

class NS_NO_VTABLE nsIMobileMessageCursorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILEMESSAGECURSORCALLBACK_IID)

  /* void notifyCursorError (in long error); */
  NS_IMETHOD NotifyCursorError(int32_t error) = 0;

  /* void notifyCursorResult ([array, size_is (size)] in nsISupports results, in uint32_t size); */
  NS_IMETHOD NotifyCursorResult(nsISupports **results, uint32_t size) = 0;

  /* void notifyCursorDone (); */
  NS_IMETHOD NotifyCursorDone(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileMessageCursorCallback, NS_IMOBILEMESSAGECURSORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILEMESSAGECURSORCALLBACK \
  NS_IMETHOD NotifyCursorError(int32_t error) override; \
  NS_IMETHOD NotifyCursorResult(nsISupports **results, uint32_t size) override; \
  NS_IMETHOD NotifyCursorDone(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILEMESSAGECURSORCALLBACK(_to) \
  NS_IMETHOD NotifyCursorError(int32_t error) override { return _to NotifyCursorError(error); } \
  NS_IMETHOD NotifyCursorResult(nsISupports **results, uint32_t size) override { return _to NotifyCursorResult(results, size); } \
  NS_IMETHOD NotifyCursorDone(void) override { return _to NotifyCursorDone(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILEMESSAGECURSORCALLBACK(_to) \
  NS_IMETHOD NotifyCursorError(int32_t error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCursorError(error); } \
  NS_IMETHOD NotifyCursorResult(nsISupports **results, uint32_t size) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCursorResult(results, size); } \
  NS_IMETHOD NotifyCursorDone(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCursorDone(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileMessageCursorCallback : public nsIMobileMessageCursorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILEMESSAGECURSORCALLBACK

  nsMobileMessageCursorCallback();

private:
  ~nsMobileMessageCursorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileMessageCursorCallback, nsIMobileMessageCursorCallback)

nsMobileMessageCursorCallback::nsMobileMessageCursorCallback()
{
  /* member initializers and constructor code */
}

nsMobileMessageCursorCallback::~nsMobileMessageCursorCallback()
{
  /* destructor code */
}

/* void notifyCursorError (in long error); */
NS_IMETHODIMP nsMobileMessageCursorCallback::NotifyCursorError(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyCursorResult ([array, size_is (size)] in nsISupports results, in uint32_t size); */
NS_IMETHODIMP nsMobileMessageCursorCallback::NotifyCursorResult(nsISupports **results, uint32_t size)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyCursorDone (); */
NS_IMETHODIMP nsMobileMessageCursorCallback::NotifyCursorDone()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileMessageCursorCallback_h__ */
