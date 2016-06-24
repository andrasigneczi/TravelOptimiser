/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAddonInterposition.idl
 */

#ifndef __gen_nsIAddonInterposition_h__
#define __gen_nsIAddonInterposition_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAddonInterposition */
#define NS_IADDONINTERPOSITION_IID_STR "d05cc5fd-ad88-41a6-854c-36fd94d69ddb"

#define NS_IADDONINTERPOSITION_IID \
  {0xd05cc5fd, 0xad88, 0x41a6, \
    { 0x85, 0x4c, 0x36, 0xfd, 0x94, 0xd6, 0x9d, 0xdb }}

class NS_NO_VTABLE nsIAddonInterposition : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IADDONINTERPOSITION_IID)

  /* jsval interposeProperty (in jsval addonId, in jsval target, in nsIIDPtr iface, in jsval prop); */
  NS_IMETHOD InterposeProperty(JS::HandleValue addonId, JS::HandleValue target, const nsIID *iface, JS::HandleValue prop, JS::MutableHandleValue _retval) = 0;

  /* jsval interposeCall (in jsval addonId, in jsval originalFunc, in jsval originalThis, in jsval args); */
  NS_IMETHOD InterposeCall(JS::HandleValue addonId, JS::HandleValue originalFunc, JS::HandleValue originalThis, JS::HandleValue args, JS::MutableHandleValue _retval) = 0;

  /* jsval getWhitelist (); */
  NS_IMETHOD GetWhitelist(JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAddonInterposition, NS_IADDONINTERPOSITION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIADDONINTERPOSITION \
  NS_IMETHOD InterposeProperty(JS::HandleValue addonId, JS::HandleValue target, const nsIID *iface, JS::HandleValue prop, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD InterposeCall(JS::HandleValue addonId, JS::HandleValue originalFunc, JS::HandleValue originalThis, JS::HandleValue args, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetWhitelist(JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIADDONINTERPOSITION(_to) \
  NS_IMETHOD InterposeProperty(JS::HandleValue addonId, JS::HandleValue target, const nsIID *iface, JS::HandleValue prop, JS::MutableHandleValue _retval) override { return _to InterposeProperty(addonId, target, iface, prop, _retval); } \
  NS_IMETHOD InterposeCall(JS::HandleValue addonId, JS::HandleValue originalFunc, JS::HandleValue originalThis, JS::HandleValue args, JS::MutableHandleValue _retval) override { return _to InterposeCall(addonId, originalFunc, originalThis, args, _retval); } \
  NS_IMETHOD GetWhitelist(JS::MutableHandleValue _retval) override { return _to GetWhitelist(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIADDONINTERPOSITION(_to) \
  NS_IMETHOD InterposeProperty(JS::HandleValue addonId, JS::HandleValue target, const nsIID *iface, JS::HandleValue prop, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InterposeProperty(addonId, target, iface, prop, _retval); } \
  NS_IMETHOD InterposeCall(JS::HandleValue addonId, JS::HandleValue originalFunc, JS::HandleValue originalThis, JS::HandleValue args, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InterposeCall(addonId, originalFunc, originalThis, args, _retval); } \
  NS_IMETHOD GetWhitelist(JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhitelist(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAddonInterposition : public nsIAddonInterposition
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIADDONINTERPOSITION

  nsAddonInterposition();

private:
  ~nsAddonInterposition();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAddonInterposition, nsIAddonInterposition)

nsAddonInterposition::nsAddonInterposition()
{
  /* member initializers and constructor code */
}

nsAddonInterposition::~nsAddonInterposition()
{
  /* destructor code */
}

/* jsval interposeProperty (in jsval addonId, in jsval target, in nsIIDPtr iface, in jsval prop); */
NS_IMETHODIMP nsAddonInterposition::InterposeProperty(JS::HandleValue addonId, JS::HandleValue target, const nsIID *iface, JS::HandleValue prop, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval interposeCall (in jsval addonId, in jsval originalFunc, in jsval originalThis, in jsval args); */
NS_IMETHODIMP nsAddonInterposition::InterposeCall(JS::HandleValue addonId, JS::HandleValue originalFunc, JS::HandleValue originalThis, JS::HandleValue args, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval getWhitelist (); */
NS_IMETHODIMP nsAddonInterposition::GetWhitelist(JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAddonInterposition_h__ */
