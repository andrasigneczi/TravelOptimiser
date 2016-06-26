/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMessageManager.idl
 */

#ifndef __gen_nsIMessageManager_h__
#define __gen_nsIMessageManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIContent; /* forward declaration */

class nsIFrameLoader; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIMessageListener */
#define NS_IMESSAGELISTENER_IID_STR "2b44eb57-a9c6-4773-9a1e-fe0818739a4c"

#define NS_IMESSAGELISTENER_IID \
  {0x2b44eb57, 0xa9c6, 0x4773, \
    { 0x9a, 0x1e, 0xfe, 0x08, 0x18, 0x73, 0x9a, 0x4c }}

class NS_NO_VTABLE nsIMessageListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGELISTENER_IID)

  /* void receiveMessage (); */
  NS_IMETHOD ReceiveMessage(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageListener, NS_IMESSAGELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGELISTENER \
  NS_IMETHOD ReceiveMessage(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGELISTENER(_to) \
  NS_IMETHOD ReceiveMessage(void) override { return _to ReceiveMessage(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGELISTENER(_to) \
  NS_IMETHOD ReceiveMessage(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReceiveMessage(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageListener : public nsIMessageListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGELISTENER

  nsMessageListener();

private:
  ~nsMessageListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMessageListener, nsIMessageListener)

nsMessageListener::nsMessageListener()
{
  /* member initializers and constructor code */
}

nsMessageListener::~nsMessageListener()
{
  /* destructor code */
}

/* void receiveMessage (); */
NS_IMETHODIMP nsMessageListener::ReceiveMessage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMessageListenerManager */
#define NS_IMESSAGELISTENERMANAGER_IID_STR "b949bfec-bb7d-47bc-b387-ac6a9b655072"

#define NS_IMESSAGELISTENERMANAGER_IID \
  {0xb949bfec, 0xbb7d, 0x47bc, \
    { 0xb3, 0x87, 0xac, 0x6a, 0x9b, 0x65, 0x50, 0x72 }}

class NS_NO_VTABLE nsIMessageListenerManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGELISTENERMANAGER_IID)

  /* void addMessageListener (in AString messageName, in nsIMessageListener listener, [optional] in boolean listenWhenClosed); */
  NS_IMETHOD AddMessageListener(const nsAString & messageName, nsIMessageListener *listener, bool listenWhenClosed) = 0;

  /* void removeMessageListener (in AString messageName, in nsIMessageListener listener); */
  NS_IMETHOD RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener) = 0;

  /* void addWeakMessageListener (in AString messageName, in nsIMessageListener listener); */
  NS_IMETHOD AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) = 0;

  /* void removeWeakMessageListener (in AString messageName, in nsIMessageListener listener); */
  NS_IMETHOD RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) = 0;

  /* [notxpcom] boolean markForCC (); */
  NS_IMETHOD_(bool) MarkForCC(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageListenerManager, NS_IMESSAGELISTENERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGELISTENERMANAGER \
  NS_IMETHOD AddMessageListener(const nsAString & messageName, nsIMessageListener *listener, bool listenWhenClosed) override; \
  NS_IMETHOD RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener) override; \
  NS_IMETHOD AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) override; \
  NS_IMETHOD RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) override; \
  NS_IMETHOD_(bool) MarkForCC(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGELISTENERMANAGER(_to) \
  NS_IMETHOD AddMessageListener(const nsAString & messageName, nsIMessageListener *listener, bool listenWhenClosed) override { return _to AddMessageListener(messageName, listener, listenWhenClosed); } \
  NS_IMETHOD RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener) override { return _to RemoveMessageListener(messageName, listener); } \
  NS_IMETHOD AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) override { return _to AddWeakMessageListener(messageName, listener); } \
  NS_IMETHOD RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) override { return _to RemoveWeakMessageListener(messageName, listener); } \
  NS_IMETHOD_(bool) MarkForCC(void) override { return _to MarkForCC(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGELISTENERMANAGER(_to) \
  NS_IMETHOD AddMessageListener(const nsAString & messageName, nsIMessageListener *listener, bool listenWhenClosed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddMessageListener(messageName, listener, listenWhenClosed); } \
  NS_IMETHOD RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveMessageListener(messageName, listener); } \
  NS_IMETHOD AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWeakMessageListener(messageName, listener); } \
  NS_IMETHOD RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWeakMessageListener(messageName, listener); } \
  NS_IMETHOD_(bool) MarkForCC(void) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageListenerManager : public nsIMessageListenerManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGELISTENERMANAGER

  nsMessageListenerManager();

