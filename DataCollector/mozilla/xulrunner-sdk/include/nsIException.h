/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIException.idl
 */

#ifndef __gen_nsIException_h__
#define __gen_nsIException_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStackFrame */
#define NS_ISTACKFRAME_IID_STR "28bfb2a2-5ea6-4738-918b-049dc4d51f0b"

#define NS_ISTACKFRAME_IID \
  {0x28bfb2a2, 0x5ea6, 0x4738, \
    { 0x91, 0x8b, 0x04, 0x9d, 0xc4, 0xd5, 0x1f, 0x0b }}

class NS_NO_VTABLE nsIStackFrame : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTACKFRAME_IID)

  /* readonly attribute uint32_t language; */
  NS_IMETHOD GetLanguage(uint32_t *aLanguage) = 0;

  /* readonly attribute AUTF8String languageName; */
  NS_IMETHOD GetLanguageName(nsACString & aLanguageName) = 0;

  /* readonly attribute AString filename; */
  NS_IMETHOD GetFilename(nsAString & aFilename) = 0;

  /* readonly attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute int32_t lineNumber; */
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) = 0;

  /* readonly attribute int32_t columnNumber; */
  NS_IMETHOD GetColumnNumber(int32_t *aColumnNumber) = 0;

  /* readonly attribute AUTF8String sourceLine; */
  NS_IMETHOD GetSourceLine(nsACString & aSourceLine) = 0;

  /* readonly attribute AString asyncCause; */
  NS_IMETHOD GetAsyncCause(nsAString & aAsyncCause) = 0;

  /* readonly attribute nsIStackFrame asyncCaller; */
  NS_IMETHOD GetAsyncCaller(nsIStackFrame * *aAsyncCaller) = 0;

  /* readonly attribute nsIStackFrame caller; */
  NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) = 0;

  /* readonly attribute AString formattedStack; */
  NS_IMETHOD GetFormattedStack(nsAString & aFormattedStack) = 0;

  /* readonly attribute jsval nativeSavedFrame; */
  NS_IMETHOD GetNativeSavedFrame(JS::MutableHandleValue aNativeSavedFrame) = 0;

  /* AUTF8String toString (); */
  NS_IMETHOD ToString(nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStackFrame, NS_ISTACKFRAME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTACKFRAME \
  NS_IMETHOD GetLanguage(uint32_t *aLanguage) override; \
  NS_IMETHOD GetLanguageName(nsACString & aLanguageName) override; \
  NS_IMETHOD GetFilename(nsAString & aFilename) override; \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) override; \
  NS_IMETHOD GetColumnNumber(int32_t *aColumnNumber) override; \
  NS_IMETHOD GetSourceLine(nsACString & aSourceLine) override; \
  NS_IMETHOD GetAsyncCause(nsAString & aAsyncCause) override; \
  NS_IMETHOD GetAsyncCaller(nsIStackFrame * *aAsyncCaller) override; \
  NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) override; \
  NS_IMETHOD GetFormattedStack(nsAString & aFormattedStack) override; \
  NS_IMETHOD GetNativeSavedFrame(JS::MutableHandleValue aNativeSavedFrame) override; \
  NS_IMETHOD ToString(nsACString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTACKFRAME(_to) \
  NS_IMETHOD GetLanguage(uint32_t *aLanguage) override { return _to GetLanguage(aLanguage); } \
  NS_IMETHOD GetLanguageName(nsACString & aLanguageName) override { return _to GetLanguageName(aLanguageName); } \
  NS_IMETHOD GetFilename(nsAString & aFilename) override { return _to GetFilename(aFilename); } \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) override { return _to GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(int32_t *aColumnNumber) override { return _to GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetSourceLine(nsACString & aSourceLine) override { return _to GetSourceLine(aSourceLine); } \
  NS_IMETHOD GetAsyncCause(nsAString & aAsyncCause) override { return _to GetAsyncCause(aAsyncCause); } \
  NS_IMETHOD GetAsyncCaller(nsIStackFrame * *aAsyncCaller) override { return _to GetAsyncCaller(aAsyncCaller); } \
  NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) override { return _to GetCaller(aCaller); } \
  NS_IMETHOD GetFormattedStack(nsAString & aFormattedStack) override { return _to GetFormattedStack(aFormattedStack); } \
  NS_IMETHOD GetNativeSavedFrame(JS::MutableHandleValue aNativeSavedFrame) override { return _to GetNativeSavedFrame(aNativeSavedFrame); } \
  NS_IMETHOD ToString(nsACString & _retval) override { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTACKFRAME(_to) \
  NS_IMETHOD GetLanguage(uint32_t *aLanguage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } \
  NS_IMETHOD GetLanguageName(nsACString & aLanguageName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguageName(aLanguageName); } \
  NS_IMETHOD GetFilename(nsAString & aFilename) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetLineNumber(int32_t *aLineNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(int32_t *aColumnNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetSourceLine(nsACString & aSourceLine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceLine(aSourceLine); } \
  NS_IMETHOD GetAsyncCause(nsAString & aAsyncCause) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncCause(aAsyncCause); } \
  NS_IMETHOD GetAsyncCaller(nsIStackFrame * *aAsyncCaller) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncCaller(aAsyncCaller); } \
  NS_IMETHOD GetCaller(nsIStackFrame * *aCaller) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaller(aCaller); } \
  NS_IMETHOD GetFormattedStack(nsAString & aFormattedStack) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFormattedStack(aFormattedStack); } \
  NS_IMETHOD GetNativeSavedFrame(JS::MutableHandleValue aNativeSavedFrame) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeSavedFrame(aNativeSavedFrame); } \
  NS_IMETHOD ToString(nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStackFrame : public nsIStackFrame
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTACKFRAME

  nsStackFrame();

private:
  ~nsStackFrame();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStackFrame, nsIStackFrame)

