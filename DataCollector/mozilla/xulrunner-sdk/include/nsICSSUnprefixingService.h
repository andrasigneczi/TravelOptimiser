/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICSSUnprefixingService.idl
 */

#ifndef __gen_nsICSSUnprefixingService_h__
#define __gen_nsICSSUnprefixingService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICSSUnprefixingService */
#define NS_ICSSUNPREFIXINGSERVICE_IID_STR "a5d6e2f4-d3ec-11e4-b002-782bcbaebb28"

#define NS_ICSSUNPREFIXINGSERVICE_IID \
  {0xa5d6e2f4, 0xd3ec, 0x11e4, \
    { 0xb0, 0x02, 0x78, 0x2b, 0xcb, 0xae, 0xbb, 0x28 }}

class NS_NO_VTABLE nsICSSUnprefixingService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICSSUNPREFIXINGSERVICE_IID)

  /* boolean generateUnprefixedDeclaration (in AString aPropName, in AString aRightHalfOfDecl, out AString aUnprefixedDecl); */
  NS_IMETHOD GenerateUnprefixedDeclaration(const nsAString & aPropName, const nsAString & aRightHalfOfDecl, nsAString & aUnprefixedDecl, bool *_retval) = 0;

  /* boolean generateUnprefixedGradientValue (in AString aPrefixedFuncName, in AString aPrefixedFuncBody, out AString aUnprefixedFuncName, out AString aUnprefixedFuncBody); */
  NS_IMETHOD GenerateUnprefixedGradientValue(const nsAString & aPrefixedFuncName, const nsAString & aPrefixedFuncBody, nsAString & aUnprefixedFuncName, nsAString & aUnprefixedFuncBody, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICSSUnprefixingService, NS_ICSSUNPREFIXINGSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICSSUNPREFIXINGSERVICE \
  NS_IMETHOD GenerateUnprefixedDeclaration(const nsAString & aPropName, const nsAString & aRightHalfOfDecl, nsAString & aUnprefixedDecl, bool *_retval) override; \
  NS_IMETHOD GenerateUnprefixedGradientValue(const nsAString & aPrefixedFuncName, const nsAString & aPrefixedFuncBody, nsAString & aUnprefixedFuncName, nsAString & aUnprefixedFuncBody, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICSSUNPREFIXINGSERVICE(_to) \
  NS_IMETHOD GenerateUnprefixedDeclaration(const nsAString & aPropName, const nsAString & aRightHalfOfDecl, nsAString & aUnprefixedDecl, bool *_retval) override { return _to GenerateUnprefixedDeclaration(aPropName, aRightHalfOfDecl, aUnprefixedDecl, _retval); } \
  NS_IMETHOD GenerateUnprefixedGradientValue(const nsAString & aPrefixedFuncName, const nsAString & aPrefixedFuncBody, nsAString & aUnprefixedFuncName, nsAString & aUnprefixedFuncBody, bool *_retval) override { return _to GenerateUnprefixedGradientValue(aPrefixedFuncName, aPrefixedFuncBody, aUnprefixedFuncName, aUnprefixedFuncBody, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICSSUNPREFIXINGSERVICE(_to) \
  NS_IMETHOD GenerateUnprefixedDeclaration(const nsAString & aPropName, const nsAString & aRightHalfOfDecl, nsAString & aUnprefixedDecl, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateUnprefixedDeclaration(aPropName, aRightHalfOfDecl, aUnprefixedDecl, _retval); } \
  NS_IMETHOD GenerateUnprefixedGradientValue(const nsAString & aPrefixedFuncName, const nsAString & aPrefixedFuncBody, nsAString & aUnprefixedFuncName, nsAString & aUnprefixedFuncBody, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateUnprefixedGradientValue(aPrefixedFuncName, aPrefixedFuncBody, aUnprefixedFuncName, aUnprefixedFuncBody, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCSSUnprefixingService : public nsICSSUnprefixingService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICSSUNPREFIXINGSERVICE

  nsCSSUnprefixingService();

private:
  ~nsCSSUnprefixingService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCSSUnprefixingService, nsICSSUnprefixingService)

nsCSSUnprefixingService::nsCSSUnprefixingService()
{
  /* member initializers and constructor code */
}

nsCSSUnprefixingService::~nsCSSUnprefixingService()
{
  /* destructor code */
}

/* boolean generateUnprefixedDeclaration (in AString aPropName, in AString aRightHalfOfDecl, out AString aUnprefixedDecl); */
NS_IMETHODIMP nsCSSUnprefixingService::GenerateUnprefixedDeclaration(const nsAString & aPropName, const nsAString & aRightHalfOfDecl, nsAString & aUnprefixedDecl, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean generateUnprefixedGradientValue (in AString aPrefixedFuncName, in AString aPrefixedFuncBody, out AString aUnprefixedFuncName, out AString aUnprefixedFuncBody); */
NS_IMETHODIMP nsCSSUnprefixingService::GenerateUnprefixedGradientValue(const nsAString & aPrefixedFuncName, const nsAString & aPrefixedFuncBody, nsAString & aUnprefixedFuncName, nsAString & aUnprefixedFuncBody, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CSSUNPREFIXINGSERVICE_CONTRACTID \
    "@mozilla.org/css-unprefixing-service;1"

#endif /* __gen_nsICSSUnprefixingService_h__ */
