/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICellBroadcastService.idl
 */

#ifndef __gen_nsICellBroadcastService_h__
#define __gen_nsICellBroadcastService_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICellBroadcastListener */
#define NS_ICELLBROADCASTLISTENER_IID_STR "56f66190-44a0-11e4-aa32-636783cc014a"

#define NS_ICELLBROADCASTLISTENER_IID \
  {0x56f66190, 0x44a0, 0x11e4, \
    { 0xaa, 0x32, 0x63, 0x67, 0x83, 0xcc, 0x01, 0x4a }}

class NS_NO_VTABLE nsICellBroadcastListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICELLBROADCASTLISTENER_IID)

  /* void notifyMessageReceived (in unsigned long aServiceId, in unsigned long aGsmGeographicalScope, in unsigned short aMessageCode, in unsigned short aMessageId, in DOMString aLanguage, in DOMString aBody, in unsigned long aMessageClass, in DOMTimeStamp aTimestamp, in unsigned long aCdmaServiceCategory, in boolean aHasEtwsInfo, in unsigned long aEtwsWarningType, in boolean aEtwsEmergencyUserAlert, in boolean aEtwsPopup); */
  NS_IMETHOD NotifyMessageReceived(uint32_t aServiceId, uint32_t aGsmGeographicalScope, uint16_t aMessageCode, uint16_t aMessageId, const nsAString & aLanguage, const nsAString & aBody, uint32_t aMessageClass, DOMTimeStamp aTimestamp, uint32_t aCdmaServiceCategory, bool aHasEtwsInfo, uint32_t aEtwsWarningType, bool aEtwsEmergencyUserAlert, bool aEtwsPopup) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICellBroadcastListener, NS_ICELLBROADCASTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICELLBROADCASTLISTENER \
  NS_IMETHOD NotifyMessageReceived(uint32_t aServiceId, uint32_t aGsmGeographicalScope, uint16_t aMessageCode, uint16_t aMessageId, const nsAString & aLanguage, const nsAString & aBody, uint32_t aMessageClass, DOMTimeStamp aTimestamp, uint32_t aCdmaServiceCategory, bool aHasEtwsInfo, uint32_t aEtwsWarningType, bool aEtwsEmergencyUserAlert, bool aEtwsPopup) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICELLBROADCASTLISTENER(_to) \
  NS_IMETHOD NotifyMessageReceived(uint32_t aServiceId, uint32_t aGsmGeographicalScope, uint16_t aMessageCode, uint16_t aMessageId, const nsAString & aLanguage, const nsAString & aBody, uint32_t aMessageClass, DOMTimeStamp aTimestamp, uint32_t aCdmaServiceCategory, bool aHasEtwsInfo, uint32_t aEtwsWarningType, bool aEtwsEmergencyUserAlert, bool aEtwsPopup) override { return _to NotifyMessageReceived(aServiceId, aGsmGeographicalScope, aMessageCode, aMessageId, aLanguage, aBody, aMessageClass, aTimestamp, aCdmaServiceCategory, aHasEtwsInfo, aEtwsWarningType, aEtwsEmergencyUserAlert, aEtwsPopup); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICELLBROADCASTLISTENER(_to) \
  NS_IMETHOD NotifyMessageReceived(uint32_t aServiceId, uint32_t aGsmGeographicalScope, uint16_t aMessageCode, uint16_t aMessageId, const nsAString & aLanguage, const nsAString & aBody, uint32_t aMessageClass, DOMTimeStamp aTimestamp, uint32_t aCdmaServiceCategory, bool aHasEtwsInfo, uint32_t aEtwsWarningType, bool aEtwsEmergencyUserAlert, bool aEtwsPopup) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageReceived(aServiceId, aGsmGeographicalScope, aMessageCode, aMessageId, aLanguage, aBody, aMessageClass, aTimestamp, aCdmaServiceCategory, aHasEtwsInfo, aEtwsWarningType, aEtwsEmergencyUserAlert, aEtwsPopup); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCellBroadcastListener : public nsICellBroadcastListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICELLBROADCASTLISTENER

  nsCellBroadcastListener();

private:
  ~nsCellBroadcastListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCellBroadcastListener, nsICellBroadcastListener)

nsCellBroadcastListener::nsCellBroadcastListener()
{
  /* member initializers and constructor code */
}

nsCellBroadcastListener::~nsCellBroadcastListener()
{
  /* destructor code */
}

