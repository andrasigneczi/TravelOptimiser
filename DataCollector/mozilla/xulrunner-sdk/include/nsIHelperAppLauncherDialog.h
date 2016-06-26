/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHelperAppLauncherDialog.idl
 */

#ifndef __gen_nsIHelperAppLauncherDialog_h__
#define __gen_nsIHelperAppLauncherDialog_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHelperAppLauncher; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsIHelperAppLauncherDialog */
#define NS_IHELPERAPPLAUNCHERDIALOG_IID_STR "bfc739f3-8d75-4034-a6f8-1039a5996bad"

#define NS_IHELPERAPPLAUNCHERDIALOG_IID \
  {0xbfc739f3, 0x8d75, 0x4034, \
    { 0xa6, 0xf8, 0x10, 0x39, 0xa5, 0x99, 0x6b, 0xad }}

class NS_NO_VTABLE nsIHelperAppLauncherDialog : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHELPERAPPLAUNCHERDIALOG_IID)

  enum {
    REASON_CANTHANDLE = 0U,
    REASON_SERVERREQUEST = 1U,
    REASON_TYPESNIFFED = 2U
  };

  /* void show (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in unsigned long aReason); */
  NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason) = 0;

  /* void promptForSaveToFileAsync (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in wstring aDefaultFileName, in wstring aSuggestedFileExtension, in boolean aForcePrompt); */
  NS_IMETHOD PromptForSaveToFileAsync(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const char16_t * aDefaultFileName, const char16_t * aSuggestedFileExtension, bool aForcePrompt) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHelperAppLauncherDialog, NS_IHELPERAPPLAUNCHERDIALOG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHELPERAPPLAUNCHERDIALOG \
  NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason) override; \
  NS_IMETHOD PromptForSaveToFileAsync(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const char16_t * aDefaultFileName, const char16_t * aSuggestedFileExtension, bool aForcePrompt) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHELPERAPPLAUNCHERDIALOG(_to) \
  NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason) override { return _to Show(aLauncher, aWindowContext, aReason); } \
  NS_IMETHOD PromptForSaveToFileAsync(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const char16_t * aDefaultFileName, const char16_t * aSuggestedFileExtension, bool aForcePrompt) override { return _to PromptForSaveToFileAsync(aLauncher, aWindowContext, aDefaultFileName, aSuggestedFileExtension, aForcePrompt); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHELPERAPPLAUNCHERDIALOG(_to) \
  NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(aLauncher, aWindowContext, aReason); } \
  NS_IMETHOD PromptForSaveToFileAsync(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const char16_t * aDefaultFileName, const char16_t * aSuggestedFileExtension, bool aForcePrompt) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptForSaveToFileAsync(aLauncher, aWindowContext, aDefaultFileName, aSuggestedFileExtension, aForcePrompt); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHelperAppLauncherDialog : public nsIHelperAppLauncherDialog
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHELPERAPPLAUNCHERDIALOG

  nsHelperAppLauncherDialog();

private:
  ~nsHelperAppLauncherDialog();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsHelperAppLauncherDialog, nsIHelperAppLauncherDialog)

nsHelperAppLauncherDialog::nsHelperAppLauncherDialog()
{
  /* member initializers and constructor code */
}

nsHelperAppLauncherDialog::~nsHelperAppLauncherDialog()
{
  /* destructor code */
}

/* void show (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in unsigned long aReason); */
NS_IMETHODIMP nsHelperAppLauncherDialog::Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void promptForSaveToFileAsync (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in wstring aDefaultFileName, in wstring aSuggestedFileExtension, in boolean aForcePrompt); */
NS_IMETHODIMP nsHelperAppLauncherDialog::PromptForSaveToFileAsync(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const char16_t * aDefaultFileName, const char16_t * aSuggestedFileExtension, bool aForcePrompt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_HELPERAPPLAUNCHERDLG_CONTRACTID    "@mozilla.org/helperapplauncherdialog;1"

#endif /* __gen_nsIHelperAppLauncherDialog_h__ */
