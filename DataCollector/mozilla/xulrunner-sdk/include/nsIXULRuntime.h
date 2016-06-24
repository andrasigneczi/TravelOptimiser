/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXULRuntime.idl
 */

#ifndef __gen_nsIXULRuntime_h__
#define __gen_nsIXULRuntime_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

namespace mozilla {
// Simple C++ getter for nsIXULRuntime::browserTabsRemoteAutostart
// This getter is a temporary function that checks for special
// conditions in which e10s support is not great yet, and should
// therefore be disabled. Bug 1065561 tracks its removal.
bool BrowserTabsRemoteAutostart();
}

/* starting interface:    nsIXULRuntime */
#define NS_IXULRUNTIME_IID_STR "ce9d05f4-0c20-4f52-87e1-3a425e61e2f3"

#define NS_IXULRUNTIME_IID \
  {0xce9d05f4, 0x0c20, 0x4f52, \
    { 0x87, 0xe1, 0x3a, 0x42, 0x5e, 0x61, 0xe2, 0xf3 }}

class NS_NO_VTABLE nsIXULRuntime : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULRUNTIME_IID)

  /* readonly attribute boolean inSafeMode; */
  NS_IMETHOD GetInSafeMode(bool *aInSafeMode) = 0;

  /* attribute boolean logConsoleErrors; */
  NS_IMETHOD GetLogConsoleErrors(bool *aLogConsoleErrors) = 0;
  NS_IMETHOD SetLogConsoleErrors(bool aLogConsoleErrors) = 0;

  /* readonly attribute AUTF8String OS; */
  NS_IMETHOD GetOS(nsACString & aOS) = 0;

  /* readonly attribute AUTF8String XPCOMABI; */
  NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) = 0;

  /* readonly attribute AUTF8String widgetToolkit; */
  NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) = 0;

  enum {
    PROCESS_TYPE_DEFAULT = 0U,
    PROCESS_TYPE_PLUGIN = 1U,
    PROCESS_TYPE_CONTENT = 2U,
    PROCESS_TYPE_IPDLUNITTEST = 3U,
    PROCESS_TYPE_GMPLUGIN = 4U
  };

  /* readonly attribute unsigned long processType; */
  NS_IMETHOD GetProcessType(uint32_t *aProcessType) = 0;

  /* readonly attribute unsigned long processID; */
  NS_IMETHOD GetProcessID(uint32_t *aProcessID) = 0;

  /* readonly attribute boolean browserTabsRemoteAutostart; */
  NS_IMETHOD GetBrowserTabsRemoteAutostart(bool *aBrowserTabsRemoteAutostart) = 0;

  /* readonly attribute boolean accessibilityEnabled; */
  NS_IMETHOD GetAccessibilityEnabled(bool *aAccessibilityEnabled) = 0;

  /* readonly attribute boolean accessibilityIsBlacklistedForE10S; */
  NS_IMETHOD GetAccessibilityIsBlacklistedForE10S(bool *aAccessibilityIsBlacklistedForE10S) = 0;

  /* readonly attribute boolean is64Bit; */
  NS_IMETHOD GetIs64Bit(bool *aIs64Bit) = 0;

  /* void invalidateCachesOnRestart (); */
  NS_IMETHOD InvalidateCachesOnRestart(void) = 0;

  /* void ensureContentProcess (); */
  NS_IMETHOD EnsureContentProcess(void) = 0;

  /* readonly attribute PRTime replacedLockTime; */
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) = 0;

  /* readonly attribute DOMString lastRunCrashID; */
  NS_IMETHOD GetLastRunCrashID(nsAString & aLastRunCrashID) = 0;

  /* readonly attribute boolean isReleaseBuild; */
  NS_IMETHOD GetIsReleaseBuild(bool *aIsReleaseBuild) = 0;

  /* readonly attribute boolean isOfficialBranding; */
  NS_IMETHOD GetIsOfficialBranding(bool *aIsOfficialBranding) = 0;

  /* readonly attribute AUTF8String defaultUpdateChannel; */
  NS_IMETHOD GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel) = 0;

  /* readonly attribute AUTF8String distributionID; */
  NS_IMETHOD GetDistributionID(nsACString & aDistributionID) = 0;

  /* readonly attribute boolean isOfficial; */
  NS_IMETHOD GetIsOfficial(bool *aIsOfficial) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULRuntime, NS_IXULRUNTIME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULRUNTIME \
  NS_IMETHOD GetInSafeMode(bool *aInSafeMode) override; \
  NS_IMETHOD GetLogConsoleErrors(bool *aLogConsoleErrors) override; \
  NS_IMETHOD SetLogConsoleErrors(bool aLogConsoleErrors) override; \
  NS_IMETHOD GetOS(nsACString & aOS) override; \
  NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) override; \
  NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) override; \
  NS_IMETHOD GetProcessType(uint32_t *aProcessType) override; \
  NS_IMETHOD GetProcessID(uint32_t *aProcessID) override; \
  NS_IMETHOD GetBrowserTabsRemoteAutostart(bool *aBrowserTabsRemoteAutostart) override; \
  NS_IMETHOD GetAccessibilityEnabled(bool *aAccessibilityEnabled) override; \
  NS_IMETHOD GetAccessibilityIsBlacklistedForE10S(bool *aAccessibilityIsBlacklistedForE10S) override; \
  NS_IMETHOD GetIs64Bit(bool *aIs64Bit) override; \
  NS_IMETHOD InvalidateCachesOnRestart(void) override; \
  NS_IMETHOD EnsureContentProcess(void) override; \
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) override; \
  NS_IMETHOD GetLastRunCrashID(nsAString & aLastRunCrashID) override; \
  NS_IMETHOD GetIsReleaseBuild(bool *aIsReleaseBuild) override; \
  NS_IMETHOD GetIsOfficialBranding(bool *aIsOfficialBranding) override; \
  NS_IMETHOD GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel) override; \
  NS_IMETHOD GetDistributionID(nsACString & aDistributionID) override; \
  NS_IMETHOD GetIsOfficial(bool *aIsOfficial) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULRUNTIME(_to) \
  NS_IMETHOD GetInSafeMode(bool *aInSafeMode) override { return _to GetInSafeMode(aInSafeMode); } \
  NS_IMETHOD GetLogConsoleErrors(bool *aLogConsoleErrors) override { return _to GetLogConsoleErrors(aLogConsoleErrors); } \
  NS_IMETHOD SetLogConsoleErrors(bool aLogConsoleErrors) override { return _to SetLogConsoleErrors(aLogConsoleErrors); } \
  NS_IMETHOD GetOS(nsACString & aOS) override { return _to GetOS(aOS); } \
  NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) override { return _to GetXPCOMABI(aXPCOMABI); } \
  NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) override { return _to GetWidgetToolkit(aWidgetToolkit); } \
  NS_IMETHOD GetProcessType(uint32_t *aProcessType) override { return _to GetProcessType(aProcessType); } \
  NS_IMETHOD GetProcessID(uint32_t *aProcessID) override { return _to GetProcessID(aProcessID); } \
  NS_IMETHOD GetBrowserTabsRemoteAutostart(bool *aBrowserTabsRemoteAutostart) override { return _to GetBrowserTabsRemoteAutostart(aBrowserTabsRemoteAutostart); } \
  NS_IMETHOD GetAccessibilityEnabled(bool *aAccessibilityEnabled) override { return _to GetAccessibilityEnabled(aAccessibilityEnabled); } \
  NS_IMETHOD GetAccessibilityIsBlacklistedForE10S(bool *aAccessibilityIsBlacklistedForE10S) override { return _to GetAccessibilityIsBlacklistedForE10S(aAccessibilityIsBlacklistedForE10S); } \
  NS_IMETHOD GetIs64Bit(bool *aIs64Bit) override { return _to GetIs64Bit(aIs64Bit); } \
  NS_IMETHOD InvalidateCachesOnRestart(void) override { return _to InvalidateCachesOnRestart(); } \
  NS_IMETHOD EnsureContentProcess(void) override { return _to EnsureContentProcess(); } \
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) override { return _to GetReplacedLockTime(aReplacedLockTime); } \
  NS_IMETHOD GetLastRunCrashID(nsAString & aLastRunCrashID) override { return _to GetLastRunCrashID(aLastRunCrashID); } \
  NS_IMETHOD GetIsReleaseBuild(bool *aIsReleaseBuild) override { return _to GetIsReleaseBuild(aIsReleaseBuild); } \
  NS_IMETHOD GetIsOfficialBranding(bool *aIsOfficialBranding) override { return _to GetIsOfficialBranding(aIsOfficialBranding); } \
  NS_IMETHOD GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel) override { return _to GetDefaultUpdateChannel(aDefaultUpdateChannel); } \
  NS_IMETHOD GetDistributionID(nsACString & aDistributionID) override { return _to GetDistributionID(aDistributionID); } \
  NS_IMETHOD GetIsOfficial(bool *aIsOfficial) override { return _to GetIsOfficial(aIsOfficial); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULRUNTIME(_to) \
  NS_IMETHOD GetInSafeMode(bool *aInSafeMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInSafeMode(aInSafeMode); } \
  NS_IMETHOD GetLogConsoleErrors(bool *aLogConsoleErrors) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLogConsoleErrors(aLogConsoleErrors); } \
  NS_IMETHOD SetLogConsoleErrors(bool aLogConsoleErrors) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLogConsoleErrors(aLogConsoleErrors); } \
  NS_IMETHOD GetOS(nsACString & aOS) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOS(aOS); } \
  NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXPCOMABI(aXPCOMABI); } \
  NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidgetToolkit(aWidgetToolkit); } \
  NS_IMETHOD GetProcessType(uint32_t *aProcessType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProcessType(aProcessType); } \
  NS_IMETHOD GetProcessID(uint32_t *aProcessID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProcessID(aProcessID); } \
  NS_IMETHOD GetBrowserTabsRemoteAutostart(bool *aBrowserTabsRemoteAutostart) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBrowserTabsRemoteAutostart(aBrowserTabsRemoteAutostart); } \
  NS_IMETHOD GetAccessibilityEnabled(bool *aAccessibilityEnabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibilityEnabled(aAccessibilityEnabled); } \
  NS_IMETHOD GetAccessibilityIsBlacklistedForE10S(bool *aAccessibilityIsBlacklistedForE10S) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessibilityIsBlacklistedForE10S(aAccessibilityIsBlacklistedForE10S); } \
  NS_IMETHOD GetIs64Bit(bool *aIs64Bit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIs64Bit(aIs64Bit); } \
  NS_IMETHOD InvalidateCachesOnRestart(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateCachesOnRestart(); } \
  NS_IMETHOD EnsureContentProcess(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureContentProcess(); } \
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReplacedLockTime(aReplacedLockTime); } \
  NS_IMETHOD GetLastRunCrashID(nsAString & aLastRunCrashID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastRunCrashID(aLastRunCrashID); } \
  NS_IMETHOD GetIsReleaseBuild(bool *aIsReleaseBuild) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsReleaseBuild(aIsReleaseBuild); } \
  NS_IMETHOD GetIsOfficialBranding(bool *aIsOfficialBranding) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsOfficialBranding(aIsOfficialBranding); } \
  NS_IMETHOD GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultUpdateChannel(aDefaultUpdateChannel); } \
  NS_IMETHOD GetDistributionID(nsACString & aDistributionID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDistributionID(aDistributionID); } \
  NS_IMETHOD GetIsOfficial(bool *aIsOfficial) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsOfficial(aIsOfficial); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULRuntime : public nsIXULRuntime
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULRUNTIME

  nsXULRuntime();

