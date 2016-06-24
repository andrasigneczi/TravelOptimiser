/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITabSource.idl
 */

#ifndef __gen_nsITabSource_h__
#define __gen_nsITabSource_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIDOMWindow_h__
#include "nsIDOMWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITabSource */
#define NS_ITABSOURCE_IID_STR "b3a7a402-2760-4583-b4a3-af095fe00c84"

#define NS_ITABSOURCE_IID \
  {0xb3a7a402, 0x2760, 0x4583, \
    { 0xb4, 0xa3, 0xaf, 0x09, 0x5f, 0xe0, 0x0c, 0x84 }}

class NS_NO_VTABLE nsITabSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABSOURCE_IID)

  /* nsIDOMWindow getTabToStream (); */
  NS_IMETHOD GetTabToStream(nsIDOMWindow * *_retval) = 0;

  /* void notifyStreamStart (in nsIDOMWindow window); */
  NS_IMETHOD NotifyStreamStart(nsIDOMWindow *window) = 0;

  /* void notifyStreamStop (in nsIDOMWindow window); */
  NS_IMETHOD NotifyStreamStop(nsIDOMWindow *window) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITabSource, NS_ITABSOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABSOURCE \
  NS_IMETHOD GetTabToStream(nsIDOMWindow * *_retval) override; \
  NS_IMETHOD NotifyStreamStart(nsIDOMWindow *window) override; \
  NS_IMETHOD NotifyStreamStop(nsIDOMWindow *window) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABSOURCE(_to) \
  NS_IMETHOD GetTabToStream(nsIDOMWindow * *_retval) override { return _to GetTabToStream(_retval); } \
  NS_IMETHOD NotifyStreamStart(nsIDOMWindow *window) override { return _to NotifyStreamStart(window); } \
  NS_IMETHOD NotifyStreamStop(nsIDOMWindow *window) override { return _to NotifyStreamStop(window); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABSOURCE(_to) \
  NS_IMETHOD GetTabToStream(nsIDOMWindow * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabToStream(_retval); } \
  NS_IMETHOD NotifyStreamStart(nsIDOMWindow *window) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyStreamStart(window); } \
  NS_IMETHOD NotifyStreamStop(nsIDOMWindow *window) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyStreamStop(window); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTabSource : public nsITabSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABSOURCE

  nsTabSource();

private:
  ~nsTabSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTabSource, nsITabSource)

nsTabSource::nsTabSource()
{
  /* member initializers and constructor code */
}

nsTabSource::~nsTabSource()
{
  /* destructor code */
}

/* nsIDOMWindow getTabToStream (); */
NS_IMETHODIMP nsTabSource::GetTabToStream(nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyStreamStart (in nsIDOMWindow window); */
NS_IMETHODIMP nsTabSource::NotifyStreamStart(nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyStreamStop (in nsIDOMWindow window); */
NS_IMETHODIMP nsTabSource::NotifyStreamStop(nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_TABSOURCESERVICE_CONTRACTID "@mozilla.org/tab-source-service;1"

#endif /* __gen_nsITabSource_h__ */
