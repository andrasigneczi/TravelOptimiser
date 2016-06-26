/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISpeculativeConnect.idl
 */

#ifndef __gen_nsISpeculativeConnect_h__
#define __gen_nsISpeculativeConnect_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsISpeculativeConnect */
#define NS_ISPECULATIVECONNECT_IID_STR "d74a17ac-5b8a-4824-a309-b1f04a3c4aed"

#define NS_ISPECULATIVECONNECT_IID \
  {0xd74a17ac, 0x5b8a, 0x4824, \
    { 0xa3, 0x09, 0xb1, 0xf0, 0x4a, 0x3c, 0x4a, 0xed }}

class NS_NO_VTABLE nsISpeculativeConnect : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISPECULATIVECONNECT_IID)

  /* void speculativeConnect (in nsIURI aURI, in nsIInterfaceRequestor aCallbacks); */
  NS_IMETHOD SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) = 0;

  /* void speculativeAnonymousConnect (in nsIURI aURI, in nsIInterfaceRequestor aCallbacks); */
  NS_IMETHOD SpeculativeAnonymousConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISpeculativeConnect, NS_ISPECULATIVECONNECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISPECULATIVECONNECT \
  NS_IMETHOD SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) override; \
  NS_IMETHOD SpeculativeAnonymousConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISPECULATIVECONNECT(_to) \
  NS_IMETHOD SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) override { return _to SpeculativeConnect(aURI, aCallbacks); } \
  NS_IMETHOD SpeculativeAnonymousConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) override { return _to SpeculativeAnonymousConnect(aURI, aCallbacks); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISPECULATIVECONNECT(_to) \
  NS_IMETHOD SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SpeculativeConnect(aURI, aCallbacks); } \
  NS_IMETHOD SpeculativeAnonymousConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SpeculativeAnonymousConnect(aURI, aCallbacks); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSpeculativeConnect : public nsISpeculativeConnect
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISPECULATIVECONNECT

  nsSpeculativeConnect();

private:
  ~nsSpeculativeConnect();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSpeculativeConnect, nsISpeculativeConnect)

nsSpeculativeConnect::nsSpeculativeConnect()
{
  /* member initializers and constructor code */
}

nsSpeculativeConnect::~nsSpeculativeConnect()
{
  /* destructor code */
}

