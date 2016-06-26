/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMobileMessageDatabaseService.idl
 */

#ifndef __gen_nsIMobileMessageDatabaseService_h__
#define __gen_nsIMobileMessageDatabaseService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define MOBILE_MESSAGE_DATABASE_SERVICE_CID \
{ 0x0d84b9c2, 0x8f76, 0x4ba4,    \
{ 0xa5, 0xcd, 0xdb, 0xfb, 0x01, 0xdf, 0xda, 0x99 } }
#define MOBILE_MESSAGE_DATABASE_SERVICE_CONTRACTID "@mozilla.org/mobilemessage/mobilemessagedatabaseservice;1"
class nsICursorContinueCallback; /* forward declaration */

class nsIMobileMessageCallback; /* forward declaration */

class nsIMobileMessageCursorCallback; /* forward declaration */


/* starting interface:    nsIMobileMessageDatabaseService */
#define NS_IMOBILEMESSAGEDATABASESERVICE_IID_STR "ead626bc-f5b4-47e1-921c-0b956c9298e0"

#define NS_IMOBILEMESSAGEDATABASESERVICE_IID \
  {0xead626bc, 0xf5b4, 0x47e1, \
    { 0x92, 0x1c, 0x0b, 0x95, 0x6c, 0x92, 0x98, 0xe0 }}

