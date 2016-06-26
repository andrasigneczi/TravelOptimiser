/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFocusManager.idl
 */

#ifndef __gen_nsIFocusManager_h__
#define __gen_nsIFocusManager_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocument; /* forward declaration */

class nsIContent; /* forward declaration */


/* starting interface:    nsIFocusManager */
#define NS_IFOCUSMANAGER_IID_STR "c0716002-5602-4002-a0de-cc69b924b2c6"

#define NS_IFOCUSMANAGER_IID \
  {0xc0716002, 0x5602, 0x4002, \
    { 0xa0, 0xde, 0xcc, 0x69, 0xb9, 0x24, 0xb2, 0xc6 }}

class NS_NO_VTABLE nsIFocusManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFOCUSMANAGER_IID)

  /* attribute nsIDOMWindow activeWindow; */
  NS_IMETHOD GetActiveWindow(nsIDOMWindow * *aActiveWindow) = 0;
  NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) = 0;

  /* attribute nsIDOMWindow focusedWindow; */
  NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) = 0;
  NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) = 0;

  /* readonly attribute nsIDOMElement focusedElement; */
  NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) = 0;

  /* uint32_t getLastFocusMethod (in nsIDOMWindow window); */
  NS_IMETHOD GetLastFocusMethod(nsIDOMWindow *window, uint32_t *_retval) = 0;

  /* void setFocus (in nsIDOMElement aElement, in unsigned long aFlags); */
  NS_IMETHOD SetFocus(nsIDOMElement *aElement, uint32_t aFlags) = 0;

  /* nsIDOMElement moveFocus (in nsIDOMWindow aWindow, in nsIDOMElement aStartElement, in unsigned long aType, in unsigned long aFlags); */
  NS_IMETHOD MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, uint32_t aType, uint32_t aFlags, nsIDOMElement * *_retval) = 0;

  /* void clearFocus (in nsIDOMWindow aWindow); */
  NS_IMETHOD ClearFocus(nsIDOMWindow *aWindow) = 0;

  /* nsIDOMElement getFocusedElementForWindow (in nsIDOMWindow aWindow, in boolean aDeep, out nsIDOMWindow aFocusedWindow); */
  NS_IMETHOD GetFocusedElementForWindow(nsIDOMWindow *aWindow, bool aDeep, nsIDOMWindow * *aFocusedWindow, nsIDOMElement * *_retval) = 0;

  /* void moveCaretToFocus (in nsIDOMWindow aWindow); */
  NS_IMETHOD MoveCaretToFocus(nsIDOMWindow *aWindow) = 0;

  /* boolean elementIsFocusable (in nsIDOMElement aElement, in unsigned long aFlags); */
  NS_IMETHOD ElementIsFocusable(nsIDOMElement *aElement, uint32_t aFlags, bool *_retval) = 0;

  enum {
    FLAG_RAISE = 1U,
    FLAG_NOSCROLL = 2U,
    FLAG_NOSWITCHFRAME = 4U,
    FLAG_NOPARENTFRAME = 8U,
    FLAG_BYMOUSE = 4096U,
    FLAG_BYKEY = 8192U,
    FLAG_BYMOVEFOCUS = 16384U,
    FLAG_SHOWRING = 1048576U,
    MOVEFOCUS_FORWARD = 1U,
    MOVEFOCUS_BACKWARD = 2U,
    MOVEFOCUS_FORWARDDOC = 3U,
    MOVEFOCUS_BACKWARDDOC = 4U,
    MOVEFOCUS_FIRST = 5U,
    MOVEFOCUS_LAST = 6U,
    MOVEFOCUS_ROOT = 7U,
    MOVEFOCUS_CARET = 8U
  };

  /* [noscript] void windowRaised (in nsIDOMWindow aWindow); */
  NS_IMETHOD WindowRaised(nsIDOMWindow *aWindow) = 0;

  /* [noscript] void windowLowered (in nsIDOMWindow aWindow); */
  NS_IMETHOD WindowLowered(nsIDOMWindow *aWindow) = 0;

  /* [noscript] void windowShown (in nsIDOMWindow aWindow, in boolean aNeedsFocus); */
  NS_IMETHOD WindowShown(nsIDOMWindow *aWindow, bool aNeedsFocus) = 0;

  /* [noscript] void windowHidden (in nsIDOMWindow aWindow); */
  NS_IMETHOD WindowHidden(nsIDOMWindow *aWindow) = 0;

  /* [noscript] void fireDelayedEvents (in nsIDocument aDocument); */
  NS_IMETHOD FireDelayedEvents(nsIDocument *aDocument) = 0;

  /* [noscript] void focusPlugin (in nsIContent aPlugin); */
  NS_IMETHOD FocusPlugin(nsIContent *aPlugin) = 0;

  /* [noscript] void parentActivated (in nsIDOMWindow aWindow, in bool active); */
  NS_IMETHOD ParentActivated(nsIDOMWindow *aWindow, bool active) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFocusManager, NS_IFOCUSMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFOCUSMANAGER \
  NS_IMETHOD GetActiveWindow(nsIDOMWindow * *aActiveWindow) override; \
  NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) override; \
  NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) override; \
  NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) override; \
  NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) override; \
  NS_IMETHOD GetLastFocusMethod(nsIDOMWindow *window, uint32_t *_retval) override; \
  NS_IMETHOD SetFocus(nsIDOMElement *aElement, uint32_t aFlags) override; \
  NS_IMETHOD MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, uint32_t aType, uint32_t aFlags, nsIDOMElement * *_retval) override; \
  NS_IMETHOD ClearFocus(nsIDOMWindow *aWindow) override; \
  NS_IMETHOD GetFocusedElementForWindow(nsIDOMWindow *aWindow, bool aDeep, nsIDOMWindow * *aFocusedWindow, nsIDOMElement * *_retval) override; \
  NS_IMETHOD MoveCaretToFocus(nsIDOMWindow *aWindow) override; \
  NS_IMETHOD ElementIsFocusable(nsIDOMElement *aElement, uint32_t aFlags, bool *_retval) override; \
  NS_IMETHOD WindowRaised(nsIDOMWindow *aWindow) override; \
  NS_IMETHOD WindowLowered(nsIDOMWindow *aWindow) override; \
  NS_IMETHOD WindowShown(nsIDOMWindow *aWindow, bool aNeedsFocus) override; \
  NS_IMETHOD WindowHidden(nsIDOMWindow *aWindow) override; \
  NS_IMETHOD FireDelayedEvents(nsIDocument *aDocument) override; \
  NS_IMETHOD FocusPlugin(nsIContent *aPlugin) override; \
  NS_IMETHOD ParentActivated(nsIDOMWindow *aWindow, bool active) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFOCUSMANAGER(_to) \
  NS_IMETHOD GetActiveWindow(nsIDOMWindow * *aActiveWindow) override { return _to GetActiveWindow(aActiveWindow); } \
  NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) override { return _to SetActiveWindow(aActiveWindow); } \
  NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) override { return _to GetFocusedWindow(aFocusedWindow); } \
  NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) override { return _to SetFocusedWindow(aFocusedWindow); } \
  NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) override { return _to GetFocusedElement(aFocusedElement); } \
  NS_IMETHOD GetLastFocusMethod(nsIDOMWindow *window, uint32_t *_retval) override { return _to GetLastFocusMethod(window, _retval); } \
  NS_IMETHOD SetFocus(nsIDOMElement *aElement, uint32_t aFlags) override { return _to SetFocus(aElement, aFlags); } \
  NS_IMETHOD MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, uint32_t aType, uint32_t aFlags, nsIDOMElement * *_retval) override { return _to MoveFocus(aWindow, aStartElement, aType, aFlags, _retval); } \
  NS_IMETHOD ClearFocus(nsIDOMWindow *aWindow) override { return _to ClearFocus(aWindow); } \
  NS_IMETHOD GetFocusedElementForWindow(nsIDOMWindow *aWindow, bool aDeep, nsIDOMWindow * *aFocusedWindow, nsIDOMElement * *_retval) override { return _to GetFocusedElementForWindow(aWindow, aDeep, aFocusedWindow, _retval); } \
  NS_IMETHOD MoveCaretToFocus(nsIDOMWindow *aWindow) override { return _to MoveCaretToFocus(aWindow); } \
  NS_IMETHOD ElementIsFocusable(nsIDOMElement *aElement, uint32_t aFlags, bool *_retval) override { return _to ElementIsFocusable(aElement, aFlags, _retval); } \
  NS_IMETHOD WindowRaised(nsIDOMWindow *aWindow) override { return _to WindowRaised(aWindow); } \
  NS_IMETHOD WindowLowered(nsIDOMWindow *aWindow) override { return _to WindowLowered(aWindow); } \
  NS_IMETHOD WindowShown(nsIDOMWindow *aWindow, bool aNeedsFocus) override { return _to WindowShown(aWindow, aNeedsFocus); } \
  NS_IMETHOD WindowHidden(nsIDOMWindow *aWindow) override { return _to WindowHidden(aWindow); } \
  NS_IMETHOD FireDelayedEvents(nsIDocument *aDocument) override { return _to FireDelayedEvents(aDocument); } \
  NS_IMETHOD FocusPlugin(nsIContent *aPlugin) override { return _to FocusPlugin(aPlugin); } \
  NS_IMETHOD ParentActivated(nsIDOMWindow *aWindow, bool active) override { return _to ParentActivated(aWindow, active); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFOCUSMANAGER(_to) \
  NS_IMETHOD GetActiveWindow(nsIDOMWindow * *aActiveWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveWindow(aActiveWindow); } \
  NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetActiveWindow(aActiveWindow); } \
  NS_IMETHOD GetFocusedWindow(nsIDOMWindow * *aFocusedWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedWindow(aFocusedWindow); } \
  NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusedWindow(aFocusedWindow); } \
  NS_IMETHOD GetFocusedElement(nsIDOMElement * *aFocusedElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedElement(aFocusedElement); } \
  NS_IMETHOD GetLastFocusMethod(nsIDOMWindow *window, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastFocusMethod(window, _retval); } \
  NS_IMETHOD SetFocus(nsIDOMElement *aElement, uint32_t aFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocus(aElement, aFlags); } \
  NS_IMETHOD MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, uint32_t aType, uint32_t aFlags, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveFocus(aWindow, aStartElement, aType, aFlags, _retval); } \
  NS_IMETHOD ClearFocus(nsIDOMWindow *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearFocus(aWindow); } \
  NS_IMETHOD GetFocusedElementForWindow(nsIDOMWindow *aWindow, bool aDeep, nsIDOMWindow * *aFocusedWindow, nsIDOMElement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedElementForWindow(aWindow, aDeep, aFocusedWindow, _retval); } \
  NS_IMETHOD MoveCaretToFocus(nsIDOMWindow *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveCaretToFocus(aWindow); } \
  NS_IMETHOD ElementIsFocusable(nsIDOMElement *aElement, uint32_t aFlags, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ElementIsFocusable(aElement, aFlags, _retval); } \
  NS_IMETHOD WindowRaised(nsIDOMWindow *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowRaised(aWindow); } \
  NS_IMETHOD WindowLowered(nsIDOMWindow *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowLowered(aWindow); } \
  NS_IMETHOD WindowShown(nsIDOMWindow *aWindow, bool aNeedsFocus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowShown(aWindow, aNeedsFocus); } \
  NS_IMETHOD WindowHidden(nsIDOMWindow *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowHidden(aWindow); } \
  NS_IMETHOD FireDelayedEvents(nsIDocument *aDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FireDelayedEvents(aDocument); } \
  NS_IMETHOD FocusPlugin(nsIContent *aPlugin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FocusPlugin(aPlugin); } \
  NS_IMETHOD ParentActivated(nsIDOMWindow *aWindow, bool active) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ParentActivated(aWindow, active); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFocusManager : public nsIFocusManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFOCUSMANAGER

  nsFocusManager();

