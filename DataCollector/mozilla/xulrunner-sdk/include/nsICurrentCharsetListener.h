/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICurrentCharsetListener.idl
 */

#ifndef __gen_nsICurrentCharsetListener_h__
#define __gen_nsICurrentCharsetListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// {CF9428C1-DF50-11d3-9D0C-0050040007B2}
#define NS_CURRENTCHARSETLISTENER_CID { 0xcf9428c1, 0xdf50, 0x11d3, { 0x9d, 0xc, 0x0, 0x50, 0x4, 0x0, 0x7, 0xb2 } }
#define NS_ICURRENTCHARSETLISTENER_CONTRACTID "@mozilla.org/intl/currentcharsetlistener;1"

/* starting interface:    nsICurrentCharsetListener */
#define NS_ICURRENTCHARSETLISTENER_IID_STR "cf9428c1-df50-11d3-9d0c-0050040007b2"

#define NS_ICURRENTCHARSETLISTENER_IID \
  {0xcf9428c1, 0xdf50, 0x11d3, \
    { 0x9d, 0x0c, 0x00, 0x50, 0x04, 0x00, 0x07, 0xb2 }}

class NS_NO_VTABLE nsICurrentCharsetListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICURRENTCHARSETLISTENER_IID)

  /* void SetCurrentCharset (in wstring charset); */
  NS_IMETHOD SetCurrentCharset(const char16_t * charset) = 0;

  /* void SetCurrentMailCharset (in wstring charset); */
  NS_IMETHOD SetCurrentMailCharset(const char16_t * charset) = 0;

  /* void SetCurrentComposerCharset (in wstring charset); */
  NS_IMETHOD SetCurrentComposerCharset(const char16_t * charset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICurrentCharsetListener, NS_ICURRENTCHARSETLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICURRENTCHARSETLISTENER \
  NS_IMETHOD SetCurrentCharset(const char16_t * charset) override; \
  NS_IMETHOD SetCurrentMailCharset(const char16_t * charset) override; \
  NS_IMETHOD SetCurrentComposerCharset(const char16_t * charset) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICURRENTCHARSETLISTENER(_to) \
  NS_IMETHOD SetCurrentCharset(const char16_t * charset) override { return _to SetCurrentCharset(charset); } \
  NS_IMETHOD SetCurrentMailCharset(const char16_t * charset) override { return _to SetCurrentMailCharset(charset); } \
  NS_IMETHOD SetCurrentComposerCharset(const char16_t * charset) override { return _to SetCurrentComposerCharset(charset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICURRENTCHARSETLISTENER(_to) \
  NS_IMETHOD SetCurrentCharset(const char16_t * charset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentCharset(charset); } \
  NS_IMETHOD SetCurrentMailCharset(const char16_t * charset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentMailCharset(charset); } \
  NS_IMETHOD SetCurrentComposerCharset(const char16_t * charset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentComposerCharset(charset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCurrentCharsetListener : public nsICurrentCharsetListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICURRENTCHARSETLISTENER

  nsCurrentCharsetListener();

private:
  ~nsCurrentCharsetListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCurrentCharsetListener, nsICurrentCharsetListener)

nsCurrentCharsetListener::nsCurrentCharsetListener()
{
  /* member initializers and constructor code */
}

nsCurrentCharsetListener::~nsCurrentCharsetListener()
{
  /* destructor code */
}

/* void SetCurrentCharset (in wstring charset); */
NS_IMETHODIMP nsCurrentCharsetListener::SetCurrentCharset(const char16_t * charset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetCurrentMailCharset (in wstring charset); */
NS_IMETHODIMP nsCurrentCharsetListener::SetCurrentMailCharset(const char16_t * charset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetCurrentComposerCharset (in wstring charset); */
NS_IMETHODIMP nsCurrentCharsetListener::SetCurrentComposerCharset(const char16_t * charset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICurrentCharsetListener_h__ */
