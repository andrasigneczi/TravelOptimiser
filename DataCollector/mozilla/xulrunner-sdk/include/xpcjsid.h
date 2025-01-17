/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\xpcjsid.idl
 */

#ifndef __gen_xpcjsid_h__
#define __gen_xpcjsid_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIJSID */
#define NS_IJSID_IID_STR "62883d14-4146-4039-94f5-a5e1e1a51a15"

#define NS_IJSID_IID \
  {0x62883d14, 0x4146, 0x4039, \
    { 0x94, 0xf5, 0xa5, 0xe1, 0xe1, 0xa5, 0x1a, 0x15 }}

class NS_NO_VTABLE nsIJSID : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSID_IID)

  /* readonly attribute string name; */
  NS_IMETHOD GetName(char * *aName) = 0;

  /* readonly attribute string number; */
  NS_IMETHOD GetNumber(char * *aNumber) = 0;

  /* readonly attribute boolean valid; */
  NS_IMETHOD GetValid(bool *aValid) = 0;

  /* boolean equals (in nsIJSID other); */
  NS_IMETHOD Equals(nsIJSID *other, bool *_retval) = 0;

  /* string toString (); */
  NS_IMETHOD ToString(char * *_retval) = 0;

  /* [noscript] void initialize (in string idString); */
  NS_IMETHOD Initialize(const char * idString) = 0;

  /* [notxpcom] const_nsID_ptr getID (); */
  NS_IMETHOD_(const nsID *) GetID(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSID, NS_IJSID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSID \
  NS_IMETHOD GetName(char * *aName) override; \
  NS_IMETHOD GetNumber(char * *aNumber) override; \
  NS_IMETHOD GetValid(bool *aValid) override; \
  NS_IMETHOD Equals(nsIJSID *other, bool *_retval) override; \
  NS_IMETHOD ToString(char * *_retval) override; \
  NS_IMETHOD Initialize(const char * idString) override; \
  NS_IMETHOD_(const nsID *) GetID(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSID(_to) \
  NS_IMETHOD GetName(char * *aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetNumber(char * *aNumber) override { return _to GetNumber(aNumber); } \
  NS_IMETHOD GetValid(bool *aValid) override { return _to GetValid(aValid); } \
  NS_IMETHOD Equals(nsIJSID *other, bool *_retval) override { return _to Equals(other, _retval); } \
  NS_IMETHOD ToString(char * *_retval) override { return _to ToString(_retval); } \
  NS_IMETHOD Initialize(const char * idString) override { return _to Initialize(idString); } \
  NS_IMETHOD_(const nsID *) GetID(void) override { return _to GetID(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSID(_to) \
  NS_IMETHOD GetName(char * *aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetNumber(char * *aNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumber(aNumber); } \
  NS_IMETHOD GetValid(bool *aValid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValid(aValid); } \
  NS_IMETHOD Equals(nsIJSID *other, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(other, _retval); } \
  NS_IMETHOD ToString(char * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } \
  NS_IMETHOD Initialize(const char * idString) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(idString); } \
  NS_IMETHOD_(const nsID *) GetID(void) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSID : public nsIJSID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSID

  nsJSID();

private:
  ~nsJSID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsJSID, nsIJSID)

nsJSID::nsJSID()
{
  /* member initializers and constructor code */
}

nsJSID::~nsJSID()
{
  /* destructor code */
}

/* readonly attribute string name; */
NS_IMETHODIMP nsJSID::GetName(char * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string number; */
NS_IMETHODIMP nsJSID::GetNumber(char * *aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean valid; */
NS_IMETHODIMP nsJSID::GetValid(bool *aValid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equals (in nsIJSID other); */
NS_IMETHODIMP nsJSID::Equals(nsIJSID *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string toString (); */
NS_IMETHODIMP nsJSID::ToString(char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initialize (in string idString); */
NS_IMETHODIMP nsJSID::Initialize(const char * idString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] const_nsID_ptr getID (); */
NS_IMETHODIMP_(const nsID *) nsJSID::GetID()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJSIID */
#define NS_IJSIID_IID_STR "e76ec564-a080-4705-8609-384c755ec91e"

#define NS_IJSIID_IID \
  {0xe76ec564, 0xa080, 0x4705, \
    { 0x86, 0x09, 0x38, 0x4c, 0x75, 0x5e, 0xc9, 0x1e }}

class NS_NO_VTABLE nsIJSIID : public nsIJSID {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSIID_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSIID, NS_IJSIID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSIID \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSIID(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSIID(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSIID : public nsIJSIID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSIID

  nsJSIID();

private:
  ~nsJSIID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsJSIID, nsIJSIID)

nsJSIID::nsJSIID()
{
  /* member initializers and constructor code */
}

nsJSIID::~nsJSIID()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIJSCID */
#define NS_IJSCID_IID_STR "bf5eb086-9eaa-4694-aec3-fe4aac6119bd"

#define NS_IJSCID_IID \
  {0xbf5eb086, 0x9eaa, 0x4694, \
    { 0xae, 0xc3, 0xfe, 0x4a, 0xac, 0x61, 0x19, 0xbd }}

class NS_NO_VTABLE nsIJSCID : public nsIJSID {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSCID_IID)

  /* [implicit_jscontext,optional_argc] jsval createInstance ([optional] in jsval iid); */
  NS_IMETHOD CreateInstance(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext,optional_argc] jsval getService ([optional] in jsval iid); */
  NS_IMETHOD GetService(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSCID, NS_IJSCID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSCID \
  NS_IMETHOD CreateInstance(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetService(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSCID(_to) \
  NS_IMETHOD CreateInstance(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return _to CreateInstance(iid, cx, _argc, _retval); } \
  NS_IMETHOD GetService(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return _to GetService(iid, cx, _argc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSCID(_to) \
  NS_IMETHOD CreateInstance(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInstance(iid, cx, _argc, _retval); } \
  NS_IMETHOD GetService(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetService(iid, cx, _argc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSCID : public nsIJSCID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSCID

  nsJSCID();

private:
  ~nsJSCID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsJSCID, nsIJSCID)

nsJSCID::nsJSCID()
{
  /* member initializers and constructor code */
}

nsJSCID::~nsJSCID()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] jsval createInstance ([optional] in jsval iid); */
NS_IMETHODIMP nsJSCID::CreateInstance(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] jsval getService ([optional] in jsval iid); */
NS_IMETHODIMP nsJSCID::GetService(JS::HandleValue iid, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/********************************************************/
// {F24A14F0-4FA1-11d3-9894-006008962422}
#define NS_JS_ID_CID  \
{ 0xf24a14f0, 0x4fa1, 0x11d3, \
    { 0x98, 0x94, 0x0, 0x60, 0x8, 0x96, 0x24, 0x22 } }

#endif /* __gen_xpcjsid_h__ */
