/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILoginManager.idl
 */

#ifndef __gen_nsILoginManager_h__
#define __gen_nsILoginManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsILoginInfo; /* forward declaration */

class nsIAutoCompleteResult; /* forward declaration */

class nsIFormAutoCompleteObserver; /* forward declaration */

class nsIDOMHTMLInputElement; /* forward declaration */

class nsIDOMHTMLFormElement; /* forward declaration */

class nsIPropertyBag; /* forward declaration */


/* starting interface:    nsILoginManager */
#define NS_ILOGINMANAGER_IID_STR "38c7f6af-7df9-49c7-b558-2776b24e6cc1"

#define NS_ILOGINMANAGER_IID \
  {0x38c7f6af, 0x7df9, 0x49c7, \
    { 0xb5, 0x58, 0x27, 0x76, 0xb2, 0x4e, 0x6c, 0xc1 }}

class NS_NO_VTABLE nsILoginManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMANAGER_IID)

  /* readonly attribute jsval initializationPromise; */
  NS_IMETHOD GetInitializationPromise(JS::MutableHandleValue aInitializationPromise) = 0;

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

  /* void autoCompleteSearchAsync (in AString aSearchString, in nsIAutoCompleteResult aPreviousResult, in nsIDOMHTMLInputElement aElement, in nsIFormAutoCompleteObserver aListener); */
  NS_IMETHOD AutoCompleteSearchAsync(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIFormAutoCompleteObserver *aListener) = 0;

  /* void searchLogins (out unsigned long count, in nsIPropertyBag matchData, [array, size_is (count), retval] out nsILoginInfo logins); */
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) = 0;

  /* readonly attribute boolean uiBusy; */
  NS_IMETHOD GetUiBusy(bool *aUiBusy) = 0;

  /* readonly attribute boolean isLoggedIn; */
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginManager, NS_ILOGINMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMANAGER \
  NS_IMETHOD GetInitializationPromise(JS::MutableHandleValue aInitializationPromise) override; \
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) override; \
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) override; \
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) override; \
  NS_IMETHOD RemoveAllLogins(void) override; \
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) override; \
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, char16_t * **hostnames) override; \
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) override; \
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) override; \
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) override; \
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) override; \
  NS_IMETHOD AutoCompleteSearchAsync(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIFormAutoCompleteObserver *aListener) override; \
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) override; \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) override; \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMANAGER(_to) \
  NS_IMETHOD GetInitializationPromise(JS::MutableHandleValue aInitializationPromise) override { return _to GetInitializationPromise(aInitializationPromise); } \
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) override { return _to AddLogin(aLogin); } \
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) override { return _to RemoveLogin(aLogin); } \
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) override { return _to ModifyLogin(oldLogin, newLoginData); } \
  NS_IMETHOD RemoveAllLogins(void) override { return _to RemoveAllLogins(); } \
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) override { return _to GetAllLogins(count, logins); } \
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, char16_t * **hostnames) override { return _to GetAllDisabledHosts(count, hostnames); } \
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) override { return _to GetLoginSavingEnabled(aHost, _retval); } \
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) override { return _to SetLoginSavingEnabled(aHost, isEnabled); } \
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) override { return _to FindLogins(count, aHostname, aActionURL, aHttpRealm, logins); } \
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) override { return _to CountLogins(aHostname, aActionURL, aHttpRealm, _retval); } \
  NS_IMETHOD AutoCompleteSearchAsync(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIFormAutoCompleteObserver *aListener) override { return _to AutoCompleteSearchAsync(aSearchString, aPreviousResult, aElement, aListener); } \
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) override { return _to SearchLogins(count, matchData, logins); } \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) override { return _to GetUiBusy(aUiBusy); } \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) override { return _to GetIsLoggedIn(aIsLoggedIn); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMANAGER(_to) \
  NS_IMETHOD GetInitializationPromise(JS::MutableHandleValue aInitializationPromise) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInitializationPromise(aInitializationPromise); } \
  NS_IMETHOD AddLogin(nsILoginInfo *aLogin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddLogin(aLogin); } \
  NS_IMETHOD RemoveLogin(nsILoginInfo *aLogin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveLogin(aLogin); } \
  NS_IMETHOD ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ModifyLogin(oldLogin, newLoginData); } \
  NS_IMETHOD RemoveAllLogins(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllLogins(); } \
  NS_IMETHOD GetAllLogins(uint32_t *count, nsILoginInfo * **logins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllLogins(count, logins); } \
  NS_IMETHOD GetAllDisabledHosts(uint32_t *count, char16_t * **hostnames) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllDisabledHosts(count, hostnames); } \
  NS_IMETHOD GetLoginSavingEnabled(const nsAString & aHost, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoginSavingEnabled(aHost, _retval); } \
  NS_IMETHOD SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoginSavingEnabled(aHost, isEnabled); } \
  NS_IMETHOD FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindLogins(count, aHostname, aActionURL, aHttpRealm, logins); } \
  NS_IMETHOD CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CountLogins(aHostname, aActionURL, aHttpRealm, _retval); } \
  NS_IMETHOD AutoCompleteSearchAsync(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIFormAutoCompleteObserver *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoCompleteSearchAsync(aSearchString, aPreviousResult, aElement, aListener); } \
  NS_IMETHOD SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SearchLogins(count, matchData, logins); } \
  NS_IMETHOD GetUiBusy(bool *aUiBusy) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUiBusy(aUiBusy); } \
  NS_IMETHOD GetIsLoggedIn(bool *aIsLoggedIn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsLoggedIn(aIsLoggedIn); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginManager : public nsILoginManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMANAGER

  nsLoginManager();

private:
  ~nsLoginManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLoginManager, nsILoginManager)

