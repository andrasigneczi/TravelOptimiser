/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITCPPresentationServer.idl
 */

#ifndef __gen_nsITCPPresentationServer_h__
#define __gen_nsITCPPresentationServer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPresentationDevice; /* forward declaration */


/* starting interface:    nsITCPPresentationServerListener */
#define NS_ITCPPRESENTATIONSERVERLISTENER_IID_STR "b0dc6b1f-5f6f-455d-a917-90d0ad37186b"

#define NS_ITCPPRESENTATIONSERVERLISTENER_IID \
  {0xb0dc6b1f, 0x5f6f, 0x455d, \
    { 0xa9, 0x17, 0x90, 0xd0, 0xad, 0x37, 0x18, 0x6b }}

class NS_NO_VTABLE nsITCPPresentationServerListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPPRESENTATIONSERVERLISTENER_IID)

  /* void onClose (in nsresult aReason); */
  NS_IMETHOD OnClose(nsresult aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPPresentationServerListener, NS_ITCPPRESENTATIONSERVERLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPPRESENTATIONSERVERLISTENER \
  NS_IMETHOD OnClose(nsresult aReason) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPPRESENTATIONSERVERLISTENER(_to) \
  NS_IMETHOD OnClose(nsresult aReason) override { return _to OnClose(aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPPRESENTATIONSERVERLISTENER(_to) \
  NS_IMETHOD OnClose(nsresult aReason) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnClose(aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPPresentationServerListener : public nsITCPPresentationServerListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPPRESENTATIONSERVERLISTENER

  nsTCPPresentationServerListener();

private:
  ~nsTCPPresentationServerListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTCPPresentationServerListener, nsITCPPresentationServerListener)

nsTCPPresentationServerListener::nsTCPPresentationServerListener()
{
  /* member initializers and constructor code */
}

nsTCPPresentationServerListener::~nsTCPPresentationServerListener()
{
  /* destructor code */
}

/* void onClose (in nsresult aReason); */
NS_IMETHODIMP nsTCPPresentationServerListener::OnClose(nsresult aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITCPPresentationServer */
#define NS_ITCPPRESENTATIONSERVER_IID_STR "4fc57682-33d5-4793-b149-e2cc4714d70f"

#define NS_ITCPPRESENTATIONSERVER_IID \
  {0x4fc57682, 0x33d5, 0x4793, \
    { 0xb1, 0x49, 0xe2, 0xcc, 0x47, 0x14, 0xd7, 0x0f }}

class NS_NO_VTABLE nsITCPPresentationServer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPPRESENTATIONSERVER_IID)

  /* void init ([optional] in AUTF8String aId, [optional] in uint16_t aPort); */
  NS_IMETHOD Init(const nsACString & aId, uint16_t aPort) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* nsIPresentationDevice createTCPDevice (in AUTF8String aId, in AUTF8String aName, in AUTF8String aType, in AUTF8String aHost, in uint16_t aPort); */
  NS_IMETHOD CreateTCPDevice(const nsACString & aId, const nsACString & aName, const nsACString & aType, const nsACString & aHost, uint16_t aPort, nsIPresentationDevice * *_retval) = 0;

  /* nsIPresentationDevice getTCPDevice (in AUTF8String aId); */
  NS_IMETHOD GetTCPDevice(const nsACString & aId, nsIPresentationDevice * *_retval) = 0;

  /* void removeTCPDevice (in AUTF8String aId); */
  NS_IMETHOD RemoveTCPDevice(const nsACString & aId) = 0;

  /* readonly attribute uint16_t port; */
  NS_IMETHOD GetPort(uint16_t *aPort) = 0;

  /* attribute AUTF8String id; */
  NS_IMETHOD GetId(nsACString & aId) = 0;
  NS_IMETHOD SetId(const nsACString & aId) = 0;

  /* attribute nsITCPPresentationServerListener listener; */
  NS_IMETHOD GetListener(nsITCPPresentationServerListener * *aListener) = 0;
  NS_IMETHOD SetListener(nsITCPPresentationServerListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPPresentationServer, NS_ITCPPRESENTATIONSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPPRESENTATIONSERVER \
  NS_IMETHOD Init(const nsACString & aId, uint16_t aPort) override; \
  NS_IMETHOD Close(void) override; \
  NS_IMETHOD CreateTCPDevice(const nsACString & aId, const nsACString & aName, const nsACString & aType, const nsACString & aHost, uint16_t aPort, nsIPresentationDevice * *_retval) override; \
  NS_IMETHOD GetTCPDevice(const nsACString & aId, nsIPresentationDevice * *_retval) override; \
  NS_IMETHOD RemoveTCPDevice(const nsACString & aId) override; \
  NS_IMETHOD GetPort(uint16_t *aPort) override; \
  NS_IMETHOD GetId(nsACString & aId) override; \
  NS_IMETHOD SetId(const nsACString & aId) override; \
  NS_IMETHOD GetListener(nsITCPPresentationServerListener * *aListener) override; \
  NS_IMETHOD SetListener(nsITCPPresentationServerListener *aListener) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPPRESENTATIONSERVER(_to) \
  NS_IMETHOD Init(const nsACString & aId, uint16_t aPort) override { return _to Init(aId, aPort); } \
  NS_IMETHOD Close(void) override { return _to Close(); } \
  NS_IMETHOD CreateTCPDevice(const nsACString & aId, const nsACString & aName, const nsACString & aType, const nsACString & aHost, uint16_t aPort, nsIPresentationDevice * *_retval) override { return _to CreateTCPDevice(aId, aName, aType, aHost, aPort, _retval); } \
  NS_IMETHOD GetTCPDevice(const nsACString & aId, nsIPresentationDevice * *_retval) override { return _to GetTCPDevice(aId, _retval); } \
  NS_IMETHOD RemoveTCPDevice(const nsACString & aId) override { return _to RemoveTCPDevice(aId); } \
  NS_IMETHOD GetPort(uint16_t *aPort) override { return _to GetPort(aPort); } \
  NS_IMETHOD GetId(nsACString & aId) override { return _to GetId(aId); } \
  NS_IMETHOD SetId(const nsACString & aId) override { return _to SetId(aId); } \
  NS_IMETHOD GetListener(nsITCPPresentationServerListener * *aListener) override { return _to GetListener(aListener); } \
  NS_IMETHOD SetListener(nsITCPPresentationServerListener *aListener) override { return _to SetListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPPRESENTATIONSERVER(_to) \
  NS_IMETHOD Init(const nsACString & aId, uint16_t aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aId, aPort); } \
  NS_IMETHOD Close(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD CreateTCPDevice(const nsACString & aId, const nsACString & aName, const nsACString & aType, const nsACString & aHost, uint16_t aPort, nsIPresentationDevice * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTCPDevice(aId, aName, aType, aHost, aPort, _retval); } \
  NS_IMETHOD GetTCPDevice(const nsACString & aId, nsIPresentationDevice * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTCPDevice(aId, _retval); } \
  NS_IMETHOD RemoveTCPDevice(const nsACString & aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveTCPDevice(aId); } \
  NS_IMETHOD GetPort(uint16_t *aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetId(nsACString & aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD SetId(const nsACString & aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetId(aId); } \
  NS_IMETHOD GetListener(nsITCPPresentationServerListener * *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListener(aListener); } \
  NS_IMETHOD SetListener(nsITCPPresentationServerListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPPresentationServer : public nsITCPPresentationServer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPPRESENTATIONSERVER

  nsTCPPresentationServer();

private:
  ~nsTCPPresentationServer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTCPPresentationServer, nsITCPPresentationServer)

nsTCPPresentationServer::nsTCPPresentationServer()
{
  /* member initializers and constructor code */
}

nsTCPPresentationServer::~nsTCPPresentationServer()
{
  /* destructor code */
}

/* void init ([optional] in AUTF8String aId, [optional] in uint16_t aPort); */
NS_IMETHODIMP nsTCPPresentationServer::Init(const nsACString & aId, uint16_t aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsTCPPresentationServer::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPresentationDevice createTCPDevice (in AUTF8String aId, in AUTF8String aName, in AUTF8String aType, in AUTF8String aHost, in uint16_t aPort); */
NS_IMETHODIMP nsTCPPresentationServer::CreateTCPDevice(const nsACString & aId, const nsACString & aName, const nsACString & aType, const nsACString & aHost, uint16_t aPort, nsIPresentationDevice * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPresentationDevice getTCPDevice (in AUTF8String aId); */
NS_IMETHODIMP nsTCPPresentationServer::GetTCPDevice(const nsACString & aId, nsIPresentationDevice * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeTCPDevice (in AUTF8String aId); */
NS_IMETHODIMP nsTCPPresentationServer::RemoveTCPDevice(const nsACString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint16_t port; */
NS_IMETHODIMP nsTCPPresentationServer::GetPort(uint16_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String id; */
NS_IMETHODIMP nsTCPPresentationServer::GetId(nsACString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTCPPresentationServer::SetId(const nsACString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsITCPPresentationServerListener listener; */
NS_IMETHODIMP nsTCPPresentationServer::GetListener(nsITCPPresentationServerListener * *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTCPPresentationServer::SetListener(nsITCPPresentationServerListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITCPPresentationServer_h__ */
