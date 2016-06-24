/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrintSettings.idl
 */

#ifndef __gen_nsIPrintSettings_h__
#define __gen_nsIPrintSettings_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsMargin.h"
#include "nsTArray.h"
class nsIPrintSession; /* forward declaration */


/* starting interface:    nsIPrintSettings */
#define NS_IPRINTSETTINGS_IID_STR "04dd3a01-a74e-44aa-8d49-2c30478fd7b8"

#define NS_IPRINTSETTINGS_IID \
  {0x04dd3a01, 0xa74e, 0x44aa, \
    { 0x8d, 0x49, 0x2c, 0x30, 0x47, 0x8f, 0xd7, 0xb8 }}

class NS_NO_VTABLE nsIPrintSettings : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTSETTINGS_IID)

  enum {
    kInitSaveOddEvenPages = 1U,
    kInitSaveHeaderLeft = 2U,
    kInitSaveHeaderCenter = 4U,
    kInitSaveHeaderRight = 8U,
    kInitSaveFooterLeft = 16U,
    kInitSaveFooterCenter = 32U,
    kInitSaveFooterRight = 64U,
    kInitSaveBGColors = 128U,
    kInitSaveBGImages = 256U,
    kInitSavePaperSize = 512U,
    kInitSaveResolution = 1024U,
    kInitSaveDuplex = 2048U,
    kInitSavePaperData = 8192U,
    kInitSaveUnwriteableMargins = 16384U,
    kInitSaveEdges = 32768U,
    kInitSaveReversed = 65536U,
    kInitSaveInColor = 131072U,
    kInitSaveOrientation = 262144U,
    kInitSavePrinterName = 1048576U,
    kInitSavePrintToFile = 2097152U,
    kInitSaveToFileName = 4194304U,
    kInitSavePageDelay = 8388608U,
    kInitSaveMargins = 16777216U,
    kInitSaveNativeData = 33554432U,
    kInitSaveShrinkToFit = 134217728U,
    kInitSaveScaling = 268435456U,
    kInitSaveAll = 4294967295U,
    kPrintOddPages = 1,
    kPrintEvenPages = 2,
    kEnableSelectionRB = 4,
    kRangeAllPages = 0,
    kRangeSpecifiedPageRange = 1,
    kRangeSelection = 2,
    kRangeFocusFrame = 3,
    kJustLeft = 0,
    kJustCenter = 1,
    kJustRight = 2,
    kUseInternalDefault = 0,
    kUseSettingWhenPossible = 1,
    kPaperSizeNativeData = 0,
    kPaperSizeDefined = 1,
    kPaperSizeInches = 0,
    kPaperSizeMillimeters = 1,
    kPortraitOrientation = 0,
    kLandscapeOrientation = 1,
    kNoFrames = 0,
    kFramesAsIs = 1,
    kSelectedFrame = 2,
    kEachFrameSep = 3,
    kFrameEnableNone = 0,
    kFrameEnableAll = 1,
    kFrameEnableAsIsAndEach = 2,
    kOutputFormatNative = 0,
    kOutputFormatPS = 1,
    kOutputFormatPDF = 2
  };

  /* void SetPrintOptions (in int32_t aType, in boolean aTurnOnOff); */
  NS_IMETHOD SetPrintOptions(int32_t aType, bool aTurnOnOff) = 0;

  /* boolean GetPrintOptions (in int32_t aType); */
  NS_IMETHOD GetPrintOptions(int32_t aType, bool *_retval) = 0;

  /* int32_t GetPrintOptionsBits (); */
  NS_IMETHOD GetPrintOptionsBits(int32_t *_retval) = 0;

  /* void SetPrintOptionsBits (in int32_t bits); */
  NS_IMETHOD SetPrintOptionsBits(int32_t bits) = 0;

  /* void GetEffectivePageSize (out double aWidth, out double aHeight); */
  NS_IMETHOD GetEffectivePageSize(double *aWidth, double *aHeight) = 0;

  /* nsIPrintSettings clone (); */
  NS_IMETHOD Clone(nsIPrintSettings * *_retval) = 0;

  /* void assign (in nsIPrintSettings aPS); */
  NS_IMETHOD Assign(nsIPrintSettings *aPS) = 0;

  /* [noscript] attribute nsIPrintSession printSession; */
  NS_IMETHOD GetPrintSession(nsIPrintSession * *aPrintSession) = 0;
  NS_IMETHOD SetPrintSession(nsIPrintSession *aPrintSession) = 0;

  /* attribute long startPageRange; */
  NS_IMETHOD GetStartPageRange(int32_t *aStartPageRange) = 0;
  NS_IMETHOD SetStartPageRange(int32_t aStartPageRange) = 0;

  /* attribute long endPageRange; */
  NS_IMETHOD GetEndPageRange(int32_t *aEndPageRange) = 0;
  NS_IMETHOD SetEndPageRange(int32_t aEndPageRange) = 0;

  /* attribute double edgeTop; */
  NS_IMETHOD GetEdgeTop(double *aEdgeTop) = 0;
  NS_IMETHOD SetEdgeTop(double aEdgeTop) = 0;

  /* attribute double edgeLeft; */
  NS_IMETHOD GetEdgeLeft(double *aEdgeLeft) = 0;
  NS_IMETHOD SetEdgeLeft(double aEdgeLeft) = 0;

  /* attribute double edgeBottom; */
  NS_IMETHOD GetEdgeBottom(double *aEdgeBottom) = 0;
  NS_IMETHOD SetEdgeBottom(double aEdgeBottom) = 0;

  /* attribute double edgeRight; */
  NS_IMETHOD GetEdgeRight(double *aEdgeRight) = 0;
  NS_IMETHOD SetEdgeRight(double aEdgeRight) = 0;

  /* attribute double marginTop; */
  NS_IMETHOD GetMarginTop(double *aMarginTop) = 0;
  NS_IMETHOD SetMarginTop(double aMarginTop) = 0;

  /* attribute double marginLeft; */
  NS_IMETHOD GetMarginLeft(double *aMarginLeft) = 0;
  NS_IMETHOD SetMarginLeft(double aMarginLeft) = 0;

  /* attribute double marginBottom; */
  NS_IMETHOD GetMarginBottom(double *aMarginBottom) = 0;
  NS_IMETHOD SetMarginBottom(double aMarginBottom) = 0;

  /* attribute double marginRight; */
  NS_IMETHOD GetMarginRight(double *aMarginRight) = 0;
  NS_IMETHOD SetMarginRight(double aMarginRight) = 0;

  /* attribute double unwriteableMarginTop; */
  NS_IMETHOD GetUnwriteableMarginTop(double *aUnwriteableMarginTop) = 0;
  NS_IMETHOD SetUnwriteableMarginTop(double aUnwriteableMarginTop) = 0;

  /* attribute double unwriteableMarginLeft; */
  NS_IMETHOD GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft) = 0;
  NS_IMETHOD SetUnwriteableMarginLeft(double aUnwriteableMarginLeft) = 0;

  /* attribute double unwriteableMarginBottom; */
  NS_IMETHOD GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom) = 0;
  NS_IMETHOD SetUnwriteableMarginBottom(double aUnwriteableMarginBottom) = 0;

  /* attribute double unwriteableMarginRight; */
  NS_IMETHOD GetUnwriteableMarginRight(double *aUnwriteableMarginRight) = 0;
  NS_IMETHOD SetUnwriteableMarginRight(double aUnwriteableMarginRight) = 0;

  /* attribute double scaling; */
  NS_IMETHOD GetScaling(double *aScaling) = 0;
  NS_IMETHOD SetScaling(double aScaling) = 0;

  /* attribute boolean printBGColors; */
  NS_IMETHOD GetPrintBGColors(bool *aPrintBGColors) = 0;
  NS_IMETHOD SetPrintBGColors(bool aPrintBGColors) = 0;

  /* attribute boolean printBGImages; */
  NS_IMETHOD GetPrintBGImages(bool *aPrintBGImages) = 0;
  NS_IMETHOD SetPrintBGImages(bool aPrintBGImages) = 0;

  /* attribute short printRange; */
  NS_IMETHOD GetPrintRange(int16_t *aPrintRange) = 0;
  NS_IMETHOD SetPrintRange(int16_t aPrintRange) = 0;

  /* attribute wstring title; */
  NS_IMETHOD GetTitle(char16_t * *aTitle) = 0;
  NS_IMETHOD SetTitle(const char16_t * aTitle) = 0;

  /* attribute wstring docURL; */
  NS_IMETHOD GetDocURL(char16_t * *aDocURL) = 0;
  NS_IMETHOD SetDocURL(const char16_t * aDocURL) = 0;

  /* attribute wstring headerStrLeft; */
  NS_IMETHOD GetHeaderStrLeft(char16_t * *aHeaderStrLeft) = 0;
  NS_IMETHOD SetHeaderStrLeft(const char16_t * aHeaderStrLeft) = 0;

  /* attribute wstring headerStrCenter; */
  NS_IMETHOD GetHeaderStrCenter(char16_t * *aHeaderStrCenter) = 0;
  NS_IMETHOD SetHeaderStrCenter(const char16_t * aHeaderStrCenter) = 0;

  /* attribute wstring headerStrRight; */
  NS_IMETHOD GetHeaderStrRight(char16_t * *aHeaderStrRight) = 0;
  NS_IMETHOD SetHeaderStrRight(const char16_t * aHeaderStrRight) = 0;

  /* attribute wstring footerStrLeft; */
  NS_IMETHOD GetFooterStrLeft(char16_t * *aFooterStrLeft) = 0;
  NS_IMETHOD SetFooterStrLeft(const char16_t * aFooterStrLeft) = 0;

  /* attribute wstring footerStrCenter; */
  NS_IMETHOD GetFooterStrCenter(char16_t * *aFooterStrCenter) = 0;
  NS_IMETHOD SetFooterStrCenter(const char16_t * aFooterStrCenter) = 0;

  /* attribute wstring footerStrRight; */
  NS_IMETHOD GetFooterStrRight(char16_t * *aFooterStrRight) = 0;
  NS_IMETHOD SetFooterStrRight(const char16_t * aFooterStrRight) = 0;

  /* attribute short howToEnableFrameUI; */
  NS_IMETHOD GetHowToEnableFrameUI(int16_t *aHowToEnableFrameUI) = 0;
  NS_IMETHOD SetHowToEnableFrameUI(int16_t aHowToEnableFrameUI) = 0;

  /* attribute boolean isCancelled; */
  NS_IMETHOD GetIsCancelled(bool *aIsCancelled) = 0;
  NS_IMETHOD SetIsCancelled(bool aIsCancelled) = 0;

  /* attribute short printFrameTypeUsage; */
  NS_IMETHOD GetPrintFrameTypeUsage(int16_t *aPrintFrameTypeUsage) = 0;
  NS_IMETHOD SetPrintFrameTypeUsage(int16_t aPrintFrameTypeUsage) = 0;

  /* attribute short printFrameType; */
  NS_IMETHOD GetPrintFrameType(int16_t *aPrintFrameType) = 0;
  NS_IMETHOD SetPrintFrameType(int16_t aPrintFrameType) = 0;

  /* attribute boolean printSilent; */
  NS_IMETHOD GetPrintSilent(bool *aPrintSilent) = 0;
  NS_IMETHOD SetPrintSilent(bool aPrintSilent) = 0;

  /* attribute boolean shrinkToFit; */
  NS_IMETHOD GetShrinkToFit(bool *aShrinkToFit) = 0;
  NS_IMETHOD SetShrinkToFit(bool aShrinkToFit) = 0;

  /* attribute boolean showPrintProgress; */
  NS_IMETHOD GetShowPrintProgress(bool *aShowPrintProgress) = 0;
  NS_IMETHOD SetShowPrintProgress(bool aShowPrintProgress) = 0;

  /* attribute wstring paperName; */
  NS_IMETHOD GetPaperName(char16_t * *aPaperName) = 0;
  NS_IMETHOD SetPaperName(const char16_t * aPaperName) = 0;

  /* attribute short paperSizeType; */
  NS_IMETHOD GetPaperSizeType(int16_t *aPaperSizeType) = 0;
  NS_IMETHOD SetPaperSizeType(int16_t aPaperSizeType) = 0;

  /* attribute short paperData; */
  NS_IMETHOD GetPaperData(int16_t *aPaperData) = 0;
  NS_IMETHOD SetPaperData(int16_t aPaperData) = 0;

  /* attribute double paperWidth; */
  NS_IMETHOD GetPaperWidth(double *aPaperWidth) = 0;
  NS_IMETHOD SetPaperWidth(double aPaperWidth) = 0;

  /* attribute double paperHeight; */
  NS_IMETHOD GetPaperHeight(double *aPaperHeight) = 0;
  NS_IMETHOD SetPaperHeight(double aPaperHeight) = 0;

  /* attribute short paperSizeUnit; */
  NS_IMETHOD GetPaperSizeUnit(int16_t *aPaperSizeUnit) = 0;
  NS_IMETHOD SetPaperSizeUnit(int16_t aPaperSizeUnit) = 0;

  /* attribute boolean printReversed; */
  NS_IMETHOD GetPrintReversed(bool *aPrintReversed) = 0;
  NS_IMETHOD SetPrintReversed(bool aPrintReversed) = 0;

  /* attribute boolean printInColor; */
  NS_IMETHOD GetPrintInColor(bool *aPrintInColor) = 0;
  NS_IMETHOD SetPrintInColor(bool aPrintInColor) = 0;

  /* attribute long orientation; */
  NS_IMETHOD GetOrientation(int32_t *aOrientation) = 0;
  NS_IMETHOD SetOrientation(int32_t aOrientation) = 0;

  /* attribute long numCopies; */
  NS_IMETHOD GetNumCopies(int32_t *aNumCopies) = 0;
  NS_IMETHOD SetNumCopies(int32_t aNumCopies) = 0;

  /* attribute wstring printerName; */
  NS_IMETHOD GetPrinterName(char16_t * *aPrinterName) = 0;
  NS_IMETHOD SetPrinterName(const char16_t * aPrinterName) = 0;

  /* attribute boolean printToFile; */
  NS_IMETHOD GetPrintToFile(bool *aPrintToFile) = 0;
  NS_IMETHOD SetPrintToFile(bool aPrintToFile) = 0;

  /* attribute wstring toFileName; */
  NS_IMETHOD GetToFileName(char16_t * *aToFileName) = 0;
  NS_IMETHOD SetToFileName(const char16_t * aToFileName) = 0;

  /* attribute short outputFormat; */
  NS_IMETHOD GetOutputFormat(int16_t *aOutputFormat) = 0;
  NS_IMETHOD SetOutputFormat(int16_t aOutputFormat) = 0;

  /* attribute long printPageDelay; */
  NS_IMETHOD GetPrintPageDelay(int32_t *aPrintPageDelay) = 0;
  NS_IMETHOD SetPrintPageDelay(int32_t aPrintPageDelay) = 0;

  /* attribute long resolution; */
  NS_IMETHOD GetResolution(int32_t *aResolution) = 0;
  NS_IMETHOD SetResolution(int32_t aResolution) = 0;

  /* attribute long duplex; */
  NS_IMETHOD GetDuplex(int32_t *aDuplex) = 0;
  NS_IMETHOD SetDuplex(int32_t aDuplex) = 0;

  /* attribute boolean isInitializedFromPrinter; */
  NS_IMETHOD GetIsInitializedFromPrinter(bool *aIsInitializedFromPrinter) = 0;
  NS_IMETHOD SetIsInitializedFromPrinter(bool aIsInitializedFromPrinter) = 0;

  /* attribute boolean isInitializedFromPrefs; */
  NS_IMETHOD GetIsInitializedFromPrefs(bool *aIsInitializedFromPrefs) = 0;
  NS_IMETHOD SetIsInitializedFromPrefs(bool aIsInitializedFromPrefs) = 0;

  /* attribute boolean persistMarginBoxSettings; */
  NS_IMETHOD GetPersistMarginBoxSettings(bool *aPersistMarginBoxSettings) = 0;
  NS_IMETHOD SetPersistMarginBoxSettings(bool aPersistMarginBoxSettings) = 0;

  /* [noscript] void SetMarginInTwips (in nsNativeIntMarginRef aMargin); */
  NS_IMETHOD SetMarginInTwips(nsIntMargin & aMargin) = 0;

  /* [noscript] void SetEdgeInTwips (in nsNativeIntMarginRef aEdge); */
  NS_IMETHOD SetEdgeInTwips(nsIntMargin & aEdge) = 0;

  /* [noscript] void GetMarginInTwips (in nsNativeIntMarginRef aMargin); */
  NS_IMETHOD GetMarginInTwips(nsIntMargin & aMargin) = 0;

  /* [noscript] void GetEdgeInTwips (in nsNativeIntMarginRef aEdge); */
  NS_IMETHOD GetEdgeInTwips(nsIntMargin & aEdge) = 0;

  /* [noscript] void SetupSilentPrinting (); */
  NS_IMETHOD SetupSilentPrinting(void) = 0;

  /* [noscript] void SetUnwriteableMarginInTwips (in nsNativeIntMarginRef aEdge); */
  NS_IMETHOD SetUnwriteableMarginInTwips(nsIntMargin & aEdge) = 0;

  /* [noscript] void GetUnwriteableMarginInTwips (in nsNativeIntMarginRef aEdge); */
  NS_IMETHOD GetUnwriteableMarginInTwips(nsIntMargin & aEdge) = 0;

  /* [noscript] void GetPageRanges (in IntegerArray aPages); */
  NS_IMETHOD GetPageRanges(nsTArray<int32_t> & aPages) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintSettings, NS_IPRINTSETTINGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTSETTINGS \
  NS_IMETHOD SetPrintOptions(int32_t aType, bool aTurnOnOff) override; \
  NS_IMETHOD GetPrintOptions(int32_t aType, bool *_retval) override; \
  NS_IMETHOD GetPrintOptionsBits(int32_t *_retval) override; \
  NS_IMETHOD SetPrintOptionsBits(int32_t bits) override; \
  NS_IMETHOD GetEffectivePageSize(double *aWidth, double *aHeight) override; \
  NS_IMETHOD Clone(nsIPrintSettings * *_retval) override; \
  NS_IMETHOD Assign(nsIPrintSettings *aPS) override; \
  NS_IMETHOD GetPrintSession(nsIPrintSession * *aPrintSession) override; \
  NS_IMETHOD SetPrintSession(nsIPrintSession *aPrintSession) override; \
  NS_IMETHOD GetStartPageRange(int32_t *aStartPageRange) override; \
  NS_IMETHOD SetStartPageRange(int32_t aStartPageRange) override; \
  NS_IMETHOD GetEndPageRange(int32_t *aEndPageRange) override; \
  NS_IMETHOD SetEndPageRange(int32_t aEndPageRange) override; \
  NS_IMETHOD GetEdgeTop(double *aEdgeTop) override; \
  NS_IMETHOD SetEdgeTop(double aEdgeTop) override; \
  NS_IMETHOD GetEdgeLeft(double *aEdgeLeft) override; \
  NS_IMETHOD SetEdgeLeft(double aEdgeLeft) override; \
  NS_IMETHOD GetEdgeBottom(double *aEdgeBottom) override; \
  NS_IMETHOD SetEdgeBottom(double aEdgeBottom) override; \
  NS_IMETHOD GetEdgeRight(double *aEdgeRight) override; \
  NS_IMETHOD SetEdgeRight(double aEdgeRight) override; \
  NS_IMETHOD GetMarginTop(double *aMarginTop) override; \
  NS_IMETHOD SetMarginTop(double aMarginTop) override; \
  NS_IMETHOD GetMarginLeft(double *aMarginLeft) override; \
  NS_IMETHOD SetMarginLeft(double aMarginLeft) override; \
  NS_IMETHOD GetMarginBottom(double *aMarginBottom) override; \
  NS_IMETHOD SetMarginBottom(double aMarginBottom) override; \
  NS_IMETHOD GetMarginRight(double *aMarginRight) override; \
  NS_IMETHOD SetMarginRight(double aMarginRight) override; \
  NS_IMETHOD GetUnwriteableMarginTop(double *aUnwriteableMarginTop) override; \
  NS_IMETHOD SetUnwriteableMarginTop(double aUnwriteableMarginTop) override; \
  NS_IMETHOD GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft) override; \
  NS_IMETHOD SetUnwriteableMarginLeft(double aUnwriteableMarginLeft) override; \
  NS_IMETHOD GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom) override; \
  NS_IMETHOD SetUnwriteableMarginBottom(double aUnwriteableMarginBottom) override; \
  NS_IMETHOD GetUnwriteableMarginRight(double *aUnwriteableMarginRight) override; \
  NS_IMETHOD SetUnwriteableMarginRight(double aUnwriteableMarginRight) override; \
  NS_IMETHOD GetScaling(double *aScaling) override; \
  NS_IMETHOD SetScaling(double aScaling) override; \
  NS_IMETHOD GetPrintBGColors(bool *aPrintBGColors) override; \
  NS_IMETHOD SetPrintBGColors(bool aPrintBGColors) override; \
  NS_IMETHOD GetPrintBGImages(bool *aPrintBGImages) override; \
  NS_IMETHOD SetPrintBGImages(bool aPrintBGImages) override; \
  NS_IMETHOD GetPrintRange(int16_t *aPrintRange) override; \
  NS_IMETHOD SetPrintRange(int16_t aPrintRange) override; \
  NS_IMETHOD GetTitle(char16_t * *aTitle) override; \
  NS_IMETHOD SetTitle(const char16_t * aTitle) override; \
  NS_IMETHOD GetDocURL(char16_t * *aDocURL) override; \
  NS_IMETHOD SetDocURL(const char16_t * aDocURL) override; \
  NS_IMETHOD GetHeaderStrLeft(char16_t * *aHeaderStrLeft) override; \
  NS_IMETHOD SetHeaderStrLeft(const char16_t * aHeaderStrLeft) override; \
  NS_IMETHOD GetHeaderStrCenter(char16_t * *aHeaderStrCenter) override; \
  NS_IMETHOD SetHeaderStrCenter(const char16_t * aHeaderStrCenter) override; \
  NS_IMETHOD GetHeaderStrRight(char16_t * *aHeaderStrRight) override; \
  NS_IMETHOD SetHeaderStrRight(const char16_t * aHeaderStrRight) override; \
  NS_IMETHOD GetFooterStrLeft(char16_t * *aFooterStrLeft) override; \
  NS_IMETHOD SetFooterStrLeft(const char16_t * aFooterStrLeft) override; \
  NS_IMETHOD GetFooterStrCenter(char16_t * *aFooterStrCenter) override; \
  NS_IMETHOD SetFooterStrCenter(const char16_t * aFooterStrCenter) override; \
  NS_IMETHOD GetFooterStrRight(char16_t * *aFooterStrRight) override; \
  NS_IMETHOD SetFooterStrRight(const char16_t * aFooterStrRight) override; \
  NS_IMETHOD GetHowToEnableFrameUI(int16_t *aHowToEnableFrameUI) override; \
  NS_IMETHOD SetHowToEnableFrameUI(int16_t aHowToEnableFrameUI) override; \
  NS_IMETHOD GetIsCancelled(bool *aIsCancelled) override; \
  NS_IMETHOD SetIsCancelled(bool aIsCancelled) override; \
  NS_IMETHOD GetPrintFrameTypeUsage(int16_t *aPrintFrameTypeUsage) override; \
  NS_IMETHOD SetPrintFrameTypeUsage(int16_t aPrintFrameTypeUsage) override; \
  NS_IMETHOD GetPrintFrameType(int16_t *aPrintFrameType) override; \
  NS_IMETHOD SetPrintFrameType(int16_t aPrintFrameType) override; \
  NS_IMETHOD GetPrintSilent(bool *aPrintSilent) override; \
  NS_IMETHOD SetPrintSilent(bool aPrintSilent) override; \
  NS_IMETHOD GetShrinkToFit(bool *aShrinkToFit) override; \
  NS_IMETHOD SetShrinkToFit(bool aShrinkToFit) override; \
  NS_IMETHOD GetShowPrintProgress(bool *aShowPrintProgress) override; \
  NS_IMETHOD SetShowPrintProgress(bool aShowPrintProgress) override; \
  NS_IMETHOD GetPaperName(char16_t * *aPaperName) override; \
  NS_IMETHOD SetPaperName(const char16_t * aPaperName) override; \
  NS_IMETHOD GetPaperSizeType(int16_t *aPaperSizeType) override; \
  NS_IMETHOD SetPaperSizeType(int16_t aPaperSizeType) override; \
  NS_IMETHOD GetPaperData(int16_t *aPaperData) override; \
  NS_IMETHOD SetPaperData(int16_t aPaperData) override; \
  NS_IMETHOD GetPaperWidth(double *aPaperWidth) override; \
  NS_IMETHOD SetPaperWidth(double aPaperWidth) override; \
  NS_IMETHOD GetPaperHeight(double *aPaperHeight) override; \
  NS_IMETHOD SetPaperHeight(double aPaperHeight) override; \
  NS_IMETHOD GetPaperSizeUnit(int16_t *aPaperSizeUnit) override; \
  NS_IMETHOD SetPaperSizeUnit(int16_t aPaperSizeUnit) override; \
  NS_IMETHOD GetPrintReversed(bool *aPrintReversed) override; \
  NS_IMETHOD SetPrintReversed(bool aPrintReversed) override; \
  NS_IMETHOD GetPrintInColor(bool *aPrintInColor) override; \
  NS_IMETHOD SetPrintInColor(bool aPrintInColor) override; \
  NS_IMETHOD GetOrientation(int32_t *aOrientation) override; \
  NS_IMETHOD SetOrientation(int32_t aOrientation) override; \
  NS_IMETHOD GetNumCopies(int32_t *aNumCopies) override; \
  NS_IMETHOD SetNumCopies(int32_t aNumCopies) override; \
  NS_IMETHOD GetPrinterName(char16_t * *aPrinterName) override; \
  NS_IMETHOD SetPrinterName(const char16_t * aPrinterName) override; \
  NS_IMETHOD GetPrintToFile(bool *aPrintToFile) override; \
  NS_IMETHOD SetPrintToFile(bool aPrintToFile) override; \
  NS_IMETHOD GetToFileName(char16_t * *aToFileName) override; \
  NS_IMETHOD SetToFileName(const char16_t * aToFileName) override; \
  NS_IMETHOD GetOutputFormat(int16_t *aOutputFormat) override; \
  NS_IMETHOD SetOutputFormat(int16_t aOutputFormat) override; \
  NS_IMETHOD GetPrintPageDelay(int32_t *aPrintPageDelay) override; \
  NS_IMETHOD SetPrintPageDelay(int32_t aPrintPageDelay) override; \
  NS_IMETHOD GetResolution(int32_t *aResolution) override; \
  NS_IMETHOD SetResolution(int32_t aResolution) override; \
  NS_IMETHOD GetDuplex(int32_t *aDuplex) override; \
  NS_IMETHOD SetDuplex(int32_t aDuplex) override; \
  NS_IMETHOD GetIsInitializedFromPrinter(bool *aIsInitializedFromPrinter) override; \
  NS_IMETHOD SetIsInitializedFromPrinter(bool aIsInitializedFromPrinter) override; \
  NS_IMETHOD GetIsInitializedFromPrefs(bool *aIsInitializedFromPrefs) override; \
  NS_IMETHOD SetIsInitializedFromPrefs(bool aIsInitializedFromPrefs) override; \
  NS_IMETHOD GetPersistMarginBoxSettings(bool *aPersistMarginBoxSettings) override; \
  NS_IMETHOD SetPersistMarginBoxSettings(bool aPersistMarginBoxSettings) override; \
  NS_IMETHOD SetMarginInTwips(nsIntMargin & aMargin) override; \
  NS_IMETHOD SetEdgeInTwips(nsIntMargin & aEdge) override; \
  NS_IMETHOD GetMarginInTwips(nsIntMargin & aMargin) override; \
  NS_IMETHOD GetEdgeInTwips(nsIntMargin & aEdge) override; \
  NS_IMETHOD SetupSilentPrinting(void) override; \
  NS_IMETHOD SetUnwriteableMarginInTwips(nsIntMargin & aEdge) override; \
  NS_IMETHOD GetUnwriteableMarginInTwips(nsIntMargin & aEdge) override; \
  NS_IMETHOD GetPageRanges(nsTArray<int32_t> & aPages) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTSETTINGS(_to) \
  NS_IMETHOD SetPrintOptions(int32_t aType, bool aTurnOnOff) override { return _to SetPrintOptions(aType, aTurnOnOff); } \
  NS_IMETHOD GetPrintOptions(int32_t aType, bool *_retval) override { return _to GetPrintOptions(aType, _retval); } \
  NS_IMETHOD GetPrintOptionsBits(int32_t *_retval) override { return _to GetPrintOptionsBits(_retval); } \
  NS_IMETHOD SetPrintOptionsBits(int32_t bits) override { return _to SetPrintOptionsBits(bits); } \
  NS_IMETHOD GetEffectivePageSize(double *aWidth, double *aHeight) override { return _to GetEffectivePageSize(aWidth, aHeight); } \
  NS_IMETHOD Clone(nsIPrintSettings * *_retval) override { return _to Clone(_retval); } \
  NS_IMETHOD Assign(nsIPrintSettings *aPS) override { return _to Assign(aPS); } \
  NS_IMETHOD GetPrintSession(nsIPrintSession * *aPrintSession) override { return _to GetPrintSession(aPrintSession); } \
  NS_IMETHOD SetPrintSession(nsIPrintSession *aPrintSession) override { return _to SetPrintSession(aPrintSession); } \
  NS_IMETHOD GetStartPageRange(int32_t *aStartPageRange) override { return _to GetStartPageRange(aStartPageRange); } \
  NS_IMETHOD SetStartPageRange(int32_t aStartPageRange) override { return _to SetStartPageRange(aStartPageRange); } \
  NS_IMETHOD GetEndPageRange(int32_t *aEndPageRange) override { return _to GetEndPageRange(aEndPageRange); } \
  NS_IMETHOD SetEndPageRange(int32_t aEndPageRange) override { return _to SetEndPageRange(aEndPageRange); } \
  NS_IMETHOD GetEdgeTop(double *aEdgeTop) override { return _to GetEdgeTop(aEdgeTop); } \
  NS_IMETHOD SetEdgeTop(double aEdgeTop) override { return _to SetEdgeTop(aEdgeTop); } \
  NS_IMETHOD GetEdgeLeft(double *aEdgeLeft) override { return _to GetEdgeLeft(aEdgeLeft); } \
  NS_IMETHOD SetEdgeLeft(double aEdgeLeft) override { return _to SetEdgeLeft(aEdgeLeft); } \
  NS_IMETHOD GetEdgeBottom(double *aEdgeBottom) override { return _to GetEdgeBottom(aEdgeBottom); } \
  NS_IMETHOD SetEdgeBottom(double aEdgeBottom) override { return _to SetEdgeBottom(aEdgeBottom); } \
  NS_IMETHOD GetEdgeRight(double *aEdgeRight) override { return _to GetEdgeRight(aEdgeRight); } \
  NS_IMETHOD SetEdgeRight(double aEdgeRight) override { return _to SetEdgeRight(aEdgeRight); } \
  NS_IMETHOD GetMarginTop(double *aMarginTop) override { return _to GetMarginTop(aMarginTop); } \
  NS_IMETHOD SetMarginTop(double aMarginTop) override { return _to SetMarginTop(aMarginTop); } \
  NS_IMETHOD GetMarginLeft(double *aMarginLeft) override { return _to GetMarginLeft(aMarginLeft); } \
  NS_IMETHOD SetMarginLeft(double aMarginLeft) override { return _to SetMarginLeft(aMarginLeft); } \
  NS_IMETHOD GetMarginBottom(double *aMarginBottom) override { return _to GetMarginBottom(aMarginBottom); } \
  NS_IMETHOD SetMarginBottom(double aMarginBottom) override { return _to SetMarginBottom(aMarginBottom); } \
  NS_IMETHOD GetMarginRight(double *aMarginRight) override { return _to GetMarginRight(aMarginRight); } \
  NS_IMETHOD SetMarginRight(double aMarginRight) override { return _to SetMarginRight(aMarginRight); } \
  NS_IMETHOD GetUnwriteableMarginTop(double *aUnwriteableMarginTop) override { return _to GetUnwriteableMarginTop(aUnwriteableMarginTop); } \
  NS_IMETHOD SetUnwriteableMarginTop(double aUnwriteableMarginTop) override { return _to SetUnwriteableMarginTop(aUnwriteableMarginTop); } \
  NS_IMETHOD GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft) override { return _to GetUnwriteableMarginLeft(aUnwriteableMarginLeft); } \
  NS_IMETHOD SetUnwriteableMarginLeft(double aUnwriteableMarginLeft) override { return _to SetUnwriteableMarginLeft(aUnwriteableMarginLeft); } \
  NS_IMETHOD GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom) override { return _to GetUnwriteableMarginBottom(aUnwriteableMarginBottom); } \
  NS_IMETHOD SetUnwriteableMarginBottom(double aUnwriteableMarginBottom) override { return _to SetUnwriteableMarginBottom(aUnwriteableMarginBottom); } \
  NS_IMETHOD GetUnwriteableMarginRight(double *aUnwriteableMarginRight) override { return _to GetUnwriteableMarginRight(aUnwriteableMarginRight); } \
  NS_IMETHOD SetUnwriteableMarginRight(double aUnwriteableMarginRight) override { return _to SetUnwriteableMarginRight(aUnwriteableMarginRight); } \
  NS_IMETHOD GetScaling(double *aScaling) override { return _to GetScaling(aScaling); } \
  NS_IMETHOD SetScaling(double aScaling) override { return _to SetScaling(aScaling); } \
  NS_IMETHOD GetPrintBGColors(bool *aPrintBGColors) override { return _to GetPrintBGColors(aPrintBGColors); } \
  NS_IMETHOD SetPrintBGColors(bool aPrintBGColors) override { return _to SetPrintBGColors(aPrintBGColors); } \
  NS_IMETHOD GetPrintBGImages(bool *aPrintBGImages) override { return _to GetPrintBGImages(aPrintBGImages); } \
  NS_IMETHOD SetPrintBGImages(bool aPrintBGImages) override { return _to SetPrintBGImages(aPrintBGImages); } \
  NS_IMETHOD GetPrintRange(int16_t *aPrintRange) override { return _to GetPrintRange(aPrintRange); } \
  NS_IMETHOD SetPrintRange(int16_t aPrintRange) override { return _to SetPrintRange(aPrintRange); } \
  NS_IMETHOD GetTitle(char16_t * *aTitle) override { return _to GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const char16_t * aTitle) override { return _to SetTitle(aTitle); } \
  NS_IMETHOD GetDocURL(char16_t * *aDocURL) override { return _to GetDocURL(aDocURL); } \
  NS_IMETHOD SetDocURL(const char16_t * aDocURL) override { return _to SetDocURL(aDocURL); } \
  NS_IMETHOD GetHeaderStrLeft(char16_t * *aHeaderStrLeft) override { return _to GetHeaderStrLeft(aHeaderStrLeft); } \
  NS_IMETHOD SetHeaderStrLeft(const char16_t * aHeaderStrLeft) override { return _to SetHeaderStrLeft(aHeaderStrLeft); } \
  NS_IMETHOD GetHeaderStrCenter(char16_t * *aHeaderStrCenter) override { return _to GetHeaderStrCenter(aHeaderStrCenter); } \
  NS_IMETHOD SetHeaderStrCenter(const char16_t * aHeaderStrCenter) override { return _to SetHeaderStrCenter(aHeaderStrCenter); } \
  NS_IMETHOD GetHeaderStrRight(char16_t * *aHeaderStrRight) override { return _to GetHeaderStrRight(aHeaderStrRight); } \
  NS_IMETHOD SetHeaderStrRight(const char16_t * aHeaderStrRight) override { return _to SetHeaderStrRight(aHeaderStrRight); } \
  NS_IMETHOD GetFooterStrLeft(char16_t * *aFooterStrLeft) override { return _to GetFooterStrLeft(aFooterStrLeft); } \
  NS_IMETHOD SetFooterStrLeft(const char16_t * aFooterStrLeft) override { return _to SetFooterStrLeft(aFooterStrLeft); } \
  NS_IMETHOD GetFooterStrCenter(char16_t * *aFooterStrCenter) override { return _to GetFooterStrCenter(aFooterStrCenter); } \
  NS_IMETHOD SetFooterStrCenter(const char16_t * aFooterStrCenter) override { return _to SetFooterStrCenter(aFooterStrCenter); } \
  NS_IMETHOD GetFooterStrRight(char16_t * *aFooterStrRight) override { return _to GetFooterStrRight(aFooterStrRight); } \
  NS_IMETHOD SetFooterStrRight(const char16_t * aFooterStrRight) override { return _to SetFooterStrRight(aFooterStrRight); } \
  NS_IMETHOD GetHowToEnableFrameUI(int16_t *aHowToEnableFrameUI) override { return _to GetHowToEnableFrameUI(aHowToEnableFrameUI); } \
  NS_IMETHOD SetHowToEnableFrameUI(int16_t aHowToEnableFrameUI) override { return _to SetHowToEnableFrameUI(aHowToEnableFrameUI); } \
  NS_IMETHOD GetIsCancelled(bool *aIsCancelled) override { return _to GetIsCancelled(aIsCancelled); } \
  NS_IMETHOD SetIsCancelled(bool aIsCancelled) override { return _to SetIsCancelled(aIsCancelled); } \
  NS_IMETHOD GetPrintFrameTypeUsage(int16_t *aPrintFrameTypeUsage) override { return _to GetPrintFrameTypeUsage(aPrintFrameTypeUsage); } \
  NS_IMETHOD SetPrintFrameTypeUsage(int16_t aPrintFrameTypeUsage) override { return _to SetPrintFrameTypeUsage(aPrintFrameTypeUsage); } \
  NS_IMETHOD GetPrintFrameType(int16_t *aPrintFrameType) override { return _to GetPrintFrameType(aPrintFrameType); } \
  NS_IMETHOD SetPrintFrameType(int16_t aPrintFrameType) override { return _to SetPrintFrameType(aPrintFrameType); } \
  NS_IMETHOD GetPrintSilent(bool *aPrintSilent) override { return _to GetPrintSilent(aPrintSilent); } \
  NS_IMETHOD SetPrintSilent(bool aPrintSilent) override { return _to SetPrintSilent(aPrintSilent); } \
  NS_IMETHOD GetShrinkToFit(bool *aShrinkToFit) override { return _to GetShrinkToFit(aShrinkToFit); } \
  NS_IMETHOD SetShrinkToFit(bool aShrinkToFit) override { return _to SetShrinkToFit(aShrinkToFit); } \
  NS_IMETHOD GetShowPrintProgress(bool *aShowPrintProgress) override { return _to GetShowPrintProgress(aShowPrintProgress); } \
  NS_IMETHOD SetShowPrintProgress(bool aShowPrintProgress) override { return _to SetShowPrintProgress(aShowPrintProgress); } \
  NS_IMETHOD GetPaperName(char16_t * *aPaperName) override { return _to GetPaperName(aPaperName); } \
  NS_IMETHOD SetPaperName(const char16_t * aPaperName) override { return _to SetPaperName(aPaperName); } \
  NS_IMETHOD GetPaperSizeType(int16_t *aPaperSizeType) override { return _to GetPaperSizeType(aPaperSizeType); } \
  NS_IMETHOD SetPaperSizeType(int16_t aPaperSizeType) override { return _to SetPaperSizeType(aPaperSizeType); } \
  NS_IMETHOD GetPaperData(int16_t *aPaperData) override { return _to GetPaperData(aPaperData); } \
  NS_IMETHOD SetPaperData(int16_t aPaperData) override { return _to SetPaperData(aPaperData); } \
  NS_IMETHOD GetPaperWidth(double *aPaperWidth) override { return _to GetPaperWidth(aPaperWidth); } \
  NS_IMETHOD SetPaperWidth(double aPaperWidth) override { return _to SetPaperWidth(aPaperWidth); } \
  NS_IMETHOD GetPaperHeight(double *aPaperHeight) override { return _to GetPaperHeight(aPaperHeight); } \
  NS_IMETHOD SetPaperHeight(double aPaperHeight) override { return _to SetPaperHeight(aPaperHeight); } \
  NS_IMETHOD GetPaperSizeUnit(int16_t *aPaperSizeUnit) override { return _to GetPaperSizeUnit(aPaperSizeUnit); } \
  NS_IMETHOD SetPaperSizeUnit(int16_t aPaperSizeUnit) override { return _to SetPaperSizeUnit(aPaperSizeUnit); } \
  NS_IMETHOD GetPrintReversed(bool *aPrintReversed) override { return _to GetPrintReversed(aPrintReversed); } \
  NS_IMETHOD SetPrintReversed(bool aPrintReversed) override { return _to SetPrintReversed(aPrintReversed); } \
  NS_IMETHOD GetPrintInColor(bool *aPrintInColor) override { return _to GetPrintInColor(aPrintInColor); } \
  NS_IMETHOD SetPrintInColor(bool aPrintInColor) override { return _to SetPrintInColor(aPrintInColor); } \
  NS_IMETHOD GetOrientation(int32_t *aOrientation) override { return _to GetOrientation(aOrientation); } \
  NS_IMETHOD SetOrientation(int32_t aOrientation) override { return _to SetOrientation(aOrientation); } \
  NS_IMETHOD GetNumCopies(int32_t *aNumCopies) override { return _to GetNumCopies(aNumCopies); } \
  NS_IMETHOD SetNumCopies(int32_t aNumCopies) override { return _to SetNumCopies(aNumCopies); } \
  NS_IMETHOD GetPrinterName(char16_t * *aPrinterName) override { return _to GetPrinterName(aPrinterName); } \
  NS_IMETHOD SetPrinterName(const char16_t * aPrinterName) override { return _to SetPrinterName(aPrinterName); } \
  NS_IMETHOD GetPrintToFile(bool *aPrintToFile) override { return _to GetPrintToFile(aPrintToFile); } \
  NS_IMETHOD SetPrintToFile(bool aPrintToFile) override { return _to SetPrintToFile(aPrintToFile); } \
  NS_IMETHOD GetToFileName(char16_t * *aToFileName) override { return _to GetToFileName(aToFileName); } \
  NS_IMETHOD SetToFileName(const char16_t * aToFileName) override { return _to SetToFileName(aToFileName); } \
  NS_IMETHOD GetOutputFormat(int16_t *aOutputFormat) override { return _to GetOutputFormat(aOutputFormat); } \
  NS_IMETHOD SetOutputFormat(int16_t aOutputFormat) override { return _to SetOutputFormat(aOutputFormat); } \
  NS_IMETHOD GetPrintPageDelay(int32_t *aPrintPageDelay) override { return _to GetPrintPageDelay(aPrintPageDelay); } \
  NS_IMETHOD SetPrintPageDelay(int32_t aPrintPageDelay) override { return _to SetPrintPageDelay(aPrintPageDelay); } \
  NS_IMETHOD GetResolution(int32_t *aResolution) override { return _to GetResolution(aResolution); } \
  NS_IMETHOD SetResolution(int32_t aResolution) override { return _to SetResolution(aResolution); } \
  NS_IMETHOD GetDuplex(int32_t *aDuplex) override { return _to GetDuplex(aDuplex); } \
  NS_IMETHOD SetDuplex(int32_t aDuplex) override { return _to SetDuplex(aDuplex); } \
  NS_IMETHOD GetIsInitializedFromPrinter(bool *aIsInitializedFromPrinter) override { return _to GetIsInitializedFromPrinter(aIsInitializedFromPrinter); } \
  NS_IMETHOD SetIsInitializedFromPrinter(bool aIsInitializedFromPrinter) override { return _to SetIsInitializedFromPrinter(aIsInitializedFromPrinter); } \
  NS_IMETHOD GetIsInitializedFromPrefs(bool *aIsInitializedFromPrefs) override { return _to GetIsInitializedFromPrefs(aIsInitializedFromPrefs); } \
  NS_IMETHOD SetIsInitializedFromPrefs(bool aIsInitializedFromPrefs) override { return _to SetIsInitializedFromPrefs(aIsInitializedFromPrefs); } \
  NS_IMETHOD GetPersistMarginBoxSettings(bool *aPersistMarginBoxSettings) override { return _to GetPersistMarginBoxSettings(aPersistMarginBoxSettings); } \
  NS_IMETHOD SetPersistMarginBoxSettings(bool aPersistMarginBoxSettings) override { return _to SetPersistMarginBoxSettings(aPersistMarginBoxSettings); } \
  NS_IMETHOD SetMarginInTwips(nsIntMargin & aMargin) override { return _to SetMarginInTwips(aMargin); } \
  NS_IMETHOD SetEdgeInTwips(nsIntMargin & aEdge) override { return _to SetEdgeInTwips(aEdge); } \
  NS_IMETHOD GetMarginInTwips(nsIntMargin & aMargin) override { return _to GetMarginInTwips(aMargin); } \
  NS_IMETHOD GetEdgeInTwips(nsIntMargin & aEdge) override { return _to GetEdgeInTwips(aEdge); } \
  NS_IMETHOD SetupSilentPrinting(void) override { return _to SetupSilentPrinting(); } \
  NS_IMETHOD SetUnwriteableMarginInTwips(nsIntMargin & aEdge) override { return _to SetUnwriteableMarginInTwips(aEdge); } \
  NS_IMETHOD GetUnwriteableMarginInTwips(nsIntMargin & aEdge) override { return _to GetUnwriteableMarginInTwips(aEdge); } \
  NS_IMETHOD GetPageRanges(nsTArray<int32_t> & aPages) override { return _to GetPageRanges(aPages); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTSETTINGS(_to) \
  NS_IMETHOD SetPrintOptions(int32_t aType, bool aTurnOnOff) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintOptions(aType, aTurnOnOff); } \
  NS_IMETHOD GetPrintOptions(int32_t aType, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintOptions(aType, _retval); } \
  NS_IMETHOD GetPrintOptionsBits(int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintOptionsBits(_retval); } \
  NS_IMETHOD SetPrintOptionsBits(int32_t bits) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintOptionsBits(bits); } \
  NS_IMETHOD GetEffectivePageSize(double *aWidth, double *aHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEffectivePageSize(aWidth, aHeight); } \
  NS_IMETHOD Clone(nsIPrintSettings * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Clone(_retval); } \
  NS_IMETHOD Assign(nsIPrintSettings *aPS) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Assign(aPS); } \
  NS_IMETHOD GetPrintSession(nsIPrintSession * *aPrintSession) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintSession(aPrintSession); } \
  NS_IMETHOD SetPrintSession(nsIPrintSession *aPrintSession) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintSession(aPrintSession); } \
  NS_IMETHOD GetStartPageRange(int32_t *aStartPageRange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartPageRange(aStartPageRange); } \
  NS_IMETHOD SetStartPageRange(int32_t aStartPageRange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartPageRange(aStartPageRange); } \
  NS_IMETHOD GetEndPageRange(int32_t *aEndPageRange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndPageRange(aEndPageRange); } \
  NS_IMETHOD SetEndPageRange(int32_t aEndPageRange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndPageRange(aEndPageRange); } \
  NS_IMETHOD GetEdgeTop(double *aEdgeTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeTop(aEdgeTop); } \
  NS_IMETHOD SetEdgeTop(double aEdgeTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeTop(aEdgeTop); } \
  NS_IMETHOD GetEdgeLeft(double *aEdgeLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeLeft(aEdgeLeft); } \
  NS_IMETHOD SetEdgeLeft(double aEdgeLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeLeft(aEdgeLeft); } \
  NS_IMETHOD GetEdgeBottom(double *aEdgeBottom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeBottom(aEdgeBottom); } \
  NS_IMETHOD SetEdgeBottom(double aEdgeBottom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeBottom(aEdgeBottom); } \
  NS_IMETHOD GetEdgeRight(double *aEdgeRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeRight(aEdgeRight); } \
  NS_IMETHOD SetEdgeRight(double aEdgeRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeRight(aEdgeRight); } \
  NS_IMETHOD GetMarginTop(double *aMarginTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginTop(aMarginTop); } \
  NS_IMETHOD SetMarginTop(double aMarginTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginTop(aMarginTop); } \
  NS_IMETHOD GetMarginLeft(double *aMarginLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginLeft(aMarginLeft); } \
  NS_IMETHOD SetMarginLeft(double aMarginLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginLeft(aMarginLeft); } \
  NS_IMETHOD GetMarginBottom(double *aMarginBottom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginBottom(aMarginBottom); } \
  NS_IMETHOD SetMarginBottom(double aMarginBottom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginBottom(aMarginBottom); } \
  NS_IMETHOD GetMarginRight(double *aMarginRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginRight(aMarginRight); } \
  NS_IMETHOD SetMarginRight(double aMarginRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginRight(aMarginRight); } \
  NS_IMETHOD GetUnwriteableMarginTop(double *aUnwriteableMarginTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginTop(aUnwriteableMarginTop); } \
  NS_IMETHOD SetUnwriteableMarginTop(double aUnwriteableMarginTop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginTop(aUnwriteableMarginTop); } \
  NS_IMETHOD GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginLeft(aUnwriteableMarginLeft); } \
  NS_IMETHOD SetUnwriteableMarginLeft(double aUnwriteableMarginLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginLeft(aUnwriteableMarginLeft); } \
  NS_IMETHOD GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginBottom(aUnwriteableMarginBottom); } \
  NS_IMETHOD SetUnwriteableMarginBottom(double aUnwriteableMarginBottom) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginBottom(aUnwriteableMarginBottom); } \
  NS_IMETHOD GetUnwriteableMarginRight(double *aUnwriteableMarginRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginRight(aUnwriteableMarginRight); } \
  NS_IMETHOD SetUnwriteableMarginRight(double aUnwriteableMarginRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginRight(aUnwriteableMarginRight); } \
  NS_IMETHOD GetScaling(double *aScaling) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScaling(aScaling); } \
  NS_IMETHOD SetScaling(double aScaling) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScaling(aScaling); } \
  NS_IMETHOD GetPrintBGColors(bool *aPrintBGColors) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintBGColors(aPrintBGColors); } \
  NS_IMETHOD SetPrintBGColors(bool aPrintBGColors) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintBGColors(aPrintBGColors); } \
  NS_IMETHOD GetPrintBGImages(bool *aPrintBGImages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintBGImages(aPrintBGImages); } \
  NS_IMETHOD SetPrintBGImages(bool aPrintBGImages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintBGImages(aPrintBGImages); } \
  NS_IMETHOD GetPrintRange(int16_t *aPrintRange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintRange(aPrintRange); } \
  NS_IMETHOD SetPrintRange(int16_t aPrintRange) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintRange(aPrintRange); } \
  NS_IMETHOD GetTitle(char16_t * *aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD SetTitle(const char16_t * aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_IMETHOD GetDocURL(char16_t * *aDocURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocURL(aDocURL); } \
  NS_IMETHOD SetDocURL(const char16_t * aDocURL) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocURL(aDocURL); } \
  NS_IMETHOD GetHeaderStrLeft(char16_t * *aHeaderStrLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeaderStrLeft(aHeaderStrLeft); } \
  NS_IMETHOD SetHeaderStrLeft(const char16_t * aHeaderStrLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeaderStrLeft(aHeaderStrLeft); } \
  NS_IMETHOD GetHeaderStrCenter(char16_t * *aHeaderStrCenter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeaderStrCenter(aHeaderStrCenter); } \
  NS_IMETHOD SetHeaderStrCenter(const char16_t * aHeaderStrCenter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeaderStrCenter(aHeaderStrCenter); } \
  NS_IMETHOD GetHeaderStrRight(char16_t * *aHeaderStrRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeaderStrRight(aHeaderStrRight); } \
  NS_IMETHOD SetHeaderStrRight(const char16_t * aHeaderStrRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeaderStrRight(aHeaderStrRight); } \
  NS_IMETHOD GetFooterStrLeft(char16_t * *aFooterStrLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFooterStrLeft(aFooterStrLeft); } \
  NS_IMETHOD SetFooterStrLeft(const char16_t * aFooterStrLeft) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFooterStrLeft(aFooterStrLeft); } \
  NS_IMETHOD GetFooterStrCenter(char16_t * *aFooterStrCenter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFooterStrCenter(aFooterStrCenter); } \
  NS_IMETHOD SetFooterStrCenter(const char16_t * aFooterStrCenter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFooterStrCenter(aFooterStrCenter); } \
  NS_IMETHOD GetFooterStrRight(char16_t * *aFooterStrRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFooterStrRight(aFooterStrRight); } \
  NS_IMETHOD SetFooterStrRight(const char16_t * aFooterStrRight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFooterStrRight(aFooterStrRight); } \
  NS_IMETHOD GetHowToEnableFrameUI(int16_t *aHowToEnableFrameUI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHowToEnableFrameUI(aHowToEnableFrameUI); } \
  NS_IMETHOD SetHowToEnableFrameUI(int16_t aHowToEnableFrameUI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHowToEnableFrameUI(aHowToEnableFrameUI); } \
  NS_IMETHOD GetIsCancelled(bool *aIsCancelled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsCancelled(aIsCancelled); } \
  NS_IMETHOD SetIsCancelled(bool aIsCancelled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsCancelled(aIsCancelled); } \
  NS_IMETHOD GetPrintFrameTypeUsage(int16_t *aPrintFrameTypeUsage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintFrameTypeUsage(aPrintFrameTypeUsage); } \
  NS_IMETHOD SetPrintFrameTypeUsage(int16_t aPrintFrameTypeUsage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintFrameTypeUsage(aPrintFrameTypeUsage); } \
  NS_IMETHOD GetPrintFrameType(int16_t *aPrintFrameType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintFrameType(aPrintFrameType); } \
  NS_IMETHOD SetPrintFrameType(int16_t aPrintFrameType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintFrameType(aPrintFrameType); } \
  NS_IMETHOD GetPrintSilent(bool *aPrintSilent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintSilent(aPrintSilent); } \
  NS_IMETHOD SetPrintSilent(bool aPrintSilent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintSilent(aPrintSilent); } \
  NS_IMETHOD GetShrinkToFit(bool *aShrinkToFit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShrinkToFit(aShrinkToFit); } \
  NS_IMETHOD SetShrinkToFit(bool aShrinkToFit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShrinkToFit(aShrinkToFit); } \
  NS_IMETHOD GetShowPrintProgress(bool *aShowPrintProgress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowPrintProgress(aShowPrintProgress); } \
  NS_IMETHOD SetShowPrintProgress(bool aShowPrintProgress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowPrintProgress(aShowPrintProgress); } \
  NS_IMETHOD GetPaperName(char16_t * *aPaperName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperName(aPaperName); } \
  NS_IMETHOD SetPaperName(const char16_t * aPaperName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperName(aPaperName); } \
  NS_IMETHOD GetPaperSizeType(int16_t *aPaperSizeType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperSizeType(aPaperSizeType); } \
  NS_IMETHOD SetPaperSizeType(int16_t aPaperSizeType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperSizeType(aPaperSizeType); } \
  NS_IMETHOD GetPaperData(int16_t *aPaperData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperData(aPaperData); } \
  NS_IMETHOD SetPaperData(int16_t aPaperData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperData(aPaperData); } \
  NS_IMETHOD GetPaperWidth(double *aPaperWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperWidth(aPaperWidth); } \
  NS_IMETHOD SetPaperWidth(double aPaperWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperWidth(aPaperWidth); } \
  NS_IMETHOD GetPaperHeight(double *aPaperHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperHeight(aPaperHeight); } \
  NS_IMETHOD SetPaperHeight(double aPaperHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperHeight(aPaperHeight); } \
  NS_IMETHOD GetPaperSizeUnit(int16_t *aPaperSizeUnit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaperSizeUnit(aPaperSizeUnit); } \
  NS_IMETHOD SetPaperSizeUnit(int16_t aPaperSizeUnit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaperSizeUnit(aPaperSizeUnit); } \
  NS_IMETHOD GetPrintReversed(bool *aPrintReversed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintReversed(aPrintReversed); } \
  NS_IMETHOD SetPrintReversed(bool aPrintReversed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintReversed(aPrintReversed); } \
  NS_IMETHOD GetPrintInColor(bool *aPrintInColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintInColor(aPrintInColor); } \
  NS_IMETHOD SetPrintInColor(bool aPrintInColor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintInColor(aPrintInColor); } \
  NS_IMETHOD GetOrientation(int32_t *aOrientation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrientation(aOrientation); } \
  NS_IMETHOD SetOrientation(int32_t aOrientation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOrientation(aOrientation); } \
  NS_IMETHOD GetNumCopies(int32_t *aNumCopies) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumCopies(aNumCopies); } \
  NS_IMETHOD SetNumCopies(int32_t aNumCopies) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNumCopies(aNumCopies); } \
  NS_IMETHOD GetPrinterName(char16_t * *aPrinterName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrinterName(aPrinterName); } \
  NS_IMETHOD SetPrinterName(const char16_t * aPrinterName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrinterName(aPrinterName); } \
  NS_IMETHOD GetPrintToFile(bool *aPrintToFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintToFile(aPrintToFile); } \
  NS_IMETHOD SetPrintToFile(bool aPrintToFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintToFile(aPrintToFile); } \
  NS_IMETHOD GetToFileName(char16_t * *aToFileName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetToFileName(aToFileName); } \
  NS_IMETHOD SetToFileName(const char16_t * aToFileName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetToFileName(aToFileName); } \
  NS_IMETHOD GetOutputFormat(int16_t *aOutputFormat) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOutputFormat(aOutputFormat); } \
  NS_IMETHOD SetOutputFormat(int16_t aOutputFormat) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOutputFormat(aOutputFormat); } \
  NS_IMETHOD GetPrintPageDelay(int32_t *aPrintPageDelay) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintPageDelay(aPrintPageDelay); } \
  NS_IMETHOD SetPrintPageDelay(int32_t aPrintPageDelay) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPrintPageDelay(aPrintPageDelay); } \
  NS_IMETHOD GetResolution(int32_t *aResolution) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResolution(aResolution); } \
  NS_IMETHOD SetResolution(int32_t aResolution) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResolution(aResolution); } \
  NS_IMETHOD GetDuplex(int32_t *aDuplex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDuplex(aDuplex); } \
  NS_IMETHOD SetDuplex(int32_t aDuplex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDuplex(aDuplex); } \
  NS_IMETHOD GetIsInitializedFromPrinter(bool *aIsInitializedFromPrinter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInitializedFromPrinter(aIsInitializedFromPrinter); } \
  NS_IMETHOD SetIsInitializedFromPrinter(bool aIsInitializedFromPrinter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsInitializedFromPrinter(aIsInitializedFromPrinter); } \
  NS_IMETHOD GetIsInitializedFromPrefs(bool *aIsInitializedFromPrefs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInitializedFromPrefs(aIsInitializedFromPrefs); } \
  NS_IMETHOD SetIsInitializedFromPrefs(bool aIsInitializedFromPrefs) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsInitializedFromPrefs(aIsInitializedFromPrefs); } \
  NS_IMETHOD GetPersistMarginBoxSettings(bool *aPersistMarginBoxSettings) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPersistMarginBoxSettings(aPersistMarginBoxSettings); } \
  NS_IMETHOD SetPersistMarginBoxSettings(bool aPersistMarginBoxSettings) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPersistMarginBoxSettings(aPersistMarginBoxSettings); } \
  NS_IMETHOD SetMarginInTwips(nsIntMargin & aMargin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginInTwips(aMargin); } \
  NS_IMETHOD SetEdgeInTwips(nsIntMargin & aEdge) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEdgeInTwips(aEdge); } \
  NS_IMETHOD GetMarginInTwips(nsIntMargin & aMargin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginInTwips(aMargin); } \
  NS_IMETHOD GetEdgeInTwips(nsIntMargin & aEdge) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEdgeInTwips(aEdge); } \
  NS_IMETHOD SetupSilentPrinting(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetupSilentPrinting(); } \
  NS_IMETHOD SetUnwriteableMarginInTwips(nsIntMargin & aEdge) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUnwriteableMarginInTwips(aEdge); } \
  NS_IMETHOD GetUnwriteableMarginInTwips(nsIntMargin & aEdge) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnwriteableMarginInTwips(aEdge); } \
  NS_IMETHOD GetPageRanges(nsTArray<int32_t> & aPages) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageRanges(aPages); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintSettings : public nsIPrintSettings
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTSETTINGS

  nsPrintSettings();

