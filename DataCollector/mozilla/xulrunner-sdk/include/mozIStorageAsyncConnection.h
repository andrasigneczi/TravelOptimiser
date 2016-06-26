/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIStorageAsyncConnection.idl
 */

#ifndef __gen_mozIStorageAsyncConnection_h__
#define __gen_mozIStorageAsyncConnection_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageAggregateFunction; /* forward declaration */

class mozIStorageCompletionCallback; /* forward declaration */

class mozIStorageFunction; /* forward declaration */

class mozIStorageProgressHandler; /* forward declaration */

class mozIStorageBaseStatement; /* forward declaration */

class mozIStorageStatement; /* forward declaration */

class mozIStorageAsyncStatement; /* forward declaration */

class mozIStorageStatementCallback; /* forward declaration */

class mozIStoragePendingStatement; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    mozIStorageAsyncConnection */
#define MOZISTORAGEASYNCCONNECTION_IID_STR "8bfd34d5-4ddf-4e4b-89dd-9b14f33534c6"

#define MOZISTORAGEASYNCCONNECTION_IID \
  {0x8bfd34d5, 0x4ddf, 0x4e4b, \
    { 0x89, 0xdd, 0x9b, 0x14, 0xf3, 0x35, 0x34, 0xc6 }}

class NS_NO_VTABLE mozIStorageAsyncConnection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGEASYNCCONNECTION_IID)

  /* void asyncClose ([optional] in mozIStorageCompletionCallback aCallback); */
  NS_IMETHOD AsyncClose(mozIStorageCompletionCallback *aCallback) = 0;

  /* void asyncClone (in boolean aReadOnly, in mozIStorageCompletionCallback aCallback); */
  NS_IMETHOD AsyncClone(bool aReadOnly, mozIStorageCompletionCallback *aCallback) = 0;

  /* readonly attribute nsIFile databaseFile; */
  NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) = 0;

  /* mozIStorageAsyncStatement createAsyncStatement (in AUTF8String aSQLStatement); */
  NS_IMETHOD CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval) = 0;

  /* mozIStoragePendingStatement executeAsync ([array, size_is (aNumStatements)] in mozIStorageBaseStatement aStatements, in unsigned long aNumStatements, [optional] in mozIStorageStatementCallback aCallback); */
  NS_IMETHOD ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) = 0;

  /* mozIStoragePendingStatement executeSimpleSQLAsync (in AUTF8String aSQLStatement, [optional] in mozIStorageStatementCallback aCallback); */
  NS_IMETHOD ExecuteSimpleSQLAsync(const nsACString & aSQLStatement, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) = 0;

  /* void createFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageFunction aFunction); */
  NS_IMETHOD CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction) = 0;

  /* void createAggregateFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageAggregateFunction aFunction); */
  NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction) = 0;

  /* void removeFunction (in AUTF8String aFunctionName); */
  NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) = 0;

  /* mozIStorageProgressHandler setProgressHandler (in int32_t aGranularity, in mozIStorageProgressHandler aHandler); */
  NS_IMETHOD SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval) = 0;

  /* mozIStorageProgressHandler removeProgressHandler (); */
  NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageAsyncConnection, MOZISTORAGEASYNCCONNECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGEASYNCCONNECTION \
  NS_IMETHOD AsyncClose(mozIStorageCompletionCallback *aCallback) override; \
  NS_IMETHOD AsyncClone(bool aReadOnly, mozIStorageCompletionCallback *aCallback) override; \
  NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) override; \
  NS_IMETHOD CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval) override; \
  NS_IMETHOD ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) override; \
  NS_IMETHOD ExecuteSimpleSQLAsync(const nsACString & aSQLStatement, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) override; \
  NS_IMETHOD CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction) override; \
  NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction) override; \
  NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) override; \
  NS_IMETHOD SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval) override; \
  NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGEASYNCCONNECTION(_to) \
  NS_IMETHOD AsyncClose(mozIStorageCompletionCallback *aCallback) override { return _to AsyncClose(aCallback); } \
  NS_IMETHOD AsyncClone(bool aReadOnly, mozIStorageCompletionCallback *aCallback) override { return _to AsyncClone(aReadOnly, aCallback); } \
  NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) override { return _to GetDatabaseFile(aDatabaseFile); } \
  NS_IMETHOD CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval) override { return _to CreateAsyncStatement(aSQLStatement, _retval); } \
  NS_IMETHOD ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) override { return _to ExecuteAsync(aStatements, aNumStatements, aCallback, _retval); } \
  NS_IMETHOD ExecuteSimpleSQLAsync(const nsACString & aSQLStatement, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) override { return _to ExecuteSimpleSQLAsync(aSQLStatement, aCallback, _retval); } \
  NS_IMETHOD CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction) override { return _to CreateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction) override { return _to CreateAggregateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) override { return _to RemoveFunction(aFunctionName); } \
  NS_IMETHOD SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval) override { return _to SetProgressHandler(aGranularity, aHandler, _retval); } \
  NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler * *_retval) override { return _to RemoveProgressHandler(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGEASYNCCONNECTION(_to) \
  NS_IMETHOD AsyncClose(mozIStorageCompletionCallback *aCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncClose(aCallback); } \
  NS_IMETHOD AsyncClone(bool aReadOnly, mozIStorageCompletionCallback *aCallback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncClone(aReadOnly, aCallback); } \
  NS_IMETHOD GetDatabaseFile(nsIFile * *aDatabaseFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabaseFile(aDatabaseFile); } \
  NS_IMETHOD CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAsyncStatement(aSQLStatement, _retval); } \
  NS_IMETHOD ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteAsync(aStatements, aNumStatements, aCallback, _retval); } \
  NS_IMETHOD ExecuteSimpleSQLAsync(const nsACString & aSQLStatement, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteSimpleSQLAsync(aSQLStatement, aCallback, _retval); } \
  NS_IMETHOD CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_IMETHOD CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAggregateFunction(aFunctionName, aNumArguments, aFunction); } \
  NS_IMETHOD RemoveFunction(const nsACString & aFunctionName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFunction(aFunctionName); } \
  NS_IMETHOD SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProgressHandler(aGranularity, aHandler, _retval); } \
  NS_IMETHOD RemoveProgressHandler(mozIStorageProgressHandler * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveProgressHandler(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageAsyncConnection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGEASYNCCONNECTION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, mozIStorageAsyncConnection)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void asyncClose ([optional] in mozIStorageCompletionCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::AsyncClose(mozIStorageCompletionCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncClone (in boolean aReadOnly, in mozIStorageCompletionCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::AsyncClone(bool aReadOnly, mozIStorageCompletionCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile databaseFile; */
NS_IMETHODIMP _MYCLASS_::GetDatabaseFile(nsIFile * *aDatabaseFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageAsyncStatement createAsyncStatement (in AUTF8String aSQLStatement); */
NS_IMETHODIMP _MYCLASS_::CreateAsyncStatement(const nsACString & aSQLStatement, mozIStorageAsyncStatement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStoragePendingStatement executeAsync ([array, size_is (aNumStatements)] in mozIStorageBaseStatement aStatements, in unsigned long aNumStatements, [optional] in mozIStorageStatementCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::ExecuteAsync(mozIStorageBaseStatement **aStatements, uint32_t aNumStatements, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStoragePendingStatement executeSimpleSQLAsync (in AUTF8String aSQLStatement, [optional] in mozIStorageStatementCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::ExecuteSimpleSQLAsync(const nsACString & aSQLStatement, mozIStorageStatementCallback *aCallback, mozIStoragePendingStatement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageFunction aFunction); */
NS_IMETHODIMP _MYCLASS_::CreateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageFunction *aFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createAggregateFunction (in AUTF8String aFunctionName, in long aNumArguments, in mozIStorageAggregateFunction aFunction); */
NS_IMETHODIMP _MYCLASS_::CreateAggregateFunction(const nsACString & aFunctionName, int32_t aNumArguments, mozIStorageAggregateFunction *aFunction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeFunction (in AUTF8String aFunctionName); */
NS_IMETHODIMP _MYCLASS_::RemoveFunction(const nsACString & aFunctionName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageProgressHandler setProgressHandler (in int32_t aGranularity, in mozIStorageProgressHandler aHandler); */
NS_IMETHODIMP _MYCLASS_::SetProgressHandler(int32_t aGranularity, mozIStorageProgressHandler *aHandler, mozIStorageProgressHandler * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageProgressHandler removeProgressHandler (); */
NS_IMETHODIMP _MYCLASS_::RemoveProgressHandler(mozIStorageProgressHandler * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIStorageAsyncConnection_h__ */
