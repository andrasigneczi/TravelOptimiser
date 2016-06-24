/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIActivityUIGlue.idl
 */

#ifndef __gen_nsIActivityUIGlue_h__
#define __gen_nsIActivityUIGlue_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIActivityUIGlueCallback */
#define NS_IACTIVITYUIGLUECALLBACK_IID_STR "674b6e69-05f0-41da-aabd-4184ea85c9d8"

#define NS_IACTIVITYUIGLUECALLBACK_IID \
  {0x674b6e69, 0x05f0, 0x41da, \
    { 0xaa, 0xbd, 0x41, 0x84, 0xea, 0x85, 0xc9, 0xd8 }}

class NS_NO_VTABLE nsIActivityUIGlueCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACTIVITYUIGLUECALLBACK_IID)

  enum {
    WEBAPPS_ACTIVITY = 0,
    NATIVE_ACTIVITY = 1
  };

  /* void handleEvent (in short resultType, in jsval result); */
  NS_IMETHOD HandleEvent(int16_t resultType, JS::HandleValue result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIActivityUIGlueCallback, NS_IACTIVITYUIGLUECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACTIVITYUIGLUECALLBACK \
  NS_IMETHOD HandleEvent(int16_t resultType, JS::HandleValue result) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACTIVITYUIGLUECALLBACK(_to) \
  NS_IMETHOD HandleEvent(int16_t resultType, JS::HandleValue result) override { return _to HandleEvent(resultType, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACTIVITYUIGLUECALLBACK(_to) \
  NS_IMETHOD HandleEvent(int16_t resultType, JS::HandleValue result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(resultType, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsActivityUIGlueCallback : public nsIActivityUIGlueCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACTIVITYUIGLUECALLBACK

  nsActivityUIGlueCallback();

private:
  ~nsActivityUIGlueCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsActivityUIGlueCallback, nsIActivityUIGlueCallback)

nsActivityUIGlueCallback::nsActivityUIGlueCallback()
{
  /* member initializers and constructor code */
}

nsActivityUIGlueCallback::~nsActivityUIGlueCallback()
{
  /* destructor code */
}

/* void handleEvent (in short resultType, in jsval result); */
NS_IMETHODIMP nsActivityUIGlueCallback::HandleEvent(int16_t resultType, JS::HandleValue result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIActivityUIGlue */
#define NS_IACTIVITYUIGLUE_IID_STR "3caef69f-3569-4b19-bcea-1cfb0fee4466"

#define NS_IACTIVITYUIGLUE_IID \
  {0x3caef69f, 0x3569, 0x4b19, \
    { 0xbc, 0xea, 0x1c, 0xfb, 0x0f, 0xee, 0x44, 0x66 }}

class NS_NO_VTABLE nsIActivityUIGlue : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACTIVITYUIGLUE_IID)

  /* void chooseActivity (in jsval options, in jsval activities, in nsIActivityUIGlueCallback callback); */
  NS_IMETHOD ChooseActivity(JS::HandleValue options, JS::HandleValue activities, nsIActivityUIGlueCallback *callback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIActivityUIGlue, NS_IACTIVITYUIGLUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACTIVITYUIGLUE \
  NS_IMETHOD ChooseActivity(JS::HandleValue options, JS::HandleValue activities, nsIActivityUIGlueCallback *callback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACTIVITYUIGLUE(_to) \
  NS_IMETHOD ChooseActivity(JS::HandleValue options, JS::HandleValue activities, nsIActivityUIGlueCallback *callback) override { return _to ChooseActivity(options, activities, callback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACTIVITYUIGLUE(_to) \
  NS_IMETHOD ChooseActivity(JS::HandleValue options, JS::HandleValue activities, nsIActivityUIGlueCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ChooseActivity(options, activities, callback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsActivityUIGlue : public nsIActivityUIGlue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACTIVITYUIGLUE

  nsActivityUIGlue();

private:
  ~nsActivityUIGlue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsActivityUIGlue, nsIActivityUIGlue)

nsActivityUIGlue::nsActivityUIGlue()
{
  /* member initializers and constructor code */
}

nsActivityUIGlue::~nsActivityUIGlue()
{
  /* destructor code */
}

/* void chooseActivity (in jsval options, in jsval activities, in nsIActivityUIGlueCallback callback); */
NS_IMETHODIMP nsActivityUIGlue::ChooseActivity(JS::HandleValue options, JS::HandleValue activities, nsIActivityUIGlueCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIActivityUIGlue_h__ */
