/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICategoryManager.idl
 */

#ifndef __gen_nsICategoryManager_h__
#define __gen_nsICategoryManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsICategoryManager */
#define NS_ICATEGORYMANAGER_IID_STR "3275b2cd-af6d-429a-80d7-f0c5120342ac"

#define NS_ICATEGORYMANAGER_IID \
  {0x3275b2cd, 0xaf6d, 0x429a, \
    { 0x80, 0xd7, 0xf0, 0xc5, 0x12, 0x03, 0x42, 0xac }}

class NS_NO_VTABLE nsICategoryManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICATEGORYMANAGER_IID)

  /* string getCategoryEntry (in string aCategory, in string aEntry); */
  NS_IMETHOD GetCategoryEntry(const char * aCategory, const char * aEntry, char * *_retval) = 0;

  /* string addCategoryEntry (in string aCategory, in string aEntry, in string aValue, in boolean aPersist, in boolean aReplace); */
  NS_IMETHOD AddCategoryEntry(const char * aCategory, const char * aEntry, const char * aValue, bool aPersist, bool aReplace, char * *_retval) = 0;

  /* void deleteCategoryEntry (in string aCategory, in string aEntry, in boolean aPersist); */
  NS_IMETHOD DeleteCategoryEntry(const char * aCategory, const char * aEntry, bool aPersist) = 0;

  /* void deleteCategory (in string aCategory); */
  NS_IMETHOD DeleteCategory(const char * aCategory) = 0;

  /* nsISimpleEnumerator enumerateCategory (in string aCategory); */
  NS_IMETHOD EnumerateCategory(const char * aCategory, nsISimpleEnumerator * *_retval) = 0;

  /* nsISimpleEnumerator enumerateCategories (); */
  NS_IMETHOD EnumerateCategories(nsISimpleEnumerator * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICategoryManager, NS_ICATEGORYMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICATEGORYMANAGER \
  NS_IMETHOD GetCategoryEntry(const char * aCategory, const char * aEntry, char * *_retval) override; \
  NS_IMETHOD AddCategoryEntry(const char * aCategory, const char * aEntry, const char * aValue, bool aPersist, bool aReplace, char * *_retval) override; \
  NS_IMETHOD DeleteCategoryEntry(const char * aCategory, const char * aEntry, bool aPersist) override; \
  NS_IMETHOD DeleteCategory(const char * aCategory) override; \
  NS_IMETHOD EnumerateCategory(const char * aCategory, nsISimpleEnumerator * *_retval) override; \
  NS_IMETHOD EnumerateCategories(nsISimpleEnumerator * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICATEGORYMANAGER(_to) \
  NS_IMETHOD GetCategoryEntry(const char * aCategory, const char * aEntry, char * *_retval) override { return _to GetCategoryEntry(aCategory, aEntry, _retval); } \
  NS_IMETHOD AddCategoryEntry(const char * aCategory, const char * aEntry, const char * aValue, bool aPersist, bool aReplace, char * *_retval) override { return _to AddCategoryEntry(aCategory, aEntry, aValue, aPersist, aReplace, _retval); } \
  NS_IMETHOD DeleteCategoryEntry(const char * aCategory, const char * aEntry, bool aPersist) override { return _to DeleteCategoryEntry(aCategory, aEntry, aPersist); } \
  NS_IMETHOD DeleteCategory(const char * aCategory) override { return _to DeleteCategory(aCategory); } \
  NS_IMETHOD EnumerateCategory(const char * aCategory, nsISimpleEnumerator * *_retval) override { return _to EnumerateCategory(aCategory, _retval); } \
  NS_IMETHOD EnumerateCategories(nsISimpleEnumerator * *_retval) override { return _to EnumerateCategories(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICATEGORYMANAGER(_to) \
  NS_IMETHOD GetCategoryEntry(const char * aCategory, const char * aEntry, char * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCategoryEntry(aCategory, aEntry, _retval); } \
  NS_IMETHOD AddCategoryEntry(const char * aCategory, const char * aEntry, const char * aValue, bool aPersist, bool aReplace, char * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddCategoryEntry(aCategory, aEntry, aValue, aPersist, aReplace, _retval); } \
  NS_IMETHOD DeleteCategoryEntry(const char * aCategory, const char * aEntry, bool aPersist) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteCategoryEntry(aCategory, aEntry, aPersist); } \
  NS_IMETHOD DeleteCategory(const char * aCategory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteCategory(aCategory); } \
  NS_IMETHOD EnumerateCategory(const char * aCategory, nsISimpleEnumerator * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateCategory(aCategory, _retval); } \
  NS_IMETHOD EnumerateCategories(nsISimpleEnumerator * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateCategories(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCategoryManager : public nsICategoryManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICATEGORYMANAGER

  nsCategoryManager();

private:
  ~nsCategoryManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCategoryManager, nsICategoryManager)

nsCategoryManager::nsCategoryManager()
{
  /* member initializers and constructor code */
}

nsCategoryManager::~nsCategoryManager()
{
  /* destructor code */
}

/* string getCategoryEntry (in string aCategory, in string aEntry); */
NS_IMETHODIMP nsCategoryManager::GetCategoryEntry(const char * aCategory, const char * aEntry, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string addCategoryEntry (in string aCategory, in string aEntry, in string aValue, in boolean aPersist, in boolean aReplace); */
NS_IMETHODIMP nsCategoryManager::AddCategoryEntry(const char * aCategory, const char * aEntry, const char * aValue, bool aPersist, bool aReplace, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteCategoryEntry (in string aCategory, in string aEntry, in boolean aPersist); */
NS_IMETHODIMP nsCategoryManager::DeleteCategoryEntry(const char * aCategory, const char * aEntry, bool aPersist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteCategory (in string aCategory); */
NS_IMETHODIMP nsCategoryManager::DeleteCategory(const char * aCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateCategory (in string aCategory); */
NS_IMETHODIMP nsCategoryManager::EnumerateCategory(const char * aCategory, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateCategories (); */
NS_IMETHODIMP nsCategoryManager::EnumerateCategories(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICategoryManager_h__ */
