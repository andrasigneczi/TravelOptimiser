/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITLSServerSocket.idl
 */

#ifndef __gen_nsITLSServerSocket_h__
#define __gen_nsITLSServerSocket_h__


#ifndef __gen_nsIServerSocket_h__
#include "nsIServerSocket.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */

class nsITLSServerSecurityObserver; /* forward declaration */

class nsISocketTransport; /* forward declaration */


/* starting interface:    nsITLSServerSocket */
#define NS_ITLSSERVERSOCKET_IID_STR "2e025b6c-96ba-4781-85fb-d1cf1a653207"

#define NS_ITLSSERVERSOCKET_IID \
  {0x2e025b6c, 0x96ba, 0x4781, \
    { 0x85, 0xfb, 0xd1, 0xcf, 0x1a, 0x65, 0x32, 0x07 }}

class NS_NO_VTABLE nsITLSServerSocket : public nsIServerSocket {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITLSSERVERSOCKET_IID)

  /* attribute nsIX509Cert serverCert; */
  NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) = 0;
  NS_IMETHOD SetServerCert(nsIX509Cert *aServerCert) = 0;

  /* void setSessionCache (in boolean aSessionCache); */
  NS_IMETHOD SetSessionCache(bool aSessionCache) = 0;

  /* void setSessionTickets (in boolean aSessionTickets); */
  NS_IMETHOD SetSessionTickets(bool aSessionTickets) = 0;

  enum {
    REQUEST_NEVER = 0U,
    REQUEST_FIRST_HANDSHAKE = 1U,
    REQUEST_ALWAYS = 2U,
    REQUIRE_FIRST_HANDSHAKE = 3U,
    REQUIRE_ALWAYS = 4U
  };

  /* void setRequestClientCertificate (in unsigned long aRequestClientCert); */
  NS_IMETHOD SetRequestClientCertificate(uint32_t aRequestClientCert) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITLSServerSocket, NS_ITLSSERVERSOCKET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITLSSERVERSOCKET \
  NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) override; \
  NS_IMETHOD SetServerCert(nsIX509Cert *aServerCert) override; \
  NS_IMETHOD SetSessionCache(bool aSessionCache) override; \
  NS_IMETHOD SetSessionTickets(bool aSessionTickets) override; \
  NS_IMETHOD SetRequestClientCertificate(uint32_t aRequestClientCert) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITLSSERVERSOCKET(_to) \
  NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) override { return _to GetServerCert(aServerCert); } \
  NS_IMETHOD SetServerCert(nsIX509Cert *aServerCert) override { return _to SetServerCert(aServerCert); } \
  NS_IMETHOD SetSessionCache(bool aSessionCache) override { return _to SetSessionCache(aSessionCache); } \
  NS_IMETHOD SetSessionTickets(bool aSessionTickets) override { return _to SetSessionTickets(aSessionTickets); } \
  NS_IMETHOD SetRequestClientCertificate(uint32_t aRequestClientCert) override { return _to SetRequestClientCertificate(aRequestClientCert); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITLSSERVERSOCKET(_to) \
  NS_IMETHOD GetServerCert(nsIX509Cert * *aServerCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServerCert(aServerCert); } \
  NS_IMETHOD SetServerCert(nsIX509Cert *aServerCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetServerCert(aServerCert); } \
  NS_IMETHOD SetSessionCache(bool aSessionCache) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSessionCache(aSessionCache); } \
  NS_IMETHOD SetSessionTickets(bool aSessionTickets) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSessionTickets(aSessionTickets); } \
  NS_IMETHOD SetRequestClientCertificate(uint32_t aRequestClientCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRequestClientCertificate(aRequestClientCert); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTLSServerSocket : public nsITLSServerSocket
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITLSSERVERSOCKET

  nsTLSServerSocket();

private:
  ~nsTLSServerSocket();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTLSServerSocket, nsITLSServerSocket)

nsTLSServerSocket::nsTLSServerSocket()
{
  /* member initializers and constructor code */
}

nsTLSServerSocket::~nsTLSServerSocket()
{
  /* destructor code */
}

