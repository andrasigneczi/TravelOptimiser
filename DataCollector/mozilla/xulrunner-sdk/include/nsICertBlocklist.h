/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICertBlocklist.idl
 */

#ifndef __gen_nsICertBlocklist_h__
#define __gen_nsICertBlocklist_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */

#define NS_CERTBLOCKLIST_CONTRACTID "@mozilla.org/security/certblocklist;1"

/* starting interface:    nsICertBlocklist */
#define NS_ICERTBLOCKLIST_IID_STR "e0654480-f433-11e4-b939-0800200c9a66"

#define NS_ICERTBLOCKLIST_IID \
  {0xe0654480, 0xf433, 0x11e4, \
    { 0xb9, 0x39, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsICertBlocklist : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTBLOCKLIST_IID)

  /* void revokeCertByIssuerAndSerial (in string issuer, in string serialNumber); */
  NS_IMETHOD RevokeCertByIssuerAndSerial(const char * issuer, const char * serialNumber) = 0;

  /* void revokeCertBySubjectAndPubKey (in string subject, in string pubKeyHash); */
  NS_IMETHOD RevokeCertBySubjectAndPubKey(const char * subject, const char * pubKeyHash) = 0;

  /* void saveEntries (); */
  NS_IMETHOD SaveEntries(void) = 0;

  /* boolean isCertRevoked ([array, size_is (issuer_length), const] in octet issuer, in unsigned long issuer_length, [array, size_is (serial_length), const] in octet serial, in unsigned long serial_length, [array, size_is (subject_length), const] in octet subject, in unsigned long subject_length, [array, size_is (pubkey_length), const] in octet pubkey, in unsigned long pubkey_length); */
  NS_IMETHOD IsCertRevoked(const uint8_t *issuer, uint32_t issuer_length, const uint8_t *serial, uint32_t serial_length, const uint8_t *subject, uint32_t subject_length, const uint8_t *pubkey, uint32_t pubkey_length, bool *_retval) = 0;

  /* boolean isBlocklistFresh (); */
  NS_IMETHOD IsBlocklistFresh(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertBlocklist, NS_ICERTBLOCKLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTBLOCKLIST \
  NS_IMETHOD RevokeCertByIssuerAndSerial(const char * issuer, const char * serialNumber) override; \
  NS_IMETHOD RevokeCertBySubjectAndPubKey(const char * subject, const char * pubKeyHash) override; \
  NS_IMETHOD SaveEntries(void) override; \
  NS_IMETHOD IsCertRevoked(const uint8_t *issuer, uint32_t issuer_length, const uint8_t *serial, uint32_t serial_length, const uint8_t *subject, uint32_t subject_length, const uint8_t *pubkey, uint32_t pubkey_length, bool *_retval) override; \
  NS_IMETHOD IsBlocklistFresh(bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTBLOCKLIST(_to) \
  NS_IMETHOD RevokeCertByIssuerAndSerial(const char * issuer, const char * serialNumber) override { return _to RevokeCertByIssuerAndSerial(issuer, serialNumber); } \
  NS_IMETHOD RevokeCertBySubjectAndPubKey(const char * subject, const char * pubKeyHash) override { return _to RevokeCertBySubjectAndPubKey(subject, pubKeyHash); } \
  NS_IMETHOD SaveEntries(void) override { return _to SaveEntries(); } \
  NS_IMETHOD IsCertRevoked(const uint8_t *issuer, uint32_t issuer_length, const uint8_t *serial, uint32_t serial_length, const uint8_t *subject, uint32_t subject_length, const uint8_t *pubkey, uint32_t pubkey_length, bool *_retval) override { return _to IsCertRevoked(issuer, issuer_length, serial, serial_length, subject, subject_length, pubkey, pubkey_length, _retval); } \
  NS_IMETHOD IsBlocklistFresh(bool *_retval) override { return _to IsBlocklistFresh(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTBLOCKLIST(_to) \
  NS_IMETHOD RevokeCertByIssuerAndSerial(const char * issuer, const char * serialNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RevokeCertByIssuerAndSerial(issuer, serialNumber); } \
  NS_IMETHOD RevokeCertBySubjectAndPubKey(const char * subject, const char * pubKeyHash) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RevokeCertBySubjectAndPubKey(subject, pubKeyHash); } \
  NS_IMETHOD SaveEntries(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveEntries(); } \
  NS_IMETHOD IsCertRevoked(const uint8_t *issuer, uint32_t issuer_length, const uint8_t *serial, uint32_t serial_length, const uint8_t *subject, uint32_t subject_length, const uint8_t *pubkey, uint32_t pubkey_length, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCertRevoked(issuer, issuer_length, serial, serial_length, subject, subject_length, pubkey, pubkey_length, _retval); } \
  NS_IMETHOD IsBlocklistFresh(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsBlocklistFresh(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertBlocklist : public nsICertBlocklist
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTBLOCKLIST

  nsCertBlocklist();

private:
  ~nsCertBlocklist();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCertBlocklist, nsICertBlocklist)

nsCertBlocklist::nsCertBlocklist()
{
  /* member initializers and constructor code */
}

nsCertBlocklist::~nsCertBlocklist()
{
  /* destructor code */
}

/* void revokeCertByIssuerAndSerial (in string issuer, in string serialNumber); */
NS_IMETHODIMP nsCertBlocklist::RevokeCertByIssuerAndSerial(const char * issuer, const char * serialNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void revokeCertBySubjectAndPubKey (in string subject, in string pubKeyHash); */
NS_IMETHODIMP nsCertBlocklist::RevokeCertBySubjectAndPubKey(const char * subject, const char * pubKeyHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveEntries (); */
NS_IMETHODIMP nsCertBlocklist::SaveEntries()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCertRevoked ([array, size_is (issuer_length), const] in octet issuer, in unsigned long issuer_length, [array, size_is (serial_length), const] in octet serial, in unsigned long serial_length, [array, size_is (subject_length), const] in octet subject, in unsigned long subject_length, [array, size_is (pubkey_length), const] in octet pubkey, in unsigned long pubkey_length); */
NS_IMETHODIMP nsCertBlocklist::IsCertRevoked(const uint8_t *issuer, uint32_t issuer_length, const uint8_t *serial, uint32_t serial_length, const uint8_t *subject, uint32_t subject_length, const uint8_t *pubkey, uint32_t pubkey_length, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isBlocklistFresh (); */
NS_IMETHODIMP nsCertBlocklist::IsBlocklistFresh(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICertBlocklist_h__ */
