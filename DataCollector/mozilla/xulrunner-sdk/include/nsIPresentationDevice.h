/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPresentationDevice.idl
 */

#ifndef __gen_nsIPresentationDevice_h__
#define __gen_nsIPresentationDevice_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPresentationControlChannel; /* forward declaration */

class nsIPresentationDevice; /* forward declaration */


/* starting interface:    nsIPresentationDeviceEventListener */
#define NS_IPRESENTATIONDEVICEEVENTLISTENER_IID_STR "81984458-b9d1-4731-a26a-ba62ab339aac"

#define NS_IPRESENTATIONDEVICEEVENTLISTENER_IID \
  {0x81984458, 0xb9d1, 0x4731, \
    { 0xa2, 0x6a, 0xba, 0x62, 0xab, 0x33, 0x9a, 0xac }}

class NS_NO_VTABLE nsIPresentationDeviceEventListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRESENTATIONDEVICEEVENTLISTENER_IID)

  /* void onSessionRequest (in nsIPresentationDevice device, in DOMString url, in DOMString presentationId, in nsIPresentationControlChannel controlChannel); */
  NS_IMETHOD OnSessionRequest(nsIPresentationDevice *device, const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel *controlChannel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPresentationDeviceEventListener, NS_IPRESENTATIONDEVICEEVENTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRESENTATIONDEVICEEVENTLISTENER \
  NS_IMETHOD OnSessionRequest(nsIPresentationDevice *device, const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel *controlChannel) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRESENTATIONDEVICEEVENTLISTENER(_to) \
  NS_IMETHOD OnSessionRequest(nsIPresentationDevice *device, const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel *controlChannel) override { return _to OnSessionRequest(device, url, presentationId, controlChannel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRESENTATIONDEVICEEVENTLISTENER(_to) \
  NS_IMETHOD OnSessionRequest(nsIPresentationDevice *device, const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel *controlChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSessionRequest(device, url, presentationId, controlChannel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPresentationDeviceEventListener : public nsIPresentationDeviceEventListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRESENTATIONDEVICEEVENTLISTENER

  nsPresentationDeviceEventListener();

private:
  ~nsPresentationDeviceEventListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPresentationDeviceEventListener, nsIPresentationDeviceEventListener)

nsPresentationDeviceEventListener::nsPresentationDeviceEventListener()
{
  /* member initializers and constructor code */
}

nsPresentationDeviceEventListener::~nsPresentationDeviceEventListener()
{
  /* destructor code */
}

/* void onSessionRequest (in nsIPresentationDevice device, in DOMString url, in DOMString presentationId, in nsIPresentationControlChannel controlChannel); */
NS_IMETHODIMP nsPresentationDeviceEventListener::OnSessionRequest(nsIPresentationDevice *device, const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel *controlChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPresentationDevice */
#define NS_IPRESENTATIONDEVICE_IID_STR "7fac99d4-9b19-4b8d-b5cd-5da8adbe58f1"

#define NS_IPRESENTATIONDEVICE_IID \
  {0x7fac99d4, 0x9b19, 0x4b8d, \
    { 0xb5, 0xcd, 0x5d, 0xa8, 0xad, 0xbe, 0x58, 0xf1 }}

class NS_NO_VTABLE nsIPresentationDevice : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRESENTATIONDEVICE_IID)

  /* readonly attribute AUTF8String id; */
  NS_IMETHOD GetId(nsACString & aId) = 0;

  /* readonly attribute AUTF8String name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute AUTF8String type; */
  NS_IMETHOD GetType(nsACString & aType) = 0;

  /* attribute nsIPresentationDeviceEventListener listener; */
  NS_IMETHOD GetListener(nsIPresentationDeviceEventListener * *aListener) = 0;
  NS_IMETHOD SetListener(nsIPresentationDeviceEventListener *aListener) = 0;

  /* nsIPresentationControlChannel establishControlChannel (in DOMString url, in DOMString presentationId); */
  NS_IMETHOD EstablishControlChannel(const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPresentationDevice, NS_IPRESENTATIONDEVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRESENTATIONDEVICE \
  NS_IMETHOD GetId(nsACString & aId) override; \
  NS_IMETHOD GetName(nsACString & aName) override; \
  NS_IMETHOD GetType(nsACString & aType) override; \
  NS_IMETHOD GetListener(nsIPresentationDeviceEventListener * *aListener) override; \
  NS_IMETHOD SetListener(nsIPresentationDeviceEventListener *aListener) override; \
  NS_IMETHOD EstablishControlChannel(const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRESENTATIONDEVICE(_to) \
  NS_IMETHOD GetId(nsACString & aId) override { return _to GetId(aId); } \
  NS_IMETHOD GetName(nsACString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetType(nsACString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetListener(nsIPresentationDeviceEventListener * *aListener) override { return _to GetListener(aListener); } \
  NS_IMETHOD SetListener(nsIPresentationDeviceEventListener *aListener) override { return _to SetListener(aListener); } \
  NS_IMETHOD EstablishControlChannel(const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel * *_retval) override { return _to EstablishControlChannel(url, presentationId, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRESENTATIONDEVICE(_to) \
  NS_IMETHOD GetId(nsACString & aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetName(nsACString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetType(nsACString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetListener(nsIPresentationDeviceEventListener * *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListener(aListener); } \
  NS_IMETHOD SetListener(nsIPresentationDeviceEventListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetListener(aListener); } \
  NS_IMETHOD EstablishControlChannel(const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EstablishControlChannel(url, presentationId, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPresentationDevice : public nsIPresentationDevice
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRESENTATIONDEVICE

  nsPresentationDevice();

private:
  ~nsPresentationDevice();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPresentationDevice, nsIPresentationDevice)

nsPresentationDevice::nsPresentationDevice()
{
  /* member initializers and constructor code */
}

nsPresentationDevice::~nsPresentationDevice()
{
  /* destructor code */
}

/* readonly attribute AUTF8String id; */
NS_IMETHODIMP nsPresentationDevice::GetId(nsACString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsPresentationDevice::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String type; */
NS_IMETHODIMP nsPresentationDevice::GetType(nsACString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIPresentationDeviceEventListener listener; */
NS_IMETHODIMP nsPresentationDevice::GetListener(nsIPresentationDeviceEventListener * *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPresentationDevice::SetListener(nsIPresentationDeviceEventListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPresentationControlChannel establishControlChannel (in DOMString url, in DOMString presentationId); */
NS_IMETHODIMP nsPresentationDevice::EstablishControlChannel(const nsAString & url, const nsAString & presentationId, nsIPresentationControlChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPresentationDevice_h__ */
