/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDomainPolicy.idl
 */

#ifndef __gen_nsIDomainPolicy_h__
#define __gen_nsIDomainPolicy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDomainSet; /* forward declaration */

namespace mozilla {
namespace dom {
class DomainPolicyClone;
}
}

/* starting interface:    nsIDomainPolicy */
#define NS_IDOMAINPOLICY_IID_STR "82b24a20-6701-4d40-a0f9-f5dc7321b555"

#define NS_IDOMAINPOLICY_IID \
  {0x82b24a20, 0x6701, 0x4d40, \
    { 0xa0, 0xf9, 0xf5, 0xdc, 0x73, 0x21, 0xb5, 0x55 }}

class NS_NO_VTABLE nsIDomainPolicy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMAINPOLICY_IID)

  /* readonly attribute nsIDomainSet blacklist; */
  NS_IMETHOD GetBlacklist(nsIDomainSet * *aBlacklist) = 0;

  /* readonly attribute nsIDomainSet superBlacklist; */
  NS_IMETHOD GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist) = 0;

  /* readonly attribute nsIDomainSet whitelist; */
  NS_IMETHOD GetWhitelist(nsIDomainSet * *aWhitelist) = 0;

  /* readonly attribute nsIDomainSet superWhitelist; */
  NS_IMETHOD GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist) = 0;

  /* void deactivate (); */
  NS_IMETHOD Deactivate(void) = 0;

  /* [noscript,notxpcom] void cloneDomainPolicy (in DomainPolicyClonePtr aClone); */
  NS_IMETHOD_(void) CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone) = 0;

  /* [noscript,notxpcom] void applyClone (in DomainPolicyClonePtr aClone); */
  NS_IMETHOD_(void) ApplyClone(mozilla::dom::DomainPolicyClone *aClone) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDomainPolicy, NS_IDOMAINPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMAINPOLICY \
  NS_IMETHOD GetBlacklist(nsIDomainSet * *aBlacklist) override; \
  NS_IMETHOD GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist) override; \
  NS_IMETHOD GetWhitelist(nsIDomainSet * *aWhitelist) override; \
  NS_IMETHOD GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist) override; \
  NS_IMETHOD Deactivate(void) override; \
  NS_IMETHOD_(void) CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone) override; \
  NS_IMETHOD_(void) ApplyClone(mozilla::dom::DomainPolicyClone *aClone) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMAINPOLICY(_to) \
  NS_IMETHOD GetBlacklist(nsIDomainSet * *aBlacklist) override { return _to GetBlacklist(aBlacklist); } \
  NS_IMETHOD GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist) override { return _to GetSuperBlacklist(aSuperBlacklist); } \
  NS_IMETHOD GetWhitelist(nsIDomainSet * *aWhitelist) override { return _to GetWhitelist(aWhitelist); } \
  NS_IMETHOD GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist) override { return _to GetSuperWhitelist(aSuperWhitelist); } \
  NS_IMETHOD Deactivate(void) override { return _to Deactivate(); } \
  NS_IMETHOD_(void) CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone) override { return _to CloneDomainPolicy(aClone); } \
  NS_IMETHOD_(void) ApplyClone(mozilla::dom::DomainPolicyClone *aClone) override { return _to ApplyClone(aClone); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMAINPOLICY(_to) \
  NS_IMETHOD GetBlacklist(nsIDomainSet * *aBlacklist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlacklist(aBlacklist); } \
  NS_IMETHOD GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuperBlacklist(aSuperBlacklist); } \
  NS_IMETHOD GetWhitelist(nsIDomainSet * *aWhitelist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhitelist(aWhitelist); } \
  NS_IMETHOD GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuperWhitelist(aSuperWhitelist); } \
  NS_IMETHOD Deactivate(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Deactivate(); } \
  NS_IMETHOD_(void) CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone) override; \
  NS_IMETHOD_(void) ApplyClone(mozilla::dom::DomainPolicyClone *aClone) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDomainPolicy : public nsIDomainPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMAINPOLICY

  nsDomainPolicy();

private:
  ~nsDomainPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDomainPolicy, nsIDomainPolicy)

nsDomainPolicy::nsDomainPolicy()
{
  /* member initializers and constructor code */
}

nsDomainPolicy::~nsDomainPolicy()
{
  /* destructor code */
}

