/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebProgressListener.idl
 */

#ifndef __gen_nsIWebProgressListener_h__
#define __gen_nsIWebProgressListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIWebProgress; /* forward declaration */

class nsIRequest; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIWebProgressListener */
#define NS_IWEBPROGRESSLISTENER_IID_STR "a9df523b-efe2-421e-9d8e-3d7f807dda4c"

#define NS_IWEBPROGRESSLISTENER_IID \
  {0xa9df523b, 0xefe2, 0x421e, \
    { 0x9d, 0x8e, 0x3d, 0x7f, 0x80, 0x7d, 0xda, 0x4c }}

class NS_NO_VTABLE nsIWebProgressListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBPROGRESSLISTENER_IID)

  enum {
    STATE_START = 1U,
    STATE_REDIRECTING = 2U,
    STATE_TRANSFERRING = 4U,
    STATE_NEGOTIATING = 8U,
    STATE_STOP = 16U,
    STATE_IS_REQUEST = 65536U,
    STATE_IS_DOCUMENT = 131072U,
    STATE_IS_NETWORK = 262144U,
    STATE_IS_WINDOW = 524288U,
    STATE_RESTORING = 16777216U,
    STATE_IS_INSECURE = 4U,
    STATE_IS_BROKEN = 1U,
    STATE_IS_SECURE = 2U,
    STATE_BLOCKED_MIXED_ACTIVE_CONTENT = 16U,
    STATE_LOADED_MIXED_ACTIVE_CONTENT = 32U,
    STATE_BLOCKED_MIXED_DISPLAY_CONTENT = 256U,
    STATE_LOADED_MIXED_DISPLAY_CONTENT = 512U,
    STATE_BLOCKED_TRACKING_CONTENT = 4096U,
    STATE_LOADED_TRACKING_CONTENT = 8192U,
    STATE_SECURE_HIGH = 262144U,
    STATE_SECURE_MED = 65536U,
    STATE_SECURE_LOW = 131072U,
    STATE_IDENTITY_EV_TOPLEVEL = 1048576U,
    STATE_USES_SSL_3 = 16777216U,
    STATE_USES_WEAK_CRYPTO = 33554432U
  };

  /* void onStateChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in unsigned long aStateFlags, in nsresult aStatus); */
  NS_IMETHOD OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus) = 0;

  /* void onProgressChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in long aCurSelfProgress, in long aMaxSelfProgress, in long aCurTotalProgress, in long aMaxTotalProgress); */
  NS_IMETHOD OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int32_t aCurSelfProgress, int32_t aMaxSelfProgress, int32_t aCurTotalProgress, int32_t aMaxTotalProgress) = 0;

  enum {
    LOCATION_CHANGE_SAME_DOCUMENT = 1U,
    LOCATION_CHANGE_ERROR_PAGE = 2U
  };

  /* void onLocationChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in nsIURI aLocation, [optional] in unsigned long aFlags); */
  NS_IMETHOD OnLocationChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsIURI *aLocation, uint32_t aFlags) = 0;

  /* void onStatusChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in nsresult aStatus, in wstring aMessage); */
  NS_IMETHOD OnStatusChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsresult aStatus, const char16_t * aMessage) = 0;

  /* void onSecurityChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in unsigned long aState); */
  NS_IMETHOD OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebProgressListener, NS_IWEBPROGRESSLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBPROGRESSLISTENER \
  NS_IMETHOD OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus) override; \
  NS_IMETHOD OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int32_t aCurSelfProgress, int32_t aMaxSelfProgress, int32_t aCurTotalProgress, int32_t aMaxTotalProgress) override; \
  NS_IMETHOD OnLocationChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsIURI *aLocation, uint32_t aFlags) override; \
  NS_IMETHOD OnStatusChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsresult aStatus, const char16_t * aMessage) override; \
  NS_IMETHOD OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBPROGRESSLISTENER(_to) \
  NS_IMETHOD OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus) override { return _to OnStateChange(aWebProgress, aRequest, aStateFlags, aStatus); } \
  NS_IMETHOD OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int32_t aCurSelfProgress, int32_t aMaxSelfProgress, int32_t aCurTotalProgress, int32_t aMaxTotalProgress) override { return _to OnProgressChange(aWebProgress, aRequest, aCurSelfProgress, aMaxSelfProgress, aCurTotalProgress, aMaxTotalProgress); } \
  NS_IMETHOD OnLocationChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsIURI *aLocation, uint32_t aFlags) override { return _to OnLocationChange(aWebProgress, aRequest, aLocation, aFlags); } \
  NS_IMETHOD OnStatusChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsresult aStatus, const char16_t * aMessage) override { return _to OnStatusChange(aWebProgress, aRequest, aStatus, aMessage); } \
  NS_IMETHOD OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState) override { return _to OnSecurityChange(aWebProgress, aRequest, aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBPROGRESSLISTENER(_to) \
  NS_IMETHOD OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStateChange(aWebProgress, aRequest, aStateFlags, aStatus); } \
  NS_IMETHOD OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int32_t aCurSelfProgress, int32_t aMaxSelfProgress, int32_t aCurTotalProgress, int32_t aMaxTotalProgress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProgressChange(aWebProgress, aRequest, aCurSelfProgress, aMaxSelfProgress, aCurTotalProgress, aMaxTotalProgress); } \
  NS_IMETHOD OnLocationChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsIURI *aLocation, uint32_t aFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnLocationChange(aWebProgress, aRequest, aLocation, aFlags); } \
  NS_IMETHOD OnStatusChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsresult aStatus, const char16_t * aMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStatusChange(aWebProgress, aRequest, aStatus, aMessage); } \
  NS_IMETHOD OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSecurityChange(aWebProgress, aRequest, aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebProgressListener : public nsIWebProgressListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBPROGRESSLISTENER

  nsWebProgressListener();

private:
  ~nsWebProgressListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsWebProgressListener, nsIWebProgressListener)

nsWebProgressListener::nsWebProgressListener()
{
  /* member initializers and constructor code */
}

nsWebProgressListener::~nsWebProgressListener()
{
  /* destructor code */
}

/* void onStateChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in unsigned long aStateFlags, in nsresult aStatus); */
NS_IMETHODIMP nsWebProgressListener::OnStateChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aStateFlags, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onProgressChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in long aCurSelfProgress, in long aMaxSelfProgress, in long aCurTotalProgress, in long aMaxTotalProgress); */
NS_IMETHODIMP nsWebProgressListener::OnProgressChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, int32_t aCurSelfProgress, int32_t aMaxSelfProgress, int32_t aCurTotalProgress, int32_t aMaxTotalProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onLocationChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in nsIURI aLocation, [optional] in unsigned long aFlags); */
NS_IMETHODIMP nsWebProgressListener::OnLocationChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsIURI *aLocation, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStatusChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in nsresult aStatus, in wstring aMessage); */
NS_IMETHODIMP nsWebProgressListener::OnStatusChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, nsresult aStatus, const char16_t * aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSecurityChange (in nsIWebProgress aWebProgress, in nsIRequest aRequest, in unsigned long aState); */
NS_IMETHODIMP nsWebProgressListener::OnSecurityChange(nsIWebProgress *aWebProgress, nsIRequest *aRequest, uint32_t aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebProgressListener_h__ */
