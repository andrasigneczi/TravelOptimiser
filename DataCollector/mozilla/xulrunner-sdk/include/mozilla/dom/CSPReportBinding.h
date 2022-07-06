/* THIS FILE IS AUTOGENERATED FROM CSPReport.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_CSPReportBinding_h
#define mozilla_dom_CSPReportBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Nullable.h"

namespace mozilla {
namespace dom {

struct CSPReportAtoms;
struct CSPReportProperties;
struct CSPReportPropertiesAtoms;
struct NativePropertyHooks;
class ProtoAndIfaceCache;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

struct CSPReportProperties : public DictionaryBase
{
  nsString mBlocked_uri;
  nsString mDocument_uri;
  Optional<int32_t> mLine_number;
  nsString mOriginal_policy;
  nsString mReferrer;
  Optional<nsString> mScript_sample;
  Optional<nsString> mSource_file;
  nsString mViolated_directive;

  CSPReportProperties();

  explicit inline CSPReportProperties(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline CSPReportProperties(const CSPReportProperties& aOther)
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
  operator=(const CSPReportProperties& aOther);

private:
  static bool
  InitIds(JSContext* cx, CSPReportPropertiesAtoms* atomsCache);
};

namespace binding_detail {
struct FastCSPReportProperties : public CSPReportProperties
{
  inline FastCSPReportProperties()
    : CSPReportProperties(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


struct CSPReport : public DictionaryBase
{
  CSPReportProperties mCsp_report;

  CSPReport();

  explicit inline CSPReport(const FastDictionaryInitializer& )
    : mCsp_report(FastDictionaryInitializer())
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline CSPReport(const CSPReport& aOther)
    : mCsp_report(FastDictionaryInitializer())
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
  operator=(const CSPReport& aOther);

private:
  static bool
  InitIds(JSContext* cx, CSPReportAtoms* atomsCache);
};

namespace binding_detail {
struct FastCSPReport : public CSPReport
{
  inline FastCSPReport()
    : CSPReport(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_CSPReportBinding_h