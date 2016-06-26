/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILoadInfo.idl
 */

#ifndef __gen_nsILoadInfo_h__
#define __gen_nsILoadInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIContentPolicy_h__
#include "nsIContentPolicy.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsINode; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIURI; /* forward declaration */

typedef uint32_t  nsSecurityFlags;


/* starting interface:    nsILoadInfo */
#define NS_ILOADINFO_IID_STR "f6bce897-1a4a-4664-b96b-abacd6543e95"

#define NS_ILOADINFO_IID \
  {0xf6bce897, 0x1a4a, 0x4664, \
    { 0xb9, 0x6b, 0xab, 0xac, 0xd6, 0x54, 0x3e, 0x95 }}

class nsILoadInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOADINFO_IID)

  enum {
    SEC_NORMAL = 0U,
    SEC_FORCE_INHERIT_PRINCIPAL = 1U,
    SEC_SANDBOXED = 2U
  };

  /* readonly attribute nsIPrincipal loadingPrincipal; */
  NS_IMETHOD GetLoadingPrincipal(nsIPrincipal * *aLoadingPrincipal) = 0;

  /* [binaryname(LoadingPrincipal),noscript,nostdcall,notxpcom] nsIPrincipal binaryLoadingPrincipal (); */
  virtual nsIPrincipal * LoadingPrincipal(void) = 0;

  /* readonly attribute nsIPrincipal triggeringPrincipal; */
  NS_IMETHOD GetTriggeringPrincipal(nsIPrincipal * *aTriggeringPrincipal) = 0;

  /* [binaryname(TriggeringPrincipal),noscript,nostdcall,notxpcom] nsIPrincipal binaryTriggeringPrincipal (); */
  virtual nsIPrincipal * TriggeringPrincipal(void) = 0;

  /* readonly attribute nsIDOMDocument loadingDocument; */
  NS_IMETHOD GetLoadingDocument(nsIDOMDocument * *aLoadingDocument) = 0;

  /* [binaryname(LoadingNode),noscript,nostdcall,notxpcom] nsINode binaryLoadingNode (); */
  virtual nsINode * LoadingNode(void) = 0;

  /* readonly attribute nsSecurityFlags securityFlags; */
  NS_IMETHOD GetSecurityFlags(nsSecurityFlags *aSecurityFlags) = 0;

   inline nsSecurityFlags GetSecurityFlags()
  {
    nsSecurityFlags result;
    mozilla::DebugOnly<nsresult> rv = GetSecurityFlags(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  /* [infallible] readonly attribute boolean forceInheritPrincipal; */
  NS_IMETHOD GetForceInheritPrincipal(bool *aForceInheritPrincipal) = 0;
  inline bool GetForceInheritPrincipal()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetForceInheritPrincipal(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean loadingSandboxed; */
  NS_IMETHOD GetLoadingSandboxed(bool *aLoadingSandboxed) = 0;
  inline bool GetLoadingSandboxed()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetLoadingSandboxed(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* readonly attribute nsContentPolicyType contentPolicyType; */
  NS_IMETHOD GetContentPolicyType(nsContentPolicyType *aContentPolicyType) = 0;

   inline nsContentPolicyType GetContentPolicyType()
  {
    nsContentPolicyType result;
    mozilla::DebugOnly<nsresult> rv = GetContentPolicyType(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  /* [noscript,notxpcom] nsContentPolicyType internalContentPolicyType (); */
  NS_IMETHOD_(nsContentPolicyType) InternalContentPolicyType(void) = 0;

  /* readonly attribute nsIURI baseURI; */
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) = 0;

  /* [binaryname(BaseURI),noscript,nostdcall,notxpcom] nsIURI binaryBaseURI (); */
  virtual nsIURI * BaseURI(void) = 0;

  /* readonly attribute unsigned long long innerWindowID; */
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) = 0;

  /* readonly attribute unsigned long long outerWindowID; */
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) = 0;

  /* readonly attribute unsigned long long parentOuterWindowID; */
  NS_IMETHOD GetParentOuterWindowID(uint64_t *aParentOuterWindowID) = 0;

   inline uint64_t GetInnerWindowID()
  {
    uint64_t result;
    mozilla::DebugOnly<nsresult> rv = GetInnerWindowID(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  inline uint64_t GetOuterWindowID()
  {
    uint64_t result;
    mozilla::DebugOnly<nsresult> rv = GetOuterWindowID(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  inline uint64_t GetParentOuterWindowID()
  {
    uint64_t result;
    mozilla::DebugOnly<nsresult> rv = GetParentOuterWindowID(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }
  };

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoadInfo, NS_ILOADINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOADINFO \
  NS_IMETHOD GetLoadingPrincipal(nsIPrincipal * *aLoadingPrincipal) override; \
  virtual nsIPrincipal * LoadingPrincipal(void) override; \
  NS_IMETHOD GetTriggeringPrincipal(nsIPrincipal * *aTriggeringPrincipal) override; \
  virtual nsIPrincipal * TriggeringPrincipal(void) override; \
  NS_IMETHOD GetLoadingDocument(nsIDOMDocument * *aLoadingDocument) override; \
  virtual nsINode * LoadingNode(void) override; \
  NS_IMETHOD GetSecurityFlags(nsSecurityFlags *aSecurityFlags) override; \
  using nsILoadInfo::GetForceInheritPrincipal; \
  NS_IMETHOD GetForceInheritPrincipal(bool *aForceInheritPrincipal) override; \
  using nsILoadInfo::GetLoadingSandboxed; \
  NS_IMETHOD GetLoadingSandboxed(bool *aLoadingSandboxed) override; \
  NS_IMETHOD GetContentPolicyType(nsContentPolicyType *aContentPolicyType) override; \
  NS_IMETHOD_(nsContentPolicyType) InternalContentPolicyType(void) override; \
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) override; \
  virtual nsIURI * BaseURI(void) override; \
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) override; \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) override; \
  NS_IMETHOD GetParentOuterWindowID(uint64_t *aParentOuterWindowID) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOADINFO(_to) \
  NS_IMETHOD GetLoadingPrincipal(nsIPrincipal * *aLoadingPrincipal) override { return _to GetLoadingPrincipal(aLoadingPrincipal); } \
  virtual nsIPrincipal * LoadingPrincipal(void) override { return _to LoadingPrincipal(); } \
  NS_IMETHOD GetTriggeringPrincipal(nsIPrincipal * *aTriggeringPrincipal) override { return _to GetTriggeringPrincipal(aTriggeringPrincipal); } \
  virtual nsIPrincipal * TriggeringPrincipal(void) override { return _to TriggeringPrincipal(); } \
  NS_IMETHOD GetLoadingDocument(nsIDOMDocument * *aLoadingDocument) override { return _to GetLoadingDocument(aLoadingDocument); } \
  virtual nsINode * LoadingNode(void) override { return _to LoadingNode(); } \
  NS_IMETHOD GetSecurityFlags(nsSecurityFlags *aSecurityFlags) override { return _to GetSecurityFlags(aSecurityFlags); } \
  using nsILoadInfo::GetForceInheritPrincipal; \
  NS_IMETHOD GetForceInheritPrincipal(bool *aForceInheritPrincipal) override { return _to GetForceInheritPrincipal(aForceInheritPrincipal); } \
  using nsILoadInfo::GetLoadingSandboxed; \
  NS_IMETHOD GetLoadingSandboxed(bool *aLoadingSandboxed) override { return _to GetLoadingSandboxed(aLoadingSandboxed); } \
  NS_IMETHOD GetContentPolicyType(nsContentPolicyType *aContentPolicyType) override { return _to GetContentPolicyType(aContentPolicyType); } \
  NS_IMETHOD_(nsContentPolicyType) InternalContentPolicyType(void) override { return _to InternalContentPolicyType(); } \
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) override { return _to GetBaseURI(aBaseURI); } \
  virtual nsIURI * BaseURI(void) override { return _to BaseURI(); } \
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) override { return _to GetInnerWindowID(aInnerWindowID); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) override { return _to GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetParentOuterWindowID(uint64_t *aParentOuterWindowID) override { return _to GetParentOuterWindowID(aParentOuterWindowID); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOADINFO(_to) \
  NS_IMETHOD GetLoadingPrincipal(nsIPrincipal * *aLoadingPrincipal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadingPrincipal(aLoadingPrincipal); } \
  virtual nsIPrincipal * LoadingPrincipal(void) override; \
  NS_IMETHOD GetTriggeringPrincipal(nsIPrincipal * *aTriggeringPrincipal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTriggeringPrincipal(aTriggeringPrincipal); } \
  virtual nsIPrincipal * TriggeringPrincipal(void) override; \
  NS_IMETHOD GetLoadingDocument(nsIDOMDocument * *aLoadingDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadingDocument(aLoadingDocument); } \
  virtual nsINode * LoadingNode(void) override; \
  NS_IMETHOD GetSecurityFlags(nsSecurityFlags *aSecurityFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityFlags(aSecurityFlags); } \
  NS_IMETHOD GetForceInheritPrincipal(bool *aForceInheritPrincipal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceInheritPrincipal(aForceInheritPrincipal); } \
  NS_IMETHOD GetLoadingSandboxed(bool *aLoadingSandboxed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadingSandboxed(aLoadingSandboxed); } \
  NS_IMETHOD GetContentPolicyType(nsContentPolicyType *aContentPolicyType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentPolicyType(aContentPolicyType); } \
  NS_IMETHOD_(nsContentPolicyType) InternalContentPolicyType(void) override; \
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseURI(aBaseURI); } \
  virtual nsIURI * BaseURI(void) override; \
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerWindowID(aInnerWindowID); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetParentOuterWindowID(uint64_t *aParentOuterWindowID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentOuterWindowID(aParentOuterWindowID); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoadInfo : public nsILoadInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOADINFO

  nsLoadInfo();

private:
  ~nsLoadInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLoadInfo, nsILoadInfo)

nsLoadInfo::nsLoadInfo()
{
  /* member initializers and constructor code */
}

nsLoadInfo::~nsLoadInfo()
{
  /* destructor code */
}

/* readonly attribute nsIPrincipal loadingPrincipal; */
NS_IMETHODIMP nsLoadInfo::GetLoadingPrincipal(nsIPrincipal * *aLoadingPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(LoadingPrincipal),noscript,nostdcall,notxpcom] nsIPrincipal binaryLoadingPrincipal (); */
nsIPrincipal * nsLoadInfo::LoadingPrincipal()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrincipal triggeringPrincipal; */
NS_IMETHODIMP nsLoadInfo::GetTriggeringPrincipal(nsIPrincipal * *aTriggeringPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(TriggeringPrincipal),noscript,nostdcall,notxpcom] nsIPrincipal binaryTriggeringPrincipal (); */
nsIPrincipal * nsLoadInfo::TriggeringPrincipal()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument loadingDocument; */
NS_IMETHODIMP nsLoadInfo::GetLoadingDocument(nsIDOMDocument * *aLoadingDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(LoadingNode),noscript,nostdcall,notxpcom] nsINode binaryLoadingNode (); */
nsINode * nsLoadInfo::LoadingNode()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsSecurityFlags securityFlags; */
NS_IMETHODIMP nsLoadInfo::GetSecurityFlags(nsSecurityFlags *aSecurityFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean forceInheritPrincipal; */
NS_IMETHODIMP nsLoadInfo::GetForceInheritPrincipal(bool *aForceInheritPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean loadingSandboxed; */
NS_IMETHODIMP nsLoadInfo::GetLoadingSandboxed(bool *aLoadingSandboxed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsContentPolicyType contentPolicyType; */
NS_IMETHODIMP nsLoadInfo::GetContentPolicyType(nsContentPolicyType *aContentPolicyType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] nsContentPolicyType internalContentPolicyType (); */
NS_IMETHODIMP_(nsContentPolicyType) nsLoadInfo::InternalContentPolicyType()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI baseURI; */
NS_IMETHODIMP nsLoadInfo::GetBaseURI(nsIURI * *aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(BaseURI),noscript,nostdcall,notxpcom] nsIURI binaryBaseURI (); */
nsIURI * nsLoadInfo::BaseURI()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long innerWindowID; */
NS_IMETHODIMP nsLoadInfo::GetInnerWindowID(uint64_t *aInnerWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long outerWindowID; */
NS_IMETHODIMP nsLoadInfo::GetOuterWindowID(uint64_t *aOuterWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long parentOuterWindowID; */
NS_IMETHODIMP nsLoadInfo::GetParentOuterWindowID(uint64_t *aParentOuterWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoadInfo_h__ */
