/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrintOptions.idl
 */

#ifndef __gen_nsIPrintOptions_h__
#define __gen_nsIPrintOptions_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPrintSettings_h__
#include "nsIPrintSettings.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
struct nsFont;
namespace mozilla {
namespace embedding {
  class PrintData;
}
}
class nsIStringEnumerator; /* forward declaration */

class nsIWebBrowserPrint; /* forward declaration */


/* starting interface:    nsIPrintOptions */
#define NS_IPRINTOPTIONS_IID_STR "2ac74034-700e-40fd-8059-81d33223af58"

#define NS_IPRINTOPTIONS_IID \
  {0x2ac74034, 0x700e, 0x40fd, \
    { 0x80, 0x59, 0x81, 0xd3, 0x32, 0x23, 0xaf, 0x58 }}

class NS_NO_VTABLE nsIPrintOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTOPTIONS_IID)

  /* void ShowPrintSetupDialog (in nsIPrintSettings aThePrintSettings); */
  NS_IMETHOD ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings) = 0;

  /* nsIPrintSettings CreatePrintSettings (); */
  NS_IMETHOD CreatePrintSettings(nsIPrintSettings * *_retval) = 0;

  /* int32_t getPrinterPrefInt (in nsIPrintSettings aPrintSettings, in wstring aPrefName); */
  NS_IMETHOD GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const char16_t * aPrefName, int32_t *_retval) = 0;

  /* void displayJobProperties (in wstring aPrinter, in nsIPrintSettings aPrintSettings, out boolean aDisplayed); */
  NS_IMETHOD DisplayJobProperties(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed) = 0;

  enum {
    kNativeDataPrintRecord = 0
  };

  /* [noscript] voidPtr GetNativeData (in short aDataType); */
  NS_IMETHOD GetNativeData(int16_t aDataType, void **_retval) = 0;

  /* [noscript] void SerializeToPrintData (in nsIPrintSettings aPrintSettings, in nsIWebBrowserPrint aWebBrowserPrint, in PrintDataPtr data); */
  NS_IMETHOD SerializeToPrintData(nsIPrintSettings *aPrintSettings, nsIWebBrowserPrint *aWebBrowserPrint, mozilla::embedding::PrintData *data) = 0;

  /* [noscript] void DeserializeToPrintSettings (in PrintDataRef data, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD DeserializeToPrintSettings(const mozilla::embedding::PrintData & data, nsIPrintSettings *aPrintSettings) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintOptions, NS_IPRINTOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTOPTIONS \
  NS_IMETHOD ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings) override; \
  NS_IMETHOD CreatePrintSettings(nsIPrintSettings * *_retval) override; \
  NS_IMETHOD GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const char16_t * aPrefName, int32_t *_retval) override; \
  NS_IMETHOD DisplayJobProperties(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed) override; \
  NS_IMETHOD GetNativeData(int16_t aDataType, void **_retval) override; \
  NS_IMETHOD SerializeToPrintData(nsIPrintSettings *aPrintSettings, nsIWebBrowserPrint *aWebBrowserPrint, mozilla::embedding::PrintData *data) override; \
  NS_IMETHOD DeserializeToPrintSettings(const mozilla::embedding::PrintData & data, nsIPrintSettings *aPrintSettings) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTOPTIONS(_to) \
  NS_IMETHOD ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings) override { return _to ShowPrintSetupDialog(aThePrintSettings); } \
  NS_IMETHOD CreatePrintSettings(nsIPrintSettings * *_retval) override { return _to CreatePrintSettings(_retval); } \
  NS_IMETHOD GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const char16_t * aPrefName, int32_t *_retval) override { return _to GetPrinterPrefInt(aPrintSettings, aPrefName, _retval); } \
  NS_IMETHOD DisplayJobProperties(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed) override { return _to DisplayJobProperties(aPrinter, aPrintSettings, aDisplayed); } \
  NS_IMETHOD GetNativeData(int16_t aDataType, void **_retval) override { return _to GetNativeData(aDataType, _retval); } \
  NS_IMETHOD SerializeToPrintData(nsIPrintSettings *aPrintSettings, nsIWebBrowserPrint *aWebBrowserPrint, mozilla::embedding::PrintData *data) override { return _to SerializeToPrintData(aPrintSettings, aWebBrowserPrint, data); } \
  NS_IMETHOD DeserializeToPrintSettings(const mozilla::embedding::PrintData & data, nsIPrintSettings *aPrintSettings) override { return _to DeserializeToPrintSettings(data, aPrintSettings); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTOPTIONS(_to) \
  NS_IMETHOD ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowPrintSetupDialog(aThePrintSettings); } \
  NS_IMETHOD CreatePrintSettings(nsIPrintSettings * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreatePrintSettings(_retval); } \
  NS_IMETHOD GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const char16_t * aPrefName, int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrinterPrefInt(aPrintSettings, aPrefName, _retval); } \
  NS_IMETHOD DisplayJobProperties(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DisplayJobProperties(aPrinter, aPrintSettings, aDisplayed); } \
  NS_IMETHOD GetNativeData(int16_t aDataType, void **_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeData(aDataType, _retval); } \
  NS_IMETHOD SerializeToPrintData(nsIPrintSettings *aPrintSettings, nsIWebBrowserPrint *aWebBrowserPrint, mozilla::embedding::PrintData *data) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SerializeToPrintData(aPrintSettings, aWebBrowserPrint, data); } \
  NS_IMETHOD DeserializeToPrintSettings(const mozilla::embedding::PrintData & data, nsIPrintSettings *aPrintSettings) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeserializeToPrintSettings(data, aPrintSettings); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintOptions : public nsIPrintOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTOPTIONS

  nsPrintOptions();

private:
  ~nsPrintOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPrintOptions, nsIPrintOptions)

nsPrintOptions::nsPrintOptions()
{
  /* member initializers and constructor code */
}

