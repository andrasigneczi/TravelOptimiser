/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPackagedAppService.idl
 */

#ifndef __gen_nsIPackagedAppService_h__
#define __gen_nsIPackagedAppService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsILoadContextInfo; /* forward declaration */

class nsICacheEntryOpenCallback; /* forward declaration */

  #define PACKAGED_APP_TOKEN "!//"

/* starting interface:    nsIPackagedAppService */
#define NS_IPACKAGEDAPPSERVICE_IID_STR "77f9a34d-d082-43f1-9f83-e852d0173cd5"

#define NS_IPACKAGEDAPPSERVICE_IID \
  {0x77f9a34d, 0xd082, 0x43f1, \
    { 0x9f, 0x83, 0xe8, 0x52, 0xd0, 0x17, 0x3c, 0xd5 }}

class NS_NO_VTABLE nsIPackagedAppService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPACKAGEDAPPSERVICE_IID)

  /* void requestURI (in nsIURI aURI, in nsILoadContextInfo aInfo, in nsICacheEntryOpenCallback aCallback); */
  NS_IMETHOD RequestURI(nsIURI *aURI, nsILoadContextInfo *aInfo, nsICacheEntryOpenCallback *aCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPackagedAppService, NS_IPACKAGEDAPPSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPACKAGEDAPPSERVICE \
  NS_IMETHOD RequestURI(nsIURI *aURI, nsILoadContextInfo *aInfo, nsICacheEntryOpenCallback *aCallback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPACKAGEDAPPSERVICE(_to) \
  NS_IMETHOD RequestURI(nsIURI *aURI, nsILoadContextInfo *aInfo, nsICacheEntryOpenCallback *aCallback) override { return _to RequestURI(aURI, aInfo, aCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPACKAGEDAPPSERVICE(_to) \
  NS_IMETHOD RequestURI(nsIURI *aURI, nsILoadContextInfo *aInfo, nsICacheEntryOpenCallback *aCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestURI(aURI, aInfo, aCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPackagedAppService : public nsIPackagedAppService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPACKAGEDAPPSERVICE

  nsPackagedAppService();

private:
  ~nsPackagedAppService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPackagedAppService, nsIPackagedAppService)

nsPackagedAppService::nsPackagedAppService()
{
  /* member initializers and constructor code */
}

nsPackagedAppService::~nsPackagedAppService()
{
  /* destructor code */
}

/* void requestURI (in nsIURI aURI, in nsILoadContextInfo aInfo, in nsICacheEntryOpenCallback aCallback); */
NS_IMETHODIMP nsPackagedAppService::RequestURI(nsIURI *aURI, nsILoadContextInfo *aInfo, nsICacheEntryOpenCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPackagedAppService_h__ */