class NS_NO_VTABLE nsIMobileMessageDatabaseService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILEMESSAGEDATABASESERVICE_IID)

  /* [binaryname(GetMessageMoz)] void getMessage (in long messageId, in nsIMobileMessageCallback request); */
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request) = 0;

  /* void deleteMessage ([array, size_is (count)] in long messageIds, in uint32_t count, in nsIMobileMessageCallback request); */
  NS_IMETHOD DeleteMessage(int32_t *messageIds, uint32_t count, nsIMobileMessageCallback *request) = 0;

  /* nsICursorContinueCallback createMessageCursor (in boolean hasStartDate, in unsigned long long startDate, in boolean hasEndDate, in unsigned long long endDate, [array, size_is (numbersCount)] in wstring numbers, in uint32_t numbersCount, [Null (Null), Undefined (Null)] in DOMString delivery, in boolean hasRead, in boolean read, in unsigned long long threadId, in boolean reverse, in nsIMobileMessageCursorCallback callback); */
  NS_IMETHOD CreateMessageCursor(bool hasStartDate, uint64_t startDate, bool hasEndDate, uint64_t endDate, const char16_t * *numbers, uint32_t numbersCount, const nsAString & delivery, bool hasRead, bool read, uint64_t threadId, bool reverse, nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval) = 0;

  /* void markMessageRead (in long messageId, in boolean value, in boolean sendReadReport, in nsIMobileMessageCallback request); */
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, bool sendReadReport, nsIMobileMessageCallback *request) = 0;

  /* nsICursorContinueCallback createThreadCursor (in nsIMobileMessageCursorCallback callback); */
  NS_IMETHOD CreateThreadCursor(nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileMessageDatabaseService, NS_IMOBILEMESSAGEDATABASESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILEMESSAGEDATABASESERVICE \
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request) override; \
  NS_IMETHOD DeleteMessage(int32_t *messageIds, uint32_t count, nsIMobileMessageCallback *request) override; \
  NS_IMETHOD CreateMessageCursor(bool hasStartDate, uint64_t startDate, bool hasEndDate, uint64_t endDate, const char16_t * *numbers, uint32_t numbersCount, const nsAString & delivery, bool hasRead, bool read, uint64_t threadId, bool reverse, nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval) override; \
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, bool sendReadReport, nsIMobileMessageCallback *request) override; \
  NS_IMETHOD CreateThreadCursor(nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILEMESSAGEDATABASESERVICE(_to) \
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request) override { return _to GetMessageMoz(messageId, request); } \
  NS_IMETHOD DeleteMessage(int32_t *messageIds, uint32_t count, nsIMobileMessageCallback *request) override { return _to DeleteMessage(messageIds, count, request); } \
  NS_IMETHOD CreateMessageCursor(bool hasStartDate, uint64_t startDate, bool hasEndDate, uint64_t endDate, const char16_t * *numbers, uint32_t numbersCount, const nsAString & delivery, bool hasRead, bool read, uint64_t threadId, bool reverse, nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval) override { return _to CreateMessageCursor(hasStartDate, startDate, hasEndDate, endDate, numbers, numbersCount, delivery, hasRead, read, threadId, reverse, callback, _retval); } \
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, bool sendReadReport, nsIMobileMessageCallback *request) override { return _to MarkMessageRead(messageId, value, sendReadReport, request); } \
  NS_IMETHOD CreateThreadCursor(nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval) override { return _to CreateThreadCursor(callback, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILEMESSAGEDATABASESERVICE(_to) \
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(messageId, request); } \
  NS_IMETHOD DeleteMessage(int32_t *messageIds, uint32_t count, nsIMobileMessageCallback *request) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteMessage(messageIds, count, request); } \
  NS_IMETHOD CreateMessageCursor(bool hasStartDate, uint64_t startDate, bool hasEndDate, uint64_t endDate, const char16_t * *numbers, uint32_t numbersCount, const nsAString & delivery, bool hasRead, bool read, uint64_t threadId, bool reverse, nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateMessageCursor(hasStartDate, startDate, hasEndDate, endDate, numbers, numbersCount, delivery, hasRead, read, threadId, reverse, callback, _retval); } \
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, bool sendReadReport, nsIMobileMessageCallback *request) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkMessageRead(messageId, value, sendReadReport, request); } \
  NS_IMETHOD CreateThreadCursor(nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateThreadCursor(callback, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileMessageDatabaseService : public nsIMobileMessageDatabaseService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILEMESSAGEDATABASESERVICE

  nsMobileMessageDatabaseService();

private:
  ~nsMobileMessageDatabaseService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileMessageDatabaseService, nsIMobileMessageDatabaseService)

nsMobileMessageDatabaseService::nsMobileMessageDatabaseService()
{
  /* member initializers and constructor code */
}

nsMobileMessageDatabaseService::~nsMobileMessageDatabaseService()
{
  /* destructor code */
}

/* [binaryname(GetMessageMoz)] void getMessage (in long messageId, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMobileMessageDatabaseService::GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteMessage ([array, size_is (count)] in long messageIds, in uint32_t count, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMobileMessageDatabaseService::DeleteMessage(int32_t *messageIds, uint32_t count, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICursorContinueCallback createMessageCursor (in boolean hasStartDate, in unsigned long long startDate, in boolean hasEndDate, in unsigned long long endDate, [array, size_is (numbersCount)] in wstring numbers, in uint32_t numbersCount, [Null (Null), Undefined (Null)] in DOMString delivery, in boolean hasRead, in boolean read, in unsigned long long threadId, in boolean reverse, in nsIMobileMessageCursorCallback callback); */
NS_IMETHODIMP nsMobileMessageDatabaseService::CreateMessageCursor(bool hasStartDate, uint64_t startDate, bool hasEndDate, uint64_t endDate, const char16_t * *numbers, uint32_t numbersCount, const nsAString & delivery, bool hasRead, bool read, uint64_t threadId, bool reverse, nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markMessageRead (in long messageId, in boolean value, in boolean sendReadReport, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMobileMessageDatabaseService::MarkMessageRead(int32_t messageId, bool value, bool sendReadReport, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICursorContinueCallback createThreadCursor (in nsIMobileMessageCursorCallback callback); */
NS_IMETHODIMP nsMobileMessageDatabaseService::CreateThreadCursor(nsIMobileMessageCursorCallback *callback, nsICursorContinueCallback * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

template<typename T> struct already_AddRefed;
already_AddRefed<nsIMobileMessageDatabaseService>
NS_CreateMobileMessageDatabaseService();

#endif /* __gen_nsIMobileMessageDatabaseService_h__ */
