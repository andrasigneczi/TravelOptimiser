/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAsyncShutdown.idl
 */

#ifndef __gen_nsIAsyncShutdown_h__
#define __gen_nsIAsyncShutdown_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPropertyBag_h__
#include "nsIPropertyBag.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAsyncShutdownClient; /* forward declaration */


/* starting interface:    nsIAsyncShutdownBlocker */
#define NS_IASYNCSHUTDOWNBLOCKER_IID_STR "4ef43f29-6715-4b57-a750-2ff83695ddce"

#define NS_IASYNCSHUTDOWNBLOCKER_IID \
  {0x4ef43f29, 0x6715, 0x4b57, \
    { 0xa7, 0x50, 0x2f, 0xf8, 0x36, 0x95, 0xdd, 0xce }}

class NS_NO_VTABLE nsIAsyncShutdownBlocker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCSHUTDOWNBLOCKER_IID)

  /* readonly attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* void blockShutdown (in nsIAsyncShutdownClient aBarrierClient); */
  NS_IMETHOD BlockShutdown(nsIAsyncShutdownClient *aBarrierClient) = 0;

  /* readonly attribute nsIPropertyBag state; */
  NS_IMETHOD GetState(nsIPropertyBag * *aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncShutdownBlocker, NS_IASYNCSHUTDOWNBLOCKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCSHUTDOWNBLOCKER \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD BlockShutdown(nsIAsyncShutdownClient *aBarrierClient) override; \
  NS_IMETHOD GetState(nsIPropertyBag * *aState) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCSHUTDOWNBLOCKER(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD BlockShutdown(nsIAsyncShutdownClient *aBarrierClient) override { return _to BlockShutdown(aBarrierClient); } \
  NS_IMETHOD GetState(nsIPropertyBag * *aState) override { return _to GetState(aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCSHUTDOWNBLOCKER(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD BlockShutdown(nsIAsyncShutdownClient *aBarrierClient) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BlockShutdown(aBarrierClient); } \
  NS_IMETHOD GetState(nsIPropertyBag * *aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncShutdownBlocker : public nsIAsyncShutdownBlocker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCSHUTDOWNBLOCKER

  nsAsyncShutdownBlocker();

private:
  ~nsAsyncShutdownBlocker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAsyncShutdownBlocker, nsIAsyncShutdownBlocker)

nsAsyncShutdownBlocker::nsAsyncShutdownBlocker()
{
  /* member initializers and constructor code */
}

nsAsyncShutdownBlocker::~nsAsyncShutdownBlocker()
{
  /* destructor code */
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsAsyncShutdownBlocker::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blockShutdown (in nsIAsyncShutdownClient aBarrierClient); */
NS_IMETHODIMP nsAsyncShutdownBlocker::BlockShutdown(nsIAsyncShutdownClient *aBarrierClient)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPropertyBag state; */
NS_IMETHODIMP nsAsyncShutdownBlocker::GetState(nsIPropertyBag * *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAsyncShutdownClient */
#define NS_IASYNCSHUTDOWNCLIENT_IID_STR "d2031049-b990-43a2-95be-59f8a3ca5954"

#define NS_IASYNCSHUTDOWNCLIENT_IID \
  {0xd2031049, 0xb990, 0x43a2, \
    { 0x95, 0xbe, 0x59, 0xf8, 0xa3, 0xca, 0x59, 0x54 }}

class NS_NO_VTABLE nsIAsyncShutdownClient : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCSHUTDOWNCLIENT_IID)

  /* readonly attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* void addBlocker (in nsIAsyncShutdownBlocker aBlocker, in AString aFileName, in long aLineNumber, in AString aStack); */
  NS_IMETHOD AddBlocker(nsIAsyncShutdownBlocker *aBlocker, const nsAString & aFileName, int32_t aLineNumber, const nsAString & aStack) = 0;

  /* void removeBlocker (in nsIAsyncShutdownBlocker aBlocker); */
  NS_IMETHOD RemoveBlocker(nsIAsyncShutdownBlocker *aBlocker) = 0;

  /* readonly attribute jsval jsclient; */
  NS_IMETHOD GetJsclient(JS::MutableHandleValue aJsclient) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncShutdownClient, NS_IASYNCSHUTDOWNCLIENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCSHUTDOWNCLIENT \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD AddBlocker(nsIAsyncShutdownBlocker *aBlocker, const nsAString & aFileName, int32_t aLineNumber, const nsAString & aStack) override; \
  NS_IMETHOD RemoveBlocker(nsIAsyncShutdownBlocker *aBlocker) override; \
  NS_IMETHOD GetJsclient(JS::MutableHandleValue aJsclient) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCSHUTDOWNCLIENT(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD AddBlocker(nsIAsyncShutdownBlocker *aBlocker, const nsAString & aFileName, int32_t aLineNumber, const nsAString & aStack) override { return _to AddBlocker(aBlocker, aFileName, aLineNumber, aStack); } \
  NS_IMETHOD RemoveBlocker(nsIAsyncShutdownBlocker *aBlocker) override { return _to RemoveBlocker(aBlocker); } \
  NS_IMETHOD GetJsclient(JS::MutableHandleValue aJsclient) override { return _to GetJsclient(aJsclient); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCSHUTDOWNCLIENT(_to) \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD AddBlocker(nsIAsyncShutdownBlocker *aBlocker, const nsAString & aFileName, int32_t aLineNumber, const nsAString & aStack) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddBlocker(aBlocker, aFileName, aLineNumber, aStack); } \
  NS_IMETHOD RemoveBlocker(nsIAsyncShutdownBlocker *aBlocker) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveBlocker(aBlocker); } \
  NS_IMETHOD GetJsclient(JS::MutableHandleValue aJsclient) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJsclient(aJsclient); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncShutdownClient : public nsIAsyncShutdownClient
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCSHUTDOWNCLIENT

  nsAsyncShutdownClient();

private:
  ~nsAsyncShutdownClient();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAsyncShutdownClient, nsIAsyncShutdownClient)

nsAsyncShutdownClient::nsAsyncShutdownClient()
{
  /* member initializers and constructor code */
}

nsAsyncShutdownClient::~nsAsyncShutdownClient()
{
  /* destructor code */
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsAsyncShutdownClient::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addBlocker (in nsIAsyncShutdownBlocker aBlocker, in AString aFileName, in long aLineNumber, in AString aStack); */
NS_IMETHODIMP nsAsyncShutdownClient::AddBlocker(nsIAsyncShutdownBlocker *aBlocker, const nsAString & aFileName, int32_t aLineNumber, const nsAString & aStack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeBlocker (in nsIAsyncShutdownBlocker aBlocker); */
NS_IMETHODIMP nsAsyncShutdownClient::RemoveBlocker(nsIAsyncShutdownBlocker *aBlocker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval jsclient; */
NS_IMETHODIMP nsAsyncShutdownClient::GetJsclient(JS::MutableHandleValue aJsclient)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAsyncShutdownCompletionCallback */
#define NS_IASYNCSHUTDOWNCOMPLETIONCALLBACK_IID_STR "910c9309-1da0-4dd0-8bdb-a325a38c604e"

#define NS_IASYNCSHUTDOWNCOMPLETIONCALLBACK_IID \
  {0x910c9309, 0x1da0, 0x4dd0, \
    { 0x8b, 0xdb, 0xa3, 0x25, 0xa3, 0x8c, 0x60, 0x4e }}

class NS_NO_VTABLE nsIAsyncShutdownCompletionCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCSHUTDOWNCOMPLETIONCALLBACK_IID)

  /* void done (); */
  NS_IMETHOD Done(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncShutdownCompletionCallback, NS_IASYNCSHUTDOWNCOMPLETIONCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCSHUTDOWNCOMPLETIONCALLBACK \
  NS_IMETHOD Done(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCSHUTDOWNCOMPLETIONCALLBACK(_to) \
  NS_IMETHOD Done(void) override { return _to Done(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCSHUTDOWNCOMPLETIONCALLBACK(_to) \
  NS_IMETHOD Done(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Done(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncShutdownCompletionCallback : public nsIAsyncShutdownCompletionCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCSHUTDOWNCOMPLETIONCALLBACK

  nsAsyncShutdownCompletionCallback();

private:
  ~nsAsyncShutdownCompletionCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAsyncShutdownCompletionCallback, nsIAsyncShutdownCompletionCallback)

nsAsyncShutdownCompletionCallback::nsAsyncShutdownCompletionCallback()
{
  /* member initializers and constructor code */
}

nsAsyncShutdownCompletionCallback::~nsAsyncShutdownCompletionCallback()
{
  /* destructor code */
}

/* void done (); */
NS_IMETHODIMP nsAsyncShutdownCompletionCallback::Done()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAsyncShutdownBarrier */
#define NS_IASYNCSHUTDOWNBARRIER_IID_STR "50fa8a86-9c91-4256-8389-17d310adec90"

#define NS_IASYNCSHUTDOWNBARRIER_IID \
  {0x50fa8a86, 0x9c91, 0x4256, \
    { 0x83, 0x89, 0x17, 0xd3, 0x10, 0xad, 0xec, 0x90 }}

class NS_NO_VTABLE nsIAsyncShutdownBarrier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCSHUTDOWNBARRIER_IID)

  /* readonly attribute nsIAsyncShutdownClient client; */
  NS_IMETHOD GetClient(nsIAsyncShutdownClient * *aClient) = 0;

  /* readonly attribute nsIPropertyBag state; */
  NS_IMETHOD GetState(nsIPropertyBag * *aState) = 0;

  /* void wait (in nsIAsyncShutdownCompletionCallback aOnReady); */
  NS_IMETHOD Wait(nsIAsyncShutdownCompletionCallback *aOnReady) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncShutdownBarrier, NS_IASYNCSHUTDOWNBARRIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCSHUTDOWNBARRIER \
  NS_IMETHOD GetClient(nsIAsyncShutdownClient * *aClient) override; \
  NS_IMETHOD GetState(nsIPropertyBag * *aState) override; \
  NS_IMETHOD Wait(nsIAsyncShutdownCompletionCallback *aOnReady) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCSHUTDOWNBARRIER(_to) \
  NS_IMETHOD GetClient(nsIAsyncShutdownClient * *aClient) override { return _to GetClient(aClient); } \
  NS_IMETHOD GetState(nsIPropertyBag * *aState) override { return _to GetState(aState); } \
  NS_IMETHOD Wait(nsIAsyncShutdownCompletionCallback *aOnReady) override { return _to Wait(aOnReady); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCSHUTDOWNBARRIER(_to) \
  NS_IMETHOD GetClient(nsIAsyncShutdownClient * *aClient) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClient(aClient); } \
  NS_IMETHOD GetState(nsIPropertyBag * *aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD Wait(nsIAsyncShutdownCompletionCallback *aOnReady) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Wait(aOnReady); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncShutdownBarrier : public nsIAsyncShutdownBarrier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCSHUTDOWNBARRIER

  nsAsyncShutdownBarrier();

private:
  ~nsAsyncShutdownBarrier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAsyncShutdownBarrier, nsIAsyncShutdownBarrier)

nsAsyncShutdownBarrier::nsAsyncShutdownBarrier()
{
  /* member initializers and constructor code */
}

nsAsyncShutdownBarrier::~nsAsyncShutdownBarrier()
{
  /* destructor code */
}

/* readonly attribute nsIAsyncShutdownClient client; */
NS_IMETHODIMP nsAsyncShutdownBarrier::GetClient(nsIAsyncShutdownClient * *aClient)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPropertyBag state; */
NS_IMETHODIMP nsAsyncShutdownBarrier::GetState(nsIPropertyBag * *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wait (in nsIAsyncShutdownCompletionCallback aOnReady); */
NS_IMETHODIMP nsAsyncShutdownBarrier::Wait(nsIAsyncShutdownCompletionCallback *aOnReady)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAsyncShutdownService */
#define NS_IASYNCSHUTDOWNSERVICE_IID_STR "8a9a0859-0404-4d50-9e76-10a4f56dfb51"

#define NS_IASYNCSHUTDOWNSERVICE_IID \
  {0x8a9a0859, 0x0404, 0x4d50, \
    { 0x9e, 0x76, 0x10, 0xa4, 0xf5, 0x6d, 0xfb, 0x51 }}

class NS_NO_VTABLE nsIAsyncShutdownService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCSHUTDOWNSERVICE_IID)

  /* nsIAsyncShutdownBarrier makeBarrier (in AString aName); */
  NS_IMETHOD MakeBarrier(const nsAString & aName, nsIAsyncShutdownBarrier * *_retval) = 0;

  /* readonly attribute nsIAsyncShutdownClient profileBeforeChange; */
  NS_IMETHOD GetProfileBeforeChange(nsIAsyncShutdownClient * *aProfileBeforeChange) = 0;

  /* readonly attribute nsIAsyncShutdownClient profileChangeTeardown; */
  NS_IMETHOD GetProfileChangeTeardown(nsIAsyncShutdownClient * *aProfileChangeTeardown) = 0;

  /* readonly attribute nsIAsyncShutdownClient sendTelemetry; */
  NS_IMETHOD GetSendTelemetry(nsIAsyncShutdownClient * *aSendTelemetry) = 0;

  /* readonly attribute nsIAsyncShutdownClient webWorkersShutdown; */
  NS_IMETHOD GetWebWorkersShutdown(nsIAsyncShutdownClient * *aWebWorkersShutdown) = 0;

  /* readonly attribute nsIAsyncShutdownClient xpcomThreadsShutdown; */
  NS_IMETHOD GetXpcomThreadsShutdown(nsIAsyncShutdownClient * *aXpcomThreadsShutdown) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncShutdownService, NS_IASYNCSHUTDOWNSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCSHUTDOWNSERVICE \
  NS_IMETHOD MakeBarrier(const nsAString & aName, nsIAsyncShutdownBarrier * *_retval) override; \
  NS_IMETHOD GetProfileBeforeChange(nsIAsyncShutdownClient * *aProfileBeforeChange) override; \
  NS_IMETHOD GetProfileChangeTeardown(nsIAsyncShutdownClient * *aProfileChangeTeardown) override; \
  NS_IMETHOD GetSendTelemetry(nsIAsyncShutdownClient * *aSendTelemetry) override; \
  NS_IMETHOD GetWebWorkersShutdown(nsIAsyncShutdownClient * *aWebWorkersShutdown) override; \
  NS_IMETHOD GetXpcomThreadsShutdown(nsIAsyncShutdownClient * *aXpcomThreadsShutdown) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCSHUTDOWNSERVICE(_to) \
  NS_IMETHOD MakeBarrier(const nsAString & aName, nsIAsyncShutdownBarrier * *_retval) override { return _to MakeBarrier(aName, _retval); } \
  NS_IMETHOD GetProfileBeforeChange(nsIAsyncShutdownClient * *aProfileBeforeChange) override { return _to GetProfileBeforeChange(aProfileBeforeChange); } \
  NS_IMETHOD GetProfileChangeTeardown(nsIAsyncShutdownClient * *aProfileChangeTeardown) override { return _to GetProfileChangeTeardown(aProfileChangeTeardown); } \
  NS_IMETHOD GetSendTelemetry(nsIAsyncShutdownClient * *aSendTelemetry) override { return _to GetSendTelemetry(aSendTelemetry); } \
  NS_IMETHOD GetWebWorkersShutdown(nsIAsyncShutdownClient * *aWebWorkersShutdown) override { return _to GetWebWorkersShutdown(aWebWorkersShutdown); } \
  NS_IMETHOD GetXpcomThreadsShutdown(nsIAsyncShutdownClient * *aXpcomThreadsShutdown) override { return _to GetXpcomThreadsShutdown(aXpcomThreadsShutdown); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCSHUTDOWNSERVICE(_to) \
  NS_IMETHOD MakeBarrier(const nsAString & aName, nsIAsyncShutdownBarrier * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeBarrier(aName, _retval); } \
  NS_IMETHOD GetProfileBeforeChange(nsIAsyncShutdownClient * *aProfileBeforeChange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileBeforeChange(aProfileBeforeChange); } \
  NS_IMETHOD GetProfileChangeTeardown(nsIAsyncShutdownClient * *aProfileChangeTeardown) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileChangeTeardown(aProfileChangeTeardown); } \
  NS_IMETHOD GetSendTelemetry(nsIAsyncShutdownClient * *aSendTelemetry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSendTelemetry(aSendTelemetry); } \
  NS_IMETHOD GetWebWorkersShutdown(nsIAsyncShutdownClient * *aWebWorkersShutdown) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWebWorkersShutdown(aWebWorkersShutdown); } \
  NS_IMETHOD GetXpcomThreadsShutdown(nsIAsyncShutdownClient * *aXpcomThreadsShutdown) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXpcomThreadsShutdown(aXpcomThreadsShutdown); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncShutdownService : public nsIAsyncShutdownService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCSHUTDOWNSERVICE

  nsAsyncShutdownService();

private:
  ~nsAsyncShutdownService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAsyncShutdownService, nsIAsyncShutdownService)

nsAsyncShutdownService::nsAsyncShutdownService()
{
  /* member initializers and constructor code */
}

nsAsyncShutdownService::~nsAsyncShutdownService()
{
  /* destructor code */
}

/* nsIAsyncShutdownBarrier makeBarrier (in AString aName); */
NS_IMETHODIMP nsAsyncShutdownService::MakeBarrier(const nsAString & aName, nsIAsyncShutdownBarrier * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncShutdownClient profileBeforeChange; */
NS_IMETHODIMP nsAsyncShutdownService::GetProfileBeforeChange(nsIAsyncShutdownClient * *aProfileBeforeChange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncShutdownClient profileChangeTeardown; */
NS_IMETHODIMP nsAsyncShutdownService::GetProfileChangeTeardown(nsIAsyncShutdownClient * *aProfileChangeTeardown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncShutdownClient sendTelemetry; */
NS_IMETHODIMP nsAsyncShutdownService::GetSendTelemetry(nsIAsyncShutdownClient * *aSendTelemetry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncShutdownClient webWorkersShutdown; */
NS_IMETHODIMP nsAsyncShutdownService::GetWebWorkersShutdown(nsIAsyncShutdownClient * *aWebWorkersShutdown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncShutdownClient xpcomThreadsShutdown; */
NS_IMETHODIMP nsAsyncShutdownService::GetXpcomThreadsShutdown(nsIAsyncShutdownClient * *aXpcomThreadsShutdown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_ASYNCSHUTDOWNSERVICE_CONTRACTID "@mozilla.org/async-shutdown-service;1"

#endif /* __gen_nsIAsyncShutdown_h__ */
