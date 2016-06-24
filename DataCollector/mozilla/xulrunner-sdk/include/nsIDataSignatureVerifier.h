/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDataSignatureVerifier.idl
 */

#ifndef __gen_nsIDataSignatureVerifier_h__
#define __gen_nsIDataSignatureVerifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIX509Cert; /* forward declaration */


/* starting interface:    nsIDataSignatureVerifier */
#define NS_IDATASIGNATUREVERIFIER_IID_STR "94066a00-37c9-11e4-916c-0800200c9a66"

#define NS_IDATASIGNATUREVERIFIER_IID \
  {0x94066a00, 0x37c9, 0x11e4, \
    { 0x91, 0x6c, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIDataSignatureVerifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDATASIGNATUREVERIFIER_IID)

  /* boolean verifyData (in ACString aData, in ACString aSignature, in ACString aPublicKey); */
  NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval) = 0;

  enum {
    VERIFY_OK = 0,
    VERIFY_ERROR_UNKNOWN_ISSUER = 1,
    VERIFY_ERROR_OTHER = 2
  };

  /* nsIX509Cert verifySignature (in string aSignature, in unsigned long aSignatureLen, in string plaintext, in unsigned long plaintextLen, out long errorCode); */
  NS_IMETHOD VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsIX509Cert * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDataSignatureVerifier, NS_IDATASIGNATUREVERIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDATASIGNATUREVERIFIER \
  NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval) override; \
  NS_IMETHOD VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsIX509Cert * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDATASIGNATUREVERIFIER(_to) \
  NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval) override { return _to VerifyData(aData, aSignature, aPublicKey, _retval); } \
  NS_IMETHOD VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsIX509Cert * *_retval) override { return _to VerifySignature(aSignature, aSignatureLen, plaintext, plaintextLen, errorCode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDATASIGNATUREVERIFIER(_to) \
  NS_IMETHOD VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifyData(aData, aSignature, aPublicKey, _retval); } \
  NS_IMETHOD VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VerifySignature(aSignature, aSignatureLen, plaintext, plaintextLen, errorCode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDataSignatureVerifier : public nsIDataSignatureVerifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDATASIGNATUREVERIFIER

  nsDataSignatureVerifier();

private:
  ~nsDataSignatureVerifier();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDataSignatureVerifier, nsIDataSignatureVerifier)

nsDataSignatureVerifier::nsDataSignatureVerifier()
{
  /* member initializers and constructor code */
}

nsDataSignatureVerifier::~nsDataSignatureVerifier()
{
  /* destructor code */
}

/* boolean verifyData (in ACString aData, in ACString aSignature, in ACString aPublicKey); */
NS_IMETHODIMP nsDataSignatureVerifier::VerifyData(const nsACString & aData, const nsACString & aSignature, const nsACString & aPublicKey, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert verifySignature (in string aSignature, in unsigned long aSignatureLen, in string plaintext, in unsigned long plaintextLen, out long errorCode); */
NS_IMETHODIMP nsDataSignatureVerifier::VerifySignature(const char * aSignature, uint32_t aSignatureLen, const char * plaintext, uint32_t plaintextLen, int32_t *errorCode, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDataSignatureVerifier_h__ */
