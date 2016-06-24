/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISystemMessageGlue.idl
 */

#ifndef __gen_nsISystemMessageGlue_h__
#define __gen_nsISystemMessageGlue_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISystemMessageGlue */
#define NS_ISYSTEMMESSAGEGLUE_IID_STR "b5d98286-e7cc-11e3-92fb-74d02b97e723"

#define NS_ISYSTEMMESSAGEGLUE_IID \
  {0xb5d98286, 0xe7cc, 0x11e3, \
    { 0x92, 0xfb, 0x74, 0xd0, 0x2b, 0x97, 0xe7, 0x23 }}

class NS_NO_VTABLE nsISystemMessageGlue : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMMESSAGEGLUE_IID)

  /* void openApp (in DOMString pageURL, in DOMString manifestURL, in DOMString type, in jsval target, in boolean showApp, in boolean onlyShowApp, [optional] in jsval extra); */
  NS_IMETHOD OpenApp(const nsAString & pageURL, const nsAString & manifestURL, const nsAString & type, JS::HandleValue target, bool showApp, bool onlyShowApp, JS::HandleValue extra) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessageGlue, NS_ISYSTEMMESSAGEGLUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGEGLUE \
  NS_IMETHOD OpenApp(const nsAString & pageURL, const nsAString & manifestURL, const nsAString & type, JS::HandleValue target, bool showApp, bool onlyShowApp, JS::HandleValue extra) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGEGLUE(_to) \
  NS_IMETHOD OpenApp(const nsAString & pageURL, const nsAString & manifestURL, const nsAString & type, JS::HandleValue target, bool showApp, bool onlyShowApp, JS::HandleValue extra) override { return _to OpenApp(pageURL, manifestURL, type, target, showApp, onlyShowApp, extra); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGEGLUE(_to) \
  NS_IMETHOD OpenApp(const nsAString & pageURL, const nsAString & manifestURL, const nsAString & type, JS::HandleValue target, bool showApp, bool onlyShowApp, JS::HandleValue extra) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenApp(pageURL, manifestURL, type, target, showApp, onlyShowApp, extra); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemMessageGlue : public nsISystemMessageGlue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMMESSAGEGLUE

  nsSystemMessageGlue();

private:
  ~nsSystemMessageGlue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSystemMessageGlue, nsISystemMessageGlue)

nsSystemMessageGlue::nsSystemMessageGlue()
{
  /* member initializers and constructor code */
}

nsSystemMessageGlue::~nsSystemMessageGlue()
{
  /* destructor code */
}

/* void openApp (in DOMString pageURL, in DOMString manifestURL, in DOMString type, in jsval target, in boolean showApp, in boolean onlyShowApp, [optional] in jsval extra); */
NS_IMETHODIMP nsSystemMessageGlue::OpenApp(const nsAString & pageURL, const nsAString & manifestURL, const nsAString & type, JS::HandleValue target, bool showApp, bool onlyShowApp, JS::HandleValue extra)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISystemMessageGlue_h__ */
