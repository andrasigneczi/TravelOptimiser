/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAppStartup.idl
 */

#ifndef __gen_nsIAppStartup_h__
#define __gen_nsIAppStartup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICmdLineService; /* forward declaration */


/* starting interface:    nsIAppStartup */
#define NS_IAPPSTARTUP_IID_STR "6621f6d5-6c04-4a0e-9e74-447db221484e"

#define NS_IAPPSTARTUP_IID \
  {0x6621f6d5, 0x6c04, 0x4a0e, \
    { 0x9e, 0x74, 0x44, 0x7d, 0xb2, 0x21, 0x48, 0x4e }}

class NS_NO_VTABLE nsIAppStartup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSTARTUP_IID)

  /* void createHiddenWindow (); */
  NS_IMETHOD CreateHiddenWindow(void) = 0;

  /* void destroyHiddenWindow (); */
  NS_IMETHOD DestroyHiddenWindow(void) = 0;

  /* void run (); */
  NS_IMETHOD Run(void) = 0;

  /* void enterLastWindowClosingSurvivalArea (); */
  NS_IMETHOD EnterLastWindowClosingSurvivalArea(void) = 0;

  /* void exitLastWindowClosingSurvivalArea (); */
  NS_IMETHOD ExitLastWindowClosingSurvivalArea(void) = 0;

  /* readonly attribute boolean automaticSafeModeNecessary; */
  NS_IMETHOD GetAutomaticSafeModeNecessary(bool *aAutomaticSafeModeNecessary) = 0;

  /* void restartInSafeMode (in uint32_t aQuitMode); */
  NS_IMETHOD RestartInSafeMode(uint32_t aQuitMode) = 0;

  /* bool trackStartupCrashBegin (); */
  NS_IMETHOD TrackStartupCrashBegin(bool *_retval) = 0;

  /* void trackStartupCrashEnd (); */
  NS_IMETHOD TrackStartupCrashEnd(void) = 0;

  enum {
    eConsiderQuit = 1U,
    eAttemptQuit = 2U,
    eForceQuit = 3U,
    eRestart = 16U,
    eRestarti386 = 32U,
    eRestartx86_64 = 64U,
    eRestartNotSameProfile = 256U
  };

  /* void quit (in uint32_t aMode); */
  NS_IMETHOD Quit(uint32_t aMode) = 0;

  /* readonly attribute boolean shuttingDown; */
  NS_IMETHOD GetShuttingDown(bool *aShuttingDown) = 0;

  /* readonly attribute boolean startingUp; */
  NS_IMETHOD GetStartingUp(bool *aStartingUp) = 0;

  /* [noscript] void doneStartingUp (); */
  NS_IMETHOD DoneStartingUp(void) = 0;

  /* readonly attribute boolean restarting; */
  NS_IMETHOD GetRestarting(bool *aRestarting) = 0;

  /* readonly attribute boolean wasRestarted; */
  NS_IMETHOD GetWasRestarted(bool *aWasRestarted) = 0;

  /* [implicit_jscontext] jsval getStartupInfo (); */
  NS_IMETHOD GetStartupInfo(JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* attribute boolean interrupted; */
  NS_IMETHOD GetInterrupted(bool *aInterrupted) = 0;
  NS_IMETHOD SetInterrupted(bool aInterrupted) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppStartup, NS_IAPPSTARTUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSTARTUP \
  NS_IMETHOD CreateHiddenWindow(void) override; \
  NS_IMETHOD DestroyHiddenWindow(void) override; \
  NS_IMETHOD Run(void) override; \
  NS_IMETHOD EnterLastWindowClosingSurvivalArea(void) override; \
  NS_IMETHOD ExitLastWindowClosingSurvivalArea(void) override; \
  NS_IMETHOD GetAutomaticSafeModeNecessary(bool *aAutomaticSafeModeNecessary) override; \
  NS_IMETHOD RestartInSafeMode(uint32_t aQuitMode) override; \
  NS_IMETHOD TrackStartupCrashBegin(bool *_retval) override; \
  NS_IMETHOD TrackStartupCrashEnd(void) override; \
  NS_IMETHOD Quit(uint32_t aMode) override; \
  NS_IMETHOD GetShuttingDown(bool *aShuttingDown) override; \
  NS_IMETHOD GetStartingUp(bool *aStartingUp) override; \
  NS_IMETHOD DoneStartingUp(void) override; \
  NS_IMETHOD GetRestarting(bool *aRestarting) override; \
  NS_IMETHOD GetWasRestarted(bool *aWasRestarted) override; \
  NS_IMETHOD GetStartupInfo(JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetInterrupted(bool *aInterrupted) override; \
  NS_IMETHOD SetInterrupted(bool aInterrupted) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSTARTUP(_to) \
  NS_IMETHOD CreateHiddenWindow(void) override { return _to CreateHiddenWindow(); } \
  NS_IMETHOD DestroyHiddenWindow(void) override { return _to DestroyHiddenWindow(); } \
  NS_IMETHOD Run(void) override { return _to Run(); } \
  NS_IMETHOD EnterLastWindowClosingSurvivalArea(void) override { return _to EnterLastWindowClosingSurvivalArea(); } \
  NS_IMETHOD ExitLastWindowClosingSurvivalArea(void) override { return _to ExitLastWindowClosingSurvivalArea(); } \
  NS_IMETHOD GetAutomaticSafeModeNecessary(bool *aAutomaticSafeModeNecessary) override { return _to GetAutomaticSafeModeNecessary(aAutomaticSafeModeNecessary); } \
  NS_IMETHOD RestartInSafeMode(uint32_t aQuitMode) override { return _to RestartInSafeMode(aQuitMode); } \
  NS_IMETHOD TrackStartupCrashBegin(bool *_retval) override { return _to TrackStartupCrashBegin(_retval); } \
  NS_IMETHOD TrackStartupCrashEnd(void) override { return _to TrackStartupCrashEnd(); } \
  NS_IMETHOD Quit(uint32_t aMode) override { return _to Quit(aMode); } \
  NS_IMETHOD GetShuttingDown(bool *aShuttingDown) override { return _to GetShuttingDown(aShuttingDown); } \
  NS_IMETHOD GetStartingUp(bool *aStartingUp) override { return _to GetStartingUp(aStartingUp); } \
  NS_IMETHOD DoneStartingUp(void) override { return _to DoneStartingUp(); } \
  NS_IMETHOD GetRestarting(bool *aRestarting) override { return _to GetRestarting(aRestarting); } \
  NS_IMETHOD GetWasRestarted(bool *aWasRestarted) override { return _to GetWasRestarted(aWasRestarted); } \
  NS_IMETHOD GetStartupInfo(JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetStartupInfo(cx, _retval); } \
  NS_IMETHOD GetInterrupted(bool *aInterrupted) override { return _to GetInterrupted(aInterrupted); } \
  NS_IMETHOD SetInterrupted(bool aInterrupted) override { return _to SetInterrupted(aInterrupted); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSTARTUP(_to) \
  NS_IMETHOD CreateHiddenWindow(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateHiddenWindow(); } \
  NS_IMETHOD DestroyHiddenWindow(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DestroyHiddenWindow(); } \
  NS_IMETHOD Run(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Run(); } \
  NS_IMETHOD EnterLastWindowClosingSurvivalArea(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnterLastWindowClosingSurvivalArea(); } \
  NS_IMETHOD ExitLastWindowClosingSurvivalArea(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExitLastWindowClosingSurvivalArea(); } \
  NS_IMETHOD GetAutomaticSafeModeNecessary(bool *aAutomaticSafeModeNecessary) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutomaticSafeModeNecessary(aAutomaticSafeModeNecessary); } \
  NS_IMETHOD RestartInSafeMode(uint32_t aQuitMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RestartInSafeMode(aQuitMode); } \
  NS_IMETHOD TrackStartupCrashBegin(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TrackStartupCrashBegin(_retval); } \
  NS_IMETHOD TrackStartupCrashEnd(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->TrackStartupCrashEnd(); } \
  NS_IMETHOD Quit(uint32_t aMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Quit(aMode); } \
  NS_IMETHOD GetShuttingDown(bool *aShuttingDown) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShuttingDown(aShuttingDown); } \
  NS_IMETHOD GetStartingUp(bool *aStartingUp) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartingUp(aStartingUp); } \
  NS_IMETHOD DoneStartingUp(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DoneStartingUp(); } \
  NS_IMETHOD GetRestarting(bool *aRestarting) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRestarting(aRestarting); } \
  NS_IMETHOD GetWasRestarted(bool *aWasRestarted) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWasRestarted(aWasRestarted); } \
  NS_IMETHOD GetStartupInfo(JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartupInfo(cx, _retval); } \
  NS_IMETHOD GetInterrupted(bool *aInterrupted) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterrupted(aInterrupted); } \
  NS_IMETHOD SetInterrupted(bool aInterrupted) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInterrupted(aInterrupted); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppStartup : public nsIAppStartup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSTARTUP

  nsAppStartup();

