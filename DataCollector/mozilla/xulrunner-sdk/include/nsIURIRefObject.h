/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIURIRefObject.idl
 */

#ifndef __gen_nsIURIRefObject_h__
#define __gen_nsIURIRefObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    nsIURIRefObject */
#define NS_IURIREFOBJECT_IID_STR "2226927e-1dd2-11b2-b57f-faab47288563"

#define NS_IURIREFOBJECT_IID \
  {0x2226927e, 0x1dd2, 0x11b2, \
    { 0xb5, 0x7f, 0xfa, 0xab, 0x47, 0x28, 0x85, 0x63 }}

class NS_NO_VTABLE nsIURIRefObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURIREFOBJECT_IID)

  /* attribute nsIDOMNode node; */
  NS_IMETHOD GetNode(nsIDOMNode * *aNode) = 0;
  NS_IMETHOD SetNode(nsIDOMNode *aNode) = 0;

  /* void Reset (); */
  NS_IMETHOD Reset(void) = 0;

  /* DOMString GetNextURI (); */
  NS_IMETHOD GetNextURI(nsAString & _retval) = 0;

  /* void RewriteAllURIs (in DOMString aOldPat, in DOMString aNewPat, in boolean aMakeRel); */
  NS_IMETHOD RewriteAllURIs(const nsAString & aOldPat, const nsAString & aNewPat, bool aMakeRel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIRefObject, NS_IURIREFOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURIREFOBJECT \
  NS_IMETHOD GetNode(nsIDOMNode * *aNode) override; \
  NS_IMETHOD SetNode(nsIDOMNode *aNode) override; \
  NS_IMETHOD Reset(void) override; \
  NS_IMETHOD GetNextURI(nsAString & _retval) override; \
  NS_IMETHOD RewriteAllURIs(const nsAString & aOldPat, const nsAString & aNewPat, bool aMakeRel) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURIREFOBJECT(_to) \
  NS_IMETHOD GetNode(nsIDOMNode * *aNode) override { return _to GetNode(aNode); } \
  NS_IMETHOD SetNode(nsIDOMNode *aNode) override { return _to SetNode(aNode); } \
  NS_IMETHOD Reset(void) override { return _to Reset(); } \
  NS_IMETHOD GetNextURI(nsAString & _retval) override { return _to GetNextURI(_retval); } \
  NS_IMETHOD RewriteAllURIs(const nsAString & aOldPat, const nsAString & aNewPat, bool aMakeRel) override { return _to RewriteAllURIs(aOldPat, aNewPat, aMakeRel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURIREFOBJECT(_to) \
  NS_IMETHOD GetNode(nsIDOMNode * *aNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNode(aNode); } \
  NS_IMETHOD SetNode(nsIDOMNode *aNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNode(aNode); } \
  NS_IMETHOD Reset(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_IMETHOD GetNextURI(nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextURI(_retval); } \
  NS_IMETHOD RewriteAllURIs(const nsAString & aOldPat, const nsAString & aNewPat, bool aMakeRel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RewriteAllURIs(aOldPat, aNewPat, aMakeRel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIRefObject : public nsIURIRefObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURIREFOBJECT

  nsURIRefObject();

private:
  ~nsURIRefObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsURIRefObject, nsIURIRefObject)

nsURIRefObject::nsURIRefObject()
{
  /* member initializers and constructor code */
}

nsURIRefObject::~nsURIRefObject()
{
  /* destructor code */
}

/* attribute nsIDOMNode node; */
NS_IMETHODIMP nsURIRefObject::GetNode(nsIDOMNode * *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsURIRefObject::SetNode(nsIDOMNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Reset (); */
NS_IMETHODIMP nsURIRefObject::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString GetNextURI (); */
NS_IMETHODIMP nsURIRefObject::GetNextURI(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RewriteAllURIs (in DOMString aOldPat, in DOMString aNewPat, in boolean aMakeRel); */
NS_IMETHODIMP nsURIRefObject::RewriteAllURIs(const nsAString & aOldPat, const nsAString & aNewPat, bool aMakeRel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIRefObject_h__ */
