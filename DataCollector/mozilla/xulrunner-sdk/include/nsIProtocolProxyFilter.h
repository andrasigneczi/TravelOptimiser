/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProtocolProxyFilter.idl
 */

#ifndef __gen_nsIProtocolProxyFilter_h__
#define __gen_nsIProtocolProxyFilter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIProtocolProxyService; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIProtocolProxyFilter */
#define NS_IPROTOCOLPROXYFILTER_IID_STR "f424abd3-32b4-456c-9f45-b7e3376cb0d1"

#define NS_IPROTOCOLPROXYFILTER_IID \
  {0xf424abd3, 0x32b4, 0x456c, \
    { 0x9f, 0x45, 0xb7, 0xe3, 0x37, 0x6c, 0xb0, 0xd1 }}

class NS_NO_VTABLE nsIProtocolProxyFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLPROXYFILTER_IID)

  /* nsIProxyInfo applyFilter (in nsIProtocolProxyService aProxyService, in nsIURI aURI, in nsIProxyInfo aProxy); */
  NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolProxyFilter, NS_IPROTOCOLPROXYFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLPROXYFILTER \
  NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLPROXYFILTER(_to) \
  NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval) override { return _to ApplyFilter(aProxyService, aURI, aProxy, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLPROXYFILTER(_to) \
  NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplyFilter(aProxyService, aURI, aProxy, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolProxyFilter : public nsIProtocolProxyFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLPROXYFILTER

  nsProtocolProxyFilter();

private:
  ~nsProtocolProxyFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProtocolProxyFilter, nsIProtocolProxyFilter)

nsProtocolProxyFilter::nsProtocolProxyFilter()
{
  /* member initializers and constructor code */
}

nsProtocolProxyFilter::~nsProtocolProxyFilter()
{
  /* destructor code */
}

/* nsIProxyInfo applyFilter (in nsIProtocolProxyService aProxyService, in nsIURI aURI, in nsIProxyInfo aProxy); */
NS_IMETHODIMP nsProtocolProxyFilter::ApplyFilter(nsIProtocolProxyService *aProxyService, nsIURI *aURI, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIProtocolProxyChannelFilter */
#define NS_IPROTOCOLPROXYCHANNELFILTER_IID_STR "245b0880-82c5-4e6e-be6d-bc586aa55a90"

#define NS_IPROTOCOLPROXYCHANNELFILTER_IID \
  {0x245b0880, 0x82c5, 0x4e6e, \
    { 0xbe, 0x6d, 0xbc, 0x58, 0x6a, 0xa5, 0x5a, 0x90 }}

class NS_NO_VTABLE nsIProtocolProxyChannelFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLPROXYCHANNELFILTER_IID)

  /* nsIProxyInfo applyFilter (in nsIProtocolProxyService aProxyService, in nsIChannel aChannel, in nsIProxyInfo aProxy); */
  NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIChannel *aChannel, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolProxyChannelFilter, NS_IPROTOCOLPROXYCHANNELFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLPROXYCHANNELFILTER \
  NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIChannel *aChannel, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLPROXYCHANNELFILTER(_to) \
  NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIChannel *aChannel, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval) override { return _to ApplyFilter(aProxyService, aChannel, aProxy, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLPROXYCHANNELFILTER(_to) \
  NS_IMETHOD ApplyFilter(nsIProtocolProxyService *aProxyService, nsIChannel *aChannel, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplyFilter(aProxyService, aChannel, aProxy, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolProxyChannelFilter : public nsIProtocolProxyChannelFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLPROXYCHANNELFILTER

  nsProtocolProxyChannelFilter();

private:
  ~nsProtocolProxyChannelFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProtocolProxyChannelFilter, nsIProtocolProxyChannelFilter)

nsProtocolProxyChannelFilter::nsProtocolProxyChannelFilter()
{
  /* member initializers and constructor code */
}

nsProtocolProxyChannelFilter::~nsProtocolProxyChannelFilter()
{
  /* destructor code */
}

/* nsIProxyInfo applyFilter (in nsIProtocolProxyService aProxyService, in nsIChannel aChannel, in nsIProxyInfo aProxy); */
NS_IMETHODIMP nsProtocolProxyChannelFilter::ApplyFilter(nsIProtocolProxyService *aProxyService, nsIChannel *aChannel, nsIProxyInfo *aProxy, nsIProxyInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProtocolProxyFilter_h__ */
