/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIScriptSecurityManager.idl
 */

#ifndef __gen_nsIScriptSecurityManager_h__
#define __gen_nsIScriptSecurityManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPrincipal_h__
#include "nsIPrincipal.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIClassInfo; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIDomainPolicy; /* forward declaration */

class nsILoadContext; /* forward declaration */

#include "jspubtd.h"
namespace mozilla {
namespace dom {
class DomainPolicyClone;
}
}

/* starting interface:    nsIScriptSecurityManager */
#define NS_ISCRIPTSECURITYMANAGER_IID_STR "f4c578b8-5bac-4ba1-9582-f1140e09a3b4"

#define NS_ISCRIPTSECURITYMANAGER_IID \
  {0xf4c578b8, 0x5bac, 0x4ba1, \
    { 0x95, 0x82, 0xf1, 0x14, 0x0e, 0x09, 0xa3, 0xb4 }}

class nsIScriptSecurityManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTSECURITYMANAGER_IID)

  /* [noscript] void canCreateWrapper (in JSContextPtr aJSContext, in nsIIDRef aIID, in nsISupports aObj, in nsIClassInfo aClassInfo); */
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo) = 0;

  /* [noscript] void canCreateInstance (in JSContextPtr aJSContext, in nsCIDRef aCID); */
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) = 0;

  /* [noscript] void canGetService (in JSContextPtr aJSContext, in nsCIDRef aCID); */
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) = 0;

  /* [noscript] void checkLoadURIFromScript (in JSContextPtr cx, in nsIURI uri); */
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri) = 0;

  enum {
    STANDARD = 0U,
    LOAD_IS_AUTOMATIC_DOCUMENT_REPLACEMENT = 1U,
    ALLOW_CHROME = 2U,
    DISALLOW_INHERIT_PRINCIPAL = 4U,
    DISALLOW_SCRIPT_OR_DATA = 4U,
    DISALLOW_SCRIPT = 8U,
    DONT_REPORT_ERRORS = 16U
  };

  /* void checkLoadURIWithPrincipal (in nsIPrincipal aPrincipal, in nsIURI uri, in unsigned long flags); */
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags) = 0;

  /* void checkLoadURIStrWithPrincipal (in nsIPrincipal aPrincipal, in AUTF8String uri, in unsigned long flags); */
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags) = 0;

  /* [noscript,notxpcom] boolean scriptAllowed (in JSObjectPtr aGlobal); */
  NS_IMETHOD_(bool) ScriptAllowed(JSObject *aGlobal) = 0;

  /* nsIPrincipal getSystemPrincipal (); */
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getSimpleCodebasePrincipal (in nsIURI aURI); */
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getAppCodebasePrincipal (in nsIURI uri, in unsigned long appId, in boolean inMozBrowser); */
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getLoadContextCodebasePrincipal (in nsIURI uri, in nsILoadContext loadContext); */
  NS_IMETHOD GetLoadContextCodebasePrincipal(nsIURI *uri, nsILoadContext *loadContext, nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getDocShellCodebasePrincipal (in nsIURI uri, in nsIDocShell docShell); */
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getNoAppCodebasePrincipal (in nsIURI uri); */
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) = 0;

  /* [deprecated] nsIPrincipal getCodebasePrincipal (in nsIURI uri); */
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) = 0;

  /* [implicit_jscontext] nsIPrincipal createCodebasePrincipal (in nsIURI uri, in jsval originAttributes); */
  NS_IMETHOD CreateCodebasePrincipal(nsIURI *uri, JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval) = 0;

  /* [implicit_jscontext] nsIPrincipal createNullPrincipal (in jsval originAttributes); */
  NS_IMETHOD CreateNullPrincipal(JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval) = 0;

  /* void checkSameOriginURI (in nsIURI aSourceURI, in nsIURI aTargetURI, in boolean reportError); */
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError) = 0;

  /* nsIPrincipal getChannelResultPrincipal (in nsIChannel aChannel); */
  NS_IMETHOD GetChannelResultPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) = 0;

  /* nsIPrincipal getChannelURIPrincipal (in nsIChannel aChannel); */
  NS_IMETHOD GetChannelURIPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) = 0;

  /* boolean isSystemPrincipal (in nsIPrincipal aPrincipal); */
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval) = 0;

     bool IsSystemPrincipal(nsIPrincipal* aPrincipal) {
      bool isSystem = false;
      IsSystemPrincipal(aPrincipal, &isSystem);
      return isSystem;
    }
  enum {
    NO_APP_ID = 0U,
    UNKNOWN_APP_ID = 4294967295U,
    SAFEBROWSING_APP_ID = 4294967294U
  };

  /* AUTF8String getJarPrefix (in unsigned long appId, in boolean inMozBrowser); */
  NS_IMETHOD GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval) = 0;

  /* nsIDomainPolicy activateDomainPolicy (); */
  NS_IMETHOD ActivateDomainPolicy(nsIDomainPolicy * *_retval) = 0;

  /* readonly attribute boolean domainPolicyActive; */
  NS_IMETHOD GetDomainPolicyActive(bool *aDomainPolicyActive) = 0;

  /* [noscript] nsIDomainPolicy activateDomainPolicyInternal (); */
  NS_IMETHOD ActivateDomainPolicyInternal(nsIDomainPolicy * *_retval) = 0;

  /* [noscript,notxpcom] void cloneDomainPolicy (in DomainPolicyClonePtr aClone); */
  NS_IMETHOD_(void) CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone) = 0;

  /* bool policyAllowsScript (in nsIURI aDomain); */
  NS_IMETHOD PolicyAllowsScript(nsIURI *aDomain, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptSecurityManager, NS_ISCRIPTSECURITYMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTSECURITYMANAGER \
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo) override; \
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) override; \
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) override; \
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri) override; \
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags) override; \
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags) override; \
  NS_IMETHOD_(bool) ScriptAllowed(JSObject *aGlobal) override; \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval) override; \
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval) override; \
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval) override; \
  NS_IMETHOD GetLoadContextCodebasePrincipal(nsIURI *uri, nsILoadContext *loadContext, nsIPrincipal * *_retval) override; \
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval) override; \
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) override; \
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) override; \
  NS_IMETHOD CreateCodebasePrincipal(nsIURI *uri, JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval) override; \
  NS_IMETHOD CreateNullPrincipal(JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval) override; \
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError) override; \
  NS_IMETHOD GetChannelResultPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) override; \
  NS_IMETHOD GetChannelURIPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) override; \
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval) override; \
  NS_IMETHOD GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval) override; \
  NS_IMETHOD ActivateDomainPolicy(nsIDomainPolicy * *_retval) override; \
  NS_IMETHOD GetDomainPolicyActive(bool *aDomainPolicyActive) override; \
  NS_IMETHOD ActivateDomainPolicyInternal(nsIDomainPolicy * *_retval) override; \
  NS_IMETHOD_(void) CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone) override; \
  NS_IMETHOD PolicyAllowsScript(nsIURI *aDomain, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTSECURITYMANAGER(_to) \
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo) override { return _to CanCreateWrapper(aJSContext, aIID, aObj, aClassInfo); } \
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) override { return _to CanCreateInstance(aJSContext, aCID); } \
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) override { return _to CanGetService(aJSContext, aCID); } \
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri) override { return _to CheckLoadURIFromScript(cx, uri); } \
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags) override { return _to CheckLoadURIWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags) override { return _to CheckLoadURIStrWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD_(bool) ScriptAllowed(JSObject *aGlobal) override { return _to ScriptAllowed(aGlobal); } \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval) override { return _to GetSystemPrincipal(_retval); } \
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval) override { return _to GetSimpleCodebasePrincipal(aURI, _retval); } \
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval) override { return _to GetAppCodebasePrincipal(uri, appId, inMozBrowser, _retval); } \
  NS_IMETHOD GetLoadContextCodebasePrincipal(nsIURI *uri, nsILoadContext *loadContext, nsIPrincipal * *_retval) override { return _to GetLoadContextCodebasePrincipal(uri, loadContext, _retval); } \
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval) override { return _to GetDocShellCodebasePrincipal(uri, docShell, _retval); } \
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) override { return _to GetNoAppCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) override { return _to GetCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD CreateCodebasePrincipal(nsIURI *uri, JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval) override { return _to CreateCodebasePrincipal(uri, originAttributes, cx, _retval); } \
  NS_IMETHOD CreateNullPrincipal(JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval) override { return _to CreateNullPrincipal(originAttributes, cx, _retval); } \
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError) override { return _to CheckSameOriginURI(aSourceURI, aTargetURI, reportError); } \
  NS_IMETHOD GetChannelResultPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) override { return _to GetChannelResultPrincipal(aChannel, _retval); } \
  NS_IMETHOD GetChannelURIPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) override { return _to GetChannelURIPrincipal(aChannel, _retval); } \
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval) override { return _to IsSystemPrincipal(aPrincipal, _retval); } \
  NS_IMETHOD GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval) override { return _to GetJarPrefix(appId, inMozBrowser, _retval); } \
  NS_IMETHOD ActivateDomainPolicy(nsIDomainPolicy * *_retval) override { return _to ActivateDomainPolicy(_retval); } \
  NS_IMETHOD GetDomainPolicyActive(bool *aDomainPolicyActive) override { return _to GetDomainPolicyActive(aDomainPolicyActive); } \
  NS_IMETHOD ActivateDomainPolicyInternal(nsIDomainPolicy * *_retval) override { return _to ActivateDomainPolicyInternal(_retval); } \
  NS_IMETHOD_(void) CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone) override { return _to CloneDomainPolicy(aClone); } \
  NS_IMETHOD PolicyAllowsScript(nsIURI *aDomain, bool *_retval) override { return _to PolicyAllowsScript(aDomain, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTSECURITYMANAGER(_to) \
  NS_IMETHOD CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCreateWrapper(aJSContext, aIID, aObj, aClassInfo); } \
  NS_IMETHOD CanCreateInstance(JSContext *aJSContext, const nsCID & aCID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCreateInstance(aJSContext, aCID); } \
  NS_IMETHOD CanGetService(JSContext *aJSContext, const nsCID & aCID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanGetService(aJSContext, aCID); } \
  NS_IMETHOD CheckLoadURIFromScript(JSContext *cx, nsIURI *uri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIFromScript(cx, uri); } \
  NS_IMETHOD CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckLoadURIStrWithPrincipal(aPrincipal, uri, flags); } \
  NS_IMETHOD_(bool) ScriptAllowed(JSObject *aGlobal) override; \
  NS_IMETHOD GetSystemPrincipal(nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemPrincipal(_retval); } \
  NS_IMETHOD GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSimpleCodebasePrincipal(aURI, _retval); } \
  NS_IMETHOD GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppCodebasePrincipal(uri, appId, inMozBrowser, _retval); } \
  NS_IMETHOD GetLoadContextCodebasePrincipal(nsIURI *uri, nsILoadContext *loadContext, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadContextCodebasePrincipal(uri, loadContext, _retval); } \
  NS_IMETHOD GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShellCodebasePrincipal(uri, docShell, _retval); } \
  NS_IMETHOD GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNoAppCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCodebasePrincipal(uri, _retval); } \
  NS_IMETHOD CreateCodebasePrincipal(nsIURI *uri, JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateCodebasePrincipal(uri, originAttributes, cx, _retval); } \
  NS_IMETHOD CreateNullPrincipal(JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNullPrincipal(originAttributes, cx, _retval); } \
  NS_IMETHOD CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckSameOriginURI(aSourceURI, aTargetURI, reportError); } \
  NS_IMETHOD GetChannelResultPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelResultPrincipal(aChannel, _retval); } \
  NS_IMETHOD GetChannelURIPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelURIPrincipal(aChannel, _retval); } \
  NS_IMETHOD IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSystemPrincipal(aPrincipal, _retval); } \
  NS_IMETHOD GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJarPrefix(appId, inMozBrowser, _retval); } \
  NS_IMETHOD ActivateDomainPolicy(nsIDomainPolicy * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateDomainPolicy(_retval); } \
  NS_IMETHOD GetDomainPolicyActive(bool *aDomainPolicyActive) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainPolicyActive(aDomainPolicyActive); } \
  NS_IMETHOD ActivateDomainPolicyInternal(nsIDomainPolicy * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateDomainPolicyInternal(_retval); } \
  NS_IMETHOD_(void) CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone) override; \
  NS_IMETHOD PolicyAllowsScript(nsIURI *aDomain, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PolicyAllowsScript(aDomain, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptSecurityManager : public nsIScriptSecurityManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTSECURITYMANAGER

  nsScriptSecurityManager();

private:
  ~nsScriptSecurityManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsScriptSecurityManager, nsIScriptSecurityManager)

nsScriptSecurityManager::nsScriptSecurityManager()
{
  /* member initializers and constructor code */
}

nsScriptSecurityManager::~nsScriptSecurityManager()
{
  /* destructor code */
}

/* [noscript] void canCreateWrapper (in JSContextPtr aJSContext, in nsIIDRef aIID, in nsISupports aObj, in nsIClassInfo aClassInfo); */
NS_IMETHODIMP nsScriptSecurityManager::CanCreateWrapper(JSContext *aJSContext, const nsIID & aIID, nsISupports *aObj, nsIClassInfo *aClassInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void canCreateInstance (in JSContextPtr aJSContext, in nsCIDRef aCID); */
NS_IMETHODIMP nsScriptSecurityManager::CanCreateInstance(JSContext *aJSContext, const nsCID & aCID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void canGetService (in JSContextPtr aJSContext, in nsCIDRef aCID); */
NS_IMETHODIMP nsScriptSecurityManager::CanGetService(JSContext *aJSContext, const nsCID & aCID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void checkLoadURIFromScript (in JSContextPtr cx, in nsIURI uri); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIFromScript(JSContext *cx, nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkLoadURIWithPrincipal (in nsIPrincipal aPrincipal, in nsIURI uri, in unsigned long flags); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIWithPrincipal(nsIPrincipal *aPrincipal, nsIURI *uri, uint32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkLoadURIStrWithPrincipal (in nsIPrincipal aPrincipal, in AUTF8String uri, in unsigned long flags); */
NS_IMETHODIMP nsScriptSecurityManager::CheckLoadURIStrWithPrincipal(nsIPrincipal *aPrincipal, const nsACString & uri, uint32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] boolean scriptAllowed (in JSObjectPtr aGlobal); */
NS_IMETHODIMP_(bool) nsScriptSecurityManager::ScriptAllowed(JSObject *aGlobal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getSystemPrincipal (); */
NS_IMETHODIMP nsScriptSecurityManager::GetSystemPrincipal(nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getSimpleCodebasePrincipal (in nsIURI aURI); */
NS_IMETHODIMP nsScriptSecurityManager::GetSimpleCodebasePrincipal(nsIURI *aURI, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getAppCodebasePrincipal (in nsIURI uri, in unsigned long appId, in boolean inMozBrowser); */
NS_IMETHODIMP nsScriptSecurityManager::GetAppCodebasePrincipal(nsIURI *uri, uint32_t appId, bool inMozBrowser, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getLoadContextCodebasePrincipal (in nsIURI uri, in nsILoadContext loadContext); */
NS_IMETHODIMP nsScriptSecurityManager::GetLoadContextCodebasePrincipal(nsIURI *uri, nsILoadContext *loadContext, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getDocShellCodebasePrincipal (in nsIURI uri, in nsIDocShell docShell); */
NS_IMETHODIMP nsScriptSecurityManager::GetDocShellCodebasePrincipal(nsIURI *uri, nsIDocShell *docShell, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getNoAppCodebasePrincipal (in nsIURI uri); */
NS_IMETHODIMP nsScriptSecurityManager::GetNoAppCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated] nsIPrincipal getCodebasePrincipal (in nsIURI uri); */
NS_IMETHODIMP nsScriptSecurityManager::GetCodebasePrincipal(nsIURI *uri, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIPrincipal createCodebasePrincipal (in nsIURI uri, in jsval originAttributes); */
NS_IMETHODIMP nsScriptSecurityManager::CreateCodebasePrincipal(nsIURI *uri, JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIPrincipal createNullPrincipal (in jsval originAttributes); */
NS_IMETHODIMP nsScriptSecurityManager::CreateNullPrincipal(JS::HandleValue originAttributes, JSContext* cx, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkSameOriginURI (in nsIURI aSourceURI, in nsIURI aTargetURI, in boolean reportError); */
NS_IMETHODIMP nsScriptSecurityManager::CheckSameOriginURI(nsIURI *aSourceURI, nsIURI *aTargetURI, bool reportError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getChannelResultPrincipal (in nsIChannel aChannel); */
NS_IMETHODIMP nsScriptSecurityManager::GetChannelResultPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getChannelURIPrincipal (in nsIChannel aChannel); */
NS_IMETHODIMP nsScriptSecurityManager::GetChannelURIPrincipal(nsIChannel *aChannel, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSystemPrincipal (in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsScriptSecurityManager::IsSystemPrincipal(nsIPrincipal *aPrincipal, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String getJarPrefix (in unsigned long appId, in boolean inMozBrowser); */
NS_IMETHODIMP nsScriptSecurityManager::GetJarPrefix(uint32_t appId, bool inMozBrowser, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDomainPolicy activateDomainPolicy (); */
NS_IMETHODIMP nsScriptSecurityManager::ActivateDomainPolicy(nsIDomainPolicy * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean domainPolicyActive; */
NS_IMETHODIMP nsScriptSecurityManager::GetDomainPolicyActive(bool *aDomainPolicyActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIDomainPolicy activateDomainPolicyInternal (); */
NS_IMETHODIMP nsScriptSecurityManager::ActivateDomainPolicyInternal(nsIDomainPolicy * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void cloneDomainPolicy (in DomainPolicyClonePtr aClone); */
NS_IMETHODIMP_(void) nsScriptSecurityManager::CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool policyAllowsScript (in nsIURI aDomain); */
NS_IMETHODIMP nsScriptSecurityManager::PolicyAllowsScript(nsIURI *aDomain, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SCRIPTSECURITYMANAGER_CONTRACTID "@mozilla.org/scriptsecuritymanager;1"

#endif /* __gen_nsIScriptSecurityManager_h__ */
