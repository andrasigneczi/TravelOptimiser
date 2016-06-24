/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITabChild.idl
 */

#ifndef __gen_nsITabChild_h__
#define __gen_nsITabChild_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIContentFrameMessageManager; /* forward declaration */

class nsIWebBrowserChrome3; /* forward declaration */


/* starting interface:    nsITabChild */
#define NS_ITABCHILD_IID_STR "1fb79c27-e760-4088-b19c-1ce3673ec24e"

#define NS_ITABCHILD_IID \
  {0x1fb79c27, 0xe760, 0x4088, \
    { 0xb1, 0x9c, 0x1c, 0xe3, 0x67, 0x3e, 0xc2, 0x4e }}

class NS_NO_VTABLE nsITabChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABCHILD_IID)

  /* readonly attribute nsIContentFrameMessageManager messageManager; */
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) = 0;

  /* attribute nsIWebBrowserChrome3 webBrowserChrome; */
  NS_IMETHOD GetWebBrowserChrome(nsIWebBrowserChrome3 * *aWebBrowserChrome) = 0;
  NS_IMETHOD SetWebBrowserChrome(nsIWebBrowserChrome3 *aWebBrowserChrome) = 0;

  /* [notxpcom] void sendRequestFocus (in boolean canFocus); */
  NS_IMETHOD_(void) SendRequestFocus(bool canFocus) = 0;

  /* [noscript,notxpcom] void enableDisableCommands (in AString action, in CommandsArrayRef enabledCommands, in CommandsArrayRef disabledCommands); */
  NS_IMETHOD_(void) EnableDisableCommands(const nsAString & action, nsTArray<nsCString> & enabledCommands, nsTArray<nsCString> & disabledCommands) = 0;

  /* readonly attribute uint64_t tabId; */
  NS_IMETHOD GetTabId(uint64_t *aTabId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITabChild, NS_ITABCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABCHILD \
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) override; \
  NS_IMETHOD GetWebBrowserChrome(nsIWebBrowserChrome3 * *aWebBrowserChrome) override; \
  NS_IMETHOD SetWebBrowserChrome(nsIWebBrowserChrome3 *aWebBrowserChrome) override; \
  NS_IMETHOD_(void) SendRequestFocus(bool canFocus) override; \
  NS_IMETHOD_(void) EnableDisableCommands(const nsAString & action, nsTArray<nsCString> & enabledCommands, nsTArray<nsCString> & disabledCommands) override; \
  NS_IMETHOD GetTabId(uint64_t *aTabId) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABCHILD(_to) \
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) override { return _to GetMessageManager(aMessageManager); } \
  NS_IMETHOD GetWebBrowserChrome(nsIWebBrowserChrome3 * *aWebBrowserChrome) override { return _to GetWebBrowserChrome(aWebBrowserChrome); } \
  NS_IMETHOD SetWebBrowserChrome(nsIWebBrowserChrome3 *aWebBrowserChrome) override { return _to SetWebBrowserChrome(aWebBrowserChrome); } \
  NS_IMETHOD_(void) SendRequestFocus(bool canFocus) override { return _to SendRequestFocus(canFocus); } \
  NS_IMETHOD_(void) EnableDisableCommands(const nsAString & action, nsTArray<nsCString> & enabledCommands, nsTArray<nsCString> & disabledCommands) override { return _to EnableDisableCommands(action, enabledCommands, disabledCommands); } \
  NS_IMETHOD GetTabId(uint64_t *aTabId) override { return _to GetTabId(aTabId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABCHILD(_to) \
  NS_IMETHOD GetMessageManager(nsIContentFrameMessageManager * *aMessageManager) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageManager(aMessageManager); } \
  NS_IMETHOD GetWebBrowserChrome(nsIWebBrowserChrome3 * *aWebBrowserChrome) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWebBrowserChrome(aWebBrowserChrome); } \
  NS_IMETHOD SetWebBrowserChrome(nsIWebBrowserChrome3 *aWebBrowserChrome) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWebBrowserChrome(aWebBrowserChrome); } \
  NS_IMETHOD_(void) SendRequestFocus(bool canFocus) override; \
  NS_IMETHOD_(void) EnableDisableCommands(const nsAString & action, nsTArray<nsCString> & enabledCommands, nsTArray<nsCString> & disabledCommands) override; \
  NS_IMETHOD GetTabId(uint64_t *aTabId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabId(aTabId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTabChild : public nsITabChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABCHILD

  nsTabChild();

private:
  ~nsTabChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTabChild, nsITabChild)

nsTabChild::nsTabChild()
{
  /* member initializers and constructor code */
}

nsTabChild::~nsTabChild()
{
  /* destructor code */
}

/* readonly attribute nsIContentFrameMessageManager messageManager; */
NS_IMETHODIMP nsTabChild::GetMessageManager(nsIContentFrameMessageManager * *aMessageManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWebBrowserChrome3 webBrowserChrome; */
NS_IMETHODIMP nsTabChild::GetWebBrowserChrome(nsIWebBrowserChrome3 * *aWebBrowserChrome)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTabChild::SetWebBrowserChrome(nsIWebBrowserChrome3 *aWebBrowserChrome)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void sendRequestFocus (in boolean canFocus); */
NS_IMETHODIMP_(void) nsTabChild::SendRequestFocus(bool canFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void enableDisableCommands (in AString action, in CommandsArrayRef enabledCommands, in CommandsArrayRef disabledCommands); */
NS_IMETHODIMP_(void) nsTabChild::EnableDisableCommands(const nsAString & action, nsTArray<nsCString> & enabledCommands, nsTArray<nsCString> & disabledCommands)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint64_t tabId; */
NS_IMETHODIMP nsTabChild::GetTabId(uint64_t *aTabId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITabChild_h__ */
