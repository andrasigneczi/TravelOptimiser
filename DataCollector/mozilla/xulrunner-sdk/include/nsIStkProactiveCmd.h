/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStkProactiveCmd.idl
 */

#ifndef __gen_nsIStkProactiveCmd_h__
#define __gen_nsIStkProactiveCmd_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStkDuration */
#define NS_ISTKDURATION_IID_STR "1510cf0c-5db6-11e4-9869-6bf419e26642"

#define NS_ISTKDURATION_IID \
  {0x1510cf0c, 0x5db6, 0x11e4, \
    { 0x98, 0x69, 0x6b, 0xf4, 0x19, 0xe2, 0x66, 0x42 }}

class NS_NO_VTABLE nsIStkDuration : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKDURATION_IID)

  /* readonly attribute unsigned short timeUnit; */
  NS_IMETHOD GetTimeUnit(uint16_t *aTimeUnit) = 0;

  /* readonly attribute unsigned short timeInterval; */
  NS_IMETHOD GetTimeInterval(uint16_t *aTimeInterval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkDuration, NS_ISTKDURATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKDURATION \
  NS_IMETHOD GetTimeUnit(uint16_t *aTimeUnit) override; \
  NS_IMETHOD GetTimeInterval(uint16_t *aTimeInterval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKDURATION(_to) \
  NS_IMETHOD GetTimeUnit(uint16_t *aTimeUnit) override { return _to GetTimeUnit(aTimeUnit); } \
  NS_IMETHOD GetTimeInterval(uint16_t *aTimeInterval) override { return _to GetTimeInterval(aTimeInterval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKDURATION(_to) \
  NS_IMETHOD GetTimeUnit(uint16_t *aTimeUnit) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeUnit(aTimeUnit); } \
  NS_IMETHOD GetTimeInterval(uint16_t *aTimeInterval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeInterval(aTimeInterval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkDuration : public nsIStkDuration
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKDURATION

  nsStkDuration();

private:
  ~nsStkDuration();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkDuration, nsIStkDuration)

nsStkDuration::nsStkDuration()
{
  /* member initializers and constructor code */
}

nsStkDuration::~nsStkDuration()
{
  /* destructor code */
}

/* readonly attribute unsigned short timeUnit; */
NS_IMETHODIMP nsStkDuration::GetTimeUnit(uint16_t *aTimeUnit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short timeInterval; */
NS_IMETHODIMP nsStkDuration::GetTimeInterval(uint16_t *aTimeInterval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkIcon */
#define NS_ISTKICON_IID_STR "c7b6e57a-696d-11e4-bcaa-bfe8386e75a9"

#define NS_ISTKICON_IID \
  {0xc7b6e57a, 0x696d, 0x11e4, \
    { 0xbc, 0xaa, 0xbf, 0xe8, 0x38, 0x6e, 0x75, 0xa9 }}

class NS_NO_VTABLE nsIStkIcon : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKICON_IID)

  enum {
    CODING_SCHEME_BASIC = 17U,
    CODING_SCHEME_COLOR = 33U,
    CODING_SCHEME_COLOR_TRANSPARENCY = 34U
  };

  /* readonly attribute unsigned long width; */
  NS_IMETHOD GetWidth(uint32_t *aWidth) = 0;

  /* readonly attribute unsigned long height; */
  NS_IMETHOD GetHeight(uint32_t *aHeight) = 0;

  /* readonly attribute unsigned short codingScheme; */
  NS_IMETHOD GetCodingScheme(uint16_t *aCodingScheme) = 0;

  /* void getPixels ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out unsigned long aPixels); */
  NS_IMETHOD GetPixels(uint32_t *aCount, uint32_t **aPixels) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkIcon, NS_ISTKICON_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKICON \
  NS_IMETHOD GetWidth(uint32_t *aWidth) override; \
  NS_IMETHOD GetHeight(uint32_t *aHeight) override; \
  NS_IMETHOD GetCodingScheme(uint16_t *aCodingScheme) override; \
  NS_IMETHOD GetPixels(uint32_t *aCount, uint32_t **aPixels) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKICON(_to) \
  NS_IMETHOD GetWidth(uint32_t *aWidth) override { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) override { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetCodingScheme(uint16_t *aCodingScheme) override { return _to GetCodingScheme(aCodingScheme); } \
  NS_IMETHOD GetPixels(uint32_t *aCount, uint32_t **aPixels) override { return _to GetPixels(aCount, aPixels); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKICON(_to) \
  NS_IMETHOD GetWidth(uint32_t *aWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetCodingScheme(uint16_t *aCodingScheme) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCodingScheme(aCodingScheme); } \
  NS_IMETHOD GetPixels(uint32_t *aCount, uint32_t **aPixels) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPixels(aCount, aPixels); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkIcon : public nsIStkIcon
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKICON

  nsStkIcon();

private:
  ~nsStkIcon();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkIcon, nsIStkIcon)

nsStkIcon::nsStkIcon()
{
  /* member initializers and constructor code */
}

nsStkIcon::~nsStkIcon()
{
  /* destructor code */
}

/* readonly attribute unsigned long width; */
NS_IMETHODIMP nsStkIcon::GetWidth(uint32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long height; */
NS_IMETHODIMP nsStkIcon::GetHeight(uint32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short codingScheme; */
NS_IMETHODIMP nsStkIcon::GetCodingScheme(uint16_t *aCodingScheme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPixels ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out unsigned long aPixels); */
NS_IMETHODIMP nsStkIcon::GetPixels(uint32_t *aCount, uint32_t **aPixels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkIconInfo */
#define NS_ISTKICONINFO_IID_STR "4a6d173e-5e8b-11e4-9d78-071bb3d6ba8f"

#define NS_ISTKICONINFO_IID \
  {0x4a6d173e, 0x5e8b, 0x11e4, \
    { 0x9d, 0x78, 0x07, 0x1b, 0xb3, 0xd6, 0xba, 0x8f }}

class NS_NO_VTABLE nsIStkIconInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKICONINFO_IID)

  /* readonly attribute boolean iconSelfExplanatory; */
  NS_IMETHOD GetIconSelfExplanatory(bool *aIconSelfExplanatory) = 0;

  /* void getIcons ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIStkIcon aIcons); */
  NS_IMETHOD GetIcons(uint32_t *aCount, nsIStkIcon * **aIcons) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkIconInfo, NS_ISTKICONINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKICONINFO \
  NS_IMETHOD GetIconSelfExplanatory(bool *aIconSelfExplanatory) override; \
  NS_IMETHOD GetIcons(uint32_t *aCount, nsIStkIcon * **aIcons) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKICONINFO(_to) \
  NS_IMETHOD GetIconSelfExplanatory(bool *aIconSelfExplanatory) override { return _to GetIconSelfExplanatory(aIconSelfExplanatory); } \
  NS_IMETHOD GetIcons(uint32_t *aCount, nsIStkIcon * **aIcons) override { return _to GetIcons(aCount, aIcons); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKICONINFO(_to) \
  NS_IMETHOD GetIconSelfExplanatory(bool *aIconSelfExplanatory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconSelfExplanatory(aIconSelfExplanatory); } \
  NS_IMETHOD GetIcons(uint32_t *aCount, nsIStkIcon * **aIcons) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIcons(aCount, aIcons); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkIconInfo : public nsIStkIconInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKICONINFO

  nsStkIconInfo();

private:
  ~nsStkIconInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkIconInfo, nsIStkIconInfo)

nsStkIconInfo::nsStkIconInfo()
{
  /* member initializers and constructor code */
}

nsStkIconInfo::~nsStkIconInfo()
{
  /* destructor code */
}

/* readonly attribute boolean iconSelfExplanatory; */
NS_IMETHODIMP nsStkIconInfo::GetIconSelfExplanatory(bool *aIconSelfExplanatory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getIcons ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIStkIcon aIcons); */
NS_IMETHODIMP nsStkIconInfo::GetIcons(uint32_t *aCount, nsIStkIcon * **aIcons)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkItem */
#define NS_ISTKITEM_IID_STR "ea95d25c-5e84-11e4-bd96-07285c50c1f2"

#define NS_ISTKITEM_IID \
  {0xea95d25c, 0x5e84, 0x11e4, \
    { 0xbd, 0x96, 0x07, 0x28, 0x5c, 0x50, 0xc1, 0xf2 }}

class NS_NO_VTABLE nsIStkItem : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKITEM_IID)

  /* readonly attribute unsigned short identifier; */
  NS_IMETHOD GetIdentifier(uint16_t *aIdentifier) = 0;

  /* readonly attribute DOMString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;

  /* readonly attribute nsIStkIconInfo iconInfo; */
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkItem, NS_ISTKITEM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKITEM \
  NS_IMETHOD GetIdentifier(uint16_t *aIdentifier) override; \
  NS_IMETHOD GetText(nsAString & aText) override; \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKITEM(_to) \
  NS_IMETHOD GetIdentifier(uint16_t *aIdentifier) override { return _to GetIdentifier(aIdentifier); } \
  NS_IMETHOD GetText(nsAString & aText) override { return _to GetText(aText); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return _to GetIconInfo(aIconInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKITEM(_to) \
  NS_IMETHOD GetIdentifier(uint16_t *aIdentifier) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdentifier(aIdentifier); } \
  NS_IMETHOD GetText(nsAString & aText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconInfo(aIconInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkItem : public nsIStkItem
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKITEM

  nsStkItem();

private:
  ~nsStkItem();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkItem, nsIStkItem)

nsStkItem::nsStkItem()
{
  /* member initializers and constructor code */
}

nsStkItem::~nsStkItem()
{
  /* destructor code */
}

/* readonly attribute unsigned short identifier; */
NS_IMETHODIMP nsStkItem::GetIdentifier(uint16_t *aIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString text; */
NS_IMETHODIMP nsStkItem::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkIconInfo iconInfo; */
NS_IMETHODIMP nsStkItem::GetIconInfo(nsIStkIconInfo * *aIconInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkTimer */
#define NS_ISTKTIMER_IID_STR "1ec0d430-eeec-11e4-8566-df81b6d562c8"

#define NS_ISTKTIMER_IID \
  {0x1ec0d430, 0xeeec, 0x11e4, \
    { 0x85, 0x66, 0xdf, 0x81, 0xb6, 0xd5, 0x62, 0xc8 }}

class NS_NO_VTABLE nsIStkTimer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKTIMER_IID)

  /* readonly attribute unsigned short timerId; */
  NS_IMETHOD GetTimerId(uint16_t *aTimerId) = 0;

  enum {
    TIMER_VALUE_INVALID = 4294967295U
  };

  /* readonly attribute unsigned long timerValue; */
  NS_IMETHOD GetTimerValue(uint32_t *aTimerValue) = 0;

  enum {
    TIMER_ACTION_START = 0U,
    TIMER_ACTION_DEACTIVATE = 1U,
    TIMER_ACTION_GET_CURRENT_VALUE = 2U,
    TIMER_ACTION_INVALID = 255U
  };

  /* readonly attribute unsigned short timerAction; */
  NS_IMETHOD GetTimerAction(uint16_t *aTimerAction) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkTimer, NS_ISTKTIMER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKTIMER \
  NS_IMETHOD GetTimerId(uint16_t *aTimerId) override; \
  NS_IMETHOD GetTimerValue(uint32_t *aTimerValue) override; \
  NS_IMETHOD GetTimerAction(uint16_t *aTimerAction) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKTIMER(_to) \
  NS_IMETHOD GetTimerId(uint16_t *aTimerId) override { return _to GetTimerId(aTimerId); } \
  NS_IMETHOD GetTimerValue(uint32_t *aTimerValue) override { return _to GetTimerValue(aTimerValue); } \
  NS_IMETHOD GetTimerAction(uint16_t *aTimerAction) override { return _to GetTimerAction(aTimerAction); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKTIMER(_to) \
  NS_IMETHOD GetTimerId(uint16_t *aTimerId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimerId(aTimerId); } \
  NS_IMETHOD GetTimerValue(uint32_t *aTimerValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimerValue(aTimerValue); } \
  NS_IMETHOD GetTimerAction(uint16_t *aTimerAction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimerAction(aTimerAction); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkTimer : public nsIStkTimer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKTIMER

  nsStkTimer();

private:
  ~nsStkTimer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkTimer, nsIStkTimer)

nsStkTimer::nsStkTimer()
{
  /* member initializers and constructor code */
}

nsStkTimer::~nsStkTimer()
{
  /* destructor code */
}

/* readonly attribute unsigned short timerId; */
NS_IMETHODIMP nsStkTimer::GetTimerId(uint16_t *aTimerId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long timerValue; */
NS_IMETHODIMP nsStkTimer::GetTimerValue(uint32_t *aTimerValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short timerAction; */
NS_IMETHODIMP nsStkTimer::GetTimerAction(uint16_t *aTimerAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkLocationInfo */
#define NS_ISTKLOCATIONINFO_IID_STR "09903cfe-f3bf-11e4-a029-23d988cd1a82"

#define NS_ISTKLOCATIONINFO_IID \
  {0x09903cfe, 0xf3bf, 0x11e4, \
    { 0xa0, 0x29, 0x23, 0xd9, 0x88, 0xcd, 0x1a, 0x82 }}

class NS_NO_VTABLE nsIStkLocationInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKLOCATIONINFO_IID)

  /* readonly attribute DOMString mcc; */
  NS_IMETHOD GetMcc(nsAString & aMcc) = 0;

  /* readonly attribute DOMString mnc; */
  NS_IMETHOD GetMnc(nsAString & aMnc) = 0;

  /* readonly attribute unsigned short gsmLocationAreaCode; */
  NS_IMETHOD GetGsmLocationAreaCode(uint16_t *aGsmLocationAreaCode) = 0;

  /* readonly attribute unsigned long gsmCellId; */
  NS_IMETHOD GetGsmCellId(uint32_t *aGsmCellId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkLocationInfo, NS_ISTKLOCATIONINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKLOCATIONINFO \
  NS_IMETHOD GetMcc(nsAString & aMcc) override; \
  NS_IMETHOD GetMnc(nsAString & aMnc) override; \
  NS_IMETHOD GetGsmLocationAreaCode(uint16_t *aGsmLocationAreaCode) override; \
  NS_IMETHOD GetGsmCellId(uint32_t *aGsmCellId) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKLOCATIONINFO(_to) \
  NS_IMETHOD GetMcc(nsAString & aMcc) override { return _to GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(nsAString & aMnc) override { return _to GetMnc(aMnc); } \
  NS_IMETHOD GetGsmLocationAreaCode(uint16_t *aGsmLocationAreaCode) override { return _to GetGsmLocationAreaCode(aGsmLocationAreaCode); } \
  NS_IMETHOD GetGsmCellId(uint32_t *aGsmCellId) override { return _to GetGsmCellId(aGsmCellId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKLOCATIONINFO(_to) \
  NS_IMETHOD GetMcc(nsAString & aMcc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMcc(aMcc); } \
  NS_IMETHOD GetMnc(nsAString & aMnc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMnc(aMnc); } \
  NS_IMETHOD GetGsmLocationAreaCode(uint16_t *aGsmLocationAreaCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGsmLocationAreaCode(aGsmLocationAreaCode); } \
  NS_IMETHOD GetGsmCellId(uint32_t *aGsmCellId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGsmCellId(aGsmCellId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkLocationInfo : public nsIStkLocationInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKLOCATIONINFO

  nsStkLocationInfo();

private:
  ~nsStkLocationInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkLocationInfo, nsIStkLocationInfo)

nsStkLocationInfo::nsStkLocationInfo()
{
  /* member initializers and constructor code */
}

nsStkLocationInfo::~nsStkLocationInfo()
{
  /* destructor code */
}

/* readonly attribute DOMString mcc; */
NS_IMETHODIMP nsStkLocationInfo::GetMcc(nsAString & aMcc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mnc; */
NS_IMETHODIMP nsStkLocationInfo::GetMnc(nsAString & aMnc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short gsmLocationAreaCode; */
NS_IMETHODIMP nsStkLocationInfo::GetGsmLocationAreaCode(uint16_t *aGsmLocationAreaCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long gsmCellId; */
NS_IMETHODIMP nsStkLocationInfo::GetGsmCellId(uint32_t *aGsmCellId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkProactiveCmd */
#define NS_ISTKPROACTIVECMD_IID_STR "f47f25b2-5d84-11e4-8637-7f59ea6da82f"

#define NS_ISTKPROACTIVECMD_IID \
  {0xf47f25b2, 0x5d84, 0x11e4, \
    { 0x86, 0x37, 0x7f, 0x59, 0xea, 0x6d, 0xa8, 0x2f }}

class NS_NO_VTABLE nsIStkProactiveCmd : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKPROACTIVECMD_IID)

  /* readonly attribute unsigned short commandNumber; */
  NS_IMETHOD GetCommandNumber(uint16_t *aCommandNumber) = 0;

  /* readonly attribute unsigned short typeOfCommand; */
  NS_IMETHOD GetTypeOfCommand(uint16_t *aTypeOfCommand) = 0;

  /* readonly attribute unsigned short commandQualifier; */
  NS_IMETHOD GetCommandQualifier(uint16_t *aCommandQualifier) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkProactiveCmd, NS_ISTKPROACTIVECMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKPROACTIVECMD \
  NS_IMETHOD GetCommandNumber(uint16_t *aCommandNumber) override; \
  NS_IMETHOD GetTypeOfCommand(uint16_t *aTypeOfCommand) override; \
  NS_IMETHOD GetCommandQualifier(uint16_t *aCommandQualifier) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKPROACTIVECMD(_to) \
  NS_IMETHOD GetCommandNumber(uint16_t *aCommandNumber) override { return _to GetCommandNumber(aCommandNumber); } \
  NS_IMETHOD GetTypeOfCommand(uint16_t *aTypeOfCommand) override { return _to GetTypeOfCommand(aTypeOfCommand); } \
  NS_IMETHOD GetCommandQualifier(uint16_t *aCommandQualifier) override { return _to GetCommandQualifier(aCommandQualifier); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKPROACTIVECMD(_to) \
  NS_IMETHOD GetCommandNumber(uint16_t *aCommandNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommandNumber(aCommandNumber); } \
  NS_IMETHOD GetTypeOfCommand(uint16_t *aTypeOfCommand) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTypeOfCommand(aTypeOfCommand); } \
  NS_IMETHOD GetCommandQualifier(uint16_t *aCommandQualifier) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCommandQualifier(aCommandQualifier); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkProactiveCmd : public nsIStkProactiveCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKPROACTIVECMD

  nsStkProactiveCmd();

private:
  ~nsStkProactiveCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkProactiveCmd, nsIStkProactiveCmd)

nsStkProactiveCmd::nsStkProactiveCmd()
{
  /* member initializers and constructor code */
}

nsStkProactiveCmd::~nsStkProactiveCmd()
{
  /* destructor code */
}

/* readonly attribute unsigned short commandNumber; */
NS_IMETHODIMP nsStkProactiveCmd::GetCommandNumber(uint16_t *aCommandNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short typeOfCommand; */
NS_IMETHODIMP nsStkProactiveCmd::GetTypeOfCommand(uint16_t *aTypeOfCommand)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short commandQualifier; */
NS_IMETHODIMP nsStkProactiveCmd::GetCommandQualifier(uint16_t *aCommandQualifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkPollIntervalCmd */
#define NS_ISTKPOLLINTERVALCMD_IID_STR "0a27c090-5dbc-11e4-92eb-ebc26db3db29"

#define NS_ISTKPOLLINTERVALCMD_IID \
  {0x0a27c090, 0x5dbc, 0x11e4, \
    { 0x92, 0xeb, 0xeb, 0xc2, 0x6d, 0xb3, 0xdb, 0x29 }}

class NS_NO_VTABLE nsIStkPollIntervalCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKPOLLINTERVALCMD_IID)

  /* readonly attribute nsIStkDuration duration; */
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkPollIntervalCmd, NS_ISTKPOLLINTERVALCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKPOLLINTERVALCMD \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKPOLLINTERVALCMD(_to) \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return _to GetDuration(aDuration); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKPOLLINTERVALCMD(_to) \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDuration(aDuration); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkPollIntervalCmd : public nsIStkPollIntervalCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKPOLLINTERVALCMD

  nsStkPollIntervalCmd();

private:
  ~nsStkPollIntervalCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkPollIntervalCmd, nsIStkPollIntervalCmd)

nsStkPollIntervalCmd::nsStkPollIntervalCmd()
{
  /* member initializers and constructor code */
}

nsStkPollIntervalCmd::~nsStkPollIntervalCmd()
{
  /* destructor code */
}

/* readonly attribute nsIStkDuration duration; */
NS_IMETHODIMP nsStkPollIntervalCmd::GetDuration(nsIStkDuration * *aDuration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkProvideLocalInfoCmd */
#define NS_ISTKPROVIDELOCALINFOCMD_IID_STR "89a304ce-5dc6-11e4-8dce-23723fb242b4"

#define NS_ISTKPROVIDELOCALINFOCMD_IID \
  {0x89a304ce, 0x5dc6, 0x11e4, \
    { 0x8d, 0xce, 0x23, 0x72, 0x3f, 0xb2, 0x42, 0xb4 }}

class NS_NO_VTABLE nsIStkProvideLocalInfoCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKPROVIDELOCALINFOCMD_IID)

  /* readonly attribute unsigned short localInfoType; */
  NS_IMETHOD GetLocalInfoType(uint16_t *aLocalInfoType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkProvideLocalInfoCmd, NS_ISTKPROVIDELOCALINFOCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKPROVIDELOCALINFOCMD \
  NS_IMETHOD GetLocalInfoType(uint16_t *aLocalInfoType) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKPROVIDELOCALINFOCMD(_to) \
  NS_IMETHOD GetLocalInfoType(uint16_t *aLocalInfoType) override { return _to GetLocalInfoType(aLocalInfoType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKPROVIDELOCALINFOCMD(_to) \
  NS_IMETHOD GetLocalInfoType(uint16_t *aLocalInfoType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalInfoType(aLocalInfoType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkProvideLocalInfoCmd : public nsIStkProvideLocalInfoCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKPROVIDELOCALINFOCMD

  nsStkProvideLocalInfoCmd();

private:
  ~nsStkProvideLocalInfoCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkProvideLocalInfoCmd, nsIStkProvideLocalInfoCmd)

nsStkProvideLocalInfoCmd::nsStkProvideLocalInfoCmd()
{
  /* member initializers and constructor code */
}

nsStkProvideLocalInfoCmd::~nsStkProvideLocalInfoCmd()
{
  /* destructor code */
}

/* readonly attribute unsigned short localInfoType; */
NS_IMETHODIMP nsStkProvideLocalInfoCmd::GetLocalInfoType(uint16_t *aLocalInfoType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkSetupEventListCmd */
#define NS_ISTKSETUPEVENTLISTCMD_IID_STR "5f796dec-5e6a-11e4-aaf3-bb675cb36df5"

#define NS_ISTKSETUPEVENTLISTCMD_IID \
  {0x5f796dec, 0x5e6a, 0x11e4, \
    { 0xaa, 0xf3, 0xbb, 0x67, 0x5c, 0xb3, 0x6d, 0xf5 }}

class NS_NO_VTABLE nsIStkSetupEventListCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKSETUPEVENTLISTCMD_IID)

  /* void getEventList ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out unsigned short aEventList); */
  NS_IMETHOD GetEventList(uint32_t *aCount, uint16_t **aEventList) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkSetupEventListCmd, NS_ISTKSETUPEVENTLISTCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKSETUPEVENTLISTCMD \
  NS_IMETHOD GetEventList(uint32_t *aCount, uint16_t **aEventList) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKSETUPEVENTLISTCMD(_to) \
  NS_IMETHOD GetEventList(uint32_t *aCount, uint16_t **aEventList) override { return _to GetEventList(aCount, aEventList); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKSETUPEVENTLISTCMD(_to) \
  NS_IMETHOD GetEventList(uint32_t *aCount, uint16_t **aEventList) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventList(aCount, aEventList); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkSetupEventListCmd : public nsIStkSetupEventListCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKSETUPEVENTLISTCMD

  nsStkSetupEventListCmd();

private:
  ~nsStkSetupEventListCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkSetupEventListCmd, nsIStkSetupEventListCmd)

nsStkSetupEventListCmd::nsStkSetupEventListCmd()
{
  /* member initializers and constructor code */
}

nsStkSetupEventListCmd::~nsStkSetupEventListCmd()
{
  /* destructor code */
}

/* void getEventList ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out unsigned short aEventList); */
NS_IMETHODIMP nsStkSetupEventListCmd::GetEventList(uint32_t *aCount, uint16_t **aEventList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkSetUpMenuCmd */
#define NS_ISTKSETUPMENUCMD_IID_STR "d7a66664-a602-11e4-9cc7-c7ce5fdade7d"

#define NS_ISTKSETUPMENUCMD_IID \
  {0xd7a66664, 0xa602, 0x11e4, \
    { 0x9c, 0xc7, 0xc7, 0xce, 0x5f, 0xda, 0xde, 0x7d }}

class NS_NO_VTABLE nsIStkSetUpMenuCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKSETUPMENUCMD_IID)

  /* readonly attribute DOMString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;

  /* void getItems ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIStkItem aItems); */
  NS_IMETHOD GetItems(uint32_t *aCount, nsIStkItem * **aItems) = 0;

  /* void getNextActionList ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out unsigned short aActions); */
  NS_IMETHOD GetNextActionList(uint32_t *aCount, uint16_t **aActions) = 0;

  /* readonly attribute nsIStkIconInfo iconInfo; */
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) = 0;

  /* readonly attribute boolean isHelpAvailable; */
  NS_IMETHOD GetIsHelpAvailable(bool *aIsHelpAvailable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkSetUpMenuCmd, NS_ISTKSETUPMENUCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKSETUPMENUCMD \
  NS_IMETHOD GetTitle(nsAString & aTitle) override; \
  NS_IMETHOD GetItems(uint32_t *aCount, nsIStkItem * **aItems) override; \
  NS_IMETHOD GetNextActionList(uint32_t *aCount, uint16_t **aActions) override; \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override; \
  NS_IMETHOD GetIsHelpAvailable(bool *aIsHelpAvailable) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKSETUPMENUCMD(_to) \
  NS_IMETHOD GetTitle(nsAString & aTitle) override { return _to GetTitle(aTitle); } \
  NS_IMETHOD GetItems(uint32_t *aCount, nsIStkItem * **aItems) override { return _to GetItems(aCount, aItems); } \
  NS_IMETHOD GetNextActionList(uint32_t *aCount, uint16_t **aActions) override { return _to GetNextActionList(aCount, aActions); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return _to GetIconInfo(aIconInfo); } \
  NS_IMETHOD GetIsHelpAvailable(bool *aIsHelpAvailable) override { return _to GetIsHelpAvailable(aIsHelpAvailable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKSETUPMENUCMD(_to) \
  NS_IMETHOD GetTitle(nsAString & aTitle) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD GetItems(uint32_t *aCount, nsIStkItem * **aItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItems(aCount, aItems); } \
  NS_IMETHOD GetNextActionList(uint32_t *aCount, uint16_t **aActions) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextActionList(aCount, aActions); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconInfo(aIconInfo); } \
  NS_IMETHOD GetIsHelpAvailable(bool *aIsHelpAvailable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsHelpAvailable(aIsHelpAvailable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkSetUpMenuCmd : public nsIStkSetUpMenuCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKSETUPMENUCMD

  nsStkSetUpMenuCmd();

private:
  ~nsStkSetUpMenuCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkSetUpMenuCmd, nsIStkSetUpMenuCmd)

nsStkSetUpMenuCmd::nsStkSetUpMenuCmd()
{
  /* member initializers and constructor code */
}

nsStkSetUpMenuCmd::~nsStkSetUpMenuCmd()
{
  /* destructor code */
}

/* readonly attribute DOMString title; */
NS_IMETHODIMP nsStkSetUpMenuCmd::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getItems ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIStkItem aItems); */
NS_IMETHODIMP nsStkSetUpMenuCmd::GetItems(uint32_t *aCount, nsIStkItem * **aItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNextActionList ([optional] out unsigned long aCount, [array, size_is (aCount), retval] out unsigned short aActions); */
NS_IMETHODIMP nsStkSetUpMenuCmd::GetNextActionList(uint32_t *aCount, uint16_t **aActions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkIconInfo iconInfo; */
NS_IMETHODIMP nsStkSetUpMenuCmd::GetIconInfo(nsIStkIconInfo * *aIconInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isHelpAvailable; */
NS_IMETHODIMP nsStkSetUpMenuCmd::GetIsHelpAvailable(bool *aIsHelpAvailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkSelectItemCmd */
#define NS_ISTKSELECTITEMCMD_IID_STR "eb71f0fa-a602-11e4-926f-a3814461d218"

#define NS_ISTKSELECTITEMCMD_IID \
  {0xeb71f0fa, 0xa602, 0x11e4, \
    { 0x92, 0x6f, 0xa3, 0x81, 0x44, 0x61, 0xd2, 0x18 }}

class NS_NO_VTABLE nsIStkSelectItemCmd : public nsIStkSetUpMenuCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKSELECTITEMCMD_IID)

  enum {
    PRESENTATION_TYPE_NOT_SPECIFIED = 0U,
    PRESENTATION_TYPE_DATA_VALUES = 1U,
    PRESENTATION_TYPE_NAVIGATION_OPTIONS = 3U
  };

  /* readonly attribute unsigned short presentationType; */
  NS_IMETHOD GetPresentationType(uint16_t *aPresentationType) = 0;

  enum {
    DEFAULT_ITEM_INVALID = 65535U
  };

  /* readonly attribute unsigned short defaultItem; */
  NS_IMETHOD GetDefaultItem(uint16_t *aDefaultItem) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkSelectItemCmd, NS_ISTKSELECTITEMCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKSELECTITEMCMD \
  NS_IMETHOD GetPresentationType(uint16_t *aPresentationType) override; \
  NS_IMETHOD GetDefaultItem(uint16_t *aDefaultItem) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKSELECTITEMCMD(_to) \
  NS_IMETHOD GetPresentationType(uint16_t *aPresentationType) override { return _to GetPresentationType(aPresentationType); } \
  NS_IMETHOD GetDefaultItem(uint16_t *aDefaultItem) override { return _to GetDefaultItem(aDefaultItem); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKSELECTITEMCMD(_to) \
  NS_IMETHOD GetPresentationType(uint16_t *aPresentationType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresentationType(aPresentationType); } \
  NS_IMETHOD GetDefaultItem(uint16_t *aDefaultItem) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultItem(aDefaultItem); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkSelectItemCmd : public nsIStkSelectItemCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKSELECTITEMCMD

  nsStkSelectItemCmd();

private:
  ~nsStkSelectItemCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkSelectItemCmd, nsIStkSelectItemCmd)

nsStkSelectItemCmd::nsStkSelectItemCmd()
{
  /* member initializers and constructor code */
}

nsStkSelectItemCmd::~nsStkSelectItemCmd()
{
  /* destructor code */
}

/* readonly attribute unsigned short presentationType; */
NS_IMETHODIMP nsStkSelectItemCmd::GetPresentationType(uint16_t *aPresentationType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short defaultItem; */
NS_IMETHODIMP nsStkSelectItemCmd::GetDefaultItem(uint16_t *aDefaultItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkTextMessageCmd */
#define NS_ISTKTEXTMESSAGECMD_IID_STR "61c42b3c-6324-11e4-959e-7fb2dc9a3f0d"

#define NS_ISTKTEXTMESSAGECMD_IID \
  {0x61c42b3c, 0x6324, 0x11e4, \
    { 0x95, 0x9e, 0x7f, 0xb2, 0xdc, 0x9a, 0x3f, 0x0d }}

class NS_NO_VTABLE nsIStkTextMessageCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKTEXTMESSAGECMD_IID)

  /* readonly attribute DOMString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;

  /* readonly attribute nsIStkIconInfo iconInfo; */
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkTextMessageCmd, NS_ISTKTEXTMESSAGECMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKTEXTMESSAGECMD \
  NS_IMETHOD GetText(nsAString & aText) override; \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKTEXTMESSAGECMD(_to) \
  NS_IMETHOD GetText(nsAString & aText) override { return _to GetText(aText); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return _to GetIconInfo(aIconInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKTEXTMESSAGECMD(_to) \
  NS_IMETHOD GetText(nsAString & aText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconInfo(aIconInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkTextMessageCmd : public nsIStkTextMessageCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKTEXTMESSAGECMD

  nsStkTextMessageCmd();

private:
  ~nsStkTextMessageCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkTextMessageCmd, nsIStkTextMessageCmd)

nsStkTextMessageCmd::nsStkTextMessageCmd()
{
  /* member initializers and constructor code */
}

nsStkTextMessageCmd::~nsStkTextMessageCmd()
{
  /* destructor code */
}

/* readonly attribute DOMString text; */
NS_IMETHODIMP nsStkTextMessageCmd::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkIconInfo iconInfo; */
NS_IMETHODIMP nsStkTextMessageCmd::GetIconInfo(nsIStkIconInfo * *aIconInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkDisplayTextCmd */
#define NS_ISTKDISPLAYTEXTCMD_IID_STR "66a83f0a-6322-11e4-a773-9382de87a74a"

#define NS_ISTKDISPLAYTEXTCMD_IID \
  {0x66a83f0a, 0x6322, 0x11e4, \
    { 0xa7, 0x73, 0x93, 0x82, 0xde, 0x87, 0xa7, 0x4a }}

class NS_NO_VTABLE nsIStkDisplayTextCmd : public nsIStkTextMessageCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKDISPLAYTEXTCMD_IID)

  /* readonly attribute nsIStkDuration duration; */
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) = 0;

  /* readonly attribute boolean isHighPriority; */
  NS_IMETHOD GetIsHighPriority(bool *aIsHighPriority) = 0;

  /* readonly attribute boolean userClear; */
  NS_IMETHOD GetUserClear(bool *aUserClear) = 0;

  /* readonly attribute boolean responseNeeded; */
  NS_IMETHOD GetResponseNeeded(bool *aResponseNeeded) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkDisplayTextCmd, NS_ISTKDISPLAYTEXTCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKDISPLAYTEXTCMD \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override; \
  NS_IMETHOD GetIsHighPriority(bool *aIsHighPriority) override; \
  NS_IMETHOD GetUserClear(bool *aUserClear) override; \
  NS_IMETHOD GetResponseNeeded(bool *aResponseNeeded) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKDISPLAYTEXTCMD(_to) \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return _to GetDuration(aDuration); } \
  NS_IMETHOD GetIsHighPriority(bool *aIsHighPriority) override { return _to GetIsHighPriority(aIsHighPriority); } \
  NS_IMETHOD GetUserClear(bool *aUserClear) override { return _to GetUserClear(aUserClear); } \
  NS_IMETHOD GetResponseNeeded(bool *aResponseNeeded) override { return _to GetResponseNeeded(aResponseNeeded); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKDISPLAYTEXTCMD(_to) \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDuration(aDuration); } \
  NS_IMETHOD GetIsHighPriority(bool *aIsHighPriority) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsHighPriority(aIsHighPriority); } \
  NS_IMETHOD GetUserClear(bool *aUserClear) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserClear(aUserClear); } \
  NS_IMETHOD GetResponseNeeded(bool *aResponseNeeded) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseNeeded(aResponseNeeded); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkDisplayTextCmd : public nsIStkDisplayTextCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKDISPLAYTEXTCMD

  nsStkDisplayTextCmd();

private:
  ~nsStkDisplayTextCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkDisplayTextCmd, nsIStkDisplayTextCmd)

nsStkDisplayTextCmd::nsStkDisplayTextCmd()
{
  /* member initializers and constructor code */
}

nsStkDisplayTextCmd::~nsStkDisplayTextCmd()
{
  /* destructor code */
}

/* readonly attribute nsIStkDuration duration; */
NS_IMETHODIMP nsStkDisplayTextCmd::GetDuration(nsIStkDuration * *aDuration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isHighPriority; */
NS_IMETHODIMP nsStkDisplayTextCmd::GetIsHighPriority(bool *aIsHighPriority)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean userClear; */
NS_IMETHODIMP nsStkDisplayTextCmd::GetUserClear(bool *aUserClear)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean responseNeeded; */
NS_IMETHODIMP nsStkDisplayTextCmd::GetResponseNeeded(bool *aResponseNeeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkInputCmd */
#define NS_ISTKINPUTCMD_IID_STR "ed16a67e-6022-11e4-a8fd-c34fe6e6bb11"

#define NS_ISTKINPUTCMD_IID \
  {0xed16a67e, 0x6022, 0x11e4, \
    { 0xa8, 0xfd, 0xc3, 0x4f, 0xe6, 0xe6, 0xbb, 0x11 }}

class NS_NO_VTABLE nsIStkInputCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKINPUTCMD_IID)

  /* readonly attribute DOMString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;

  /* readonly attribute nsIStkDuration duration; */
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) = 0;

  /* readonly attribute unsigned short minLength; */
  NS_IMETHOD GetMinLength(uint16_t *aMinLength) = 0;

  /* readonly attribute unsigned short maxLength; */
  NS_IMETHOD GetMaxLength(uint16_t *aMaxLength) = 0;

  /* readonly attribute DOMString defaultText; */
  NS_IMETHOD GetDefaultText(nsAString & aDefaultText) = 0;

  /* readonly attribute boolean isAlphabet; */
  NS_IMETHOD GetIsAlphabet(bool *aIsAlphabet) = 0;

  /* readonly attribute boolean isUCS2; */
  NS_IMETHOD GetIsUCS2(bool *aIsUCS2) = 0;

  /* readonly attribute boolean isHelpAvailable; */
  NS_IMETHOD GetIsHelpAvailable(bool *aIsHelpAvailable) = 0;

  /* readonly attribute nsIStkIconInfo iconInfo; */
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkInputCmd, NS_ISTKINPUTCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKINPUTCMD \
  NS_IMETHOD GetText(nsAString & aText) override; \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override; \
  NS_IMETHOD GetMinLength(uint16_t *aMinLength) override; \
  NS_IMETHOD GetMaxLength(uint16_t *aMaxLength) override; \
  NS_IMETHOD GetDefaultText(nsAString & aDefaultText) override; \
  NS_IMETHOD GetIsAlphabet(bool *aIsAlphabet) override; \
  NS_IMETHOD GetIsUCS2(bool *aIsUCS2) override; \
  NS_IMETHOD GetIsHelpAvailable(bool *aIsHelpAvailable) override; \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKINPUTCMD(_to) \
  NS_IMETHOD GetText(nsAString & aText) override { return _to GetText(aText); } \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return _to GetDuration(aDuration); } \
  NS_IMETHOD GetMinLength(uint16_t *aMinLength) override { return _to GetMinLength(aMinLength); } \
  NS_IMETHOD GetMaxLength(uint16_t *aMaxLength) override { return _to GetMaxLength(aMaxLength); } \
  NS_IMETHOD GetDefaultText(nsAString & aDefaultText) override { return _to GetDefaultText(aDefaultText); } \
  NS_IMETHOD GetIsAlphabet(bool *aIsAlphabet) override { return _to GetIsAlphabet(aIsAlphabet); } \
  NS_IMETHOD GetIsUCS2(bool *aIsUCS2) override { return _to GetIsUCS2(aIsUCS2); } \
  NS_IMETHOD GetIsHelpAvailable(bool *aIsHelpAvailable) override { return _to GetIsHelpAvailable(aIsHelpAvailable); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return _to GetIconInfo(aIconInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKINPUTCMD(_to) \
  NS_IMETHOD GetText(nsAString & aText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDuration(aDuration); } \
  NS_IMETHOD GetMinLength(uint16_t *aMinLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMinLength(aMinLength); } \
  NS_IMETHOD GetMaxLength(uint16_t *aMaxLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxLength(aMaxLength); } \
  NS_IMETHOD GetDefaultText(nsAString & aDefaultText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultText(aDefaultText); } \
  NS_IMETHOD GetIsAlphabet(bool *aIsAlphabet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsAlphabet(aIsAlphabet); } \
  NS_IMETHOD GetIsUCS2(bool *aIsUCS2) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsUCS2(aIsUCS2); } \
  NS_IMETHOD GetIsHelpAvailable(bool *aIsHelpAvailable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsHelpAvailable(aIsHelpAvailable); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconInfo(aIconInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkInputCmd : public nsIStkInputCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKINPUTCMD

  nsStkInputCmd();

private:
  ~nsStkInputCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkInputCmd, nsIStkInputCmd)

nsStkInputCmd::nsStkInputCmd()
{
  /* member initializers and constructor code */
}

nsStkInputCmd::~nsStkInputCmd()
{
  /* destructor code */
}

/* readonly attribute DOMString text; */
NS_IMETHODIMP nsStkInputCmd::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkDuration duration; */
NS_IMETHODIMP nsStkInputCmd::GetDuration(nsIStkDuration * *aDuration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short minLength; */
NS_IMETHODIMP nsStkInputCmd::GetMinLength(uint16_t *aMinLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short maxLength; */
NS_IMETHODIMP nsStkInputCmd::GetMaxLength(uint16_t *aMaxLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString defaultText; */
NS_IMETHODIMP nsStkInputCmd::GetDefaultText(nsAString & aDefaultText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isAlphabet; */
NS_IMETHODIMP nsStkInputCmd::GetIsAlphabet(bool *aIsAlphabet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isUCS2; */
NS_IMETHODIMP nsStkInputCmd::GetIsUCS2(bool *aIsUCS2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isHelpAvailable; */
NS_IMETHODIMP nsStkInputCmd::GetIsHelpAvailable(bool *aIsHelpAvailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkIconInfo iconInfo; */
NS_IMETHODIMP nsStkInputCmd::GetIconInfo(nsIStkIconInfo * *aIconInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkInputKeyCmd */
#define NS_ISTKINPUTKEYCMD_IID_STR "27a4078a-6025-11e4-a9ab-bf39252bfaf1"

#define NS_ISTKINPUTKEYCMD_IID \
  {0x27a4078a, 0x6025, 0x11e4, \
    { 0xa9, 0xab, 0xbf, 0x39, 0x25, 0x2b, 0xfa, 0xf1 }}

class NS_NO_VTABLE nsIStkInputKeyCmd : public nsIStkInputCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKINPUTKEYCMD_IID)

  /* readonly attribute boolean isYesNoRequested; */
  NS_IMETHOD GetIsYesNoRequested(bool *aIsYesNoRequested) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkInputKeyCmd, NS_ISTKINPUTKEYCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKINPUTKEYCMD \
  NS_IMETHOD GetIsYesNoRequested(bool *aIsYesNoRequested) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKINPUTKEYCMD(_to) \
  NS_IMETHOD GetIsYesNoRequested(bool *aIsYesNoRequested) override { return _to GetIsYesNoRequested(aIsYesNoRequested); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKINPUTKEYCMD(_to) \
  NS_IMETHOD GetIsYesNoRequested(bool *aIsYesNoRequested) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsYesNoRequested(aIsYesNoRequested); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkInputKeyCmd : public nsIStkInputKeyCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKINPUTKEYCMD

  nsStkInputKeyCmd();

private:
  ~nsStkInputKeyCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkInputKeyCmd, nsIStkInputKeyCmd)

nsStkInputKeyCmd::nsStkInputKeyCmd()
{
  /* member initializers and constructor code */
}

nsStkInputKeyCmd::~nsStkInputKeyCmd()
{
  /* destructor code */
}

/* readonly attribute boolean isYesNoRequested; */
NS_IMETHODIMP nsStkInputKeyCmd::GetIsYesNoRequested(bool *aIsYesNoRequested)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkInputTextCmd */
#define NS_ISTKINPUTTEXTCMD_IID_STR "f3c33ae8-60d4-11e4-9da8-4ff4cb8566c3"

#define NS_ISTKINPUTTEXTCMD_IID \
  {0xf3c33ae8, 0x60d4, 0x11e4, \
    { 0x9d, 0xa8, 0x4f, 0xf4, 0xcb, 0x85, 0x66, 0xc3 }}

class NS_NO_VTABLE nsIStkInputTextCmd : public nsIStkInputCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKINPUTTEXTCMD_IID)

  /* readonly attribute boolean hideInput; */
  NS_IMETHOD GetHideInput(bool *aHideInput) = 0;

  /* readonly attribute boolean isPacked; */
  NS_IMETHOD GetIsPacked(bool *aIsPacked) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkInputTextCmd, NS_ISTKINPUTTEXTCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKINPUTTEXTCMD \
  NS_IMETHOD GetHideInput(bool *aHideInput) override; \
  NS_IMETHOD GetIsPacked(bool *aIsPacked) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKINPUTTEXTCMD(_to) \
  NS_IMETHOD GetHideInput(bool *aHideInput) override { return _to GetHideInput(aHideInput); } \
  NS_IMETHOD GetIsPacked(bool *aIsPacked) override { return _to GetIsPacked(aIsPacked); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKINPUTTEXTCMD(_to) \
  NS_IMETHOD GetHideInput(bool *aHideInput) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHideInput(aHideInput); } \
  NS_IMETHOD GetIsPacked(bool *aIsPacked) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsPacked(aIsPacked); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkInputTextCmd : public nsIStkInputTextCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKINPUTTEXTCMD

  nsStkInputTextCmd();

private:
  ~nsStkInputTextCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkInputTextCmd, nsIStkInputTextCmd)

nsStkInputTextCmd::nsStkInputTextCmd()
{
  /* member initializers and constructor code */
}

nsStkInputTextCmd::~nsStkInputTextCmd()
{
  /* destructor code */
}

/* readonly attribute boolean hideInput; */
NS_IMETHODIMP nsStkInputTextCmd::GetHideInput(bool *aHideInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isPacked; */
NS_IMETHODIMP nsStkInputTextCmd::GetIsPacked(bool *aIsPacked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkSetUpCallCmd */
#define NS_ISTKSETUPCALLCMD_IID_STR "6abbf688-6956-11e4-a9d3-4b07f063ef21"

#define NS_ISTKSETUPCALLCMD_IID \
  {0x6abbf688, 0x6956, 0x11e4, \
    { 0xa9, 0xd3, 0x4b, 0x07, 0xf0, 0x63, 0xef, 0x21 }}

class NS_NO_VTABLE nsIStkSetUpCallCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKSETUPCALLCMD_IID)

  /* readonly attribute DOMString address; */
  NS_IMETHOD GetAddress(nsAString & aAddress) = 0;

  /* readonly attribute DOMString confirmText; */
  NS_IMETHOD GetConfirmText(nsAString & aConfirmText) = 0;

  /* readonly attribute nsIStkIconInfo confirmIconInfo; */
  NS_IMETHOD GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo) = 0;

  /* readonly attribute DOMString callText; */
  NS_IMETHOD GetCallText(nsAString & aCallText) = 0;

  /* readonly attribute nsIStkIconInfo callIconInfo; */
  NS_IMETHOD GetCallIconInfo(nsIStkIconInfo * *aCallIconInfo) = 0;

  /* readonly attribute nsIStkDuration duration; */
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkSetUpCallCmd, NS_ISTKSETUPCALLCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKSETUPCALLCMD \
  NS_IMETHOD GetAddress(nsAString & aAddress) override; \
  NS_IMETHOD GetConfirmText(nsAString & aConfirmText) override; \
  NS_IMETHOD GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo) override; \
  NS_IMETHOD GetCallText(nsAString & aCallText) override; \
  NS_IMETHOD GetCallIconInfo(nsIStkIconInfo * *aCallIconInfo) override; \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKSETUPCALLCMD(_to) \
  NS_IMETHOD GetAddress(nsAString & aAddress) override { return _to GetAddress(aAddress); } \
  NS_IMETHOD GetConfirmText(nsAString & aConfirmText) override { return _to GetConfirmText(aConfirmText); } \
  NS_IMETHOD GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo) override { return _to GetConfirmIconInfo(aConfirmIconInfo); } \
  NS_IMETHOD GetCallText(nsAString & aCallText) override { return _to GetCallText(aCallText); } \
  NS_IMETHOD GetCallIconInfo(nsIStkIconInfo * *aCallIconInfo) override { return _to GetCallIconInfo(aCallIconInfo); } \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return _to GetDuration(aDuration); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKSETUPCALLCMD(_to) \
  NS_IMETHOD GetAddress(nsAString & aAddress) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddress(aAddress); } \
  NS_IMETHOD GetConfirmText(nsAString & aConfirmText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConfirmText(aConfirmText); } \
  NS_IMETHOD GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConfirmIconInfo(aConfirmIconInfo); } \
  NS_IMETHOD GetCallText(nsAString & aCallText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallText(aCallText); } \
  NS_IMETHOD GetCallIconInfo(nsIStkIconInfo * *aCallIconInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallIconInfo(aCallIconInfo); } \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDuration(aDuration); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkSetUpCallCmd : public nsIStkSetUpCallCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKSETUPCALLCMD

  nsStkSetUpCallCmd();

private:
  ~nsStkSetUpCallCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkSetUpCallCmd, nsIStkSetUpCallCmd)

nsStkSetUpCallCmd::nsStkSetUpCallCmd()
{
  /* member initializers and constructor code */
}

nsStkSetUpCallCmd::~nsStkSetUpCallCmd()
{
  /* destructor code */
}

/* readonly attribute DOMString address; */
NS_IMETHODIMP nsStkSetUpCallCmd::GetAddress(nsAString & aAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString confirmText; */
NS_IMETHODIMP nsStkSetUpCallCmd::GetConfirmText(nsAString & aConfirmText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkIconInfo confirmIconInfo; */
NS_IMETHODIMP nsStkSetUpCallCmd::GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString callText; */
NS_IMETHODIMP nsStkSetUpCallCmd::GetCallText(nsAString & aCallText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkIconInfo callIconInfo; */
NS_IMETHODIMP nsStkSetUpCallCmd::GetCallIconInfo(nsIStkIconInfo * *aCallIconInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkDuration duration; */
NS_IMETHODIMP nsStkSetUpCallCmd::GetDuration(nsIStkDuration * *aDuration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkBrowserSettingCmd */
#define NS_ISTKBROWSERSETTINGCMD_IID_STR "b9bca548-695b-11e4-8c1f-cfb850f421ab"

#define NS_ISTKBROWSERSETTINGCMD_IID \
  {0xb9bca548, 0x695b, 0x11e4, \
    { 0x8c, 0x1f, 0xcf, 0xb8, 0x50, 0xf4, 0x21, 0xab }}

class NS_NO_VTABLE nsIStkBrowserSettingCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKBROWSERSETTINGCMD_IID)

  /* readonly attribute DOMString url; */
  NS_IMETHOD GetUrl(nsAString & aUrl) = 0;

  /* readonly attribute unsigned short mode; */
  NS_IMETHOD GetMode(uint16_t *aMode) = 0;

  /* readonly attribute DOMString confirmText; */
  NS_IMETHOD GetConfirmText(nsAString & aConfirmText) = 0;

  /* readonly attribute nsIStkIconInfo confirmIconInfo; */
  NS_IMETHOD GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkBrowserSettingCmd, NS_ISTKBROWSERSETTINGCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKBROWSERSETTINGCMD \
  NS_IMETHOD GetUrl(nsAString & aUrl) override; \
  NS_IMETHOD GetMode(uint16_t *aMode) override; \
  NS_IMETHOD GetConfirmText(nsAString & aConfirmText) override; \
  NS_IMETHOD GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKBROWSERSETTINGCMD(_to) \
  NS_IMETHOD GetUrl(nsAString & aUrl) override { return _to GetUrl(aUrl); } \
  NS_IMETHOD GetMode(uint16_t *aMode) override { return _to GetMode(aMode); } \
  NS_IMETHOD GetConfirmText(nsAString & aConfirmText) override { return _to GetConfirmText(aConfirmText); } \
  NS_IMETHOD GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo) override { return _to GetConfirmIconInfo(aConfirmIconInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKBROWSERSETTINGCMD(_to) \
  NS_IMETHOD GetUrl(nsAString & aUrl) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrl(aUrl); } \
  NS_IMETHOD GetMode(uint16_t *aMode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMode(aMode); } \
  NS_IMETHOD GetConfirmText(nsAString & aConfirmText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConfirmText(aConfirmText); } \
  NS_IMETHOD GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConfirmIconInfo(aConfirmIconInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkBrowserSettingCmd : public nsIStkBrowserSettingCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKBROWSERSETTINGCMD

  nsStkBrowserSettingCmd();

private:
  ~nsStkBrowserSettingCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkBrowserSettingCmd, nsIStkBrowserSettingCmd)

nsStkBrowserSettingCmd::nsStkBrowserSettingCmd()
{
  /* member initializers and constructor code */
}

nsStkBrowserSettingCmd::~nsStkBrowserSettingCmd()
{
  /* destructor code */
}

/* readonly attribute DOMString url; */
NS_IMETHODIMP nsStkBrowserSettingCmd::GetUrl(nsAString & aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short mode; */
NS_IMETHODIMP nsStkBrowserSettingCmd::GetMode(uint16_t *aMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString confirmText; */
NS_IMETHODIMP nsStkBrowserSettingCmd::GetConfirmText(nsAString & aConfirmText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkIconInfo confirmIconInfo; */
NS_IMETHODIMP nsStkBrowserSettingCmd::GetConfirmIconInfo(nsIStkIconInfo * *aConfirmIconInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkPlayToneCmd */
#define NS_ISTKPLAYTONECMD_IID_STR "f49dd148-60ee-11e4-af46-6b938538de51"

#define NS_ISTKPLAYTONECMD_IID \
  {0xf49dd148, 0x60ee, 0x11e4, \
    { 0xaf, 0x46, 0x6b, 0x93, 0x85, 0x38, 0xde, 0x51 }}

class NS_NO_VTABLE nsIStkPlayToneCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKPLAYTONECMD_IID)

  enum {
    TONE_TYPE_INVALID = 65535U
  };

  /* readonly attribute DOMString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;

  /* readonly attribute unsigned short tone; */
  NS_IMETHOD GetTone(uint16_t *aTone) = 0;

  /* readonly attribute nsIStkDuration duration; */
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) = 0;

  /* readonly attribute boolean isVibrate; */
  NS_IMETHOD GetIsVibrate(bool *aIsVibrate) = 0;

  /* readonly attribute nsIStkIconInfo iconInfo; */
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkPlayToneCmd, NS_ISTKPLAYTONECMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKPLAYTONECMD \
  NS_IMETHOD GetText(nsAString & aText) override; \
  NS_IMETHOD GetTone(uint16_t *aTone) override; \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override; \
  NS_IMETHOD GetIsVibrate(bool *aIsVibrate) override; \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKPLAYTONECMD(_to) \
  NS_IMETHOD GetText(nsAString & aText) override { return _to GetText(aText); } \
  NS_IMETHOD GetTone(uint16_t *aTone) override { return _to GetTone(aTone); } \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return _to GetDuration(aDuration); } \
  NS_IMETHOD GetIsVibrate(bool *aIsVibrate) override { return _to GetIsVibrate(aIsVibrate); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return _to GetIconInfo(aIconInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKPLAYTONECMD(_to) \
  NS_IMETHOD GetText(nsAString & aText) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD GetTone(uint16_t *aTone) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTone(aTone); } \
  NS_IMETHOD GetDuration(nsIStkDuration * *aDuration) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDuration(aDuration); } \
  NS_IMETHOD GetIsVibrate(bool *aIsVibrate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsVibrate(aIsVibrate); } \
  NS_IMETHOD GetIconInfo(nsIStkIconInfo * *aIconInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIconInfo(aIconInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkPlayToneCmd : public nsIStkPlayToneCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKPLAYTONECMD

  nsStkPlayToneCmd();

private:
  ~nsStkPlayToneCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkPlayToneCmd, nsIStkPlayToneCmd)

nsStkPlayToneCmd::nsStkPlayToneCmd()
{
  /* member initializers and constructor code */
}

nsStkPlayToneCmd::~nsStkPlayToneCmd()
{
  /* destructor code */
}

/* readonly attribute DOMString text; */
NS_IMETHODIMP nsStkPlayToneCmd::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short tone; */
NS_IMETHODIMP nsStkPlayToneCmd::GetTone(uint16_t *aTone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkDuration duration; */
NS_IMETHODIMP nsStkPlayToneCmd::GetDuration(nsIStkDuration * *aDuration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isVibrate; */
NS_IMETHODIMP nsStkPlayToneCmd::GetIsVibrate(bool *aIsVibrate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkIconInfo iconInfo; */
NS_IMETHODIMP nsStkPlayToneCmd::GetIconInfo(nsIStkIconInfo * *aIconInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkTimerManagementCmd */
#define NS_ISTKTIMERMANAGEMENTCMD_IID_STR "e421b122-60f3-11e4-b8d7-bfe75825a796"

#define NS_ISTKTIMERMANAGEMENTCMD_IID \
  {0xe421b122, 0x60f3, 0x11e4, \
    { 0xb8, 0xd7, 0xbf, 0xe7, 0x58, 0x25, 0xa7, 0x96 }}

class NS_NO_VTABLE nsIStkTimerManagementCmd : public nsIStkProactiveCmd {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKTIMERMANAGEMENTCMD_IID)

  /* readonly attribute nsIStkTimer timerInfo; */
  NS_IMETHOD GetTimerInfo(nsIStkTimer * *aTimerInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkTimerManagementCmd, NS_ISTKTIMERMANAGEMENTCMD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKTIMERMANAGEMENTCMD \
  NS_IMETHOD GetTimerInfo(nsIStkTimer * *aTimerInfo) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKTIMERMANAGEMENTCMD(_to) \
  NS_IMETHOD GetTimerInfo(nsIStkTimer * *aTimerInfo) override { return _to GetTimerInfo(aTimerInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKTIMERMANAGEMENTCMD(_to) \
  NS_IMETHOD GetTimerInfo(nsIStkTimer * *aTimerInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimerInfo(aTimerInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkTimerManagementCmd : public nsIStkTimerManagementCmd
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKTIMERMANAGEMENTCMD

  nsStkTimerManagementCmd();

private:
  ~nsStkTimerManagementCmd();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkTimerManagementCmd, nsIStkTimerManagementCmd)

nsStkTimerManagementCmd::nsStkTimerManagementCmd()
{
  /* member initializers and constructor code */
}

nsStkTimerManagementCmd::~nsStkTimerManagementCmd()
{
  /* destructor code */
}

/* readonly attribute nsIStkTimer timerInfo; */
NS_IMETHODIMP nsStkTimerManagementCmd::GetTimerInfo(nsIStkTimer * *aTimerInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkTerminalResponse */
#define NS_ISTKTERMINALRESPONSE_IID_STR "8e9f94de-0059-11e5-8608-67b08648d3d9"

#define NS_ISTKTERMINALRESPONSE_IID \
  {0x8e9f94de, 0x0059, 0x11e5, \
    { 0x86, 0x08, 0x67, 0xb0, 0x86, 0x48, 0xd3, 0xd9 }}

class NS_NO_VTABLE nsIStkTerminalResponse : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKTERMINALRESPONSE_IID)

  enum {
    RESULT_OK = 0U,
    RESULT_PRFRMD_WITH_PARTIAL_COMPREHENSION = 1U,
    RESULT_PRFRMD_WITH_MISSING_INFO = 2U,
    RESULT_PRFRMD_WITH_ADDITIONAL_EFS_READ = 3U,
    RESULT_PRFRMD_ICON_NOT_DISPLAYED = 4U,
    RESULT_PRFRMD_LIMITED_SERVICE = 6U,
    RESULT_UICC_SESSION_TERM_BY_USER = 16U,
    RESULT_BACKWARD_MOVE_BY_USER = 17U,
    RESULT_NO_RESPONSE_FROM_USER = 18U,
    RESULT_HELP_INFO_REQUIRED = 19U,
    RESULT_USSD_SS_SESSION_TERM_BY_USER = 20U,
    RESULT_TERMINAL_CRNTLY_UNABLE_TO_PROCESS = 32U,
    RESULT_NETWORK_CRNTLY_UNABLE_TO_PROCESS = 33U,
    RESULT_USER_NOT_ACCEPT = 34U,
    RESULT_USER_CLEAR_DOWN_CALL = 35U,
    RESULT_ACTION_CONTRADICTION_TIMER_STATE = 36U,
    RESULT_LAUNCH_BROWSER_ERROR = 38U,
    RESULT_BEYOND_TERMINAL_CAPABILITY = 48U,
    RESULT_CMD_TYPE_NOT_UNDERSTOOD = 49U,
    RESULT_CMD_DATA_NOT_UNDERSTOOD = 50U,
    RESULT_CMD_NUM_NOT_KNOWN = 51U,
    RESULT_SS_RETURN_ERROR = 52U,
    RESULT_SMS_RP_ERROR = 53U,
    RESULT_REQUIRED_VALUES_MISSING = 54U,
    RESULT_USSD_RETURN_ERROR = 55U,
    RESULT_MULTI_CARDS_CMD_ERROR = 56U,
    RESULT_USIM_CALL_CONTROL_PERMANENT = 57U,
    RESULT_BIP_ERROR = 58U,
    ADDITIONAL_INFO_ME_PROBLEM_SCREEN_IS_BUSY = 1U,
    ADDITIONAL_INFO_INVALID = 65535U
  };

  /* readonly attribute unsigned short resultCode; */
  NS_IMETHOD GetResultCode(uint16_t *aResultCode) = 0;

  /* readonly attribute unsigned short additionalInformation; */
  NS_IMETHOD GetAdditionalInformation(uint16_t *aAdditionalInformation) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkTerminalResponse, NS_ISTKTERMINALRESPONSE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKTERMINALRESPONSE \
  NS_IMETHOD GetResultCode(uint16_t *aResultCode) override; \
  NS_IMETHOD GetAdditionalInformation(uint16_t *aAdditionalInformation) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKTERMINALRESPONSE(_to) \
  NS_IMETHOD GetResultCode(uint16_t *aResultCode) override { return _to GetResultCode(aResultCode); } \
  NS_IMETHOD GetAdditionalInformation(uint16_t *aAdditionalInformation) override { return _to GetAdditionalInformation(aAdditionalInformation); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKTERMINALRESPONSE(_to) \
  NS_IMETHOD GetResultCode(uint16_t *aResultCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultCode(aResultCode); } \
  NS_IMETHOD GetAdditionalInformation(uint16_t *aAdditionalInformation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdditionalInformation(aAdditionalInformation); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkTerminalResponse : public nsIStkTerminalResponse
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKTERMINALRESPONSE

  nsStkTerminalResponse();

private:
  ~nsStkTerminalResponse();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkTerminalResponse, nsIStkTerminalResponse)

nsStkTerminalResponse::nsStkTerminalResponse()
{
  /* member initializers and constructor code */
}

nsStkTerminalResponse::~nsStkTerminalResponse()
{
  /* destructor code */
}

/* readonly attribute unsigned short resultCode; */
NS_IMETHODIMP nsStkTerminalResponse::GetResultCode(uint16_t *aResultCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short additionalInformation; */
NS_IMETHODIMP nsStkTerminalResponse::GetAdditionalInformation(uint16_t *aAdditionalInformation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkSelectItemResponse */
#define NS_ISTKSELECTITEMRESPONSE_IID_STR "8eaa2496-ed7e-11e4-9aff-bfcf22a78770"

#define NS_ISTKSELECTITEMRESPONSE_IID \
  {0x8eaa2496, 0xed7e, 0x11e4, \
    { 0x9a, 0xff, 0xbf, 0xcf, 0x22, 0xa7, 0x87, 0x70 }}

class NS_NO_VTABLE nsIStkSelectItemResponse : public nsIStkTerminalResponse {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKSELECTITEMRESPONSE_IID)

  /* readonly attribute unsigned short itemIdentifier; */
  NS_IMETHOD GetItemIdentifier(uint16_t *aItemIdentifier) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkSelectItemResponse, NS_ISTKSELECTITEMRESPONSE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKSELECTITEMRESPONSE \
  NS_IMETHOD GetItemIdentifier(uint16_t *aItemIdentifier) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKSELECTITEMRESPONSE(_to) \
  NS_IMETHOD GetItemIdentifier(uint16_t *aItemIdentifier) override { return _to GetItemIdentifier(aItemIdentifier); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKSELECTITEMRESPONSE(_to) \
  NS_IMETHOD GetItemIdentifier(uint16_t *aItemIdentifier) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemIdentifier(aItemIdentifier); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkSelectItemResponse : public nsIStkSelectItemResponse
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKSELECTITEMRESPONSE

  nsStkSelectItemResponse();

private:
  ~nsStkSelectItemResponse();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkSelectItemResponse, nsIStkSelectItemResponse)

nsStkSelectItemResponse::nsStkSelectItemResponse()
{
  /* member initializers and constructor code */
}

nsStkSelectItemResponse::~nsStkSelectItemResponse()
{
  /* destructor code */
}

/* readonly attribute unsigned short itemIdentifier; */
NS_IMETHODIMP nsStkSelectItemResponse::GetItemIdentifier(uint16_t *aItemIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkGetInputResponse */
#define NS_ISTKGETINPUTRESPONSE_IID_STR "f39d9cd8-ee33-11e4-a55b-ef2489a0707d"

#define NS_ISTKGETINPUTRESPONSE_IID \
  {0xf39d9cd8, 0xee33, 0x11e4, \
    { 0xa5, 0x5b, 0xef, 0x24, 0x89, 0xa0, 0x70, 0x7d }}

class NS_NO_VTABLE nsIStkGetInputResponse : public nsIStkTerminalResponse {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKGETINPUTRESPONSE_IID)

  enum {
    YES_NO_INVALID = 65535U,
    YES = 1U,
    NO = 0U
  };

  /* readonly attribute unsigned short isYesNo; */
  NS_IMETHOD GetIsYesNo(uint16_t *aIsYesNo) = 0;

  /* readonly attribute DOMString input; */
  NS_IMETHOD GetInput(nsAString & aInput) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkGetInputResponse, NS_ISTKGETINPUTRESPONSE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKGETINPUTRESPONSE \
  NS_IMETHOD GetIsYesNo(uint16_t *aIsYesNo) override; \
  NS_IMETHOD GetInput(nsAString & aInput) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKGETINPUTRESPONSE(_to) \
  NS_IMETHOD GetIsYesNo(uint16_t *aIsYesNo) override { return _to GetIsYesNo(aIsYesNo); } \
  NS_IMETHOD GetInput(nsAString & aInput) override { return _to GetInput(aInput); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKGETINPUTRESPONSE(_to) \
  NS_IMETHOD GetIsYesNo(uint16_t *aIsYesNo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsYesNo(aIsYesNo); } \
  NS_IMETHOD GetInput(nsAString & aInput) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInput(aInput); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkGetInputResponse : public nsIStkGetInputResponse
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKGETINPUTRESPONSE

  nsStkGetInputResponse();

private:
  ~nsStkGetInputResponse();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkGetInputResponse, nsIStkGetInputResponse)

nsStkGetInputResponse::nsStkGetInputResponse()
{
  /* member initializers and constructor code */
}

nsStkGetInputResponse::~nsStkGetInputResponse()
{
  /* destructor code */
}

/* readonly attribute unsigned short isYesNo; */
NS_IMETHODIMP nsStkGetInputResponse::GetIsYesNo(uint16_t *aIsYesNo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString input; */
NS_IMETHODIMP nsStkGetInputResponse::GetInput(nsAString & aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkCallSetupResponse */
#define NS_ISTKCALLSETUPRESPONSE_IID_STR "dbf61506-ed7f-11e4-93ea-233485a1bac9"

#define NS_ISTKCALLSETUPRESPONSE_IID \
  {0xdbf61506, 0xed7f, 0x11e4, \
    { 0x93, 0xea, 0x23, 0x34, 0x85, 0xa1, 0xba, 0xc9 }}

class NS_NO_VTABLE nsIStkCallSetupResponse : public nsIStkTerminalResponse {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKCALLSETUPRESPONSE_IID)

  /* readonly attribute boolean hasConfirmed; */
  NS_IMETHOD GetHasConfirmed(bool *aHasConfirmed) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkCallSetupResponse, NS_ISTKCALLSETUPRESPONSE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKCALLSETUPRESPONSE \
  NS_IMETHOD GetHasConfirmed(bool *aHasConfirmed) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKCALLSETUPRESPONSE(_to) \
  NS_IMETHOD GetHasConfirmed(bool *aHasConfirmed) override { return _to GetHasConfirmed(aHasConfirmed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKCALLSETUPRESPONSE(_to) \
  NS_IMETHOD GetHasConfirmed(bool *aHasConfirmed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasConfirmed(aHasConfirmed); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkCallSetupResponse : public nsIStkCallSetupResponse
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKCALLSETUPRESPONSE

  nsStkCallSetupResponse();

private:
  ~nsStkCallSetupResponse();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkCallSetupResponse, nsIStkCallSetupResponse)

nsStkCallSetupResponse::nsStkCallSetupResponse()
{
  /* member initializers and constructor code */
}

nsStkCallSetupResponse::~nsStkCallSetupResponse()
{
  /* destructor code */
}

/* readonly attribute boolean hasConfirmed; */
NS_IMETHODIMP nsStkCallSetupResponse::GetHasConfirmed(bool *aHasConfirmed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkLocalInfoResponse */
#define NS_ISTKLOCALINFORESPONSE_IID_STR "24fd4ece-ee37-11e4-8ac4-af876b1ce771"

#define NS_ISTKLOCALINFORESPONSE_IID \
  {0x24fd4ece, 0xee37, 0x11e4, \
    { 0x8a, 0xc4, 0xaf, 0x87, 0x6b, 0x1c, 0xe7, 0x71 }}

class NS_NO_VTABLE nsIStkLocalInfoResponse : public nsIStkTerminalResponse {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKLOCALINFORESPONSE_IID)

  enum {
    DATE_INVALID = 0U
  };

  /* readonly attribute DOMString imei; */
  NS_IMETHOD GetImei(nsAString & aImei) = 0;

  /* readonly attribute nsIStkLocationInfo locationInfo; */
  NS_IMETHOD GetLocationInfo(nsIStkLocationInfo * *aLocationInfo) = 0;

  /* readonly attribute DOMTimeStamp date; */
  NS_IMETHOD GetDate(DOMTimeStamp *aDate) = 0;

  /* readonly attribute DOMString language; */
  NS_IMETHOD GetLanguage(nsAString & aLanguage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkLocalInfoResponse, NS_ISTKLOCALINFORESPONSE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKLOCALINFORESPONSE \
  NS_IMETHOD GetImei(nsAString & aImei) override; \
  NS_IMETHOD GetLocationInfo(nsIStkLocationInfo * *aLocationInfo) override; \
  NS_IMETHOD GetDate(DOMTimeStamp *aDate) override; \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKLOCALINFORESPONSE(_to) \
  NS_IMETHOD GetImei(nsAString & aImei) override { return _to GetImei(aImei); } \
  NS_IMETHOD GetLocationInfo(nsIStkLocationInfo * *aLocationInfo) override { return _to GetLocationInfo(aLocationInfo); } \
  NS_IMETHOD GetDate(DOMTimeStamp *aDate) override { return _to GetDate(aDate); } \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) override { return _to GetLanguage(aLanguage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKLOCALINFORESPONSE(_to) \
  NS_IMETHOD GetImei(nsAString & aImei) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImei(aImei); } \
  NS_IMETHOD GetLocationInfo(nsIStkLocationInfo * *aLocationInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocationInfo(aLocationInfo); } \
  NS_IMETHOD GetDate(DOMTimeStamp *aDate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDate(aDate); } \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkLocalInfoResponse : public nsIStkLocalInfoResponse
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKLOCALINFORESPONSE

  nsStkLocalInfoResponse();

private:
  ~nsStkLocalInfoResponse();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkLocalInfoResponse, nsIStkLocalInfoResponse)

nsStkLocalInfoResponse::nsStkLocalInfoResponse()
{
  /* member initializers and constructor code */
}

nsStkLocalInfoResponse::~nsStkLocalInfoResponse()
{
  /* destructor code */
}

/* readonly attribute DOMString imei; */
NS_IMETHODIMP nsStkLocalInfoResponse::GetImei(nsAString & aImei)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkLocationInfo locationInfo; */
NS_IMETHODIMP nsStkLocalInfoResponse::GetLocationInfo(nsIStkLocationInfo * *aLocationInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMTimeStamp date; */
NS_IMETHODIMP nsStkLocalInfoResponse::GetDate(DOMTimeStamp *aDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString language; */
NS_IMETHODIMP nsStkLocalInfoResponse::GetLanguage(nsAString & aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkTimerResponse */
#define NS_ISTKTIMERRESPONSE_IID_STR "19f37a02-ed84-11e4-8316-0fde52ecfba6"

#define NS_ISTKTIMERRESPONSE_IID \
  {0x19f37a02, 0xed84, 0x11e4, \
    { 0x83, 0x16, 0x0f, 0xde, 0x52, 0xec, 0xfb, 0xa6 }}

class NS_NO_VTABLE nsIStkTimerResponse : public nsIStkTerminalResponse {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKTIMERRESPONSE_IID)

  /* readonly attribute nsIStkTimer timer; */
  NS_IMETHOD GetTimer(nsIStkTimer * *aTimer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkTimerResponse, NS_ISTKTIMERRESPONSE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKTIMERRESPONSE \
  NS_IMETHOD GetTimer(nsIStkTimer * *aTimer) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKTIMERRESPONSE(_to) \
  NS_IMETHOD GetTimer(nsIStkTimer * *aTimer) override { return _to GetTimer(aTimer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKTIMERRESPONSE(_to) \
  NS_IMETHOD GetTimer(nsIStkTimer * *aTimer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimer(aTimer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkTimerResponse : public nsIStkTimerResponse
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKTIMERRESPONSE

  nsStkTimerResponse();

private:
  ~nsStkTimerResponse();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkTimerResponse, nsIStkTimerResponse)

nsStkTimerResponse::nsStkTimerResponse()
{
  /* member initializers and constructor code */
}

nsStkTimerResponse::~nsStkTimerResponse()
{
  /* destructor code */
}

/* readonly attribute nsIStkTimer timer; */
NS_IMETHODIMP nsStkTimerResponse::GetTimer(nsIStkTimer * *aTimer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkDownloadEvent */
#define NS_ISTKDOWNLOADEVENT_IID_STR "0215d918-ee4a-11e4-9dcf-ab2c197c9211"

#define NS_ISTKDOWNLOADEVENT_IID \
  {0x0215d918, 0xee4a, 0x11e4, \
    { 0x9d, 0xcf, 0xab, 0x2c, 0x19, 0x7c, 0x92, 0x11 }}

class NS_NO_VTABLE nsIStkDownloadEvent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKDOWNLOADEVENT_IID)

  /* readonly attribute unsigned short eventType; */
  NS_IMETHOD GetEventType(uint16_t *aEventType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkDownloadEvent, NS_ISTKDOWNLOADEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKDOWNLOADEVENT \
  NS_IMETHOD GetEventType(uint16_t *aEventType) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKDOWNLOADEVENT(_to) \
  NS_IMETHOD GetEventType(uint16_t *aEventType) override { return _to GetEventType(aEventType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKDOWNLOADEVENT(_to) \
  NS_IMETHOD GetEventType(uint16_t *aEventType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventType(aEventType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkDownloadEvent : public nsIStkDownloadEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKDOWNLOADEVENT

  nsStkDownloadEvent();

private:
  ~nsStkDownloadEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkDownloadEvent, nsIStkDownloadEvent)

nsStkDownloadEvent::nsStkDownloadEvent()
{
  /* member initializers and constructor code */
}

nsStkDownloadEvent::~nsStkDownloadEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned short eventType; */
NS_IMETHODIMP nsStkDownloadEvent::GetEventType(uint16_t *aEventType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkLocationEvent */
#define NS_ISTKLOCATIONEVENT_IID_STR "807b14f0-0059-11e5-aff7-1f8b4e659dbc"

#define NS_ISTKLOCATIONEVENT_IID \
  {0x807b14f0, 0x0059, 0x11e5, \
    { 0xaf, 0xf7, 0x1f, 0x8b, 0x4e, 0x65, 0x9d, 0xbc }}

class NS_NO_VTABLE nsIStkLocationEvent : public nsIStkDownloadEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKLOCATIONEVENT_IID)

  enum {
    SERVICE_STATE_NORMAL = 0U,
    SERVICE_STATE_LIMITED = 1U,
    SERVICE_STATE_UNAVAILABLE = 2U
  };

  /* readonly attribute unsigned short locationStatus; */
  NS_IMETHOD GetLocationStatus(uint16_t *aLocationStatus) = 0;

  /* readonly attribute nsIStkLocationInfo locationInfo; */
  NS_IMETHOD GetLocationInfo(nsIStkLocationInfo * *aLocationInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkLocationEvent, NS_ISTKLOCATIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKLOCATIONEVENT \
  NS_IMETHOD GetLocationStatus(uint16_t *aLocationStatus) override; \
  NS_IMETHOD GetLocationInfo(nsIStkLocationInfo * *aLocationInfo) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKLOCATIONEVENT(_to) \
  NS_IMETHOD GetLocationStatus(uint16_t *aLocationStatus) override { return _to GetLocationStatus(aLocationStatus); } \
  NS_IMETHOD GetLocationInfo(nsIStkLocationInfo * *aLocationInfo) override { return _to GetLocationInfo(aLocationInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKLOCATIONEVENT(_to) \
  NS_IMETHOD GetLocationStatus(uint16_t *aLocationStatus) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocationStatus(aLocationStatus); } \
  NS_IMETHOD GetLocationInfo(nsIStkLocationInfo * *aLocationInfo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocationInfo(aLocationInfo); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkLocationEvent : public nsIStkLocationEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKLOCATIONEVENT

  nsStkLocationEvent();

private:
  ~nsStkLocationEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkLocationEvent, nsIStkLocationEvent)

nsStkLocationEvent::nsStkLocationEvent()
{
  /* member initializers and constructor code */
}

nsStkLocationEvent::~nsStkLocationEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned short locationStatus; */
NS_IMETHODIMP nsStkLocationEvent::GetLocationStatus(uint16_t *aLocationStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStkLocationInfo locationInfo; */
NS_IMETHODIMP nsStkLocationEvent::GetLocationInfo(nsIStkLocationInfo * *aLocationInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkCallEvent */
#define NS_ISTKCALLEVENT_IID_STR "e47dfc98-ee51-11e4-a672-43216a0b375a"

#define NS_ISTKCALLEVENT_IID \
  {0xe47dfc98, 0xee51, 0x11e4, \
    { 0xa6, 0x72, 0x43, 0x21, 0x6a, 0x0b, 0x37, 0x5a }}

class NS_NO_VTABLE nsIStkCallEvent : public nsIStkDownloadEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKCALLEVENT_IID)

  /* readonly attribute DOMString number; */
  NS_IMETHOD GetNumber(nsAString & aNumber) = 0;

  /* readonly attribute boolean isIssuedByRemote; */
  NS_IMETHOD GetIsIssuedByRemote(bool *aIsIssuedByRemote) = 0;

  /* readonly attribute DOMString error; */
  NS_IMETHOD GetError(nsAString & aError) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkCallEvent, NS_ISTKCALLEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKCALLEVENT \
  NS_IMETHOD GetNumber(nsAString & aNumber) override; \
  NS_IMETHOD GetIsIssuedByRemote(bool *aIsIssuedByRemote) override; \
  NS_IMETHOD GetError(nsAString & aError) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKCALLEVENT(_to) \
  NS_IMETHOD GetNumber(nsAString & aNumber) override { return _to GetNumber(aNumber); } \
  NS_IMETHOD GetIsIssuedByRemote(bool *aIsIssuedByRemote) override { return _to GetIsIssuedByRemote(aIsIssuedByRemote); } \
  NS_IMETHOD GetError(nsAString & aError) override { return _to GetError(aError); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKCALLEVENT(_to) \
  NS_IMETHOD GetNumber(nsAString & aNumber) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumber(aNumber); } \
  NS_IMETHOD GetIsIssuedByRemote(bool *aIsIssuedByRemote) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsIssuedByRemote(aIsIssuedByRemote); } \
  NS_IMETHOD GetError(nsAString & aError) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkCallEvent : public nsIStkCallEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKCALLEVENT

  nsStkCallEvent();

private:
  ~nsStkCallEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkCallEvent, nsIStkCallEvent)

nsStkCallEvent::nsStkCallEvent()
{
  /* member initializers and constructor code */
}

nsStkCallEvent::~nsStkCallEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString number; */
NS_IMETHODIMP nsStkCallEvent::GetNumber(nsAString & aNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isIssuedByRemote; */
NS_IMETHODIMP nsStkCallEvent::GetIsIssuedByRemote(bool *aIsIssuedByRemote)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString error; */
NS_IMETHODIMP nsStkCallEvent::GetError(nsAString & aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkLanguageSelectionEvent */
#define NS_ISTKLANGUAGESELECTIONEVENT_IID_STR "d185f0dc-ee51-11e4-912a-933874ee6cec"

#define NS_ISTKLANGUAGESELECTIONEVENT_IID \
  {0xd185f0dc, 0xee51, 0x11e4, \
    { 0x91, 0x2a, 0x93, 0x38, 0x74, 0xee, 0x6c, 0xec }}

class NS_NO_VTABLE nsIStkLanguageSelectionEvent : public nsIStkDownloadEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKLANGUAGESELECTIONEVENT_IID)

  /* readonly attribute DOMString language; */
  NS_IMETHOD GetLanguage(nsAString & aLanguage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkLanguageSelectionEvent, NS_ISTKLANGUAGESELECTIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKLANGUAGESELECTIONEVENT \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKLANGUAGESELECTIONEVENT(_to) \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) override { return _to GetLanguage(aLanguage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKLANGUAGESELECTIONEVENT(_to) \
  NS_IMETHOD GetLanguage(nsAString & aLanguage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLanguage(aLanguage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkLanguageSelectionEvent : public nsIStkLanguageSelectionEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKLANGUAGESELECTIONEVENT

  nsStkLanguageSelectionEvent();

private:
  ~nsStkLanguageSelectionEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkLanguageSelectionEvent, nsIStkLanguageSelectionEvent)

nsStkLanguageSelectionEvent::nsStkLanguageSelectionEvent()
{
  /* member initializers and constructor code */
}

nsStkLanguageSelectionEvent::~nsStkLanguageSelectionEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString language; */
NS_IMETHODIMP nsStkLanguageSelectionEvent::GetLanguage(nsAString & aLanguage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStkBrowserTerminationEvent */
#define NS_ISTKBROWSERTERMINATIONEVENT_IID_STR "7ae84bde-0059-11e5-8238-8ba12036dc26"

#define NS_ISTKBROWSERTERMINATIONEVENT_IID \
  {0x7ae84bde, 0x0059, 0x11e5, \
    { 0x82, 0x38, 0x8b, 0xa1, 0x20, 0x36, 0xdc, 0x26 }}

class NS_NO_VTABLE nsIStkBrowserTerminationEvent : public nsIStkDownloadEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTKBROWSERTERMINATIONEVENT_IID)

  enum {
    BROWSER_TERMINATION_CAUSE_USER = 0U,
    BROWSER_TERMINATION_CAUSE_ERROR = 1U
  };

  /* readonly attribute unsigned short terminationCause; */
  NS_IMETHOD GetTerminationCause(uint16_t *aTerminationCause) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStkBrowserTerminationEvent, NS_ISTKBROWSERTERMINATIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTKBROWSERTERMINATIONEVENT \
  NS_IMETHOD GetTerminationCause(uint16_t *aTerminationCause) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTKBROWSERTERMINATIONEVENT(_to) \
  NS_IMETHOD GetTerminationCause(uint16_t *aTerminationCause) override { return _to GetTerminationCause(aTerminationCause); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTKBROWSERTERMINATIONEVENT(_to) \
  NS_IMETHOD GetTerminationCause(uint16_t *aTerminationCause) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTerminationCause(aTerminationCause); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStkBrowserTerminationEvent : public nsIStkBrowserTerminationEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTKBROWSERTERMINATIONEVENT

  nsStkBrowserTerminationEvent();

private:
  ~nsStkBrowserTerminationEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsStkBrowserTerminationEvent, nsIStkBrowserTerminationEvent)

nsStkBrowserTerminationEvent::nsStkBrowserTerminationEvent()
{
  /* member initializers and constructor code */
}

nsStkBrowserTerminationEvent::~nsStkBrowserTerminationEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned short terminationCause; */
NS_IMETHODIMP nsStkBrowserTerminationEvent::GetTerminationCause(uint16_t *aTerminationCause)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStkProactiveCmd_h__ */