private:
  ~nsMessageListenerManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMessageListenerManager, nsIMessageListenerManager)

nsMessageListenerManager::nsMessageListenerManager()
{
  /* member initializers and constructor code */
}

nsMessageListenerManager::~nsMessageListenerManager()
{
  /* destructor code */
}

/* void addMessageListener (in AString messageName, in nsIMessageListener listener, [optional] in boolean listenWhenClosed); */
NS_IMETHODIMP nsMessageListenerManager::AddMessageListener(const nsAString & messageName, nsIMessageListener *listener, bool listenWhenClosed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeMessageListener (in AString messageName, in nsIMessageListener listener); */
NS_IMETHODIMP nsMessageListenerManager::RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addWeakMessageListener (in AString messageName, in nsIMessageListener listener); */
NS_IMETHODIMP nsMessageListenerManager::AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWeakMessageListener (in AString messageName, in nsIMessageListener listener); */
NS_IMETHODIMP nsMessageListenerManager::RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean markForCC (); */
NS_IMETHODIMP_(bool) nsMessageListenerManager::MarkForCC()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMessageSender */
#define NS_IMESSAGESENDER_IID_STR "bb5d79e4-e73c-45e7-9651-4d718f4b994c"

#define NS_IMESSAGESENDER_IID \
  {0xbb5d79e4, 0xe73c, 0x45e7, \
    { 0x96, 0x51, 0x4d, 0x71, 0x8f, 0x4b, 0x99, 0x4c }}

class NS_NO_VTABLE nsIMessageSender : public nsIMessageListenerManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGESENDER_IID)

  /* [implicit_jscontext,optional_argc] void sendAsyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
  NS_IMETHOD SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageSender, NS_IMESSAGESENDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGESENDER \
  NS_IMETHOD SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGESENDER(_to) \
  NS_IMETHOD SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc) override { return _to SendAsyncMessage(messageName, obj, objects, principal, cx, _argc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGESENDER(_to) \
  NS_IMETHOD SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendAsyncMessage(messageName, obj, objects, principal, cx, _argc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageSender : public nsIMessageSender
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGESENDER

  nsMessageSender();

private:
  ~nsMessageSender();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMessageSender, nsIMessageSender)

nsMessageSender::nsMessageSender()
{
  /* member initializers and constructor code */
}

nsMessageSender::~nsMessageSender()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] void sendAsyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
NS_IMETHODIMP nsMessageSender::SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMessageBroadcaster */
#define NS_IMESSAGEBROADCASTER_IID_STR "4d7d62ad-4725-4f39-86cf-8fb22bf9c1d8"

#define NS_IMESSAGEBROADCASTER_IID \
  {0x4d7d62ad, 0x4725, 0x4f39, \
    { 0x86, 0xcf, 0x8f, 0xb2, 0x2b, 0xf9, 0xc1, 0xd8 }}

