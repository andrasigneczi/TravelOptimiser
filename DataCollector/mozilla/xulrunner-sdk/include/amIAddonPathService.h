/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\amIAddonPathService.idl
 */

#ifndef __gen_amIAddonPathService_h__
#define __gen_amIAddonPathService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    amIAddonPathService */
#define AMIADDONPATHSERVICE_IID_STR "fcd9e270-dfb1-11e3-8b68-0800200c9a66"

#define AMIADDONPATHSERVICE_IID \
  {0xfcd9e270, 0xdfb1, 0x11e3, \
    { 0x8b, 0x68, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE amIAddonPathService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(AMIADDONPATHSERVICE_IID)

  /* AString findAddonId (in AString path); */
  NS_IMETHOD FindAddonId(const nsAString & path, nsAString & _retval) = 0;

  /* void insertPath (in AString path, in AString addonId); */
  NS_IMETHOD InsertPath(const nsAString & path, const nsAString & addonId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(amIAddonPathService, AMIADDONPATHSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_AMIADDONPATHSERVICE \
  NS_IMETHOD FindAddonId(const nsAString & path, nsAString & _retval) override; \
  NS_IMETHOD InsertPath(const nsAString & path, const nsAString & addonId) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_AMIADDONPATHSERVICE(_to) \
  NS_IMETHOD FindAddonId(const nsAString & path, nsAString & _retval) override { return _to FindAddonId(path, _retval); } \
  NS_IMETHOD InsertPath(const nsAString & path, const nsAString & addonId) override { return _to InsertPath(path, addonId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_AMIADDONPATHSERVICE(_to) \
  NS_IMETHOD FindAddonId(const nsAString & path, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindAddonId(path, _retval); } \
  NS_IMETHOD InsertPath(const nsAString & path, const nsAString & addonId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertPath(path, addonId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class amAddonPathService : public amIAddonPathService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_AMIADDONPATHSERVICE

  amAddonPathService();

private:
  ~amAddonPathService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(amAddonPathService, amIAddonPathService)

amAddonPathService::amAddonPathService()
{
  /* member initializers and constructor code */
}

amAddonPathService::~amAddonPathService()
{
  /* destructor code */
}

/* AString findAddonId (in AString path); */
NS_IMETHODIMP amAddonPathService::FindAddonId(const nsAString & path, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertPath (in AString path, in AString addonId); */
NS_IMETHODIMP amAddonPathService::InsertPath(const nsAString & path, const nsAString & addonId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_amIAddonPathService_h__ */
