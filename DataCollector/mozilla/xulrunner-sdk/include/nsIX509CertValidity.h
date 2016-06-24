/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIX509CertValidity.idl
 */

#ifndef __gen_nsIX509CertValidity_h__
#define __gen_nsIX509CertValidity_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIX509CertValidity */
#define NS_IX509CERTVALIDITY_IID_STR "e701dfd8-1dd1-11b2-a172-ffa6cc6156ad"

#define NS_IX509CERTVALIDITY_IID \
  {0xe701dfd8, 0x1dd1, 0x11b2, \
    { 0xa1, 0x72, 0xff, 0xa6, 0xcc, 0x61, 0x56, 0xad }}

class NS_NO_VTABLE nsIX509CertValidity : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERTVALIDITY_IID)

  /* readonly attribute PRTime notBefore; */
  NS_IMETHOD GetNotBefore(PRTime *aNotBefore) = 0;

  /* readonly attribute AString notBeforeLocalTime; */
  NS_IMETHOD GetNotBeforeLocalTime(nsAString & aNotBeforeLocalTime) = 0;

  /* readonly attribute AString notBeforeLocalDay; */
  NS_IMETHOD GetNotBeforeLocalDay(nsAString & aNotBeforeLocalDay) = 0;

  /* readonly attribute AString notBeforeGMT; */
  NS_IMETHOD GetNotBeforeGMT(nsAString & aNotBeforeGMT) = 0;

  /* readonly attribute PRTime notAfter; */
  NS_IMETHOD GetNotAfter(PRTime *aNotAfter) = 0;

  /* readonly attribute AString notAfterLocalTime; */
  NS_IMETHOD GetNotAfterLocalTime(nsAString & aNotAfterLocalTime) = 0;

  /* readonly attribute AString notAfterLocalDay; */
  NS_IMETHOD GetNotAfterLocalDay(nsAString & aNotAfterLocalDay) = 0;

  /* readonly attribute AString notAfterGMT; */
  NS_IMETHOD GetNotAfterGMT(nsAString & aNotAfterGMT) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509CertValidity, NS_IX509CERTVALIDITY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERTVALIDITY \
  NS_IMETHOD GetNotBefore(PRTime *aNotBefore) override; \
  NS_IMETHOD GetNotBeforeLocalTime(nsAString & aNotBeforeLocalTime) override; \
  NS_IMETHOD GetNotBeforeLocalDay(nsAString & aNotBeforeLocalDay) override; \
  NS_IMETHOD GetNotBeforeGMT(nsAString & aNotBeforeGMT) override; \
  NS_IMETHOD GetNotAfter(PRTime *aNotAfter) override; \
  NS_IMETHOD GetNotAfterLocalTime(nsAString & aNotAfterLocalTime) override; \
  NS_IMETHOD GetNotAfterLocalDay(nsAString & aNotAfterLocalDay) override; \
  NS_IMETHOD GetNotAfterGMT(nsAString & aNotAfterGMT) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERTVALIDITY(_to) \
  NS_IMETHOD GetNotBefore(PRTime *aNotBefore) override { return _to GetNotBefore(aNotBefore); } \
  NS_IMETHOD GetNotBeforeLocalTime(nsAString & aNotBeforeLocalTime) override { return _to GetNotBeforeLocalTime(aNotBeforeLocalTime); } \
  NS_IMETHOD GetNotBeforeLocalDay(nsAString & aNotBeforeLocalDay) override { return _to GetNotBeforeLocalDay(aNotBeforeLocalDay); } \
  NS_IMETHOD GetNotBeforeGMT(nsAString & aNotBeforeGMT) override { return _to GetNotBeforeGMT(aNotBeforeGMT); } \
  NS_IMETHOD GetNotAfter(PRTime *aNotAfter) override { return _to GetNotAfter(aNotAfter); } \
  NS_IMETHOD GetNotAfterLocalTime(nsAString & aNotAfterLocalTime) override { return _to GetNotAfterLocalTime(aNotAfterLocalTime); } \
  NS_IMETHOD GetNotAfterLocalDay(nsAString & aNotAfterLocalDay) override { return _to GetNotAfterLocalDay(aNotAfterLocalDay); } \
  NS_IMETHOD GetNotAfterGMT(nsAString & aNotAfterGMT) override { return _to GetNotAfterGMT(aNotAfterGMT); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERTVALIDITY(_to) \
  NS_IMETHOD GetNotBefore(PRTime *aNotBefore) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotBefore(aNotBefore); } \
  NS_IMETHOD GetNotBeforeLocalTime(nsAString & aNotBeforeLocalTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotBeforeLocalTime(aNotBeforeLocalTime); } \
  NS_IMETHOD GetNotBeforeLocalDay(nsAString & aNotBeforeLocalDay) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotBeforeLocalDay(aNotBeforeLocalDay); } \
  NS_IMETHOD GetNotBeforeGMT(nsAString & aNotBeforeGMT) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotBeforeGMT(aNotBeforeGMT); } \
  NS_IMETHOD GetNotAfter(PRTime *aNotAfter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotAfter(aNotAfter); } \
  NS_IMETHOD GetNotAfterLocalTime(nsAString & aNotAfterLocalTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotAfterLocalTime(aNotAfterLocalTime); } \
  NS_IMETHOD GetNotAfterLocalDay(nsAString & aNotAfterLocalDay) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotAfterLocalDay(aNotAfterLocalDay); } \
  NS_IMETHOD GetNotAfterGMT(nsAString & aNotAfterGMT) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotAfterGMT(aNotAfterGMT); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509CertValidity : public nsIX509CertValidity
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERTVALIDITY

  nsX509CertValidity();

private:
  ~nsX509CertValidity();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsX509CertValidity, nsIX509CertValidity)

nsX509CertValidity::nsX509CertValidity()
{
  /* member initializers and constructor code */
}

nsX509CertValidity::~nsX509CertValidity()
{
  /* destructor code */
}

/* readonly attribute PRTime notBefore; */
NS_IMETHODIMP nsX509CertValidity::GetNotBefore(PRTime *aNotBefore)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString notBeforeLocalTime; */
NS_IMETHODIMP nsX509CertValidity::GetNotBeforeLocalTime(nsAString & aNotBeforeLocalTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString notBeforeLocalDay; */
NS_IMETHODIMP nsX509CertValidity::GetNotBeforeLocalDay(nsAString & aNotBeforeLocalDay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString notBeforeGMT; */
NS_IMETHODIMP nsX509CertValidity::GetNotBeforeGMT(nsAString & aNotBeforeGMT)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime notAfter; */
NS_IMETHODIMP nsX509CertValidity::GetNotAfter(PRTime *aNotAfter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString notAfterLocalTime; */
NS_IMETHODIMP nsX509CertValidity::GetNotAfterLocalTime(nsAString & aNotAfterLocalTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString notAfterLocalDay; */
NS_IMETHODIMP nsX509CertValidity::GetNotAfterLocalDay(nsAString & aNotAfterLocalDay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString notAfterGMT; */
NS_IMETHODIMP nsX509CertValidity::GetNotAfterGMT(nsAString & aNotAfterGMT)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIX509CertValidity_h__ */
