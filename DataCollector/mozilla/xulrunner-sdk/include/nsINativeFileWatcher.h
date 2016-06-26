/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINativeFileWatcher.idl
 */

#ifndef __gen_nsINativeFileWatcher_h__
#define __gen_nsINativeFileWatcher_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINativeFileWatcherErrorCallback */
#define NS_INATIVEFILEWATCHERERRORCALLBACK_IID_STR "5daeddc3-fc94-4880-8a4f-26d910b92662"

#define NS_INATIVEFILEWATCHERERRORCALLBACK_IID \
  {0x5daeddc3, 0xfc94, 0x4880, \
    { 0x8a, 0x4f, 0x26, 0xd9, 0x10, 0xb9, 0x26, 0x62 }}

class NS_NO_VTABLE nsINativeFileWatcherErrorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INATIVEFILEWATCHERERRORCALLBACK_IID)

  /* void complete (in nsresult xpcomError, in long osError); */
  NS_IMETHOD Complete(nsresult xpcomError, int32_t osError) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINativeFileWatcherErrorCallback, NS_INATIVEFILEWATCHERERRORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINATIVEFILEWATCHERERRORCALLBACK \
  NS_IMETHOD Complete(nsresult xpcomError, int32_t osError) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINATIVEFILEWATCHERERRORCALLBACK(_to) \
  NS_IMETHOD Complete(nsresult xpcomError, int32_t osError) override { return _to Complete(xpcomError, osError); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINATIVEFILEWATCHERERRORCALLBACK(_to) \
  NS_IMETHOD Complete(nsresult xpcomError, int32_t osError) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Complete(xpcomError, osError); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNativeFileWatcherErrorCallback : public nsINativeFileWatcherErrorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINATIVEFILEWATCHERERRORCALLBACK

  nsNativeFileWatcherErrorCallback();

private:
  ~nsNativeFileWatcherErrorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNativeFileWatcherErrorCallback, nsINativeFileWatcherErrorCallback)

nsNativeFileWatcherErrorCallback::nsNativeFileWatcherErrorCallback()
{
  /* member initializers and constructor code */
}

nsNativeFileWatcherErrorCallback::~nsNativeFileWatcherErrorCallback()
{
  /* destructor code */
}

