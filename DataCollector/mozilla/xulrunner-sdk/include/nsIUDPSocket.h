/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUDPSocket.idl
 */

#ifndef __gen_nsIUDPSocket_h__
#define __gen_nsIUDPSocket_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsINetAddr; /* forward declaration */

class nsIUDPSocketListener; /* forward declaration */

class nsIUDPMessage; /* forward declaration */

class nsISocketTransport; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIPrincipal; /* forward declaration */

#include "nsTArrayForwardDeclare.h"
namespace mozilla {
namespace net {
union NetAddr;
}
}

/* starting interface:    nsIUDPSocket */
#define NS_IUDPSOCKET_IID_STR "e0377f7b-34a9-4d0f-8191-7e0cba77a52f"

#define NS_IUDPSOCKET_IID \
  {0xe0377f7b, 0x34a9, 0x4d0f, \
    { 0x81, 0x91, 0x7e, 0x0c, 0xba, 0x77, 0xa5, 0x2f }}

class NS_NO_VTABLE nsIUDPSocket : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKET_IID)

  /* [optional_argc] void init (in long aPort, in boolean aLoopbackOnly, in nsIPrincipal aPrincipal, [optional] in boolean aAddressReuse); */
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc) = 0;

  /* [noscript,optional_argc] void initWithAddress ([const] in NetAddrPtr aAddr, in nsIPrincipal aPrincipal, [optional] in boolean aAddressReuse); */
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void asyncListen (in nsIUDPSocketListener aListener); */
  NS_IMETHOD AsyncListen(nsIUDPSocketListener *aListener) = 0;

  /* readonly attribute nsINetAddr localAddr; */
  NS_IMETHOD GetLocalAddr(nsINetAddr * *aLocalAddr) = 0;

  /* readonly attribute long port; */
  NS_IMETHOD GetPort(int32_t *aPort) = 0;

  /* [noscript] NetAddr getAddress (); */
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) = 0;

  /* unsigned long send (in AUTF8String host, in unsigned short port, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) = 0;

  /* unsigned long sendWithAddr (in nsINetAddr addr, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) = 0;

  /* [noscript] unsigned long sendWithAddress ([const] in NetAddrPtr addr, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) = 0;

  /* void sendBinaryStream (in AUTF8String host, in unsigned short port, in nsIInputStream stream); */
  NS_IMETHOD SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream) = 0;

  /* void sendBinaryStreamWithAddress ([const] in NetAddrPtr addr, in nsIInputStream stream); */
  NS_IMETHOD SendBinaryStreamWithAddress(const mozilla::net::NetAddr *addr, nsIInputStream *stream) = 0;

  /* void joinMulticast (in AUTF8String addr, [optional] in AUTF8String iface); */
  NS_IMETHOD JoinMulticast(const nsACString & addr, const nsACString & iface) = 0;

  /* [noscript] void joinMulticastAddr ([const] in NetAddr addr, [const, optional] in NetAddrPtr iface); */
  NS_IMETHOD JoinMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface) = 0;

  /* void leaveMulticast (in AUTF8String addr, [optional] in AUTF8String iface); */
  NS_IMETHOD LeaveMulticast(const nsACString & addr, const nsACString & iface) = 0;

  /* [noscript] void leaveMulticastAddr ([const] in NetAddr addr, [const, optional] in NetAddrPtr iface); */
  NS_IMETHOD LeaveMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface) = 0;

  /* attribute boolean multicastLoopback; */
  NS_IMETHOD GetMulticastLoopback(bool *aMulticastLoopback) = 0;
  NS_IMETHOD SetMulticastLoopback(bool aMulticastLoopback) = 0;

  /* attribute AUTF8String multicastInterface; */
  NS_IMETHOD GetMulticastInterface(nsACString & aMulticastInterface) = 0;
  NS_IMETHOD SetMulticastInterface(const nsACString & aMulticastInterface) = 0;

  /* [noscript] attribute NetAddr multicastInterfaceAddr; */
  NS_IMETHOD GetMulticastInterfaceAddr(mozilla::net::NetAddr *aMulticastInterfaceAddr) = 0;
  NS_IMETHOD SetMulticastInterfaceAddr(mozilla::net::NetAddr aMulticastInterfaceAddr) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocket, NS_IUDPSOCKET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKET \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc) override; \
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc) override; \
  NS_IMETHOD Close(void) override; \
  NS_IMETHOD AsyncListen(nsIUDPSocketListener *aListener) override; \
  NS_IMETHOD GetLocalAddr(nsINetAddr * *aLocalAddr) override; \
  NS_IMETHOD GetPort(int32_t *aPort) override; \
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) override; \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) override; \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) override; \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) override; \
  NS_IMETHOD SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream) override; \
  NS_IMETHOD SendBinaryStreamWithAddress(const mozilla::net::NetAddr *addr, nsIInputStream *stream) override; \
  NS_IMETHOD JoinMulticast(const nsACString & addr, const nsACString & iface) override; \
  NS_IMETHOD JoinMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface) override; \
  NS_IMETHOD LeaveMulticast(const nsACString & addr, const nsACString & iface) override; \
  NS_IMETHOD LeaveMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface) override; \
  NS_IMETHOD GetMulticastLoopback(bool *aMulticastLoopback) override; \
  NS_IMETHOD SetMulticastLoopback(bool aMulticastLoopback) override; \
  NS_IMETHOD GetMulticastInterface(nsACString & aMulticastInterface) override; \
  NS_IMETHOD SetMulticastInterface(const nsACString & aMulticastInterface) override; \
  NS_IMETHOD GetMulticastInterfaceAddr(mozilla::net::NetAddr *aMulticastInterfaceAddr) override; \
  NS_IMETHOD SetMulticastInterfaceAddr(mozilla::net::NetAddr aMulticastInterfaceAddr) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKET(_to) \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc) override { return _to Init(aPort, aLoopbackOnly, aPrincipal, aAddressReuse, _argc); } \
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc) override { return _to InitWithAddress(aAddr, aPrincipal, aAddressReuse, _argc); } \
  NS_IMETHOD Close(void) override { return _to Close(); } \
  NS_IMETHOD AsyncListen(nsIUDPSocketListener *aListener) override { return _to AsyncListen(aListener); } \
  NS_IMETHOD GetLocalAddr(nsINetAddr * *aLocalAddr) override { return _to GetLocalAddr(aLocalAddr); } \
  NS_IMETHOD GetPort(int32_t *aPort) override { return _to GetPort(aPort); } \
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) override { return _to GetAddress(_retval); } \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) override { return _to Send(host, port, data, dataLength, _retval); } \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) override { return _to SendWithAddr(addr, data, dataLength, _retval); } \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) override { return _to SendWithAddress(addr, data, dataLength, _retval); } \
  NS_IMETHOD SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream) override { return _to SendBinaryStream(host, port, stream); } \
  NS_IMETHOD SendBinaryStreamWithAddress(const mozilla::net::NetAddr *addr, nsIInputStream *stream) override { return _to SendBinaryStreamWithAddress(addr, stream); } \
  NS_IMETHOD JoinMulticast(const nsACString & addr, const nsACString & iface) override { return _to JoinMulticast(addr, iface); } \
  NS_IMETHOD JoinMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface) override { return _to JoinMulticastAddr(addr, iface); } \
  NS_IMETHOD LeaveMulticast(const nsACString & addr, const nsACString & iface) override { return _to LeaveMulticast(addr, iface); } \
  NS_IMETHOD LeaveMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface) override { return _to LeaveMulticastAddr(addr, iface); } \
  NS_IMETHOD GetMulticastLoopback(bool *aMulticastLoopback) override { return _to GetMulticastLoopback(aMulticastLoopback); } \
  NS_IMETHOD SetMulticastLoopback(bool aMulticastLoopback) override { return _to SetMulticastLoopback(aMulticastLoopback); } \
  NS_IMETHOD GetMulticastInterface(nsACString & aMulticastInterface) override { return _to GetMulticastInterface(aMulticastInterface); } \
  NS_IMETHOD SetMulticastInterface(const nsACString & aMulticastInterface) override { return _to SetMulticastInterface(aMulticastInterface); } \
  NS_IMETHOD GetMulticastInterfaceAddr(mozilla::net::NetAddr *aMulticastInterfaceAddr) override { return _to GetMulticastInterfaceAddr(aMulticastInterfaceAddr); } \
  NS_IMETHOD SetMulticastInterfaceAddr(mozilla::net::NetAddr aMulticastInterfaceAddr) override { return _to SetMulticastInterfaceAddr(aMulticastInterfaceAddr); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKET(_to) \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aPort, aLoopbackOnly, aPrincipal, aAddressReuse, _argc); } \
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithAddress(aAddr, aPrincipal, aAddressReuse, _argc); } \
  NS_IMETHOD Close(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD AsyncListen(nsIUDPSocketListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncListen(aListener); } \
  NS_IMETHOD GetLocalAddr(nsINetAddr * *aLocalAddr) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalAddr(aLocalAddr); } \
  NS_IMETHOD GetPort(int32_t *aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddress(_retval); } \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(host, port, data, dataLength, _retval); } \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWithAddr(addr, data, dataLength, _retval); } \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWithAddress(addr, data, dataLength, _retval); } \
  NS_IMETHOD SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendBinaryStream(host, port, stream); } \
  NS_IMETHOD SendBinaryStreamWithAddress(const mozilla::net::NetAddr *addr, nsIInputStream *stream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SendBinaryStreamWithAddress(addr, stream); } \
  NS_IMETHOD JoinMulticast(const nsACString & addr, const nsACString & iface) override { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinMulticast(addr, iface); } \
  NS_IMETHOD JoinMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface) override { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinMulticastAddr(addr, iface); } \
  NS_IMETHOD LeaveMulticast(const nsACString & addr, const nsACString & iface) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LeaveMulticast(addr, iface); } \
  NS_IMETHOD LeaveMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LeaveMulticastAddr(addr, iface); } \
  NS_IMETHOD GetMulticastLoopback(bool *aMulticastLoopback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMulticastLoopback(aMulticastLoopback); } \
  NS_IMETHOD SetMulticastLoopback(bool aMulticastLoopback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMulticastLoopback(aMulticastLoopback); } \
  NS_IMETHOD GetMulticastInterface(nsACString & aMulticastInterface) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMulticastInterface(aMulticastInterface); } \
  NS_IMETHOD SetMulticastInterface(const nsACString & aMulticastInterface) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMulticastInterface(aMulticastInterface); } \
  NS_IMETHOD GetMulticastInterfaceAddr(mozilla::net::NetAddr *aMulticastInterfaceAddr) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMulticastInterfaceAddr(aMulticastInterfaceAddr); } \
  NS_IMETHOD SetMulticastInterfaceAddr(mozilla::net::NetAddr aMulticastInterfaceAddr) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMulticastInterfaceAddr(aMulticastInterfaceAddr); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocket : public nsIUDPSocket
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKET

  nsUDPSocket();

