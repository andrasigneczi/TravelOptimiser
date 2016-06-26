/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInterAppCommUIGlue.idl
 */

#ifndef __gen_nsIInterAppCommUIGlue_h__
#define __gen_nsIInterAppCommUIGlue_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIInterAppCommUIGlue */
#define NS_IINTERAPPCOMMUIGLUE_IID_STR "634555c6-e246-11e3-b427-74d02b97e723"

#define NS_IINTERAPPCOMMUIGLUE_IID \
  {0x634555c6, 0xe246, 0x11e3, \
    { 0xb4, 0x27, 0x74, 0xd0, 0x2b, 0x97, 0xe7, 0x23 }}

class NS_NO_VTABLE nsIInterAppCommUIGlue : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINTERAPPCOMMUIGLUE_IID)

  /* jsval selectApps (in AString callerID, in AString pubAppManifestURL, in AString keyword, in jsval appsToSelect); */
  NS_IMETHOD SelectApps(const nsAString & callerID, const nsAString & pubAppManifestURL, const nsAString & keyword, JS::HandleValue appsToSelect, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInterAppCommUIGlue, NS_IINTERAPPCOMMUIGLUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINTERAPPCOMMUIGLUE \
  NS_IMETHOD SelectApps(const nsAString & callerID, const nsAString & pubAppManifestURL, const nsAString & keyword, JS::HandleValue appsToSelect, JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINTERAPPCOMMUIGLUE(_to) \
  NS_IMETHOD SelectApps(const nsAString & callerID, const nsAString & pubAppManifestURL, const nsAString & keyword, JS::HandleValue appsToSelect, JS::MutableHandleValue _retval) override { return _to SelectApps(callerID, pubAppManifestURL, keyword, appsToSelect, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINTERAPPCOMMUIGLUE(_to) \
  NS_IMETHOD SelectApps(const nsAString & callerID, const nsAString & pubAppManifestURL, const nsAString & keyword, JS::HandleValue appsToSelect, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectApps(callerID, pubAppManifestURL, keyword, appsToSelect, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInterAppCommUIGlue : public nsIInterAppCommUIGlue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINTERAPPCOMMUIGLUE

  nsInterAppCommUIGlue();

private:
  ~nsInterAppCommUIGlue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInterAppCommUIGlue, nsIInterAppCommUIGlue)

nsInterAppCommUIGlue::nsInterAppCommUIGlue()
{
  /* member initializers and constructor code */
}

nsInterAppCommUIGlue::~nsInterAppCommUIGlue()
{
  /* destructor code */
}

/* jsval selectApps (in AString callerID, in AString pubAppManifestURL, in AString keyword, in jsval appsToSelect); */
NS_IMETHODIMP nsInterAppCommUIGlue::SelectApps(const nsAString & callerID, const nsAString & pubAppManifestURL, const nsAString & keyword, JS::HandleValue appsToSelect, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInterAppCommUIGlue_h__ */