class NS_NO_VTABLE nsIMessageBroadcaster : public nsIMessageListenerManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGEBROADCASTER_IID)

  /* [implicit_jscontext,optional_argc] void broadcastAsyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects); */
  NS_IMETHOD BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc) = 0;

  /* readonly attribute unsigned long childCount; */
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) = 0;

  /* nsIMessageListenerManager getChildAt (in unsigned long aIndex); */
  NS_IMETHOD GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageBroadcaster, NS_IMESSAGEBROADCASTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGEBROADCASTER \
  NS_IMETHOD BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc) override; \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) override; \
  NS_IMETHOD GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGEBROADCASTER(_to) \
  NS_IMETHOD BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc) override { return _to BroadcastAsyncMessage(messageName, obj, objects, cx, _argc); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) override { return _to GetChildCount(aChildCount); } \
  NS_IMETHOD GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval) override { return _to GetChildAt(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGEBROADCASTER(_to) \
  NS_IMETHOD BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BroadcastAsyncMessage(messageName, obj, objects, cx, _argc); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_IMETHOD GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAt(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageBroadcaster : public nsIMessageBroadcaster
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGEBROADCASTER

  nsMessageBroadcaster();

private:
  ~nsMessageBroadcaster();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMessageBroadcaster, nsIMessageBroadcaster)

nsMessageBroadcaster::nsMessageBroadcaster()
{
  /* member initializers and constructor code */
}

nsMessageBroadcaster::~nsMessageBroadcaster()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] void broadcastAsyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects); */
NS_IMETHODIMP nsMessageBroadcaster::BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childCount; */
NS_IMETHODIMP nsMessageBroadcaster::GetChildCount(uint32_t *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMessageListenerManager getChildAt (in unsigned long aIndex); */
NS_IMETHODIMP nsMessageBroadcaster::GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISyncMessageSender */
#define NS_ISYNCMESSAGESENDER_IID_STR "0e602c9e-1977-422a-a8e4-fe0d4a4f78d0"

#define NS_ISYNCMESSAGESENDER_IID \
  {0x0e602c9e, 0x1977, 0x422a, \
    { 0xa8, 0xe4, 0xfe, 0x0d, 0x4a, 0x4f, 0x78, 0xd0 }}

class NS_NO_VTABLE nsISyncMessageSender : public nsIMessageSender {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYNCMESSAGESENDER_IID)

  /* [implicit_jscontext,optional_argc] jsval sendSyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
  NS_IMETHOD SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext,optional_argc] jsval sendRpcMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
  NS_IMETHOD SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISyncMessageSender, NS_ISYNCMESSAGESENDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYNCMESSAGESENDER \
  NS_IMETHOD SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYNCMESSAGESENDER(_to) \
  NS_IMETHOD SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return _to SendSyncMessage(messageName, obj, objects, principal, cx, _argc, _retval); } \
  NS_IMETHOD SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return _to SendRpcMessage(messageName, obj, objects, principal, cx, _argc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYNCMESSAGESENDER(_to) \
  NS_IMETHOD SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSyncMessage(messageName, obj, objects, principal, cx, _argc, _retval); } \
  NS_IMETHOD SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendRpcMessage(messageName, obj, objects, principal, cx, _argc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSyncMessageSender : public nsISyncMessageSender
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYNCMESSAGESENDER

  nsSyncMessageSender();

private:
  ~nsSyncMessageSender();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSyncMessageSender, nsISyncMessageSender)

nsSyncMessageSender::nsSyncMessageSender()
{
  /* member initializers and constructor code */
}

nsSyncMessageSender::~nsSyncMessageSender()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] jsval sendSyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
NS_IMETHODIMP nsSyncMessageSender::SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] jsval sendRpcMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
NS_IMETHODIMP nsSyncMessageSender::SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMessageManagerGlobal */
#define NS_IMESSAGEMANAGERGLOBAL_IID_STR "13f3555f-769e-44ea-b607-5239230c3162"

#define NS_IMESSAGEMANAGERGLOBAL_IID \
  {0x13f3555f, 0x769e, 0x44ea, \
    { 0xb6, 0x07, 0x52, 0x39, 0x23, 0x0c, 0x31, 0x62 }}

