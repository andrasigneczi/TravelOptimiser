/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIClassOfService.idl
 */

#ifndef __gen_nsIClassOfService_h__
#define __gen_nsIClassOfService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIClassOfService */
#define NS_ICLASSOFSERVICE_IID_STR "1ccb58ec-5e07-4cf9-a30d-ac5490d23b41"

#define NS_ICLASSOFSERVICE_IID \
  {0x1ccb58ec, 0x5e07, 0x4cf9, \
    { 0xa3, 0x0d, 0xac, 0x54, 0x90, 0xd2, 0x3b, 0x41 }}

class NS_NO_VTABLE nsIClassOfService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLASSOFSERVICE_IID)

  /* attribute unsigned long classFlags; */
  NS_IMETHOD GetClassFlags(uint32_t *aClassFlags) = 0;
  NS_IMETHOD SetClassFlags(uint32_t aClassFlags) = 0;

  /* void clearClassFlags (in unsigned long flags); */
  NS_IMETHOD ClearClassFlags(uint32_t flags) = 0;

  /* void addClassFlags (in unsigned long flags); */
  NS_IMETHOD AddClassFlags(uint32_t flags) = 0;

  enum {
    Leader = 1U,
    Follower = 2U,
    Speculative = 4U,
    Background = 8U,
    Unblocked = 16U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClassOfService, NS_ICLASSOFSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLASSOFSERVICE \
  NS_IMETHOD GetClassFlags(uint32_t *aClassFlags) override; \
  NS_IMETHOD SetClassFlags(uint32_t aClassFlags) override; \
  NS_IMETHOD ClearClassFlags(uint32_t flags) override; \
  NS_IMETHOD AddClassFlags(uint32_t flags) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLASSOFSERVICE(_to) \
  NS_IMETHOD GetClassFlags(uint32_t *aClassFlags) override { return _to GetClassFlags(aClassFlags); } \
  NS_IMETHOD SetClassFlags(uint32_t aClassFlags) override { return _to SetClassFlags(aClassFlags); } \
  NS_IMETHOD ClearClassFlags(uint32_t flags) override { return _to ClearClassFlags(flags); } \
  NS_IMETHOD AddClassFlags(uint32_t flags) override { return _to AddClassFlags(flags); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLASSOFSERVICE(_to) \
  NS_IMETHOD GetClassFlags(uint32_t *aClassFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassFlags(aClassFlags); } \
  NS_IMETHOD SetClassFlags(uint32_t aClassFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetClassFlags(aClassFlags); } \
  NS_IMETHOD ClearClassFlags(uint32_t flags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearClassFlags(flags); } \
  NS_IMETHOD AddClassFlags(uint32_t flags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddClassFlags(flags); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClassOfService : public nsIClassOfService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLASSOFSERVICE

  nsClassOfService();

private:
  ~nsClassOfService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsClassOfService, nsIClassOfService)

nsClassOfService::nsClassOfService()
{
  /* member initializers and constructor code */
}

nsClassOfService::~nsClassOfService()
{
  /* destructor code */
}

/* attribute unsigned long classFlags; */
NS_IMETHODIMP nsClassOfService::GetClassFlags(uint32_t *aClassFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsClassOfService::SetClassFlags(uint32_t aClassFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearClassFlags (in unsigned long flags); */
NS_IMETHODIMP nsClassOfService::ClearClassFlags(uint32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addClassFlags (in unsigned long flags); */
NS_IMETHODIMP nsClassOfService::AddClassFlags(uint32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClassOfService_h__ */
