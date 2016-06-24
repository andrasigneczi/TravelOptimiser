/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInputPortService.idl
 */

#ifndef __gen_nsIInputPortService_h__
#define __gen_nsIInputPortService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

#define INPUTPORT_DATA_CID \
  { 0x90b192d1, 0x357a, 0x4793, { 0xab, 0x58, 0x04, 0xee, 0x21, 0x62, 0x27, 0xda } }
#define INPUTPORT_DATA_CONTRACTID \
  "@mozilla.org/inputport/inputportdata;1"

/* starting interface:    nsIInputPortData */
#define NS_IINPUTPORTDATA_IID_STR "244a2b1d-aa1f-4188-a639-ddb56c554b6d"

#define NS_IINPUTPORTDATA_IID \
  {0x244a2b1d, 0xaa1f, 0x4188, \
    { 0xa6, 0x39, 0xdd, 0xb5, 0x6c, 0x55, 0x4b, 0x6d }}

class NS_NO_VTABLE nsIInputPortData : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTPORTDATA_IID)

  /* attribute DOMString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;
  NS_IMETHOD SetId(const nsAString & aId) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute boolean connected; */
  NS_IMETHOD GetConnected(bool *aConnected) = 0;
  NS_IMETHOD SetConnected(bool aConnected) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputPortData, NS_IINPUTPORTDATA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTPORTDATA \
  NS_IMETHOD GetId(nsAString & aId) override; \
  NS_IMETHOD SetId(const nsAString & aId) override; \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD SetType(const nsAString & aType) override; \
  NS_IMETHOD GetConnected(bool *aConnected) override; \
  NS_IMETHOD SetConnected(bool aConnected) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTPORTDATA(_to) \
  NS_IMETHOD GetId(nsAString & aId) override { return _to GetId(aId); } \
  NS_IMETHOD SetId(const nsAString & aId) override { return _to SetId(aId); } \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return _to SetType(aType); } \
  NS_IMETHOD GetConnected(bool *aConnected) override { return _to GetConnected(aConnected); } \
  NS_IMETHOD SetConnected(bool aConnected) override { return _to SetConnected(aConnected); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTPORTDATA(_to) \
  NS_IMETHOD GetId(nsAString & aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD SetId(const nsAString & aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetId(aId); } \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetConnected(bool *aConnected) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnected(aConnected); } \
  NS_IMETHOD SetConnected(bool aConnected) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConnected(aConnected); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputPortData : public nsIInputPortData
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTPORTDATA

  nsInputPortData();

private:
  ~nsInputPortData();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInputPortData, nsIInputPortData)

nsInputPortData::nsInputPortData()
{
  /* member initializers and constructor code */
}

nsInputPortData::~nsInputPortData()
{
  /* destructor code */
}

