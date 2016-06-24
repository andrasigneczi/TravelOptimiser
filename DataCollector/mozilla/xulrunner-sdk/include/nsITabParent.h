/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITabParent.idl
 */

#ifndef __gen_nsITabParent_h__
#define __gen_nsITabParent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITabParent */
#define NS_ITABPARENT_IID_STR "4d4576eb-ecfe-47b9-93b8-4121518621ad"

#define NS_ITABPARENT_IID \
  {0x4d4576eb, 0xecfe, 0x47b9, \
    { 0x93, 0xb8, 0x41, 0x21, 0x51, 0x86, 0x21, 0xad }}

class NS_NO_VTABLE nsITabParent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABPARENT_IID)

  /* void injectTouchEvent (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers); */
  NS_IMETHOD InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers) = 0;

  /* void getChildProcessOffset (out int32_t aCssX, out int32_t aCssY); */
  NS_IMETHOD GetChildProcessOffset(int32_t *aCssX, int32_t *aCssY) = 0;

  /* readonly attribute boolean useAsyncPanZoom; */
  NS_IMETHOD GetUseAsyncPanZoom(bool *aUseAsyncPanZoom) = 0;

  /* void setIsDocShellActive (in bool aIsActive); */
  NS_IMETHOD SetIsDocShellActive(bool aIsActive) = 0;

  /* readonly attribute uint64_t tabId; */
  NS_IMETHOD GetTabId(uint64_t *aTabId) = 0;

  /* readonly attribute boolean hasContentOpener; */
  NS_IMETHOD GetHasContentOpener(bool *aHasContentOpener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITabParent, NS_ITABPARENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABPARENT \
  NS_IMETHOD InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers) override; \
  NS_IMETHOD GetChildProcessOffset(int32_t *aCssX, int32_t *aCssY) override; \
  NS_IMETHOD GetUseAsyncPanZoom(bool *aUseAsyncPanZoom) override; \
  NS_IMETHOD SetIsDocShellActive(bool aIsActive) override; \
  NS_IMETHOD GetTabId(uint64_t *aTabId) override; \
  NS_IMETHOD GetHasContentOpener(bool *aHasContentOpener) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABPARENT(_to) \
  NS_IMETHOD InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers) override { return _to InjectTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers); } \
  NS_IMETHOD GetChildProcessOffset(int32_t *aCssX, int32_t *aCssY) override { return _to GetChildProcessOffset(aCssX, aCssY); } \
  NS_IMETHOD GetUseAsyncPanZoom(bool *aUseAsyncPanZoom) override { return _to GetUseAsyncPanZoom(aUseAsyncPanZoom); } \
  NS_IMETHOD SetIsDocShellActive(bool aIsActive) override { return _to SetIsDocShellActive(aIsActive); } \
  NS_IMETHOD GetTabId(uint64_t *aTabId) override { return _to GetTabId(aTabId); } \
  NS_IMETHOD GetHasContentOpener(bool *aHasContentOpener) override { return _to GetHasContentOpener(aHasContentOpener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABPARENT(_to) \
  NS_IMETHOD InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InjectTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers); } \
  NS_IMETHOD GetChildProcessOffset(int32_t *aCssX, int32_t *aCssY) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildProcessOffset(aCssX, aCssY); } \
  NS_IMETHOD GetUseAsyncPanZoom(bool *aUseAsyncPanZoom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseAsyncPanZoom(aUseAsyncPanZoom); } \
  NS_IMETHOD SetIsDocShellActive(bool aIsActive) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsDocShellActive(aIsActive); } \
  NS_IMETHOD GetTabId(uint64_t *aTabId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabId(aTabId); } \
  NS_IMETHOD GetHasContentOpener(bool *aHasContentOpener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasContentOpener(aHasContentOpener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTabParent : public nsITabParent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABPARENT

  nsTabParent();

private:
  ~nsTabParent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTabParent, nsITabParent)

nsTabParent::nsTabParent()
{
  /* member initializers and constructor code */
}

nsTabParent::~nsTabParent()
{
  /* destructor code */
}

/* void injectTouchEvent (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers); */
NS_IMETHODIMP nsTabParent::InjectTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getChildProcessOffset (out int32_t aCssX, out int32_t aCssY); */
NS_IMETHODIMP nsTabParent::GetChildProcessOffset(int32_t *aCssX, int32_t *aCssY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean useAsyncPanZoom; */
NS_IMETHODIMP nsTabParent::GetUseAsyncPanZoom(bool *aUseAsyncPanZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setIsDocShellActive (in bool aIsActive); */
NS_IMETHODIMP nsTabParent::SetIsDocShellActive(bool aIsActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint64_t tabId; */
NS_IMETHODIMP nsTabParent::GetTabId(uint64_t *aTabId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasContentOpener; */
NS_IMETHODIMP nsTabParent::GetHasContentOpener(bool *aHasContentOpener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITabParent_h__ */
