/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMChromeWindow.idl
 */

#ifndef __gen_nsIDOMChromeWindow_h__
#define __gen_nsIDOMChromeWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBrowserDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMEvent; /* forward declaration */

class nsIMessageBroadcaster; /* forward declaration */


/* starting interface:    nsIDOMChromeWindow */
#define NS_IDOMCHROMEWINDOW_IID_STR "78bdcb41-1efa-409f-aaba-70842213f80f"

#define NS_IDOMCHROMEWINDOW_IID \
  {0x78bdcb41, 0x1efa, 0x409f, \
    { 0xaa, 0xba, 0x70, 0x84, 0x22, 0x13, 0xf8, 0x0f }}

class NS_NO_VTABLE nsIDOMChromeWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCHROMEWINDOW_IID)

  enum {
    STATE_MAXIMIZED = 1U,
    STATE_MINIMIZED = 2U,
    STATE_NORMAL = 3U,
    STATE_FULLSCREEN = 4U
  };

  /* readonly attribute unsigned short windowState; */
  NS_IMETHOD GetWindowState(uint16_t *aWindowState) = 0;

  /* attribute nsIBrowserDOMWindow browserDOMWindow; */
  NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow) = 0;
  NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow) = 0;

  /* void getAttention (); */
  NS_IMETHOD GetAttention(void) = 0;

  /* void getAttentionWithCycleCount (in long aCycleCount); */
  NS_IMETHOD GetAttentionWithCycleCount(int32_t aCycleCount) = 0;

  /* void setCursor (in DOMString cursor); */
  NS_IMETHOD SetCursor(const nsAString & cursor) = 0;

  /* void maximize (); */
  NS_IMETHOD Maximize(void) = 0;

  /* void minimize (); */
  NS_IMETHOD Minimize(void) = 0;

  /* void restore (); */
  NS_IMETHOD Restore(void) = 0;

  /* void notifyDefaultButtonLoaded (in nsIDOMElement defaultButton); */
  NS_IMETHOD NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton) = 0;

  /* readonly attribute nsIMessageBroadcaster messageManager; */
  NS_IMETHOD GetMessageManager(nsIMessageBroadcaster * *aMessageManager) = 0;

  /* nsIMessageBroadcaster getGroupMessageManager (in AString group); */
  NS_IMETHOD GetGroupMessageManager(const nsAString & group, nsIMessageBroadcaster * *_retval) = 0;

  /* void beginWindowMove (in nsIDOMEvent mouseDownEvent, [optional] in nsIDOMElement panel); */
  NS_IMETHOD BeginWindowMove(nsIDOMEvent *mouseDownEvent, nsIDOMElement *panel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMChromeWindow, NS_IDOMCHROMEWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCHROMEWINDOW \
  NS_IMETHOD GetWindowState(uint16_t *aWindowState) override; \
  NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow) override; \
  NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow) override; \
  NS_IMETHOD GetAttention(void) override; \
  NS_IMETHOD GetAttentionWithCycleCount(int32_t aCycleCount) override; \
  NS_IMETHOD SetCursor(const nsAString & cursor) override; \
  NS_IMETHOD Maximize(void) override; \
  NS_IMETHOD Minimize(void) override; \
  NS_IMETHOD Restore(void) override; \
  NS_IMETHOD NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton) override; \
  NS_IMETHOD GetMessageManager(nsIMessageBroadcaster * *aMessageManager) override; \
  NS_IMETHOD GetGroupMessageManager(const nsAString & group, nsIMessageBroadcaster * *_retval) override; \
  NS_IMETHOD BeginWindowMove(nsIDOMEvent *mouseDownEvent, nsIDOMElement *panel) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCHROMEWINDOW(_to) \
  NS_IMETHOD GetWindowState(uint16_t *aWindowState) override { return _to GetWindowState(aWindowState); } \
  NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow) override { return _to GetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow) override { return _to SetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_IMETHOD GetAttention(void) override { return _to GetAttention(); } \
  NS_IMETHOD GetAttentionWithCycleCount(int32_t aCycleCount) override { return _to GetAttentionWithCycleCount(aCycleCount); } \
  NS_IMETHOD SetCursor(const nsAString & cursor) override { return _to SetCursor(cursor); } \
  NS_IMETHOD Maximize(void) override { return _to Maximize(); } \
  NS_IMETHOD Minimize(void) override { return _to Minimize(); } \
  NS_IMETHOD Restore(void) override { return _to Restore(); } \
  NS_IMETHOD NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton) override { return _to NotifyDefaultButtonLoaded(defaultButton); } \
  NS_IMETHOD GetMessageManager(nsIMessageBroadcaster * *aMessageManager) override { return _to GetMessageManager(aMessageManager); } \
  NS_IMETHOD GetGroupMessageManager(const nsAString & group, nsIMessageBroadcaster * *_retval) override { return _to GetGroupMessageManager(group, _retval); } \
  NS_IMETHOD BeginWindowMove(nsIDOMEvent *mouseDownEvent, nsIDOMElement *panel) override { return _to BeginWindowMove(mouseDownEvent, panel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCHROMEWINDOW(_to) \
  NS_IMETHOD GetWindowState(uint16_t *aWindowState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowState(aWindowState); } \
  NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_IMETHOD GetAttention(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttention(); } \
  NS_IMETHOD GetAttentionWithCycleCount(int32_t aCycleCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttentionWithCycleCount(aCycleCount); } \
  NS_IMETHOD SetCursor(const nsAString & cursor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCursor(cursor); } \
  NS_IMETHOD Maximize(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Maximize(); } \
  NS_IMETHOD Minimize(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Minimize(); } \
  NS_IMETHOD Restore(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Restore(); } \
  NS_IMETHOD NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDefaultButtonLoaded(defaultButton); } \
  NS_IMETHOD GetMessageManager(nsIMessageBroadcaster * *aMessageManager) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageManager(aMessageManager); } \
  NS_IMETHOD GetGroupMessageManager(const nsAString & group, nsIMessageBroadcaster * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGroupMessageManager(group, _retval); } \
  NS_IMETHOD BeginWindowMove(nsIDOMEvent *mouseDownEvent, nsIDOMElement *panel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginWindowMove(mouseDownEvent, panel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMChromeWindow : public nsIDOMChromeWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCHROMEWINDOW

  nsDOMChromeWindow();

private:
  ~nsDOMChromeWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMChromeWindow, nsIDOMChromeWindow)

nsDOMChromeWindow::nsDOMChromeWindow()
{
  /* member initializers and constructor code */
}

nsDOMChromeWindow::~nsDOMChromeWindow()
{
  /* destructor code */
}

/* readonly attribute unsigned short windowState; */
NS_IMETHODIMP nsDOMChromeWindow::GetWindowState(uint16_t *aWindowState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIBrowserDOMWindow browserDOMWindow; */
NS_IMETHODIMP nsDOMChromeWindow::GetBrowserDOMWindow(nsIBrowserDOMWindow * *aBrowserDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMChromeWindow::SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttention (); */
NS_IMETHODIMP nsDOMChromeWindow::GetAttention()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttentionWithCycleCount (in long aCycleCount); */
NS_IMETHODIMP nsDOMChromeWindow::GetAttentionWithCycleCount(int32_t aCycleCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCursor (in DOMString cursor); */
NS_IMETHODIMP nsDOMChromeWindow::SetCursor(const nsAString & cursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void maximize (); */
NS_IMETHODIMP nsDOMChromeWindow::Maximize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void minimize (); */
NS_IMETHODIMP nsDOMChromeWindow::Minimize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restore (); */
NS_IMETHODIMP nsDOMChromeWindow::Restore()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDefaultButtonLoaded (in nsIDOMElement defaultButton); */
NS_IMETHODIMP nsDOMChromeWindow::NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMessageBroadcaster messageManager; */
NS_IMETHODIMP nsDOMChromeWindow::GetMessageManager(nsIMessageBroadcaster * *aMessageManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMessageBroadcaster getGroupMessageManager (in AString group); */
NS_IMETHODIMP nsDOMChromeWindow::GetGroupMessageManager(const nsAString & group, nsIMessageBroadcaster * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginWindowMove (in nsIDOMEvent mouseDownEvent, [optional] in nsIDOMElement panel); */
NS_IMETHODIMP nsDOMChromeWindow::BeginWindowMove(nsIDOMEvent *mouseDownEvent, nsIDOMElement *panel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMChromeWindow_h__ */
