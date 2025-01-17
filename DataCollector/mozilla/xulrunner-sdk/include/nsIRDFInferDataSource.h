/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRDFInferDataSource.idl
 */

#ifndef __gen_nsIRDFInferDataSource_h__
#define __gen_nsIRDFInferDataSource_h__


#ifndef __gen_nsIRDFDataSource_h__
#include "nsIRDFDataSource.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFInferDataSource */
#define NS_IRDFINFERDATASOURCE_IID_STR "2b04860f-4017-40f6-8a57-784a1e35077a"

#define NS_IRDFINFERDATASOURCE_IID \
  {0x2b04860f, 0x4017, 0x40f6, \
    { 0x8a, 0x57, 0x78, 0x4a, 0x1e, 0x35, 0x07, 0x7a }}

class NS_NO_VTABLE nsIRDFInferDataSource : public nsIRDFDataSource {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFINFERDATASOURCE_IID)

  /* attribute nsIRDFDataSource baseDataSource; */
  NS_IMETHOD GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource) = 0;
  NS_IMETHOD SetBaseDataSource(nsIRDFDataSource *aBaseDataSource) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFInferDataSource, NS_IRDFINFERDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFINFERDATASOURCE \
  NS_IMETHOD GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource) override; \
  NS_IMETHOD SetBaseDataSource(nsIRDFDataSource *aBaseDataSource) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFINFERDATASOURCE(_to) \
  NS_IMETHOD GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource) override { return _to GetBaseDataSource(aBaseDataSource); } \
  NS_IMETHOD SetBaseDataSource(nsIRDFDataSource *aBaseDataSource) override { return _to SetBaseDataSource(aBaseDataSource); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFINFERDATASOURCE(_to) \
  NS_IMETHOD GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseDataSource(aBaseDataSource); } \
  NS_IMETHOD SetBaseDataSource(nsIRDFDataSource *aBaseDataSource) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBaseDataSource(aBaseDataSource); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFInferDataSource : public nsIRDFInferDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFINFERDATASOURCE

  nsRDFInferDataSource();

private:
  ~nsRDFInferDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsRDFInferDataSource, nsIRDFInferDataSource)

nsRDFInferDataSource::nsRDFInferDataSource()
{
  /* member initializers and constructor code */
}

nsRDFInferDataSource::~nsRDFInferDataSource()
{
  /* destructor code */
}

/* attribute nsIRDFDataSource baseDataSource; */
NS_IMETHODIMP nsRDFInferDataSource::GetBaseDataSource(nsIRDFDataSource * *aBaseDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsRDFInferDataSource::SetBaseDataSource(nsIRDFDataSource *aBaseDataSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFInferDataSource_h__ */
