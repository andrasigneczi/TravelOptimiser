/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDeletedMessageInfo.idl
 */

#ifndef __gen_nsIDeletedMessageInfo_h__
#define __gen_nsIDeletedMessageInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDeletedMessageInfo */
#define NS_IDELETEDMESSAGEINFO_IID_STR "174139d8-00e1-11e4-818a-f38357d90920"

#define NS_IDELETEDMESSAGEINFO_IID \
  {0x174139d8, 0x00e1, 0x11e4, \
    { 0x81, 0x8a, 0xf3, 0x83, 0x57, 0xd9, 0x09, 0x20 }}

class NS_NO_VTABLE nsIDeletedMessageInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDELETEDMESSAGEINFO_IID)

  /* readonly attribute nsIVariant deletedMessageIds; */
  NS_IMETHOD GetDeletedMessageIds(nsIVariant * *aDeletedMessageIds) = 0;

  /* readonly attribute nsIVariant deletedThreadIds; */
  NS_IMETHOD GetDeletedThreadIds(nsIVariant * *aDeletedThreadIds) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDeletedMessageInfo, NS_IDELETEDMESSAGEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDELETEDMESSAGEINFO \
  NS_IMETHOD GetDeletedMessageIds(nsIVariant * *aDeletedMessageIds) override; \
  NS_IMETHOD GetDeletedThreadIds(nsIVariant * *aDeletedThreadIds) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDELETEDMESSAGEINFO(_to) \
  NS_IMETHOD GetDeletedMessageIds(nsIVariant * *aDeletedMessageIds) override { return _to GetDeletedMessageIds(aDeletedMessageIds); } \
  NS_IMETHOD GetDeletedThreadIds(nsIVariant * *aDeletedThreadIds) override { return _to GetDeletedThreadIds(aDeletedThreadIds); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDELETEDMESSAGEINFO(_to) \
  NS_IMETHOD GetDeletedMessageIds(nsIVariant * *aDeletedMessageIds) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeletedMessageIds(aDeletedMessageIds); } \
  NS_IMETHOD GetDeletedThreadIds(nsIVariant * *aDeletedThreadIds) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeletedThreadIds(aDeletedThreadIds); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDeletedMessageInfo : public nsIDeletedMessageInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDELETEDMESSAGEINFO

  nsDeletedMessageInfo();

private:
  ~nsDeletedMessageInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDeletedMessageInfo, nsIDeletedMessageInfo)

nsDeletedMessageInfo::nsDeletedMessageInfo()
{
  /* member initializers and constructor code */
}

nsDeletedMessageInfo::~nsDeletedMessageInfo()
{
  /* destructor code */
}

/* readonly attribute nsIVariant deletedMessageIds; */
NS_IMETHODIMP nsDeletedMessageInfo::GetDeletedMessageIds(nsIVariant * *aDeletedMessageIds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant deletedThreadIds; */
NS_IMETHODIMP nsDeletedMessageInfo::GetDeletedThreadIds(nsIVariant * *aDeletedThreadIds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDeletedMessageInfo_h__ */
