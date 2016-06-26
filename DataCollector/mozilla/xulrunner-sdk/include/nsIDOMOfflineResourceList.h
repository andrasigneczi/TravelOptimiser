/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMOfflineResourceList.idl
 */

#ifndef __gen_nsIDOMOfflineResourceList_h__
#define __gen_nsIDOMOfflineResourceList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMOfflineResourceList */
#define NS_IDOMOFFLINERESOURCELIST_IID_STR "6044702d-e4a9-420c-b711-558b7d6a3b9f"

#define NS_IDOMOFFLINERESOURCELIST_IID \
  {0x6044702d, 0xe4a9, 0x420c, \
    { 0xb7, 0x11, 0x55, 0x8b, 0x7d, 0x6a, 0x3b, 0x9f }}

class NS_NO_VTABLE nsIDOMOfflineResourceList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMOFFLINERESOURCELIST_IID)

  /* readonly attribute nsISupports mozItems; */
  NS_IMETHOD GetMozItems(nsISupports * *aMozItems) = 0;

  /* boolean mozHasItem (in DOMString uri); */
  NS_IMETHOD MozHasItem(const nsAString & uri, bool *_retval) = 0;

  /* readonly attribute unsigned long mozLength; */
  NS_IMETHOD GetMozLength(uint32_t *aMozLength) = 0;

  /* DOMString mozItem (in unsigned long index); */
  NS_IMETHOD MozItem(uint32_t index, nsAString & _retval) = 0;

  /* void mozAdd (in DOMString uri); */
  NS_IMETHOD MozAdd(const nsAString & uri) = 0;

  /* void mozRemove (in DOMString uri); */
  NS_IMETHOD MozRemove(const nsAString & uri) = 0;

  enum {
    UNCACHED = 0U,
    IDLE = 1U,
    CHECKING = 2U,
    DOWNLOADING = 3U,
    UPDATEREADY = 4U,
    OBSOLETE = 5U
  };

  /* readonly attribute unsigned short status; */
  NS_IMETHOD GetStatus(uint16_t *aStatus) = 0;

  /* void update (); */
  NS_IMETHOD Update(void) = 0;

  /* void swapCache (); */
  NS_IMETHOD SwapCache(void) = 0;

  /* [implicit_jscontext] attribute jsval onchecking; */
  NS_IMETHOD GetOnchecking(JSContext* cx, JS::MutableHandleValue aOnchecking) = 0;
  NS_IMETHOD SetOnchecking(JSContext* cx, JS::HandleValue aOnchecking) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) = 0;

  /* [implicit_jscontext] attribute jsval onnoupdate; */
  NS_IMETHOD GetOnnoupdate(JSContext* cx, JS::MutableHandleValue aOnnoupdate) = 0;
  NS_IMETHOD SetOnnoupdate(JSContext* cx, JS::HandleValue aOnnoupdate) = 0;

  /* [implicit_jscontext] attribute jsval ondownloading; */
  NS_IMETHOD GetOndownloading(JSContext* cx, JS::MutableHandleValue aOndownloading) = 0;
  NS_IMETHOD SetOndownloading(JSContext* cx, JS::HandleValue aOndownloading) = 0;

  /* [implicit_jscontext] attribute jsval onprogress; */
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress) = 0;
  NS_IMETHOD SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress) = 0;

  /* [implicit_jscontext] attribute jsval onupdateready; */
  NS_IMETHOD GetOnupdateready(JSContext* cx, JS::MutableHandleValue aOnupdateready) = 0;
  NS_IMETHOD SetOnupdateready(JSContext* cx, JS::HandleValue aOnupdateready) = 0;

  /* [implicit_jscontext] attribute jsval oncached; */
  NS_IMETHOD GetOncached(JSContext* cx, JS::MutableHandleValue aOncached) = 0;
  NS_IMETHOD SetOncached(JSContext* cx, JS::HandleValue aOncached) = 0;

  /* [implicit_jscontext] attribute jsval onobsolete; */
  NS_IMETHOD GetOnobsolete(JSContext* cx, JS::MutableHandleValue aOnobsolete) = 0;
  NS_IMETHOD SetOnobsolete(JSContext* cx, JS::HandleValue aOnobsolete) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMOfflineResourceList, NS_IDOMOFFLINERESOURCELIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMOFFLINERESOURCELIST \
  NS_IMETHOD GetMozItems(nsISupports * *aMozItems) override; \
  NS_IMETHOD MozHasItem(const nsAString & uri, bool *_retval) override; \
  NS_IMETHOD GetMozLength(uint32_t *aMozLength) override; \
  NS_IMETHOD MozItem(uint32_t index, nsAString & _retval) override; \
  NS_IMETHOD MozAdd(const nsAString & uri) override; \
  NS_IMETHOD MozRemove(const nsAString & uri) override; \
  NS_IMETHOD GetStatus(uint16_t *aStatus) override; \
  NS_IMETHOD Update(void) override; \
  NS_IMETHOD SwapCache(void) override; \
  NS_IMETHOD GetOnchecking(JSContext* cx, JS::MutableHandleValue aOnchecking) override; \
  NS_IMETHOD SetOnchecking(JSContext* cx, JS::HandleValue aOnchecking) override; \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) override; \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) override; \
  NS_IMETHOD GetOnnoupdate(JSContext* cx, JS::MutableHandleValue aOnnoupdate) override; \
  NS_IMETHOD SetOnnoupdate(JSContext* cx, JS::HandleValue aOnnoupdate) override; \
  NS_IMETHOD GetOndownloading(JSContext* cx, JS::MutableHandleValue aOndownloading) override; \
  NS_IMETHOD SetOndownloading(JSContext* cx, JS::HandleValue aOndownloading) override; \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress) override; \
  NS_IMETHOD SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress) override; \
  NS_IMETHOD GetOnupdateready(JSContext* cx, JS::MutableHandleValue aOnupdateready) override; \
  NS_IMETHOD SetOnupdateready(JSContext* cx, JS::HandleValue aOnupdateready) override; \
  NS_IMETHOD GetOncached(JSContext* cx, JS::MutableHandleValue aOncached) override; \
  NS_IMETHOD SetOncached(JSContext* cx, JS::HandleValue aOncached) override; \
  NS_IMETHOD GetOnobsolete(JSContext* cx, JS::MutableHandleValue aOnobsolete) override; \
  NS_IMETHOD SetOnobsolete(JSContext* cx, JS::HandleValue aOnobsolete) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMOFFLINERESOURCELIST(_to) \
  NS_IMETHOD GetMozItems(nsISupports * *aMozItems) override { return _to GetMozItems(aMozItems); } \
  NS_IMETHOD MozHasItem(const nsAString & uri, bool *_retval) override { return _to MozHasItem(uri, _retval); } \
  NS_IMETHOD GetMozLength(uint32_t *aMozLength) override { return _to GetMozLength(aMozLength); } \
  NS_IMETHOD MozItem(uint32_t index, nsAString & _retval) override { return _to MozItem(index, _retval); } \
  NS_IMETHOD MozAdd(const nsAString & uri) override { return _to MozAdd(uri); } \
  NS_IMETHOD MozRemove(const nsAString & uri) override { return _to MozRemove(uri); } \
  NS_IMETHOD GetStatus(uint16_t *aStatus) override { return _to GetStatus(aStatus); } \
  NS_IMETHOD Update(void) override { return _to Update(); } \
  NS_IMETHOD SwapCache(void) override { return _to SwapCache(); } \
  NS_IMETHOD GetOnchecking(JSContext* cx, JS::MutableHandleValue aOnchecking) override { return _to GetOnchecking(cx, aOnchecking); } \
  NS_IMETHOD SetOnchecking(JSContext* cx, JS::HandleValue aOnchecking) override { return _to SetOnchecking(cx, aOnchecking); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) override { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) override { return _to SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnnoupdate(JSContext* cx, JS::MutableHandleValue aOnnoupdate) override { return _to GetOnnoupdate(cx, aOnnoupdate); } \
  NS_IMETHOD SetOnnoupdate(JSContext* cx, JS::HandleValue aOnnoupdate) override { return _to SetOnnoupdate(cx, aOnnoupdate); } \
  NS_IMETHOD GetOndownloading(JSContext* cx, JS::MutableHandleValue aOndownloading) override { return _to GetOndownloading(cx, aOndownloading); } \
  NS_IMETHOD SetOndownloading(JSContext* cx, JS::HandleValue aOndownloading) override { return _to SetOndownloading(cx, aOndownloading); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress) override { return _to GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress) override { return _to SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnupdateready(JSContext* cx, JS::MutableHandleValue aOnupdateready) override { return _to GetOnupdateready(cx, aOnupdateready); } \
  NS_IMETHOD SetOnupdateready(JSContext* cx, JS::HandleValue aOnupdateready) override { return _to SetOnupdateready(cx, aOnupdateready); } \
  NS_IMETHOD GetOncached(JSContext* cx, JS::MutableHandleValue aOncached) override { return _to GetOncached(cx, aOncached); } \
  NS_IMETHOD SetOncached(JSContext* cx, JS::HandleValue aOncached) override { return _to SetOncached(cx, aOncached); } \
  NS_IMETHOD GetOnobsolete(JSContext* cx, JS::MutableHandleValue aOnobsolete) override { return _to GetOnobsolete(cx, aOnobsolete); } \
  NS_IMETHOD SetOnobsolete(JSContext* cx, JS::HandleValue aOnobsolete) override { return _to SetOnobsolete(cx, aOnobsolete); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMOFFLINERESOURCELIST(_to) \
  NS_IMETHOD GetMozItems(nsISupports * *aMozItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozItems(aMozItems); } \
  NS_IMETHOD MozHasItem(const nsAString & uri, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozHasItem(uri, _retval); } \
  NS_IMETHOD GetMozLength(uint32_t *aMozLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozLength(aMozLength); } \
  NS_IMETHOD MozItem(uint32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozItem(index, _retval); } \
  NS_IMETHOD MozAdd(const nsAString & uri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozAdd(uri); } \
  NS_IMETHOD MozRemove(const nsAString & uri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRemove(uri); } \
  NS_IMETHOD GetStatus(uint16_t *aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_IMETHOD Update(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Update(); } \
  NS_IMETHOD SwapCache(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SwapCache(); } \
  NS_IMETHOD GetOnchecking(JSContext* cx, JS::MutableHandleValue aOnchecking) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchecking(cx, aOnchecking); } \
  NS_IMETHOD SetOnchecking(JSContext* cx, JS::HandleValue aOnchecking) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchecking(cx, aOnchecking); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnnoupdate(JSContext* cx, JS::MutableHandleValue aOnnoupdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnnoupdate(cx, aOnnoupdate); } \
  NS_IMETHOD SetOnnoupdate(JSContext* cx, JS::HandleValue aOnnoupdate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnnoupdate(cx, aOnnoupdate); } \
  NS_IMETHOD GetOndownloading(JSContext* cx, JS::MutableHandleValue aOndownloading) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndownloading(cx, aOndownloading); } \
  NS_IMETHOD SetOndownloading(JSContext* cx, JS::HandleValue aOndownloading) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndownloading(cx, aOndownloading); } \
  NS_IMETHOD GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnprogress(cx, aOnprogress); } \
  NS_IMETHOD GetOnupdateready(JSContext* cx, JS::MutableHandleValue aOnupdateready) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnupdateready(cx, aOnupdateready); } \
  NS_IMETHOD SetOnupdateready(JSContext* cx, JS::HandleValue aOnupdateready) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnupdateready(cx, aOnupdateready); } \
  NS_IMETHOD GetOncached(JSContext* cx, JS::MutableHandleValue aOncached) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncached(cx, aOncached); } \
  NS_IMETHOD SetOncached(JSContext* cx, JS::HandleValue aOncached) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncached(cx, aOncached); } \
  NS_IMETHOD GetOnobsolete(JSContext* cx, JS::MutableHandleValue aOnobsolete) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnobsolete(cx, aOnobsolete); } \
  NS_IMETHOD SetOnobsolete(JSContext* cx, JS::HandleValue aOnobsolete) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnobsolete(cx, aOnobsolete); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMOfflineResourceList : public nsIDOMOfflineResourceList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMOFFLINERESOURCELIST

  nsDOMOfflineResourceList();

