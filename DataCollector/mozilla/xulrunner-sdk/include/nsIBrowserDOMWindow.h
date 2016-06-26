/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBrowserDOMWindow.idl
 */

#ifndef __gen_nsIBrowserDOMWindow_h__
#define __gen_nsIBrowserDOMWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIFrameLoaderOwner; /* forward declaration */


/* starting interface:    nsIOpenURIInFrameParams */
#define NS_IOPENURIINFRAMEPARAMS_IID_STR "e774db14-79ac-4156-a7a3-aa3fd0a22c10"

#define NS_IOPENURIINFRAMEPARAMS_IID \
  {0xe774db14, 0x79ac, 0x4156, \
    { 0xa7, 0xa3, 0xaa, 0x3f, 0xd0, 0xa2, 0x2c, 0x10 }}

class NS_NO_VTABLE nsIOpenURIInFrameParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOPENURIINFRAMEPARAMS_IID)

  /* attribute DOMString referrer; */
  NS_IMETHOD GetReferrer(nsAString & aReferrer) = 0;
  NS_IMETHOD SetReferrer(const nsAString & aReferrer) = 0;

  /* attribute boolean isPrivate; */
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) = 0;
  NS_IMETHOD SetIsPrivate(bool aIsPrivate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOpenURIInFrameParams, NS_IOPENURIINFRAMEPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOPENURIINFRAMEPARAMS \
  NS_IMETHOD GetReferrer(nsAString & aReferrer) override; \
  NS_IMETHOD SetReferrer(const nsAString & aReferrer) override; \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) override; \
  NS_IMETHOD SetIsPrivate(bool aIsPrivate) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOPENURIINFRAMEPARAMS(_to) \
  NS_IMETHOD GetReferrer(nsAString & aReferrer) override { return _to GetReferrer(aReferrer); } \
  NS_IMETHOD SetReferrer(const nsAString & aReferrer) override { return _to SetReferrer(aReferrer); } \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) override { return _to GetIsPrivate(aIsPrivate); } \
  NS_IMETHOD SetIsPrivate(bool aIsPrivate) override { return _to SetIsPrivate(aIsPrivate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOPENURIINFRAMEPARAMS(_to) \
  NS_IMETHOD GetReferrer(nsAString & aReferrer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_IMETHOD SetReferrer(const nsAString & aReferrer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReferrer(aReferrer); } \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsPrivate(aIsPrivate); } \
  NS_IMETHOD SetIsPrivate(bool aIsPrivate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsPrivate(aIsPrivate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOpenURIInFrameParams : public nsIOpenURIInFrameParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOPENURIINFRAMEPARAMS

  nsOpenURIInFrameParams();

private:
  ~nsOpenURIInFrameParams();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsOpenURIInFrameParams, nsIOpenURIInFrameParams)

nsOpenURIInFrameParams::nsOpenURIInFrameParams()
{
  /* member initializers and constructor code */
}

nsOpenURIInFrameParams::~nsOpenURIInFrameParams()
{
  /* destructor code */
}

/* attribute DOMString referrer; */
NS_IMETHODIMP nsOpenURIInFrameParams::GetReferrer(nsAString & aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsOpenURIInFrameParams::SetReferrer(const nsAString & aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isPrivate; */
NS_IMETHODIMP nsOpenURIInFrameParams::GetIsPrivate(bool *aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsOpenURIInFrameParams::SetIsPrivate(bool aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBrowserDOMWindow */
#define NS_IBROWSERDOMWINDOW_IID_STR "99f5a347-722c-4337-bd38-f14ec94801b3"

#define NS_IBROWSERDOMWINDOW_IID \
  {0x99f5a347, 0x722c, 0x4337, \
    { 0xbd, 0x38, 0xf1, 0x4e, 0xc9, 0x48, 0x01, 0xb3 }}

class NS_NO_VTABLE nsIBrowserDOMWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERDOMWINDOW_IID)

  enum {
    OPEN_DEFAULTWINDOW = 0,
    OPEN_CURRENTWINDOW = 1,
    OPEN_NEWWINDOW = 2,
    OPEN_NEWTAB = 3,
    OPEN_SWITCHTAB = 4,
    OPEN_EXTERNAL = 1,
    OPEN_NEW = 2
  };

  /* nsIDOMWindow openURI (in nsIURI aURI, in nsIDOMWindow aOpener, in short aWhere, in short aContext); */
  NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval) = 0;

  /* nsIFrameLoaderOwner openURIInFrame (in nsIURI aURI, in nsIOpenURIInFrameParams params, in short aWhere, in short aContext); */
  NS_IMETHOD OpenURIInFrame(nsIURI *aURI, nsIOpenURIInFrameParams *params, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval) = 0;

  /* boolean isTabContentWindow (in nsIDOMWindow aWindow); */
  NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserDOMWindow, NS_IBROWSERDOMWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERDOMWINDOW \
  NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval) override; \
  NS_IMETHOD OpenURIInFrame(nsIURI *aURI, nsIOpenURIInFrameParams *params, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval) override; \
  NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERDOMWINDOW(_to) \
  NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval) override { return _to OpenURI(aURI, aOpener, aWhere, aContext, _retval); } \
  NS_IMETHOD OpenURIInFrame(nsIURI *aURI, nsIOpenURIInFrameParams *params, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval) override { return _to OpenURIInFrame(aURI, params, aWhere, aContext, _retval); } \
  NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval) override { return _to IsTabContentWindow(aWindow, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERDOMWINDOW(_to) \
  NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenURI(aURI, aOpener, aWhere, aContext, _retval); } \
  NS_IMETHOD OpenURIInFrame(nsIURI *aURI, nsIOpenURIInFrameParams *params, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenURIInFrame(aURI, params, aWhere, aContext, _retval); } \
  NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsTabContentWindow(aWindow, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserDOMWindow : public nsIBrowserDOMWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERDOMWINDOW

  nsBrowserDOMWindow();

private:
  ~nsBrowserDOMWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsBrowserDOMWindow, nsIBrowserDOMWindow)

nsBrowserDOMWindow::nsBrowserDOMWindow()
{
  /* member initializers and constructor code */
}

nsBrowserDOMWindow::~nsBrowserDOMWindow()
{
  /* destructor code */
}

/* nsIDOMWindow openURI (in nsIURI aURI, in nsIDOMWindow aOpener, in short aWhere, in short aContext); */
NS_IMETHODIMP nsBrowserDOMWindow::OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFrameLoaderOwner openURIInFrame (in nsIURI aURI, in nsIOpenURIInFrameParams params, in short aWhere, in short aContext); */
NS_IMETHODIMP nsBrowserDOMWindow::OpenURIInFrame(nsIURI *aURI, nsIOpenURIInFrameParams *params, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isTabContentWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsBrowserDOMWindow::IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserDOMWindow_h__ */
