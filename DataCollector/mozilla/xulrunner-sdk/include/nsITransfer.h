/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITransfer.idl
 */

#ifndef __gen_nsITransfer_h__
#define __gen_nsITransfer_h__


#ifndef __gen_nsIWebProgressListener2_h__
#include "nsIWebProgressListener2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIURI; /* forward declaration */

class nsICancelable; /* forward declaration */

class nsIMIMEInfo; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsITransfer */
#define NS_ITRANSFER_IID_STR "37ec75d3-97ad-4da8-afaa-eabe5b4afd73"

#define NS_ITRANSFER_IID \
  {0x37ec75d3, 0x97ad, 0x4da8, \
    { 0xaf, 0xaa, 0xea, 0xbe, 0x5b, 0x4a, 0xfd, 0x73 }}

class NS_NO_VTABLE nsITransfer : public nsIWebProgressListener2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSFER_IID)

  /* void init (in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime startTime, in nsIFile aTempFile, in nsICancelable aCancelable, in boolean aIsPrivate); */
  NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate) = 0;

  /* void setSha256Hash (in ACString aHash); */
  NS_IMETHOD SetSha256Hash(const nsACString & aHash) = 0;

  /* void setSignatureInfo (in nsIArray aSignatureInfo); */
  NS_IMETHOD SetSignatureInfo(nsIArray *aSignatureInfo) = 0;

  /* void setRedirects (in nsIArray aRedirects); */
  NS_IMETHOD SetRedirects(nsIArray *aRedirects) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransfer, NS_ITRANSFER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSFER \
  NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate) override; \
  NS_IMETHOD SetSha256Hash(const nsACString & aHash) override; \
  NS_IMETHOD SetSignatureInfo(nsIArray *aSignatureInfo) override; \
  NS_IMETHOD SetRedirects(nsIArray *aRedirects) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSFER(_to) \
  NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate) override { return _to Init(aSource, aTarget, aDisplayName, aMIMEInfo, startTime, aTempFile, aCancelable, aIsPrivate); } \
  NS_IMETHOD SetSha256Hash(const nsACString & aHash) override { return _to SetSha256Hash(aHash); } \
  NS_IMETHOD SetSignatureInfo(nsIArray *aSignatureInfo) override { return _to SetSignatureInfo(aSignatureInfo); } \
  NS_IMETHOD SetRedirects(nsIArray *aRedirects) override { return _to SetRedirects(aRedirects); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSFER(_to) \
  NS_IMETHOD Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aSource, aTarget, aDisplayName, aMIMEInfo, startTime, aTempFile, aCancelable, aIsPrivate); } \
  NS_IMETHOD SetSha256Hash(const nsACString & aHash) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSha256Hash(aHash); } \
  NS_IMETHOD SetSignatureInfo(nsIArray *aSignatureInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSignatureInfo(aSignatureInfo); } \
  NS_IMETHOD SetRedirects(nsIArray *aRedirects) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRedirects(aRedirects); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransfer : public nsITransfer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSFER

  nsTransfer();

private:
  ~nsTransfer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTransfer, nsITransfer)

nsTransfer::nsTransfer()
{
  /* member initializers and constructor code */
}

nsTransfer::~nsTransfer()
{
  /* destructor code */
}

/* void init (in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime startTime, in nsIFile aTempFile, in nsICancelable aCancelable, in boolean aIsPrivate); */
NS_IMETHODIMP nsTransfer::Init(nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime startTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSha256Hash (in ACString aHash); */
NS_IMETHODIMP nsTransfer::SetSha256Hash(const nsACString & aHash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSignatureInfo (in nsIArray aSignatureInfo); */
NS_IMETHODIMP nsTransfer::SetSignatureInfo(nsIArray *aSignatureInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRedirects (in nsIArray aRedirects); */
NS_IMETHODIMP nsTransfer::SetRedirects(nsIArray *aRedirects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * A component with this contract ID will be created each time a download is
 * started, and nsITransfer::Init will be called on it and an observer will be set.
 *
 * Notifications of the download progress will happen via
 * nsIWebProgressListener/nsIWebProgressListener2.
 *
 * INTERFACES THAT MUST BE IMPLEMENTED:
 *   nsITransfer
 *   nsIWebProgressListener
 *   nsIWebProgressListener2
 *
 * XXX move this to nsEmbedCID.h once the interfaces (and the contract ID) are
 * frozen.
 */
#define NS_TRANSFER_CONTRACTID "@mozilla.org/transfer;1"

#endif /* __gen_nsITransfer_h__ */
