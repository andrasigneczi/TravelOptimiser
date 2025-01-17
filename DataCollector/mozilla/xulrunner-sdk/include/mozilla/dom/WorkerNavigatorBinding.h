/* THIS FILE IS AUTOGENERATED FROM WorkerNavigator.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_WorkerNavigatorBinding_h
#define mozilla_dom_WorkerNavigatorBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Nullable.h"

namespace mozilla {
namespace dom {

struct NativePropertyHooks;
class ProtoAndIfaceCache;

namespace workers {

class WorkerNavigator;
struct WorkerNavigatorAtoms;

} // namespace workers

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

namespace WorkerNavigatorBinding_workers {

  typedef mozilla::dom::workers::WorkerNavigator NativeType;

  const JSClass*
  GetJSClass();

  bool
  Wrap(JSContext* aCx, mozilla::dom::workers::WorkerNavigator* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, T* aObject, JS::Handle<JSObject*> aGivenProto)
  {
    JS::Rooted<JSObject*> reflector(aCx);
    return Wrap(aCx, aObject, aObject, aGivenProto, &reflector) ? reflector.get() : nullptr;
  }

  void
  ClearCachedLanguageValue(mozilla::dom::workers::WorkerNavigator* aObject);

  void
  ClearCachedLanguagesValue(mozilla::dom::workers::WorkerNavigator* aObject);

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, ProtoAndIfaceCache& aProtoAndIfaceCache, bool aDefineOnGlobal);

  JS::Handle<JSObject*>
  GetProtoObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

  JS::Handle<JSObject*>
  GetConstructorObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal, bool aDefineOnGlobal = true);

  JSObject*
  GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

} // namespace WorkerNavigatorBinding_workers



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_WorkerNavigatorBinding_h
