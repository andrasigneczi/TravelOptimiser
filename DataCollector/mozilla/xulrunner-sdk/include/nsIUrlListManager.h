/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUrlListManager.idl
 */

#ifndef __gen_nsIUrlListManager_h__
#define __gen_nsIUrlListManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIUrlListManagerCallback */
#define NS_IURLLISTMANAGERCALLBACK_IID_STR "fa4caf12-d057-4e7e-81e9-ce066ceee90b"

#define NS_IURLLISTMANAGERCALLBACK_IID \
  {0xfa4caf12, 0xd057, 0x4e7e, \
    { 0x81, 0xe9, 0xce, 0x06, 0x6c, 0xee, 0xe9, 0x0b }}

class NS_NO_VTABLE nsIUrlListManagerCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLLISTMANAGERCALLBACK_IID)

  /* void handleEvent (in ACString value); */
  NS_IMETHOD HandleEvent(const nsACString & value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlListManagerCallback, NS_IURLLISTMANAGERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLLISTMANAGERCALLBACK \
  NS_IMETHOD HandleEvent(const nsACString & value) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLLISTMANAGERCALLBACK(_to) \
  NS_IMETHOD HandleEvent(const nsACString & value) override { return _to HandleEvent(value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLLISTMANAGERCALLBACK(_to) \
  NS_IMETHOD HandleEvent(const nsACString & value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlListManagerCallback : public nsIUrlListManagerCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLLISTMANAGERCALLBACK

  nsUrlListManagerCallback();

private:
  ~nsUrlListManagerCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUrlListManagerCallback, nsIUrlListManagerCallback)

nsUrlListManagerCallback::nsUrlListManagerCallback()
{
  /* member initializers and constructor code */
}

nsUrlListManagerCallback::~nsUrlListManagerCallback()
{
  /* destructor code */
}

/* void handleEvent (in ACString value); */
NS_IMETHODIMP nsUrlListManagerCallback::HandleEvent(const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUrlListManager */
#define NS_IURLLISTMANAGER_IID_STR "5d5ed98f-72cd-46b6-a9fe-76418adfdfeb"

#define NS_IURLLISTMANAGER_IID \
  {0x5d5ed98f, 0x72cd, 0x46b6, \
    { 0xa9, 0xfe, 0x76, 0x41, 0x8a, 0xdf, 0xdf, 0xeb }}

class NS_NO_VTABLE nsIUrlListManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLLISTMANAGER_IID)

  /* ACString getGethashUrl (in ACString tableName); */
  NS_IMETHOD GetGethashUrl(const nsACString & tableName, nsACString & _retval) = 0;

  /* boolean registerTable (in ACString tableName, in ACString updateUrl, in ACString gethashUrl); */
  NS_IMETHOD RegisterTable(const nsACString & tableName, const nsACString & updateUrl, const nsACString & gethashUrl, bool *_retval) = 0;

  /* void enableUpdate (in ACString tableName); */
  NS_IMETHOD EnableUpdate(const nsACString & tableName) = 0;

  /* void disableUpdate (in ACString tableName); */
  NS_IMETHOD DisableUpdate(const nsACString & tableName) = 0;

  /* void maybeToggleUpdateChecking (); */
  NS_IMETHOD MaybeToggleUpdateChecking(void) = 0;

  /* void safeLookup (in nsIPrincipal key, in nsIUrlListManagerCallback cb); */
  NS_IMETHOD SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlListManager, NS_IURLLISTMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLLISTMANAGER \
  NS_IMETHOD GetGethashUrl(const nsACString & tableName, nsACString & _retval) override; \
  NS_IMETHOD RegisterTable(const nsACString & tableName, const nsACString & updateUrl, const nsACString & gethashUrl, bool *_retval) override; \
  NS_IMETHOD EnableUpdate(const nsACString & tableName) override; \
  NS_IMETHOD DisableUpdate(const nsACString & tableName) override; \
  NS_IMETHOD MaybeToggleUpdateChecking(void) override; \
  NS_IMETHOD SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLLISTMANAGER(_to) \
  NS_IMETHOD GetGethashUrl(const nsACString & tableName, nsACString & _retval) override { return _to GetGethashUrl(tableName, _retval); } \
  NS_IMETHOD RegisterTable(const nsACString & tableName, const nsACString & updateUrl, const nsACString & gethashUrl, bool *_retval) override { return _to RegisterTable(tableName, updateUrl, gethashUrl, _retval); } \
  NS_IMETHOD EnableUpdate(const nsACString & tableName) override { return _to EnableUpdate(tableName); } \
  NS_IMETHOD DisableUpdate(const nsACString & tableName) override { return _to DisableUpdate(tableName); } \
  NS_IMETHOD MaybeToggleUpdateChecking(void) override { return _to MaybeToggleUpdateChecking(); } \
  NS_IMETHOD SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb) override { return _to SafeLookup(key, cb); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLLISTMANAGER(_to) \
  NS_IMETHOD GetGethashUrl(const nsACString & tableName, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGethashUrl(tableName, _retval); } \
  NS_IMETHOD RegisterTable(const nsACString & tableName, const nsACString & updateUrl, const nsACString & gethashUrl, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterTable(tableName, updateUrl, gethashUrl, _retval); } \
  NS_IMETHOD EnableUpdate(const nsACString & tableName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableUpdate(tableName); } \
  NS_IMETHOD DisableUpdate(const nsACString & tableName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableUpdate(tableName); } \
  NS_IMETHOD MaybeToggleUpdateChecking(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MaybeToggleUpdateChecking(); } \
  NS_IMETHOD SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SafeLookup(key, cb); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlListManager : public nsIUrlListManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLLISTMANAGER

  nsUrlListManager();

private:
  ~nsUrlListManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUrlListManager, nsIUrlListManager)

nsUrlListManager::nsUrlListManager()
{
  /* member initializers and constructor code */
}

nsUrlListManager::~nsUrlListManager()
{
  /* destructor code */
}

/* ACString getGethashUrl (in ACString tableName); */
NS_IMETHODIMP nsUrlListManager::GetGethashUrl(const nsACString & tableName, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean registerTable (in ACString tableName, in ACString updateUrl, in ACString gethashUrl); */
NS_IMETHODIMP nsUrlListManager::RegisterTable(const nsACString & tableName, const nsACString & updateUrl, const nsACString & gethashUrl, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableUpdate (in ACString tableName); */
NS_IMETHODIMP nsUrlListManager::EnableUpdate(const nsACString & tableName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableUpdate (in ACString tableName); */
NS_IMETHODIMP nsUrlListManager::DisableUpdate(const nsACString & tableName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void maybeToggleUpdateChecking (); */
NS_IMETHODIMP nsUrlListManager::MaybeToggleUpdateChecking()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void safeLookup (in nsIPrincipal key, in nsIUrlListManagerCallback cb); */
NS_IMETHODIMP nsUrlListManager::SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUrlListManager_h__ */
