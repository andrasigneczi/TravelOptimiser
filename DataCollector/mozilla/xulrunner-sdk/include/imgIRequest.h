/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\imgIRequest.idl
 */

#ifndef __gen_imgIRequest_h__
#define __gen_imgIRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIContainer; /* forward declaration */

class imgINotificationObserver; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    imgIRequest */
#define IMGIREQUEST_IID_STR "83a7708b-5c35-409f-bab3-7fc08be6a264"

#define IMGIREQUEST_IID \
  {0x83a7708b, 0x5c35, 0x409f, \
    { 0xba, 0xb3, 0x7f, 0xc0, 0x8b, 0xe6, 0xa2, 0x64 }}

class NS_NO_VTABLE imgIRequest : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(IMGIREQUEST_IID)

  /* readonly attribute imgIContainer image; */
  NS_IMETHOD GetImage(imgIContainer * *aImage) = 0;

  enum {
    STATUS_NONE = 0,
    STATUS_SIZE_AVAILABLE = 1,
    STATUS_LOAD_COMPLETE = 2,
    STATUS_ERROR = 4,
    STATUS_DECODE_STARTED = 8,
    STATUS_FRAME_COMPLETE = 16,
    STATUS_DECODE_COMPLETE = 32,
    STATUS_IS_ANIMATED = 64,
    STATUS_HAS_TRANSPARENCY = 128
  };

  /* readonly attribute unsigned long imageStatus; */
  NS_IMETHOD GetImageStatus(uint32_t *aImageStatus) = 0;

  /* [noscript] readonly attribute nsresult imageErrorCode; */
  NS_IMETHOD GetImageErrorCode(nsresult *aImageErrorCode) = 0;

  /* readonly attribute nsIURI URI; */
  NS_IMETHOD GetURI(nsIURI * *aURI) = 0;

  /* readonly attribute nsIURI currentURI; */
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) = 0;

  /* readonly attribute imgINotificationObserver notificationObserver; */
  NS_IMETHOD GetNotificationObserver(imgINotificationObserver * *aNotificationObserver) = 0;

  /* readonly attribute string mimeType; */
  NS_IMETHOD GetMimeType(char * *aMimeType) = 0;

  /* imgIRequest clone (in imgINotificationObserver aObserver); */
  NS_IMETHOD Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval) = 0;

  /* readonly attribute nsIPrincipal imagePrincipal; */
  NS_IMETHOD GetImagePrincipal(nsIPrincipal * *aImagePrincipal) = 0;

  /* readonly attribute bool multipart; */
  NS_IMETHOD GetMultipart(bool *aMultipart) = 0;

  enum {
    CORS_NONE = 1,
    CORS_ANONYMOUS = 2,
    CORS_USE_CREDENTIALS = 3
  };

  /* readonly attribute long CORSMode; */
  NS_IMETHOD GetCORSMode(int32_t *aCORSMode) = 0;

  /* void cancelAndForgetObserver (in nsresult aStatus); */
  NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) = 0;

  /* void requestDecode (); */
  NS_IMETHOD RequestDecode(void) = 0;

  /* void startDecoding (); */
  NS_IMETHOD StartDecoding(void) = 0;

  /* void lockImage (); */
  NS_IMETHOD LockImage(void) = 0;

  /* void unlockImage (); */
  NS_IMETHOD UnlockImage(void) = 0;

  /* void requestDiscard (); */
  NS_IMETHOD RequestDiscard(void) = 0;

  /* imgIRequest getStaticRequest (); */
  NS_IMETHOD GetStaticRequest(imgIRequest * *_retval) = 0;

  /* void incrementAnimationConsumers (); */
  NS_IMETHOD IncrementAnimationConsumers(void) = 0;

  /* void decrementAnimationConsumers (); */
  NS_IMETHOD DecrementAnimationConsumers(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(imgIRequest, IMGIREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMGIREQUEST \
  NS_IMETHOD GetImage(imgIContainer * *aImage) override; \
  NS_IMETHOD GetImageStatus(uint32_t *aImageStatus) override; \
  NS_IMETHOD GetImageErrorCode(nsresult *aImageErrorCode) override; \
  NS_IMETHOD GetURI(nsIURI * *aURI) override; \
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) override; \
  NS_IMETHOD GetNotificationObserver(imgINotificationObserver * *aNotificationObserver) override; \
  NS_IMETHOD GetMimeType(char * *aMimeType) override; \
  NS_IMETHOD Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval) override; \
  NS_IMETHOD GetImagePrincipal(nsIPrincipal * *aImagePrincipal) override; \
  NS_IMETHOD GetMultipart(bool *aMultipart) override; \
  NS_IMETHOD GetCORSMode(int32_t *aCORSMode) override; \
  NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) override; \
  NS_IMETHOD RequestDecode(void) override; \
  NS_IMETHOD StartDecoding(void) override; \
  NS_IMETHOD LockImage(void) override; \
  NS_IMETHOD UnlockImage(void) override; \
  NS_IMETHOD RequestDiscard(void) override; \
  NS_IMETHOD GetStaticRequest(imgIRequest * *_retval) override; \
  NS_IMETHOD IncrementAnimationConsumers(void) override; \
  NS_IMETHOD DecrementAnimationConsumers(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMGIREQUEST(_to) \
  NS_IMETHOD GetImage(imgIContainer * *aImage) override { return _to GetImage(aImage); } \
  NS_IMETHOD GetImageStatus(uint32_t *aImageStatus) override { return _to GetImageStatus(aImageStatus); } \
  NS_IMETHOD GetImageErrorCode(nsresult *aImageErrorCode) override { return _to GetImageErrorCode(aImageErrorCode); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) override { return _to GetURI(aURI); } \
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) override { return _to GetCurrentURI(aCurrentURI); } \
  NS_IMETHOD GetNotificationObserver(imgINotificationObserver * *aNotificationObserver) override { return _to GetNotificationObserver(aNotificationObserver); } \
  NS_IMETHOD GetMimeType(char * *aMimeType) override { return _to GetMimeType(aMimeType); } \
  NS_IMETHOD Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval) override { return _to Clone(aObserver, _retval); } \
  NS_IMETHOD GetImagePrincipal(nsIPrincipal * *aImagePrincipal) override { return _to GetImagePrincipal(aImagePrincipal); } \
  NS_IMETHOD GetMultipart(bool *aMultipart) override { return _to GetMultipart(aMultipart); } \
  NS_IMETHOD GetCORSMode(int32_t *aCORSMode) override { return _to GetCORSMode(aCORSMode); } \
  NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) override { return _to CancelAndForgetObserver(aStatus); } \
  NS_IMETHOD RequestDecode(void) override { return _to RequestDecode(); } \
  NS_IMETHOD StartDecoding(void) override { return _to StartDecoding(); } \
  NS_IMETHOD LockImage(void) override { return _to LockImage(); } \
  NS_IMETHOD UnlockImage(void) override { return _to UnlockImage(); } \
  NS_IMETHOD RequestDiscard(void) override { return _to RequestDiscard(); } \
  NS_IMETHOD GetStaticRequest(imgIRequest * *_retval) override { return _to GetStaticRequest(_retval); } \
  NS_IMETHOD IncrementAnimationConsumers(void) override { return _to IncrementAnimationConsumers(); } \
  NS_IMETHOD DecrementAnimationConsumers(void) override { return _to DecrementAnimationConsumers(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMGIREQUEST(_to) \
  NS_IMETHOD GetImage(imgIContainer * *aImage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_IMETHOD GetImageStatus(uint32_t *aImageStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageStatus(aImageStatus); } \
  NS_IMETHOD GetImageErrorCode(nsresult *aImageErrorCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageErrorCode(aImageErrorCode); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetCurrentURI(nsIURI * *aCurrentURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentURI(aCurrentURI); } \
  NS_IMETHOD GetNotificationObserver(imgINotificationObserver * *aNotificationObserver) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationObserver(aNotificationObserver); } \
  NS_IMETHOD GetMimeType(char * *aMimeType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_IMETHOD Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(aObserver, _retval); } \
  NS_IMETHOD GetImagePrincipal(nsIPrincipal * *aImagePrincipal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImagePrincipal(aImagePrincipal); } \
  NS_IMETHOD GetMultipart(bool *aMultipart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMultipart(aMultipart); } \
  NS_IMETHOD GetCORSMode(int32_t *aCORSMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCORSMode(aCORSMode); } \
  NS_IMETHOD CancelAndForgetObserver(nsresult aStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelAndForgetObserver(aStatus); } \
  NS_IMETHOD RequestDecode(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestDecode(); } \
  NS_IMETHOD StartDecoding(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartDecoding(); } \
  NS_IMETHOD LockImage(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LockImage(); } \
  NS_IMETHOD UnlockImage(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlockImage(); } \
  NS_IMETHOD RequestDiscard(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestDiscard(); } \
  NS_IMETHOD GetStaticRequest(imgIRequest * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStaticRequest(_retval); } \
  NS_IMETHOD IncrementAnimationConsumers(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IncrementAnimationConsumers(); } \
  NS_IMETHOD DecrementAnimationConsumers(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DecrementAnimationConsumers(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public imgIRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMGIREQUEST

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, imgIRequest)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute imgIContainer image; */
NS_IMETHODIMP _MYCLASS_::GetImage(imgIContainer * *aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long imageStatus; */
NS_IMETHODIMP _MYCLASS_::GetImageStatus(uint32_t *aImageStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsresult imageErrorCode; */
NS_IMETHODIMP _MYCLASS_::GetImageErrorCode(nsresult *aImageErrorCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI URI; */
NS_IMETHODIMP _MYCLASS_::GetURI(nsIURI * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI currentURI; */
NS_IMETHODIMP _MYCLASS_::GetCurrentURI(nsIURI * *aCurrentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute imgINotificationObserver notificationObserver; */
NS_IMETHODIMP _MYCLASS_::GetNotificationObserver(imgINotificationObserver * *aNotificationObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string mimeType; */
NS_IMETHODIMP _MYCLASS_::GetMimeType(char * *aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgIRequest clone (in imgINotificationObserver aObserver); */
NS_IMETHODIMP _MYCLASS_::Clone(imgINotificationObserver *aObserver, imgIRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrincipal imagePrincipal; */
NS_IMETHODIMP _MYCLASS_::GetImagePrincipal(nsIPrincipal * *aImagePrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool multipart; */
NS_IMETHODIMP _MYCLASS_::GetMultipart(bool *aMultipart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long CORSMode; */
NS_IMETHODIMP _MYCLASS_::GetCORSMode(int32_t *aCORSMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelAndForgetObserver (in nsresult aStatus); */
NS_IMETHODIMP _MYCLASS_::CancelAndForgetObserver(nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestDecode (); */
NS_IMETHODIMP _MYCLASS_::RequestDecode()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startDecoding (); */
NS_IMETHODIMP _MYCLASS_::StartDecoding()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lockImage (); */
NS_IMETHODIMP _MYCLASS_::LockImage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlockImage (); */
NS_IMETHODIMP _MYCLASS_::UnlockImage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestDiscard (); */
NS_IMETHODIMP _MYCLASS_::RequestDiscard()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* imgIRequest getStaticRequest (); */
NS_IMETHODIMP _MYCLASS_::GetStaticRequest(imgIRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void incrementAnimationConsumers (); */
NS_IMETHODIMP _MYCLASS_::IncrementAnimationConsumers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void decrementAnimationConsumers (); */
NS_IMETHODIMP _MYCLASS_::DecrementAnimationConsumers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_imgIRequest_h__ */