private:
  ~nsUDPSocket();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUDPSocket, nsIUDPSocket)

nsUDPSocket::nsUDPSocket()
{
  /* member initializers and constructor code */
}

nsUDPSocket::~nsUDPSocket()
{
  /* destructor code */
}

/* [optional_argc] void init (in long aPort, in boolean aLoopbackOnly, in nsIPrincipal aPrincipal, [optional] in boolean aAddressReuse); */
NS_IMETHODIMP nsUDPSocket::Init(int32_t aPort, bool aLoopbackOnly, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,optional_argc] void initWithAddress ([const] in NetAddrPtr aAddr, in nsIPrincipal aPrincipal, [optional] in boolean aAddressReuse); */
NS_IMETHODIMP nsUDPSocket::InitWithAddress(const mozilla::net::NetAddr *aAddr, nsIPrincipal *aPrincipal, bool aAddressReuse, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsUDPSocket::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncListen (in nsIUDPSocketListener aListener); */
NS_IMETHODIMP nsUDPSocket::AsyncListen(nsIUDPSocketListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsINetAddr localAddr; */
NS_IMETHODIMP nsUDPSocket::GetLocalAddr(nsINetAddr * *aLocalAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long port; */
NS_IMETHODIMP nsUDPSocket::GetPort(int32_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] NetAddr getAddress (); */
NS_IMETHODIMP nsUDPSocket::GetAddress(mozilla::net::NetAddr *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long send (in AUTF8String host, in unsigned short port, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
NS_IMETHODIMP nsUDPSocket::Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long sendWithAddr (in nsINetAddr addr, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
NS_IMETHODIMP nsUDPSocket::SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] unsigned long sendWithAddress ([const] in NetAddrPtr addr, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
NS_IMETHODIMP nsUDPSocket::SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendBinaryStream (in AUTF8String host, in unsigned short port, in nsIInputStream stream); */
NS_IMETHODIMP nsUDPSocket::SendBinaryStream(const nsACString & host, uint16_t port, nsIInputStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendBinaryStreamWithAddress ([const] in NetAddrPtr addr, in nsIInputStream stream); */
NS_IMETHODIMP nsUDPSocket::SendBinaryStreamWithAddress(const mozilla::net::NetAddr *addr, nsIInputStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void joinMulticast (in AUTF8String addr, [optional] in AUTF8String iface); */
NS_IMETHODIMP nsUDPSocket::JoinMulticast(const nsACString & addr, const nsACString & iface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void joinMulticastAddr ([const] in NetAddr addr, [const, optional] in NetAddrPtr iface); */
NS_IMETHODIMP nsUDPSocket::JoinMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void leaveMulticast (in AUTF8String addr, [optional] in AUTF8String iface); */
NS_IMETHODIMP nsUDPSocket::LeaveMulticast(const nsACString & addr, const nsACString & iface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void leaveMulticastAddr ([const] in NetAddr addr, [const, optional] in NetAddrPtr iface); */
NS_IMETHODIMP nsUDPSocket::LeaveMulticastAddr(const mozilla::net::NetAddr addr, const mozilla::net::NetAddr *iface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean multicastLoopback; */
NS_IMETHODIMP nsUDPSocket::GetMulticastLoopback(bool *aMulticastLoopback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUDPSocket::SetMulticastLoopback(bool aMulticastLoopback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String multicastInterface; */
NS_IMETHODIMP nsUDPSocket::GetMulticastInterface(nsACString & aMulticastInterface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUDPSocket::SetMulticastInterface(const nsACString & aMulticastInterface)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute NetAddr multicastInterfaceAddr; */
NS_IMETHODIMP nsUDPSocket::GetMulticastInterfaceAddr(mozilla::net::NetAddr *aMulticastInterfaceAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUDPSocket::SetMulticastInterfaceAddr(mozilla::net::NetAddr aMulticastInterfaceAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUDPSocketListener */
#define NS_IUDPSOCKETLISTENER_IID_STR "2e4b5dd3-7358-4281-b81f-10c62ef39cb5"

#define NS_IUDPSOCKETLISTENER_IID \
  {0x2e4b5dd3, 0x7358, 0x4281, \
    { 0xb8, 0x1f, 0x10, 0xc6, 0x2e, 0xf3, 0x9c, 0xb5 }}

class NS_NO_VTABLE nsIUDPSocketListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKETLISTENER_IID)

  /* void onPacketReceived (in nsIUDPSocket aSocket, in nsIUDPMessage aMessage); */
  NS_IMETHOD OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage) = 0;

  /* void onStopListening (in nsIUDPSocket aSocket, in nsresult aStatus); */
  NS_IMETHOD OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocketListener, NS_IUDPSOCKETLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKETLISTENER \
  NS_IMETHOD OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage) override; \
  NS_IMETHOD OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKETLISTENER(_to) \
  NS_IMETHOD OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage) override { return _to OnPacketReceived(aSocket, aMessage); } \
  NS_IMETHOD OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus) override { return _to OnStopListening(aSocket, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKETLISTENER(_to) \
  NS_IMETHOD OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPacketReceived(aSocket, aMessage); } \
  NS_IMETHOD OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopListening(aSocket, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocketListener : public nsIUDPSocketListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKETLISTENER

  nsUDPSocketListener();

private:
  ~nsUDPSocketListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUDPSocketListener, nsIUDPSocketListener)

nsUDPSocketListener::nsUDPSocketListener()
{
  /* member initializers and constructor code */
}

nsUDPSocketListener::~nsUDPSocketListener()
{
  /* destructor code */
}

/* void onPacketReceived (in nsIUDPSocket aSocket, in nsIUDPMessage aMessage); */
NS_IMETHODIMP nsUDPSocketListener::OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopListening (in nsIUDPSocket aSocket, in nsresult aStatus); */
NS_IMETHODIMP nsUDPSocketListener::OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUDPMessage */
#define NS_IUDPMESSAGE_IID_STR "afdc743f-9cc0-40d8-b442-695dc54bbb74"

#define NS_IUDPMESSAGE_IID \
  {0xafdc743f, 0x9cc0, 0x40d8, \
    { 0xb4, 0x42, 0x69, 0x5d, 0xc5, 0x4b, 0xbb, 0x74 }}

class NS_NO_VTABLE nsIUDPMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPMESSAGE_IID)

  /* readonly attribute nsINetAddr fromAddr; */
  NS_IMETHOD GetFromAddr(nsINetAddr * *aFromAddr) = 0;

  /* readonly attribute ACString data; */
  NS_IMETHOD GetData(nsACString & aData) = 0;

  /* readonly attribute nsIOutputStream outputStream; */
  NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) = 0;

  /* [implicit_jscontext] readonly attribute jsval rawData; */
  NS_IMETHOD GetRawData(JSContext* cx, JS::MutableHandleValue aRawData) = 0;

  /* [noscript,nostdcall,notxpcom] Uint8TArrayRef getDataAsTArray (); */
  virtual FallibleTArray<uint8_t> & GetDataAsTArray(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPMessage, NS_IUDPMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPMESSAGE \
  NS_IMETHOD GetFromAddr(nsINetAddr * *aFromAddr) override; \
  NS_IMETHOD GetData(nsACString & aData) override; \
  NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) override; \
  NS_IMETHOD GetRawData(JSContext* cx, JS::MutableHandleValue aRawData) override; \
  virtual FallibleTArray<uint8_t> & GetDataAsTArray(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPMESSAGE(_to) \
  NS_IMETHOD GetFromAddr(nsINetAddr * *aFromAddr) override { return _to GetFromAddr(aFromAddr); } \
  NS_IMETHOD GetData(nsACString & aData) override { return _to GetData(aData); } \
  NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) override { return _to GetOutputStream(aOutputStream); } \
  NS_IMETHOD GetRawData(JSContext* cx, JS::MutableHandleValue aRawData) override { return _to GetRawData(cx, aRawData); } \
  virtual FallibleTArray<uint8_t> & GetDataAsTArray(void) override { return _to GetDataAsTArray(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPMESSAGE(_to) \
  NS_IMETHOD GetFromAddr(nsINetAddr * *aFromAddr) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFromAddr(aFromAddr); } \
  NS_IMETHOD GetData(nsACString & aData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOutputStream(aOutputStream); } \
  NS_IMETHOD GetRawData(JSContext* cx, JS::MutableHandleValue aRawData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRawData(cx, aRawData); } \
  virtual FallibleTArray<uint8_t> & GetDataAsTArray(void) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPMessage : public nsIUDPMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPMESSAGE

  nsUDPMessage();

private:
  ~nsUDPMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUDPMessage, nsIUDPMessage)

nsUDPMessage::nsUDPMessage()
{
  /* member initializers and constructor code */
}

nsUDPMessage::~nsUDPMessage()
{
  /* destructor code */
}

/* readonly attribute nsINetAddr fromAddr; */
NS_IMETHODIMP nsUDPMessage::GetFromAddr(nsINetAddr * *aFromAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString data; */
NS_IMETHODIMP nsUDPMessage::GetData(nsACString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIOutputStream outputStream; */
NS_IMETHODIMP nsUDPMessage::GetOutputStream(nsIOutputStream * *aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval rawData; */
NS_IMETHODIMP nsUDPMessage::GetRawData(JSContext* cx, JS::MutableHandleValue aRawData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] Uint8TArrayRef getDataAsTArray (); */
FallibleTArray<uint8_t> & nsUDPMessage::GetDataAsTArray()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUDPSocket_h__ */