private:
  ~nsDOMOfflineResourceList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMOfflineResourceList, nsIDOMOfflineResourceList)

nsDOMOfflineResourceList::nsDOMOfflineResourceList()
{
  /* member initializers and constructor code */
}

nsDOMOfflineResourceList::~nsDOMOfflineResourceList()
{
  /* destructor code */
}

/* readonly attribute nsISupports mozItems; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetMozItems(nsISupports * *aMozItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean mozHasItem (in DOMString uri); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozHasItem(const nsAString & uri, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozLength; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetMozLength(uint32_t *aMozLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString mozItem (in unsigned long index); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozItem(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozAdd (in DOMString uri); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozAdd(const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozRemove (in DOMString uri); */
NS_IMETHODIMP nsDOMOfflineResourceList::MozRemove(const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short status; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetStatus(uint16_t *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void update (); */
NS_IMETHODIMP nsDOMOfflineResourceList::Update()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void swapCache (); */
NS_IMETHODIMP nsDOMOfflineResourceList::SwapCache()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onchecking; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnchecking(JSContext* cx, JS::MutableHandleValue aOnchecking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnchecking(JSContext* cx, JS::HandleValue aOnchecking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnerror(JSContext* cx, JS::HandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onnoupdate; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnnoupdate(JSContext* cx, JS::MutableHandleValue aOnnoupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnnoupdate(JSContext* cx, JS::HandleValue aOnnoupdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondownloading; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOndownloading(JSContext* cx, JS::MutableHandleValue aOndownloading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOndownloading(JSContext* cx, JS::HandleValue aOndownloading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onprogress; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnprogress(JSContext* cx, JS::MutableHandleValue aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnprogress(JSContext* cx, JS::HandleValue aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onupdateready; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnupdateready(JSContext* cx, JS::MutableHandleValue aOnupdateready)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnupdateready(JSContext* cx, JS::HandleValue aOnupdateready)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval oncached; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOncached(JSContext* cx, JS::MutableHandleValue aOncached)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOncached(JSContext* cx, JS::HandleValue aOncached)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onobsolete; */
NS_IMETHODIMP nsDOMOfflineResourceList::GetOnobsolete(JSContext* cx, JS::MutableHandleValue aOnobsolete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMOfflineResourceList::SetOnobsolete(JSContext* cx, JS::HandleValue aOnobsolete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMOfflineResourceList_h__ */
