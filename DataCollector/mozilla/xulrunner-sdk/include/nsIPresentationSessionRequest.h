/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPresentationSessionRequest.idl
 */

#ifndef __gen_nsIPresentationSessionRequest_h__
#define __gen_nsIPresentationSessionRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPresentationDevice; /* forward declaration */

class nsIPresentationControlChannel; /* forward declaration */

#define PRESENTATION_SESSION_REQUEST_TOPIC "presentation-session-request"

/* starting interface:    nsIPresentationSessionRequest */
#define NS_IPRESENTATIONSESSIONREQUEST_IID_STR "d808a084-d0f8-455a-a8df-5879e05a755b"

#define NS_IPRESENTATIONSESSIONREQUEST_IID \
  {0xd808a084, 0xd0f8, 0x455a, \
    { 0xa8, 0xdf, 0x58, 0x79, 0xe0, 0x5a, 0x75, 0x5b }}

class NS_NO_VTABLE nsIPresentationSessionRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRESENTATIONSESSIONREQUEST_IID)

  /* readonly attribute nsIPresentationDevice device; */
  NS_IMETHOD GetDevice(nsIPresentationDevice * *aDevice) = 0;

  /* readonly attribute DOMString url; */
  NS_IMETHOD GetUrl(nsAString & aUrl) = 0;

  /* readonly attribute DOMString presentationId; */
  NS_IMETHOD GetPresentationId(nsAString & aPresentationId) = 0;

  /* readonly attribute nsIPresentationControlChannel controlChannel; */
  NS_IMETHOD GetControlChannel(nsIPresentationControlChannel * *aControlChannel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPresentationSessionRequest, NS_IPRESENTATIONSESSIONREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRESENTATIONSESSIONREQUEST \
  NS_IMETHOD GetDevice(nsIPresentationDevice * *aDevice) override; \
  NS_IMETHOD GetUrl(nsAString & aUrl) override; \
  NS_IMETHOD GetPresentationId(nsAString & aPresentationId) override; \
  NS_IMETHOD GetControlChannel(nsIPresentationControlChannel * *aControlChannel) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRESENTATIONSESSIONREQUEST(_to) \
  NS_IMETHOD GetDevice(nsIPresentationDevice * *aDevice) override { return _to GetDevice(aDevice); } \
  NS_IMETHOD GetUrl(nsAString & aUrl) override { return _to GetUrl(aUrl); } \
  NS_IMETHOD GetPresentationId(nsAString & aPresentationId) override { return _to GetPresentationId(aPresentationId); } \
  NS_IMETHOD GetControlChannel(nsIPresentationControlChannel * *aControlChannel) override { return _to GetControlChannel(aControlChannel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRESENTATIONSESSIONREQUEST(_to) \
  NS_IMETHOD GetDevice(nsIPresentationDevice * *aDevice) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDevice(aDevice); } \
  NS_IMETHOD GetUrl(nsAString & aUrl) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrl(aUrl); } \
  NS_IMETHOD GetPresentationId(nsAString & aPresentationId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresentationId(aPresentationId); } \
  NS_IMETHOD GetControlChannel(nsIPresentationControlChannel * *aControlChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControlChannel(aControlChannel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPresentationSessionRequest : public nsIPresentationSessionRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRESENTATIONSESSIONREQUEST

  nsPresentationSessionRequest();

private:
  ~nsPresentationSessionRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPresentationSessionRequest, nsIPresentationSessionRequest)

nsPresentationSessionRequest::nsPresentationSessionRequest()
{
  /* member initializers and constructor code */
}

nsPresentationSessionRequest::~nsPresentationSessionRequest()
{
  /* destructor code */
}

/* readonly attribute nsIPresentationDevice device; */
NS_IMETHODIMP nsPresentationSessionRequest::GetDevice(nsIPresentationDevice * *aDevice)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString url; */
NS_IMETHODIMP nsPresentationSessionRequest::GetUrl(nsAString & aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString presentationId; */
NS_IMETHODIMP nsPresentationSessionRequest::GetPresentationId(nsAString & aPresentationId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPresentationControlChannel controlChannel; */
NS_IMETHODIMP nsPresentationSessionRequest::GetControlChannel(nsIPresentationControlChannel * *aControlChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPresentationSessionRequest_h__ */
