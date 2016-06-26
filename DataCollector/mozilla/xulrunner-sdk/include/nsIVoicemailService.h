/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIVoicemailService.idl
 */

#ifndef __gen_nsIVoicemailService_h__
#define __gen_nsIVoicemailService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVoicemailProvider; /* forward declaration */


/* starting interface:    nsIVoicemailListener */
#define NS_IVOICEMAILLISTENER_IID_STR "6a8b0133-960d-409d-88cd-583239e45f9f"

#define NS_IVOICEMAILLISTENER_IID \
  {0x6a8b0133, 0x960d, 0x409d, \
    { 0x88, 0xcd, 0x58, 0x32, 0x39, 0xe4, 0x5f, 0x9f }}

class NS_NO_VTABLE nsIVoicemailListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVOICEMAILLISTENER_IID)

  /* void notifyStatusChanged (in nsIVoicemailProvider provider); */
  NS_IMETHOD NotifyStatusChanged(nsIVoicemailProvider *provider) = 0;

  /* void notifyInfoChanged (in nsIVoicemailProvider provider); */
  NS_IMETHOD NotifyInfoChanged(nsIVoicemailProvider *provider) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVoicemailListener, NS_IVOICEMAILLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVOICEMAILLISTENER \
  NS_IMETHOD NotifyStatusChanged(nsIVoicemailProvider *provider) override; \
  NS_IMETHOD NotifyInfoChanged(nsIVoicemailProvider *provider) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVOICEMAILLISTENER(_to) \
  NS_IMETHOD NotifyStatusChanged(nsIVoicemailProvider *provider) override { return _to NotifyStatusChanged(provider); } \
  NS_IMETHOD NotifyInfoChanged(nsIVoicemailProvider *provider) override { return _to NotifyInfoChanged(provider); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVOICEMAILLISTENER(_to) \
  NS_IMETHOD NotifyStatusChanged(nsIVoicemailProvider *provider) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyStatusChanged(provider); } \
  NS_IMETHOD NotifyInfoChanged(nsIVoicemailProvider *provider) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyInfoChanged(provider); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVoicemailListener : public nsIVoicemailListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVOICEMAILLISTENER

  nsVoicemailListener();

private:
  ~nsVoicemailListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsVoicemailListener, nsIVoicemailListener)

nsVoicemailListener::nsVoicemailListener()
{
  /* member initializers and constructor code */
}

nsVoicemailListener::~nsVoicemailListener()
{
  /* destructor code */
}

/* void notifyStatusChanged (in nsIVoicemailProvider provider); */
NS_IMETHODIMP nsVoicemailListener::NotifyStatusChanged(nsIVoicemailProvider *provider)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyInfoChanged (in nsIVoicemailProvider provider); */
NS_IMETHODIMP nsVoicemailListener::NotifyInfoChanged(nsIVoicemailProvider *provider)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_VOICEMAIL_SERVICE_CID \
  { 0xcdd8fd72, 0x7d55, 0x496b, \
    { 0xab, 0x1d, 0x74, 0x9f, 0xbc, 0x44, 0x56, 0x32 } }
#define NS_VOICEMAIL_SERVICE_CONTRACTID \
  "@mozilla.org/voicemail/voicemailservice;1"

/* starting interface:    nsIVoicemailService */
#define NS_IVOICEMAILSERVICE_IID_STR "8ffd16c7-a614-4c4a-81f0-2a95e807152d"

#define NS_IVOICEMAILSERVICE_IID \
  {0x8ffd16c7, 0xa614, 0x4c4a, \
    { 0x81, 0xf0, 0x2a, 0x95, 0xe8, 0x07, 0x15, 0x2d }}