/* void complete (in nsresult xpcomError, in long osError); */
NS_IMETHODIMP nsNativeFileWatcherErrorCallback::Complete(nsresult xpcomError, int32_t osError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINativeFileWatcherCallback */
#define NS_INATIVEFILEWATCHERCALLBACK_IID_STR "fe4d86c9-243f-4195-b544-aece3df4b86a"

#define NS_INATIVEFILEWATCHERCALLBACK_IID \
  {0xfe4d86c9, 0x243f, 0x4195, \
    { 0xb5, 0x44, 0xae, 0xce, 0x3d, 0xf4, 0xb8, 0x6a }}

class NS_NO_VTABLE nsINativeFileWatcherCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INATIVEFILEWATCHERCALLBACK_IID)

  /* void changed (in AString resourcePath, in int32_t flags); */
  NS_IMETHOD Changed(const nsAString & resourcePath, int32_t flags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINativeFileWatcherCallback, NS_INATIVEFILEWATCHERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINATIVEFILEWATCHERCALLBACK \
  NS_IMETHOD Changed(const nsAString & resourcePath, int32_t flags) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINATIVEFILEWATCHERCALLBACK(_to) \
  NS_IMETHOD Changed(const nsAString & resourcePath, int32_t flags) override { return _to Changed(resourcePath, flags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINATIVEFILEWATCHERCALLBACK(_to) \
  NS_IMETHOD Changed(const nsAString & resourcePath, int32_t flags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Changed(resourcePath, flags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNativeFileWatcherCallback : public nsINativeFileWatcherCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINATIVEFILEWATCHERCALLBACK

  nsNativeFileWatcherCallback();

private:
  ~nsNativeFileWatcherCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNativeFileWatcherCallback, nsINativeFileWatcherCallback)

nsNativeFileWatcherCallback::nsNativeFileWatcherCallback()
{
  /* member initializers and constructor code */
}

nsNativeFileWatcherCallback::~nsNativeFileWatcherCallback()
{
  /* destructor code */
}

/* void changed (in AString resourcePath, in int32_t flags); */
NS_IMETHODIMP nsNativeFileWatcherCallback::Changed(const nsAString & resourcePath, int32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINativeFileWatcherSuccessCallback */
#define NS_INATIVEFILEWATCHERSUCCESSCALLBACK_IID_STR "c3d7f542-681b-4abd-9d65-9d799b29a42b"

#define NS_INATIVEFILEWATCHERSUCCESSCALLBACK_IID \
  {0xc3d7f542, 0x681b, 0x4abd, \
    { 0x9d, 0x65, 0x9d, 0x79, 0x9b, 0x29, 0xa4, 0x2b }}

class NS_NO_VTABLE nsINativeFileWatcherSuccessCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INATIVEFILEWATCHERSUCCESSCALLBACK_IID)

  /* void complete (in AString resourcePath); */
  NS_IMETHOD Complete(const nsAString & resourcePath) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINativeFileWatcherSuccessCallback, NS_INATIVEFILEWATCHERSUCCESSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINATIVEFILEWATCHERSUCCESSCALLBACK \
  NS_IMETHOD Complete(const nsAString & resourcePath) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINATIVEFILEWATCHERSUCCESSCALLBACK(_to) \
  NS_IMETHOD Complete(const nsAString & resourcePath) override { return _to Complete(resourcePath); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINATIVEFILEWATCHERSUCCESSCALLBACK(_to) \
  NS_IMETHOD Complete(const nsAString & resourcePath) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Complete(resourcePath); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNativeFileWatcherSuccessCallback : public nsINativeFileWatcherSuccessCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINATIVEFILEWATCHERSUCCESSCALLBACK

  nsNativeFileWatcherSuccessCallback();

private:
  ~nsNativeFileWatcherSuccessCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNativeFileWatcherSuccessCallback, nsINativeFileWatcherSuccessCallback)

nsNativeFileWatcherSuccessCallback::nsNativeFileWatcherSuccessCallback()
{
  /* member initializers and constructor code */
}

nsNativeFileWatcherSuccessCallback::~nsNativeFileWatcherSuccessCallback()
{
  /* destructor code */
}

/* void complete (in AString resourcePath); */
NS_IMETHODIMP nsNativeFileWatcherSuccessCallback::Complete(const nsAString & resourcePath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINativeFileWatcherService */
#define NS_INATIVEFILEWATCHERSERVICE_IID_STR "b3a4e8d8-7dc8-47db-a8b4-83736d7ac1aa"

#define NS_INATIVEFILEWATCHERSERVICE_IID \
  {0xb3a4e8d8, 0x7dc8, 0x47db, \
    { 0xa8, 0xb4, 0x83, 0x73, 0x6d, 0x7a, 0xc1, 0xaa }}

class NS_NO_VTABLE nsINativeFileWatcherService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INATIVEFILEWATCHERSERVICE_IID)

  /* void addPath (in AString pathToWatch, in nsINativeFileWatcherCallback onChange, [optional] in nsINativeFileWatcherErrorCallback onError, [optional] in nsINativeFileWatcherSuccessCallback onSuccess); */
  NS_IMETHOD AddPath(const nsAString & pathToWatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess) = 0;

  /* void removePath (in AString pathToUnwatch, in nsINativeFileWatcherCallback onChange, [optional] in nsINativeFileWatcherErrorCallback onError, [optional] in nsINativeFileWatcherSuccessCallback onSuccess); */
  NS_IMETHOD RemovePath(const nsAString & pathToUnwatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINativeFileWatcherService, NS_INATIVEFILEWATCHERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINATIVEFILEWATCHERSERVICE \
  NS_IMETHOD AddPath(const nsAString & pathToWatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess) override; \
  NS_IMETHOD RemovePath(const nsAString & pathToUnwatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINATIVEFILEWATCHERSERVICE(_to) \
  NS_IMETHOD AddPath(const nsAString & pathToWatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess) override { return _to AddPath(pathToWatch, onChange, onError, onSuccess); } \
  NS_IMETHOD RemovePath(const nsAString & pathToUnwatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess) override { return _to RemovePath(pathToUnwatch, onChange, onError, onSuccess); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINATIVEFILEWATCHERSERVICE(_to) \
  NS_IMETHOD AddPath(const nsAString & pathToWatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddPath(pathToWatch, onChange, onError, onSuccess); } \
  NS_IMETHOD RemovePath(const nsAString & pathToUnwatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePath(pathToUnwatch, onChange, onError, onSuccess); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNativeFileWatcherService : public nsINativeFileWatcherService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINATIVEFILEWATCHERSERVICE

  nsNativeFileWatcherService();

private:
  ~nsNativeFileWatcherService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNativeFileWatcherService, nsINativeFileWatcherService)

nsNativeFileWatcherService::nsNativeFileWatcherService()
{
  /* member initializers and constructor code */
}

nsNativeFileWatcherService::~nsNativeFileWatcherService()
{
  /* destructor code */
}

/* void addPath (in AString pathToWatch, in nsINativeFileWatcherCallback onChange, [optional] in nsINativeFileWatcherErrorCallback onError, [optional] in nsINativeFileWatcherSuccessCallback onSuccess); */
NS_IMETHODIMP nsNativeFileWatcherService::AddPath(const nsAString & pathToWatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePath (in AString pathToUnwatch, in nsINativeFileWatcherCallback onChange, [optional] in nsINativeFileWatcherErrorCallback onError, [optional] in nsINativeFileWatcherSuccessCallback onSuccess); */
NS_IMETHODIMP nsNativeFileWatcherService::RemovePath(const nsAString & pathToUnwatch, nsINativeFileWatcherCallback *onChange, nsINativeFileWatcherErrorCallback *onError, nsINativeFileWatcherSuccessCallback *onSuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NATIVE_FILEWATCHER_SERVICE_CID {0x6F488507, 0x469D, 0x4350, {0xA6, 0x8D, 0x99, 0xC8, 0x7, 0xBE, 0xA, 0x78}}
#define NATIVE_FILEWATCHER_SERVICE_CONTRACTID "@mozilla.org/toolkit/filewatcher/native-file-watcher;1"

#endif /* __gen_nsINativeFileWatcher_h__ */
