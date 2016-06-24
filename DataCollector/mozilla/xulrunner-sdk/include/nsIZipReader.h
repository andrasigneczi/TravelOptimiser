/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIZipReader.idl
 */

#ifndef __gen_nsIZipReader_h__
#define __gen_nsIZipReader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
struct PRFileDesc;
class nsIUTF8StringEnumerator; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIX509Cert; /* forward declaration */


/* starting interface:    nsIZipEntry */
#define NS_IZIPENTRY_IID_STR "fad6f72f-13d8-4e26-9173-53007a4afe71"

#define NS_IZIPENTRY_IID \
  {0xfad6f72f, 0x13d8, 0x4e26, \
    { 0x91, 0x73, 0x53, 0x00, 0x7a, 0x4a, 0xfe, 0x71 }}

class NS_NO_VTABLE nsIZipEntry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPENTRY_IID)

  /* readonly attribute unsigned short compression; */
  NS_IMETHOD GetCompression(uint16_t *aCompression) = 0;

  /* readonly attribute unsigned long size; */
  NS_IMETHOD GetSize(uint32_t *aSize) = 0;

  /* readonly attribute unsigned long realSize; */
  NS_IMETHOD GetRealSize(uint32_t *aRealSize) = 0;

  /* readonly attribute unsigned long CRC32; */
  NS_IMETHOD GetCRC32(uint32_t *aCRC32) = 0;

  /* readonly attribute boolean isDirectory; */
  NS_IMETHOD GetIsDirectory(bool *aIsDirectory) = 0;

  /* readonly attribute PRTime lastModifiedTime; */
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) = 0;

  /* readonly attribute boolean isSynthetic; */
  NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) = 0;

  /* readonly attribute unsigned long permissions; */
  NS_IMETHOD GetPermissions(uint32_t *aPermissions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipEntry, NS_IZIPENTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPENTRY \
  NS_IMETHOD GetCompression(uint16_t *aCompression) override; \
  NS_IMETHOD GetSize(uint32_t *aSize) override; \
  NS_IMETHOD GetRealSize(uint32_t *aRealSize) override; \
  NS_IMETHOD GetCRC32(uint32_t *aCRC32) override; \
  NS_IMETHOD GetIsDirectory(bool *aIsDirectory) override; \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) override; \
  NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) override; \
  NS_IMETHOD GetPermissions(uint32_t *aPermissions) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPENTRY(_to) \
  NS_IMETHOD GetCompression(uint16_t *aCompression) override { return _to GetCompression(aCompression); } \
  NS_IMETHOD GetSize(uint32_t *aSize) override { return _to GetSize(aSize); } \
  NS_IMETHOD GetRealSize(uint32_t *aRealSize) override { return _to GetRealSize(aRealSize); } \
  NS_IMETHOD GetCRC32(uint32_t *aCRC32) override { return _to GetCRC32(aCRC32); } \
  NS_IMETHOD GetIsDirectory(bool *aIsDirectory) override { return _to GetIsDirectory(aIsDirectory); } \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) override { return _to GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) override { return _to GetIsSynthetic(aIsSynthetic); } \
  NS_IMETHOD GetPermissions(uint32_t *aPermissions) override { return _to GetPermissions(aPermissions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPENTRY(_to) \
  NS_IMETHOD GetCompression(uint16_t *aCompression) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompression(aCompression); } \
  NS_IMETHOD GetSize(uint32_t *aSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_IMETHOD GetRealSize(uint32_t *aRealSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealSize(aRealSize); } \
  NS_IMETHOD GetCRC32(uint32_t *aCRC32) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCRC32(aCRC32); } \
  NS_IMETHOD GetIsDirectory(bool *aIsDirectory) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDirectory(aIsDirectory); } \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSynthetic(aIsSynthetic); } \
  NS_IMETHOD GetPermissions(uint32_t *aPermissions) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermissions(aPermissions); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipEntry : public nsIZipEntry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPENTRY

  nsZipEntry();

private:
  ~nsZipEntry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsZipEntry, nsIZipEntry)

nsZipEntry::nsZipEntry()
{
  /* member initializers and constructor code */
}

nsZipEntry::~nsZipEntry()
{
  /* destructor code */
}

