/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMozBrowserFrame.idl
 */

#ifndef __gen_nsIMozBrowserFrame_h__
#define __gen_nsIMozBrowserFrame_h__


#ifndef __gen_nsIDOMMozBrowserFrame_h__
#include "nsIDOMMozBrowserFrame.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITabParent; /* forward declaration */


/* starting interface:    nsIMozBrowserFrame */
#define NS_IMOZBROWSERFRAME_IID_STR "0c0a862c-1a47-43c0-ae9e-d51835e3e1a6"

#define NS_IMOZBROWSERFRAME_IID \
  {0x0c0a862c, 0x1a47, 0x43c0, \
    { 0xae, 0x9e, 0xd5, 0x18, 0x35, 0xe3, 0xe1, 0xa6 }}

class NS_NO_VTABLE nsIMozBrowserFrame : public nsIDOMMozBrowserFrame {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOZBROWSERFRAME_IID)

  /* [infallible] readonly attribute boolean reallyIsBrowserOrApp; */
  NS_IMETHOD GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp) = 0;
  inline bool GetReallyIsBrowserOrApp()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetReallyIsBrowserOrApp(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean reallyIsApp; */
  NS_IMETHOD GetReallyIsApp(bool *aReallyIsApp) = 0;
  inline bool GetReallyIsApp()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetReallyIsApp(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean reallyIsWidget; */
  NS_IMETHOD GetReallyIsWidget(bool *aReallyIsWidget) = 0;
  inline bool GetReallyIsWidget()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetReallyIsWidget(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean isExpectingSystemMessage; */
  NS_IMETHOD GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage) = 0;
  inline bool GetIsExpectingSystemMessage()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsExpectingSystemMessage(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* readonly attribute AString appManifestURL; */
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) = 0;

  /* void disallowCreateFrameLoader (); */
  NS_IMETHOD DisallowCreateFrameLoader(void) = 0;

  /* void allowCreateFrameLoader (); */
  NS_IMETHOD AllowCreateFrameLoader(void) = 0;

  /* void createRemoteFrameLoader (in nsITabParent aTabParent); */
  NS_IMETHOD CreateRemoteFrameLoader(nsITabParent *aTabParent) = 0;

  /* [noscript] void initializeBrowserAPI (); */
  NS_IMETHOD InitializeBrowserAPI(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMozBrowserFrame, NS_IMOZBROWSERFRAME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOZBROWSERFRAME \
  using nsIMozBrowserFrame::GetReallyIsBrowserOrApp; \
  NS_IMETHOD GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp) override; \
  using nsIMozBrowserFrame::GetReallyIsApp; \
  NS_IMETHOD GetReallyIsApp(bool *aReallyIsApp) override; \
  using nsIMozBrowserFrame::GetReallyIsWidget; \
  NS_IMETHOD GetReallyIsWidget(bool *aReallyIsWidget) override; \
  using nsIMozBrowserFrame::GetIsExpectingSystemMessage; \
  NS_IMETHOD GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage) override; \
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) override; \
  NS_IMETHOD DisallowCreateFrameLoader(void) override; \
  NS_IMETHOD AllowCreateFrameLoader(void) override; \
  NS_IMETHOD CreateRemoteFrameLoader(nsITabParent *aTabParent) override; \
  NS_IMETHOD InitializeBrowserAPI(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOZBROWSERFRAME(_to) \
  using nsIMozBrowserFrame::GetReallyIsBrowserOrApp; \
  NS_IMETHOD GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp) override { return _to GetReallyIsBrowserOrApp(aReallyIsBrowserOrApp); } \
  using nsIMozBrowserFrame::GetReallyIsApp; \
  NS_IMETHOD GetReallyIsApp(bool *aReallyIsApp) override { return _to GetReallyIsApp(aReallyIsApp); } \
  using nsIMozBrowserFrame::GetReallyIsWidget; \
  NS_IMETHOD GetReallyIsWidget(bool *aReallyIsWidget) override { return _to GetReallyIsWidget(aReallyIsWidget); } \
  using nsIMozBrowserFrame::GetIsExpectingSystemMessage; \
  NS_IMETHOD GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage) override { return _to GetIsExpectingSystemMessage(aIsExpectingSystemMessage); } \
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) override { return _to GetAppManifestURL(aAppManifestURL); } \
  NS_IMETHOD DisallowCreateFrameLoader(void) override { return _to DisallowCreateFrameLoader(); } \
  NS_IMETHOD AllowCreateFrameLoader(void) override { return _to AllowCreateFrameLoader(); } \
  NS_IMETHOD CreateRemoteFrameLoader(nsITabParent *aTabParent) override { return _to CreateRemoteFrameLoader(aTabParent); } \
  NS_IMETHOD InitializeBrowserAPI(void) override { return _to InitializeBrowserAPI(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOZBROWSERFRAME(_to) \
  NS_IMETHOD GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReallyIsBrowserOrApp(aReallyIsBrowserOrApp); } \
  NS_IMETHOD GetReallyIsApp(bool *aReallyIsApp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReallyIsApp(aReallyIsApp); } \
  NS_IMETHOD GetReallyIsWidget(bool *aReallyIsWidget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReallyIsWidget(aReallyIsWidget); } \
  NS_IMETHOD GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsExpectingSystemMessage(aIsExpectingSystemMessage); } \
  NS_IMETHOD GetAppManifestURL(nsAString & aAppManifestURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppManifestURL(aAppManifestURL); } \
  NS_IMETHOD DisallowCreateFrameLoader(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DisallowCreateFrameLoader(); } \
  NS_IMETHOD AllowCreateFrameLoader(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AllowCreateFrameLoader(); } \
  NS_IMETHOD CreateRemoteFrameLoader(nsITabParent *aTabParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateRemoteFrameLoader(aTabParent); } \
  NS_IMETHOD InitializeBrowserAPI(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InitializeBrowserAPI(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMozBrowserFrame : public nsIMozBrowserFrame
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOZBROWSERFRAME

  nsMozBrowserFrame();

private:
  ~nsMozBrowserFrame();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMozBrowserFrame, nsIMozBrowserFrame)

nsMozBrowserFrame::nsMozBrowserFrame()
{
  /* member initializers and constructor code */
}

nsMozBrowserFrame::~nsMozBrowserFrame()
{
  /* destructor code */
}

/* [infallible] readonly attribute boolean reallyIsBrowserOrApp; */
NS_IMETHODIMP nsMozBrowserFrame::GetReallyIsBrowserOrApp(bool *aReallyIsBrowserOrApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean reallyIsApp; */
NS_IMETHODIMP nsMozBrowserFrame::GetReallyIsApp(bool *aReallyIsApp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean reallyIsWidget; */
NS_IMETHODIMP nsMozBrowserFrame::GetReallyIsWidget(bool *aReallyIsWidget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isExpectingSystemMessage; */
NS_IMETHODIMP nsMozBrowserFrame::GetIsExpectingSystemMessage(bool *aIsExpectingSystemMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString appManifestURL; */
NS_IMETHODIMP nsMozBrowserFrame::GetAppManifestURL(nsAString & aAppManifestURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disallowCreateFrameLoader (); */
NS_IMETHODIMP nsMozBrowserFrame::DisallowCreateFrameLoader()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void allowCreateFrameLoader (); */
NS_IMETHODIMP nsMozBrowserFrame::AllowCreateFrameLoader()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createRemoteFrameLoader (in nsITabParent aTabParent); */
NS_IMETHODIMP nsMozBrowserFrame::CreateRemoteFrameLoader(nsITabParent *aTabParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initializeBrowserAPI (); */
NS_IMETHODIMP nsMozBrowserFrame::InitializeBrowserAPI()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMozBrowserFrame_h__ */
