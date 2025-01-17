/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIClipboardOwner.idl
 */

#ifndef __gen_nsIClipboardOwner_h__
#define __gen_nsIClipboardOwner_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsITransferable_h__
#include "nsITransferable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIClipboardOwner */
#define NS_ICLIPBOARDOWNER_IID_STR "5a31c7a1-e122-11d2-9a57-000064657374"

#define NS_ICLIPBOARDOWNER_IID \
  {0x5a31c7a1, 0xe122, 0x11d2, \
    { 0x9a, 0x57, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

class NS_NO_VTABLE nsIClipboardOwner : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIPBOARDOWNER_IID)

  /* void LosingOwnership (in nsITransferable aTransferable); */
  NS_IMETHOD LosingOwnership(nsITransferable *aTransferable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClipboardOwner, NS_ICLIPBOARDOWNER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIPBOARDOWNER \
  NS_IMETHOD LosingOwnership(nsITransferable *aTransferable) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIPBOARDOWNER(_to) \
  NS_IMETHOD LosingOwnership(nsITransferable *aTransferable) override { return _to LosingOwnership(aTransferable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIPBOARDOWNER(_to) \
  NS_IMETHOD LosingOwnership(nsITransferable *aTransferable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LosingOwnership(aTransferable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClipboardOwner : public nsIClipboardOwner
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIPBOARDOWNER

  nsClipboardOwner();

private:
  ~nsClipboardOwner();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsClipboardOwner, nsIClipboardOwner)

nsClipboardOwner::nsClipboardOwner()
{
  /* member initializers and constructor code */
}

nsClipboardOwner::~nsClipboardOwner()
{
  /* destructor code */
}

/* void LosingOwnership (in nsITransferable aTransferable); */
NS_IMETHODIMP nsClipboardOwner::LosingOwnership(nsITransferable *aTransferable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif



#endif /* __gen_nsIClipboardOwner_h__ */
