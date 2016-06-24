/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStkCmdFactory.idl
 */

#ifndef __gen_nsIStkCmdFactory_h__
#define __gen_nsIStkCmdFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define ICC_STK_CMD_FACTORY_CONTRACTID \
  "@mozilla.org/icc/stkcmdfactory;1"
class nsIStkProactiveCmd; /* forward declaration */

class nsIStkTerminalResponse; /* forward declaration */

class nsIStkDownloadEvent; /* forward declaration */

class nsIStkTimer; /* forward declaration */


/* starting interface:    nsIStkCmdFactory */
#define NS_ISTKCMDFACTORY_IID_STR "743536c4-006f-11e5-a3f7-bf7a7fd59b9b"

#define NS_ISTKCMDFACTORY_IID \
  {0x743536c4, 0x006f, 0x11e5, \
    { 0xa3, 0xf7, 0xbf, 0x7a, 0x7f, 0xd5, 0x9b, 0x9b }}

class NS_NO_VTABLE nsIStkCmdFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKCMDFACTORY_IID)

  /* nsIStkProactiveCmd createCommand (in jsval aCommandDetails); */
  NS_IMETHOD CreateCommand(JS::HandleValue aCommandDetails, nsIStkProactiveCmd * *_retval) = 0;

  /* jsval createCommandMessage (in nsIStkProactiveCmd aStkProactiveCmd); */
  NS_IMETHOD CreateCommandMessage(nsIStkProactiveCmd *aStkProactiveCmd, JS::MutableHandleValue _retval) = 0;

  /* AString deflateCommand (in nsIStkProactiveCmd aStkProactiveCmd); */
  NS_IMETHOD DeflateCommand(nsIStkProactiveCmd *aStkProactiveCmd, nsAString & _retval) = 0;

  /* nsIStkProactiveCmd inflateCommand (in AString aJSON); */
  NS_IMETHOD InflateCommand(const nsAString & aJSON, nsIStkProactiveCmd * *_retval) = 0;

  /* nsIStkTerminalResponse createResponse (in jsval aResponseMessage); */
  NS_IMETHOD CreateResponse(JS::HandleValue aResponseMessage, nsIStkTerminalResponse * *_retval) = 0;

  /* jsval createResponseMessage (in nsIStkTerminalResponse aStkTerminalResponse); */
  NS_IMETHOD CreateResponseMessage(nsIStkTerminalResponse *aStkTerminalResponse, JS::MutableHandleValue _retval) = 0;

  /* AString deflateResponse (in nsIStkTerminalResponse aStkTerminalResponse); */
  NS_IMETHOD DeflateResponse(nsIStkTerminalResponse *aStkTerminalResponse, nsAString & _retval) = 0;

  /* nsIStkTerminalResponse inflateResponse (in AString aJSON); */
  NS_IMETHOD InflateResponse(const nsAString & aJSON, nsIStkTerminalResponse * *_retval) = 0;

  /* nsIStkDownloadEvent createEvent (in jsval aEventMessage); */
  NS_IMETHOD CreateEvent(JS::HandleValue aEventMessage, nsIStkDownloadEvent * *_retval) = 0;

  /* jsval createEventMessage (in nsIStkDownloadEvent aStkDownloadEvent); */
  NS_IMETHOD CreateEventMessage(nsIStkDownloadEvent *aStkDownloadEvent, JS::MutableHandleValue _retval) = 0;

  /* AString deflateDownloadEvent (in nsIStkDownloadEvent aStkDownloadEvent); */
  NS_IMETHOD DeflateDownloadEvent(nsIStkDownloadEvent *aStkDownloadEvent, nsAString & _retval) = 0;

  /* nsIStkDownloadEvent inflateDownloadEvent (in AString aJSON); */
  NS_IMETHOD InflateDownloadEvent(const nsAString & aJSON, nsIStkDownloadEvent * *_retval) = 0;

  /* nsIStkTimer createTimer (in jsval aStkTimerMessage); */
  NS_IMETHOD CreateTimer(JS::HandleValue aStkTimerMessage, nsIStkTimer * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkCmdFactory, NS_ISTKCMDFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKCMDFACTORY \
  NS_IMETHOD CreateCommand(JS::HandleValue aCommandDetails, nsIStkProactiveCmd * *_retval) override; \
  NS_IMETHOD CreateCommandMessage(nsIStkProactiveCmd *aStkProactiveCmd, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD DeflateCommand(nsIStkProactiveCmd *aStkProactiveCmd, nsAString & _retval) override; \
  NS_IMETHOD InflateCommand(const nsAString & aJSON, nsIStkProactiveCmd * *_retval) override; \
  NS_IMETHOD CreateResponse(JS::HandleValue aResponseMessage, nsIStkTerminalResponse * *_retval) override; \
  NS_IMETHOD CreateResponseMessage(nsIStkTerminalResponse *aStkTerminalResponse, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD DeflateResponse(nsIStkTerminalResponse *aStkTerminalResponse, nsAString & _retval) override; \
  NS_IMETHOD InflateResponse(const nsAString & aJSON, nsIStkTerminalResponse * *_retval) override; \
  NS_IMETHOD CreateEvent(JS::HandleValue aEventMessage, nsIStkDownloadEvent * *_retval) override; \
  NS_IMETHOD CreateEventMessage(nsIStkDownloadEvent *aStkDownloadEvent, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD DeflateDownloadEvent(nsIStkDownloadEvent *aStkDownloadEvent, nsAString & _retval) override; \
  NS_IMETHOD InflateDownloadEvent(const nsAString & aJSON, nsIStkDownloadEvent * *_retval) override; \
  NS_IMETHOD CreateTimer(JS::HandleValue aStkTimerMessage, nsIStkTimer * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKCMDFACTORY(_to) \
  NS_IMETHOD CreateCommand(JS::HandleValue aCommandDetails, nsIStkProactiveCmd * *_retval) override { return _to CreateCommand(aCommandDetails, _retval); } \
  NS_IMETHOD CreateCommandMessage(nsIStkProactiveCmd *aStkProactiveCmd, JS::MutableHandleValue _retval) override { return _to CreateCommandMessage(aStkProactiveCmd, _retval); } \
  NS_IMETHOD DeflateCommand(nsIStkProactiveCmd *aStkProactiveCmd, nsAString & _retval) override { return _to DeflateCommand(aStkProactiveCmd, _retval); } \
  NS_IMETHOD InflateCommand(const nsAString & aJSON, nsIStkProactiveCmd * *_retval) override { return _to InflateCommand(aJSON, _retval); } \
  NS_IMETHOD CreateResponse(JS::HandleValue aResponseMessage, nsIStkTerminalResponse * *_retval) override { return _to CreateResponse(aResponseMessage, _retval); } \
  NS_IMETHOD CreateResponseMessage(nsIStkTerminalResponse *aStkTerminalResponse, JS::MutableHandleValue _retval) override { return _to CreateResponseMessage(aStkTerminalResponse, _retval); } \
  NS_IMETHOD DeflateResponse(nsIStkTerminalResponse *aStkTerminalResponse, nsAString & _retval) override { return _to DeflateResponse(aStkTerminalResponse, _retval); } \
  NS_IMETHOD InflateResponse(const nsAString & aJSON, nsIStkTerminalResponse * *_retval) override { return _to InflateResponse(aJSON, _retval); } \
  NS_IMETHOD CreateEvent(JS::HandleValue aEventMessage, nsIStkDownloadEvent * *_retval) override { return _to CreateEvent(aEventMessage, _retval); } \
  NS_IMETHOD CreateEventMessage(nsIStkDownloadEvent *aStkDownloadEvent, JS::MutableHandleValue _retval) override { return _to CreateEventMessage(aStkDownloadEvent, _retval); } \
  NS_IMETHOD DeflateDownloadEvent(nsIStkDownloadEvent *aStkDownloadEvent, nsAString & _retval) override { return _to DeflateDownloadEvent(aStkDownloadEvent, _retval); } \
  NS_IMETHOD InflateDownloadEvent(const nsAString & aJSON, nsIStkDownloadEvent * *_retval) override { return _to InflateDownloadEvent(aJSON, _retval); } \
  NS_IMETHOD CreateTimer(JS::HandleValue aStkTimerMessage, nsIStkTimer * *_retval) override { return _to CreateTimer(aStkTimerMessage, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKCMDFACTORY(_to) \
  NS_IMETHOD CreateCommand(JS::HandleValue aCommandDetails, nsIStkProactiveCmd * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateCommand(aCommandDetails, _retval); } \
  NS_IMETHOD CreateCommandMessage(nsIStkProactiveCmd *aStkProactiveCmd, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateCommandMessage(aStkProactiveCmd, _retval); } \
  NS_IMETHOD DeflateCommand(nsIStkProactiveCmd *aStkProactiveCmd, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeflateCommand(aStkProactiveCmd, _retval); } \
  NS_IMETHOD InflateCommand(const nsAString & aJSON, nsIStkProactiveCmd * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InflateCommand(aJSON, _retval); } \
  NS_IMETHOD CreateResponse(JS::HandleValue aResponseMessage, nsIStkTerminalResponse * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateResponse(aResponseMessage, _retval); } \
  NS_IMETHOD CreateResponseMessage(nsIStkTerminalResponse *aStkTerminalResponse, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateResponseMessage(aStkTerminalResponse, _retval); } \
  NS_IMETHOD DeflateResponse(nsIStkTerminalResponse *aStkTerminalResponse, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeflateResponse(aStkTerminalResponse, _retval); } \
  NS_IMETHOD InflateResponse(const nsAString & aJSON, nsIStkTerminalResponse * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InflateResponse(aJSON, _retval); } \
  NS_IMETHOD CreateEvent(JS::HandleValue aEventMessage, nsIStkDownloadEvent * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateEvent(aEventMessage, _retval); } \
  NS_IMETHOD CreateEventMessage(nsIStkDownloadEvent *aStkDownloadEvent, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateEventMessage(aStkDownloadEvent, _retval); } \
  NS_IMETHOD DeflateDownloadEvent(nsIStkDownloadEvent *aStkDownloadEvent, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeflateDownloadEvent(aStkDownloadEvent, _retval); } \
  NS_IMETHOD InflateDownloadEvent(const nsAString & aJSON, nsIStkDownloadEvent * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InflateDownloadEvent(aJSON, _retval); } \
  NS_IMETHOD CreateTimer(JS::HandleValue aStkTimerMessage, nsIStkTimer * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTimer(aStkTimerMessage, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkCmdFactory : public nsIStkCmdFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKCMDFACTORY

  nsStkCmdFactory();

private:
  ~nsStkCmdFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkCmdFactory, nsIStkCmdFactory)

nsStkCmdFactory::nsStkCmdFactory()
{
  /* member initializers and constructor code */
}

nsStkCmdFactory::~nsStkCmdFactory()
{
  /* destructor code */
}

/* nsIStkProactiveCmd createCommand (in jsval aCommandDetails); */
NS_IMETHODIMP nsStkCmdFactory::CreateCommand(JS::HandleValue aCommandDetails, nsIStkProactiveCmd * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval createCommandMessage (in nsIStkProactiveCmd aStkProactiveCmd); */
NS_IMETHODIMP nsStkCmdFactory::CreateCommandMessage(nsIStkProactiveCmd *aStkProactiveCmd, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString deflateCommand (in nsIStkProactiveCmd aStkProactiveCmd); */
NS_IMETHODIMP nsStkCmdFactory::DeflateCommand(nsIStkProactiveCmd *aStkProactiveCmd, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStkProactiveCmd inflateCommand (in AString aJSON); */
NS_IMETHODIMP nsStkCmdFactory::InflateCommand(const nsAString & aJSON, nsIStkProactiveCmd * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStkTerminalResponse createResponse (in jsval aResponseMessage); */
NS_IMETHODIMP nsStkCmdFactory::CreateResponse(JS::HandleValue aResponseMessage, nsIStkTerminalResponse * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval createResponseMessage (in nsIStkTerminalResponse aStkTerminalResponse); */
NS_IMETHODIMP nsStkCmdFactory::CreateResponseMessage(nsIStkTerminalResponse *aStkTerminalResponse, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString deflateResponse (in nsIStkTerminalResponse aStkTerminalResponse); */
NS_IMETHODIMP nsStkCmdFactory::DeflateResponse(nsIStkTerminalResponse *aStkTerminalResponse, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStkTerminalResponse inflateResponse (in AString aJSON); */
NS_IMETHODIMP nsStkCmdFactory::InflateResponse(const nsAString & aJSON, nsIStkTerminalResponse * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStkDownloadEvent createEvent (in jsval aEventMessage); */
NS_IMETHODIMP nsStkCmdFactory::CreateEvent(JS::HandleValue aEventMessage, nsIStkDownloadEvent * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval createEventMessage (in nsIStkDownloadEvent aStkDownloadEvent); */
NS_IMETHODIMP nsStkCmdFactory::CreateEventMessage(nsIStkDownloadEvent *aStkDownloadEvent, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString deflateDownloadEvent (in nsIStkDownloadEvent aStkDownloadEvent); */
NS_IMETHODIMP nsStkCmdFactory::DeflateDownloadEvent(nsIStkDownloadEvent *aStkDownloadEvent, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStkDownloadEvent inflateDownloadEvent (in AString aJSON); */
NS_IMETHODIMP nsStkCmdFactory::InflateDownloadEvent(const nsAString & aJSON, nsIStkDownloadEvent * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStkTimer createTimer (in jsval aStkTimerMessage); */
NS_IMETHODIMP nsStkCmdFactory::CreateTimer(JS::HandleValue aStkTimerMessage, nsIStkTimer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStkCmdFactory_h__ */
