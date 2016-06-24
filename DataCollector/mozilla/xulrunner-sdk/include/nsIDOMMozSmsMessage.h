/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMozSmsMessage.idl
 */

#ifndef __gen_nsIDOMMozSmsMessage_h__
#define __gen_nsIDOMMozSmsMessage_h__


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

/* starting interface:    nsIDOMMozSmsMessage */
#define NS_IDOMMOZSMSMESSAGE_IID_STR "fc8153d2-0026-11e3-bf31-8b0c1d5e7638"

#define NS_IDOMMOZSMSMESSAGE_IID \
  {0xfc8153d2, 0x0026, 0x11e3, \
    { 0xbf, 0x31, 0x8b, 0x0c, 0x1d, 0x5e, 0x76, 0x38 }}

class NS_NO_VTABLE nsIDOMMozSmsMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZSMSMESSAGE_IID)

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute long id; */
  NS_IMETHOD GetId(int32_t *aId) = 0;

  /* readonly attribute unsigned long long threadId; */
  NS_IMETHOD GetThreadId(uint64_t *aThreadId) = 0;

  /* readonly attribute DOMString iccId; */
  NS_IMETHOD GetIccId(nsAString & aIccId) = 0;

  /* readonly attribute DOMString delivery; */
  NS_IMETHOD GetDelivery(nsAString & aDelivery) = 0;

  /* readonly attribute DOMString deliveryStatus; */
  NS_IMETHOD GetDeliveryStatus(nsAString & aDeliveryStatus) = 0;

  /* readonly attribute DOMString sender; */
  NS_IMETHOD GetSender(nsAString & aSender) = 0;

  /* readonly attribute DOMString receiver; */
  NS_IMETHOD GetReceiver(nsAString & aReceiver) = 0;

  /* readonly attribute DOMString body; */
  NS_IMETHOD GetBody(nsAString & aBody) = 0;

  /* readonly attribute DOMString messageClass; */
  NS_IMETHOD GetMessageClass(nsAString & aMessageClass) = 0;

  /* readonly attribute DOMTimeStamp timestamp; */
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) = 0;

  /* readonly attribute DOMTimeStamp sentTimestamp; */
  NS_IMETHOD GetSentTimestamp(DOMTimeStamp *aSentTimestamp) = 0;

  /* readonly attribute DOMTimeStamp deliveryTimestamp; */
  NS_IMETHOD GetDeliveryTimestamp(DOMTimeStamp *aDeliveryTimestamp) = 0;

  /* readonly attribute boolean read; */
  NS_IMETHOD GetRead(bool *aRead) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozSmsMessage, NS_IDOMMOZSMSMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZSMSMESSAGE \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD GetId(int32_t *aId) override; \
  NS_IMETHOD GetThreadId(uint64_t *aThreadId) override; \
  NS_IMETHOD GetIccId(nsAString & aIccId) override; \
  NS_IMETHOD GetDelivery(nsAString & aDelivery) override; \
  NS_IMETHOD GetDeliveryStatus(nsAString & aDeliveryStatus) override; \
  NS_IMETHOD GetSender(nsAString & aSender) override; \
  NS_IMETHOD GetReceiver(nsAString & aReceiver) override; \
  NS_IMETHOD GetBody(nsAString & aBody) override; \
  NS_IMETHOD GetMessageClass(nsAString & aMessageClass) override; \
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) override; \
  NS_IMETHOD GetSentTimestamp(DOMTimeStamp *aSentTimestamp) override; \
  NS_IMETHOD GetDeliveryTimestamp(DOMTimeStamp *aDeliveryTimestamp) override; \
  NS_IMETHOD GetRead(bool *aRead) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZSMSMESSAGE(_to) \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetId(int32_t *aId) override { return _to GetId(aId); } \
  NS_IMETHOD GetThreadId(uint64_t *aThreadId) override { return _to GetThreadId(aThreadId); } \
  NS_IMETHOD GetIccId(nsAString & aIccId) override { return _to GetIccId(aIccId); } \
  NS_IMETHOD GetDelivery(nsAString & aDelivery) override { return _to GetDelivery(aDelivery); } \
  NS_IMETHOD GetDeliveryStatus(nsAString & aDeliveryStatus) override { return _to GetDeliveryStatus(aDeliveryStatus); } \
  NS_IMETHOD GetSender(nsAString & aSender) override { return _to GetSender(aSender); } \
  NS_IMETHOD GetReceiver(nsAString & aReceiver) override { return _to GetReceiver(aReceiver); } \
  NS_IMETHOD GetBody(nsAString & aBody) override { return _to GetBody(aBody); } \
  NS_IMETHOD GetMessageClass(nsAString & aMessageClass) override { return _to GetMessageClass(aMessageClass); } \
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) override { return _to GetTimestamp(aTimestamp); } \
  NS_IMETHOD GetSentTimestamp(DOMTimeStamp *aSentTimestamp) override { return _to GetSentTimestamp(aSentTimestamp); } \
  NS_IMETHOD GetDeliveryTimestamp(DOMTimeStamp *aDeliveryTimestamp) override { return _to GetDeliveryTimestamp(aDeliveryTimestamp); } \
  NS_IMETHOD GetRead(bool *aRead) override { return _to GetRead(aRead); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZSMSMESSAGE(_to) \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetId(int32_t *aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetThreadId(uint64_t *aThreadId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreadId(aThreadId); } \
  NS_IMETHOD GetIccId(nsAString & aIccId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIccId(aIccId); } \
  NS_IMETHOD GetDelivery(nsAString & aDelivery) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelivery(aDelivery); } \
  NS_IMETHOD GetDeliveryStatus(nsAString & aDeliveryStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeliveryStatus(aDeliveryStatus); } \
  NS_IMETHOD GetSender(nsAString & aSender) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSender(aSender); } \
  NS_IMETHOD GetReceiver(nsAString & aReceiver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReceiver(aReceiver); } \
  NS_IMETHOD GetBody(nsAString & aBody) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBody(aBody); } \
  NS_IMETHOD GetMessageClass(nsAString & aMessageClass) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageClass(aMessageClass); } \
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimestamp(aTimestamp); } \
  NS_IMETHOD GetSentTimestamp(DOMTimeStamp *aSentTimestamp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSentTimestamp(aSentTimestamp); } \
  NS_IMETHOD GetDeliveryTimestamp(DOMTimeStamp *aDeliveryTimestamp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeliveryTimestamp(aDeliveryTimestamp); } \
  NS_IMETHOD GetRead(bool *aRead) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRead(aRead); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozSmsMessage : public nsIDOMMozSmsMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZSMSMESSAGE

  nsDOMMozSmsMessage();

