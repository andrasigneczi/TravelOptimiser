/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDocShellLoadInfo.idl
 */

#ifndef __gen_nsIDocShellLoadInfo_h__
#define __gen_nsIDocShellLoadInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsISHEntry; /* forward declaration */

class nsIDocShell; /* forward declaration */

typedef int32_t  nsDocShellInfoLoadType;

typedef uint32_t  nsDocShellInfoReferrerPolicy;


/* starting interface:    nsIDocShellLoadInfo */
#define NS_IDOCSHELLLOADINFO_IID_STR "c63e9d64-490d-48bf-8013-b5d8ee4dbc25"

#define NS_IDOCSHELLLOADINFO_IID \
  {0xc63e9d64, 0x490d, 0x48bf, \
    { 0x80, 0x13, 0xb5, 0xd8, 0xee, 0x4d, 0xbc, 0x25 }}

class NS_NO_VTABLE nsIDocShellLoadInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOCSHELLLOADINFO_IID)

  /* attribute nsIURI referrer; */
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) = 0;
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) = 0;

  /* attribute nsISupports owner; */
  NS_IMETHOD GetOwner(nsISupports * *aOwner) = 0;
  NS_IMETHOD SetOwner(nsISupports *aOwner) = 0;

  /* attribute boolean inheritOwner; */
  NS_IMETHOD GetInheritOwner(bool *aInheritOwner) = 0;
  NS_IMETHOD SetInheritOwner(bool aInheritOwner) = 0;

  /* attribute boolean ownerIsExplicit; */
  NS_IMETHOD GetOwnerIsExplicit(bool *aOwnerIsExplicit) = 0;
  NS_IMETHOD SetOwnerIsExplicit(bool aOwnerIsExplicit) = 0;

  enum {
    loadNormal = 0,
    loadNormalReplace = 1,
    loadHistory = 2,
    loadReloadNormal = 3,
    loadReloadBypassCache = 4,
    loadReloadBypassProxy = 5,
    loadReloadBypassProxyAndCache = 6,
    loadLink = 7,
    loadRefresh = 8,
    loadReloadCharsetChange = 9,
    loadBypassHistory = 10,
    loadStopContent = 11,
    loadStopContentAndReplace = 12,
    loadNormalExternal = 13,
    loadNormalBypassCache = 14,
    loadNormalBypassProxy = 15,
    loadNormalBypassProxyAndCache = 16,
    loadPushState = 17,
    loadReplaceBypassCache = 18,
    loadReloadMixedContent = 19,
    loadNormalAllowMixedContent = 20
  };

  /* attribute nsDocShellInfoLoadType loadType; */
  NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) = 0;
  NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) = 0;

  /* attribute nsISHEntry SHEntry; */
  NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) = 0;
  NS_IMETHOD SetSHEntry(nsISHEntry *aSHEntry) = 0;

  /* attribute wstring target; */
  NS_IMETHOD GetTarget(char16_t * *aTarget) = 0;
  NS_IMETHOD SetTarget(const char16_t * aTarget) = 0;

  /* attribute nsIInputStream postDataStream; */
  NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) = 0;
  NS_IMETHOD SetPostDataStream(nsIInputStream *aPostDataStream) = 0;

  /* attribute nsIInputStream headersStream; */
  NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) = 0;
  NS_IMETHOD SetHeadersStream(nsIInputStream *aHeadersStream) = 0;

  /* attribute boolean sendReferrer; */
  NS_IMETHOD GetSendReferrer(bool *aSendReferrer) = 0;
  NS_IMETHOD SetSendReferrer(bool aSendReferrer) = 0;

  /* attribute nsDocShellInfoReferrerPolicy referrerPolicy; */
  NS_IMETHOD GetReferrerPolicy(nsDocShellInfoReferrerPolicy *aReferrerPolicy) = 0;
  NS_IMETHOD SetReferrerPolicy(nsDocShellInfoReferrerPolicy aReferrerPolicy) = 0;

  /* readonly attribute boolean isSrcdocLoad; */
  NS_IMETHOD GetIsSrcdocLoad(bool *aIsSrcdocLoad) = 0;

  /* attribute AString srcdocData; */
  NS_IMETHOD GetSrcdocData(nsAString & aSrcdocData) = 0;
  NS_IMETHOD SetSrcdocData(const nsAString & aSrcdocData) = 0;

  /* attribute nsIDocShell sourceDocShell; */
  NS_IMETHOD GetSourceDocShell(nsIDocShell * *aSourceDocShell) = 0;
  NS_IMETHOD SetSourceDocShell(nsIDocShell *aSourceDocShell) = 0;

  /* attribute nsIURI baseURI; */
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) = 0;
  NS_IMETHOD SetBaseURI(nsIURI *aBaseURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDocShellLoadInfo, NS_IDOCSHELLLOADINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOCSHELLLOADINFO \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) override; \
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) override; \
  NS_IMETHOD GetOwner(nsISupports * *aOwner) override; \
  NS_IMETHOD SetOwner(nsISupports *aOwner) override; \
  NS_IMETHOD GetInheritOwner(bool *aInheritOwner) override; \
  NS_IMETHOD SetInheritOwner(bool aInheritOwner) override; \
  NS_IMETHOD GetOwnerIsExplicit(bool *aOwnerIsExplicit) override; \
  NS_IMETHOD SetOwnerIsExplicit(bool aOwnerIsExplicit) override; \
  NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) override; \
  NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) override; \
  NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) override; \
  NS_IMETHOD SetSHEntry(nsISHEntry *aSHEntry) override; \
  NS_IMETHOD GetTarget(char16_t * *aTarget) override; \
  NS_IMETHOD SetTarget(const char16_t * aTarget) override; \
  NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) override; \
  NS_IMETHOD SetPostDataStream(nsIInputStream *aPostDataStream) override; \
  NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) override; \
  NS_IMETHOD SetHeadersStream(nsIInputStream *aHeadersStream) override; \
  NS_IMETHOD GetSendReferrer(bool *aSendReferrer) override; \
  NS_IMETHOD SetSendReferrer(bool aSendReferrer) override; \
  NS_IMETHOD GetReferrerPolicy(nsDocShellInfoReferrerPolicy *aReferrerPolicy) override; \
  NS_IMETHOD SetReferrerPolicy(nsDocShellInfoReferrerPolicy aReferrerPolicy) override; \
  NS_IMETHOD GetIsSrcdocLoad(bool *aIsSrcdocLoad) override; \
  NS_IMETHOD GetSrcdocData(nsAString & aSrcdocData) override; \
  NS_IMETHOD SetSrcdocData(const nsAString & aSrcdocData) override; \
  NS_IMETHOD GetSourceDocShell(nsIDocShell * *aSourceDocShell) override; \
  NS_IMETHOD SetSourceDocShell(nsIDocShell *aSourceDocShell) override; \
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) override; \
  NS_IMETHOD SetBaseURI(nsIURI *aBaseURI) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOCSHELLLOADINFO(_to) \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) override { return _to GetReferrer(aReferrer); } \
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) override { return _to SetReferrer(aReferrer); } \
  NS_IMETHOD GetOwner(nsISupports * *aOwner) override { return _to GetOwner(aOwner); } \
  NS_IMETHOD SetOwner(nsISupports *aOwner) override { return _to SetOwner(aOwner); } \
  NS_IMETHOD GetInheritOwner(bool *aInheritOwner) override { return _to GetInheritOwner(aInheritOwner); } \
  NS_IMETHOD SetInheritOwner(bool aInheritOwner) override { return _to SetInheritOwner(aInheritOwner); } \
  NS_IMETHOD GetOwnerIsExplicit(bool *aOwnerIsExplicit) override { return _to GetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_IMETHOD SetOwnerIsExplicit(bool aOwnerIsExplicit) override { return _to SetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) override { return _to GetLoadType(aLoadType); } \
  NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) override { return _to SetLoadType(aLoadType); } \
  NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) override { return _to GetSHEntry(aSHEntry); } \
  NS_IMETHOD SetSHEntry(nsISHEntry *aSHEntry) override { return _to SetSHEntry(aSHEntry); } \
  NS_IMETHOD GetTarget(char16_t * *aTarget) override { return _to GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const char16_t * aTarget) override { return _to SetTarget(aTarget); } \
  NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) override { return _to GetPostDataStream(aPostDataStream); } \
  NS_IMETHOD SetPostDataStream(nsIInputStream *aPostDataStream) override { return _to SetPostDataStream(aPostDataStream); } \
  NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) override { return _to GetHeadersStream(aHeadersStream); } \
  NS_IMETHOD SetHeadersStream(nsIInputStream *aHeadersStream) override { return _to SetHeadersStream(aHeadersStream); } \
  NS_IMETHOD GetSendReferrer(bool *aSendReferrer) override { return _to GetSendReferrer(aSendReferrer); } \
  NS_IMETHOD SetSendReferrer(bool aSendReferrer) override { return _to SetSendReferrer(aSendReferrer); } \
  NS_IMETHOD GetReferrerPolicy(nsDocShellInfoReferrerPolicy *aReferrerPolicy) override { return _to GetReferrerPolicy(aReferrerPolicy); } \
  NS_IMETHOD SetReferrerPolicy(nsDocShellInfoReferrerPolicy aReferrerPolicy) override { return _to SetReferrerPolicy(aReferrerPolicy); } \
  NS_IMETHOD GetIsSrcdocLoad(bool *aIsSrcdocLoad) override { return _to GetIsSrcdocLoad(aIsSrcdocLoad); } \
  NS_IMETHOD GetSrcdocData(nsAString & aSrcdocData) override { return _to GetSrcdocData(aSrcdocData); } \
  NS_IMETHOD SetSrcdocData(const nsAString & aSrcdocData) override { return _to SetSrcdocData(aSrcdocData); } \
  NS_IMETHOD GetSourceDocShell(nsIDocShell * *aSourceDocShell) override { return _to GetSourceDocShell(aSourceDocShell); } \
  NS_IMETHOD SetSourceDocShell(nsIDocShell *aSourceDocShell) override { return _to SetSourceDocShell(aSourceDocShell); } \
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) override { return _to GetBaseURI(aBaseURI); } \
  NS_IMETHOD SetBaseURI(nsIURI *aBaseURI) override { return _to SetBaseURI(aBaseURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOCSHELLLOADINFO(_to) \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_IMETHOD SetReferrer(nsIURI *aReferrer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReferrer(aReferrer); } \
  NS_IMETHOD GetOwner(nsISupports * *aOwner) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwner(aOwner); } \
  NS_IMETHOD SetOwner(nsISupports *aOwner) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOwner(aOwner); } \
  NS_IMETHOD GetInheritOwner(bool *aInheritOwner) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInheritOwner(aInheritOwner); } \
  NS_IMETHOD SetInheritOwner(bool aInheritOwner) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInheritOwner(aInheritOwner); } \
  NS_IMETHOD GetOwnerIsExplicit(bool *aOwnerIsExplicit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_IMETHOD SetOwnerIsExplicit(bool aOwnerIsExplicit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOwnerIsExplicit(aOwnerIsExplicit); } \
  NS_IMETHOD GetLoadType(nsDocShellInfoLoadType *aLoadType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadType(aLoadType); } \
  NS_IMETHOD SetLoadType(nsDocShellInfoLoadType aLoadType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadType(aLoadType); } \
  NS_IMETHOD GetSHEntry(nsISHEntry * *aSHEntry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSHEntry(aSHEntry); } \
  NS_IMETHOD SetSHEntry(nsISHEntry *aSHEntry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSHEntry(aSHEntry); } \
  NS_IMETHOD GetTarget(char16_t * *aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD SetTarget(const char16_t * aTarget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTarget(aTarget); } \
  NS_IMETHOD GetPostDataStream(nsIInputStream * *aPostDataStream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPostDataStream(aPostDataStream); } \
  NS_IMETHOD SetPostDataStream(nsIInputStream *aPostDataStream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPostDataStream(aPostDataStream); } \
  NS_IMETHOD GetHeadersStream(nsIInputStream * *aHeadersStream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeadersStream(aHeadersStream); } \
  NS_IMETHOD SetHeadersStream(nsIInputStream *aHeadersStream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeadersStream(aHeadersStream); } \
  NS_IMETHOD GetSendReferrer(bool *aSendReferrer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSendReferrer(aSendReferrer); } \
  NS_IMETHOD SetSendReferrer(bool aSendReferrer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSendReferrer(aSendReferrer); } \
  NS_IMETHOD GetReferrerPolicy(nsDocShellInfoReferrerPolicy *aReferrerPolicy) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrerPolicy(aReferrerPolicy); } \
  NS_IMETHOD SetReferrerPolicy(nsDocShellInfoReferrerPolicy aReferrerPolicy) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReferrerPolicy(aReferrerPolicy); } \
  NS_IMETHOD GetIsSrcdocLoad(bool *aIsSrcdocLoad) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSrcdocLoad(aIsSrcdocLoad); } \
  NS_IMETHOD GetSrcdocData(nsAString & aSrcdocData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrcdocData(aSrcdocData); } \
  NS_IMETHOD SetSrcdocData(const nsAString & aSrcdocData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrcdocData(aSrcdocData); } \
  NS_IMETHOD GetSourceDocShell(nsIDocShell * *aSourceDocShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceDocShell(aSourceDocShell); } \
  NS_IMETHOD SetSourceDocShell(nsIDocShell *aSourceDocShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSourceDocShell(aSourceDocShell); } \
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseURI(aBaseURI); } \
  NS_IMETHOD SetBaseURI(nsIURI *aBaseURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseURI(aBaseURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDocShellLoadInfo : public nsIDocShellLoadInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOCSHELLLOADINFO

  nsDocShellLoadInfo();

private:
  ~nsDocShellLoadInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDocShellLoadInfo, nsIDocShellLoadInfo)

nsDocShellLoadInfo::nsDocShellLoadInfo()
{
  /* member initializers and constructor code */
}

nsDocShellLoadInfo::~nsDocShellLoadInfo()
{
  /* destructor code */
}

/* attribute nsIURI referrer; */
NS_IMETHODIMP nsDocShellLoadInfo::GetReferrer(nsIURI * *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetReferrer(nsIURI *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports owner; */
NS_IMETHODIMP nsDocShellLoadInfo::GetOwner(nsISupports * *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetOwner(nsISupports *aOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean inheritOwner; */
NS_IMETHODIMP nsDocShellLoadInfo::GetInheritOwner(bool *aInheritOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetInheritOwner(bool aInheritOwner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean ownerIsExplicit; */
NS_IMETHODIMP nsDocShellLoadInfo::GetOwnerIsExplicit(bool *aOwnerIsExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetOwnerIsExplicit(bool aOwnerIsExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsDocShellInfoLoadType loadType; */
NS_IMETHODIMP nsDocShellLoadInfo::GetLoadType(nsDocShellInfoLoadType *aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetLoadType(nsDocShellInfoLoadType aLoadType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISHEntry SHEntry; */
NS_IMETHODIMP nsDocShellLoadInfo::GetSHEntry(nsISHEntry * *aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetSHEntry(nsISHEntry *aSHEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring target; */
NS_IMETHODIMP nsDocShellLoadInfo::GetTarget(char16_t * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetTarget(const char16_t * aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream postDataStream; */
NS_IMETHODIMP nsDocShellLoadInfo::GetPostDataStream(nsIInputStream * *aPostDataStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetPostDataStream(nsIInputStream *aPostDataStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream headersStream; */
NS_IMETHODIMP nsDocShellLoadInfo::GetHeadersStream(nsIInputStream * *aHeadersStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetHeadersStream(nsIInputStream *aHeadersStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean sendReferrer; */
NS_IMETHODIMP nsDocShellLoadInfo::GetSendReferrer(bool *aSendReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetSendReferrer(bool aSendReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsDocShellInfoReferrerPolicy referrerPolicy; */
NS_IMETHODIMP nsDocShellLoadInfo::GetReferrerPolicy(nsDocShellInfoReferrerPolicy *aReferrerPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetReferrerPolicy(nsDocShellInfoReferrerPolicy aReferrerPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSrcdocLoad; */
NS_IMETHODIMP nsDocShellLoadInfo::GetIsSrcdocLoad(bool *aIsSrcdocLoad)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString srcdocData; */
NS_IMETHODIMP nsDocShellLoadInfo::GetSrcdocData(nsAString & aSrcdocData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetSrcdocData(const nsAString & aSrcdocData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDocShell sourceDocShell; */
NS_IMETHODIMP nsDocShellLoadInfo::GetSourceDocShell(nsIDocShell * *aSourceDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetSourceDocShell(nsIDocShell *aSourceDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI baseURI; */
NS_IMETHODIMP nsDocShellLoadInfo::GetBaseURI(nsIURI * *aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDocShellLoadInfo::SetBaseURI(nsIURI *aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDocShellLoadInfo_h__ */
