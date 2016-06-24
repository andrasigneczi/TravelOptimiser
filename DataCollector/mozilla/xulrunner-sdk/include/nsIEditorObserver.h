/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIEditorObserver.idl
 */

#ifndef __gen_nsIEditorObserver_h__
#define __gen_nsIEditorObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIEditorObserver */
#define NS_IEDITOROBSERVER_IID_STR "f3ee57a6-890c-4ce0-a584-8a84bba0292e"

#define NS_IEDITOROBSERVER_IID \
  {0xf3ee57a6, 0x890c, 0x4ce0, \
    { 0xa5, 0x84, 0x8a, 0x84, 0xbb, 0xa0, 0x29, 0x2e }}

class NS_NO_VTABLE nsIEditorObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITOROBSERVER_IID)

  /* void EditAction (); */
  NS_IMETHOD EditAction(void) = 0;

  /* void BeforeEditAction (); */
  NS_IMETHOD BeforeEditAction(void) = 0;

  /* void CancelEditAction (); */
  NS_IMETHOD CancelEditAction(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorObserver, NS_IEDITOROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITOROBSERVER \
  NS_IMETHOD EditAction(void) override; \
  NS_IMETHOD BeforeEditAction(void) override; \
  NS_IMETHOD CancelEditAction(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITOROBSERVER(_to) \
  NS_IMETHOD EditAction(void) override { return _to EditAction(); } \
  NS_IMETHOD BeforeEditAction(void) override { return _to BeforeEditAction(); } \
  NS_IMETHOD CancelEditAction(void) override { return _to CancelEditAction(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITOROBSERVER(_to) \
  NS_IMETHOD EditAction(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EditAction(); } \
  NS_IMETHOD BeforeEditAction(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BeforeEditAction(); } \
  NS_IMETHOD CancelEditAction(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelEditAction(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorObserver : public nsIEditorObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITOROBSERVER

  nsEditorObserver();

private:
  ~nsEditorObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsEditorObserver, nsIEditorObserver)

nsEditorObserver::nsEditorObserver()
{
  /* member initializers and constructor code */
}

nsEditorObserver::~nsEditorObserver()
{
  /* destructor code */
}

/* void EditAction (); */
NS_IMETHODIMP nsEditorObserver::EditAction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void BeforeEditAction (); */
NS_IMETHODIMP nsEditorObserver::BeforeEditAction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void CancelEditAction (); */
NS_IMETHODIMP nsEditorObserver::CancelEditAction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorObserver_h__ */
