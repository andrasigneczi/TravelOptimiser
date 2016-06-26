/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInterfaceInfo.idl
 */

#ifndef __gen_nsIInterfaceInfo_h__
#define __gen_nsIInterfaceInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsXPTMethodInfo;
class nsXPTParamInfo;
class nsXPTType;

/* starting interface:    nsIInterfaceInfo */
#define NS_IINTERFACEINFO_IID_STR "3820e663-8e22-4789-b470-56bcf7083f2b"

#define NS_IINTERFACEINFO_IID \
  {0x3820e663, 0x8e22, 0x4789, \
    { 0xb4, 0x70, 0x56, 0xbc, 0xf7, 0x08, 0x3f, 0x2b }}

class NS_NO_VTABLE nsIInterfaceInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINTERFACEINFO_IID)

  /* readonly attribute string name; */
  NS_IMETHOD GetName(char * *aName) = 0;

  /* readonly attribute nsIIDPtr InterfaceIID; */
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) = 0;

  /* boolean isScriptable (); */
  NS_IMETHOD IsScriptable(bool *_retval) = 0;

  /* boolean isBuiltinClass (); */
  NS_IMETHOD IsBuiltinClass(bool *_retval) = 0;

  /* readonly attribute nsIInterfaceInfo parent; */
  NS_IMETHOD GetParent(nsIInterfaceInfo * *aParent) = 0;

  /* readonly attribute uint16_t methodCount; */
  NS_IMETHOD GetMethodCount(uint16_t *aMethodCount) = 0;

  /* readonly attribute uint16_t constantCount; */
  NS_IMETHOD GetConstantCount(uint16_t *aConstantCount) = 0;

  /* void getMethodInfo (in uint16_t index, [shared, retval] out nsXPTMethodInfoPtr info); */
  NS_IMETHOD GetMethodInfo(uint16_t index, const nsXPTMethodInfo **info) = 0;

  /* void getMethodInfoForName (in string methodName, out uint16_t index, [shared, retval] out nsXPTMethodInfoPtr info); */
  NS_IMETHOD GetMethodInfoForName(const char * methodName, uint16_t *index, const nsXPTMethodInfo **info) = 0;

  /* void getConstant (in uint16_t index, out jsval constant, out string name); */
  NS_IMETHOD GetConstant(uint16_t index, JS::MutableHandleValue constant, char * *name) = 0;

  /* nsIInterfaceInfo getInfoForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param); */
  NS_IMETHOD GetInfoForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIInterfaceInfo * *_retval) = 0;

  /* nsIIDPtr getIIDForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param); */
  NS_IMETHOD GetIIDForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID **_retval) = 0;

  /* nsXPTType getTypeForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param, in uint16_t dimension); */
  NS_IMETHOD GetTypeForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, nsXPTType *_retval) = 0;

  /* uint8_t getSizeIsArgNumberForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param, in uint16_t dimension); */
  NS_IMETHOD GetSizeIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, uint8_t *_retval) = 0;

  /* uint8_t getInterfaceIsArgNumberForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param); */
  NS_IMETHOD GetInterfaceIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint8_t *_retval) = 0;

  /* boolean isIID (in nsIIDPtr IID); */
  NS_IMETHOD IsIID(const nsIID *IID, bool *_retval) = 0;

  /* void getNameShared ([shared, retval] out string name); */
  NS_IMETHOD GetNameShared(const char * *name) = 0;

  /* void getIIDShared ([shared, retval] out nsIIDPtrShared iid); */
  NS_IMETHOD GetIIDShared(const nsIID **iid) = 0;

  /* boolean isFunction (); */
  NS_IMETHOD IsFunction(bool *_retval) = 0;

  /* boolean hasAncestor (in nsIIDPtr iid); */
  NS_IMETHOD HasAncestor(const nsIID *iid, bool *_retval) = 0;

  /* [notxpcom] nsresult getIIDForParamNoAlloc (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param, out nsIID iid); */
  NS_IMETHOD_(nsresult) GetIIDForParamNoAlloc(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID *iid) = 0;

  /* boolean isMainProcessScriptableOnly (); */
  NS_IMETHOD IsMainProcessScriptableOnly(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInterfaceInfo, NS_IINTERFACEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINTERFACEINFO \
  NS_IMETHOD GetName(char * *aName) override; \
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) override; \
  NS_IMETHOD IsScriptable(bool *_retval) override; \
  NS_IMETHOD IsBuiltinClass(bool *_retval) override; \
  NS_IMETHOD GetParent(nsIInterfaceInfo * *aParent) override; \
  NS_IMETHOD GetMethodCount(uint16_t *aMethodCount) override; \
  NS_IMETHOD GetConstantCount(uint16_t *aConstantCount) override; \
  NS_IMETHOD GetMethodInfo(uint16_t index, const nsXPTMethodInfo **info) override; \
  NS_IMETHOD GetMethodInfoForName(const char * methodName, uint16_t *index, const nsXPTMethodInfo **info) override; \
  NS_IMETHOD GetConstant(uint16_t index, JS::MutableHandleValue constant, char * *name) override; \
  NS_IMETHOD GetInfoForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIInterfaceInfo * *_retval) override; \
  NS_IMETHOD GetIIDForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID **_retval) override; \
  NS_IMETHOD GetTypeForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, nsXPTType *_retval) override; \
  NS_IMETHOD GetSizeIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, uint8_t *_retval) override; \
  NS_IMETHOD GetInterfaceIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint8_t *_retval) override; \
  NS_IMETHOD IsIID(const nsIID *IID, bool *_retval) override; \
  NS_IMETHOD GetNameShared(const char * *name) override; \
  NS_IMETHOD GetIIDShared(const nsIID **iid) override; \
  NS_IMETHOD IsFunction(bool *_retval) override; \
  NS_IMETHOD HasAncestor(const nsIID *iid, bool *_retval) override; \
  NS_IMETHOD_(nsresult) GetIIDForParamNoAlloc(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID *iid) override; \
  NS_IMETHOD IsMainProcessScriptableOnly(bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINTERFACEINFO(_to) \
  NS_IMETHOD GetName(char * *aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) override { return _to GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD IsScriptable(bool *_retval) override { return _to IsScriptable(_retval); } \
  NS_IMETHOD IsBuiltinClass(bool *_retval) override { return _to IsBuiltinClass(_retval); } \
  NS_IMETHOD GetParent(nsIInterfaceInfo * *aParent) override { return _to GetParent(aParent); } \
  NS_IMETHOD GetMethodCount(uint16_t *aMethodCount) override { return _to GetMethodCount(aMethodCount); } \
  NS_IMETHOD GetConstantCount(uint16_t *aConstantCount) override { return _to GetConstantCount(aConstantCount); } \
  NS_IMETHOD GetMethodInfo(uint16_t index, const nsXPTMethodInfo **info) override { return _to GetMethodInfo(index, info); } \
  NS_IMETHOD GetMethodInfoForName(const char * methodName, uint16_t *index, const nsXPTMethodInfo **info) override { return _to GetMethodInfoForName(methodName, index, info); } \
  NS_IMETHOD GetConstant(uint16_t index, JS::MutableHandleValue constant, char * *name) override { return _to GetConstant(index, constant, name); } \
  NS_IMETHOD GetInfoForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIInterfaceInfo * *_retval) override { return _to GetInfoForParam(methodIndex, param, _retval); } \
  NS_IMETHOD GetIIDForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID **_retval) override { return _to GetIIDForParam(methodIndex, param, _retval); } \
  NS_IMETHOD GetTypeForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, nsXPTType *_retval) override { return _to GetTypeForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetSizeIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, uint8_t *_retval) override { return _to GetSizeIsArgNumberForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetInterfaceIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint8_t *_retval) override { return _to GetInterfaceIsArgNumberForParam(methodIndex, param, _retval); } \
  NS_IMETHOD IsIID(const nsIID *IID, bool *_retval) override { return _to IsIID(IID, _retval); } \
  NS_IMETHOD GetNameShared(const char * *name) override { return _to GetNameShared(name); } \
  NS_IMETHOD GetIIDShared(const nsIID **iid) override { return _to GetIIDShared(iid); } \
  NS_IMETHOD IsFunction(bool *_retval) override { return _to IsFunction(_retval); } \
  NS_IMETHOD HasAncestor(const nsIID *iid, bool *_retval) override { return _to HasAncestor(iid, _retval); } \
  NS_IMETHOD_(nsresult) GetIIDForParamNoAlloc(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID *iid) override { return _to GetIIDForParamNoAlloc(methodIndex, param, iid); } \
  NS_IMETHOD IsMainProcessScriptableOnly(bool *_retval) override { return _to IsMainProcessScriptableOnly(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINTERFACEINFO(_to) \
  NS_IMETHOD GetName(char * *aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetInterfaceIID(nsIID **aInterfaceIID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceIID(aInterfaceIID); } \
  NS_IMETHOD IsScriptable(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsScriptable(_retval); } \
  NS_IMETHOD IsBuiltinClass(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsBuiltinClass(_retval); } \
  NS_IMETHOD GetParent(nsIInterfaceInfo * *aParent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_IMETHOD GetMethodCount(uint16_t *aMethodCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMethodCount(aMethodCount); } \
  NS_IMETHOD GetConstantCount(uint16_t *aConstantCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConstantCount(aConstantCount); } \
  NS_IMETHOD GetMethodInfo(uint16_t index, const nsXPTMethodInfo **info) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMethodInfo(index, info); } \
  NS_IMETHOD GetMethodInfoForName(const char * methodName, uint16_t *index, const nsXPTMethodInfo **info) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMethodInfoForName(methodName, index, info); } \
  NS_IMETHOD GetConstant(uint16_t index, JS::MutableHandleValue constant, char * *name) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConstant(index, constant, name); } \
  NS_IMETHOD GetInfoForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIInterfaceInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInfoForParam(methodIndex, param, _retval); } \
  NS_IMETHOD GetIIDForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID **_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIIDForParam(methodIndex, param, _retval); } \
  NS_IMETHOD GetTypeForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, nsXPTType *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetSizeIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, uint8_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSizeIsArgNumberForParam(methodIndex, param, dimension, _retval); } \
  NS_IMETHOD GetInterfaceIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint8_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceIsArgNumberForParam(methodIndex, param, _retval); } \
  NS_IMETHOD IsIID(const nsIID *IID, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsIID(IID, _retval); } \
  NS_IMETHOD GetNameShared(const char * *name) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNameShared(name); } \
  NS_IMETHOD GetIIDShared(const nsIID **iid) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIIDShared(iid); } \
  NS_IMETHOD IsFunction(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsFunction(_retval); } \
  NS_IMETHOD HasAncestor(const nsIID *iid, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasAncestor(iid, _retval); } \
  NS_IMETHOD_(nsresult) GetIIDForParamNoAlloc(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID *iid) override; \
  NS_IMETHOD IsMainProcessScriptableOnly(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsMainProcessScriptableOnly(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInterfaceInfo : public nsIInterfaceInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINTERFACEINFO

  nsInterfaceInfo();

private:
  ~nsInterfaceInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsInterfaceInfo, nsIInterfaceInfo)

nsInterfaceInfo::nsInterfaceInfo()
{
  /* member initializers and constructor code */
}

nsInterfaceInfo::~nsInterfaceInfo()
{
  /* destructor code */
}

/* readonly attribute string name; */
NS_IMETHODIMP nsInterfaceInfo::GetName(char * *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDPtr InterfaceIID; */
NS_IMETHODIMP nsInterfaceInfo::GetInterfaceIID(nsIID **aInterfaceIID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isScriptable (); */
NS_IMETHODIMP nsInterfaceInfo::IsScriptable(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isBuiltinClass (); */
NS_IMETHODIMP nsInterfaceInfo::IsBuiltinClass(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIInterfaceInfo parent; */
NS_IMETHODIMP nsInterfaceInfo::GetParent(nsIInterfaceInfo * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint16_t methodCount; */
NS_IMETHODIMP nsInterfaceInfo::GetMethodCount(uint16_t *aMethodCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint16_t constantCount; */
NS_IMETHODIMP nsInterfaceInfo::GetConstantCount(uint16_t *aConstantCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMethodInfo (in uint16_t index, [shared, retval] out nsXPTMethodInfoPtr info); */
NS_IMETHODIMP nsInterfaceInfo::GetMethodInfo(uint16_t index, const nsXPTMethodInfo **info)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getMethodInfoForName (in string methodName, out uint16_t index, [shared, retval] out nsXPTMethodInfoPtr info); */
NS_IMETHODIMP nsInterfaceInfo::GetMethodInfoForName(const char * methodName, uint16_t *index, const nsXPTMethodInfo **info)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getConstant (in uint16_t index, out jsval constant, out string name); */
NS_IMETHODIMP nsInterfaceInfo::GetConstant(uint16_t index, JS::MutableHandleValue constant, char * *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInterfaceInfo getInfoForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param); */
NS_IMETHODIMP nsInterfaceInfo::GetInfoForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIInterfaceInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIIDPtr getIIDForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param); */
NS_IMETHODIMP nsInterfaceInfo::GetIIDForParam(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsXPTType getTypeForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param, in uint16_t dimension); */
NS_IMETHODIMP nsInterfaceInfo::GetTypeForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, nsXPTType *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint8_t getSizeIsArgNumberForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param, in uint16_t dimension); */
NS_IMETHODIMP nsInterfaceInfo::GetSizeIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint16_t dimension, uint8_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint8_t getInterfaceIsArgNumberForParam (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param); */
NS_IMETHODIMP nsInterfaceInfo::GetInterfaceIsArgNumberForParam(uint16_t methodIndex, const nsXPTParamInfo *param, uint8_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isIID (in nsIIDPtr IID); */
NS_IMETHODIMP nsInterfaceInfo::IsIID(const nsIID *IID, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNameShared ([shared, retval] out string name); */
NS_IMETHODIMP nsInterfaceInfo::GetNameShared(const char * *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getIIDShared ([shared, retval] out nsIIDPtrShared iid); */
NS_IMETHODIMP nsInterfaceInfo::GetIIDShared(const nsIID **iid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isFunction (); */
NS_IMETHODIMP nsInterfaceInfo::IsFunction(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasAncestor (in nsIIDPtr iid); */
NS_IMETHODIMP nsInterfaceInfo::HasAncestor(const nsIID *iid, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] nsresult getIIDForParamNoAlloc (in uint16_t methodIndex, [const] in nsXPTParamInfoPtr param, out nsIID iid); */
NS_IMETHODIMP_(nsresult) nsInterfaceInfo::GetIIDForParamNoAlloc(uint16_t methodIndex, const nsXPTParamInfo *param, nsIID *iid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isMainProcessScriptableOnly (); */
NS_IMETHODIMP nsInterfaceInfo::IsMainProcessScriptableOnly(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInterfaceInfo_h__ */
