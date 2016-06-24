/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISocketTransport.idl
 */

#ifndef __gen_nsISocketTransport_h__
#define __gen_nsISocketTransport_h__


#ifndef __gen_nsITransport_h__
#include "nsITransport.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */

class nsINetAddr; /* forward declaration */

namespace mozilla {
namespace net {
union NetAddr;
}
}

/* starting interface:    nsISocketTransport */
#define NS_ISOCKETTRANSPORT_IID_STR "79221831-85e2-43a8-8152-05d77d6fde31"

#define NS_ISOCKETTRANSPORT_IID \
  {0x79221831, 0x85e2, 0x43a8, \
    { 0x81, 0x52, 0x05, 0xd7, 0x7d, 0x6f, 0xde, 0x31 }}

class NS_NO_VTABLE nsISocketTransport : public nsITransport {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOCKETTRANSPORT_IID)

  /* readonly attribute AUTF8String host; */
  NS_IMETHOD GetHost(nsACString & aHost) = 0;

  /* readonly attribute long port; */
  NS_IMETHOD GetPort(int32_t *aPort) = 0;

  /* attribute ACString networkInterfaceId; */
  NS_IMETHOD GetNetworkInterfaceId(nsACString & aNetworkInterfaceId) = 0;
  NS_IMETHOD SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId) = 0;

  /* [noscript] NetAddr getPeerAddr (); */
  NS_IMETHOD GetPeerAddr(mozilla::net::NetAddr *_retval) = 0;

  /* [noscript] NetAddr getSelfAddr (); */
  NS_IMETHOD GetSelfAddr(mozilla::net::NetAddr *_retval) = 0;

  /* [noscript] void bind (in NetAddrPtr aLocalAddr); */
  NS_IMETHOD Bind(mozilla::net::NetAddr *aLocalAddr) = 0;

  /* nsINetAddr getScriptablePeerAddr (); */
  NS_IMETHOD GetScriptablePeerAddr(nsINetAddr * *_retval) = 0;

  /* nsINetAddr getScriptableSelfAddr (); */
  NS_IMETHOD GetScriptableSelfAddr(nsINetAddr * *_retval) = 0;

  /* readonly attribute nsISupports securityInfo; */
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) = 0;

  /* attribute nsIInterfaceRequestor securityCallbacks; */
  NS_IMETHOD GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks) = 0;
  NS_IMETHOD SetSecurityCallbacks(nsIInterfaceRequestor *aSecurityCallbacks) = 0;

  /* boolean isAlive (); */
  NS_IMETHOD IsAlive(bool *_retval) = 0;

  /* unsigned long getTimeout (in unsigned long aType); */
  NS_IMETHOD GetTimeout(uint32_t aType, uint32_t *_retval) = 0;

  /* void setTimeout (in unsigned long aType, in unsigned long aValue); */
  NS_IMETHOD SetTimeout(uint32_t aType, uint32_t aValue) = 0;

  enum {
    TIMEOUT_CONNECT = 0U,
    TIMEOUT_READ_WRITE = 1U,
    STATUS_RESOLVING = 2152398851U,
    STATUS_RESOLVED = 2152398859U,
    STATUS_CONNECTING_TO = 2152398855U,
    STATUS_CONNECTED_TO = 2152398852U,
    STATUS_SENDING_TO = 2152398853U,
    STATUS_WAITING_FOR = 2152398858U,
    STATUS_RECEIVING_FROM = 2152398854U
  };

  /* attribute unsigned long connectionFlags; */
  NS_IMETHOD GetConnectionFlags(uint32_t *aConnectionFlags) = 0;
  NS_IMETHOD SetConnectionFlags(uint32_t aConnectionFlags) = 0;

  enum {
    BYPASS_CACHE = 1U,
    ANONYMOUS_CONNECT = 2U,
    DISABLE_IPV6 = 4U,
    NO_PERMANENT_STORAGE = 8U,
    DISABLE_IPV4 = 16U,
    DISABLE_RFC1918 = 32U,
    MITM_OK = 64U
  };

  /* attribute octet QoSBits; */
  NS_IMETHOD GetQoSBits(uint8_t *aQoSBits) = 0;
  NS_IMETHOD SetQoSBits(uint8_t aQoSBits) = 0;

  /* attribute unsigned long recvBufferSize; */
  NS_IMETHOD GetRecvBufferSize(uint32_t *aRecvBufferSize) = 0;
  NS_IMETHOD SetRecvBufferSize(uint32_t aRecvBufferSize) = 0;

  /* attribute unsigned long sendBufferSize; */
  NS_IMETHOD GetSendBufferSize(uint32_t *aSendBufferSize) = 0;
  NS_IMETHOD SetSendBufferSize(uint32_t aSendBufferSize) = 0;

  /* attribute boolean keepaliveEnabled; */
  NS_IMETHOD GetKeepaliveEnabled(bool *aKeepaliveEnabled) = 0;
  NS_IMETHOD SetKeepaliveEnabled(bool aKeepaliveEnabled) = 0;

  /* void setKeepaliveVals (in long keepaliveIdleTime, in long keepaliveRetryInterval); */
  NS_IMETHOD SetKeepaliveVals(int32_t keepaliveIdleTime, int32_t keepaliveRetryInterval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISocketTransport, NS_ISOCKETTRANSPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOCKETTRANSPORT \
  NS_IMETHOD GetHost(nsACString & aHost) override; \
  NS_IMETHOD GetPort(int32_t *aPort) override; \
  NS_IMETHOD GetNetworkInterfaceId(nsACString & aNetworkInterfaceId) override; \
  NS_IMETHOD SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId) override; \
  NS_IMETHOD GetPeerAddr(mozilla::net::NetAddr *_retval) override; \
  NS_IMETHOD GetSelfAddr(mozilla::net::NetAddr *_retval) override; \
  NS_IMETHOD Bind(mozilla::net::NetAddr *aLocalAddr) override; \
  NS_IMETHOD GetScriptablePeerAddr(nsINetAddr * *_retval) override; \
  NS_IMETHOD GetScriptableSelfAddr(nsINetAddr * *_retval) override; \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) override; \
  NS_IMETHOD GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks) override; \
  NS_IMETHOD SetSecurityCallbacks(nsIInterfaceRequestor *aSecurityCallbacks) override; \
  NS_IMETHOD IsAlive(bool *_retval) override; \
  NS_IMETHOD GetTimeout(uint32_t aType, uint32_t *_retval) override; \
  NS_IMETHOD SetTimeout(uint32_t aType, uint32_t aValue) override; \
  NS_IMETHOD GetConnectionFlags(uint32_t *aConnectionFlags) override; \
  NS_IMETHOD SetConnectionFlags(uint32_t aConnectionFlags) override; \
  NS_IMETHOD GetQoSBits(uint8_t *aQoSBits) override; \
  NS_IMETHOD SetQoSBits(uint8_t aQoSBits) override; \
  NS_IMETHOD GetRecvBufferSize(uint32_t *aRecvBufferSize) override; \
  NS_IMETHOD SetRecvBufferSize(uint32_t aRecvBufferSize) override; \
  NS_IMETHOD GetSendBufferSize(uint32_t *aSendBufferSize) override; \
  NS_IMETHOD SetSendBufferSize(uint32_t aSendBufferSize) override; \
  NS_IMETHOD GetKeepaliveEnabled(bool *aKeepaliveEnabled) override; \
  NS_IMETHOD SetKeepaliveEnabled(bool aKeepaliveEnabled) override; \
  NS_IMETHOD SetKeepaliveVals(int32_t keepaliveIdleTime, int32_t keepaliveRetryInterval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOCKETTRANSPORT(_to) \
  NS_IMETHOD GetHost(nsACString & aHost) override { return _to GetHost(aHost); } \
  NS_IMETHOD GetPort(int32_t *aPort) override { return _to GetPort(aPort); } \
  NS_IMETHOD GetNetworkInterfaceId(nsACString & aNetworkInterfaceId) override { return _to GetNetworkInterfaceId(aNetworkInterfaceId); } \
  NS_IMETHOD SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId) override { return _to SetNetworkInterfaceId(aNetworkInterfaceId); } \
  NS_IMETHOD GetPeerAddr(mozilla::net::NetAddr *_retval) override { return _to GetPeerAddr(_retval); } \
  NS_IMETHOD GetSelfAddr(mozilla::net::NetAddr *_retval) override { return _to GetSelfAddr(_retval); } \
  NS_IMETHOD Bind(mozilla::net::NetAddr *aLocalAddr) override { return _to Bind(aLocalAddr); } \
  NS_IMETHOD GetScriptablePeerAddr(nsINetAddr * *_retval) override { return _to GetScriptablePeerAddr(_retval); } \
  NS_IMETHOD GetScriptableSelfAddr(nsINetAddr * *_retval) override { return _to GetScriptableSelfAddr(_retval); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) override { return _to GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks) override { return _to GetSecurityCallbacks(aSecurityCallbacks); } \
  NS_IMETHOD SetSecurityCallbacks(nsIInterfaceRequestor *aSecurityCallbacks) override { return _to SetSecurityCallbacks(aSecurityCallbacks); } \
  NS_IMETHOD IsAlive(bool *_retval) override { return _to IsAlive(_retval); } \
  NS_IMETHOD GetTimeout(uint32_t aType, uint32_t *_retval) override { return _to GetTimeout(aType, _retval); } \
  NS_IMETHOD SetTimeout(uint32_t aType, uint32_t aValue) override { return _to SetTimeout(aType, aValue); } \
  NS_IMETHOD GetConnectionFlags(uint32_t *aConnectionFlags) override { return _to GetConnectionFlags(aConnectionFlags); } \
  NS_IMETHOD SetConnectionFlags(uint32_t aConnectionFlags) override { return _to SetConnectionFlags(aConnectionFlags); } \
  NS_IMETHOD GetQoSBits(uint8_t *aQoSBits) override { return _to GetQoSBits(aQoSBits); } \
  NS_IMETHOD SetQoSBits(uint8_t aQoSBits) override { return _to SetQoSBits(aQoSBits); } \
  NS_IMETHOD GetRecvBufferSize(uint32_t *aRecvBufferSize) override { return _to GetRecvBufferSize(aRecvBufferSize); } \
  NS_IMETHOD SetRecvBufferSize(uint32_t aRecvBufferSize) override { return _to SetRecvBufferSize(aRecvBufferSize); } \
  NS_IMETHOD GetSendBufferSize(uint32_t *aSendBufferSize) override { return _to GetSendBufferSize(aSendBufferSize); } \
  NS_IMETHOD SetSendBufferSize(uint32_t aSendBufferSize) override { return _to SetSendBufferSize(aSendBufferSize); } \
  NS_IMETHOD GetKeepaliveEnabled(bool *aKeepaliveEnabled) override { return _to GetKeepaliveEnabled(aKeepaliveEnabled); } \
  NS_IMETHOD SetKeepaliveEnabled(bool aKeepaliveEnabled) override { return _to SetKeepaliveEnabled(aKeepaliveEnabled); } \
  NS_IMETHOD SetKeepaliveVals(int32_t keepaliveIdleTime, int32_t keepaliveRetryInterval) override { return _to SetKeepaliveVals(keepaliveIdleTime, keepaliveRetryInterval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOCKETTRANSPORT(_to) \
  NS_IMETHOD GetHost(nsACString & aHost) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD GetPort(int32_t *aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetNetworkInterfaceId(nsACString & aNetworkInterfaceId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetworkInterfaceId(aNetworkInterfaceId); } \
  NS_IMETHOD SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNetworkInterfaceId(aNetworkInterfaceId); } \
  NS_IMETHOD GetPeerAddr(mozilla::net::NetAddr *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPeerAddr(_retval); } \
  NS_IMETHOD GetSelfAddr(mozilla::net::NetAddr *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelfAddr(_retval); } \
  NS_IMETHOD Bind(mozilla::net::NetAddr *aLocalAddr) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Bind(aLocalAddr); } \
  NS_IMETHOD GetScriptablePeerAddr(nsINetAddr * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptablePeerAddr(_retval); } \
  NS_IMETHOD GetScriptableSelfAddr(nsINetAddr * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableSelfAddr(_retval); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityCallbacks(aSecurityCallbacks); } \
  NS_IMETHOD SetSecurityCallbacks(nsIInterfaceRequestor *aSecurityCallbacks) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityCallbacks(aSecurityCallbacks); } \
  NS_IMETHOD IsAlive(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAlive(_retval); } \
  NS_IMETHOD GetTimeout(uint32_t aType, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeout(aType, _retval); } \
  NS_IMETHOD SetTimeout(uint32_t aType, uint32_t aValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeout(aType, aValue); } \
  NS_IMETHOD GetConnectionFlags(uint32_t *aConnectionFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectionFlags(aConnectionFlags); } \
  NS_IMETHOD SetConnectionFlags(uint32_t aConnectionFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConnectionFlags(aConnectionFlags); } \
  NS_IMETHOD GetQoSBits(uint8_t *aQoSBits) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQoSBits(aQoSBits); } \
  NS_IMETHOD SetQoSBits(uint8_t aQoSBits) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetQoSBits(aQoSBits); } \
  NS_IMETHOD GetRecvBufferSize(uint32_t *aRecvBufferSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRecvBufferSize(aRecvBufferSize); } \
  NS_IMETHOD SetRecvBufferSize(uint32_t aRecvBufferSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRecvBufferSize(aRecvBufferSize); } \
  NS_IMETHOD GetSendBufferSize(uint32_t *aSendBufferSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSendBufferSize(aSendBufferSize); } \
  NS_IMETHOD SetSendBufferSize(uint32_t aSendBufferSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSendBufferSize(aSendBufferSize); } \
  NS_IMETHOD GetKeepaliveEnabled(bool *aKeepaliveEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeepaliveEnabled(aKeepaliveEnabled); } \
  NS_IMETHOD SetKeepaliveEnabled(bool aKeepaliveEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKeepaliveEnabled(aKeepaliveEnabled); } \
  NS_IMETHOD SetKeepaliveVals(int32_t keepaliveIdleTime, int32_t keepaliveRetryInterval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKeepaliveVals(keepaliveIdleTime, keepaliveRetryInterval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSocketTransport : public nsISocketTransport
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOCKETTRANSPORT

  nsSocketTransport();

private:
  ~nsSocketTransport();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSocketTransport, nsISocketTransport)

nsSocketTransport::nsSocketTransport()
{
  /* member initializers and constructor code */
}

nsSocketTransport::~nsSocketTransport()
{
  /* destructor code */
}

/* readonly attribute AUTF8String host; */
NS_IMETHODIMP nsSocketTransport::GetHost(nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long port; */
NS_IMETHODIMP nsSocketTransport::GetPort(int32_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString networkInterfaceId; */
NS_IMETHODIMP nsSocketTransport::GetNetworkInterfaceId(nsACString & aNetworkInterfaceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSocketTransport::SetNetworkInterfaceId(const nsACString & aNetworkInterfaceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] NetAddr getPeerAddr (); */
NS_IMETHODIMP nsSocketTransport::GetPeerAddr(mozilla::net::NetAddr *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] NetAddr getSelfAddr (); */
NS_IMETHODIMP nsSocketTransport::GetSelfAddr(mozilla::net::NetAddr *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void bind (in NetAddrPtr aLocalAddr); */
NS_IMETHODIMP nsSocketTransport::Bind(mozilla::net::NetAddr *aLocalAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINetAddr getScriptablePeerAddr (); */
NS_IMETHODIMP nsSocketTransport::GetScriptablePeerAddr(nsINetAddr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINetAddr getScriptableSelfAddr (); */
NS_IMETHODIMP nsSocketTransport::GetScriptableSelfAddr(nsINetAddr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports securityInfo; */
NS_IMETHODIMP nsSocketTransport::GetSecurityInfo(nsISupports * *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInterfaceRequestor securityCallbacks; */
NS_IMETHODIMP nsSocketTransport::GetSecurityCallbacks(nsIInterfaceRequestor * *aSecurityCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSocketTransport::SetSecurityCallbacks(nsIInterfaceRequestor *aSecurityCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isAlive (); */
NS_IMETHODIMP nsSocketTransport::IsAlive(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getTimeout (in unsigned long aType); */
NS_IMETHODIMP nsSocketTransport::GetTimeout(uint32_t aType, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTimeout (in unsigned long aType, in unsigned long aValue); */
NS_IMETHODIMP nsSocketTransport::SetTimeout(uint32_t aType, uint32_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long connectionFlags; */
NS_IMETHODIMP nsSocketTransport::GetConnectionFlags(uint32_t *aConnectionFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSocketTransport::SetConnectionFlags(uint32_t aConnectionFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute octet QoSBits; */
NS_IMETHODIMP nsSocketTransport::GetQoSBits(uint8_t *aQoSBits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSocketTransport::SetQoSBits(uint8_t aQoSBits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long recvBufferSize; */
NS_IMETHODIMP nsSocketTransport::GetRecvBufferSize(uint32_t *aRecvBufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSocketTransport::SetRecvBufferSize(uint32_t aRecvBufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long sendBufferSize; */
NS_IMETHODIMP nsSocketTransport::GetSendBufferSize(uint32_t *aSendBufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSocketTransport::SetSendBufferSize(uint32_t aSendBufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean keepaliveEnabled; */
NS_IMETHODIMP nsSocketTransport::GetKeepaliveEnabled(bool *aKeepaliveEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSocketTransport::SetKeepaliveEnabled(bool aKeepaliveEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setKeepaliveVals (in long keepaliveIdleTime, in long keepaliveRetryInterval); */
NS_IMETHODIMP nsSocketTransport::SetKeepaliveVals(int32_t keepaliveIdleTime, int32_t keepaliveRetryInterval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISocketTransport_h__ */
