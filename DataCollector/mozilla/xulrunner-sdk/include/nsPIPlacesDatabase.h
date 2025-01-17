/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsPIPlacesDatabase.idl
 */

#ifndef __gen_nsPIPlacesDatabase_h__
#define __gen_nsPIPlacesDatabase_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */

class nsINavHistoryQuery; /* forward declaration */

class nsINavHistoryQueryOptions; /* forward declaration */

class mozIStorageStatementCallback; /* forward declaration */

class mozIStoragePendingStatement; /* forward declaration */

class nsIAsyncShutdownClient; /* forward declaration */


/* starting interface:    nsPIPlacesDatabase */
#define NS_PIPLACESDATABASE_IID_STR "366ee63e-a413-477d-9ad6-8d6863e89401"

#define NS_PIPLACESDATABASE_IID \
  {0x366ee63e, 0xa413, 0x477d, \
    { 0x9a, 0xd6, 0x8d, 0x68, 0x63, 0xe8, 0x94, 0x01 }}

class NS_NO_VTABLE nsPIPlacesDatabase : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIPLACESDATABASE_IID)

  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) = 0;

  /* mozIStoragePendingStatement asyncExecuteLegacyQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions aOptions, in mozIStorageStatementCallback aCallback); */
  NS_IMETHOD AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) = 0;

  /* readonly attribute nsIAsyncShutdownClient shutdownClient; */
  NS_IMETHOD GetShutdownClient(nsIAsyncShutdownClient * *aShutdownClient) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIPlacesDatabase, NS_PIPLACESDATABASE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIPLACESDATABASE \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) override; \
  NS_IMETHOD AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) override; \
  NS_IMETHOD GetShutdownClient(nsIAsyncShutdownClient * *aShutdownClient) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIPLACESDATABASE(_to) \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) override { return _to GetDBConnection(aDBConnection); } \
  NS_IMETHOD AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) override { return _to AsyncExecuteLegacyQueries(aQueries, aQueryCount, aOptions, aCallback, _retval); } \
  NS_IMETHOD GetShutdownClient(nsIAsyncShutdownClient * *aShutdownClient) override { return _to GetShutdownClient(aShutdownClient); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIPLACESDATABASE(_to) \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } \
  NS_IMETHOD AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncExecuteLegacyQueries(aQueries, aQueryCount, aOptions, aCallback, _retval); } \
  NS_IMETHOD GetShutdownClient(nsIAsyncShutdownClient * *aShutdownClient) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShutdownClient(aShutdownClient); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIPlacesDatabase
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIPLACESDATABASE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, nsPIPlacesDatabase)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP _MYCLASS_::GetDBConnection(mozIStorageConnection * *aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStoragePendingStatement asyncExecuteLegacyQueries ([array, size_is (aQueryCount)] in nsINavHistoryQuery aQueries, in unsigned long aQueryCount, in nsINavHistoryQueryOptions aOptions, in mozIStorageStatementCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::AsyncExecuteLegacyQueries(nsINavHistoryQuery **aQueries, uint32_t aQueryCount, nsINavHistoryQueryOptions *aOptions, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIAsyncShutdownClient shutdownClient; */
NS_IMETHODIMP _MYCLASS_::GetShutdownClient(nsIAsyncShutdownClient * *aShutdownClient)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIPlacesDatabase_h__ */
