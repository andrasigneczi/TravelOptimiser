/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIScriptError.idl
 */

#ifndef __gen_nsIScriptError_h__
#define __gen_nsIScriptError_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIConsoleMessage_h__
#include "nsIConsoleMessage.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsStringGlue.h" // for nsDependentCString

/* starting interface:    nsIScriptError */
#define NS_ISCRIPTERROR_IID_STR "248b2c94-2736-4d29-bfdf-bc64a2e60d35"

#define NS_ISCRIPTERROR_IID \
  {0x248b2c94, 0x2736, 0x4d29, \
    { 0xbf, 0xdf, 0xbc, 0x64, 0xa2, 0xe6, 0x0d, 0x35 }}

class nsIScriptError : public nsIConsoleMessage {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTERROR_IID)

  enum {
    errorFlag = 0U,
    warningFlag = 1U,
    exceptionFlag = 2U,
    strictFlag = 4U,
    infoFlag = 8U
  };

  /* readonly attribute AString errorMessage; */
  NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) = 0;

  /* readonly attribute AString sourceName; */
  NS_IMETHOD GetSourceName(nsAString & aSourceName) = 0;

  /* readonly attribute AString sourceLine; */
  NS_IMETHOD GetSourceLine(nsAString & aSourceLine) = 0;

  /* readonly attribute uint32_t lineNumber; */
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) = 0;

  /* readonly attribute uint32_t columnNumber; */
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) = 0;

  /* readonly attribute uint32_t flags; */
  NS_IMETHOD GetFlags(uint32_t *aFlags) = 0;

  /* readonly attribute string category; */
  NS_IMETHOD GetCategory(char * *aCategory) = 0;

  /* readonly attribute unsigned long long outerWindowID; */
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) = 0;

  /* readonly attribute unsigned long long innerWindowID; */
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) = 0;

  /* readonly attribute boolean isFromPrivateWindow; */
  NS_IMETHOD GetIsFromPrivateWindow(bool *aIsFromPrivateWindow) = 0;

  /* void init (in AString message, in AString sourceName, in AString sourceLine, in uint32_t lineNumber, in uint32_t columnNumber, in uint32_t flags, in string category); */
  NS_IMETHOD Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category) = 0;

  /* void initWithWindowID (in AString message, in AString sourceName, in AString sourceLine, in uint32_t lineNumber, in uint32_t columnNumber, in uint32_t flags, in ACString category, in unsigned long long innerWindowID); */
  NS_IMETHOD InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const nsACString & category, uint64_t innerWindowID) = 0;

     // This overload allows passing a literal string for category.
    template<uint32_t N>
    nsresult InitWithWindowID(const nsAString& message,
                              const nsAString& sourceName,
                              const nsAString& sourceLine,
                              uint32_t lineNumber,
                              uint32_t columnNumber,
                              uint32_t flags,
                              const char (&c)[N],
                              uint64_t aInnerWindowID)
    {
        nsDependentCString category(c, N - 1);
        return InitWithWindowID(message, sourceName, sourceLine, lineNumber,
                                columnNumber, flags, category, aInnerWindowID);
    }
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptError, NS_ISCRIPTERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTERROR \
  NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) override; \
  NS_IMETHOD GetSourceName(nsAString & aSourceName) override; \
  NS_IMETHOD GetSourceLine(nsAString & aSourceLine) override; \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) override; \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) override; \
  NS_IMETHOD GetFlags(uint32_t *aFlags) override; \
  NS_IMETHOD GetCategory(char * *aCategory) override; \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) override; \
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) override; \
  NS_IMETHOD GetIsFromPrivateWindow(bool *aIsFromPrivateWindow) override; \
  NS_IMETHOD Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category) override; \
  NS_IMETHOD InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const nsACString & category, uint64_t innerWindowID) override; \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTERROR(_to) \
  NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) override { return _to GetErrorMessage(aErrorMessage); } \
  NS_IMETHOD GetSourceName(nsAString & aSourceName) override { return _to GetSourceName(aSourceName); } \
  NS_IMETHOD GetSourceLine(nsAString & aSourceLine) override { return _to GetSourceLine(aSourceLine); } \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) override { return _to GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) override { return _to GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) override { return _to GetFlags(aFlags); } \
  NS_IMETHOD GetCategory(char * *aCategory) override { return _to GetCategory(aCategory); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) override { return _to GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) override { return _to GetInnerWindowID(aInnerWindowID); } \
  NS_IMETHOD GetIsFromPrivateWindow(bool *aIsFromPrivateWindow) override { return _to GetIsFromPrivateWindow(aIsFromPrivateWindow); } \
  NS_IMETHOD Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category) override { return _to Init(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category); } \
  NS_IMETHOD InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const nsACString & category, uint64_t innerWindowID) override { return _to InitWithWindowID(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category, innerWindowID); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTERROR(_to) \
  NS_IMETHOD GetErrorMessage(nsAString & aErrorMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorMessage(aErrorMessage); } \
  NS_IMETHOD GetSourceName(nsAString & aSourceName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceName(aSourceName); } \
  NS_IMETHOD GetSourceLine(nsAString & aSourceLine) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceLine(aSourceLine); } \
  NS_IMETHOD GetLineNumber(uint32_t *aLineNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLineNumber(aLineNumber); } \
  NS_IMETHOD GetColumnNumber(uint32_t *aColumnNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetColumnNumber(aColumnNumber); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_IMETHOD GetCategory(char * *aCategory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCategory(aCategory); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetInnerWindowID(uint64_t *aInnerWindowID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerWindowID(aInnerWindowID); } \
  NS_IMETHOD GetIsFromPrivateWindow(bool *aIsFromPrivateWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFromPrivateWindow(aIsFromPrivateWindow); } \
  NS_IMETHOD Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category); } \
  NS_IMETHOD InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const nsACString & category, uint64_t innerWindowID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithWindowID(message, sourceName, sourceLine, lineNumber, columnNumber, flags, category, innerWindowID); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptError : public nsIScriptError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTERROR

  nsScriptError();

