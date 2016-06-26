/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIOService2.idl
 */

#ifndef __gen_nsIIOService2_h__
#define __gen_nsIIOService2_h__


#ifndef __gen_nsIIOService_h__
#include "nsIIOService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIIOService2 */
#define NS_IIOSERVICE2_IID_STR "52c5804b-0d3c-4d4f-8654-1c36fd310e69"

#define NS_IIOSERVICE2_IID \
  {0x52c5804b, 0x0d3c, 0x4d4f, \
    { 0x86, 0x54, 0x1c, 0x36, 0xfd, 0x31, 0x0e, 0x69 }}

class NS_NO_VTABLE nsIIOService2 : public nsIIOService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIOSERVICE2_IID)

  /* attribute boolean manageOfflineStatus; */
  NS_IMETHOD GetManageOfflineStatus(bool *aManageOfflineStatus) = 0;
  NS_IMETHOD SetManageOfflineStatus(bool aManageOfflineStatus) = 0;

  /* nsIChannel newChannelFromURIWithProxyFlags2 (in nsIURI aURI, in nsIURI aProxyURI, in unsigned long aProxyFlags, in nsIDOMNode aLoadingNode, in nsIPrincipal aLoadingPrincipal, in nsIPrincipal aTriggeringPrincipal, in unsigned long aSecurityFlags, in unsigned long aContentPolicyType); */
  NS_IMETHOD NewChannelFromURIWithProxyFlags2(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) = 0;

  /* nsIChannel newChannelFromURIWithProxyFlags (in nsIURI aURI, in nsIURI aProxyURI, in unsigned long aProxyFlags); */
  NS_IMETHOD NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIOService2, NS_IIOSERVICE2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIOSERVICE2 \
  NS_IMETHOD GetManageOfflineStatus(bool *aManageOfflineStatus) override; \
  NS_IMETHOD SetManageOfflineStatus(bool aManageOfflineStatus) override; \
  NS_IMETHOD NewChannelFromURIWithProxyFlags2(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) override; \
  NS_IMETHOD NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIOSERVICE2(_to) \
  NS_IMETHOD GetManageOfflineStatus(bool *aManageOfflineStatus) override { return _to GetManageOfflineStatus(aManageOfflineStatus); } \
  NS_IMETHOD SetManageOfflineStatus(bool aManageOfflineStatus) override { return _to SetManageOfflineStatus(aManageOfflineStatus); } \
  NS_IMETHOD NewChannelFromURIWithProxyFlags2(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) override { return _to NewChannelFromURIWithProxyFlags2(aURI, aProxyURI, aProxyFlags, aLoadingNode, aLoadingPrincipal, aTriggeringPrincipal, aSecurityFlags, aContentPolicyType, _retval); } \
  NS_IMETHOD NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval) override { return _to NewChannelFromURIWithProxyFlags(aURI, aProxyURI, aProxyFlags, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIOSERVICE2(_to) \
  NS_IMETHOD GetManageOfflineStatus(bool *aManageOfflineStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManageOfflineStatus(aManageOfflineStatus); } \
  NS_IMETHOD SetManageOfflineStatus(bool aManageOfflineStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetManageOfflineStatus(aManageOfflineStatus); } \
  NS_IMETHOD NewChannelFromURIWithProxyFlags2(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannelFromURIWithProxyFlags2(aURI, aProxyURI, aProxyFlags, aLoadingNode, aLoadingPrincipal, aTriggeringPrincipal, aSecurityFlags, aContentPolicyType, _retval); } \
  NS_IMETHOD NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannelFromURIWithProxyFlags(aURI, aProxyURI, aProxyFlags, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIOService2 : public nsIIOService2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIOSERVICE2

  nsIOService2();

private:
  ~nsIOService2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsIOService2, nsIIOService2)

nsIOService2::nsIOService2()
{
  /* member initializers and constructor code */
}

nsIOService2::~nsIOService2()
{
  /* destructor code */
}

/* attribute boolean manageOfflineStatus; */
NS_IMETHODIMP nsIOService2::GetManageOfflineStatus(bool *aManageOfflineStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIOService2::SetManageOfflineStatus(bool aManageOfflineStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannelFromURIWithProxyFlags2 (in nsIURI aURI, in nsIURI aProxyURI, in unsigned long aProxyFlags, in nsIDOMNode aLoadingNode, in nsIPrincipal aLoadingPrincipal, in nsIPrincipal aTriggeringPrincipal, in unsigned long aSecurityFlags, in unsigned long aContentPolicyType); */
NS_IMETHODIMP nsIOService2::NewChannelFromURIWithProxyFlags2(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIDOMNode *aLoadingNode, nsIPrincipal *aLoadingPrincipal, nsIPrincipal *aTriggeringPrincipal, uint32_t aSecurityFlags, uint32_t aContentPolicyType, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannelFromURIWithProxyFlags (in nsIURI aURI, in nsIURI aProxyURI, in unsigned long aProxyFlags); */
NS_IMETHODIMP nsIOService2::NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIOService2_h__ */
