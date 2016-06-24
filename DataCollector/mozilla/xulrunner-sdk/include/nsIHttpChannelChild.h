/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHttpChannelChild.idl
 */

#ifndef __gen_nsIHttpChannelChild_h__
#define __gen_nsIHttpChannelChild_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHttpChannelChild */
#define NS_IHTTPCHANNELCHILD_IID_STR "3842c5e9-b5b1-400c-8eb7-936a3316ff21"

#define NS_IHTTPCHANNELCHILD_IID \
  {0x3842c5e9, 0xb5b1, 0x400c, \
    { 0x8e, 0xb7, 0x93, 0x6a, 0x33, 0x16, 0xff, 0x21 }}

class NS_NO_VTABLE nsIHttpChannelChild : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPCHANNELCHILD_IID)

  /* void addCookiesToRequest (); */
  NS_IMETHOD AddCookiesToRequest(void) = 0;

  /* void forceIntercepted (); */
  NS_IMETHOD ForceIntercepted(void) = 0;

  /* readonly attribute RequestHeaderTuples clientSetRequestHeaders; */
  NS_IMETHOD GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpChannelChild, NS_IHTTPCHANNELCHILD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPCHANNELCHILD \
  NS_IMETHOD AddCookiesToRequest(void) override; \
  NS_IMETHOD ForceIntercepted(void) override; \
  NS_IMETHOD GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPCHANNELCHILD(_to) \
  NS_IMETHOD AddCookiesToRequest(void) override { return _to AddCookiesToRequest(); } \
  NS_IMETHOD ForceIntercepted(void) override { return _to ForceIntercepted(); } \
  NS_IMETHOD GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders) override { return _to GetClientSetRequestHeaders(aClientSetRequestHeaders); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPCHANNELCHILD(_to) \
  NS_IMETHOD AddCookiesToRequest(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCookiesToRequest(); } \
  NS_IMETHOD ForceIntercepted(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceIntercepted(); } \
  NS_IMETHOD GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientSetRequestHeaders(aClientSetRequestHeaders); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpChannelChild : public nsIHttpChannelChild
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPCHANNELCHILD

  nsHttpChannelChild();

private:
  ~nsHttpChannelChild();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsHttpChannelChild, nsIHttpChannelChild)

nsHttpChannelChild::nsHttpChannelChild()
{
  /* member initializers and constructor code */
}

nsHttpChannelChild::~nsHttpChannelChild()
{
  /* destructor code */
}

/* void addCookiesToRequest (); */
NS_IMETHODIMP nsHttpChannelChild::AddCookiesToRequest()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceIntercepted (); */
NS_IMETHODIMP nsHttpChannelChild::ForceIntercepted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute RequestHeaderTuples clientSetRequestHeaders; */
NS_IMETHODIMP nsHttpChannelChild::GetClientSetRequestHeaders(mozilla::net::RequestHeaderTuples **aClientSetRequestHeaders)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpChannelChild_h__ */
