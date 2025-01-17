/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIControllerContext.idl
 */

#ifndef __gen_nsIControllerContext_h__
#define __gen_nsIControllerContext_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIControllerCommandTable_h__
#include "nsIControllerCommandTable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIControllerContext */
#define NS_ICONTROLLERCONTEXT_IID_STR "47b82b60-a36f-4167-8072-6f421151ed50"

#define NS_ICONTROLLERCONTEXT_IID \
  {0x47b82b60, 0xa36f, 0x4167, \
    { 0x80, 0x72, 0x6f, 0x42, 0x11, 0x51, 0xed, 0x50 }}

class NS_NO_VTABLE nsIControllerContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTROLLERCONTEXT_IID)

  /* void init (in nsIControllerCommandTable aCommandTable); */
  NS_IMETHOD Init(nsIControllerCommandTable *aCommandTable) = 0;

  /* void setCommandContext (in nsISupports aCommandContext); */
  NS_IMETHOD SetCommandContext(nsISupports *aCommandContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIControllerContext, NS_ICONTROLLERCONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTROLLERCONTEXT \
  NS_IMETHOD Init(nsIControllerCommandTable *aCommandTable) override; \
  NS_IMETHOD SetCommandContext(nsISupports *aCommandContext) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTROLLERCONTEXT(_to) \
  NS_IMETHOD Init(nsIControllerCommandTable *aCommandTable) override { return _to Init(aCommandTable); } \
  NS_IMETHOD SetCommandContext(nsISupports *aCommandContext) override { return _to SetCommandContext(aCommandContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTROLLERCONTEXT(_to) \
  NS_IMETHOD Init(nsIControllerCommandTable *aCommandTable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aCommandTable); } \
  NS_IMETHOD SetCommandContext(nsISupports *aCommandContext) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCommandContext(aCommandContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsControllerContext : public nsIControllerContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTROLLERCONTEXT

  nsControllerContext();

private:
  ~nsControllerContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsControllerContext, nsIControllerContext)

nsControllerContext::nsControllerContext()
{
  /* member initializers and constructor code */
}

nsControllerContext::~nsControllerContext()
{
  /* destructor code */
}

/* void init (in nsIControllerCommandTable aCommandTable); */
NS_IMETHODIMP nsControllerContext::Init(nsIControllerCommandTable *aCommandTable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCommandContext (in nsISupports aCommandContext); */
NS_IMETHODIMP nsControllerContext::SetCommandContext(nsISupports *aCommandContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIControllerContext_h__ */
