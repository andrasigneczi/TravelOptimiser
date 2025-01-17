/* THIS FILE IS AUTOGENERATED FROM InterAppConnection.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_InterAppConnectionBinding_h
#define mozilla_dom_InterAppConnectionBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/ToJSValue.h"
#include "nsWeakReference.h"

namespace mozilla {
namespace dom {

class MozInterAppConnection;
struct MozInterAppConnectionAtoms;
struct NativePropertyHooks;
class ProtoAndIfaceCache;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

namespace MozInterAppConnectionBinding {

  typedef mozilla::dom::MozInterAppConnection NativeType;

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
  Wrap(JSContext* aCx, mozilla::dom::MozInterAppConnection* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace MozInterAppConnectionBinding



class MozInterAppConnectionJSImpl : public CallbackInterface
{
public:
  explicit inline MozInterAppConnectionJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  void Cancel(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void __Init(const nsAString& keyword, const nsAString& publisher, const nsAString& subsriber, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const MozInterAppConnectionJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  void GetKeyword(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetPublisher(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetSubscriber(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, MozInterAppConnectionAtoms* atomsCache);
};


class MozInterAppConnection final : public nsSupportsWeakReference,
                                    public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(MozInterAppConnection)

private:
  nsRefPtr<MozInterAppConnectionJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  MozInterAppConnection(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~MozInterAppConnection();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  static already_AddRefed<MozInterAppConnection> Constructor(const GlobalObject& global, JSContext* cx, const nsAString& keyword, const nsAString& publisher, const nsAString& subsriber, ErrorResult& aRv);

  void GetKeyword(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetPublisher(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetSubscriber(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void Cancel(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_InterAppConnectionBinding_h
