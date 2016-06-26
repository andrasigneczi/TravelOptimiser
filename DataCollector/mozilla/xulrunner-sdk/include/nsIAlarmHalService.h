/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAlarmHalService.idl
 */

#ifndef __gen_nsIAlarmHalService_h__
#define __gen_nsIAlarmHalService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAlarmFiredCb */
#define NS_IALARMFIREDCB_IID_STR "53dec7f9-bb51-4c3a-98ab-80d5d750c9dd"

#define NS_IALARMFIREDCB_IID \
  {0x53dec7f9, 0xbb51, 0x4c3a, \
    { 0x98, 0xab, 0x80, 0xd5, 0xd7, 0x50, 0xc9, 0xdd }}

class NS_NO_VTABLE nsIAlarmFiredCb : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IALARMFIREDCB_IID)

  /* void onAlarmFired (); */
  NS_IMETHOD OnAlarmFired(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAlarmFiredCb, NS_IALARMFIREDCB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIALARMFIREDCB \
  NS_IMETHOD OnAlarmFired(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIALARMFIREDCB(_to) \
  NS_IMETHOD OnAlarmFired(void) override { return _to OnAlarmFired(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIALARMFIREDCB(_to) \
  NS_IMETHOD OnAlarmFired(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAlarmFired(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAlarmFiredCb : public nsIAlarmFiredCb
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIALARMFIREDCB

  nsAlarmFiredCb();

private:
  ~nsAlarmFiredCb();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAlarmFiredCb, nsIAlarmFiredCb)

nsAlarmFiredCb::nsAlarmFiredCb()
{
  /* member initializers and constructor code */
}

nsAlarmFiredCb::~nsAlarmFiredCb()
{
  /* destructor code */
}

/* void onAlarmFired (); */
NS_IMETHODIMP nsAlarmFiredCb::OnAlarmFired()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITimezoneChangedCb */
#define NS_ITIMEZONECHANGEDCB_IID_STR "e6662911-c066-4358-9388-8661065c65a2"

#define NS_ITIMEZONECHANGEDCB_IID \
  {0xe6662911, 0xc066, 0x4358, \
    { 0x93, 0x88, 0x86, 0x61, 0x06, 0x5c, 0x65, 0xa2 }}

class NS_NO_VTABLE nsITimezoneChangedCb : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITIMEZONECHANGEDCB_IID)

  /* void onTimezoneChanged (in int32_t aTimezoneOffset); */
  NS_IMETHOD OnTimezoneChanged(int32_t aTimezoneOffset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITimezoneChangedCb, NS_ITIMEZONECHANGEDCB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITIMEZONECHANGEDCB \
  NS_IMETHOD OnTimezoneChanged(int32_t aTimezoneOffset) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITIMEZONECHANGEDCB(_to) \
  NS_IMETHOD OnTimezoneChanged(int32_t aTimezoneOffset) override { return _to OnTimezoneChanged(aTimezoneOffset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITIMEZONECHANGEDCB(_to) \
  NS_IMETHOD OnTimezoneChanged(int32_t aTimezoneOffset) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTimezoneChanged(aTimezoneOffset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTimezoneChangedCb : public nsITimezoneChangedCb
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITIMEZONECHANGEDCB

  nsTimezoneChangedCb();

private:
  ~nsTimezoneChangedCb();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTimezoneChangedCb, nsITimezoneChangedCb)

nsTimezoneChangedCb::nsTimezoneChangedCb()
{
  /* member initializers and constructor code */
}

nsTimezoneChangedCb::~nsTimezoneChangedCb()
{
  /* destructor code */
}

/* void onTimezoneChanged (in int32_t aTimezoneOffset); */
NS_IMETHODIMP nsTimezoneChangedCb::OnTimezoneChanged(int32_t aTimezoneOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISystemClockChangedCb */
#define NS_ISYSTEMCLOCKCHANGEDCB_IID_STR "46ece987-a3ec-4124-906f-d99c83296ac6"

#define NS_ISYSTEMCLOCKCHANGEDCB_IID \
  {0x46ece987, 0xa3ec, 0x4124, \
    { 0x90, 0x6f, 0xd9, 0x9c, 0x83, 0x29, 0x6a, 0xc6 }}

class NS_NO_VTABLE nsISystemClockChangedCb : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYSTEMCLOCKCHANGEDCB_IID)

  /* void onSystemClockChanged (in int32_t aClockDeltaMS); */
  NS_IMETHOD OnSystemClockChanged(int32_t aClockDeltaMS) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISystemClockChangedCb, NS_ISYSTEMCLOCKCHANGEDCB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYSTEMCLOCKCHANGEDCB \
  NS_IMETHOD OnSystemClockChanged(int32_t aClockDeltaMS) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYSTEMCLOCKCHANGEDCB(_to) \
  NS_IMETHOD OnSystemClockChanged(int32_t aClockDeltaMS) override { return _to OnSystemClockChanged(aClockDeltaMS); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYSTEMCLOCKCHANGEDCB(_to) \
  NS_IMETHOD OnSystemClockChanged(int32_t aClockDeltaMS) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSystemClockChanged(aClockDeltaMS); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSystemClockChangedCb : public nsISystemClockChangedCb
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYSTEMCLOCKCHANGEDCB

  nsSystemClockChangedCb();

private:
  ~nsSystemClockChangedCb();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsSystemClockChangedCb, nsISystemClockChangedCb)

nsSystemClockChangedCb::nsSystemClockChangedCb()
{
  /* member initializers and constructor code */
}

nsSystemClockChangedCb::~nsSystemClockChangedCb()
{
  /* destructor code */
}

/* void onSystemClockChanged (in int32_t aClockDeltaMS); */
NS_IMETHODIMP nsSystemClockChangedCb::OnSystemClockChanged(int32_t aClockDeltaMS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_ALARMHALSERVICE_CID { 0x7dafea4c, 0x7163, 0x4b70, { 0x95, 0x4e, 0x5a, 0xd4, 0x09, 0x94, 0x83, 0xd7 } }
#define ALARMHALSERVICE_CONTRACTID "@mozilla.org/alarmHalService;1"

/* starting interface:    nsIAlarmHalService */
#define NS_IALARMHALSERVICE_IID_STR "35074214-f50d-4f9a-b173-8d564dfa657d"

#define NS_IALARMHALSERVICE_IID \
  {0x35074214, 0xf50d, 0x4f9a, \
    { 0xb1, 0x73, 0x8d, 0x56, 0x4d, 0xfa, 0x65, 0x7d }}

class NS_NO_VTABLE nsIAlarmHalService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IALARMHALSERVICE_IID)

  /* bool setAlarm (in int32_t aSeconds, in int32_t aNanoseconds); */
  NS_IMETHOD SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval) = 0;

  /* void setAlarmFiredCb (in nsIAlarmFiredCb aAlarmFiredCb); */
  NS_IMETHOD SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb) = 0;

  /* void setTimezoneChangedCb (in nsITimezoneChangedCb aTimezoneChangedCb); */
  NS_IMETHOD SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb) = 0;

  /* void setSystemClockChangedCb (in nsISystemClockChangedCb aSystemClockChangedCb); */
  NS_IMETHOD SetSystemClockChangedCb(nsISystemClockChangedCb *aSystemClockChangedCb) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAlarmHalService, NS_IALARMHALSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIALARMHALSERVICE \
  NS_IMETHOD SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval) override; \
  NS_IMETHOD SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb) override; \
  NS_IMETHOD SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb) override; \
  NS_IMETHOD SetSystemClockChangedCb(nsISystemClockChangedCb *aSystemClockChangedCb) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIALARMHALSERVICE(_to) \
  NS_IMETHOD SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval) override { return _to SetAlarm(aSeconds, aNanoseconds, _retval); } \
  NS_IMETHOD SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb) override { return _to SetAlarmFiredCb(aAlarmFiredCb); } \
  NS_IMETHOD SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb) override { return _to SetTimezoneChangedCb(aTimezoneChangedCb); } \
  NS_IMETHOD SetSystemClockChangedCb(nsISystemClockChangedCb *aSystemClockChangedCb) override { return _to SetSystemClockChangedCb(aSystemClockChangedCb); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIALARMHALSERVICE(_to) \
  NS_IMETHOD SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlarm(aSeconds, aNanoseconds, _retval); } \
  NS_IMETHOD SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlarmFiredCb(aAlarmFiredCb); } \
  NS_IMETHOD SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimezoneChangedCb(aTimezoneChangedCb); } \
  NS_IMETHOD SetSystemClockChangedCb(nsISystemClockChangedCb *aSystemClockChangedCb) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSystemClockChangedCb(aSystemClockChangedCb); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAlarmHalService : public nsIAlarmHalService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIALARMHALSERVICE

  nsAlarmHalService();

private:
  ~nsAlarmHalService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsAlarmHalService, nsIAlarmHalService)

nsAlarmHalService::nsAlarmHalService()
{
  /* member initializers and constructor code */
}

nsAlarmHalService::~nsAlarmHalService()
{
  /* destructor code */
}

/* bool setAlarm (in int32_t aSeconds, in int32_t aNanoseconds); */
NS_IMETHODIMP nsAlarmHalService::SetAlarm(int32_t aSeconds, int32_t aNanoseconds, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAlarmFiredCb (in nsIAlarmFiredCb aAlarmFiredCb); */
NS_IMETHODIMP nsAlarmHalService::SetAlarmFiredCb(nsIAlarmFiredCb *aAlarmFiredCb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTimezoneChangedCb (in nsITimezoneChangedCb aTimezoneChangedCb); */
NS_IMETHODIMP nsAlarmHalService::SetTimezoneChangedCb(nsITimezoneChangedCb *aTimezoneChangedCb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSystemClockChangedCb (in nsISystemClockChangedCb aSystemClockChangedCb); */
NS_IMETHODIMP nsAlarmHalService::SetSystemClockChangedCb(nsISystemClockChangedCb *aSystemClockChangedCb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAlarmHalService_h__ */
