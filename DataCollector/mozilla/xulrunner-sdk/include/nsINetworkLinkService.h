/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINetworkLinkService.idl
 */

#ifndef __gen_nsINetworkLinkService_h__
#define __gen_nsINetworkLinkService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINetworkLinkService */
#define NS_INETWORKLINKSERVICE_IID_STR "103e5293-77b3-4b70-af59-6e9e4a1f994a"

#define NS_INETWORKLINKSERVICE_IID \
  {0x103e5293, 0x77b3, 0x4b70, \
    { 0xaf, 0x59, 0x6e, 0x9e, 0x4a, 0x1f, 0x99, 0x4a }}

class NS_NO_VTABLE nsINetworkLinkService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETWORKLINKSERVICE_IID)

  enum {
    LINK_TYPE_UNKNOWN = 0U,
    LINK_TYPE_ETHERNET = 1U,
    LINK_TYPE_USB = 2U,
    LINK_TYPE_WIFI = 3U,
    LINK_TYPE_WIMAX = 4U,
    LINK_TYPE_2G = 5U,
    LINK_TYPE_3G = 6U,
    LINK_TYPE_4G = 7U
  };

  /* readonly attribute boolean isLinkUp; */
  NS_IMETHOD GetIsLinkUp(bool *aIsLinkUp) = 0;

  /* readonly attribute boolean linkStatusKnown; */
  NS_IMETHOD GetLinkStatusKnown(bool *aLinkStatusKnown) = 0;

  /* readonly attribute unsigned long linkType; */
  NS_IMETHOD GetLinkType(uint32_t *aLinkType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetworkLinkService, NS_INETWORKLINKSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETWORKLINKSERVICE \
  NS_IMETHOD GetIsLinkUp(bool *aIsLinkUp) override; \
  NS_IMETHOD GetLinkStatusKnown(bool *aLinkStatusKnown) override; \
  NS_IMETHOD GetLinkType(uint32_t *aLinkType) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETWORKLINKSERVICE(_to) \
  NS_IMETHOD GetIsLinkUp(bool *aIsLinkUp) override { return _to GetIsLinkUp(aIsLinkUp); } \
  NS_IMETHOD GetLinkStatusKnown(bool *aLinkStatusKnown) override { return _to GetLinkStatusKnown(aLinkStatusKnown); } \
  NS_IMETHOD GetLinkType(uint32_t *aLinkType) override { return _to GetLinkType(aLinkType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETWORKLINKSERVICE(_to) \
  NS_IMETHOD GetIsLinkUp(bool *aIsLinkUp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLinkUp(aIsLinkUp); } \
  NS_IMETHOD GetLinkStatusKnown(bool *aLinkStatusKnown) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkStatusKnown(aLinkStatusKnown); } \
  NS_IMETHOD GetLinkType(uint32_t *aLinkType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLinkType(aLinkType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetworkLinkService : public nsINetworkLinkService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETWORKLINKSERVICE

  nsNetworkLinkService();

private:
  ~nsNetworkLinkService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNetworkLinkService, nsINetworkLinkService)

nsNetworkLinkService::nsNetworkLinkService()
{
  /* member initializers and constructor code */
}

nsNetworkLinkService::~nsNetworkLinkService()
{
  /* destructor code */
}

/* readonly attribute boolean isLinkUp; */
NS_IMETHODIMP nsNetworkLinkService::GetIsLinkUp(bool *aIsLinkUp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean linkStatusKnown; */
NS_IMETHODIMP nsNetworkLinkService::GetLinkStatusKnown(bool *aLinkStatusKnown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long linkType; */
NS_IMETHODIMP nsNetworkLinkService::GetLinkType(uint32_t *aLinkType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * We send notifications through nsIObserverService with topic
 * NS_NETWORK_LINK_TOPIC whenever one of isLinkUp or linkStatusKnown
 * changes. We pass one of the NS_NETWORK_LINK_DATA_ constants below
 * as the aData parameter of the notification.
 */
#define NS_NETWORK_LINK_TOPIC "network:link-status-changed"
/**
 * isLinkUp is now true, linkStatusKnown is true.
 */
#define NS_NETWORK_LINK_DATA_UP      "up"
/**
 * isLinkUp is now false, linkStatusKnown is true.
 */
#define NS_NETWORK_LINK_DATA_DOWN    "down"
/**
 * isLinkUp is still true, but the network setup is modified.
 * linkStatusKnown is true.
 */
#define NS_NETWORK_LINK_DATA_CHANGED "changed"
/**
 * linkStatusKnown is now false.
 */
#define NS_NETWORK_LINK_DATA_UNKNOWN "unknown"
/**
 * We send notifications through nsIObserverService with topic
 * NS_NETWORK_LINK_TYPE_TOPIC whenever the network connection type
 * changes. We pass one of the valid connection type constants
 * below as the aData parameter of the notification.
 */
#define NS_NETWORK_LINK_TYPE_TOPIC "network:link-type-changed"
/** We were unable to determine the network connection type */
#define NS_NETWORK_LINK_TYPE_UNKNOWN  "unknown"
/** A standard wired ethernet connection */
#define NS_NETWORK_LINK_TYPE_ETHERNET    "ethernet"
/** A connection via a USB port */
#define NS_NETWORK_LINK_TYPE_USB    "usb"
/** A connection via a WiFi access point (IEEE802.11) */
#define NS_NETWORK_LINK_TYPE_WIFI "wifi"
/** A connection via WiMax (IEEE802.16) */
#define NS_NETWORK_LINK_TYPE_WIMAX "wimax"
/** A '2G' mobile connection (e.g. GSM, GPRS, EDGE) */
#define NS_NETWORK_LINK_TYPE_2G "2g"
/** A '3G' mobile connection (e.g. UMTS, CDMA) */
#define NS_NETWORK_LINK_TYPE_3G "3g"
/** A '4G' mobile connection (e.g. LTE, UMB) */
#define NS_NETWORK_LINK_TYPE_4G "4g"

#endif /* __gen_nsINetworkLinkService_h__ */
