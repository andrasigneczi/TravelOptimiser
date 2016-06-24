/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUDPSocketChild.idl
 */

#ifndef __gen_nsIUDPSocketChild_h__
#define __gen_nsIUDPSocketChild_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsINetAddr_h__
#include "nsINetAddr.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUDPSocketInternal; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIPrincipal; /* forward declaration */

namespace mozilla {
namespace net {
union NetAddr;
}
}

/* starting interface:    nsIUDPSocketChild */
#define NS_IUDPSOCKETCHILD_IID_STR "481f15ce-224a-40b6-9927-7effbc326776"

#define NS_IUDPSOCKETCHILD_IID \
  {0x481f15ce, 0x224a, 0x40b6, \
    { 0x99, 0x27, 0x7e, 0xff, 0xbc, 0x32, 0x67, 0x76 }}

class NS_NO_VTABLE nsIUDPSocketChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKETCHILD_IID)

  /* readonly attribute unsigned short localPort; */
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) = 0;

  /* readonly attribute AUTF8String localAddress; */
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) = 0;

  /* attribute AUTF8String filterName; */
  NS_IMETHOD GetFilterName(nsACString & aFilterName) = 0;
  NS_IMETHOD SetFilterName(const nsACString & aFilterName) = 0;

  /* [noscript] void setBackgroundSpinsEvents (); */
  NS_IMETHOD SetBackgroundSpinsEvents(void) = 0;

  /* void bind (in nsIUDPSocketInternal socket, in nsIPrincipal principal, in AUTF8String host, in unsigned short port, in bool addressReuse, in bool loopback); */
  NS_IMETHOD Bind(nsIUDPSocketInternal *socket, nsIPrincipal *principal, const nsACString & host, uint16_t port, bool addressReuse, bool loopback) = 0;

  /* void send (in AUTF8String host, in unsigned short port, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength) = 0;

  /* void sendWithAddr (in nsINetAddr addr, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength) = 0;

  /* [noscript] void sendWithAddress ([const] in NetAddrPtr addr, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength) = 0;

  /* void sendBinaryStream (in AUTF8String host, in unsigned short port, in nsIInputStream stream); */
  NS_IMETHOD SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void joinMulticast (in AUTF8String multicastAddress, in AUTF8String iface); */
  NS_IMETHOD JoinMulticast(const nsACString & multicastAddress, const nsACString & iface) = 0;

  /* void leaveMulticast (in AUTF8String multicastAddress, in AUTF8String iface); */
  NS_IMETHOD LeaveMulticast(const nsACString & multicastAddress, const nsACString & iface) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocketChild, NS_IUDPSOCKETCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKETCHILD \
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) override; \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) override; \
  NS_IMETHOD GetFilterName(nsACString & aFilterName) override; \
  NS_IMETHOD SetFilterName(const nsACString & aFilterName) override; \
  NS_IMETHOD SetBackgroundSpinsEvents(void) override; \
  NS_IMETHOD Bind(nsIUDPSocketInternal *socket, nsIPrincipal *principal, const nsACString & host, uint16_t port, bool addressReuse, bool loopback) override; \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength) override; \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength) override; \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength) override; \
  NS_IMETHOD SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream) override; \
  NS_IMETHOD Close(void) override; \
  NS_IMETHOD JoinMulticast(const nsACString & multicastAddress, const nsACString & iface) override; \
  NS_IMETHOD LeaveMulticast(const nsACString & multicastAddress, const nsACString & iface) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKETCHILD(_to) \
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) override { return _to GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) override { return _to GetLocalAddress(aLocalAddress); } \
  NS_IMETHOD GetFilterName(nsACString & aFilterName) override { return _to GetFilterName(aFilterName); } \
  NS_IMETHOD SetFilterName(const nsACString & aFilterName) override { return _to SetFilterName(aFilterName); } \
  NS_IMETHOD SetBackgroundSpinsEvents(void) override { return _to SetBackgroundSpinsEvents(); } \
  NS_IMETHOD Bind(nsIUDPSocketInternal *socket, nsIPrincipal *principal, const nsACString & host, uint16_t port, bool addressReuse, bool loopback) override { return _to Bind(socket, principal, host, port, addressReuse, loopback); } \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength) override { return _to Send(host, port, bytes, byteLength); } \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength) override { return _to SendWithAddr(addr, bytes, byteLength); } \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength) override { return _to SendWithAddress(addr, bytes, byteLength); } \
  NS_IMETHOD SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream) override { return _to SendBinaryStream(host, port, stream); } \
  NS_IMETHOD Close(void) override { return _to Close(); } \
  NS_IMETHOD JoinMulticast(const nsACString & multicastAddress, const nsACString & iface) override { return _to JoinMulticast(multicastAddress, iface); } \
  NS_IMETHOD LeaveMulticast(const nsACString & multicastAddress, const nsACString & iface) override { return _to LeaveMulticast(multicastAddress, iface); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKETCHILD(_to) \
  NS_IMETHOD GetLocalPort(uint16_t *aLocalPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalAddress(aLocalAddress); } \
  NS_IMETHOD GetFilterName(nsACString & aFilterName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterName(aFilterName); } \
  NS_IMETHOD SetFilterName(const nsACString & aFilterName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilterName(aFilterName); } \
  NS_IMETHOD SetBackgroundSpinsEvents(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBackgroundSpinsEvents(); } \
  NS_IMETHOD Bind(nsIUDPSocketInternal *socket, nsIPrincipal *principal, const nsACString & host, uint16_t port, bool addressReuse, bool loopback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Bind(socket, principal, host, port, addressReuse, loopback); } \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(host, port, bytes, byteLength); } \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWithAddr(addr, bytes, byteLength); } \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWithAddress(addr, bytes, byteLength); } \
  NS_IMETHOD SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendBinaryStream(host, port, stream); } \
  NS_IMETHOD Close(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD JoinMulticast(const nsACString & multicastAddress, const nsACString & iface) override { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinMulticast(multicastAddress, iface); } \
  NS_IMETHOD LeaveMulticast(const nsACString & multicastAddress, const nsACString & iface) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LeaveMulticast(multicastAddress, iface); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocketChild : public nsIUDPSocketChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKETCHILD

  nsUDPSocketChild();

private:
  ~nsUDPSocketChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUDPSocketChild, nsIUDPSocketChild)

