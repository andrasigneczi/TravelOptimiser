/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIGeckoMediaPluginChromeService.idl
 */

#ifndef __gen_mozIGeckoMediaPluginChromeService_h__
#define __gen_mozIGeckoMediaPluginChromeService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    mozIGeckoMediaPluginChromeService */
#define MOZIGECKOMEDIAPLUGINCHROMESERVICE_IID_STR "32d35d21-181f-4630-8caa-a431e2ebad72"

#define MOZIGECKOMEDIAPLUGINCHROMESERVICE_IID \
  {0x32d35d21, 0x181f, 0x4630, \
    { 0x8c, 0xaa, 0xa4, 0x31, 0xe2, 0xeb, 0xad, 0x72 }}

class NS_NO_VTABLE mozIGeckoMediaPluginChromeService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIGECKOMEDIAPLUGINCHROMESERVICE_IID)

  /* void addPluginDirectory (in AString directory); */
  NS_IMETHOD AddPluginDirectory(const nsAString & directory) = 0;

  /* void removePluginDirectory (in AString directory); */
  NS_IMETHOD RemovePluginDirectory(const nsAString & directory) = 0;

  /* void removeAndDeletePluginDirectory (in AString directory, [optional] in bool defer); */
  NS_IMETHOD RemoveAndDeletePluginDirectory(const nsAString & directory, bool defer) = 0;

  /* void forgetThisSite (in AString site); */
  NS_IMETHOD ForgetThisSite(const nsAString & site) = 0;

  /* bool isPersistentStorageAllowed (in ACString nodeId); */
  NS_IMETHOD IsPersistentStorageAllowed(const nsACString & nodeId, bool *_retval) = 0;

  /* nsIFile getStorageDir (); */
  NS_IMETHOD GetStorageDir(nsIFile * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIGeckoMediaPluginChromeService, MOZIGECKOMEDIAPLUGINCHROMESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIGECKOMEDIAPLUGINCHROMESERVICE \
  NS_IMETHOD AddPluginDirectory(const nsAString & directory) override; \
  NS_IMETHOD RemovePluginDirectory(const nsAString & directory) override; \
  NS_IMETHOD RemoveAndDeletePluginDirectory(const nsAString & directory, bool defer) override; \
  NS_IMETHOD ForgetThisSite(const nsAString & site) override; \
  NS_IMETHOD IsPersistentStorageAllowed(const nsACString & nodeId, bool *_retval) override; \
  NS_IMETHOD GetStorageDir(nsIFile * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIGECKOMEDIAPLUGINCHROMESERVICE(_to) \
  NS_IMETHOD AddPluginDirectory(const nsAString & directory) override { return _to AddPluginDirectory(directory); } \
  NS_IMETHOD RemovePluginDirectory(const nsAString & directory) override { return _to RemovePluginDirectory(directory); } \
  NS_IMETHOD RemoveAndDeletePluginDirectory(const nsAString & directory, bool defer) override { return _to RemoveAndDeletePluginDirectory(directory, defer); } \
  NS_IMETHOD ForgetThisSite(const nsAString & site) override { return _to ForgetThisSite(site); } \
  NS_IMETHOD IsPersistentStorageAllowed(const nsACString & nodeId, bool *_retval) override { return _to IsPersistentStorageAllowed(nodeId, _retval); } \
  NS_IMETHOD GetStorageDir(nsIFile * *_retval) override { return _to GetStorageDir(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIGECKOMEDIAPLUGINCHROMESERVICE(_to) \
  NS_IMETHOD AddPluginDirectory(const nsAString & directory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddPluginDirectory(directory); } \
  NS_IMETHOD RemovePluginDirectory(const nsAString & directory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePluginDirectory(directory); } \
  NS_IMETHOD RemoveAndDeletePluginDirectory(const nsAString & directory, bool defer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAndDeletePluginDirectory(directory, defer); } \
  NS_IMETHOD ForgetThisSite(const nsAString & site) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForgetThisSite(site); } \
  NS_IMETHOD IsPersistentStorageAllowed(const nsACString & nodeId, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPersistentStorageAllowed(nodeId, _retval); } \
  NS_IMETHOD GetStorageDir(nsIFile * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorageDir(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIGeckoMediaPluginChromeService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIGECKOMEDIAPLUGINCHROMESERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, mozIGeckoMediaPluginChromeService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void addPluginDirectory (in AString directory); */
NS_IMETHODIMP _MYCLASS_::AddPluginDirectory(const nsAString & directory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePluginDirectory (in AString directory); */
NS_IMETHODIMP _MYCLASS_::RemovePluginDirectory(const nsAString & directory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAndDeletePluginDirectory (in AString directory, [optional] in bool defer); */
NS_IMETHODIMP _MYCLASS_::RemoveAndDeletePluginDirectory(const nsAString & directory, bool defer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forgetThisSite (in AString site); */
NS_IMETHODIMP _MYCLASS_::ForgetThisSite(const nsAString & site)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isPersistentStorageAllowed (in ACString nodeId); */
NS_IMETHODIMP _MYCLASS_::IsPersistentStorageAllowed(const nsACString & nodeId, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile getStorageDir (); */
NS_IMETHODIMP _MYCLASS_::GetStorageDir(nsIFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIGeckoMediaPluginChromeService_h__ */
