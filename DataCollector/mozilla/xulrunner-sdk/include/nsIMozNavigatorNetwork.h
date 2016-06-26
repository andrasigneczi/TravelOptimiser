/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMozNavigatorNetwork.idl
 */

#ifndef __gen_nsIMozNavigatorNetwork_h__
#define __gen_nsIMozNavigatorNetwork_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsINetworkProperties; /* forward declaration */


/* starting interface:    nsIMozNavigatorNetwork */
#define NS_IMOZNAVIGATORNETWORK_IID_STR "7956523b-631e-4f80-94a5-3883bcfd6bf3"

#define NS_IMOZNAVIGATORNETWORK_IID \
  {0x7956523b, 0x631e, 0x4f80, \
    { 0x94, 0xa5, 0x38, 0x83, 0xbc, 0xfd, 0x6b, 0xf3 }}

class NS_NO_VTABLE nsIMozNavigatorNetwork : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOZNAVIGATORNETWORK_IID)

  /* readonly attribute nsINetworkProperties properties; */
  NS_IMETHOD GetProperties(nsINetworkProperties * *aProperties) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMozNavigatorNetwork, NS_IMOZNAVIGATORNETWORK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOZNAVIGATORNETWORK \
  NS_IMETHOD GetProperties(nsINetworkProperties * *aProperties) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOZNAVIGATORNETWORK(_to) \
  NS_IMETHOD GetProperties(nsINetworkProperties * *aProperties) override { return _to GetProperties(aProperties); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOZNAVIGATORNETWORK(_to) \
  NS_IMETHOD GetProperties(nsINetworkProperties * *aProperties) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperties(aProperties); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMozNavigatorNetwork : public nsIMozNavigatorNetwork
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOZNAVIGATORNETWORK

  nsMozNavigatorNetwork();

private:
  ~nsMozNavigatorNetwork();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMozNavigatorNetwork, nsIMozNavigatorNetwork)

nsMozNavigatorNetwork::nsMozNavigatorNetwork()
{
  /* member initializers and constructor code */
}

nsMozNavigatorNetwork::~nsMozNavigatorNetwork()
{
  /* destructor code */
}

/* readonly attribute nsINetworkProperties properties; */
NS_IMETHODIMP nsMozNavigatorNetwork::GetProperties(nsINetworkProperties * *aProperties)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMozNavigatorNetwork_h__ */
