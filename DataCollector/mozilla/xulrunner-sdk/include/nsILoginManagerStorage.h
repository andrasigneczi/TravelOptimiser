/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILoginManagerStorage.idl
 */

#ifndef __gen_nsILoginManagerStorage_h__
#define __gen_nsILoginManagerStorage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsILoginInfo; /* forward declaration */

class nsIPropertyBag; /* forward declaration */


/* starting interface:    nsILoginManagerStorage */
#define NS_ILOGINMANAGERSTORAGE_IID_STR "5df81a93-25e6-4b45-a696-089479e15c7d"

#define NS_ILOGINMANAGERSTORAGE_IID \
  {0x5df81a93, 0x25e6, 0x4b45, \
    { 0xa6, 0x96, 0x08, 0x94, 0x79, 0xe1, 0x5c, 0x7d }}

class NS_NO_VTABLE nsILoginManagerStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMANAGERSTORAGE_IID)

  /* jsval initialize (); */
  NS_IMETHOD Initialize(JS::MutableHandleValue _retval) = 0;

  /* jsval terminate (); */
  NS_IMETHOD Terminate(JS::MutableHandleValue _retval) = 0;

  /* void addLogin (in nsILoginInfo aLogin); */
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) = 0;

  /* void removeLogin (in nsILoginInfo aLogin); */
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) = 0;

  /* void modifyLogin (in nsILoginInfo oldLogin, in nsISupports newLoginData); */
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) = 0;

  /* void removeAllLogins (); */
  NS_IMETHOD RemoveAllLogins(void) = 0;

  /* void getAllLogins ([optional] out unsigned long count, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) = 0;

  /* void searchLogins (out unsigned long count, in nsIPropertyBag matchData, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) = 0;

  /* void getAllDisabledHosts ([optional] out unsigned long count, [array, size_is (count), retval] out wstring hostnames); */
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, char16_t * **hostnames) = 0;

  /* boolean getLoginSavingEnabled (in AString aHost); */
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) = 0;

  /* void setLoginSavingEnabled (in AString aHost, in boolean isEnabled); */
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) = 0;

  /* void findLogins (out unsigned long count, in AString aHostname, in AString aActionURL, in AString aHttpRealm, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) = 0;

  /* unsigned long countLogins (in AString aHostname, in AString aActionURL, in AString aHttpRealm); */
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) = 0;

  /* readonly attribute boolean uiBusy; */
  NS_IMETHOD GetUiBusy(bool *aUiBusy) = 0;

  /* readonly attribute boolean isLoggedIn; */
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginManagerStorage, NS_ILOGINMANAGERSTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMANAGERSTORAGE \
  NS_IMETHOD Initialize(JS::MutableHandleValue _retval) override; \
  NS_IMETHOD Terminate(JS::MutableHandleValue _retval) override; \
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) override; \
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) override; \
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) override; \
  NS_IMETHOD RemoveAllLogins(void) override; \
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) override; \
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) override; \
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, char16_t * **hostnames) override; \
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) override; \
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) override; \
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) override; \
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) override; \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) override; \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMANAGERSTORAGE(_to) \
  NS_IMETHOD Initialize(JS::MutableHandleValue _retval) override { return _to Initialize(_retval); } \
  NS_IMETHOD Terminate(JS::MutableHandleValue _retval) override { return _to Terminate(_retval); } \
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) override { return _to AddLogin(aLogin); } \
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) override { return _to RemoveLogin(aLogin); } \
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) override { return _to ModifyLogin(oldLogin, newLoginData); } \
  NS_IMETHOD RemoveAllLogins(void) override { return _to RemoveAllLogins(); } \
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) override { return _to GetAllLogins(count, logins); } \
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) override { return _to SearchLogins(count, matchData, logins); } \
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, char16_t * **hostnames) override { return _to GetAllDisabledHosts(count, hostnames); } \
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) override { return _to GetLoginSavingEnabled(aHost, _retval); } \
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) override { return _to SetLoginSavingEnabled(aHost, isEnabled); } \
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) override { return _to FindLogins(count, aHostname, aActionURL, aHttpRealm, logins); } \
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) override { return _to CountLogins(aHostname, aActionURL, aHttpRealm, _retval); } \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) override { return _to GetUiBusy(aUiBusy); } \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) override { return _to GetIsLoggedIn(aIsLoggedIn); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMANAGERSTORAGE(_to) \
  NS_IMETHOD Initialize(JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(_retval); } \
  NS_IMETHOD Terminate(JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Terminate(_retval); } \
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddLogin(aLogin); } \
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveLogin(aLogin); } \
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ModifyLogin(oldLogin, newLoginData); } \
  NS_IMETHOD RemoveAllLogins(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllLogins(); } \
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllLogins(count, logins); } \
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchLogins(count, matchData, logins); } \
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, char16_t * **hostnames) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllDisabledHosts(count, hostnames); } \
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoginSavingEnabled(aHost, _retval); } \
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoginSavingEnabled(aHost, isEnabled); } \
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindLogins(count, aHostname, aActionURL, aHttpRealm, logins); } \
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CountLogins(aHostname, aActionURL, aHttpRealm, _retval); } \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUiBusy(aUiBusy); } \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLoggedIn(aIsLoggedIn); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginManagerStorage : public nsILoginManagerStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMANAGERSTORAGE

  nsLoginManagerStorage();

private:
  ~nsLoginManagerStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLoginManagerStorage, nsILoginManagerStorage)

nsLoginManagerStorage::nsLoginManagerStorage()
{
  /* member initializers and constructor code */
}

nsLoginManagerStorage::~nsLoginManagerStorage()
{
  /* destructor code */
}

/* jsval initialize (); */
NS_IMETHODIMP nsLoginManagerStorage::Initialize(JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval terminate (); */
NS_IMETHODIMP nsLoginManagerStorage::Terminate(JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addLogin (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManagerStorage::AddLogin(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeLogin (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManagerStorage::RemoveLogin(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void modifyLogin (in nsILoginInfo oldLogin, in nsISupports newLoginData); */
NS_IMETHODIMP nsLoginManagerStorage::ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllLogins (); */
NS_IMETHODIMP nsLoginManagerStorage::RemoveAllLogins()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllLogins ([optional] out unsigned long count, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManagerStorage::GetAllLogins(uint32_t *count, nsILoginInfo * **logins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void searchLogins (out unsigned long count, in nsIPropertyBag matchData, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManagerStorage::SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllDisabledHosts ([optional] out unsigned long count, [array, size_is (count), retval] out wstring hostnames); */
NS_IMETHODIMP nsLoginManagerStorage::GetAllDisabledHosts(uint32_t *count, char16_t * **hostnames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getLoginSavingEnabled (in AString aHost); */
NS_IMETHODIMP nsLoginManagerStorage::GetLoginSavingEnabled(const nsAString & aHost, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLoginSavingEnabled (in AString aHost, in boolean isEnabled); */
NS_IMETHODIMP nsLoginManagerStorage::SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findLogins (out unsigned long count, in AString aHostname, in AString aActionURL, in AString aHttpRealm, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManagerStorage::FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long countLogins (in AString aHostname, in AString aActionURL, in AString aHttpRealm); */
NS_IMETHODIMP nsLoginManagerStorage::CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean uiBusy; */
NS_IMETHODIMP nsLoginManagerStorage::GetUiBusy(bool *aUiBusy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isLoggedIn; */
NS_IMETHODIMP nsLoginManagerStorage::GetIsLoggedIn(bool *aIsLoggedIn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoginManagerStorage_h__ */
