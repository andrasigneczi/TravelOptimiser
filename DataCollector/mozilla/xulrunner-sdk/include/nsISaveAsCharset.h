/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISaveAsCharset.idl
 */

#ifndef __gen_nsISaveAsCharset_h__
#define __gen_nsISaveAsCharset_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIEntityConverter_h__
#include "nsIEntityConverter.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_SAVEASCHARSET_CID { 0xcd233e0, 0x7a86, 0x11d3, { 0x91, 0x5c, 0x0, 0x60, 0x8, 0xa6, 0xed, 0xf6 } }
#define NS_SAVEASCHARSET_CONTRACTID "@mozilla.org/intl/saveascharset;1"

/* starting interface:    nsISaveAsCharset */
#define NS_ISAVEASCHARSET_IID_STR "33b87f70-7a9c-11d3-915c-006008a6edf6"

#define NS_ISAVEASCHARSET_IID \
  {0x33b87f70, 0x7a9c, 0x11d3, \
    { 0x91, 0x5c, 0x00, 0x60, 0x08, 0xa6, 0xed, 0xf6 }}

class NS_NO_VTABLE nsISaveAsCharset : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAVEASCHARSET_IID)

  enum {
    mask_Fallback = 255U,
    mask_Entity = 768U,
    mask_CharsetFallback = 1024U,
    attr_FallbackNone = 0U,
    attr_FallbackQuestionMark = 1U,
    attr_FallbackEscapeU = 2U,
    attr_FallbackDecimalNCR = 3U,
    attr_FallbackHexNCR = 4U,
    attr_EntityNone = 0U,
    attr_EntityBeforeCharsetConv = 256U,
    attr_EntityAfterCharsetConv = 512U,
    attr_CharsetFallback = 1024U,
    attr_plainTextDefault = 0U,
    attr_htmlTextDefault = 259U
  };

  /* readonly attribute string charset; */
  NS_IMETHOD GetCharset(char * *aCharset) = 0;

  /* void Init (in string charset, in unsigned long attr, in unsigned long entityVersion); */
  NS_IMETHOD Init(const char * charset, uint32_t attr, uint32_t entityVersion) = 0;

  /* string Convert (in wstring inString); */
  NS_IMETHOD Convert(const char16_t * inString, char * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISaveAsCharset, NS_ISAVEASCHARSET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAVEASCHARSET \
  NS_IMETHOD GetCharset(char * *aCharset) override; \
  NS_IMETHOD Init(const char * charset, uint32_t attr, uint32_t entityVersion) override; \
  NS_IMETHOD Convert(const char16_t * inString, char * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAVEASCHARSET(_to) \
  NS_IMETHOD GetCharset(char * *aCharset) override { return _to GetCharset(aCharset); } \
  NS_IMETHOD Init(const char * charset, uint32_t attr, uint32_t entityVersion) override { return _to Init(charset, attr, entityVersion); } \
  NS_IMETHOD Convert(const char16_t * inString, char * *_retval) override { return _to Convert(inString, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAVEASCHARSET(_to) \
  NS_IMETHOD GetCharset(char * *aCharset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharset(aCharset); } \
  NS_IMETHOD Init(const char * charset, uint32_t attr, uint32_t entityVersion) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(charset, attr, entityVersion); } \
  NS_IMETHOD Convert(const char16_t * inString, char * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Convert(inString, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSaveAsCharset : public nsISaveAsCharset
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAVEASCHARSET

  nsSaveAsCharset();

private:
  ~nsSaveAsCharset();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSaveAsCharset, nsISaveAsCharset)

nsSaveAsCharset::nsSaveAsCharset()
{
  /* member initializers and constructor code */
}

nsSaveAsCharset::~nsSaveAsCharset()
{
  /* destructor code */
}

/* readonly attribute string charset; */
NS_IMETHODIMP nsSaveAsCharset::GetCharset(char * *aCharset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Init (in string charset, in unsigned long attr, in unsigned long entityVersion); */
NS_IMETHODIMP nsSaveAsCharset::Init(const char * charset, uint32_t attr, uint32_t entityVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string Convert (in wstring inString); */
NS_IMETHODIMP nsSaveAsCharset::Convert(const char16_t * inString, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISaveAsCharset_h__ */
