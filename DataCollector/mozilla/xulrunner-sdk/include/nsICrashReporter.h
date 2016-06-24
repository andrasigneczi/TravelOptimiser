/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICrashReporter.idl
 */

#ifndef __gen_nsICrashReporter_h__
#define __gen_nsICrashReporter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIURL; /* forward declaration */


/* starting interface:    nsICrashReporter */
#define NS_ICRASHREPORTER_IID_STR "4b74c39a-cf69-4a8a-8e63-169d81ad1ecf"

#define NS_ICRASHREPORTER_IID \
  {0x4b74c39a, 0xcf69, 0x4a8a, \
    { 0x8e, 0x63, 0x16, 0x9d, 0x81, 0xad, 0x1e, 0xcf }}

class NS_NO_VTABLE nsICrashReporter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICRASHREPORTER_IID)

  /* readonly attribute boolean enabled; */
  NS_IMETHOD GetEnabled(bool *aEnabled) = 0;

  /* [noscript] void setEnabled (in bool enabled); */
  NS_IMETHOD SetEnabled(bool enabled) = 0;

  /* attribute nsIURL serverURL; */
  NS_IMETHOD GetServerURL(nsIURL * *aServerURL) = 0;
  NS_IMETHOD SetServerURL(nsIURL *aServerURL) = 0;

  /* attribute nsIFile minidumpPath; */
  NS_IMETHOD GetMinidumpPath(nsIFile * *aMinidumpPath) = 0;
  NS_IMETHOD SetMinidumpPath(nsIFile *aMinidumpPath) = 0;

  /* void annotateCrashReport (in AUTF8String key, in AUTF8String data); */
  NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) = 0;

  /* void appendAppNotesToCrashReport (in ACString data); */
  NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) = 0;

  /* void registerAppMemory (in unsigned long long ptr, in unsigned long long size); */
  NS_IMETHOD RegisterAppMemory(uint64_t ptr, uint64_t size) = 0;

  /* [noscript] void writeMinidumpForException (in voidPtr aExceptionInfo); */
  NS_IMETHOD WriteMinidumpForException(void *aExceptionInfo) = 0;

  /* [noscript] void appendObjCExceptionInfoToAppNotes (in voidPtr aException); */
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void *aException) = 0;

  /* attribute boolean submitReports; */
  NS_IMETHOD GetSubmitReports(bool *aSubmitReports) = 0;
  NS_IMETHOD SetSubmitReports(bool aSubmitReports) = 0;

  /* void UpdateCrashEventsDir (); */
  NS_IMETHOD UpdateCrashEventsDir(void) = 0;

  /* void saveMemoryReport (); */
  NS_IMETHOD SaveMemoryReport(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICrashReporter, NS_ICRASHREPORTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICRASHREPORTER \
  NS_IMETHOD GetEnabled(bool *aEnabled) override; \
  NS_IMETHOD SetEnabled(bool enabled) override; \
  NS_IMETHOD GetServerURL(nsIURL * *aServerURL) override; \
  NS_IMETHOD SetServerURL(nsIURL *aServerURL) override; \
  NS_IMETHOD GetMinidumpPath(nsIFile * *aMinidumpPath) override; \
  NS_IMETHOD SetMinidumpPath(nsIFile *aMinidumpPath) override; \
  NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) override; \
  NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) override; \
  NS_IMETHOD RegisterAppMemory(uint64_t ptr, uint64_t size) override; \
  NS_IMETHOD WriteMinidumpForException(void *aExceptionInfo) override; \
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void *aException) override; \
  NS_IMETHOD GetSubmitReports(bool *aSubmitReports) override; \
  NS_IMETHOD SetSubmitReports(bool aSubmitReports) override; \
  NS_IMETHOD UpdateCrashEventsDir(void) override; \
  NS_IMETHOD SaveMemoryReport(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICRASHREPORTER(_to) \
  NS_IMETHOD GetEnabled(bool *aEnabled) override { return _to GetEnabled(aEnabled); } \
  NS_IMETHOD SetEnabled(bool enabled) override { return _to SetEnabled(enabled); } \
  NS_IMETHOD GetServerURL(nsIURL * *aServerURL) override { return _to GetServerURL(aServerURL); } \
  NS_IMETHOD SetServerURL(nsIURL *aServerURL) override { return _to SetServerURL(aServerURL); } \
  NS_IMETHOD GetMinidumpPath(nsIFile * *aMinidumpPath) override { return _to GetMinidumpPath(aMinidumpPath); } \
  NS_IMETHOD SetMinidumpPath(nsIFile *aMinidumpPath) override { return _to SetMinidumpPath(aMinidumpPath); } \
  NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) override { return _to AnnotateCrashReport(key, data); } \
  NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) override { return _to AppendAppNotesToCrashReport(data); } \
  NS_IMETHOD RegisterAppMemory(uint64_t ptr, uint64_t size) override { return _to RegisterAppMemory(ptr, size); } \
  NS_IMETHOD WriteMinidumpForException(void *aExceptionInfo) override { return _to WriteMinidumpForException(aExceptionInfo); } \
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void *aException) override { return _to AppendObjCExceptionInfoToAppNotes(aException); } \
  NS_IMETHOD GetSubmitReports(bool *aSubmitReports) override { return _to GetSubmitReports(aSubmitReports); } \
  NS_IMETHOD SetSubmitReports(bool aSubmitReports) override { return _to SetSubmitReports(aSubmitReports); } \
  NS_IMETHOD UpdateCrashEventsDir(void) override { return _to UpdateCrashEventsDir(); } \
  NS_IMETHOD SaveMemoryReport(void) override { return _to SaveMemoryReport(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICRASHREPORTER(_to) \
  NS_IMETHOD GetEnabled(bool *aEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnabled(aEnabled); } \
  NS_IMETHOD SetEnabled(bool enabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnabled(enabled); } \
  NS_IMETHOD GetServerURL(nsIURL * *aServerURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetServerURL(aServerURL); } \
  NS_IMETHOD SetServerURL(nsIURL *aServerURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetServerURL(aServerURL); } \
  NS_IMETHOD GetMinidumpPath(nsIFile * *aMinidumpPath) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinidumpPath(aMinidumpPath); } \
  NS_IMETHOD SetMinidumpPath(nsIFile *aMinidumpPath) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMinidumpPath(aMinidumpPath); } \
  NS_IMETHOD AnnotateCrashReport(const nsACString & key, const nsACString & data) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AnnotateCrashReport(key, data); } \
  NS_IMETHOD AppendAppNotesToCrashReport(const nsACString & data) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendAppNotesToCrashReport(data); } \
  NS_IMETHOD RegisterAppMemory(uint64_t ptr, uint64_t size) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterAppMemory(ptr, size); } \
  NS_IMETHOD WriteMinidumpForException(void *aExceptionInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteMinidumpForException(aExceptionInfo); } \
  NS_IMETHOD AppendObjCExceptionInfoToAppNotes(void *aException) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendObjCExceptionInfoToAppNotes(aException); } \
  NS_IMETHOD GetSubmitReports(bool *aSubmitReports) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubmitReports(aSubmitReports); } \
  NS_IMETHOD SetSubmitReports(bool aSubmitReports) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSubmitReports(aSubmitReports); } \
  NS_IMETHOD UpdateCrashEventsDir(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCrashEventsDir(); } \
  NS_IMETHOD SaveMemoryReport(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SaveMemoryReport(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCrashReporter : public nsICrashReporter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICRASHREPORTER

  nsCrashReporter();

private:
  ~nsCrashReporter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsCrashReporter, nsICrashReporter)

nsCrashReporter::nsCrashReporter()
{
  /* member initializers and constructor code */
}

nsCrashReporter::~nsCrashReporter()
{
  /* destructor code */
}

/* readonly attribute boolean enabled; */
NS_IMETHODIMP nsCrashReporter::GetEnabled(bool *aEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setEnabled (in bool enabled); */
NS_IMETHODIMP nsCrashReporter::SetEnabled(bool enabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURL serverURL; */
NS_IMETHODIMP nsCrashReporter::GetServerURL(nsIURL * *aServerURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCrashReporter::SetServerURL(nsIURL *aServerURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFile minidumpPath; */
NS_IMETHODIMP nsCrashReporter::GetMinidumpPath(nsIFile * *aMinidumpPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCrashReporter::SetMinidumpPath(nsIFile *aMinidumpPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void annotateCrashReport (in AUTF8String key, in AUTF8String data); */
NS_IMETHODIMP nsCrashReporter::AnnotateCrashReport(const nsACString & key, const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendAppNotesToCrashReport (in ACString data); */
NS_IMETHODIMP nsCrashReporter::AppendAppNotesToCrashReport(const nsACString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerAppMemory (in unsigned long long ptr, in unsigned long long size); */
NS_IMETHODIMP nsCrashReporter::RegisterAppMemory(uint64_t ptr, uint64_t size)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void writeMinidumpForException (in voidPtr aExceptionInfo); */
NS_IMETHODIMP nsCrashReporter::WriteMinidumpForException(void *aExceptionInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void appendObjCExceptionInfoToAppNotes (in voidPtr aException); */
NS_IMETHODIMP nsCrashReporter::AppendObjCExceptionInfoToAppNotes(void *aException)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean submitReports; */
NS_IMETHODIMP nsCrashReporter::GetSubmitReports(bool *aSubmitReports)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCrashReporter::SetSubmitReports(bool aSubmitReports)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void UpdateCrashEventsDir (); */
NS_IMETHODIMP nsCrashReporter::UpdateCrashEventsDir()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void saveMemoryReport (); */
NS_IMETHODIMP nsCrashReporter::SaveMemoryReport()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICrashReporter_h__ */
