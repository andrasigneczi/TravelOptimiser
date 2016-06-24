/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMenuBuilder.idl
 */

#ifndef __gen_nsIMenuBuilder_h__
#define __gen_nsIMenuBuilder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLMenuItemElement; /* forward declaration */


/* starting interface:    nsIMenuBuilder */
#define NS_IMENUBUILDER_IID_STR "93f4a48f-d043-4f45-97fd-9771ea1af976"

#define NS_IMENUBUILDER_IID \
  {0x93f4a48f, 0xd043, 0x4f45, \
    { 0x97, 0xfd, 0x97, 0x71, 0xea, 0x1a, 0xf9, 0x76 }}

class NS_NO_VTABLE nsIMenuBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMENUBUILDER_IID)

  /* void openContainer (in DOMString aLabel); */
  NS_IMETHOD OpenContainer(const nsAString & aLabel) = 0;

  /* void addItemFor (in nsIDOMHTMLMenuItemElement aElement, in boolean aCanLoadIcon); */
  NS_IMETHOD AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon) = 0;

  /* void addSeparator (); */
  NS_IMETHOD AddSeparator(void) = 0;

  /* void undoAddSeparator (); */
  NS_IMETHOD UndoAddSeparator(void) = 0;

  /* void closeContainer (); */
  NS_IMETHOD CloseContainer(void) = 0;

  /* AString toJSONString (); */
  NS_IMETHOD ToJSONString(nsAString & _retval) = 0;

  /* void click (in DOMString aGeneratedItemId); */
  NS_IMETHOD Click(const nsAString & aGeneratedItemId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMenuBuilder, NS_IMENUBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMENUBUILDER \
  NS_IMETHOD OpenContainer(const nsAString & aLabel) override; \
  NS_IMETHOD AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon) override; \
  NS_IMETHOD AddSeparator(void) override; \
  NS_IMETHOD UndoAddSeparator(void) override; \
  NS_IMETHOD CloseContainer(void) override; \
  NS_IMETHOD ToJSONString(nsAString & _retval) override; \
  NS_IMETHOD Click(const nsAString & aGeneratedItemId) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMENUBUILDER(_to) \
  NS_IMETHOD OpenContainer(const nsAString & aLabel) override { return _to OpenContainer(aLabel); } \
  NS_IMETHOD AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon) override { return _to AddItemFor(aElement, aCanLoadIcon); } \
  NS_IMETHOD AddSeparator(void) override { return _to AddSeparator(); } \
  NS_IMETHOD UndoAddSeparator(void) override { return _to UndoAddSeparator(); } \
  NS_IMETHOD CloseContainer(void) override { return _to CloseContainer(); } \
  NS_IMETHOD ToJSONString(nsAString & _retval) override { return _to ToJSONString(_retval); } \
  NS_IMETHOD Click(const nsAString & aGeneratedItemId) override { return _to Click(aGeneratedItemId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMENUBUILDER(_to) \
  NS_IMETHOD OpenContainer(const nsAString & aLabel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenContainer(aLabel); } \
  NS_IMETHOD AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddItemFor(aElement, aCanLoadIcon); } \
  NS_IMETHOD AddSeparator(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSeparator(); } \
  NS_IMETHOD UndoAddSeparator(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UndoAddSeparator(); } \
  NS_IMETHOD CloseContainer(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseContainer(); } \
  NS_IMETHOD ToJSONString(nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ToJSONString(_retval); } \
  NS_IMETHOD Click(const nsAString & aGeneratedItemId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Click(aGeneratedItemId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMenuBuilder : public nsIMenuBuilder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMENUBUILDER

  nsMenuBuilder();

private:
  ~nsMenuBuilder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsMenuBuilder, nsIMenuBuilder)

nsMenuBuilder::nsMenuBuilder()
{
  /* member initializers and constructor code */
}

nsMenuBuilder::~nsMenuBuilder()
{
  /* destructor code */
}

/* void openContainer (in DOMString aLabel); */
NS_IMETHODIMP nsMenuBuilder::OpenContainer(const nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addItemFor (in nsIDOMHTMLMenuItemElement aElement, in boolean aCanLoadIcon); */
NS_IMETHODIMP nsMenuBuilder::AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSeparator (); */
NS_IMETHODIMP nsMenuBuilder::AddSeparator()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undoAddSeparator (); */
NS_IMETHODIMP nsMenuBuilder::UndoAddSeparator()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeContainer (); */
NS_IMETHODIMP nsMenuBuilder::CloseContainer()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString toJSONString (); */
NS_IMETHODIMP nsMenuBuilder::ToJSONString(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void click (in DOMString aGeneratedItemId); */
NS_IMETHODIMP nsMenuBuilder::Click(const nsAString & aGeneratedItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMenuBuilder_h__ */
