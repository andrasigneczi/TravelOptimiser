/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStatusReporter.idl
 */

#ifndef __gen_nsIStatusReporter_h__
#define __gen_nsIStatusReporter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIStatusReporter */
#define NS_ISTATUSREPORTER_IID_STR "ffcb716c-deeb-44ea-9d9d-ab25dc6980a8"

#define NS_ISTATUSREPORTER_IID \
  {0xffcb716c, 0xdeeb, 0x44ea, \
    { 0x9d, 0x9d, 0xab, 0x25, 0xdc, 0x69, 0x80, 0xa8 }}

class NS_NO_VTABLE nsIStatusReporter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTATUSREPORTER_IID)

  /* readonly attribute ACString name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute ACString process; */
  NS_IMETHOD GetProcess(nsACString & aProcess) = 0;

  /* readonly attribute AUTF8String description; */
  NS_IMETHOD GetDescription(nsACString & aDescription) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStatusReporter, NS_ISTATUSREPORTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTATUSREPORTER \
  NS_IMETHOD GetName(nsACString & aName) override; \
  NS_IMETHOD GetProcess(nsACString & aProcess) override; \
  NS_IMETHOD GetDescription(nsACString & aDescription) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTATUSREPORTER(_to) \
  NS_IMETHOD GetName(nsACString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD GetProcess(nsACString & aProcess) override { return _to GetProcess(aProcess); } \
  NS_IMETHOD GetDescription(nsACString & aDescription) override { return _to GetDescription(aDescription); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTATUSREPORTER(_to) \
  NS_IMETHOD GetName(nsACString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetProcess(nsACString & aProcess) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProcess(aProcess); } \
  NS_IMETHOD GetDescription(nsACString & aDescription) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStatusReporter : public nsIStatusReporter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTATUSREPORTER

  nsStatusReporter();

private:
  ~nsStatusReporter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStatusReporter, nsIStatusReporter)

nsStatusReporter::nsStatusReporter()
{
  /* member initializers and constructor code */
}

nsStatusReporter::~nsStatusReporter()
{
  /* destructor code */
}

/* readonly attribute ACString name; */
NS_IMETHODIMP nsStatusReporter::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString process; */
NS_IMETHODIMP nsStatusReporter::GetProcess(nsACString & aProcess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String description; */
NS_IMETHODIMP nsStatusReporter::GetDescription(nsACString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStatusReporterManager */
#define NS_ISTATUSREPORTERMANAGER_IID_STR "fd531273-3319-4fcd-90f2-9f53876c3828"

#define NS_ISTATUSREPORTERMANAGER_IID \
  {0xfd531273, 0x3319, 0x4fcd, \
    { 0x90, 0xf2, 0x9f, 0x53, 0x87, 0x6c, 0x38, 0x28 }}

class NS_NO_VTABLE nsIStatusReporterManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTATUSREPORTERMANAGER_IID)

  /* nsISimpleEnumerator enumerateReporters (); */
  NS_IMETHOD EnumerateReporters(nsISimpleEnumerator * *_retval) = 0;

  /* void registerReporter (in nsIStatusReporter reporter); */
  NS_IMETHOD RegisterReporter(nsIStatusReporter *reporter) = 0;

  /* void unregisterReporter (in nsIStatusReporter reporter); */
  NS_IMETHOD UnregisterReporter(nsIStatusReporter *reporter) = 0;

  /* void init (); */
  NS_IMETHOD Init(void) = 0;

  /* void dumpReports (); */
  NS_IMETHOD DumpReports(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStatusReporterManager, NS_ISTATUSREPORTERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTATUSREPORTERMANAGER \
  NS_IMETHOD EnumerateReporters(nsISimpleEnumerator * *_retval) override; \
  NS_IMETHOD RegisterReporter(nsIStatusReporter *reporter) override; \
  NS_IMETHOD UnregisterReporter(nsIStatusReporter *reporter) override; \
  NS_IMETHOD Init(void) override; \
  NS_IMETHOD DumpReports(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTATUSREPORTERMANAGER(_to) \
  NS_IMETHOD EnumerateReporters(nsISimpleEnumerator * *_retval) override { return _to EnumerateReporters(_retval); } \
  NS_IMETHOD RegisterReporter(nsIStatusReporter *reporter) override { return _to RegisterReporter(reporter); } \
  NS_IMETHOD UnregisterReporter(nsIStatusReporter *reporter) override { return _to UnregisterReporter(reporter); } \
  NS_IMETHOD Init(void) override { return _to Init(); } \
  NS_IMETHOD DumpReports(void) override { return _to DumpReports(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTATUSREPORTERMANAGER(_to) \
  NS_IMETHOD EnumerateReporters(nsISimpleEnumerator * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateReporters(_retval); } \
  NS_IMETHOD RegisterReporter(nsIStatusReporter *reporter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterReporter(reporter); } \
  NS_IMETHOD UnregisterReporter(nsIStatusReporter *reporter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterReporter(reporter); } \
  NS_IMETHOD Init(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD DumpReports(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpReports(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStatusReporterManager : public nsIStatusReporterManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTATUSREPORTERMANAGER

  nsStatusReporterManager();

private:
  ~nsStatusReporterManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStatusReporterManager, nsIStatusReporterManager)

nsStatusReporterManager::nsStatusReporterManager()
{
  /* member initializers and constructor code */
}

nsStatusReporterManager::~nsStatusReporterManager()
{
  /* destructor code */
}

/* nsISimpleEnumerator enumerateReporters (); */
NS_IMETHODIMP nsStatusReporterManager::EnumerateReporters(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerReporter (in nsIStatusReporter reporter); */
NS_IMETHODIMP nsStatusReporterManager::RegisterReporter(nsIStatusReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterReporter (in nsIStatusReporter reporter); */
NS_IMETHODIMP nsStatusReporterManager::UnregisterReporter(nsIStatusReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (); */
NS_IMETHODIMP nsStatusReporterManager::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpReports (); */
NS_IMETHODIMP nsStatusReporterManager::DumpReports()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/*
 * Note that this defaults 'process' to "", which is usually what's desired.
 */
#define NS_STATUS_REPORTER_IMPLEMENT(_classname, _name, _desc_Function)       \
    class StatusReporter_##_classname final : public nsIStatusReporter {      \
      ~StatusReporter_##_classname() {}                                       \
    public:                                                                   \
      NS_DECL_ISUPPORTS                                                       \
      NS_IMETHOD GetName(nsACString &name) override                           \
        { name.AssignLiteral(_name); return NS_OK; }                          \
      NS_IMETHOD GetProcess(nsACString &process) override                     \
        { process.Truncate(); return NS_OK; }                                 \
      NS_IMETHOD GetDescription(nsACString &desc) override                    \
        { _desc_Function(desc); return NS_OK; }                               \
    };                                                                        \
    NS_IMPL_ISUPPORTS(StatusReporter_##_classname, nsIStatusReporter)
#define NS_STATUS_REPORTER_NAME(_classname)  StatusReporter_##_classname
nsresult NS_RegisterStatusReporter(nsIStatusReporter *reporter);
nsresult NS_UnregisterStatusReporter(nsIStatusReporter *reporter);
nsresult NS_DumpStatusReporter();
#define NS_STATUS_REPORTER_MANAGER_CID \
{ 0xe8eb4e7e, 0xf2cf, 0x45e5, \
{ 0xb8, 0xa4, 0x6a, 0x0f, 0x50, 0x18, 0x84, 0x63 } }

#endif /* __gen_nsIStatusReporter_h__ */
