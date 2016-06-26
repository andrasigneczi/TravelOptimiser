/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITextInputProcessorCallback.idl
 */

#ifndef __gen_nsITextInputProcessorCallback_h__
#define __gen_nsITextInputProcessorCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITextInputProcessor; /* forward declaration */


/* starting interface:    nsITextInputProcessorNotification */
#define NS_ITEXTINPUTPROCESSORNOTIFICATION_IID_STR "c0ce1add-82bb-45ab-b99a-42cfba7fd5d7"

#define NS_ITEXTINPUTPROCESSORNOTIFICATION_IID \
  {0xc0ce1add, 0x82bb, 0x45ab, \
    { 0xb9, 0x9a, 0x42, 0xcf, 0xba, 0x7f, 0xd5, 0xd7 }}

class NS_NO_VTABLE nsITextInputProcessorNotification : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITEXTINPUTPROCESSORNOTIFICATION_IID)

  /* readonly attribute ACString type; */
  NS_IMETHOD GetType(nsACString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITextInputProcessorNotification, NS_ITEXTINPUTPROCESSORNOTIFICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITEXTINPUTPROCESSORNOTIFICATION \
  NS_IMETHOD GetType(nsACString & aType) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITEXTINPUTPROCESSORNOTIFICATION(_to) \
  NS_IMETHOD GetType(nsACString & aType) override { return _to GetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITEXTINPUTPROCESSORNOTIFICATION(_to) \
  NS_IMETHOD GetType(nsACString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTextInputProcessorNotification : public nsITextInputProcessorNotification
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITEXTINPUTPROCESSORNOTIFICATION

  nsTextInputProcessorNotification();

private:
  ~nsTextInputProcessorNotification();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTextInputProcessorNotification, nsITextInputProcessorNotification)

nsTextInputProcessorNotification::nsTextInputProcessorNotification()
{
  /* member initializers and constructor code */
}

nsTextInputProcessorNotification::~nsTextInputProcessorNotification()
{
  /* destructor code */
}

/* readonly attribute ACString type; */
NS_IMETHODIMP nsTextInputProcessorNotification::GetType(nsACString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITextInputProcessorCallback */
#define NS_ITEXTINPUTPROCESSORCALLBACK_IID_STR "23d5f242-adb5-46f1-8766-90d1bf0383df"

#define NS_ITEXTINPUTPROCESSORCALLBACK_IID \
  {0x23d5f242, 0xadb5, 0x46f1, \
    { 0x87, 0x66, 0x90, 0xd1, 0xbf, 0x03, 0x83, 0xdf }}

class NS_NO_VTABLE nsITextInputProcessorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITEXTINPUTPROCESSORCALLBACK_IID)

  /* boolean onNotify (in nsITextInputProcessor aTextInputProcessor, in nsITextInputProcessorNotification aNotification); */
  NS_IMETHOD OnNotify(nsITextInputProcessor *aTextInputProcessor, nsITextInputProcessorNotification *aNotification, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITextInputProcessorCallback, NS_ITEXTINPUTPROCESSORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITEXTINPUTPROCESSORCALLBACK \
  NS_IMETHOD OnNotify(nsITextInputProcessor *aTextInputProcessor, nsITextInputProcessorNotification *aNotification, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITEXTINPUTPROCESSORCALLBACK(_to) \
  NS_IMETHOD OnNotify(nsITextInputProcessor *aTextInputProcessor, nsITextInputProcessorNotification *aNotification, bool *_retval) override { return _to OnNotify(aTextInputProcessor, aNotification, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITEXTINPUTPROCESSORCALLBACK(_to) \
  NS_IMETHOD OnNotify(nsITextInputProcessor *aTextInputProcessor, nsITextInputProcessorNotification *aNotification, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnNotify(aTextInputProcessor, aNotification, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTextInputProcessorCallback : public nsITextInputProcessorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITEXTINPUTPROCESSORCALLBACK

  nsTextInputProcessorCallback();

private:
  ~nsTextInputProcessorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTextInputProcessorCallback, nsITextInputProcessorCallback)

nsTextInputProcessorCallback::nsTextInputProcessorCallback()
{
  /* member initializers and constructor code */
}

nsTextInputProcessorCallback::~nsTextInputProcessorCallback()
{
  /* destructor code */
}

/* boolean onNotify (in nsITextInputProcessor aTextInputProcessor, in nsITextInputProcessorNotification aNotification); */
NS_IMETHODIMP nsTextInputProcessorCallback::OnNotify(nsITextInputProcessor *aTextInputProcessor, nsITextInputProcessorNotification *aNotification, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITextInputProcessorCallback_h__ */
