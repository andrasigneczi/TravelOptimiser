/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWorkerDebugger.idl
 */

#ifndef __gen_nsIWorkerDebugger_h__
#define __gen_nsIWorkerDebugger_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIWorkerDebuggerListener */
#define NS_IWORKERDEBUGGERLISTENER_IID_STR "530db841-1b2c-485a-beeb-f2b1acb9714e"

#define NS_IWORKERDEBUGGERLISTENER_IID \
  {0x530db841, 0x1b2c, 0x485a, \
    { 0xbe, 0xeb, 0xf2, 0xb1, 0xac, 0xb9, 0x71, 0x4e }}

class NS_NO_VTABLE nsIWorkerDebuggerListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERDEBUGGERLISTENER_IID)

  /* void onClose (); */
  NS_IMETHOD OnClose(void) = 0;

  /* void onError (in DOMString filename, in unsigned long lineno, in DOMString message); */
  NS_IMETHOD OnError(const nsAString & filename, uint32_t lineno, const nsAString & message) = 0;

  /* void onFreeze (); */
  NS_IMETHOD OnFreeze(void) = 0;

  /* void onMessage (in DOMString message); */
  NS_IMETHOD OnMessage(const nsAString & message) = 0;

  /* void onThaw (); */
  NS_IMETHOD OnThaw(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerDebuggerListener, NS_IWORKERDEBUGGERLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERDEBUGGERLISTENER \
  NS_IMETHOD OnClose(void) override; \
  NS_IMETHOD OnError(const nsAString & filename, uint32_t lineno, const nsAString & message) override; \
  NS_IMETHOD OnFreeze(void) override; \
  NS_IMETHOD OnMessage(const nsAString & message) override; \
  NS_IMETHOD OnThaw(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERDEBUGGERLISTENER(_to) \
  NS_IMETHOD OnClose(void) override { return _to OnClose(); } \
  NS_IMETHOD OnError(const nsAString & filename, uint32_t lineno, const nsAString & message) override { return _to OnError(filename, lineno, message); } \
  NS_IMETHOD OnFreeze(void) override { return _to OnFreeze(); } \
  NS_IMETHOD OnMessage(const nsAString & message) override { return _to OnMessage(message); } \
  NS_IMETHOD OnThaw(void) override { return _to OnThaw(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERDEBUGGERLISTENER(_to) \
  NS_IMETHOD OnClose(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnClose(); } \
  NS_IMETHOD OnError(const nsAString & filename, uint32_t lineno, const nsAString & message) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(filename, lineno, message); } \
  NS_IMETHOD OnFreeze(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnFreeze(); } \
  NS_IMETHOD OnMessage(const nsAString & message) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnMessage(message); } \
  NS_IMETHOD OnThaw(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnThaw(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerDebuggerListener : public nsIWorkerDebuggerListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERDEBUGGERLISTENER

  nsWorkerDebuggerListener();

private:
  ~nsWorkerDebuggerListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsWorkerDebuggerListener, nsIWorkerDebuggerListener)

nsWorkerDebuggerListener::nsWorkerDebuggerListener()
{
  /* member initializers and constructor code */
}

nsWorkerDebuggerListener::~nsWorkerDebuggerListener()
{
  /* destructor code */
}

/* void onClose (); */
NS_IMETHODIMP nsWorkerDebuggerListener::OnClose()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onError (in DOMString filename, in unsigned long lineno, in DOMString message); */
NS_IMETHODIMP nsWorkerDebuggerListener::OnError(const nsAString & filename, uint32_t lineno, const nsAString & message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onFreeze (); */
NS_IMETHODIMP nsWorkerDebuggerListener::OnFreeze()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onMessage (in DOMString message); */
NS_IMETHODIMP nsWorkerDebuggerListener::OnMessage(const nsAString & message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onThaw (); */
NS_IMETHODIMP nsWorkerDebuggerListener::OnThaw()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWorkerDebugger */
#define NS_IWORKERDEBUGGER_IID_STR "bdcaf96f-916a-4b24-bb53-165c1785668b"

#define NS_IWORKERDEBUGGER_IID \
  {0xbdcaf96f, 0x916a, 0x4b24, \
    { 0xbb, 0x53, 0x16, 0x5c, 0x17, 0x85, 0x66, 0x8b }}

class NS_NO_VTABLE nsIWorkerDebugger : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWORKERDEBUGGER_IID)

  enum {
    TYPE_DEDICATED = 0U,
    TYPE_SHARED = 1U,
    TYPE_SERVICE = 2U
  };

  /* readonly attribute bool isClosed; */
  NS_IMETHOD GetIsClosed(bool *aIsClosed) = 0;

  /* readonly attribute bool isChrome; */
  NS_IMETHOD GetIsChrome(bool *aIsChrome) = 0;

  /* readonly attribute bool isFrozen; */
  NS_IMETHOD GetIsFrozen(bool *aIsFrozen) = 0;

  /* readonly attribute bool isInitialized; */
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) = 0;

  /* readonly attribute nsIWorkerDebugger parent; */
  NS_IMETHOD GetParent(nsIWorkerDebugger * *aParent) = 0;

  /* readonly attribute unsigned long type; */
  NS_IMETHOD GetType(uint32_t *aType) = 0;

  /* readonly attribute DOMString url; */
  NS_IMETHOD GetUrl(nsAString & aUrl) = 0;

  /* readonly attribute nsIDOMWindow window; */
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) = 0;

  /* [implicit_jscontext] void initialize (in DOMString url); */
  NS_IMETHOD Initialize(const nsAString & url, JSContext* cx) = 0;

  /* [binaryname(PostMessageMoz),implicit_jscontext] void postMessage (in DOMString message); */
  NS_IMETHOD PostMessageMoz(const nsAString & message, JSContext* cx) = 0;

  /* void addListener (in nsIWorkerDebuggerListener listener); */
  NS_IMETHOD AddListener(nsIWorkerDebuggerListener *listener) = 0;

  /* void removeListener (in nsIWorkerDebuggerListener listener); */
  NS_IMETHOD RemoveListener(nsIWorkerDebuggerListener *listener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWorkerDebugger, NS_IWORKERDEBUGGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWORKERDEBUGGER \
  NS_IMETHOD GetIsClosed(bool *aIsClosed) override; \
  NS_IMETHOD GetIsChrome(bool *aIsChrome) override; \
  NS_IMETHOD GetIsFrozen(bool *aIsFrozen) override; \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) override; \
  NS_IMETHOD GetParent(nsIWorkerDebugger * *aParent) override; \
  NS_IMETHOD GetType(uint32_t *aType) override; \
  NS_IMETHOD GetUrl(nsAString & aUrl) override; \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override; \
  NS_IMETHOD Initialize(const nsAString & url, JSContext* cx) override; \
  NS_IMETHOD PostMessageMoz(const nsAString & message, JSContext* cx) override; \
  NS_IMETHOD AddListener(nsIWorkerDebuggerListener *listener) override; \
  NS_IMETHOD RemoveListener(nsIWorkerDebuggerListener *listener) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWORKERDEBUGGER(_to) \
  NS_IMETHOD GetIsClosed(bool *aIsClosed) override { return _to GetIsClosed(aIsClosed); } \
  NS_IMETHOD GetIsChrome(bool *aIsChrome) override { return _to GetIsChrome(aIsChrome); } \
  NS_IMETHOD GetIsFrozen(bool *aIsFrozen) override { return _to GetIsFrozen(aIsFrozen); } \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) override { return _to GetIsInitialized(aIsInitialized); } \
  NS_IMETHOD GetParent(nsIWorkerDebugger * *aParent) override { return _to GetParent(aParent); } \
  NS_IMETHOD GetType(uint32_t *aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetUrl(nsAString & aUrl) override { return _to GetUrl(aUrl); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override { return _to GetWindow(aWindow); } \
  NS_IMETHOD Initialize(const nsAString & url, JSContext* cx) override { return _to Initialize(url, cx); } \
  NS_IMETHOD PostMessageMoz(const nsAString & message, JSContext* cx) override { return _to PostMessageMoz(message, cx); } \
  NS_IMETHOD AddListener(nsIWorkerDebuggerListener *listener) override { return _to AddListener(listener); } \
  NS_IMETHOD RemoveListener(nsIWorkerDebuggerListener *listener) override { return _to RemoveListener(listener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWORKERDEBUGGER(_to) \
  NS_IMETHOD GetIsClosed(bool *aIsClosed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsClosed(aIsClosed); } \
  NS_IMETHOD GetIsChrome(bool *aIsChrome) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsChrome(aIsChrome); } \
  NS_IMETHOD GetIsFrozen(bool *aIsFrozen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFrozen(aIsFrozen); } \
  NS_IMETHOD GetIsInitialized(bool *aIsInitialized) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInitialized(aIsInitialized); } \
  NS_IMETHOD GetParent(nsIWorkerDebugger * *aParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_IMETHOD GetType(uint32_t *aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetUrl(nsAString & aUrl) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrl(aUrl); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD Initialize(const nsAString & url, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(url, cx); } \
  NS_IMETHOD PostMessageMoz(const nsAString & message, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PostMessageMoz(message, cx); } \
  NS_IMETHOD AddListener(nsIWorkerDebuggerListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(listener); } \
  NS_IMETHOD RemoveListener(nsIWorkerDebuggerListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(listener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWorkerDebugger : public nsIWorkerDebugger
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWORKERDEBUGGER

  nsWorkerDebugger();

private:
  ~nsWorkerDebugger();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsWorkerDebugger, nsIWorkerDebugger)

nsWorkerDebugger::nsWorkerDebugger()
{
  /* member initializers and constructor code */
}

nsWorkerDebugger::~nsWorkerDebugger()
{
  /* destructor code */
}

/* readonly attribute bool isClosed; */
NS_IMETHODIMP nsWorkerDebugger::GetIsClosed(bool *aIsClosed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool isChrome; */
NS_IMETHODIMP nsWorkerDebugger::GetIsChrome(bool *aIsChrome)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool isFrozen; */
NS_IMETHODIMP nsWorkerDebugger::GetIsFrozen(bool *aIsFrozen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool isInitialized; */
NS_IMETHODIMP nsWorkerDebugger::GetIsInitialized(bool *aIsInitialized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIWorkerDebugger parent; */
NS_IMETHODIMP nsWorkerDebugger::GetParent(nsIWorkerDebugger * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long type; */
NS_IMETHODIMP nsWorkerDebugger::GetType(uint32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString url; */
NS_IMETHODIMP nsWorkerDebugger::GetUrl(nsAString & aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow window; */
NS_IMETHODIMP nsWorkerDebugger::GetWindow(nsIDOMWindow * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void initialize (in DOMString url); */
NS_IMETHODIMP nsWorkerDebugger::Initialize(const nsAString & url, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(PostMessageMoz),implicit_jscontext] void postMessage (in DOMString message); */
NS_IMETHODIMP nsWorkerDebugger::PostMessageMoz(const nsAString & message, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addListener (in nsIWorkerDebuggerListener listener); */
NS_IMETHODIMP nsWorkerDebugger::AddListener(nsIWorkerDebuggerListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in nsIWorkerDebuggerListener listener); */
NS_IMETHODIMP nsWorkerDebugger::RemoveListener(nsIWorkerDebuggerListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWorkerDebugger_h__ */
