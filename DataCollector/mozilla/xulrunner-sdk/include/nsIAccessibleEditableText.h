/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleEditableText.idl
 */

#ifndef __gen_nsIAccessibleEditableText_h__
#define __gen_nsIAccessibleEditableText_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAccessibleEditableText */
#define NS_IACCESSIBLEEDITABLETEXT_IID_STR "28915cca-3366-4034-ba1d-b7afb9b37639"

#define NS_IACCESSIBLEEDITABLETEXT_IID \
  {0x28915cca, 0x3366, 0x4034, \
    { 0xba, 0x1d, 0xb7, 0xaf, 0xb9, 0xb3, 0x76, 0x39 }}

class NS_NO_VTABLE nsIAccessibleEditableText : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEEDITABLETEXT_IID)

  /* void setTextContents (in AString text); */
  NS_IMETHOD SetTextContents(const nsAString & text) = 0;

  /* void insertText (in AString text, in long position); */
  NS_IMETHOD InsertText(const nsAString & text, int32_t position) = 0;

  /* void copyText (in long startPos, in long endPos); */
  NS_IMETHOD CopyText(int32_t startPos, int32_t endPos) = 0;

  /* void cutText (in long startPos, in long endPos); */
  NS_IMETHOD CutText(int32_t startPos, int32_t endPos) = 0;

  /* void deleteText (in long startPos, in long endPos); */
  NS_IMETHOD DeleteText(int32_t startPos, int32_t endPos) = 0;

  /* void pasteText (in long position); */
  NS_IMETHOD PasteText(int32_t position) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleEditableText, NS_IACCESSIBLEEDITABLETEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEEDITABLETEXT \
  NS_IMETHOD SetTextContents(const nsAString & text) override; \
  NS_IMETHOD InsertText(const nsAString & text, int32_t position) override; \
  NS_IMETHOD CopyText(int32_t startPos, int32_t endPos) override; \
  NS_IMETHOD CutText(int32_t startPos, int32_t endPos) override; \
  NS_IMETHOD DeleteText(int32_t startPos, int32_t endPos) override; \
  NS_IMETHOD PasteText(int32_t position) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEEDITABLETEXT(_to) \
  NS_IMETHOD SetTextContents(const nsAString & text) override { return _to SetTextContents(text); } \
  NS_IMETHOD InsertText(const nsAString & text, int32_t position) override { return _to InsertText(text, position); } \
  NS_IMETHOD CopyText(int32_t startPos, int32_t endPos) override { return _to CopyText(startPos, endPos); } \
  NS_IMETHOD CutText(int32_t startPos, int32_t endPos) override { return _to CutText(startPos, endPos); } \
  NS_IMETHOD DeleteText(int32_t startPos, int32_t endPos) override { return _to DeleteText(startPos, endPos); } \
  NS_IMETHOD PasteText(int32_t position) override { return _to PasteText(position); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEEDITABLETEXT(_to) \
  NS_IMETHOD SetTextContents(const nsAString & text) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextContents(text); } \
  NS_IMETHOD InsertText(const nsAString & text, int32_t position) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertText(text, position); } \
  NS_IMETHOD CopyText(int32_t startPos, int32_t endPos) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyText(startPos, endPos); } \
  NS_IMETHOD CutText(int32_t startPos, int32_t endPos) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CutText(startPos, endPos); } \
  NS_IMETHOD DeleteText(int32_t startPos, int32_t endPos) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteText(startPos, endPos); } \
  NS_IMETHOD PasteText(int32_t position) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PasteText(position); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleEditableText : public nsIAccessibleEditableText
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEEDITABLETEXT

  nsAccessibleEditableText();

private:
  ~nsAccessibleEditableText();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessibleEditableText, nsIAccessibleEditableText)

nsAccessibleEditableText::nsAccessibleEditableText()
{
  /* member initializers and constructor code */
}

nsAccessibleEditableText::~nsAccessibleEditableText()
{
  /* destructor code */
}

/* void setTextContents (in AString text); */
NS_IMETHODIMP nsAccessibleEditableText::SetTextContents(const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertText (in AString text, in long position); */
NS_IMETHODIMP nsAccessibleEditableText::InsertText(const nsAString & text, int32_t position)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyText (in long startPos, in long endPos); */
NS_IMETHODIMP nsAccessibleEditableText::CopyText(int32_t startPos, int32_t endPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cutText (in long startPos, in long endPos); */
NS_IMETHODIMP nsAccessibleEditableText::CutText(int32_t startPos, int32_t endPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteText (in long startPos, in long endPos); */
NS_IMETHODIMP nsAccessibleEditableText::DeleteText(int32_t startPos, int32_t endPos)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pasteText (in long position); */
NS_IMETHODIMP nsAccessibleEditableText::PasteText(int32_t position)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleEditableText_h__ */
