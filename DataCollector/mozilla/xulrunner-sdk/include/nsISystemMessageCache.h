/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISystemMessageCache.idl
 */

#ifndef __gen_nsISystemMessageCache_h__
#define __gen_nsISystemMessageCache_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISystemMessageCache */
#define NS_ISYSTEMMESSAGECACHE_IID_STR "e888447c-6d4d-4045-92bd-1a5985404375"

#define NS_ISYSTEMMESSAGECACHE_IID \
  {0xe888447c, 0x6d4d, 0x4045, \
    { 0x92, 0xbd, 0x1a, 0x59, 0x85, 0x40, 0x43, 0x75 }}

class NS_NO_VTABLE nsISystemMessageCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMMESSAGECACHE_IID)

  /* boolean hasPendingMessage (in DOMString type, in DOMString pageURL, in DOMString manifestURL); */
  NS_IMETHOD HasPendingMessage(const nsAString & type, const nsAString & pageURL, const nsAString & manifestURL, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemMessageCache, NS_ISYSTEMMESSAGECACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMMESSAGECACHE \
  NS_IMETHOD HasPendingMessage(const nsAString & type, const nsAString & pageURL, const nsAString & manifestURL, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMMESSAGECACHE(_to) \
  NS_IMETHOD HasPendingMessage(const nsAString & type, const nsAString & pageURL, const nsAString & manifestURL, bool *_retval) override { return _to HasPendingMessage(type, pageURL, manifestURL, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMMESSAGECACHE(_to) \
  NS_IMETHOD HasPendingMessage(const nsAString & type, const nsAString & pageURL, const nsAString & manifestURL, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPendingMessage(type, pageURL, manifestURL, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemMessageCache : public nsISystemMessageCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMMESSAGECACHE

  nsSystemMessageCache();

private:
  ~nsSystemMessageCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSystemMessageCache, nsISystemMessageCache)

nsSystemMessageCache::nsSystemMessageCache()
{
  /* member initializers and constructor code */
}

nsSystemMessageCache::~nsSystemMessageCache()
{
  /* destructor code */
}

/* boolean hasPendingMessage (in DOMString type, in DOMString pageURL, in DOMString manifestURL); */
NS_IMETHODIMP nsSystemMessageCache::HasPendingMessage(const nsAString & type, const nsAString & pageURL, const nsAString & manifestURL, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISystemMessageCache_h__ */
