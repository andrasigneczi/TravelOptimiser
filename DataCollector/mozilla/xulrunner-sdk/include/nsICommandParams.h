/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICommandParams.idl
 */

#ifndef __gen_nsICommandParams_h__
#define __gen_nsICommandParams_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICommandParams */
#define NS_ICOMMANDPARAMS_IID_STR "b1fdf3c4-74e3-4f7d-a14d-2b76bcf53482"

#define NS_ICOMMANDPARAMS_IID \
  {0xb1fdf3c4, 0x74e3, 0x4f7d, \
    { 0xa1, 0x4d, 0x2b, 0x76, 0xbc, 0xf5, 0x34, 0x82 }}

class NS_NO_VTABLE nsICommandParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOMMANDPARAMS_IID)

  enum {
    eNoType = 0,
    eBooleanType = 1,
    eLongType = 2,
    eDoubleType = 3,
    eWStringType = 4,
    eISupportsType = 5,
    eStringType = 6
  };

  /* short getValueType (in string name); */
  NS_IMETHOD GetValueType(const char * name, int16_t *_retval) = 0;

  /* boolean getBooleanValue (in string name); */
  NS_IMETHOD GetBooleanValue(const char * name, bool *_retval) = 0;

  /* long getLongValue (in string name); */
  NS_IMETHOD GetLongValue(const char * name, int32_t *_retval) = 0;

  /* double getDoubleValue (in string name); */
  NS_IMETHOD GetDoubleValue(const char * name, double *_retval) = 0;

  /* AString getStringValue (in string name); */
  NS_IMETHOD GetStringValue(const char * name, nsAString & _retval) = 0;

  /* string getCStringValue (in string name); */
  NS_IMETHOD GetCStringValue(const char * name, char * *_retval) = 0;

  /* nsISupports getISupportsValue (in string name); */
  NS_IMETHOD GetISupportsValue(const char * name, nsISupports * *_retval) = 0;

  /* void setBooleanValue (in string name, in boolean value); */
  NS_IMETHOD SetBooleanValue(const char * name, bool value) = 0;

  /* void setLongValue (in string name, in long value); */
  NS_IMETHOD SetLongValue(const char * name, int32_t value) = 0;

  /* void setDoubleValue (in string name, in double value); */
  NS_IMETHOD SetDoubleValue(const char * name, double value) = 0;

  /* void setStringValue (in string name, in AString value); */
  NS_IMETHOD SetStringValue(const char * name, const nsAString & value) = 0;

  /* void setCStringValue (in string name, in string value); */
  NS_IMETHOD SetCStringValue(const char * name, const char * value) = 0;

  /* void setISupportsValue (in string name, in nsISupports value); */
  NS_IMETHOD SetISupportsValue(const char * name, nsISupports *value) = 0;

  /* void removeValue (in string name); */
  NS_IMETHOD RemoveValue(const char * name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICommandParams, NS_ICOMMANDPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOMMANDPARAMS \
  NS_IMETHOD GetValueType(const char * name, int16_t *_retval) override; \
  NS_IMETHOD GetBooleanValue(const char * name, bool *_retval) override; \
  NS_IMETHOD GetLongValue(const char * name, int32_t *_retval) override; \
  NS_IMETHOD GetDoubleValue(const char * name, double *_retval) override; \
  NS_IMETHOD GetStringValue(const char * name, nsAString & _retval) override; \
  NS_IMETHOD GetCStringValue(const char * name, char * *_retval) override; \
  NS_IMETHOD GetISupportsValue(const char * name, nsISupports * *_retval) override; \
  NS_IMETHOD SetBooleanValue(const char * name, bool value) override; \
  NS_IMETHOD SetLongValue(const char * name, int32_t value) override; \
  NS_IMETHOD SetDoubleValue(const char * name, double value) override; \
  NS_IMETHOD SetStringValue(const char * name, const nsAString & value) override; \
  NS_IMETHOD SetCStringValue(const char * name, const char * value) override; \
  NS_IMETHOD SetISupportsValue(const char * name, nsISupports *value) override; \
  NS_IMETHOD RemoveValue(const char * name) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOMMANDPARAMS(_to) \
  NS_IMETHOD GetValueType(const char * name, int16_t *_retval) override { return _to GetValueType(name, _retval); } \
  NS_IMETHOD GetBooleanValue(const char * name, bool *_retval) override { return _to GetBooleanValue(name, _retval); } \
  NS_IMETHOD GetLongValue(const char * name, int32_t *_retval) override { return _to GetLongValue(name, _retval); } \
  NS_IMETHOD GetDoubleValue(const char * name, double *_retval) override { return _to GetDoubleValue(name, _retval); } \
  NS_IMETHOD GetStringValue(const char * name, nsAString & _retval) override { return _to GetStringValue(name, _retval); } \
  NS_IMETHOD GetCStringValue(const char * name, char * *_retval) override { return _to GetCStringValue(name, _retval); } \
  NS_IMETHOD GetISupportsValue(const char * name, nsISupports * *_retval) override { return _to GetISupportsValue(name, _retval); } \
  NS_IMETHOD SetBooleanValue(const char * name, bool value) override { return _to SetBooleanValue(name, value); } \
  NS_IMETHOD SetLongValue(const char * name, int32_t value) override { return _to SetLongValue(name, value); } \
  NS_IMETHOD SetDoubleValue(const char * name, double value) override { return _to SetDoubleValue(name, value); } \
  NS_IMETHOD SetStringValue(const char * name, const nsAString & value) override { return _to SetStringValue(name, value); } \
  NS_IMETHOD SetCStringValue(const char * name, const char * value) override { return _to SetCStringValue(name, value); } \
  NS_IMETHOD SetISupportsValue(const char * name, nsISupports *value) override { return _to SetISupportsValue(name, value); } \
  NS_IMETHOD RemoveValue(const char * name) override { return _to RemoveValue(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOMMANDPARAMS(_to) \
  NS_IMETHOD GetValueType(const char * name, int16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValueType(name, _retval); } \
  NS_IMETHOD GetBooleanValue(const char * name, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBooleanValue(name, _retval); } \
  NS_IMETHOD GetLongValue(const char * name, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLongValue(name, _retval); } \
  NS_IMETHOD GetDoubleValue(const char * name, double *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDoubleValue(name, _retval); } \
  NS_IMETHOD GetStringValue(const char * name, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStringValue(name, _retval); } \
  NS_IMETHOD GetCStringValue(const char * name, char * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCStringValue(name, _retval); } \
  NS_IMETHOD GetISupportsValue(const char * name, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetISupportsValue(name, _retval); } \
  NS_IMETHOD SetBooleanValue(const char * name, bool value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBooleanValue(name, value); } \
  NS_IMETHOD SetLongValue(const char * name, int32_t value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLongValue(name, value); } \
  NS_IMETHOD SetDoubleValue(const char * name, double value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDoubleValue(name, value); } \
  NS_IMETHOD SetStringValue(const char * name, const nsAString & value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStringValue(name, value); } \
  NS_IMETHOD SetCStringValue(const char * name, const char * value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCStringValue(name, value); } \
  NS_IMETHOD SetISupportsValue(const char * name, nsISupports *value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetISupportsValue(name, value); } \
  NS_IMETHOD RemoveValue(const char * name) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveValue(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCommandParams : public nsICommandParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOMMANDPARAMS

  nsCommandParams();

private:
  ~nsCommandParams();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCommandParams, nsICommandParams)

nsCommandParams::nsCommandParams()
{
  /* member initializers and constructor code */
}

nsCommandParams::~nsCommandParams()
{
  /* destructor code */
}

/* short getValueType (in string name); */
NS_IMETHODIMP nsCommandParams::GetValueType(const char * name, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getBooleanValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetBooleanValue(const char * name, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getLongValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetLongValue(const char * name, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double getDoubleValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetDoubleValue(const char * name, double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getStringValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetStringValue(const char * name, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getCStringValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetCStringValue(const char * name, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getISupportsValue (in string name); */
NS_IMETHODIMP nsCommandParams::GetISupportsValue(const char * name, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBooleanValue (in string name, in boolean value); */
NS_IMETHODIMP nsCommandParams::SetBooleanValue(const char * name, bool value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLongValue (in string name, in long value); */
NS_IMETHODIMP nsCommandParams::SetLongValue(const char * name, int32_t value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDoubleValue (in string name, in double value); */
NS_IMETHODIMP nsCommandParams::SetDoubleValue(const char * name, double value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setStringValue (in string name, in AString value); */
NS_IMETHODIMP nsCommandParams::SetStringValue(const char * name, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCStringValue (in string name, in string value); */
NS_IMETHODIMP nsCommandParams::SetCStringValue(const char * name, const char * value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setISupportsValue (in string name, in nsISupports value); */
NS_IMETHODIMP nsCommandParams::SetISupportsValue(const char * name, nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeValue (in string name); */
NS_IMETHODIMP nsCommandParams::RemoveValue(const char * name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_COMMAND_PARAMS_CID { 0xf7fa4581, 0x238e, 0x11d5, { 0xa7, 0x3c, 0xab, 0x64, 0xfb, 0x68, 0xf2, 0xbc } }
#define NS_COMMAND_PARAMS_CONTRACTID "@mozilla.org/embedcomp/command-params;1"

#endif /* __gen_nsICommandParams_h__ */
