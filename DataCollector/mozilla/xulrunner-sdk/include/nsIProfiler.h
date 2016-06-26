/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProfiler.idl
 */

#ifndef __gen_nsIProfiler_h__
#define __gen_nsIProfiler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
template<class T> class nsTArray;
class nsCString;

/* starting interface:    nsIProfiler */
#define NS_IPROFILER_IID_STR "921e1223-b1ea-4906-bb26-a846e6b6835b"

#define NS_IPROFILER_IID \
  {0x921e1223, 0xb1ea, 0x4906, \
    { 0xbb, 0x26, 0xa8, 0x46, 0xe6, 0xb6, 0x83, 0x5b }}

class NS_NO_VTABLE nsIProfiler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILER_IID)

  /* void StartProfiler (in uint32_t aEntries, in double aInterval, [array, size_is (aFeatureCount)] in string aFeatures, in uint32_t aFeatureCount, [array, size_is (aFilterCount), optional] in string aThreadNameFilters, [optional] in uint32_t aFilterCount); */
  NS_IMETHOD StartProfiler(uint32_t aEntries, double aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount) = 0;

  /* void StopProfiler (); */
  NS_IMETHOD StopProfiler(void) = 0;

  /* boolean IsPaused (); */
  NS_IMETHOD IsPaused(bool *_retval) = 0;

  /* void PauseSampling (); */
  NS_IMETHOD PauseSampling(void) = 0;

  /* void ResumeSampling (); */
  NS_IMETHOD ResumeSampling(void) = 0;

  /* void AddMarker (in string aMarker); */
  NS_IMETHOD AddMarker(const char * aMarker) = 0;

  /* string GetProfile ([optional] in double aSinceTime); */
  NS_IMETHOD GetProfile(double aSinceTime, char * *_retval) = 0;

  /* [implicit_jscontext] jsval getProfileData ([optional] in double aSinceTime); */
  NS_IMETHOD GetProfileData(double aSinceTime, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] nsISupports getProfileDataAsync ([optional] in double aSinceTime); */
  NS_IMETHOD GetProfileDataAsync(double aSinceTime, JSContext* cx, nsISupports * *_retval) = 0;

  /* boolean IsActive (); */
  NS_IMETHOD IsActive(bool *_retval) = 0;

  /* void GetFeatures (out uint32_t aCount, [array, size_is (aCount), retval] out string aFeatures); */
  NS_IMETHOD GetFeatures(uint32_t *aCount, char * **aFeatures) = 0;

  /* void GetBufferInfo (out uint32_t aCurrentPosition, out uint32_t aTotalSize, out uint32_t aGeneration); */
  NS_IMETHOD GetBufferInfo(uint32_t *aCurrentPosition, uint32_t *aTotalSize, uint32_t *aGeneration) = 0;

  /* double getElapsedTime (); */
  NS_IMETHOD GetElapsedTime(double *_retval) = 0;

  /* AString getSharedLibraryInformation (); */
  NS_IMETHOD GetSharedLibraryInformation(nsAString & _retval) = 0;

  /* void dumpProfileToFile (in string aFilename); */
  NS_IMETHOD DumpProfileToFile(const char * aFilename) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfiler, NS_IPROFILER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILER \
  NS_IMETHOD StartProfiler(uint32_t aEntries, double aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount) override; \
  NS_IMETHOD StopProfiler(void) override; \
  NS_IMETHOD IsPaused(bool *_retval) override; \
  NS_IMETHOD PauseSampling(void) override; \
  NS_IMETHOD ResumeSampling(void) override; \
  NS_IMETHOD AddMarker(const char * aMarker) override; \
  NS_IMETHOD GetProfile(double aSinceTime, char * *_retval) override; \
  NS_IMETHOD GetProfileData(double aSinceTime, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetProfileDataAsync(double aSinceTime, JSContext* cx, nsISupports * *_retval) override; \
  NS_IMETHOD IsActive(bool *_retval) override; \
  NS_IMETHOD GetFeatures(uint32_t *aCount, char * **aFeatures) override; \
  NS_IMETHOD GetBufferInfo(uint32_t *aCurrentPosition, uint32_t *aTotalSize, uint32_t *aGeneration) override; \
  NS_IMETHOD GetElapsedTime(double *_retval) override; \
  NS_IMETHOD GetSharedLibraryInformation(nsAString & _retval) override; \
  NS_IMETHOD DumpProfileToFile(const char * aFilename) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILER(_to) \
  NS_IMETHOD StartProfiler(uint32_t aEntries, double aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount) override { return _to StartProfiler(aEntries, aInterval, aFeatures, aFeatureCount, aThreadNameFilters, aFilterCount); } \
  NS_IMETHOD StopProfiler(void) override { return _to StopProfiler(); } \
  NS_IMETHOD IsPaused(bool *_retval) override { return _to IsPaused(_retval); } \
  NS_IMETHOD PauseSampling(void) override { return _to PauseSampling(); } \
  NS_IMETHOD ResumeSampling(void) override { return _to ResumeSampling(); } \
  NS_IMETHOD AddMarker(const char * aMarker) override { return _to AddMarker(aMarker); } \
  NS_IMETHOD GetProfile(double aSinceTime, char * *_retval) override { return _to GetProfile(aSinceTime, _retval); } \
  NS_IMETHOD GetProfileData(double aSinceTime, JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetProfileData(aSinceTime, cx, _retval); } \
  NS_IMETHOD GetProfileDataAsync(double aSinceTime, JSContext* cx, nsISupports * *_retval) override { return _to GetProfileDataAsync(aSinceTime, cx, _retval); } \
  NS_IMETHOD IsActive(bool *_retval) override { return _to IsActive(_retval); } \
  NS_IMETHOD GetFeatures(uint32_t *aCount, char * **aFeatures) override { return _to GetFeatures(aCount, aFeatures); } \
  NS_IMETHOD GetBufferInfo(uint32_t *aCurrentPosition, uint32_t *aTotalSize, uint32_t *aGeneration) override { return _to GetBufferInfo(aCurrentPosition, aTotalSize, aGeneration); } \
  NS_IMETHOD GetElapsedTime(double *_retval) override { return _to GetElapsedTime(_retval); } \
  NS_IMETHOD GetSharedLibraryInformation(nsAString & _retval) override { return _to GetSharedLibraryInformation(_retval); } \
  NS_IMETHOD DumpProfileToFile(const char * aFilename) override { return _to DumpProfileToFile(aFilename); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILER(_to) \
  NS_IMETHOD StartProfiler(uint32_t aEntries, double aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StartProfiler(aEntries, aInterval, aFeatures, aFeatureCount, aThreadNameFilters, aFilterCount); } \
  NS_IMETHOD StopProfiler(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->StopProfiler(); } \
  NS_IMETHOD IsPaused(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPaused(_retval); } \
  NS_IMETHOD PauseSampling(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PauseSampling(); } \
  NS_IMETHOD ResumeSampling(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeSampling(); } \
  NS_IMETHOD AddMarker(const char * aMarker) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddMarker(aMarker); } \
  NS_IMETHOD GetProfile(double aSinceTime, char * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfile(aSinceTime, _retval); } \
  NS_IMETHOD GetProfileData(double aSinceTime, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileData(aSinceTime, cx, _retval); } \
  NS_IMETHOD GetProfileDataAsync(double aSinceTime, JSContext* cx, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileDataAsync(aSinceTime, cx, _retval); } \
  NS_IMETHOD IsActive(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsActive(_retval); } \
  NS_IMETHOD GetFeatures(uint32_t *aCount, char * **aFeatures) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeatures(aCount, aFeatures); } \
  NS_IMETHOD GetBufferInfo(uint32_t *aCurrentPosition, uint32_t *aTotalSize, uint32_t *aGeneration) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBufferInfo(aCurrentPosition, aTotalSize, aGeneration); } \
  NS_IMETHOD GetElapsedTime(double *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElapsedTime(_retval); } \
  NS_IMETHOD GetSharedLibraryInformation(nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedLibraryInformation(_retval); } \
  NS_IMETHOD DumpProfileToFile(const char * aFilename) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpProfileToFile(aFilename); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfiler : public nsIProfiler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILER

  nsProfiler();

