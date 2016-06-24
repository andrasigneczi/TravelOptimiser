/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIClipboardHelper.idl
 */

#ifndef __gen_nsIClipboardHelper_h__
#define __gen_nsIClipboardHelper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIClipboard_h__
#include "nsIClipboard.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsString.h" // needed for AString -> nsAString, unfortunately
class nsIDOMDocument; /* forward declaration */


/* starting interface:    nsIClipboardHelper */
#define NS_ICLIPBOARDHELPER_IID_STR "438307fd-0c68-4d79-922a-f6cc9550cd02"

#define NS_ICLIPBOARDHELPER_IID \
  {0x438307fd, 0x0c68, 0x4d79, \
    { 0x92, 0x2a, 0xf6, 0xcc, 0x95, 0x50, 0xcd, 0x02 }}

class NS_NO_VTABLE nsIClipboardHelper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIPBOARDHELPER_IID)

  /* void copyStringToClipboard (in AString aString, in long aClipboardID); */
  NS_IMETHOD CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID) = 0;

  /* void copyString (in AString aString); */
  NS_IMETHOD CopyString(const nsAString & aString) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClipboardHelper, NS_ICLIPBOARDHELPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIPBOARDHELPER \
  NS_IMETHOD CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID) override; \
  NS_IMETHOD CopyString(const nsAString & aString) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIPBOARDHELPER(_to) \
  NS_IMETHOD CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID) override { return _to CopyStringToClipboard(aString, aClipboardID); } \
  NS_IMETHOD CopyString(const nsAString & aString) override { return _to CopyString(aString); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIPBOARDHELPER(_to) \
  NS_IMETHOD CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyStringToClipboard(aString, aClipboardID); } \
  NS_IMETHOD CopyString(const nsAString & aString) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyString(aString); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClipboardHelper : public nsIClipboardHelper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIPBOARDHELPER

  nsClipboardHelper();

private:
  ~nsClipboardHelper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsClipboardHelper, nsIClipboardHelper)

nsClipboardHelper::nsClipboardHelper()
{
  /* member initializers and constructor code */
}

nsClipboardHelper::~nsClipboardHelper()
{
  /* destructor code */
}

/* void copyStringToClipboard (in AString aString, in long aClipboardID); */
NS_IMETHODIMP nsClipboardHelper::CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyString (in AString aString); */
NS_IMETHODIMP nsClipboardHelper::CopyString(const nsAString & aString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClipboardHelper_h__ */
