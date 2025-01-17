/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFeedElementBase.idl
 */

#ifndef __gen_nsIFeedElementBase_h__
#define __gen_nsIFeedElementBase_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISAXAttributes; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIFeedElementBase */
#define NS_IFEEDELEMENTBASE_IID_STR "5215291e-fa0a-40c2-8ce7-e86cd1a1d3fa"

#define NS_IFEEDELEMENTBASE_IID \
  {0x5215291e, 0xfa0a, 0x40c2, \
    { 0x8c, 0xe7, 0xe8, 0x6c, 0xd1, 0xa1, 0xd3, 0xfa }}

class NS_NO_VTABLE nsIFeedElementBase : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEEDELEMENTBASE_IID)

  /* attribute nsISAXAttributes attributes; */
  NS_IMETHOD GetAttributes(nsISAXAttributes * *aAttributes) = 0;
  NS_IMETHOD SetAttributes(nsISAXAttributes *aAttributes) = 0;

  /* attribute nsIURI baseURI; */
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) = 0;
  NS_IMETHOD SetBaseURI(nsIURI *aBaseURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeedElementBase, NS_IFEEDELEMENTBASE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEEDELEMENTBASE \
  NS_IMETHOD GetAttributes(nsISAXAttributes * *aAttributes) override; \
  NS_IMETHOD SetAttributes(nsISAXAttributes *aAttributes) override; \
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) override; \
  NS_IMETHOD SetBaseURI(nsIURI *aBaseURI) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEEDELEMENTBASE(_to) \
  NS_IMETHOD GetAttributes(nsISAXAttributes * *aAttributes) override { return _to GetAttributes(aAttributes); } \
  NS_IMETHOD SetAttributes(nsISAXAttributes *aAttributes) override { return _to SetAttributes(aAttributes); } \
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) override { return _to GetBaseURI(aBaseURI); } \
  NS_IMETHOD SetBaseURI(nsIURI *aBaseURI) override { return _to SetBaseURI(aBaseURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEEDELEMENTBASE(_to) \
  NS_IMETHOD GetAttributes(nsISAXAttributes * *aAttributes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributes(aAttributes); } \
  NS_IMETHOD SetAttributes(nsISAXAttributes *aAttributes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributes(aAttributes); } \
  NS_IMETHOD GetBaseURI(nsIURI * *aBaseURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseURI(aBaseURI); } \
  NS_IMETHOD SetBaseURI(nsIURI *aBaseURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseURI(aBaseURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeedElementBase : public nsIFeedElementBase
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEEDELEMENTBASE

  nsFeedElementBase();

private:
  ~nsFeedElementBase();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsFeedElementBase, nsIFeedElementBase)

nsFeedElementBase::nsFeedElementBase()
{
  /* member initializers and constructor code */
}

nsFeedElementBase::~nsFeedElementBase()
{
  /* destructor code */
}

/* attribute nsISAXAttributes attributes; */
NS_IMETHODIMP nsFeedElementBase::GetAttributes(nsISAXAttributes * *aAttributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedElementBase::SetAttributes(nsISAXAttributes *aAttributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI baseURI; */
NS_IMETHODIMP nsFeedElementBase::GetBaseURI(nsIURI * *aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeedElementBase::SetBaseURI(nsIURI *aBaseURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeedElementBase_h__ */
