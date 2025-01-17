/* THIS FILE IS AUTOGENERATED FROM Contacts.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_ContactsBinding_h
#define mozilla_dom_ContactsBinding_h

#include "ContactsBinding.h"
#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/DOMEventTargetHelper.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/Date.h"
#include "mozilla/dom/File.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/ToJSValue.h"
#include "mozilla/dom/UnionMember.h"
#include "nsWeakReference.h"

namespace mozilla {
namespace dom {

class Blob;
struct ContactAddress;
struct ContactAddressAtoms;
struct ContactField;
struct ContactFieldAtoms;
struct ContactFindOptions;
struct ContactFindOptionsAtoms;
struct ContactFindSortOptions;
struct ContactFindSortOptionsAtoms;
class ContactManager;
struct ContactManagerAtoms;
struct ContactProperties;
struct ContactPropertiesAtoms;
struct ContactTelField;
struct ContactTelFieldAtoms;
class DOMCursor;
class DOMRequest;
class EventHandlerNonNull;
struct NativePropertyHooks;
class OwningmozContactOrString;
class ProtoAndIfaceCache;
class mozContact;
struct mozContactAtoms;
class mozContactOrString;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

void
ImplCycleCollectionTraverse(nsCycleCollectionTraversalCallback& aCallback, OwningmozContactOrString& aUnion, const char* aName, uint32_t aFlags = 0);


void
ImplCycleCollectionUnlink(OwningmozContactOrString& aUnion);


struct ContactAddress : public DictionaryBase
{
  Optional<nsString> mCountryName;
  Optional<nsString> mLocality;
  Optional<nsString> mPostalCode;
  Optional<Nullable<bool>> mPref;
  Optional<nsString> mRegion;
  Optional<nsString> mStreetAddress;
  Optional<Nullable<Sequence<nsString>>> mType;

  ContactAddress();

  explicit inline ContactAddress(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ContactAddress(const ContactAddress& aOther)
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
  operator=(const ContactAddress& aOther);

private:
  static bool
  InitIds(JSContext* cx, ContactAddressAtoms* atomsCache);
};

namespace binding_detail {
struct FastContactAddress : public ContactAddress
{
  inline FastContactAddress()
    : ContactAddress(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct ContactField : public DictionaryBase
{
  Optional<Nullable<bool>> mPref;
  Optional<Nullable<Sequence<nsString>>> mType;
  Optional<nsString> mValue;

  ContactField();

  explicit inline ContactField(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ContactField(const ContactField& aOther)
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
  operator=(const ContactField& aOther);

private:
  static bool
  InitIds(JSContext* cx, ContactFieldAtoms* atomsCache);
};

namespace binding_detail {
struct FastContactField : public ContactField
{
  inline FastContactField()
    : ContactField(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct ContactFindSortOptions : public DictionaryBase
{
  Optional<nsString> mSortBy;
  nsString mSortOrder;

  ContactFindSortOptions();

  explicit inline ContactFindSortOptions(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ContactFindSortOptions(const ContactFindSortOptions& aOther)
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
  operator=(const ContactFindSortOptions& aOther);

private:
  static bool
  InitIds(JSContext* cx, ContactFindSortOptionsAtoms* atomsCache);
};

namespace binding_detail {
struct FastContactFindSortOptions : public ContactFindSortOptions
{
  inline FastContactFindSortOptions()
    : ContactFindSortOptions(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


class mozContactOrString
{
  friend class mozContactOrStringArgument;
  enum Type
  {
    eUninitialized,
    emozContact,
    eString
  };

  union Value
  {
    UnionMember<NonNull<mozilla::dom::mozContact> > mmozContact;
    UnionMember<binding_detail::FakeString > mString;

  };

  Type mType;
  Value mValue;

  mozContactOrString(const mozContactOrString&) = delete;
  void operator=(const mozContactOrString) = delete;
public:
  explicit inline mozContactOrString()
    : mType(eUninitialized)
  {
  }

  inline ~mozContactOrString()
  {
    Uninit();
  }

  inline NonNull<mozilla::dom::mozContact>&
  RawSetAsmozContact()
  {
    if (mType == emozContact) {
      return mValue.mmozContact.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = emozContact;
    return mValue.mmozContact.SetValue();
  }

  inline NonNull<mozilla::dom::mozContact>&
  SetAsmozContact()
  {
    if (mType == emozContact) {
      return mValue.mmozContact.Value();
    }
    Uninit();
    mType = emozContact;
    return mValue.mmozContact.SetValue();
  }

  inline bool
  IsmozContact() const
  {
    return mType == emozContact;
  }

  inline NonNull<mozilla::dom::mozContact>&
  GetAsmozContact()
  {
    MOZ_ASSERT(IsmozContact(), "Wrong type!");
    return mValue.mmozContact.Value();
  }

  inline mozilla::dom::mozContact&
  GetAsmozContact() const
  {
    MOZ_ASSERT(IsmozContact(), "Wrong type!");
    return mValue.mmozContact.Value();
  }

  inline binding_detail::FakeString&
  RawSetAsString()
  {
    if (mType == eString) {
      return mValue.mString.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eString;
    return mValue.mString.SetValue();
  }

  inline binding_detail::FakeString&
  SetAsString()
  {
    if (mType == eString) {
      return mValue.mString.Value();
    }
    Uninit();
    mType = eString;
    return mValue.mString.SetValue();
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline binding_detail::FakeString&
  GetAsString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return mValue.mString.Value();
  }

  inline const nsAString&
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return mValue.mString.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case emozContact: {
        DestroymozContact();
        break;
      }
      case eString: {
        DestroyString();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroymozContact()
  {
    MOZ_ASSERT(IsmozContact(), "Wrong type!");
    mValue.mmozContact.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }
};


class OwningmozContactOrString : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningmozContactOrString& aUnion);
  enum Type
  {
    eUninitialized,
    emozContact,
    eString
  };

  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::mozContact> > mmozContact;
    UnionMember<nsString > mString;

  };

  Type mType;
  Value mValue;

public:
  explicit inline OwningmozContactOrString()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningmozContactOrString(const OwningmozContactOrString& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  inline ~OwningmozContactOrString()
  {
    Uninit();
  }

  OwningNonNull<mozilla::dom::mozContact>&
  RawSetAsmozContact();

  OwningNonNull<mozilla::dom::mozContact>&
  SetAsmozContact();

  bool
  TrySetTomozContact(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsmozContact() const
  {
    return mType == emozContact;
  }

  inline OwningNonNull<mozilla::dom::mozContact>&
  GetAsmozContact()
  {
    MOZ_ASSERT(IsmozContact(), "Wrong type!");
    return mValue.mmozContact.Value();
  }

  inline OwningNonNull<mozilla::dom::mozContact> const &
  GetAsmozContact() const
  {
    MOZ_ASSERT(IsmozContact(), "Wrong type!");
    return mValue.mmozContact.Value();
  }

  nsString&
  RawSetAsString();

  nsString&
  SetAsString();

  bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline void
  SetStringData(const nsString::char_type* aData, nsString::size_type aLength)
  {
    RawSetAsString().Assign(aData, aLength);
  }

  inline bool
  IsString() const
  {
    return mType == eString;
  }

  inline nsString&
  GetAsString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return mValue.mString.Value();
  }

  inline nsString const &
  GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return mValue.mString.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningmozContactOrString& aOther);

private:
  void
  DestroymozContact();

  void
  DestroyString();
};


struct ContactFindOptions : public ContactFindSortOptions
{
  JS::Value mFilterBy;
  uint32_t mFilterLimit;
  Optional<nsString> mFilterOp;
  Optional<nsString> mFilterValue;

  ContactFindOptions();

  explicit inline ContactFindOptions(const FastDictionaryInitializer& )
    : ContactFindSortOptions(FastDictionaryInitializer()),
      mFilterBy(JS::UndefinedValue())
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

private:
  ContactFindOptions(const ContactFindOptions&) = delete;
  void operator=(const ContactFindOptions) = delete;

  static bool
  InitIds(JSContext* cx, ContactFindOptionsAtoms* atomsCache);

public:
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
};

namespace binding_detail {
struct FastContactFindOptions : public ContactFindOptions
{
  inline FastContactFindOptions()
    : ContactFindOptions(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct ContactTelField : public ContactField
{
  Optional<nsString> mCarrier;

  ContactTelField();

  explicit inline ContactTelField(const FastDictionaryInitializer& )
    : ContactField(FastDictionaryInitializer())
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline ContactTelField(const ContactTelField& aOther)
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
  operator=(const ContactTelField& aOther);

private:
  static bool
  InitIds(JSContext* cx, ContactTelFieldAtoms* atomsCache);
};

namespace binding_detail {
struct FastContactTelField : public ContactTelField
{
  inline FastContactTelField()
    : ContactTelField(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct ContactProperties : public DictionaryBase
{
  Optional<Nullable<Sequence<nsString>>> mAdditionalName;
  Optional<Nullable<Sequence<ContactAddress>>> mAdr;
  Optional<Nullable<Date>> mAnniversary;
  Optional<Nullable<Date>> mBday;
  Optional<Nullable<Sequence<nsString>>> mCategory;
  Optional<Nullable<Sequence<ContactField>>> mEmail;
  Optional<Nullable<Sequence<nsString>>> mFamilyName;
  Optional<nsString> mGenderIdentity;
  Optional<Nullable<Sequence<nsString>>> mGivenName;
  Optional<Nullable<Sequence<nsString>>> mHonorificPrefix;
  Optional<Nullable<Sequence<nsString>>> mHonorificSuffix;
  Optional<Nullable<Sequence<ContactField>>> mImpp;
  Optional<Nullable<Sequence<nsString>>> mJobTitle;
  Optional<Nullable<Sequence<nsString>>> mKey;
  Optional<Nullable<Sequence<nsString>>> mName;
  Optional<Nullable<Sequence<nsString>>> mNickname;
  Optional<Nullable<Sequence<nsString>>> mNote;
  Optional<Nullable<Sequence<nsString>>> mOrg;
  Optional<Nullable<Sequence<nsString>>> mPhoneticFamilyName;
  Optional<Nullable<Sequence<nsString>>> mPhoneticGivenName;
  Optional<Nullable<Sequence<OwningNonNull<mozilla::dom::Blob>>>> mPhoto;
  Optional<nsString> mSex;
  Optional<Nullable<Sequence<ContactTelField>>> mTel;
  Optional<Nullable<Sequence<ContactField>>> mUrl;

  ContactProperties();

  explicit inline ContactProperties(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

private:
  ContactProperties(const ContactProperties&) = delete;
  void operator=(const ContactProperties) = delete;

  static bool
  InitIds(JSContext* cx, ContactPropertiesAtoms* atomsCache);

public:
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
};

namespace binding_detail {
struct FastContactProperties : public ContactProperties
{
  inline FastContactProperties()
    : ContactProperties(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


namespace ContactManagerBinding {

  typedef mozilla::dom::ContactManager NativeType;

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

  const JSClass*
  GetJSClass();

  bool
  Wrap(JSContext* aCx, mozilla::dom::ContactManager* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace ContactManagerBinding



namespace mozContactBinding {

  typedef mozilla::dom::mozContact NativeType;

  bool
  JsonifyAttributes(JSContext* aCx, JS::Handle<JSObject*> obj, mozilla::dom::mozContact* self, JS::Rooted<JSObject*>& aResult);

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

  const JSClass*
  GetJSClass();

  bool
  Wrap(JSContext* aCx, mozilla::dom::mozContact* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, T* aObject, JS::Handle<JSObject*> aGivenProto)
  {
    JS::Rooted<JSObject*> reflector(aCx);
    return Wrap(aCx, aObject, aObject, aGivenProto, &reflector) ? reflector.get() : nullptr;
  }

  void
  ClearCachedPhotoValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedAdrValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedEmailValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedUrlValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedImppValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedTelValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedNameValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedHonorificPrefixValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedGivenNameValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedPhoneticGivenNameValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedAdditionalNameValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedFamilyNameValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedPhoneticFamilyNameValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedHonorificSuffixValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedNicknameValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedCategoryValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedOrgValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedJobTitleValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedNoteValue(mozilla::dom::mozContact* aObject);

  void
  ClearCachedKeyValue(mozilla::dom::mozContact* aObject);

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, ProtoAndIfaceCache& aProtoAndIfaceCache, bool aDefineOnGlobal);

  JS::Handle<JSObject*>
  GetProtoObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

  JS::Handle<JSObject*>
  GetConstructorObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal, bool aDefineOnGlobal = true);

  JSObject*
  GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

} // namespace mozContactBinding



class ContactManagerJSImpl : public CallbackInterface
{
public:
  explicit inline ContactManagerJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  already_AddRefed<DOMRequest> Find(const ContactFindOptions& options, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMCursor> GetAll(const ContactFindSortOptions& options, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMRequest> Clear(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMRequest> Save(mozContact& contact, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMRequest> Remove(const mozContactOrString& contactOrId, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMRequest> GetRevision(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMRequest> GetCount(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const ContactManagerJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  already_AddRefed<EventHandlerNonNull> GetOncontactchange(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetOncontactchange(EventHandlerNonNull* arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, ContactManagerAtoms* atomsCache);
};


class ContactManager final : public mozilla::DOMEventTargetHelper
{
public:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(ContactManager, mozilla::DOMEventTargetHelper)

private:
  nsRefPtr<ContactManagerJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  ContactManager(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~ContactManager();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMRequest> Find(const ContactFindOptions& options, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMCursor> GetAll(const ContactFindSortOptions& options, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMRequest> Clear(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMRequest> Save(mozContact& contact, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMRequest> Remove(const mozContactOrString& contactOrId, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMRequest> GetRevision(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMRequest> GetCount(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<EventHandlerNonNull> GetOncontactchange(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetOncontactchange(EventHandlerNonNull* arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


class mozContactJSImpl : public CallbackInterface
{
public:
  explicit inline mozContactJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  void Init(const ContactProperties& properties, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetMetadata(const nsAString& id, const Nullable<Date>& published, const Nullable<Date>& updated, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void __Init(const ContactProperties& properties, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const mozContactJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  void GetId(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  Nullable<Date> GetPublished(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  Nullable<Date> GetUpdated(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  Nullable<Date> GetBday(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  Nullable<Date> GetAnniversary(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetSex(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetGenderIdentity(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetPhoto(Nullable<nsTArray<nsRefPtr<Blob>>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetAdr(Nullable<nsTArray<ContactAddress>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetEmail(Nullable<nsTArray<ContactField>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetUrl(Nullable<nsTArray<ContactField>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetImpp(Nullable<nsTArray<ContactField>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetTel(Nullable<nsTArray<ContactTelField>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetHonorificPrefix(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetGivenName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetPhoneticGivenName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetAdditionalName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetFamilyName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetPhoneticFamilyName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetHonorificSuffix(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetNickname(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetCategory(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetOrg(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetJobTitle(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetNote(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetKey(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetId(const nsAString& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetBday(const Nullable<Date>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetAnniversary(const Nullable<Date>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetSex(const nsAString& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetGenderIdentity(const nsAString& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetPhoto(const Nullable<Sequence<OwningNonNull<Blob>>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetAdr(const Nullable<Sequence<ContactAddress>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetEmail(const Nullable<Sequence<ContactField>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetUrl(const Nullable<Sequence<ContactField>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetImpp(const Nullable<Sequence<ContactField>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetTel(const Nullable<Sequence<ContactTelField>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetHonorificPrefix(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetGivenName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetPhoneticGivenName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetAdditionalName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetFamilyName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetPhoneticFamilyName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetHonorificSuffix(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetNickname(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetCategory(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetOrg(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetJobTitle(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetNote(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetKey(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, mozContactAtoms* atomsCache);
};


class mozContact final : public nsSupportsWeakReference,
                         public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(mozContact)

private:
  nsRefPtr<mozContactJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  mozContact(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~mozContact();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  static already_AddRefed<mozContact> Constructor(const GlobalObject& global, JSContext* cx, const ContactProperties& properties, ErrorResult& aRv);

  void GetId(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetId(const nsAString& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  Nullable<Date> GetPublished(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  Nullable<Date> GetUpdated(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  Nullable<Date> GetBday(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetBday(const Nullable<Date>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  Nullable<Date> GetAnniversary(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetAnniversary(const Nullable<Date>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetSex(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetSex(const nsAString& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetGenderIdentity(nsString& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetGenderIdentity(const nsAString& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetPhoto(Nullable<nsTArray<nsRefPtr<Blob>>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetPhoto(const Nullable<Sequence<OwningNonNull<Blob>>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetAdr(Nullable<nsTArray<ContactAddress>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetAdr(const Nullable<Sequence<ContactAddress>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetEmail(Nullable<nsTArray<ContactField>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetEmail(const Nullable<Sequence<ContactField>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetUrl(Nullable<nsTArray<ContactField>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetUrl(const Nullable<Sequence<ContactField>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetImpp(Nullable<nsTArray<ContactField>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetImpp(const Nullable<Sequence<ContactField>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetTel(Nullable<nsTArray<ContactTelField>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetTel(const Nullable<Sequence<ContactTelField>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetHonorificPrefix(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetHonorificPrefix(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetGivenName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetGivenName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetPhoneticGivenName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetPhoneticGivenName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetAdditionalName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetAdditionalName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetFamilyName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetFamilyName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetPhoneticFamilyName(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetPhoneticFamilyName(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetHonorificSuffix(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetHonorificSuffix(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetNickname(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetNickname(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetCategory(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetCategory(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetOrg(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetOrg(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetJobTitle(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetJobTitle(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetNote(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetNote(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void GetKey(Nullable<nsTArray<nsString>>& aRetVal, ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetKey(const Nullable<Sequence<nsString>>& arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void Init(const ContactProperties& properties, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetMetadata(const nsAString& id, const Nullable<Date>& published, const Nullable<Date>& updated, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_ContactsBinding_h
