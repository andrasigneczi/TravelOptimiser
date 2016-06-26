/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPresentationDeviceManager.idl
 */

#ifndef __gen_nsIPresentationDeviceManager_h__
#define __gen_nsIPresentationDeviceManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIPresentationDeviceProvider; /* forward declaration */

#define PRESENTATION_DEVICE_MANAGER_CONTRACTID "@mozilla.org/presentation-device/manager;1"
#define PRESENTATION_DEVICE_CHANGE_TOPIC "presentation-device-change"

/* starting interface:    nsIPresentationDeviceManager */
#define NS_IPRESENTATIONDEVICEMANAGER_IID_STR "beb61db5-3d5f-454f-a15a-dbfa0337c569"

#define NS_IPRESENTATIONDEVICEMANAGER_IID \
  {0xbeb61db5, 0x3d5f, 0x454f, \
    { 0xa1, 0x5a, 0xdb, 0xfa, 0x03, 0x37, 0xc5, 0x69 }}

class NS_NO_VTABLE nsIPresentationDeviceManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRESENTATIONDEVICEMANAGER_IID)

  /* readonly attribute boolean deviceAvailable; */
  NS_IMETHOD GetDeviceAvailable(bool *aDeviceAvailable) = 0;

  /* void addDeviceProvider (in nsIPresentationDeviceProvider provider); */
  NS_IMETHOD AddDeviceProvider(nsIPresentationDeviceProvider *provider) = 0;

  /* void removeDeviceProvider (in nsIPresentationDeviceProvider provider); */
  NS_IMETHOD RemoveDeviceProvider(nsIPresentationDeviceProvider *provider) = 0;

  /* void forceDiscovery (); */
  NS_IMETHOD ForceDiscovery(void) = 0;

  /* nsIArray getAvailableDevices (); */
  NS_IMETHOD GetAvailableDevices(nsIArray * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPresentationDeviceManager, NS_IPRESENTATIONDEVICEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRESENTATIONDEVICEMANAGER \
  NS_IMETHOD GetDeviceAvailable(bool *aDeviceAvailable) override; \
  NS_IMETHOD AddDeviceProvider(nsIPresentationDeviceProvider *provider) override; \
  NS_IMETHOD RemoveDeviceProvider(nsIPresentationDeviceProvider *provider) override; \
  NS_IMETHOD ForceDiscovery(void) override; \
  NS_IMETHOD GetAvailableDevices(nsIArray * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRESENTATIONDEVICEMANAGER(_to) \
  NS_IMETHOD GetDeviceAvailable(bool *aDeviceAvailable) override { return _to GetDeviceAvailable(aDeviceAvailable); } \
  NS_IMETHOD AddDeviceProvider(nsIPresentationDeviceProvider *provider) override { return _to AddDeviceProvider(provider); } \
  NS_IMETHOD RemoveDeviceProvider(nsIPresentationDeviceProvider *provider) override { return _to RemoveDeviceProvider(provider); } \
  NS_IMETHOD ForceDiscovery(void) override { return _to ForceDiscovery(); } \
  NS_IMETHOD GetAvailableDevices(nsIArray * *_retval) override { return _to GetAvailableDevices(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRESENTATIONDEVICEMANAGER(_to) \
  NS_IMETHOD GetDeviceAvailable(bool *aDeviceAvailable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeviceAvailable(aDeviceAvailable); } \
  NS_IMETHOD AddDeviceProvider(nsIPresentationDeviceProvider *provider) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDeviceProvider(provider); } \
  NS_IMETHOD RemoveDeviceProvider(nsIPresentationDeviceProvider *provider) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDeviceProvider(provider); } \
  NS_IMETHOD ForceDiscovery(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceDiscovery(); } \
  NS_IMETHOD GetAvailableDevices(nsIArray * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvailableDevices(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPresentationDeviceManager : public nsIPresentationDeviceManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRESENTATIONDEVICEMANAGER

  nsPresentationDeviceManager();

private:
  ~nsPresentationDeviceManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPresentationDeviceManager, nsIPresentationDeviceManager)

nsPresentationDeviceManager::nsPresentationDeviceManager()
{
  /* member initializers and constructor code */
}

nsPresentationDeviceManager::~nsPresentationDeviceManager()
{
  /* destructor code */
}

/* readonly attribute boolean deviceAvailable; */
NS_IMETHODIMP nsPresentationDeviceManager::GetDeviceAvailable(bool *aDeviceAvailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDeviceProvider (in nsIPresentationDeviceProvider provider); */
NS_IMETHODIMP nsPresentationDeviceManager::AddDeviceProvider(nsIPresentationDeviceProvider *provider)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDeviceProvider (in nsIPresentationDeviceProvider provider); */
NS_IMETHODIMP nsPresentationDeviceManager::RemoveDeviceProvider(nsIPresentationDeviceProvider *provider)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceDiscovery (); */
NS_IMETHODIMP nsPresentationDeviceManager::ForceDiscovery()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getAvailableDevices (); */
NS_IMETHODIMP nsPresentationDeviceManager::GetAvailableDevices(nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPresentationDeviceManager_h__ */