/* attribute nsIX509Cert serverCert; */
NS_IMETHODIMP nsTLSServerSocket::GetServerCert(nsIX509Cert * *aServerCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTLSServerSocket::SetServerCert(nsIX509Cert *aServerCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSessionCache (in boolean aSessionCache); */
NS_IMETHODIMP nsTLSServerSocket::SetSessionCache(bool aSessionCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSessionTickets (in boolean aSessionTickets); */
NS_IMETHODIMP nsTLSServerSocket::SetSessionTickets(bool aSessionTickets)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRequestClientCertificate (in unsigned long aRequestClientCert); */
NS_IMETHODIMP nsTLSServerSocket::SetRequestClientCertificate(uint32_t aRequestClientCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITLSClientStatus */
#define NS_ITLSCLIENTSTATUS_IID_STR "19668ea4-e5ad-4182-9698-7e890d48f327"

#define NS_ITLSCLIENTSTATUS_IID \
  {0x19668ea4, 0xe5ad, 0x4182, \
    { 0x96, 0x98, 0x7e, 0x89, 0x0d, 0x48, 0xf3, 0x27 }}

class NS_NO_VTABLE nsITLSClientStatus : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITLSCLIENTSTATUS_IID)

  /* readonly attribute nsIX509Cert peerCert; */
  NS_IMETHOD GetPeerCert(nsIX509Cert * *aPeerCert) = 0;

  enum {
    SSL_VERSION_3 = 768,
    TLS_VERSION_1 = 769,
    TLS_VERSION_1_1 = 770,
    TLS_VERSION_1_2 = 771,
    TLS_VERSION_UNKNOWN = -1
  };

  /* readonly attribute short tlsVersionUsed; */
  NS_IMETHOD GetTlsVersionUsed(int16_t *aTlsVersionUsed) = 0;

  /* readonly attribute ACString cipherName; */
  NS_IMETHOD GetCipherName(nsACString & aCipherName) = 0;

  /* readonly attribute unsigned long keyLength; */
  NS_IMETHOD GetKeyLength(uint32_t *aKeyLength) = 0;

  /* readonly attribute unsigned long macLength; */
  NS_IMETHOD GetMacLength(uint32_t *aMacLength) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITLSClientStatus, NS_ITLSCLIENTSTATUS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITLSCLIENTSTATUS \
  NS_IMETHOD GetPeerCert(nsIX509Cert * *aPeerCert) override; \
  NS_IMETHOD GetTlsVersionUsed(int16_t *aTlsVersionUsed) override; \
  NS_IMETHOD GetCipherName(nsACString & aCipherName) override; \
  NS_IMETHOD GetKeyLength(uint32_t *aKeyLength) override; \
  NS_IMETHOD GetMacLength(uint32_t *aMacLength) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITLSCLIENTSTATUS(_to) \
  NS_IMETHOD GetPeerCert(nsIX509Cert * *aPeerCert) override { return _to GetPeerCert(aPeerCert); } \
  NS_IMETHOD GetTlsVersionUsed(int16_t *aTlsVersionUsed) override { return _to GetTlsVersionUsed(aTlsVersionUsed); } \
  NS_IMETHOD GetCipherName(nsACString & aCipherName) override { return _to GetCipherName(aCipherName); } \
  NS_IMETHOD GetKeyLength(uint32_t *aKeyLength) override { return _to GetKeyLength(aKeyLength); } \
  NS_IMETHOD GetMacLength(uint32_t *aMacLength) override { return _to GetMacLength(aMacLength); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITLSCLIENTSTATUS(_to) \
  NS_IMETHOD GetPeerCert(nsIX509Cert * *aPeerCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPeerCert(aPeerCert); } \
  NS_IMETHOD GetTlsVersionUsed(int16_t *aTlsVersionUsed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTlsVersionUsed(aTlsVersionUsed); } \
  NS_IMETHOD GetCipherName(nsACString & aCipherName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCipherName(aCipherName); } \
  NS_IMETHOD GetKeyLength(uint32_t *aKeyLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyLength(aKeyLength); } \
  NS_IMETHOD GetMacLength(uint32_t *aMacLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMacLength(aMacLength); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTLSClientStatus : public nsITLSClientStatus
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITLSCLIENTSTATUS

  nsTLSClientStatus();

private:
  ~nsTLSClientStatus();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTLSClientStatus, nsITLSClientStatus)

nsTLSClientStatus::nsTLSClientStatus()
{
  /* member initializers and constructor code */
}

nsTLSClientStatus::~nsTLSClientStatus()
{
  /* destructor code */
}

/* readonly attribute nsIX509Cert peerCert; */
NS_IMETHODIMP nsTLSClientStatus::GetPeerCert(nsIX509Cert * *aPeerCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short tlsVersionUsed; */
NS_IMETHODIMP nsTLSClientStatus::GetTlsVersionUsed(int16_t *aTlsVersionUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString cipherName; */
NS_IMETHODIMP nsTLSClientStatus::GetCipherName(nsACString & aCipherName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long keyLength; */
NS_IMETHODIMP nsTLSClientStatus::GetKeyLength(uint32_t *aKeyLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long macLength; */
NS_IMETHODIMP nsTLSClientStatus::GetMacLength(uint32_t *aMacLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITLSServerConnectionInfo */
#define NS_ITLSSERVERCONNECTIONINFO_IID_STR "8a93f5d5-eddd-4c62-a4bd-bfd297653184"

#define NS_ITLSSERVERCONNECTIONINFO_IID \
  {0x8a93f5d5, 0xeddd, 0x4c62, \
    { 0xa4, 0xbd, 0xbf, 0xd2, 0x97, 0x65, 0x31, 0x84 }}

class NS_NO_VTABLE nsITLSServerConnectionInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITLSSERVERCONNECTIONINFO_IID)

  /* void setSecurityObserver (in nsITLSServerSecurityObserver observer); */
  NS_IMETHOD SetSecurityObserver(nsITLSServerSecurityObserver *observer) = 0;

  /* readonly attribute nsITLSServerSocket serverSocket; */
  NS_IMETHOD GetServerSocket(nsITLSServerSocket * *aServerSocket) = 0;

  /* readonly attribute nsITLSClientStatus status; */
  NS_IMETHOD GetStatus(nsITLSClientStatus * *aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITLSServerConnectionInfo, NS_ITLSSERVERCONNECTIONINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITLSSERVERCONNECTIONINFO \
  NS_IMETHOD SetSecurityObserver(nsITLSServerSecurityObserver *observer) override; \
  NS_IMETHOD GetServerSocket(nsITLSServerSocket * *aServerSocket) override; \
  NS_IMETHOD GetStatus(nsITLSClientStatus * *aStatus) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITLSSERVERCONNECTIONINFO(_to) \
  NS_IMETHOD SetSecurityObserver(nsITLSServerSecurityObserver *observer) override { return _to SetSecurityObserver(observer); } \
  NS_IMETHOD GetServerSocket(nsITLSServerSocket * *aServerSocket) override { return _to GetServerSocket(aServerSocket); } \
  NS_IMETHOD GetStatus(nsITLSClientStatus * *aStatus) override { return _to GetStatus(aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITLSSERVERCONNECTIONINFO(_to) \
  NS_IMETHOD SetSecurityObserver(nsITLSServerSecurityObserver *observer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSecurityObserver(observer); } \
  NS_IMETHOD GetServerSocket(nsITLSServerSocket * *aServerSocket) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServerSocket(aServerSocket); } \
  NS_IMETHOD GetStatus(nsITLSClientStatus * *aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTLSServerConnectionInfo : public nsITLSServerConnectionInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITLSSERVERCONNECTIONINFO

  nsTLSServerConnectionInfo();

private:
  ~nsTLSServerConnectionInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTLSServerConnectionInfo, nsITLSServerConnectionInfo)

nsTLSServerConnectionInfo::nsTLSServerConnectionInfo()
{
  /* member initializers and constructor code */
}

nsTLSServerConnectionInfo::~nsTLSServerConnectionInfo()
{
  /* destructor code */
}

/* void setSecurityObserver (in nsITLSServerSecurityObserver observer); */
NS_IMETHODIMP nsTLSServerConnectionInfo::SetSecurityObserver(nsITLSServerSecurityObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsITLSServerSocket serverSocket; */
NS_IMETHODIMP nsTLSServerConnectionInfo::GetServerSocket(nsITLSServerSocket * *aServerSocket)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsITLSClientStatus status; */
NS_IMETHODIMP nsTLSServerConnectionInfo::GetStatus(nsITLSClientStatus * *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITLSServerSecurityObserver */
#define NS_ITLSSERVERSECURITYOBSERVER_IID_STR "1f62e1ae-e546-4a38-8917-d428472ed736"

#define NS_ITLSSERVERSECURITYOBSERVER_IID \
  {0x1f62e1ae, 0xe546, 0x4a38, \
    { 0x89, 0x17, 0xd4, 0x28, 0x47, 0x2e, 0xd7, 0x36 }}

class NS_NO_VTABLE nsITLSServerSecurityObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITLSSERVERSECURITYOBSERVER_IID)

  /* void onHandshakeDone (in nsITLSServerSocket aServer, in nsITLSClientStatus aStatus); */
  NS_IMETHOD OnHandshakeDone(nsITLSServerSocket *aServer, nsITLSClientStatus *aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITLSServerSecurityObserver, NS_ITLSSERVERSECURITYOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITLSSERVERSECURITYOBSERVER \
  NS_IMETHOD OnHandshakeDone(nsITLSServerSocket *aServer, nsITLSClientStatus *aStatus) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITLSSERVERSECURITYOBSERVER(_to) \
  NS_IMETHOD OnHandshakeDone(nsITLSServerSocket *aServer, nsITLSClientStatus *aStatus) override { return _to OnHandshakeDone(aServer, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITLSSERVERSECURITYOBSERVER(_to) \
  NS_IMETHOD OnHandshakeDone(nsITLSServerSocket *aServer, nsITLSClientStatus *aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnHandshakeDone(aServer, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTLSServerSecurityObserver : public nsITLSServerSecurityObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITLSSERVERSECURITYOBSERVER

  nsTLSServerSecurityObserver();

private:
  ~nsTLSServerSecurityObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTLSServerSecurityObserver, nsITLSServerSecurityObserver)

nsTLSServerSecurityObserver::nsTLSServerSecurityObserver()
{
  /* member initializers and constructor code */
}

nsTLSServerSecurityObserver::~nsTLSServerSecurityObserver()
{
  /* destructor code */
}

/* void onHandshakeDone (in nsITLSServerSocket aServer, in nsITLSClientStatus aStatus); */
NS_IMETHODIMP nsTLSServerSecurityObserver::OnHandshakeDone(nsITLSServerSocket *aServer, nsITLSClientStatus *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITLSServerSocket_h__ */
