/* THIS FILE IS AUTOGENERATED FROM TVScanningStateChangedEvent.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_TVScanningStateChangedEventBinding_h
#define mozilla_dom_TVScanningStateChangedEventBinding_h

#include "EventBinding.h"
#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/TVChannel.h"

namespace mozilla {
namespace dom {

struct NativePropertyHooks;
class ProtoAndIfaceCache;
class TVChannel;
class TVScanningStateChangedEvent;
struct TVScanningStateChangedEventAtoms;
struct TVScanningStateChangedEventInitAtoms;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

enum class TVScanningState : uint32_t {
  Cleared,
  Scanned,
  Completed,
  Stopped,
  EndGuard_
};

namespace TVScanningStateValues {
extern const EnumEntry strings[5];
} // namespace TVScanningStateValues


struct TVScanningStateChangedEventInit : public EventInit
{
  nsRefPtr<mozilla::dom::TVChannel> mChannel;
  TVScanningState mState;

  TVScanningStateChangedEventInit();

  explicit inline TVScanningStateChangedEventInit(const FastDictionaryInitializer& )
    : EventInit(FastDictionaryInitializer())
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline TVScanningStateChangedEventInit(const TVScanningStateChangedEventInit& aOther)
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
  operator=(const TVScanningStateChangedEventInit& aOther);

private:
  static bool
  InitIds(JSContext* cx, TVScanningStateChangedEventInitAtoms* atomsCache);
};

namespace binding_detail {
struct FastTVScanningStateChangedEventInit : public TVScanningStateChangedEventInit
{
  inline FastTVScanningStateChangedEventInit()
    : TVScanningStateChangedEventInit(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


namespace TVScanningStateChangedEventBinding {

  typedef mozilla::dom::TVScanningStateChangedEvent NativeType;

  // We declare this as an array so that retrieving a pointer to this
  // binding's property hooks only requires compile/link-time resolvable
  // address arithmetic.  Declaring it as a pointer instead would require
  // doing a run-time load to fetch a pointer to this binding's property
  // hooks.  And then structures which embedded a pointer to this structure
  // would require a run-time load for proper initialization, which would
  // then induce static constructors.  Lots of static constructors.
  extern const NativePropertyHooks sNativePropertyHooks[];

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool aDefineOnGlobal);

  bool
  ConstructorEnabled(JSContext* aCx, JS::Handle<JSObject*> aObj);

  const JSClass*
  GetJSClass();

  bool
  Wrap(JSContext* aCx, mozilla::dom::TVScanningStateChangedEvent* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, T* aObject, JS::Handle<JSObject*> aGivenProto)
  {
    JS::Rooted<JSObject*> reflector(aCx);
    return Wrap(aCx, aObject, aObject, aGivenProto, &reflector) ? reflector.get() : nullptr;
  }

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, ProtoAndIfaceCache& aProtoAndIfaceCache, bool aDefineOnGlobal);

  JS::Handle<JSObject*>
  GetProtoObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

  JS::Handle<JSObject*>
  GetConstructorObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal, bool aDefineOnGlobal = true);

  JSObject*
  GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

} // namespace TVScanningStateChangedEventBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_TVScanningStateChangedEventBinding_h
