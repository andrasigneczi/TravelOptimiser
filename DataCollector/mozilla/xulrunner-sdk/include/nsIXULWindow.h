/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXULWindow.idl
 */

#ifndef __gen_nsIXULWindow_h__
#define __gen_nsIXULWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsIDocShellTreeItem; /* forward declaration */

class nsIXULBrowserWindow; /* forward declaration */

class nsITabParent; /* forward declaration */


/* starting interface:    nsIXULWindow */
#define NS_IXULWINDOW_IID_STR "a68a40b9-f7df-47ff-a874-2af3df7eb888"

#define NS_IXULWINDOW_IID \
  {0xa68a40b9, 0xf7df, 0x47ff, \
    { 0xa8, 0x74, 0x2a, 0xf3, 0xdf, 0x7e, 0xb8, 0x88 }}

class NS_NO_VTABLE nsIXULWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULWINDOW_IID)

  /* readonly attribute nsIDocShell docShell; */
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) = 0;

  /* attribute boolean intrinsicallySized; */
  NS_IMETHOD GetIntrinsicallySized(bool *aIntrinsicallySized) = 0;
  NS_IMETHOD SetIntrinsicallySized(bool aIntrinsicallySized) = 0;

  /* readonly attribute nsIDocShellTreeItem primaryContentShell; */
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) = 0;

  /* nsIDocShellTreeItem getContentShellById (in wstring ID); */
  NS_IMETHOD GetContentShellById(const char16_t * ID, nsIDocShellTreeItem * *_retval) = 0;

  /* void addChildWindow (in nsIXULWindow aChild); */
  NS_IMETHOD AddChildWindow(nsIXULWindow *aChild) = 0;

  /* void removeChildWindow (in nsIXULWindow aChild); */
  NS_IMETHOD RemoveChildWindow(nsIXULWindow *aChild) = 0;

  /* void center (in nsIXULWindow aRelative, in boolean aScreen, in boolean aAlert); */
  NS_IMETHOD Center(nsIXULWindow *aRelative, bool aScreen, bool aAlert) = 0;

  /* void showModal (); */
  NS_IMETHOD ShowModal(void) = 0;

  enum {
    lowestZ = 0U,
    loweredZ = 4U,
    normalZ = 5U,
    raisedZ = 6U,
    highestZ = 9U
  };

  /* attribute unsigned long zLevel; */
  NS_IMETHOD GetZLevel(uint32_t *aZLevel) = 0;
  NS_IMETHOD SetZLevel(uint32_t aZLevel) = 0;

  /* attribute uint32_t contextFlags; */
  NS_IMETHOD GetContextFlags(uint32_t *aContextFlags) = 0;
  NS_IMETHOD SetContextFlags(uint32_t aContextFlags) = 0;

  /* attribute uint32_t chromeFlags; */
  NS_IMETHOD GetChromeFlags(uint32_t *aChromeFlags) = 0;
  NS_IMETHOD SetChromeFlags(uint32_t aChromeFlags) = 0;

  /* void assumeChromeFlagsAreFrozen (); */
  NS_IMETHOD AssumeChromeFlagsAreFrozen(void) = 0;

  /* nsIXULWindow createNewWindow (in int32_t aChromeFlags, in nsITabParent aOpeningTab); */
  NS_IMETHOD CreateNewWindow(int32_t aChromeFlags, nsITabParent *aOpeningTab, nsIXULWindow * *_retval) = 0;

  /* attribute nsIXULBrowserWindow XULBrowserWindow; */
  NS_IMETHOD GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow) = 0;
  NS_IMETHOD SetXULBrowserWindow(nsIXULBrowserWindow *aXULBrowserWindow) = 0;

  /* [noscript] void applyChromeFlags (); */
  NS_IMETHOD ApplyChromeFlags(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULWindow, NS_IXULWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULWINDOW \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) override; \
  NS_IMETHOD GetIntrinsicallySized(bool *aIntrinsicallySized) override; \
  NS_IMETHOD SetIntrinsicallySized(bool aIntrinsicallySized) override; \
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) override; \
  NS_IMETHOD GetContentShellById(const char16_t * ID, nsIDocShellTreeItem * *_retval) override; \
  NS_IMETHOD AddChildWindow(nsIXULWindow *aChild) override; \
  NS_IMETHOD RemoveChildWindow(nsIXULWindow *aChild) override; \
  NS_IMETHOD Center(nsIXULWindow *aRelative, bool aScreen, bool aAlert) override; \
  NS_IMETHOD ShowModal(void) override; \
  NS_IMETHOD GetZLevel(uint32_t *aZLevel) override; \
  NS_IMETHOD SetZLevel(uint32_t aZLevel) override; \
  NS_IMETHOD GetContextFlags(uint32_t *aContextFlags) override; \
  NS_IMETHOD SetContextFlags(uint32_t aContextFlags) override; \
  NS_IMETHOD GetChromeFlags(uint32_t *aChromeFlags) override; \
  NS_IMETHOD SetChromeFlags(uint32_t aChromeFlags) override; \
  NS_IMETHOD AssumeChromeFlagsAreFrozen(void) override; \
  NS_IMETHOD CreateNewWindow(int32_t aChromeFlags, nsITabParent *aOpeningTab, nsIXULWindow * *_retval) override; \
  NS_IMETHOD GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow) override; \
  NS_IMETHOD SetXULBrowserWindow(nsIXULBrowserWindow *aXULBrowserWindow) override; \
  NS_IMETHOD ApplyChromeFlags(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULWINDOW(_to) \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) override { return _to GetDocShell(aDocShell); } \
  NS_IMETHOD GetIntrinsicallySized(bool *aIntrinsicallySized) override { return _to GetIntrinsicallySized(aIntrinsicallySized); } \
  NS_IMETHOD SetIntrinsicallySized(bool aIntrinsicallySized) override { return _to SetIntrinsicallySized(aIntrinsicallySized); } \
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) override { return _to GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_IMETHOD GetContentShellById(const char16_t * ID, nsIDocShellTreeItem * *_retval) override { return _to GetContentShellById(ID, _retval); } \
  NS_IMETHOD AddChildWindow(nsIXULWindow *aChild) override { return _to AddChildWindow(aChild); } \
  NS_IMETHOD RemoveChildWindow(nsIXULWindow *aChild) override { return _to RemoveChildWindow(aChild); } \
  NS_IMETHOD Center(nsIXULWindow *aRelative, bool aScreen, bool aAlert) override { return _to Center(aRelative, aScreen, aAlert); } \
  NS_IMETHOD ShowModal(void) override { return _to ShowModal(); } \
  NS_IMETHOD GetZLevel(uint32_t *aZLevel) override { return _to GetZLevel(aZLevel); } \
  NS_IMETHOD SetZLevel(uint32_t aZLevel) override { return _to SetZLevel(aZLevel); } \
  NS_IMETHOD GetContextFlags(uint32_t *aContextFlags) override { return _to GetContextFlags(aContextFlags); } \
  NS_IMETHOD SetContextFlags(uint32_t aContextFlags) override { return _to SetContextFlags(aContextFlags); } \
  NS_IMETHOD GetChromeFlags(uint32_t *aChromeFlags) override { return _to GetChromeFlags(aChromeFlags); } \
  NS_IMETHOD SetChromeFlags(uint32_t aChromeFlags) override { return _to SetChromeFlags(aChromeFlags); } \
  NS_IMETHOD AssumeChromeFlagsAreFrozen(void) override { return _to AssumeChromeFlagsAreFrozen(); } \
  NS_IMETHOD CreateNewWindow(int32_t aChromeFlags, nsITabParent *aOpeningTab, nsIXULWindow * *_retval) override { return _to CreateNewWindow(aChromeFlags, aOpeningTab, _retval); } \
  NS_IMETHOD GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow) override { return _to GetXULBrowserWindow(aXULBrowserWindow); } \
  NS_IMETHOD SetXULBrowserWindow(nsIXULBrowserWindow *aXULBrowserWindow) override { return _to SetXULBrowserWindow(aXULBrowserWindow); } \
  NS_IMETHOD ApplyChromeFlags(void) override { return _to ApplyChromeFlags(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULWINDOW(_to) \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShell(aDocShell); } \
  NS_IMETHOD GetIntrinsicallySized(bool *aIntrinsicallySized) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIntrinsicallySized(aIntrinsicallySized); } \
  NS_IMETHOD SetIntrinsicallySized(bool aIntrinsicallySized) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIntrinsicallySized(aIntrinsicallySized); } \
  NS_IMETHOD GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrimaryContentShell(aPrimaryContentShell); } \
  NS_IMETHOD GetContentShellById(const char16_t * ID, nsIDocShellTreeItem * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentShellById(ID, _retval); } \
  NS_IMETHOD AddChildWindow(nsIXULWindow *aChild) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddChildWindow(aChild); } \
  NS_IMETHOD RemoveChildWindow(nsIXULWindow *aChild) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChildWindow(aChild); } \
  NS_IMETHOD Center(nsIXULWindow *aRelative, bool aScreen, bool aAlert) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Center(aRelative, aScreen, aAlert); } \
  NS_IMETHOD ShowModal(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowModal(); } \
  NS_IMETHOD GetZLevel(uint32_t *aZLevel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZLevel(aZLevel); } \
  NS_IMETHOD SetZLevel(uint32_t aZLevel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetZLevel(aZLevel); } \
  NS_IMETHOD GetContextFlags(uint32_t *aContextFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContextFlags(aContextFlags); } \
  NS_IMETHOD SetContextFlags(uint32_t aContextFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContextFlags(aContextFlags); } \
  NS_IMETHOD GetChromeFlags(uint32_t *aChromeFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChromeFlags(aChromeFlags); } \
  NS_IMETHOD SetChromeFlags(uint32_t aChromeFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChromeFlags(aChromeFlags); } \
  NS_IMETHOD AssumeChromeFlagsAreFrozen(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AssumeChromeFlagsAreFrozen(); } \
  NS_IMETHOD CreateNewWindow(int32_t aChromeFlags, nsITabParent *aOpeningTab, nsIXULWindow * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNewWindow(aChromeFlags, aOpeningTab, _retval); } \
  NS_IMETHOD GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXULBrowserWindow(aXULBrowserWindow); } \
  NS_IMETHOD SetXULBrowserWindow(nsIXULBrowserWindow *aXULBrowserWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetXULBrowserWindow(aXULBrowserWindow); } \
  NS_IMETHOD ApplyChromeFlags(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplyChromeFlags(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULWindow : public nsIXULWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULWINDOW

  nsXULWindow();

private:
  ~nsXULWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXULWindow, nsIXULWindow)

nsXULWindow::nsXULWindow()
{
  /* member initializers and constructor code */
}

nsXULWindow::~nsXULWindow()
{
  /* destructor code */
}

/* readonly attribute nsIDocShell docShell; */
NS_IMETHODIMP nsXULWindow::GetDocShell(nsIDocShell * *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean intrinsicallySized; */
NS_IMETHODIMP nsXULWindow::GetIntrinsicallySized(bool *aIntrinsicallySized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetIntrinsicallySized(bool aIntrinsicallySized)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShellTreeItem primaryContentShell; */
NS_IMETHODIMP nsXULWindow::GetPrimaryContentShell(nsIDocShellTreeItem * *aPrimaryContentShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDocShellTreeItem getContentShellById (in wstring ID); */
NS_IMETHODIMP nsXULWindow::GetContentShellById(const char16_t * ID, nsIDocShellTreeItem * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addChildWindow (in nsIXULWindow aChild); */
NS_IMETHODIMP nsXULWindow::AddChildWindow(nsIXULWindow *aChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeChildWindow (in nsIXULWindow aChild); */
NS_IMETHODIMP nsXULWindow::RemoveChildWindow(nsIXULWindow *aChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void center (in nsIXULWindow aRelative, in boolean aScreen, in boolean aAlert); */
NS_IMETHODIMP nsXULWindow::Center(nsIXULWindow *aRelative, bool aScreen, bool aAlert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showModal (); */
NS_IMETHODIMP nsXULWindow::ShowModal()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long zLevel; */
NS_IMETHODIMP nsXULWindow::GetZLevel(uint32_t *aZLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetZLevel(uint32_t aZLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute uint32_t contextFlags; */
NS_IMETHODIMP nsXULWindow::GetContextFlags(uint32_t *aContextFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetContextFlags(uint32_t aContextFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute uint32_t chromeFlags; */
NS_IMETHODIMP nsXULWindow::GetChromeFlags(uint32_t *aChromeFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetChromeFlags(uint32_t aChromeFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void assumeChromeFlagsAreFrozen (); */
NS_IMETHODIMP nsXULWindow::AssumeChromeFlagsAreFrozen()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXULWindow createNewWindow (in int32_t aChromeFlags, in nsITabParent aOpeningTab); */
NS_IMETHODIMP nsXULWindow::CreateNewWindow(int32_t aChromeFlags, nsITabParent *aOpeningTab, nsIXULWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIXULBrowserWindow XULBrowserWindow; */
NS_IMETHODIMP nsXULWindow::GetXULBrowserWindow(nsIXULBrowserWindow * *aXULBrowserWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULWindow::SetXULBrowserWindow(nsIXULBrowserWindow *aXULBrowserWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void applyChromeFlags (); */
NS_IMETHODIMP nsXULWindow::ApplyChromeFlags()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULWindow_h__ */
