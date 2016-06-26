#ifndef mozilla_dom_UnionTypes_h
#define mozilla_dom_UnionTypes_h

#include "jsfriendapi.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/OwningNonNull.h"
#include "mozilla/dom/TypedArray.h"
#include "mozilla/dom/UnionMember.h"

class nsGenericHTMLElement;

namespace mozilla {
namespace dom {

class Blob;
class HTMLOptGroupElement;
class HTMLOptionElement;
class OwningArrayBufferOrArrayBufferViewOrBlobOrString;
class OwningHTMLElementOrLong;
class OwningHTMLOptionElementOrHTMLOptGroupElement;
class OwningStringOrBlobOrArrayBufferOrArrayBufferView;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {
void
ImplCycleCollectionTraverse(nsCycleCollectionTraversalCallback& aCallback, OwningArrayBufferOrArrayBufferViewOrBlobOrString& aUnion, const char* aName, uint32_t aFlags = 0);

void
ImplCycleCollectionTraverse(nsCycleCollectionTraversalCallback& aCallback, OwningHTMLElementOrLong& aUnion, const char* aName, uint32_t aFlags = 0);

void
ImplCycleCollectionTraverse(nsCycleCollectionTraversalCallback& aCallback, OwningHTMLOptionElementOrHTMLOptGroupElement& aUnion, const char* aName, uint32_t aFlags = 0);

void
ImplCycleCollectionTraverse(nsCycleCollectionTraversalCallback& aCallback, OwningStringOrBlobOrArrayBufferOrArrayBufferView& aUnion, const char* aName, uint32_t aFlags = 0);

void
ImplCycleCollectionUnlink(OwningArrayBufferOrArrayBufferViewOrBlobOrString& aUnion);

void
ImplCycleCollectionUnlink(OwningHTMLElementOrLong& aUnion);

void
ImplCycleCollectionUnlink(OwningHTMLOptionElementOrHTMLOptGroupElement& aUnion);

void
ImplCycleCollectionUnlink(OwningStringOrBlobOrArrayBufferOrArrayBufferView& aUnion);

class ArrayBufferOrArrayBufferViewOrBlobOrString
{
  friend class ArrayBufferOrArrayBufferViewOrBlobOrStringArgument;
  enum Type
  {
    eUninitialized,
    eArrayBuffer,
    eArrayBufferView,
    eBlob,
    eString
  };

  union Value
  {
    UnionMember<RootedTypedArray<ArrayBuffer> > mArrayBuffer;
    UnionMember<RootedTypedArray<ArrayBufferView> > mArrayBufferView;
    UnionMember<NonNull<mozilla::dom::Blob> > mBlob;
    UnionMember<binding_detail::FakeString > mString;

  };

  Type mType;
  Value mValue;

  ArrayBufferOrArrayBufferViewOrBlobOrString(const ArrayBufferOrArrayBufferViewOrBlobOrString&) = delete;
  void operator=(const ArrayBufferOrArrayBufferViewOrBlobOrString) = delete;
public:
  explicit inline ArrayBufferOrArrayBufferViewOrBlobOrString()
    : mType(eUninitialized)
  {
  }

  inline ~ArrayBufferOrArrayBufferViewOrBlobOrString()
  {
    Uninit();
  }

