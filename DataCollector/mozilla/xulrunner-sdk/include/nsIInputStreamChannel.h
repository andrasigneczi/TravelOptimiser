/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInputStreamChannel.idl
 */

#ifndef __gen_nsIInputStreamChannel_h__
#define __gen_nsIInputStreamChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIInputStreamChannel */
#define NS_IINPUTSTREAMCHANNEL_IID_STR "e1e95852-914b-4d83-b574-23f114db9b89"

#define NS_IINPUTSTREAMCHANNEL_IID \
  {0xe1e95852, 0x914b, 0x4d83, \
    { 0xb5, 0x74, 0x23, 0xf1, 0x14, 0xdb, 0x9b, 0x89 }}

class NS_NO_VTABLE nsIInputStreamChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTSTREAMCHANNEL_IID)

  /* void setURI (in nsIURI aURI); */
  NS_IMETHOD SetURI(nsIURI *aURI) = 0;

  /* attribute nsIInputStream contentStream; */
  NS_IMETHOD GetContentStream(nsIInputStream * *aContentStream) = 0;
  NS_IMETHOD SetContentStream(nsIInputStream *aContentStream) = 0;

  /* attribute AString srcdocData; */
  NS_IMETHOD GetSrcdocData(nsAString & aSrcdocData) = 0;
  NS_IMETHOD SetSrcdocData(const nsAString & aSrcdocData) = 0;

  /* readonly attribute boolean isSrcdocChannel; */
  NS_IMETHOD GetIsSrcdocChannel(bool *aIsSrcdocChannel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputStreamChannel, NS_IINPUTSTREAMCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTSTREAMCHANNEL \
  NS_IMETHOD SetURI(nsIURI *aURI) override; \
  NS_IMETHOD GetContentStream(nsIInputStream * *aContentStream) override; \
  NS_IMETHOD SetContentStream(nsIInputStream *aContentStream) override; \
  NS_IMETHOD GetSrcdocData(nsAString & aSrcdocData) override; \
  NS_IMETHOD SetSrcdocData(const nsAString & aSrcdocData) override; \
  NS_IMETHOD GetIsSrcdocChannel(bool *aIsSrcdocChannel) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTSTREAMCHANNEL(_to) \
  NS_IMETHOD SetURI(nsIURI *aURI) override { return _to SetURI(aURI); } \
  NS_IMETHOD GetContentStream(nsIInputStream * *aContentStream) override { return _to GetContentStream(aContentStream); } \
  NS_IMETHOD SetContentStream(nsIInputStream *aContentStream) override { return _to SetContentStream(aContentStream); } \
  NS_IMETHOD GetSrcdocData(nsAString & aSrcdocData) override { return _to GetSrcdocData(aSrcdocData); } \
  NS_IMETHOD SetSrcdocData(const nsAString & aSrcdocData) override { return _to SetSrcdocData(aSrcdocData); } \
  NS_IMETHOD GetIsSrcdocChannel(bool *aIsSrcdocChannel) override { return _to GetIsSrcdocChannel(aIsSrcdocChannel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTSTREAMCHANNEL(_to) \
  NS_IMETHOD SetURI(nsIURI *aURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetURI(aURI); } \
  NS_IMETHOD GetContentStream(nsIInputStream * *aContentStream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentStream(aContentStream); } \
  NS_IMETHOD SetContentStream(nsIInputStream *aContentStream) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentStream(aContentStream); } \
  NS_IMETHOD GetSrcdocData(nsAString & aSrcdocData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrcdocData(aSrcdocData); } \
  NS_IMETHOD SetSrcdocData(const nsAString & aSrcdocData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrcdocData(aSrcdocData); } \
  NS_IMETHOD GetIsSrcdocChannel(bool *aIsSrcdocChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSrcdocChannel(aIsSrcdocChannel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputStreamChannel : public nsIInputStreamChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTSTREAMCHANNEL

  nsInputStreamChannel();

private:
  ~nsInputStreamChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInputStreamChannel, nsIInputStreamChannel)

nsInputStreamChannel::nsInputStreamChannel()
{
  /* member initializers and constructor code */
}

nsInputStreamChannel::~nsInputStreamChannel()
{
  /* destructor code */
}

/* void setURI (in nsIURI aURI); */
NS_IMETHODIMP nsInputStreamChannel::SetURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInputStream contentStream; */
NS_IMETHODIMP nsInputStreamChannel::GetContentStream(nsIInputStream * *aContentStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputStreamChannel::SetContentStream(nsIInputStream *aContentStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString srcdocData; */
NS_IMETHODIMP nsInputStreamChannel::GetSrcdocData(nsAString & aSrcdocData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsInputStreamChannel::SetSrcdocData(const nsAString & aSrcdocData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSrcdocChannel; */
NS_IMETHODIMP nsInputStreamChannel::GetIsSrcdocChannel(bool *aIsSrcdocChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInputStreamChannel_h__ */