/* readonly attribute nsIDomainSet blacklist; */
NS_IMETHODIMP nsDomainPolicy::GetBlacklist(nsIDomainSet * *aBlacklist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDomainSet superBlacklist; */
NS_IMETHODIMP nsDomainPolicy::GetSuperBlacklist(nsIDomainSet * *aSuperBlacklist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDomainSet whitelist; */
NS_IMETHODIMP nsDomainPolicy::GetWhitelist(nsIDomainSet * *aWhitelist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDomainSet superWhitelist; */
NS_IMETHODIMP nsDomainPolicy::GetSuperWhitelist(nsIDomainSet * *aSuperWhitelist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deactivate (); */
NS_IMETHODIMP nsDomainPolicy::Deactivate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void cloneDomainPolicy (in DomainPolicyClonePtr aClone); */
NS_IMETHODIMP_(void) nsDomainPolicy::CloneDomainPolicy(mozilla::dom::DomainPolicyClone *aClone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void applyClone (in DomainPolicyClonePtr aClone); */
NS_IMETHODIMP_(void) nsDomainPolicy::ApplyClone(mozilla::dom::DomainPolicyClone *aClone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDomainSet */
#define NS_IDOMAINSET_IID_STR "665c981b-0a0f-4229-ac06-a826e02d4f69"

#define NS_IDOMAINSET_IID \
  {0x665c981b, 0x0a0f, 0x4229, \
    { 0xac, 0x06, 0xa8, 0x26, 0xe0, 0x2d, 0x4f, 0x69 }}

class NS_NO_VTABLE nsIDomainSet : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMAINSET_IID)

  /* [noscript] readonly attribute uint32_t type; */
  NS_IMETHOD GetType(uint32_t *aType) = 0;

  /* void add (in nsIURI aDomain); */
  NS_IMETHOD Add(nsIURI *aDomain) = 0;

  /* void remove (in nsIURI aDomain); */
  NS_IMETHOD Remove(nsIURI *aDomain) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  /* bool contains (in nsIURI aDomain); */
  NS_IMETHOD Contains(nsIURI *aDomain, bool *_retval) = 0;

  /* bool containsSuperDomain (in nsIURI aDomain); */
  NS_IMETHOD ContainsSuperDomain(nsIURI *aDomain, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDomainSet, NS_IDOMAINSET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMAINSET \
  NS_IMETHOD GetType(uint32_t *aType) override; \
  NS_IMETHOD Add(nsIURI *aDomain) override; \
  NS_IMETHOD Remove(nsIURI *aDomain) override; \
  NS_IMETHOD Clear(void) override; \
  NS_IMETHOD Contains(nsIURI *aDomain, bool *_retval) override; \
  NS_IMETHOD ContainsSuperDomain(nsIURI *aDomain, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMAINSET(_to) \
  NS_IMETHOD GetType(uint32_t *aType) override { return _to GetType(aType); } \
  NS_IMETHOD Add(nsIURI *aDomain) override { return _to Add(aDomain); } \
  NS_IMETHOD Remove(nsIURI *aDomain) override { return _to Remove(aDomain); } \
  NS_IMETHOD Clear(void) override { return _to Clear(); } \
  NS_IMETHOD Contains(nsIURI *aDomain, bool *_retval) override { return _to Contains(aDomain, _retval); } \
  NS_IMETHOD ContainsSuperDomain(nsIURI *aDomain, bool *_retval) override { return _to ContainsSuperDomain(aDomain, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMAINSET(_to) \
  NS_IMETHOD GetType(uint32_t *aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD Add(nsIURI *aDomain) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(aDomain); } \
  NS_IMETHOD Remove(nsIURI *aDomain) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(aDomain); } \
  NS_IMETHOD Clear(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD Contains(nsIURI *aDomain, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Contains(aDomain, _retval); } \
  NS_IMETHOD ContainsSuperDomain(nsIURI *aDomain, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainsSuperDomain(aDomain, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDomainSet : public nsIDomainSet
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMAINSET

  nsDomainSet();

private:
  ~nsDomainSet();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDomainSet, nsIDomainSet)

nsDomainSet::nsDomainSet()
{
  /* member initializers and constructor code */
}

nsDomainSet::~nsDomainSet()
{
  /* destructor code */
}

/* [noscript] readonly attribute uint32_t type; */
NS_IMETHODIMP nsDomainSet::GetType(uint32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void add (in nsIURI aDomain); */
NS_IMETHODIMP nsDomainSet::Add(nsIURI *aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in nsIURI aDomain); */
NS_IMETHODIMP nsDomainSet::Remove(nsIURI *aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsDomainSet::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool contains (in nsIURI aDomain); */
NS_IMETHODIMP nsDomainSet::Contains(nsIURI *aDomain, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool containsSuperDomain (in nsIURI aDomain); */
NS_IMETHODIMP nsDomainSet::ContainsSuperDomain(nsIURI *aDomain, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDomainPolicy_h__ */
