/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleDocument.idl
 */

#ifndef __gen_nsIAccessibleDocument_h__
#define __gen_nsIAccessibleDocument_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessiblePivot; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIAccessibleDocument */
#define NS_IACCESSIBLEDOCUMENT_IID_STR "2be938df-0210-4609-9ece-26b197a517e5"

#define NS_IACCESSIBLEDOCUMENT_IID \
  {0x2be938df, 0x0210, 0x4609, \
    { 0x9e, 0xce, 0x26, 0xb1, 0x97, 0xa5, 0x17, 0xe5 }}

class NS_NO_VTABLE nsIAccessibleDocument : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEDOCUMENT_IID)

  /* readonly attribute AString URL; */
  NS_IMETHOD GetURL(nsAString & aURL) = 0;

  /* readonly attribute AString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;

  /* readonly attribute AString mimeType; */
  NS_IMETHOD GetMimeType(nsAString & aMimeType) = 0;

  /* readonly attribute AString docType; */
  NS_IMETHOD GetDocType(nsAString & aDocType) = 0;

  /* readonly attribute nsIDOMDocument DOMDocument; */
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) = 0;

  /* readonly attribute nsIDOMWindow window; */
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) = 0;

  /* readonly attribute nsIAccessibleDocument parentDocument; */
  NS_IMETHOD GetParentDocument(nsIAccessibleDocument * *aParentDocument) = 0;

  /* readonly attribute unsigned long childDocumentCount; */
  NS_IMETHOD GetChildDocumentCount(uint32_t *aChildDocumentCount) = 0;

  /* readonly attribute nsIAccessiblePivot virtualCursor; */
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) = 0;

  /* nsIAccessibleDocument getChildDocumentAt (in unsigned long index); */
  NS_IMETHOD GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleDocument, NS_IACCESSIBLEDOCUMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEDOCUMENT \
  NS_IMETHOD GetURL(nsAString & aURL) override; \
  NS_IMETHOD GetTitle(nsAString & aTitle) override; \
  NS_IMETHOD GetMimeType(nsAString & aMimeType) override; \
  NS_IMETHOD GetDocType(nsAString & aDocType) override; \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) override; \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override; \
  NS_IMETHOD GetParentDocument(nsIAccessibleDocument * *aParentDocument) override; \
  NS_IMETHOD GetChildDocumentCount(uint32_t *aChildDocumentCount) override; \
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) override; \
  NS_IMETHOD GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEDOCUMENT(_to) \
  NS_IMETHOD GetURL(nsAString & aURL) override { return _to GetURL(aURL); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) override { return _to GetTitle(aTitle); } \
  NS_IMETHOD GetMimeType(nsAString & aMimeType) override { return _to GetMimeType(aMimeType); } \
  NS_IMETHOD GetDocType(nsAString & aDocType) override { return _to GetDocType(aDocType); } \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) override { return _to GetDOMDocument(aDOMDocument); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override { return _to GetWindow(aWindow); } \
  NS_IMETHOD GetParentDocument(nsIAccessibleDocument * *aParentDocument) override { return _to GetParentDocument(aParentDocument); } \
  NS_IMETHOD GetChildDocumentCount(uint32_t *aChildDocumentCount) override { return _to GetChildDocumentCount(aChildDocumentCount); } \
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) override { return _to GetVirtualCursor(aVirtualCursor); } \
  NS_IMETHOD GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval) override { return _to GetChildDocumentAt(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEDOCUMENT(_to) \
  NS_IMETHOD GetURL(nsAString & aURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURL(aURL); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD GetMimeType(nsAString & aMimeType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_IMETHOD GetDocType(nsAString & aDocType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocType(aDocType); } \
  NS_IMETHOD GetDOMDocument(nsIDOMDocument * *aDOMDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMDocument(aDOMDocument); } \
  NS_IMETHOD GetWindow(nsIDOMWindow * *aWindow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_IMETHOD GetParentDocument(nsIAccessibleDocument * *aParentDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentDocument(aParentDocument); } \
  NS_IMETHOD GetChildDocumentCount(uint32_t *aChildDocumentCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildDocumentCount(aChildDocumentCount); } \
  NS_IMETHOD GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVirtualCursor(aVirtualCursor); } \
  NS_IMETHOD GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildDocumentAt(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleDocument : public nsIAccessibleDocument
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEDOCUMENT

  nsAccessibleDocument();

private:
  ~nsAccessibleDocument();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessibleDocument, nsIAccessibleDocument)

nsAccessibleDocument::nsAccessibleDocument()
{
  /* member initializers and constructor code */
}

nsAccessibleDocument::~nsAccessibleDocument()
{
  /* destructor code */
}

/* readonly attribute AString URL; */
NS_IMETHODIMP nsAccessibleDocument::GetURL(nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString title; */
NS_IMETHODIMP nsAccessibleDocument::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString mimeType; */
NS_IMETHODIMP nsAccessibleDocument::GetMimeType(nsAString & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString docType; */
NS_IMETHODIMP nsAccessibleDocument::GetDocType(nsAString & aDocType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument DOMDocument; */
NS_IMETHODIMP nsAccessibleDocument::GetDOMDocument(nsIDOMDocument * *aDOMDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow window; */
NS_IMETHODIMP nsAccessibleDocument::GetWindow(nsIDOMWindow * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessibleDocument parentDocument; */
NS_IMETHODIMP nsAccessibleDocument::GetParentDocument(nsIAccessibleDocument * *aParentDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childDocumentCount; */
NS_IMETHODIMP nsAccessibleDocument::GetChildDocumentCount(uint32_t *aChildDocumentCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAccessiblePivot virtualCursor; */
NS_IMETHODIMP nsAccessibleDocument::GetVirtualCursor(nsIAccessiblePivot * *aVirtualCursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessibleDocument getChildDocumentAt (in unsigned long index); */
NS_IMETHODIMP nsAccessibleDocument::GetChildDocumentAt(uint32_t index, nsIAccessibleDocument * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleDocument_h__ */
