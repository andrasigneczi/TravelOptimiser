/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIPlacesAutoComplete.idl
 */

#ifndef __gen_mozIPlacesAutoComplete_h__
#define __gen_mozIPlacesAutoComplete_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    mozIPlacesAutoComplete */
#define MOZIPLACESAUTOCOMPLETE_IID_STR "61b6348a-09e1-4810-8057-f8cb3cec6ef8"

#define MOZIPLACESAUTOCOMPLETE_IID \
  {0x61b6348a, 0x09e1, 0x4810, \
    { 0x80, 0x57, 0xf8, 0xcb, 0x3c, 0xec, 0x6e, 0xf8 }}

class NS_NO_VTABLE mozIPlacesAutoComplete : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIPLACESAUTOCOMPLETE_IID)

  enum {
    MATCH_ANYWHERE = 0,
    MATCH_BOUNDARY_ANYWHERE = 1,
    MATCH_BOUNDARY = 2,
    MATCH_BEGINNING = 3,
    MATCH_ANYWHERE_UNMODIFIED = 4,
    MATCH_BEGINNING_CASE_SENSITIVE = 5,
    BEHAVIOR_HISTORY = 1,
    BEHAVIOR_BOOKMARK = 2,
    BEHAVIOR_TAG = 4,
    BEHAVIOR_TITLE = 8,
    BEHAVIOR_URL = 16,
    BEHAVIOR_TYPED = 32,
    BEHAVIOR_JAVASCRIPT = 64,
    BEHAVIOR_OPENPAGE = 128,
    BEHAVIOR_RESTRICT = 256,
    BEHAVIOR_SEARCHES = 512
  };

  /* void registerOpenPage (in nsIURI aURI); */
  NS_IMETHOD RegisterOpenPage(nsIURI *aURI) = 0;

  /* void unregisterOpenPage (in nsIURI aURI); */
  NS_IMETHOD UnregisterOpenPage(nsIURI *aURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIPlacesAutoComplete, MOZIPLACESAUTOCOMPLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIPLACESAUTOCOMPLETE \
  NS_IMETHOD RegisterOpenPage(nsIURI *aURI) override; \
  NS_IMETHOD UnregisterOpenPage(nsIURI *aURI) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIPLACESAUTOCOMPLETE(_to) \
  NS_IMETHOD RegisterOpenPage(nsIURI *aURI) override { return _to RegisterOpenPage(aURI); } \
  NS_IMETHOD UnregisterOpenPage(nsIURI *aURI) override { return _to UnregisterOpenPage(aURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIPLACESAUTOCOMPLETE(_to) \
  NS_IMETHOD RegisterOpenPage(nsIURI *aURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterOpenPage(aURI); } \
  NS_IMETHOD UnregisterOpenPage(nsIURI *aURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterOpenPage(aURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIPlacesAutoComplete
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIPLACESAUTOCOMPLETE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, mozIPlacesAutoComplete)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void registerOpenPage (in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::RegisterOpenPage(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterOpenPage (in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::UnregisterOpenPage(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIPlacesAutoComplete_h__ */