private:
  ~nsScriptError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsScriptError, nsIScriptError)

nsScriptError::nsScriptError()
{
  /* member initializers and constructor code */
}

nsScriptError::~nsScriptError()
{
  /* destructor code */
}

/* readonly attribute AString errorMessage; */
NS_IMETHODIMP nsScriptError::GetErrorMessage(nsAString & aErrorMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString sourceName; */
NS_IMETHODIMP nsScriptError::GetSourceName(nsAString & aSourceName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString sourceLine; */
NS_IMETHODIMP nsScriptError::GetSourceLine(nsAString & aSourceLine)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t lineNumber; */
NS_IMETHODIMP nsScriptError::GetLineNumber(uint32_t *aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t columnNumber; */
NS_IMETHODIMP nsScriptError::GetColumnNumber(uint32_t *aColumnNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t flags; */
NS_IMETHODIMP nsScriptError::GetFlags(uint32_t *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string category; */
NS_IMETHODIMP nsScriptError::GetCategory(char * *aCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long outerWindowID; */
NS_IMETHODIMP nsScriptError::GetOuterWindowID(uint64_t *aOuterWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long innerWindowID; */
NS_IMETHODIMP nsScriptError::GetInnerWindowID(uint64_t *aInnerWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isFromPrivateWindow; */
NS_IMETHODIMP nsScriptError::GetIsFromPrivateWindow(bool *aIsFromPrivateWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in AString message, in AString sourceName, in AString sourceLine, in uint32_t lineNumber, in uint32_t columnNumber, in uint32_t flags, in string category); */
NS_IMETHODIMP nsScriptError::Init(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const char * category)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithWindowID (in AString message, in AString sourceName, in AString sourceLine, in uint32_t lineNumber, in uint32_t columnNumber, in uint32_t flags, in ACString category, in unsigned long long innerWindowID); */
NS_IMETHODIMP nsScriptError::InitWithWindowID(const nsAString & message, const nsAString & sourceName, const nsAString & sourceLine, uint32_t lineNumber, uint32_t columnNumber, uint32_t flags, const nsACString & category, uint64_t innerWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SCRIPTERROR_CID \
{ 0x1950539a, 0x90f0, 0x4d22, { 0xb5, 0xaf, 0x71, 0x32, 0x9c, 0x68, 0xfa, 0x35 }}
#define NS_SCRIPTERROR_CONTRACTID "@mozilla.org/scripterror;1"

#endif /* __gen_nsIScriptError_h__ */
