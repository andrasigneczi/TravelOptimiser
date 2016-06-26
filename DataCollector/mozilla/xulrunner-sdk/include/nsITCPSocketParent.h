/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITCPSocketParent.idl
 */

#ifndef __gen_nsITCPSocketParent_h__
#define __gen_nsITCPSocketParent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMTCPSocket; /* forward declaration */

class nsIDOMTCPServerSocket; /* forward declaration */

class nsITCPServerSocketParent; /* forward declaration */

class nsITCPSocketIntermediary; /* forward declaration */


/* starting interface:    nsITCPSocketParent */
#define NS_ITCPSOCKETPARENT_IID_STR "6f040bf0-6852-11e3-949a-0800200c9a66"

#define NS_ITCPSOCKETPARENT_IID \
  {0x6f040bf0, 0x6852, 0x11e3, \
    { 0x94, 0x9a, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsITCPSocketParent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETPARENT_IID)

  /* [implicit_jscontext] void initJS (in jsval intermediary); */
  NS_IMETHOD InitJS(JS::HandleValue intermediary, JSContext* cx) = 0;

  /* [implicit_jscontext] void sendEvent (in DOMString type, in jsval data, in DOMString readyState); */
  NS_IMETHOD SendEvent(const nsAString & type, JS::HandleValue data, const nsAString & readyState, JSContext* cx) = 0;

  /* [implicit_jscontext] void setSocketAndIntermediary (in nsIDOMTCPSocket socket, in nsITCPSocketIntermediary intermediary); */
  NS_IMETHOD SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx) = 0;

  /* void sendUpdateBufferedAmount (in uint32_t bufferedAmount, in uint32_t trackingNumber); */
  NS_IMETHOD SendUpdateBufferedAmount(uint32_t bufferedAmount, uint32_t trackingNumber) = 0;

  /* readonly attribute DOMString host; */
  NS_IMETHOD GetHost(nsAString & aHost) = 0;

  /* readonly attribute unsigned short port; */
  NS_IMETHOD GetPort(uint16_t *aPort) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketParent, NS_ITCPSOCKETPARENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETPARENT \
  NS_IMETHOD InitJS(JS::HandleValue intermediary, JSContext* cx) override; \
  NS_IMETHOD SendEvent(const nsAString & type, JS::HandleValue data, const nsAString & readyState, JSContext* cx) override; \
  NS_IMETHOD SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx) override; \
  NS_IMETHOD SendUpdateBufferedAmount(uint32_t bufferedAmount, uint32_t trackingNumber) override; \
  NS_IMETHOD GetHost(nsAString & aHost) override; \
  NS_IMETHOD GetPort(uint16_t *aPort) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETPARENT(_to) \
  NS_IMETHOD InitJS(JS::HandleValue intermediary, JSContext* cx) override { return _to InitJS(intermediary, cx); } \
  NS_IMETHOD SendEvent(const nsAString & type, JS::HandleValue data, const nsAString & readyState, JSContext* cx) override { return _to SendEvent(type, data, readyState, cx); } \
  NS_IMETHOD SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx) override { return _to SetSocketAndIntermediary(socket, intermediary, cx); } \
  NS_IMETHOD SendUpdateBufferedAmount(uint32_t bufferedAmount, uint32_t trackingNumber) override { return _to SendUpdateBufferedAmount(bufferedAmount, trackingNumber); } \
  NS_IMETHOD GetHost(nsAString & aHost) override { return _to GetHost(aHost); } \
  NS_IMETHOD GetPort(uint16_t *aPort) override { return _to GetPort(aPort); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETPARENT(_to) \
  NS_IMETHOD InitJS(JS::HandleValue intermediary, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InitJS(intermediary, cx); } \
  NS_IMETHOD SendEvent(const nsAString & type, JS::HandleValue data, const nsAString & readyState, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendEvent(type, data, readyState, cx); } \
  NS_IMETHOD SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSocketAndIntermediary(socket, intermediary, cx); } \
  NS_IMETHOD SendUpdateBufferedAmount(uint32_t bufferedAmount, uint32_t trackingNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendUpdateBufferedAmount(bufferedAmount, trackingNumber); } \
  NS_IMETHOD GetHost(nsAString & aHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD GetPort(uint16_t *aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketParent : public nsITCPSocketParent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETPARENT

  nsTCPSocketParent();

private:
  ~nsTCPSocketParent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTCPSocketParent, nsITCPSocketParent)

nsTCPSocketParent::nsTCPSocketParent()
{
  /* member initializers and constructor code */
}

nsTCPSocketParent::~nsTCPSocketParent()
{
  /* destructor code */
}

/* [implicit_jscontext] void initJS (in jsval intermediary); */
NS_IMETHODIMP nsTCPSocketParent::InitJS(JS::HandleValue intermediary, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void sendEvent (in DOMString type, in jsval data, in DOMString readyState); */
NS_IMETHODIMP nsTCPSocketParent::SendEvent(const nsAString & type, JS::HandleValue data, const nsAString & readyState, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setSocketAndIntermediary (in nsIDOMTCPSocket socket, in nsITCPSocketIntermediary intermediary); */
NS_IMETHODIMP nsTCPSocketParent::SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendUpdateBufferedAmount (in uint32_t bufferedAmount, in uint32_t trackingNumber); */
NS_IMETHODIMP nsTCPSocketParent::SendUpdateBufferedAmount(uint32_t bufferedAmount, uint32_t trackingNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString host; */
NS_IMETHODIMP nsTCPSocketParent::GetHost(nsAString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short port; */
NS_IMETHODIMP nsTCPSocketParent::GetPort(uint16_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITCPSocketIntermediary */
#define NS_ITCPSOCKETINTERMEDIARY_IID_STR "aa9bd46d-26bf-4ba8-9c18-ba02482c02f0"

#define NS_ITCPSOCKETINTERMEDIARY_IID \
  {0xaa9bd46d, 0x26bf, 0x4ba8, \
    { 0x9c, 0x18, 0xba, 0x02, 0x48, 0x2c, 0x02, 0xf0 }}

class NS_NO_VTABLE nsITCPSocketIntermediary : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETINTERMEDIARY_IID)

  /* nsIDOMTCPSocket open (in nsITCPSocketParent parent, in DOMString host, in unsigned short port, in boolean useSSL, in DOMString binaryType, in unsigned long appId, in boolean inBrowser); */
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPSocket * *_retval) = 0;

  /* nsIDOMTCPServerSocket listen (in nsITCPServerSocketParent parent, in unsigned short port, in unsigned short backlog, in DOMString binaryType, in unsigned long appId, in boolean inBrowser); */
  NS_IMETHOD Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPServerSocket * *_retval) = 0;

  /* void onRecvSendString (in DOMString data, in uint32_t trackingNumber); */
  NS_IMETHOD OnRecvSendString(const nsAString & data, uint32_t trackingNumber) = 0;

  /* void onRecvSendArrayBuffer (in jsval data, in uint32_t trackingNumber); */
  NS_IMETHOD OnRecvSendArrayBuffer(JS::HandleValue data, uint32_t trackingNumber) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketIntermediary, NS_ITCPSOCKETINTERMEDIARY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETINTERMEDIARY \
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPSocket * *_retval) override; \
  NS_IMETHOD Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPServerSocket * *_retval) override; \
  NS_IMETHOD OnRecvSendString(const nsAString & data, uint32_t trackingNumber) override; \
  NS_IMETHOD OnRecvSendArrayBuffer(JS::HandleValue data, uint32_t trackingNumber) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETINTERMEDIARY(_to) \
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPSocket * *_retval) override { return _to Open(parent, host, port, useSSL, binaryType, appId, inBrowser, _retval); } \
  NS_IMETHOD Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPServerSocket * *_retval) override { return _to Listen(parent, port, backlog, binaryType, appId, inBrowser, _retval); } \
  NS_IMETHOD OnRecvSendString(const nsAString & data, uint32_t trackingNumber) override { return _to OnRecvSendString(data, trackingNumber); } \
  NS_IMETHOD OnRecvSendArrayBuffer(JS::HandleValue data, uint32_t trackingNumber) override { return _to OnRecvSendArrayBuffer(data, trackingNumber); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETINTERMEDIARY(_to) \
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPSocket * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(parent, host, port, useSSL, binaryType, appId, inBrowser, _retval); } \
  NS_IMETHOD Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPServerSocket * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Listen(parent, port, backlog, binaryType, appId, inBrowser, _retval); } \
  NS_IMETHOD OnRecvSendString(const nsAString & data, uint32_t trackingNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRecvSendString(data, trackingNumber); } \
  NS_IMETHOD OnRecvSendArrayBuffer(JS::HandleValue data, uint32_t trackingNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRecvSendArrayBuffer(data, trackingNumber); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketIntermediary : public nsITCPSocketIntermediary
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETINTERMEDIARY

  nsTCPSocketIntermediary();

private:
  ~nsTCPSocketIntermediary();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTCPSocketIntermediary, nsITCPSocketIntermediary)

