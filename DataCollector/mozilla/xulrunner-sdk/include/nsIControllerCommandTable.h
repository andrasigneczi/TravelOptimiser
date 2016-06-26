/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIControllerCommandTable.idl
 */

#ifndef __gen_nsIControllerCommandTable_h__
#define __gen_nsIControllerCommandTable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIControllerCommand_h__
#include "nsIControllerCommand.h"
#endif

#ifndef __gen_nsICommandParams_h__
#include "nsICommandParams.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIControllerCommandTable */
#define NS_ICONTROLLERCOMMANDTABLE_IID_STR "c847f90e-b8f3-49db-a4df-8867831f2800"

#define NS_ICONTROLLERCOMMANDTABLE_IID \
  {0xc847f90e, 0xb8f3, 0x49db, \
    { 0xa4, 0xdf, 0x88, 0x67, 0x83, 0x1f, 0x28, 0x00 }}

class NS_NO_VTABLE nsIControllerCommandTable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTROLLERCOMMANDTABLE_IID)

  /* void makeImmutable (); */
  NS_IMETHOD MakeImmutable(void) = 0;

  /* void registerCommand (in string aCommandName, in nsIControllerCommand aCommand); */
  NS_IMETHOD RegisterCommand(const char * aCommandName, nsIControllerCommand *aCommand) = 0;

  /* void unregisterCommand (in string aCommandName, in nsIControllerCommand aCommand); */
  NS_IMETHOD UnregisterCommand(const char * aCommandName, nsIControllerCommand *aCommand) = 0;

  /* nsIControllerCommand findCommandHandler (in string aCommandName); */
  NS_IMETHOD FindCommandHandler(const char * aCommandName, nsIControllerCommand * *_retval) = 0;

  /* boolean isCommandEnabled (in string aCommandName, in nsISupports aCommandRefCon); */
  NS_IMETHOD IsCommandEnabled(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval) = 0;

  /* void updateCommandState (in string aCommandName, in nsISupports aCommandRefCon); */
  NS_IMETHOD UpdateCommandState(const char * aCommandName, nsISupports *aCommandRefCon) = 0;

  /* boolean supportsCommand (in string aCommandName, in nsISupports aCommandRefCon); */
  NS_IMETHOD SupportsCommand(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval) = 0;

  /* void doCommand (in string aCommandName, in nsISupports aCommandRefCon); */
  NS_IMETHOD DoCommand(const char * aCommandName, nsISupports *aCommandRefCon) = 0;

  /* void doCommandParams (in string aCommandName, in nsICommandParams aParam, in nsISupports aCommandRefCon); */
  NS_IMETHOD DoCommandParams(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) = 0;

  /* void getCommandState (in string aCommandName, in nsICommandParams aParam, in nsISupports aCommandRefCon); */
  NS_IMETHOD GetCommandState(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) = 0;

  /* void getSupportedCommands (out unsigned long count, [array, size_is (count), retval] out string commands); */
  NS_IMETHOD GetSupportedCommands(uint32_t *count, char * **commands) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIControllerCommandTable, NS_ICONTROLLERCOMMANDTABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTROLLERCOMMANDTABLE \
  NS_IMETHOD MakeImmutable(void) override; \
  NS_IMETHOD RegisterCommand(const char * aCommandName, nsIControllerCommand *aCommand) override; \
  NS_IMETHOD UnregisterCommand(const char * aCommandName, nsIControllerCommand *aCommand) override; \
  NS_IMETHOD FindCommandHandler(const char * aCommandName, nsIControllerCommand * *_retval) override; \
  NS_IMETHOD IsCommandEnabled(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval) override; \
  NS_IMETHOD UpdateCommandState(const char * aCommandName, nsISupports *aCommandRefCon) override; \
  NS_IMETHOD SupportsCommand(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval) override; \
  NS_IMETHOD DoCommand(const char * aCommandName, nsISupports *aCommandRefCon) override; \
  NS_IMETHOD DoCommandParams(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) override; \
  NS_IMETHOD GetCommandState(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) override; \
  NS_IMETHOD GetSupportedCommands(uint32_t *count, char * **commands) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTROLLERCOMMANDTABLE(_to) \
  NS_IMETHOD MakeImmutable(void) override { return _to MakeImmutable(); } \
  NS_IMETHOD RegisterCommand(const char * aCommandName, nsIControllerCommand *aCommand) override { return _to RegisterCommand(aCommandName, aCommand); } \
  NS_IMETHOD UnregisterCommand(const char * aCommandName, nsIControllerCommand *aCommand) override { return _to UnregisterCommand(aCommandName, aCommand); } \
  NS_IMETHOD FindCommandHandler(const char * aCommandName, nsIControllerCommand * *_retval) override { return _to FindCommandHandler(aCommandName, _retval); } \
  NS_IMETHOD IsCommandEnabled(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval) override { return _to IsCommandEnabled(aCommandName, aCommandRefCon, _retval); } \
  NS_IMETHOD UpdateCommandState(const char * aCommandName, nsISupports *aCommandRefCon) override { return _to UpdateCommandState(aCommandName, aCommandRefCon); } \
  NS_IMETHOD SupportsCommand(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval) override { return _to SupportsCommand(aCommandName, aCommandRefCon, _retval); } \
  NS_IMETHOD DoCommand(const char * aCommandName, nsISupports *aCommandRefCon) override { return _to DoCommand(aCommandName, aCommandRefCon); } \
  NS_IMETHOD DoCommandParams(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) override { return _to DoCommandParams(aCommandName, aParam, aCommandRefCon); } \
  NS_IMETHOD GetCommandState(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) override { return _to GetCommandState(aCommandName, aParam, aCommandRefCon); } \
  NS_IMETHOD GetSupportedCommands(uint32_t *count, char * **commands) override { return _to GetSupportedCommands(count, commands); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTROLLERCOMMANDTABLE(_to) \
  NS_IMETHOD MakeImmutable(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeImmutable(); } \
  NS_IMETHOD RegisterCommand(const char * aCommandName, nsIControllerCommand *aCommand) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterCommand(aCommandName, aCommand); } \
  NS_IMETHOD UnregisterCommand(const char * aCommandName, nsIControllerCommand *aCommand) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterCommand(aCommandName, aCommand); } \
  NS_IMETHOD FindCommandHandler(const char * aCommandName, nsIControllerCommand * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindCommandHandler(aCommandName, _retval); } \
  NS_IMETHOD IsCommandEnabled(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandEnabled(aCommandName, aCommandRefCon, _retval); } \
  NS_IMETHOD UpdateCommandState(const char * aCommandName, nsISupports *aCommandRefCon) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateCommandState(aCommandName, aCommandRefCon); } \
  NS_IMETHOD SupportsCommand(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SupportsCommand(aCommandName, aCommandRefCon, _retval); } \
  NS_IMETHOD DoCommand(const char * aCommandName, nsISupports *aCommandRefCon) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(aCommandName, aCommandRefCon); } \
  NS_IMETHOD DoCommandParams(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommandParams(aCommandName, aParam, aCommandRefCon); } \
  NS_IMETHOD GetCommandState(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommandState(aCommandName, aParam, aCommandRefCon); } \
  NS_IMETHOD GetSupportedCommands(uint32_t *count, char * **commands) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSupportedCommands(count, commands); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsControllerCommandTable : public nsIControllerCommandTable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTROLLERCOMMANDTABLE

  nsControllerCommandTable();

