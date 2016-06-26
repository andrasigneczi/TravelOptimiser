/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\IPeerConnection.idl
 */

#ifndef __gen_IPeerConnection_h__
#define __gen_IPeerConnection_h__


#ifndef __gen_nsIThread_h__
#include "nsIThread.h"
#endif

#ifndef __gen_nsIDOMWindow_h__
#include "nsIDOMWindow.h"
#endif

#ifndef __gen_nsIPropertyBag2_h__
#include "nsIPropertyBag2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDataChannel; /* forward declaration */


/* starting interface:    IPeerConnectionManager */
#define IPEERCONNECTIONMANAGER_IID_STR "c2218bd2-2648-4701-8fa6-305d3379e9f8"

#define IPEERCONNECTIONMANAGER_IID \
  {0xc2218bd2, 0x2648, 0x4701, \
    { 0x8f, 0xa6, 0x30, 0x5d, 0x33, 0x79, 0xe9, 0xf8 }}

class NS_NO_VTABLE IPeerConnectionManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IPEERCONNECTIONMANAGER_IID)

  /* boolean hasActivePeerConnection (in unsigned long innerWindowID); */
  NS_IMETHOD HasActivePeerConnection(uint32_t innerWindowID, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IPeerConnectionManager, IPEERCONNECTIONMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IPEERCONNECTIONMANAGER \
  NS_IMETHOD HasActivePeerConnection(uint32_t innerWindowID, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IPEERCONNECTIONMANAGER(_to) \
  NS_IMETHOD HasActivePeerConnection(uint32_t innerWindowID, bool *_retval) override { return _to HasActivePeerConnection(innerWindowID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IPEERCONNECTIONMANAGER(_to) \
  NS_IMETHOD HasActivePeerConnection(uint32_t innerWindowID, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasActivePeerConnection(innerWindowID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IPeerConnectionManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IPEERCONNECTIONMANAGER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, IPeerConnectionManager)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean hasActivePeerConnection (in unsigned long innerWindowID); */
NS_IMETHODIMP _MYCLASS_::HasActivePeerConnection(uint32_t innerWindowID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define IPEERCONNECTION_MANAGER_CONTRACTID "@mozilla.org/dom/peerconnectionmanager;1"

/* starting interface:    IPeerConnectionObserver */
#define IPEERCONNECTIONOBSERVER_IID_STR "d7dfe148-0416-446b-a128-66a7c71ae8d3"

#define IPEERCONNECTIONOBSERVER_IID \
  {0xd7dfe148, 0x0416, 0x446b, \
    { 0xa1, 0x28, 0x66, 0xa7, 0xc7, 0x1a, 0xe8, 0xd3 }}

class NS_NO_VTABLE IPeerConnectionObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IPEERCONNECTIONOBSERVER_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IPeerConnectionObserver, IPEERCONNECTIONOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IPEERCONNECTIONOBSERVER \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IPEERCONNECTIONOBSERVER(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IPEERCONNECTIONOBSERVER(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IPeerConnectionObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IPEERCONNECTIONOBSERVER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, IPeerConnectionObserver)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    IPeerConnection */
#define IPEERCONNECTION_IID_STR "14afc8e7-e421-4d0c-99a5-69308d871481"

#define IPEERCONNECTION_IID \
  {0x14afc8e7, 0xe421, 0x4d0c, \
    { 0x99, 0xa5, 0x69, 0x30, 0x8d, 0x87, 0x14, 0x81 }}

class NS_NO_VTABLE IPeerConnection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IPEERCONNECTION_IID)

  enum {
    kHintAudio = 1U,
    kHintVideo = 2U,
    kActionNone = -1,
    kActionOffer = 0,
    kActionAnswer = 1,
    kActionPRAnswer = 2,
    kActionRollback = 3,
    kIceGathering = 0,
    kIceWaiting = 1,
    kIceChecking = 2,
    kIceConnected = 3,
    kIceFailed = 4,
    kNew = 0,
    kNegotiating = 1,
    kActive = 2,
    kClosing = 3,
    kClosed = 4,
    kDataChannelReliable = 0U,
    kDataChannelPartialReliableRexmit = 1U,
    kDataChannelPartialReliableTimed = 2U,
    kNoError = 0U,
    kInvalidCandidate = 2U,
    kInvalidMediastreamTrack = 3U,
    kInvalidState = 4U,
    kInvalidSessionDescription = 5U,
    kIncompatibleSessionDescription = 6U,
    kIncompatibleMediaStreamTrack = 8U,
    kInternalError = 9U,
    kMaxErrorType = 9U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(IPeerConnection, IPEERCONNECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IPEERCONNECTION \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IPEERCONNECTION(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IPEERCONNECTION(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IPeerConnection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IPEERCONNECTION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, IPeerConnection)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_IPeerConnection_h__ */
