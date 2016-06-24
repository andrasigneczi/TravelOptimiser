/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIX509CertList.idl
 */

#ifndef __gen_nsIX509CertList_h__
#define __gen_nsIX509CertList_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsIX509Cert; /* forward declaration */


/* starting interface:    nsIX509CertList */
#define NS_IX509CERTLIST_IID_STR "ae74cda5-cd2f-473f-96f5-f0b7fff62c68"

#define NS_IX509CERTLIST_IID \
  {0xae74cda5, 0xcd2f, 0x473f, \
    { 0x96, 0xf5, 0xf0, 0xb7, 0xff, 0xf6, 0x2c, 0x68 }}

class NS_NO_VTABLE nsIX509CertList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERTLIST_IID)

  /* void addCert (in nsIX509Cert cert); */
  NS_IMETHOD AddCert(nsIX509Cert *cert) = 0;

  /* void deleteCert (in nsIX509Cert cert); */
  NS_IMETHOD DeleteCert(nsIX509Cert *cert) = 0;

  /* nsISimpleEnumerator getEnumerator (); */
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *_retval) = 0;

  /* [noscript,notxpcom] voidPtr getRawCertList (); */
  NS_IMETHOD_(void *) GetRawCertList(void) = 0;

  /* boolean equals (in nsIX509CertList other); */
  NS_IMETHOD Equals(nsIX509CertList *other, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509CertList, NS_IX509CERTLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERTLIST \
  NS_IMETHOD AddCert(nsIX509Cert *cert) override; \
  NS_IMETHOD DeleteCert(nsIX509Cert *cert) override; \
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *_retval) override; \
  NS_IMETHOD_(void *) GetRawCertList(void) override; \
  NS_IMETHOD Equals(nsIX509CertList *other, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERTLIST(_to) \
  NS_IMETHOD AddCert(nsIX509Cert *cert) override { return _to AddCert(cert); } \
  NS_IMETHOD DeleteCert(nsIX509Cert *cert) override { return _to DeleteCert(cert); } \
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *_retval) override { return _to GetEnumerator(_retval); } \
  NS_IMETHOD_(void *) GetRawCertList(void) override { return _to GetRawCertList(); } \
  NS_IMETHOD Equals(nsIX509CertList *other, bool *_retval) override { return _to Equals(other, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERTLIST(_to) \
  NS_IMETHOD AddCert(nsIX509Cert *cert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCert(cert); } \
  NS_IMETHOD DeleteCert(nsIX509Cert *cert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteCert(cert); } \
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(_retval); } \
  NS_IMETHOD_(void *) GetRawCertList(void) override; \
  NS_IMETHOD Equals(nsIX509CertList *other, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(other, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509CertList : public nsIX509CertList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERTLIST

  nsX509CertList();

private:
  ~nsX509CertList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsX509CertList, nsIX509CertList)

nsX509CertList::nsX509CertList()
{
  /* member initializers and constructor code */
}

nsX509CertList::~nsX509CertList()
{
  /* destructor code */
}

/* void addCert (in nsIX509Cert cert); */
NS_IMETHODIMP nsX509CertList::AddCert(nsIX509Cert *cert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteCert (in nsIX509Cert cert); */
NS_IMETHODIMP nsX509CertList::DeleteCert(nsIX509Cert *cert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getEnumerator (); */
NS_IMETHODIMP nsX509CertList::GetEnumerator(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] voidPtr getRawCertList (); */
NS_IMETHODIMP_(void *) nsX509CertList::GetRawCertList()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIX509CertList other); */
NS_IMETHODIMP nsX509CertList::Equals(nsIX509CertList *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_X509CERTLIST_CID { /* 959fb165-6517-487f-ab9b-d8913be53197 */  \
    0x959fb165,                                                           \
    0x6517,                                                               \
    0x487f,                                                               \
    {0xab, 0x9b, 0xd8, 0x91, 0x3b, 0xe5, 0x31, 0x97}                      \
  }
#define NS_X509CERTLIST_CONTRACTID "@mozilla.org/security/x509certlist;1"

#endif /* __gen_nsIX509CertList_h__ */
