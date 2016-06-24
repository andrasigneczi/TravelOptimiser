/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMNavigatorUserMedia.idl
 */

#ifndef __gen_nsIDOMNavigatorUserMedia_h__
#define __gen_nsIDOMNavigatorUserMedia_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMediaDevice */
#define NS_IMEDIADEVICE_IID_STR "cebcefca-2de1-460d-b253-d0582c50b40f"

#define NS_IMEDIADEVICE_IID \
  {0xcebcefca, 0x2de1, 0x460d, \
    { 0xb2, 0x53, 0xd0, 0x58, 0x2c, 0x50, 0xb4, 0x0f }}

class NS_NO_VTABLE nsIMediaDevice : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEDIADEVICE_IID)

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;

  /* readonly attribute DOMString mediaSource; */
  NS_IMETHOD GetMediaSource(nsAString & aMediaSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMediaDevice, NS_IMEDIADEVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEDIADEVICE \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD GetId(nsAString & aId) override; \
  NS_IMETHOD GetMediaSource(nsAString & aMediaSource) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEDIADEVICE(_to) \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetId(nsAString & aId) override { return _to GetId(aId); } \
  NS_IMETHOD GetMediaSource(nsAString & aMediaSource) override { return _to GetMediaSource(aMediaSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEDIADEVICE(_to) \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetId(nsAString & aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetMediaSource(nsAString & aMediaSource) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMediaSource(aMediaSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMediaDevice : public nsIMediaDevice
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEDIADEVICE

  nsMediaDevice();

private:
  ~nsMediaDevice();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMediaDevice, nsIMediaDevice)

nsMediaDevice::nsMediaDevice()
{
  /* member initializers and constructor code */
}

nsMediaDevice::~nsMediaDevice()
{
  /* destructor code */
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsMediaDevice::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsMediaDevice::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString id; */
NS_IMETHODIMP nsMediaDevice::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mediaSource; */
NS_IMETHODIMP nsMediaDevice::GetMediaSource(nsAString & aMediaSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIGetUserMediaDevicesSuccessCallback */
#define NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID_STR "24544878-d35e-4962-8c5f-fb84e97bdfee"

#define NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID \
  {0x24544878, 0xd35e, 0x4962, \
    { 0x8c, 0x5f, 0xfb, 0x84, 0xe9, 0x7b, 0xdf, 0xee }}

class NS_NO_VTABLE nsIGetUserMediaDevicesSuccessCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID)

  /* void onSuccess (in nsIVariant devices); */
  NS_IMETHOD OnSuccess(nsIVariant *devices) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGetUserMediaDevicesSuccessCallback, NS_IGETUSERMEDIADEVICESSUCCESSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK \
  NS_IMETHOD OnSuccess(nsIVariant *devices) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsIVariant *devices) override { return _to OnSuccess(devices); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsIVariant *devices) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSuccess(devices); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGetUserMediaDevicesSuccessCallback : public nsIGetUserMediaDevicesSuccessCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGETUSERMEDIADEVICESSUCCESSCALLBACK

  nsGetUserMediaDevicesSuccessCallback();

private:
  ~nsGetUserMediaDevicesSuccessCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsGetUserMediaDevicesSuccessCallback, nsIGetUserMediaDevicesSuccessCallback)

nsGetUserMediaDevicesSuccessCallback::nsGetUserMediaDevicesSuccessCallback()
{
  /* member initializers and constructor code */
}

nsGetUserMediaDevicesSuccessCallback::~nsGetUserMediaDevicesSuccessCallback()
{
  /* destructor code */
}

/* void onSuccess (in nsIVariant devices); */
NS_IMETHODIMP nsGetUserMediaDevicesSuccessCallback::OnSuccess(nsIVariant *devices)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMGetUserMediaSuccessCallback */
#define NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID_STR "f2a144fc-3534-4761-8c5d-989ae720f89a"

#define NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID \
  {0xf2a144fc, 0x3534, 0x4761, \
    { 0x8c, 0x5d, 0x98, 0x9a, 0xe7, 0x20, 0xf8, 0x9a }}

class NS_NO_VTABLE nsIDOMGetUserMediaSuccessCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID)

  /* void onSuccess (in nsISupports value); */
  NS_IMETHOD OnSuccess(nsISupports *value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGetUserMediaSuccessCallback, NS_IDOMGETUSERMEDIASUCCESSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGETUSERMEDIASUCCESSCALLBACK \
  NS_IMETHOD OnSuccess(nsISupports *value) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGETUSERMEDIASUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsISupports *value) override { return _to OnSuccess(value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGETUSERMEDIASUCCESSCALLBACK(_to) \
  NS_IMETHOD OnSuccess(nsISupports *value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSuccess(value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGetUserMediaSuccessCallback : public nsIDOMGetUserMediaSuccessCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGETUSERMEDIASUCCESSCALLBACK

  nsDOMGetUserMediaSuccessCallback();

private:
  ~nsDOMGetUserMediaSuccessCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMGetUserMediaSuccessCallback, nsIDOMGetUserMediaSuccessCallback)

nsDOMGetUserMediaSuccessCallback::nsDOMGetUserMediaSuccessCallback()
{
  /* member initializers and constructor code */
}

nsDOMGetUserMediaSuccessCallback::~nsDOMGetUserMediaSuccessCallback()
{
  /* destructor code */
}

/* void onSuccess (in nsISupports value); */
NS_IMETHODIMP nsDOMGetUserMediaSuccessCallback::OnSuccess(nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMGetUserMediaErrorCallback */
#define NS_IDOMGETUSERMEDIAERRORCALLBACK_IID_STR "39e96c61-2636-4f0e-918e-9bb64276492a"

#define NS_IDOMGETUSERMEDIAERRORCALLBACK_IID \
  {0x39e96c61, 0x2636, 0x4f0e, \
    { 0x91, 0x8e, 0x9b, 0xb6, 0x42, 0x76, 0x49, 0x2a }}

class NS_NO_VTABLE nsIDOMGetUserMediaErrorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGETUSERMEDIAERRORCALLBACK_IID)

  /* void onError (in nsISupports error); */
  NS_IMETHOD OnError(nsISupports *error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGetUserMediaErrorCallback, NS_IDOMGETUSERMEDIAERRORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGETUSERMEDIAERRORCALLBACK \
  NS_IMETHOD OnError(nsISupports *error) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGETUSERMEDIAERRORCALLBACK(_to) \
  NS_IMETHOD OnError(nsISupports *error) override { return _to OnError(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGETUSERMEDIAERRORCALLBACK(_to) \
  NS_IMETHOD OnError(nsISupports *error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnError(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGetUserMediaErrorCallback : public nsIDOMGetUserMediaErrorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGETUSERMEDIAERRORCALLBACK

  nsDOMGetUserMediaErrorCallback();

private:
  ~nsDOMGetUserMediaErrorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMGetUserMediaErrorCallback, nsIDOMGetUserMediaErrorCallback)

nsDOMGetUserMediaErrorCallback::nsDOMGetUserMediaErrorCallback()
{
  /* member initializers and constructor code */
}

nsDOMGetUserMediaErrorCallback::~nsDOMGetUserMediaErrorCallback()
{
  /* destructor code */
}

/* void onError (in nsISupports error); */
NS_IMETHODIMP nsDOMGetUserMediaErrorCallback::OnError(nsISupports *error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorUserMedia_h__ */