  inline RootedTypedArray<ArrayBuffer>&
  RawSetAsArrayBuffer(JSContext* cx)
  {
    if (mType == eArrayBuffer) {
      return mValue.mArrayBuffer.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eArrayBuffer;
    return mValue.mArrayBuffer.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBuffer>&
  SetAsArrayBuffer(JSContext* cx)
  {
    if (mType == eArrayBuffer) {
      return mValue.mArrayBuffer.Value();
    }
    Uninit();
    mType = eArrayBuffer;
    return mValue.mArrayBuffer.SetValue(cx);
  }

  inline bool
  IsArrayBuffer() const
  {
    return mType == eArrayBuffer;
  }

  inline RootedTypedArray<ArrayBuffer>&
  GetAsArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  inline ArrayBuffer const &
  GetAsArrayBuffer() const
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  inline RootedTypedArray<ArrayBufferView>&
  RawSetAsArrayBufferView(JSContext* cx)
  {
    if (mType == eArrayBufferView) {
      return mValue.mArrayBufferView.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eArrayBufferView;
    return mValue.mArrayBufferView.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBufferView>&
  SetAsArrayBufferView(JSContext* cx)
  {
    if (mType == eArrayBufferView) {
      return mValue.mArrayBufferView.Value();
    }
    Uninit();
    mType = eArrayBufferView;
    return mValue.mArrayBufferView.SetValue(cx);
  }

  inline bool
  IsArrayBufferView() const
  {
    return mType == eArrayBufferView;
  }

  inline RootedTypedArray<ArrayBufferView>&
  GetAsArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  inline ArrayBufferView const &
  GetAsArrayBufferView() const
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  inline NonNull<mozilla::dom::Blob>&
  RawSetAsBlob()
  {
    if (mType == eBlob) {
      return mValue.mBlob.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eBlob;
    return mValue.mBlob.SetValue();
  }

  inline NonNull<mozilla::dom::Blob>&
  SetAsBlob()
  {
    if (mType == eBlob) {
      return mValue.mBlob.Value();
    }
    Uninit();
    mType = eBlob;
    return mValue.mBlob.SetValue();
  }

  inline bool
  IsBlob() const
  {
    return mType == eBlob;
  }

  inline NonNull<mozilla::dom::Blob>&
  GetAsBlob()
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return mValue.mBlob.Value();
  }

  inline mozilla::dom::Blob&
  GetAsBlob() const
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return mValue.mBlob.Value();
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
      case eArrayBuffer: {
        DestroyArrayBuffer();
        break;
      }
      case eArrayBufferView: {
        DestroyArrayBufferView();
        break;
      }
      case eBlob: {
        DestroyBlob();
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
  DestroyArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    mValue.mArrayBuffer.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    mValue.mArrayBufferView.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyBlob()
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    mValue.mBlob.Destroy();
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

class ArrayBufferViewOrArrayBuffer
{
  friend class ArrayBufferViewOrArrayBufferArgument;
  enum Type
  {
    eUninitialized,
    eArrayBufferView,
    eArrayBuffer
  };

  union Value
  {
    UnionMember<RootedTypedArray<ArrayBufferView> > mArrayBufferView;
    UnionMember<RootedTypedArray<ArrayBuffer> > mArrayBuffer;

  };

  Type mType;
  Value mValue;

  ArrayBufferViewOrArrayBuffer(const ArrayBufferViewOrArrayBuffer&) = delete;
  void operator=(const ArrayBufferViewOrArrayBuffer) = delete;
public:
  explicit inline ArrayBufferViewOrArrayBuffer()
    : mType(eUninitialized)
  {
  }

  inline ~ArrayBufferViewOrArrayBuffer()
  {
    Uninit();
  }

  inline RootedTypedArray<ArrayBufferView>&
  RawSetAsArrayBufferView(JSContext* cx)
  {
    if (mType == eArrayBufferView) {
      return mValue.mArrayBufferView.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eArrayBufferView;
    return mValue.mArrayBufferView.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBufferView>&
  SetAsArrayBufferView(JSContext* cx)
  {
    if (mType == eArrayBufferView) {
      return mValue.mArrayBufferView.Value();
    }
    Uninit();
    mType = eArrayBufferView;
    return mValue.mArrayBufferView.SetValue(cx);
  }

  inline bool
  IsArrayBufferView() const
  {
    return mType == eArrayBufferView;
  }

  inline RootedTypedArray<ArrayBufferView>&
  GetAsArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  inline ArrayBufferView const &
  GetAsArrayBufferView() const
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  inline RootedTypedArray<ArrayBuffer>&
  RawSetAsArrayBuffer(JSContext* cx)
  {
    if (mType == eArrayBuffer) {
      return mValue.mArrayBuffer.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eArrayBuffer;
    return mValue.mArrayBuffer.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBuffer>&
  SetAsArrayBuffer(JSContext* cx)
  {
    if (mType == eArrayBuffer) {
      return mValue.mArrayBuffer.Value();
    }
    Uninit();
    mType = eArrayBuffer;
    return mValue.mArrayBuffer.SetValue(cx);
  }

  inline bool
  IsArrayBuffer() const
  {
    return mType == eArrayBuffer;
  }

  inline RootedTypedArray<ArrayBuffer>&
  GetAsArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  inline ArrayBuffer const &
  GetAsArrayBuffer() const
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eArrayBufferView: {
        DestroyArrayBufferView();
        break;
      }
      case eArrayBuffer: {
        DestroyArrayBuffer();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    mValue.mArrayBufferView.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    mValue.mArrayBuffer.Destroy();
    mType = eUninitialized;
  }
};

class HTMLElementOrLong
{
  friend class HTMLElementOrLongArgument;
  enum Type
  {
    eUninitialized,
    eHTMLElement,
    eLong
  };

  union Value
  {
    UnionMember<NonNull<nsGenericHTMLElement> > mHTMLElement;
    UnionMember<int32_t > mLong;

  };

  Type mType;
  Value mValue;

  HTMLElementOrLong(const HTMLElementOrLong&) = delete;
  void operator=(const HTMLElementOrLong) = delete;
public:
  explicit inline HTMLElementOrLong()
    : mType(eUninitialized)
  {
  }

  inline ~HTMLElementOrLong()
  {
    Uninit();
  }

  inline NonNull<nsGenericHTMLElement>&
  RawSetAsHTMLElement()
  {
    if (mType == eHTMLElement) {
      return mValue.mHTMLElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLElement;
    return mValue.mHTMLElement.SetValue();
  }

  inline NonNull<nsGenericHTMLElement>&
  SetAsHTMLElement()
  {
    if (mType == eHTMLElement) {
      return mValue.mHTMLElement.Value();
    }
    Uninit();
    mType = eHTMLElement;
    return mValue.mHTMLElement.SetValue();
  }

  inline bool
  IsHTMLElement() const
  {
    return mType == eHTMLElement;
  }

  inline NonNull<nsGenericHTMLElement>&
  GetAsHTMLElement()
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    return mValue.mHTMLElement.Value();
  }

  inline nsGenericHTMLElement&
  GetAsHTMLElement() const
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    return mValue.mHTMLElement.Value();
  }

  inline int32_t&
  RawSetAsLong()
  {
    if (mType == eLong) {
      return mValue.mLong.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eLong;
    return mValue.mLong.SetValue();
  }

  inline int32_t&
  SetAsLong()
  {
    if (mType == eLong) {
      return mValue.mLong.Value();
    }
    Uninit();
    mType = eLong;
    return mValue.mLong.SetValue();
  }

  inline bool
  IsLong() const
  {
    return mType == eLong;
  }

  inline int32_t&
  GetAsLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return mValue.mLong.Value();
  }

  inline int32_t
  GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return mValue.mLong.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eHTMLElement: {
        DestroyHTMLElement();
        break;
      }
      case eLong: {
        DestroyLong();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyHTMLElement()
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    mValue.mHTMLElement.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    mValue.mLong.Destroy();
    mType = eUninitialized;
  }
};

class HTMLOptionElementOrHTMLOptGroupElement
{
  friend class HTMLOptionElementOrHTMLOptGroupElementArgument;
  enum Type
  {
    eUninitialized,
    eHTMLOptionElement,
    eHTMLOptGroupElement
  };

  union Value
  {
    UnionMember<NonNull<mozilla::dom::HTMLOptionElement> > mHTMLOptionElement;
    UnionMember<NonNull<mozilla::dom::HTMLOptGroupElement> > mHTMLOptGroupElement;

  };

  Type mType;
  Value mValue;

  HTMLOptionElementOrHTMLOptGroupElement(const HTMLOptionElementOrHTMLOptGroupElement&) = delete;
  void operator=(const HTMLOptionElementOrHTMLOptGroupElement) = delete;
public:
  explicit inline HTMLOptionElementOrHTMLOptGroupElement()
    : mType(eUninitialized)
  {
  }

  inline ~HTMLOptionElementOrHTMLOptGroupElement()
  {
    Uninit();
  }

  inline NonNull<mozilla::dom::HTMLOptionElement>&
  RawSetAsHTMLOptionElement()
  {
    if (mType == eHTMLOptionElement) {
      return mValue.mHTMLOptionElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLOptionElement;
    return mValue.mHTMLOptionElement.SetValue();
  }

  inline NonNull<mozilla::dom::HTMLOptionElement>&
  SetAsHTMLOptionElement()
  {
    if (mType == eHTMLOptionElement) {
      return mValue.mHTMLOptionElement.Value();
    }
    Uninit();
    mType = eHTMLOptionElement;
    return mValue.mHTMLOptionElement.SetValue();
  }

  inline bool
  IsHTMLOptionElement() const
  {
    return mType == eHTMLOptionElement;
  }

  inline NonNull<mozilla::dom::HTMLOptionElement>&
  GetAsHTMLOptionElement()
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    return mValue.mHTMLOptionElement.Value();
  }

  inline mozilla::dom::HTMLOptionElement&
  GetAsHTMLOptionElement() const
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    return mValue.mHTMLOptionElement.Value();
  }

  inline NonNull<mozilla::dom::HTMLOptGroupElement>&
  RawSetAsHTMLOptGroupElement()
  {
    if (mType == eHTMLOptGroupElement) {
      return mValue.mHTMLOptGroupElement.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eHTMLOptGroupElement;
    return mValue.mHTMLOptGroupElement.SetValue();
  }

  inline NonNull<mozilla::dom::HTMLOptGroupElement>&
  SetAsHTMLOptGroupElement()
  {
    if (mType == eHTMLOptGroupElement) {
      return mValue.mHTMLOptGroupElement.Value();
    }
    Uninit();
    mType = eHTMLOptGroupElement;
    return mValue.mHTMLOptGroupElement.SetValue();
  }

  inline bool
  IsHTMLOptGroupElement() const
  {
    return mType == eHTMLOptGroupElement;
  }

  inline NonNull<mozilla::dom::HTMLOptGroupElement>&
  GetAsHTMLOptGroupElement()
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    return mValue.mHTMLOptGroupElement.Value();
  }

  inline mozilla::dom::HTMLOptGroupElement&
  GetAsHTMLOptGroupElement() const
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    return mValue.mHTMLOptGroupElement.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eHTMLOptionElement: {
        DestroyHTMLOptionElement();
        break;
      }
      case eHTMLOptGroupElement: {
        DestroyHTMLOptGroupElement();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyHTMLOptionElement()
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    mValue.mHTMLOptionElement.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyHTMLOptGroupElement()
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    mValue.mHTMLOptGroupElement.Destroy();
    mType = eUninitialized;
  }
};

class StringOrBlobOrArrayBufferOrArrayBufferView
{
  friend class StringOrBlobOrArrayBufferOrArrayBufferViewArgument;
  enum Type
  {
    eUninitialized,
    eString,
    eBlob,
    eArrayBuffer,
    eArrayBufferView
  };

  union Value
  {
    UnionMember<binding_detail::FakeString > mString;
    UnionMember<NonNull<mozilla::dom::Blob> > mBlob;
    UnionMember<RootedTypedArray<ArrayBuffer> > mArrayBuffer;
    UnionMember<RootedTypedArray<ArrayBufferView> > mArrayBufferView;

  };

  Type mType;
  Value mValue;

  StringOrBlobOrArrayBufferOrArrayBufferView(const StringOrBlobOrArrayBufferOrArrayBufferView&) = delete;
  void operator=(const StringOrBlobOrArrayBufferOrArrayBufferView) = delete;
public:
  explicit inline StringOrBlobOrArrayBufferOrArrayBufferView()
    : mType(eUninitialized)
  {
  }

  inline ~StringOrBlobOrArrayBufferOrArrayBufferView()
  {
    Uninit();
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

  inline NonNull<mozilla::dom::Blob>&
  RawSetAsBlob()
  {
    if (mType == eBlob) {
      return mValue.mBlob.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eBlob;
    return mValue.mBlob.SetValue();
  }

  inline NonNull<mozilla::dom::Blob>&
  SetAsBlob()
  {
    if (mType == eBlob) {
      return mValue.mBlob.Value();
    }
    Uninit();
    mType = eBlob;
    return mValue.mBlob.SetValue();
  }

  inline bool
  IsBlob() const
  {
    return mType == eBlob;
  }

  inline NonNull<mozilla::dom::Blob>&
  GetAsBlob()
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return mValue.mBlob.Value();
  }

  inline mozilla::dom::Blob&
  GetAsBlob() const
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return mValue.mBlob.Value();
  }

  inline RootedTypedArray<ArrayBuffer>&
  RawSetAsArrayBuffer(JSContext* cx)
  {
    if (mType == eArrayBuffer) {
      return mValue.mArrayBuffer.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eArrayBuffer;
    return mValue.mArrayBuffer.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBuffer>&
  SetAsArrayBuffer(JSContext* cx)
  {
    if (mType == eArrayBuffer) {
      return mValue.mArrayBuffer.Value();
    }
    Uninit();
    mType = eArrayBuffer;
    return mValue.mArrayBuffer.SetValue(cx);
  }

  inline bool
  IsArrayBuffer() const
  {
    return mType == eArrayBuffer;
  }

  inline RootedTypedArray<ArrayBuffer>&
  GetAsArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  inline ArrayBuffer const &
  GetAsArrayBuffer() const
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  inline RootedTypedArray<ArrayBufferView>&
  RawSetAsArrayBufferView(JSContext* cx)
  {
    if (mType == eArrayBufferView) {
      return mValue.mArrayBufferView.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eArrayBufferView;
    return mValue.mArrayBufferView.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBufferView>&
  SetAsArrayBufferView(JSContext* cx)
  {
    if (mType == eArrayBufferView) {
      return mValue.mArrayBufferView.Value();
    }
    Uninit();
    mType = eArrayBufferView;
    return mValue.mArrayBufferView.SetValue(cx);
  }

  inline bool
  IsArrayBufferView() const
  {
    return mType == eArrayBufferView;
  }

  inline RootedTypedArray<ArrayBufferView>&
  GetAsArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  inline ArrayBufferView const &
  GetAsArrayBufferView() const
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eString: {
        DestroyString();
        break;
      }
      case eBlob: {
        DestroyBlob();
        break;
      }
      case eArrayBuffer: {
        DestroyArrayBuffer();
        break;
      }
      case eArrayBufferView: {
        DestroyArrayBufferView();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyBlob()
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    mValue.mBlob.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    mValue.mArrayBuffer.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    mValue.mArrayBufferView.Destroy();
    mType = eUninitialized;
  }
};

class StringOrStringSequence
{
  friend class StringOrStringSequenceArgument;
  enum Type
  {
    eUninitialized,
    eString,
    eStringSequence
  };

  union Value
  {
    UnionMember<binding_detail::FakeString > mString;
    UnionMember<binding_detail::AutoSequence<nsString> > mStringSequence;

  };

  Type mType;
  Value mValue;

  StringOrStringSequence(const StringOrStringSequence&) = delete;
  void operator=(const StringOrStringSequence) = delete;
public:
  explicit inline StringOrStringSequence()
    : mType(eUninitialized)
  {
  }

  inline ~StringOrStringSequence()
  {
    Uninit();
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

  inline binding_detail::AutoSequence<nsString>&
  RawSetAsStringSequence()
  {
    if (mType == eStringSequence) {
      return mValue.mStringSequence.Value();
    }
    MOZ_ASSERT(mType == eUninitialized);
    mType = eStringSequence;
    return mValue.mStringSequence.SetValue();
  }

  inline binding_detail::AutoSequence<nsString>&
  SetAsStringSequence()
  {
    if (mType == eStringSequence) {
      return mValue.mStringSequence.Value();
    }
    Uninit();
    mType = eStringSequence;
    return mValue.mStringSequence.SetValue();
  }

  inline bool
  IsStringSequence() const
  {
    return mType == eStringSequence;
  }

  inline binding_detail::AutoSequence<nsString>&
  GetAsStringSequence()
  {
    MOZ_ASSERT(IsStringSequence(), "Wrong type!");
    return mValue.mStringSequence.Value();
  }

  inline const Sequence<nsString>&
  GetAsStringSequence() const
  {
    MOZ_ASSERT(IsStringSequence(), "Wrong type!");
    return mValue.mStringSequence.Value();
  }

  inline void
  Uninit()
  {
    switch (mType) {
      case eUninitialized: {
        break;
      }
      case eString: {
        DestroyString();
        break;
      }
      case eStringSequence: {
        DestroyStringSequence();
        break;
      }
    }
  }

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

private:
  inline void
  DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }

  inline void
  DestroyStringSequence()
  {
    MOZ_ASSERT(IsStringSequence(), "Wrong type!");
    mValue.mStringSequence.Destroy();
    mType = eUninitialized;
  }
};

class OwningArrayBufferOrArrayBufferViewOrBlobOrString : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningArrayBufferOrArrayBufferViewOrBlobOrString& aUnion);
  enum Type
  {
    eUninitialized,
    eArrayBuffer,
    eArrayBufferView,
    eBlob,
    eString
  };

  union Value
  {
    UnionMember<ArrayBuffer > mArrayBuffer;
    UnionMember<ArrayBufferView > mArrayBufferView;
    UnionMember<OwningNonNull<mozilla::dom::Blob> > mBlob;
    UnionMember<nsString > mString;

  };

  Type mType;
  Value mValue;

  OwningArrayBufferOrArrayBufferViewOrBlobOrString(const OwningArrayBufferOrArrayBufferViewOrBlobOrString&) = delete;
  void operator=(const OwningArrayBufferOrArrayBufferViewOrBlobOrString) = delete;
public:
  explicit inline OwningArrayBufferOrArrayBufferViewOrBlobOrString()
    : mType(eUninitialized)
  {
  }

  inline ~OwningArrayBufferOrArrayBufferViewOrBlobOrString()
  {
    Uninit();
  }

  ArrayBuffer&
  RawSetAsArrayBuffer();

  ArrayBuffer&
  SetAsArrayBuffer();

  bool
  TrySetToArrayBuffer(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsArrayBuffer() const
  {
    return mType == eArrayBuffer;
  }

  inline ArrayBuffer&
  GetAsArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  inline ArrayBuffer const &
  GetAsArrayBuffer() const
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  ArrayBufferView&
  RawSetAsArrayBufferView();

  ArrayBufferView&
  SetAsArrayBufferView();

  bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsArrayBufferView() const
  {
    return mType == eArrayBufferView;
  }

  inline ArrayBufferView&
  GetAsArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  inline ArrayBufferView const &
  GetAsArrayBufferView() const
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  OwningNonNull<mozilla::dom::Blob>&
  RawSetAsBlob();

  OwningNonNull<mozilla::dom::Blob>&
  SetAsBlob();

  bool
  TrySetToBlob(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsBlob() const
  {
    return mType == eBlob;
  }

  inline OwningNonNull<mozilla::dom::Blob>&
  GetAsBlob()
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return mValue.mBlob.Value();
  }

  inline OwningNonNull<mozilla::dom::Blob> const &
  GetAsBlob() const
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return mValue.mBlob.Value();
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

private:
  void
  DestroyArrayBuffer();

  void
  DestroyArrayBufferView();

  void
  DestroyBlob();

  void
  DestroyString();
};

class OwningArrayBufferViewOrArrayBuffer : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningArrayBufferViewOrArrayBuffer& aUnion);
  enum Type
  {
    eUninitialized,
    eArrayBufferView,
    eArrayBuffer
  };

  union Value
  {
    UnionMember<ArrayBufferView > mArrayBufferView;
    UnionMember<ArrayBuffer > mArrayBuffer;

  };

  Type mType;
  Value mValue;

  OwningArrayBufferViewOrArrayBuffer(const OwningArrayBufferViewOrArrayBuffer&) = delete;
  void operator=(const OwningArrayBufferViewOrArrayBuffer) = delete;
public:
  explicit inline OwningArrayBufferViewOrArrayBuffer()
    : mType(eUninitialized)
  {
  }

  inline ~OwningArrayBufferViewOrArrayBuffer()
  {
    Uninit();
  }

  ArrayBufferView&
  RawSetAsArrayBufferView();

  ArrayBufferView&
  SetAsArrayBufferView();

  bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsArrayBufferView() const
  {
    return mType == eArrayBufferView;
  }

  inline ArrayBufferView&
  GetAsArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  inline ArrayBufferView const &
  GetAsArrayBufferView() const
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  ArrayBuffer&
  RawSetAsArrayBuffer();

  ArrayBuffer&
  SetAsArrayBuffer();

  bool
  TrySetToArrayBuffer(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsArrayBuffer() const
  {
    return mType == eArrayBuffer;
  }

  inline ArrayBuffer&
  GetAsArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  inline ArrayBuffer const &
  GetAsArrayBuffer() const
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyArrayBufferView();

  void
  DestroyArrayBuffer();
};

class OwningHTMLElementOrLong : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningHTMLElementOrLong& aUnion);
  enum Type
  {
    eUninitialized,
    eHTMLElement,
    eLong
  };

  union Value
  {
    UnionMember<OwningNonNull<nsGenericHTMLElement> > mHTMLElement;
    UnionMember<int32_t > mLong;

  };

  Type mType;
  Value mValue;

public:
  explicit inline OwningHTMLElementOrLong()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningHTMLElementOrLong(const OwningHTMLElementOrLong& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  inline ~OwningHTMLElementOrLong()
  {
    Uninit();
  }

  OwningNonNull<nsGenericHTMLElement>&
  RawSetAsHTMLElement();

  OwningNonNull<nsGenericHTMLElement>&
  SetAsHTMLElement();

  bool
  TrySetToHTMLElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsHTMLElement() const
  {
    return mType == eHTMLElement;
  }

  inline OwningNonNull<nsGenericHTMLElement>&
  GetAsHTMLElement()
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    return mValue.mHTMLElement.Value();
  }

  inline OwningNonNull<nsGenericHTMLElement> const &
  GetAsHTMLElement() const
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    return mValue.mHTMLElement.Value();
  }

  int32_t&
  RawSetAsLong();

  int32_t&
  SetAsLong();

  bool
  TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsLong() const
  {
    return mType == eLong;
  }

  inline int32_t&
  GetAsLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return mValue.mLong.Value();
  }

  inline int32_t const &
  GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return mValue.mLong.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningHTMLElementOrLong& aOther);

private:
  void
  DestroyHTMLElement();

  void
  DestroyLong();
};

class OwningHTMLOptionElementOrHTMLOptGroupElement : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningHTMLOptionElementOrHTMLOptGroupElement& aUnion);
  enum Type
  {
    eUninitialized,
    eHTMLOptionElement,
    eHTMLOptGroupElement
  };

  union Value
  {
    UnionMember<OwningNonNull<mozilla::dom::HTMLOptionElement> > mHTMLOptionElement;
    UnionMember<OwningNonNull<mozilla::dom::HTMLOptGroupElement> > mHTMLOptGroupElement;

  };

  Type mType;
  Value mValue;

public:
  explicit inline OwningHTMLOptionElementOrHTMLOptGroupElement()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningHTMLOptionElementOrHTMLOptGroupElement(const OwningHTMLOptionElementOrHTMLOptGroupElement& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  inline ~OwningHTMLOptionElementOrHTMLOptGroupElement()
  {
    Uninit();
  }

  OwningNonNull<mozilla::dom::HTMLOptionElement>&
  RawSetAsHTMLOptionElement();

  OwningNonNull<mozilla::dom::HTMLOptionElement>&
  SetAsHTMLOptionElement();

  bool
  TrySetToHTMLOptionElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsHTMLOptionElement() const
  {
    return mType == eHTMLOptionElement;
  }

  inline OwningNonNull<mozilla::dom::HTMLOptionElement>&
  GetAsHTMLOptionElement()
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    return mValue.mHTMLOptionElement.Value();
  }

  inline OwningNonNull<mozilla::dom::HTMLOptionElement> const &
  GetAsHTMLOptionElement() const
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    return mValue.mHTMLOptionElement.Value();
  }

  OwningNonNull<mozilla::dom::HTMLOptGroupElement>&
  RawSetAsHTMLOptGroupElement();

  OwningNonNull<mozilla::dom::HTMLOptGroupElement>&
  SetAsHTMLOptGroupElement();

  bool
  TrySetToHTMLOptGroupElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsHTMLOptGroupElement() const
  {
    return mType == eHTMLOptGroupElement;
  }

  inline OwningNonNull<mozilla::dom::HTMLOptGroupElement>&
  GetAsHTMLOptGroupElement()
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    return mValue.mHTMLOptGroupElement.Value();
  }

  inline OwningNonNull<mozilla::dom::HTMLOptGroupElement> const &
  GetAsHTMLOptGroupElement() const
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    return mValue.mHTMLOptGroupElement.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningHTMLOptionElementOrHTMLOptGroupElement& aOther);

private:
  void
  DestroyHTMLOptionElement();