private:
  ~nsXULRuntime();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXULRuntime, nsIXULRuntime)

nsXULRuntime::nsXULRuntime()
{
  /* member initializers and constructor code */
}

nsXULRuntime::~nsXULRuntime()
{
  /* destructor code */
}

/* readonly attribute boolean inSafeMode; */
NS_IMETHODIMP nsXULRuntime::GetInSafeMode(bool *aInSafeMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean logConsoleErrors; */
NS_IMETHODIMP nsXULRuntime::GetLogConsoleErrors(bool *aLogConsoleErrors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULRuntime::SetLogConsoleErrors(bool aLogConsoleErrors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String OS; */
NS_IMETHODIMP nsXULRuntime::GetOS(nsACString & aOS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String XPCOMABI; */
NS_IMETHODIMP nsXULRuntime::GetXPCOMABI(nsACString & aXPCOMABI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String widgetToolkit; */
NS_IMETHODIMP nsXULRuntime::GetWidgetToolkit(nsACString & aWidgetToolkit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long processType; */
NS_IMETHODIMP nsXULRuntime::GetProcessType(uint32_t *aProcessType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long processID; */
NS_IMETHODIMP nsXULRuntime::GetProcessID(uint32_t *aProcessID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean browserTabsRemoteAutostart; */
NS_IMETHODIMP nsXULRuntime::GetBrowserTabsRemoteAutostart(bool *aBrowserTabsRemoteAutostart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean accessibilityEnabled; */
NS_IMETHODIMP nsXULRuntime::GetAccessibilityEnabled(bool *aAccessibilityEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean accessibilityIsBlacklistedForE10S; */
NS_IMETHODIMP nsXULRuntime::GetAccessibilityIsBlacklistedForE10S(bool *aAccessibilityIsBlacklistedForE10S)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean is64Bit; */
NS_IMETHODIMP nsXULRuntime::GetIs64Bit(bool *aIs64Bit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateCachesOnRestart (); */
NS_IMETHODIMP nsXULRuntime::InvalidateCachesOnRestart()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureContentProcess (); */
NS_IMETHODIMP nsXULRuntime::EnsureContentProcess()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime replacedLockTime; */
NS_IMETHODIMP nsXULRuntime::GetReplacedLockTime(PRTime *aReplacedLockTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastRunCrashID; */
NS_IMETHODIMP nsXULRuntime::GetLastRunCrashID(nsAString & aLastRunCrashID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isReleaseBuild; */
NS_IMETHODIMP nsXULRuntime::GetIsReleaseBuild(bool *aIsReleaseBuild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isOfficialBranding; */
NS_IMETHODIMP nsXULRuntime::GetIsOfficialBranding(bool *aIsOfficialBranding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String defaultUpdateChannel; */
NS_IMETHODIMP nsXULRuntime::GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String distributionID; */
NS_IMETHODIMP nsXULRuntime::GetDistributionID(nsACString & aDistributionID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isOfficial; */
NS_IMETHODIMP nsXULRuntime::GetIsOfficial(bool *aIsOfficial)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULRuntime_h__ */
