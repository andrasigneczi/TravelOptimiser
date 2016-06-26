#ifndef mozilla_dom_UnionConversions_h
#define mozilla_dom_UnionConversions_h

#include "AudioTrackBinding.h"
#include "BlobBinding.h"
#include "CanvasRenderingContext2DBinding.h"
#include "ClientBinding.h"
#include "ConsoleBinding.h"
#include "ConstraintsBinding.h"
#include "ContactsBinding.h"
#include "DOMMobileMessageErrorBinding.h"
#include "DataStoreBinding.h"
#include "DirectoryBinding.h"
#include "DocumentBinding.h"
#include "ElementBinding.h"
#include "EventBinding.h"
#include "EventHandlerBinding.h"
#include "ExternalBinding.h"
#include "FetchBinding.h"
#include "FetchEventBinding.h"
#include "FileBinding.h"
#include "FontFaceBinding.h"
#include "FormDataBinding.h"
#include "GeometryUtilsBinding.h"
#include "HTMLAllCollectionBinding.h"
#include "HTMLCanvasElementBinding.h"
#include "HTMLCollectionBinding.h"
#include "HTMLElementBinding.h"
#include "HTMLFormControlsCollectionBinding.h"
#include "HTMLImageElementBinding.h"
#include "HTMLOptGroupElementBinding.h"
#include "HTMLOptionElementBinding.h"
#include "HTMLVideoElementBinding.h"
#include "HeadersBinding.h"
#include "IDBCursorBinding.h"
#include "IDBIndexBinding.h"
#include "IDBObjectStoreBinding.h"
#include "IDBRequestBinding.h"
#include "InstallTriggerBinding.h"
#include "MediaStreamBinding.h"
#include "MediaStreamTrackBinding.h"
#include "MediaTrackConstraintSetBinding.h"
#include "MessageEventBinding.h"
#include "MessagePortBinding.h"
#include "MozIccBinding.h"
#include "MozIccInfoBinding.h"
#include "MozMobileConnectionBinding.h"
#include "MozMobileMessageManagerBinding.h"
#include "NavigatorBinding.h"
#include "NodeBinding.h"
#include "PromiseBinding.h"
#include "RadioNodeListBinding.h"
#include "RequestBinding.h"
#include "ResourceStatsBinding.h"
#include "ResponseBinding.h"
#include "SubtleCryptoBinding.h"
#include "TelephonyBinding.h"
#include "TelephonyCallBinding.h"
#include "TelephonyCallGroupBinding.h"
#include "TextBinding.h"
#include "TextTrackBinding.h"
#include "TrackEventBinding.h"
#include "URLSearchParamsBinding.h"
#include "VTTCueBinding.h"
#include "VideoTrackBinding.h"
#include "WebGL2RenderingContextBinding.h"
#include "WebGLRenderingContextBinding.h"
#include "WindowBinding.h"
#include "jsfriendapi.h"
#include "mozilla/dom/MozMap.h"
#include "mozilla/dom/PrimitiveConversions.h"
#include "mozilla/dom/TypedArray.h"
#include "mozilla/dom/UnionTypes.h"
#include "nsDebug.h"
#include "nsIDOMMozMmsMessage.h"
#include "nsIDOMMozSmsMessage.h"
#include "nsIDOMWindow.h"

namespace mozilla {
namespace dom {
class ArrayBufferOrArrayBufferViewOrBlobOrFormDataOrUSVStringOrURLSearchParamsArgument
{
  ArrayBufferOrArrayBufferViewOrBlobOrFormDataOrUSVStringOrURLSearchParams& mUnion;

  ArrayBufferOrArrayBufferViewOrBlobOrFormDataOrUSVStringOrURLSearchParamsArgument(const ArrayBufferOrArrayBufferViewOrBlobOrFormDataOrUSVStringOrURLSearchParamsArgument&) = delete;
  void operator=(const ArrayBufferOrArrayBufferViewOrBlobOrFormDataOrUSVStringOrURLSearchParamsArgument) = delete;
public:
  explicit inline ArrayBufferOrArrayBufferViewOrBlobOrFormDataOrUSVStringOrURLSearchParamsArgument(const ArrayBufferOrArrayBufferViewOrBlobOrFormDataOrUSVStringOrURLSearchParams& aUnion)
    : mUnion(const_cast<ArrayBufferOrArrayBufferViewOrBlobOrFormDataOrUSVStringOrURLSearchParams&>(aUnion))
  {
  }

