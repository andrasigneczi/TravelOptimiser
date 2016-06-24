/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICrashService.idl
 */

#ifndef __gen_nsICrashService_h__
#define __gen_nsICrashService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICrashService */
#define NS_ICRASHSERVICE_IID_STR "f60d76e5-62c3-4f58-89f6-b726c2b7bc20"

#define NS_ICRASHSERVICE_IID \
  {0xf60d76e5, 0x62c3, 0x4f58, \
    { 0x89, 0xf6, 0xb7, 0x26, 0xc2, 0xb7, 0xbc, 0x20 }}

class NS_NO_VTABLE nsICrashService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRASHSERVICE_IID)

  /* void addCrash (in long processType, in long crashType, in AString id); */
  NS_IMETHOD AddCrash(int32_t processType, int32_t crashType, const nsAString & id) = 0;

  enum {
    PROCESS_TYPE_MAIN = 0,
    PROCESS_TYPE_CONTENT = 1,
    PROCESS_TYPE_PLUGIN = 2,
    PROCESS_TYPE_GMPLUGIN = 3,
    CRASH_TYPE_CRASH = 0,
    CRASH_TYPE_HANG = 1
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICrashService, NS_ICRASHSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRASHSERVICE \
  NS_IMETHOD AddCrash(int32_t processType, int32_t crashType, const nsAString & id) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRASHSERVICE(_to) \
  NS_IMETHOD AddCrash(int32_t processType, int32_t crashType, const nsAString & id) override { return _to AddCrash(processType, crashType, id); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRASHSERVICE(_to) \
  NS_IMETHOD AddCrash(int32_t processType, int32_t crashType, const nsAString & id) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCrash(processType, crashType, id); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCrashService : public nsICrashService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRASHSERVICE

  nsCrashService();

private:
  ~nsCrashService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCrashService, nsICrashService)

nsCrashService::nsCrashService()
{
  /* member initializers and constructor code */
}

nsCrashService::~nsCrashService()
{
  /* destructor code */
}

/* void addCrash (in long processType, in long crashType, in AString id); */
NS_IMETHODIMP nsCrashService::AddCrash(int32_t processType, int32_t crashType, const nsAString & id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICrashService_h__ */
