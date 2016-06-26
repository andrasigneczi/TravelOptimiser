/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISettingsService.idl
 */

#ifndef __gen_nsISettingsService_h__
#define __gen_nsISettingsService_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISettingsServiceCallback */
#define NS_ISETTINGSSERVICECALLBACK_IID_STR "aad47850-2e87-11e2-81c1-0800200c9a66"

#define NS_ISETTINGSSERVICECALLBACK_IID \
  {0xaad47850, 0x2e87, 0x11e2, \
    { 0x81, 0xc1, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsISettingsServiceCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISETTINGSSERVICECALLBACK_IID)

  /* void handle (in DOMString aName, in jsval aResult); */
  NS_IMETHOD Handle(const nsAString & aName, JS::HandleValue aResult) = 0;

  /* void handleError (in DOMString aErrorMessage); */
  NS_IMETHOD HandleError(const nsAString & aErrorMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISettingsServiceCallback, NS_ISETTINGSSERVICECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISETTINGSSERVICECALLBACK \
  NS_IMETHOD Handle(const nsAString & aName, JS::HandleValue aResult) override; \
  NS_IMETHOD HandleError(const nsAString & aErrorMessage) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISETTINGSSERVICECALLBACK(_to) \
  NS_IMETHOD Handle(const nsAString & aName, JS::HandleValue aResult) override { return _to Handle(aName, aResult); } \
  NS_IMETHOD HandleError(const nsAString & aErrorMessage) override { return _to HandleError(aErrorMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISETTINGSSERVICECALLBACK(_to) \
  NS_IMETHOD Handle(const nsAString & aName, JS::HandleValue aResult) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Handle(aName, aResult); } \
  NS_IMETHOD HandleError(const nsAString & aErrorMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleError(aErrorMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSettingsServiceCallback : public nsISettingsServiceCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISETTINGSSERVICECALLBACK

  nsSettingsServiceCallback();

private:
  ~nsSettingsServiceCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSettingsServiceCallback, nsISettingsServiceCallback)

nsSettingsServiceCallback::nsSettingsServiceCallback()
{
  /* member initializers and constructor code */
}

nsSettingsServiceCallback::~nsSettingsServiceCallback()
{
  /* destructor code */
}

/* void handle (in DOMString aName, in jsval aResult); */
NS_IMETHODIMP nsSettingsServiceCallback::Handle(const nsAString & aName, JS::HandleValue aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleError (in DOMString aErrorMessage); */
NS_IMETHODIMP nsSettingsServiceCallback::HandleError(const nsAString & aErrorMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISettingsTransactionCompleteCallback */
#define NS_ISETTINGSTRANSACTIONCOMPLETECALLBACK_IID_STR "f1b3d820-8e75-11e3-baa8-0800200c9a66"

#define NS_ISETTINGSTRANSACTIONCOMPLETECALLBACK_IID \
  {0xf1b3d820, 0x8e75, 0x11e3, \
    { 0xba, 0xa8, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsISettingsTransactionCompleteCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISETTINGSTRANSACTIONCOMPLETECALLBACK_IID)

  /* void handle (); */
  NS_IMETHOD Handle(void) = 0;

  /* void handleAbort (in DOMString aErrorMessage); */
  NS_IMETHOD HandleAbort(const nsAString & aErrorMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISettingsTransactionCompleteCallback, NS_ISETTINGSTRANSACTIONCOMPLETECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISETTINGSTRANSACTIONCOMPLETECALLBACK \
  NS_IMETHOD Handle(void) override; \
  NS_IMETHOD HandleAbort(const nsAString & aErrorMessage) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISETTINGSTRANSACTIONCOMPLETECALLBACK(_to) \
  NS_IMETHOD Handle(void) override { return _to Handle(); } \
  NS_IMETHOD HandleAbort(const nsAString & aErrorMessage) override { return _to HandleAbort(aErrorMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISETTINGSTRANSACTIONCOMPLETECALLBACK(_to) \
  NS_IMETHOD Handle(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Handle(); } \
  NS_IMETHOD HandleAbort(const nsAString & aErrorMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleAbort(aErrorMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSettingsTransactionCompleteCallback : public nsISettingsTransactionCompleteCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISETTINGSTRANSACTIONCOMPLETECALLBACK

  nsSettingsTransactionCompleteCallback();

private:
  ~nsSettingsTransactionCompleteCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSettingsTransactionCompleteCallback, nsISettingsTransactionCompleteCallback)

nsSettingsTransactionCompleteCallback::nsSettingsTransactionCompleteCallback()
{
  /* member initializers and constructor code */
}

nsSettingsTransactionCompleteCallback::~nsSettingsTransactionCompleteCallback()
{
  /* destructor code */
}

/* void handle (); */
NS_IMETHODIMP nsSettingsTransactionCompleteCallback::Handle()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleAbort (in DOMString aErrorMessage); */
NS_IMETHODIMP nsSettingsTransactionCompleteCallback::HandleAbort(const nsAString & aErrorMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISettingsServiceLock */
#define NS_ISETTINGSSERVICELOCK_IID_STR "d7a395a0-e292-11e1-834e-1761d57f5f99"

#define NS_ISETTINGSSERVICELOCK_IID \
  {0xd7a395a0, 0xe292, 0x11e1, \
    { 0x83, 0x4e, 0x17, 0x61, 0xd5, 0x7f, 0x5f, 0x99 }}

class NS_NO_VTABLE nsISettingsServiceLock : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISETTINGSSERVICELOCK_IID)

  /* void set (in string aName, in jsval aValue, in nsISettingsServiceCallback aCallback, [optional] in string aMessage); */
  NS_IMETHOD Set(const char * aName, JS::HandleValue aValue, nsISettingsServiceCallback *aCallback, const char * aMessage) = 0;

  /* void get (in string aName, in nsISettingsServiceCallback aCallback); */
  NS_IMETHOD Get(const char * aName, nsISettingsServiceCallback *aCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISettingsServiceLock, NS_ISETTINGSSERVICELOCK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISETTINGSSERVICELOCK \
  NS_IMETHOD Set(const char * aName, JS::HandleValue aValue, nsISettingsServiceCallback *aCallback, const char * aMessage) override; \
  NS_IMETHOD Get(const char * aName, nsISettingsServiceCallback *aCallback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISETTINGSSERVICELOCK(_to) \
  NS_IMETHOD Set(const char * aName, JS::HandleValue aValue, nsISettingsServiceCallback *aCallback, const char * aMessage) override { return _to Set(aName, aValue, aCallback, aMessage); } \
  NS_IMETHOD Get(const char * aName, nsISettingsServiceCallback *aCallback) override { return _to Get(aName, aCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISETTINGSSERVICELOCK(_to) \
  NS_IMETHOD Set(const char * aName, JS::HandleValue aValue, nsISettingsServiceCallback *aCallback, const char * aMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(aName, aValue, aCallback, aMessage); } \
  NS_IMETHOD Get(const char * aName, nsISettingsServiceCallback *aCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, aCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSettingsServiceLock : public nsISettingsServiceLock
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISETTINGSSERVICELOCK

  nsSettingsServiceLock();

private:
  ~nsSettingsServiceLock();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSettingsServiceLock, nsISettingsServiceLock)

nsSettingsServiceLock::nsSettingsServiceLock()
{
  /* member initializers and constructor code */
}

nsSettingsServiceLock::~nsSettingsServiceLock()
{
  /* destructor code */
}

/* void set (in string aName, in jsval aValue, in nsISettingsServiceCallback aCallback, [optional] in string aMessage); */
NS_IMETHODIMP nsSettingsServiceLock::Set(const char * aName, JS::HandleValue aValue, nsISettingsServiceCallback *aCallback, const char * aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void get (in string aName, in nsISettingsServiceCallback aCallback); */
NS_IMETHODIMP nsSettingsServiceLock::Get(const char * aName, nsISettingsServiceCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISettingsService */
#define NS_ISETTINGSSERVICE_IID_STR "d1ed155c-9f90-47bb-91c2-7eac54d69f4b"

#define NS_ISETTINGSSERVICE_IID \
  {0xd1ed155c, 0x9f90, 0x47bb, \
    { 0x91, 0xc2, 0x7e, 0xac, 0x54, 0xd6, 0x9f, 0x4b }}

class NS_NO_VTABLE nsISettingsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISETTINGSSERVICE_IID)

  /* nsISettingsServiceLock createLock ([optional] in nsISettingsTransactionCompleteCallback aCallback); */
  NS_IMETHOD CreateLock(nsISettingsTransactionCompleteCallback *aCallback, nsISettingsServiceLock * *_retval) = 0;

  /* void receiveMessage (in jsval aMessage); */
  NS_IMETHOD ReceiveMessage(JS::HandleValue aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISettingsService, NS_ISETTINGSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISETTINGSSERVICE \
  NS_IMETHOD CreateLock(nsISettingsTransactionCompleteCallback *aCallback, nsISettingsServiceLock * *_retval) override; \
  NS_IMETHOD ReceiveMessage(JS::HandleValue aMessage) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISETTINGSSERVICE(_to) \
  NS_IMETHOD CreateLock(nsISettingsTransactionCompleteCallback *aCallback, nsISettingsServiceLock * *_retval) override { return _to CreateLock(aCallback, _retval); } \
  NS_IMETHOD ReceiveMessage(JS::HandleValue aMessage) override { return _to ReceiveMessage(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISETTINGSSERVICE(_to) \
  NS_IMETHOD CreateLock(nsISettingsTransactionCompleteCallback *aCallback, nsISettingsServiceLock * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateLock(aCallback, _retval); } \
  NS_IMETHOD ReceiveMessage(JS::HandleValue aMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReceiveMessage(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSettingsService : public nsISettingsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISETTINGSSERVICE

  nsSettingsService();

private:
  ~nsSettingsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSettingsService, nsISettingsService)

nsSettingsService::nsSettingsService()
{
  /* member initializers and constructor code */
}

nsSettingsService::~nsSettingsService()
{
  /* destructor code */
}

/* nsISettingsServiceLock createLock ([optional] in nsISettingsTransactionCompleteCallback aCallback); */
NS_IMETHODIMP nsSettingsService::CreateLock(nsISettingsTransactionCompleteCallback *aCallback, nsISettingsServiceLock * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void receiveMessage (in jsval aMessage); */
NS_IMETHODIMP nsSettingsService::ReceiveMessage(JS::HandleValue aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISettingsService_h__ */