/* attribute DOMString id; */
NS_IMETHODIMP nsInputPortData::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputPortData::SetId(const nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsInputPortData::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputPortData::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean connected; */
NS_IMETHODIMP nsInputPortData::GetConnected(bool *aConnected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputPortData::SetConnected(bool aConnected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIInputPortListener */
#define NS_IINPUTPORTLISTENER_IID_STR "32a62e7c-f698-4846-81f7-617c87854d32"

#define NS_IINPUTPORTLISTENER_IID \
  {0x32a62e7c, 0xf698, 0x4846, \
    { 0x81, 0xf7, 0x61, 0x7c, 0x87, 0x85, 0x4d, 0x32 }}

class NS_NO_VTABLE nsIInputPortListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTPORTLISTENER_IID)

  /* void notifyConnectionChanged (in DOMString portId, in boolean isConnected); */
  NS_IMETHOD NotifyConnectionChanged(const nsAString & portId, bool isConnected) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputPortListener, NS_IINPUTPORTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTPORTLISTENER \
  NS_IMETHOD NotifyConnectionChanged(const nsAString & portId, bool isConnected) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTPORTLISTENER(_to) \
  NS_IMETHOD NotifyConnectionChanged(const nsAString & portId, bool isConnected) override { return _to NotifyConnectionChanged(portId, isConnected); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTPORTLISTENER(_to) \
  NS_IMETHOD NotifyConnectionChanged(const nsAString & portId, bool isConnected) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyConnectionChanged(portId, isConnected); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputPortListener : public nsIInputPortListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTPORTLISTENER

  nsInputPortListener();

private:
  ~nsInputPortListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInputPortListener, nsIInputPortListener)

nsInputPortListener::nsInputPortListener()
{
  /* member initializers and constructor code */
}

nsInputPortListener::~nsInputPortListener()
{
  /* destructor code */
}

/* void notifyConnectionChanged (in DOMString portId, in boolean isConnected); */
NS_IMETHODIMP nsInputPortListener::NotifyConnectionChanged(const nsAString & portId, bool isConnected)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIInputPortServiceCallback */
#define NS_IINPUTPORTSERVICECALLBACK_IID_STR "c2a47757-25f6-4bc8-bd27-c23af2d87381"

#define NS_IINPUTPORTSERVICECALLBACK_IID \
  {0xc2a47757, 0x25f6, 0x4bc8, \
    { 0xbd, 0x27, 0xc2, 0x3a, 0xf2, 0xd8, 0x73, 0x81 }}

class NS_NO_VTABLE nsIInputPortServiceCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTPORTSERVICECALLBACK_IID)

  enum {
    INPUTPORT_ERROR_OK = 0U,
    INPUTPORT_ERROR_FAILURE = 1U,
    INPUTPORT_ERROR_INVALID_ARG = 2U,
    INPUTPORT_ERROR_NOT_SUPPORTED = 3U
  };

  /* void notifyError (in unsigned short errorCode); */
  NS_IMETHOD NotifyError(uint16_t errorCode) = 0;

  /* void notifySuccess ([optional] in nsIArray dataList); */
  NS_IMETHOD NotifySuccess(nsIArray *dataList) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputPortServiceCallback, NS_IINPUTPORTSERVICECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTPORTSERVICECALLBACK \
  NS_IMETHOD NotifyError(uint16_t errorCode) override; \
  NS_IMETHOD NotifySuccess(nsIArray *dataList) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTPORTSERVICECALLBACK(_to) \
  NS_IMETHOD NotifyError(uint16_t errorCode) override { return _to NotifyError(errorCode); } \
  NS_IMETHOD NotifySuccess(nsIArray *dataList) override { return _to NotifySuccess(dataList); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTPORTSERVICECALLBACK(_to) \
  NS_IMETHOD NotifyError(uint16_t errorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyError(errorCode); } \
  NS_IMETHOD NotifySuccess(nsIArray *dataList) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySuccess(dataList); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputPortServiceCallback : public nsIInputPortServiceCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTPORTSERVICECALLBACK

  nsInputPortServiceCallback();

private:
  ~nsInputPortServiceCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInputPortServiceCallback, nsIInputPortServiceCallback)

nsInputPortServiceCallback::nsInputPortServiceCallback()
{
  /* member initializers and constructor code */
}

nsInputPortServiceCallback::~nsInputPortServiceCallback()
{
  /* destructor code */
}

/* void notifyError (in unsigned short errorCode); */
NS_IMETHODIMP nsInputPortServiceCallback::NotifyError(uint16_t errorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifySuccess ([optional] in nsIArray dataList); */
NS_IMETHODIMP nsInputPortServiceCallback::NotifySuccess(nsIArray *dataList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define INPUTPORT_SERVICE_CONTRACTID \
  "@mozilla.org/inputport/inputportservice;1"

/* starting interface:    nsIInputPortService */
#define NS_IINPUTPORTSERVICE_IID_STR "6214dae0-840e-11e4-b4a9-0800200c9a66"

#define NS_IINPUTPORTSERVICE_IID \
  {0x6214dae0, 0x840e, 0x11e4, \
    { 0xb4, 0xa9, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIInputPortService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTPORTSERVICE_IID)

  /* attribute nsIInputPortListener inputPortListener; */
  NS_IMETHOD GetInputPortListener(nsIInputPortListener * *aInputPortListener) = 0;
  NS_IMETHOD SetInputPortListener(nsIInputPortListener *aInputPortListener) = 0;

  /* void getInputPorts (in nsIInputPortServiceCallback callback); */
  NS_IMETHOD GetInputPorts(nsIInputPortServiceCallback *callback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputPortService, NS_IINPUTPORTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTPORTSERVICE \
  NS_IMETHOD GetInputPortListener(nsIInputPortListener * *aInputPortListener) override; \
  NS_IMETHOD SetInputPortListener(nsIInputPortListener *aInputPortListener) override; \
  NS_IMETHOD GetInputPorts(nsIInputPortServiceCallback *callback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTPORTSERVICE(_to) \
  NS_IMETHOD GetInputPortListener(nsIInputPortListener * *aInputPortListener) override { return _to GetInputPortListener(aInputPortListener); } \
  NS_IMETHOD SetInputPortListener(nsIInputPortListener *aInputPortListener) override { return _to SetInputPortListener(aInputPortListener); } \
  NS_IMETHOD GetInputPorts(nsIInputPortServiceCallback *callback) override { return _to GetInputPorts(callback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTPORTSERVICE(_to) \
  NS_IMETHOD GetInputPortListener(nsIInputPortListener * *aInputPortListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputPortListener(aInputPortListener); } \
  NS_IMETHOD SetInputPortListener(nsIInputPortListener *aInputPortListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInputPortListener(aInputPortListener); } \
  NS_IMETHOD GetInputPorts(nsIInputPortServiceCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputPorts(callback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputPortService : public nsIInputPortService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTPORTSERVICE

  nsInputPortService();

private:
  ~nsInputPortService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInputPortService, nsIInputPortService)

nsInputPortService::nsInputPortService()
{
  /* member initializers and constructor code */
}

nsInputPortService::~nsInputPortService()
{
  /* destructor code */
}

/* attribute nsIInputPortListener inputPortListener; */
NS_IMETHODIMP nsInputPortService::GetInputPortListener(nsIInputPortListener * *aInputPortListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputPortService::SetInputPortListener(nsIInputPortListener *aInputPortListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getInputPorts (in nsIInputPortServiceCallback callback); */
NS_IMETHODIMP nsInputPortService::GetInputPorts(nsIInputPortServiceCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInputPortService_h__ */
