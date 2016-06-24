/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXPCScriptable.idl
 */

#ifndef __gen_nsIXPCScriptable_h__
#define __gen_nsIXPCScriptable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIClassInfo_h__
#include "nsIClassInfo.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef XP_WIN
#undef GetClassName
#endif
#include "js/TypeDecls.h"
struct JSFreeOp;
class nsIXPConnectWrappedNative; /* forward declaration */


/* starting interface:    nsIXPCScriptable */
#define NS_IXPCSCRIPTABLE_IID_STR "19b70b26-7c3f-437f-a04a-2a8f9e28b617"

#define NS_IXPCSCRIPTABLE_IID \
  {0x19b70b26, 0x7c3f, 0x437f, \
    { 0xa0, 0x4a, 0x2a, 0x8f, 0x9e, 0x28, 0xb6, 0x17 }}

class NS_NO_VTABLE nsIXPCScriptable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCSCRIPTABLE_IID)

  enum {
    WANT_PRECREATE = 1U,
    WANT_ADDPROPERTY = 8U,
    WANT_GETPROPERTY = 32U,
    WANT_SETPROPERTY = 64U,
    WANT_ENUMERATE = 128U,
    WANT_NEWENUMERATE = 256U,
    WANT_RESOLVE = 512U,
    WANT_FINALIZE = 2048U,
    WANT_CALL = 8192U,
    WANT_CONSTRUCT = 16384U,
    WANT_HASINSTANCE = 32768U,
    USE_JSSTUB_FOR_ADDPROPERTY = 131072U,
    USE_JSSTUB_FOR_DELPROPERTY = 262144U,
    USE_JSSTUB_FOR_SETPROPERTY = 524288U,
    DONT_ENUM_QUERY_INTERFACE = 2097152U,
    DONT_ASK_INSTANCE_FOR_SCRIPTABLE = 4194304U,
    CLASSINFO_INTERFACES_ONLY = 8388608U,
    ALLOW_PROP_MODS_DURING_RESOLVE = 16777216U,
    ALLOW_PROP_MODS_TO_PROTOTYPE = 33554432U,
    IS_GLOBAL_OBJECT = 67108864U,
    DONT_REFLECT_INTERFACE_NAMES = 134217728U,
    RESERVED = 2147483648U
  };

  /* readonly attribute string className; */
  NS_IMETHOD GetClassName(char * *aClassName) = 0;

  /* [nostdcall,notxpcom] uint32_t getScriptableFlags (); */
  virtual uint32_t GetScriptableFlags(void) = 0;

  /* void preCreate (in nsISupports nativeObj, in JSContextPtr cx, in JSObjectPtr globalObj, out JSObjectPtr parentObj); */
  NS_IMETHOD PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj) = 0;

  /* boolean addProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in jsval val); */
  NS_IMETHOD AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::HandleValue val, bool *_retval) = 0;

  /* boolean getProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
  NS_IMETHOD GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval) = 0;

  /* boolean setProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
  NS_IMETHOD SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval) = 0;

  /* boolean enumerate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
  NS_IMETHOD Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval) = 0;

  /* boolean newEnumerate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in JSAutoIdVector properties); */
  NS_IMETHOD NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::AutoIdVector & properties, bool *_retval) = 0;

  /* boolean resolve (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, out boolean resolvedp); */
  NS_IMETHOD Resolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, bool *resolvedp, bool *_retval) = 0;

  /* void finalize (in nsIXPConnectWrappedNative wrapper, in JSFreeOpPtr fop, in JSObjectPtr obj); */
  NS_IMETHOD Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj) = 0;

  /* boolean call (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in JSCallArgsRef args); */
  NS_IMETHOD Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval) = 0;

  /* boolean construct (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in JSCallArgsRef args); */
  NS_IMETHOD Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval) = 0;

  /* boolean hasInstance (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsval val, out boolean bp); */
  NS_IMETHOD HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::HandleValue val, bool *bp, bool *_retval) = 0;

  /* void postCreatePrototype (in JSContextPtr cx, in JSObjectPtr proto); */
  NS_IMETHOD PostCreatePrototype(JSContext *cx, JSObject *proto) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCScriptable, NS_IXPCSCRIPTABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCSCRIPTABLE \
  NS_IMETHOD GetClassName(char * *aClassName) override; \
  virtual uint32_t GetScriptableFlags(void) override; \
  NS_IMETHOD PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj) override; \
  NS_IMETHOD AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::HandleValue val, bool *_retval) override; \
  NS_IMETHOD GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval) override; \
  NS_IMETHOD SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval) override; \
  NS_IMETHOD Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval) override; \
  NS_IMETHOD NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::AutoIdVector & properties, bool *_retval) override; \
  NS_IMETHOD Resolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, bool *resolvedp, bool *_retval) override; \
  NS_IMETHOD Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj) override; \
  NS_IMETHOD Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval) override; \
  NS_IMETHOD Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval) override; \
  NS_IMETHOD HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::HandleValue val, bool *bp, bool *_retval) override; \
  NS_IMETHOD PostCreatePrototype(JSContext *cx, JSObject *proto) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCSCRIPTABLE(_to) \
  NS_IMETHOD GetClassName(char * *aClassName) override { return _to GetClassName(aClassName); } \
  virtual uint32_t GetScriptableFlags(void) override { return _to GetScriptableFlags(); } \
  NS_IMETHOD PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj) override { return _to PreCreate(nativeObj, cx, globalObj, parentObj); } \
  NS_IMETHOD AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::HandleValue val, bool *_retval) override { return _to AddProperty(wrapper, cx, obj, id, val, _retval); } \
  NS_IMETHOD GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval) override { return _to GetProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval) override { return _to SetProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval) override { return _to Enumerate(wrapper, cx, obj, _retval); } \
  NS_IMETHOD NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::AutoIdVector & properties, bool *_retval) override { return _to NewEnumerate(wrapper, cx, obj, properties, _retval); } \
  NS_IMETHOD Resolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, bool *resolvedp, bool *_retval) override { return _to Resolve(wrapper, cx, obj, id, resolvedp, _retval); } \
  NS_IMETHOD Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj) override { return _to Finalize(wrapper, fop, obj); } \
  NS_IMETHOD Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval) override { return _to Call(wrapper, cx, obj, args, _retval); } \
  NS_IMETHOD Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval) override { return _to Construct(wrapper, cx, obj, args, _retval); } \
  NS_IMETHOD HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::HandleValue val, bool *bp, bool *_retval) override { return _to HasInstance(wrapper, cx, obj, val, bp, _retval); } \
  NS_IMETHOD PostCreatePrototype(JSContext *cx, JSObject *proto) override { return _to PostCreatePrototype(cx, proto); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCSCRIPTABLE(_to) \
  NS_IMETHOD GetClassName(char * *aClassName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassName(aClassName); } \
  virtual uint32_t GetScriptableFlags(void) override; \
  NS_IMETHOD PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PreCreate(nativeObj, cx, globalObj, parentObj); } \
  NS_IMETHOD AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::HandleValue val, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddProperty(wrapper, cx, obj, id, val, _retval); } \
  NS_IMETHOD GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProperty(wrapper, cx, obj, id, vp, _retval); } \
  NS_IMETHOD Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Enumerate(wrapper, cx, obj, _retval); } \
  NS_IMETHOD NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::AutoIdVector & properties, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NewEnumerate(wrapper, cx, obj, properties, _retval); } \
  NS_IMETHOD Resolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, bool *resolvedp, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Resolve(wrapper, cx, obj, id, resolvedp, _retval); } \
  NS_IMETHOD Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Finalize(wrapper, fop, obj); } \
  NS_IMETHOD Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Call(wrapper, cx, obj, args, _retval); } \
  NS_IMETHOD Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Construct(wrapper, cx, obj, args, _retval); } \
  NS_IMETHOD HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::HandleValue val, bool *bp, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasInstance(wrapper, cx, obj, val, bp, _retval); } \
  NS_IMETHOD PostCreatePrototype(JSContext *cx, JSObject *proto) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PostCreatePrototype(cx, proto); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCScriptable : public nsIXPCScriptable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCSCRIPTABLE

  nsXPCScriptable();

