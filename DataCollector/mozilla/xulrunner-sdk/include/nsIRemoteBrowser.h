/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRemoteBrowser.idl
 */

#ifndef __gen_nsIRemoteBrowser_h__
#define __gen_nsIRemoteBrowser_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRemoteBrowser */
#define NS_IREMOTEBROWSER_IID_STR "c8379366-f79f-4d25-89a6-22bec0a93d16"

#define NS_IREMOTEBROWSER_IID \
  {0xc8379366, 0xf79f, 0x4d25, \
    { 0x89, 0xa6, 0x22, 0xbe, 0xc0, 0xa9, 0x3d, 0x16 }}

class NS_NO_VTABLE nsIRemoteBrowser : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREMOTEBROWSER_IID)

  /* void enableDisableCommands (in AString action, in unsigned long enabledLength, [array, size_is (enabledLength)] in string enabledCommands, in unsigned long disabledLength, [array, size_is (disabledLength)] in string disabledCommands); */
  NS_IMETHOD EnableDisableCommands(const nsAString & action, uint32_t enabledLength, const char * *enabledCommands, uint32_t disabledLength, const char * *disabledCommands) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRemoteBrowser, NS_IREMOTEBROWSER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREMOTEBROWSER \
  NS_IMETHOD EnableDisableCommands(const nsAString & action, uint32_t enabledLength, const char * *enabledCommands, uint32_t disabledLength, const char * *disabledCommands) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREMOTEBROWSER(_to) \
  NS_IMETHOD EnableDisableCommands(const nsAString & action, uint32_t enabledLength, const char * *enabledCommands, uint32_t disabledLength, const char * *disabledCommands) override { return _to EnableDisableCommands(action, enabledLength, enabledCommands, disabledLength, disabledCommands); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREMOTEBROWSER(_to) \
  NS_IMETHOD EnableDisableCommands(const nsAString & action, uint32_t enabledLength, const char * *enabledCommands, uint32_t disabledLength, const char * *disabledCommands) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableDisableCommands(action, enabledLength, enabledCommands, disabledLength, disabledCommands); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRemoteBrowser : public nsIRemoteBrowser
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREMOTEBROWSER

  nsRemoteBrowser();

private:
  ~nsRemoteBrowser();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsRemoteBrowser, nsIRemoteBrowser)

nsRemoteBrowser::nsRemoteBrowser()
{
  /* member initializers and constructor code */
}

nsRemoteBrowser::~nsRemoteBrowser()
{
  /* destructor code */
}

/* void enableDisableCommands (in AString action, in unsigned long enabledLength, [array, size_is (enabledLength)] in string enabledCommands, in unsigned long disabledLength, [array, size_is (disabledLength)] in string disabledCommands); */
NS_IMETHODIMP nsRemoteBrowser::EnableDisableCommands(const nsAString & action, uint32_t enabledLength, const char * *enabledCommands, uint32_t disabledLength, const char * *disabledCommands)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRemoteBrowser_h__ */
