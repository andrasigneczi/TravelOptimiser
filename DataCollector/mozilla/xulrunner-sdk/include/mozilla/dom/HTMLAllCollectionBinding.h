/* THIS FILE IS AUTOGENERATED FROM HTMLAllCollection.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_HTMLAllCollectionBinding_h
#define mozilla_dom_HTMLAllCollectionBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/UnionMember.h"

class nsIHTMLCollection;
class nsINode;

namespace mozilla {
namespace dom {

class HTMLAllCollection;
struct HTMLAllCollectionAtoms;
struct NativePropertyHooks;
class OwningNodeOrHTMLCollection;
class ProtoAndIfaceCache;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

void
ImplCycleCollectionTraverse(nsCycleCollectionTraversalCallback& aCallback, OwningNodeOrHTMLCollection& aUnion, const char* aName, uint32_t aFlags = 0);


void
ImplCycleCollectionUnlink(OwningNodeOrHTMLCollection& aUnion);


class NodeOrHTMLCollection
{
  friend class NodeOrHTMLCollectionArgument;
  enum Type
  {
    eUninitialized,
    eNode,
    eHTMLCollection
  };

  union Value
  {
    UnionMember<NonNull<nsINode> > mNode;
    UnionMember<NonNull<nsIHTMLCollection> > mHTMLCollection;

  };

  Type mType;
  Value mValue;

  NodeOrHTMLCollection(const NodeOrHTMLCollection&) = delete;
  void operator=(const NodeOrHTMLCollection) = delete;
public:
  explicit inline NodeOrHTMLCollection()
    : mType(eUninitialized)
  {
  }

  inline ~NodeOrHTMLCollection()
  {
    Uninit();
  }

  inline NonNull<nsINode>&
  RawSetAsNode()
  {
    if (mType == eNode) {
      return mValue.mNode.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eNode;
    return mValue.mNode.SetValue();
  }

  inline NonNull<nsINode>&
  SetAsNode()
  {
    if (mType == eNode) {
      return mValue.mNode.Value();
    }
    Uninit();
    mType = eNode;
    return mValue.mNode.SetValue();
  }

  inline bool
  IsNode() const
  {
    return mType == eNode;
  }

  inline NonNull<nsINode>&
  GetAsNode()
  {
    MOZ_ASSERT(IsNode(), "Wrong type!");
    return mValue.mNode.Value();
  }

  inline nsINode&
  GetAsNode() const
  {
    MOZ_ASSERT(IsNode(), "Wrong type!");
    return mValue.mNode.Value();
  }

  inline NonNull<nsIHTMLCollection>&
  RawSetAsHTMLCollection()
  {
    if (mType == eHTMLCollection) {
      return mValue.mHTMLCollection.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLCollection;
    return mValue.mHTMLCollection.SetValue();
  }

  inline NonNull<nsIHTMLCollection>&
  SetAsHTMLCollection()
  {
    if (mType == eHTMLCollection) {
      return mValue.mHTMLCollection.Value();
    }
    Uninit();
    mType = eHTMLCollection;
    return mValue.mHTMLCollection.SetValue();
  }

  inline bool
  IsHTMLCollection() const
  {
    return mType == eHTMLCollection;
  }

  inline NonNull<nsIHTMLCollection>&
  GetAsHTMLCollection()
  {
    MOZ_ASSERT(IsHTMLCollection(), "Wrong type!");
    return mValue.mHTMLCollection.Value();
  }

  inline nsIHTMLCollection&
  GetAsHTMLCollection() const
  {
    MOZ_ASSERT(IsHTMLCollection(), "Wrong type!");
    return mValue.mHTMLCollection.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eNode: {
        DestroyNode();
        break;
      }
      case eHTMLCollection: {
        DestroyHTMLCollection();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyNode()
  {
    MOZ_ASSERT(IsNode(), "Wrong type!");
    mValue.mNode.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyHTMLCollection()
  {
    MOZ_ASSERT(IsHTMLCollection(), "Wrong type!");
    mValue.mHTMLCollection.Destroy();
    mType = eUninitialized;
  }
};


class OwningNodeOrHTMLCollection : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningNodeOrHTMLCollection& aUnion);
  enum Type
  {
    eUninitialized,
    eNode,
    eHTMLCollection
  };

  union Value
  {
    UnionMember<OwningNonNull<nsINode> > mNode;
    UnionMember<OwningNonNull<nsIHTMLCollection> > mHTMLCollection;

  };

  Type mType;
  Value mValue;

public:
  explicit inline OwningNodeOrHTMLCollection()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningNodeOrHTMLCollection(const OwningNodeOrHTMLCollection& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  inline ~OwningNodeOrHTMLCollection()
  {
    Uninit();
  }

  OwningNonNull<nsINode>&
  RawSetAsNode();

  OwningNonNull<nsINode>&
  SetAsNode();

  bool
  TrySetToNode(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsNode() const
  {
    return mType == eNode;
  }

  inline OwningNonNull<nsINode>&
  GetAsNode()
  {
    MOZ_ASSERT(IsNode(), "Wrong type!");
    return mValue.mNode.Value();
  }

  inline OwningNonNull<nsINode> const &
  GetAsNode() const
  {
    MOZ_ASSERT(IsNode(), "Wrong type!");
    return mValue.mNode.Value();
  }

  OwningNonNull<nsIHTMLCollection>&
  RawSetAsHTMLCollection();

  OwningNonNull<nsIHTMLCollection>&
  SetAsHTMLCollection();

  bool
  TrySetToHTMLCollection(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsHTMLCollection() const
  {
    return mType == eHTMLCollection;
  }

  inline OwningNonNull<nsIHTMLCollection>&
  GetAsHTMLCollection()
  {
    MOZ_ASSERT(IsHTMLCollection(), "Wrong type!");
    return mValue.mHTMLCollection.Value();
  }

  inline OwningNonNull<nsIHTMLCollection> const &
  GetAsHTMLCollection() const
  {
    MOZ_ASSERT(IsHTMLCollection(), "Wrong type!");
    return mValue.mHTMLCollection.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningNodeOrHTMLCollection& aOther);

private:
  void
  DestroyNode();

  void
  DestroyHTMLCollection();
};


namespace HTMLAllCollectionBinding {

  typedef mozilla::dom::HTMLAllCollection NativeType;

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
  Wrap(JSContext* aCx, mozilla::dom::HTMLAllCollection* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace HTMLAllCollectionBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_HTMLAllCollectionBinding_h
