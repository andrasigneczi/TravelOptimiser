/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIResponseHeadProvider.idl
 */

#ifndef __gen_nsIResponseHeadProvider_h__
#define __gen_nsIResponseHeadProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHttpHeaderVisitor; /* forward declaration */

namespace mozilla {
namespace net {
class nsHttpResponseHead;
}
}

/* starting interface:    nsIResponseHeadProvider */
#define NS_IRESPONSEHEADPROVIDER_IID_STR "cd0d0804-2e0c-4bff-aa0a-78a3e3159b69"

#define NS_IRESPONSEHEADPROVIDER_IID \
  {0xcd0d0804, 0x2e0c, 0x4bff, \
    { 0xaa, 0x0a, 0x78, 0xa3, 0xe3, 0x15, 0x9b, 0x69 }}

class NS_NO_VTABLE nsIResponseHeadProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRESPONSEHEADPROVIDER_IID)

  /* [notxpcom] nsHttpResponseHeadPtr GetResponseHead (); */
  NS_IMETHOD_(mozilla::net::nsHttpResponseHead *) GetResponseHead(void) = 0;

  /* void visitResponseHeaders (in nsIHttpHeaderVisitor aVisitor); */
  NS_IMETHOD VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIResponseHeadProvider, NS_IRESPONSEHEADPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRESPONSEHEADPROVIDER \
  NS_IMETHOD_(mozilla::net::nsHttpResponseHead *) GetResponseHead(void) override; \
  NS_IMETHOD VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRESPONSEHEADPROVIDER(_to) \
  NS_IMETHOD_(mozilla::net::nsHttpResponseHead *) GetResponseHead(void) override { return _to GetResponseHead(); } \
  NS_IMETHOD VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor) override { return _to VisitResponseHeaders(aVisitor); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRESPONSEHEADPROVIDER(_to) \
  NS_IMETHOD_(mozilla::net::nsHttpResponseHead *) GetResponseHead(void) override; \
  NS_IMETHOD VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitResponseHeaders(aVisitor); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsResponseHeadProvider : public nsIResponseHeadProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRESPONSEHEADPROVIDER

  nsResponseHeadProvider();

private:
  ~nsResponseHeadProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsResponseHeadProvider, nsIResponseHeadProvider)

nsResponseHeadProvider::nsResponseHeadProvider()
{
  /* member initializers and constructor code */
}

nsResponseHeadProvider::~nsResponseHeadProvider()
{
  /* destructor code */
}

/* [notxpcom] nsHttpResponseHeadPtr GetResponseHead (); */
NS_IMETHODIMP_(mozilla::net::nsHttpResponseHead *) nsResponseHeadProvider::GetResponseHead()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void visitResponseHeaders (in nsIHttpHeaderVisitor aVisitor); */
NS_IMETHODIMP nsResponseHeadProvider::VisitResponseHeaders(nsIHttpHeaderVisitor *aVisitor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIResponseHeadProvider_h__ */