class NS_NO_VTABLE nsIVoicemailService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVOICEMAILSERVICE_IID)

  /* readonly attribute unsigned long numItems; */
  NS_IMETHOD GetNumItems(uint32_t *aNumItems) = 0;

  /* nsIVoicemailProvider getItemByServiceId (in unsigned long serviceId); */
  NS_IMETHOD GetItemByServiceId(uint32_t serviceId, nsIVoicemailProvider * *_retval) = 0;

  /* nsIVoicemailProvider getDefaultItem (); */
  NS_IMETHOD GetDefaultItem(nsIVoicemailProvider * *_retval) = 0;

  /* void registerListener (in nsIVoicemailListener listener); */
  NS_IMETHOD RegisterListener(nsIVoicemailListener *listener) = 0;

  /* void unregisterListener (in nsIVoicemailListener listener); */
  NS_IMETHOD UnregisterListener(nsIVoicemailListener *listener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVoicemailService, NS_IVOICEMAILSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVOICEMAILSERVICE \
  NS_IMETHOD GetNumItems(uint32_t *aNumItems) override; \
  NS_IMETHOD GetItemByServiceId(uint32_t serviceId, nsIVoicemailProvider * *_retval) override; \
  NS_IMETHOD GetDefaultItem(nsIVoicemailProvider * *_retval) override; \
  NS_IMETHOD RegisterListener(nsIVoicemailListener *listener) override; \
  NS_IMETHOD UnregisterListener(nsIVoicemailListener *listener) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVOICEMAILSERVICE(_to) \
  NS_IMETHOD GetNumItems(uint32_t *aNumItems) override { return _to GetNumItems(aNumItems); } \
  NS_IMETHOD GetItemByServiceId(uint32_t serviceId, nsIVoicemailProvider * *_retval) override { return _to GetItemByServiceId(serviceId, _retval); } \
  NS_IMETHOD GetDefaultItem(nsIVoicemailProvider * *_retval) override { return _to GetDefaultItem(_retval); } \
  NS_IMETHOD RegisterListener(nsIVoicemailListener *listener) override { return _to RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsIVoicemailListener *listener) override { return _to UnregisterListener(listener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVOICEMAILSERVICE(_to) \
  NS_IMETHOD GetNumItems(uint32_t *aNumItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumItems(aNumItems); } \
  NS_IMETHOD GetItemByServiceId(uint32_t serviceId, nsIVoicemailProvider * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemByServiceId(serviceId, _retval); } \
  NS_IMETHOD GetDefaultItem(nsIVoicemailProvider * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultItem(_retval); } \
  NS_IMETHOD RegisterListener(nsIVoicemailListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsIVoicemailListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterListener(listener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVoicemailService : public nsIVoicemailService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVOICEMAILSERVICE

  nsVoicemailService();

private:
  ~nsVoicemailService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsVoicemailService, nsIVoicemailService)

nsVoicemailService::nsVoicemailService()
{
  /* member initializers and constructor code */
}

nsVoicemailService::~nsVoicemailService()
{
  /* destructor code */
}

/* readonly attribute unsigned long numItems; */
NS_IMETHODIMP nsVoicemailService::GetNumItems(uint32_t *aNumItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVoicemailProvider getItemByServiceId (in unsigned long serviceId); */
NS_IMETHODIMP nsVoicemailService::GetItemByServiceId(uint32_t serviceId, nsIVoicemailProvider * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVoicemailProvider getDefaultItem (); */
NS_IMETHODIMP nsVoicemailService::GetDefaultItem(nsIVoicemailProvider * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerListener (in nsIVoicemailListener listener); */
NS_IMETHODIMP nsVoicemailService::RegisterListener(nsIVoicemailListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterListener (in nsIVoicemailListener listener); */
NS_IMETHODIMP nsVoicemailService::UnregisterListener(nsIVoicemailListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

template<typename T> struct already_AddRefed;
already_AddRefed<nsIVoicemailService>
NS_CreateVoicemailService();

/* starting interface:    nsIVoicemailProvider */
#define NS_IVOICEMAILPROVIDER_IID_STR "a0bc19a2-3216-4f3f-89d3-8976a48cb829"

#define NS_IVOICEMAILPROVIDER_IID \
  {0xa0bc19a2, 0x3216, 0x4f3f, \
    { 0x89, 0xd3, 0x89, 0x76, 0xa4, 0x8c, 0xb8, 0x29 }}

class NS_NO_VTABLE nsIVoicemailProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVOICEMAILPROVIDER_IID)

  /* readonly attribute unsigned long serviceId; */
  NS_IMETHOD GetServiceId(uint32_t *aServiceId) = 0;

  /* readonly attribute DOMString number; */
  NS_IMETHOD GetNumber(nsAString & aNumber) = 0;

  /* readonly attribute DOMString displayName; */
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) = 0;

  /* readonly attribute boolean hasMessages; */
  NS_IMETHOD GetHasMessages(bool *aHasMessages) = 0;

  /* readonly attribute long messageCount; */
  NS_IMETHOD GetMessageCount(int32_t *aMessageCount) = 0;

  /* readonly attribute DOMString returnNumber; */
  NS_IMETHOD GetReturnNumber(nsAString & aReturnNumber) = 0;

  /* readonly attribute DOMString returnMessage; */
  NS_IMETHOD GetReturnMessage(nsAString & aReturnMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVoicemailProvider, NS_IVOICEMAILPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVOICEMAILPROVIDER \
  NS_IMETHOD GetServiceId(uint32_t *aServiceId) override; \
  NS_IMETHOD GetNumber(nsAString & aNumber) override; \
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) override; \
  NS_IMETHOD GetHasMessages(bool *aHasMessages) override; \
  NS_IMETHOD GetMessageCount(int32_t *aMessageCount) override; \
  NS_IMETHOD GetReturnNumber(nsAString & aReturnNumber) override; \
  NS_IMETHOD GetReturnMessage(nsAString & aReturnMessage) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVOICEMAILPROVIDER(_to) \
  NS_IMETHOD GetServiceId(uint32_t *aServiceId) override { return _to GetServiceId(aServiceId); } \
  NS_IMETHOD GetNumber(nsAString & aNumber) override { return _to GetNumber(aNumber); } \
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) override { return _to GetDisplayName(aDisplayName); } \
  NS_IMETHOD GetHasMessages(bool *aHasMessages) override { return _to GetHasMessages(aHasMessages); } \
  NS_IMETHOD GetMessageCount(int32_t *aMessageCount) override { return _to GetMessageCount(aMessageCount); } \
  NS_IMETHOD GetReturnNumber(nsAString & aReturnNumber) override { return _to GetReturnNumber(aReturnNumber); } \
  NS_IMETHOD GetReturnMessage(nsAString & aReturnMessage) override { return _to GetReturnMessage(aReturnMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVOICEMAILPROVIDER(_to) \
  NS_IMETHOD GetServiceId(uint32_t *aServiceId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceId(aServiceId); } \
  NS_IMETHOD GetNumber(nsAString & aNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumber(aNumber); } \
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayName(aDisplayName); } \
  NS_IMETHOD GetHasMessages(bool *aHasMessages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasMessages(aHasMessages); } \
  NS_IMETHOD GetMessageCount(int32_t *aMessageCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageCount(aMessageCount); } \
  NS_IMETHOD GetReturnNumber(nsAString & aReturnNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnNumber(aReturnNumber); } \
  NS_IMETHOD GetReturnMessage(nsAString & aReturnMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnMessage(aReturnMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVoicemailProvider : public nsIVoicemailProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVOICEMAILPROVIDER

  nsVoicemailProvider();

private:
  ~nsVoicemailProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsVoicemailProvider, nsIVoicemailProvider)

nsVoicemailProvider::nsVoicemailProvider()
{
  /* member initializers and constructor code */
}

nsVoicemailProvider::~nsVoicemailProvider()
{
  /* destructor code */
}

/* readonly attribute unsigned long serviceId; */
NS_IMETHODIMP nsVoicemailProvider::GetServiceId(uint32_t *aServiceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString number; */
NS_IMETHODIMP nsVoicemailProvider::GetNumber(nsAString & aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString displayName; */
NS_IMETHODIMP nsVoicemailProvider::GetDisplayName(nsAString & aDisplayName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasMessages; */
NS_IMETHODIMP nsVoicemailProvider::GetHasMessages(bool *aHasMessages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long messageCount; */
NS_IMETHODIMP nsVoicemailProvider::GetMessageCount(int32_t *aMessageCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString returnNumber; */
NS_IMETHODIMP nsVoicemailProvider::GetReturnNumber(nsAString & aReturnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString returnMessage; */
NS_IMETHODIMP nsVoicemailProvider::GetReturnMessage(nsAString & aReturnMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIVoicemailService_h__ */
