/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICloneableInputStream.idl
 */

#ifndef __gen_nsICloneableInputStream_h__
#define __gen_nsICloneableInputStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICloneableInputStream */
#define NS_ICLONEABLEINPUTSTREAM_IID_STR "8149be1f-44d3-4f14-8b65-a57a5fbbeb97"

#define NS_ICLONEABLEINPUTSTREAM_IID \
  {0x8149be1f, 0x44d3, 0x4f14, \
    { 0x8b, 0x65, 0xa5, 0x7a, 0x5f, 0xbb, 0xeb, 0x97 }}

class NS_NO_VTABLE nsICloneableInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLONEABLEINPUTSTREAM_IID)

  /* [infallible] readonly attribute boolean cloneable; */
  NS_IMETHOD GetCloneable(bool *aCloneable) = 0;
  inline bool GetCloneable()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetCloneable(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* nsIInputStream clone (); */
  NS_IMETHOD Clone(nsIInputStream * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICloneableInputStream, NS_ICLONEABLEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLONEABLEINPUTSTREAM \
  using nsICloneableInputStream::GetCloneable; \
  NS_IMETHOD GetCloneable(bool *aCloneable) override; \
  NS_IMETHOD Clone(nsIInputStream * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLONEABLEINPUTSTREAM(_to) \
  using nsICloneableInputStream::GetCloneable; \
  NS_IMETHOD GetCloneable(bool *aCloneable) override { return _to GetCloneable(aCloneable); } \
  NS_IMETHOD Clone(nsIInputStream * *_retval) override { return _to Clone(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLONEABLEINPUTSTREAM(_to) \
  NS_IMETHOD GetCloneable(bool *aCloneable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCloneable(aCloneable); } \
  NS_IMETHOD Clone(nsIInputStream * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCloneableInputStream : public nsICloneableInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLONEABLEINPUTSTREAM

  nsCloneableInputStream();

private:
  ~nsCloneableInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCloneableInputStream, nsICloneableInputStream)

nsCloneableInputStream::nsCloneableInputStream()
{
  /* member initializers and constructor code */
}

nsCloneableInputStream::~nsCloneableInputStream()
{
  /* destructor code */
}

/* [infallible] readonly attribute boolean cloneable; */
NS_IMETHODIMP nsCloneableInputStream::GetCloneable(bool *aCloneable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream clone (); */
NS_IMETHODIMP nsCloneableInputStream::Clone(nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICloneableInputStream_h__ */
