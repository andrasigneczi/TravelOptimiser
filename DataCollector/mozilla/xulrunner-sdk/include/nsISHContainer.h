/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISHContainer.idl
 */

#ifndef __gen_nsISHContainer_h__
#define __gen_nsISHContainer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISHEntry; /* forward declaration */


/* starting interface:    nsISHContainer */
#define NS_ISHCONTAINER_IID_STR "67dd0357-8372-4122-bff6-217435e8b7e4"

#define NS_ISHCONTAINER_IID \
  {0x67dd0357, 0x8372, 0x4122, \
    { 0xbf, 0xf6, 0x21, 0x74, 0x35, 0xe8, 0xb7, 0xe4 }}

class NS_NO_VTABLE nsISHContainer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHCONTAINER_IID)

  /* readonly attribute long childCount; */
  NS_IMETHOD GetChildCount(int32_t *aChildCount) = 0;

  /* void AddChild (in nsISHEntry child, in long offset); */
  NS_IMETHOD AddChild(nsISHEntry *child, int32_t offset) = 0;

  /* void RemoveChild (in nsISHEntry child); */
  NS_IMETHOD RemoveChild(nsISHEntry *child) = 0;

  /* nsISHEntry GetChildAt (in long index); */
  NS_IMETHOD GetChildAt(int32_t index, nsISHEntry * *_retval) = 0;

  /* void ReplaceChild (in nsISHEntry aNewChild); */
  NS_IMETHOD ReplaceChild(nsISHEntry *aNewChild) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHContainer, NS_ISHCONTAINER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHCONTAINER \
  NS_IMETHOD GetChildCount(int32_t *aChildCount) override; \
  NS_IMETHOD AddChild(nsISHEntry *child, int32_t offset) override; \
  NS_IMETHOD RemoveChild(nsISHEntry *child) override; \
  NS_IMETHOD GetChildAt(int32_t index, nsISHEntry * *_retval) override; \
  NS_IMETHOD ReplaceChild(nsISHEntry *aNewChild) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHCONTAINER(_to) \
  NS_IMETHOD GetChildCount(int32_t *aChildCount) override { return _to GetChildCount(aChildCount); } \
  NS_IMETHOD AddChild(nsISHEntry *child, int32_t offset) override { return _to AddChild(child, offset); } \
  NS_IMETHOD RemoveChild(nsISHEntry *child) override { return _to RemoveChild(child); } \
  NS_IMETHOD GetChildAt(int32_t index, nsISHEntry * *_retval) override { return _to GetChildAt(index, _retval); } \
  NS_IMETHOD ReplaceChild(nsISHEntry *aNewChild) override { return _to ReplaceChild(aNewChild); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHCONTAINER(_to) \
  NS_IMETHOD GetChildCount(int32_t *aChildCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_IMETHOD AddChild(nsISHEntry *child, int32_t offset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddChild(child, offset); } \
  NS_IMETHOD RemoveChild(nsISHEntry *child) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveChild(child); } \
  NS_IMETHOD GetChildAt(int32_t index, nsISHEntry * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAt(index, _retval); } \
  NS_IMETHOD ReplaceChild(nsISHEntry *aNewChild) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceChild(aNewChild); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHContainer : public nsISHContainer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHCONTAINER

  nsSHContainer();

private:
  ~nsSHContainer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSHContainer, nsISHContainer)

nsSHContainer::nsSHContainer()
{
  /* member initializers and constructor code */
}

nsSHContainer::~nsSHContainer()
{
  /* destructor code */
}

/* readonly attribute long childCount; */
NS_IMETHODIMP nsSHContainer::GetChildCount(int32_t *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddChild (in nsISHEntry child, in long offset); */
NS_IMETHODIMP nsSHContainer::AddChild(nsISHEntry *child, int32_t offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveChild (in nsISHEntry child); */
NS_IMETHODIMP nsSHContainer::RemoveChild(nsISHEntry *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISHEntry GetChildAt (in long index); */
NS_IMETHODIMP nsSHContainer::GetChildAt(int32_t index, nsISHEntry * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ReplaceChild (in nsISHEntry aNewChild); */
NS_IMETHODIMP nsSHContainer::ReplaceChild(nsISHEntry *aNewChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISHContainer_h__ */
