/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMNavigatorSystemMessages.idl
 */

#ifndef __gen_nsIDOMNavigatorSystemMessages_h__
#define __gen_nsIDOMNavigatorSystemMessages_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSystemMessageCallback */
#define NS_IDOMSYSTEMMESSAGECALLBACK_IID_STR "42692976-57fd-4bb4-ab95-2b97ebdc5056"

#define NS_IDOMSYSTEMMESSAGECALLBACK_IID \
  {0x42692976, 0x57fd, 0x4bb4, \
    { 0xab, 0x95, 0x2b, 0x97, 0xeb, 0xdc, 0x50, 0x56 }}

class NS_NO_VTABLE nsIDOMSystemMessageCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSYSTEMMESSAGECALLBACK_IID)

  /* void handleMessage (in jsval message); */
  NS_IMETHOD HandleMessage(JS::HandleValue message) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSystemMessageCallback, NS_IDOMSYSTEMMESSAGECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSYSTEMMESSAGECALLBACK \
  NS_IMETHOD HandleMessage(JS::HandleValue message) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSYSTEMMESSAGECALLBACK(_to) \
  NS_IMETHOD HandleMessage(JS::HandleValue message) override { return _to HandleMessage(message); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSYSTEMMESSAGECALLBACK(_to) \
  NS_IMETHOD HandleMessage(JS::HandleValue message) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleMessage(message); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSystemMessageCallback : public nsIDOMSystemMessageCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSYSTEMMESSAGECALLBACK

  nsDOMSystemMessageCallback();

private:
  ~nsDOMSystemMessageCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMSystemMessageCallback, nsIDOMSystemMessageCallback)

nsDOMSystemMessageCallback::nsDOMSystemMessageCallback()
{
  /* member initializers and constructor code */
}

nsDOMSystemMessageCallback::~nsDOMSystemMessageCallback()
{
  /* destructor code */
}

/* void handleMessage (in jsval message); */
NS_IMETHODIMP nsDOMSystemMessageCallback::HandleMessage(JS::HandleValue message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMNavigatorSystemMessages */
#define NS_IDOMNAVIGATORSYSTEMMESSAGES_IID_STR "d04d3c11-26aa-46eb-a981-353af101f9cf"

#define NS_IDOMNAVIGATORSYSTEMMESSAGES_IID \
  {0xd04d3c11, 0x26aa, 0x46eb, \
    { 0xa9, 0x81, 0x35, 0x3a, 0xf1, 0x01, 0xf9, 0xcf }}

class NS_NO_VTABLE nsIDOMNavigatorSystemMessages : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNAVIGATORSYSTEMMESSAGES_IID)

  /* void mozSetMessageHandler (in DOMString type, in nsIDOMSystemMessageCallback callback); */
  NS_IMETHOD MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback) = 0;

  /* boolean mozHasPendingMessage (in DOMString type); */
  NS_IMETHOD MozHasPendingMessage(const nsAString & type, bool *_retval) = 0;

  /* void mozSetMessageHandlerPromise (in nsISupports promise); */
  NS_IMETHOD MozSetMessageHandlerPromise(nsISupports *promise) = 0;

  /* bool mozIsHandlingMessage (); */
  NS_IMETHOD MozIsHandlingMessage(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNavigatorSystemMessages, NS_IDOMNAVIGATORSYSTEMMESSAGES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNAVIGATORSYSTEMMESSAGES \
  NS_IMETHOD MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback) override; \
  NS_IMETHOD MozHasPendingMessage(const nsAString & type, bool *_retval) override; \
  NS_IMETHOD MozSetMessageHandlerPromise(nsISupports *promise) override; \
  NS_IMETHOD MozIsHandlingMessage(bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNAVIGATORSYSTEMMESSAGES(_to) \
  NS_IMETHOD MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback) override { return _to MozSetMessageHandler(type, callback); } \
  NS_IMETHOD MozHasPendingMessage(const nsAString & type, bool *_retval) override { return _to MozHasPendingMessage(type, _retval); } \
  NS_IMETHOD MozSetMessageHandlerPromise(nsISupports *promise) override { return _to MozSetMessageHandlerPromise(promise); } \
  NS_IMETHOD MozIsHandlingMessage(bool *_retval) override { return _to MozIsHandlingMessage(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNAVIGATORSYSTEMMESSAGES(_to) \
  NS_IMETHOD MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozSetMessageHandler(type, callback); } \
  NS_IMETHOD MozHasPendingMessage(const nsAString & type, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozHasPendingMessage(type, _retval); } \
  NS_IMETHOD MozSetMessageHandlerPromise(nsISupports *promise) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozSetMessageHandlerPromise(promise); } \
  NS_IMETHOD MozIsHandlingMessage(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozIsHandlingMessage(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNavigatorSystemMessages : public nsIDOMNavigatorSystemMessages
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNAVIGATORSYSTEMMESSAGES

  nsDOMNavigatorSystemMessages();

private:
  ~nsDOMNavigatorSystemMessages();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMNavigatorSystemMessages, nsIDOMNavigatorSystemMessages)

nsDOMNavigatorSystemMessages::nsDOMNavigatorSystemMessages()
{
  /* member initializers and constructor code */
}

nsDOMNavigatorSystemMessages::~nsDOMNavigatorSystemMessages()
{
  /* destructor code */
}

/* void mozSetMessageHandler (in DOMString type, in nsIDOMSystemMessageCallback callback); */
NS_IMETHODIMP nsDOMNavigatorSystemMessages::MozSetMessageHandler(const nsAString & type, nsIDOMSystemMessageCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean mozHasPendingMessage (in DOMString type); */
NS_IMETHODIMP nsDOMNavigatorSystemMessages::MozHasPendingMessage(const nsAString & type, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozSetMessageHandlerPromise (in nsISupports promise); */
NS_IMETHODIMP nsDOMNavigatorSystemMessages::MozSetMessageHandlerPromise(nsISupports *promise)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool mozIsHandlingMessage (); */
NS_IMETHODIMP nsDOMNavigatorSystemMessages::MozIsHandlingMessage(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorSystemMessages_h__ */
