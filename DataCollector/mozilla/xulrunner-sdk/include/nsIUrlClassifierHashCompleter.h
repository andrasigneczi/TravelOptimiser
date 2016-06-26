/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUrlClassifierHashCompleter.idl
 */

#ifndef __gen_nsIUrlClassifierHashCompleter_h__
#define __gen_nsIUrlClassifierHashCompleter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUrlClassifierHashCompleterCallback */
#define NS_IURLCLASSIFIERHASHCOMPLETERCALLBACK_IID_STR "da16de40-df26-414d-bde7-c4faf4504868"

#define NS_IURLCLASSIFIERHASHCOMPLETERCALLBACK_IID \
  {0xda16de40, 0xdf26, 0x414d, \
    { 0xbd, 0xe7, 0xc4, 0xfa, 0xf4, 0x50, 0x48, 0x68 }}

class NS_NO_VTABLE nsIUrlClassifierHashCompleterCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERHASHCOMPLETERCALLBACK_IID)

  /* void completion (in ACString hash, in ACString table, in uint32_t chunkId); */
  NS_IMETHOD Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId) = 0;

  /* void completionFinished (in nsresult status); */
  NS_IMETHOD CompletionFinished(nsresult status) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierHashCompleterCallback, NS_IURLCLASSIFIERHASHCOMPLETERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERHASHCOMPLETERCALLBACK \
  NS_IMETHOD Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId) override; \
  NS_IMETHOD CompletionFinished(nsresult status) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERHASHCOMPLETERCALLBACK(_to) \
  NS_IMETHOD Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId) override { return _to Completion(hash, table, chunkId); } \
  NS_IMETHOD CompletionFinished(nsresult status) override { return _to CompletionFinished(status); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERHASHCOMPLETERCALLBACK(_to) \
  NS_IMETHOD Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Completion(hash, table, chunkId); } \
  NS_IMETHOD CompletionFinished(nsresult status) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CompletionFinished(status); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierHashCompleterCallback : public nsIUrlClassifierHashCompleterCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERHASHCOMPLETERCALLBACK

  nsUrlClassifierHashCompleterCallback();

private:
  ~nsUrlClassifierHashCompleterCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUrlClassifierHashCompleterCallback, nsIUrlClassifierHashCompleterCallback)

nsUrlClassifierHashCompleterCallback::nsUrlClassifierHashCompleterCallback()
{
  /* member initializers and constructor code */
}

nsUrlClassifierHashCompleterCallback::~nsUrlClassifierHashCompleterCallback()
{
  /* destructor code */
}

/* void completion (in ACString hash, in ACString table, in uint32_t chunkId); */
NS_IMETHODIMP nsUrlClassifierHashCompleterCallback::Completion(const nsACString & hash, const nsACString & table, uint32_t chunkId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completionFinished (in nsresult status); */
NS_IMETHODIMP nsUrlClassifierHashCompleterCallback::CompletionFinished(nsresult status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUrlClassifierHashCompleter */
#define NS_IURLCLASSIFIERHASHCOMPLETER_IID_STR "231fb2ad-ea8a-4e63-a331-eafc3b434811"

#define NS_IURLCLASSIFIERHASHCOMPLETER_IID \
  {0x231fb2ad, 0xea8a, 0x4e63, \
    { 0xa3, 0x31, 0xea, 0xfc, 0x3b, 0x43, 0x48, 0x11 }}

class NS_NO_VTABLE nsIUrlClassifierHashCompleter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERHASHCOMPLETER_IID)

  /* void complete (in ACString partialHash, in ACString gethashUrl, in nsIUrlClassifierHashCompleterCallback callback); */
  NS_IMETHOD Complete(const nsACString & partialHash, const nsACString & gethashUrl, nsIUrlClassifierHashCompleterCallback *callback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierHashCompleter, NS_IURLCLASSIFIERHASHCOMPLETER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERHASHCOMPLETER \
  NS_IMETHOD Complete(const nsACString & partialHash, const nsACString & gethashUrl, nsIUrlClassifierHashCompleterCallback *callback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERHASHCOMPLETER(_to) \
  NS_IMETHOD Complete(const nsACString & partialHash, const nsACString & gethashUrl, nsIUrlClassifierHashCompleterCallback *callback) override { return _to Complete(partialHash, gethashUrl, callback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERHASHCOMPLETER(_to) \
  NS_IMETHOD Complete(const nsACString & partialHash, const nsACString & gethashUrl, nsIUrlClassifierHashCompleterCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Complete(partialHash, gethashUrl, callback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierHashCompleter : public nsIUrlClassifierHashCompleter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERHASHCOMPLETER

  nsUrlClassifierHashCompleter();

private:
  ~nsUrlClassifierHashCompleter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsUrlClassifierHashCompleter, nsIUrlClassifierHashCompleter)

nsUrlClassifierHashCompleter::nsUrlClassifierHashCompleter()
{
  /* member initializers and constructor code */
}

nsUrlClassifierHashCompleter::~nsUrlClassifierHashCompleter()
{
  /* destructor code */
}

/* void complete (in ACString partialHash, in ACString gethashUrl, in nsIUrlClassifierHashCompleterCallback callback); */
NS_IMETHODIMP nsUrlClassifierHashCompleter::Complete(const nsACString & partialHash, const nsACString & gethashUrl, nsIUrlClassifierHashCompleterCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUrlClassifierHashCompleter_h__ */
