/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMSerializer.idl
 */

#ifndef __gen_nsIDOMSerializer_h__
#define __gen_nsIDOMSerializer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStream; /* forward declaration */

class nsIDOMNode; /* forward declaration */


/* starting interface:    nsIDOMSerializer */
#define NS_IDOMSERIALIZER_IID_STR "9fd4ba15-e67c-4c98-b52c-7715f62c9196"

#define NS_IDOMSERIALIZER_IID \
  {0x9fd4ba15, 0xe67c, 0x4c98, \
    { 0xb5, 0x2c, 0x77, 0x15, 0xf6, 0x2c, 0x91, 0x96 }}

class NS_NO_VTABLE nsIDOMSerializer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSERIALIZER_IID)

  /* AString serializeToString (in nsIDOMNode root); */
  NS_IMETHOD SerializeToString(nsIDOMNode *root, nsAString & _retval) = 0;

  /* void serializeToStream (in nsIDOMNode root, in nsIOutputStream stream, in AUTF8String charset); */
  NS_IMETHOD SerializeToStream(nsIDOMNode *root, nsIOutputStream *stream, const nsACString & charset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSerializer, NS_IDOMSERIALIZER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSERIALIZER \
  NS_IMETHOD SerializeToString(nsIDOMNode *root, nsAString & _retval) override; \
  NS_IMETHOD SerializeToStream(nsIDOMNode *root, nsIOutputStream *stream, const nsACString & charset) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSERIALIZER(_to) \
  NS_IMETHOD SerializeToString(nsIDOMNode *root, nsAString & _retval) override { return _to SerializeToString(root, _retval); } \
  NS_IMETHOD SerializeToStream(nsIDOMNode *root, nsIOutputStream *stream, const nsACString & charset) override { return _to SerializeToStream(root, stream, charset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSERIALIZER(_to) \
  NS_IMETHOD SerializeToString(nsIDOMNode *root, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SerializeToString(root, _retval); } \
  NS_IMETHOD SerializeToStream(nsIDOMNode *root, nsIOutputStream *stream, const nsACString & charset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SerializeToStream(root, stream, charset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSerializer : public nsIDOMSerializer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSERIALIZER

  nsDOMSerializer();

private:
  ~nsDOMSerializer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMSerializer, nsIDOMSerializer)

nsDOMSerializer::nsDOMSerializer()
{
  /* member initializers and constructor code */
}

nsDOMSerializer::~nsDOMSerializer()
{
  /* destructor code */
}

/* AString serializeToString (in nsIDOMNode root); */
NS_IMETHODIMP nsDOMSerializer::SerializeToString(nsIDOMNode *root, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void serializeToStream (in nsIDOMNode root, in nsIOutputStream stream, in AUTF8String charset); */
NS_IMETHODIMP nsDOMSerializer::SerializeToStream(nsIDOMNode *root, nsIOutputStream *stream, const nsACString & charset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_XMLSERIALIZER_CID                        \
 { /* a6cf9124-15b3-11d2-932e-00805f8add32 */       \
   0xa6cf9124, 0x15b3, 0x11d2,                      \
  {0x93, 0x2e, 0x00, 0x80, 0x5f, 0x8a, 0xdd, 0x32} }
#define NS_XMLSERIALIZER_CONTRACTID \
"@mozilla.org/xmlextras/xmlserializer;1"

#endif /* __gen_nsIDOMSerializer_h__ */
