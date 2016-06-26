/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITimer.idl
 */

#ifndef __gen_nsITimer_h__
#define __gen_nsITimer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIObserver; /* forward declaration */

class nsIEventTarget; /* forward declaration */

#include "mozilla/MemoryReporting.h"
/**
 * The signature of the timer callback function passed to initWithFuncCallback.
 * This is the function that will get called when the timer expires if the
 * timer is initialized via initWithFuncCallback.
 *
 * @param aTimer the timer which has expired
 * @param aClosure opaque parameter passed to initWithFuncCallback
 */
class nsITimer;
typedef void (*nsTimerCallbackFunc) (nsITimer *aTimer, void *aClosure);
class nsITimer; /* forward declaration */


/* starting interface:    nsITimerCallback */
#define NS_ITIMERCALLBACK_IID_STR "a796816d-7d47-4348-9ab8-c7aeb3216a7d"

#define NS_ITIMERCALLBACK_IID \
  {0xa796816d, 0x7d47, 0x4348, \
    { 0x9a, 0xb8, 0xc7, 0xae, 0xb3, 0x21, 0x6a, 0x7d }}

class NS_NO_VTABLE nsITimerCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITIMERCALLBACK_IID)

  /* void notify (in nsITimer timer); */
  NS_IMETHOD Notify(nsITimer *timer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITimerCallback, NS_ITIMERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITIMERCALLBACK \
  NS_IMETHOD Notify(nsITimer *timer) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITIMERCALLBACK(_to) \
  NS_IMETHOD Notify(nsITimer *timer) override { return _to Notify(timer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITIMERCALLBACK(_to) \
  NS_IMETHOD Notify(nsITimer *timer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Notify(timer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTimerCallback : public nsITimerCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITIMERCALLBACK

  nsTimerCallback();

private:
  ~nsTimerCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTimerCallback, nsITimerCallback)

nsTimerCallback::nsTimerCallback()
{
  /* member initializers and constructor code */
}

nsTimerCallback::~nsTimerCallback()
{
  /* destructor code */
}

/* void notify (in nsITimer timer); */
NS_IMETHODIMP nsTimerCallback::Notify(nsITimer *timer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// Two timer deadlines must differ by less than half the PRIntervalTime domain.
#define DELAY_INTERVAL_LIMIT    PR_BIT(8 * sizeof(PRIntervalTime) - 1)

/* starting interface:    nsITimer */
#define NS_ITIMER_IID_STR "c569e813-333f-4b78-8691-13ca5839e10a"

#define NS_ITIMER_IID \
  {0xc569e813, 0x333f, 0x4b78, \
    { 0x86, 0x91, 0x13, 0xca, 0x58, 0x39, 0xe1, 0x0a }}

class nsITimer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITIMER_IID)

  enum {
    TYPE_ONE_SHOT = 0,
    TYPE_REPEATING_SLACK = 1,
    TYPE_REPEATING_PRECISE = 2,
    TYPE_REPEATING_PRECISE_CAN_SKIP = 3
  };

  /* void init (in nsIObserver aObserver, in unsigned long aDelay, in unsigned long aType); */
  NS_IMETHOD Init(nsIObserver *aObserver, uint32_t aDelay, uint32_t aType) = 0;

  /* [noscript] void initWithFuncCallback (in nsTimerCallbackFunc aCallback, in voidPtr aClosure, in unsigned long aDelay, in unsigned long aType); */
  NS_IMETHOD InitWithFuncCallback(nsTimerCallbackFunc aCallback, void *aClosure, uint32_t aDelay, uint32_t aType) = 0;

  /* void initWithCallback (in nsITimerCallback aCallback, in unsigned long aDelay, in unsigned long aType); */
  NS_IMETHOD InitWithCallback(nsITimerCallback *aCallback, uint32_t aDelay, uint32_t aType) = 0;

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

  /* attribute unsigned long delay; */
  NS_IMETHOD GetDelay(uint32_t *aDelay) = 0;
  NS_IMETHOD SetDelay(uint32_t aDelay) = 0;

  /* attribute unsigned long type; */
  NS_IMETHOD GetType(uint32_t *aType) = 0;
  NS_IMETHOD SetType(uint32_t aType) = 0;

  /* [noscript] readonly attribute voidPtr closure; */
  NS_IMETHOD GetClosure(void **aClosure) = 0;

  /* readonly attribute nsITimerCallback callback; */
  NS_IMETHOD GetCallback(nsITimerCallback * *aCallback) = 0;

  /* attribute nsIEventTarget target; */
  NS_IMETHOD GetTarget(nsIEventTarget * *aTarget) = 0;
  NS_IMETHOD SetTarget(nsIEventTarget *aTarget) = 0;

   virtual size_t SizeOfIncludingThis(mozilla::MallocSizeOf aMallocSizeOf) const = 0;
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITimer, NS_ITIMER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITIMER \
  NS_IMETHOD Init(nsIObserver *aObserver, uint32_t aDelay, uint32_t aType) override; \
  NS_IMETHOD InitWithFuncCallback(nsTimerCallbackFunc aCallback, void *aClosure, uint32_t aDelay, uint32_t aType) override; \
  NS_IMETHOD InitWithCallback(nsITimerCallback *aCallback, uint32_t aDelay, uint32_t aType) override; \
  NS_IMETHOD Cancel(void) override; \
  NS_IMETHOD GetDelay(uint32_t *aDelay) override; \
  NS_IMETHOD SetDelay(uint32_t aDelay) override; \
  NS_IMETHOD GetType(uint32_t *aType) override; \
  NS_IMETHOD SetType(uint32_t aType) override; \
  NS_IMETHOD GetClosure(void **aClosure) override; \
  NS_IMETHOD GetCallback(nsITimerCallback * *aCallback) override; \
  NS_IMETHOD GetTarget(nsIEventTarget * *aTarget) override; \
  NS_IMETHOD SetTarget(nsIEventTarget *aTarget) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITIMER(_to) \
  NS_IMETHOD Init(nsIObserver *aObserver, uint32_t aDelay, uint32_t aType) override { return _to Init(aObserver, aDelay, aType); } \
  NS_IMETHOD InitWithFuncCallback(nsTimerCallbackFunc aCallback, void *aClosure, uint32_t aDelay, uint32_t aType) override { return _to InitWithFuncCallback(aCallback, aClosure, aDelay, aType); } \
  NS_IMETHOD InitWithCallback(nsITimerCallback *aCallback, uint32_t aDelay, uint32_t aType) override { return _to InitWithCallback(aCallback, aDelay, aType); } \
  NS_IMETHOD Cancel(void) override { return _to Cancel(); } \
  NS_IMETHOD GetDelay(uint32_t *aDelay) override { return _to GetDelay(aDelay); } \
  NS_IMETHOD SetDelay(uint32_t aDelay) override { return _to SetDelay(aDelay); } \
  NS_IMETHOD GetType(uint32_t *aType) override { return _to GetType(aType); } \
  NS_IMETHOD SetType(uint32_t aType) override { return _to SetType(aType); } \
  NS_IMETHOD GetClosure(void **aClosure) override { return _to GetClosure(aClosure); } \
  NS_IMETHOD GetCallback(nsITimerCallback * *aCallback) override { return _to GetCallback(aCallback); } \
  NS_IMETHOD GetTarget(nsIEventTarget * *aTarget) override { return _to GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(nsIEventTarget *aTarget) override { return _to SetTarget(aTarget); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITIMER(_to) \
  NS_IMETHOD Init(nsIObserver *aObserver, uint32_t aDelay, uint32_t aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aObserver, aDelay, aType); } \
  NS_IMETHOD InitWithFuncCallback(nsTimerCallbackFunc aCallback, void *aClosure, uint32_t aDelay, uint32_t aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithFuncCallback(aCallback, aClosure, aDelay, aType); } \
  NS_IMETHOD InitWithCallback(nsITimerCallback *aCallback, uint32_t aDelay, uint32_t aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithCallback(aCallback, aDelay, aType); } \
  NS_IMETHOD Cancel(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } \
  NS_IMETHOD GetDelay(uint32_t *aDelay) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelay(aDelay); } \
  NS_IMETHOD SetDelay(uint32_t aDelay) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDelay(aDelay); } \
  NS_IMETHOD GetType(uint32_t *aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(uint32_t aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetClosure(void **aClosure) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClosure(aClosure); } \
  NS_IMETHOD GetCallback(nsITimerCallback * *aCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallback(aCallback); } \
  NS_IMETHOD GetTarget(nsIEventTarget * *aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(nsIEventTarget *aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTimer : public nsITimer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITIMER

  nsTimer();

private:
  ~nsTimer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTimer, nsITimer)

nsTimer::nsTimer()
{
  /* member initializers and constructor code */
}

nsTimer::~nsTimer()
{
  /* destructor code */
}

/* void init (in nsIObserver aObserver, in unsigned long aDelay, in unsigned long aType); */
NS_IMETHODIMP nsTimer::Init(nsIObserver *aObserver, uint32_t aDelay, uint32_t aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initWithFuncCallback (in nsTimerCallbackFunc aCallback, in voidPtr aClosure, in unsigned long aDelay, in unsigned long aType); */
NS_IMETHODIMP nsTimer::InitWithFuncCallback(nsTimerCallbackFunc aCallback, void *aClosure, uint32_t aDelay, uint32_t aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithCallback (in nsITimerCallback aCallback, in unsigned long aDelay, in unsigned long aType); */
NS_IMETHODIMP nsTimer::InitWithCallback(nsITimerCallback *aCallback, uint32_t aDelay, uint32_t aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsTimer::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long delay; */
NS_IMETHODIMP nsTimer::GetDelay(uint32_t *aDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimer::SetDelay(uint32_t aDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long type; */
NS_IMETHODIMP nsTimer::GetType(uint32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimer::SetType(uint32_t aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute voidPtr closure; */
NS_IMETHODIMP nsTimer::GetClosure(void **aClosure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsITimerCallback callback; */
NS_IMETHODIMP nsTimer::GetCallback(nsITimerCallback * *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIEventTarget target; */
NS_IMETHODIMP nsTimer::GetTarget(nsIEventTarget * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimer::SetTarget(nsIEventTarget *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_TIMER_CONTRACTID "@mozilla.org/timer;1"
#define NS_TIMER_CALLBACK_TOPIC "timer-callback"

#endif /* __gen_nsITimer_h__ */
