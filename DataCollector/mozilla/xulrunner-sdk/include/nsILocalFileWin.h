/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILocalFileWin.idl
 */

#ifndef __gen_nsILocalFileWin_h__
#define __gen_nsILocalFileWin_h__


#ifndef __gen_nsILocalFile_h__
#include "nsILocalFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
struct PRFileDesc;

/* starting interface:    nsILocalFileWin */
#define NS_ILOCALFILEWIN_IID_STR "e7a3a954-384b-4aeb-a5f7-55626b0de9be"

#define NS_ILOCALFILEWIN_IID \
  {0xe7a3a954, 0x384b, 0x4aeb, \
    { 0xa5, 0xf7, 0x55, 0x62, 0x6b, 0x0d, 0xe9, 0xbe }}

class NS_NO_VTABLE nsILocalFileWin : public nsILocalFile {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALFILEWIN_IID)

  /* AString getVersionInfoField (in string aField); */
  NS_IMETHOD GetVersionInfoField(const char * aField, nsAString & _retval) = 0;

  /* readonly attribute AString canonicalPath; */
  NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) = 0;

  /* [noscript] readonly attribute ACString nativeCanonicalPath; */
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) = 0;

  enum {
    WFA_SEARCH_INDEXED = 1U,
    WFA_READONLY = 2U,
    WFA_READWRITE = 4U
  };

  /* attribute unsigned long fileAttributesWin; */
  NS_IMETHOD GetFileAttributesWin(uint32_t *aFileAttributesWin) = 0;
  NS_IMETHOD SetFileAttributesWin(uint32_t aFileAttributesWin) = 0;

  /* void setShortcut ([optional] in nsIFile targetFile, [optional] in nsIFile workingDir, [optional] in wstring args, [optional] in wstring description, [optional] in nsIFile iconFile, [optional] in long iconIndex); */
  NS_IMETHOD SetShortcut(nsIFile *targetFile, nsIFile *workingDir, const char16_t * args, const char16_t * description, nsIFile *iconFile, int32_t iconIndex) = 0;

  /* [noscript] PRFileDescStar openNSPRFileDescShareDelete (in long flags, in long mode); */
  NS_IMETHOD OpenNSPRFileDescShareDelete(int32_t flags, int32_t mode, PRFileDesc **_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalFileWin, NS_ILOCALFILEWIN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALFILEWIN \
  NS_IMETHOD GetVersionInfoField(const char * aField, nsAString & _retval) override; \
  NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) override; \
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) override; \
  NS_IMETHOD GetFileAttributesWin(uint32_t *aFileAttributesWin) override; \
  NS_IMETHOD SetFileAttributesWin(uint32_t aFileAttributesWin) override; \
  NS_IMETHOD SetShortcut(nsIFile *targetFile, nsIFile *workingDir, const char16_t * args, const char16_t * description, nsIFile *iconFile, int32_t iconIndex) override; \
  NS_IMETHOD OpenNSPRFileDescShareDelete(int32_t flags, int32_t mode, PRFileDesc **_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALFILEWIN(_to) \
  NS_IMETHOD GetVersionInfoField(const char * aField, nsAString & _retval) override { return _to GetVersionInfoField(aField, _retval); } \
  NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) override { return _to GetCanonicalPath(aCanonicalPath); } \
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) override { return _to GetNativeCanonicalPath(aNativeCanonicalPath); } \
  NS_IMETHOD GetFileAttributesWin(uint32_t *aFileAttributesWin) override { return _to GetFileAttributesWin(aFileAttributesWin); } \
  NS_IMETHOD SetFileAttributesWin(uint32_t aFileAttributesWin) override { return _to SetFileAttributesWin(aFileAttributesWin); } \
  NS_IMETHOD SetShortcut(nsIFile *targetFile, nsIFile *workingDir, const char16_t * args, const char16_t * description, nsIFile *iconFile, int32_t iconIndex) override { return _to SetShortcut(targetFile, workingDir, args, description, iconFile, iconIndex); } \
  NS_IMETHOD OpenNSPRFileDescShareDelete(int32_t flags, int32_t mode, PRFileDesc **_retval) override { return _to OpenNSPRFileDescShareDelete(flags, mode, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALFILEWIN(_to) \
  NS_IMETHOD GetVersionInfoField(const char * aField, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersionInfoField(aField, _retval); } \
  NS_IMETHOD GetCanonicalPath(nsAString & aCanonicalPath) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanonicalPath(aCanonicalPath); } \
  NS_IMETHOD GetNativeCanonicalPath(nsACString & aNativeCanonicalPath) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeCanonicalPath(aNativeCanonicalPath); } \
  NS_IMETHOD GetFileAttributesWin(uint32_t *aFileAttributesWin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileAttributesWin(aFileAttributesWin); } \
  NS_IMETHOD SetFileAttributesWin(uint32_t aFileAttributesWin) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFileAttributesWin(aFileAttributesWin); } \
  NS_IMETHOD SetShortcut(nsIFile *targetFile, nsIFile *workingDir, const char16_t * args, const char16_t * description, nsIFile *iconFile, int32_t iconIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShortcut(targetFile, workingDir, args, description, iconFile, iconIndex); } \
  NS_IMETHOD OpenNSPRFileDescShareDelete(int32_t flags, int32_t mode, PRFileDesc **_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenNSPRFileDescShareDelete(flags, mode, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalFileWin : public nsILocalFileWin
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALFILEWIN

  nsLocalFileWin();

private:
  ~nsLocalFileWin();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLocalFileWin, nsILocalFileWin)

nsLocalFileWin::nsLocalFileWin()
{
  /* member initializers and constructor code */
}

nsLocalFileWin::~nsLocalFileWin()
{
  /* destructor code */
}

/* AString getVersionInfoField (in string aField); */
NS_IMETHODIMP nsLocalFileWin::GetVersionInfoField(const char * aField, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString canonicalPath; */
NS_IMETHODIMP nsLocalFileWin::GetCanonicalPath(nsAString & aCanonicalPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute ACString nativeCanonicalPath; */
NS_IMETHODIMP nsLocalFileWin::GetNativeCanonicalPath(nsACString & aNativeCanonicalPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long fileAttributesWin; */
NS_IMETHODIMP nsLocalFileWin::GetFileAttributesWin(uint32_t *aFileAttributesWin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLocalFileWin::SetFileAttributesWin(uint32_t aFileAttributesWin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setShortcut ([optional] in nsIFile targetFile, [optional] in nsIFile workingDir, [optional] in wstring args, [optional] in wstring description, [optional] in nsIFile iconFile, [optional] in long iconIndex); */
NS_IMETHODIMP nsLocalFileWin::SetShortcut(nsIFile *targetFile, nsIFile *workingDir, const char16_t * args, const char16_t * description, nsIFile *iconFile, int32_t iconIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] PRFileDescStar openNSPRFileDescShareDelete (in long flags, in long mode); */
NS_IMETHODIMP nsLocalFileWin::OpenNSPRFileDescShareDelete(int32_t flags, int32_t mode, PRFileDesc **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILocalFileWin_h__ */
