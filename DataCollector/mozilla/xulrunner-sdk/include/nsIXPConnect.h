/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXPConnect.idl
 */

#ifndef __gen_nsIXPConnect_h__
#define __gen_nsIXPConnect_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"
#include "js/TypeDecls.h"
#include "mozilla/Attributes.h"
#include "nsCOMPtr.h"
struct JSFreeOp;
class nsWrapperCache;
class nsAXPCNativeCallContext;
class nsIXPCScriptable; /* forward declaration */

class nsIXPConnect; /* forward declaration */

class nsIXPConnectWrappedNative; /* forward declaration */

class nsIInterfaceInfo; /* forward declaration */

class nsIXPCSecurityManager; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIClassInfo; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIStackFrame; /* forward declaration */

class nsIObjectInputStream; /* forward declaration */

class nsIObjectOutputStream; /* forward declaration */


/* starting interface:    nsIXPConnectJSObjectHolder */
#define NS_IXPCONNECTJSOBJECTHOLDER_IID_STR "73e6ff4a-ab99-4d99-ac00-ba39ccb8e4d7"

#define NS_IXPCONNECTJSOBJECTHOLDER_IID \
  {0x73e6ff4a, 0xab99, 0x4d99, \
    { 0xac, 0x00, 0xba, 0x39, 0xcc, 0xb8, 0xe4, 0xd7 }}

class NS_NO_VTABLE nsIXPConnectJSObjectHolder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECTJSOBJECTHOLDER_IID)

  /* [nostdcall,notxpcom] JSObjectPtr GetJSObject (); */
  virtual JSObject * GetJSObject(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnectJSObjectHolder, NS_IXPCONNECTJSOBJECTHOLDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECTJSOBJECTHOLDER \
  virtual JSObject * GetJSObject(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECTJSOBJECTHOLDER(_to) \
  virtual JSObject * GetJSObject(void) override { return _to GetJSObject(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECTJSOBJECTHOLDER(_to) \
  virtual JSObject * GetJSObject(void) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnectJSObjectHolder : public nsIXPConnectJSObjectHolder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECTJSOBJECTHOLDER

  nsXPConnectJSObjectHolder();

private:
  ~nsXPConnectJSObjectHolder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPConnectJSObjectHolder, nsIXPConnectJSObjectHolder)

nsXPConnectJSObjectHolder::nsXPConnectJSObjectHolder()
{
  /* member initializers and constructor code */
}

nsXPConnectJSObjectHolder::~nsXPConnectJSObjectHolder()
{
  /* destructor code */
}

/* [nostdcall,notxpcom] JSObjectPtr GetJSObject (); */
JSObject * nsXPConnectJSObjectHolder::GetJSObject()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPConnectWrappedNative */
#define NS_IXPCONNECTWRAPPEDNATIVE_IID_STR "e787be29-db5d-4a45-a3d6-1de1d6b85c30"

#define NS_IXPCONNECTWRAPPEDNATIVE_IID \
  {0xe787be29, 0xdb5d, 0x4a45, \
    { 0xa3, 0xd6, 0x1d, 0xe1, 0xd6, 0xb8, 0x5c, 0x30 }}

class nsIXPConnectWrappedNative : public nsIXPConnectJSObjectHolder {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECTWRAPPEDNATIVE_IID)

  /* readonly attribute nsISupports Native; */
  NS_IMETHOD GetNative(nsISupports * *aNative) = 0;

  /* readonly attribute JSObjectPtr JSObjectPrototype; */
  NS_IMETHOD GetJSObjectPrototype(JSObject **aJSObjectPrototype) = 0;

  /* nsIInterfaceInfo FindInterfaceWithMember (in JSHandleId nameID); */
  NS_IMETHOD FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) = 0;

  /* nsIInterfaceInfo FindInterfaceWithName (in JSHandleId nameID); */
  NS_IMETHOD FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) = 0;

  /* [notxpcom] bool HasNativeMember (in JSHandleId name); */
  NS_IMETHOD_(bool) HasNativeMember(JS::Handle<jsid> name) = 0;

  /* void debugDump (in short depth); */
  NS_IMETHOD DebugDump(int16_t depth) = 0;

     /**
     * Faster access to the native object from C++.  Will never return null.
     */
    nsISupports* Native() const { return mIdentity; }
protected:
    nsCOMPtr<nsISupports> mIdentity;
public:
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnectWrappedNative, NS_IXPCONNECTWRAPPEDNATIVE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECTWRAPPEDNATIVE \
  NS_IMETHOD GetNative(nsISupports * *aNative) override; \
  NS_IMETHOD GetJSObjectPrototype(JSObject **aJSObjectPrototype) override; \
  NS_IMETHOD FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) override; \
  NS_IMETHOD FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) override; \
  NS_IMETHOD_(bool) HasNativeMember(JS::Handle<jsid> name) override; \
  NS_IMETHOD DebugDump(int16_t depth) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECTWRAPPEDNATIVE(_to) \
  NS_IMETHOD GetNative(nsISupports * *aNative) override { return _to GetNative(aNative); } \
  NS_IMETHOD GetJSObjectPrototype(JSObject **aJSObjectPrototype) override { return _to GetJSObjectPrototype(aJSObjectPrototype); } \
  NS_IMETHOD FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) override { return _to FindInterfaceWithMember(nameID, _retval); } \
  NS_IMETHOD FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) override { return _to FindInterfaceWithName(nameID, _retval); } \
  NS_IMETHOD_(bool) HasNativeMember(JS::Handle<jsid> name) override { return _to HasNativeMember(name); } \
  NS_IMETHOD DebugDump(int16_t depth) override { return _to DebugDump(depth); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECTWRAPPEDNATIVE(_to) \
  NS_IMETHOD GetNative(nsISupports * *aNative) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNative(aNative); } \
  NS_IMETHOD GetJSObjectPrototype(JSObject **aJSObjectPrototype) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSObjectPrototype(aJSObjectPrototype); } \
  NS_IMETHOD FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindInterfaceWithMember(nameID, _retval); } \
  NS_IMETHOD FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindInterfaceWithName(nameID, _retval); } \
  NS_IMETHOD_(bool) HasNativeMember(JS::Handle<jsid> name) override; \
  NS_IMETHOD DebugDump(int16_t depth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDump(depth); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnectWrappedNative : public nsIXPConnectWrappedNative
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECTWRAPPEDNATIVE

  nsXPConnectWrappedNative();

private:
  ~nsXPConnectWrappedNative();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPConnectWrappedNative, nsIXPConnectWrappedNative)

