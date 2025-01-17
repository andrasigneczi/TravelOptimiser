/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPluginInputStream.idl
 */

#ifndef __gen_nsIPluginInputStream_h__
#define __gen_nsIPluginInputStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPluginInputStream */
#define NS_IPLUGININPUTSTREAM_IID_STR "af160530-542a-11d2-8164-006008119d7a"

#define NS_IPLUGININPUTSTREAM_IID \
  {0xaf160530, 0x542a, 0x11d2, \
    { 0x81, 0x64, 0x00, 0x60, 0x08, 0x11, 0x9d, 0x7a }}

class NS_NO_VTABLE nsIPluginInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGININPUTSTREAM_IID)

  /* void getLastModified (out unsigned long aResult); */
  NS_IMETHOD GetLastModified(uint32_t *aResult) = 0;

  /* void requestRead (out NPByteRange aRangeList); */
  NS_IMETHOD RequestRead(NPByteRange *aRangeList) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginInputStream, NS_IPLUGININPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGININPUTSTREAM \
  NS_IMETHOD GetLastModified(uint32_t *aResult) override; \
  NS_IMETHOD RequestRead(NPByteRange *aRangeList) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGININPUTSTREAM(_to) \
  NS_IMETHOD GetLastModified(uint32_t *aResult) override { return _to GetLastModified(aResult); } \
  NS_IMETHOD RequestRead(NPByteRange *aRangeList) override { return _to RequestRead(aRangeList); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGININPUTSTREAM(_to) \
  NS_IMETHOD GetLastModified(uint32_t *aResult) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aResult); } \
  NS_IMETHOD RequestRead(NPByteRange *aRangeList) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestRead(aRangeList); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginInputStream : public nsIPluginInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGININPUTSTREAM

  nsPluginInputStream();

private:
  ~nsPluginInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPluginInputStream, nsIPluginInputStream)

nsPluginInputStream::nsPluginInputStream()
{
  /* member initializers and constructor code */
}

nsPluginInputStream::~nsPluginInputStream()
{
  /* destructor code */
}

/* void getLastModified (out unsigned long aResult); */
NS_IMETHODIMP nsPluginInputStream::GetLastModified(uint32_t *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestRead (out NPByteRange aRangeList); */
NS_IMETHODIMP nsPluginInputStream::RequestRead(NPByteRange *aRangeList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginInputStream_h__ */
