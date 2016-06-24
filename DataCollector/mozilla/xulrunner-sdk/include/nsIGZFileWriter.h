/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIGZFileWriter.idl
 */

#ifndef __gen_nsIGZFileWriter_h__
#define __gen_nsIGZFileWriter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsDependentString.h"
#include <stdio.h>
class nsIFile; /* forward declaration */


/* starting interface:    nsIGZFileWriter */
#define NS_IGZFILEWRITER_IID_STR "6bd5642c-1b90-4499-ba4b-199f27efaba5"

#define NS_IGZFILEWRITER_IID \
  {0x6bd5642c, 0x1b90, 0x4499, \
    { 0xba, 0x4b, 0x19, 0x9f, 0x27, 0xef, 0xab, 0xa5 }}

class nsIGZFileWriter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGZFILEWRITER_IID)

  /* void init (in nsIFile file); */
  NS_IMETHOD Init(nsIFile *file) = 0;

  /* [noscript] void initANSIFileDesc (in FILE file); */
  NS_IMETHOD InitANSIFileDesc(FILE *file) = 0;

  /* void write (in AUTF8String str); */
  NS_IMETHOD Write(const nsACString & str) = 0;

   /**
   * Write the given char* to the file (not including the null-terminator).
   */
  nsresult Write(const char* str)
  {
    return Write(str, strlen(str));
  }
  /**
   * Write |length| bytes of |str| to the file.
   */
  nsresult Write(const char* str, uint32_t len)
  {
    return Write(nsDependentCString(str, len));
  }
    /* void finish (); */
  NS_IMETHOD Finish(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGZFileWriter, NS_IGZFILEWRITER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGZFILEWRITER \
  NS_IMETHOD Init(nsIFile *file) override; \
  NS_IMETHOD InitANSIFileDesc(FILE *file) override; \
  NS_IMETHOD Write(const nsACString & str) override; \
  NS_IMETHOD Finish(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGZFILEWRITER(_to) \
  NS_IMETHOD Init(nsIFile *file) override { return _to Init(file); } \
  NS_IMETHOD InitANSIFileDesc(FILE *file) override { return _to InitANSIFileDesc(file); } \
  NS_IMETHOD Write(const nsACString & str) override { return _to Write(str); } \
  NS_IMETHOD Finish(void) override { return _to Finish(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGZFILEWRITER(_to) \
  NS_IMETHOD Init(nsIFile *file) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(file); } \
  NS_IMETHOD InitANSIFileDesc(FILE *file) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InitANSIFileDesc(file); } \
  NS_IMETHOD Write(const nsACString & str) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Write(str); } \
  NS_IMETHOD Finish(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Finish(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGZFileWriter : public nsIGZFileWriter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGZFILEWRITER

  nsGZFileWriter();

private:
  ~nsGZFileWriter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsGZFileWriter, nsIGZFileWriter)

nsGZFileWriter::nsGZFileWriter()
{
  /* member initializers and constructor code */
}

nsGZFileWriter::~nsGZFileWriter()
{
  /* destructor code */
}

/* void init (in nsIFile file); */
NS_IMETHODIMP nsGZFileWriter::Init(nsIFile *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initANSIFileDesc (in FILE file); */
NS_IMETHODIMP nsGZFileWriter::InitANSIFileDesc(FILE *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void write (in AUTF8String str); */
NS_IMETHODIMP nsGZFileWriter::Write(const nsACString & str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finish (); */
NS_IMETHODIMP nsGZFileWriter::Finish()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGZFileWriter_h__ */
