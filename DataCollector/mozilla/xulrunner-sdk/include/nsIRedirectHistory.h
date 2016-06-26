/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRedirectHistory.idl
 */

#ifndef __gen_nsIRedirectHistory_h__
#define __gen_nsIRedirectHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIRedirectHistory */
#define NS_IREDIRECTHISTORY_IID_STR "ab87eabf-d0c4-40a9-b4b2-a1191108d4c0"

#define NS_IREDIRECTHISTORY_IID \
  {0xab87eabf, 0xd0c4, 0x40a9, \
    { 0xb4, 0xb2, 0xa1, 0x19, 0x11, 0x08, 0xd4, 0xc0 }}

class NS_NO_VTABLE nsIRedirectHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREDIRECTHISTORY_IID)

  /* readonly attribute nsIArray redirects; */
  NS_IMETHOD GetRedirects(nsIArray * *aRedirects) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRedirectHistory, NS_IREDIRECTHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREDIRECTHISTORY \
  NS_IMETHOD GetRedirects(nsIArray * *aRedirects) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREDIRECTHISTORY(_to) \
  NS_IMETHOD GetRedirects(nsIArray * *aRedirects) override { return _to GetRedirects(aRedirects); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREDIRECTHISTORY(_to) \
  NS_IMETHOD GetRedirects(nsIArray * *aRedirects) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRedirects(aRedirects); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRedirectHistory : public nsIRedirectHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREDIRECTHISTORY

  nsRedirectHistory();

private:
  ~nsRedirectHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsRedirectHistory, nsIRedirectHistory)

nsRedirectHistory::nsRedirectHistory()
{
  /* member initializers and constructor code */
}

nsRedirectHistory::~nsRedirectHistory()
{
  /* destructor code */
}

/* readonly attribute nsIArray redirects; */
NS_IMETHODIMP nsRedirectHistory::GetRedirects(nsIArray * *aRedirects)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRedirectHistory_h__ */
