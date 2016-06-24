/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIURIFixup.idl
 */

#ifndef __gen_nsIURIFixup_h__
#define __gen_nsIURIFixup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */


/* starting interface:    nsIURIFixupInfo */
#define NS_IURIFIXUPINFO_IID_STR "4819f183-b532-4932-ac09-b309cd853be7"

#define NS_IURIFIXUPINFO_IID \
  {0x4819f183, 0xb532, 0x4932, \
    { 0xac, 0x09, 0xb3, 0x09, 0xcd, 0x85, 0x3b, 0xe7 }}

class NS_NO_VTABLE nsIURIFixupInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURIFIXUPINFO_IID)

  /* attribute nsISupports consumer; */
  NS_IMETHOD GetConsumer(nsISupports * *aConsumer) = 0;
  NS_IMETHOD SetConsumer(nsISupports *aConsumer) = 0;

  /* readonly attribute nsIURI preferredURI; */
  NS_IMETHOD GetPreferredURI(nsIURI * *aPreferredURI) = 0;

  /* readonly attribute nsIURI fixedURI; */
  NS_IMETHOD GetFixedURI(nsIURI * *aFixedURI) = 0;

  /* readonly attribute AString keywordProviderName; */
  NS_IMETHOD GetKeywordProviderName(nsAString & aKeywordProviderName) = 0;

  /* readonly attribute AString keywordAsSent; */
  NS_IMETHOD GetKeywordAsSent(nsAString & aKeywordAsSent) = 0;

  /* readonly attribute boolean fixupChangedProtocol; */
  NS_IMETHOD GetFixupChangedProtocol(bool *aFixupChangedProtocol) = 0;

  /* readonly attribute boolean fixupCreatedAlternateURI; */
  NS_IMETHOD GetFixupCreatedAlternateURI(bool *aFixupCreatedAlternateURI) = 0;

  /* readonly attribute AUTF8String originalInput; */
  NS_IMETHOD GetOriginalInput(nsACString & aOriginalInput) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIFixupInfo, NS_IURIFIXUPINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURIFIXUPINFO \
  NS_IMETHOD GetConsumer(nsISupports * *aConsumer) override; \
  NS_IMETHOD SetConsumer(nsISupports *aConsumer) override; \
  NS_IMETHOD GetPreferredURI(nsIURI * *aPreferredURI) override; \
  NS_IMETHOD GetFixedURI(nsIURI * *aFixedURI) override; \
  NS_IMETHOD GetKeywordProviderName(nsAString & aKeywordProviderName) override; \
  NS_IMETHOD GetKeywordAsSent(nsAString & aKeywordAsSent) override; \
  NS_IMETHOD GetFixupChangedProtocol(bool *aFixupChangedProtocol) override; \
  NS_IMETHOD GetFixupCreatedAlternateURI(bool *aFixupCreatedAlternateURI) override; \
  NS_IMETHOD GetOriginalInput(nsACString & aOriginalInput) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURIFIXUPINFO(_to) \
  NS_IMETHOD GetConsumer(nsISupports * *aConsumer) override { return _to GetConsumer(aConsumer); } \
  NS_IMETHOD SetConsumer(nsISupports *aConsumer) override { return _to SetConsumer(aConsumer); } \
  NS_IMETHOD GetPreferredURI(nsIURI * *aPreferredURI) override { return _to GetPreferredURI(aPreferredURI); } \
  NS_IMETHOD GetFixedURI(nsIURI * *aFixedURI) override { return _to GetFixedURI(aFixedURI); } \
  NS_IMETHOD GetKeywordProviderName(nsAString & aKeywordProviderName) override { return _to GetKeywordProviderName(aKeywordProviderName); } \
  NS_IMETHOD GetKeywordAsSent(nsAString & aKeywordAsSent) override { return _to GetKeywordAsSent(aKeywordAsSent); } \
  NS_IMETHOD GetFixupChangedProtocol(bool *aFixupChangedProtocol) override { return _to GetFixupChangedProtocol(aFixupChangedProtocol); } \
  NS_IMETHOD GetFixupCreatedAlternateURI(bool *aFixupCreatedAlternateURI) override { return _to GetFixupCreatedAlternateURI(aFixupCreatedAlternateURI); } \
  NS_IMETHOD GetOriginalInput(nsACString & aOriginalInput) override { return _to GetOriginalInput(aOriginalInput); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURIFIXUPINFO(_to) \
  NS_IMETHOD GetConsumer(nsISupports * *aConsumer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConsumer(aConsumer); } \
  NS_IMETHOD SetConsumer(nsISupports *aConsumer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConsumer(aConsumer); } \
  NS_IMETHOD GetPreferredURI(nsIURI * *aPreferredURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreferredURI(aPreferredURI); } \
  NS_IMETHOD GetFixedURI(nsIURI * *aFixedURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFixedURI(aFixedURI); } \
  NS_IMETHOD GetKeywordProviderName(nsAString & aKeywordProviderName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeywordProviderName(aKeywordProviderName); } \
  NS_IMETHOD GetKeywordAsSent(nsAString & aKeywordAsSent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeywordAsSent(aKeywordAsSent); } \
  NS_IMETHOD GetFixupChangedProtocol(bool *aFixupChangedProtocol) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFixupChangedProtocol(aFixupChangedProtocol); } \
  NS_IMETHOD GetFixupCreatedAlternateURI(bool *aFixupCreatedAlternateURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFixupCreatedAlternateURI(aFixupCreatedAlternateURI); } \
  NS_IMETHOD GetOriginalInput(nsACString & aOriginalInput) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginalInput(aOriginalInput); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIFixupInfo : public nsIURIFixupInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURIFIXUPINFO

  nsURIFixupInfo();

