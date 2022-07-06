/* THIS FILE IS AUTOGENERATED FROM ResourceStats.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_ResourceStatsBinding_h
#define mozilla_dom_ResourceStatsBinding_h

#include "ResourceStatsManagerBinding.h"
#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/ToJSValue.h"
#include "mozilla/dom/UnionMember.h"
#include "nsWeakReference.h"

namespace mozilla {
namespace dom {

struct NativePropertyHooks;
class NetworkStatsData;
struct NetworkStatsDataAtoms;
class NetworkStatsDataOrPowerStatsData;
class OwningNetworkStatsDataOrPowerStatsData;
class PowerStatsData;
struct PowerStatsDataAtoms;
class ProtoAndIfaceCache;
class ResourceStats;
struct ResourceStatsAtoms;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

void
ImplCycleCollectionTraverse(nsCycleCollectionTraversalCallback& aCallback, OwningNetworkStatsDataOrPowerStatsData& aUnion, const char* aName, uint32_t aFlags = 0);


void
ImplCycleCollectionUnlink(OwningNetworkStatsDataOrPowerStatsData& aUnion);


class NetworkStatsDataOrPowerStatsData
{
  friend class NetworkStatsDataOrPowerStatsDataArgument;
  enum Type
  {
    eUninitialized,
    eNetworkStatsData,
    ePowerStatsData
  };

  union Value
  {
    UnionMember<NonNull<mozilla::dom::NetworkStatsData> > mNetworkStatsData;
    UnionMember<NonNull<mozilla::dom::PowerStatsData> > mPowerStatsData;

  };

  Type mType;
  Value mValue;

  NetworkStatsDataOrPowerStatsData(const NetworkStatsDataOrPowerStatsData&) = delete;
  void operator=(const NetworkStatsDataOrPowerStatsData) = delete;
public:
  explicit inline NetworkStatsDataOrPowerStatsData()
    : mType(eUninitialized)
  {
  }

  inline ~NetworkStatsDataOrPowerStatsData()
  {
    Uninit();
  }

  inline NonNull<mozilla::dom::NetworkStatsData>&
  RawSetAsNetworkStatsData()
  {
    if (mType == eNetworkStatsData) {
      return mValue.mNetworkStatsData.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eNetworkStatsData;
    return mValue.mNetworkStatsData.SetValue();
  }

  inline NonNull<mozilla::dom::NetworkStatsData>&
  SetAsNetworkStatsData()
  {
    if (mType == eNetworkStatsData) {
      return mValue.mNetworkStatsData.Value();
    }
    Uninit();
    mType = eNetworkStatsData;
    return mValue.mNetworkStatsData.SetValue();
  }

  inline bool
  IsNetworkStatsData() const
  {
    return mType == eNetworkStatsData;
  }

  inline NonNull<mozilla::dom::NetworkStatsData>&
  GetAsNetworkStatsData()
  {
    MOZ_ASSERT(IsNetworkStatsData(), "Wrong type!");
    return mValue.mNetworkStatsData.Value();
  }

  inline mozilla::dom::NetworkStatsData&
  GetAsNetworkStatsData() const
  {
    MOZ_ASSERT(IsNetworkStatsData(), "Wrong type!");
    return mValue.mNetworkStatsData.Value();
  }

  inline NonNull<mozilla::dom::PowerStatsData>&
  RawSetAsPowerStatsData()
  {
    if (mType == ePowerStatsData) {
      return mValue.mPowerStatsData.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = ePowerStatsData;
    return mValue.mPowerStatsData.SetValue();
  }

  inline NonNull<mozilla::dom::PowerStatsData>&
  SetAsPowerStatsData()
  {
    if (mType == ePowerStatsData) {
      return mValue.mPowerStatsData.Value();
    }
    Uninit();
    mType = ePowerStatsData;
    return mValue.mPowerStatsData.SetValue();
  }

  inline bool
  IsPowerStatsData() const
  {
    return mType == ePowerStatsData;
  }

  inline NonNull<mozilla::dom::PowerStatsData>&
  GetAsPowerStatsData()
  {
    MOZ_ASSERT(IsPowerStatsData(), "Wrong type!");
    return mValue.mPowerStatsData.Value();
  }

  inline mozilla::dom::PowerStatsData&
  GetAsPowerStatsData() const
  {
    MOZ_ASSERT(IsPowerStatsData(), "Wrong type!");
    return mValue.mPowerStatsData.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eNetworkStatsData: {
        DestroyNetworkStatsData();
        break;
      }
      case ePowerStatsData: {
        DestroyPowerStatsData();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyNetworkStatsData()
  {
    MOZ_ASSERT(IsNetworkStatsData(), "Wrong type!");
    mValue.mNetworkStatsData.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyPowerStatsData()
  {
    MOZ_ASSERT(IsPowerStatsData(), "Wrong type!");
    mValue.mPowerStatsData.Destroy();
    mType = eUninitialized;
  }
};


class OwningNetworkStatsDataOrPowerStatsData : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningNetworkStatsDataOrPowerStatsData& aUnion);
  enum Type
  {
    eUninitialized,
    eNetworkStatsData,
    ePowerStatsData
  };

  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::NetworkStatsData> > mNetworkStatsData;
    UnionMember<OwningNonNull<mozilla::dom::PowerStatsData> > mPowerStatsData;

  };

  Type mType;
  Value mValue;

public:
  explicit inline OwningNetworkStatsDataOrPowerStatsData()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningNetworkStatsDataOrPowerStatsData(const OwningNetworkStatsDataOrPowerStatsData& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  inline ~OwningNetworkStatsDataOrPowerStatsData()
  {
    Uninit();
  }

  OwningNonNull<mozilla::dom::NetworkStatsData>&
  RawSetAsNetworkStatsData();

  OwningNonNull<mozilla::dom::NetworkStatsData>&
  SetAsNetworkStatsData();

  bool
  TrySetToNetworkStatsData(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsNetworkStatsData() const
  {
    return mType == eNetworkStatsData;
  }

  inline OwningNonNull<mozilla::dom::NetworkStatsData>&
  GetAsNetworkStatsData()
  {
    MOZ_ASSERT(IsNetworkStatsData(), "Wrong type!");
    return mValue.mNetworkStatsData.Value();
  }

  inline OwningNonNull<mozilla::dom::NetworkStatsData> const &
  GetAsNetworkStatsData() const
  {
    MOZ_ASSERT(IsNetworkStatsData(), "Wrong type!");
    return mValue.mNetworkStatsData.Value();
  }

  OwningNonNull<mozilla::dom::PowerStatsData>&
  RawSetAsPowerStatsData();

  OwningNonNull<mozilla::dom::PowerStatsData>&
  SetAsPowerStatsData();

  bool
  TrySetToPowerStatsData(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsPowerStatsData() const
  {
    return mType == ePowerStatsData;
  }

  inline OwningNonNull<mozilla::dom::PowerStatsData>&
  GetAsPowerStatsData()
  {
    MOZ_ASSERT(IsPowerStatsData(), "Wrong type!");
    return mValue.mPowerStatsData.Value();
  }

  inline OwningNonNull<mozilla::dom::PowerStatsData> const &
  GetAsPowerStatsData() const
  {
    MOZ_ASSERT(IsPowerStatsData(), "Wrong type!");
    return mValue.mPowerStatsData.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningNetworkStatsDataOrPowerStatsData& aOther);

private:
  void
  DestroyNetworkStatsData();

  void
  DestroyPowerStatsData();
};


namespace NetworkStatsDataBinding {

  typedef mozilla::dom::NetworkStatsData NativeType;

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
  Wrap(JSContext* aCx, mozilla::dom::NetworkStatsData* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace NetworkStatsDataBinding



namespace PowerStatsDataBinding {

  typedef mozilla::dom::PowerStatsData NativeType;

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
  Wrap(JSContext* aCx, mozilla::dom::PowerStatsData* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace PowerStatsDataBinding



namespace ResourceStatsBinding {

  typedef mozilla::dom::ResourceStats NativeType;

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
  Wrap(JSContext* aCx, mozilla::dom::ResourceStats* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace ResourceStatsBinding



class NetworkStatsDataJSImpl : public CallbackInterface
{
public:
  explicit inline NetworkStatsDataJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  inline bool
  operator==(const NetworkStatsDataJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  uint64_t GetReceivedBytes(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint64_t GetSentBytes(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint64_t GetTimestamp(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, NetworkStatsDataAtoms* atomsCache);
};


class NetworkStatsData final : public nsSupportsWeakReference,
                               public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(NetworkStatsData)

private:
  nsRefPtr<NetworkStatsDataJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  NetworkStatsData(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~NetworkStatsData();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  uint64_t GetReceivedBytes(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  uint64_t GetSentBytes(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  uint64_t GetTimestamp(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


class PowerStatsDataJSImpl : public CallbackInterface
{
public:
  explicit inline PowerStatsDataJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  inline bool
  operator==(const PowerStatsDataJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  uint64_t GetConsumedPower(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint64_t GetTimestamp(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, PowerStatsDataAtoms* atomsCache);
};


class PowerStatsData final : public nsSupportsWeakReference,
                             public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(PowerStatsData)

private:
  nsRefPtr<PowerStatsDataJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  PowerStatsData(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~PowerStatsData();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  uint64_t GetConsumedPower(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  uint64_t GetTimestamp(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


class ResourceStatsJSImpl : public CallbackInterface
{
public:
  explicit inline ResourceStatsJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  void GetData(nsTArray<OwningNetworkStatsDataOrPowerStatsData>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const ResourceStatsJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  ResourceType GetType(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetComponent(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  Nullable<SystemService> GetServiceType(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetManifestURL(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint64_t GetStart(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint64_t GetEnd(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, ResourceStatsAtoms* atomsCache);
};


class ResourceStats final : public nsSupportsWeakReference,
                            public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(ResourceStats)

private:
  nsRefPtr<ResourceStatsJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  ResourceStats(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~ResourceStats();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  ResourceType GetType(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetComponent(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  Nullable<SystemService> GetServiceType(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetManifestURL(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void GetData(nsTArray<OwningNetworkStatsDataOrPowerStatsData>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  uint64_t GetStart(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  uint64_t GetEnd(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_ResourceStatsBinding_h