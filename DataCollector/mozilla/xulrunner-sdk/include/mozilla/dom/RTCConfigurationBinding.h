/* THIS FILE IS AUTOGENERATED FROM RTCConfiguration.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_RTCConfigurationBinding_h
#define mozilla_dom_RTCConfigurationBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/UnionTypes.h"

namespace mozilla {
namespace dom {

struct NativePropertyHooks;
class OwningStringOrStringSequence;
class ProtoAndIfaceCache;
struct RTCConfigurationAtoms;
struct RTCIceServer;
struct RTCIceServerAtoms;
class StringOrStringSequence;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

struct RTCIceServer : public DictionaryBase
{
  nsString mCredential;
  Optional<nsString> mUrl;
  Optional<OwningStringOrStringSequence> mUrls;
  nsString mUsername;

  RTCIceServer();

  explicit inline RTCIceServer(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline RTCIceServer(const RTCIceServer& aOther)
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
  operator=(const RTCIceServer& aOther);

private:
  static bool
  InitIds(JSContext* cx, RTCIceServerAtoms* atomsCache);
};

namespace binding_detail {
struct FastRTCIceServer : public RTCIceServer
{
  inline FastRTCIceServer()
    : RTCIceServer(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct RTCConfiguration : public DictionaryBase
{
  Optional<Sequence<RTCIceServer>> mIceServers;
  nsString mPeerIdentity;

  RTCConfiguration();

  explicit inline RTCConfiguration(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline RTCConfiguration(const RTCConfiguration& aOther)
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
  operator=(const RTCConfiguration& aOther);

private:
  static bool
  InitIds(JSContext* cx, RTCConfigurationAtoms* atomsCache);
};

namespace binding_detail {
struct FastRTCConfiguration : public RTCConfiguration
{
  inline FastRTCConfiguration()
    : RTCConfiguration(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_RTCConfigurationBinding_h