/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISAXMutableAttributes.idl
 */

#ifndef __gen_nsISAXMutableAttributes_h__
#define __gen_nsISAXMutableAttributes_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISAXAttributes_h__
#include "nsISAXAttributes.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXMutableAttributes */
#define NS_ISAXMUTABLEATTRIBUTES_IID_STR "8b1de83d-cebb-49fa-8245-c0fe319eb7b6"

#define NS_ISAXMUTABLEATTRIBUTES_IID \
  {0x8b1de83d, 0xcebb, 0x49fa, \
    { 0x82, 0x45, 0xc0, 0xfe, 0x31, 0x9e, 0xb7, 0xb6 }}

class NS_NO_VTABLE nsISAXMutableAttributes : public nsISAXAttributes {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXMUTABLEATTRIBUTES_IID)

  /* void addAttribute (in AString uri, in AString localName, in AString qName, in AString type, in AString value); */
  NS_IMETHOD AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) = 0;

  /* void clear (); */
  NS_IMETHOD Clear(void) = 0;

  /* void removeAttribute (in unsigned long index); */
  NS_IMETHOD RemoveAttribute(uint32_t index) = 0;

  /* void setAttributes (in nsISAXAttributes attributes); */
  NS_IMETHOD SetAttributes(nsISAXAttributes *attributes) = 0;

  /* void setAttribute (in unsigned long index, in AString uri, in AString localName, in AString qName, in AString type, in AString value); */
  NS_IMETHOD SetAttribute(uint32_t index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) = 0;

  /* void setLocalName (in unsigned long index, in AString localName); */
  NS_IMETHOD SetLocalName(uint32_t index, const nsAString & localName) = 0;

  /* void setQName (in unsigned long index, in AString qName); */
  NS_IMETHOD SetQName(uint32_t index, const nsAString & qName) = 0;

  /* void setType (in unsigned long index, in AString type); */
  NS_IMETHOD SetType(uint32_t index, const nsAString & type) = 0;

  /* void setURI (in unsigned long index, in AString uri); */
  NS_IMETHOD SetURI(uint32_t index, const nsAString & uri) = 0;

  /* void setValue (in unsigned long index, in AString value); */
  NS_IMETHOD SetValue(uint32_t index, const nsAString & value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXMutableAttributes, NS_ISAXMUTABLEATTRIBUTES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXMUTABLEATTRIBUTES \
  NS_IMETHOD AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) override; \
  NS_IMETHOD Clear(void) override; \
  NS_IMETHOD RemoveAttribute(uint32_t index) override; \
  NS_IMETHOD SetAttributes(nsISAXAttributes *attributes) override; \
  NS_IMETHOD SetAttribute(uint32_t index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) override; \
  NS_IMETHOD SetLocalName(uint32_t index, const nsAString & localName) override; \
  NS_IMETHOD SetQName(uint32_t index, const nsAString & qName) override; \
  NS_IMETHOD SetType(uint32_t index, const nsAString & type) override; \
  NS_IMETHOD SetURI(uint32_t index, const nsAString & uri) override; \
  NS_IMETHOD SetValue(uint32_t index, const nsAString & value) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXMUTABLEATTRIBUTES(_to) \
  NS_IMETHOD AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) override { return _to AddAttribute(uri, localName, qName, type, value); } \
  NS_IMETHOD Clear(void) override { return _to Clear(); } \
  NS_IMETHOD RemoveAttribute(uint32_t index) override { return _to RemoveAttribute(index); } \
  NS_IMETHOD SetAttributes(nsISAXAttributes *attributes) override { return _to SetAttributes(attributes); } \
  NS_IMETHOD SetAttribute(uint32_t index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) override { return _to SetAttribute(index, uri, localName, qName, type, value); } \
  NS_IMETHOD SetLocalName(uint32_t index, const nsAString & localName) override { return _to SetLocalName(index, localName); } \
  NS_IMETHOD SetQName(uint32_t index, const nsAString & qName) override { return _to SetQName(index, qName); } \
  NS_IMETHOD SetType(uint32_t index, const nsAString & type) override { return _to SetType(index, type); } \
  NS_IMETHOD SetURI(uint32_t index, const nsAString & uri) override { return _to SetURI(index, uri); } \
  NS_IMETHOD SetValue(uint32_t index, const nsAString & value) override { return _to SetValue(index, value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXMUTABLEATTRIBUTES(_to) \
  NS_IMETHOD AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddAttribute(uri, localName, qName, type, value); } \
  NS_IMETHOD Clear(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(); } \
  NS_IMETHOD RemoveAttribute(uint32_t index) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttribute(index); } \
  NS_IMETHOD SetAttributes(nsISAXAttributes *attributes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributes(attributes); } \
  NS_IMETHOD SetAttribute(uint32_t index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttribute(index, uri, localName, qName, type, value); } \
  NS_IMETHOD SetLocalName(uint32_t index, const nsAString & localName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocalName(index, localName); } \
  NS_IMETHOD SetQName(uint32_t index, const nsAString & qName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetQName(index, qName); } \
  NS_IMETHOD SetType(uint32_t index, const nsAString & type) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(index, type); } \
  NS_IMETHOD SetURI(uint32_t index, const nsAString & uri) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetURI(index, uri); } \
  NS_IMETHOD SetValue(uint32_t index, const nsAString & value) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(index, value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXMutableAttributes : public nsISAXMutableAttributes
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXMUTABLEATTRIBUTES

  nsSAXMutableAttributes();

private:
  ~nsSAXMutableAttributes();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSAXMutableAttributes, nsISAXMutableAttributes)

nsSAXMutableAttributes::nsSAXMutableAttributes()
{
  /* member initializers and constructor code */
}

nsSAXMutableAttributes::~nsSAXMutableAttributes()
{
  /* destructor code */
}

/* void addAttribute (in AString uri, in AString localName, in AString qName, in AString type, in AString value); */
NS_IMETHODIMP nsSAXMutableAttributes::AddAttribute(const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clear (); */
NS_IMETHODIMP nsSAXMutableAttributes::Clear()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttribute (in unsigned long index); */
NS_IMETHODIMP nsSAXMutableAttributes::RemoveAttribute(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttributes (in nsISAXAttributes attributes); */
NS_IMETHODIMP nsSAXMutableAttributes::SetAttributes(nsISAXAttributes *attributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttribute (in unsigned long index, in AString uri, in AString localName, in AString qName, in AString type, in AString value); */
NS_IMETHODIMP nsSAXMutableAttributes::SetAttribute(uint32_t index, const nsAString & uri, const nsAString & localName, const nsAString & qName, const nsAString & type, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLocalName (in unsigned long index, in AString localName); */
NS_IMETHODIMP nsSAXMutableAttributes::SetLocalName(uint32_t index, const nsAString & localName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setQName (in unsigned long index, in AString qName); */
NS_IMETHODIMP nsSAXMutableAttributes::SetQName(uint32_t index, const nsAString & qName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setType (in unsigned long index, in AString type); */
NS_IMETHODIMP nsSAXMutableAttributes::SetType(uint32_t index, const nsAString & type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setURI (in unsigned long index, in AString uri); */
NS_IMETHODIMP nsSAXMutableAttributes::SetURI(uint32_t index, const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setValue (in unsigned long index, in AString value); */
NS_IMETHODIMP nsSAXMutableAttributes::SetValue(uint32_t index, const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXMutableAttributes_h__ */