nsStackFrame::nsStackFrame()
{
  /* member initializers and constructor code */
}

nsStackFrame::~nsStackFrame()
{
  /* destructor code */
}

/* readonly attribute uint32_t language; */
NS_IMETHODIMP nsStackFrame::GetLanguage(uint32_t *aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String languageName; */
NS_IMETHODIMP nsStackFrame::GetLanguageName(nsACString & aLanguageName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString filename; */
NS_IMETHODIMP nsStackFrame::GetFilename(nsAString & aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsStackFrame::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t lineNumber; */
NS_IMETHODIMP nsStackFrame::GetLineNumber(int32_t *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t columnNumber; */
NS_IMETHODIMP nsStackFrame::GetColumnNumber(int32_t *aColumnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String sourceLine; */
NS_IMETHODIMP nsStackFrame::GetSourceLine(nsACString & aSourceLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString asyncCause; */
NS_IMETHODIMP nsStackFrame::GetAsyncCause(nsAString & aAsyncCause)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame asyncCaller; */
NS_IMETHODIMP nsStackFrame::GetAsyncCaller(nsIStackFrame * *aAsyncCaller)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame caller; */
NS_IMETHODIMP nsStackFrame::GetCaller(nsIStackFrame * *aCaller)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString formattedStack; */
NS_IMETHODIMP nsStackFrame::GetFormattedStack(nsAString & aFormattedStack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval nativeSavedFrame; */
NS_IMETHODIMP nsStackFrame::GetNativeSavedFrame(JS::MutableHandleValue aNativeSavedFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String toString (); */
NS_IMETHODIMP nsStackFrame::ToString(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIException */
#define NS_IEXCEPTION_IID_STR "1caf1461-be1d-4b79-a552-5292b6bf3c35"

#define NS_IEXCEPTION_IID \
  {0x1caf1461, 0xbe1d, 0x4b79, \
    { 0xa5, 0x52, 0x52, 0x92, 0xb6, 0xbf, 0x3c, 0x35 }}

class NS_NO_VTABLE nsIException : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXCEPTION_IID)

  /* [binaryname(MessageMoz)] readonly attribute AUTF8String message; */
  NS_IMETHOD GetMessageMoz(nsACString & aMessage) = 0;

  /* readonly attribute nsresult result; */
  NS_IMETHOD GetResult(nsresult *aResult) = 0;

  /* readonly attribute AUTF8String name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute AString filename; */
  NS_IMETHOD GetFilename(nsAString & aFilename) = 0;

  /* readonly attribute uint32_t lineNumber; */
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) = 0;

  /* readonly attribute uint32_t columnNumber; */
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) = 0;

  /* readonly attribute nsIStackFrame location; */
  NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) = 0;

  /* readonly attribute nsIException inner; */
  NS_IMETHOD GetInner(nsIException * *aInner) = 0;

  /* readonly attribute nsISupports data; */
  NS_IMETHOD GetData(nsISupports * *aData) = 0;

  /* AUTF8String toString (); */
  NS_IMETHOD ToString(nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIException, NS_IEXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXCEPTION \
  NS_IMETHOD GetMessageMoz(nsACString & aMessage) override; \
  NS_IMETHOD GetResult(nsresult *aResult) override; \
  NS_IMETHOD GetName(nsACString & aName) override; \
  NS_IMETHOD GetFilename(nsAString & aFilename) override; \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) override; \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) override; \
  NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) override; \
  NS_IMETHOD GetInner(nsIException * *aInner) override; \
  NS_IMETHOD GetData(nsISupports * *aData) override; \
  NS_IMETHOD ToString(nsACString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXCEPTION(_to) \
  NS_IMETHOD GetMessageMoz(nsACString & aMessage) override { return _to GetMessageMoz(aMessage); } \
  NS_IMETHOD GetResult(nsresult *aResult) override { return _to GetResult(aResult); } \
  NS_IMETHOD GetName(nsACString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetFilename(nsAString & aFilename) override { return _to GetFilename(aFilename); } \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) override { return _to GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) override { return _to GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) override { return _to GetLocation(aLocation); } \
  NS_IMETHOD GetInner(nsIException * *aInner) override { return _to GetInner(aInner); } \
  NS_IMETHOD GetData(nsISupports * *aData) override { return _to GetData(aData); } \
  NS_IMETHOD ToString(nsACString & _retval) override { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXCEPTION(_to) \
  NS_IMETHOD GetMessageMoz(nsACString & aMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(aMessage); } \
  NS_IMETHOD GetResult(nsresult *aResult) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_IMETHOD GetName(nsACString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetFilename(nsAString & aFilename) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilename(aFilename); } \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetLocation(nsIStackFrame * *aLocation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocation(aLocation); } \
  NS_IMETHOD GetInner(nsIException * *aInner) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInner(aInner); } \
  NS_IMETHOD GetData(nsISupports * *aData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD ToString(nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsException : public nsIException
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXCEPTION

  nsException();

private:
  ~nsException();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsException, nsIException)

nsException::nsException()
{
  /* member initializers and constructor code */
}

nsException::~nsException()
{
  /* destructor code */
}

/* [binaryname(MessageMoz)] readonly attribute AUTF8String message; */
NS_IMETHODIMP nsException::GetMessageMoz(nsACString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsresult result; */
NS_IMETHODIMP nsException::GetResult(nsresult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String name; */
NS_IMETHODIMP nsException::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString filename; */
NS_IMETHODIMP nsException::GetFilename(nsAString & aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lineNumber; */
NS_IMETHODIMP nsException::GetLineNumber(uint32_t *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t columnNumber; */
NS_IMETHODIMP nsException::GetColumnNumber(uint32_t *aColumnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame location; */
NS_IMETHODIMP nsException::GetLocation(nsIStackFrame * *aLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIException inner; */
NS_IMETHODIMP nsException::GetInner(nsIException * *aInner)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports data; */
NS_IMETHODIMP nsException::GetData(nsISupports * *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AUTF8String toString (); */
NS_IMETHODIMP nsException::ToString(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIException_h__ */