private:
  ~nsDOMMozSmsMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMMozSmsMessage, nsIDOMMozSmsMessage)

nsDOMMozSmsMessage::nsDOMMozSmsMessage()
{
  /* member initializers and constructor code */
}

nsDOMMozSmsMessage::~nsDOMMozSmsMessage()
{
  /* destructor code */
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long id; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetId(int32_t *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long threadId; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetThreadId(uint64_t *aThreadId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString iccId; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetIccId(nsAString & aIccId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString delivery; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetDelivery(nsAString & aDelivery)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString deliveryStatus; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetDeliveryStatus(nsAString & aDeliveryStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString sender; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetSender(nsAString & aSender)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString receiver; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetReceiver(nsAString & aReceiver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString body; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetBody(nsAString & aBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString messageClass; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetMessageClass(nsAString & aMessageClass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMTimeStamp timestamp; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetTimestamp(DOMTimeStamp *aTimestamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMTimeStamp sentTimestamp; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetSentTimestamp(DOMTimeStamp *aSentTimestamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMTimeStamp deliveryTimestamp; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetDeliveryTimestamp(DOMTimeStamp *aDeliveryTimestamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean read; */
NS_IMETHODIMP nsDOMMozSmsMessage::GetRead(bool *aRead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozSmsMessage_h__ */
