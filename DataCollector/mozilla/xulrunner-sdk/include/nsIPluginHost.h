/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPluginHost.idl
 */

#ifndef __gen_nsIPluginHost_h__
#define __gen_nsIPluginHost_h__


#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPluginTag_h__
#include "nsIPluginTag.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define MOZ_PLUGIN_HOST_CONTRACTID \
  "@mozilla.org/plugin/host;1"

/* starting interface:    nsIPluginPlayPreviewInfo */
#define NS_IPLUGINPLAYPREVIEWINFO_IID_STR "57069ada-2845-46ef-b57f-233596d1c02c"

#define NS_IPLUGINPLAYPREVIEWINFO_IID \
  {0x57069ada, 0x2845, 0x46ef, \
    { 0xb5, 0x7f, 0x23, 0x35, 0x96, 0xd1, 0xc0, 0x2c }}

class NS_NO_VTABLE nsIPluginPlayPreviewInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINPLAYPREVIEWINFO_IID)

  /* readonly attribute AUTF8String mimeType; */
  NS_IMETHOD GetMimeType(nsACString & aMimeType) = 0;

  /* readonly attribute boolean ignoreCTP; */
  NS_IMETHOD GetIgnoreCTP(bool *aIgnoreCTP) = 0;

  /* readonly attribute AUTF8String redirectURL; */
  NS_IMETHOD GetRedirectURL(nsACString & aRedirectURL) = 0;

  /* readonly attribute AUTF8String whitelist; */
  NS_IMETHOD GetWhitelist(nsACString & aWhitelist) = 0;

  /* boolean checkWhitelist (in AUTF8String pageURI, in AUTF8String objectURI); */
  NS_IMETHOD CheckWhitelist(const nsACString & pageURI, const nsACString & objectURI, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginPlayPreviewInfo, NS_IPLUGINPLAYPREVIEWINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINPLAYPREVIEWINFO \
  NS_IMETHOD GetMimeType(nsACString & aMimeType) override; \
  NS_IMETHOD GetIgnoreCTP(bool *aIgnoreCTP) override; \
  NS_IMETHOD GetRedirectURL(nsACString & aRedirectURL) override; \
  NS_IMETHOD GetWhitelist(nsACString & aWhitelist) override; \
  NS_IMETHOD CheckWhitelist(const nsACString & pageURI, const nsACString & objectURI, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINPLAYPREVIEWINFO(_to) \
  NS_IMETHOD GetMimeType(nsACString & aMimeType) override { return _to GetMimeType(aMimeType); } \
  NS_IMETHOD GetIgnoreCTP(bool *aIgnoreCTP) override { return _to GetIgnoreCTP(aIgnoreCTP); } \
  NS_IMETHOD GetRedirectURL(nsACString & aRedirectURL) override { return _to GetRedirectURL(aRedirectURL); } \
  NS_IMETHOD GetWhitelist(nsACString & aWhitelist) override { return _to GetWhitelist(aWhitelist); } \
  NS_IMETHOD CheckWhitelist(const nsACString & pageURI, const nsACString & objectURI, bool *_retval) override { return _to CheckWhitelist(pageURI, objectURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINPLAYPREVIEWINFO(_to) \
  NS_IMETHOD GetMimeType(nsACString & aMimeType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_IMETHOD GetIgnoreCTP(bool *aIgnoreCTP) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIgnoreCTP(aIgnoreCTP); } \
  NS_IMETHOD GetRedirectURL(nsACString & aRedirectURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirectURL(aRedirectURL); } \
  NS_IMETHOD GetWhitelist(nsACString & aWhitelist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhitelist(aWhitelist); } \
  NS_IMETHOD CheckWhitelist(const nsACString & pageURI, const nsACString & objectURI, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckWhitelist(pageURI, objectURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginPlayPreviewInfo : public nsIPluginPlayPreviewInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINPLAYPREVIEWINFO

  nsPluginPlayPreviewInfo();

private:
  ~nsPluginPlayPreviewInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPluginPlayPreviewInfo, nsIPluginPlayPreviewInfo)

nsPluginPlayPreviewInfo::nsPluginPlayPreviewInfo()
{
  /* member initializers and constructor code */
}

nsPluginPlayPreviewInfo::~nsPluginPlayPreviewInfo()
{
  /* destructor code */
}

/* readonly attribute AUTF8String mimeType; */
NS_IMETHODIMP nsPluginPlayPreviewInfo::GetMimeType(nsACString & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ignoreCTP; */
NS_IMETHODIMP nsPluginPlayPreviewInfo::GetIgnoreCTP(bool *aIgnoreCTP)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String redirectURL; */
NS_IMETHODIMP nsPluginPlayPreviewInfo::GetRedirectURL(nsACString & aRedirectURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String whitelist; */
NS_IMETHODIMP nsPluginPlayPreviewInfo::GetWhitelist(nsACString & aWhitelist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkWhitelist (in AUTF8String pageURI, in AUTF8String objectURI); */
NS_IMETHODIMP nsPluginPlayPreviewInfo::CheckWhitelist(const nsACString & pageURI, const nsACString & objectURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPluginHost */
#define NS_IPLUGINHOST_IID_STR "d7d5b2e0-105b-4c9d-8558-b6b31f28b7df"

#define NS_IPLUGINHOST_IID \
  {0xd7d5b2e0, 0x105b, 0x4c9d, \
    { 0x85, 0x58, 0xb6, 0xb3, 0x1f, 0x28, 0xb7, 0xdf }}

class NS_NO_VTABLE nsIPluginHost : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINHOST_IID)

  /* void reloadPlugins (); */
  NS_IMETHOD ReloadPlugins(void) = 0;

  /* void getPluginTags ([optional] out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) = 0;

  enum {
    FLAG_CLEAR_ALL = 0U,
    FLAG_CLEAR_CACHE = 1U,
    EXCLUDE_NONE = 0U,
    EXCLUDE_DISABLED = 1U
  };

  /* void clearSiteData (in nsIPluginTag plugin, in AUTF8String domain, in uint64_t flags, in int64_t maxAge); */
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) = 0;

  /* boolean siteHasData (in nsIPluginTag plugin, in AUTF8String domain); */
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) = 0;

  /* void registerPlayPreviewMimeType (in AUTF8String mimeType, [optional] in boolean ignoreCTP, [optional] in AUTF8String redirectURL, [optional] in AUTF8String whitelist); */
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL, const nsACString & whitelist) = 0;

  /* void unregisterPlayPreviewMimeType (in AUTF8String mimeType); */
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) = 0;

  /* nsIPluginPlayPreviewInfo getPlayPreviewInfo (in AUTF8String mimeType); */
  NS_IMETHOD GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval) = 0;

  /* ACString getPermissionStringForType (in AUTF8String mimeType, [optional] in uint32_t excludeFlags); */
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, uint32_t excludeFlags, nsACString & _retval) = 0;

  /* nsIPluginTag getPluginTagForType (in AUTF8String mimeType, [optional] in uint32_t excludeFlags); */
  NS_IMETHOD GetPluginTagForType(const nsACString & mimeType, uint32_t excludeFlags, nsIPluginTag * *_retval) = 0;

  /* unsigned long getStateForType (in AUTF8String mimeType, [optional] in uint32_t excludeFlags); */
  NS_IMETHOD GetStateForType(const nsACString & mimeType, uint32_t excludeFlags, uint32_t *_retval) = 0;

  /* uint32_t getBlocklistStateForType (in AUTF8String aMimeType, [optional] in uint32_t excludeFlags); */
  NS_IMETHOD GetBlocklistStateForType(const nsACString & aMimeType, uint32_t excludeFlags, uint32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginHost, NS_IPLUGINHOST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINHOST \
  NS_IMETHOD ReloadPlugins(void) override; \
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) override; \
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) override; \
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) override; \
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL, const nsACString & whitelist) override; \
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) override; \
  NS_IMETHOD GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval) override; \
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, uint32_t excludeFlags, nsACString & _retval) override; \
  NS_IMETHOD GetPluginTagForType(const nsACString & mimeType, uint32_t excludeFlags, nsIPluginTag * *_retval) override; \
  NS_IMETHOD GetStateForType(const nsACString & mimeType, uint32_t excludeFlags, uint32_t *_retval) override; \
  NS_IMETHOD GetBlocklistStateForType(const nsACString & aMimeType, uint32_t excludeFlags, uint32_t *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINHOST(_to) \
  NS_IMETHOD ReloadPlugins(void) override { return _to ReloadPlugins(); } \
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) override { return _to GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) override { return _to ClearSiteData(plugin, domain, flags, maxAge); } \
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) override { return _to SiteHasData(plugin, domain, _retval); } \
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL, const nsACString & whitelist) override { return _to RegisterPlayPreviewMimeType(mimeType, ignoreCTP, redirectURL, whitelist); } \
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) override { return _to UnregisterPlayPreviewMimeType(mimeType); } \
  NS_IMETHOD GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval) override { return _to GetPlayPreviewInfo(mimeType, _retval); } \
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, uint32_t excludeFlags, nsACString & _retval) override { return _to GetPermissionStringForType(mimeType, excludeFlags, _retval); } \
  NS_IMETHOD GetPluginTagForType(const nsACString & mimeType, uint32_t excludeFlags, nsIPluginTag * *_retval) override { return _to GetPluginTagForType(mimeType, excludeFlags, _retval); } \
  NS_IMETHOD GetStateForType(const nsACString & mimeType, uint32_t excludeFlags, uint32_t *_retval) override { return _to GetStateForType(mimeType, excludeFlags, _retval); } \
  NS_IMETHOD GetBlocklistStateForType(const nsACString & aMimeType, uint32_t excludeFlags, uint32_t *_retval) override { return _to GetBlocklistStateForType(aMimeType, excludeFlags, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINHOST(_to) \
  NS_IMETHOD ReloadPlugins(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadPlugins(); } \
  NS_IMETHOD GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginTags(aPluginCount, aResults); } \
  NS_IMETHOD ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearSiteData(plugin, domain, flags, maxAge); } \
  NS_IMETHOD SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SiteHasData(plugin, domain, _retval); } \
  NS_IMETHOD RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL, const nsACString & whitelist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterPlayPreviewMimeType(mimeType, ignoreCTP, redirectURL, whitelist); } \
  NS_IMETHOD UnregisterPlayPreviewMimeType(const nsACString & mimeType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterPlayPreviewMimeType(mimeType); } \
  NS_IMETHOD GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlayPreviewInfo(mimeType, _retval); } \
  NS_IMETHOD GetPermissionStringForType(const nsACString & mimeType, uint32_t excludeFlags, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermissionStringForType(mimeType, excludeFlags, _retval); } \
  NS_IMETHOD GetPluginTagForType(const nsACString & mimeType, uint32_t excludeFlags, nsIPluginTag * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginTagForType(mimeType, excludeFlags, _retval); } \
  NS_IMETHOD GetStateForType(const nsACString & mimeType, uint32_t excludeFlags, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStateForType(mimeType, excludeFlags, _retval); } \
  NS_IMETHOD GetBlocklistStateForType(const nsACString & aMimeType, uint32_t excludeFlags, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlocklistStateForType(aMimeType, excludeFlags, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginHost : public nsIPluginHost
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINHOST

  nsPluginHost();

private:
  ~nsPluginHost();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPluginHost, nsIPluginHost)

nsPluginHost::nsPluginHost()
{
  /* member initializers and constructor code */
}

nsPluginHost::~nsPluginHost()
{
  /* destructor code */
}

/* void reloadPlugins (); */
NS_IMETHODIMP nsPluginHost::ReloadPlugins()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPluginTags ([optional] out unsigned long aPluginCount, [array, size_is (aPluginCount), retval] out nsIPluginTag aResults); */
NS_IMETHODIMP nsPluginHost::GetPluginTags(uint32_t *aPluginCount, nsIPluginTag * **aResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearSiteData (in nsIPluginTag plugin, in AUTF8String domain, in uint64_t flags, in int64_t maxAge); */
NS_IMETHODIMP nsPluginHost::ClearSiteData(nsIPluginTag *plugin, const nsACString & domain, uint64_t flags, int64_t maxAge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean siteHasData (in nsIPluginTag plugin, in AUTF8String domain); */
NS_IMETHODIMP nsPluginHost::SiteHasData(nsIPluginTag *plugin, const nsACString & domain, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerPlayPreviewMimeType (in AUTF8String mimeType, [optional] in boolean ignoreCTP, [optional] in AUTF8String redirectURL, [optional] in AUTF8String whitelist); */
NS_IMETHODIMP nsPluginHost::RegisterPlayPreviewMimeType(const nsACString & mimeType, bool ignoreCTP, const nsACString & redirectURL, const nsACString & whitelist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterPlayPreviewMimeType (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::UnregisterPlayPreviewMimeType(const nsACString & mimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPluginPlayPreviewInfo getPlayPreviewInfo (in AUTF8String mimeType); */
NS_IMETHODIMP nsPluginHost::GetPlayPreviewInfo(const nsACString & mimeType, nsIPluginPlayPreviewInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getPermissionStringForType (in AUTF8String mimeType, [optional] in uint32_t excludeFlags); */
NS_IMETHODIMP nsPluginHost::GetPermissionStringForType(const nsACString & mimeType, uint32_t excludeFlags, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPluginTag getPluginTagForType (in AUTF8String mimeType, [optional] in uint32_t excludeFlags); */
NS_IMETHODIMP nsPluginHost::GetPluginTagForType(const nsACString & mimeType, uint32_t excludeFlags, nsIPluginTag * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getStateForType (in AUTF8String mimeType, [optional] in uint32_t excludeFlags); */
NS_IMETHODIMP nsPluginHost::GetStateForType(const nsACString & mimeType, uint32_t excludeFlags, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t getBlocklistStateForType (in AUTF8String aMimeType, [optional] in uint32_t excludeFlags); */
NS_IMETHODIMP nsPluginHost::GetBlocklistStateForType(const nsACString & aMimeType, uint32_t excludeFlags, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginHost_h__ */