nsPrintOptions::~nsPrintOptions()
{
  /* destructor code */
}

/* void ShowPrintSetupDialog (in nsIPrintSettings aThePrintSettings); */
NS_IMETHODIMP nsPrintOptions::ShowPrintSetupDialog(nsIPrintSettings *aThePrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrintSettings CreatePrintSettings (); */
NS_IMETHODIMP nsPrintOptions::CreatePrintSettings(nsIPrintSettings * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t getPrinterPrefInt (in nsIPrintSettings aPrintSettings, in wstring aPrefName); */
NS_IMETHODIMP nsPrintOptions::GetPrinterPrefInt(nsIPrintSettings *aPrintSettings, const char16_t * aPrefName, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void displayJobProperties (in wstring aPrinter, in nsIPrintSettings aPrintSettings, out boolean aDisplayed); */
NS_IMETHODIMP nsPrintOptions::DisplayJobProperties(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings, bool *aDisplayed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] voidPtr GetNativeData (in short aDataType); */
NS_IMETHODIMP nsPrintOptions::GetNativeData(int16_t aDataType, void **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SerializeToPrintData (in nsIPrintSettings aPrintSettings, in nsIWebBrowserPrint aWebBrowserPrint, in PrintDataPtr data); */
NS_IMETHODIMP nsPrintOptions::SerializeToPrintData(nsIPrintSettings *aPrintSettings, nsIWebBrowserPrint *aWebBrowserPrint, mozilla::embedding::PrintData *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void DeserializeToPrintSettings (in PrintDataRef data, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsPrintOptions::DeserializeToPrintSettings(const mozilla::embedding::PrintData & data, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPrinterEnumerator */
#define NS_IPRINTERENUMERATOR_IID_STR "5e738fff-404c-4c94-9189-e8f2cce93e94"

#define NS_IPRINTERENUMERATOR_IID \
  {0x5e738fff, 0x404c, 0x4c94, \
    { 0x91, 0x89, 0xe8, 0xf2, 0xcc, 0xe9, 0x3e, 0x94 }}

class NS_NO_VTABLE nsIPrinterEnumerator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTERENUMERATOR_IID)

  /* readonly attribute wstring defaultPrinterName; */
  NS_IMETHOD GetDefaultPrinterName(char16_t * *aDefaultPrinterName) = 0;

  /* void initPrintSettingsFromPrinter (in wstring aPrinterName, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD InitPrintSettingsFromPrinter(const char16_t * aPrinterName, nsIPrintSettings *aPrintSettings) = 0;

  /* readonly attribute nsIStringEnumerator printerNameList; */
  NS_IMETHOD GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList) = 0;

  /* void displayPropertiesDlg (in wstring aPrinter, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD DisplayPropertiesDlg(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrinterEnumerator, NS_IPRINTERENUMERATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTERENUMERATOR \
  NS_IMETHOD GetDefaultPrinterName(char16_t * *aDefaultPrinterName) override; \
  NS_IMETHOD InitPrintSettingsFromPrinter(const char16_t * aPrinterName, nsIPrintSettings *aPrintSettings) override; \
  NS_IMETHOD GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList) override; \
  NS_IMETHOD DisplayPropertiesDlg(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTERENUMERATOR(_to) \
  NS_IMETHOD GetDefaultPrinterName(char16_t * *aDefaultPrinterName) override { return _to GetDefaultPrinterName(aDefaultPrinterName); } \
  NS_IMETHOD InitPrintSettingsFromPrinter(const char16_t * aPrinterName, nsIPrintSettings *aPrintSettings) override { return _to InitPrintSettingsFromPrinter(aPrinterName, aPrintSettings); } \
  NS_IMETHOD GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList) override { return _to GetPrinterNameList(aPrinterNameList); } \
  NS_IMETHOD DisplayPropertiesDlg(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings) override { return _to DisplayPropertiesDlg(aPrinter, aPrintSettings); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTERENUMERATOR(_to) \
  NS_IMETHOD GetDefaultPrinterName(char16_t * *aDefaultPrinterName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultPrinterName(aDefaultPrinterName); } \
  NS_IMETHOD InitPrintSettingsFromPrinter(const char16_t * aPrinterName, nsIPrintSettings *aPrintSettings) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPrintSettingsFromPrinter(aPrinterName, aPrintSettings); } \
  NS_IMETHOD GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrinterNameList(aPrinterNameList); } \
  NS_IMETHOD DisplayPropertiesDlg(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DisplayPropertiesDlg(aPrinter, aPrintSettings); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrinterEnumerator : public nsIPrinterEnumerator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTERENUMERATOR

  nsPrinterEnumerator();

private:
  ~nsPrinterEnumerator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPrinterEnumerator, nsIPrinterEnumerator)

nsPrinterEnumerator::nsPrinterEnumerator()
{
  /* member initializers and constructor code */
}

nsPrinterEnumerator::~nsPrinterEnumerator()
{
  /* destructor code */
}

/* readonly attribute wstring defaultPrinterName; */
NS_IMETHODIMP nsPrinterEnumerator::GetDefaultPrinterName(char16_t * *aDefaultPrinterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPrintSettingsFromPrinter (in wstring aPrinterName, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsPrinterEnumerator::InitPrintSettingsFromPrinter(const char16_t * aPrinterName, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStringEnumerator printerNameList; */
NS_IMETHODIMP nsPrinterEnumerator::GetPrinterNameList(nsIStringEnumerator * *aPrinterNameList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void displayPropertiesDlg (in wstring aPrinter, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsPrinterEnumerator::DisplayPropertiesDlg(const char16_t * aPrinter, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintOptions_h__ */
