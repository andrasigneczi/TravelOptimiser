/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrintProgressParams.idl
 */

#ifndef __gen_nsIPrintProgressParams_h__
#define __gen_nsIPrintProgressParams_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrintProgressParams */
#define NS_IPRINTPROGRESSPARAMS_IID_STR "ca89b55b-6faf-4051-9645-1c03ef5108f8"

#define NS_IPRINTPROGRESSPARAMS_IID \
  {0xca89b55b, 0x6faf, 0x4051, \
    { 0x96, 0x45, 0x1c, 0x03, 0xef, 0x51, 0x08, 0xf8 }}

class NS_NO_VTABLE nsIPrintProgressParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTPROGRESSPARAMS_IID)

  /* attribute wstring docTitle; */
  NS_IMETHOD GetDocTitle(char16_t * *aDocTitle) = 0;
  NS_IMETHOD SetDocTitle(const char16_t * aDocTitle) = 0;

  /* attribute wstring docURL; */
  NS_IMETHOD GetDocURL(char16_t * *aDocURL) = 0;
  NS_IMETHOD SetDocURL(const char16_t * aDocURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintProgressParams, NS_IPRINTPROGRESSPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTPROGRESSPARAMS \
  NS_IMETHOD GetDocTitle(char16_t * *aDocTitle) override; \
  NS_IMETHOD SetDocTitle(const char16_t * aDocTitle) override; \
  NS_IMETHOD GetDocURL(char16_t * *aDocURL) override; \
  NS_IMETHOD SetDocURL(const char16_t * aDocURL) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTPROGRESSPARAMS(_to) \
  NS_IMETHOD GetDocTitle(char16_t * *aDocTitle) override { return _to GetDocTitle(aDocTitle); } \
  NS_IMETHOD SetDocTitle(const char16_t * aDocTitle) override { return _to SetDocTitle(aDocTitle); } \
  NS_IMETHOD GetDocURL(char16_t * *aDocURL) override { return _to GetDocURL(aDocURL); } \
  NS_IMETHOD SetDocURL(const char16_t * aDocURL) override { return _to SetDocURL(aDocURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTPROGRESSPARAMS(_to) \
  NS_IMETHOD GetDocTitle(char16_t * *aDocTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocTitle(aDocTitle); } \
  NS_IMETHOD SetDocTitle(const char16_t * aDocTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocTitle(aDocTitle); } \
  NS_IMETHOD GetDocURL(char16_t * *aDocURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocURL(aDocURL); } \
  NS_IMETHOD SetDocURL(const char16_t * aDocURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocURL(aDocURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintProgressParams : public nsIPrintProgressParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTPROGRESSPARAMS

  nsPrintProgressParams();

private:
  ~nsPrintProgressParams();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPrintProgressParams, nsIPrintProgressParams)

nsPrintProgressParams::nsPrintProgressParams()
{
  /* member initializers and constructor code */
}

nsPrintProgressParams::~nsPrintProgressParams()
{
  /* destructor code */
}

/* attribute wstring docTitle; */
NS_IMETHODIMP nsPrintProgressParams::GetDocTitle(char16_t * *aDocTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintProgressParams::SetDocTitle(const char16_t * aDocTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring docURL; */
NS_IMETHODIMP nsPrintProgressParams::GetDocURL(char16_t * *aDocURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintProgressParams::SetDocURL(const char16_t * aDocURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintProgressParams_h__ */