private:
  ~nsProfiler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProfiler, nsIProfiler)

nsProfiler::nsProfiler()
{
  /* member initializers and constructor code */
}

nsProfiler::~nsProfiler()
{
  /* destructor code */
}

/* void StartProfiler (in uint32_t aEntries, in double aInterval, [array, size_is (aFeatureCount)] in string aFeatures, in uint32_t aFeatureCount, [array, size_is (aFilterCount), optional] in string aThreadNameFilters, [optional] in uint32_t aFilterCount); */
NS_IMETHODIMP nsProfiler::StartProfiler(uint32_t aEntries, double aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void StopProfiler (); */
NS_IMETHODIMP nsProfiler::StopProfiler()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsPaused (); */
NS_IMETHODIMP nsProfiler::IsPaused(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void PauseSampling (); */
NS_IMETHODIMP nsProfiler::PauseSampling()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ResumeSampling (); */
NS_IMETHODIMP nsProfiler::ResumeSampling()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddMarker (in string aMarker); */
NS_IMETHODIMP nsProfiler::AddMarker(const char * aMarker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string GetProfile ([optional] in double aSinceTime); */
NS_IMETHODIMP nsProfiler::GetProfile(double aSinceTime, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getProfileData ([optional] in double aSinceTime); */
NS_IMETHODIMP nsProfiler::GetProfileData(double aSinceTime, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsISupports getProfileDataAsync ([optional] in double aSinceTime); */
NS_IMETHODIMP nsProfiler::GetProfileDataAsync(double aSinceTime, JSContext* cx, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsActive (); */
NS_IMETHODIMP nsProfiler::IsActive(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetFeatures (out uint32_t aCount, [array, size_is (aCount), retval] out string aFeatures); */
NS_IMETHODIMP nsProfiler::GetFeatures(uint32_t *aCount, char * **aFeatures)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetBufferInfo (out uint32_t aCurrentPosition, out uint32_t aTotalSize, out uint32_t aGeneration); */
NS_IMETHODIMP nsProfiler::GetBufferInfo(uint32_t *aCurrentPosition, uint32_t *aTotalSize, uint32_t *aGeneration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double getElapsedTime (); */
NS_IMETHODIMP nsProfiler::GetElapsedTime(double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getSharedLibraryInformation (); */
NS_IMETHODIMP nsProfiler::GetSharedLibraryInformation(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpProfileToFile (in string aFilename); */
NS_IMETHODIMP nsProfiler::DumpProfileToFile(const char * aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIProfilerStartParams */
#define NS_IPROFILERSTARTPARAMS_IID_STR "0a175ba7-8fcf-4ce9-9c4b-ccc6272f4425"

#define NS_IPROFILERSTARTPARAMS_IID \
  {0x0a175ba7, 0x8fcf, 0x4ce9, \
    { 0x9c, 0x4b, 0xcc, 0xc6, 0x27, 0x2f, 0x44, 0x25 }}

class NS_NO_VTABLE nsIProfilerStartParams : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILERSTARTPARAMS_IID)

  /* attribute uint32_t entries; */
  NS_IMETHOD GetEntries(uint32_t *aEntries) = 0;
  NS_IMETHOD SetEntries(uint32_t aEntries) = 0;

  /* attribute double interval; */
  NS_IMETHOD GetInterval(double *aInterval) = 0;
  NS_IMETHOD SetInterval(double aInterval) = 0;

  /* [noscript,nostdcall,notxpcom] StringArrayRef getFeatures (); */
  virtual const nsTArray<nsCString> & GetFeatures(void) = 0;

  /* [noscript,nostdcall,notxpcom] StringArrayRef getThreadFilterNames (); */
  virtual const nsTArray<nsCString> & GetThreadFilterNames(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfilerStartParams, NS_IPROFILERSTARTPARAMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILERSTARTPARAMS \
  NS_IMETHOD GetEntries(uint32_t *aEntries) override; \
  NS_IMETHOD SetEntries(uint32_t aEntries) override; \
  NS_IMETHOD GetInterval(double *aInterval) override; \
  NS_IMETHOD SetInterval(double aInterval) override; \
  virtual const nsTArray<nsCString> & GetFeatures(void) override; \
  virtual const nsTArray<nsCString> & GetThreadFilterNames(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILERSTARTPARAMS(_to) \
  NS_IMETHOD GetEntries(uint32_t *aEntries) override { return _to GetEntries(aEntries); } \
  NS_IMETHOD SetEntries(uint32_t aEntries) override { return _to SetEntries(aEntries); } \
  NS_IMETHOD GetInterval(double *aInterval) override { return _to GetInterval(aInterval); } \
  NS_IMETHOD SetInterval(double aInterval) override { return _to SetInterval(aInterval); } \
  virtual const nsTArray<nsCString> & GetFeatures(void) override { return _to GetFeatures(); } \
  virtual const nsTArray<nsCString> & GetThreadFilterNames(void) override { return _to GetThreadFilterNames(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILERSTARTPARAMS(_to) \
  NS_IMETHOD GetEntries(uint32_t *aEntries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntries(aEntries); } \
  NS_IMETHOD SetEntries(uint32_t aEntries) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEntries(aEntries); } \
  NS_IMETHOD GetInterval(double *aInterval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterval(aInterval); } \
  NS_IMETHOD SetInterval(double aInterval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInterval(aInterval); } \
  virtual const nsTArray<nsCString> & GetFeatures(void) override; \
  virtual const nsTArray<nsCString> & GetThreadFilterNames(void) override; 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfilerStartParams : public nsIProfilerStartParams
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILERSTARTPARAMS

  nsProfilerStartParams();

private:
  ~nsProfilerStartParams();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsProfilerStartParams, nsIProfilerStartParams)

nsProfilerStartParams::nsProfilerStartParams()
{
  /* member initializers and constructor code */
}

nsProfilerStartParams::~nsProfilerStartParams()
{
  /* destructor code */
}

/* attribute uint32_t entries; */
NS_IMETHODIMP nsProfilerStartParams::GetEntries(uint32_t *aEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsProfilerStartParams::SetEntries(uint32_t aEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double interval; */
NS_IMETHODIMP nsProfilerStartParams::GetInterval(double *aInterval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsProfilerStartParams::SetInterval(double aInterval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] StringArrayRef getFeatures (); */
const nsTArray<nsCString> & nsProfilerStartParams::GetFeatures()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] StringArrayRef getThreadFilterNames (); */
const nsTArray<nsCString> & nsProfilerStartParams::GetThreadFilterNames()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProfiler_h__ */
