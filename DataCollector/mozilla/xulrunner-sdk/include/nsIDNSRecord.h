/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDNSRecord.idl
 */

#ifndef __gen_nsIDNSRecord_h__
#define __gen_nsIDNSRecord_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace mozilla {
namespace net {
union NetAddr;
}
}
template<class T> class nsTArray;
class nsINetAddr; /* forward declaration */


/* starting interface:    nsIDNSRecord */
#define NS_IDNSRECORD_IID_STR "f92228ae-c417-4188-a604-0830a95e7eb9"

#define NS_IDNSRECORD_IID \
  {0xf92228ae, 0xc417, 0x4188, \
    { 0xa6, 0x04, 0x08, 0x30, 0xa9, 0x5e, 0x7e, 0xb9 }}

class NS_NO_VTABLE nsIDNSRecord : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSRECORD_IID)

  /* readonly attribute ACString canonicalName; */
  NS_IMETHOD GetCanonicalName(nsACString & aCanonicalName) = 0;

  /* [noscript] NetAddr getNextAddr (in uint16_t aPort); */
  NS_IMETHOD GetNextAddr(uint16_t aPort, mozilla::net::NetAddr *_retval) = 0;

  /* [noscript] void getAddresses (out nsNetAddrTArrayRef aAddressArray); */
  NS_IMETHOD GetAddresses(nsTArray<mozilla::net::NetAddr> & aAddressArray) = 0;

  /* nsINetAddr getScriptableNextAddr (in uint16_t aPort); */
  NS_IMETHOD GetScriptableNextAddr(uint16_t aPort, nsINetAddr * *_retval) = 0;

  /* ACString getNextAddrAsString (); */
  NS_IMETHOD GetNextAddrAsString(nsACString & _retval) = 0;

  /* boolean hasMore (); */
  NS_IMETHOD HasMore(bool *_retval) = 0;

  /* void rewind (); */
  NS_IMETHOD Rewind(void) = 0;

  /* void reportUnusable (in uint16_t aPort); */
  NS_IMETHOD ReportUnusable(uint16_t aPort) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSRecord, NS_IDNSRECORD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSRECORD \
  NS_IMETHOD GetCanonicalName(nsACString & aCanonicalName) override; \
  NS_IMETHOD GetNextAddr(uint16_t aPort, mozilla::net::NetAddr *_retval) override; \
  NS_IMETHOD GetAddresses(nsTArray<mozilla::net::NetAddr> & aAddressArray) override; \
  NS_IMETHOD GetScriptableNextAddr(uint16_t aPort, nsINetAddr * *_retval) override; \
  NS_IMETHOD GetNextAddrAsString(nsACString & _retval) override; \
  NS_IMETHOD HasMore(bool *_retval) override; \
  NS_IMETHOD Rewind(void) override; \
  NS_IMETHOD ReportUnusable(uint16_t aPort) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSRECORD(_to) \
  NS_IMETHOD GetCanonicalName(nsACString & aCanonicalName) override { return _to GetCanonicalName(aCanonicalName); } \
  NS_IMETHOD GetNextAddr(uint16_t aPort, mozilla::net::NetAddr *_retval) override { return _to GetNextAddr(aPort, _retval); } \
  NS_IMETHOD GetAddresses(nsTArray<mozilla::net::NetAddr> & aAddressArray) override { return _to GetAddresses(aAddressArray); } \
  NS_IMETHOD GetScriptableNextAddr(uint16_t aPort, nsINetAddr * *_retval) override { return _to GetScriptableNextAddr(aPort, _retval); } \
  NS_IMETHOD GetNextAddrAsString(nsACString & _retval) override { return _to GetNextAddrAsString(_retval); } \
  NS_IMETHOD HasMore(bool *_retval) override { return _to HasMore(_retval); } \
  NS_IMETHOD Rewind(void) override { return _to Rewind(); } \
  NS_IMETHOD ReportUnusable(uint16_t aPort) override { return _to ReportUnusable(aPort); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSRECORD(_to) \
  NS_IMETHOD GetCanonicalName(nsACString & aCanonicalName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanonicalName(aCanonicalName); } \
  NS_IMETHOD GetNextAddr(uint16_t aPort, mozilla::net::NetAddr *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextAddr(aPort, _retval); } \
  NS_IMETHOD GetAddresses(nsTArray<mozilla::net::NetAddr> & aAddressArray) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddresses(aAddressArray); } \
  NS_IMETHOD GetScriptableNextAddr(uint16_t aPort, nsINetAddr * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableNextAddr(aPort, _retval); } \
  NS_IMETHOD GetNextAddrAsString(nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextAddrAsString(_retval); } \
  NS_IMETHOD HasMore(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasMore(_retval); } \
  NS_IMETHOD Rewind(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Rewind(); } \
  NS_IMETHOD ReportUnusable(uint16_t aPort) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReportUnusable(aPort); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSRecord : public nsIDNSRecord
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSRECORD

  nsDNSRecord();

private:
  ~nsDNSRecord();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDNSRecord, nsIDNSRecord)

nsDNSRecord::nsDNSRecord()
{
  /* member initializers and constructor code */
}

nsDNSRecord::~nsDNSRecord()
{
  /* destructor code */
}

/* readonly attribute ACString canonicalName; */
NS_IMETHODIMP nsDNSRecord::GetCanonicalName(nsACString & aCanonicalName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] NetAddr getNextAddr (in uint16_t aPort); */
NS_IMETHODIMP nsDNSRecord::GetNextAddr(uint16_t aPort, mozilla::net::NetAddr *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getAddresses (out nsNetAddrTArrayRef aAddressArray); */
NS_IMETHODIMP nsDNSRecord::GetAddresses(nsTArray<mozilla::net::NetAddr> & aAddressArray)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsINetAddr getScriptableNextAddr (in uint16_t aPort); */
NS_IMETHODIMP nsDNSRecord::GetScriptableNextAddr(uint16_t aPort, nsINetAddr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getNextAddrAsString (); */
NS_IMETHODIMP nsDNSRecord::GetNextAddrAsString(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasMore (); */
NS_IMETHODIMP nsDNSRecord::HasMore(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rewind (); */
NS_IMETHODIMP nsDNSRecord::Rewind()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reportUnusable (in uint16_t aPort); */
NS_IMETHODIMP nsDNSRecord::ReportUnusable(uint16_t aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDNSRecord_h__ */