nsUDPSocketChild::nsUDPSocketChild()
{
  /* member initializers and constructor code */
}

nsUDPSocketChild::~nsUDPSocketChild()
{
  /* destructor code */
}

/* readonly attribute unsigned short localPort; */
NS_IMETHODIMP nsUDPSocketChild::GetLocalPort(uint16_t *aLocalPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String localAddress; */
NS_IMETHODIMP nsUDPSocketChild::GetLocalAddress(nsACString & aLocalAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String filterName; */
NS_IMETHODIMP nsUDPSocketChild::GetFilterName(nsACString & aFilterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUDPSocketChild::SetFilterName(const nsACString & aFilterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setBackgroundSpinsEvents (); */
NS_IMETHODIMP nsUDPSocketChild::SetBackgroundSpinsEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void bind (in nsIUDPSocketInternal socket, in nsIPrincipal principal, in AUTF8String host, in unsigned short port, in bool addressReuse, in bool loopback); */
NS_IMETHODIMP nsUDPSocketChild::Bind(nsIUDPSocketInternal *socket, nsIPrincipal *principal, const nsACString & host, uint16_t port, bool addressReuse, bool loopback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send (in AUTF8String host, in unsigned short port, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
NS_IMETHODIMP nsUDPSocketChild::Send(const nsACString & host, uint16_t port, const uint8_t *bytes, uint32_t byteLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendWithAddr (in nsINetAddr addr, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
NS_IMETHODIMP nsUDPSocketChild::SendWithAddr(nsINetAddr *addr, const uint8_t *bytes, uint32_t byteLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void sendWithAddress ([const] in NetAddrPtr addr, [array, size_is (byteLength), const] in uint8_t bytes, in unsigned long byteLength); */
NS_IMETHODIMP nsUDPSocketChild::SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *bytes, uint32_t byteLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendBinaryStream (in AUTF8String host, in unsigned short port, in nsIInputStream stream); */
NS_IMETHODIMP nsUDPSocketChild::SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsUDPSocketChild::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void joinMulticast (in AUTF8String multicastAddress, in AUTF8String iface); */
NS_IMETHODIMP nsUDPSocketChild::JoinMulticast(const nsACString & multicastAddress, const nsACString & iface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void leaveMulticast (in AUTF8String multicastAddress, in AUTF8String iface); */
NS_IMETHODIMP nsUDPSocketChild::LeaveMulticast(const nsACString & multicastAddress, const nsACString & iface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUDPSocketInternal */
#define NS_IUDPSOCKETINTERNAL_IID_STR "44cd9ad5-d574-4169-baf9-e1af0648a143"

#define NS_IUDPSOCKETINTERNAL_IID \
  {0x44cd9ad5, 0xd574, 0x4169, \
    { 0xba, 0xf9, 0xe1, 0xaf, 0x06, 0x48, 0xa1, 0x43 }}

class NS_NO_VTABLE nsIUDPSocketInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKETINTERNAL_IID)

  /* void callListenerOpened (); */
  NS_IMETHOD CallListenerOpened(void) = 0;

  /* void callListenerClosed (); */
  NS_IMETHOD CallListenerClosed(void) = 0;

  /* void callListenerReceivedData (in AUTF8String host, in unsigned short port, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
  NS_IMETHOD CallListenerReceivedData(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength) = 0;

  /* void callListenerError (in AUTF8String message, in AUTF8String filename, in uint32_t lineNumber); */
  NS_IMETHOD CallListenerError(const nsACString & message, const nsACString & filename, uint32_t lineNumber) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocketInternal, NS_IUDPSOCKETINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKETINTERNAL \
  NS_IMETHOD CallListenerOpened(void) override; \
  NS_IMETHOD CallListenerClosed(void) override; \
  NS_IMETHOD CallListenerReceivedData(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength) override; \
  NS_IMETHOD CallListenerError(const nsACString & message, const nsACString & filename, uint32_t lineNumber) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKETINTERNAL(_to) \
  NS_IMETHOD CallListenerOpened(void) override { return _to CallListenerOpened(); } \
  NS_IMETHOD CallListenerClosed(void) override { return _to CallListenerClosed(); } \
  NS_IMETHOD CallListenerReceivedData(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength) override { return _to CallListenerReceivedData(host, port, data, dataLength); } \
  NS_IMETHOD CallListenerError(const nsACString & message, const nsACString & filename, uint32_t lineNumber) override { return _to CallListenerError(message, filename, lineNumber); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKETINTERNAL(_to) \
  NS_IMETHOD CallListenerOpened(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerOpened(); } \
  NS_IMETHOD CallListenerClosed(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerClosed(); } \
  NS_IMETHOD CallListenerReceivedData(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerReceivedData(host, port, data, dataLength); } \
  NS_IMETHOD CallListenerError(const nsACString & message, const nsACString & filename, uint32_t lineNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CallListenerError(message, filename, lineNumber); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocketInternal : public nsIUDPSocketInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKETINTERNAL

  nsUDPSocketInternal();

private:
  ~nsUDPSocketInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUDPSocketInternal, nsIUDPSocketInternal)

nsUDPSocketInternal::nsUDPSocketInternal()
{
  /* member initializers and constructor code */
}

nsUDPSocketInternal::~nsUDPSocketInternal()
{
  /* destructor code */
}

/* void callListenerOpened (); */
NS_IMETHODIMP nsUDPSocketInternal::CallListenerOpened()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerClosed (); */
NS_IMETHODIMP nsUDPSocketInternal::CallListenerClosed()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerReceivedData (in AUTF8String host, in unsigned short port, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
NS_IMETHODIMP nsUDPSocketInternal::CallListenerReceivedData(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void callListenerError (in AUTF8String message, in AUTF8String filename, in uint32_t lineNumber); */
NS_IMETHODIMP nsUDPSocketInternal::CallListenerError(const nsACString & message, const nsACString & filename, uint32_t lineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUDPSocketChild_h__ */