private:
  ~nsFocusManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsFocusManager, nsIFocusManager)

nsFocusManager::nsFocusManager()
{
  /* member initializers and constructor code */
}

nsFocusManager::~nsFocusManager()
{
  /* destructor code */
}

/* attribute nsIDOMWindow activeWindow; */
NS_IMETHODIMP nsFocusManager::GetActiveWindow(nsIDOMWindow * *aActiveWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFocusManager::SetActiveWindow(nsIDOMWindow *aActiveWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindow focusedWindow; */
NS_IMETHODIMP nsFocusManager::GetFocusedWindow(nsIDOMWindow * *aFocusedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFocusManager::SetFocusedWindow(nsIDOMWindow *aFocusedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement focusedElement; */
NS_IMETHODIMP nsFocusManager::GetFocusedElement(nsIDOMElement * *aFocusedElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t getLastFocusMethod (in nsIDOMWindow window); */
NS_IMETHODIMP nsFocusManager::GetLastFocusMethod(nsIDOMWindow *window, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFocus (in nsIDOMElement aElement, in unsigned long aFlags); */
NS_IMETHODIMP nsFocusManager::SetFocus(nsIDOMElement *aElement, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement moveFocus (in nsIDOMWindow aWindow, in nsIDOMElement aStartElement, in unsigned long aType, in unsigned long aFlags); */
NS_IMETHODIMP nsFocusManager::MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, uint32_t aType, uint32_t aFlags, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearFocus (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::ClearFocus(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getFocusedElementForWindow (in nsIDOMWindow aWindow, in boolean aDeep, out nsIDOMWindow aFocusedWindow); */
NS_IMETHODIMP nsFocusManager::GetFocusedElementForWindow(nsIDOMWindow *aWindow, bool aDeep, nsIDOMWindow * *aFocusedWindow, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveCaretToFocus (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::MoveCaretToFocus(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean elementIsFocusable (in nsIDOMElement aElement, in unsigned long aFlags); */
NS_IMETHODIMP nsFocusManager::ElementIsFocusable(nsIDOMElement *aElement, uint32_t aFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void windowRaised (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::WindowRaised(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void windowLowered (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::WindowLowered(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void windowShown (in nsIDOMWindow aWindow, in boolean aNeedsFocus); */
NS_IMETHODIMP nsFocusManager::WindowShown(nsIDOMWindow *aWindow, bool aNeedsFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void windowHidden (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::WindowHidden(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void fireDelayedEvents (in nsIDocument aDocument); */
NS_IMETHODIMP nsFocusManager::FireDelayedEvents(nsIDocument *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void focusPlugin (in nsIContent aPlugin); */
NS_IMETHODIMP nsFocusManager::FocusPlugin(nsIContent *aPlugin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void parentActivated (in nsIDOMWindow aWindow, in bool active); */
NS_IMETHODIMP nsFocusManager::ParentActivated(nsIDOMWindow *aWindow, bool active)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFocusManager_h__ */
