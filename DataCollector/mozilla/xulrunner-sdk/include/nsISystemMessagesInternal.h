/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISystemMessagesInternal.idl
 */

#ifndef __gen_nsISystemMessagesInternal_h__
#define __gen_nsISystemMessagesInternal_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIMessageSender; /* forward declaration */


/* starting interface:    nsISystemMessagesInternal */
#define NS_ISYSTEMMESSAGESINTERNAL_IID_STR "54c8e274-decb-4258-9a24-4ebfcbf3d00a"

#define NS_ISYSTEMMESSAGESINTERNAL_IID \
  {0x54c8e274, 0xdecb, 0x4258, \
    { 0x9a, 0x24, 0x4e, 0xbf, 0xcb, 0xf3, 0xd0, 0x0a }}

class NS_NO_VTABLE nsISystemMessagesInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMMESSAGESINTERNAL_IID)

  /* nsISupports sendMessage (in DOMString type, in jsval message, in nsIURI pageURI, in nsIURI manifestURI, [optional] in jsval extra); */
  NS_IMETHOD SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra, nsISupports * *_retval) = 0;

  /* void broadcastMessage (in DOMString type, in jsval message, [optional] in jsval extra); */
  NS_IMETHOD BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra) = 0;

  /* void registerPage (in DOMString type, in nsIURI pageURI, in nsIURI manifestURI); */
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI) = 0;

  /* void refreshCache (in nsIMessageSender childMM, in nsIURI manifestURI); */
  NS_IMETHOD RefreshCache(nsIMessageSender *childMM, nsIURI *manifestURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessagesInternal, NS_ISYSTEMMESSAGESINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGESINTERNAL \
  NS_IMETHOD SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra, nsISupports * *_retval) override; \
  NS_IMETHOD BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra) override; \
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI) override; \
  NS_IMETHOD RefreshCache(nsIMessageSender *childMM, nsIURI *manifestURI) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGESINTERNAL(_to) \
  NS_IMETHOD SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra, nsISupports * *_retval) override { return _to SendMessage(type, message, pageURI, manifestURI, extra, _retval); } \
  NS_IMETHOD BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra) override { return _to BroadcastMessage(type, message, extra); } \
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI) override { return _to RegisterPage(type, pageURI, manifestURI); } \
  NS_IMETHOD RefreshCache(nsIMessageSender *childMM, nsIURI *manifestURI) override { return _to RefreshCache(childMM, manifestURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGESINTERNAL(_to) \
  NS_IMETHOD SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMessage(type, message, pageURI, manifestURI, extra, _retval); } \
  NS_IMETHOD BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BroadcastMessage(type, message, extra); } \
  NS_IMETHOD RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterPage(type, pageURI, manifestURI); } \
  NS_IMETHOD RefreshCache(nsIMessageSender *childMM, nsIURI *manifestURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshCache(childMM, manifestURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemMessagesInternal : public nsISystemMessagesInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMMESSAGESINTERNAL

  nsSystemMessagesInternal();

private:
  ~nsSystemMessagesInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSystemMessagesInternal, nsISystemMessagesInternal)

nsSystemMessagesInternal::nsSystemMessagesInternal()
{
  /* member initializers and constructor code */
}

nsSystemMessagesInternal::~nsSystemMessagesInternal()
{
  /* destructor code */
}

/* nsISupports sendMessage (in DOMString type, in jsval message, in nsIURI pageURI, in nsIURI manifestURI, [optional] in jsval extra); */
NS_IMETHODIMP nsSystemMessagesInternal::SendMessage(const nsAString & type, JS::HandleValue message, nsIURI *pageURI, nsIURI *manifestURI, JS::HandleValue extra, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void broadcastMessage (in DOMString type, in jsval message, [optional] in jsval extra); */
NS_IMETHODIMP nsSystemMessagesInternal::BroadcastMessage(const nsAString & type, JS::HandleValue message, JS::HandleValue extra)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerPage (in DOMString type, in nsIURI pageURI, in nsIURI manifestURI); */
NS_IMETHODIMP nsSystemMessagesInternal::RegisterPage(const nsAString & type, nsIURI *pageURI, nsIURI *manifestURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refreshCache (in nsIMessageSender childMM, in nsIURI manifestURI); */
NS_IMETHODIMP nsSystemMessagesInternal::RefreshCache(nsIMessageSender *childMM, nsIURI *manifestURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISystemMessagesWrapper */
#define NS_ISYSTEMMESSAGESWRAPPER_IID_STR "002f0e82-91f0-41de-ad43-569a2b9d12df"

#define NS_ISYSTEMMESSAGESWRAPPER_IID \
  {0x002f0e82, 0x91f0, 0x41de, \
    { 0xad, 0x43, 0x56, 0x9a, 0x2b, 0x9d, 0x12, 0xdf }}

class NS_NO_VTABLE nsISystemMessagesWrapper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMMESSAGESWRAPPER_IID)

  /* jsval wrapMessage (in jsval message, in nsIDOMWindow window); */
  NS_IMETHOD WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessagesWrapper, NS_ISYSTEMMESSAGESWRAPPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGESWRAPPER \
  NS_IMETHOD WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGESWRAPPER(_to) \
  NS_IMETHOD WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval) override { return _to WrapMessage(message, window, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGESWRAPPER(_to) \
  NS_IMETHOD WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapMessage(message, window, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemMessagesWrapper : public nsISystemMessagesWrapper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMMESSAGESWRAPPER

  nsSystemMessagesWrapper();

private:
  ~nsSystemMessagesWrapper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSystemMessagesWrapper, nsISystemMessagesWrapper)

nsSystemMessagesWrapper::nsSystemMessagesWrapper()
{
  /* member initializers and constructor code */
}

nsSystemMessagesWrapper::~nsSystemMessagesWrapper()
{
  /* destructor code */
}

/* jsval wrapMessage (in jsval message, in nsIDOMWindow window); */
NS_IMETHODIMP nsSystemMessagesWrapper::WrapMessage(JS::HandleValue message, nsIDOMWindow *window, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISystemMessagesConfigurator */
#define NS_ISYSTEMMESSAGESCONFIGURATOR_IID_STR "31b78730-21c6-11e4-8c21-0800200c9a66"

#define NS_ISYSTEMMESSAGESCONFIGURATOR_IID \
  {0x31b78730, 0x21c6, 0x11e4, \
    { 0x8c, 0x21, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsISystemMessagesConfigurator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMMESSAGESCONFIGURATOR_IID)

  /* readonly attribute boolean mustShowRunningApp; */
  NS_IMETHOD GetMustShowRunningApp(bool *aMustShowRunningApp) = 0;

  /* jsval shouldDispatch (in DOMString manifestURL, in DOMString pageURL, in DOMString type, in jsval message, [optional] in jsval extra); */
  NS_IMETHOD ShouldDispatch(const nsAString & manifestURL, const nsAString & pageURL, const nsAString & type, JS::HandleValue message, JS::HandleValue extra, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessagesConfigurator, NS_ISYSTEMMESSAGESCONFIGURATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGESCONFIGURATOR \
  NS_IMETHOD GetMustShowRunningApp(bool *aMustShowRunningApp) override; \
  NS_IMETHOD ShouldDispatch(const nsAString & manifestURL, const nsAString & pageURL, const nsAString & type, JS::HandleValue message, JS::HandleValue extra, JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGESCONFIGURATOR(_to) \
  NS_IMETHOD GetMustShowRunningApp(bool *aMustShowRunningApp) override { return _to GetMustShowRunningApp(aMustShowRunningApp); } \
  NS_IMETHOD ShouldDispatch(const nsAString & manifestURL, const nsAString & pageURL, const nsAString & type, JS::HandleValue message, JS::HandleValue extra, JS::MutableHandleValue _retval) override { return _to ShouldDispatch(manifestURL, pageURL, type, message, extra, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGESCONFIGURATOR(_to) \
  NS_IMETHOD GetMustShowRunningApp(bool *aMustShowRunningApp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMustShowRunningApp(aMustShowRunningApp); } \
  NS_IMETHOD ShouldDispatch(const nsAString & manifestURL, const nsAString & pageURL, const nsAString & type, JS::HandleValue message, JS::HandleValue extra, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldDispatch(manifestURL, pageURL, type, message, extra, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemMessagesConfigurator : public nsISystemMessagesConfigurator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMMESSAGESCONFIGURATOR

  nsSystemMessagesConfigurator();

private:
  ~nsSystemMessagesConfigurator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSystemMessagesConfigurator, nsISystemMessagesConfigurator)

nsSystemMessagesConfigurator::nsSystemMessagesConfigurator()
{
  /* member initializers and constructor code */
}

nsSystemMessagesConfigurator::~nsSystemMessagesConfigurator()
{
  /* destructor code */
}

/* readonly attribute boolean mustShowRunningApp; */
NS_IMETHODIMP nsSystemMessagesConfigurator::GetMustShowRunningApp(bool *aMustShowRunningApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval shouldDispatch (in DOMString manifestURL, in DOMString pageURL, in DOMString type, in jsval message, [optional] in jsval extra); */
NS_IMETHODIMP nsSystemMessagesConfigurator::ShouldDispatch(const nsAString & manifestURL, const nsAString & pageURL, const nsAString & type, JS::HandleValue message, JS::HandleValue extra, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISystemMessagesInternal_h__ */