nsTCPSocketIntermediary::nsTCPSocketIntermediary()
{
  /* member initializers and constructor code */
}

nsTCPSocketIntermediary::~nsTCPSocketIntermediary()
{
  /* destructor code */
}

/* nsIDOMTCPSocket open (in nsITCPSocketParent parent, in DOMString host, in unsigned short port, in boolean useSSL, in DOMString binaryType, in unsigned long appId, in boolean inBrowser); */
NS_IMETHODIMP nsTCPSocketIntermediary::Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPSocket * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMTCPServerSocket listen (in nsITCPServerSocketParent parent, in unsigned short port, in unsigned short backlog, in DOMString binaryType, in unsigned long appId, in boolean inBrowser); */
NS_IMETHODIMP nsTCPSocketIntermediary::Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, uint32_t appId, bool inBrowser, nsIDOMTCPServerSocket * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onRecvSendString (in DOMString data, in uint32_t trackingNumber); */
NS_IMETHODIMP nsTCPSocketIntermediary::OnRecvSendString(const nsAString & data, uint32_t trackingNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onRecvSendArrayBuffer (in jsval data, in uint32_t trackingNumber); */
NS_IMETHODIMP nsTCPSocketIntermediary::OnRecvSendArrayBuffer(JS::HandleValue data, uint32_t trackingNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITCPSocketParent_h__ */