nsXPConnectWrappedNative::nsXPConnectWrappedNative()
{
  /* member initializers and constructor code */
}

nsXPConnectWrappedNative::~nsXPConnectWrappedNative()
{
  /* destructor code */
}

/* readonly attribute nsISupports Native; */
NS_IMETHODIMP nsXPConnectWrappedNative::GetNative(nsISupports * *aNative)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute JSObjectPtr JSObjectPrototype; */
NS_IMETHODIMP nsXPConnectWrappedNative::GetJSObjectPrototype(JSObject **aJSObjectPrototype)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo FindInterfaceWithMember (in JSHandleId nameID); */
NS_IMETHODIMP nsXPConnectWrappedNative::FindInterfaceWithMember(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo FindInterfaceWithName (in JSHandleId nameID); */
NS_IMETHODIMP nsXPConnectWrappedNative::FindInterfaceWithName(JS::Handle<jsid> nameID, nsIInterfaceInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] bool HasNativeMember (in JSHandleId name); */
NS_IMETHODIMP_(bool) nsXPConnectWrappedNative::HasNativeMember(JS::Handle<jsid> name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDump (in short depth); */
NS_IMETHODIMP nsXPConnectWrappedNative::DebugDump(int16_t depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


inline
const nsQueryInterface
do_QueryWrappedNative(nsIXPConnectWrappedNative *aWrappedNative)
{
    return nsQueryInterface(aWrappedNative->Native());
}
inline
const nsQueryInterfaceWithError
do_QueryWrappedNative(nsIXPConnectWrappedNative *aWrappedNative,
                      nsresult *aError)
{
    return nsQueryInterfaceWithError(aWrappedNative->Native(), aError);
}

/* starting interface:    nsIXPConnectWrappedJS */
#define NS_IXPCONNECTWRAPPEDJS_IID_STR "3a01b0d6-074b-49ed-bac3-08c76366cae4"

#define NS_IXPCONNECTWRAPPEDJS_IID \
  {0x3a01b0d6, 0x074b, 0x49ed, \
    { 0xba, 0xc3, 0x08, 0xc7, 0x63, 0x66, 0xca, 0xe4 }}

class NS_NO_VTABLE nsIXPConnectWrappedJS : public nsIXPConnectJSObjectHolder {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECTWRAPPEDJS_IID)

  /* readonly attribute nsIInterfaceInfo InterfaceInfo; */
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) = 0;

  /* readonly attribute nsIIDPtr InterfaceIID; */
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) = 0;

  /* void debugDump (in short depth); */
  NS_IMETHOD DebugDump(int16_t depth) = 0;

  /* void aggregatedQueryInterface (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void **result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnectWrappedJS, NS_IXPCONNECTWRAPPEDJS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECTWRAPPEDJS \
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) override; \
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) override; \
  NS_IMETHOD DebugDump(int16_t depth) override; \
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void **result) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECTWRAPPEDJS(_to) \
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) override { return _to GetInterfaceInfo(aInterfaceInfo); } \
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) override { return _to GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD DebugDump(int16_t depth) override { return _to DebugDump(depth); } \
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void **result) override { return _to AggregatedQueryInterface(uuid, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECTWRAPPEDJS(_to) \
  NS_IMETHOD GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceInfo(aInterfaceInfo); } \
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD DebugDump(int16_t depth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDump(depth); } \
  NS_IMETHOD AggregatedQueryInterface(const nsIID & uuid, void **result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AggregatedQueryInterface(uuid, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnectWrappedJS : public nsIXPConnectWrappedJS
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECTWRAPPEDJS

  nsXPConnectWrappedJS();

private:
  ~nsXPConnectWrappedJS();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPConnectWrappedJS, nsIXPConnectWrappedJS)

nsXPConnectWrappedJS::nsXPConnectWrappedJS()
{
  /* member initializers and constructor code */
}

