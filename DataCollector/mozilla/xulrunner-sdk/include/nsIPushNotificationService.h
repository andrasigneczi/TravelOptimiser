/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPushNotificationService.idl
 */

#ifndef __gen_nsIPushNotificationService_h__
#define __gen_nsIPushNotificationService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPushNotificationService */
#define NS_IPUSHNOTIFICATIONSERVICE_IID_STR "abde228b-7d14-4cab-b1f9-9f87750ede0f"

#define NS_IPUSHNOTIFICATIONSERVICE_IID \
  {0xabde228b, 0x7d14, 0x4cab, \
    { 0xb1, 0xf9, 0x9f, 0x87, 0x75, 0x0e, 0xde, 0x0f }}

class NS_NO_VTABLE nsIPushNotificationService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPUSHNOTIFICATIONSERVICE_IID)

  /* jsval register (in string scope, in jsval originAttributes); */
  NS_IMETHOD Register(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) = 0;

  /* jsval unregister (in string scope, in jsval originAttributes); */
  NS_IMETHOD Unregister(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) = 0;

  /* jsval registration (in string scope, in jsval originAttributes); */
  NS_IMETHOD Registration(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) = 0;

  /* jsval clearAll (); */
  NS_IMETHOD ClearAll(JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPushNotificationService, NS_IPUSHNOTIFICATIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPUSHNOTIFICATIONSERVICE \
  NS_IMETHOD Register(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD Unregister(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD Registration(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD ClearAll(JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPUSHNOTIFICATIONSERVICE(_to) \
  NS_IMETHOD Register(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) override { return _to Register(scope, originAttributes, _retval); } \
  NS_IMETHOD Unregister(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) override { return _to Unregister(scope, originAttributes, _retval); } \
  NS_IMETHOD Registration(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) override { return _to Registration(scope, originAttributes, _retval); } \
  NS_IMETHOD ClearAll(JS::MutableHandleValue _retval) override { return _to ClearAll(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPUSHNOTIFICATIONSERVICE(_to) \
  NS_IMETHOD Register(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Register(scope, originAttributes, _retval); } \
  NS_IMETHOD Unregister(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Unregister(scope, originAttributes, _retval); } \
  NS_IMETHOD Registration(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Registration(scope, originAttributes, _retval); } \
  NS_IMETHOD ClearAll(JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearAll(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPushNotificationService : public nsIPushNotificationService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPUSHNOTIFICATIONSERVICE

  nsPushNotificationService();

private:
  ~nsPushNotificationService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPushNotificationService, nsIPushNotificationService)

nsPushNotificationService::nsPushNotificationService()
{
  /* member initializers and constructor code */
}

nsPushNotificationService::~nsPushNotificationService()
{
  /* destructor code */
}

/* jsval register (in string scope, in jsval originAttributes); */
NS_IMETHODIMP nsPushNotificationService::Register(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval unregister (in string scope, in jsval originAttributes); */
NS_IMETHODIMP nsPushNotificationService::Unregister(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval registration (in string scope, in jsval originAttributes); */
NS_IMETHODIMP nsPushNotificationService::Registration(const char * scope, JS::HandleValue originAttributes, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval clearAll (); */
NS_IMETHODIMP nsPushNotificationService::ClearAll(JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPushNotificationService_h__ */
