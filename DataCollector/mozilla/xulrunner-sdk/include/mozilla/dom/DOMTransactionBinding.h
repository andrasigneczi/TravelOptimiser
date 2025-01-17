/* THIS FILE IS AUTOGENERATED FROM DOMTransaction.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_DOMTransactionBinding_h
#define mozilla_dom_DOMTransactionBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/CallbackFunction.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/ToJSValue.h"

namespace mozilla {
namespace dom {

class DOMTransaction;
struct DOMTransactionAtoms;
class DOMTransactionCallback;
struct NativePropertyHooks;
class ProtoAndIfaceCache;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

class DOMTransactionCallback : public CallbackFunction
{
public:
  explicit inline DOMTransactionCallback(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackFunction(aCallback, aIncumbentGlobal)
  {
    MOZ_ASSERT(JS::IsCallable(mCallback));
  }

  explicit inline DOMTransactionCallback(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisVal, ErrorResult& aRv, const char* aExecutionReason = nullptr, ExceptionHandling aExceptionHandling = eReportExceptions, JSCompartment* aCompartment = nullptr)
  {
    if (!aExecutionReason) {
      aExecutionReason = "DOMTransactionCallback";
    }
    CallSetup s(this, aRv, aExecutionReason, aExceptionHandling, aCompartment);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    JS::Rooted<JS::Value> thisValJS(s.GetContext());
    if (!ToJSValue(s.GetContext(), thisVal, &thisValJS)) {
      aRv.Throw(NS_ERROR_FAILURE);
      return;
    }
    return Call(s.GetContext(), thisValJS, aRv);
  }

  inline void
  Call(ErrorResult& aRv, const char* aExecutionReason = nullptr, ExceptionHandling aExceptionHandling = eReportExceptions, JSCompartment* aCompartment = nullptr)
  {
    if (!aExecutionReason) {
      aExecutionReason = "DOMTransactionCallback";
    }
    CallSetup s(this, aRv, aExecutionReason, aExceptionHandling, aCompartment);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::UndefinedHandleValue, aRv);
  }

  inline bool
  operator==(const DOMTransactionCallback& aOther) const
  {
    return CallbackFunction::operator==(aOther);
  }

private:
  void Call(JSContext* cx, JS::Handle<JS::Value> aThisVal, ErrorResult& aRv);
};


class DOMTransaction : public CallbackInterface
{
public:
  explicit inline DOMTransaction(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  inline bool
  operator==(const DOMTransaction& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  void GetLabel(nsString& aRetVal, ErrorResult& aRv, const char* aExecutionReason = nullptr, ExceptionHandling aExceptionHandling = eReportExceptions, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMTransactionCallback> GetExecuteAutomatic(ErrorResult& aRv, const char* aExecutionReason = nullptr, ExceptionHandling aExceptionHandling = eReportExceptions, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMTransactionCallback> GetExecute(ErrorResult& aRv, const char* aExecutionReason = nullptr, ExceptionHandling aExceptionHandling = eReportExceptions, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMTransactionCallback> GetUndo(ErrorResult& aRv, const char* aExecutionReason = nullptr, ExceptionHandling aExceptionHandling = eReportExceptions, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMTransactionCallback> GetRedo(ErrorResult& aRv, const char* aExecutionReason = nullptr, ExceptionHandling aExceptionHandling = eReportExceptions, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, DOMTransactionAtoms* atomsCache);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_DOMTransactionBinding_h
