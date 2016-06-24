/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMediaManager.idl
 */

#ifndef __gen_nsIMediaManager_h__
#define __gen_nsIMediaManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISupportsArray; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

#define NS_MEDIAMANAGERSERVICE_CID {0xabc622ea, 0x9655, 0x4123, {0x80, 0xd9, 0x22, 0x62, 0x1b, 0xdd, 0x54, 0x65}}
#define MEDIAMANAGERSERVICE_CONTRACTID "@mozilla.org/mediaManagerService;1"

/* starting interface:    nsIMediaManagerService */
#define NS_IMEDIAMANAGERSERVICE_IID_STR "24b23e01-33fd-401f-ba25-6e52658750b0"

#define NS_IMEDIAMANAGERSERVICE_IID \
  {0x24b23e01, 0x33fd, 0x401f, \
    { 0xba, 0x25, 0x6e, 0x52, 0x65, 0x87, 0x50, 0xb0 }}

class NS_NO_VTABLE nsIMediaManagerService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEDIAMANAGERSERVICE_IID)

  /* readonly attribute nsISupportsArray activeMediaCaptureWindows; */
  NS_IMETHOD GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows) = 0;

  /* void mediaCaptureWindowState (in nsIDOMWindow aWindow, out boolean aVideo, out boolean aAudio, [optional] out boolean aScreenShare, [optional] out boolean aWindowShare, [optional] out boolean aAppShare, [optional] out boolean aBrowserShare); */
  NS_IMETHOD MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio, bool *aScreenShare, bool *aWindowShare, bool *aAppShare, bool *aBrowserShare) = 0;

  /* void sanitizeDeviceIds (in long long sinceWhen); */
  NS_IMETHOD SanitizeDeviceIds(int64_t sinceWhen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMediaManagerService, NS_IMEDIAMANAGERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEDIAMANAGERSERVICE \
  NS_IMETHOD GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows) override; \
  NS_IMETHOD MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio, bool *aScreenShare, bool *aWindowShare, bool *aAppShare, bool *aBrowserShare) override; \
  NS_IMETHOD SanitizeDeviceIds(int64_t sinceWhen) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEDIAMANAGERSERVICE(_to) \
  NS_IMETHOD GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows) override { return _to GetActiveMediaCaptureWindows(aActiveMediaCaptureWindows); } \
  NS_IMETHOD MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio, bool *aScreenShare, bool *aWindowShare, bool *aAppShare, bool *aBrowserShare) override { return _to MediaCaptureWindowState(aWindow, aVideo, aAudio, aScreenShare, aWindowShare, aAppShare, aBrowserShare); } \
  NS_IMETHOD SanitizeDeviceIds(int64_t sinceWhen) override { return _to SanitizeDeviceIds(sinceWhen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEDIAMANAGERSERVICE(_to) \
  NS_IMETHOD GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveMediaCaptureWindows(aActiveMediaCaptureWindows); } \
  NS_IMETHOD MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio, bool *aScreenShare, bool *aWindowShare, bool *aAppShare, bool *aBrowserShare) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MediaCaptureWindowState(aWindow, aVideo, aAudio, aScreenShare, aWindowShare, aAppShare, aBrowserShare); } \
  NS_IMETHOD SanitizeDeviceIds(int64_t sinceWhen) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SanitizeDeviceIds(sinceWhen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMediaManagerService : public nsIMediaManagerService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEDIAMANAGERSERVICE

  nsMediaManagerService();

private:
  ~nsMediaManagerService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMediaManagerService, nsIMediaManagerService)

nsMediaManagerService::nsMediaManagerService()
{
  /* member initializers and constructor code */
}

nsMediaManagerService::~nsMediaManagerService()
{
  /* destructor code */
}

/* readonly attribute nsISupportsArray activeMediaCaptureWindows; */
NS_IMETHODIMP nsMediaManagerService::GetActiveMediaCaptureWindows(nsISupportsArray * *aActiveMediaCaptureWindows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mediaCaptureWindowState (in nsIDOMWindow aWindow, out boolean aVideo, out boolean aAudio, [optional] out boolean aScreenShare, [optional] out boolean aWindowShare, [optional] out boolean aAppShare, [optional] out boolean aBrowserShare); */
NS_IMETHODIMP nsMediaManagerService::MediaCaptureWindowState(nsIDOMWindow *aWindow, bool *aVideo, bool *aAudio, bool *aScreenShare, bool *aWindowShare, bool *aAppShare, bool *aBrowserShare)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sanitizeDeviceIds (in long long sinceWhen); */
NS_IMETHODIMP nsMediaManagerService::SanitizeDeviceIds(int64_t sinceWhen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMediaManager_h__ */
