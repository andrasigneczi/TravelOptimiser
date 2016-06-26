/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMobileCallForwardingOptions.idl
 */

#ifndef __gen_nsIMobileCallForwardingOptions_h__
#define __gen_nsIMobileCallForwardingOptions_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMobileCallForwardingOptions */
#define NS_IMOBILECALLFORWARDINGOPTIONS_IID_STR "c616ecb6-65f5-441e-b97e-c642ddef6888"

#define NS_IMOBILECALLFORWARDINGOPTIONS_IID \
  {0xc616ecb6, 0x65f5, 0x441e, \
    { 0xb9, 0x7e, 0xc6, 0x42, 0xdd, 0xef, 0x68, 0x88 }}

class NS_NO_VTABLE nsIMobileCallForwardingOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILECALLFORWARDINGOPTIONS_IID)

  /* readonly attribute bool active; */
  NS_IMETHOD GetActive(bool *aActive) = 0;

  /* readonly attribute short action; */
  NS_IMETHOD GetAction(int16_t *aAction) = 0;

  /* readonly attribute short reason; */
  NS_IMETHOD GetReason(int16_t *aReason) = 0;

  /* readonly attribute DOMString number; */
  NS_IMETHOD GetNumber(nsAString & aNumber) = 0;

  /* readonly attribute short timeSeconds; */
  NS_IMETHOD GetTimeSeconds(int16_t *aTimeSeconds) = 0;

  /* readonly attribute short serviceClass; */
  NS_IMETHOD GetServiceClass(int16_t *aServiceClass) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileCallForwardingOptions, NS_IMOBILECALLFORWARDINGOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILECALLFORWARDINGOPTIONS \
  NS_IMETHOD GetActive(bool *aActive) override; \
  NS_IMETHOD GetAction(int16_t *aAction) override; \
  NS_IMETHOD GetReason(int16_t *aReason) override; \
  NS_IMETHOD GetNumber(nsAString & aNumber) override; \
  NS_IMETHOD GetTimeSeconds(int16_t *aTimeSeconds) override; \
  NS_IMETHOD GetServiceClass(int16_t *aServiceClass) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILECALLFORWARDINGOPTIONS(_to) \
  NS_IMETHOD GetActive(bool *aActive) override { return _to GetActive(aActive); } \
  NS_IMETHOD GetAction(int16_t *aAction) override { return _to GetAction(aAction); } \
  NS_IMETHOD GetReason(int16_t *aReason) override { return _to GetReason(aReason); } \
  NS_IMETHOD GetNumber(nsAString & aNumber) override { return _to GetNumber(aNumber); } \
  NS_IMETHOD GetTimeSeconds(int16_t *aTimeSeconds) override { return _to GetTimeSeconds(aTimeSeconds); } \
  NS_IMETHOD GetServiceClass(int16_t *aServiceClass) override { return _to GetServiceClass(aServiceClass); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILECALLFORWARDINGOPTIONS(_to) \
  NS_IMETHOD GetActive(bool *aActive) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActive(aActive); } \
  NS_IMETHOD GetAction(int16_t *aAction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAction(aAction); } \
  NS_IMETHOD GetReason(int16_t *aReason) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReason(aReason); } \
  NS_IMETHOD GetNumber(nsAString & aNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumber(aNumber); } \
  NS_IMETHOD GetTimeSeconds(int16_t *aTimeSeconds) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeSeconds(aTimeSeconds); } \
  NS_IMETHOD GetServiceClass(int16_t *aServiceClass) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServiceClass(aServiceClass); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileCallForwardingOptions : public nsIMobileCallForwardingOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILECALLFORWARDINGOPTIONS

  nsMobileCallForwardingOptions();

private:
  ~nsMobileCallForwardingOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMobileCallForwardingOptions, nsIMobileCallForwardingOptions)

nsMobileCallForwardingOptions::nsMobileCallForwardingOptions()
{
  /* member initializers and constructor code */
}

nsMobileCallForwardingOptions::~nsMobileCallForwardingOptions()
{
  /* destructor code */
}

/* readonly attribute bool active; */
NS_IMETHODIMP nsMobileCallForwardingOptions::GetActive(bool *aActive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short action; */
NS_IMETHODIMP nsMobileCallForwardingOptions::GetAction(int16_t *aAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short reason; */
NS_IMETHODIMP nsMobileCallForwardingOptions::GetReason(int16_t *aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString number; */
NS_IMETHODIMP nsMobileCallForwardingOptions::GetNumber(nsAString & aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short timeSeconds; */
NS_IMETHODIMP nsMobileCallForwardingOptions::GetTimeSeconds(int16_t *aTimeSeconds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short serviceClass; */
NS_IMETHODIMP nsMobileCallForwardingOptions::GetServiceClass(int16_t *aServiceClass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileCallForwardingOptions_h__ */