  inline bool
  TrySetToArrayBuffer(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBuffer>& memberSlot = RawSetAsArrayBuffer(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBuffer();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

  inline bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBufferView>& memberSlot = RawSetAsArrayBufferView(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBufferView();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

  inline bool
  TrySetToBlob(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Blob>& memberSlot = RawSetAsBlob();
      {
        nsresult rv = UnwrapObject<prototypes::id::Blob, mozilla::dom::Blob>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyBlob();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToFormData(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsFormData>& memberSlot = RawSetAsFormData();
      {
        nsresult rv = UnwrapObject<prototypes::id::FormData, nsFormData>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyFormData();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToUSVString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsUSVString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
      NormalizeUSVString(cx, memberSlot);
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsUSVString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToURLSearchParams(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::URLSearchParams>& memberSlot = RawSetAsURLSearchParams();
      {
        nsresult rv = UnwrapObject<prototypes::id::URLSearchParams, mozilla::dom::URLSearchParams>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyURLSearchParams();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline RootedTypedArray<ArrayBuffer>&
  RawSetAsArrayBuffer(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBuffer;
    return mUnion.mValue.mArrayBuffer.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBufferView>&
  RawSetAsArrayBufferView(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBufferView;
    return mUnion.mValue.mArrayBufferView.SetValue(cx);
  }

  inline NonNull<mozilla::dom::Blob>&
  RawSetAsBlob()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eBlob;
    return mUnion.mValue.mBlob.SetValue();
  }

  inline NonNull<nsFormData>&
  RawSetAsFormData()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eFormData;
    return mUnion.mValue.mFormData.SetValue();
  }

  inline binding_detail::FakeString&
  RawSetAsUSVString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUSVString;
    return mUnion.mValue.mUSVString.SetValue();
  }

  inline NonNull<mozilla::dom::URLSearchParams>&
  RawSetAsURLSearchParams()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eURLSearchParams;
    return mUnion.mValue.mURLSearchParams.SetValue();
  }
};

class ArrayBufferOrArrayBufferViewOrBlobOrStringArgument
{
  ArrayBufferOrArrayBufferViewOrBlobOrString& mUnion;

  ArrayBufferOrArrayBufferViewOrBlobOrStringArgument(const ArrayBufferOrArrayBufferViewOrBlobOrStringArgument&) = delete;
  void operator=(const ArrayBufferOrArrayBufferViewOrBlobOrStringArgument) = delete;
public:
  explicit inline ArrayBufferOrArrayBufferViewOrBlobOrStringArgument(const ArrayBufferOrArrayBufferViewOrBlobOrString& aUnion)
    : mUnion(const_cast<ArrayBufferOrArrayBufferViewOrBlobOrString&>(aUnion))
  {
  }

  inline bool
  TrySetToArrayBuffer(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBuffer>& memberSlot = RawSetAsArrayBuffer(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBuffer();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

  inline bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBufferView>& memberSlot = RawSetAsArrayBufferView(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBufferView();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

  inline bool
  TrySetToBlob(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Blob>& memberSlot = RawSetAsBlob();
      {
        nsresult rv = UnwrapObject<prototypes::id::Blob, mozilla::dom::Blob>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyBlob();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

private:
  inline RootedTypedArray<ArrayBuffer>&
  RawSetAsArrayBuffer(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBuffer;
    return mUnion.mValue.mArrayBuffer.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBufferView>&
  RawSetAsArrayBufferView(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBufferView;
    return mUnion.mValue.mArrayBufferView.SetValue(cx);
  }

  inline NonNull<mozilla::dom::Blob>&
  RawSetAsBlob()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eBlob;
    return mUnion.mValue.mBlob.SetValue();
  }

  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
};

class ArrayBufferViewOrArrayBufferArgument
{
  ArrayBufferViewOrArrayBuffer& mUnion;

  ArrayBufferViewOrArrayBufferArgument(const ArrayBufferViewOrArrayBufferArgument&) = delete;
  void operator=(const ArrayBufferViewOrArrayBufferArgument) = delete;
public:
  explicit inline ArrayBufferViewOrArrayBufferArgument(const ArrayBufferViewOrArrayBuffer& aUnion)
    : mUnion(const_cast<ArrayBufferViewOrArrayBuffer&>(aUnion))
  {
  }

  inline bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBufferView>& memberSlot = RawSetAsArrayBufferView(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBufferView();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

  inline bool
  TrySetToArrayBuffer(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBuffer>& memberSlot = RawSetAsArrayBuffer(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBuffer();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

private:
  inline RootedTypedArray<ArrayBufferView>&
  RawSetAsArrayBufferView(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBufferView;
    return mUnion.mValue.mArrayBufferView.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBuffer>&
  RawSetAsArrayBuffer(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBuffer;
    return mUnion.mValue.mArrayBuffer.SetValue(cx);
  }
};

class ArrayBufferViewOrBlobOrStringOrFormDataArgument
{
  ArrayBufferViewOrBlobOrStringOrFormData& mUnion;

  ArrayBufferViewOrBlobOrStringOrFormDataArgument(const ArrayBufferViewOrBlobOrStringOrFormDataArgument&) = delete;
  void operator=(const ArrayBufferViewOrBlobOrStringOrFormDataArgument) = delete;
public:
  explicit inline ArrayBufferViewOrBlobOrStringOrFormDataArgument(const ArrayBufferViewOrBlobOrStringOrFormData& aUnion)
    : mUnion(const_cast<ArrayBufferViewOrBlobOrStringOrFormData&>(aUnion))
  {
  }

  inline bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBufferView>& memberSlot = RawSetAsArrayBufferView(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBufferView();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

  inline bool
  TrySetToBlob(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Blob>& memberSlot = RawSetAsBlob();
      {
        nsresult rv = UnwrapObject<prototypes::id::Blob, mozilla::dom::Blob>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyBlob();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToFormData(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsFormData>& memberSlot = RawSetAsFormData();
      {
        nsresult rv = UnwrapObject<prototypes::id::FormData, nsFormData>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyFormData();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline RootedTypedArray<ArrayBufferView>&
  RawSetAsArrayBufferView(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBufferView;
    return mUnion.mValue.mArrayBufferView.SetValue(cx);
  }

  inline NonNull<mozilla::dom::Blob>&
  RawSetAsBlob()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eBlob;
    return mUnion.mValue.mBlob.SetValue();
  }

  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline NonNull<nsFormData>&
  RawSetAsFormData()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eFormData;
    return mUnion.mValue.mFormData.SetValue();
  }
};

class BooleanOrMediaTrackConstraintsArgument
{
  BooleanOrMediaTrackConstraints& mUnion;

  BooleanOrMediaTrackConstraintsArgument(const BooleanOrMediaTrackConstraintsArgument&) = delete;
  void operator=(const BooleanOrMediaTrackConstraintsArgument) = delete;
public:
  explicit inline BooleanOrMediaTrackConstraintsArgument(const BooleanOrMediaTrackConstraints& aUnion)
    : mUnion(const_cast<BooleanOrMediaTrackConstraints&>(aUnion))
  {
  }

  inline bool
  TrySetToBoolean(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      bool& memberSlot = RawSetAsBoolean();
      if (!ValueToPrimitive<bool, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline bool
  TrySetToMediaTrackConstraints(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FastMediaTrackConstraints& memberSlot = RawSetAsMediaTrackConstraints();
      if (!IsConvertibleToDictionary(cx, value)) {
        mUnion.DestroyMediaTrackConstraints();
        tryNext = true;
        return true;
      }

      if (!memberSlot.Init(cx, value, "Member of BooleanOrMediaTrackConstraints", passedToJSImpl)) {
        return false;
      }
    }
    return true;
  }

private:
  inline bool&
  RawSetAsBoolean()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eBoolean;
    return mUnion.mValue.mBoolean.SetValue();
  }

  inline binding_detail::FastMediaTrackConstraints&
  RawSetAsMediaTrackConstraints()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMediaTrackConstraints;
    return mUnion.mValue.mMediaTrackConstraints.SetValue();
  }
};

class DoubleOrConstrainDoubleRangeArgument
{
  DoubleOrConstrainDoubleRange& mUnion;

  DoubleOrConstrainDoubleRangeArgument(const DoubleOrConstrainDoubleRangeArgument&) = delete;
  void operator=(const DoubleOrConstrainDoubleRangeArgument) = delete;
public:
  explicit inline DoubleOrConstrainDoubleRangeArgument(const DoubleOrConstrainDoubleRange& aUnion)
    : mUnion(const_cast<DoubleOrConstrainDoubleRange&>(aUnion))
  {
  }

  inline bool
  TrySetToDouble(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      double& memberSlot = RawSetAsDouble();
      if (!ValueToPrimitive<double, eDefault>(cx, value, &memberSlot)) {
        return false;
      } else if (!mozilla::IsFinite(memberSlot)) {
        // Note: mozilla::IsFinite will do the right thing
        //       when passed a non-finite float too.
        ThrowErrorMessage(cx, MSG_NOT_FINITE, "Member of DoubleOrConstrainDoubleRange");
        return false;
      }
    }
    return true;
  }

  inline bool
  TrySetToConstrainDoubleRange(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FastConstrainDoubleRange& memberSlot = RawSetAsConstrainDoubleRange();
      if (!IsConvertibleToDictionary(cx, value)) {
        mUnion.DestroyConstrainDoubleRange();
        tryNext = true;
        return true;
      }

      if (!memberSlot.Init(cx, value, "Member of DoubleOrConstrainDoubleRange", passedToJSImpl)) {
        return false;
      }
    }
    return true;
  }

private:
  inline double&
  RawSetAsDouble()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eDouble;
    return mUnion.mValue.mDouble.SetValue();
  }

  inline binding_detail::FastConstrainDoubleRange&
  RawSetAsConstrainDoubleRange()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eConstrainDoubleRange;
    return mUnion.mValue.mConstrainDoubleRange.SetValue();
  }
};

class EventOrStringArgument
{
  EventOrString& mUnion;

  EventOrStringArgument(const EventOrStringArgument&) = delete;
  void operator=(const EventOrStringArgument) = delete;
public:
  explicit inline EventOrStringArgument(const EventOrString& aUnion)
    : mUnion(const_cast<EventOrString&>(aUnion))
  {
  }

  inline bool
  TrySetToEvent(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Event>& memberSlot = RawSetAsEvent();
      {
        nsresult rv = UnwrapObject<prototypes::id::Event, mozilla::dom::Event>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyEvent();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

private:
  inline NonNull<mozilla::dom::Event>&
  RawSetAsEvent()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eEvent;
    return mUnion.mValue.mEvent.SetValue();
  }

  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
};

class ExternalOrWindowProxyArgument
{
  ExternalOrWindowProxy& mUnion;
  Maybe<nsRefPtr<nsIDOMWindow>> mWindowProxyHolder;

  ExternalOrWindowProxyArgument(const ExternalOrWindowProxyArgument&) = delete;
  void operator=(const ExternalOrWindowProxyArgument) = delete;
public:
  explicit inline ExternalOrWindowProxyArgument(const ExternalOrWindowProxy& aUnion)
    : mUnion(const_cast<ExternalOrWindowProxy&>(aUnion))
  {
  }

  inline bool
  TrySetToExternal(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::External>& memberSlot = RawSetAsExternal();
      {
        nsresult rv = UnwrapObject<prototypes::id::External, mozilla::dom::External>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyExternal();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToWindowProxy(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      nsIDOMWindow*& memberSlot = RawSetAsWindowProxy();
      mWindowProxyHolder.emplace();
      JS::Rooted<JSObject*> source(cx, &value.toObject());
      if (NS_FAILED(UnwrapArg<nsIDOMWindow>(source, getter_AddRefs(mWindowProxyHolder.ref())))) {
        mWindowProxyHolder.reset();
        mUnion.DestroyWindowProxy();
        tryNext = true;
        return true;
      }
      MOZ_ASSERT(mWindowProxyHolder.ref());
      memberSlot = mWindowProxyHolder.ref();
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::External>&
  RawSetAsExternal()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eExternal;
    return mUnion.mValue.mExternal.SetValue();
  }

  inline nsIDOMWindow*&
  RawSetAsWindowProxy()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eWindowProxy;
    return mUnion.mValue.mWindowProxy.SetValue();
  }
};

class FileOrUSVStringArgument
{
  FileOrUSVString& mUnion;

  FileOrUSVStringArgument(const FileOrUSVStringArgument&) = delete;
  void operator=(const FileOrUSVStringArgument) = delete;
public:
  explicit inline FileOrUSVStringArgument(const FileOrUSVString& aUnion)
    : mUnion(const_cast<FileOrUSVString&>(aUnion))
  {
  }

  inline bool
  TrySetToFile(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::File>& memberSlot = RawSetAsFile();
      {
        nsresult rv = UnwrapObject<prototypes::id::File, mozilla::dom::File>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyFile();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToUSVString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsUSVString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
      NormalizeUSVString(cx, memberSlot);
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsUSVString().Rebind(aData, aLength);
  }

private:
  inline NonNull<mozilla::dom::File>&
  RawSetAsFile()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eFile;
    return mUnion.mValue.mFile.SetValue();
  }

  inline binding_detail::FakeString&
  RawSetAsUSVString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUSVString;
    return mUnion.mValue.mUSVString.SetValue();
  }
};

class HTMLElementOrLongArgument
{
  HTMLElementOrLong& mUnion;

  HTMLElementOrLongArgument(const HTMLElementOrLongArgument&) = delete;
  void operator=(const HTMLElementOrLongArgument) = delete;
public:
  explicit inline HTMLElementOrLongArgument(const HTMLElementOrLong& aUnion)
    : mUnion(const_cast<HTMLElementOrLong&>(aUnion))
  {
  }

  inline bool
  TrySetToHTMLElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsGenericHTMLElement>& memberSlot = RawSetAsHTMLElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLElement, nsGenericHTMLElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      int32_t& memberSlot = RawSetAsLong();
      if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

private:
  inline NonNull<nsGenericHTMLElement>&
  RawSetAsHTMLElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLElement;
    return mUnion.mValue.mHTMLElement.SetValue();
  }

  inline int32_t&
  RawSetAsLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }
};

class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument
{
  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& mUnion;

  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument&) = delete;
  void operator=(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument) = delete;
public:
  explicit inline HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& aUnion)
    : mUnion(const_cast<HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement&>(aUnion))
  {
  }

  inline bool
  TrySetToHTMLImageElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLImageElement>& memberSlot = RawSetAsHTMLImageElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLImageElement, mozilla::dom::HTMLImageElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLImageElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToHTMLCanvasElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLCanvasElement>& memberSlot = RawSetAsHTMLCanvasElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLCanvasElement, mozilla::dom::HTMLCanvasElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLCanvasElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToHTMLVideoElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLVideoElement>& memberSlot = RawSetAsHTMLVideoElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLVideoElement, mozilla::dom::HTMLVideoElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLVideoElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::HTMLImageElement>&
  RawSetAsHTMLImageElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLImageElement;
    return mUnion.mValue.mHTMLImageElement.SetValue();
  }

  inline NonNull<mozilla::dom::HTMLCanvasElement>&
  RawSetAsHTMLCanvasElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLCanvasElement;
    return mUnion.mValue.mHTMLCanvasElement.SetValue();
  }

  inline NonNull<mozilla::dom::HTMLVideoElement>&
  RawSetAsHTMLVideoElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLVideoElement;
    return mUnion.mValue.mHTMLVideoElement.SetValue();
  }
};

class HTMLOptionElementOrHTMLOptGroupElementArgument
{
  HTMLOptionElementOrHTMLOptGroupElement& mUnion;

  HTMLOptionElementOrHTMLOptGroupElementArgument(const HTMLOptionElementOrHTMLOptGroupElementArgument&) = delete;
  void operator=(const HTMLOptionElementOrHTMLOptGroupElementArgument) = delete;
public:
  explicit inline HTMLOptionElementOrHTMLOptGroupElementArgument(const HTMLOptionElementOrHTMLOptGroupElement& aUnion)
    : mUnion(const_cast<HTMLOptionElementOrHTMLOptGroupElement&>(aUnion))
  {
  }

  inline bool
  TrySetToHTMLOptionElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLOptionElement>& memberSlot = RawSetAsHTMLOptionElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLOptionElement, mozilla::dom::HTMLOptionElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLOptionElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToHTMLOptGroupElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::HTMLOptGroupElement>& memberSlot = RawSetAsHTMLOptGroupElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLOptGroupElement, mozilla::dom::HTMLOptGroupElement>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLOptGroupElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::HTMLOptionElement>&
  RawSetAsHTMLOptionElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLOptionElement;
    return mUnion.mValue.mHTMLOptionElement.SetValue();
  }

  inline NonNull<mozilla::dom::HTMLOptGroupElement>&
  RawSetAsHTMLOptGroupElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLOptGroupElement;
    return mUnion.mValue.mHTMLOptGroupElement.SetValue();
  }
};

class HeadersOrByteStringSequenceSequenceOrByteStringMozMapArgument
{
  HeadersOrByteStringSequenceSequenceOrByteStringMozMap& mUnion;

  HeadersOrByteStringSequenceSequenceOrByteStringMozMapArgument(const HeadersOrByteStringSequenceSequenceOrByteStringMozMapArgument&) = delete;
  void operator=(const HeadersOrByteStringSequenceSequenceOrByteStringMozMapArgument) = delete;
public:
  explicit inline HeadersOrByteStringSequenceSequenceOrByteStringMozMapArgument(const HeadersOrByteStringSequenceSequenceOrByteStringMozMap& aUnion)
    : mUnion(const_cast<HeadersOrByteStringSequenceSequenceOrByteStringMozMap&>(aUnion))
  {
  }

  inline bool
  TrySetToHeaders(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Headers>& memberSlot = RawSetAsHeaders();
      {
        nsresult rv = UnwrapObject<prototypes::id::Headers, mozilla::dom::Headers>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHeaders();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToByteStringSequenceSequence(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::AutoSequence<Sequence<nsCString>>& memberSlot = RawSetAsByteStringSequenceSequence();
      JS::ForOfIterator iter(cx);
      if (!iter.init(value, JS::ForOfIterator::AllowNonIterable)) {
        return false;
      }
      if (!iter.valueIsIterable()) {
        mUnion.DestroyByteStringSequenceSequence();
        tryNext = true;
        return true;
      }
      binding_detail::AutoSequence<Sequence<nsCString>> &arr = memberSlot;
      JS::Rooted<JS::Value> temp(cx);
      while (true) {
        bool done;
        if (!iter.next(&temp, &done)) {
          return false;
        }
        if (done) {
          break;
        }
        Sequence<nsCString>* slotPtr = arr.AppendElement(mozilla::fallible);
        if (!slotPtr) {
          JS_ReportOutOfMemory(cx);
          return false;
        }
        Sequence<nsCString>& slot = *slotPtr;
        if (temp.isObject()) {
          JS::ForOfIterator iter1(cx);
          if (!iter1.init(temp, JS::ForOfIterator::AllowNonIterable)) {
            return false;
          }
          if (!iter1.valueIsIterable()) {
            ThrowErrorMessage(cx, MSG_NOT_SEQUENCE, "Element of member of HeadersOrByteStringSequenceSequenceOrByteStringMozMap");
            return false;
          }
          Sequence<nsCString> &arr1 = slot;
          JS::Rooted<JS::Value> temp1(cx);
          while (true) {
            bool done1;
            if (!iter1.next(&temp1, &done1)) {
              return false;
            }
            if (done1) {
              break;
            }
            nsCString* slotPtr1 = arr1.AppendElement(mozilla::fallible);
            if (!slotPtr1) {
              JS_ReportOutOfMemory(cx);
              return false;
            }
            nsCString& slot1 = *slotPtr1;
            if (!ConvertJSValueToByteString(cx, temp1, false, slot1)) {
              return false;
            }
          }
        } else {
          ThrowErrorMessage(cx, MSG_NOT_SEQUENCE, "Element of member of HeadersOrByteStringSequenceSequenceOrByteStringMozMap");
          return false;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToByteStringMozMap(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      MozMap<nsCString>& memberSlot = RawSetAsByteStringMozMap();
      MozMap<nsCString> &mozMap = memberSlot;

      JS::Rooted<JSObject*> mozMapObj(cx, &value.toObject());
      JS::AutoIdArray ids(cx, JS_Enumerate(cx, mozMapObj));
      if (!ids) {
        return false;
      }
      JS::Rooted<JS::Value> propNameValue(cx);
      JS::Rooted<JS::Value> temp(cx);
      JS::Rooted<jsid> curId(cx);
      for (size_t i = 0; i < ids.length(); ++i) {
        // Make sure we get the value before converting the name, since
        // getting the value can trigger GC but our name is a dependent
        // string.
        curId = ids[i];
        binding_detail::FakeString propName;
        bool isSymbol;
        if (!ConvertIdToString(cx, curId, propName, isSymbol) ||
            (!isSymbol && !JS_GetPropertyById(cx, mozMapObj, curId, &temp))) {
          return false;
        }
        if (isSymbol) {
          continue;
        }

        nsCString* slotPtr = mozMap.AddEntry(propName);
        if (!slotPtr) {
          JS_ReportOutOfMemory(cx);
          return false;
        }
        nsCString& slot = *slotPtr;
        if (!ConvertJSValueToByteString(cx, temp, false, slot)) {
          return false;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::Headers>&
  RawSetAsHeaders()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHeaders;
    return mUnion.mValue.mHeaders.SetValue();
  }

  inline binding_detail::AutoSequence<Sequence<nsCString>>&
  RawSetAsByteStringSequenceSequence()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eByteStringSequenceSequence;
    return mUnion.mValue.mByteStringSequenceSequence.SetValue();
  }

  inline MozMap<nsCString>&
  RawSetAsByteStringMozMap()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eByteStringMozMap;
    return mUnion.mValue.mByteStringMozMap.SetValue();
  }
};

class IDBObjectStoreOrIDBIndexArgument
{
  IDBObjectStoreOrIDBIndex& mUnion;

  IDBObjectStoreOrIDBIndexArgument(const IDBObjectStoreOrIDBIndexArgument&) = delete;
  void operator=(const IDBObjectStoreOrIDBIndexArgument) = delete;
public:
  explicit inline IDBObjectStoreOrIDBIndexArgument(const IDBObjectStoreOrIDBIndex& aUnion)
    : mUnion(const_cast<IDBObjectStoreOrIDBIndex&>(aUnion))
  {
  }

  inline bool
  TrySetToIDBObjectStore(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBObjectStore>& memberSlot = RawSetAsIDBObjectStore();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBObjectStore, mozilla::dom::indexedDB::IDBObjectStore>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBObjectStore();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToIDBIndex(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBIndex>& memberSlot = RawSetAsIDBIndex();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBIndex, mozilla::dom::indexedDB::IDBIndex>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBIndex();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  RawSetAsIDBObjectStore()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBObjectStore;
    return mUnion.mValue.mIDBObjectStore.SetValue();
  }

  inline NonNull<mozilla::dom::indexedDB::IDBIndex>&
  RawSetAsIDBIndex()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBIndex;
    return mUnion.mValue.mIDBIndex.SetValue();
  }
};

class IDBObjectStoreOrIDBIndexOrIDBCursorArgument
{
  IDBObjectStoreOrIDBIndexOrIDBCursor& mUnion;

  IDBObjectStoreOrIDBIndexOrIDBCursorArgument(const IDBObjectStoreOrIDBIndexOrIDBCursorArgument&) = delete;
  void operator=(const IDBObjectStoreOrIDBIndexOrIDBCursorArgument) = delete;
public:
  explicit inline IDBObjectStoreOrIDBIndexOrIDBCursorArgument(const IDBObjectStoreOrIDBIndexOrIDBCursor& aUnion)
    : mUnion(const_cast<IDBObjectStoreOrIDBIndexOrIDBCursor&>(aUnion))
  {
  }

  inline bool
  TrySetToIDBObjectStore(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBObjectStore>& memberSlot = RawSetAsIDBObjectStore();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBObjectStore, mozilla::dom::indexedDB::IDBObjectStore>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBObjectStore();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToIDBIndex(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBIndex>& memberSlot = RawSetAsIDBIndex();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBIndex, mozilla::dom::indexedDB::IDBIndex>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBIndex();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToIDBCursor(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::indexedDB::IDBCursor>& memberSlot = RawSetAsIDBCursor();
      {
        nsresult rv = UnwrapObject<prototypes::id::IDBCursor, mozilla::dom::indexedDB::IDBCursor>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyIDBCursor();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::indexedDB::IDBObjectStore>&
  RawSetAsIDBObjectStore()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBObjectStore;
    return mUnion.mValue.mIDBObjectStore.SetValue();
  }

  inline NonNull<mozilla::dom::indexedDB::IDBIndex>&
  RawSetAsIDBIndex()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBIndex;
    return mUnion.mValue.mIDBIndex.SetValue();
  }

  inline NonNull<mozilla::dom::indexedDB::IDBCursor>&
  RawSetAsIDBCursor()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eIDBCursor;
    return mUnion.mValue.mIDBCursor.SetValue();
  }
};

class LongOrAutoKeywordArgument
{
  LongOrAutoKeyword& mUnion;

  LongOrAutoKeywordArgument(const LongOrAutoKeywordArgument&) = delete;
  void operator=(const LongOrAutoKeywordArgument) = delete;
public:
  explicit inline LongOrAutoKeywordArgument(const LongOrAutoKeyword& aUnion)
    : mUnion(const_cast<LongOrAutoKeyword&>(aUnion))
  {
  }

  inline bool
  TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      int32_t& memberSlot = RawSetAsLong();
      if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline bool
  TrySetToAutoKeyword(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      AutoKeyword& memberSlot = RawSetAsAutoKeyword();
      {
        bool ok;
        int index = FindEnumStringIndex<true>(cx, value, AutoKeywordValues::strings, "AutoKeyword", "Member of LongOrAutoKeyword", &ok);
        if (!ok) {
          return false;
        }
        MOZ_ASSERT(index >= 0);
        memberSlot = static_cast<AutoKeyword>(index);
      }
    }
    return true;
  }

private:
  inline int32_t&
  RawSetAsLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  inline AutoKeyword&
  RawSetAsAutoKeyword()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eAutoKeyword;
    return mUnion.mValue.mAutoKeyword.SetValue();
  }
};

class LongOrConstrainLongRangeArgument
{
  LongOrConstrainLongRange& mUnion;

  LongOrConstrainLongRangeArgument(const LongOrConstrainLongRangeArgument&) = delete;
  void operator=(const LongOrConstrainLongRangeArgument) = delete;
public:
  explicit inline LongOrConstrainLongRangeArgument(const LongOrConstrainLongRange& aUnion)
    : mUnion(const_cast<LongOrConstrainLongRange&>(aUnion))
  {
  }

  inline bool
  TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      int32_t& memberSlot = RawSetAsLong();
      if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline bool
  TrySetToConstrainLongRange(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FastConstrainLongRange& memberSlot = RawSetAsConstrainLongRange();
      if (!IsConvertibleToDictionary(cx, value)) {
        mUnion.DestroyConstrainLongRange();
        tryNext = true;
        return true;
      }

      if (!memberSlot.Init(cx, value, "Member of LongOrConstrainLongRange", passedToJSImpl)) {
        return false;
      }
    }
    return true;
  }

private:
  inline int32_t&
  RawSetAsLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  inline binding_detail::FastConstrainLongRange&
  RawSetAsConstrainLongRange()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eConstrainLongRange;
    return mUnion.mValue.mConstrainLongRange.SetValue();
  }
};

class LongOrMozSmsMessageOrMozMmsMessageArgument
{
  LongOrMozSmsMessageOrMozMmsMessage& mUnion;
  Maybe<nsRefPtr<nsIDOMMozSmsMessage>> mMozSmsMessageHolder;
  Maybe<nsRefPtr<nsIDOMMozMmsMessage>> mMozMmsMessageHolder;

  LongOrMozSmsMessageOrMozMmsMessageArgument(const LongOrMozSmsMessageOrMozMmsMessageArgument&) = delete;
  void operator=(const LongOrMozSmsMessageOrMozMmsMessageArgument) = delete;
public:
  explicit inline LongOrMozSmsMessageOrMozMmsMessageArgument(const LongOrMozSmsMessageOrMozMmsMessage& aUnion)
    : mUnion(const_cast<LongOrMozSmsMessageOrMozMmsMessage&>(aUnion))
  {
  }

  inline bool
  TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      int32_t& memberSlot = RawSetAsLong();
      if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline bool
  TrySetToMozSmsMessage(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      nsIDOMMozSmsMessage*& memberSlot = RawSetAsMozSmsMessage();
      mMozSmsMessageHolder.emplace();
      JS::Rooted<JSObject*> source(cx, &value.toObject());
      if (NS_FAILED(UnwrapArg<nsIDOMMozSmsMessage>(source, getter_AddRefs(mMozSmsMessageHolder.ref())))) {
        mMozSmsMessageHolder.reset();
        mUnion.DestroyMozSmsMessage();
        tryNext = true;
        return true;
      }
      MOZ_ASSERT(mMozSmsMessageHolder.ref());
      memberSlot = mMozSmsMessageHolder.ref();
    }
    return true;
  }

  inline bool
  TrySetToMozMmsMessage(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      nsIDOMMozMmsMessage*& memberSlot = RawSetAsMozMmsMessage();
      mMozMmsMessageHolder.emplace();
      JS::Rooted<JSObject*> source(cx, &value.toObject());
      if (NS_FAILED(UnwrapArg<nsIDOMMozMmsMessage>(source, getter_AddRefs(mMozMmsMessageHolder.ref())))) {
        mMozMmsMessageHolder.reset();
        mUnion.DestroyMozMmsMessage();
        tryNext = true;
        return true;
      }
      MOZ_ASSERT(mMozMmsMessageHolder.ref());
      memberSlot = mMozMmsMessageHolder.ref();
    }
    return true;
  }

private:
  inline int32_t&
  RawSetAsLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  inline nsIDOMMozSmsMessage*&
  RawSetAsMozSmsMessage()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMozSmsMessage;
    return mUnion.mValue.mMozSmsMessage.SetValue();
  }

  inline nsIDOMMozMmsMessage*&
  RawSetAsMozMmsMessage()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMozMmsMessage;
    return mUnion.mValue.mMozMmsMessage.SetValue();
  }
};

class MozIccInfoOrMozGsmIccInfoOrMozCdmaIccInfoArgument
{
  MozIccInfoOrMozGsmIccInfoOrMozCdmaIccInfo& mUnion;

  MozIccInfoOrMozGsmIccInfoOrMozCdmaIccInfoArgument(const MozIccInfoOrMozGsmIccInfoOrMozCdmaIccInfoArgument&) = delete;
  void operator=(const MozIccInfoOrMozGsmIccInfoOrMozCdmaIccInfoArgument) = delete;
public:
  explicit inline MozIccInfoOrMozGsmIccInfoOrMozCdmaIccInfoArgument(const MozIccInfoOrMozGsmIccInfoOrMozCdmaIccInfo& aUnion)
    : mUnion(const_cast<MozIccInfoOrMozGsmIccInfoOrMozCdmaIccInfo&>(aUnion))
  {
  }

  inline bool
  TrySetToMozIccInfo(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::IccInfo>& memberSlot = RawSetAsMozIccInfo();
      {
        nsresult rv = UnwrapObject<prototypes::id::MozIccInfo, mozilla::dom::IccInfo>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyMozIccInfo();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToMozGsmIccInfo(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::GsmIccInfo>& memberSlot = RawSetAsMozGsmIccInfo();
      {
        nsresult rv = UnwrapObject<prototypes::id::MozGsmIccInfo, mozilla::dom::GsmIccInfo>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyMozGsmIccInfo();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToMozCdmaIccInfo(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::CdmaIccInfo>& memberSlot = RawSetAsMozCdmaIccInfo();
      {
        nsresult rv = UnwrapObject<prototypes::id::MozCdmaIccInfo, mozilla::dom::CdmaIccInfo>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyMozCdmaIccInfo();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::IccInfo>&
  RawSetAsMozIccInfo()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMozIccInfo;
    return mUnion.mValue.mMozIccInfo.SetValue();
  }

  inline NonNull<mozilla::dom::GsmIccInfo>&
  RawSetAsMozGsmIccInfo()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMozGsmIccInfo;
    return mUnion.mValue.mMozGsmIccInfo.SetValue();
  }

  inline NonNull<mozilla::dom::CdmaIccInfo>&
  RawSetAsMozCdmaIccInfo()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMozCdmaIccInfo;
    return mUnion.mValue.mMozCdmaIccInfo.SetValue();
  }
};

class MozSmsMessageOrMozMmsMessageArgument
{
  MozSmsMessageOrMozMmsMessage& mUnion;
  Maybe<nsRefPtr<nsIDOMMozSmsMessage>> mMozSmsMessageHolder;
  Maybe<nsRefPtr<nsIDOMMozMmsMessage>> mMozMmsMessageHolder;

  MozSmsMessageOrMozMmsMessageArgument(const MozSmsMessageOrMozMmsMessageArgument&) = delete;
  void operator=(const MozSmsMessageOrMozMmsMessageArgument) = delete;
public:
  explicit inline MozSmsMessageOrMozMmsMessageArgument(const MozSmsMessageOrMozMmsMessage& aUnion)
    : mUnion(const_cast<MozSmsMessageOrMozMmsMessage&>(aUnion))
  {
  }

  inline bool
  TrySetToMozSmsMessage(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      nsIDOMMozSmsMessage*& memberSlot = RawSetAsMozSmsMessage();
      mMozSmsMessageHolder.emplace();
      JS::Rooted<JSObject*> source(cx, &value.toObject());
      if (NS_FAILED(UnwrapArg<nsIDOMMozSmsMessage>(source, getter_AddRefs(mMozSmsMessageHolder.ref())))) {
        mMozSmsMessageHolder.reset();
        mUnion.DestroyMozSmsMessage();
        tryNext = true;
        return true;
      }
      MOZ_ASSERT(mMozSmsMessageHolder.ref());
      memberSlot = mMozSmsMessageHolder.ref();
    }
    return true;
  }

  inline bool
  TrySetToMozMmsMessage(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      nsIDOMMozMmsMessage*& memberSlot = RawSetAsMozMmsMessage();
      mMozMmsMessageHolder.emplace();
      JS::Rooted<JSObject*> source(cx, &value.toObject());
      if (NS_FAILED(UnwrapArg<nsIDOMMozMmsMessage>(source, getter_AddRefs(mMozMmsMessageHolder.ref())))) {
        mMozMmsMessageHolder.reset();
        mUnion.DestroyMozMmsMessage();
        tryNext = true;
        return true;
      }
      MOZ_ASSERT(mMozMmsMessageHolder.ref());
      memberSlot = mMozMmsMessageHolder.ref();
    }
    return true;
  }

private:
  inline nsIDOMMozSmsMessage*&
  RawSetAsMozSmsMessage()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMozSmsMessage;
    return mUnion.mValue.mMozSmsMessage.SetValue();
  }

  inline nsIDOMMozMmsMessage*&
  RawSetAsMozMmsMessage()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMozMmsMessage;
    return mUnion.mValue.mMozMmsMessage.SetValue();
  }
};

class NetworkStatsDataOrPowerStatsDataArgument
{
  NetworkStatsDataOrPowerStatsData& mUnion;

  NetworkStatsDataOrPowerStatsDataArgument(const NetworkStatsDataOrPowerStatsDataArgument&) = delete;
  void operator=(const NetworkStatsDataOrPowerStatsDataArgument) = delete;
public:
  explicit inline NetworkStatsDataOrPowerStatsDataArgument(const NetworkStatsDataOrPowerStatsData& aUnion)
    : mUnion(const_cast<NetworkStatsDataOrPowerStatsData&>(aUnion))
  {
  }

  inline bool
  TrySetToNetworkStatsData(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::NetworkStatsData>& memberSlot = RawSetAsNetworkStatsData();
      {
        nsresult rv = UnwrapObject<prototypes::id::NetworkStatsData, mozilla::dom::NetworkStatsData>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyNetworkStatsData();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToPowerStatsData(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::PowerStatsData>& memberSlot = RawSetAsPowerStatsData();
      {
        nsresult rv = UnwrapObject<prototypes::id::PowerStatsData, mozilla::dom::PowerStatsData>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyPowerStatsData();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::NetworkStatsData>&
  RawSetAsNetworkStatsData()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eNetworkStatsData;
    return mUnion.mValue.mNetworkStatsData.SetValue();
  }

  inline NonNull<mozilla::dom::PowerStatsData>&
  RawSetAsPowerStatsData()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.ePowerStatsData;
    return mUnion.mValue.mPowerStatsData.SetValue();
  }
};

class NodeOrHTMLCollectionArgument
{
  NodeOrHTMLCollection& mUnion;

  NodeOrHTMLCollectionArgument(const NodeOrHTMLCollectionArgument&) = delete;
  void operator=(const NodeOrHTMLCollectionArgument) = delete;
public:
  explicit inline NodeOrHTMLCollectionArgument(const NodeOrHTMLCollection& aUnion)
    : mUnion(const_cast<NodeOrHTMLCollection&>(aUnion))
  {
  }

  inline bool
  TrySetToNode(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsINode>& memberSlot = RawSetAsNode();
      {
        nsresult rv = UnwrapObject<prototypes::id::Node, nsINode>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyNode();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToHTMLCollection(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsIHTMLCollection>& memberSlot = RawSetAsHTMLCollection();
      {
        nsresult rv = UnwrapObject<prototypes::id::HTMLCollection, nsIHTMLCollection>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyHTMLCollection();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<nsINode>&
  RawSetAsNode()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eNode;
    return mUnion.mValue.mNode.SetValue();
  }

  inline NonNull<nsIHTMLCollection>&
  RawSetAsHTMLCollection()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eHTMLCollection;
    return mUnion.mValue.mHTMLCollection.SetValue();
  }
};

class ObjectOrStringArgument
{
  ObjectOrString& mUnion;

  ObjectOrStringArgument(const ObjectOrStringArgument&) = delete;
  void operator=(const ObjectOrStringArgument) = delete;
public:
  explicit inline ObjectOrStringArgument(const ObjectOrString& aUnion)
    : mUnion(const_cast<ObjectOrString&>(aUnion))
  {
  }

  inline bool
  SetToObject(JSContext* cx, JSObject* obj, bool passedToJSImpl = false)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mValue.mObject.SetValue(cx, obj);
    mUnion.mType = mUnion.eObject;
    if (passedToJSImpl && !CallerSubsumes(obj)) {
      ThrowErrorMessage(cx, MSG_PERMISSION_DENIED_TO_PASS_ARG, "%s");
      return false;
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

private:
  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
};

class RadioNodeListOrElementArgument
{
  RadioNodeListOrElement& mUnion;

  RadioNodeListOrElementArgument(const RadioNodeListOrElementArgument&) = delete;
  void operator=(const RadioNodeListOrElementArgument) = delete;
public:
  explicit inline RadioNodeListOrElementArgument(const RadioNodeListOrElement& aUnion)
    : mUnion(const_cast<RadioNodeListOrElement&>(aUnion))
  {
  }

  inline bool
  TrySetToRadioNodeList(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::RadioNodeList>& memberSlot = RawSetAsRadioNodeList();
      {
        nsresult rv = UnwrapObject<prototypes::id::RadioNodeList, mozilla::dom::RadioNodeList>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyRadioNodeList();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Element>& memberSlot = RawSetAsElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::Element, mozilla::dom::Element>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::RadioNodeList>&
  RawSetAsRadioNodeList()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eRadioNodeList;
    return mUnion.mValue.mRadioNodeList.SetValue();
  }

  inline NonNull<mozilla::dom::Element>&
  RawSetAsElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eElement;
    return mUnion.mValue.mElement.SetValue();
  }
};

class RequestOrUSVStringArgument
{
  RequestOrUSVString& mUnion;

  RequestOrUSVStringArgument(const RequestOrUSVStringArgument&) = delete;
  void operator=(const RequestOrUSVStringArgument) = delete;
public:
  explicit inline RequestOrUSVStringArgument(const RequestOrUSVString& aUnion)
    : mUnion(const_cast<RequestOrUSVString&>(aUnion))
  {
  }

  inline bool
  TrySetToRequest(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Request>& memberSlot = RawSetAsRequest();
      {
        nsresult rv = UnwrapObject<prototypes::id::Request, mozilla::dom::Request>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyRequest();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToUSVString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsUSVString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
      NormalizeUSVString(cx, memberSlot);
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsUSVString().Rebind(aData, aLength);
  }

private:
  inline NonNull<mozilla::dom::Request>&
  RawSetAsRequest()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eRequest;
    return mUnion.mValue.mRequest.SetValue();
  }

  inline binding_detail::FakeString&
  RawSetAsUSVString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUSVString;
    return mUnion.mValue.mUSVString.SetValue();
  }
};

class ResponseOrPromiseArgument
{
  ResponseOrPromise& mUnion;

  ResponseOrPromiseArgument(const ResponseOrPromiseArgument&) = delete;
  void operator=(const ResponseOrPromiseArgument) = delete;
public:
  explicit inline ResponseOrPromiseArgument(const ResponseOrPromise& aUnion)
    : mUnion(const_cast<ResponseOrPromise&>(aUnion))
  {
  }

  inline bool
  TrySetToResponse(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Response>& memberSlot = RawSetAsResponse();
      {
        nsresult rv = UnwrapObject<prototypes::id::Response, mozilla::dom::Response>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyResponse();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToPromise(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Promise>& memberSlot = RawSetAsPromise();
      {
        nsresult rv = UnwrapObject<prototypes::id::Promise, mozilla::dom::Promise>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyPromise();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::Response>&
  RawSetAsResponse()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eResponse;
    return mUnion.mValue.mResponse.SetValue();
  }

  inline NonNull<mozilla::dom::Promise>&
  RawSetAsPromise()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.ePromise;
    return mUnion.mValue.mPromise.SetValue();
  }
};

class StringOrArrayBufferOrArrayBufferViewArgument
{
  StringOrArrayBufferOrArrayBufferView& mUnion;

  StringOrArrayBufferOrArrayBufferViewArgument(const StringOrArrayBufferOrArrayBufferViewArgument&) = delete;
  void operator=(const StringOrArrayBufferOrArrayBufferViewArgument) = delete;
public:
  explicit inline StringOrArrayBufferOrArrayBufferViewArgument(const StringOrArrayBufferOrArrayBufferView& aUnion)
    : mUnion(const_cast<StringOrArrayBufferOrArrayBufferView&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToArrayBuffer(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBuffer>& memberSlot = RawSetAsArrayBuffer(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBuffer();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

  inline bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBufferView>& memberSlot = RawSetAsArrayBufferView(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBufferView();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline RootedTypedArray<ArrayBuffer>&
  RawSetAsArrayBuffer(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBuffer;
    return mUnion.mValue.mArrayBuffer.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBufferView>&
  RawSetAsArrayBufferView(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBufferView;
    return mUnion.mValue.mArrayBufferView.SetValue(cx);
  }
};

class StringOrBlobOrArrayBufferOrArrayBufferViewArgument
{
  StringOrBlobOrArrayBufferOrArrayBufferView& mUnion;

  StringOrBlobOrArrayBufferOrArrayBufferViewArgument(const StringOrBlobOrArrayBufferOrArrayBufferViewArgument&) = delete;
  void operator=(const StringOrBlobOrArrayBufferOrArrayBufferViewArgument) = delete;
public:
  explicit inline StringOrBlobOrArrayBufferOrArrayBufferViewArgument(const StringOrBlobOrArrayBufferOrArrayBufferView& aUnion)
    : mUnion(const_cast<StringOrBlobOrArrayBufferOrArrayBufferView&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToBlob(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Blob>& memberSlot = RawSetAsBlob();
      {
        nsresult rv = UnwrapObject<prototypes::id::Blob, mozilla::dom::Blob>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyBlob();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToArrayBuffer(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBuffer>& memberSlot = RawSetAsArrayBuffer(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBuffer();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

  inline bool
  TrySetToArrayBufferView(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<ArrayBufferView>& memberSlot = RawSetAsArrayBufferView(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyArrayBufferView();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline NonNull<mozilla::dom::Blob>&
  RawSetAsBlob()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eBlob;
    return mUnion.mValue.mBlob.SetValue();
  }

  inline RootedTypedArray<ArrayBuffer>&
  RawSetAsArrayBuffer(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBuffer;
    return mUnion.mValue.mArrayBuffer.SetValue(cx);
  }

  inline RootedTypedArray<ArrayBufferView>&
  RawSetAsArrayBufferView(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eArrayBufferView;
    return mUnion.mValue.mArrayBufferView.SetValue(cx);
  }
};

class StringOrCanvasGradientOrCanvasPatternArgument
{
  StringOrCanvasGradientOrCanvasPattern& mUnion;

  StringOrCanvasGradientOrCanvasPatternArgument(const StringOrCanvasGradientOrCanvasPatternArgument&) = delete;
  void operator=(const StringOrCanvasGradientOrCanvasPatternArgument) = delete;
public:
  explicit inline StringOrCanvasGradientOrCanvasPatternArgument(const StringOrCanvasGradientOrCanvasPattern& aUnion)
    : mUnion(const_cast<StringOrCanvasGradientOrCanvasPattern&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToCanvasGradient(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::CanvasGradient>& memberSlot = RawSetAsCanvasGradient();
      {
        nsresult rv = UnwrapObject<prototypes::id::CanvasGradient, mozilla::dom::CanvasGradient>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyCanvasGradient();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToCanvasPattern(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::CanvasPattern>& memberSlot = RawSetAsCanvasPattern();
      {
        nsresult rv = UnwrapObject<prototypes::id::CanvasPattern, mozilla::dom::CanvasPattern>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyCanvasPattern();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline NonNull<mozilla::dom::CanvasGradient>&
  RawSetAsCanvasGradient()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eCanvasGradient;
    return mUnion.mValue.mCanvasGradient.SetValue();
  }

  inline NonNull<mozilla::dom::CanvasPattern>&
  RawSetAsCanvasPattern()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eCanvasPattern;
    return mUnion.mValue.mCanvasPattern.SetValue();
  }
};

class StringOrFileOrDirectoryArgument
{
  StringOrFileOrDirectory& mUnion;

  StringOrFileOrDirectoryArgument(const StringOrFileOrDirectoryArgument&) = delete;
  void operator=(const StringOrFileOrDirectoryArgument) = delete;
public:
  explicit inline StringOrFileOrDirectoryArgument(const StringOrFileOrDirectory& aUnion)
    : mUnion(const_cast<StringOrFileOrDirectory&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToFile(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::File>& memberSlot = RawSetAsFile();
      {
        nsresult rv = UnwrapObject<prototypes::id::File, mozilla::dom::File>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyFile();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToDirectory(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Directory>& memberSlot = RawSetAsDirectory();
      {
        nsresult rv = UnwrapObject<prototypes::id::Directory, mozilla::dom::Directory>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyDirectory();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline NonNull<mozilla::dom::File>&
  RawSetAsFile()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eFile;
    return mUnion.mValue.mFile.SetValue();
  }

  inline NonNull<mozilla::dom::Directory>&
  RawSetAsDirectory()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eDirectory;
    return mUnion.mValue.mDirectory.SetValue();
  }
};

class StringOrInstallTriggerDataArgument
{
  StringOrInstallTriggerData& mUnion;

  StringOrInstallTriggerDataArgument(const StringOrInstallTriggerDataArgument&) = delete;
  void operator=(const StringOrInstallTriggerDataArgument) = delete;
public:
  explicit inline StringOrInstallTriggerDataArgument(const StringOrInstallTriggerData& aUnion)
    : mUnion(const_cast<StringOrInstallTriggerData&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToInstallTriggerData(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FastInstallTriggerData& memberSlot = RawSetAsInstallTriggerData();
      if (!IsConvertibleToDictionary(cx, value)) {
        mUnion.DestroyInstallTriggerData();
        tryNext = true;
        return true;
      }

      if (!memberSlot.Init(cx, value, "Member of StringOrInstallTriggerData", passedToJSImpl)) {
        return false;
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline binding_detail::FastInstallTriggerData&
  RawSetAsInstallTriggerData()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eInstallTriggerData;
    return mUnion.mValue.mInstallTriggerData.SetValue();
  }
};

class StringOrStringSequenceArgument
{
  StringOrStringSequence& mUnion;

  StringOrStringSequenceArgument(const StringOrStringSequenceArgument&) = delete;
  void operator=(const StringOrStringSequenceArgument) = delete;
public:
  explicit inline StringOrStringSequenceArgument(const StringOrStringSequence& aUnion)
    : mUnion(const_cast<StringOrStringSequence&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToStringSequence(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::AutoSequence<nsString>& memberSlot = RawSetAsStringSequence();
      JS::ForOfIterator iter(cx);
      if (!iter.init(value, JS::ForOfIterator::AllowNonIterable)) {
        return false;
      }
      if (!iter.valueIsIterable()) {
        mUnion.DestroyStringSequence();
        tryNext = true;
        return true;
      }
      binding_detail::AutoSequence<nsString> &arr = memberSlot;
      JS::Rooted<JS::Value> temp(cx);
      while (true) {
        bool done;
        if (!iter.next(&temp, &done)) {
          return false;
        }
        if (done) {
          break;
        }
        nsString* slotPtr = arr.AppendElement(mozilla::fallible);
        if (!slotPtr) {
          JS_ReportOutOfMemory(cx);
          return false;
        }
        nsString& slot = *slotPtr;
        if (!ConvertJSValueToString(cx, temp, eStringify, eStringify, slot)) {
          return false;
        }
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline binding_detail::AutoSequence<nsString>&
  RawSetAsStringSequence()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eStringSequence;
    return mUnion.mValue.mStringSequence.SetValue();
  }
};

class StringOrStringSequenceOrConstrainDOMStringParametersArgument
{
  StringOrStringSequenceOrConstrainDOMStringParameters& mUnion;

  StringOrStringSequenceOrConstrainDOMStringParametersArgument(const StringOrStringSequenceOrConstrainDOMStringParametersArgument&) = delete;
  void operator=(const StringOrStringSequenceOrConstrainDOMStringParametersArgument) = delete;
public:
  explicit inline StringOrStringSequenceOrConstrainDOMStringParametersArgument(const StringOrStringSequenceOrConstrainDOMStringParameters& aUnion)
    : mUnion(const_cast<StringOrStringSequenceOrConstrainDOMStringParameters&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToStringSequence(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::AutoSequence<nsString>& memberSlot = RawSetAsStringSequence();
      JS::ForOfIterator iter(cx);
      if (!iter.init(value, JS::ForOfIterator::AllowNonIterable)) {
        return false;
      }
      if (!iter.valueIsIterable()) {
        mUnion.DestroyStringSequence();
        tryNext = true;
        return true;
      }
      binding_detail::AutoSequence<nsString> &arr = memberSlot;
      JS::Rooted<JS::Value> temp(cx);
      while (true) {
        bool done;
        if (!iter.next(&temp, &done)) {
          return false;
        }
        if (done) {
          break;
        }
        nsString* slotPtr = arr.AppendElement(mozilla::fallible);
        if (!slotPtr) {
          JS_ReportOutOfMemory(cx);
          return false;
        }
        nsString& slot = *slotPtr;
        if (!ConvertJSValueToString(cx, temp, eStringify, eStringify, slot)) {
          return false;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToConstrainDOMStringParameters(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FastConstrainDOMStringParameters& memberSlot = RawSetAsConstrainDOMStringParameters();
      if (!IsConvertibleToDictionary(cx, value)) {
        mUnion.DestroyConstrainDOMStringParameters();
        tryNext = true;
        return true;
      }

      if (!memberSlot.Init(cx, value, "Member of StringOrStringSequenceOrConstrainDOMStringParameters", passedToJSImpl)) {
        return false;
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline binding_detail::AutoSequence<nsString>&
  RawSetAsStringSequence()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eStringSequence;
    return mUnion.mValue.mStringSequence.SetValue();
  }

  inline binding_detail::FastConstrainDOMStringParameters&
  RawSetAsConstrainDOMStringParameters()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eConstrainDOMStringParameters;
    return mUnion.mValue.mConstrainDOMStringParameters.SetValue();
  }
};

class StringOrUnsignedLongArgument
{
  StringOrUnsignedLong& mUnion;

  StringOrUnsignedLongArgument(const StringOrUnsignedLongArgument&) = delete;
  void operator=(const StringOrUnsignedLongArgument) = delete;
public:
  explicit inline StringOrUnsignedLongArgument(const StringOrUnsignedLong& aUnion)
    : mUnion(const_cast<StringOrUnsignedLong&>(aUnion))
  {
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

  inline bool
  TrySetToUnsignedLong(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      uint32_t& memberSlot = RawSetAsUnsignedLong();
      if (!ValueToPrimitive<uint32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

private:
  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  inline uint32_t&
  RawSetAsUnsignedLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUnsignedLong;
    return mUnion.mValue.mUnsignedLong.SetValue();
  }
};

class TelephonyCallOrTelephonyCallGroupArgument
{
  TelephonyCallOrTelephonyCallGroup& mUnion;

  TelephonyCallOrTelephonyCallGroupArgument(const TelephonyCallOrTelephonyCallGroupArgument&) = delete;
  void operator=(const TelephonyCallOrTelephonyCallGroupArgument) = delete;
public:
  explicit inline TelephonyCallOrTelephonyCallGroupArgument(const TelephonyCallOrTelephonyCallGroup& aUnion)
    : mUnion(const_cast<TelephonyCallOrTelephonyCallGroup&>(aUnion))
  {
  }

  inline bool
  TrySetToTelephonyCall(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::TelephonyCall>& memberSlot = RawSetAsTelephonyCall();
      {
        nsresult rv = UnwrapObject<prototypes::id::TelephonyCall, mozilla::dom::TelephonyCall>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyTelephonyCall();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToTelephonyCallGroup(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::TelephonyCallGroup>& memberSlot = RawSetAsTelephonyCallGroup();
      {
        nsresult rv = UnwrapObject<prototypes::id::TelephonyCallGroup, mozilla::dom::TelephonyCallGroup>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyTelephonyCallGroup();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::TelephonyCall>&
  RawSetAsTelephonyCall()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eTelephonyCall;
    return mUnion.mValue.mTelephonyCall.SetValue();
  }

  inline NonNull<mozilla::dom::TelephonyCallGroup>&
  RawSetAsTelephonyCallGroup()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eTelephonyCallGroup;
    return mUnion.mValue.mTelephonyCallGroup.SetValue();
  }
};

class TextOrElementOrDocumentArgument
{
  TextOrElementOrDocument& mUnion;

  TextOrElementOrDocumentArgument(const TextOrElementOrDocumentArgument&) = delete;
  void operator=(const TextOrElementOrDocumentArgument) = delete;
public:
  explicit inline TextOrElementOrDocumentArgument(const TextOrElementOrDocument& aUnion)
    : mUnion(const_cast<TextOrElementOrDocument&>(aUnion))
  {
  }

  inline bool
  TrySetToText(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Text>& memberSlot = RawSetAsText();
      {
        nsresult rv = UnwrapObject<prototypes::id::Text, mozilla::dom::Text>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyText();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToElement(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::Element>& memberSlot = RawSetAsElement();
      {
        nsresult rv = UnwrapObject<prototypes::id::Element, mozilla::dom::Element>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyElement();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToDocument(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsIDocument>& memberSlot = RawSetAsDocument();
      {
        nsresult rv = UnwrapObject<prototypes::id::Document, nsIDocument>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyDocument();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::Text>&
  RawSetAsText()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eText;
    return mUnion.mValue.mText.SetValue();
  }

  inline NonNull<mozilla::dom::Element>&
  RawSetAsElement()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eElement;
    return mUnion.mValue.mElement.SetValue();
  }

  inline NonNull<nsIDocument>&
  RawSetAsDocument()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eDocument;
    return mUnion.mValue.mDocument.SetValue();
  }
};

class UnsignedLongLongOrStringArgument
{
  UnsignedLongLongOrString& mUnion;

  UnsignedLongLongOrStringArgument(const UnsignedLongLongOrStringArgument&) = delete;
  void operator=(const UnsignedLongLongOrStringArgument) = delete;
public:
  explicit inline UnsignedLongLongOrStringArgument(const UnsignedLongLongOrString& aUnion)
    : mUnion(const_cast<UnsignedLongLongOrString&>(aUnion))
  {
  }

  inline bool
  TrySetToUnsignedLongLong(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      uint64_t& memberSlot = RawSetAsUnsignedLongLong();
      if (!ValueToPrimitive<uint64_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

private:
  inline uint64_t&
  RawSetAsUnsignedLongLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUnsignedLongLong;
    return mUnion.mValue.mUnsignedLongLong.SetValue();
  }

  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
};

class UnsignedLongOrUint32ArrayOrBooleanArgument
{
  UnsignedLongOrUint32ArrayOrBoolean& mUnion;

  UnsignedLongOrUint32ArrayOrBooleanArgument(const UnsignedLongOrUint32ArrayOrBooleanArgument&) = delete;
  void operator=(const UnsignedLongOrUint32ArrayOrBooleanArgument) = delete;
public:
  explicit inline UnsignedLongOrUint32ArrayOrBooleanArgument(const UnsignedLongOrUint32ArrayOrBoolean& aUnion)
    : mUnion(const_cast<UnsignedLongOrUint32ArrayOrBoolean&>(aUnion))
  {
  }

  inline bool
  TrySetToUnsignedLong(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      uint32_t& memberSlot = RawSetAsUnsignedLong();
      if (!ValueToPrimitive<uint32_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline bool
  TrySetToUint32Array(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      RootedTypedArray<Uint32Array>& memberSlot = RawSetAsUint32Array(cx);
      if (!memberSlot.Init(&value.toObject())) {
        mUnion.DestroyUint32Array();
        tryNext = true;
        return true;
      }
    }
    return true;
  }

  inline bool
  TrySetToBoolean(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      bool& memberSlot = RawSetAsBoolean();
      if (!ValueToPrimitive<bool, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

private:
  inline uint32_t&
  RawSetAsUnsignedLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUnsignedLong;
    return mUnion.mValue.mUnsignedLong.SetValue();
  }

  inline RootedTypedArray<Uint32Array>&
  RawSetAsUint32Array(JSContext* cx)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUint32Array;
    return mUnion.mValue.mUint32Array.SetValue(cx);
  }

  inline bool&
  RawSetAsBoolean()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eBoolean;
    return mUnion.mValue.mBoolean.SetValue();
  }
};

class UnsignedShortOrObjectArgument
{
  UnsignedShortOrObject& mUnion;

  UnsignedShortOrObjectArgument(const UnsignedShortOrObjectArgument&) = delete;
  void operator=(const UnsignedShortOrObjectArgument) = delete;
public:
  explicit inline UnsignedShortOrObjectArgument(const UnsignedShortOrObject& aUnion)
    : mUnion(const_cast<UnsignedShortOrObject&>(aUnion))
  {
  }

  inline bool
  TrySetToUnsignedShort(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      uint16_t& memberSlot = RawSetAsUnsignedShort();
      if (!ValueToPrimitive<uint16_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline bool
  SetToObject(JSContext* cx, JSObject* obj, bool passedToJSImpl = false)
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mValue.mObject.SetValue(cx, obj);
    mUnion.mType = mUnion.eObject;
    if (passedToJSImpl && !CallerSubsumes(obj)) {
      ThrowErrorMessage(cx, MSG_PERMISSION_DENIED_TO_PASS_ARG, "%s");
      return false;
    }
    return true;
  }

private:
  inline uint16_t&
  RawSetAsUnsignedShort()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eUnsignedShort;
    return mUnion.mValue.mUnsignedShort.SetValue();
  }
};

class VideoTrackOrAudioTrackOrTextTrackArgument
{
  VideoTrackOrAudioTrackOrTextTrack& mUnion;

  VideoTrackOrAudioTrackOrTextTrackArgument(const VideoTrackOrAudioTrackOrTextTrackArgument&) = delete;
  void operator=(const VideoTrackOrAudioTrackOrTextTrackArgument) = delete;
public:
  explicit inline VideoTrackOrAudioTrackOrTextTrackArgument(const VideoTrackOrAudioTrackOrTextTrack& aUnion)
    : mUnion(const_cast<VideoTrackOrAudioTrackOrTextTrack&>(aUnion))
  {
  }

  inline bool
  TrySetToVideoTrack(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::VideoTrack>& memberSlot = RawSetAsVideoTrack();
      {
        nsresult rv = UnwrapObject<prototypes::id::VideoTrack, mozilla::dom::VideoTrack>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyVideoTrack();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToAudioTrack(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::AudioTrack>& memberSlot = RawSetAsAudioTrack();
      {
        nsresult rv = UnwrapObject<prototypes::id::AudioTrack, mozilla::dom::AudioTrack>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyAudioTrack();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToTextTrack(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::TextTrack>& memberSlot = RawSetAsTextTrack();
      {
        nsresult rv = UnwrapObject<prototypes::id::TextTrack, mozilla::dom::TextTrack>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyTextTrack();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::dom::VideoTrack>&
  RawSetAsVideoTrack()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eVideoTrack;
    return mUnion.mValue.mVideoTrack.SetValue();
  }

  inline NonNull<mozilla::dom::AudioTrack>&
  RawSetAsAudioTrack()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eAudioTrack;
    return mUnion.mValue.mAudioTrack.SetValue();
  }

  inline NonNull<mozilla::dom::TextTrack>&
  RawSetAsTextTrack()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eTextTrack;
    return mUnion.mValue.mTextTrack.SetValue();
  }
};

class WebGLBufferOrLongLongArgument
{
  WebGLBufferOrLongLong& mUnion;

  WebGLBufferOrLongLongArgument(const WebGLBufferOrLongLongArgument&) = delete;
  void operator=(const WebGLBufferOrLongLongArgument) = delete;
public:
  explicit inline WebGLBufferOrLongLongArgument(const WebGLBufferOrLongLong& aUnion)
    : mUnion(const_cast<WebGLBufferOrLongLong&>(aUnion))
  {
  }

  inline bool
  TrySetToWebGLBuffer(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::WebGLBuffer>& memberSlot = RawSetAsWebGLBuffer();
      {
        nsresult rv = UnwrapObject<prototypes::id::WebGLBuffer, mozilla::WebGLBuffer>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyWebGLBuffer();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToLongLong(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      int64_t& memberSlot = RawSetAsLongLong();
      if (!ValueToPrimitive<int64_t, eDefault>(cx, value, &memberSlot)) {
        return false;
      }
    }
    return true;
  }

private:
  inline NonNull<mozilla::WebGLBuffer>&
  RawSetAsWebGLBuffer()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eWebGLBuffer;
    return mUnion.mValue.mWebGLBuffer.SetValue();
  }

  inline int64_t&
  RawSetAsLongLong()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eLongLong;
    return mUnion.mValue.mLongLong.SetValue();
  }
};

class WindowOrMessagePortArgument
{
  WindowOrMessagePort& mUnion;

  WindowOrMessagePortArgument(const WindowOrMessagePortArgument&) = delete;
  void operator=(const WindowOrMessagePortArgument) = delete;
public:
  explicit inline WindowOrMessagePortArgument(const WindowOrMessagePort& aUnion)
    : mUnion(const_cast<WindowOrMessagePort&>(aUnion))
  {
  }

  inline bool
  TrySetToWindow(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<nsGlobalWindow>& memberSlot = RawSetAsWindow();
      {
        nsresult rv = UnwrapObject<prototypes::id::Window, nsGlobalWindow>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyWindow();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToMessagePort(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::MessagePortBase>& memberSlot = RawSetAsMessagePort();
      {
        nsresult rv = UnwrapObject<prototypes::id::MessagePort, mozilla::dom::MessagePortBase>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyMessagePort();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline NonNull<nsGlobalWindow>&
  RawSetAsWindow()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eWindow;
    return mUnion.mValue.mWindow.SetValue();
  }

  inline NonNull<mozilla::dom::MessagePortBase>&
  RawSetAsMessagePort()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMessagePort;
    return mUnion.mValue.mMessagePort.SetValue();
  }
};

class WindowProxyOrMessagePortOrClientArgument
{
  WindowProxyOrMessagePortOrClient& mUnion;
  Maybe<nsRefPtr<nsIDOMWindow>> mWindowProxyHolder;

  WindowProxyOrMessagePortOrClientArgument(const WindowProxyOrMessagePortOrClientArgument&) = delete;
  void operator=(const WindowProxyOrMessagePortOrClientArgument) = delete;
public:
  explicit inline WindowProxyOrMessagePortOrClientArgument(const WindowProxyOrMessagePortOrClient& aUnion)
    : mUnion(const_cast<WindowProxyOrMessagePortOrClient&>(aUnion))
  {
  }

  inline bool
  TrySetToWindowProxy(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      nsIDOMWindow*& memberSlot = RawSetAsWindowProxy();
      mWindowProxyHolder.emplace();
      JS::Rooted<JSObject*> source(cx, &value.toObject());
      if (NS_FAILED(UnwrapArg<nsIDOMWindow>(source, getter_AddRefs(mWindowProxyHolder.ref())))) {
        mWindowProxyHolder.reset();
        mUnion.DestroyWindowProxy();
        tryNext = true;
        return true;
      }
      MOZ_ASSERT(mWindowProxyHolder.ref());
      memberSlot = mWindowProxyHolder.ref();
    }
    return true;
  }

  inline bool
  TrySetToMessagePort(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::MessagePortBase>& memberSlot = RawSetAsMessagePort();
      {
        nsresult rv = UnwrapObject<prototypes::id::MessagePort, mozilla::dom::MessagePortBase>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyMessagePort();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToClient(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::workers::ServiceWorkerClient>& memberSlot = RawSetAsClient();
      {
        nsresult rv = UnwrapObject<prototypes::id::Client, mozilla::dom::workers::ServiceWorkerClient>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroyClient();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

private:
  inline nsIDOMWindow*&
  RawSetAsWindowProxy()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eWindowProxy;
    return mUnion.mValue.mWindowProxy.SetValue();
  }

  inline NonNull<mozilla::dom::MessagePortBase>&
  RawSetAsMessagePort()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eMessagePort;
    return mUnion.mValue.mMessagePort.SetValue();
  }

  inline NonNull<mozilla::dom::workers::ServiceWorkerClient>&
  RawSetAsClient()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eClient;
    return mUnion.mValue.mClient.SetValue();
  }
};

class mozContactOrStringArgument
{
  mozContactOrString& mUnion;

  mozContactOrStringArgument(const mozContactOrStringArgument&) = delete;
  void operator=(const mozContactOrStringArgument) = delete;
public:
  explicit inline mozContactOrStringArgument(const mozContactOrString& aUnion)
    : mUnion(const_cast<mozContactOrString&>(aUnion))
  {
  }

  inline bool
  TrySetTomozContact(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      NonNull<mozilla::dom::mozContact>& memberSlot = RawSetAsmozContact();
      {
        nsresult rv = UnwrapObject<prototypes::id::mozContact, mozilla::dom::mozContact>(&value.toObject(), memberSlot);
        if (NS_FAILED(rv)) {
          mUnion.DestroymozContact();
          tryNext = true;
          return true;
        }
      }
    }
    return true;
  }

  inline bool
  TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, bool& tryNext, bool passedToJSImpl = false)
  {
    tryNext = false;
    { // scope for memberSlot
      binding_detail::FakeString& memberSlot = RawSetAsString();
      if (!ConvertJSValueToString(cx, value, eStringify, eStringify, memberSlot)) {
        return false;
      }
    }
    return true;
  }

  inline void
  SetStringData(const nsDependentString::char_type* aData, nsDependentString::size_type aLength)
  {
    RawSetAsString().Rebind(aData, aLength);
  }

private:
  inline NonNull<mozilla::dom::mozContact>&
  RawSetAsmozContact()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.emozContact;
    return mUnion.mValue.mmozContact.SetValue();
  }

  inline binding_detail::FakeString&
  RawSetAsString()
  {
    MOZ_ASSERT(mUnion.mType == mUnion.eUninitialized);
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
};


} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_UnionConversions_h
