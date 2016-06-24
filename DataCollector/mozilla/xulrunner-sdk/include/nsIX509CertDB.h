/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIX509CertDB.idl
 */

#ifndef __gen_nsIX509CertDB_h__
#define __gen_nsIX509CertDB_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIX509Cert; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

class nsIZipReader; /* forward declaration */

class nsIX509CertList; /* forward declaration */

class nsIInputStream; /* forward declaration */

#define NS_X509CERTDB_CONTRACTID "@mozilla.org/security/x509certdb;1"
typedef uint32_t  AppTrustedRoot;


/* starting interface:    nsIOpenSignedAppFileCallback */
#define NS_IOPENSIGNEDAPPFILECALLBACK_IID_STR "fc2b60e5-9a07-47c2-a2cd-b83b68a660ac"

#define NS_IOPENSIGNEDAPPFILECALLBACK_IID \
  {0xfc2b60e5, 0x9a07, 0x47c2, \
    { 0xa2, 0xcd, 0xb8, 0x3b, 0x68, 0xa6, 0x60, 0xac }}

class NS_NO_VTABLE nsIOpenSignedAppFileCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOPENSIGNEDAPPFILECALLBACK_IID)

  /* void openSignedAppFileFinished (in nsresult rv, in nsIZipReader aZipReader, in nsIX509Cert aSignerCert); */
  NS_IMETHOD OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert *aSignerCert) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOpenSignedAppFileCallback, NS_IOPENSIGNEDAPPFILECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOPENSIGNEDAPPFILECALLBACK \
  NS_IMETHOD OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert *aSignerCert) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOPENSIGNEDAPPFILECALLBACK(_to) \
  NS_IMETHOD OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert *aSignerCert) override { return _to OpenSignedAppFileFinished(rv, aZipReader, aSignerCert); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOPENSIGNEDAPPFILECALLBACK(_to) \
  NS_IMETHOD OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert *aSignerCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenSignedAppFileFinished(rv, aZipReader, aSignerCert); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOpenSignedAppFileCallback : public nsIOpenSignedAppFileCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOPENSIGNEDAPPFILECALLBACK

  nsOpenSignedAppFileCallback();

private:
  ~nsOpenSignedAppFileCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsOpenSignedAppFileCallback, nsIOpenSignedAppFileCallback)

nsOpenSignedAppFileCallback::nsOpenSignedAppFileCallback()
{
  /* member initializers and constructor code */
}

nsOpenSignedAppFileCallback::~nsOpenSignedAppFileCallback()
{
  /* destructor code */
}