/* void speculativeConnect (in nsIURI aURI, in nsIInterfaceRequestor aCallbacks); */
NS_IMETHODIMP nsSpeculativeConnect::SpeculativeConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void speculativeAnonymousConnect (in nsIURI aURI, in nsIInterfaceRequestor aCallbacks); */
NS_IMETHODIMP nsSpeculativeConnect::SpeculativeAnonymousConnect(nsIURI *aURI, nsIInterfaceRequestor *aCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISpeculativeConnectionOverrider */
#define NS_ISPECULATIVECONNECTIONOVERRIDER_IID_STR "f6a0d1e5-369f-4abc-81ae-d370d36e4006"

#define NS_ISPECULATIVECONNECTIONOVERRIDER_IID \
  {0xf6a0d1e5, 0x369f, 0x4abc, \
    { 0x81, 0xae, 0xd3, 0x70, 0xd3, 0x6e, 0x40, 0x06 }}

class NS_NO_VTABLE nsISpeculativeConnectionOverrider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISPECULATIVECONNECTIONOVERRIDER_IID)

  /* [infallible] readonly attribute unsigned long parallelSpeculativeConnectLimit; */
  NS_IMETHOD GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit) = 0;
  inline uint32_t GetParallelSpeculativeConnectLimit()
  {
    uint32_t result;
    mozilla::DebugOnly<nsresult> rv = GetParallelSpeculativeConnectLimit(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean ignorePossibleSpdyConnections; */
  NS_IMETHOD GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections) = 0;
  inline bool GetIgnorePossibleSpdyConnections()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIgnorePossibleSpdyConnections(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean ignoreIdle; */
  NS_IMETHOD GetIgnoreIdle(bool *aIgnoreIdle) = 0;
  inline bool GetIgnoreIdle()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIgnoreIdle(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean isFromPredictor; */
  NS_IMETHOD GetIsFromPredictor(bool *aIsFromPredictor) = 0;
  inline bool GetIsFromPredictor()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsFromPredictor(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean allow1918; */
  NS_IMETHOD GetAllow1918(bool *aAllow1918) = 0;
  inline bool GetAllow1918()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetAllow1918(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISpeculativeConnectionOverrider, NS_ISPECULATIVECONNECTIONOVERRIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISPECULATIVECONNECTIONOVERRIDER \
  using nsISpeculativeConnectionOverrider::GetParallelSpeculativeConnectLimit; \
  NS_IMETHOD GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit) override; \
  using nsISpeculativeConnectionOverrider::GetIgnorePossibleSpdyConnections; \
  NS_IMETHOD GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections) override; \
  using nsISpeculativeConnectionOverrider::GetIgnoreIdle; \
  NS_IMETHOD GetIgnoreIdle(bool *aIgnoreIdle) override; \
  using nsISpeculativeConnectionOverrider::GetIsFromPredictor; \
  NS_IMETHOD GetIsFromPredictor(bool *aIsFromPredictor) override; \
  using nsISpeculativeConnectionOverrider::GetAllow1918; \
  NS_IMETHOD GetAllow1918(bool *aAllow1918) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISPECULATIVECONNECTIONOVERRIDER(_to) \
  using nsISpeculativeConnectionOverrider::GetParallelSpeculativeConnectLimit; \
  NS_IMETHOD GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit) override { return _to GetParallelSpeculativeConnectLimit(aParallelSpeculativeConnectLimit); } \
  using nsISpeculativeConnectionOverrider::GetIgnorePossibleSpdyConnections; \
  NS_IMETHOD GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections) override { return _to GetIgnorePossibleSpdyConnections(aIgnorePossibleSpdyConnections); } \
  using nsISpeculativeConnectionOverrider::GetIgnoreIdle; \
  NS_IMETHOD GetIgnoreIdle(bool *aIgnoreIdle) override { return _to GetIgnoreIdle(aIgnoreIdle); } \
  using nsISpeculativeConnectionOverrider::GetIsFromPredictor; \
  NS_IMETHOD GetIsFromPredictor(bool *aIsFromPredictor) override { return _to GetIsFromPredictor(aIsFromPredictor); } \
  using nsISpeculativeConnectionOverrider::GetAllow1918; \
  NS_IMETHOD GetAllow1918(bool *aAllow1918) override { return _to GetAllow1918(aAllow1918); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISPECULATIVECONNECTIONOVERRIDER(_to) \
  NS_IMETHOD GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParallelSpeculativeConnectLimit(aParallelSpeculativeConnectLimit); } \
  NS_IMETHOD GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIgnorePossibleSpdyConnections(aIgnorePossibleSpdyConnections); } \
  NS_IMETHOD GetIgnoreIdle(bool *aIgnoreIdle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIgnoreIdle(aIgnoreIdle); } \
  NS_IMETHOD GetIsFromPredictor(bool *aIsFromPredictor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFromPredictor(aIsFromPredictor); } \
  NS_IMETHOD GetAllow1918(bool *aAllow1918) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllow1918(aAllow1918); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSpeculativeConnectionOverrider : public nsISpeculativeConnectionOverrider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISPECULATIVECONNECTIONOVERRIDER

  nsSpeculativeConnectionOverrider();

private:
  ~nsSpeculativeConnectionOverrider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSpeculativeConnectionOverrider, nsISpeculativeConnectionOverrider)

nsSpeculativeConnectionOverrider::nsSpeculativeConnectionOverrider()
{
  /* member initializers and constructor code */
}

nsSpeculativeConnectionOverrider::~nsSpeculativeConnectionOverrider()
{
  /* destructor code */
}

/* [infallible] readonly attribute unsigned long parallelSpeculativeConnectLimit; */
NS_IMETHODIMP nsSpeculativeConnectionOverrider::GetParallelSpeculativeConnectLimit(uint32_t *aParallelSpeculativeConnectLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean ignorePossibleSpdyConnections; */
NS_IMETHODIMP nsSpeculativeConnectionOverrider::GetIgnorePossibleSpdyConnections(bool *aIgnorePossibleSpdyConnections)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean ignoreIdle; */
NS_IMETHODIMP nsSpeculativeConnectionOverrider::GetIgnoreIdle(bool *aIgnoreIdle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isFromPredictor; */
NS_IMETHODIMP nsSpeculativeConnectionOverrider::GetIsFromPredictor(bool *aIsFromPredictor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean allow1918; */
NS_IMETHODIMP nsSpeculativeConnectionOverrider::GetAllow1918(bool *aAllow1918)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISpeculativeConnect_h__ */
