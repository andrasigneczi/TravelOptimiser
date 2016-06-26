/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMJSWindow.idl
 */

#ifndef __gen_nsIDOMJSWindow_h__
#define __gen_nsIDOMJSWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMJSWindow */
#define NS_IDOMJSWINDOW_IID_STR "e0f739e3-47e2-4007-af30-181939e97a51"

#define NS_IDOMJSWINDOW_IID \
  {0xe0f739e3, 0x47e2, 0x4007, \
    { 0xaf, 0x30, 0x18, 0x19, 0x39, 0xe9, 0x7a, 0x51 }}

class NS_NO_VTABLE nsIDOMJSWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMJSWINDOW_IID)

  /* void dump (in DOMString str); */
  NS_IMETHOD Dump(const nsAString & str) = 0;

  /* void clearTimeout ([optional] in long handle); */
  NS_IMETHOD ClearTimeout(int32_t handle) = 0;

  /* void clearInterval ([optional] in long handle); */
  NS_IMETHOD ClearInterval(int32_t handle) = 0;

  /* void setResizable (in boolean resizable); */
  NS_IMETHOD SetResizable(bool resizable) = 0;

  /* void captureEvents (); */
  NS_IMETHOD CaptureEvents(void) = 0;

  /* void releaseEvents (); */
  NS_IMETHOD ReleaseEvents(void) = 0;

  /* [binaryname(OpenJS)] nsIDOMWindow open ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
  NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) = 0;

  /* nsIDOMWindow openDialog ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) = 0;

  /* readonly attribute nsIDOMWindow frames; */
  NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) = 0;

  /* [binaryname(ScriptableContent),implicit_jscontext] readonly attribute jsval content; */
  NS_IMETHOD GetScriptableContent(JSContext* cx, JS::MutableHandleValue aContent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMJSWindow, NS_IDOMJSWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMJSWINDOW \
  NS_IMETHOD Dump(const nsAString & str) override; \
  NS_IMETHOD ClearTimeout(int32_t handle) override; \
  NS_IMETHOD ClearInterval(int32_t handle) override; \
  NS_IMETHOD SetResizable(bool resizable) override; \
  NS_IMETHOD CaptureEvents(void) override; \
  NS_IMETHOD ReleaseEvents(void) override; \
  NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) override; \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) override; \
  NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) override; \
  NS_IMETHOD GetScriptableContent(JSContext* cx, JS::MutableHandleValue aContent) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMJSWINDOW(_to) \
  NS_IMETHOD Dump(const nsAString & str) override { return _to Dump(str); } \
  NS_IMETHOD ClearTimeout(int32_t handle) override { return _to ClearTimeout(handle); } \
  NS_IMETHOD ClearInterval(int32_t handle) override { return _to ClearInterval(handle); } \
  NS_IMETHOD SetResizable(bool resizable) override { return _to SetResizable(resizable); } \
  NS_IMETHOD CaptureEvents(void) override { return _to CaptureEvents(); } \
  NS_IMETHOD ReleaseEvents(void) override { return _to ReleaseEvents(); } \
  NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) override { return _to OpenJS(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) override { return _to OpenDialog(url, name, options, _retval); } \
  NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) override { return _to GetFrames(aFrames); } \
  NS_IMETHOD GetScriptableContent(JSContext* cx, JS::MutableHandleValue aContent) override { return _to GetScriptableContent(cx, aContent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMJSWINDOW(_to) \
  NS_IMETHOD Dump(const nsAString & str) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Dump(str); } \
  NS_IMETHOD ClearTimeout(int32_t handle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearTimeout(handle); } \
  NS_IMETHOD ClearInterval(int32_t handle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearInterval(handle); } \
  NS_IMETHOD SetResizable(bool resizable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResizable(resizable); } \
  NS_IMETHOD CaptureEvents(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CaptureEvents(); } \
  NS_IMETHOD ReleaseEvents(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseEvents(); } \
  NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenJS(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDialog(url, name, options, _retval); } \
  NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrames(aFrames); } \
  NS_IMETHOD GetScriptableContent(JSContext* cx, JS::MutableHandleValue aContent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptableContent(cx, aContent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMJSWindow : public nsIDOMJSWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMJSWINDOW

  nsDOMJSWindow();

private:
  ~nsDOMJSWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMJSWindow, nsIDOMJSWindow)

nsDOMJSWindow::nsDOMJSWindow()
{
  /* member initializers and constructor code */
}

nsDOMJSWindow::~nsDOMJSWindow()
{
  /* destructor code */
}

/* void dump (in DOMString str); */
NS_IMETHODIMP nsDOMJSWindow::Dump(const nsAString & str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearTimeout ([optional] in long handle); */
NS_IMETHODIMP nsDOMJSWindow::ClearTimeout(int32_t handle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearInterval ([optional] in long handle); */
NS_IMETHODIMP nsDOMJSWindow::ClearInterval(int32_t handle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setResizable (in boolean resizable); */
NS_IMETHODIMP nsDOMJSWindow::SetResizable(bool resizable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void captureEvents (); */
NS_IMETHODIMP nsDOMJSWindow::CaptureEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseEvents (); */
NS_IMETHODIMP nsDOMJSWindow::ReleaseEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(OpenJS)] nsIDOMWindow open ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
NS_IMETHODIMP nsDOMJSWindow::OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow openDialog ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
NS_IMETHODIMP nsDOMJSWindow::OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow frames; */
NS_IMETHODIMP nsDOMJSWindow::GetFrames(nsIDOMWindow * *aFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableContent),implicit_jscontext] readonly attribute jsval content; */
NS_IMETHODIMP nsDOMJSWindow::GetScriptableContent(JSContext* cx, JS::MutableHandleValue aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMJSWindow_h__ */
