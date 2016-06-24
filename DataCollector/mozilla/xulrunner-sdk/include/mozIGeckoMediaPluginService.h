/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIGeckoMediaPluginService.idl
 */

#ifndef __gen_mozIGeckoMediaPluginService_h__
#define __gen_mozIGeckoMediaPluginService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIThread_h__
#include "nsIThread.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "mozilla/UniquePtr.h"
#include "nsTArray.h"
#include "nsStringGlue.h"
class GMPAudioDecoderProxy;
class GMPDecryptorProxy;
class GMPVideoDecoderProxy;
class GMPVideoEncoderProxy;
class GMPVideoHost;
template<class T>
class GMPGetterCallback
{
public:
  GMPGetterCallback() { MOZ_COUNT_CTOR(GMPGetterCallback<T>); }
  virtual ~GMPGetterCallback() { MOZ_COUNT_DTOR(GMPGetterCallback<T>); }
  virtual void Done(T*) = 0;
};
template<class T>
class GMPVideoGetterCallback
{
public:
  GMPVideoGetterCallback() { MOZ_COUNT_CTOR(GMPVideoGetterCallback<T>); }
  virtual ~GMPVideoGetterCallback() { MOZ_COUNT_DTOR(GMPVideoGetterCallback<T>); }
  virtual void Done(T*, GMPVideoHost*) = 0;
};
typedef GMPGetterCallback<GMPDecryptorProxy> GetGMPDecryptorCallback;
typedef GMPGetterCallback<GMPAudioDecoderProxy> GetGMPAudioDecoderCallback;
typedef GMPVideoGetterCallback<GMPVideoDecoderProxy> GetGMPVideoDecoderCallback;
typedef GMPVideoGetterCallback<GMPVideoEncoderProxy> GetGMPVideoEncoderCallback;
class GetNodeIdCallback
{
public:
  GetNodeIdCallback() { MOZ_COUNT_CTOR(GetNodeIdCallback); }
  virtual ~GetNodeIdCallback() { MOZ_COUNT_DTOR(GetNodeIdCallback); }
  virtual void Done(nsresult aResult, const nsACString& aNodeId) = 0;
};

/* starting interface:    mozIGeckoMediaPluginService */
#define MOZIGECKOMEDIAPLUGINSERVICE_IID_STR "787cf744-eea8-48c8-b692-376e0485ef97"

#define MOZIGECKOMEDIAPLUGINSERVICE_IID \
  {0x787cf744, 0xeea8, 0x48c8, \
    { 0xb6, 0x92, 0x37, 0x6e, 0x04, 0x85, 0xef, 0x97 }}