class NS_NO_VTABLE nsIMessageManagerGlobal : public nsISyncMessageSender {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGEMANAGERGLOBAL_IID)

  /* void dump (in DOMString aStr); */
  NS_IMETHOD Dump(const nsAString & aStr) = 0;

  /* void privateNoteIntentionalCrash (); */
  NS_IMETHOD PrivateNoteIntentionalCrash(void) = 0;

  /* DOMString atob (in DOMString aAsciiString); */
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) = 0;

  /* DOMString btoa (in DOMString aBase64Data); */
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageManagerGlobal, NS_IMESSAGEMANAGERGLOBAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGEMANAGERGLOBAL \
  NS_IMETHOD Dump(const nsAString & aStr) override; \
  NS_IMETHOD PrivateNoteIntentionalCrash(void) override; \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) override; \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGEMANAGERGLOBAL(_to) \
  NS_IMETHOD Dump(const nsAString & aStr) override { return _to Dump(aStr); } \
  NS_IMETHOD PrivateNoteIntentionalCrash(void) override { return _to PrivateNoteIntentionalCrash(); } \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) override { return _to Atob(aAsciiString, _retval); } \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) override { return _to Btoa(aBase64Data, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGEMANAGERGLOBAL(_to) \
  NS_IMETHOD Dump(const nsAString & aStr) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Dump(aStr); } \
  NS_IMETHOD PrivateNoteIntentionalCrash(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PrivateNoteIntentionalCrash(); } \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Atob(aAsciiString, _retval); } \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Btoa(aBase64Data, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageManagerGlobal : public nsIMessageManagerGlobal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGEMANAGERGLOBAL

  nsMessageManagerGlobal();

private:
  ~nsMessageManagerGlobal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMessageManagerGlobal, nsIMessageManagerGlobal)

nsMessageManagerGlobal::nsMessageManagerGlobal()
{
  /* member initializers and constructor code */
}

nsMessageManagerGlobal::~nsMessageManagerGlobal()
{
  /* destructor code */
}

/* void dump (in DOMString aStr); */
NS_IMETHODIMP nsMessageManagerGlobal::Dump(const nsAString & aStr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void privateNoteIntentionalCrash (); */
NS_IMETHODIMP nsMessageManagerGlobal::PrivateNoteIntentionalCrash()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString atob (in DOMString aAsciiString); */
NS_IMETHODIMP nsMessageManagerGlobal::Atob(const nsAString & aAsciiString, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString btoa (in DOMString aBase64Data); */
NS_IMETHODIMP nsMessageManagerGlobal::Btoa(const nsAString & aBase64Data, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentFrameMessageManager */
#define NS_ICONTENTFRAMEMESSAGEMANAGER_IID_STR "fff36099-9f84-4c7c-b69a-1cbf103d1708"

#define NS_ICONTENTFRAMEMESSAGEMANAGER_IID \
  {0xfff36099, 0x9f84, 0x4c7c, \
    { 0xb6, 0x9a, 0x1c, 0xbf, 0x10, 0x3d, 0x17, 0x08 }}

class NS_NO_VTABLE nsIContentFrameMessageManager : public nsIMessageManagerGlobal {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTFRAMEMESSAGEMANAGER_IID)

  /* readonly attribute nsIDOMWindow content; */
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) = 0;

  /* readonly attribute nsIDocShell docShell; */
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentFrameMessageManager, NS_ICONTENTFRAMEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTFRAMEMESSAGEMANAGER \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) override; \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) override { return _to GetContent(aContent); } \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) override { return _to GetDocShell(aDocShell); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContent(aContent); } \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShell(aDocShell); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentFrameMessageManager : public nsIContentFrameMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTFRAMEMESSAGEMANAGER

  nsContentFrameMessageManager();

private:
  ~nsContentFrameMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentFrameMessageManager, nsIContentFrameMessageManager)

nsContentFrameMessageManager::nsContentFrameMessageManager()
{
  /* member initializers and constructor code */
}

