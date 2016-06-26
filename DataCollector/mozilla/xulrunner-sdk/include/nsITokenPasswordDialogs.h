/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITokenPasswordDialogs.idl
 */

#ifndef __gen_nsITokenPasswordDialogs_h__
#define __gen_nsITokenPasswordDialogs_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsITokenPasswordDialogs */
#define NS_ITOKENPASSWORDDIALOGS_IID_STR "87dbd64a-4466-474e-95f5-1ad1cee5702c"

#define NS_ITOKENPASSWORDDIALOGS_IID \
  {0x87dbd64a, 0x4466, 0x474e, \
    { 0x95, 0xf5, 0x1a, 0xd1, 0xce, 0xe5, 0x70, 0x2c }}

class NS_NO_VTABLE nsITokenPasswordDialogs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOKENPASSWORDDIALOGS_IID)

  /* void setPassword (in nsIInterfaceRequestor ctx, in wstring tokenName, out boolean canceled); */
  NS_IMETHOD SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITokenPasswordDialogs, NS_ITOKENPASSWORDDIALOGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOKENPASSWORDDIALOGS \
  NS_IMETHOD SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOKENPASSWORDDIALOGS(_to) \
  NS_IMETHOD SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled) override { return _to SetPassword(ctx, tokenName, canceled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOKENPASSWORDDIALOGS(_to) \
  NS_IMETHOD SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPassword(ctx, tokenName, canceled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTokenPasswordDialogs : public nsITokenPasswordDialogs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOKENPASSWORDDIALOGS

  nsTokenPasswordDialogs();

private:
  ~nsTokenPasswordDialogs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTokenPasswordDialogs, nsITokenPasswordDialogs)

nsTokenPasswordDialogs::nsTokenPasswordDialogs()
{
  /* member initializers and constructor code */
}

nsTokenPasswordDialogs::~nsTokenPasswordDialogs()
{
  /* destructor code */
}

/* void setPassword (in nsIInterfaceRequestor ctx, in wstring tokenName, out boolean canceled); */
NS_IMETHODIMP nsTokenPasswordDialogs::SetPassword(nsIInterfaceRequestor *ctx, const char16_t * tokenName, bool *canceled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_TOKENPASSWORDSDIALOG_CONTRACTID "@mozilla.org/nsTokenPasswordDialogs;1"

#endif /* __gen_nsITokenPasswordDialogs_h__ */
