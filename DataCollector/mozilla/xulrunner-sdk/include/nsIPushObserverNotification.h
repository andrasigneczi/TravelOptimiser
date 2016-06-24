/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPushObserverNotification.idl
 */

#ifndef __gen_nsIPushObserverNotification_h__
#define __gen_nsIPushObserverNotification_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPushObserverNotification */
#define NS_IPUSHOBSERVERNOTIFICATION_IID_STR "56f57607-28b6-44b0-aa56-3d4d3c88be15"

#define NS_IPUSHOBSERVERNOTIFICATION_IID \
  {0x56f57607, 0x28b6, 0x44b0, \
    { 0xaa, 0x56, 0x3d, 0x4d, 0x3c, 0x88, 0xbe, 0x15 }}

class NS_NO_VTABLE nsIPushObserverNotification : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPUSHOBSERVERNOTIFICATION_IID)

  /* attribute string pushEndpoint; */
  NS_IMETHOD GetPushEndpoint(char * *aPushEndpoint) = 0;
  NS_IMETHOD SetPushEndpoint(const char * aPushEndpoint) = 0;

  /* attribute long long version; */
  NS_IMETHOD GetVersion(int64_t *aVersion) = 0;
  NS_IMETHOD SetVersion(int64_t aVersion) = 0;

  /* attribute string data; */
  NS_IMETHOD GetData(char * *aData) = 0;
  NS_IMETHOD SetData(const char * aData) = 0;

  /* attribute long long pushCount; */
  NS_IMETHOD GetPushCount(int64_t *aPushCount) = 0;
  NS_IMETHOD SetPushCount(int64_t aPushCount) = 0;

  /* attribute long long lastPush; */
  NS_IMETHOD GetLastPush(int64_t *aLastPush) = 0;
  NS_IMETHOD SetLastPush(int64_t aLastPush) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPushObserverNotification, NS_IPUSHOBSERVERNOTIFICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPUSHOBSERVERNOTIFICATION \
  NS_IMETHOD GetPushEndpoint(char * *aPushEndpoint) override; \
  NS_IMETHOD SetPushEndpoint(const char * aPushEndpoint) override; \
  NS_IMETHOD GetVersion(int64_t *aVersion) override; \
  NS_IMETHOD SetVersion(int64_t aVersion) override; \
  NS_IMETHOD GetData(char * *aData) override; \
  NS_IMETHOD SetData(const char * aData) override; \
  NS_IMETHOD GetPushCount(int64_t *aPushCount) override; \
  NS_IMETHOD SetPushCount(int64_t aPushCount) override; \
  NS_IMETHOD GetLastPush(int64_t *aLastPush) override; \
  NS_IMETHOD SetLastPush(int64_t aLastPush) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPUSHOBSERVERNOTIFICATION(_to) \
  NS_IMETHOD GetPushEndpoint(char * *aPushEndpoint) override { return _to GetPushEndpoint(aPushEndpoint); } \
  NS_IMETHOD SetPushEndpoint(const char * aPushEndpoint) override { return _to SetPushEndpoint(aPushEndpoint); } \
  NS_IMETHOD GetVersion(int64_t *aVersion) override { return _to GetVersion(aVersion); } \
  NS_IMETHOD SetVersion(int64_t aVersion) override { return _to SetVersion(aVersion); } \
  NS_IMETHOD GetData(char * *aData) override { return _to GetData(aData); } \
  NS_IMETHOD SetData(const char * aData) override { return _to SetData(aData); } \
  NS_IMETHOD GetPushCount(int64_t *aPushCount) override { return _to GetPushCount(aPushCount); } \
  NS_IMETHOD SetPushCount(int64_t aPushCount) override { return _to SetPushCount(aPushCount); } \
  NS_IMETHOD GetLastPush(int64_t *aLastPush) override { return _to GetLastPush(aLastPush); } \
  NS_IMETHOD SetLastPush(int64_t aLastPush) override { return _to SetLastPush(aLastPush); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPUSHOBSERVERNOTIFICATION(_to) \
  NS_IMETHOD GetPushEndpoint(char * *aPushEndpoint) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPushEndpoint(aPushEndpoint); } \
  NS_IMETHOD SetPushEndpoint(const char * aPushEndpoint) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPushEndpoint(aPushEndpoint); } \
  NS_IMETHOD GetVersion(int64_t *aVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD SetVersion(int64_t aVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVersion(aVersion); } \
  NS_IMETHOD GetData(char * *aData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD SetData(const char * aData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(aData); } \
  NS_IMETHOD GetPushCount(int64_t *aPushCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPushCount(aPushCount); } \
  NS_IMETHOD SetPushCount(int64_t aPushCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPushCount(aPushCount); } \
  NS_IMETHOD GetLastPush(int64_t *aLastPush) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastPush(aLastPush); } \
  NS_IMETHOD SetLastPush(int64_t aLastPush) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLastPush(aLastPush); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPushObserverNotification : public nsIPushObserverNotification
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPUSHOBSERVERNOTIFICATION

  nsPushObserverNotification();

private:
  ~nsPushObserverNotification();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPushObserverNotification, nsIPushObserverNotification)

nsPushObserverNotification::nsPushObserverNotification()
{
  /* member initializers and constructor code */
}

nsPushObserverNotification::~nsPushObserverNotification()
{
  /* destructor code */
}

/* attribute string pushEndpoint; */
NS_IMETHODIMP nsPushObserverNotification::GetPushEndpoint(char * *aPushEndpoint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPushObserverNotification::SetPushEndpoint(const char * aPushEndpoint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long long version; */
NS_IMETHODIMP nsPushObserverNotification::GetVersion(int64_t *aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPushObserverNotification::SetVersion(int64_t aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string data; */
NS_IMETHODIMP nsPushObserverNotification::GetData(char * *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPushObserverNotification::SetData(const char * aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long long pushCount; */
NS_IMETHODIMP nsPushObserverNotification::GetPushCount(int64_t *aPushCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPushObserverNotification::SetPushCount(int64_t aPushCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long long lastPush; */
NS_IMETHODIMP nsPushObserverNotification::GetLastPush(int64_t *aLastPush)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPushObserverNotification::SetLastPush(int64_t aLastPush)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPushObserverNotification_h__ */
