/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHangReport.idl
 */

#ifndef __gen_nsIHangReport_h__
#define __gen_nsIHangReport_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIFrameLoader; /* forward declaration */


/* starting interface:    nsIHangReport */
#define NS_IHANGREPORT_IID_STR "90cea731-dd3e-459e-b017-f9a14697b56e"

#define NS_IHANGREPORT_IID \
  {0x90cea731, 0xdd3e, 0x459e, \
    { 0xb0, 0x17, 0xf9, 0xa1, 0x46, 0x97, 0xb5, 0x6e }}

class NS_NO_VTABLE nsIHangReport : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHANGREPORT_IID)

  enum {
    SLOW_SCRIPT = 1U,
    PLUGIN_HANG = 2U
  };

  /* readonly attribute unsigned long hangType; */
  NS_IMETHOD GetHangType(uint32_t *aHangType) = 0;

  /* readonly attribute nsIDOMElement scriptBrowser; */
  NS_IMETHOD GetScriptBrowser(nsIDOMElement * *aScriptBrowser) = 0;

  /* readonly attribute ACString scriptFileName; */
  NS_IMETHOD GetScriptFileName(nsACString & aScriptFileName) = 0;

  /* readonly attribute unsigned long scriptLineNo; */
  NS_IMETHOD GetScriptLineNo(uint32_t *aScriptLineNo) = 0;

  /* readonly attribute ACString pluginName; */
  NS_IMETHOD GetPluginName(nsACString & aPluginName) = 0;

  /* void userCanceled (); */
  NS_IMETHOD UserCanceled(void) = 0;

  /* void terminateScript (); */
  NS_IMETHOD TerminateScript(void) = 0;

  /* void terminatePlugin (); */
  NS_IMETHOD TerminatePlugin(void) = 0;

  /* void terminateProcess (); */
  NS_IMETHOD TerminateProcess(void) = 0;

  /* void beginStartingDebugger (); */
  NS_IMETHOD BeginStartingDebugger(void) = 0;

  /* void endStartingDebugger (); */
  NS_IMETHOD EndStartingDebugger(void) = 0;

  /* bool isReportForBrowser (in nsIFrameLoader aFrameLoader); */
  NS_IMETHOD IsReportForBrowser(nsIFrameLoader *aFrameLoader, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHangReport, NS_IHANGREPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHANGREPORT \
  NS_IMETHOD GetHangType(uint32_t *aHangType) override; \
  NS_IMETHOD GetScriptBrowser(nsIDOMElement * *aScriptBrowser) override; \
  NS_IMETHOD GetScriptFileName(nsACString & aScriptFileName) override; \
  NS_IMETHOD GetScriptLineNo(uint32_t *aScriptLineNo) override; \
  NS_IMETHOD GetPluginName(nsACString & aPluginName) override; \
  NS_IMETHOD UserCanceled(void) override; \
  NS_IMETHOD TerminateScript(void) override; \
  NS_IMETHOD TerminatePlugin(void) override; \
  NS_IMETHOD TerminateProcess(void) override; \
  NS_IMETHOD BeginStartingDebugger(void) override; \
  NS_IMETHOD EndStartingDebugger(void) override; \
  NS_IMETHOD IsReportForBrowser(nsIFrameLoader *aFrameLoader, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHANGREPORT(_to) \
  NS_IMETHOD GetHangType(uint32_t *aHangType) override { return _to GetHangType(aHangType); } \
  NS_IMETHOD GetScriptBrowser(nsIDOMElement * *aScriptBrowser) override { return _to GetScriptBrowser(aScriptBrowser); } \
  NS_IMETHOD GetScriptFileName(nsACString & aScriptFileName) override { return _to GetScriptFileName(aScriptFileName); } \
  NS_IMETHOD GetScriptLineNo(uint32_t *aScriptLineNo) override { return _to GetScriptLineNo(aScriptLineNo); } \
  NS_IMETHOD GetPluginName(nsACString & aPluginName) override { return _to GetPluginName(aPluginName); } \
  NS_IMETHOD UserCanceled(void) override { return _to UserCanceled(); } \
  NS_IMETHOD TerminateScript(void) override { return _to TerminateScript(); } \
  NS_IMETHOD TerminatePlugin(void) override { return _to TerminatePlugin(); } \
  NS_IMETHOD TerminateProcess(void) override { return _to TerminateProcess(); } \
  NS_IMETHOD BeginStartingDebugger(void) override { return _to BeginStartingDebugger(); } \
  NS_IMETHOD EndStartingDebugger(void) override { return _to EndStartingDebugger(); } \
  NS_IMETHOD IsReportForBrowser(nsIFrameLoader *aFrameLoader, bool *_retval) override { return _to IsReportForBrowser(aFrameLoader, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHANGREPORT(_to) \
  NS_IMETHOD GetHangType(uint32_t *aHangType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHangType(aHangType); } \
  NS_IMETHOD GetScriptBrowser(nsIDOMElement * *aScriptBrowser) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptBrowser(aScriptBrowser); } \
  NS_IMETHOD GetScriptFileName(nsACString & aScriptFileName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptFileName(aScriptFileName); } \
  NS_IMETHOD GetScriptLineNo(uint32_t *aScriptLineNo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScriptLineNo(aScriptLineNo); } \
  NS_IMETHOD GetPluginName(nsACString & aPluginName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginName(aPluginName); } \
  NS_IMETHOD UserCanceled(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UserCanceled(); } \
  NS_IMETHOD TerminateScript(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TerminateScript(); } \
  NS_IMETHOD TerminatePlugin(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TerminatePlugin(); } \
  NS_IMETHOD TerminateProcess(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TerminateProcess(); } \
  NS_IMETHOD BeginStartingDebugger(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginStartingDebugger(); } \
  NS_IMETHOD EndStartingDebugger(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EndStartingDebugger(); } \
  NS_IMETHOD IsReportForBrowser(nsIFrameLoader *aFrameLoader, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsReportForBrowser(aFrameLoader, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHangReport : public nsIHangReport
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHANGREPORT

  nsHangReport();

private:
  ~nsHangReport();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsHangReport, nsIHangReport)

nsHangReport::nsHangReport()
{
  /* member initializers and constructor code */
}

nsHangReport::~nsHangReport()
{
  /* destructor code */
}

/* readonly attribute unsigned long hangType; */
NS_IMETHODIMP nsHangReport::GetHangType(uint32_t *aHangType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement scriptBrowser; */
NS_IMETHODIMP nsHangReport::GetScriptBrowser(nsIDOMElement * *aScriptBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString scriptFileName; */
NS_IMETHODIMP nsHangReport::GetScriptFileName(nsACString & aScriptFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long scriptLineNo; */
NS_IMETHODIMP nsHangReport::GetScriptLineNo(uint32_t *aScriptLineNo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString pluginName; */
NS_IMETHODIMP nsHangReport::GetPluginName(nsACString & aPluginName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void userCanceled (); */
NS_IMETHODIMP nsHangReport::UserCanceled()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void terminateScript (); */
NS_IMETHODIMP nsHangReport::TerminateScript()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void terminatePlugin (); */
NS_IMETHODIMP nsHangReport::TerminatePlugin()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void terminateProcess (); */
NS_IMETHODIMP nsHangReport::TerminateProcess()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginStartingDebugger (); */
NS_IMETHODIMP nsHangReport::BeginStartingDebugger()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endStartingDebugger (); */
NS_IMETHODIMP nsHangReport::EndStartingDebugger()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isReportForBrowser (in nsIFrameLoader aFrameLoader); */
NS_IMETHODIMP nsHangReport::IsReportForBrowser(nsIFrameLoader *aFrameLoader, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHangReport_h__ */
