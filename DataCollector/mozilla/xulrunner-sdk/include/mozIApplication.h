/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIApplication.idl
 */

#ifndef __gen_mozIApplication_h__
#define __gen_mozIApplication_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrincipal; /* forward declaration */


/* starting interface:    mozIApplication */
#define MOZIAPPLICATION_IID_STR "e76aa5e0-80b2-404f-bccc-1067828bb6ed"

#define MOZIAPPLICATION_IID \
  {0xe76aa5e0, 0x80b2, 0x404f, \
    { 0xbc, 0xcc, 0x10, 0x67, 0x82, 0x8b, 0xb6, 0xed }}

class NS_NO_VTABLE mozIApplication : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIAPPLICATION_IID)

  /* boolean hasPermission (in string permission); */
  NS_IMETHOD HasPermission(const char * permission, bool *_retval) = 0;

  /* boolean hasWidgetPage (in DOMString pageURL); */
  NS_IMETHOD HasWidgetPage(const nsAString & pageURL, bool *_retval) = 0;

  /* readonly attribute unsigned short appStatus; */
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) = 0;

  /* readonly attribute DOMString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;

  /* readonly attribute DOMString origin; */
  NS_IMETHOD GetOrigin(nsAString & aOrigin) = 0;

  /* readonly attribute DOMString manifestURL; */
  NS_IMETHOD GetManifestURL(nsAString & aManifestURL) = 0;

  /* readonly attribute unsigned long localId; */
  NS_IMETHOD GetLocalId(uint32_t *aLocalId) = 0;

  /* readonly attribute DOMString basePath; */
  NS_IMETHOD GetBasePath(nsAString & aBasePath) = 0;

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString csp; */
  NS_IMETHOD GetCsp(nsAString & aCsp) = 0;

  /* readonly attribute DOMString storeID; */
  NS_IMETHOD GetStoreID(nsAString & aStoreID) = 0;

  /* readonly attribute unsigned long storeVersion; */
  NS_IMETHOD GetStoreVersion(uint32_t *aStoreVersion) = 0;

  /* readonly attribute DOMString role; */
  NS_IMETHOD GetRole(nsAString & aRole) = 0;

  /* readonly attribute DOMString kind; */
  NS_IMETHOD GetKind(nsAString & aKind) = 0;

  /* readonly attribute nsIPrincipal principal; */
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIApplication, MOZIAPPLICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIAPPLICATION \
  NS_IMETHOD HasPermission(const char * permission, bool *_retval) override; \
  NS_IMETHOD HasWidgetPage(const nsAString & pageURL, bool *_retval) override; \
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) override; \
  NS_IMETHOD GetId(nsAString & aId) override; \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) override; \
  NS_IMETHOD GetManifestURL(nsAString & aManifestURL) override; \
  NS_IMETHOD GetLocalId(uint32_t *aLocalId) override; \
  NS_IMETHOD GetBasePath(nsAString & aBasePath) override; \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD GetCsp(nsAString & aCsp) override; \
  NS_IMETHOD GetStoreID(nsAString & aStoreID) override; \
  NS_IMETHOD GetStoreVersion(uint32_t *aStoreVersion) override; \
  NS_IMETHOD GetRole(nsAString & aRole) override; \
  NS_IMETHOD GetKind(nsAString & aKind) override; \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIAPPLICATION(_to) \
  NS_IMETHOD HasPermission(const char * permission, bool *_retval) override { return _to HasPermission(permission, _retval); } \
  NS_IMETHOD HasWidgetPage(const nsAString & pageURL, bool *_retval) override { return _to HasWidgetPage(pageURL, _retval); } \
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) override { return _to GetAppStatus(aAppStatus); } \
  NS_IMETHOD GetId(nsAString & aId) override { return _to GetId(aId); } \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) override { return _to GetOrigin(aOrigin); } \
  NS_IMETHOD GetManifestURL(nsAString & aManifestURL) override { return _to GetManifestURL(aManifestURL); } \
  NS_IMETHOD GetLocalId(uint32_t *aLocalId) override { return _to GetLocalId(aLocalId); } \
  NS_IMETHOD GetBasePath(nsAString & aBasePath) override { return _to GetBasePath(aBasePath); } \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetCsp(nsAString & aCsp) override { return _to GetCsp(aCsp); } \
  NS_IMETHOD GetStoreID(nsAString & aStoreID) override { return _to GetStoreID(aStoreID); } \
  NS_IMETHOD GetStoreVersion(uint32_t *aStoreVersion) override { return _to GetStoreVersion(aStoreVersion); } \
  NS_IMETHOD GetRole(nsAString & aRole) override { return _to GetRole(aRole); } \
  NS_IMETHOD GetKind(nsAString & aKind) override { return _to GetKind(aKind); } \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) override { return _to GetPrincipal(aPrincipal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIAPPLICATION(_to) \
  NS_IMETHOD HasPermission(const char * permission, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPermission(permission, _retval); } \
  NS_IMETHOD HasWidgetPage(const nsAString & pageURL, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasWidgetPage(pageURL, _retval); } \
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppStatus(aAppStatus); } \
  NS_IMETHOD GetId(nsAString & aId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrigin(aOrigin); } \
  NS_IMETHOD GetManifestURL(nsAString & aManifestURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestURL(aManifestURL); } \
  NS_IMETHOD GetLocalId(uint32_t *aLocalId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalId(aLocalId); } \
  NS_IMETHOD GetBasePath(nsAString & aBasePath) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBasePath(aBasePath); } \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetCsp(nsAString & aCsp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCsp(aCsp); } \
  NS_IMETHOD GetStoreID(nsAString & aStoreID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStoreID(aStoreID); } \
  NS_IMETHOD GetStoreVersion(uint32_t *aStoreVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStoreVersion(aStoreVersion); } \
  NS_IMETHOD GetRole(nsAString & aRole) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRole(aRole); } \
  NS_IMETHOD GetKind(nsAString & aKind) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKind(aKind); } \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrincipal(aPrincipal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIApplication
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIAPPLICATION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, mozIApplication)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* boolean hasPermission (in string permission); */
NS_IMETHODIMP _MYCLASS_::HasPermission(const char * permission, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasWidgetPage (in DOMString pageURL); */
NS_IMETHODIMP _MYCLASS_::HasWidgetPage(const nsAString & pageURL, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short appStatus; */
NS_IMETHODIMP _MYCLASS_::GetAppStatus(uint16_t *aAppStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString id; */
NS_IMETHODIMP _MYCLASS_::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString origin; */
NS_IMETHODIMP _MYCLASS_::GetOrigin(nsAString & aOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString manifestURL; */
NS_IMETHODIMP _MYCLASS_::GetManifestURL(nsAString & aManifestURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long localId; */
NS_IMETHODIMP _MYCLASS_::GetLocalId(uint32_t *aLocalId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString basePath; */
NS_IMETHODIMP _MYCLASS_::GetBasePath(nsAString & aBasePath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP _MYCLASS_::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString csp; */
NS_IMETHODIMP _MYCLASS_::GetCsp(nsAString & aCsp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString storeID; */
NS_IMETHODIMP _MYCLASS_::GetStoreID(nsAString & aStoreID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long storeVersion; */
NS_IMETHODIMP _MYCLASS_::GetStoreVersion(uint32_t *aStoreVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString role; */
NS_IMETHODIMP _MYCLASS_::GetRole(nsAString & aRole)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString kind; */
NS_IMETHODIMP _MYCLASS_::GetKind(nsAString & aKind)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrincipal principal; */
NS_IMETHODIMP _MYCLASS_::GetPrincipal(nsIPrincipal * *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIApplication_h__ */
