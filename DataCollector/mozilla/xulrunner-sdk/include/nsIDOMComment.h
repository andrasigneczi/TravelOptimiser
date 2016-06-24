/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMComment.idl
 */

#ifndef __gen_nsIDOMComment_h__
#define __gen_nsIDOMComment_h__


#ifndef __gen_nsIDOMCharacterData_h__
#include "nsIDOMCharacterData.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMComment */
#define NS_IDOMCOMMENT_IID_STR "e7866ff8-b7fc-494f-87c0-fb017d8a4d30"

#define NS_IDOMCOMMENT_IID \
  {0xe7866ff8, 0xb7fc, 0x494f, \
    { 0x87, 0xc0, 0xfb, 0x01, 0x7d, 0x8a, 0x4d, 0x30 }}

class NS_NO_VTABLE nsIDOMComment : public nsIDOMCharacterData {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCOMMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMComment, NS_IDOMCOMMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCOMMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCOMMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCOMMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMComment : public nsIDOMComment
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCOMMENT

  nsDOMComment();

private:
  ~nsDOMComment();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMComment, nsIDOMComment)

nsDOMComment::nsDOMComment()
{
  /* member initializers and constructor code */
}

nsDOMComment::~nsDOMComment()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMComment_h__ */