private:
  ~nsControllerCommandTable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsControllerCommandTable, nsIControllerCommandTable)

nsControllerCommandTable::nsControllerCommandTable()
{
  /* member initializers and constructor code */
}

nsControllerCommandTable::~nsControllerCommandTable()
{
  /* destructor code */
}

/* void makeImmutable (); */
NS_IMETHODIMP nsControllerCommandTable::MakeImmutable()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerCommand (in string aCommandName, in nsIControllerCommand aCommand); */
NS_IMETHODIMP nsControllerCommandTable::RegisterCommand(const char * aCommandName, nsIControllerCommand *aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterCommand (in string aCommandName, in nsIControllerCommand aCommand); */
NS_IMETHODIMP nsControllerCommandTable::UnregisterCommand(const char * aCommandName, nsIControllerCommand *aCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIControllerCommand findCommandHandler (in string aCommandName); */
NS_IMETHODIMP nsControllerCommandTable::FindCommandHandler(const char * aCommandName, nsIControllerCommand * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isCommandEnabled (in string aCommandName, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::IsCommandEnabled(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateCommandState (in string aCommandName, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::UpdateCommandState(const char * aCommandName, nsISupports *aCommandRefCon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean supportsCommand (in string aCommandName, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::SupportsCommand(const char * aCommandName, nsISupports *aCommandRefCon, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommand (in string aCommandName, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::DoCommand(const char * aCommandName, nsISupports *aCommandRefCon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doCommandParams (in string aCommandName, in nsICommandParams aParam, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::DoCommandParams(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCommandState (in string aCommandName, in nsICommandParams aParam, in nsISupports aCommandRefCon); */
NS_IMETHODIMP nsControllerCommandTable::GetCommandState(const char * aCommandName, nsICommandParams *aParam, nsISupports *aCommandRefCon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSupportedCommands (out unsigned long count, [array, size_is (count), retval] out string commands); */
NS_IMETHODIMP nsControllerCommandTable::GetSupportedCommands(uint32_t *count, char * **commands)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {670ee5da-6ad5-11d7-9950-000393636592}
#define NS_CONTROLLERCOMMANDTABLE_CID \
  {0x670ee5da, 0x6ad5, 0x11d7, \
    { 0x99, 0x50, 0x00, 0x03, 0x93, 0x63, 0x65, 0x92 }}
#define NS_CONTROLLERCOMMANDTABLE_CONTRACTID \
 "@mozilla.org/embedcomp/controller-command-table;1"

#endif /* __gen_nsIControllerCommandTable_h__ */
