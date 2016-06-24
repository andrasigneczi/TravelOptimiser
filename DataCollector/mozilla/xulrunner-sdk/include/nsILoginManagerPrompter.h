/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILoginManagerPrompter.idl
 */

#ifndef __gen_nsILoginManagerPrompter_h__
#define __gen_nsILoginManagerPrompter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsILoginInfo; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsILoginManagerPrompter */
#define NS_ILOGINMANAGERPROMPTER_IID_STR "425f73b9-b2db-4e8a-88c5-9ac2512934ce"

#define NS_ILOGINMANAGERPROMPTER_IID \
  {0x425f73b9, 0xb2db, 0x4e8a, \
    { 0x88, 0xc5, 0x9a, 0xc2, 0x51, 0x29, 0x34, 0xce }}

class NS_NO_VTABLE nsILoginManagerPrompter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMANAGERPROMPTER_IID)

  /* void init (in nsIDOMWindow aWindow); */
  NS_IMETHOD Init(nsIDOMWindow *aWindow) = 0;

  /* void setE10sData (in nsIDOMElement aBrowser, in nsIDOMWindow aOpener); */
  NS_IMETHOD SetE10sData(nsIDOMElement *aBrowser, nsIDOMWindow *aOpener) = 0;

  /* void promptToSavePassword (in nsILoginInfo aLogin); */
  NS_IMETHOD PromptToSavePassword(nsILoginInfo *aLogin) = 0;

  /* void promptToChangePassword (in nsILoginInfo aOldLogin, in nsILoginInfo aNewLogin); */
  NS_IMETHOD PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin) = 0;

  /* void promptToChangePasswordWithUsernames ([array, size_is (count)] in nsILoginInfo logins, in uint32_t count, in nsILoginInfo aNewLogin); */
  NS_IMETHOD PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginManagerPrompter, NS_ILOGINMANAGERPROMPTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMANAGERPROMPTER \
  NS_IMETHOD Init(nsIDOMWindow *aWindow) override; \
  NS_IMETHOD SetE10sData(nsIDOMElement *aBrowser, nsIDOMWindow *aOpener) override; \
  NS_IMETHOD PromptToSavePassword(nsILoginInfo *aLogin) override; \
  NS_IMETHOD PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin) override; \
  NS_IMETHOD PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMANAGERPROMPTER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *aWindow) override { return _to Init(aWindow); } \
  NS_IMETHOD SetE10sData(nsIDOMElement *aBrowser, nsIDOMWindow *aOpener) override { return _to SetE10sData(aBrowser, aOpener); } \
  NS_IMETHOD PromptToSavePassword(nsILoginInfo *aLogin) override { return _to PromptToSavePassword(aLogin); } \
  NS_IMETHOD PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin) override { return _to PromptToChangePassword(aOldLogin, aNewLogin); } \
  NS_IMETHOD PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin) override { return _to PromptToChangePasswordWithUsernames(logins, count, aNewLogin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMANAGERPROMPTER(_to) \
  NS_IMETHOD Init(nsIDOMWindow *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aWindow); } \
  NS_IMETHOD SetE10sData(nsIDOMElement *aBrowser, nsIDOMWindow *aOpener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetE10sData(aBrowser, aOpener); } \
  NS_IMETHOD PromptToSavePassword(nsILoginInfo *aLogin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptToSavePassword(aLogin); } \
  NS_IMETHOD PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptToChangePassword(aOldLogin, aNewLogin); } \
  NS_IMETHOD PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptToChangePasswordWithUsernames(logins, count, aNewLogin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginManagerPrompter : public nsILoginManagerPrompter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMANAGERPROMPTER

  nsLoginManagerPrompter();

private:
  ~nsLoginManagerPrompter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLoginManagerPrompter, nsILoginManagerPrompter)

nsLoginManagerPrompter::nsLoginManagerPrompter()
{
  /* member initializers and constructor code */
}

nsLoginManagerPrompter::~nsLoginManagerPrompter()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsLoginManagerPrompter::Init(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setE10sData (in nsIDOMElement aBrowser, in nsIDOMWindow aOpener); */
NS_IMETHODIMP nsLoginManagerPrompter::SetE10sData(nsIDOMElement *aBrowser, nsIDOMWindow *aOpener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void promptToSavePassword (in nsILoginInfo aLogin); */
NS_IMETHODIMP nsLoginManagerPrompter::PromptToSavePassword(nsILoginInfo *aLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void promptToChangePassword (in nsILoginInfo aOldLogin, in nsILoginInfo aNewLogin); */
NS_IMETHODIMP nsLoginManagerPrompter::PromptToChangePassword(nsILoginInfo *aOldLogin, nsILoginInfo *aNewLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void promptToChangePasswordWithUsernames ([array, size_is (count)] in nsILoginInfo logins, in uint32_t count, in nsILoginInfo aNewLogin); */
NS_IMETHODIMP nsLoginManagerPrompter::PromptToChangePasswordWithUsernames(nsILoginInfo **logins, uint32_t count, nsILoginInfo *aNewLogin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_LOGINMANAGERPROMPTER_CONTRACTID "@mozilla.org/login-manager/prompter/;1"

#endif /* __gen_nsILoginManagerPrompter_h__ */
