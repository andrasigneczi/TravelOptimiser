#ifndef mozilla_dom_ResolveSystemBinding_h
#define mozilla_dom_ResolveSystemBinding_h


namespace mozilla {
namespace dom {
bool
ResolveSystemBinding(JSContext* aCx, JS::Handle<JSObject*> aObj, JS::Handle<jsid> aId, bool* aResolvedp);

} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_ResolveSystemBinding_h