nsContentFrameMessageManager::~nsContentFrameMessageManager()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow content; */
NS_IMETHODIMP nsContentFrameMessageManager::GetContent(nsIDOMWindow * *aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShell docShell; */
NS_IMETHODIMP nsContentFrameMessageManager::GetDocShell(nsIDocShell * *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIInProcessContentFrameMessageManager */
#define NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID_STR "9c6bd4d7-88d2-46d6-8606-f2d57d46f051"

#define NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID \
  {0x9c6bd4d7, 0x88d2, 0x46d6, \
    { 0x86, 0x06, 0xf2, 0xd5, 0x7d, 0x46, 0xf0, 0x51 }}

class NS_NO_VTABLE nsIInProcessContentFrameMessageManager : public nsIContentFrameMessageManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID)

  /* [notxpcom] nsIContent getOwnerContent (); */
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void) = 0;

  /* [notxpcom] void cacheFrameLoader (in nsIFrameLoader aFrameLoader); */
  NS_IMETHOD_(void) CacheFrameLoader(nsIFrameLoader *aFrameLoader) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInProcessContentFrameMessageManager, NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER \
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void) override; \
  NS_IMETHOD_(void) CacheFrameLoader(nsIFrameLoader *aFrameLoader) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void) override { return _to GetOwnerContent(); } \
  NS_IMETHOD_(void) CacheFrameLoader(nsIFrameLoader *aFrameLoader) override { return _to CacheFrameLoader(aFrameLoader); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void) override; \
  NS_IMETHOD_(void) CacheFrameLoader(nsIFrameLoader *aFrameLoader) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInProcessContentFrameMessageManager : public nsIInProcessContentFrameMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER

  nsInProcessContentFrameMessageManager();

private:
  ~nsInProcessContentFrameMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInProcessContentFrameMessageManager, nsIInProcessContentFrameMessageManager)

nsInProcessContentFrameMessageManager::nsInProcessContentFrameMessageManager()
{
  /* member initializers and constructor code */
}

nsInProcessContentFrameMessageManager::~nsInProcessContentFrameMessageManager()
{
  /* destructor code */
}

/* [notxpcom] nsIContent getOwnerContent (); */
NS_IMETHODIMP_(nsIContent *) nsInProcessContentFrameMessageManager::GetOwnerContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void cacheFrameLoader (in nsIFrameLoader aFrameLoader); */
NS_IMETHODIMP_(void) nsInProcessContentFrameMessageManager::CacheFrameLoader(nsIFrameLoader *aFrameLoader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentProcessMessageManager */
#define NS_ICONTENTPROCESSMESSAGEMANAGER_IID_STR "6d12e467-2446-46db-9965-e4e93cb87ca5"

#define NS_ICONTENTPROCESSMESSAGEMANAGER_IID \
  {0x6d12e467, 0x2446, 0x46db, \
    { 0x99, 0x65, 0xe4, 0xe9, 0x3c, 0xb8, 0x7c, 0xa5 }}

class NS_NO_VTABLE nsIContentProcessMessageManager : public nsIMessageManagerGlobal {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPROCESSMESSAGEMANAGER_IID)

  /* [implicit_jscontext] readonly attribute jsval initialProcessData; */
  NS_IMETHOD GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentProcessMessageManager, NS_ICONTENTPROCESSMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPROCESSMESSAGEMANAGER \
  NS_IMETHOD GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPROCESSMESSAGEMANAGER(_to) \
  NS_IMETHOD GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData) override { return _to GetInitialProcessData(cx, aInitialProcessData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPROCESSMESSAGEMANAGER(_to) \
  NS_IMETHOD GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInitialProcessData(cx, aInitialProcessData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentProcessMessageManager : public nsIContentProcessMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPROCESSMESSAGEMANAGER

  nsContentProcessMessageManager();

private:
  ~nsContentProcessMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentProcessMessageManager, nsIContentProcessMessageManager)

nsContentProcessMessageManager::nsContentProcessMessageManager()
{
  /* member initializers and constructor code */
}

nsContentProcessMessageManager::~nsContentProcessMessageManager()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval initialProcessData; */
NS_IMETHODIMP nsContentProcessMessageManager::GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFrameScriptLoader */
#define NS_IFRAMESCRIPTLOADER_IID_STR "bf61446b-ba24-4b1d-88c7-4f94724b9ce1"

#define NS_IFRAMESCRIPTLOADER_IID \
  {0xbf61446b, 0xba24, 0x4b1d, \
    { 0x88, 0xc7, 0x4f, 0x94, 0x72, 0x4b, 0x9c, 0xe1 }}

class NS_NO_VTABLE nsIFrameScriptLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMESCRIPTLOADER_IID)

  /* void loadFrameScript (in AString aURL, in boolean aAllowDelayedLoad, [optional] in boolean aRunInGlobalScope); */
  NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope) = 0;

  /* void removeDelayedFrameScript (in AString aURL); */
  NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) = 0;

  /* [implicit_jscontext] jsval getDelayedFrameScripts (); */
  NS_IMETHOD GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameScriptLoader, NS_IFRAMESCRIPTLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMESCRIPTLOADER \
  NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope) override; \
  NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) override; \
  NS_IMETHOD GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMESCRIPTLOADER(_to) \
  NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope) override { return _to LoadFrameScript(aURL, aAllowDelayedLoad, aRunInGlobalScope); } \
  NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) override { return _to RemoveDelayedFrameScript(aURL); } \
  NS_IMETHOD GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetDelayedFrameScripts(cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMESCRIPTLOADER(_to) \
  NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadFrameScript(aURL, aAllowDelayedLoad, aRunInGlobalScope); } \
  NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDelayedFrameScript(aURL); } \
  NS_IMETHOD GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelayedFrameScripts(cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameScriptLoader : public nsIFrameScriptLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMESCRIPTLOADER

  nsFrameScriptLoader();

private:
  ~nsFrameScriptLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsFrameScriptLoader, nsIFrameScriptLoader)

