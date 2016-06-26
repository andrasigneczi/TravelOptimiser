/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDebug2.idl
 */

#ifndef __gen_nsIDebug2_h__
#define __gen_nsIDebug2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDebug2 */
#define NS_IDEBUG2_IID_STR "9641dc15-10fb-42e3-a285-18be90a5c10b"

#define NS_IDEBUG2_IID \
  {0x9641dc15, 0x10fb, 0x42e3, \
    { 0xa2, 0x85, 0x18, 0xbe, 0x90, 0xa5, 0xc1, 0x0b }}

class NS_NO_VTABLE nsIDebug2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDEBUG2_IID)

  /* readonly attribute boolean isDebugBuild; */
  NS_IMETHOD GetIsDebugBuild(bool *aIsDebugBuild) = 0;

  /* readonly attribute long assertionCount; */
  NS_IMETHOD GetAssertionCount(int32_t *aAssertionCount) = 0;

  /* readonly attribute bool isDebuggerAttached; */
  NS_IMETHOD GetIsDebuggerAttached(bool *aIsDebuggerAttached) = 0;

  /* void assertion (in string aStr, in string aExpr, in string aFile, in long aLine); */
  NS_IMETHOD Assertion(const char * aStr, const char * aExpr, const char * aFile, int32_t aLine) = 0;

  /* void warning (in string aStr, in string aFile, in long aLine); */
  NS_IMETHOD Warning(const char * aStr, const char * aFile, int32_t aLine) = 0;

  /* void break (in string aFile, in long aLine); */
  NS_IMETHOD Break(const char * aFile, int32_t aLine) = 0;

  /* void abort (in string aFile, in long aLine); */
  NS_IMETHOD Abort(const char * aFile, int32_t aLine) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDebug2, NS_IDEBUG2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDEBUG2 \
  NS_IMETHOD GetIsDebugBuild(bool *aIsDebugBuild) override; \
  NS_IMETHOD GetAssertionCount(int32_t *aAssertionCount) override; \
  NS_IMETHOD GetIsDebuggerAttached(bool *aIsDebuggerAttached) override; \
  NS_IMETHOD Assertion(const char * aStr, const char * aExpr, const char * aFile, int32_t aLine) override; \
  NS_IMETHOD Warning(const char * aStr, const char * aFile, int32_t aLine) override; \
  NS_IMETHOD Break(const char * aFile, int32_t aLine) override; \
  NS_IMETHOD Abort(const char * aFile, int32_t aLine) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDEBUG2(_to) \
  NS_IMETHOD GetIsDebugBuild(bool *aIsDebugBuild) override { return _to GetIsDebugBuild(aIsDebugBuild); } \
  NS_IMETHOD GetAssertionCount(int32_t *aAssertionCount) override { return _to GetAssertionCount(aAssertionCount); } \
  NS_IMETHOD GetIsDebuggerAttached(bool *aIsDebuggerAttached) override { return _to GetIsDebuggerAttached(aIsDebuggerAttached); } \
  NS_IMETHOD Assertion(const char * aStr, const char * aExpr, const char * aFile, int32_t aLine) override { return _to Assertion(aStr, aExpr, aFile, aLine); } \
  NS_IMETHOD Warning(const char * aStr, const char * aFile, int32_t aLine) override { return _to Warning(aStr, aFile, aLine); } \
  NS_IMETHOD Break(const char * aFile, int32_t aLine) override { return _to Break(aFile, aLine); } \
  NS_IMETHOD Abort(const char * aFile, int32_t aLine) override { return _to Abort(aFile, aLine); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDEBUG2(_to) \
  NS_IMETHOD GetIsDebugBuild(bool *aIsDebugBuild) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDebugBuild(aIsDebugBuild); } \
  NS_IMETHOD GetAssertionCount(int32_t *aAssertionCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAssertionCount(aAssertionCount); } \
  NS_IMETHOD GetIsDebuggerAttached(bool *aIsDebuggerAttached) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDebuggerAttached(aIsDebuggerAttached); } \
  NS_IMETHOD Assertion(const char * aStr, const char * aExpr, const char * aFile, int32_t aLine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Assertion(aStr, aExpr, aFile, aLine); } \
  NS_IMETHOD Warning(const char * aStr, const char * aFile, int32_t aLine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Warning(aStr, aFile, aLine); } \
  NS_IMETHOD Break(const char * aFile, int32_t aLine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Break(aFile, aLine); } \
  NS_IMETHOD Abort(const char * aFile, int32_t aLine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Abort(aFile, aLine); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDebug2 : public nsIDebug2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDEBUG2

  nsDebug2();

private:
  ~nsDebug2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDebug2, nsIDebug2)

nsDebug2::nsDebug2()
{
  /* member initializers and constructor code */
}

nsDebug2::~nsDebug2()
{
  /* destructor code */
}

/* readonly attribute boolean isDebugBuild; */
NS_IMETHODIMP nsDebug2::GetIsDebugBuild(bool *aIsDebugBuild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long assertionCount; */
NS_IMETHODIMP nsDebug2::GetAssertionCount(int32_t *aAssertionCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool isDebuggerAttached; */
NS_IMETHODIMP nsDebug2::GetIsDebuggerAttached(bool *aIsDebuggerAttached)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void assertion (in string aStr, in string aExpr, in string aFile, in long aLine); */
NS_IMETHODIMP nsDebug2::Assertion(const char * aStr, const char * aExpr, const char * aFile, int32_t aLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void warning (in string aStr, in string aFile, in long aLine); */
NS_IMETHODIMP nsDebug2::Warning(const char * aStr, const char * aFile, int32_t aLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void break (in string aFile, in long aLine); */
NS_IMETHODIMP nsDebug2::Break(const char * aFile, int32_t aLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (in string aFile, in long aLine); */
NS_IMETHODIMP nsDebug2::Abort(const char * aFile, int32_t aLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDebug2_h__ */
