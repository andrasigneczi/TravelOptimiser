/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICertPickDialogs.idl
 */

#ifndef __gen_nsICertPickDialogs_h__
#define __gen_nsICertPickDialogs_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsICertPickDialogs */
#define NS_ICERTPICKDIALOGS_IID_STR "51d59b08-1dd2-11b2-ad4a-a51b92f8a184"

#define NS_ICERTPICKDIALOGS_IID \
  {0x51d59b08, 0x1dd2, 0x11b2, \
    { 0xad, 0x4a, 0xa5, 0x1b, 0x92, 0xf8, 0xa1, 0x84 }}

class NS_NO_VTABLE nsICertPickDialogs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTPICKDIALOGS_IID)

  /* void PickCertificate (in nsIInterfaceRequestor ctx, [array, size_is (count)] in wstring certNickList, [array, size_is (count)] in wstring certDetailsList, in unsigned long count, inout long selectedIndex, out boolean canceled); */
  NS_IMETHOD PickCertificate(nsIInterfaceRequestor *ctx, const char16_t * *certNickList, const char16_t * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertPickDialogs, NS_ICERTPICKDIALOGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTPICKDIALOGS \
  NS_IMETHOD PickCertificate(nsIInterfaceRequestor *ctx, const char16_t * *certNickList, const char16_t * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTPICKDIALOGS(_to) \
  NS_IMETHOD PickCertificate(nsIInterfaceRequestor *ctx, const char16_t * *certNickList, const char16_t * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled) override { return _to PickCertificate(ctx, certNickList, certDetailsList, count, selectedIndex, canceled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTPICKDIALOGS(_to) \
  NS_IMETHOD PickCertificate(nsIInterfaceRequestor *ctx, const char16_t * *certNickList, const char16_t * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PickCertificate(ctx, certNickList, certDetailsList, count, selectedIndex, canceled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertPickDialogs : public nsICertPickDialogs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTPICKDIALOGS

  nsCertPickDialogs();

private:
  ~nsCertPickDialogs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCertPickDialogs, nsICertPickDialogs)

nsCertPickDialogs::nsCertPickDialogs()
{
  /* member initializers and constructor code */
}

nsCertPickDialogs::~nsCertPickDialogs()
{
  /* destructor code */
}

/* void PickCertificate (in nsIInterfaceRequestor ctx, [array, size_is (count)] in wstring certNickList, [array, size_is (count)] in wstring certDetailsList, in unsigned long count, inout long selectedIndex, out boolean canceled); */
NS_IMETHODIMP nsCertPickDialogs::PickCertificate(nsIInterfaceRequestor *ctx, const char16_t * *certNickList, const char16_t * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CERTPICKDIALOGS_CONTRACTID "@mozilla.org/nsCertPickDialogs;1"

#endif /* __gen_nsICertPickDialogs_h__ */