nsXPConnectWrappedJS::~nsXPConnectWrappedJS()
{
  /* destructor code */
}

/* readonly attribute nsIInterfaceInfo InterfaceInfo; */
NS_IMETHODIMP nsXPConnectWrappedJS::GetInterfaceInfo(nsIInterfaceInfo * *aInterfaceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDPtr InterfaceIID; */
NS_IMETHODIMP nsXPConnectWrappedJS::GetInterfaceIID(nsIID **aInterfaceIID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDump (in short depth); */
NS_IMETHODIMP nsXPConnectWrappedJS::DebugDump(int16_t depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void aggregatedQueryInterface (in nsIIDRef uuid, [iid_is (uuid), retval] out nsQIResult result); */
NS_IMETHODIMP nsXPConnectWrappedJS::AggregatedQueryInterface(const nsIID & uuid, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCWrappedJSObjectGetter */
#define NS_IXPCWRAPPEDJSOBJECTGETTER_IID_STR "254bb2e0-6439-11d4-8fe0-0010a4e73d9a"

#define NS_IXPCWRAPPEDJSOBJECTGETTER_IID \
  {0x254bb2e0, 0x6439, 0x11d4, \
    { 0x8f, 0xe0, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIXPCWrappedJSObjectGetter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCWRAPPEDJSOBJECTGETTER_IID)

  /* readonly attribute nsISupports neverCalled; */
  NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCWrappedJSObjectGetter, NS_IXPCWRAPPEDJSOBJECTGETTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCWRAPPEDJSOBJECTGETTER \
  NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCWRAPPEDJSOBJECTGETTER(_to) \
  NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) override { return _to GetNeverCalled(aNeverCalled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCWRAPPEDJSOBJECTGETTER(_to) \
  NS_IMETHOD GetNeverCalled(nsISupports * *aNeverCalled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNeverCalled(aNeverCalled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCWrappedJSObjectGetter : public nsIXPCWrappedJSObjectGetter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCWRAPPEDJSOBJECTGETTER

  nsXPCWrappedJSObjectGetter();

private:
  ~nsXPCWrappedJSObjectGetter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCWrappedJSObjectGetter, nsIXPCWrappedJSObjectGetter)

nsXPCWrappedJSObjectGetter::nsXPCWrappedJSObjectGetter()
{
  /* member initializers and constructor code */
}

nsXPCWrappedJSObjectGetter::~nsXPCWrappedJSObjectGetter()
{
  /* destructor code */
}

/* readonly attribute nsISupports neverCalled; */
NS_IMETHODIMP nsXPCWrappedJSObjectGetter::GetNeverCalled(nsISupports * *aNeverCalled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCFunctionThisTranslator */
#define NS_IXPCFUNCTIONTHISTRANSLATOR_IID_STR "f5f84b70-92eb-41f1-a1dd-2eaac0ed564c"

#define NS_IXPCFUNCTIONTHISTRANSLATOR_IID \
  {0xf5f84b70, 0x92eb, 0x41f1, \
    { 0xa1, 0xdd, 0x2e, 0xaa, 0xc0, 0xed, 0x56, 0x4c }}

class NS_NO_VTABLE nsIXPCFunctionThisTranslator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCFUNCTIONTHISTRANSLATOR_IID)

  /* nsISupports TranslateThis (in nsISupports aInitialThis); */
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCFunctionThisTranslator, NS_IXPCFUNCTIONTHISTRANSLATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCFUNCTIONTHISTRANSLATOR \
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCFUNCTIONTHISTRANSLATOR(_to) \
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval) override { return _to TranslateThis(aInitialThis, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCFUNCTIONTHISTRANSLATOR(_to) \
  NS_IMETHOD TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TranslateThis(aInitialThis, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCFunctionThisTranslator : public nsIXPCFunctionThisTranslator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCFUNCTIONTHISTRANSLATOR

  nsXPCFunctionThisTranslator();

private:
  ~nsXPCFunctionThisTranslator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCFunctionThisTranslator, nsIXPCFunctionThisTranslator)

nsXPCFunctionThisTranslator::nsXPCFunctionThisTranslator()
{
  /* member initializers and constructor code */
}

nsXPCFunctionThisTranslator::~nsXPCFunctionThisTranslator()
{
  /* destructor code */
}

/* nsISupports TranslateThis (in nsISupports aInitialThis); */
NS_IMETHODIMP nsXPCFunctionThisTranslator::TranslateThis(nsISupports *aInitialThis, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// For use with the service manager
// {CB6593E0-F9B2-11d2-BDD6-000064657374}
#define NS_XPCONNECT_CID \
{ 0xcb6593e0, 0xf9b2, 0x11d2, \
    { 0xbd, 0xd6, 0x0, 0x0, 0x64, 0x65, 0x73, 0x74 } }

/* starting interface:    nsIXPConnect */
#define NS_IXPCONNECT_IID_STR "241fbefa-89dc-42b2-b180-08167d4b351b"

#define NS_IXPCONNECT_IID \
  {0x241fbefa, 0x89dc, 0x42b2, \
    { 0xb1, 0x80, 0x08, 0x16, 0x7d, 0x4b, 0x35, 0x1b }}

class nsIXPConnect : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCONNECT_IID)

   NS_DEFINE_STATIC_CID_ACCESSOR(NS_XPCONNECT_CID)
  /* nsIXPConnectJSObjectHolder initClassesWithNewWrappedGlobal (in JSContextPtr aJSContext, in nsISupports aCOMObj, in nsIPrincipal aPrincipal, in uint32_t aFlags, in JSCompartmentOptions aOptions); */
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval) = 0;

  enum {
    INIT_JS_STANDARD_CLASSES = 1U,
    DONT_FIRE_ONNEWGLOBALHOOK = 2U,
    OMIT_COMPONENTS_OBJECT = 4U
  };

  /* nsIXPConnectJSObjectHolder wrapNative (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
  NS_IMETHOD WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval) = 0;

  /* void wrapNativeToJSVal (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsWrapperCachePtr aCache, in nsIIDPtr aIID, in boolean aAllowWrapper, out jsval aVal); */
  NS_IMETHOD WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal) = 0;

  /* void wrapJS (in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
  NS_IMETHOD WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) = 0;

  /* nsIVariant jSValToVariant (in JSContextPtr cx, in jsval aJSVal); */
  NS_IMETHOD JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval) = 0;

  /* nsIXPConnectWrappedNative getWrappedNativeOfJSObject (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval) = 0;

  /* [noscript,notxpcom] nsISupports getNativeOfWrapper (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
  NS_IMETHOD_(nsISupports *) GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj) = 0;

  /* [noscript,nostdcall,notxpcom] JSContextPtr getCurrentJSContext (); */
  virtual JSContext * GetCurrentJSContext(void) = 0;

  /* [noscript,nostdcall,notxpcom] JSContextPtr getSafeJSContext (); */
  virtual JSContext * GetSafeJSContext(void) = 0;

  /* readonly attribute nsIStackFrame CurrentJSStack; */
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) = 0;

  /* readonly attribute nsAXPCNativeCallContextPtr CurrentNativeCallContext; */
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext) = 0;

  /* void debugDump (in short depth); */
  NS_IMETHOD DebugDump(int16_t depth) = 0;

  /* void debugDumpObject (in nsISupports aCOMObj, in short depth); */
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, int16_t depth) = 0;

  /* void debugDumpJSStack (in boolean showArgs, in boolean showLocals, in boolean showThisProps); */
  NS_IMETHOD DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps) = 0;

  /* void wrapJSAggregatedToNative (in nsISupports aOuter, in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) = 0;

  /* nsIXPConnectWrappedNative getWrappedNativeOfNativeObject (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval) = 0;

  /* void setFunctionThisTranslator (in nsIIDRef aIID, in nsIXPCFunctionThisTranslator aTranslator); */
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator) = 0;

  /* nsIXPConnectJSObjectHolder getWrappedNativePrototype (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsIClassInfo aClassInfo); */
  NS_IMETHOD GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval) = 0;

  /* jsval variantToJS (in JSContextPtr ctx, in JSObjectPtr scope, in nsIVariant value); */
  NS_IMETHOD VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval) = 0;

  /* nsIVariant JSToVariant (in JSContextPtr ctx, in jsval value); */
  NS_IMETHOD JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval) = 0;

  /* [noscript] nsIXPConnectJSObjectHolder createSandbox (in JSContextPtr cx, in nsIPrincipal principal); */
  NS_IMETHOD CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval) = 0;

  /* [noscript] jsval evalInSandboxObject (in AString source, in string filename, in JSContextPtr cx, in JSObjectPtr sandbox); */
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, JS::MutableHandleValue _retval) = 0;

  /* void setReportAllJSExceptions (in boolean reportAllJSExceptions); */
  NS_IMETHOD SetReportAllJSExceptions(bool reportAllJSExceptions) = 0;

  /* void GarbageCollect (in uint32_t reason); */
  NS_IMETHOD GarbageCollect(uint32_t reason) = 0;

  /* void NotifyDidPaint (); */
  NS_IMETHOD NotifyDidPaint(void) = 0;

     /**
     * Get the object principal for this wrapper.  Note that this may well end
     * up being null; in that case one should seek principals elsewhere.  Null
     * here does NOT indicate system principal or no principals at all, just
     * that this wrapper doesn't have an intrinsic one.
     */
    virtual nsIPrincipal* GetPrincipal(JSObject* obj,
                                       bool allowShortCircuit) const = 0;
    virtual char* DebugPrintJSStack(bool showArgs,
                                    bool showLocals,
                                    bool showThisProps) = 0;
  /* [noscript] void writeScript (in nsIObjectOutputStream aStream, in JSContextPtr aJSContext, in JSScriptPtr aJSScript); */
  NS_IMETHOD WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript) = 0;

  /* [noscript] JSScriptPtr readScript (in nsIObjectInputStream aStream, in JSContextPtr aJSContext); */
  NS_IMETHOD ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval) = 0;

  /* [noscript] void writeFunction (in nsIObjectOutputStream aStream, in JSContextPtr aJSContext, in JSObjectPtr aJSObject); */
  NS_IMETHOD WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject) = 0;

  /* [noscript] JSObjectPtr readFunction (in nsIObjectInputStream aStream, in JSContextPtr aJSContext); */
  NS_IMETHOD ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPConnect, NS_IXPCONNECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCONNECT \
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval) override; \
  NS_IMETHOD WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval) override; \
  NS_IMETHOD WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal) override; \
  NS_IMETHOD WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) override; \
  NS_IMETHOD JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval) override; \
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval) override; \
  NS_IMETHOD_(nsISupports *) GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj) override; \
  virtual JSContext * GetCurrentJSContext(void) override; \
  virtual JSContext * GetSafeJSContext(void) override; \
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) override; \
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext) override; \
  NS_IMETHOD DebugDump(int16_t depth) override; \
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, int16_t depth) override; \
  NS_IMETHOD DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps) override; \
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) override; \
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval) override; \
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator) override; \
  NS_IMETHOD GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval) override; \
  NS_IMETHOD VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval) override; \
  NS_IMETHOD CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval) override; \
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD SetReportAllJSExceptions(bool reportAllJSExceptions) override; \
  NS_IMETHOD GarbageCollect(uint32_t reason) override; \
  NS_IMETHOD NotifyDidPaint(void) override; \
  NS_IMETHOD WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript) override; \
  NS_IMETHOD ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval) override; \
  NS_IMETHOD WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject) override; \
  NS_IMETHOD ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCONNECT(_to) \
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval) override { return _to InitClassesWithNewWrappedGlobal(aJSContext, aCOMObj, aPrincipal, aFlags, aOptions, _retval); } \
  NS_IMETHOD WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval) override { return _to WrapNative(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal) override { return _to WrapNativeToJSVal(aJSContext, aScope, aCOMObj, aCache, aIID, aAllowWrapper, aVal); } \
  NS_IMETHOD WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) override { return _to WrapJS(aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval) override { return _to JSValToVariant(cx, aJSVal, _retval); } \
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval) override { return _to GetWrappedNativeOfJSObject(aJSContext, aJSObj, _retval); } \
  NS_IMETHOD_(nsISupports *) GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj) override { return _to GetNativeOfWrapper(aJSContext, aJSObj); } \
  virtual JSContext * GetCurrentJSContext(void) override { return _to GetCurrentJSContext(); } \
  virtual JSContext * GetSafeJSContext(void) override { return _to GetSafeJSContext(); } \
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) override { return _to GetCurrentJSStack(aCurrentJSStack); } \
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext) override { return _to GetCurrentNativeCallContext(aCurrentNativeCallContext); } \
  NS_IMETHOD DebugDump(int16_t depth) override { return _to DebugDump(depth); } \
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, int16_t depth) override { return _to DebugDumpObject(aCOMObj, depth); } \
  NS_IMETHOD DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps) override { return _to DebugDumpJSStack(showArgs, showLocals, showThisProps); } \
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) override { return _to WrapJSAggregatedToNative(aOuter, aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval) override { return _to GetWrappedNativeOfNativeObject(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator) override { return _to SetFunctionThisTranslator(aIID, aTranslator); } \
  NS_IMETHOD GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval) override { return _to GetWrappedNativePrototype(aJSContext, aScope, aClassInfo, _retval); } \
  NS_IMETHOD VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval) override { return _to VariantToJS(ctx, scope, value, _retval); } \
  NS_IMETHOD JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval) override { return _to JSToVariant(ctx, value, _retval); } \
  NS_IMETHOD CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval) override { return _to CreateSandbox(cx, principal, _retval); } \
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, JS::MutableHandleValue _retval) override { return _to EvalInSandboxObject(source, filename, cx, sandbox, _retval); } \
  NS_IMETHOD SetReportAllJSExceptions(bool reportAllJSExceptions) override { return _to SetReportAllJSExceptions(reportAllJSExceptions); } \
  NS_IMETHOD GarbageCollect(uint32_t reason) override { return _to GarbageCollect(reason); } \
  NS_IMETHOD NotifyDidPaint(void) override { return _to NotifyDidPaint(); } \
  NS_IMETHOD WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript) override { return _to WriteScript(aStream, aJSContext, aJSScript); } \
  NS_IMETHOD ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval) override { return _to ReadScript(aStream, aJSContext, _retval); } \
  NS_IMETHOD WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject) override { return _to WriteFunction(aStream, aJSContext, aJSObject); } \
  NS_IMETHOD ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval) override { return _to ReadFunction(aStream, aJSContext, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCONNECT(_to) \
  NS_IMETHOD InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InitClassesWithNewWrappedGlobal(aJSContext, aCOMObj, aPrincipal, aFlags, aOptions, _retval); } \
  NS_IMETHOD WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapNative(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapNativeToJSVal(aJSContext, aScope, aCOMObj, aCache, aIID, aAllowWrapper, aVal); } \
  NS_IMETHOD WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapJS(aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->JSValToVariant(cx, aJSVal, _retval); } \
  NS_IMETHOD GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedNativeOfJSObject(aJSContext, aJSObj, _retval); } \
  NS_IMETHOD_(nsISupports *) GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj) override; \
  virtual JSContext * GetCurrentJSContext(void) override; \
  virtual JSContext * GetSafeJSContext(void) override; \
  NS_IMETHOD GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentJSStack(aCurrentJSStack); } \
  NS_IMETHOD GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentNativeCallContext(aCurrentNativeCallContext); } \
  NS_IMETHOD DebugDump(int16_t depth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDump(depth); } \
  NS_IMETHOD DebugDumpObject(nsISupports *aCOMObj, int16_t depth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpObject(aCOMObj, depth); } \
  NS_IMETHOD DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpJSStack(showArgs, showLocals, showThisProps); } \
  NS_IMETHOD WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapJSAggregatedToNative(aOuter, aJSContext, aJSObj, aIID, result); } \
  NS_IMETHOD GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedNativeOfNativeObject(aJSContext, aScope, aCOMObj, aIID, _retval); } \
  NS_IMETHOD SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFunctionThisTranslator(aIID, aTranslator); } \
  NS_IMETHOD GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWrappedNativePrototype(aJSContext, aScope, aClassInfo, _retval); } \
  NS_IMETHOD VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->VariantToJS(ctx, scope, value, _retval); } \
  NS_IMETHOD JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->JSToVariant(ctx, value, _retval); } \
  NS_IMETHOD CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSandbox(cx, principal, _retval); } \
  NS_IMETHOD EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EvalInSandboxObject(source, filename, cx, sandbox, _retval); } \
  NS_IMETHOD SetReportAllJSExceptions(bool reportAllJSExceptions) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReportAllJSExceptions(reportAllJSExceptions); } \
  NS_IMETHOD GarbageCollect(uint32_t reason) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GarbageCollect(reason); } \
  NS_IMETHOD NotifyDidPaint(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDidPaint(); } \
  NS_IMETHOD WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteScript(aStream, aJSContext, aJSScript); } \
  NS_IMETHOD ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadScript(aStream, aJSContext, _retval); } \
  NS_IMETHOD WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteFunction(aStream, aJSContext, aJSObject); } \
  NS_IMETHOD ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadFunction(aStream, aJSContext, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPConnect : public nsIXPConnect
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCONNECT

  nsXPConnect();

private:
  ~nsXPConnect();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPConnect, nsIXPConnect)

