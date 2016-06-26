/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILoadContext.idl
 */

#ifndef __gen_nsILoadContext_h__
#define __gen_nsILoadContext_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */


/* starting interface:    nsILoadContext */
#define NS_ILOADCONTEXT_IID_STR "6ec837fa-af93-4350-bbb8-0985d54c74ca"

#define NS_ILOADCONTEXT_IID \
  {0x6ec837fa, 0xaf93, 0x4350, \
    { 0xbb, 0xb8, 0x09, 0x85, 0xd5, 0x4c, 0x74, 0xca }}

class nsILoadContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOADCONTEXT_IID)

  /* readonly attribute nsIDOMWindow associatedWindow; */
  NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) = 0;

  /* readonly attribute nsIDOMWindow topWindow; */
  NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) = 0;

  /* readonly attribute nsIDOMElement topFrameElement; */
  NS_IMETHOD GetTopFrameElement(nsIDOMElement * *aTopFrameElement) = 0;

  /* readonly attribute unsigned long long nestedFrameId; */
  NS_IMETHOD GetNestedFrameId(uint64_t *aNestedFrameId) = 0;

  /* boolean isAppOfType (in unsigned long appType); */
  NS_IMETHOD IsAppOfType(uint32_t appType, bool *_retval) = 0;

  /* readonly attribute boolean isContent; */
  NS_IMETHOD GetIsContent(bool *aIsContent) = 0;

  /* attribute boolean usePrivateBrowsing; */
  NS_IMETHOD GetUsePrivateBrowsing(bool *aUsePrivateBrowsing) = 0;
  NS_IMETHOD SetUsePrivateBrowsing(bool aUsePrivateBrowsing) = 0;

  /* readonly attribute boolean useRemoteTabs; */
  NS_IMETHOD GetUseRemoteTabs(bool *aUseRemoteTabs) = 0;

   /**
   * De-XPCOMed getter to make call-sites cleaner.
   */
  bool UsePrivateBrowsing() {
    bool usingPB;
    GetUsePrivateBrowsing(&usingPB);
    return usingPB;
  }
  bool UseRemoteTabs() {
    bool usingRT;
    GetUseRemoteTabs(&usingRT);
    return usingRT;
  }
  /* [noscript] void SetPrivateBrowsing (in boolean aInPrivateBrowsing); */
  NS_IMETHOD SetPrivateBrowsing(bool aInPrivateBrowsing) = 0;

  /* [noscript] void SetRemoteTabs (in boolean aUseRemoteTabs); */
  NS_IMETHOD SetRemoteTabs(bool aUseRemoteTabs) = 0;

  /* readonly attribute boolean isInBrowserElement; */
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) = 0;

  /* readonly attribute unsigned long appId; */
  NS_IMETHOD GetAppId(uint32_t *aAppId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoadContext, NS_ILOADCONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOADCONTEXT \
  NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) override; \
  NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) override; \
  NS_IMETHOD GetTopFrameElement(nsIDOMElement * *aTopFrameElement) override; \
  NS_IMETHOD GetNestedFrameId(uint64_t *aNestedFrameId) override; \
  NS_IMETHOD IsAppOfType(uint32_t appType, bool *_retval) override; \
  NS_IMETHOD GetIsContent(bool *aIsContent) override; \
  NS_IMETHOD GetUsePrivateBrowsing(bool *aUsePrivateBrowsing) override; \
  NS_IMETHOD SetUsePrivateBrowsing(bool aUsePrivateBrowsing) override; \
  NS_IMETHOD GetUseRemoteTabs(bool *aUseRemoteTabs) override; \
  NS_IMETHOD SetPrivateBrowsing(bool aInPrivateBrowsing) override; \
  NS_IMETHOD SetRemoteTabs(bool aUseRemoteTabs) override; \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) override; \
  NS_IMETHOD GetAppId(uint32_t *aAppId) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOADCONTEXT(_to) \
  NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) override { return _to GetAssociatedWindow(aAssociatedWindow); } \
  NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) override { return _to GetTopWindow(aTopWindow); } \
  NS_IMETHOD GetTopFrameElement(nsIDOMElement * *aTopFrameElement) override { return _to GetTopFrameElement(aTopFrameElement); } \
  NS_IMETHOD GetNestedFrameId(uint64_t *aNestedFrameId) override { return _to GetNestedFrameId(aNestedFrameId); } \
  NS_IMETHOD IsAppOfType(uint32_t appType, bool *_retval) override { return _to IsAppOfType(appType, _retval); } \
  NS_IMETHOD GetIsContent(bool *aIsContent) override { return _to GetIsContent(aIsContent); } \
  NS_IMETHOD GetUsePrivateBrowsing(bool *aUsePrivateBrowsing) override { return _to GetUsePrivateBrowsing(aUsePrivateBrowsing); } \
  NS_IMETHOD SetUsePrivateBrowsing(bool aUsePrivateBrowsing) override { return _to SetUsePrivateBrowsing(aUsePrivateBrowsing); } \
  NS_IMETHOD GetUseRemoteTabs(bool *aUseRemoteTabs) override { return _to GetUseRemoteTabs(aUseRemoteTabs); } \
  NS_IMETHOD SetPrivateBrowsing(bool aInPrivateBrowsing) override { return _to SetPrivateBrowsing(aInPrivateBrowsing); } \
  NS_IMETHOD SetRemoteTabs(bool aUseRemoteTabs) override { return _to SetRemoteTabs(aUseRemoteTabs); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) override { return _to GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) override { return _to GetAppId(aAppId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOADCONTEXT(_to) \
  NS_IMETHOD GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAssociatedWindow(aAssociatedWindow); } \
  NS_IMETHOD GetTopWindow(nsIDOMWindow * *aTopWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTopWindow(aTopWindow); } \
  NS_IMETHOD GetTopFrameElement(nsIDOMElement * *aTopFrameElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTopFrameElement(aTopFrameElement); } \
  NS_IMETHOD GetNestedFrameId(uint64_t *aNestedFrameId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNestedFrameId(aNestedFrameId); } \
  NS_IMETHOD IsAppOfType(uint32_t appType, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsAppOfType(appType, _retval); } \
  NS_IMETHOD GetIsContent(bool *aIsContent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsContent(aIsContent); } \
  NS_IMETHOD GetUsePrivateBrowsing(bool *aUsePrivateBrowsing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsePrivateBrowsing(aUsePrivateBrowsing); } \
  NS_IMETHOD SetUsePrivateBrowsing(bool aUsePrivateBrowsing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUsePrivateBrowsing(aUsePrivateBrowsing); } \
  NS_IMETHOD GetUseRemoteTabs(bool *aUseRemoteTabs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseRemoteTabs(aUseRemoteTabs); } \
  NS_IMETHOD SetPrivateBrowsing(bool aInPrivateBrowsing) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrivateBrowsing(aInPrivateBrowsing); } \
  NS_IMETHOD SetRemoteTabs(bool aUseRemoteTabs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRemoteTabs(aUseRemoteTabs); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppId(aAppId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoadContext : public nsILoadContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOADCONTEXT

  nsLoadContext();

private:
  ~nsLoadContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLoadContext, nsILoadContext)

nsLoadContext::nsLoadContext()
{
  /* member initializers and constructor code */
}

nsLoadContext::~nsLoadContext()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow associatedWindow; */
NS_IMETHODIMP nsLoadContext::GetAssociatedWindow(nsIDOMWindow * *aAssociatedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow topWindow; */
NS_IMETHODIMP nsLoadContext::GetTopWindow(nsIDOMWindow * *aTopWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement topFrameElement; */
NS_IMETHODIMP nsLoadContext::GetTopFrameElement(nsIDOMElement * *aTopFrameElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long nestedFrameId; */
NS_IMETHODIMP nsLoadContext::GetNestedFrameId(uint64_t *aNestedFrameId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isAppOfType (in unsigned long appType); */
NS_IMETHODIMP nsLoadContext::IsAppOfType(uint32_t appType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isContent; */
NS_IMETHODIMP nsLoadContext::GetIsContent(bool *aIsContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean usePrivateBrowsing; */
NS_IMETHODIMP nsLoadContext::GetUsePrivateBrowsing(bool *aUsePrivateBrowsing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoadContext::SetUsePrivateBrowsing(bool aUsePrivateBrowsing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean useRemoteTabs; */
NS_IMETHODIMP nsLoadContext::GetUseRemoteTabs(bool *aUseRemoteTabs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetPrivateBrowsing (in boolean aInPrivateBrowsing); */
NS_IMETHODIMP nsLoadContext::SetPrivateBrowsing(bool aInPrivateBrowsing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetRemoteTabs (in boolean aUseRemoteTabs); */
NS_IMETHODIMP nsLoadContext::SetRemoteTabs(bool aUseRemoteTabs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isInBrowserElement; */
NS_IMETHODIMP nsLoadContext::GetIsInBrowserElement(bool *aIsInBrowserElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long appId; */
NS_IMETHODIMP nsLoadContext::GetAppId(uint32_t *aAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoadContext_h__ */
