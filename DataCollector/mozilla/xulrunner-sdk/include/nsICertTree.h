/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICertTree.idl
 */

#ifndef __gen_nsICertTree_h__
#define __gen_nsICertTree_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsITreeView_h__
#include "nsITreeView.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */

class nsIX509CertList; /* forward declaration */


/* starting interface:    nsICertTreeItem */
#define NS_ICERTTREEITEM_IID_STR "d0180863-606e-49e6-8324-cf45ed4dd891"

#define NS_ICERTTREEITEM_IID \
  {0xd0180863, 0x606e, 0x49e6, \
    { 0x83, 0x24, 0xcf, 0x45, 0xed, 0x4d, 0xd8, 0x91 }}

class NS_NO_VTABLE nsICertTreeItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTTREEITEM_IID)

  /* readonly attribute nsIX509Cert cert; */
  NS_IMETHOD GetCert(nsIX509Cert * *aCert) = 0;

  /* readonly attribute AString hostPort; */
  NS_IMETHOD GetHostPort(nsAString & aHostPort) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertTreeItem, NS_ICERTTREEITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTTREEITEM \
  NS_IMETHOD GetCert(nsIX509Cert * *aCert) override; \
  NS_IMETHOD GetHostPort(nsAString & aHostPort) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTTREEITEM(_to) \
  NS_IMETHOD GetCert(nsIX509Cert * *aCert) override { return _to GetCert(aCert); } \
  NS_IMETHOD GetHostPort(nsAString & aHostPort) override { return _to GetHostPort(aHostPort); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTTREEITEM(_to) \
  NS_IMETHOD GetCert(nsIX509Cert * *aCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCert(aCert); } \
  NS_IMETHOD GetHostPort(nsAString & aHostPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHostPort(aHostPort); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertTreeItem : public nsICertTreeItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTTREEITEM

  nsCertTreeItem();

private:
  ~nsCertTreeItem();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCertTreeItem, nsICertTreeItem)

nsCertTreeItem::nsCertTreeItem()
{
  /* member initializers and constructor code */
}

nsCertTreeItem::~nsCertTreeItem()
{
  /* destructor code */
}

/* readonly attribute nsIX509Cert cert; */
NS_IMETHODIMP nsCertTreeItem::GetCert(nsIX509Cert * *aCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString hostPort; */
NS_IMETHODIMP nsCertTreeItem::GetHostPort(nsAString & aHostPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICertTree */
#define NS_ICERTTREE_IID_STR "55d5ad6b-5572-47fe-941c-f01fe723659e"

#define NS_ICERTTREE_IID \
  {0x55d5ad6b, 0x5572, 0x47fe, \
    { 0x94, 0x1c, 0xf0, 0x1f, 0xe7, 0x23, 0x65, 0x9e }}

class NS_NO_VTABLE nsICertTree : public nsITreeView {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTTREE_IID)

  /* void loadCerts (in unsigned long type); */
  NS_IMETHOD LoadCerts(uint32_t type) = 0;

  /* void loadCertsFromCache (in nsIX509CertList cache, in unsigned long type); */
  NS_IMETHOD LoadCertsFromCache(nsIX509CertList *cache, uint32_t type) = 0;

  /* nsIX509Cert getCert (in unsigned long index); */
  NS_IMETHOD GetCert(uint32_t index, nsIX509Cert * *_retval) = 0;

  /* nsICertTreeItem getTreeItem (in unsigned long index); */
  NS_IMETHOD GetTreeItem(uint32_t index, nsICertTreeItem * *_retval) = 0;

  /* boolean isHostPortOverride (in unsigned long index); */
  NS_IMETHOD IsHostPortOverride(uint32_t index, bool *_retval) = 0;

  /* void deleteEntryObject (in unsigned long index); */
  NS_IMETHOD DeleteEntryObject(uint32_t index) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertTree, NS_ICERTTREE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTTREE \
  NS_IMETHOD LoadCerts(uint32_t type) override; \
  NS_IMETHOD LoadCertsFromCache(nsIX509CertList *cache, uint32_t type) override; \
  NS_IMETHOD GetCert(uint32_t index, nsIX509Cert * *_retval) override; \
  NS_IMETHOD GetTreeItem(uint32_t index, nsICertTreeItem * *_retval) override; \
  NS_IMETHOD IsHostPortOverride(uint32_t index, bool *_retval) override; \
  NS_IMETHOD DeleteEntryObject(uint32_t index) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTTREE(_to) \
  NS_IMETHOD LoadCerts(uint32_t type) override { return _to LoadCerts(type); } \
  NS_IMETHOD LoadCertsFromCache(nsIX509CertList *cache, uint32_t type) override { return _to LoadCertsFromCache(cache, type); } \
  NS_IMETHOD GetCert(uint32_t index, nsIX509Cert * *_retval) override { return _to GetCert(index, _retval); } \
  NS_IMETHOD GetTreeItem(uint32_t index, nsICertTreeItem * *_retval) override { return _to GetTreeItem(index, _retval); } \
  NS_IMETHOD IsHostPortOverride(uint32_t index, bool *_retval) override { return _to IsHostPortOverride(index, _retval); } \
  NS_IMETHOD DeleteEntryObject(uint32_t index) override { return _to DeleteEntryObject(index); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTTREE(_to) \
  NS_IMETHOD LoadCerts(uint32_t type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadCerts(type); } \
  NS_IMETHOD LoadCertsFromCache(nsIX509CertList *cache, uint32_t type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadCertsFromCache(cache, type); } \
  NS_IMETHOD GetCert(uint32_t index, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCert(index, _retval); } \
  NS_IMETHOD GetTreeItem(uint32_t index, nsICertTreeItem * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTreeItem(index, _retval); } \
  NS_IMETHOD IsHostPortOverride(uint32_t index, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsHostPortOverride(index, _retval); } \
  NS_IMETHOD DeleteEntryObject(uint32_t index) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteEntryObject(index); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertTree : public nsICertTree
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTTREE

  nsCertTree();

private:
  ~nsCertTree();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCertTree, nsICertTree)

nsCertTree::nsCertTree()
{
  /* member initializers and constructor code */
}

nsCertTree::~nsCertTree()
{
  /* destructor code */
}

/* void loadCerts (in unsigned long type); */
NS_IMETHODIMP nsCertTree::LoadCerts(uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadCertsFromCache (in nsIX509CertList cache, in unsigned long type); */
NS_IMETHODIMP nsCertTree::LoadCertsFromCache(nsIX509CertList *cache, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert getCert (in unsigned long index); */
NS_IMETHODIMP nsCertTree::GetCert(uint32_t index, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICertTreeItem getTreeItem (in unsigned long index); */
NS_IMETHODIMP nsCertTree::GetTreeItem(uint32_t index, nsICertTreeItem * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isHostPortOverride (in unsigned long index); */
NS_IMETHODIMP nsCertTree::IsHostPortOverride(uint32_t index, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteEntryObject (in unsigned long index); */
NS_IMETHODIMP nsCertTree::DeleteEntryObject(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_CERTTREE_CID { 0x4ea60761, 0x31d6, 0x491d, \
                         { 0x9e, 0x34, 0x4b, 0x53, 0xa2, 0x6c, 0x41, 0x6c } }
#define NS_CERTTREE_CONTRACTID "@mozilla.org/security/nsCertTree;1"

#endif /* __gen_nsICertTree_h__ */