nsFrameScriptLoader::nsFrameScriptLoader()
{
  /* member initializers and constructor code */
}

nsFrameScriptLoader::~nsFrameScriptLoader()
{
  /* destructor code */
}

/* void loadFrameScript (in AString aURL, in boolean aAllowDelayedLoad, [optional] in boolean aRunInGlobalScope); */
NS_IMETHODIMP nsFrameScriptLoader::LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDelayedFrameScript (in AString aURL); */
NS_IMETHODIMP nsFrameScriptLoader::RemoveDelayedFrameScript(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getDelayedFrameScripts (); */
NS_IMETHODIMP nsFrameScriptLoader::GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIProcessScriptLoader */
#define NS_IPROCESSSCRIPTLOADER_IID_STR "7e1e1a20-b24f-11e4-ab27-0800200c9a66"

#define NS_IPROCESSSCRIPTLOADER_IID \
  {0x7e1e1a20, 0xb24f, 0x11e4, \
    { 0xab, 0x27, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIProcessScriptLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROCESSSCRIPTLOADER_IID)

  /* void loadProcessScript (in AString aURL, in boolean aAllowDelayedLoad); */
  NS_IMETHOD LoadProcessScript(const nsAString & aURL, bool aAllowDelayedLoad) = 0;

  /* void removeDelayedProcessScript (in AString aURL); */
  NS_IMETHOD RemoveDelayedProcessScript(const nsAString & aURL) = 0;

  /* [implicit_jscontext] jsval getDelayedProcessScripts (); */
  NS_IMETHOD GetDelayedProcessScripts(JSContext* cx, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProcessScriptLoader, NS_IPROCESSSCRIPTLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROCESSSCRIPTLOADER \
  NS_IMETHOD LoadProcessScript(const nsAString & aURL, bool aAllowDelayedLoad) override; \
  NS_IMETHOD RemoveDelayedProcessScript(const nsAString & aURL) override; \
  NS_IMETHOD GetDelayedProcessScripts(JSContext* cx, JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROCESSSCRIPTLOADER(_to) \
  NS_IMETHOD LoadProcessScript(const nsAString & aURL, bool aAllowDelayedLoad) override { return _to LoadProcessScript(aURL, aAllowDelayedLoad); } \
  NS_IMETHOD RemoveDelayedProcessScript(const nsAString & aURL) override { return _to RemoveDelayedProcessScript(aURL); } \
  NS_IMETHOD GetDelayedProcessScripts(JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetDelayedProcessScripts(cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROCESSSCRIPTLOADER(_to) \
  NS_IMETHOD LoadProcessScript(const nsAString & aURL, bool aAllowDelayedLoad) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadProcessScript(aURL, aAllowDelayedLoad); } \
  NS_IMETHOD RemoveDelayedProcessScript(const nsAString & aURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDelayedProcessScript(aURL); } \
  NS_IMETHOD GetDelayedProcessScripts(JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelayedProcessScripts(cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProcessScriptLoader : public nsIProcessScriptLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROCESSSCRIPTLOADER

  nsProcessScriptLoader();

private:
  ~nsProcessScriptLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProcessScriptLoader, nsIProcessScriptLoader)

nsProcessScriptLoader::nsProcessScriptLoader()
{
  /* member initializers and constructor code */
}

nsProcessScriptLoader::~nsProcessScriptLoader()
{
  /* destructor code */
}

/* void loadProcessScript (in AString aURL, in boolean aAllowDelayedLoad); */
NS_IMETHODIMP nsProcessScriptLoader::LoadProcessScript(const nsAString & aURL, bool aAllowDelayedLoad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDelayedProcessScript (in AString aURL); */
NS_IMETHODIMP nsProcessScriptLoader::RemoveDelayedProcessScript(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getDelayedProcessScripts (); */
NS_IMETHODIMP nsProcessScriptLoader::GetDelayedProcessScripts(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGlobalProcessScriptLoader */
#define NS_IGLOBALPROCESSSCRIPTLOADER_IID_STR "5b390753-abb3-49b0-ae3b-b803dab58144"

#define NS_IGLOBALPROCESSSCRIPTLOADER_IID \
  {0x5b390753, 0xabb3, 0x49b0, \
    { 0xae, 0x3b, 0xb8, 0x03, 0xda, 0xb5, 0x81, 0x44 }}

class NS_NO_VTABLE nsIGlobalProcessScriptLoader : public nsIProcessScriptLoader {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGLOBALPROCESSSCRIPTLOADER_IID)

  /* [implicit_jscontext] readonly attribute jsval initialProcessData; */
  NS_IMETHOD GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGlobalProcessScriptLoader, NS_IGLOBALPROCESSSCRIPTLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGLOBALPROCESSSCRIPTLOADER \
  NS_IMETHOD GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGLOBALPROCESSSCRIPTLOADER(_to) \
  NS_IMETHOD GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData) override { return _to GetInitialProcessData(cx, aInitialProcessData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGLOBALPROCESSSCRIPTLOADER(_to) \
  NS_IMETHOD GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInitialProcessData(cx, aInitialProcessData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGlobalProcessScriptLoader : public nsIGlobalProcessScriptLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGLOBALPROCESSSCRIPTLOADER

  nsGlobalProcessScriptLoader();

private:
  ~nsGlobalProcessScriptLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsGlobalProcessScriptLoader, nsIGlobalProcessScriptLoader)

nsGlobalProcessScriptLoader::nsGlobalProcessScriptLoader()
{
  /* member initializers and constructor code */
}

nsGlobalProcessScriptLoader::~nsGlobalProcessScriptLoader()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval initialProcessData; */
NS_IMETHODIMP nsGlobalProcessScriptLoader::GetInitialProcessData(JSContext* cx, JS::MutableHandleValue aInitialProcessData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIProcessChecker */
#define NS_IPROCESSCHECKER_IID_STR "637e8538-4f8f-4a3d-8510-e74386233e19"

#define NS_IPROCESSCHECKER_IID \
  {0x637e8538, 0x4f8f, 0x4a3d, \
    { 0x85, 0x10, 0xe7, 0x43, 0x86, 0x23, 0x3e, 0x19 }}

class NS_NO_VTABLE nsIProcessChecker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROCESSCHECKER_IID)

  /* bool killChild (); */
  NS_IMETHOD KillChild(bool *_retval) = 0;

  /* boolean assertPermission (in DOMString aPermission); */
  NS_IMETHOD AssertPermission(const nsAString & aPermission, bool *_retval) = 0;

  /* boolean assertContainApp (in DOMString aManifestURL); */
  NS_IMETHOD AssertContainApp(const nsAString & aManifestURL, bool *_retval) = 0;

  /* boolean assertAppHasPermission (in DOMString aPermission); */
  NS_IMETHOD AssertAppHasPermission(const nsAString & aPermission, bool *_retval) = 0;

  /* boolean assertAppHasStatus (in unsigned short aStatus); */
  NS_IMETHOD AssertAppHasStatus(uint16_t aStatus, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProcessChecker, NS_IPROCESSCHECKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROCESSCHECKER \
  NS_IMETHOD KillChild(bool *_retval) override; \
  NS_IMETHOD AssertPermission(const nsAString & aPermission, bool *_retval) override; \
  NS_IMETHOD AssertContainApp(const nsAString & aManifestURL, bool *_retval) override; \
  NS_IMETHOD AssertAppHasPermission(const nsAString & aPermission, bool *_retval) override; \
  NS_IMETHOD AssertAppHasStatus(uint16_t aStatus, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROCESSCHECKER(_to) \
  NS_IMETHOD KillChild(bool *_retval) override { return _to KillChild(_retval); } \
  NS_IMETHOD AssertPermission(const nsAString & aPermission, bool *_retval) override { return _to AssertPermission(aPermission, _retval); } \
  NS_IMETHOD AssertContainApp(const nsAString & aManifestURL, bool *_retval) override { return _to AssertContainApp(aManifestURL, _retval); } \
  NS_IMETHOD AssertAppHasPermission(const nsAString & aPermission, bool *_retval) override { return _to AssertAppHasPermission(aPermission, _retval); } \
  NS_IMETHOD AssertAppHasStatus(uint16_t aStatus, bool *_retval) override { return _to AssertAppHasStatus(aStatus, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROCESSCHECKER(_to) \
  NS_IMETHOD KillChild(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->KillChild(_retval); } \
  NS_IMETHOD AssertPermission(const nsAString & aPermission, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AssertPermission(aPermission, _retval); } \
  NS_IMETHOD AssertContainApp(const nsAString & aManifestURL, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AssertContainApp(aManifestURL, _retval); } \
  NS_IMETHOD AssertAppHasPermission(const nsAString & aPermission, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AssertAppHasPermission(aPermission, _retval); } \
  NS_IMETHOD AssertAppHasStatus(uint16_t aStatus, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AssertAppHasStatus(aStatus, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProcessChecker : public nsIProcessChecker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROCESSCHECKER

  nsProcessChecker();

private:
  ~nsProcessChecker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProcessChecker, nsIProcessChecker)

nsProcessChecker::nsProcessChecker()
{
  /* member initializers and constructor code */
}

nsProcessChecker::~nsProcessChecker()
{
  /* destructor code */
}

/* bool killChild (); */
NS_IMETHODIMP nsProcessChecker::KillChild(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean assertPermission (in DOMString aPermission); */
NS_IMETHODIMP nsProcessChecker::AssertPermission(const nsAString & aPermission, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean assertContainApp (in DOMString aManifestURL); */
NS_IMETHODIMP nsProcessChecker::AssertContainApp(const nsAString & aManifestURL, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean assertAppHasPermission (in DOMString aPermission); */
NS_IMETHODIMP nsProcessChecker::AssertAppHasPermission(const nsAString & aPermission, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean assertAppHasStatus (in unsigned short aStatus); */
NS_IMETHODIMP nsProcessChecker::AssertAppHasStatus(uint16_t aStatus, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMessageManager_h__ */
