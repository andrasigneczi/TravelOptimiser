/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAppShell.idl
 */

#ifndef __gen_nsIAppShell_h__
#define __gen_nsIAppShell_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRunnable; /* forward declaration */

template <class T> struct already_AddRefed;

/* starting interface:    nsIAppShell */
#define NS_IAPPSHELL_IID_STR "3d09973e-3975-4fd4-b103-276300cc8437"

#define NS_IAPPSHELL_IID \
  {0x3d09973e, 0x3975, 0x4fd4, \
    { 0xb1, 0x03, 0x27, 0x63, 0x00, 0xcc, 0x84, 0x37 }}

class nsIAppShell : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSHELL_IID)

  /* void run (); */
  NS_IMETHOD Run(void) = 0;

  /* void exit (); */
  NS_IMETHOD Exit(void) = 0;

  /* void favorPerformanceHint (in boolean favorPerfOverStarvation, in unsigned long starvationDelay); */
  NS_IMETHOD FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay) = 0;

  /* void suspendNative (); */
  NS_IMETHOD SuspendNative(void) = 0;

  /* void resumeNative (); */
  NS_IMETHOD ResumeNative(void) = 0;

  /* readonly attribute unsigned long eventloopNestingLevel; */
  NS_IMETHOD GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel) = 0;

   /**
   * Add a "synchronous section", in the form of an nsIRunnable run once the
   * event loop has reached a "stable state". |runnable| must not cause any
   * queued events to be processed (i.e. must not spin the event loop). We've
   * reached a stable state when the currently executing task/event has
   * finished, see:
   * http://www.whatwg.org/specs/web-apps/current-work/multipage/webappapis.html#synchronous-section
   * In practice this runs aRunnable once the currently executing event
   * finishes. If called multiple times per task/event, all the runnables will
   * be executed, in the order in which runInStableState() was called.
   */
  virtual void RunInStableState(already_AddRefed<nsIRunnable> runnable) = 0;
  /* void runBeforeNextEvent (in nsIRunnable runnable); */
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppShell, NS_IAPPSHELL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSHELL \
  NS_IMETHOD Run(void) override; \
  NS_IMETHOD Exit(void) override; \
  NS_IMETHOD FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay) override; \
  NS_IMETHOD SuspendNative(void) override; \
  NS_IMETHOD ResumeNative(void) override; \
  NS_IMETHOD GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel) override; \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSHELL(_to) \
  NS_IMETHOD Run(void) override { return _to Run(); } \
  NS_IMETHOD Exit(void) override { return _to Exit(); } \
  NS_IMETHOD FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay) override { return _to FavorPerformanceHint(favorPerfOverStarvation, starvationDelay); } \
  NS_IMETHOD SuspendNative(void) override { return _to SuspendNative(); } \
  NS_IMETHOD ResumeNative(void) override { return _to ResumeNative(); } \
  NS_IMETHOD GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel) override { return _to GetEventloopNestingLevel(aEventloopNestingLevel); } \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) override { return _to RunBeforeNextEvent(runnable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSHELL(_to) \
  NS_IMETHOD Run(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Run(); } \
  NS_IMETHOD Exit(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Exit(); } \
  NS_IMETHOD FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FavorPerformanceHint(favorPerfOverStarvation, starvationDelay); } \
  NS_IMETHOD SuspendNative(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SuspendNative(); } \
  NS_IMETHOD ResumeNative(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeNative(); } \
  NS_IMETHOD GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventloopNestingLevel(aEventloopNestingLevel); } \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RunBeforeNextEvent(runnable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppShell : public nsIAppShell
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSHELL

  nsAppShell();

private:
  ~nsAppShell();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAppShell, nsIAppShell)

nsAppShell::nsAppShell()
{
  /* member initializers and constructor code */
}

nsAppShell::~nsAppShell()
{
  /* destructor code */
}

/* void run (); */
NS_IMETHODIMP nsAppShell::Run()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exit (); */
NS_IMETHODIMP nsAppShell::Exit()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void favorPerformanceHint (in boolean favorPerfOverStarvation, in unsigned long starvationDelay); */
NS_IMETHODIMP nsAppShell::FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspendNative (); */
NS_IMETHODIMP nsAppShell::SuspendNative()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeNative (); */
NS_IMETHODIMP nsAppShell::ResumeNative()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long eventloopNestingLevel; */
NS_IMETHODIMP nsAppShell::GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runBeforeNextEvent (in nsIRunnable runnable); */
NS_IMETHODIMP nsAppShell::RunBeforeNextEvent(nsIRunnable *runnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppShell_h__ */
