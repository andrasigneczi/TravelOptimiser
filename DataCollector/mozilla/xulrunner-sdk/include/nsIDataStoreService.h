/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDataStoreService.idl
 */

#ifndef __gen_nsIDataStoreService_h__
#define __gen_nsIDataStoreService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIDataStoreService */
#define NS_IDATASTORESERVICE_IID_STR "79944b1c-187d-11e4-abb6-74d02b97e723"

#define NS_IDATASTORESERVICE_IID \
  {0x79944b1c, 0x187d, 0x11e4, \
    { 0xab, 0xb6, 0x74, 0xd0, 0x2b, 0x97, 0xe7, 0x23 }}

class NS_NO_VTABLE nsIDataStoreService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDATASTORESERVICE_IID)

  /* void installDataStore (in unsigned long appId, in DOMString name, in DOMString originURL, in DOMString manifestURL, in boolean readOnly); */
  NS_IMETHOD InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) = 0;

  /* void installAccessDataStore (in unsigned long appId, in DOMString name, in DOMString originURL, in DOMString manifestURL, in boolean readOnly); */
  NS_IMETHOD InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) = 0;

  /* nsISupports getDataStores (in nsIDOMWindow window, in DOMString name, in DOMString owner); */
  NS_IMETHOD GetDataStores(nsIDOMWindow *window, const nsAString & name, const nsAString & owner, nsISupports * *_retval) = 0;

  /* nsIArray getAppManifestURLsForDataStore (in DOMString name); */
  NS_IMETHOD GetAppManifestURLsForDataStore(const nsAString & name, nsIArray * *_retval) = 0;

  /* boolean checkPermission (in nsIPrincipal principal); */
  NS_IMETHOD CheckPermission(nsIPrincipal *principal, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDataStoreService, NS_IDATASTORESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDATASTORESERVICE \
  NS_IMETHOD InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) override; \
  NS_IMETHOD InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) override; \
  NS_IMETHOD GetDataStores(nsIDOMWindow *window, const nsAString & name, const nsAString & owner, nsISupports * *_retval) override; \
  NS_IMETHOD GetAppManifestURLsForDataStore(const nsAString & name, nsIArray * *_retval) override; \
  NS_IMETHOD CheckPermission(nsIPrincipal *principal, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDATASTORESERVICE(_to) \
  NS_IMETHOD InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) override { return _to InstallDataStore(appId, name, originURL, manifestURL, readOnly); } \
  NS_IMETHOD InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) override { return _to InstallAccessDataStore(appId, name, originURL, manifestURL, readOnly); } \
  NS_IMETHOD GetDataStores(nsIDOMWindow *window, const nsAString & name, const nsAString & owner, nsISupports * *_retval) override { return _to GetDataStores(window, name, owner, _retval); } \
  NS_IMETHOD GetAppManifestURLsForDataStore(const nsAString & name, nsIArray * *_retval) override { return _to GetAppManifestURLsForDataStore(name, _retval); } \
  NS_IMETHOD CheckPermission(nsIPrincipal *principal, bool *_retval) override { return _to CheckPermission(principal, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDATASTORESERVICE(_to) \
  NS_IMETHOD InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallDataStore(appId, name, originURL, manifestURL, readOnly); } \
  NS_IMETHOD InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallAccessDataStore(appId, name, originURL, manifestURL, readOnly); } \
  NS_IMETHOD GetDataStores(nsIDOMWindow *window, const nsAString & name, const nsAString & owner, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataStores(window, name, owner, _retval); } \
  NS_IMETHOD GetAppManifestURLsForDataStore(const nsAString & name, nsIArray * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppManifestURLsForDataStore(name, _retval); } \
  NS_IMETHOD CheckPermission(nsIPrincipal *principal, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckPermission(principal, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDataStoreService : public nsIDataStoreService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDATASTORESERVICE

  nsDataStoreService();

private:
  ~nsDataStoreService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDataStoreService, nsIDataStoreService)

nsDataStoreService::nsDataStoreService()
{
  /* member initializers and constructor code */
}

nsDataStoreService::~nsDataStoreService()
{
  /* destructor code */
}

/* void installDataStore (in unsigned long appId, in DOMString name, in DOMString originURL, in DOMString manifestURL, in boolean readOnly); */
NS_IMETHODIMP nsDataStoreService::InstallDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void installAccessDataStore (in unsigned long appId, in DOMString name, in DOMString originURL, in DOMString manifestURL, in boolean readOnly); */
NS_IMETHODIMP nsDataStoreService::InstallAccessDataStore(uint32_t appId, const nsAString & name, const nsAString & originURL, const nsAString & manifestURL, bool readOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getDataStores (in nsIDOMWindow window, in DOMString name, in DOMString owner); */
NS_IMETHODIMP nsDataStoreService::GetDataStores(nsIDOMWindow *window, const nsAString & name, const nsAString & owner, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getAppManifestURLsForDataStore (in DOMString name); */
NS_IMETHODIMP nsDataStoreService::GetAppManifestURLsForDataStore(const nsAString & name, nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkPermission (in nsIPrincipal principal); */
NS_IMETHODIMP nsDataStoreService::CheckPermission(nsIPrincipal *principal, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDataStoreService_h__ */
