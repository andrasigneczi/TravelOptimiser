/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrefService.idl
 */

#ifndef __gen_nsIPrefService_h__
#define __gen_nsIPrefService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPrefBranch_h__
#include "nsIPrefBranch.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
struct PrefTuple;
#include "nsTArrayForwardDeclare.h"
class nsIFile; /* forward declaration */


/* starting interface:    nsIPrefService */
#define NS_IPREFSERVICE_IID_STR "1f84fd56-3956-40df-b86a-1ea01402ee96"

#define NS_IPREFSERVICE_IID \
  {0x1f84fd56, 0x3956, 0x40df, \
    { 0xb8, 0x6a, 0x1e, 0xa0, 0x14, 0x02, 0xee, 0x96 }}

class NS_NO_VTABLE nsIPrefService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFSERVICE_IID)

  /* void readUserPrefs (in nsIFile aFile); */
  NS_IMETHOD ReadUserPrefs(nsIFile *aFile) = 0;

  /* void resetPrefs (); */
  NS_IMETHOD ResetPrefs(void) = 0;

  /* void resetUserPrefs (); */
  NS_IMETHOD ResetUserPrefs(void) = 0;

  /* void savePrefFile (in nsIFile aFile); */
  NS_IMETHOD SavePrefFile(nsIFile *aFile) = 0;

  /* nsIPrefBranch getBranch (in string aPrefRoot); */
  NS_IMETHOD GetBranch(const char * aPrefRoot, nsIPrefBranch * *_retval) = 0;

  /* nsIPrefBranch getDefaultBranch (in string aPrefRoot); */
  NS_IMETHOD GetDefaultBranch(const char * aPrefRoot, nsIPrefBranch * *_retval) = 0;

  /* readonly attribute boolean dirty; */
  NS_IMETHOD GetDirty(bool *aDirty) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefService, NS_IPREFSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFSERVICE \
  NS_IMETHOD ReadUserPrefs(nsIFile *aFile) override; \
  NS_IMETHOD ResetPrefs(void) override; \
  NS_IMETHOD ResetUserPrefs(void) override; \
  NS_IMETHOD SavePrefFile(nsIFile *aFile) override; \
  NS_IMETHOD GetBranch(const char * aPrefRoot, nsIPrefBranch * *_retval) override; \
  NS_IMETHOD GetDefaultBranch(const char * aPrefRoot, nsIPrefBranch * *_retval) override; \
  NS_IMETHOD GetDirty(bool *aDirty) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFSERVICE(_to) \
  NS_IMETHOD ReadUserPrefs(nsIFile *aFile) override { return _to ReadUserPrefs(aFile); } \
  NS_IMETHOD ResetPrefs(void) override { return _to ResetPrefs(); } \
  NS_IMETHOD ResetUserPrefs(void) override { return _to ResetUserPrefs(); } \
  NS_IMETHOD SavePrefFile(nsIFile *aFile) override { return _to SavePrefFile(aFile); } \
  NS_IMETHOD GetBranch(const char * aPrefRoot, nsIPrefBranch * *_retval) override { return _to GetBranch(aPrefRoot, _retval); } \
  NS_IMETHOD GetDefaultBranch(const char * aPrefRoot, nsIPrefBranch * *_retval) override { return _to GetDefaultBranch(aPrefRoot, _retval); } \
  NS_IMETHOD GetDirty(bool *aDirty) override { return _to GetDirty(aDirty); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFSERVICE(_to) \
  NS_IMETHOD ReadUserPrefs(nsIFile *aFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadUserPrefs(aFile); } \
  NS_IMETHOD ResetPrefs(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetPrefs(); } \
  NS_IMETHOD ResetUserPrefs(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetUserPrefs(); } \
  NS_IMETHOD SavePrefFile(nsIFile *aFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SavePrefFile(aFile); } \
  NS_IMETHOD GetBranch(const char * aPrefRoot, nsIPrefBranch * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBranch(aPrefRoot, _retval); } \
  NS_IMETHOD GetDefaultBranch(const char * aPrefRoot, nsIPrefBranch * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultBranch(aPrefRoot, _retval); } \
  NS_IMETHOD GetDirty(bool *aDirty) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirty(aDirty); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrefService : public nsIPrefService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREFSERVICE

  nsPrefService();

private:
  ~nsPrefService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPrefService, nsIPrefService)

nsPrefService::nsPrefService()
{
  /* member initializers and constructor code */
}

nsPrefService::~nsPrefService()
{
  /* destructor code */
}

/* void readUserPrefs (in nsIFile aFile); */
NS_IMETHODIMP nsPrefService::ReadUserPrefs(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetPrefs (); */
NS_IMETHODIMP nsPrefService::ResetPrefs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetUserPrefs (); */
NS_IMETHODIMP nsPrefService::ResetUserPrefs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void savePrefFile (in nsIFile aFile); */
NS_IMETHODIMP nsPrefService::SavePrefFile(nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrefBranch getBranch (in string aPrefRoot); */
NS_IMETHODIMP nsPrefService::GetBranch(const char * aPrefRoot, nsIPrefBranch * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrefBranch getDefaultBranch (in string aPrefRoot); */
NS_IMETHODIMP nsPrefService::GetDefaultBranch(const char * aPrefRoot, nsIPrefBranch * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean dirty; */
NS_IMETHODIMP nsPrefService::GetDirty(bool *aDirty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_PREFSERVICE_CID                             \
  { /* {1cd91b88-1dd2-11b2-92e1-ed22ed298000} */       \
    0x91ca2441,                                        \
    0x050f,                                            \
    0x4f7c,                                            \
    { 0x9d, 0xf8, 0x75, 0xb4, 0x0e, 0xa4, 0x01, 0x56 } \
  }
#define NS_PREFSERVICE_CONTRACTID "@mozilla.org/preferences-service;1"
/**
 * Notification sent before reading the default user preferences files.
 */
#define NS_PREFSERVICE_READ_TOPIC_ID "prefservice:before-read-userprefs"
/**
 * Notification sent when resetPrefs has been called, but before the actual
 * reset process occurs.
 */
#define NS_PREFSERVICE_RESET_TOPIC_ID "prefservice:before-reset"
/**
 * Notification sent when after reading app-provided default
 * preferences, but before user profile override defaults or extension
 * defaults are loaded.
 */
#define NS_PREFSERVICE_APPDEFAULTS_TOPIC_ID "prefservice:after-app-defaults"

#endif /* __gen_nsIPrefService_h__ */