nsXPConnect::nsXPConnect()
{
  /* member initializers and constructor code */
}

nsXPConnect::~nsXPConnect()
{
  /* destructor code */
}

/* nsIXPConnectJSObjectHolder initClassesWithNewWrappedGlobal (in JSContextPtr aJSContext, in nsISupports aCOMObj, in nsIPrincipal aPrincipal, in uint32_t aFlags, in JSCompartmentOptions aOptions); */
NS_IMETHODIMP nsXPConnect::InitClassesWithNewWrappedGlobal(JSContext *aJSContext, nsISupports *aCOMObj, nsIPrincipal *aPrincipal, uint32_t aFlags, JS::CompartmentOptions & aOptions, nsIXPConnectJSObjectHolder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder wrapNative (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
NS_IMETHODIMP nsXPConnect::WrapNative(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectJSObjectHolder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrapNativeToJSVal (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsWrapperCachePtr aCache, in nsIIDPtr aIID, in boolean aAllowWrapper, out jsval aVal); */
NS_IMETHODIMP nsXPConnect::WrapNativeToJSVal(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, nsWrapperCache *aCache, const nsIID *aIID, bool aAllowWrapper, JS::MutableHandleValue aVal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrapJS (in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
NS_IMETHODIMP nsXPConnect::WrapJS(JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant jSValToVariant (in JSContextPtr cx, in jsval aJSVal); */
NS_IMETHODIMP nsXPConnect::JSValToVariant(JSContext *cx, JS::HandleValue aJSVal, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectWrappedNative getWrappedNativeOfJSObject (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
NS_IMETHODIMP nsXPConnect::GetWrappedNativeOfJSObject(JSContext *aJSContext, JSObject *aJSObj, nsIXPConnectWrappedNative * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] nsISupports getNativeOfWrapper (in JSContextPtr aJSContext, in JSObjectPtr aJSObj); */
NS_IMETHODIMP_(nsISupports *) nsXPConnect::GetNativeOfWrapper(JSContext *aJSContext, JSObject *aJSObj)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] JSContextPtr getCurrentJSContext (); */
JSContext * nsXPConnect::GetCurrentJSContext()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] JSContextPtr getSafeJSContext (); */
JSContext * nsXPConnect::GetSafeJSContext()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame CurrentJSStack; */
NS_IMETHODIMP nsXPConnect::GetCurrentJSStack(nsIStackFrame * *aCurrentJSStack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsAXPCNativeCallContextPtr CurrentNativeCallContext; */
NS_IMETHODIMP nsXPConnect::GetCurrentNativeCallContext(nsAXPCNativeCallContext **aCurrentNativeCallContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDump (in short depth); */
NS_IMETHODIMP nsXPConnect::DebugDump(int16_t depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpObject (in nsISupports aCOMObj, in short depth); */
NS_IMETHODIMP nsXPConnect::DebugDumpObject(nsISupports *aCOMObj, int16_t depth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpJSStack (in boolean showArgs, in boolean showLocals, in boolean showThisProps); */
NS_IMETHODIMP nsXPConnect::DebugDumpJSStack(bool showArgs, bool showLocals, bool showThisProps)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wrapJSAggregatedToNative (in nsISupports aOuter, in JSContextPtr aJSContext, in JSObjectPtr aJSObj, in nsIIDRef aIID, [iid_is (aIID), retval] out nsQIResult result); */
NS_IMETHODIMP nsXPConnect::WrapJSAggregatedToNative(nsISupports *aOuter, JSContext *aJSContext, JSObject *aJSObj, const nsIID & aIID, void **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectWrappedNative getWrappedNativeOfNativeObject (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsISupports aCOMObj, in nsIIDRef aIID); */
NS_IMETHODIMP nsXPConnect::GetWrappedNativeOfNativeObject(JSContext *aJSContext, JSObject *aScope, nsISupports *aCOMObj, const nsIID & aIID, nsIXPConnectWrappedNative * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFunctionThisTranslator (in nsIIDRef aIID, in nsIXPCFunctionThisTranslator aTranslator); */
NS_IMETHODIMP nsXPConnect::SetFunctionThisTranslator(const nsIID & aIID, nsIXPCFunctionThisTranslator *aTranslator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXPConnectJSObjectHolder getWrappedNativePrototype (in JSContextPtr aJSContext, in JSObjectPtr aScope, in nsIClassInfo aClassInfo); */
NS_IMETHODIMP nsXPConnect::GetWrappedNativePrototype(JSContext *aJSContext, JSObject *aScope, nsIClassInfo *aClassInfo, nsIXPConnectJSObjectHolder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval variantToJS (in JSContextPtr ctx, in JSObjectPtr scope, in nsIVariant value); */
NS_IMETHODIMP nsXPConnect::VariantToJS(JSContext *ctx, JSObject *scope, nsIVariant *value, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant JSToVariant (in JSContextPtr ctx, in jsval value); */
NS_IMETHODIMP nsXPConnect::JSToVariant(JSContext *ctx, JS::HandleValue value, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIXPConnectJSObjectHolder createSandbox (in JSContextPtr cx, in nsIPrincipal principal); */
NS_IMETHODIMP nsXPConnect::CreateSandbox(JSContext *cx, nsIPrincipal *principal, nsIXPConnectJSObjectHolder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] jsval evalInSandboxObject (in AString source, in string filename, in JSContextPtr cx, in JSObjectPtr sandbox); */
NS_IMETHODIMP nsXPConnect::EvalInSandboxObject(const nsAString & source, const char * filename, JSContext *cx, JSObject *sandbox, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setReportAllJSExceptions (in boolean reportAllJSExceptions); */
NS_IMETHODIMP nsXPConnect::SetReportAllJSExceptions(bool reportAllJSExceptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GarbageCollect (in uint32_t reason); */
NS_IMETHODIMP nsXPConnect::GarbageCollect(uint32_t reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void NotifyDidPaint (); */
NS_IMETHODIMP nsXPConnect::NotifyDidPaint()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void writeScript (in nsIObjectOutputStream aStream, in JSContextPtr aJSContext, in JSScriptPtr aJSScript); */
NS_IMETHODIMP nsXPConnect::WriteScript(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSScript *aJSScript)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSScriptPtr readScript (in nsIObjectInputStream aStream, in JSContextPtr aJSContext); */
NS_IMETHODIMP nsXPConnect::ReadScript(nsIObjectInputStream *aStream, JSContext *aJSContext, JSScript **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void writeFunction (in nsIObjectOutputStream aStream, in JSContextPtr aJSContext, in JSObjectPtr aJSObject); */
NS_IMETHODIMP nsXPConnect::WriteFunction(nsIObjectOutputStream *aStream, JSContext *aJSContext, JSObject *aJSObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] JSObjectPtr readFunction (in nsIObjectInputStream aStream, in JSContextPtr aJSContext); */
NS_IMETHODIMP nsXPConnect::ReadFunction(nsIObjectInputStream *aStream, JSContext *aJSContext, JSObject **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPConnect_h__ */