class NS_NO_VTABLE mozIGeckoMediaPluginService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIGECKOMEDIAPLUGINSERVICE_IID)

  /* readonly attribute nsIThread thread; */
  NS_IMETHOD GetThread(nsIThread * *aThread) = 0;

  /* [noscript] boolean hasPluginForAPI (in ACString api, in TagArray tags); */
  NS_IMETHOD HasPluginForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *_retval) = 0;

  /* [noscript] void getPluginVersionForAPI (in ACString api, in TagArray tags, out boolean hasPlugin, out ACString version); */
  NS_IMETHOD GetPluginVersionForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *hasPlugin, nsACString & version) = 0;

  /* [noscript] void getGMPVideoDecoder (in TagArray tags, [optional] in ACString nodeId, in GetGMPVideoDecoderCallback callback); */
  NS_IMETHOD GetGMPVideoDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoDecoderCallback>&& callback) = 0;

  /* [noscript] void getGMPVideoEncoder (in TagArray tags, [optional] in ACString nodeId, in GetGMPVideoEncoderCallback callback); */
  NS_IMETHOD GetGMPVideoEncoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoEncoderCallback>&& callback) = 0;

  /* [noscript] void getGMPAudioDecoder (in TagArray tags, [optional] in ACString nodeId, in GetGMPAudioDecoderCallback callback); */
  NS_IMETHOD GetGMPAudioDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPAudioDecoderCallback>&& callback) = 0;

  /* [noscript] void getGMPDecryptor (in TagArray tags, in ACString nodeId, in GetGMPDecryptorCallback callback); */
  NS_IMETHOD GetGMPDecryptor(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPDecryptorCallback>&& callback) = 0;

  /* [noscript] void getNodeId (in AString origin, in AString topLevelOrigin, in bool inPrivateBrowsingMode, in GetNodeIdCallback callback); */
  NS_IMETHOD GetNodeId(const nsAString & origin, const nsAString & topLevelOrigin, bool inPrivateBrowsingMode, mozilla::UniquePtr<GetNodeIdCallback>&& callback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIGeckoMediaPluginService, MOZIGECKOMEDIAPLUGINSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIGECKOMEDIAPLUGINSERVICE \
  NS_IMETHOD GetThread(nsIThread * *aThread) override; \
  NS_IMETHOD HasPluginForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *_retval) override; \
  NS_IMETHOD GetPluginVersionForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *hasPlugin, nsACString & version) override; \
  NS_IMETHOD GetGMPVideoDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoDecoderCallback>&& callback) override; \
  NS_IMETHOD GetGMPVideoEncoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoEncoderCallback>&& callback) override; \
  NS_IMETHOD GetGMPAudioDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPAudioDecoderCallback>&& callback) override; \
  NS_IMETHOD GetGMPDecryptor(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPDecryptorCallback>&& callback) override; \
  NS_IMETHOD GetNodeId(const nsAString & origin, const nsAString & topLevelOrigin, bool inPrivateBrowsingMode, mozilla::UniquePtr<GetNodeIdCallback>&& callback) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIGECKOMEDIAPLUGINSERVICE(_to) \
  NS_IMETHOD GetThread(nsIThread * *aThread) override { return _to GetThread(aThread); } \
  NS_IMETHOD HasPluginForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *_retval) override { return _to HasPluginForAPI(api, tags, _retval); } \
  NS_IMETHOD GetPluginVersionForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *hasPlugin, nsACString & version) override { return _to GetPluginVersionForAPI(api, tags, hasPlugin, version); } \
  NS_IMETHOD GetGMPVideoDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoDecoderCallback>&& callback) override { return _to GetGMPVideoDecoder(tags, nodeId, callback); } \
  NS_IMETHOD GetGMPVideoEncoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoEncoderCallback>&& callback) override { return _to GetGMPVideoEncoder(tags, nodeId, callback); } \
  NS_IMETHOD GetGMPAudioDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPAudioDecoderCallback>&& callback) override { return _to GetGMPAudioDecoder(tags, nodeId, callback); } \
  NS_IMETHOD GetGMPDecryptor(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPDecryptorCallback>&& callback) override { return _to GetGMPDecryptor(tags, nodeId, callback); } \
  NS_IMETHOD GetNodeId(const nsAString & origin, const nsAString & topLevelOrigin, bool inPrivateBrowsingMode, mozilla::UniquePtr<GetNodeIdCallback>&& callback) override { return _to GetNodeId(origin, topLevelOrigin, inPrivateBrowsingMode, callback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIGECKOMEDIAPLUGINSERVICE(_to) \
  NS_IMETHOD GetThread(nsIThread * *aThread) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThread(aThread); } \
  NS_IMETHOD HasPluginForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPluginForAPI(api, tags, _retval); } \
  NS_IMETHOD GetPluginVersionForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *hasPlugin, nsACString & version) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPluginVersionForAPI(api, tags, hasPlugin, version); } \
  NS_IMETHOD GetGMPVideoDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoDecoderCallback>&& callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGMPVideoDecoder(tags, nodeId, callback); } \
  NS_IMETHOD GetGMPVideoEncoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoEncoderCallback>&& callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGMPVideoEncoder(tags, nodeId, callback); } \
  NS_IMETHOD GetGMPAudioDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPAudioDecoderCallback>&& callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGMPAudioDecoder(tags, nodeId, callback); } \
  NS_IMETHOD GetGMPDecryptor(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPDecryptorCallback>&& callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGMPDecryptor(tags, nodeId, callback); } \
  NS_IMETHOD GetNodeId(const nsAString & origin, const nsAString & topLevelOrigin, bool inPrivateBrowsingMode, mozilla::UniquePtr<GetNodeIdCallback>&& callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodeId(origin, topLevelOrigin, inPrivateBrowsingMode, callback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIGeckoMediaPluginService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIGECKOMEDIAPLUGINSERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, mozIGeckoMediaPluginService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute nsIThread thread; */
NS_IMETHODIMP _MYCLASS_::GetThread(nsIThread * *aThread)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean hasPluginForAPI (in ACString api, in TagArray tags); */
NS_IMETHODIMP _MYCLASS_::HasPluginForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getPluginVersionForAPI (in ACString api, in TagArray tags, out boolean hasPlugin, out ACString version); */
NS_IMETHODIMP _MYCLASS_::GetPluginVersionForAPI(const nsACString & api, nsTArray<nsCString> *tags, bool *hasPlugin, nsACString & version)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getGMPVideoDecoder (in TagArray tags, [optional] in ACString nodeId, in GetGMPVideoDecoderCallback callback); */
NS_IMETHODIMP _MYCLASS_::GetGMPVideoDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoDecoderCallback>&& callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getGMPVideoEncoder (in TagArray tags, [optional] in ACString nodeId, in GetGMPVideoEncoderCallback callback); */
NS_IMETHODIMP _MYCLASS_::GetGMPVideoEncoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPVideoEncoderCallback>&& callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getGMPAudioDecoder (in TagArray tags, [optional] in ACString nodeId, in GetGMPAudioDecoderCallback callback); */
NS_IMETHODIMP _MYCLASS_::GetGMPAudioDecoder(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPAudioDecoderCallback>&& callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getGMPDecryptor (in TagArray tags, in ACString nodeId, in GetGMPDecryptorCallback callback); */
NS_IMETHODIMP _MYCLASS_::GetGMPDecryptor(nsTArray<nsCString> *tags, const nsACString & nodeId, mozilla::UniquePtr<GetGMPDecryptorCallback>&& callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getNodeId (in AString origin, in AString topLevelOrigin, in bool inPrivateBrowsingMode, in GetNodeIdCallback callback); */
NS_IMETHODIMP _MYCLASS_::GetNodeId(const nsAString & origin, const nsAString & topLevelOrigin, bool inPrivateBrowsingMode, mozilla::UniquePtr<GetNodeIdCallback>&& callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIGeckoMediaPluginService_h__ */