nsLoginManager::nsLoginManager()
{
  /* member initializers and constructor code */
}

nsLoginManager::~nsLoginManager()
{
  /* destructor code */
}

/* readonly attribute jsval initializationPromise; */
NS_IMETHODIMP nsLoginManager::GetInitializationPromise(JS::MutableHandleValue aInitializationPromise)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addLogin (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManager::AddLogin(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeLogin (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManager::RemoveLogin(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void modifyLogin (in nsILoginInfo oldLogin, in nsISupports newLoginData); */
NS_IMETHODIMP nsLoginManager::ModifyLogin(nsILoginInfo *oldLogin, nsISupports *newLoginData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllLogins (); */
NS_IMETHODIMP nsLoginManager::RemoveAllLogins()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllLogins ([optional] out unsigned long count, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManager::GetAllLogins(uint32_t *count, nsILoginInfo * **logins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllDisabledHosts ([optional] out unsigned long count, [array, size_is (count), retval] out wstring hostnames); */
NS_IMETHODIMP nsLoginManager::GetAllDisabledHosts(uint32_t *count, char16_t * **hostnames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getLoginSavingEnabled (in AString aHost); */
NS_IMETHODIMP nsLoginManager::GetLoginSavingEnabled(const nsAString & aHost, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLoginSavingEnabled (in AString aHost, in boolean isEnabled); */
NS_IMETHODIMP nsLoginManager::SetLoginSavingEnabled(const nsAString & aHost, bool isEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findLogins (out unsigned long count, in AString aHostname, in AString aActionURL, in AString aHttpRealm, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManager::FindLogins(uint32_t *count, const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, nsILoginInfo * **logins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long countLogins (in AString aHostname, in AString aActionURL, in AString aHttpRealm); */
NS_IMETHODIMP nsLoginManager::CountLogins(const nsAString & aHostname, const nsAString & aActionURL, const nsAString & aHttpRealm, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void autoCompleteSearchAsync (in AString aSearchString, in nsIAutoCompleteResult aPreviousResult, in nsIDOMHTMLInputElement aElement, in nsIFormAutoCompleteObserver aListener); */
NS_IMETHODIMP nsLoginManager::AutoCompleteSearchAsync(const nsAString & aSearchString, nsIAutoCompleteResult *aPreviousResult, nsIDOMHTMLInputElement *aElement, nsIFormAutoCompleteObserver *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void searchLogins (out unsigned long count, in nsIPropertyBag matchData, [array, size_is (count), retval] out nsILoginInfo logins); */
NS_IMETHODIMP nsLoginManager::SearchLogins(uint32_t *count, nsIPropertyBag *matchData, nsILoginInfo * **logins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean uiBusy; */
NS_IMETHODIMP nsLoginManager::GetUiBusy(bool *aUiBusy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isLoggedIn; */
NS_IMETHODIMP nsLoginManager::GetIsLoggedIn(bool *aIsLoggedIn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_LOGINMANAGER_CONTRACTID "@mozilla.org/login-manager;1"

#endif /* __gen_nsILoginManager_h__ */
