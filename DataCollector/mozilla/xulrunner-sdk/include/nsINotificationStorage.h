/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINotificationStorage.idl
 */

#ifndef __gen_nsINotificationStorage_h__
#define __gen_nsINotificationStorage_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINotificationStorageCallback */
#define NS_INOTIFICATIONSTORAGECALLBACK_IID_STR "9f1c43b9-f01b-4c87-ad3d-1a86520c2159"

#define NS_INOTIFICATIONSTORAGECALLBACK_IID \
  {0x9f1c43b9, 0xf01b, 0x4c87, \
    { 0xad, 0x3d, 0x1a, 0x86, 0x52, 0x0c, 0x21, 0x59 }}

class NS_NO_VTABLE nsINotificationStorageCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INOTIFICATIONSTORAGECALLBACK_IID)

  /* [implicit_jscontext] void handle (in DOMString id, in DOMString title, in DOMString dir, in DOMString lang, in DOMString body, in DOMString tag, in DOMString icon, in DOMString data, in DOMString behavior); */
  NS_IMETHOD Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & data, const nsAString & behavior, JSContext* cx) = 0;

  /* [implicit_jscontext] void done (); */
  NS_IMETHOD Done(JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINotificationStorageCallback, NS_INOTIFICATIONSTORAGECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINOTIFICATIONSTORAGECALLBACK \
  NS_IMETHOD Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & data, const nsAString & behavior, JSContext* cx) override; \
  NS_IMETHOD Done(JSContext* cx) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINOTIFICATIONSTORAGECALLBACK(_to) \
  NS_IMETHOD Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & data, const nsAString & behavior, JSContext* cx) override { return _to Handle(id, title, dir, lang, body, tag, icon, data, behavior, cx); } \
  NS_IMETHOD Done(JSContext* cx) override { return _to Done(cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINOTIFICATIONSTORAGECALLBACK(_to) \
  NS_IMETHOD Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & data, const nsAString & behavior, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Handle(id, title, dir, lang, body, tag, icon, data, behavior, cx); } \
  NS_IMETHOD Done(JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Done(cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNotificationStorageCallback : public nsINotificationStorageCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINOTIFICATIONSTORAGECALLBACK

  nsNotificationStorageCallback();

private:
  ~nsNotificationStorageCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNotificationStorageCallback, nsINotificationStorageCallback)

nsNotificationStorageCallback::nsNotificationStorageCallback()
{
  /* member initializers and constructor code */
}

nsNotificationStorageCallback::~nsNotificationStorageCallback()
{
  /* destructor code */
}

/* [implicit_jscontext] void handle (in DOMString id, in DOMString title, in DOMString dir, in DOMString lang, in DOMString body, in DOMString tag, in DOMString icon, in DOMString data, in DOMString behavior); */
NS_IMETHODIMP nsNotificationStorageCallback::Handle(const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & data, const nsAString & behavior, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void done (); */
NS_IMETHODIMP nsNotificationStorageCallback::Done(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINotificationStorage */
#define NS_INOTIFICATIONSTORAGE_IID_STR "cac01fb0-c2eb-4252-b2f4-5b1fac933bd4"

#define NS_INOTIFICATIONSTORAGE_IID \
  {0xcac01fb0, 0xc2eb, 0x4252, \
    { 0xb2, 0xf4, 0x5b, 0x1f, 0xac, 0x93, 0x3b, 0xd4 }}

class NS_NO_VTABLE nsINotificationStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INOTIFICATIONSTORAGE_IID)

  /* void put (in DOMString origin, in DOMString id, in DOMString title, in DOMString dir, in DOMString lang, in DOMString body, in DOMString tag, in DOMString icon, in DOMString alertName, in DOMString data, in DOMString behavior); */
  NS_IMETHOD Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & alertName, const nsAString & data, const nsAString & behavior) = 0;

  /* void get (in DOMString origin, in DOMString tag, in nsINotificationStorageCallback aCallback); */
  NS_IMETHOD Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback) = 0;

  /* void delete (in DOMString origin, in DOMString id); */
  NS_IMETHOD Delete(const nsAString & origin, const nsAString & id) = 0;

  /* boolean canPut (in DOMString origin); */
  NS_IMETHOD CanPut(const nsAString & origin, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINotificationStorage, NS_INOTIFICATIONSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINOTIFICATIONSTORAGE \
  NS_IMETHOD Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & alertName, const nsAString & data, const nsAString & behavior) override; \
  NS_IMETHOD Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback) override; \
  NS_IMETHOD Delete(const nsAString & origin, const nsAString & id) override; \
  NS_IMETHOD CanPut(const nsAString & origin, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINOTIFICATIONSTORAGE(_to) \
  NS_IMETHOD Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & alertName, const nsAString & data, const nsAString & behavior) override { return _to Put(origin, id, title, dir, lang, body, tag, icon, alertName, data, behavior); } \
  NS_IMETHOD Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback) override { return _to Get(origin, tag, aCallback); } \
  NS_IMETHOD Delete(const nsAString & origin, const nsAString & id) override { return _to Delete(origin, id); } \
  NS_IMETHOD CanPut(const nsAString & origin, bool *_retval) override { return _to CanPut(origin, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINOTIFICATIONSTORAGE(_to) \
  NS_IMETHOD Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & alertName, const nsAString & data, const nsAString & behavior) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Put(origin, id, title, dir, lang, body, tag, icon, alertName, data, behavior); } \
  NS_IMETHOD Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(origin, tag, aCallback); } \
  NS_IMETHOD Delete(const nsAString & origin, const nsAString & id) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(origin, id); } \
  NS_IMETHOD CanPut(const nsAString & origin, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPut(origin, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNotificationStorage : public nsINotificationStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINOTIFICATIONSTORAGE

  nsNotificationStorage();

private:
  ~nsNotificationStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNotificationStorage, nsINotificationStorage)

nsNotificationStorage::nsNotificationStorage()
{
  /* member initializers and constructor code */
}

nsNotificationStorage::~nsNotificationStorage()
{
  /* destructor code */
}

/* void put (in DOMString origin, in DOMString id, in DOMString title, in DOMString dir, in DOMString lang, in DOMString body, in DOMString tag, in DOMString icon, in DOMString alertName, in DOMString data, in DOMString behavior); */
NS_IMETHODIMP nsNotificationStorage::Put(const nsAString & origin, const nsAString & id, const nsAString & title, const nsAString & dir, const nsAString & lang, const nsAString & body, const nsAString & tag, const nsAString & icon, const nsAString & alertName, const nsAString & data, const nsAString & behavior)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void get (in DOMString origin, in DOMString tag, in nsINotificationStorageCallback aCallback); */
NS_IMETHODIMP nsNotificationStorage::Get(const nsAString & origin, const nsAString & tag, nsINotificationStorageCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void delete (in DOMString origin, in DOMString id); */
NS_IMETHODIMP nsNotificationStorage::Delete(const nsAString & origin, const nsAString & id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canPut (in DOMString origin); */
NS_IMETHODIMP nsNotificationStorage::CanPut(const nsAString & origin, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_NOTIFICATION_STORAGE_CONTRACTID "@mozilla.org/notificationStorage;1"

#endif /* __gen_nsINotificationStorage_h__ */
