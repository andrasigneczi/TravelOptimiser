/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILocalFile.idl
 */

#ifndef __gen_nsILocalFile_h__
#define __gen_nsILocalFile_h__


#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILocalFile */
#define NS_ILOCALFILE_IID_STR "7ba8c6ba-2ce2-48b1-bd60-4c32aac35f9c"

#define NS_ILOCALFILE_IID \
  {0x7ba8c6ba, 0x2ce2, 0x48b1, \
    { 0xbd, 0x60, 0x4c, 0x32, 0xaa, 0xc3, 0x5f, 0x9c }}

class NS_NO_VTABLE nsILocalFile : public nsIFile {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALFILE_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalFile, NS_ILOCALFILE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALFILE \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALFILE(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALFILE(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalFile : public nsILocalFile
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALFILE

  nsLocalFile();

private:
  ~nsLocalFile();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsLocalFile, nsILocalFile)

nsLocalFile::nsLocalFile()
{
  /* member initializers and constructor code */
}

nsLocalFile::~nsLocalFile()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILocalFile_h__ */
