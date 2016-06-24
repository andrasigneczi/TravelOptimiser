/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContentPermissionPrompt.idl
 */

#ifndef __gen_nsIContentPermissionPrompt_h__
#define __gen_nsIContentPermissionPrompt_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrincipal; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIContentPermissionType */
#define NS_ICONTENTPERMISSIONTYPE_IID_STR "ef4db3b8-ca9c-4b1d-8f81-fd88ec32af13"

#define NS_ICONTENTPERMISSIONTYPE_IID \
  {0xef4db3b8, 0xca9c, 0x4b1d, \
    { 0x8f, 0x81, 0xfd, 0x88, 0xec, 0x32, 0xaf, 0x13 }}

class NS_NO_VTABLE nsIContentPermissionType : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONTYPE_IID)

  /* readonly attribute ACString type; */
  NS_IMETHOD GetType(nsACString & aType) = 0;

  /* readonly attribute ACString access; */
  NS_IMETHOD GetAccess(nsACString & aAccess) = 0;

  /* readonly attribute nsIArray options; */
  NS_IMETHOD GetOptions(nsIArray * *aOptions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionType, NS_ICONTENTPERMISSIONTYPE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONTYPE \
  NS_IMETHOD GetType(nsACString & aType) override; \
  NS_IMETHOD GetAccess(nsACString & aAccess) override; \
  NS_IMETHOD GetOptions(nsIArray * *aOptions) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONTYPE(_to) \
  NS_IMETHOD GetType(nsACString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD GetAccess(nsACString & aAccess) override { return _to GetAccess(aAccess); } \
  NS_IMETHOD GetOptions(nsIArray * *aOptions) override { return _to GetOptions(aOptions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONTYPE(_to) \
  NS_IMETHOD GetType(nsACString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetAccess(nsACString & aAccess) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccess(aAccess); } \
  NS_IMETHOD GetOptions(nsIArray * *aOptions) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOptions(aOptions); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPermissionType : public nsIContentPermissionType
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPERMISSIONTYPE

  nsContentPermissionType();

private:
  ~nsContentPermissionType();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentPermissionType, nsIContentPermissionType)

nsContentPermissionType::nsContentPermissionType()
{
  /* member initializers and constructor code */
}

nsContentPermissionType::~nsContentPermissionType()
{
  /* destructor code */
}

/* readonly attribute ACString type; */
NS_IMETHODIMP nsContentPermissionType::GetType(nsACString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString access; */
NS_IMETHODIMP nsContentPermissionType::GetAccess(nsACString & aAccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIArray options; */
NS_IMETHODIMP nsContentPermissionType::GetOptions(nsIArray * *aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPermissionRequestCallback */
#define NS_ICONTENTPERMISSIONREQUESTCALLBACK_IID_STR "5fb5bb60-7069-11e4-9803-0800200c9a66"

#define NS_ICONTENTPERMISSIONREQUESTCALLBACK_IID \
  {0x5fb5bb60, 0x7069, 0x11e4, \
    { 0x98, 0x03, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIContentPermissionRequestCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONREQUESTCALLBACK_IID)

  /* void notifyVisibility (in boolean isVisible); */
  NS_IMETHOD NotifyVisibility(bool isVisible) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionRequestCallback, NS_ICONTENTPERMISSIONREQUESTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONREQUESTCALLBACK \
  NS_IMETHOD NotifyVisibility(bool isVisible) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONREQUESTCALLBACK(_to) \
  NS_IMETHOD NotifyVisibility(bool isVisible) override { return _to NotifyVisibility(isVisible); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONREQUESTCALLBACK(_to) \
  NS_IMETHOD NotifyVisibility(bool isVisible) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyVisibility(isVisible); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPermissionRequestCallback : public nsIContentPermissionRequestCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPERMISSIONREQUESTCALLBACK

  nsContentPermissionRequestCallback();

private:
  ~nsContentPermissionRequestCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentPermissionRequestCallback, nsIContentPermissionRequestCallback)

nsContentPermissionRequestCallback::nsContentPermissionRequestCallback()
{
  /* member initializers and constructor code */
}

nsContentPermissionRequestCallback::~nsContentPermissionRequestCallback()
{
  /* destructor code */
}

/* void notifyVisibility (in boolean isVisible); */
NS_IMETHODIMP nsContentPermissionRequestCallback::NotifyVisibility(bool isVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPermissionRequester */
#define NS_ICONTENTPERMISSIONREQUESTER_IID_STR "f8577124-6a5f-486f-ae04-c5bcae911eb5"

#define NS_ICONTENTPERMISSIONREQUESTER_IID \
  {0xf8577124, 0x6a5f, 0x486f, \
    { 0xae, 0x04, 0xc5, 0xbc, 0xae, 0x91, 0x1e, 0xb5 }}

class NS_NO_VTABLE nsIContentPermissionRequester : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONREQUESTER_IID)

  /* void getVisibility (in nsIContentPermissionRequestCallback callback); */
  NS_IMETHOD GetVisibility(nsIContentPermissionRequestCallback *callback) = 0;

  /* attribute nsIContentPermissionRequestCallback onVisibilityChange; */
  NS_IMETHOD GetOnVisibilityChange(nsIContentPermissionRequestCallback * *aOnVisibilityChange) = 0;
  NS_IMETHOD SetOnVisibilityChange(nsIContentPermissionRequestCallback *aOnVisibilityChange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionRequester, NS_ICONTENTPERMISSIONREQUESTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONREQUESTER \
  NS_IMETHOD GetVisibility(nsIContentPermissionRequestCallback *callback) override; \
  NS_IMETHOD GetOnVisibilityChange(nsIContentPermissionRequestCallback * *aOnVisibilityChange) override; \
  NS_IMETHOD SetOnVisibilityChange(nsIContentPermissionRequestCallback *aOnVisibilityChange) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONREQUESTER(_to) \
  NS_IMETHOD GetVisibility(nsIContentPermissionRequestCallback *callback) override { return _to GetVisibility(callback); } \
  NS_IMETHOD GetOnVisibilityChange(nsIContentPermissionRequestCallback * *aOnVisibilityChange) override { return _to GetOnVisibilityChange(aOnVisibilityChange); } \
  NS_IMETHOD SetOnVisibilityChange(nsIContentPermissionRequestCallback *aOnVisibilityChange) override { return _to SetOnVisibilityChange(aOnVisibilityChange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONREQUESTER(_to) \
  NS_IMETHOD GetVisibility(nsIContentPermissionRequestCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisibility(callback); } \
  NS_IMETHOD GetOnVisibilityChange(nsIContentPermissionRequestCallback * *aOnVisibilityChange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnVisibilityChange(aOnVisibilityChange); } \
  NS_IMETHOD SetOnVisibilityChange(nsIContentPermissionRequestCallback *aOnVisibilityChange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnVisibilityChange(aOnVisibilityChange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPermissionRequester : public nsIContentPermissionRequester
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPERMISSIONREQUESTER

  nsContentPermissionRequester();

private:
  ~nsContentPermissionRequester();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentPermissionRequester, nsIContentPermissionRequester)

nsContentPermissionRequester::nsContentPermissionRequester()
{
  /* member initializers and constructor code */
}

nsContentPermissionRequester::~nsContentPermissionRequester()
{
  /* destructor code */
}

/* void getVisibility (in nsIContentPermissionRequestCallback callback); */
NS_IMETHODIMP nsContentPermissionRequester::GetVisibility(nsIContentPermissionRequestCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIContentPermissionRequestCallback onVisibilityChange; */
NS_IMETHODIMP nsContentPermissionRequester::GetOnVisibilityChange(nsIContentPermissionRequestCallback * *aOnVisibilityChange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContentPermissionRequester::SetOnVisibilityChange(nsIContentPermissionRequestCallback *aOnVisibilityChange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPermissionRequest */
#define NS_ICONTENTPERMISSIONREQUEST_IID_STR "408c8fcd-1420-4aff-94d8-39bf74d79219"

#define NS_ICONTENTPERMISSIONREQUEST_IID \
  {0x408c8fcd, 0x1420, 0x4aff, \
    { 0x94, 0xd8, 0x39, 0xbf, 0x74, 0xd7, 0x92, 0x19 }}

class NS_NO_VTABLE nsIContentPermissionRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONREQUEST_IID)

  /* readonly attribute nsIArray types; */
  NS_IMETHOD GetTypes(nsIArray * *aTypes) = 0;

  /* readonly attribute nsIPrincipal principal; */
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) = 0;

  /* readonly attribute nsIDOMWindow window; */
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) = 0;

  /* readonly attribute nsIDOMElement element; */
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) = 0;

  /* readonly attribute nsIContentPermissionRequester requester; */
  NS_IMETHOD GetRequester(nsIContentPermissionRequester * *aRequester) = 0;

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

  /* void allow ([optional] in jsval choices); */
  NS_IMETHOD Allow(JS::HandleValue choices) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionRequest, NS_ICONTENTPERMISSIONREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONREQUEST \
  NS_IMETHOD GetTypes(nsIArray * *aTypes) override; \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) override; \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override; \
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) override; \
  NS_IMETHOD GetRequester(nsIContentPermissionRequester * *aRequester) override; \
  NS_IMETHOD Cancel(void) override; \
  NS_IMETHOD Allow(JS::HandleValue choices) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONREQUEST(_to) \
  NS_IMETHOD GetTypes(nsIArray * *aTypes) override { return _to GetTypes(aTypes); } \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) override { return _to GetPrincipal(aPrincipal); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override { return _to GetWindow(aWindow); } \
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) override { return _to GetElement(aElement); } \
  NS_IMETHOD GetRequester(nsIContentPermissionRequester * *aRequester) override { return _to GetRequester(aRequester); } \
  NS_IMETHOD Cancel(void) override { return _to Cancel(); } \
  NS_IMETHOD Allow(JS::HandleValue choices) override { return _to Allow(choices); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONREQUEST(_to) \
  NS_IMETHOD GetTypes(nsIArray * *aTypes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypes(aTypes); } \
  NS_IMETHOD GetPrincipal(nsIPrincipal * *aPrincipal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrincipal(aPrincipal); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(aElement); } \
  NS_IMETHOD GetRequester(nsIContentPermissionRequester * *aRequester) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequester(aRequester); } \
  NS_IMETHOD Cancel(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } \
  NS_IMETHOD Allow(JS::HandleValue choices) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Allow(choices); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPermissionRequest : public nsIContentPermissionRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPERMISSIONREQUEST

  nsContentPermissionRequest();

private:
  ~nsContentPermissionRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentPermissionRequest, nsIContentPermissionRequest)

nsContentPermissionRequest::nsContentPermissionRequest()
{
  /* member initializers and constructor code */
}

nsContentPermissionRequest::~nsContentPermissionRequest()
{
  /* destructor code */
}

/* readonly attribute nsIArray types; */
NS_IMETHODIMP nsContentPermissionRequest::GetTypes(nsIArray * *aTypes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrincipal principal; */
NS_IMETHODIMP nsContentPermissionRequest::GetPrincipal(nsIPrincipal * *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow window; */
NS_IMETHODIMP nsContentPermissionRequest::GetWindow(nsIDOMWindow * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement element; */
NS_IMETHODIMP nsContentPermissionRequest::GetElement(nsIDOMElement * *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIContentPermissionRequester requester; */
NS_IMETHODIMP nsContentPermissionRequest::GetRequester(nsIContentPermissionRequester * *aRequester)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsContentPermissionRequest::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void allow ([optional] in jsval choices); */
NS_IMETHODIMP nsContentPermissionRequest::Allow(JS::HandleValue choices)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPermissionPrompt */
#define NS_ICONTENTPERMISSIONPROMPT_IID_STR "f72de90d-e954-4e69-9a61-917303029301"

#define NS_ICONTENTPERMISSIONPROMPT_IID \
  {0xf72de90d, 0xe954, 0x4e69, \
    { 0x9a, 0x61, 0x91, 0x73, 0x03, 0x02, 0x93, 0x01 }}

class NS_NO_VTABLE nsIContentPermissionPrompt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPERMISSIONPROMPT_IID)

  /* void prompt (in nsIContentPermissionRequest request); */
  NS_IMETHOD Prompt(nsIContentPermissionRequest *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPermissionPrompt, NS_ICONTENTPERMISSIONPROMPT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPERMISSIONPROMPT \
  NS_IMETHOD Prompt(nsIContentPermissionRequest *request) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPERMISSIONPROMPT(_to) \
  NS_IMETHOD Prompt(nsIContentPermissionRequest *request) override { return _to Prompt(request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPERMISSIONPROMPT(_to) \
  NS_IMETHOD Prompt(nsIContentPermissionRequest *request) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Prompt(request); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPermissionPrompt : public nsIContentPermissionPrompt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPERMISSIONPROMPT

  nsContentPermissionPrompt();

private:
  ~nsContentPermissionPrompt();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentPermissionPrompt, nsIContentPermissionPrompt)

nsContentPermissionPrompt::nsContentPermissionPrompt()
{
  /* member initializers and constructor code */
}

nsContentPermissionPrompt::~nsContentPermissionPrompt()
{
  /* destructor code */
}

/* void prompt (in nsIContentPermissionRequest request); */
NS_IMETHODIMP nsContentPermissionPrompt::Prompt(nsIContentPermissionRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CONTENT_PERMISSION_PROMPT_CONTRACTID   "@mozilla.org/content-permission/prompt;1"

#endif /* __gen_nsIContentPermissionPrompt_h__ */