private:
  ~nsPrintSettings();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsPrintSettings, nsIPrintSettings)

nsPrintSettings::nsPrintSettings()
{
  /* member initializers and constructor code */
}

nsPrintSettings::~nsPrintSettings()
{
  /* destructor code */
}

/* void SetPrintOptions (in int32_t aType, in boolean aTurnOnOff); */
NS_IMETHODIMP nsPrintSettings::SetPrintOptions(int32_t aType, bool aTurnOnOff)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean GetPrintOptions (in int32_t aType); */
NS_IMETHODIMP nsPrintSettings::GetPrintOptions(int32_t aType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t GetPrintOptionsBits (); */
NS_IMETHODIMP nsPrintSettings::GetPrintOptionsBits(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void SetPrintOptionsBits (in int32_t bits); */
NS_IMETHODIMP nsPrintSettings::SetPrintOptionsBits(int32_t bits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetEffectivePageSize (out double aWidth, out double aHeight); */
NS_IMETHODIMP nsPrintSettings::GetEffectivePageSize(double *aWidth, double *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrintSettings clone (); */
NS_IMETHODIMP nsPrintSettings::Clone(nsIPrintSettings * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void assign (in nsIPrintSettings aPS); */
NS_IMETHODIMP nsPrintSettings::Assign(nsIPrintSettings *aPS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIPrintSession printSession; */
NS_IMETHODIMP nsPrintSettings::GetPrintSession(nsIPrintSession * *aPrintSession)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintSession(nsIPrintSession *aPrintSession)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long startPageRange; */
NS_IMETHODIMP nsPrintSettings::GetStartPageRange(int32_t *aStartPageRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetStartPageRange(int32_t aStartPageRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long endPageRange; */
NS_IMETHODIMP nsPrintSettings::GetEndPageRange(int32_t *aEndPageRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEndPageRange(int32_t aEndPageRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double edgeTop; */
NS_IMETHODIMP nsPrintSettings::GetEdgeTop(double *aEdgeTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEdgeTop(double aEdgeTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double edgeLeft; */
NS_IMETHODIMP nsPrintSettings::GetEdgeLeft(double *aEdgeLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEdgeLeft(double aEdgeLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double edgeBottom; */
NS_IMETHODIMP nsPrintSettings::GetEdgeBottom(double *aEdgeBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEdgeBottom(double aEdgeBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double edgeRight; */
NS_IMETHODIMP nsPrintSettings::GetEdgeRight(double *aEdgeRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetEdgeRight(double aEdgeRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double marginTop; */
NS_IMETHODIMP nsPrintSettings::GetMarginTop(double *aMarginTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetMarginTop(double aMarginTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double marginLeft; */
NS_IMETHODIMP nsPrintSettings::GetMarginLeft(double *aMarginLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetMarginLeft(double aMarginLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double marginBottom; */
NS_IMETHODIMP nsPrintSettings::GetMarginBottom(double *aMarginBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetMarginBottom(double aMarginBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double marginRight; */
NS_IMETHODIMP nsPrintSettings::GetMarginRight(double *aMarginRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetMarginRight(double aMarginRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double unwriteableMarginTop; */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginTop(double *aUnwriteableMarginTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginTop(double aUnwriteableMarginTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double unwriteableMarginLeft; */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginLeft(double *aUnwriteableMarginLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginLeft(double aUnwriteableMarginLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double unwriteableMarginBottom; */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginBottom(double *aUnwriteableMarginBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginBottom(double aUnwriteableMarginBottom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double unwriteableMarginRight; */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginRight(double *aUnwriteableMarginRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginRight(double aUnwriteableMarginRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double scaling; */
NS_IMETHODIMP nsPrintSettings::GetScaling(double *aScaling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetScaling(double aScaling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printBGColors; */
NS_IMETHODIMP nsPrintSettings::GetPrintBGColors(bool *aPrintBGColors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintBGColors(bool aPrintBGColors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printBGImages; */
NS_IMETHODIMP nsPrintSettings::GetPrintBGImages(bool *aPrintBGImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintBGImages(bool aPrintBGImages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short printRange; */
NS_IMETHODIMP nsPrintSettings::GetPrintRange(int16_t *aPrintRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintRange(int16_t aPrintRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring title; */
NS_IMETHODIMP nsPrintSettings::GetTitle(char16_t * *aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetTitle(const char16_t * aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring docURL; */
NS_IMETHODIMP nsPrintSettings::GetDocURL(char16_t * *aDocURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetDocURL(const char16_t * aDocURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring headerStrLeft; */
NS_IMETHODIMP nsPrintSettings::GetHeaderStrLeft(char16_t * *aHeaderStrLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetHeaderStrLeft(const char16_t * aHeaderStrLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring headerStrCenter; */
NS_IMETHODIMP nsPrintSettings::GetHeaderStrCenter(char16_t * *aHeaderStrCenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetHeaderStrCenter(const char16_t * aHeaderStrCenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring headerStrRight; */
NS_IMETHODIMP nsPrintSettings::GetHeaderStrRight(char16_t * *aHeaderStrRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetHeaderStrRight(const char16_t * aHeaderStrRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring footerStrLeft; */
NS_IMETHODIMP nsPrintSettings::GetFooterStrLeft(char16_t * *aFooterStrLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetFooterStrLeft(const char16_t * aFooterStrLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring footerStrCenter; */
NS_IMETHODIMP nsPrintSettings::GetFooterStrCenter(char16_t * *aFooterStrCenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetFooterStrCenter(const char16_t * aFooterStrCenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring footerStrRight; */
NS_IMETHODIMP nsPrintSettings::GetFooterStrRight(char16_t * *aFooterStrRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetFooterStrRight(const char16_t * aFooterStrRight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short howToEnableFrameUI; */
NS_IMETHODIMP nsPrintSettings::GetHowToEnableFrameUI(int16_t *aHowToEnableFrameUI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetHowToEnableFrameUI(int16_t aHowToEnableFrameUI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isCancelled; */
NS_IMETHODIMP nsPrintSettings::GetIsCancelled(bool *aIsCancelled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetIsCancelled(bool aIsCancelled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short printFrameTypeUsage; */
NS_IMETHODIMP nsPrintSettings::GetPrintFrameTypeUsage(int16_t *aPrintFrameTypeUsage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintFrameTypeUsage(int16_t aPrintFrameTypeUsage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short printFrameType; */
NS_IMETHODIMP nsPrintSettings::GetPrintFrameType(int16_t *aPrintFrameType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintFrameType(int16_t aPrintFrameType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printSilent; */
NS_IMETHODIMP nsPrintSettings::GetPrintSilent(bool *aPrintSilent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintSilent(bool aPrintSilent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean shrinkToFit; */
NS_IMETHODIMP nsPrintSettings::GetShrinkToFit(bool *aShrinkToFit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetShrinkToFit(bool aShrinkToFit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showPrintProgress; */
NS_IMETHODIMP nsPrintSettings::GetShowPrintProgress(bool *aShowPrintProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetShowPrintProgress(bool aShowPrintProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring paperName; */
NS_IMETHODIMP nsPrintSettings::GetPaperName(char16_t * *aPaperName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperName(const char16_t * aPaperName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short paperSizeType; */
NS_IMETHODIMP nsPrintSettings::GetPaperSizeType(int16_t *aPaperSizeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperSizeType(int16_t aPaperSizeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short paperData; */
NS_IMETHODIMP nsPrintSettings::GetPaperData(int16_t *aPaperData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperData(int16_t aPaperData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double paperWidth; */
NS_IMETHODIMP nsPrintSettings::GetPaperWidth(double *aPaperWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperWidth(double aPaperWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double paperHeight; */
NS_IMETHODIMP nsPrintSettings::GetPaperHeight(double *aPaperHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperHeight(double aPaperHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short paperSizeUnit; */
NS_IMETHODIMP nsPrintSettings::GetPaperSizeUnit(int16_t *aPaperSizeUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPaperSizeUnit(int16_t aPaperSizeUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printReversed; */
NS_IMETHODIMP nsPrintSettings::GetPrintReversed(bool *aPrintReversed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintReversed(bool aPrintReversed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printInColor; */
NS_IMETHODIMP nsPrintSettings::GetPrintInColor(bool *aPrintInColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintInColor(bool aPrintInColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long orientation; */
NS_IMETHODIMP nsPrintSettings::GetOrientation(int32_t *aOrientation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetOrientation(int32_t aOrientation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long numCopies; */
NS_IMETHODIMP nsPrintSettings::GetNumCopies(int32_t *aNumCopies)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetNumCopies(int32_t aNumCopies)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring printerName; */
NS_IMETHODIMP nsPrintSettings::GetPrinterName(char16_t * *aPrinterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrinterName(const char16_t * aPrinterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean printToFile; */
NS_IMETHODIMP nsPrintSettings::GetPrintToFile(bool *aPrintToFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintToFile(bool aPrintToFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute wstring toFileName; */
NS_IMETHODIMP nsPrintSettings::GetToFileName(char16_t * *aToFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetToFileName(const char16_t * aToFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute short outputFormat; */
NS_IMETHODIMP nsPrintSettings::GetOutputFormat(int16_t *aOutputFormat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetOutputFormat(int16_t aOutputFormat)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long printPageDelay; */
NS_IMETHODIMP nsPrintSettings::GetPrintPageDelay(int32_t *aPrintPageDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPrintPageDelay(int32_t aPrintPageDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long resolution; */
NS_IMETHODIMP nsPrintSettings::GetResolution(int32_t *aResolution)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetResolution(int32_t aResolution)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long duplex; */
NS_IMETHODIMP nsPrintSettings::GetDuplex(int32_t *aDuplex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetDuplex(int32_t aDuplex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isInitializedFromPrinter; */
NS_IMETHODIMP nsPrintSettings::GetIsInitializedFromPrinter(bool *aIsInitializedFromPrinter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetIsInitializedFromPrinter(bool aIsInitializedFromPrinter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isInitializedFromPrefs; */
NS_IMETHODIMP nsPrintSettings::GetIsInitializedFromPrefs(bool *aIsInitializedFromPrefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetIsInitializedFromPrefs(bool aIsInitializedFromPrefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean persistMarginBoxSettings; */
NS_IMETHODIMP nsPrintSettings::GetPersistMarginBoxSettings(bool *aPersistMarginBoxSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettings::SetPersistMarginBoxSettings(bool aPersistMarginBoxSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetMarginInTwips (in nsNativeIntMarginRef aMargin); */
NS_IMETHODIMP nsPrintSettings::SetMarginInTwips(nsIntMargin & aMargin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetEdgeInTwips (in nsNativeIntMarginRef aEdge); */
NS_IMETHODIMP nsPrintSettings::SetEdgeInTwips(nsIntMargin & aEdge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetMarginInTwips (in nsNativeIntMarginRef aMargin); */
NS_IMETHODIMP nsPrintSettings::GetMarginInTwips(nsIntMargin & aMargin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetEdgeInTwips (in nsNativeIntMarginRef aEdge); */
NS_IMETHODIMP nsPrintSettings::GetEdgeInTwips(nsIntMargin & aEdge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetupSilentPrinting (); */
NS_IMETHODIMP nsPrintSettings::SetupSilentPrinting()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void SetUnwriteableMarginInTwips (in nsNativeIntMarginRef aEdge); */
NS_IMETHODIMP nsPrintSettings::SetUnwriteableMarginInTwips(nsIntMargin & aEdge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetUnwriteableMarginInTwips (in nsNativeIntMarginRef aEdge); */
NS_IMETHODIMP nsPrintSettings::GetUnwriteableMarginInTwips(nsIntMargin & aEdge)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void GetPageRanges (in IntegerArray aPages); */
NS_IMETHODIMP nsPrintSettings::GetPageRanges(nsTArray<int32_t> & aPages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintSettings_h__ */
