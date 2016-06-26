/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISSLSocketControl.idl
 */

#ifndef __gen_nsISSLSocketControl_h__
#define __gen_nsISSLSocketControl_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */

class nsIX509Cert; /* forward declaration */

template<class T> class nsTArray;
class nsCString;

/* starting interface:    nsISSLSocketControl */
#define NS_ISSLSOCKETCONTROL_IID_STR "418265c8-654e-4fbb-ba62-4eed27de1f03"

#define NS_ISSLSOCKETCONTROL_IID \
  {0x418265c8, 0x654e, 0x4fbb, \
    { 0xba, 0x62, 0x4e, 0xed, 0x27, 0xde, 0x1f, 0x03 }}

class NS_NO_VTABLE nsISSLSocketControl : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISSLSOCKETCONTROL_IID)

  /* attribute nsIInterfaceRequestor notificationCallbacks; */
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) = 0;
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) = 0;

  /* void proxyStartSSL (); */
  NS_IMETHOD ProxyStartSSL(void) = 0;

  /* void StartTLS (); */
  NS_IMETHOD StartTLS(void) = 0;

  /* [noscript] void setNPNList (in nsCStringTArrayRef aNPNList); */
  NS_IMETHOD SetNPNList(nsTArray<nsCString> & aNPNList) = 0;

  /* readonly attribute ACString negotiatedNPN; */
  NS_IMETHOD GetNegotiatedNPN(nsACString & aNegotiatedNPN) = 0;

  /* boolean joinConnection (in ACString npnProtocol, in ACString hostname, in long port); */
  NS_IMETHOD JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval) = 0;

  /* boolean isAcceptableForHost (in ACString hostname); */
  NS_IMETHOD IsAcceptableForHost(const nsACString & hostname, bool *_retval) = 0;

  /* [infallible] readonly attribute short KEAUsed; */
  NS_IMETHOD GetKEAUsed(int16_t *aKEAUsed) = 0;
  inline int16_t GetKEAUsed()
  {
    int16_t result;
    mozilla::DebugOnly<nsresult> rv = GetKEAUsed(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute unsigned long KEAKeyBits; */
  NS_IMETHOD GetKEAKeyBits(uint32_t *aKEAKeyBits) = 0;
  inline uint32_t GetKEAKeyBits()
  {
    uint32_t result;
    mozilla::DebugOnly<nsresult> rv = GetKEAKeyBits(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  enum {
    KEY_EXCHANGE_UNKNOWN = -1
  };

  /* readonly attribute uint32_t providerFlags; */
  NS_IMETHOD GetProviderFlags(uint32_t *aProviderFlags) = 0;

  enum {
    SSL_VERSION_3 = 768,
    TLS_VERSION_1 = 769,
    TLS_VERSION_1_1 = 770,
    TLS_VERSION_1_2 = 771,
    SSL_VERSION_UNKNOWN = -1
  };

  /* [infallible] readonly attribute short SSLVersionUsed; */
  NS_IMETHOD GetSSLVersionUsed(int16_t *aSSLVersionUsed) = 0;
  inline int16_t GetSSLVersionUsed()
  {
    int16_t result;
    mozilla::DebugOnly<nsresult> rv = GetSSLVersionUsed(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute short SSLVersionOffered; */
  NS_IMETHOD GetSSLVersionOffered(int16_t *aSSLVersionOffered) = 0;
  inline int16_t GetSSLVersionOffered()
  {
    int16_t result;
    mozilla::DebugOnly<nsresult> rv = GetSSLVersionOffered(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  enum {
    SSL_MAC_UNKNOWN = -1,
    SSL_MAC_NULL = 0,
    SSL_MAC_MD5 = 1,
    SSL_MAC_SHA = 2,
    SSL_HMAC_MD5 = 3,
    SSL_HMAC_SHA = 4,
    SSL_HMAC_SHA256 = 5,
    SSL_MAC_AEAD = 6
  };

  /* [infallible] readonly attribute short MACAlgorithmUsed; */
  NS_IMETHOD GetMACAlgorithmUsed(int16_t *aMACAlgorithmUsed) = 0;
  inline int16_t GetMACAlgorithmUsed()
  {
    int16_t result;
    mozilla::DebugOnly<nsresult> rv = GetMACAlgorithmUsed(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* attribute nsIX509Cert clientCert; */
  NS_IMETHOD GetClientCert(nsIX509Cert * *aClientCert) = 0;
  NS_IMETHOD SetClientCert(nsIX509Cert *aClientCert) = 0;

  /* [infallible] readonly attribute boolean bypassAuthentication; */
  NS_IMETHOD GetBypassAuthentication(bool *aBypassAuthentication) = 0;
  inline bool GetBypassAuthentication()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetBypassAuthentication(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean failedVerification; */
  NS_IMETHOD GetFailedVerification(bool *aFailedVerification) = 0;
  inline bool GetFailedVerification()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetFailedVerification(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISSLSocketControl, NS_ISSLSOCKETCONTROL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISSLSOCKETCONTROL \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) override; \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) override; \
  NS_IMETHOD ProxyStartSSL(void) override; \
  NS_IMETHOD StartTLS(void) override; \
  NS_IMETHOD SetNPNList(nsTArray<nsCString> & aNPNList) override; \
  NS_IMETHOD GetNegotiatedNPN(nsACString & aNegotiatedNPN) override; \
  NS_IMETHOD JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval) override; \
  NS_IMETHOD IsAcceptableForHost(const nsACString & hostname, bool *_retval) override; \
  using nsISSLSocketControl::GetKEAUsed; \
  NS_IMETHOD GetKEAUsed(int16_t *aKEAUsed) override; \
  using nsISSLSocketControl::GetKEAKeyBits; \
  NS_IMETHOD GetKEAKeyBits(uint32_t *aKEAKeyBits) override; \
  NS_IMETHOD GetProviderFlags(uint32_t *aProviderFlags) override; \
  using nsISSLSocketControl::GetSSLVersionUsed; \
  NS_IMETHOD GetSSLVersionUsed(int16_t *aSSLVersionUsed) override; \
  using nsISSLSocketControl::GetSSLVersionOffered; \
  NS_IMETHOD GetSSLVersionOffered(int16_t *aSSLVersionOffered) override; \
  using nsISSLSocketControl::GetMACAlgorithmUsed; \
  NS_IMETHOD GetMACAlgorithmUsed(int16_t *aMACAlgorithmUsed) override; \
  NS_IMETHOD GetClientCert(nsIX509Cert * *aClientCert) override; \
  NS_IMETHOD SetClientCert(nsIX509Cert *aClientCert) override; \
  using nsISSLSocketControl::GetBypassAuthentication; \
  NS_IMETHOD GetBypassAuthentication(bool *aBypassAuthentication) override; \
  using nsISSLSocketControl::GetFailedVerification; \
  NS_IMETHOD GetFailedVerification(bool *aFailedVerification) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISSLSOCKETCONTROL(_to) \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) override { return _to GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) override { return _to SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD ProxyStartSSL(void) override { return _to ProxyStartSSL(); } \
  NS_IMETHOD StartTLS(void) override { return _to StartTLS(); } \
  NS_IMETHOD SetNPNList(nsTArray<nsCString> & aNPNList) override { return _to SetNPNList(aNPNList); } \
  NS_IMETHOD GetNegotiatedNPN(nsACString & aNegotiatedNPN) override { return _to GetNegotiatedNPN(aNegotiatedNPN); } \
  NS_IMETHOD JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval) override { return _to JoinConnection(npnProtocol, hostname, port, _retval); } \
  NS_IMETHOD IsAcceptableForHost(const nsACString & hostname, bool *_retval) override { return _to IsAcceptableForHost(hostname, _retval); } \
  using nsISSLSocketControl::GetKEAUsed; \
  NS_IMETHOD GetKEAUsed(int16_t *aKEAUsed) override { return _to GetKEAUsed(aKEAUsed); } \
  using nsISSLSocketControl::GetKEAKeyBits; \
  NS_IMETHOD GetKEAKeyBits(uint32_t *aKEAKeyBits) override { return _to GetKEAKeyBits(aKEAKeyBits); } \
  NS_IMETHOD GetProviderFlags(uint32_t *aProviderFlags) override { return _to GetProviderFlags(aProviderFlags); } \
  using nsISSLSocketControl::GetSSLVersionUsed; \
  NS_IMETHOD GetSSLVersionUsed(int16_t *aSSLVersionUsed) override { return _to GetSSLVersionUsed(aSSLVersionUsed); } \
  using nsISSLSocketControl::GetSSLVersionOffered; \
  NS_IMETHOD GetSSLVersionOffered(int16_t *aSSLVersionOffered) override { return _to GetSSLVersionOffered(aSSLVersionOffered); } \
  using nsISSLSocketControl::GetMACAlgorithmUsed; \
  NS_IMETHOD GetMACAlgorithmUsed(int16_t *aMACAlgorithmUsed) override { return _to GetMACAlgorithmUsed(aMACAlgorithmUsed); } \
  NS_IMETHOD GetClientCert(nsIX509Cert * *aClientCert) override { return _to GetClientCert(aClientCert); } \
  NS_IMETHOD SetClientCert(nsIX509Cert *aClientCert) override { return _to SetClientCert(aClientCert); } \
  using nsISSLSocketControl::GetBypassAuthentication; \
  NS_IMETHOD GetBypassAuthentication(bool *aBypassAuthentication) override { return _to GetBypassAuthentication(aBypassAuthentication); } \
  using nsISSLSocketControl::GetFailedVerification; \
  NS_IMETHOD GetFailedVerification(bool *aFailedVerification) override { return _to GetFailedVerification(aFailedVerification); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISSLSOCKETCONTROL(_to) \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD ProxyStartSSL(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ProxyStartSSL(); } \
  NS_IMETHOD StartTLS(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartTLS(); } \
  NS_IMETHOD SetNPNList(nsTArray<nsCString> & aNPNList) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNPNList(aNPNList); } \
  NS_IMETHOD GetNegotiatedNPN(nsACString & aNegotiatedNPN) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNegotiatedNPN(aNegotiatedNPN); } \
  NS_IMETHOD JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinConnection(npnProtocol, hostname, port, _retval); } \
  NS_IMETHOD IsAcceptableForHost(const nsACString & hostname, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAcceptableForHost(hostname, _retval); } \
  NS_IMETHOD GetKEAUsed(int16_t *aKEAUsed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKEAUsed(aKEAUsed); } \
  NS_IMETHOD GetKEAKeyBits(uint32_t *aKEAKeyBits) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKEAKeyBits(aKEAKeyBits); } \
  NS_IMETHOD GetProviderFlags(uint32_t *aProviderFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProviderFlags(aProviderFlags); } \
  NS_IMETHOD GetSSLVersionUsed(int16_t *aSSLVersionUsed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSSLVersionUsed(aSSLVersionUsed); } \
  NS_IMETHOD GetSSLVersionOffered(int16_t *aSSLVersionOffered) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSSLVersionOffered(aSSLVersionOffered); } \
  NS_IMETHOD GetMACAlgorithmUsed(int16_t *aMACAlgorithmUsed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMACAlgorithmUsed(aMACAlgorithmUsed); } \
  NS_IMETHOD GetClientCert(nsIX509Cert * *aClientCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientCert(aClientCert); } \
  NS_IMETHOD SetClientCert(nsIX509Cert *aClientCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetClientCert(aClientCert); } \
  NS_IMETHOD GetBypassAuthentication(bool *aBypassAuthentication) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBypassAuthentication(aBypassAuthentication); } \
  NS_IMETHOD GetFailedVerification(bool *aFailedVerification) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFailedVerification(aFailedVerification); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSSLSocketControl : public nsISSLSocketControl
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISSLSOCKETCONTROL

  nsSSLSocketControl();

private:
  ~nsSSLSocketControl();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSSLSocketControl, nsISSLSocketControl)

nsSSLSocketControl::nsSSLSocketControl()
{
  /* member initializers and constructor code */
}

nsSSLSocketControl::~nsSSLSocketControl()
{
  /* destructor code */
}

/* attribute nsIInterfaceRequestor notificationCallbacks; */
NS_IMETHODIMP nsSSLSocketControl::GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSSLSocketControl::SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void proxyStartSSL (); */
NS_IMETHODIMP nsSSLSocketControl::ProxyStartSSL()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void StartTLS (); */
NS_IMETHODIMP nsSSLSocketControl::StartTLS()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setNPNList (in nsCStringTArrayRef aNPNList); */
NS_IMETHODIMP nsSSLSocketControl::SetNPNList(nsTArray<nsCString> & aNPNList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString negotiatedNPN; */
NS_IMETHODIMP nsSSLSocketControl::GetNegotiatedNPN(nsACString & aNegotiatedNPN)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean joinConnection (in ACString npnProtocol, in ACString hostname, in long port); */
NS_IMETHODIMP nsSSLSocketControl::JoinConnection(const nsACString & npnProtocol, const nsACString & hostname, int32_t port, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isAcceptableForHost (in ACString hostname); */
NS_IMETHODIMP nsSSLSocketControl::IsAcceptableForHost(const nsACString & hostname, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute short KEAUsed; */
NS_IMETHODIMP nsSSLSocketControl::GetKEAUsed(int16_t *aKEAUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute unsigned long KEAKeyBits; */
NS_IMETHODIMP nsSSLSocketControl::GetKEAKeyBits(uint32_t *aKEAKeyBits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t providerFlags; */
NS_IMETHODIMP nsSSLSocketControl::GetProviderFlags(uint32_t *aProviderFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute short SSLVersionUsed; */
NS_IMETHODIMP nsSSLSocketControl::GetSSLVersionUsed(int16_t *aSSLVersionUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute short SSLVersionOffered; */
NS_IMETHODIMP nsSSLSocketControl::GetSSLVersionOffered(int16_t *aSSLVersionOffered)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute short MACAlgorithmUsed; */
NS_IMETHODIMP nsSSLSocketControl::GetMACAlgorithmUsed(int16_t *aMACAlgorithmUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIX509Cert clientCert; */
NS_IMETHODIMP nsSSLSocketControl::GetClientCert(nsIX509Cert * *aClientCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSSLSocketControl::SetClientCert(nsIX509Cert *aClientCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean bypassAuthentication; */
NS_IMETHODIMP nsSSLSocketControl::GetBypassAuthentication(bool *aBypassAuthentication)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean failedVerification; */
NS_IMETHODIMP nsSSLSocketControl::GetFailedVerification(bool *aFailedVerification)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISSLSocketControl_h__ */
