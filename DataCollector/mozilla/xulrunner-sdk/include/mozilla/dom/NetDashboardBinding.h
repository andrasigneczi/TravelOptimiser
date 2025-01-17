/* THIS FILE IS AUTOGENERATED FROM NetDashboard.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_NetDashboardBinding_h
#define mozilla_dom_NetDashboardBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Nullable.h"

namespace mozilla {
namespace dom {

struct ConnStatusDictAtoms;
struct DNSCacheDictAtoms;
struct DNSLookupDictAtoms;
struct DnsCacheEntry;
struct DnsCacheEntryAtoms;
struct HalfOpenInfoDict;
struct HalfOpenInfoDictAtoms;
struct HttpConnDictAtoms;
struct HttpConnInfo;
struct HttpConnInfoAtoms;
struct HttpConnectionElement;
struct HttpConnectionElementAtoms;
struct NativePropertyHooks;
class ProtoAndIfaceCache;
struct SocketElement;
struct SocketElementAtoms;
struct SocketsDictAtoms;
struct WebSocketDictAtoms;
struct WebSocketElement;
struct WebSocketElementAtoms;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

struct ConnStatusDict : public DictionaryBase
{
  nsString mStatus;

  ConnStatusDict();

  explicit inline ConnStatusDict(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ConnStatusDict(const ConnStatusDict& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const ConnStatusDict& aOther);

private:
  static bool
  InitIds(JSContext* cx, ConnStatusDictAtoms* atomsCache);
};

namespace binding_detail {
struct FastConnStatusDict : public ConnStatusDict
{
  inline FastConnStatusDict()
    : ConnStatusDict(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct DNSLookupDict : public DictionaryBase
{
  Optional<Sequence<nsString>> mAddress;
  bool mAnswer;
  nsString mError;

  DNSLookupDict();

  explicit inline DNSLookupDict(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline DNSLookupDict(const DNSLookupDict& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const DNSLookupDict& aOther);

private:
  static bool
  InitIds(JSContext* cx, DNSLookupDictAtoms* atomsCache);
};

namespace binding_detail {
struct FastDNSLookupDict : public DNSLookupDict
{
  inline FastDNSLookupDict()
    : DNSLookupDict(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct DnsCacheEntry : public DictionaryBase
{
  double mExpiration;
  nsString mFamily;
  Optional<Sequence<nsString>> mHostaddr;
  nsString mHostname;

  DnsCacheEntry();

  explicit inline DnsCacheEntry(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline DnsCacheEntry(const DnsCacheEntry& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const DnsCacheEntry& aOther);

private:
  static bool
  InitIds(JSContext* cx, DnsCacheEntryAtoms* atomsCache);
};

namespace binding_detail {
struct FastDnsCacheEntry : public DnsCacheEntry
{
  inline FastDnsCacheEntry()
    : DnsCacheEntry(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct HalfOpenInfoDict : public DictionaryBase
{
  bool mSpeculative;

  HalfOpenInfoDict();

  explicit inline HalfOpenInfoDict(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline HalfOpenInfoDict(const HalfOpenInfoDict& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const HalfOpenInfoDict& aOther);

private:
  static bool
  InitIds(JSContext* cx, HalfOpenInfoDictAtoms* atomsCache);
};

namespace binding_detail {
struct FastHalfOpenInfoDict : public HalfOpenInfoDict
{
  inline FastHalfOpenInfoDict()
    : HalfOpenInfoDict(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct HttpConnInfo : public DictionaryBase
{
  nsString mProtocolVersion;
  uint32_t mRtt;
  uint32_t mTtl;

  HttpConnInfo();

  explicit inline HttpConnInfo(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline HttpConnInfo(const HttpConnInfo& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const HttpConnInfo& aOther);

private:
  static bool
  InitIds(JSContext* cx, HttpConnInfoAtoms* atomsCache);
};

namespace binding_detail {
struct FastHttpConnInfo : public HttpConnInfo
{
  inline FastHttpConnInfo()
    : HttpConnInfo(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct SocketElement : public DictionaryBase
{
  bool mActive;
  nsString mHost;
  uint32_t mPort;
  double mReceived;
  double mSent;
  bool mTcp;

  SocketElement();

  explicit inline SocketElement(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline SocketElement(const SocketElement& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const SocketElement& aOther);

private:
  static bool
  InitIds(JSContext* cx, SocketElementAtoms* atomsCache);
};

namespace binding_detail {
struct FastSocketElement : public SocketElement
{
  inline FastSocketElement()
    : SocketElement(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct WebSocketElement : public DictionaryBase
{
  bool mEncrypted;
  nsString mHostport;
  uint32_t mMsgreceived;
  uint32_t mMsgsent;
  double mReceivedsize;
  double mSentsize;

  WebSocketElement();

  explicit inline WebSocketElement(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline WebSocketElement(const WebSocketElement& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const WebSocketElement& aOther);

private:
  static bool
  InitIds(JSContext* cx, WebSocketElementAtoms* atomsCache);
};

namespace binding_detail {
struct FastWebSocketElement : public WebSocketElement
{
  inline FastWebSocketElement()
    : WebSocketElement(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct DNSCacheDict : public DictionaryBase
{
  Optional<Sequence<DnsCacheEntry>> mEntries;

  DNSCacheDict();

  explicit inline DNSCacheDict(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline DNSCacheDict(const DNSCacheDict& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const DNSCacheDict& aOther);

private:
  static bool
  InitIds(JSContext* cx, DNSCacheDictAtoms* atomsCache);
};

namespace binding_detail {
struct FastDNSCacheDict : public DNSCacheDict
{
  inline FastDNSCacheDict()
    : DNSCacheDict(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct HttpConnectionElement : public DictionaryBase
{
  Optional<Sequence<HttpConnInfo>> mActive;
  Optional<Sequence<HalfOpenInfoDict>> mHalfOpens;
  nsString mHost;
  Optional<Sequence<HttpConnInfo>> mIdle;
  uint32_t mPort;
  bool mSpdy;
  bool mSsl;

  HttpConnectionElement();

  explicit inline HttpConnectionElement(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline HttpConnectionElement(const HttpConnectionElement& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const HttpConnectionElement& aOther);

private:
  static bool
  InitIds(JSContext* cx, HttpConnectionElementAtoms* atomsCache);
};

namespace binding_detail {
struct FastHttpConnectionElement : public HttpConnectionElement
{
  inline FastHttpConnectionElement()
    : HttpConnectionElement(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct SocketsDict : public DictionaryBase
{
  double mReceived;
  double mSent;
  Optional<Sequence<SocketElement>> mSockets;

  SocketsDict();

  explicit inline SocketsDict(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline SocketsDict(const SocketsDict& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const SocketsDict& aOther);

private:
  static bool
  InitIds(JSContext* cx, SocketsDictAtoms* atomsCache);
};

namespace binding_detail {
struct FastSocketsDict : public SocketsDict
{
  inline FastSocketsDict()
    : SocketsDict(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct WebSocketDict : public DictionaryBase
{
  Optional<Sequence<WebSocketElement>> mWebsockets;

  WebSocketDict();

  explicit inline WebSocketDict(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline WebSocketDict(const WebSocketDict& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const WebSocketDict& aOther);

private:
  static bool
  InitIds(JSContext* cx, WebSocketDictAtoms* atomsCache);
};

namespace binding_detail {
struct FastWebSocketDict : public WebSocketDict
{
  inline FastWebSocketDict()
    : WebSocketDict(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct HttpConnDict : public DictionaryBase
{
  Optional<Sequence<HttpConnectionElement>> mConnections;

  HttpConnDict();

  explicit inline HttpConnDict(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline HttpConnDict(const HttpConnDict& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const HttpConnDict& aOther);

private:
  static bool
  InitIds(JSContext* cx, HttpConnDictAtoms* atomsCache);
};

namespace binding_detail {
struct FastHttpConnDict : public HttpConnDict
{
  inline FastHttpConnDict()
    : HttpConnDict(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_NetDashboardBinding_h