/* void openSignedAppFileFinished (in nsresult rv, in nsIZipReader aZipReader, in nsIX509Cert aSignerCert); */
NS_IMETHODIMP nsOpenSignedAppFileCallback::OpenSignedAppFileFinished(nsresult rv, nsIZipReader *aZipReader, nsIX509Cert *aSignerCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIVerifySignedDirectoryCallback */
#define NS_IVERIFYSIGNEDDIRECTORYCALLBACK_IID_STR "d5f97827-622a-488f-be08-d850432ac8ec"

#define NS_IVERIFYSIGNEDDIRECTORYCALLBACK_IID \
  {0xd5f97827, 0x622a, 0x488f, \
    { 0xbe, 0x08, 0xd8, 0x50, 0x43, 0x2a, 0xc8, 0xec }}

class NS_NO_VTABLE nsIVerifySignedDirectoryCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVERIFYSIGNEDDIRECTORYCALLBACK_IID)

  /* void verifySignedDirectoryFinished (in nsresult rv, in nsIX509Cert aSignerCert); */
  NS_IMETHOD VerifySignedDirectoryFinished(nsresult rv, nsIX509Cert *aSignerCert) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVerifySignedDirectoryCallback, NS_IVERIFYSIGNEDDIRECTORYCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVERIFYSIGNEDDIRECTORYCALLBACK \
  NS_IMETHOD VerifySignedDirectoryFinished(nsresult rv, nsIX509Cert *aSignerCert) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVERIFYSIGNEDDIRECTORYCALLBACK(_to) \
  NS_IMETHOD VerifySignedDirectoryFinished(nsresult rv, nsIX509Cert *aSignerCert) override { return _to VerifySignedDirectoryFinished(rv, aSignerCert); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVERIFYSIGNEDDIRECTORYCALLBACK(_to) \
  NS_IMETHOD VerifySignedDirectoryFinished(nsresult rv, nsIX509Cert *aSignerCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifySignedDirectoryFinished(rv, aSignerCert); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVerifySignedDirectoryCallback : public nsIVerifySignedDirectoryCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVERIFYSIGNEDDIRECTORYCALLBACK

  nsVerifySignedDirectoryCallback();

private:
  ~nsVerifySignedDirectoryCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsVerifySignedDirectoryCallback, nsIVerifySignedDirectoryCallback)

nsVerifySignedDirectoryCallback::nsVerifySignedDirectoryCallback()
{
  /* member initializers and constructor code */
}

nsVerifySignedDirectoryCallback::~nsVerifySignedDirectoryCallback()
{
  /* destructor code */
}

/* void verifySignedDirectoryFinished (in nsresult rv, in nsIX509Cert aSignerCert); */
NS_IMETHODIMP nsVerifySignedDirectoryCallback::VerifySignedDirectoryFinished(nsresult rv, nsIX509Cert *aSignerCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIVerifySignedManifestCallback */
#define NS_IVERIFYSIGNEDMANIFESTCALLBACK_IID_STR "3d6a9c87-5c5f-46fc-9410-96da6092f0f2"

#define NS_IVERIFYSIGNEDMANIFESTCALLBACK_IID \
  {0x3d6a9c87, 0x5c5f, 0x46fc, \
    { 0x94, 0x10, 0x96, 0xda, 0x60, 0x92, 0xf0, 0xf2 }}

class NS_NO_VTABLE nsIVerifySignedManifestCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVERIFYSIGNEDMANIFESTCALLBACK_IID)

  /* void verifySignedManifestFinished (in nsresult rv, in nsIX509Cert aSignerCert); */
  NS_IMETHOD VerifySignedManifestFinished(nsresult rv, nsIX509Cert *aSignerCert) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVerifySignedManifestCallback, NS_IVERIFYSIGNEDMANIFESTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVERIFYSIGNEDMANIFESTCALLBACK \
  NS_IMETHOD VerifySignedManifestFinished(nsresult rv, nsIX509Cert *aSignerCert) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVERIFYSIGNEDMANIFESTCALLBACK(_to) \
  NS_IMETHOD VerifySignedManifestFinished(nsresult rv, nsIX509Cert *aSignerCert) override { return _to VerifySignedManifestFinished(rv, aSignerCert); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVERIFYSIGNEDMANIFESTCALLBACK(_to) \
  NS_IMETHOD VerifySignedManifestFinished(nsresult rv, nsIX509Cert *aSignerCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifySignedManifestFinished(rv, aSignerCert); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVerifySignedManifestCallback : public nsIVerifySignedManifestCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVERIFYSIGNEDMANIFESTCALLBACK

  nsVerifySignedManifestCallback();

private:
  ~nsVerifySignedManifestCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsVerifySignedManifestCallback, nsIVerifySignedManifestCallback)

nsVerifySignedManifestCallback::nsVerifySignedManifestCallback()
{
  /* member initializers and constructor code */
}

nsVerifySignedManifestCallback::~nsVerifySignedManifestCallback()
{
  /* destructor code */
}

/* void verifySignedManifestFinished (in nsresult rv, in nsIX509Cert aSignerCert); */
NS_IMETHODIMP nsVerifySignedManifestCallback::VerifySignedManifestFinished(nsresult rv, nsIX509Cert *aSignerCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIX509CertDB */
#define NS_IX509CERTDB_IID_STR "fbe2a0c8-ec51-4ea4-80b3-e16793141967"

#define NS_IX509CERTDB_IID \
  {0xfbe2a0c8, 0xec51, 0x4ea4, \
    { 0x80, 0xb3, 0xe1, 0x67, 0x93, 0x14, 0x19, 0x67 }}

class NS_NO_VTABLE nsIX509CertDB : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERTDB_IID)

  enum {
    UNTRUSTED = 0U,
    TRUSTED_SSL = 1U,
    TRUSTED_EMAIL = 2U,
    TRUSTED_OBJSIGN = 4U
  };

  /* nsIX509Cert findCertByNickname (in nsISupports aToken, in AString aNickname); */
  NS_IMETHOD FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval) = 0;

  /* nsIX509Cert findCertByDBKey (in string aDBkey, in nsISupports aToken); */
  NS_IMETHOD FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval) = 0;

  /* void findCertNicknames (in nsISupports aToken, in unsigned long aType, out unsigned long count, [array, size_is (count)] out wstring certNameList); */
  NS_IMETHOD FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList) = 0;

  /* nsIX509Cert findEmailEncryptionCert (in AString aNickname); */
  NS_IMETHOD FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval) = 0;

  /* nsIX509Cert findEmailSigningCert (in AString aNickname); */
  NS_IMETHOD FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval) = 0;

  /* nsIX509Cert findCertByEmailAddress (in nsISupports aToken, in string aEmailAddress); */
  NS_IMETHOD FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval) = 0;

  /* void importCertificates ([array, size_is (length)] in octet data, in unsigned long length, in unsigned long type, in nsIInterfaceRequestor ctx); */
  NS_IMETHOD ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx) = 0;

  /* void importEmailCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
  NS_IMETHOD ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) = 0;

  /* void importServerCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
  NS_IMETHOD ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) = 0;

  /* void importUserCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
  NS_IMETHOD ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) = 0;

  /* void deleteCertificate (in nsIX509Cert aCert); */
  NS_IMETHOD DeleteCertificate(nsIX509Cert *aCert) = 0;

  /* void setCertTrust (in nsIX509Cert cert, in unsigned long type, in unsigned long trust); */
  NS_IMETHOD SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust) = 0;

  /* void setCertTrustFromString (in nsIX509Cert cert, in string trustString); */
  NS_IMETHOD SetCertTrustFromString(nsIX509Cert *cert, const char * trustString) = 0;

  /* boolean isCertTrusted (in nsIX509Cert cert, in unsigned long certType, in unsigned long trustType); */
  NS_IMETHOD IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval) = 0;

  /* void importCertsFromFile (in nsISupports aToken, in nsIFile aFile, in unsigned long aType); */
  NS_IMETHOD ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType) = 0;

  /* void importPKCS12File (in nsISupports aToken, in nsIFile aFile); */
  NS_IMETHOD ImportPKCS12File(nsISupports *aToken, nsIFile *aFile) = 0;

  /* void exportPKCS12File (in nsISupports aToken, in nsIFile aFile, in unsigned long count, [array, size_is (count)] in nsIX509Cert aCerts); */
  NS_IMETHOD ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts) = 0;

  /* nsIX509Cert constructX509FromBase64 (in string base64); */
  NS_IMETHOD ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval) = 0;

  /* nsIX509Cert constructX509 (in string certDER, in unsigned long length); */
  NS_IMETHOD ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval) = 0;

  enum {
    AppMarketplaceProdPublicRoot = 1U,
    AppMarketplaceProdReviewersRoot = 2U,
    AppMarketplaceDevPublicRoot = 3U,
    AppMarketplaceDevReviewersRoot = 4U,
    AppMarketplaceStageRoot = 5U,
    AppXPCShellRoot = 6U,
    TrustedHostedAppPublicRoot = 7U,
    TrustedHostedAppTestRoot = 8U,
    AddonsPublicRoot = 9U,
    AddonsStageRoot = 10U
  };

  /* void openSignedAppFileAsync (in AppTrustedRoot trustedRoot, in nsIFile aJarFile, in nsIOpenSignedAppFileCallback callback); */
  NS_IMETHOD OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback) = 0;

  /* void verifySignedDirectoryAsync (in AppTrustedRoot trustedRoot, in nsIFile aUnpackedDir, in nsIVerifySignedDirectoryCallback callback); */
  NS_IMETHOD VerifySignedDirectoryAsync(AppTrustedRoot trustedRoot, nsIFile *aUnpackedDir, nsIVerifySignedDirectoryCallback *callback) = 0;

  /* void verifySignedManifestAsync (in AppTrustedRoot trustedRoot, in nsIInputStream aManifestStream, in nsIInputStream aSignatureStream, in nsIVerifySignedManifestCallback callback); */
  NS_IMETHOD VerifySignedManifestAsync(AppTrustedRoot trustedRoot, nsIInputStream *aManifestStream, nsIInputStream *aSignatureStream, nsIVerifySignedManifestCallback *callback) = 0;

  /* void addCert (in ACString certDER, in string aTrust, in string aName); */
  NS_IMETHOD AddCert(const nsACString & certDER, const char * aTrust, const char * aName) = 0;

  enum {
    FLAG_LOCAL_ONLY = 1U,
    FLAG_MUST_BE_EV = 2U
  };

  /* int32_t verifyCertNow (in nsIX509Cert aCert, in int64_t aUsage, in uint32_t aFlags, in string aHostname, out nsIX509CertList aVerifiedChain, out bool aHasEVPolicy); */
  NS_IMETHOD VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, const char * aHostname, nsIX509CertList * *aVerifiedChain, bool *aHasEVPolicy, int32_t *_retval) = 0;

  /* void clearOCSPCache (); */
  NS_IMETHOD ClearOCSPCache(void) = 0;

  /* void addCertFromBase64 (in string base64, in string aTrust, in string aName); */
  NS_IMETHOD AddCertFromBase64(const char * base64, const char * aTrust, const char * aName) = 0;

  /* nsIX509CertList getCerts (); */
  NS_IMETHOD GetCerts(nsIX509CertList * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509CertDB, NS_IX509CERTDB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERTDB \
  NS_IMETHOD FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval) override; \
  NS_IMETHOD FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval) override; \
  NS_IMETHOD FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList) override; \
  NS_IMETHOD FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval) override; \
  NS_IMETHOD FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval) override; \
  NS_IMETHOD FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval) override; \
  NS_IMETHOD ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx) override; \
  NS_IMETHOD ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) override; \
  NS_IMETHOD ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) override; \
  NS_IMETHOD ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) override; \
  NS_IMETHOD DeleteCertificate(nsIX509Cert *aCert) override; \
  NS_IMETHOD SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust) override; \
  NS_IMETHOD SetCertTrustFromString(nsIX509Cert *cert, const char * trustString) override; \
  NS_IMETHOD IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval) override; \
  NS_IMETHOD ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType) override; \
  NS_IMETHOD ImportPKCS12File(nsISupports *aToken, nsIFile *aFile) override; \
  NS_IMETHOD ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts) override; \
  NS_IMETHOD ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval) override; \
  NS_IMETHOD ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval) override; \
  NS_IMETHOD OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback) override; \
  NS_IMETHOD VerifySignedDirectoryAsync(AppTrustedRoot trustedRoot, nsIFile *aUnpackedDir, nsIVerifySignedDirectoryCallback *callback) override; \
  NS_IMETHOD VerifySignedManifestAsync(AppTrustedRoot trustedRoot, nsIInputStream *aManifestStream, nsIInputStream *aSignatureStream, nsIVerifySignedManifestCallback *callback) override; \
  NS_IMETHOD AddCert(const nsACString & certDER, const char * aTrust, const char * aName) override; \
  NS_IMETHOD VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, const char * aHostname, nsIX509CertList * *aVerifiedChain, bool *aHasEVPolicy, int32_t *_retval) override; \
  NS_IMETHOD ClearOCSPCache(void) override; \
  NS_IMETHOD AddCertFromBase64(const char * base64, const char * aTrust, const char * aName) override; \
  NS_IMETHOD GetCerts(nsIX509CertList * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERTDB(_to) \
  NS_IMETHOD FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval) override { return _to FindCertByNickname(aToken, aNickname, _retval); } \
  NS_IMETHOD FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval) override { return _to FindCertByDBKey(aDBkey, aToken, _retval); } \
  NS_IMETHOD FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList) override { return _to FindCertNicknames(aToken, aType, count, certNameList); } \
  NS_IMETHOD FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval) override { return _to FindEmailEncryptionCert(aNickname, _retval); } \
  NS_IMETHOD FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval) override { return _to FindEmailSigningCert(aNickname, _retval); } \
  NS_IMETHOD FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval) override { return _to FindCertByEmailAddress(aToken, aEmailAddress, _retval); } \
  NS_IMETHOD ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx) override { return _to ImportCertificates(data, length, type, ctx); } \
  NS_IMETHOD ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) override { return _to ImportEmailCertificate(data, length, ctx); } \
  NS_IMETHOD ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) override { return _to ImportServerCertificate(data, length, ctx); } \
  NS_IMETHOD ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) override { return _to ImportUserCertificate(data, length, ctx); } \
  NS_IMETHOD DeleteCertificate(nsIX509Cert *aCert) override { return _to DeleteCertificate(aCert); } \
  NS_IMETHOD SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust) override { return _to SetCertTrust(cert, type, trust); } \
  NS_IMETHOD SetCertTrustFromString(nsIX509Cert *cert, const char * trustString) override { return _to SetCertTrustFromString(cert, trustString); } \
  NS_IMETHOD IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval) override { return _to IsCertTrusted(cert, certType, trustType, _retval); } \
  NS_IMETHOD ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType) override { return _to ImportCertsFromFile(aToken, aFile, aType); } \
  NS_IMETHOD ImportPKCS12File(nsISupports *aToken, nsIFile *aFile) override { return _to ImportPKCS12File(aToken, aFile); } \
  NS_IMETHOD ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts) override { return _to ExportPKCS12File(aToken, aFile, count, aCerts); } \
  NS_IMETHOD ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval) override { return _to ConstructX509FromBase64(base64, _retval); } \
  NS_IMETHOD ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval) override { return _to ConstructX509(certDER, length, _retval); } \
  NS_IMETHOD OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback) override { return _to OpenSignedAppFileAsync(trustedRoot, aJarFile, callback); } \
  NS_IMETHOD VerifySignedDirectoryAsync(AppTrustedRoot trustedRoot, nsIFile *aUnpackedDir, nsIVerifySignedDirectoryCallback *callback) override { return _to VerifySignedDirectoryAsync(trustedRoot, aUnpackedDir, callback); } \
  NS_IMETHOD VerifySignedManifestAsync(AppTrustedRoot trustedRoot, nsIInputStream *aManifestStream, nsIInputStream *aSignatureStream, nsIVerifySignedManifestCallback *callback) override { return _to VerifySignedManifestAsync(trustedRoot, aManifestStream, aSignatureStream, callback); } \
  NS_IMETHOD AddCert(const nsACString & certDER, const char * aTrust, const char * aName) override { return _to AddCert(certDER, aTrust, aName); } \
  NS_IMETHOD VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, const char * aHostname, nsIX509CertList * *aVerifiedChain, bool *aHasEVPolicy, int32_t *_retval) override { return _to VerifyCertNow(aCert, aUsage, aFlags, aHostname, aVerifiedChain, aHasEVPolicy, _retval); } \
  NS_IMETHOD ClearOCSPCache(void) override { return _to ClearOCSPCache(); } \
  NS_IMETHOD AddCertFromBase64(const char * base64, const char * aTrust, const char * aName) override { return _to AddCertFromBase64(base64, aTrust, aName); } \
  NS_IMETHOD GetCerts(nsIX509CertList * *_retval) override { return _to GetCerts(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERTDB(_to) \
  NS_IMETHOD FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCertByNickname(aToken, aNickname, _retval); } \
  NS_IMETHOD FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCertByDBKey(aDBkey, aToken, _retval); } \
  NS_IMETHOD FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCertNicknames(aToken, aType, count, certNameList); } \
  NS_IMETHOD FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEmailEncryptionCert(aNickname, _retval); } \
  NS_IMETHOD FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEmailSigningCert(aNickname, _retval); } \
  NS_IMETHOD FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCertByEmailAddress(aToken, aEmailAddress, _retval); } \
  NS_IMETHOD ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportCertificates(data, length, type, ctx); } \
  NS_IMETHOD ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportEmailCertificate(data, length, ctx); } \
  NS_IMETHOD ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportServerCertificate(data, length, ctx); } \
  NS_IMETHOD ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportUserCertificate(data, length, ctx); } \
  NS_IMETHOD DeleteCertificate(nsIX509Cert *aCert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteCertificate(aCert); } \
  NS_IMETHOD SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCertTrust(cert, type, trust); } \
  NS_IMETHOD SetCertTrustFromString(nsIX509Cert *cert, const char * trustString) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCertTrustFromString(cert, trustString); } \
  NS_IMETHOD IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCertTrusted(cert, certType, trustType, _retval); } \
  NS_IMETHOD ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportCertsFromFile(aToken, aFile, aType); } \
  NS_IMETHOD ImportPKCS12File(nsISupports *aToken, nsIFile *aFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportPKCS12File(aToken, aFile); } \
  NS_IMETHOD ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExportPKCS12File(aToken, aFile, count, aCerts); } \
  NS_IMETHOD ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ConstructX509FromBase64(base64, _retval); } \
  NS_IMETHOD ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ConstructX509(certDER, length, _retval); } \
  NS_IMETHOD OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenSignedAppFileAsync(trustedRoot, aJarFile, callback); } \
  NS_IMETHOD VerifySignedDirectoryAsync(AppTrustedRoot trustedRoot, nsIFile *aUnpackedDir, nsIVerifySignedDirectoryCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifySignedDirectoryAsync(trustedRoot, aUnpackedDir, callback); } \
  NS_IMETHOD VerifySignedManifestAsync(AppTrustedRoot trustedRoot, nsIInputStream *aManifestStream, nsIInputStream *aSignatureStream, nsIVerifySignedManifestCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifySignedManifestAsync(trustedRoot, aManifestStream, aSignatureStream, callback); } \
  NS_IMETHOD AddCert(const nsACString & certDER, const char * aTrust, const char * aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCert(certDER, aTrust, aName); } \
  NS_IMETHOD VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, const char * aHostname, nsIX509CertList * *aVerifiedChain, bool *aHasEVPolicy, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifyCertNow(aCert, aUsage, aFlags, aHostname, aVerifiedChain, aHasEVPolicy, _retval); } \
  NS_IMETHOD ClearOCSPCache(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearOCSPCache(); } \
  NS_IMETHOD AddCertFromBase64(const char * base64, const char * aTrust, const char * aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCertFromBase64(base64, aTrust, aName); } \
  NS_IMETHOD GetCerts(nsIX509CertList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCerts(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509CertDB : public nsIX509CertDB
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERTDB

  nsX509CertDB();

private:
  ~nsX509CertDB();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsX509CertDB, nsIX509CertDB)

nsX509CertDB::nsX509CertDB()
{
  /* member initializers and constructor code */
}

nsX509CertDB::~nsX509CertDB()
{
  /* destructor code */
}

/* nsIX509Cert findCertByNickname (in nsISupports aToken, in AString aNickname); */
NS_IMETHODIMP nsX509CertDB::FindCertByNickname(nsISupports *aToken, const nsAString & aNickname, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert findCertByDBKey (in string aDBkey, in nsISupports aToken); */
NS_IMETHODIMP nsX509CertDB::FindCertByDBKey(const char * aDBkey, nsISupports *aToken, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void findCertNicknames (in nsISupports aToken, in unsigned long aType, out unsigned long count, [array, size_is (count)] out wstring certNameList); */
NS_IMETHODIMP nsX509CertDB::FindCertNicknames(nsISupports *aToken, uint32_t aType, uint32_t *count, char16_t * **certNameList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert findEmailEncryptionCert (in AString aNickname); */
NS_IMETHODIMP nsX509CertDB::FindEmailEncryptionCert(const nsAString & aNickname, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert findEmailSigningCert (in AString aNickname); */
NS_IMETHODIMP nsX509CertDB::FindEmailSigningCert(const nsAString & aNickname, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert findCertByEmailAddress (in nsISupports aToken, in string aEmailAddress); */
NS_IMETHODIMP nsX509CertDB::FindCertByEmailAddress(nsISupports *aToken, const char * aEmailAddress, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importCertificates ([array, size_is (length)] in octet data, in unsigned long length, in unsigned long type, in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsX509CertDB::ImportCertificates(uint8_t *data, uint32_t length, uint32_t type, nsIInterfaceRequestor *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importEmailCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsX509CertDB::ImportEmailCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importServerCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsX509CertDB::ImportServerCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importUserCertificate ([array, size_is (length)] in octet data, in unsigned long length, in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsX509CertDB::ImportUserCertificate(uint8_t *data, uint32_t length, nsIInterfaceRequestor *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteCertificate (in nsIX509Cert aCert); */
NS_IMETHODIMP nsX509CertDB::DeleteCertificate(nsIX509Cert *aCert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCertTrust (in nsIX509Cert cert, in unsigned long type, in unsigned long trust); */
NS_IMETHODIMP nsX509CertDB::SetCertTrust(nsIX509Cert *cert, uint32_t type, uint32_t trust)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCertTrustFromString (in nsIX509Cert cert, in string trustString); */
NS_IMETHODIMP nsX509CertDB::SetCertTrustFromString(nsIX509Cert *cert, const char * trustString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCertTrusted (in nsIX509Cert cert, in unsigned long certType, in unsigned long trustType); */
NS_IMETHODIMP nsX509CertDB::IsCertTrusted(nsIX509Cert *cert, uint32_t certType, uint32_t trustType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importCertsFromFile (in nsISupports aToken, in nsIFile aFile, in unsigned long aType); */
NS_IMETHODIMP nsX509CertDB::ImportCertsFromFile(nsISupports *aToken, nsIFile *aFile, uint32_t aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importPKCS12File (in nsISupports aToken, in nsIFile aFile); */
NS_IMETHODIMP nsX509CertDB::ImportPKCS12File(nsISupports *aToken, nsIFile *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exportPKCS12File (in nsISupports aToken, in nsIFile aFile, in unsigned long count, [array, size_is (count)] in nsIX509Cert aCerts); */
NS_IMETHODIMP nsX509CertDB::ExportPKCS12File(nsISupports *aToken, nsIFile *aFile, uint32_t count, nsIX509Cert **aCerts)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert constructX509FromBase64 (in string base64); */
NS_IMETHODIMP nsX509CertDB::ConstructX509FromBase64(const char * base64, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert constructX509 (in string certDER, in unsigned long length); */
NS_IMETHODIMP nsX509CertDB::ConstructX509(const char * certDER, uint32_t length, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openSignedAppFileAsync (in AppTrustedRoot trustedRoot, in nsIFile aJarFile, in nsIOpenSignedAppFileCallback callback); */
NS_IMETHODIMP nsX509CertDB::OpenSignedAppFileAsync(AppTrustedRoot trustedRoot, nsIFile *aJarFile, nsIOpenSignedAppFileCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void verifySignedDirectoryAsync (in AppTrustedRoot trustedRoot, in nsIFile aUnpackedDir, in nsIVerifySignedDirectoryCallback callback); */
NS_IMETHODIMP nsX509CertDB::VerifySignedDirectoryAsync(AppTrustedRoot trustedRoot, nsIFile *aUnpackedDir, nsIVerifySignedDirectoryCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void verifySignedManifestAsync (in AppTrustedRoot trustedRoot, in nsIInputStream aManifestStream, in nsIInputStream aSignatureStream, in nsIVerifySignedManifestCallback callback); */
NS_IMETHODIMP nsX509CertDB::VerifySignedManifestAsync(AppTrustedRoot trustedRoot, nsIInputStream *aManifestStream, nsIInputStream *aSignatureStream, nsIVerifySignedManifestCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addCert (in ACString certDER, in string aTrust, in string aName); */
NS_IMETHODIMP nsX509CertDB::AddCert(const nsACString & certDER, const char * aTrust, const char * aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t verifyCertNow (in nsIX509Cert aCert, in int64_t aUsage, in uint32_t aFlags, in string aHostname, out nsIX509CertList aVerifiedChain, out bool aHasEVPolicy); */
NS_IMETHODIMP nsX509CertDB::VerifyCertNow(nsIX509Cert *aCert, int64_t aUsage, uint32_t aFlags, const char * aHostname, nsIX509CertList * *aVerifiedChain, bool *aHasEVPolicy, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearOCSPCache (); */
NS_IMETHODIMP nsX509CertDB::ClearOCSPCache()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addCertFromBase64 (in string base64, in string aTrust, in string aName); */
NS_IMETHODIMP nsX509CertDB::AddCertFromBase64(const char * base64, const char * aTrust, const char * aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509CertList getCerts (); */
NS_IMETHODIMP nsX509CertDB::GetCerts(nsIX509CertList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIX509CertDB_h__ */