private:
  ~nsAppStartup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAppStartup, nsIAppStartup)

nsAppStartup::nsAppStartup()
{
  /* member initializers and constructor code */
}

nsAppStartup::~nsAppStartup()
{
  /* destructor code */
}

/* void createHiddenWindow (); */
NS_IMETHODIMP nsAppStartup::CreateHiddenWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroyHiddenWindow (); */
NS_IMETHODIMP nsAppStartup::DestroyHiddenWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void run (); */
NS_IMETHODIMP nsAppStartup::Run()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enterLastWindowClosingSurvivalArea (); */
NS_IMETHODIMP nsAppStartup::EnterLastWindowClosingSurvivalArea()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exitLastWindowClosingSurvivalArea (); */
NS_IMETHODIMP nsAppStartup::ExitLastWindowClosingSurvivalArea()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean automaticSafeModeNecessary; */
NS_IMETHODIMP nsAppStartup::GetAutomaticSafeModeNecessary(bool *aAutomaticSafeModeNecessary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restartInSafeMode (in uint32_t aQuitMode); */
NS_IMETHODIMP nsAppStartup::RestartInSafeMode(uint32_t aQuitMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool trackStartupCrashBegin (); */
NS_IMETHODIMP nsAppStartup::TrackStartupCrashBegin(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void trackStartupCrashEnd (); */
NS_IMETHODIMP nsAppStartup::TrackStartupCrashEnd()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void quit (in uint32_t aMode); */
NS_IMETHODIMP nsAppStartup::Quit(uint32_t aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean shuttingDown; */
NS_IMETHODIMP nsAppStartup::GetShuttingDown(bool *aShuttingDown)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean startingUp; */
NS_IMETHODIMP nsAppStartup::GetStartingUp(bool *aStartingUp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void doneStartingUp (); */
NS_IMETHODIMP nsAppStartup::DoneStartingUp()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean restarting; */
NS_IMETHODIMP nsAppStartup::GetRestarting(bool *aRestarting)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean wasRestarted; */
NS_IMETHODIMP nsAppStartup::GetWasRestarted(bool *aWasRestarted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getStartupInfo (); */
NS_IMETHODIMP nsAppStartup::GetStartupInfo(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean interrupted; */
NS_IMETHODIMP nsAppStartup::GetInterrupted(bool *aInterrupted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAppStartup::SetInterrupted(bool aInterrupted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppStartup_h__ */