private:
  ~nsURIFixupInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsURIFixupInfo, nsIURIFixupInfo)

nsURIFixupInfo::nsURIFixupInfo()
{
  /* member initializers and constructor code */
}

nsURIFixupInfo::~nsURIFixupInfo()
{
  /* destructor code */
}

/* attribute nsISupports consumer; */
NS_IMETHODIMP nsURIFixupInfo::GetConsumer(nsISupports * *aConsumer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURIFixupInfo::SetConsumer(nsISupports *aConsumer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI preferredURI; */
NS_IMETHODIMP nsURIFixupInfo::GetPreferredURI(nsIURI * *aPreferredURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI fixedURI; */
NS_IMETHODIMP nsURIFixupInfo::GetFixedURI(nsIURI * *aFixedURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString keywordProviderName; */
NS_IMETHODIMP nsURIFixupInfo::GetKeywordProviderName(nsAString & aKeywordProviderName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString keywordAsSent; */
NS_IMETHODIMP nsURIFixupInfo::GetKeywordAsSent(nsAString & aKeywordAsSent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean fixupChangedProtocol; */
NS_IMETHODIMP nsURIFixupInfo::GetFixupChangedProtocol(bool *aFixupChangedProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean fixupCreatedAlternateURI; */
NS_IMETHODIMP nsURIFixupInfo::GetFixupCreatedAlternateURI(bool *aFixupCreatedAlternateURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String originalInput; */
NS_IMETHODIMP nsURIFixupInfo::GetOriginalInput(nsACString & aOriginalInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIURIFixup */
#define NS_IURIFIXUP_IID_STR "1da7e9d4-620b-4949-849a-1cd6077b1b2d"

#define NS_IURIFIXUP_IID \
  {0x1da7e9d4, 0x620b, 0x4949, \
    { 0x84, 0x9a, 0x1c, 0xd6, 0x07, 0x7b, 0x1b, 0x2d }}

class NS_NO_VTABLE nsIURIFixup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURIFIXUP_IID)

  enum {
    FIXUP_FLAG_NONE = 0U,
    FIXUP_FLAG_ALLOW_KEYWORD_LOOKUP = 1U,
    FIXUP_FLAGS_MAKE_ALTERNATE_URI = 2U,
    FIXUP_FLAG_FIX_SCHEME_TYPOS = 8U
  };

  /* nsIURI createExposableURI (in nsIURI aURI); */
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) = 0;

  /* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags, [optional] out nsIInputStream aPostData); */
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) = 0;

  /* nsIURIFixupInfo getFixupURIInfo (in AUTF8String aURIText, in unsigned long aFixupFlags, [optional] out nsIInputStream aPostData); */
  NS_IMETHOD GetFixupURIInfo(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval) = 0;

  /* nsIURIFixupInfo keywordToURI (in AUTF8String aKeyword, [optional] out nsIInputStream aPostData); */
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval) = 0;

  /* bool isDomainWhitelisted (in AUTF8String aDomain, in uint32_t aDotPos); */
  NS_IMETHOD IsDomainWhitelisted(const nsACString & aDomain, uint32_t aDotPos, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIFixup, NS_IURIFIXUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURIFIXUP \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) override; \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) override; \
  NS_IMETHOD GetFixupURIInfo(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval) override; \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval) override; \
  NS_IMETHOD IsDomainWhitelisted(const nsACString & aDomain, uint32_t aDotPos, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURIFIXUP(_to) \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) override { return _to CreateExposableURI(aURI, _retval); } \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) override { return _to CreateFixupURI(aURIText, aFixupFlags, aPostData, _retval); } \
  NS_IMETHOD GetFixupURIInfo(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval) override { return _to GetFixupURIInfo(aURIText, aFixupFlags, aPostData, _retval); } \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval) override { return _to KeywordToURI(aKeyword, aPostData, _retval); } \
  NS_IMETHOD IsDomainWhitelisted(const nsACString & aDomain, uint32_t aDotPos, bool *_retval) override { return _to IsDomainWhitelisted(aDomain, aDotPos, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURIFIXUP(_to) \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateExposableURI(aURI, _retval); } \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFixupURI(aURIText, aFixupFlags, aPostData, _retval); } \
  NS_IMETHOD GetFixupURIInfo(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFixupURIInfo(aURIText, aFixupFlags, aPostData, _retval); } \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->KeywordToURI(aKeyword, aPostData, _retval); } \
  NS_IMETHOD IsDomainWhitelisted(const nsACString & aDomain, uint32_t aDotPos, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDomainWhitelisted(aDomain, aDotPos, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIFixup : public nsIURIFixup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURIFIXUP

  nsURIFixup();

private:
  ~nsURIFixup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsURIFixup, nsIURIFixup)

nsURIFixup::nsURIFixup()
{
  /* member initializers and constructor code */
}

nsURIFixup::~nsURIFixup()
{
  /* destructor code */
}

/* nsIURI createExposableURI (in nsIURI aURI); */
NS_IMETHODIMP nsURIFixup::CreateExposableURI(nsIURI *aURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags, [optional] out nsIInputStream aPostData); */
NS_IMETHODIMP nsURIFixup::CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURIFixupInfo getFixupURIInfo (in AUTF8String aURIText, in unsigned long aFixupFlags, [optional] out nsIInputStream aPostData); */
NS_IMETHODIMP nsURIFixup::GetFixupURIInfo(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURIFixupInfo keywordToURI (in AUTF8String aKeyword, [optional] out nsIInputStream aPostData); */
NS_IMETHODIMP nsURIFixup::KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURIFixupInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isDomainWhitelisted (in AUTF8String aDomain, in uint32_t aDotPos); */
NS_IMETHODIMP nsURIFixup::IsDomainWhitelisted(const nsACString & aDomain, uint32_t aDotPos, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIFixup_h__ */