/* readonly attribute unsigned short compression; */
NS_IMETHODIMP nsZipEntry::GetCompression(uint16_t *aCompression)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long size; */
NS_IMETHODIMP nsZipEntry::GetSize(uint32_t *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long realSize; */
NS_IMETHODIMP nsZipEntry::GetRealSize(uint32_t *aRealSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long CRC32; */
NS_IMETHODIMP nsZipEntry::GetCRC32(uint32_t *aCRC32)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDirectory; */
NS_IMETHODIMP nsZipEntry::GetIsDirectory(bool *aIsDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModifiedTime; */
NS_IMETHODIMP nsZipEntry::GetLastModifiedTime(PRTime *aLastModifiedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSynthetic; */
NS_IMETHODIMP nsZipEntry::GetIsSynthetic(bool *aIsSynthetic)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long permissions; */
NS_IMETHODIMP nsZipEntry::GetPermissions(uint32_t *aPermissions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIZipReader */
#define NS_IZIPREADER_IID_STR "9ba4ef54-e0a0-4f65-9d23-128482448885"

#define NS_IZIPREADER_IID \
  {0x9ba4ef54, 0xe0a0, 0x4f65, \
    { 0x9d, 0x23, 0x12, 0x84, 0x82, 0x44, 0x88, 0x85 }}

class NS_NO_VTABLE nsIZipReader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPREADER_IID)

  /* void open (in nsIFile zipFile); */
  NS_IMETHOD Open(nsIFile *zipFile) = 0;

  /* void openInner (in nsIZipReader zipReader, in AUTF8String zipEntry); */
  NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) = 0;

  /* void openMemory (in voidPtr aData, in unsigned long aLength); */
  NS_IMETHOD OpenMemory(void *aData, uint32_t aLength) = 0;

  /* readonly attribute nsIFile file; */
  NS_IMETHOD GetFile(nsIFile * *aFile) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void test (in AUTF8String aEntryName); */
  NS_IMETHOD Test(const nsACString & aEntryName) = 0;

  /* void extract (in AUTF8String zipEntry, in nsIFile outFile); */
  NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) = 0;

  /* nsIZipEntry getEntry (in AUTF8String zipEntry); */
  NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval) = 0;

  /* boolean hasEntry (in AUTF8String zipEntry); */
  NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval) = 0;

  /* nsIUTF8StringEnumerator findEntries (in AUTF8String aPattern); */
  NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval) = 0;

  /* nsIInputStream getInputStream (in AUTF8String zipEntry); */
  NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval) = 0;

  /* nsIInputStream getInputStreamWithSpec (in AUTF8String aJarSpec, in AUTF8String zipEntry); */
  NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval) = 0;

  /* nsIX509Cert getSigningCert (in AUTF8String aEntryName); */
  NS_IMETHOD GetSigningCert(const nsACString & aEntryName, nsIX509Cert * *_retval) = 0;

  /* readonly attribute uint32_t manifestEntriesCount; */
  NS_IMETHOD GetManifestEntriesCount(uint32_t *aManifestEntriesCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipReader, NS_IZIPREADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPREADER \
  NS_IMETHOD Open(nsIFile *zipFile) override; \
  NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) override; \
  NS_IMETHOD OpenMemory(void *aData, uint32_t aLength) override; \
  NS_IMETHOD GetFile(nsIFile * *aFile) override; \
  NS_IMETHOD Close(void) override; \
  NS_IMETHOD Test(const nsACString & aEntryName) override; \
  NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) override; \
  NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval) override; \
  NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval) override; \
  NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval) override; \
  NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval) override; \
  NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval) override; \
  NS_IMETHOD GetSigningCert(const nsACString & aEntryName, nsIX509Cert * *_retval) override; \
  NS_IMETHOD GetManifestEntriesCount(uint32_t *aManifestEntriesCount) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPREADER(_to) \
  NS_IMETHOD Open(nsIFile *zipFile) override { return _to Open(zipFile); } \
  NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) override { return _to OpenInner(zipReader, zipEntry); } \
  NS_IMETHOD OpenMemory(void *aData, uint32_t aLength) override { return _to OpenMemory(aData, aLength); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) override { return _to GetFile(aFile); } \
  NS_IMETHOD Close(void) override { return _to Close(); } \
  NS_IMETHOD Test(const nsACString & aEntryName) override { return _to Test(aEntryName); } \
  NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) override { return _to Extract(zipEntry, outFile); } \
  NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval) override { return _to GetEntry(zipEntry, _retval); } \
  NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval) override { return _to HasEntry(zipEntry, _retval); } \
  NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval) override { return _to FindEntries(aPattern, _retval); } \
  NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval) override { return _to GetInputStream(zipEntry, _retval); } \
  NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval) override { return _to GetInputStreamWithSpec(aJarSpec, zipEntry, _retval); } \
  NS_IMETHOD GetSigningCert(const nsACString & aEntryName, nsIX509Cert * *_retval) override { return _to GetSigningCert(aEntryName, _retval); } \
  NS_IMETHOD GetManifestEntriesCount(uint32_t *aManifestEntriesCount) override { return _to GetManifestEntriesCount(aManifestEntriesCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPREADER(_to) \
  NS_IMETHOD Open(nsIFile *zipFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(zipFile); } \
  NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenInner(zipReader, zipEntry); } \
  NS_IMETHOD OpenMemory(void *aData, uint32_t aLength) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenMemory(aData, aLength); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } \
  NS_IMETHOD Close(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Test(const nsACString & aEntryName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Test(aEntryName); } \
  NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Extract(zipEntry, outFile); } \
  NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntry(zipEntry, _retval); } \
  NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasEntry(zipEntry, _retval); } \
  NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEntries(aPattern, _retval); } \
  NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStream(zipEntry, _retval); } \
  NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStreamWithSpec(aJarSpec, zipEntry, _retval); } \
  NS_IMETHOD GetSigningCert(const nsACString & aEntryName, nsIX509Cert * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSigningCert(aEntryName, _retval); } \
  NS_IMETHOD GetManifestEntriesCount(uint32_t *aManifestEntriesCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestEntriesCount(aManifestEntriesCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipReader : public nsIZipReader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPREADER

  nsZipReader();

private:
  ~nsZipReader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsZipReader, nsIZipReader)

nsZipReader::nsZipReader()
{
  /* member initializers and constructor code */
}

nsZipReader::~nsZipReader()
{
  /* destructor code */
}

/* void open (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReader::Open(nsIFile *zipFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openInner (in nsIZipReader zipReader, in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openMemory (in voidPtr aData, in unsigned long aLength); */
NS_IMETHODIMP nsZipReader::OpenMemory(void *aData, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile file; */
NS_IMETHODIMP nsZipReader::GetFile(nsIFile * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsZipReader::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void test (in AUTF8String aEntryName); */
NS_IMETHODIMP nsZipReader::Test(const nsACString & aEntryName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void extract (in AUTF8String zipEntry, in nsIFile outFile); */
NS_IMETHODIMP nsZipReader::Extract(const nsACString & zipEntry, nsIFile *outFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipEntry getEntry (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasEntry (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::HasEntry(const nsACString & zipEntry, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator findEntries (in AUTF8String aPattern); */
NS_IMETHODIMP nsZipReader::FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getInputStream (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getInputStreamWithSpec (in AUTF8String aJarSpec, in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIX509Cert getSigningCert (in AUTF8String aEntryName); */
NS_IMETHODIMP nsZipReader::GetSigningCert(const nsACString & aEntryName, nsIX509Cert * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t manifestEntriesCount; */
NS_IMETHODIMP nsZipReader::GetManifestEntriesCount(uint32_t *aManifestEntriesCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIZipReaderCache */
#define NS_IZIPREADERCACHE_IID_STR "94ecd586-d405-4801-93d3-8ac7bef81bde"

#define NS_IZIPREADERCACHE_IID \
  {0x94ecd586, 0xd405, 0x4801, \
    { 0x93, 0xd3, 0x8a, 0xc7, 0xbe, 0xf8, 0x1b, 0xde }}

class NS_NO_VTABLE nsIZipReaderCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPREADERCACHE_IID)

  /* void init (in unsigned long cacheSize); */
  NS_IMETHOD Init(uint32_t cacheSize) = 0;

  /* nsIZipReader getZip (in nsIFile zipFile); */
  NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval) = 0;

  /* bool isCached (in nsIFile zipFile); */
  NS_IMETHOD IsCached(nsIFile *zipFile, bool *_retval) = 0;

  /* nsIZipReader getInnerZip (in nsIFile zipFile, in AUTF8String zipEntry); */
  NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval) = 0;

  /* void setMustCacheFd (in nsIFile zipFile, in bool aMustCacheFd); */
  NS_IMETHOD SetMustCacheFd(nsIFile *zipFile, bool aMustCacheFd) = 0;

  /* PRFileDescStar getFd (in nsIFile zipFile); */
  NS_IMETHOD GetFd(nsIFile *zipFile, PRFileDesc **_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipReaderCache, NS_IZIPREADERCACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPREADERCACHE \
  NS_IMETHOD Init(uint32_t cacheSize) override; \
  NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval) override; \
  NS_IMETHOD IsCached(nsIFile *zipFile, bool *_retval) override; \
  NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval) override; \
  NS_IMETHOD SetMustCacheFd(nsIFile *zipFile, bool aMustCacheFd) override; \
  NS_IMETHOD GetFd(nsIFile *zipFile, PRFileDesc **_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPREADERCACHE(_to) \
  NS_IMETHOD Init(uint32_t cacheSize) override { return _to Init(cacheSize); } \
  NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval) override { return _to GetZip(zipFile, _retval); } \
  NS_IMETHOD IsCached(nsIFile *zipFile, bool *_retval) override { return _to IsCached(zipFile, _retval); } \
  NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval) override { return _to GetInnerZip(zipFile, zipEntry, _retval); } \
  NS_IMETHOD SetMustCacheFd(nsIFile *zipFile, bool aMustCacheFd) override { return _to SetMustCacheFd(zipFile, aMustCacheFd); } \
  NS_IMETHOD GetFd(nsIFile *zipFile, PRFileDesc **_retval) override { return _to GetFd(zipFile, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPREADERCACHE(_to) \
  NS_IMETHOD Init(uint32_t cacheSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(cacheSize); } \
  NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZip(zipFile, _retval); } \
  NS_IMETHOD IsCached(nsIFile *zipFile, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCached(zipFile, _retval); } \
  NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerZip(zipFile, zipEntry, _retval); } \
  NS_IMETHOD SetMustCacheFd(nsIFile *zipFile, bool aMustCacheFd) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMustCacheFd(zipFile, aMustCacheFd); } \
  NS_IMETHOD GetFd(nsIFile *zipFile, PRFileDesc **_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFd(zipFile, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipReaderCache : public nsIZipReaderCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPREADERCACHE

  nsZipReaderCache();

private:
  ~nsZipReaderCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsZipReaderCache, nsIZipReaderCache)

nsZipReaderCache::nsZipReaderCache()
{
  /* member initializers and constructor code */
}

nsZipReaderCache::~nsZipReaderCache()
{
  /* destructor code */
}

/* void init (in unsigned long cacheSize); */
NS_IMETHODIMP nsZipReaderCache::Init(uint32_t cacheSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipReader getZip (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReaderCache::GetZip(nsIFile *zipFile, nsIZipReader * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isCached (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReaderCache::IsCached(nsIFile *zipFile, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipReader getInnerZip (in nsIFile zipFile, in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReaderCache::GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setMustCacheFd (in nsIFile zipFile, in bool aMustCacheFd); */
NS_IMETHODIMP nsZipReaderCache::SetMustCacheFd(nsIFile *zipFile, bool aMustCacheFd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRFileDescStar getFd (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReaderCache::GetFd(nsIFile *zipFile, PRFileDesc **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_ZIPREADER_CID                             \
{ /* 88e2fd0b-f7f4-480c-9483-7846b00e8dad */         \
   0x88e2fd0b, 0xf7f4, 0x480c,                       \
  { 0x94, 0x83, 0x78, 0x46, 0xb0, 0x0e, 0x8d, 0xad } \
}
#define NS_ZIPREADERCACHE_CID                        \
{ /* 608b7f6f-4b60-40d6-87ed-d933bf53d8c1 */         \
   0x608b7f6f, 0x4b60, 0x40d6,                       \
  { 0x87, 0xed, 0xd9, 0x33, 0xbf, 0x53, 0xd8, 0xc1 } \
}

#endif /* __gen_nsIZipReader_h__ */
