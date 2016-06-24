/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDataChannel.idl
 */

#ifndef __gen_nsIDOMDataChannel_h__
#define __gen_nsIDOMDataChannel_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef GetBinaryType
// Windows apparently has a #define for GetBinaryType...
#undef GetBinaryType
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMDataChannel */
#define NS_IDOMDATACHANNEL_IID_STR "b00a4ca7-312e-4926-84f6-8ebb43e53d83"

#define NS_IDOMDATACHANNEL_IID \
  {0xb00a4ca7, 0x312e, 0x4926, \
    { 0x84, 0xf6, 0x8e, 0xbb, 0x43, 0xe5, 0x3d, 0x83 }}

class NS_NO_VTABLE nsIDOMDataChannel : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDATACHANNEL_IID)

  /* readonly attribute DOMString label; */
  NS_IMETHOD GetLabel(nsAString & aLabel) = 0;

  /* readonly attribute DOMString protocol; */
  NS_IMETHOD GetProtocol(nsAString & aProtocol) = 0;

  /* readonly attribute boolean reliable; */
  NS_IMETHOD GetReliable(bool *aReliable) = 0;

  /* readonly attribute boolean ordered; */
  NS_IMETHOD GetOrdered(bool *aOrdered) = 0;

  /* readonly attribute DOMString readyState; */
  NS_IMETHOD GetReadyState(nsAString & aReadyState) = 0;

  /* readonly attribute unsigned long bufferedAmount; */
  NS_IMETHOD GetBufferedAmount(uint32_t *aBufferedAmount) = 0;

  /* readonly attribute unsigned short id; */
  NS_IMETHOD GetId(uint16_t *aId) = 0;

  /* readonly attribute unsigned short stream; */
  NS_IMETHOD GetStream(uint16_t *aStream) = 0;

  /* [implicit_jscontext] attribute jsval onopen; */
  NS_IMETHOD GetOnopen(JSContext* cx, JS::MutableHandleValue aOnopen) = 0;
  NS_IMETHOD SetOnopen(JSContext* cx, JS::HandleValue aOnopen) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) = 0;

  /* [implicit_jscontext] attribute jsval onclose; */
  NS_IMETHOD GetOnclose(JSContext* cx, JS::MutableHandleValue aOnclose) = 0;
  NS_IMETHOD SetOnclose(JSContext* cx, JS::HandleValue aOnclose) = 0;

  /* [implicit_jscontext] attribute jsval onmessage; */
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::MutableHandleValue aOnmessage) = 0;
  NS_IMETHOD SetOnmessage(JSContext* cx, JS::HandleValue aOnmessage) = 0;

  /* attribute DOMString binaryType; */
  NS_IMETHOD GetBinaryType(nsAString & aBinaryType) = 0;
  NS_IMETHOD SetBinaryType(const nsAString & aBinaryType) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDataChannel, NS_IDOMDATACHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDATACHANNEL \
  NS_IMETHOD GetLabel(nsAString & aLabel) override; \
  NS_IMETHOD GetProtocol(nsAString & aProtocol) override; \
  NS_IMETHOD GetReliable(bool *aReliable) override; \
  NS_IMETHOD GetOrdered(bool *aOrdered) override; \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) override; \
  NS_IMETHOD GetBufferedAmount(uint32_t *aBufferedAmount) override; \
  NS_IMETHOD GetId(uint16_t *aId) override; \
  NS_IMETHOD GetStream(uint16_t *aStream) override; \
  NS_IMETHOD GetOnopen(JSContext* cx, JS::MutableHandleValue aOnopen) override; \
  NS_IMETHOD SetOnopen(JSContext* cx, JS::HandleValue aOnopen) override; \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) override; \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) override; \
  NS_IMETHOD GetOnclose(JSContext* cx, JS::MutableHandleValue aOnclose) override; \
  NS_IMETHOD SetOnclose(JSContext* cx, JS::HandleValue aOnclose) override; \
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::MutableHandleValue aOnmessage) override; \
  NS_IMETHOD SetOnmessage(JSContext* cx, JS::HandleValue aOnmessage) override; \
  NS_IMETHOD GetBinaryType(nsAString & aBinaryType) override; \
  NS_IMETHOD SetBinaryType(const nsAString & aBinaryType) override; \
  NS_IMETHOD Close(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDATACHANNEL(_to) \
  NS_IMETHOD GetLabel(nsAString & aLabel) override { return _to GetLabel(aLabel); } \
  NS_IMETHOD GetProtocol(nsAString & aProtocol) override { return _to GetProtocol(aProtocol); } \
  NS_IMETHOD GetReliable(bool *aReliable) override { return _to GetReliable(aReliable); } \
  NS_IMETHOD GetOrdered(bool *aOrdered) override { return _to GetOrdered(aOrdered); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) override { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetBufferedAmount(uint32_t *aBufferedAmount) override { return _to GetBufferedAmount(aBufferedAmount); } \
  NS_IMETHOD GetId(uint16_t *aId) override { return _to GetId(aId); } \
  NS_IMETHOD GetStream(uint16_t *aStream) override { return _to GetStream(aStream); } \
  NS_IMETHOD GetOnopen(JSContext* cx, JS::MutableHandleValue aOnopen) override { return _to GetOnopen(cx, aOnopen); } \
  NS_IMETHOD SetOnopen(JSContext* cx, JS::HandleValue aOnopen) override { return _to SetOnopen(cx, aOnopen); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) override { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) override { return _to SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnclose(JSContext* cx, JS::MutableHandleValue aOnclose) override { return _to GetOnclose(cx, aOnclose); } \
  NS_IMETHOD SetOnclose(JSContext* cx, JS::HandleValue aOnclose) override { return _to SetOnclose(cx, aOnclose); } \
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::MutableHandleValue aOnmessage) override { return _to GetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD SetOnmessage(JSContext* cx, JS::HandleValue aOnmessage) override { return _to SetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD GetBinaryType(nsAString & aBinaryType) override { return _to GetBinaryType(aBinaryType); } \
  NS_IMETHOD SetBinaryType(const nsAString & aBinaryType) override { return _to SetBinaryType(aBinaryType); } \
  NS_IMETHOD Close(void) override { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDATACHANNEL(_to) \
  NS_IMETHOD GetLabel(nsAString & aLabel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLabel(aLabel); } \
  NS_IMETHOD GetProtocol(nsAString & aProtocol) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocol(aProtocol); } \
  NS_IMETHOD GetReliable(bool *aReliable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReliable(aReliable); } \
  NS_IMETHOD GetOrdered(bool *aOrdered) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrdered(aOrdered); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetBufferedAmount(uint32_t *aBufferedAmount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBufferedAmount(aBufferedAmount); } \
  NS_IMETHOD GetId(uint16_t *aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetStream(uint16_t *aStream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStream(aStream); } \
  NS_IMETHOD GetOnopen(JSContext* cx, JS::MutableHandleValue aOnopen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnopen(cx, aOnopen); } \
  NS_IMETHOD SetOnopen(JSContext* cx, JS::HandleValue aOnopen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnopen(cx, aOnopen); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, JS::HandleValue aOnerror) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } \
  NS_IMETHOD GetOnclose(JSContext* cx, JS::MutableHandleValue aOnclose) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclose(cx, aOnclose); } \
  NS_IMETHOD SetOnclose(JSContext* cx, JS::HandleValue aOnclose) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclose(cx, aOnclose); } \
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::MutableHandleValue aOnmessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD SetOnmessage(JSContext* cx, JS::HandleValue aOnmessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD GetBinaryType(nsAString & aBinaryType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBinaryType(aBinaryType); } \
  NS_IMETHOD SetBinaryType(const nsAString & aBinaryType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBinaryType(aBinaryType); } \
  NS_IMETHOD Close(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDataChannel : public nsIDOMDataChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDATACHANNEL

  nsDOMDataChannel();

private:
  ~nsDOMDataChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMDataChannel, nsIDOMDataChannel)

nsDOMDataChannel::nsDOMDataChannel()
{
  /* member initializers and constructor code */
}

nsDOMDataChannel::~nsDOMDataChannel()
{
  /* destructor code */
}

/* readonly attribute DOMString label; */
NS_IMETHODIMP nsDOMDataChannel::GetLabel(nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString protocol; */
NS_IMETHODIMP nsDOMDataChannel::GetProtocol(nsAString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean reliable; */
NS_IMETHODIMP nsDOMDataChannel::GetReliable(bool *aReliable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ordered; */
NS_IMETHODIMP nsDOMDataChannel::GetOrdered(bool *aOrdered)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString readyState; */
NS_IMETHODIMP nsDOMDataChannel::GetReadyState(nsAString & aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long bufferedAmount; */
NS_IMETHODIMP nsDOMDataChannel::GetBufferedAmount(uint32_t *aBufferedAmount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short id; */
NS_IMETHODIMP nsDOMDataChannel::GetId(uint16_t *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short stream; */
NS_IMETHODIMP nsDOMDataChannel::GetStream(uint16_t *aStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onopen; */
NS_IMETHODIMP nsDOMDataChannel::GetOnopen(JSContext* cx, JS::MutableHandleValue aOnopen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataChannel::SetOnopen(JSContext* cx, JS::HandleValue aOnopen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsDOMDataChannel::GetOnerror(JSContext* cx, JS::MutableHandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataChannel::SetOnerror(JSContext* cx, JS::HandleValue aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onclose; */
NS_IMETHODIMP nsDOMDataChannel::GetOnclose(JSContext* cx, JS::MutableHandleValue aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataChannel::SetOnclose(JSContext* cx, JS::HandleValue aOnclose)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmessage; */
NS_IMETHODIMP nsDOMDataChannel::GetOnmessage(JSContext* cx, JS::MutableHandleValue aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataChannel::SetOnmessage(JSContext* cx, JS::HandleValue aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString binaryType; */
NS_IMETHODIMP nsDOMDataChannel::GetBinaryType(nsAString & aBinaryType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDataChannel::SetBinaryType(const nsAString & aBinaryType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDOMDataChannel::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDataChannel_h__ */
