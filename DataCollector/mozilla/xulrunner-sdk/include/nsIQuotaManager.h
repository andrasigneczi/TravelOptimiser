/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIQuotaManager.idl
 */

#ifndef __gen_nsIQuotaManager_h__
#define __gen_nsIQuotaManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIQuotaRequest; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIUsageCallback; /* forward declaration */


/* starting interface:    nsIQuotaManager */
#define NS_IQUOTAMANAGER_IID_STR "2968fcd5-1872-4ddc-8c16-62b27e357f31"

#define NS_IQUOTAMANAGER_IID \
  {0x2968fcd5, 0x1872, 0x4ddc, \
    { 0x8c, 0x16, 0x62, 0xb2, 0x7e, 0x35, 0x7f, 0x31 }}

class NS_NO_VTABLE nsIQuotaManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IQUOTAMANAGER_IID)

  /* [optional_argc] nsIQuotaRequest getUsageForURI (in nsIURI aURI, in nsIUsageCallback aCallback, [optional] in unsigned long aAppId, [optional] in boolean aInMozBrowserOnly); */
  NS_IMETHOD GetUsageForURI(nsIURI *aURI, nsIUsageCallback *aCallback, uint32_t aAppId, bool aInMozBrowserOnly, uint8_t _argc, nsIQuotaRequest * *_retval) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  /* [optional_argc] void clearStoragesForURI (in nsIURI aURI, [optional] in unsigned long aAppId, [optional] in boolean aInMozBrowserOnly, [optional] in ACString aPersistenceType); */
  NS_IMETHOD ClearStoragesForURI(nsIURI *aURI, uint32_t aAppId, bool aInMozBrowserOnly, const nsACString & aPersistenceType, uint8_t _argc) = 0;

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIQuotaManager, NS_IQUOTAMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIQUOTAMANAGER \
  NS_IMETHOD GetUsageForURI(nsIURI *aURI, nsIUsageCallback *aCallback, uint32_t aAppId, bool aInMozBrowserOnly, uint8_t _argc, nsIQuotaRequest * *_retval) override; \
  NS_IMETHOD Clear(void) override; \
  NS_IMETHOD ClearStoragesForURI(nsIURI *aURI, uint32_t aAppId, bool aInMozBrowserOnly, const nsACString & aPersistenceType, uint8_t _argc) override; \
  NS_IMETHOD Reset(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIQUOTAMANAGER(_to) \
  NS_IMETHOD GetUsageForURI(nsIURI *aURI, nsIUsageCallback *aCallback, uint32_t aAppId, bool aInMozBrowserOnly, uint8_t _argc, nsIQuotaRequest * *_retval) override { return _to GetUsageForURI(aURI, aCallback, aAppId, aInMozBrowserOnly, _argc, _retval); } \
  NS_IMETHOD Clear(void) override { return _to Clear(); } \
  NS_IMETHOD ClearStoragesForURI(nsIURI *aURI, uint32_t aAppId, bool aInMozBrowserOnly, const nsACString & aPersistenceType, uint8_t _argc) override { return _to ClearStoragesForURI(aURI, aAppId, aInMozBrowserOnly, aPersistenceType, _argc); } \
  NS_IMETHOD Reset(void) override { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIQUOTAMANAGER(_to) \
  NS_IMETHOD GetUsageForURI(nsIURI *aURI, nsIUsageCallback *aCallback, uint32_t aAppId, bool aInMozBrowserOnly, uint8_t _argc, nsIQuotaRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsageForURI(aURI, aCallback, aAppId, aInMozBrowserOnly, _argc, _retval); } \
  NS_IMETHOD Clear(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD ClearStoragesForURI(nsIURI *aURI, uint32_t aAppId, bool aInMozBrowserOnly, const nsACString & aPersistenceType, uint8_t _argc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearStoragesForURI(aURI, aAppId, aInMozBrowserOnly, aPersistenceType, _argc); } \
  NS_IMETHOD Reset(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsQuotaManager : public nsIQuotaManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIQUOTAMANAGER

  nsQuotaManager();

private:
  ~nsQuotaManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsQuotaManager, nsIQuotaManager)

nsQuotaManager::nsQuotaManager()
{
  /* member initializers and constructor code */
}

nsQuotaManager::~nsQuotaManager()
{
  /* destructor code */
}

/* [optional_argc] nsIQuotaRequest getUsageForURI (in nsIURI aURI, in nsIUsageCallback aCallback, [optional] in unsigned long aAppId, [optional] in boolean aInMozBrowserOnly); */
NS_IMETHODIMP nsQuotaManager::GetUsageForURI(nsIURI *aURI, nsIUsageCallback *aCallback, uint32_t aAppId, bool aInMozBrowserOnly, uint8_t _argc, nsIQuotaRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsQuotaManager::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void clearStoragesForURI (in nsIURI aURI, [optional] in unsigned long aAppId, [optional] in boolean aInMozBrowserOnly, [optional] in ACString aPersistenceType); */
NS_IMETHODIMP nsQuotaManager::ClearStoragesForURI(nsIURI *aURI, uint32_t aAppId, bool aInMozBrowserOnly, const nsACString & aPersistenceType, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsQuotaManager::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIQuotaManager_h__ */
