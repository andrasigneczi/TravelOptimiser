/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleObjectAttributeChangedEvent.idl
 */

#ifndef __gen_nsIAccessibleObjectAttributeChangedEvent_h__
#define __gen_nsIAccessibleObjectAttributeChangedEvent_h__


#ifndef __gen_nsIAccessibleEvent_h__
#include "nsIAccessibleEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom; /* forward declaration */


/* starting interface:    nsIAccessibleObjectAttributeChangedEvent */
#define NS_IACCESSIBLEOBJECTATTRIBUTECHANGEDEVENT_IID_STR "4ca96609-23c8-4771-86e7-77c8b651ca24"

#define NS_IACCESSIBLEOBJECTATTRIBUTECHANGEDEVENT_IID \
  {0x4ca96609, 0x23c8, 0x4771, \
    { 0x86, 0xe7, 0x77, 0xc8, 0xb6, 0x51, 0xca, 0x24 }}

class NS_NO_VTABLE nsIAccessibleObjectAttributeChangedEvent : public nsIAccessibleEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLEOBJECTATTRIBUTECHANGEDEVENT_IID)

  /* readonly attribute nsIAtom changedAttribute; */
  NS_IMETHOD GetChangedAttribute(nsIAtom * *aChangedAttribute) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleObjectAttributeChangedEvent, NS_IACCESSIBLEOBJECTATTRIBUTECHANGEDEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLEOBJECTATTRIBUTECHANGEDEVENT \
  NS_IMETHOD GetChangedAttribute(nsIAtom * *aChangedAttribute) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLEOBJECTATTRIBUTECHANGEDEVENT(_to) \
  NS_IMETHOD GetChangedAttribute(nsIAtom * *aChangedAttribute) override { return _to GetChangedAttribute(aChangedAttribute); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLEOBJECTATTRIBUTECHANGEDEVENT(_to) \
  NS_IMETHOD GetChangedAttribute(nsIAtom * *aChangedAttribute) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChangedAttribute(aChangedAttribute); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleObjectAttributeChangedEvent : public nsIAccessibleObjectAttributeChangedEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLEOBJECTATTRIBUTECHANGEDEVENT

  nsAccessibleObjectAttributeChangedEvent();

private:
  ~nsAccessibleObjectAttributeChangedEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAccessibleObjectAttributeChangedEvent, nsIAccessibleObjectAttributeChangedEvent)

nsAccessibleObjectAttributeChangedEvent::nsAccessibleObjectAttributeChangedEvent()
{
  /* member initializers and constructor code */
}

nsAccessibleObjectAttributeChangedEvent::~nsAccessibleObjectAttributeChangedEvent()
{
  /* destructor code */
}

/* readonly attribute nsIAtom changedAttribute; */
NS_IMETHODIMP nsAccessibleObjectAttributeChangedEvent::GetChangedAttribute(nsIAtom * *aChangedAttribute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleObjectAttributeChangedEvent_h__ */
