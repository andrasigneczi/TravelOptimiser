/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIServiceWorkerManager.idl
 */

#ifndef __gen_nsIServiceWorkerManager_h__
#define __gen_nsIServiceWorkerManager_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIDocument; /* forward declaration */

class nsIInterceptedChannel; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIServiceWorkerUnregisterCallback */
#define NS_ISERVICEWORKERUNREGISTERCALLBACK_IID_STR "52ee2c9d-ee87-4caf-9588-23ae77ff8798"

#define NS_ISERVICEWORKERUNREGISTERCALLBACK_IID \
  {0x52ee2c9d, 0xee87, 0x4caf, \
    { 0x95, 0x88, 0x23, 0xae, 0x77, 0xff, 0x87, 0x98 }}

class NS_NO_VTABLE nsIServiceWorkerUnregisterCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISERVICEWORKERUNREGISTERCALLBACK_IID)

  /* void unregisterSucceeded (in bool aState); */
  NS_IMETHOD UnregisterSucceeded(bool aState) = 0;

  /* void unregisterFailed (); */
  NS_IMETHOD UnregisterFailed(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIServiceWorkerUnregisterCallback, NS_ISERVICEWORKERUNREGISTERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISERVICEWORKERUNREGISTERCALLBACK \
  NS_IMETHOD UnregisterSucceeded(bool aState) override; \
  NS_IMETHOD UnregisterFailed(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISERVICEWORKERUNREGISTERCALLBACK(_to) \
  NS_IMETHOD UnregisterSucceeded(bool aState) override { return _to UnregisterSucceeded(aState); } \
  NS_IMETHOD UnregisterFailed(void) override { return _to UnregisterFailed(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISERVICEWORKERUNREGISTERCALLBACK(_to) \
  NS_IMETHOD UnregisterSucceeded(bool aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterSucceeded(aState); } \
  NS_IMETHOD UnregisterFailed(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterFailed(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsServiceWorkerUnregisterCallback : public nsIServiceWorkerUnregisterCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISERVICEWORKERUNREGISTERCALLBACK

  nsServiceWorkerUnregisterCallback();

private:
  ~nsServiceWorkerUnregisterCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsServiceWorkerUnregisterCallback, nsIServiceWorkerUnregisterCallback)

nsServiceWorkerUnregisterCallback::nsServiceWorkerUnregisterCallback()
{
  /* member initializers and constructor code */
}

nsServiceWorkerUnregisterCallback::~nsServiceWorkerUnregisterCallback()
{
  /* destructor code */
}

/* void unregisterSucceeded (in bool aState); */
NS_IMETHODIMP nsServiceWorkerUnregisterCallback::UnregisterSucceeded(bool aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterFailed (); */
NS_IMETHODIMP nsServiceWorkerUnregisterCallback::UnregisterFailed()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIServiceWorkerInfo */
#define NS_ISERVICEWORKERINFO_IID_STR "e633b73b-a734-4d04-a09c-b7779a439f3f"

#define NS_ISERVICEWORKERINFO_IID \
  {0xe633b73b, 0xa734, 0x4d04, \
    { 0xa0, 0x9c, 0xb7, 0x77, 0x9a, 0x43, 0x9f, 0x3f }}

class NS_NO_VTABLE nsIServiceWorkerInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISERVICEWORKERINFO_IID)

  /* readonly attribute nsIPrincipal principal; */
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) = 0;

  /* readonly attribute DOMString scope; */
  NS_IMETHOD GetScope(nsAString & aScope) = 0;

  /* readonly attribute DOMString scriptSpec; */
  NS_IMETHOD GetScriptSpec(nsAString & aScriptSpec) = 0;

  /* readonly attribute DOMString currentWorkerURL; */
  NS_IMETHOD GetCurrentWorkerURL(nsAString & aCurrentWorkerURL) = 0;

  /* readonly attribute DOMString activeCacheName; */
  NS_IMETHOD GetActiveCacheName(nsAString & aActiveCacheName) = 0;

  /* readonly attribute DOMString waitingCacheName; */
  NS_IMETHOD GetWaitingCacheName(nsAString & aWaitingCacheName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIServiceWorkerInfo, NS_ISERVICEWORKERINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISERVICEWORKERINFO \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) override; \
  NS_IMETHOD GetScope(nsAString & aScope) override; \
  NS_IMETHOD GetScriptSpec(nsAString & aScriptSpec) override; \
  NS_IMETHOD GetCurrentWorkerURL(nsAString & aCurrentWorkerURL) override; \
  NS_IMETHOD GetActiveCacheName(nsAString & aActiveCacheName) override; \
  NS_IMETHOD GetWaitingCacheName(nsAString & aWaitingCacheName) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISERVICEWORKERINFO(_to) \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) override { return _to GetPrincipal(aPrincipal); } \
  NS_IMETHOD GetScope(nsAString & aScope) override { return _to GetScope(aScope); } \
  NS_IMETHOD GetScriptSpec(nsAString & aScriptSpec) override { return _to GetScriptSpec(aScriptSpec); } \
  NS_IMETHOD GetCurrentWorkerURL(nsAString & aCurrentWorkerURL) override { return _to GetCurrentWorkerURL(aCurrentWorkerURL); } \
  NS_IMETHOD GetActiveCacheName(nsAString & aActiveCacheName) override { return _to GetActiveCacheName(aActiveCacheName); } \
  NS_IMETHOD GetWaitingCacheName(nsAString & aWaitingCacheName) override { return _to GetWaitingCacheName(aWaitingCacheName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISERVICEWORKERINFO(_to) \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrincipal(aPrincipal); } \
  NS_IMETHOD GetScope(nsAString & aScope) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScope(aScope); } \
  NS_IMETHOD GetScriptSpec(nsAString & aScriptSpec) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptSpec(aScriptSpec); } \
  NS_IMETHOD GetCurrentWorkerURL(nsAString & aCurrentWorkerURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentWorkerURL(aCurrentWorkerURL); } \
  NS_IMETHOD GetActiveCacheName(nsAString & aActiveCacheName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveCacheName(aActiveCacheName); } \
  NS_IMETHOD GetWaitingCacheName(nsAString & aWaitingCacheName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWaitingCacheName(aWaitingCacheName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsServiceWorkerInfo : public nsIServiceWorkerInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISERVICEWORKERINFO

  nsServiceWorkerInfo();

private:
  ~nsServiceWorkerInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsServiceWorkerInfo, nsIServiceWorkerInfo)

nsServiceWorkerInfo::nsServiceWorkerInfo()
{
  /* member initializers and constructor code */
}

nsServiceWorkerInfo::~nsServiceWorkerInfo()
{
  /* destructor code */
}

/* readonly attribute nsIPrincipal principal; */
NS_IMETHODIMP nsServiceWorkerInfo::GetPrincipal(nsIPrincipal * *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString scope; */
NS_IMETHODIMP nsServiceWorkerInfo::GetScope(nsAString & aScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString scriptSpec; */
NS_IMETHODIMP nsServiceWorkerInfo::GetScriptSpec(nsAString & aScriptSpec)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString currentWorkerURL; */
NS_IMETHODIMP nsServiceWorkerInfo::GetCurrentWorkerURL(nsAString & aCurrentWorkerURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString activeCacheName; */
NS_IMETHODIMP nsServiceWorkerInfo::GetActiveCacheName(nsAString & aActiveCacheName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString waitingCacheName; */
NS_IMETHODIMP nsServiceWorkerInfo::GetWaitingCacheName(nsAString & aWaitingCacheName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIServiceWorkerManager */
#define NS_ISERVICEWORKERMANAGER_IID_STR "e9abb123-0099-4d9e-85db-c8cd0aff19e6"

#define NS_ISERVICEWORKERMANAGER_IID \
  {0xe9abb123, 0x0099, 0x4d9e, \
    { 0x85, 0xdb, 0xc8, 0xcd, 0x0a, 0xff, 0x19, 0xe6 }}

class NS_NO_VTABLE nsIServiceWorkerManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISERVICEWORKERMANAGER_IID)

  /* nsISupports register (in nsIDOMWindow aWindow, in nsIURI aScope, in nsIURI aScriptURI); */
  NS_IMETHOD Register(nsIDOMWindow *aWindow, nsIURI *aScope, nsIURI *aScriptURI, nsISupports * *_retval) = 0;

  /* void unregister (in nsIPrincipal aPrincipal, in nsIServiceWorkerUnregisterCallback aCallback, in DOMString aScope); */
  NS_IMETHOD Unregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope) = 0;

  /* nsISupports getRegistrations (in nsIDOMWindow aWindow); */
  NS_IMETHOD GetRegistrations(nsIDOMWindow *aWindow, nsISupports * *_retval) = 0;

  /* nsISupports getRegistration (in nsIDOMWindow aWindow, in DOMString aScope); */
  NS_IMETHOD GetRegistration(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) = 0;

  /* nsISupports getReadyPromise (in nsIDOMWindow aWindow); */
  NS_IMETHOD GetReadyPromise(nsIDOMWindow *aWindow, nsISupports * *_retval) = 0;

  /* void removeReadyPromise (in nsIDOMWindow aWindow); */
  NS_IMETHOD RemoveReadyPromise(nsIDOMWindow *aWindow) = 0;

  /* [nostdcall,notxpcom] void MaybeStartControlling (in nsIDocument aDoc); */
  virtual void MaybeStartControlling(nsIDocument *aDoc) = 0;

  /* [nostdcall,notxpcom] void MaybeStopControlling (in nsIDocument aDoc); */
  virtual void MaybeStopControlling(nsIDocument *aDoc) = 0;

  /* [noscript] nsISupports GetInstalling (in nsIDOMWindow aWindow, in DOMString aScope); */
  NS_IMETHOD GetInstalling(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) = 0;

  /* [noscript] nsISupports GetWaiting (in nsIDOMWindow aWindow, in DOMString aScope); */
  NS_IMETHOD GetWaiting(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) = 0;

  /* [noscript] nsISupports GetActive (in nsIDOMWindow aWindow, in DOMString aScope); */
  NS_IMETHOD GetActive(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) = 0;

  /* [noscript] nsISupports GetDocumentController (in nsIDOMWindow aWindow); */
  NS_IMETHOD GetDocumentController(nsIDOMWindow *aWindow, nsISupports * *_retval) = 0;

  /* void removeAndPropagate (in AUTF8String aHost); */
  NS_IMETHOD RemoveAndPropagate(const nsACString & aHost) = 0;

  /* DOMString getScopeForUrl (in nsIPrincipal aPrincipal, in DOMString aPath); */
  NS_IMETHOD GetScopeForUrl(nsIPrincipal *aPrincipal, const nsAString & aPath, nsAString & _retval) = 0;

  /* nsIArray getAllRegistrations (); */
  NS_IMETHOD GetAllRegistrations(nsIArray * *_retval) = 0;

  /* [implicit_jscontext] void propagateSoftUpdate (in jsval aOriginAttributes, in DOMString aScope); */
  NS_IMETHOD PropagateSoftUpdate(JS::HandleValue aOriginAttributes, const nsAString & aScope, JSContext* cx) = 0;

  /* void propagateUnregister (in nsIPrincipal aPrincipal, in nsIServiceWorkerUnregisterCallback aCallback, in DOMString aScope); */
  NS_IMETHOD PropagateUnregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope) = 0;

  /* void sendPushEvent (in ACString aOriginAttributes, in ACString aScope, in DOMString aData); */
  NS_IMETHOD SendPushEvent(const nsACString & aOriginAttributes, const nsACString & aScope, const nsAString & aData) = 0;

  /* void sendPushSubscriptionChangeEvent (in ACString aOriginAttributes, in ACString scope); */
  NS_IMETHOD SendPushSubscriptionChangeEvent(const nsACString & aOriginAttributes, const nsACString & scope) = 0;

  /* void updateAllRegistrations (); */
  NS_IMETHOD UpdateAllRegistrations(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIServiceWorkerManager, NS_ISERVICEWORKERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISERVICEWORKERMANAGER \
  NS_IMETHOD Register(nsIDOMWindow *aWindow, nsIURI *aScope, nsIURI *aScriptURI, nsISupports * *_retval) override; \
  NS_IMETHOD Unregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope) override; \
  NS_IMETHOD GetRegistrations(nsIDOMWindow *aWindow, nsISupports * *_retval) override; \
  NS_IMETHOD GetRegistration(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override; \
  NS_IMETHOD GetReadyPromise(nsIDOMWindow *aWindow, nsISupports * *_retval) override; \
  NS_IMETHOD RemoveReadyPromise(nsIDOMWindow *aWindow) override; \
  virtual void MaybeStartControlling(nsIDocument *aDoc) override; \
  virtual void MaybeStopControlling(nsIDocument *aDoc) override; \
  NS_IMETHOD GetInstalling(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override; \
  NS_IMETHOD GetWaiting(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override; \
  NS_IMETHOD GetActive(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override; \
  NS_IMETHOD GetDocumentController(nsIDOMWindow *aWindow, nsISupports * *_retval) override; \
  NS_IMETHOD RemoveAndPropagate(const nsACString & aHost) override; \
  NS_IMETHOD GetScopeForUrl(nsIPrincipal *aPrincipal, const nsAString & aPath, nsAString & _retval) override; \
  NS_IMETHOD GetAllRegistrations(nsIArray * *_retval) override; \
  NS_IMETHOD PropagateSoftUpdate(JS::HandleValue aOriginAttributes, const nsAString & aScope, JSContext* cx) override; \
  NS_IMETHOD PropagateUnregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope) override; \
  NS_IMETHOD SendPushEvent(const nsACString & aOriginAttributes, const nsACString & aScope, const nsAString & aData) override; \
  NS_IMETHOD SendPushSubscriptionChangeEvent(const nsACString & aOriginAttributes, const nsACString & scope) override; \
  NS_IMETHOD UpdateAllRegistrations(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISERVICEWORKERMANAGER(_to) \
  NS_IMETHOD Register(nsIDOMWindow *aWindow, nsIURI *aScope, nsIURI *aScriptURI, nsISupports * *_retval) override { return _to Register(aWindow, aScope, aScriptURI, _retval); } \
  NS_IMETHOD Unregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope) override { return _to Unregister(aPrincipal, aCallback, aScope); } \
  NS_IMETHOD GetRegistrations(nsIDOMWindow *aWindow, nsISupports * *_retval) override { return _to GetRegistrations(aWindow, _retval); } \
  NS_IMETHOD GetRegistration(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override { return _to GetRegistration(aWindow, aScope, _retval); } \
  NS_IMETHOD GetReadyPromise(nsIDOMWindow *aWindow, nsISupports * *_retval) override { return _to GetReadyPromise(aWindow, _retval); } \
  NS_IMETHOD RemoveReadyPromise(nsIDOMWindow *aWindow) override { return _to RemoveReadyPromise(aWindow); } \
  virtual void MaybeStartControlling(nsIDocument *aDoc) override { return _to MaybeStartControlling(aDoc); } \
  virtual void MaybeStopControlling(nsIDocument *aDoc) override { return _to MaybeStopControlling(aDoc); } \
  NS_IMETHOD GetInstalling(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override { return _to GetInstalling(aWindow, aScope, _retval); } \
  NS_IMETHOD GetWaiting(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override { return _to GetWaiting(aWindow, aScope, _retval); } \
  NS_IMETHOD GetActive(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override { return _to GetActive(aWindow, aScope, _retval); } \
  NS_IMETHOD GetDocumentController(nsIDOMWindow *aWindow, nsISupports * *_retval) override { return _to GetDocumentController(aWindow, _retval); } \
  NS_IMETHOD RemoveAndPropagate(const nsACString & aHost) override { return _to RemoveAndPropagate(aHost); } \
  NS_IMETHOD GetScopeForUrl(nsIPrincipal *aPrincipal, const nsAString & aPath, nsAString & _retval) override { return _to GetScopeForUrl(aPrincipal, aPath, _retval); } \
  NS_IMETHOD GetAllRegistrations(nsIArray * *_retval) override { return _to GetAllRegistrations(_retval); } \
  NS_IMETHOD PropagateSoftUpdate(JS::HandleValue aOriginAttributes, const nsAString & aScope, JSContext* cx) override { return _to PropagateSoftUpdate(aOriginAttributes, aScope, cx); } \
  NS_IMETHOD PropagateUnregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope) override { return _to PropagateUnregister(aPrincipal, aCallback, aScope); } \
  NS_IMETHOD SendPushEvent(const nsACString & aOriginAttributes, const nsACString & aScope, const nsAString & aData) override { return _to SendPushEvent(aOriginAttributes, aScope, aData); } \
  NS_IMETHOD SendPushSubscriptionChangeEvent(const nsACString & aOriginAttributes, const nsACString & scope) override { return _to SendPushSubscriptionChangeEvent(aOriginAttributes, scope); } \
  NS_IMETHOD UpdateAllRegistrations(void) override { return _to UpdateAllRegistrations(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISERVICEWORKERMANAGER(_to) \
  NS_IMETHOD Register(nsIDOMWindow *aWindow, nsIURI *aScope, nsIURI *aScriptURI, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Register(aWindow, aScope, aScriptURI, _retval); } \
  NS_IMETHOD Unregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Unregister(aPrincipal, aCallback, aScope); } \
  NS_IMETHOD GetRegistrations(nsIDOMWindow *aWindow, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRegistrations(aWindow, _retval); } \
  NS_IMETHOD GetRegistration(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRegistration(aWindow, aScope, _retval); } \
  NS_IMETHOD GetReadyPromise(nsIDOMWindow *aWindow, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyPromise(aWindow, _retval); } \
  NS_IMETHOD RemoveReadyPromise(nsIDOMWindow *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveReadyPromise(aWindow); } \
  virtual void MaybeStartControlling(nsIDocument *aDoc) override; \
  virtual void MaybeStopControlling(nsIDocument *aDoc) override; \
  NS_IMETHOD GetInstalling(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstalling(aWindow, aScope, _retval); } \
  NS_IMETHOD GetWaiting(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWaiting(aWindow, aScope, _retval); } \
  NS_IMETHOD GetActive(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActive(aWindow, aScope, _retval); } \
  NS_IMETHOD GetDocumentController(nsIDOMWindow *aWindow, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentController(aWindow, _retval); } \
  NS_IMETHOD RemoveAndPropagate(const nsACString & aHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAndPropagate(aHost); } \
  NS_IMETHOD GetScopeForUrl(nsIPrincipal *aPrincipal, const nsAString & aPath, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScopeForUrl(aPrincipal, aPath, _retval); } \
  NS_IMETHOD GetAllRegistrations(nsIArray * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllRegistrations(_retval); } \
  NS_IMETHOD PropagateSoftUpdate(JS::HandleValue aOriginAttributes, const nsAString & aScope, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PropagateSoftUpdate(aOriginAttributes, aScope, cx); } \
  NS_IMETHOD PropagateUnregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PropagateUnregister(aPrincipal, aCallback, aScope); } \
  NS_IMETHOD SendPushEvent(const nsACString & aOriginAttributes, const nsACString & aScope, const nsAString & aData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendPushEvent(aOriginAttributes, aScope, aData); } \
  NS_IMETHOD SendPushSubscriptionChangeEvent(const nsACString & aOriginAttributes, const nsACString & scope) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendPushSubscriptionChangeEvent(aOriginAttributes, scope); } \
  NS_IMETHOD UpdateAllRegistrations(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateAllRegistrations(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsServiceWorkerManager : public nsIServiceWorkerManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISERVICEWORKERMANAGER

  nsServiceWorkerManager();

private:
  ~nsServiceWorkerManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsServiceWorkerManager, nsIServiceWorkerManager)

nsServiceWorkerManager::nsServiceWorkerManager()
{
  /* member initializers and constructor code */
}

nsServiceWorkerManager::~nsServiceWorkerManager()
{
  /* destructor code */
}

/* nsISupports register (in nsIDOMWindow aWindow, in nsIURI aScope, in nsIURI aScriptURI); */
NS_IMETHODIMP nsServiceWorkerManager::Register(nsIDOMWindow *aWindow, nsIURI *aScope, nsIURI *aScriptURI, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregister (in nsIPrincipal aPrincipal, in nsIServiceWorkerUnregisterCallback aCallback, in DOMString aScope); */
NS_IMETHODIMP nsServiceWorkerManager::Unregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getRegistrations (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsServiceWorkerManager::GetRegistrations(nsIDOMWindow *aWindow, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getRegistration (in nsIDOMWindow aWindow, in DOMString aScope); */
NS_IMETHODIMP nsServiceWorkerManager::GetRegistration(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getReadyPromise (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsServiceWorkerManager::GetReadyPromise(nsIDOMWindow *aWindow, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeReadyPromise (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsServiceWorkerManager::RemoveReadyPromise(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [nostdcall,notxpcom] void MaybeStartControlling (in nsIDocument aDoc); */
void nsServiceWorkerManager::MaybeStartControlling(nsIDocument *aDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [nostdcall,notxpcom] void MaybeStopControlling (in nsIDocument aDoc); */
void nsServiceWorkerManager::MaybeStopControlling(nsIDocument *aDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsISupports GetInstalling (in nsIDOMWindow aWindow, in DOMString aScope); */
NS_IMETHODIMP nsServiceWorkerManager::GetInstalling(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsISupports GetWaiting (in nsIDOMWindow aWindow, in DOMString aScope); */
NS_IMETHODIMP nsServiceWorkerManager::GetWaiting(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsISupports GetActive (in nsIDOMWindow aWindow, in DOMString aScope); */
NS_IMETHODIMP nsServiceWorkerManager::GetActive(nsIDOMWindow *aWindow, const nsAString & aScope, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsISupports GetDocumentController (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsServiceWorkerManager::GetDocumentController(nsIDOMWindow *aWindow, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAndPropagate (in AUTF8String aHost); */
NS_IMETHODIMP nsServiceWorkerManager::RemoveAndPropagate(const nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getScopeForUrl (in nsIPrincipal aPrincipal, in DOMString aPath); */
NS_IMETHODIMP nsServiceWorkerManager::GetScopeForUrl(nsIPrincipal *aPrincipal, const nsAString & aPath, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getAllRegistrations (); */
NS_IMETHODIMP nsServiceWorkerManager::GetAllRegistrations(nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void propagateSoftUpdate (in jsval aOriginAttributes, in DOMString aScope); */
NS_IMETHODIMP nsServiceWorkerManager::PropagateSoftUpdate(JS::HandleValue aOriginAttributes, const nsAString & aScope, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void propagateUnregister (in nsIPrincipal aPrincipal, in nsIServiceWorkerUnregisterCallback aCallback, in DOMString aScope); */
NS_IMETHODIMP nsServiceWorkerManager::PropagateUnregister(nsIPrincipal *aPrincipal, nsIServiceWorkerUnregisterCallback *aCallback, const nsAString & aScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendPushEvent (in ACString aOriginAttributes, in ACString aScope, in DOMString aData); */
NS_IMETHODIMP nsServiceWorkerManager::SendPushEvent(const nsACString & aOriginAttributes, const nsACString & aScope, const nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendPushSubscriptionChangeEvent (in ACString aOriginAttributes, in ACString scope); */
NS_IMETHODIMP nsServiceWorkerManager::SendPushSubscriptionChangeEvent(const nsACString & aOriginAttributes, const nsACString & scope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateAllRegistrations (); */
NS_IMETHODIMP nsServiceWorkerManager::UpdateAllRegistrations()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define SERVICEWORKERMANAGER_CONTRACTID "@mozilla.org/serviceworkers/manager;1"

#endif /* __gen_nsIServiceWorkerManager_h__ */
