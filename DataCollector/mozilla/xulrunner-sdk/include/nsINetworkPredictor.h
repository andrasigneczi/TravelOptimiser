/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINetworkPredictor.idl
 */

#ifndef __gen_nsINetworkPredictor_h__
#define __gen_nsINetworkPredictor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsILoadContext; /* forward declaration */

class nsINetworkPredictorVerifier; /* forward declaration */

typedef uint32_t  PredictorPredictReason;

typedef uint32_t  PredictorLearnReason;


/* starting interface:    nsINetworkPredictor */
#define NS_INETWORKPREDICTOR_IID_STR "acc88e7c-3f39-42c7-ac31-6377c2c3d73e"

#define NS_INETWORKPREDICTOR_IID \
  {0xacc88e7c, 0x3f39, 0x42c7, \
    { 0xac, 0x31, 0x63, 0x77, 0xc2, 0xc3, 0xd7, 0x3e }}

class NS_NO_VTABLE nsINetworkPredictor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INETWORKPREDICTOR_IID)

  enum {
    PREDICT_LINK = 0U,
    PREDICT_LOAD = 1U,
    PREDICT_STARTUP = 2U
  };

  /* void predict (in nsIURI targetURI, in nsIURI sourceURI, in PredictorPredictReason reason, in nsILoadContext loadContext, in nsINetworkPredictorVerifier verifier); */
  NS_IMETHOD Predict(nsIURI *targetURI, nsIURI *sourceURI, PredictorPredictReason reason, nsILoadContext *loadContext, nsINetworkPredictorVerifier *verifier) = 0;

  enum {
    LEARN_LOAD_TOPLEVEL = 0U,
    LEARN_LOAD_SUBRESOURCE = 1U,
    LEARN_LOAD_REDIRECT = 2U,
    LEARN_STARTUP = 3U
  };

  /* void learn (in nsIURI targetURI, in nsIURI sourceURI, in PredictorLearnReason reason, in nsILoadContext loadContext); */
  NS_IMETHOD Learn(nsIURI *targetURI, nsIURI *sourceURI, PredictorLearnReason reason, nsILoadContext *loadContext) = 0;

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINetworkPredictor, NS_INETWORKPREDICTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINETWORKPREDICTOR \
  NS_IMETHOD Predict(nsIURI *targetURI, nsIURI *sourceURI, PredictorPredictReason reason, nsILoadContext *loadContext, nsINetworkPredictorVerifier *verifier) override; \
  NS_IMETHOD Learn(nsIURI *targetURI, nsIURI *sourceURI, PredictorLearnReason reason, nsILoadContext *loadContext) override; \
  NS_IMETHOD Reset(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINETWORKPREDICTOR(_to) \
  NS_IMETHOD Predict(nsIURI *targetURI, nsIURI *sourceURI, PredictorPredictReason reason, nsILoadContext *loadContext, nsINetworkPredictorVerifier *verifier) override { return _to Predict(targetURI, sourceURI, reason, loadContext, verifier); } \
  NS_IMETHOD Learn(nsIURI *targetURI, nsIURI *sourceURI, PredictorLearnReason reason, nsILoadContext *loadContext) override { return _to Learn(targetURI, sourceURI, reason, loadContext); } \
  NS_IMETHOD Reset(void) override { return _to Reset(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINETWORKPREDICTOR(_to) \
  NS_IMETHOD Predict(nsIURI *targetURI, nsIURI *sourceURI, PredictorPredictReason reason, nsILoadContext *loadContext, nsINetworkPredictorVerifier *verifier) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Predict(targetURI, sourceURI, reason, loadContext, verifier); } \
  NS_IMETHOD Learn(nsIURI *targetURI, nsIURI *sourceURI, PredictorLearnReason reason, nsILoadContext *loadContext) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Learn(targetURI, sourceURI, reason, loadContext); } \
  NS_IMETHOD Reset(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNetworkPredictor : public nsINetworkPredictor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINETWORKPREDICTOR

  nsNetworkPredictor();

private:
  ~nsNetworkPredictor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNetworkPredictor, nsINetworkPredictor)

nsNetworkPredictor::nsNetworkPredictor()
{
  /* member initializers and constructor code */
}

nsNetworkPredictor::~nsNetworkPredictor()
{
  /* destructor code */
}

/* void predict (in nsIURI targetURI, in nsIURI sourceURI, in PredictorPredictReason reason, in nsILoadContext loadContext, in nsINetworkPredictorVerifier verifier); */
NS_IMETHODIMP nsNetworkPredictor::Predict(nsIURI *targetURI, nsIURI *sourceURI, PredictorPredictReason reason, nsILoadContext *loadContext, nsINetworkPredictorVerifier *verifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void learn (in nsIURI targetURI, in nsIURI sourceURI, in PredictorLearnReason reason, in nsILoadContext loadContext); */
NS_IMETHODIMP nsNetworkPredictor::Learn(nsIURI *targetURI, nsIURI *sourceURI, PredictorLearnReason reason, nsILoadContext *loadContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reset (); */
NS_IMETHODIMP nsNetworkPredictor::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// Wrapper functions to make use of the predictor easier and less invasive
class nsIChannel;
class nsIDocument;
class nsILoadContext;
class nsILoadGroup;
class nsINetworkPredictorVerifier;
namespace mozilla {
namespace net {
nsresult PredictorPredict(nsIURI *targetURI,
                          nsIURI *sourceURI,
                          PredictorPredictReason reason,
                          nsILoadContext *loadContext,
                          nsINetworkPredictorVerifier *verifier);
nsresult PredictorLearn(nsIURI *targetURI,
                        nsIURI *sourceURI,
                        PredictorLearnReason reason,
                        nsILoadContext *loadContext);
nsresult PredictorLearn(nsIURI *targetURI,
                        nsIURI *sourceURI,
                        PredictorLearnReason reason,
                        nsILoadGroup *loadGroup);
nsresult PredictorLearn(nsIURI *targetURI,
                        nsIURI *sourceURI,
                        PredictorLearnReason reason,
                        nsIDocument *document);
nsresult PredictorLearnRedirect(nsIURI *targetURI,
                                nsIChannel *channel,
                                nsILoadContext *loadContext);
} // mozilla::net
} // mozilla

#endif /* __gen_nsINetworkPredictor_h__ */
