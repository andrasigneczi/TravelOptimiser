/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWindowsUIUtils.idl
 */

#ifndef __gen_nsIWindowsUIUtils_h__
#define __gen_nsIWindowsUIUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWindowsUIUtils */
#define NS_IWINDOWSUIUTILS_IID_STR "aa8a0ecf-96a1-418c-b80e-f24ae18bbedc"

#define NS_IWINDOWSUIUTILS_IID \
  {0xaa8a0ecf, 0x96a1, 0x418c, \
    { 0xb8, 0x0e, 0xf2, 0x4a, 0xe1, 0x8b, 0xbe, 0xdc }}

class NS_NO_VTABLE nsIWindowsUIUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINDOWSUIUTILS_IID)

  /* readonly attribute boolean inTabletMode; */
  NS_IMETHOD GetInTabletMode(bool *aInTabletMode) = 0;

  /* void updateTabletModeState (); */
  NS_IMETHOD UpdateTabletModeState(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWindowsUIUtils, NS_IWINDOWSUIUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINDOWSUIUTILS \
  NS_IMETHOD GetInTabletMode(bool *aInTabletMode) override; \
  NS_IMETHOD UpdateTabletModeState(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINDOWSUIUTILS(_to) \
  NS_IMETHOD GetInTabletMode(bool *aInTabletMode) override { return _to GetInTabletMode(aInTabletMode); } \
  NS_IMETHOD UpdateTabletModeState(void) override { return _to UpdateTabletModeState(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINDOWSUIUTILS(_to) \
  NS_IMETHOD GetInTabletMode(bool *aInTabletMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInTabletMode(aInTabletMode); } \
  NS_IMETHOD UpdateTabletModeState(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateTabletModeState(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWindowsUIUtils : public nsIWindowsUIUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINDOWSUIUTILS

  nsWindowsUIUtils();

private:
  ~nsWindowsUIUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsWindowsUIUtils, nsIWindowsUIUtils)

nsWindowsUIUtils::nsWindowsUIUtils()
{
  /* member initializers and constructor code */
}

nsWindowsUIUtils::~nsWindowsUIUtils()
{
  /* destructor code */
}

/* readonly attribute boolean inTabletMode; */
NS_IMETHODIMP nsWindowsUIUtils::GetInTabletMode(bool *aInTabletMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateTabletModeState (); */
NS_IMETHODIMP nsWindowsUIUtils::UpdateTabletModeState()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWindowsUIUtils_h__ */
