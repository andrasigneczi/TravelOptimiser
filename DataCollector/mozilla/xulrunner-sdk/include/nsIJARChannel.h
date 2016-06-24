/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIJARChannel.idl
 */

#ifndef __gen_nsIJARChannel_h__
#define __gen_nsIJARChannel_h__


#ifndef __gen_nsIChannel_h__
#include "nsIChannel.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIZipEntry; /* forward declaration */


/* starting interface:    nsIJARChannel */
#define NS_IJARCHANNEL_IID_STR "fbdfaa6b-72dc-465e-af56-572fd13f153c"

#define NS_IJARCHANNEL_IID \
  {0xfbdfaa6b, 0x72dc, 0x465e, \
    { 0xaf, 0x56, 0x57, 0x2f, 0xd1, 0x3f, 0x15, 0x3c }}

class NS_NO_VTABLE nsIJARChannel : public nsIChannel {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJARCHANNEL_IID)

  /* [infallible] readonly attribute boolean isUnsafe; */
  NS_IMETHOD GetIsUnsafe(bool *aIsUnsafe) = 0;
  inline bool GetIsUnsafe()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsUnsafe(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* void setAppURI (in nsIURI uri); */
  NS_IMETHOD SetAppURI(nsIURI *uri) = 0;

  /* readonly attribute nsIFile jarFile; */
  NS_IMETHOD GetJarFile(nsIFile * *aJarFile) = 0;

  /* readonly attribute nsIZipEntry zipEntry; */
  NS_IMETHOD GetZipEntry(nsIZipEntry * *aZipEntry) = 0;

  /* void ensureChildFd (); */
  NS_IMETHOD EnsureChildFd(void) = 0;

  /* void forceNoIntercept (); */
  NS_IMETHOD ForceNoIntercept(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJARChannel, NS_IJARCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJARCHANNEL \
  using nsIJARChannel::GetIsUnsafe; \
  NS_IMETHOD GetIsUnsafe(bool *aIsUnsafe) override; \
  NS_IMETHOD SetAppURI(nsIURI *uri) override; \
  NS_IMETHOD GetJarFile(nsIFile * *aJarFile) override; \
  NS_IMETHOD GetZipEntry(nsIZipEntry * *aZipEntry) override; \
  NS_IMETHOD EnsureChildFd(void) override; \
  NS_IMETHOD ForceNoIntercept(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJARCHANNEL(_to) \
  using nsIJARChannel::GetIsUnsafe; \
  NS_IMETHOD GetIsUnsafe(bool *aIsUnsafe) override { return _to GetIsUnsafe(aIsUnsafe); } \
  NS_IMETHOD SetAppURI(nsIURI *uri) override { return _to SetAppURI(uri); } \
  NS_IMETHOD GetJarFile(nsIFile * *aJarFile) override { return _to GetJarFile(aJarFile); } \
  NS_IMETHOD GetZipEntry(nsIZipEntry * *aZipEntry) override { return _to GetZipEntry(aZipEntry); } \
  NS_IMETHOD EnsureChildFd(void) override { return _to EnsureChildFd(); } \
  NS_IMETHOD ForceNoIntercept(void) override { return _to ForceNoIntercept(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJARCHANNEL(_to) \
  NS_IMETHOD GetIsUnsafe(bool *aIsUnsafe) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsUnsafe(aIsUnsafe); } \
  NS_IMETHOD SetAppURI(nsIURI *uri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAppURI(uri); } \
  NS_IMETHOD GetJarFile(nsIFile * *aJarFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJarFile(aJarFile); } \
  NS_IMETHOD GetZipEntry(nsIZipEntry * *aZipEntry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZipEntry(aZipEntry); } \
  NS_IMETHOD EnsureChildFd(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureChildFd(); } \
  NS_IMETHOD ForceNoIntercept(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceNoIntercept(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJARChannel : public nsIJARChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJARCHANNEL

  nsJARChannel();

private:
  ~nsJARChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsJARChannel, nsIJARChannel)

nsJARChannel::nsJARChannel()
{
  /* member initializers and constructor code */
}

nsJARChannel::~nsJARChannel()
{
  /* destructor code */
}

/* [infallible] readonly attribute boolean isUnsafe; */
NS_IMETHODIMP nsJARChannel::GetIsUnsafe(bool *aIsUnsafe)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAppURI (in nsIURI uri); */
NS_IMETHODIMP nsJARChannel::SetAppURI(nsIURI *uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile jarFile; */
NS_IMETHODIMP nsJARChannel::GetJarFile(nsIFile * *aJarFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIZipEntry zipEntry; */
NS_IMETHODIMP nsJARChannel::GetZipEntry(nsIZipEntry * *aZipEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureChildFd (); */
NS_IMETHODIMP nsJARChannel::EnsureChildFd()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceNoIntercept (); */
NS_IMETHODIMP nsJARChannel::ForceNoIntercept()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJARChannel_h__ */
