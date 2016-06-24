/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITCPSocketChild.idl
 */

#ifndef __gen_nsITCPSocketChild_h__
#define __gen_nsITCPSocketChild_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITCPSocketInternal; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsITCPSocketChild */
#define NS_ITCPSOCKETCHILD_IID_STR "4277aff0-4c33-11e3-8f96-0800200c9a66"

#define NS_ITCPSOCKETCHILD_IID \
  {0x4277aff0, 0x4c33, 0x11e3, \
    { 0x8f, 0x96, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsITCPSocketChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETCHILD_IID)

  /* [implicit_jscontext] void sendOpen (in nsITCPSocketInternal socket, in DOMString host, in unsigned short port, in boolean ssl, in DOMString binaryType, in nsIDOMWindow window, in jsval windowVal); */
  NS_IMETHOD SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx) = 0;

  /* [implicit_jscontext] void sendSend (in jsval data, in unsigned long byteOffset, in unsigned long byteLength, in unsigned long trackingNumber); */
  NS_IMETHOD SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx) = 0;

  /* void sendResume (); */
  NS_IMETHOD SendResume(void) = 0;

  /* void sendSuspend (); */
  NS_IMETHOD SendSuspend(void) = 0;

  /* void sendClose (); */
  NS_IMETHOD SendClose(void) = 0;

  /* void sendStartTLS (); */
  NS_IMETHOD SendStartTLS(void) = 0;

  /* [implicit_jscontext] void setSocketAndWindow (in nsITCPSocketInternal socket, in jsval windowVal); */
  NS_IMETHOD SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx) = 0;

  /* readonly attribute DOMString host; */
  NS_IMETHOD GetHost(nsAString & aHost) = 0;

  /* readonly attribute unsigned short port; */
  NS_IMETHOD GetPort(uint16_t *aPort) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketChild, NS_ITCPSOCKETCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETCHILD \
  NS_IMETHOD SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx) override; \
  NS_IMETHOD SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx) override; \
  NS_IMETHOD SendResume(void) override; \
  NS_IMETHOD SendSuspend(void) override; \
  NS_IMETHOD SendClose(void) override; \
  NS_IMETHOD SendStartTLS(void) override; \
  NS_IMETHOD SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx) override; \
  NS_IMETHOD GetHost(nsAString & aHost) override; \
  NS_IMETHOD GetPort(uint16_t *aPort) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETCHILD(_to) \
  NS_IMETHOD SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx) override { return _to SendOpen(socket, host, port, ssl, binaryType, window, windowVal, cx); } \
  NS_IMETHOD SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx) override { return _to SendSend(data, byteOffset, byteLength, trackingNumber, cx); } \
  NS_IMETHOD SendResume(void) override { return _to SendResume(); } \
  NS_IMETHOD SendSuspend(void) override { return _to SendSuspend(); } \
  NS_IMETHOD SendClose(void) override { return _to SendClose(); } \
  NS_IMETHOD SendStartTLS(void) override { return _to SendStartTLS(); } \
  NS_IMETHOD SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx) override { return _to SetSocketAndWindow(socket, windowVal, cx); } \
  NS_IMETHOD GetHost(nsAString & aHost) override { return _to GetHost(aHost); } \
  NS_IMETHOD GetPort(uint16_t *aPort) override { return _to GetPort(aPort); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETCHILD(_to) \
  NS_IMETHOD SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendOpen(socket, host, port, ssl, binaryType, window, windowVal, cx); } \
  NS_IMETHOD SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSend(data, byteOffset, byteLength, trackingNumber, cx); } \
  NS_IMETHOD SendResume(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendResume(); } \
  NS_IMETHOD SendSuspend(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSuspend(); } \
  NS_IMETHOD SendClose(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendClose(); } \
  NS_IMETHOD SendStartTLS(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendStartTLS(); } \
  NS_IMETHOD SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSocketAndWindow(socket, windowVal, cx); } \
  NS_IMETHOD GetHost(nsAString & aHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD GetPort(uint16_t *aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketChild : public nsITCPSocketChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETCHILD

  nsTCPSocketChild();

private:
  ~nsTCPSocketChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTCPSocketChild, nsITCPSocketChild)

nsTCPSocketChild::nsTCPSocketChild()
{
  /* member initializers and constructor code */
}

nsTCPSocketChild::~nsTCPSocketChild()
{
  /* destructor code */
}

/* [implicit_jscontext] void sendOpen (in nsITCPSocketInternal socket, in DOMString host, in unsigned short port, in boolean ssl, in DOMString binaryType, in nsIDOMWindow window, in jsval windowVal); */
NS_IMETHODIMP nsTCPSocketChild::SendOpen(nsITCPSocketInternal *socket, const nsAString & host, uint16_t port, bool ssl, const nsAString & binaryType, nsIDOMWindow *window, JS::HandleValue windowVal, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void sendSend (in jsval data, in unsigned long byteOffset, in unsigned long byteLength, in unsigned long trackingNumber); */
NS_IMETHODIMP nsTCPSocketChild::SendSend(JS::HandleValue data, uint32_t byteOffset, uint32_t byteLength, uint32_t trackingNumber, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendResume (); */
NS_IMETHODIMP nsTCPSocketChild::SendResume()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendSuspend (); */
NS_IMETHODIMP nsTCPSocketChild::SendSuspend()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendClose (); */
NS_IMETHODIMP nsTCPSocketChild::SendClose()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendStartTLS (); */
NS_IMETHODIMP nsTCPSocketChild::SendStartTLS()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setSocketAndWindow (in nsITCPSocketInternal socket, in jsval windowVal); */
NS_IMETHODIMP nsTCPSocketChild::SetSocketAndWindow(nsITCPSocketInternal *socket, JS::HandleValue windowVal, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString host; */
NS_IMETHODIMP nsTCPSocketChild::GetHost(nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short port; */
NS_IMETHODIMP nsTCPSocketChild::GetPort(uint16_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITCPSocketChild_h__ */
