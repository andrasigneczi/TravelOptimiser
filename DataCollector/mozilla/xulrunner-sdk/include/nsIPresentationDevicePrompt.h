/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPresentationDevicePrompt.idl
 */

#ifndef __gen_nsIPresentationDevicePrompt_h__
#define __gen_nsIPresentationDevicePrompt_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPresentationDevice; /* forward declaration */

#define PRESENTATION_DEVICE_PROMPT_CONTRACTID "@mozilla.org/presentation-device/prompt;1"

/* starting interface:    nsIPresentationDeviceRequest */
#define NS_IPRESENTATIONDEVICEREQUEST_IID_STR "b2aa7f6a-9448-446a-bba4-9c29638b0ed4"

#define NS_IPRESENTATIONDEVICEREQUEST_IID \
  {0xb2aa7f6a, 0x9448, 0x446a, \
    { 0xbb, 0xa4, 0x9c, 0x29, 0x63, 0x8b, 0x0e, 0xd4 }}

class NS_NO_VTABLE nsIPresentationDeviceRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRESENTATIONDEVICEREQUEST_IID)

  /* readonly attribute DOMString origin; */
  NS_IMETHOD GetOrigin(nsAString & aOrigin) = 0;

  /* readonly attribute DOMString requestURL; */
  NS_IMETHOD GetRequestURL(nsAString & aRequestURL) = 0;

  /* void select (in nsIPresentationDevice device); */
  NS_IMETHOD Select(nsIPresentationDevice *device) = 0;

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPresentationDeviceRequest, NS_IPRESENTATIONDEVICEREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRESENTATIONDEVICEREQUEST \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) override; \
  NS_IMETHOD GetRequestURL(nsAString & aRequestURL) override; \
  NS_IMETHOD Select(nsIPresentationDevice *device) override; \
  NS_IMETHOD Cancel(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRESENTATIONDEVICEREQUEST(_to) \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) override { return _to GetOrigin(aOrigin); } \
  NS_IMETHOD GetRequestURL(nsAString & aRequestURL) override { return _to GetRequestURL(aRequestURL); } \
  NS_IMETHOD Select(nsIPresentationDevice *device) override { return _to Select(device); } \
  NS_IMETHOD Cancel(void) override { return _to Cancel(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRESENTATIONDEVICEREQUEST(_to) \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrigin(aOrigin); } \
  NS_IMETHOD GetRequestURL(nsAString & aRequestURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestURL(aRequestURL); } \
  NS_IMETHOD Select(nsIPresentationDevice *device) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Select(device); } \
  NS_IMETHOD Cancel(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPresentationDeviceRequest : public nsIPresentationDeviceRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRESENTATIONDEVICEREQUEST

  nsPresentationDeviceRequest();

private:
  ~nsPresentationDeviceRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPresentationDeviceRequest, nsIPresentationDeviceRequest)

nsPresentationDeviceRequest::nsPresentationDeviceRequest()
{
  /* member initializers and constructor code */
}

nsPresentationDeviceRequest::~nsPresentationDeviceRequest()
{
  /* destructor code */
}

/* readonly attribute DOMString origin; */
NS_IMETHODIMP nsPresentationDeviceRequest::GetOrigin(nsAString & aOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString requestURL; */
NS_IMETHODIMP nsPresentationDeviceRequest::GetRequestURL(nsAString & aRequestURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void select (in nsIPresentationDevice device); */
NS_IMETHODIMP nsPresentationDeviceRequest::Select(nsIPresentationDevice *device)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsPresentationDeviceRequest::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPresentationDevicePrompt */
#define NS_IPRESENTATIONDEVICEPROMPT_IID_STR "ac1a7e44-de86-454f-a9f1-276de2539831"

#define NS_IPRESENTATIONDEVICEPROMPT_IID \
  {0xac1a7e44, 0xde86, 0x454f, \
    { 0xa9, 0xf1, 0x27, 0x6d, 0xe2, 0x53, 0x98, 0x31 }}

class NS_NO_VTABLE nsIPresentationDevicePrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRESENTATIONDEVICEPROMPT_IID)

  /* void promptDeviceSelection (in nsIPresentationDeviceRequest request); */
  NS_IMETHOD PromptDeviceSelection(nsIPresentationDeviceRequest *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPresentationDevicePrompt, NS_IPRESENTATIONDEVICEPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRESENTATIONDEVICEPROMPT \
  NS_IMETHOD PromptDeviceSelection(nsIPresentationDeviceRequest *request) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRESENTATIONDEVICEPROMPT(_to) \
  NS_IMETHOD PromptDeviceSelection(nsIPresentationDeviceRequest *request) override { return _to PromptDeviceSelection(request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRESENTATIONDEVICEPROMPT(_to) \
  NS_IMETHOD PromptDeviceSelection(nsIPresentationDeviceRequest *request) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptDeviceSelection(request); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPresentationDevicePrompt : public nsIPresentationDevicePrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRESENTATIONDEVICEPROMPT

  nsPresentationDevicePrompt();

private:
  ~nsPresentationDevicePrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPresentationDevicePrompt, nsIPresentationDevicePrompt)

nsPresentationDevicePrompt::nsPresentationDevicePrompt()
{
  /* member initializers and constructor code */
}

nsPresentationDevicePrompt::~nsPresentationDevicePrompt()
{
  /* destructor code */
}

/* void promptDeviceSelection (in nsIPresentationDeviceRequest request); */
NS_IMETHODIMP nsPresentationDevicePrompt::PromptDeviceSelection(nsIPresentationDeviceRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPresentationDevicePrompt_h__ */
