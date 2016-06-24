/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContentPolicyBase.idl
 */

#ifndef __gen_nsIContentPolicyBase_h__
#define __gen_nsIContentPolicyBase_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIPrincipal; /* forward declaration */

typedef uint32_t  nsContentPolicyType;


/* starting interface:    nsIContentPolicyBase */
#define NS_ICONTENTPOLICYBASE_IID_STR "11b8d725-7c2b-429e-b51f-8b5b542d5009"

#define NS_ICONTENTPOLICYBASE_IID \
  {0x11b8d725, 0x7c2b, 0x429e, \
    { 0xb5, 0x1f, 0x8b, 0x5b, 0x54, 0x2d, 0x50, 0x09 }}

class NS_NO_VTABLE nsIContentPolicyBase : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPOLICYBASE_IID)

  enum {
    TYPE_INVALID = 0U,
    TYPE_OTHER = 1U,
    TYPE_SCRIPT = 2U,
    TYPE_IMAGE = 3U,
    TYPE_STYLESHEET = 4U,
    TYPE_OBJECT = 5U,
    TYPE_DOCUMENT = 6U,
    TYPE_SUBDOCUMENT = 7U,
    TYPE_REFRESH = 8U,
    TYPE_XBL = 9U,
    TYPE_PING = 10U,
    TYPE_XMLHTTPREQUEST = 11U,
    TYPE_DATAREQUEST = 11U,
    TYPE_OBJECT_SUBREQUEST = 12U,
    TYPE_DTD = 13U,
    TYPE_FONT = 14U,
    TYPE_MEDIA = 15U,
    TYPE_WEBSOCKET = 16U,
    TYPE_CSP_REPORT = 17U,
    TYPE_XSLT = 18U,
    TYPE_BEACON = 19U,
    TYPE_FETCH = 20U,
    TYPE_IMAGESET = 21U,
    TYPE_WEB_MANIFEST = 22U,
    TYPE_INTERNAL_SCRIPT = 23U,
    TYPE_INTERNAL_WORKER = 24U,
    TYPE_INTERNAL_SHARED_WORKER = 25U,
    TYPE_INTERNAL_EMBED = 26U,
    TYPE_INTERNAL_OBJECT = 27U,
    TYPE_INTERNAL_FRAME = 28U,
    TYPE_INTERNAL_IFRAME = 29U,
    TYPE_INTERNAL_AUDIO = 30U,
    TYPE_INTERNAL_VIDEO = 31U,
    TYPE_INTERNAL_TRACK = 32U,
    REJECT_REQUEST = -1,
    REJECT_TYPE = -2,
    REJECT_SERVER = -3,
    REJECT_OTHER = -4,
    ACCEPT = 1
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPolicyBase, NS_ICONTENTPOLICYBASE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPOLICYBASE \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPOLICYBASE(_to) \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPOLICYBASE(_to) \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPolicyBase : public nsIContentPolicyBase
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPOLICYBASE

  nsContentPolicyBase();

private:
  ~nsContentPolicyBase();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentPolicyBase, nsIContentPolicyBase)

nsContentPolicyBase::nsContentPolicyBase()
{
  /* member initializers and constructor code */
}

nsContentPolicyBase::~nsContentPolicyBase()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentPolicyBase_h__ */