private:
  ~nsXPCScriptable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCScriptable, nsIXPCScriptable)

nsXPCScriptable::nsXPCScriptable()
{
  /* member initializers and constructor code */
}

nsXPCScriptable::~nsXPCScriptable()
{
  /* destructor code */
}

/* readonly attribute string className; */
NS_IMETHODIMP nsXPCScriptable::GetClassName(char * *aClassName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [nostdcall,notxpcom] uint32_t getScriptableFlags (); */
uint32_t nsXPCScriptable::GetScriptableFlags()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preCreate (in nsISupports nativeObj, in JSContextPtr cx, in JSObjectPtr globalObj, out JSObjectPtr parentObj); */
NS_IMETHODIMP nsXPCScriptable::PreCreate(nsISupports *nativeObj, JSContext *cx, JSObject *globalObj, JSObject **parentObj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean addProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in jsval val); */
NS_IMETHODIMP nsXPCScriptable::AddProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::HandleValue val, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::GetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean setProperty (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, in JSValPtr vp); */
NS_IMETHODIMP nsXPCScriptable::SetProperty(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, JS::Value *vp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean enumerate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj); */
NS_IMETHODIMP nsXPCScriptable::Enumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean newEnumerate (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in JSAutoIdVector properties); */
NS_IMETHODIMP nsXPCScriptable::NewEnumerate(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::AutoIdVector & properties, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean resolve (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsid id, out boolean resolvedp); */
NS_IMETHODIMP nsXPCScriptable::Resolve(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, jsid id, bool *resolvedp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finalize (in nsIXPConnectWrappedNative wrapper, in JSFreeOpPtr fop, in JSObjectPtr obj); */
NS_IMETHODIMP nsXPCScriptable::Finalize(nsIXPConnectWrappedNative *wrapper, JSFreeOp *fop, JSObject *obj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean call (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in JSCallArgsRef args); */
NS_IMETHODIMP nsXPCScriptable::Call(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean construct (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in JSCallArgsRef args); */
NS_IMETHODIMP nsXPCScriptable::Construct(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, const JS::CallArgs & args, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasInstance (in nsIXPConnectWrappedNative wrapper, in JSContextPtr cx, in JSObjectPtr obj, in jsval val, out boolean bp); */
NS_IMETHODIMP nsXPCScriptable::HasInstance(nsIXPConnectWrappedNative *wrapper, JSContext *cx, JSObject *obj, JS::HandleValue val, bool *bp, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void postCreatePrototype (in JSContextPtr cx, in JSObjectPtr proto); */
NS_IMETHODIMP nsXPCScriptable::PostCreatePrototype(JSContext *cx, JSObject *proto)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#include "nsAutoPtr.h"
#define NS_XPCCLASSINFO_IID \
{ 0x43b67f01, 0xd4ce, 0x4b82, \
 { 0xb3, 0xf8, 0xeb, 0xf2, 0x13, 0x60, 0xfb, 0x7e } }
class NS_NO_VTABLE nsXPCClassInfo : public nsIClassInfo,
                                    public nsIXPCScriptable
{
public:
  NS_DECLARE_STATIC_IID_ACCESSOR(NS_XPCCLASSINFO_IID)
  NS_IMETHOD_(MozExternalRefCountType) AddRef() override = 0;
  NS_IMETHOD_(MozExternalRefCountType) Release() override = 0;
  virtual void PreserveWrapper(nsISupports *aNative) = 0;
};
NS_DEFINE_STATIC_IID_ACCESSOR(nsXPCClassInfo, NS_XPCCLASSINFO_IID)
inline
nsresult
CallQueryInterface(nsISupports* aSourcePtr,
                   nsRefPtrGetterAddRefs<nsXPCClassInfo> aDestPtr)
{
  return CallQueryInterface(aSourcePtr,
                            static_cast<nsXPCClassInfo**>(aDestPtr));
}

#endif /* __gen_nsIXPCScriptable_h__ */