  void
  DestroyHTMLOptGroupElement();
};

class OwningStringOrBlobOrArrayBufferOrArrayBufferView : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningStringOrBlobOrArrayBufferOrArrayBufferView& aUnion);
  enum Type
  {
    eUninitialized,
    eString,
    eBlob,
    eArrayBuffer,
    eArrayBufferView
  };

  union Value
  {
    UnionMember<nsString > mString;
    UnionMember<OwningNonNull<mozilla::dom::Blob> > mBlob;
    UnionMember<ArrayBuffer > mArrayBuffer;
    UnionMember<ArrayBufferView > mArrayBufferView;

  };

  Type mType;
  Value mValue;

  OwningStringOrBlobOrArrayBufferOrArrayBufferView(const OwningStringOrBlobOrArrayBufferOrArrayBufferView&) = delete;
  void operator=(const OwningStringOrBlobOrArrayBufferOrArrayBufferView) = delete;
public:
  explicit inline OwningStringOrBlobOrArrayBufferOrArrayBufferView()
    : mType(eUninitialized)
  {
  }

  inline ~OwningStringOrBlobOrArrayBufferOrArrayBufferView()
  {
    Uninit();
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

  OwningNonNull<mozilla::dom::Blob>&
  RawSetAsBlob();

  OwningNonNull<mozilla::dom::Blob>&
  SetAsBlob();

  bool
  TrySetToBlob(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsBlob() const
  {
    return mType == eBlob;
  }

  inline OwningNonNull<mozilla::dom::Blob>&
  GetAsBlob()
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return mValue.mBlob.Value();
  }

  inline OwningNonNull<mozilla::dom::Blob> const &
  GetAsBlob() const
  {
    MOZ_ASSERT(IsBlob(), "Wrong type!");
    return mValue.mBlob.Value();
  }

  ArrayBuffer&
  RawSetAsArrayBuffer();

  ArrayBuffer&
  SetAsArrayBuffer();

  bool
  TrySetToArrayBuffer(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsArrayBuffer() const
  {
    return mType == eArrayBuffer;
  }

  inline ArrayBuffer&
  GetAsArrayBuffer()
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  inline ArrayBuffer const &
  GetAsArrayBuffer() const
  {
    MOZ_ASSERT(IsArrayBuffer(), "Wrong type!");
    return mValue.mArrayBuffer.Value();
  }

  ArrayBufferView&
  RawSetAsArrayBufferView();

  ArrayBufferView&
  SetAsArrayBufferView();

  bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsArrayBufferView() const
  {
    return mType == eArrayBufferView;
  }

  inline ArrayBufferView&
  GetAsArrayBufferView()
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  inline ArrayBufferView const &
  GetAsArrayBufferView() const
  {
    MOZ_ASSERT(IsArrayBufferView(), "Wrong type!");
    return mValue.mArrayBufferView.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

private:
  void
  DestroyString();

  void
  DestroyBlob();

  void
  DestroyArrayBuffer();

  void
  DestroyArrayBufferView();
};

class OwningStringOrStringSequence : public AllOwningUnionBase
{
  friend void ImplCycleCollectionUnlink(OwningStringOrStringSequence& aUnion);
  enum Type
  {
    eUninitialized,
    eString,
    eStringSequence
  };

  union Value
  {
    UnionMember<nsString > mString;
    UnionMember<Sequence<nsString> > mStringSequence;

  };

  Type mType;
  Value mValue;

public:
  explicit inline OwningStringOrStringSequence()
    : mType(eUninitialized)
  {
  }

  explicit inline OwningStringOrStringSequence(const OwningStringOrStringSequence& aOther)
    : mType(eUninitialized)
  {
    *this = aOther;
  }

  inline ~OwningStringOrStringSequence()
  {
    Uninit();
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

  Sequence<nsString>&
  RawSetAsStringSequence();

  Sequence<nsString>&
  SetAsStringSequence();

  bool
  TrySetToStringSequence(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false);

  inline bool
  IsStringSequence() const
  {
    return mType == eStringSequence;
  }

  inline Sequence<nsString>&
  GetAsStringSequence()
  {
    MOZ_ASSERT(IsStringSequence(), "Wrong type!");
    return mValue.mStringSequence.Value();
  }

  inline Sequence<nsString> const &
  GetAsStringSequence() const
  {
    MOZ_ASSERT(IsStringSequence(), "Wrong type!");
    return mValue.mStringSequence.Value();
  }

  void
  Uninit();

  bool
  ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceUnion(JSTracer* trc);

  void
  operator=(const OwningStringOrStringSequence& aOther);

private:
  void
  DestroyString();

  void
  DestroyStringSequence();
};
} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_UnionTypes_h
