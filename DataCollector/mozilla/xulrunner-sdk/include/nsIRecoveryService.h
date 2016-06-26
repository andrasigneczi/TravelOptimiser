/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRecoveryService.idl
 */

#ifndef __gen_nsIRecoveryService_h__
#define __gen_nsIRecoveryService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRecoveryService */
#define NS_IRECOVERYSERVICE_IID_STR "bc24fb33-a0c1-49ca-aa43-05f167e02fb6"

#define NS_IRECOVERYSERVICE_IID \
  {0xbc24fb33, 0xa0c1, 0x49ca, \
    { 0xaa, 0x43, 0x05, 0xf1, 0x67, 0xe0, 0x2f, 0xb6 }}

class NS_NO_VTABLE nsIRecoveryService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRECOVERYSERVICE_IID)

  enum {
    FOTA_UPDATE_UNKNOWN = 0,
    FOTA_UPDATE_FAIL = 1,
    FOTA_UPDATE_SUCCESS = 2
  };

  /* void factoryReset (in string reason); */
  NS_IMETHOD FactoryReset(const char * reason) = 0;

  /* void installFotaUpdate (in string updatePath); */
  NS_IMETHOD InstallFotaUpdate(const char * updatePath) = 0;

  /* long getFotaUpdateStatus (); */
  NS_IMETHOD GetFotaUpdateStatus(int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRecoveryService, NS_IRECOVERYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRECOVERYSERVICE \
  NS_IMETHOD FactoryReset(const char * reason) override; \
  NS_IMETHOD InstallFotaUpdate(const char * updatePath) override; \
  NS_IMETHOD GetFotaUpdateStatus(int32_t *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRECOVERYSERVICE(_to) \
  NS_IMETHOD FactoryReset(const char * reason) override { return _to FactoryReset(reason); } \
  NS_IMETHOD InstallFotaUpdate(const char * updatePath) override { return _to InstallFotaUpdate(updatePath); } \
  NS_IMETHOD GetFotaUpdateStatus(int32_t *_retval) override { return _to GetFotaUpdateStatus(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRECOVERYSERVICE(_to) \
  NS_IMETHOD FactoryReset(const char * reason) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FactoryReset(reason); } \
  NS_IMETHOD InstallFotaUpdate(const char * updatePath) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallFotaUpdate(updatePath); } \
  NS_IMETHOD GetFotaUpdateStatus(int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFotaUpdateStatus(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRecoveryService : public nsIRecoveryService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRECOVERYSERVICE

  nsRecoveryService();

private:
  ~nsRecoveryService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsRecoveryService, nsIRecoveryService)

nsRecoveryService::nsRecoveryService()
{
  /* member initializers and constructor code */
}

nsRecoveryService::~nsRecoveryService()
{
  /* destructor code */
}

/* void factoryReset (in string reason); */
NS_IMETHODIMP nsRecoveryService::FactoryReset(const char * reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void installFotaUpdate (in string updatePath); */
NS_IMETHODIMP nsRecoveryService::InstallFotaUpdate(const char * updatePath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getFotaUpdateStatus (); */
NS_IMETHODIMP nsRecoveryService::GetFotaUpdateStatus(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRecoveryService_h__ */
