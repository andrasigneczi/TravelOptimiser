/* THIS FILE IS AUTOGENERATED FROM RequestSyncManager.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_RequestSyncManagerBinding_h
#define mozilla_dom_RequestSyncManagerBinding_h

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

struct NativePropertyHooks;
class Promise;
class ProtoAndIfaceCache;
class RequestSyncApp;
struct RequestSyncAppAtoms;
class RequestSyncManager;
struct RequestSyncManagerAtoms;
class RequestSyncTask;
struct RequestSyncTaskAtoms;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

enum class RequestSyncTaskPolicyState : uint32_t {
  Enabled,
  Disabled,
  WifiOnly,
  EndGuard_
};

namespace RequestSyncTaskPolicyStateValues {
extern const EnumEntry strings[4];
} // namespace RequestSyncTaskPolicyStateValues


namespace RequestSyncAppBinding {

  typedef mozilla::dom::RequestSyncApp NativeType;

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
  Wrap(JSContext* aCx, mozilla::dom::RequestSyncApp* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace RequestSyncAppBinding



namespace RequestSyncManagerBinding {

  typedef mozilla::dom::RequestSyncManager NativeType;

  JSObject*
  ConstructNavigatorObject(JSContext* aCx, JS::Handle<JSObject*> aObj);

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
  Wrap(JSContext* aCx, mozilla::dom::RequestSyncManager* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace RequestSyncManagerBinding



namespace RequestSyncTaskBinding {

  typedef mozilla::dom::RequestSyncTask NativeType;

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
  Wrap(JSContext* aCx, mozilla::dom::RequestSyncTask* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace RequestSyncTaskBinding



class RequestSyncAppJSImpl : public CallbackInterface
{
public:
  explicit inline RequestSyncAppJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  inline bool
  operator==(const RequestSyncAppJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  void GetOrigin(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetManifestURL(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  bool GetIsInBrowserElement(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, RequestSyncAppAtoms* atomsCache);
};


class RequestSyncApp final : public nsSupportsWeakReference,
                             public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(RequestSyncApp)

private:
  nsRefPtr<RequestSyncAppJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  RequestSyncApp(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~RequestSyncApp();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  void GetOrigin(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetManifestURL(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  bool GetIsInBrowserElement(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


class RequestSyncManagerJSImpl : public CallbackInterface
{
public:
  explicit inline RequestSyncManagerJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  already_AddRefed<Promise> Registrations(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const RequestSyncManagerJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

private:
  static bool
  InitIds(JSContext* cx, RequestSyncManagerAtoms* atomsCache);
};


class RequestSyncManager final : public nsSupportsWeakReference,
                                 public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(RequestSyncManager)

private:
  nsRefPtr<RequestSyncManagerJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  RequestSyncManager(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~RequestSyncManager();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> Registrations(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


class RequestSyncTaskJSImpl : public CallbackInterface
{
public:
  explicit inline RequestSyncTaskJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  already_AddRefed<Promise> SetPolicy(RequestSyncTaskPolicyState aState, const Optional<int32_t>& ovewrittenMinInterval, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<Promise> RunNow(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const RequestSyncTaskJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  already_AddRefed<RequestSyncApp> GetApp(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  RequestSyncTaskPolicyState GetState(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  int32_t GetOverwrittenMinInterval(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetTask(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint64_t GetLastSync(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetWakeUpPage(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  bool GetOneShot(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  int32_t GetMinInterval(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  bool GetWifiOnly(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetData(JS::MutableHandle<JS::Value> aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, RequestSyncTaskAtoms* atomsCache);
};


class RequestSyncTask final : public nsSupportsWeakReference,
                              public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(RequestSyncTask)

private:
  nsRefPtr<RequestSyncTaskJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  RequestSyncTask(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~RequestSyncTask();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<RequestSyncApp> GetApp(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  RequestSyncTaskPolicyState GetState(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  int32_t GetOverwrittenMinInterval(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetTask(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  uint64_t GetLastSync(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetWakeUpPage(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  bool GetOneShot(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  int32_t GetMinInterval(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  bool GetWifiOnly(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetData(JS::MutableHandle<JS::Value> aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> SetPolicy(RequestSyncTaskPolicyState aState, const Optional<int32_t>& ovewrittenMinInterval, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<Promise> RunNow(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_RequestSyncManagerBinding_h
