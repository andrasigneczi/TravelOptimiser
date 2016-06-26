/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPackageKitService.idl
 */

#ifndef __gen_nsIPackageKitService_h__
#define __gen_nsIPackageKitService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIObserver; /* forward declaration */


/* starting interface:    nsIPackageKitService */
#define NS_IPACKAGEKITSERVICE_IID_STR "89bb04f6-ce2a-11e3-8f4f-60a44c717042"

#define NS_IPACKAGEKITSERVICE_IID \
  {0x89bb04f6, 0xce2a, 0x11e3, \
    { 0x8f, 0x4f, 0x60, 0xa4, 0x4c, 0x71, 0x70, 0x42 }}

class NS_NO_VTABLE nsIPackageKitService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPACKAGEKITSERVICE_IID)

  enum {
    PK_INSTALL_PACKAGE_NAMES = 0U,
    PK_INSTALL_MIME_TYPES = 1U,
    PK_INSTALL_FONTCONFIG_RESOURCES = 2U,
    PK_INSTALL_GSTREAMER_RESOURCES = 3U,
    PK_INSTALL_METHOD_COUNT = 4U
  };

  /* void installPackages (in unsigned long packageKitMethod, in nsIArray packageArray, in nsIObserver observer); */
  NS_IMETHOD InstallPackages(uint32_t packageKitMethod, nsIArray *packageArray, nsIObserver *observer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPackageKitService, NS_IPACKAGEKITSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPACKAGEKITSERVICE \
  NS_IMETHOD InstallPackages(uint32_t packageKitMethod, nsIArray *packageArray, nsIObserver *observer) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPACKAGEKITSERVICE(_to) \
  NS_IMETHOD InstallPackages(uint32_t packageKitMethod, nsIArray *packageArray, nsIObserver *observer) override { return _to InstallPackages(packageKitMethod, packageArray, observer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPACKAGEKITSERVICE(_to) \
  NS_IMETHOD InstallPackages(uint32_t packageKitMethod, nsIArray *packageArray, nsIObserver *observer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallPackages(packageKitMethod, packageArray, observer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPackageKitService : public nsIPackageKitService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPACKAGEKITSERVICE

  nsPackageKitService();

private:
  ~nsPackageKitService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPackageKitService, nsIPackageKitService)

nsPackageKitService::nsPackageKitService()
{
  /* member initializers and constructor code */
}

nsPackageKitService::~nsPackageKitService()
{
  /* destructor code */
}

/* void installPackages (in unsigned long packageKitMethod, in nsIArray packageArray, in nsIObserver observer); */
NS_IMETHODIMP nsPackageKitService::InstallPackages(uint32_t packageKitMethod, nsIArray *packageArray, nsIObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_PACKAGEKITSERVICE_CONTRACTID "@mozilla.org/packagekit-service;1"

#endif /* __gen_nsIPackageKitService_h__ */
