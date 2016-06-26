/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIX509Cert.idl
 */

#ifndef __gen_nsIX509Cert_h__
#define __gen_nsIX509Cert_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIX509CertValidity; /* forward declaration */

class nsIASN1Object; /* forward declaration */

class nsICertVerificationListener; /* forward declaration */

 /* forward declaration */
 typedef struct CERTCertificateStr CERTCertificate;

/* starting interface:    nsIX509Cert */
#define NS_IX509CERT_IID_STR "f8ed8364-ced9-4c6e-86ba-48af53c393e6"

#define NS_IX509CERT_IID \
  {0xf8ed8364, 0xced9, 0x4c6e, \
    { 0x86, 0xba, 0x48, 0xaf, 0x53, 0xc3, 0x93, 0xe6 }}

class NS_NO_VTABLE nsIX509Cert : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERT_IID)

  /* readonly attribute AString nickname; */
  NS_IMETHOD GetNickname(nsAString & aNickname) = 0;

  /* readonly attribute AString emailAddress; */
  NS_IMETHOD GetEmailAddress(nsAString & aEmailAddress) = 0;

  /* void getEmailAddresses (out unsigned long length, [array, size_is (length), retval] out wstring addresses); */
  NS_IMETHOD GetEmailAddresses(uint32_t *length, char16_t * **addresses) = 0;

  /* boolean containsEmailAddress (in AString aEmailAddress); */
  NS_IMETHOD ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval) = 0;

  /* readonly attribute AString subjectName; */
  NS_IMETHOD GetSubjectName(nsAString & aSubjectName) = 0;

  /* readonly attribute AString commonName; */
  NS_IMETHOD GetCommonName(nsAString & aCommonName) = 0;

  /* readonly attribute AString organization; */
  NS_IMETHOD GetOrganization(nsAString & aOrganization) = 0;

  /* readonly attribute AString organizationalUnit; */
  NS_IMETHOD GetOrganizationalUnit(nsAString & aOrganizationalUnit) = 0;

  /* readonly attribute AString sha256Fingerprint; */
  NS_IMETHOD GetSha256Fingerprint(nsAString & aSha256Fingerprint) = 0;

  /* readonly attribute AString sha1Fingerprint; */
  NS_IMETHOD GetSha1Fingerprint(nsAString & aSha1Fingerprint) = 0;

  /* readonly attribute AString tokenName; */
  NS_IMETHOD GetTokenName(nsAString & aTokenName) = 0;

  /* readonly attribute AString issuerName; */
  NS_IMETHOD GetIssuerName(nsAString & aIssuerName) = 0;

  /* readonly attribute AString serialNumber; */
  NS_IMETHOD GetSerialNumber(nsAString & aSerialNumber) = 0;

  /* readonly attribute AString issuerCommonName; */
  NS_IMETHOD GetIssuerCommonName(nsAString & aIssuerCommonName) = 0;

  /* readonly attribute AString issuerOrganization; */
  NS_IMETHOD GetIssuerOrganization(nsAString & aIssuerOrganization) = 0;

  /* readonly attribute AString issuerOrganizationUnit; */
  NS_IMETHOD GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit) = 0;

  /* readonly attribute nsIX509Cert issuer; */
  NS_IMETHOD GetIssuer(nsIX509Cert * *aIssuer) = 0;

  /* readonly attribute nsIX509CertValidity validity; */
  NS_IMETHOD GetValidity(nsIX509CertValidity * *aValidity) = 0;

  /* readonly attribute string dbKey; */
  NS_IMETHOD GetDbKey(char * *aDbKey) = 0;

  /* readonly attribute AString windowTitle; */
  NS_IMETHOD GetWindowTitle(nsAString & aWindowTitle) = 0;

  enum {
    UNKNOWN_CERT = 0U,
    CA_CERT = 1U,
    USER_CERT = 2U,
    EMAIL_CERT = 4U,
    SERVER_CERT = 8U,
    ANY_CERT = 65535U
  };

  /* readonly attribute unsigned long certType; */
  NS_IMETHOD GetCertType(uint32_t *aCertType) = 0;

  /* readonly attribute boolean isSelfSigned; */
  NS_IMETHOD GetIsSelfSigned(bool *aIsSelfSigned) = 0;

  enum {
    VERIFIED_OK = 0U,
    NOT_VERIFIED_UNKNOWN = 1U,
    CERT_REVOKED = 2U,
    CERT_EXPIRED = 4U,
    CERT_NOT_TRUSTED = 8U,
    ISSUER_NOT_TRUSTED = 16U,
    ISSUER_UNKNOWN = 32U,
    INVALID_CA = 64U,
    USAGE_NOT_ALLOWED = 128U,
    SIGNATURE_ALGORITHM_DISABLED = 256U,
    CERT_USAGE_SSLClient = 0U,
    CERT_USAGE_SSLServer = 1U,
    CERT_USAGE_SSLServerWithStepUp = 2U,
    CERT_USAGE_SSLCA = 3U,
    CERT_USAGE_EmailSigner = 4U,
    CERT_USAGE_EmailRecipient = 5U,
    CERT_USAGE_ObjectSigner = 6U,
    CERT_USAGE_UserCertImport = 7U,
    CERT_USAGE_VerifyCA = 8U,
    CERT_USAGE_ProtectedObjectSigner = 9U,
    CERT_USAGE_StatusResponder = 10U,
    CERT_USAGE_AnyCA = 11U,
    CMS_CHAIN_MODE_CertOnly = 1U,
    CMS_CHAIN_MODE_CertChain = 2U,
    CMS_CHAIN_MODE_CertChainWithRoot = 3U
  };

  /* nsIArray getChain (); */
  NS_IMETHOD GetChain(nsIArray * *_retval) = 0;

  /* void getUsagesArray (in boolean localOnly, out uint32_t verified, out uint32_t count, [array, size_is (count)] out wstring usages); */
  NS_IMETHOD GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages) = 0;

  /* void requestUsagesArrayAsync (in nsICertVerificationListener cvl); */
  NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) = 0;

  /* void getUsagesString (in boolean localOnly, out uint32_t verified, out AString usages); */
  NS_IMETHOD GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages) = 0;

  /* readonly attribute nsIASN1Object ASN1Structure; */
  NS_IMETHOD GetASN1Structure(nsIASN1Object * *aASN1Structure) = 0;

  /* void getRawDER (out unsigned long length, [array, size_is (length), retval] out octet data); */
  NS_IMETHOD GetRawDER(uint32_t *length, uint8_t **data) = 0;

  /* boolean equals (in nsIX509Cert other); */
  NS_IMETHOD Equals(nsIX509Cert *other, bool *_retval) = 0;

  /* readonly attribute ACString sha256SubjectPublicKeyInfoDigest; */
  NS_IMETHOD GetSha256SubjectPublicKeyInfoDigest(nsACString & aSha256SubjectPublicKeyInfoDigest) = 0;

  /* void exportAsCMS (in unsigned long chainMode, out unsigned long length, [array, size_is (length), retval] out octet data); */
  NS_IMETHOD ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data) = 0;

  /* [noscript,notxpcom] CERTCertificatePtr getCert (); */
  NS_IMETHOD_(CERTCertificate *) GetCert(void) = 0;

  /* void getAllTokenNames (out unsigned long length, [array, size_is (length), retval] out wstring tokenNames); */
  NS_IMETHOD GetAllTokenNames(uint32_t *length, char16_t * **tokenNames) = 0;

  /* void markForPermDeletion (); */
  NS_IMETHOD MarkForPermDeletion(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509Cert, NS_IX509CERT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERT \
  NS_IMETHOD GetNickname(nsAString & aNickname) override; \
  NS_IMETHOD GetEmailAddress(nsAString & aEmailAddress) override; \
  NS_IMETHOD GetEmailAddresses(uint32_t *length, char16_t * **addresses) override; \
  NS_IMETHOD ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval) override; \
  NS_IMETHOD GetSubjectName(nsAString & aSubjectName) override; \
  NS_IMETHOD GetCommonName(nsAString & aCommonName) override; \
  NS_IMETHOD GetOrganization(nsAString & aOrganization) override; \
  NS_IMETHOD GetOrganizationalUnit(nsAString & aOrganizationalUnit) override; \
  NS_IMETHOD GetSha256Fingerprint(nsAString & aSha256Fingerprint) override; \
  NS_IMETHOD GetSha1Fingerprint(nsAString & aSha1Fingerprint) override; \
  NS_IMETHOD GetTokenName(nsAString & aTokenName) override; \
  NS_IMETHOD GetIssuerName(nsAString & aIssuerName) override; \
  NS_IMETHOD GetSerialNumber(nsAString & aSerialNumber) override; \
  NS_IMETHOD GetIssuerCommonName(nsAString & aIssuerCommonName) override; \
  NS_IMETHOD GetIssuerOrganization(nsAString & aIssuerOrganization) override; \
  NS_IMETHOD GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit) override; \
  NS_IMETHOD GetIssuer(nsIX509Cert * *aIssuer) override; \
  NS_IMETHOD GetValidity(nsIX509CertValidity * *aValidity) override; \
  NS_IMETHOD GetDbKey(char * *aDbKey) override; \
  NS_IMETHOD GetWindowTitle(nsAString & aWindowTitle) override; \
  NS_IMETHOD GetCertType(uint32_t *aCertType) override; \
  NS_IMETHOD GetIsSelfSigned(bool *aIsSelfSigned) override; \
  NS_IMETHOD GetChain(nsIArray * *_retval) override; \
  NS_IMETHOD GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages) override; \
  NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) override; \
  NS_IMETHOD GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages) override; \
  NS_IMETHOD GetASN1Structure(nsIASN1Object * *aASN1Structure) override; \
  NS_IMETHOD GetRawDER(uint32_t *length, uint8_t **data) override; \
  NS_IMETHOD Equals(nsIX509Cert *other, bool *_retval) override; \
  NS_IMETHOD GetSha256SubjectPublicKeyInfoDigest(nsACString & aSha256SubjectPublicKeyInfoDigest) override; \
  NS_IMETHOD ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data) override; \
  NS_IMETHOD_(CERTCertificate *) GetCert(void) override; \
  NS_IMETHOD GetAllTokenNames(uint32_t *length, char16_t * **tokenNames) override; \
  NS_IMETHOD MarkForPermDeletion(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERT(_to) \
  NS_IMETHOD GetNickname(nsAString & aNickname) override { return _to GetNickname(aNickname); } \
  NS_IMETHOD GetEmailAddress(nsAString & aEmailAddress) override { return _to GetEmailAddress(aEmailAddress); } \
  NS_IMETHOD GetEmailAddresses(uint32_t *length, char16_t * **addresses) override { return _to GetEmailAddresses(length, addresses); } \
  NS_IMETHOD ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval) override { return _to ContainsEmailAddress(aEmailAddress, _retval); } \
  NS_IMETHOD GetSubjectName(nsAString & aSubjectName) override { return _to GetSubjectName(aSubjectName); } \
  NS_IMETHOD GetCommonName(nsAString & aCommonName) override { return _to GetCommonName(aCommonName); } \
  NS_IMETHOD GetOrganization(nsAString & aOrganization) override { return _to GetOrganization(aOrganization); } \
  NS_IMETHOD GetOrganizationalUnit(nsAString & aOrganizationalUnit) override { return _to GetOrganizationalUnit(aOrganizationalUnit); } \
  NS_IMETHOD GetSha256Fingerprint(nsAString & aSha256Fingerprint) override { return _to GetSha256Fingerprint(aSha256Fingerprint); } \
  NS_IMETHOD GetSha1Fingerprint(nsAString & aSha1Fingerprint) override { return _to GetSha1Fingerprint(aSha1Fingerprint); } \
  NS_IMETHOD GetTokenName(nsAString & aTokenName) override { return _to GetTokenName(aTokenName); } \
  NS_IMETHOD GetIssuerName(nsAString & aIssuerName) override { return _to GetIssuerName(aIssuerName); } \
  NS_IMETHOD GetSerialNumber(nsAString & aSerialNumber) override { return _to GetSerialNumber(aSerialNumber); } \
  NS_IMETHOD GetIssuerCommonName(nsAString & aIssuerCommonName) override { return _to GetIssuerCommonName(aIssuerCommonName); } \
  NS_IMETHOD GetIssuerOrganization(nsAString & aIssuerOrganization) override { return _to GetIssuerOrganization(aIssuerOrganization); } \
  NS_IMETHOD GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit) override { return _to GetIssuerOrganizationUnit(aIssuerOrganizationUnit); } \
  NS_IMETHOD GetIssuer(nsIX509Cert * *aIssuer) override { return _to GetIssuer(aIssuer); } \
  NS_IMETHOD GetValidity(nsIX509CertValidity * *aValidity) override { return _to GetValidity(aValidity); } \
  NS_IMETHOD GetDbKey(char * *aDbKey) override { return _to GetDbKey(aDbKey); } \
  NS_IMETHOD GetWindowTitle(nsAString & aWindowTitle) override { return _to GetWindowTitle(aWindowTitle); } \
  NS_IMETHOD GetCertType(uint32_t *aCertType) override { return _to GetCertType(aCertType); } \
  NS_IMETHOD GetIsSelfSigned(bool *aIsSelfSigned) override { return _to GetIsSelfSigned(aIsSelfSigned); } \
  NS_IMETHOD GetChain(nsIArray * *_retval) override { return _to GetChain(_retval); } \
  NS_IMETHOD GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages) override { return _to GetUsagesArray(localOnly, verified, count, usages); } \
  NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) override { return _to RequestUsagesArrayAsync(cvl); } \
  NS_IMETHOD GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages) override { return _to GetUsagesString(localOnly, verified, usages); } \
  NS_IMETHOD GetASN1Structure(nsIASN1Object * *aASN1Structure) override { return _to GetASN1Structure(aASN1Structure); } \
  NS_IMETHOD GetRawDER(uint32_t *length, uint8_t **data) override { return _to GetRawDER(length, data); } \
  NS_IMETHOD Equals(nsIX509Cert *other, bool *_retval) override { return _to Equals(other, _retval); } \
  NS_IMETHOD GetSha256SubjectPublicKeyInfoDigest(nsACString & aSha256SubjectPublicKeyInfoDigest) override { return _to GetSha256SubjectPublicKeyInfoDigest(aSha256SubjectPublicKeyInfoDigest); } \
  NS_IMETHOD ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data) override { return _to ExportAsCMS(chainMode, length, data); } \
  NS_IMETHOD_(CERTCertificate *) GetCert(void) override { return _to GetCert(); } \
  NS_IMETHOD GetAllTokenNames(uint32_t *length, char16_t * **tokenNames) override { return _to GetAllTokenNames(length, tokenNames); } \
  NS_IMETHOD MarkForPermDeletion(void) override { return _to MarkForPermDeletion(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERT(_to) \
  NS_IMETHOD GetNickname(nsAString & aNickname) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNickname(aNickname); } \
  NS_IMETHOD GetEmailAddress(nsAString & aEmailAddress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmailAddress(aEmailAddress); } \
  NS_IMETHOD GetEmailAddresses(uint32_t *length, char16_t * **addresses) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmailAddresses(length, addresses); } \
  NS_IMETHOD ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ContainsEmailAddress(aEmailAddress, _retval); } \
  NS_IMETHOD GetSubjectName(nsAString & aSubjectName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubjectName(aSubjectName); } \
  NS_IMETHOD GetCommonName(nsAString & aCommonName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommonName(aCommonName); } \
  NS_IMETHOD GetOrganization(nsAString & aOrganization) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrganization(aOrganization); } \
  NS_IMETHOD GetOrganizationalUnit(nsAString & aOrganizationalUnit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrganizationalUnit(aOrganizationalUnit); } \
  NS_IMETHOD GetSha256Fingerprint(nsAString & aSha256Fingerprint) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSha256Fingerprint(aSha256Fingerprint); } \
  NS_IMETHOD GetSha1Fingerprint(nsAString & aSha1Fingerprint) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSha1Fingerprint(aSha1Fingerprint); } \
  NS_IMETHOD GetTokenName(nsAString & aTokenName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTokenName(aTokenName); } \
  NS_IMETHOD GetIssuerName(nsAString & aIssuerName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuerName(aIssuerName); } \
  NS_IMETHOD GetSerialNumber(nsAString & aSerialNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSerialNumber(aSerialNumber); } \
  NS_IMETHOD GetIssuerCommonName(nsAString & aIssuerCommonName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuerCommonName(aIssuerCommonName); } \
  NS_IMETHOD GetIssuerOrganization(nsAString & aIssuerOrganization) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuerOrganization(aIssuerOrganization); } \
  NS_IMETHOD GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuerOrganizationUnit(aIssuerOrganizationUnit); } \
  NS_IMETHOD GetIssuer(nsIX509Cert * *aIssuer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIssuer(aIssuer); } \
  NS_IMETHOD GetValidity(nsIX509CertValidity * *aValidity) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidity(aValidity); } \
  NS_IMETHOD GetDbKey(char * *aDbKey) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDbKey(aDbKey); } \
  NS_IMETHOD GetWindowTitle(nsAString & aWindowTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowTitle(aWindowTitle); } \
  NS_IMETHOD GetCertType(uint32_t *aCertType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertType(aCertType); } \
  NS_IMETHOD GetIsSelfSigned(bool *aIsSelfSigned) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSelfSigned(aIsSelfSigned); } \
  NS_IMETHOD GetChain(nsIArray * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChain(_retval); } \
  NS_IMETHOD GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsagesArray(localOnly, verified, count, usages); } \
  NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestUsagesArrayAsync(cvl); } \
  NS_IMETHOD GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsagesString(localOnly, verified, usages); } \
  NS_IMETHOD GetASN1Structure(nsIASN1Object * *aASN1Structure) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetASN1Structure(aASN1Structure); } \
  NS_IMETHOD GetRawDER(uint32_t *length, uint8_t **data) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRawDER(length, data); } \
  NS_IMETHOD Equals(nsIX509Cert *other, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(other, _retval); } \
  NS_IMETHOD GetSha256SubjectPublicKeyInfoDigest(nsACString & aSha256SubjectPublicKeyInfoDigest) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSha256SubjectPublicKeyInfoDigest(aSha256SubjectPublicKeyInfoDigest); } \
  NS_IMETHOD ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExportAsCMS(chainMode, length, data); } \
  NS_IMETHOD_(CERTCertificate *) GetCert(void) override; \
  NS_IMETHOD GetAllTokenNames(uint32_t *length, char16_t * **tokenNames) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllTokenNames(length, tokenNames); } \
  NS_IMETHOD MarkForPermDeletion(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkForPermDeletion(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509Cert : public nsIX509Cert
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERT

  nsX509Cert();

private:
  ~nsX509Cert();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsX509Cert, nsIX509Cert)

nsX509Cert::nsX509Cert()
{
  /* member initializers and constructor code */
}

nsX509Cert::~nsX509Cert()
{
  /* destructor code */
}

/* readonly attribute AString nickname; */
NS_IMETHODIMP nsX509Cert::GetNickname(nsAString & aNickname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString emailAddress; */
NS_IMETHODIMP nsX509Cert::GetEmailAddress(nsAString & aEmailAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getEmailAddresses (out unsigned long length, [array, size_is (length), retval] out wstring addresses); */
NS_IMETHODIMP nsX509Cert::GetEmailAddresses(uint32_t *length, char16_t * **addresses)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean containsEmailAddress (in AString aEmailAddress); */
NS_IMETHODIMP nsX509Cert::ContainsEmailAddress(const nsAString & aEmailAddress, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString subjectName; */
NS_IMETHODIMP nsX509Cert::GetSubjectName(nsAString & aSubjectName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString commonName; */
NS_IMETHODIMP nsX509Cert::GetCommonName(nsAString & aCommonName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString organization; */
NS_IMETHODIMP nsX509Cert::GetOrganization(nsAString & aOrganization)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString organizationalUnit; */
NS_IMETHODIMP nsX509Cert::GetOrganizationalUnit(nsAString & aOrganizationalUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString sha256Fingerprint; */
NS_IMETHODIMP nsX509Cert::GetSha256Fingerprint(nsAString & aSha256Fingerprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString sha1Fingerprint; */
NS_IMETHODIMP nsX509Cert::GetSha1Fingerprint(nsAString & aSha1Fingerprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString tokenName; */
NS_IMETHODIMP nsX509Cert::GetTokenName(nsAString & aTokenName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString issuerName; */
NS_IMETHODIMP nsX509Cert::GetIssuerName(nsAString & aIssuerName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString serialNumber; */
NS_IMETHODIMP nsX509Cert::GetSerialNumber(nsAString & aSerialNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString issuerCommonName; */
NS_IMETHODIMP nsX509Cert::GetIssuerCommonName(nsAString & aIssuerCommonName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString issuerOrganization; */
NS_IMETHODIMP nsX509Cert::GetIssuerOrganization(nsAString & aIssuerOrganization)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString issuerOrganizationUnit; */
NS_IMETHODIMP nsX509Cert::GetIssuerOrganizationUnit(nsAString & aIssuerOrganizationUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIX509Cert issuer; */
NS_IMETHODIMP nsX509Cert::GetIssuer(nsIX509Cert * *aIssuer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIX509CertValidity validity; */
NS_IMETHODIMP nsX509Cert::GetValidity(nsIX509CertValidity * *aValidity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string dbKey; */
NS_IMETHODIMP nsX509Cert::GetDbKey(char * *aDbKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString windowTitle; */
NS_IMETHODIMP nsX509Cert::GetWindowTitle(nsAString & aWindowTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long certType; */
NS_IMETHODIMP nsX509Cert::GetCertType(uint32_t *aCertType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSelfSigned; */
NS_IMETHODIMP nsX509Cert::GetIsSelfSigned(bool *aIsSelfSigned)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getChain (); */
NS_IMETHODIMP nsX509Cert::GetChain(nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getUsagesArray (in boolean localOnly, out uint32_t verified, out uint32_t count, [array, size_is (count)] out wstring usages); */
NS_IMETHODIMP nsX509Cert::GetUsagesArray(bool localOnly, uint32_t *verified, uint32_t *count, char16_t * **usages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestUsagesArrayAsync (in nsICertVerificationListener cvl); */
NS_IMETHODIMP nsX509Cert::RequestUsagesArrayAsync(nsICertVerificationListener *cvl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getUsagesString (in boolean localOnly, out uint32_t verified, out AString usages); */
NS_IMETHODIMP nsX509Cert::GetUsagesString(bool localOnly, uint32_t *verified, nsAString & usages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIASN1Object ASN1Structure; */
NS_IMETHODIMP nsX509Cert::GetASN1Structure(nsIASN1Object * *aASN1Structure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRawDER (out unsigned long length, [array, size_is (length), retval] out octet data); */
NS_IMETHODIMP nsX509Cert::GetRawDER(uint32_t *length, uint8_t **data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIX509Cert other); */
NS_IMETHODIMP nsX509Cert::Equals(nsIX509Cert *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString sha256SubjectPublicKeyInfoDigest; */
NS_IMETHODIMP nsX509Cert::GetSha256SubjectPublicKeyInfoDigest(nsACString & aSha256SubjectPublicKeyInfoDigest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exportAsCMS (in unsigned long chainMode, out unsigned long length, [array, size_is (length), retval] out octet data); */
NS_IMETHODIMP nsX509Cert::ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] CERTCertificatePtr getCert (); */
NS_IMETHODIMP_(CERTCertificate *) nsX509Cert::GetCert()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllTokenNames (out unsigned long length, [array, size_is (length), retval] out wstring tokenNames); */
NS_IMETHODIMP nsX509Cert::GetAllTokenNames(uint32_t *length, char16_t * **tokenNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markForPermDeletion (); */
NS_IMETHODIMP nsX509Cert::MarkForPermDeletion()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICertVerificationResult */
#define NS_ICERTVERIFICATIONRESULT_IID_STR "2fd0a785-9f2d-4327-8871-8c3e0783891d"

#define NS_ICERTVERIFICATIONRESULT_IID \
  {0x2fd0a785, 0x9f2d, 0x4327, \
    { 0x88, 0x71, 0x8c, 0x3e, 0x07, 0x83, 0x89, 0x1d }}

class NS_NO_VTABLE nsICertVerificationResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTVERIFICATIONRESULT_IID)

  /* void getUsagesArrayResult (out uint32_t verified, out uint32_t count, [array, size_is (count)] out wstring usages); */
  NS_IMETHOD GetUsagesArrayResult(uint32_t *verified, uint32_t *count, char16_t * **usages) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertVerificationResult, NS_ICERTVERIFICATIONRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTVERIFICATIONRESULT \
  NS_IMETHOD GetUsagesArrayResult(uint32_t *verified, uint32_t *count, char16_t * **usages) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTVERIFICATIONRESULT(_to) \
  NS_IMETHOD GetUsagesArrayResult(uint32_t *verified, uint32_t *count, char16_t * **usages) override { return _to GetUsagesArrayResult(verified, count, usages); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTVERIFICATIONRESULT(_to) \
  NS_IMETHOD GetUsagesArrayResult(uint32_t *verified, uint32_t *count, char16_t * **usages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsagesArrayResult(verified, count, usages); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertVerificationResult : public nsICertVerificationResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTVERIFICATIONRESULT

  nsCertVerificationResult();

private:
  ~nsCertVerificationResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCertVerificationResult, nsICertVerificationResult)

nsCertVerificationResult::nsCertVerificationResult()
{
  /* member initializers and constructor code */
}

nsCertVerificationResult::~nsCertVerificationResult()
{
  /* destructor code */
}

/* void getUsagesArrayResult (out uint32_t verified, out uint32_t count, [array, size_is (count)] out wstring usages); */
NS_IMETHODIMP nsCertVerificationResult::GetUsagesArrayResult(uint32_t *verified, uint32_t *count, char16_t * **usages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICertVerificationListener */
#define NS_ICERTVERIFICATIONLISTENER_IID_STR "6684bce9-50db-48e1-81b7-98102bf81357"

#define NS_ICERTVERIFICATIONLISTENER_IID \
  {0x6684bce9, 0x50db, 0x48e1, \
    { 0x81, 0xb7, 0x98, 0x10, 0x2b, 0xf8, 0x13, 0x57 }}

class NS_NO_VTABLE nsICertVerificationListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTVERIFICATIONLISTENER_IID)

  /* void notify (in nsIX509Cert verifiedCert, in nsICertVerificationResult result); */
  NS_IMETHOD Notify(nsIX509Cert *verifiedCert, nsICertVerificationResult *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertVerificationListener, NS_ICERTVERIFICATIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTVERIFICATIONLISTENER \
  NS_IMETHOD Notify(nsIX509Cert *verifiedCert, nsICertVerificationResult *result) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTVERIFICATIONLISTENER(_to) \
  NS_IMETHOD Notify(nsIX509Cert *verifiedCert, nsICertVerificationResult *result) override { return _to Notify(verifiedCert, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTVERIFICATIONLISTENER(_to) \
  NS_IMETHOD Notify(nsIX509Cert *verifiedCert, nsICertVerificationResult *result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Notify(verifiedCert, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertVerificationListener : public nsICertVerificationListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTVERIFICATIONLISTENER

  nsCertVerificationListener();

private:
  ~nsCertVerificationListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCertVerificationListener, nsICertVerificationListener)

nsCertVerificationListener::nsCertVerificationListener()
{
  /* member initializers and constructor code */
}

nsCertVerificationListener::~nsCertVerificationListener()
{
  /* destructor code */
}

/* void notify (in nsIX509Cert verifiedCert, in nsICertVerificationResult result); */
NS_IMETHODIMP nsCertVerificationListener::Notify(nsIX509Cert *verifiedCert, nsICertVerificationResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIX509Cert_h__ */
