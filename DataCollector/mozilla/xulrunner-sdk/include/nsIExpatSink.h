/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIExpatSink.idl
 */

#ifndef __gen_nsIExpatSink_h__
#define __gen_nsIExpatSink_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIScriptError; /* forward declaration */


/* starting interface:    nsIExpatSink */
#define NS_IEXPATSINK_IID_STR "01f681af-0f22-4725-a914-0d396114daf0"

#define NS_IEXPATSINK_IID \
  {0x01f681af, 0x0f22, 0x4725, \
    { 0xa9, 0x14, 0x0d, 0x39, 0x61, 0x14, 0xda, 0xf0 }}

class NS_NO_VTABLE nsIExpatSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXPATSINK_IID)

  /* void HandleStartElement (in wstring aName, [array, size_is (aAttsCount)] in wstring aAtts, in unsigned long aAttsCount, in unsigned long aLineNumber); */
  NS_IMETHOD HandleStartElement(const char16_t * aName, const char16_t * *aAtts, uint32_t aAttsCount, uint32_t aLineNumber) = 0;

  /* void HandleEndElement (in wstring aName); */
  NS_IMETHOD HandleEndElement(const char16_t * aName) = 0;

  /* void HandleComment (in wstring aCommentText); */
  NS_IMETHOD HandleComment(const char16_t * aCommentText) = 0;

  /* void HandleCDataSection ([size_is (aLength)] in wstring aData, in unsigned long aLength); */
  NS_IMETHOD HandleCDataSection(const char16_t * aData, uint32_t aLength) = 0;

  /* void HandleDoctypeDecl (in AString aSubset, in AString aName, in AString aSystemId, in AString aPublicId, in nsISupports aCatalogData); */
  NS_IMETHOD HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData) = 0;

  /* void HandleCharacterData ([size_is (aLength)] in wstring aData, in unsigned long aLength); */
  NS_IMETHOD HandleCharacterData(const char16_t * aData, uint32_t aLength) = 0;

  /* void HandleProcessingInstruction (in wstring aTarget, in wstring aData); */
  NS_IMETHOD HandleProcessingInstruction(const char16_t * aTarget, const char16_t * aData) = 0;

  /* void HandleXMLDeclaration (in wstring aVersion, in wstring aEncoding, in long aStandalone); */
  NS_IMETHOD HandleXMLDeclaration(const char16_t * aVersion, const char16_t * aEncoding, int32_t aStandalone) = 0;

  /* boolean ReportError (in wstring aErrorText, in wstring aSourceText, in nsIScriptError aError); */
  NS_IMETHOD ReportError(const char16_t * aErrorText, const char16_t * aSourceText, nsIScriptError *aError, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExpatSink, NS_IEXPATSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXPATSINK \
  NS_IMETHOD HandleStartElement(const char16_t * aName, const char16_t * *aAtts, uint32_t aAttsCount, uint32_t aLineNumber) override; \
  NS_IMETHOD HandleEndElement(const char16_t * aName) override; \
  NS_IMETHOD HandleComment(const char16_t * aCommentText) override; \
  NS_IMETHOD HandleCDataSection(const char16_t * aData, uint32_t aLength) override; \
  NS_IMETHOD HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData) override; \
  NS_IMETHOD HandleCharacterData(const char16_t * aData, uint32_t aLength) override; \
  NS_IMETHOD HandleProcessingInstruction(const char16_t * aTarget, const char16_t * aData) override; \
  NS_IMETHOD HandleXMLDeclaration(const char16_t * aVersion, const char16_t * aEncoding, int32_t aStandalone) override; \
  NS_IMETHOD ReportError(const char16_t * aErrorText, const char16_t * aSourceText, nsIScriptError *aError, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXPATSINK(_to) \
  NS_IMETHOD HandleStartElement(const char16_t * aName, const char16_t * *aAtts, uint32_t aAttsCount, uint32_t aLineNumber) override { return _to HandleStartElement(aName, aAtts, aAttsCount, aLineNumber); } \
  NS_IMETHOD HandleEndElement(const char16_t * aName) override { return _to HandleEndElement(aName); } \
  NS_IMETHOD HandleComment(const char16_t * aCommentText) override { return _to HandleComment(aCommentText); } \
  NS_IMETHOD HandleCDataSection(const char16_t * aData, uint32_t aLength) override { return _to HandleCDataSection(aData, aLength); } \
  NS_IMETHOD HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData) override { return _to HandleDoctypeDecl(aSubset, aName, aSystemId, aPublicId, aCatalogData); } \
  NS_IMETHOD HandleCharacterData(const char16_t * aData, uint32_t aLength) override { return _to HandleCharacterData(aData, aLength); } \
  NS_IMETHOD HandleProcessingInstruction(const char16_t * aTarget, const char16_t * aData) override { return _to HandleProcessingInstruction(aTarget, aData); } \
  NS_IMETHOD HandleXMLDeclaration(const char16_t * aVersion, const char16_t * aEncoding, int32_t aStandalone) override { return _to HandleXMLDeclaration(aVersion, aEncoding, aStandalone); } \
  NS_IMETHOD ReportError(const char16_t * aErrorText, const char16_t * aSourceText, nsIScriptError *aError, bool *_retval) override { return _to ReportError(aErrorText, aSourceText, aError, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXPATSINK(_to) \
  NS_IMETHOD HandleStartElement(const char16_t * aName, const char16_t * *aAtts, uint32_t aAttsCount, uint32_t aLineNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleStartElement(aName, aAtts, aAttsCount, aLineNumber); } \
  NS_IMETHOD HandleEndElement(const char16_t * aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEndElement(aName); } \
  NS_IMETHOD HandleComment(const char16_t * aCommentText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleComment(aCommentText); } \
  NS_IMETHOD HandleCDataSection(const char16_t * aData, uint32_t aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCDataSection(aData, aLength); } \
  NS_IMETHOD HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleDoctypeDecl(aSubset, aName, aSystemId, aPublicId, aCatalogData); } \
  NS_IMETHOD HandleCharacterData(const char16_t * aData, uint32_t aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCharacterData(aData, aLength); } \
  NS_IMETHOD HandleProcessingInstruction(const char16_t * aTarget, const char16_t * aData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleProcessingInstruction(aTarget, aData); } \
  NS_IMETHOD HandleXMLDeclaration(const char16_t * aVersion, const char16_t * aEncoding, int32_t aStandalone) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleXMLDeclaration(aVersion, aEncoding, aStandalone); } \
  NS_IMETHOD ReportError(const char16_t * aErrorText, const char16_t * aSourceText, nsIScriptError *aError, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReportError(aErrorText, aSourceText, aError, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExpatSink : public nsIExpatSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXPATSINK

  nsExpatSink();

private:
  ~nsExpatSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsExpatSink, nsIExpatSink)

nsExpatSink::nsExpatSink()
{
  /* member initializers and constructor code */
}

nsExpatSink::~nsExpatSink()
{
  /* destructor code */
}

/* void HandleStartElement (in wstring aName, [array, size_is (aAttsCount)] in wstring aAtts, in unsigned long aAttsCount, in unsigned long aLineNumber); */
NS_IMETHODIMP nsExpatSink::HandleStartElement(const char16_t * aName, const char16_t * *aAtts, uint32_t aAttsCount, uint32_t aLineNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleEndElement (in wstring aName); */
NS_IMETHODIMP nsExpatSink::HandleEndElement(const char16_t * aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleComment (in wstring aCommentText); */
NS_IMETHODIMP nsExpatSink::HandleComment(const char16_t * aCommentText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleCDataSection ([size_is (aLength)] in wstring aData, in unsigned long aLength); */
NS_IMETHODIMP nsExpatSink::HandleCDataSection(const char16_t * aData, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleDoctypeDecl (in AString aSubset, in AString aName, in AString aSystemId, in AString aPublicId, in nsISupports aCatalogData); */
NS_IMETHODIMP nsExpatSink::HandleDoctypeDecl(const nsAString & aSubset, const nsAString & aName, const nsAString & aSystemId, const nsAString & aPublicId, nsISupports *aCatalogData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleCharacterData ([size_is (aLength)] in wstring aData, in unsigned long aLength); */
NS_IMETHODIMP nsExpatSink::HandleCharacterData(const char16_t * aData, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleProcessingInstruction (in wstring aTarget, in wstring aData); */
NS_IMETHODIMP nsExpatSink::HandleProcessingInstruction(const char16_t * aTarget, const char16_t * aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HandleXMLDeclaration (in wstring aVersion, in wstring aEncoding, in long aStandalone); */
NS_IMETHODIMP nsExpatSink::HandleXMLDeclaration(const char16_t * aVersion, const char16_t * aEncoding, int32_t aStandalone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean ReportError (in wstring aErrorText, in wstring aSourceText, in nsIScriptError aError); */
NS_IMETHODIMP nsExpatSink::ReportError(const char16_t * aErrorText, const char16_t * aSourceText, nsIScriptError *aError, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIExpatSink_h__ */