/* void notifyMessageReceived (in unsigned long aServiceId, in unsigned long aGsmGeographicalScope, in unsigned short aMessageCode, in unsigned short aMessageId, in DOMString aLanguage, in DOMString aBody, in unsigned long aMessageClass, in DOMTimeStamp aTimestamp, in unsigned long aCdmaServiceCategory, in boolean aHasEtwsInfo, in unsigned long aEtwsWarningType, in boolean aEtwsEmergencyUserAlert, in boolean aEtwsPopup); */
NS_IMETHODIMP nsCellBroadcastListener::NotifyMessageReceived(uint32_t aServiceId, uint32_t aGsmGeographicalScope, uint16_t aMessageCode, uint16_t aMessageId, const nsAString & aLanguage, const nsAString & aBody, uint32_t aMessageClass, DOMTimeStamp aTimestamp, uint32_t aCdmaServiceCategory, bool aHasEtwsInfo, uint32_t aEtwsWarningType, bool aEtwsEmergencyUserAlert, bool aEtwsPopup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define CELLBROADCAST_SERVICE_CID \
  { 0xc870bdca, 0x277c, 0x11e4, { 0xac, 0xa3, 0x33, 0x73, 0xa1, 0xef, 0x48, 0xf8 } }
#define CELLBROADCAST_SERVICE_CONTRACTID \
  "@mozilla.org/cellbroadcast/cellbroadcastservice;1"

/* starting interface:    nsICellBroadcastService */
#define NS_ICELLBROADCASTSERVICE_IID_STR "906cda5a-6b18-11e4-973b-5ff3fc075b6b"

#define NS_ICELLBROADCASTSERVICE_IID \
  {0x906cda5a, 0x6b18, 0x11e4, \
    { 0x97, 0x3b, 0x5f, 0xf3, 0xfc, 0x07, 0x5b, 0x6b }}

class NS_NO_VTABLE nsICellBroadcastService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICELLBROADCASTSERVICE_IID)

  enum {
    GSM_GEOGRAPHICAL_SCOPE_CELL_IMMEDIATE = 0U,
    GSM_GEOGRAPHICAL_SCOPE_PLMN = 1U,
    GSM_GEOGRAPHICAL_SCOPE_LOCATION_AREA = 2U,
    GSM_GEOGRAPHICAL_SCOPE_CELL = 3U,
    GSM_GEOGRAPHICAL_SCOPE_INVALID = 65535U,
    GSM_MESSAGE_CLASS_0 = 0U,
    GSM_MESSAGE_CLASS_1 = 1U,
    GSM_MESSAGE_CLASS_2 = 2U,
    GSM_MESSAGE_CLASS_3 = 3U,
    GSM_MESSAGE_CLASS_USER_1 = 4U,
    GSM_MESSAGE_CLASS_USER_2 = 5U,
    GSM_MESSAGE_CLASS_NORMAL = 6U,
    GSM_ETWS_WARNING_EARTHQUAKE = 0U,
    GSM_ETWS_WARNING_TSUNAMI = 1U,
    GSM_ETWS_WARNING_EARTHQUAKE_TSUNAMI = 2U,
    GSM_ETWS_WARNING_TEST = 3U,
    GSM_ETWS_WARNING_OTHER = 4U,
    GSM_ETWS_WARNING_INVALID = 65535U,
    CDMA_SERVICE_CATEGORY_INVALID = 4294967295U
  };

  /* void registerListener (in nsICellBroadcastListener listener); */
  NS_IMETHOD RegisterListener(nsICellBroadcastListener *listener) = 0;

  /* void unregisterListener (in nsICellBroadcastListener listener); */
  NS_IMETHOD UnregisterListener(nsICellBroadcastListener *listener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICellBroadcastService, NS_ICELLBROADCASTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICELLBROADCASTSERVICE \
  NS_IMETHOD RegisterListener(nsICellBroadcastListener *listener) override; \
  NS_IMETHOD UnregisterListener(nsICellBroadcastListener *listener) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICELLBROADCASTSERVICE(_to) \
  NS_IMETHOD RegisterListener(nsICellBroadcastListener *listener) override { return _to RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsICellBroadcastListener *listener) override { return _to UnregisterListener(listener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICELLBROADCASTSERVICE(_to) \
  NS_IMETHOD RegisterListener(nsICellBroadcastListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsICellBroadcastListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterListener(listener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCellBroadcastService : public nsICellBroadcastService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICELLBROADCASTSERVICE

  nsCellBroadcastService();

private:
  ~nsCellBroadcastService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCellBroadcastService, nsICellBroadcastService)

nsCellBroadcastService::nsCellBroadcastService()
{
  /* member initializers and constructor code */
}

nsCellBroadcastService::~nsCellBroadcastService()
{
  /* destructor code */
}

/* void registerListener (in nsICellBroadcastListener listener); */
NS_IMETHODIMP nsCellBroadcastService::RegisterListener(nsICellBroadcastListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterListener (in nsICellBroadcastListener listener); */
NS_IMETHODIMP nsCellBroadcastService::UnregisterListener(nsICellBroadcastListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

template<typename T> struct already_AddRefed;
already_AddRefed<nsICellBroadcastService>
NS_CreateCellBroadcastService();

#endif /* __gen_nsICellBroadcastService_h__ */
