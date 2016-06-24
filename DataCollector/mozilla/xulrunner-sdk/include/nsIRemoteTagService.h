/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRemoteTagService.idl
 */

#ifndef __gen_nsIRemoteTagService_h__
#define __gen_nsIRemoteTagService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRemoteTagService */
#define NS_IREMOTETAGSERVICE_IID_STR "59dbe3d0-6084-11e4-9803-0800200c9a66"

#define NS_IREMOTETAGSERVICE_IID \
  {0x59dbe3d0, 0x6084, 0x11e4, \
    { 0x98, 0x03, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIRemoteTagService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREMOTETAGSERVICE_IID)

  /* ACString getRemoteObjectTag (in jsval target); */
  NS_IMETHOD GetRemoteObjectTag(JS::HandleValue target, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRemoteTagService, NS_IREMOTETAGSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREMOTETAGSERVICE \
  NS_IMETHOD GetRemoteObjectTag(JS::HandleValue target, nsACString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREMOTETAGSERVICE(_to) \
  NS_IMETHOD GetRemoteObjectTag(JS::HandleValue target, nsACString & _retval) override { return _to GetRemoteObjectTag(target, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREMOTETAGSERVICE(_to) \
  NS_IMETHOD GetRemoteObjectTag(JS::HandleValue target, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemoteObjectTag(target, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRemoteTagService : public nsIRemoteTagService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREMOTETAGSERVICE

  nsRemoteTagService();

private:
  ~nsRemoteTagService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsRemoteTagService, nsIRemoteTagService)

nsRemoteTagService::nsRemoteTagService()
{
  /* member initializers and constructor code */
}

nsRemoteTagService::~nsRemoteTagService()
{
  /* destructor code */
}

/* ACString getRemoteObjectTag (in jsval target); */
NS_IMETHODIMP nsRemoteTagService::GetRemoteObjectTag(JS::HandleValue target, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRemoteTagService_h__ */
