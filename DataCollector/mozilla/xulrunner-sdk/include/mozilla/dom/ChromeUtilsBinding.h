/* THIS FILE IS AUTOGENERATED FROM ChromeUtils.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_ChromeUtilsBinding_h
#define mozilla_dom_ChromeUtilsBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Nullable.h"

namespace mozilla {
namespace dom {

class ChromeUtils;
struct ChromeUtilsAtoms;
struct NativePropertyHooks;
struct OriginAttributesDictionaryAtoms;
class ProtoAndIfaceCache;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

struct OriginAttributesDictionary : public DictionaryBase
{
  uint32_t mAppId;
  bool mInBrowser;

  OriginAttributesDictionary();

  explicit inline OriginAttributesDictionary(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline OriginAttributesDictionary(const OriginAttributesDictionary& aOther)
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
  operator=(const OriginAttributesDictionary& aOther);

private:
  static bool
  InitIds(JSContext* cx, OriginAttributesDictionaryAtoms* atomsCache);
};

namespace binding_detail {
struct FastOriginAttributesDictionary : public OriginAttributesDictionary
{
  inline FastOriginAttributesDictionary()
    : OriginAttributesDictionary(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


namespace ChromeUtilsBinding {

  typedef mozilla::dom::ChromeUtils NativeType;

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

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, ProtoAndIfaceCache& aProtoAndIfaceCache, bool aDefineOnGlobal);

  JS::Handle<JSObject*>
  GetConstructorObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal, bool aDefineOnGlobal = true);

  JSObject*
  GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

} // namespace ChromeUtilsBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_ChromeUtilsBinding_h
