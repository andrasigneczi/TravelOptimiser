/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISmsService.idl
 */

#ifndef __gen_nsISmsService_h__
#define __gen_nsISmsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozSmsMessage; /* forward declaration */

class nsIMobileMessageCallback; /* forward declaration */

#define SMS_SERVICE_CID { 0xbada3cb8, 0xa568, 0x4dff, { 0xb5, 0x43, 0x52, 0xbb, 0xb3, 0x14, 0x31, 0x21 } }
#define SMS_SERVICE_CONTRACTID "@mozilla.org/sms/smsservice;1"

/* starting interface:    nsISmsService */
#define NS_ISMSSERVICE_IID_STR "c8ca5f06-ad76-44b0-a324-9e2910fd37da"

#define NS_ISMSSERVICE_IID \
  {0xc8ca5f06, 0xad76, 0x44b0, \
    { 0xa3, 0x24, 0x9e, 0x29, 0x10, 0xfd, 0x37, 0xda }}

class NS_NO_VTABLE nsISmsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISMSSERVICE_IID)

  enum {
    MESSAGE_CLASS_TYPE_CLASS_0 = 0U,
    MESSAGE_CLASS_TYPE_CLASS_1 = 1U,
    MESSAGE_CLASS_TYPE_CLASS_2 = 2U,
    MESSAGE_CLASS_TYPE_CLASS_3 = 3U,
    MESSAGE_CLASS_TYPE_NORMAL = 6U,
    DELIVERY_TYPE_RECEIVED = 0U,
    DELIVERY_TYPE_SENDING = 1U,
    DELIVERY_TYPE_SENT = 2U,
    DELIVERY_TYPE_ERROR = 3U,
    DELIVERY_STATUS_TYPE_NOT_APPLICABLE = 0U,
    DELIVERY_STATUS_TYPE_SUCCESS = 1U,
    DELIVERY_STATUS_TYPE_PENDING = 2U,
    DELIVERY_STATUS_TYPE_ERROR = 3U,
    TYPE_OF_NUMBER_UNKNOWN = 0U,
    TYPE_OF_NUMBER_INTERNATIONAL = 1U,
    TYPE_OF_NUMBER_NATIONAL = 2U,
    TYPE_OF_NUMBER_NETWORK_SPECIFIC = 3U,
    TYPE_OF_NUMBER_DEDICATED_ACCESS_SHORT_CODE = 4U,
    NUMBER_PLAN_IDENTIFICATION_UNKNOWN = 0U,
    NUMBER_PLAN_IDENTIFICATION_ISDN = 1U,
    NUMBER_PLAN_IDENTIFICATION_DATA = 2U,
    NUMBER_PLAN_IDENTIFICATION_TELEX = 3U,
    NUMBER_PLAN_IDENTIFICATION_NATIONAL = 4U,
    NUMBER_PLAN_IDENTIFICATION_PRIVATE = 5U
  };

  /* readonly attribute unsigned long smsDefaultServiceId; */
  NS_IMETHOD GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId) = 0;

  /* void getSegmentInfoForText (in DOMString text, in nsIMobileMessageCallback request); */
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request) = 0;

  /* void send (in unsigned long serviceId, in DOMString number, in DOMString message, in boolean silent, in nsIMobileMessageCallback request); */
  NS_IMETHOD Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) = 0;

  /* void addSilentNumber (in DOMString number); */
  NS_IMETHOD AddSilentNumber(const nsAString & number) = 0;

  /* void removeSilentNumber (in DOMString number); */
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) = 0;

  /* void getSmscAddress (in unsigned long serviceId, in nsIMobileMessageCallback request); */
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request) = 0;

  /* void setSmscAddress (in unsigned long serviceId, in DOMString number, in unsigned long typeOfNumber, in unsigned long numberPlanIdentification, in nsIMobileMessageCallback request); */
  NS_IMETHOD SetSmscAddress(uint32_t serviceId, const nsAString & number, uint32_t typeOfNumber, uint32_t numberPlanIdentification, nsIMobileMessageCallback *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISmsService, NS_ISMSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISMSSERVICE \
  NS_IMETHOD GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId) override; \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request) override; \
  NS_IMETHOD Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) override; \
  NS_IMETHOD AddSilentNumber(const nsAString & number) override; \
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) override; \
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request) override; \
  NS_IMETHOD SetSmscAddress(uint32_t serviceId, const nsAString & number, uint32_t typeOfNumber, uint32_t numberPlanIdentification, nsIMobileMessageCallback *request) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISMSSERVICE(_to) \
  NS_IMETHOD GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId) override { return _to GetSmsDefaultServiceId(aSmsDefaultServiceId); } \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request) override { return _to GetSegmentInfoForText(text, request); } \
  NS_IMETHOD Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) override { return _to Send(serviceId, number, message, silent, request); } \
  NS_IMETHOD AddSilentNumber(const nsAString & number) override { return _to AddSilentNumber(number); } \
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) override { return _to RemoveSilentNumber(number); } \
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request) override { return _to GetSmscAddress(serviceId, request); } \
  NS_IMETHOD SetSmscAddress(uint32_t serviceId, const nsAString & number, uint32_t typeOfNumber, uint32_t numberPlanIdentification, nsIMobileMessageCallback *request) override { return _to SetSmscAddress(serviceId, number, typeOfNumber, numberPlanIdentification, request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISMSSERVICE(_to) \
  NS_IMETHOD GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSmsDefaultServiceId(aSmsDefaultServiceId); } \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSegmentInfoForText(text, request); } \
  NS_IMETHOD Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(serviceId, number, message, silent, request); } \
  NS_IMETHOD AddSilentNumber(const nsAString & number) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSilentNumber(number); } \
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSilentNumber(number); } \
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSmscAddress(serviceId, request); } \
  NS_IMETHOD SetSmscAddress(uint32_t serviceId, const nsAString & number, uint32_t typeOfNumber, uint32_t numberPlanIdentification, nsIMobileMessageCallback *request) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSmscAddress(serviceId, number, typeOfNumber, numberPlanIdentification, request); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSmsService : public nsISmsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISMSSERVICE

  nsSmsService();

private:
  ~nsSmsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSmsService, nsISmsService)

nsSmsService::nsSmsService()
{
  /* member initializers and constructor code */
}

nsSmsService::~nsSmsService()
{
  /* destructor code */
}

/* readonly attribute unsigned long smsDefaultServiceId; */
NS_IMETHODIMP nsSmsService::GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSegmentInfoForText (in DOMString text, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsSmsService::GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send (in unsigned long serviceId, in DOMString number, in DOMString message, in boolean silent, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsSmsService::Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSilentNumber (in DOMString number); */
NS_IMETHODIMP nsSmsService::AddSilentNumber(const nsAString & number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSilentNumber (in DOMString number); */
NS_IMETHODIMP nsSmsService::RemoveSilentNumber(const nsAString & number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSmscAddress (in unsigned long serviceId, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsSmsService::GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSmscAddress (in unsigned long serviceId, in DOMString number, in unsigned long typeOfNumber, in unsigned long numberPlanIdentification, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsSmsService::SetSmscAddress(uint32_t serviceId, const nsAString & number, uint32_t typeOfNumber, uint32_t numberPlanIdentification, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

template<typename T> struct already_AddRefed;
already_AddRefed<nsISmsService>
NS_CreateSmsService();

#endif /* __gen_nsISmsService_h__ */
