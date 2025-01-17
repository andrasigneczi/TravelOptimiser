/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISecurityEventSink.idl
 */

#ifndef __gen_nsISecurityEventSink_h__
#define __gen_nsISecurityEventSink_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsISecurityEventSink */
#define NS_ISECURITYEVENTSINK_IID_STR "a71aee68-dd38-4736-bd79-035fea1a1ec6"

#define NS_ISECURITYEVENTSINK_IID \
  {0xa71aee68, 0xdd38, 0x4736, \
    { 0xbd, 0x79, 0x03, 0x5f, 0xea, 0x1a, 0x1e, 0xc6 }}

class NS_NO_VTABLE nsISecurityEventSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISECURITYEVENTSINK_IID)

  /* void onSecurityChange (in nsISupports i_Context, in unsigned long state); */
  NS_IMETHOD OnSecurityChange(nsISupports *i_Context, uint32_t state) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISecurityEventSink, NS_ISECURITYEVENTSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISECURITYEVENTSINK \
  NS_IMETHOD OnSecurityChange(nsISupports *i_Context, uint32_t state) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISECURITYEVENTSINK(_to) \
  NS_IMETHOD OnSecurityChange(nsISupports *i_Context, uint32_t state) override { return _to OnSecurityChange(i_Context, state); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISECURITYEVENTSINK(_to) \
  NS_IMETHOD OnSecurityChange(nsISupports *i_Context, uint32_t state) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSecurityChange(i_Context, state); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSecurityEventSink : public nsISecurityEventSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISECURITYEVENTSINK

  nsSecurityEventSink();

private:
  ~nsSecurityEventSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSecurityEventSink, nsISecurityEventSink)

nsSecurityEventSink::nsSecurityEventSink()
{
  /* member initializers and constructor code */
}

nsSecurityEventSink::~nsSecurityEventSink()
{
  /* destructor code */
}

/* void onSecurityChange (in nsISupports i_Context, in unsigned long state); */
NS_IMETHODIMP nsSecurityEventSink::OnSecurityChange(nsISupports *i_Context, uint32_t state)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISecurityEventSink_h__ */
