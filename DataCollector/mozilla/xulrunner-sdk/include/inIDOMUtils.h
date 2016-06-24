/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\inIDOMUtils.idl
 */

#ifndef __gen_inIDOMUtils_h__
#define __gen_inIDOMUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsISupportsArray; /* forward declaration */

class nsIDOMCharacterData; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMCSSRule; /* forward declaration */

class nsIDOMCSSStyleRule; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMNodeList; /* forward declaration */

class nsIDOMFontFaceList; /* forward declaration */

class nsIDOMRange; /* forward declaration */

class nsIDOMCSSStyleSheet; /* forward declaration */


/* starting interface:    inIDOMUtils */
#define INIDOMUTILS_IID_STR "60b4cbf7-2a08-4419-8937-6ef495417824"

#define INIDOMUTILS_IID \
  {0x60b4cbf7, 0x2a08, 0x4419, \
    { 0x89, 0x37, 0x6e, 0xf4, 0x95, 0x41, 0x78, 0x24 }}

class NS_NO_VTABLE inIDOMUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INIDOMUTILS_IID)

  /* void getAllStyleSheets (in nsIDOMDocument aDoc, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out nsISupports aSheets); */
  NS_IMETHOD GetAllStyleSheets(nsIDOMDocument *aDoc, uint32_t *aLength, nsISupports * **aSheets) = 0;

  /* nsISupportsArray getCSSStyleRules (in nsIDOMElement aElement, [optional] in DOMString aPseudo); */
  NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval) = 0;

  /* unsigned long getRuleLine (in nsIDOMCSSRule aRule); */
  NS_IMETHOD GetRuleLine(nsIDOMCSSRule *aRule, uint32_t *_retval) = 0;

  /* unsigned long getRuleColumn (in nsIDOMCSSRule aRule); */
  NS_IMETHOD GetRuleColumn(nsIDOMCSSRule *aRule, uint32_t *_retval) = 0;

  /* [implicit_jscontext] jsval getCSSLexer (in DOMString aText); */
  NS_IMETHOD GetCSSLexer(const nsAString & aText, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* unsigned long getSelectorCount (in nsIDOMCSSStyleRule aRule); */
  NS_IMETHOD GetSelectorCount(nsIDOMCSSStyleRule *aRule, uint32_t *_retval) = 0;

  /* AString getSelectorText (in nsIDOMCSSStyleRule aRule, in unsigned long aSelectorIndex); */
  NS_IMETHOD GetSelectorText(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, nsAString & _retval) = 0;

  /* unsigned long long getSpecificity (in nsIDOMCSSStyleRule aRule, in unsigned long aSelectorIndex); */
  NS_IMETHOD GetSpecificity(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, uint64_t *_retval) = 0;

  /* bool selectorMatchesElement (in nsIDOMElement aElement, in nsIDOMCSSStyleRule aRule, in unsigned long aSelectorIndex, [optional] in DOMString aPseudo); */
  NS_IMETHOD SelectorMatchesElement(nsIDOMElement *aElement, nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, const nsAString & aPseudo, bool *_retval) = 0;

  /* bool isInheritedProperty (in AString aPropertyName); */
  NS_IMETHOD IsInheritedProperty(const nsAString & aPropertyName, bool *_retval) = 0;

  enum {
    EXCLUDE_SHORTHANDS = 1U,
    INCLUDE_ALIASES = 2U
  };

  /* void getCSSPropertyNames ([optional] in unsigned long aFlags, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out wstring aProps); */
  NS_IMETHOD GetCSSPropertyNames(uint32_t aFlags, uint32_t *aCount, char16_t * **aProps) = 0;

  /* void getCSSValuesForProperty (in AString aProperty, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out wstring aValues); */
  NS_IMETHOD GetCSSValuesForProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues) = 0;

  /* [implicit_jscontext] jsval colorNameToRGB (in DOMString aColorName); */
  NS_IMETHOD ColorNameToRGB(const nsAString & aColorName, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* AString rgbToColorName (in octet aR, in octet aG, in octet aB); */
  NS_IMETHOD RgbToColorName(uint8_t aR, uint8_t aG, uint8_t aB, nsAString & _retval) = 0;

  /* [implicit_jscontext] jsval colorToRGBA (in DOMString aColorString); */
  NS_IMETHOD ColorToRGBA(const nsAString & aColorString, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* bool isValidCSSColor (in AString aColorString); */
  NS_IMETHOD IsValidCSSColor(const nsAString & aColorString, bool *_retval) = 0;

  /* bool cssPropertyIsValid (in AString aPropertyName, in AString aPropertyValue); */
  NS_IMETHOD CssPropertyIsValid(const nsAString & aPropertyName, const nsAString & aPropertyValue, bool *_retval) = 0;

  /* void getSubpropertiesForCSSProperty (in AString aProperty, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out wstring aValues); */
  NS_IMETHOD GetSubpropertiesForCSSProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues) = 0;

  /* bool cssPropertyIsShorthand (in AString aProperty); */
  NS_IMETHOD CssPropertyIsShorthand(const nsAString & aProperty, bool *_retval) = 0;

  enum {
    TYPE_LENGTH = 0U,
    TYPE_PERCENTAGE = 1U,
    TYPE_COLOR = 2U,
    TYPE_URL = 3U,
    TYPE_ANGLE = 4U,
    TYPE_FREQUENCY = 5U,
    TYPE_TIME = 6U,
    TYPE_GRADIENT = 7U,
    TYPE_TIMING_FUNCTION = 8U,
    TYPE_IMAGE_RECT = 9U,
    TYPE_NUMBER = 10U
  };

  /* bool cssPropertySupportsType (in AString aProperty, in unsigned long type); */
  NS_IMETHOD CssPropertySupportsType(const nsAString & aProperty, uint32_t type, bool *_retval) = 0;

  /* boolean isIgnorableWhitespace (in nsIDOMCharacterData aDataNode); */
  NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval) = 0;

  /* nsIDOMNode getParentForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
  NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval) = 0;

  /* nsIDOMNodeList getChildrenForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
  NS_IMETHOD GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval) = 0;

  /* nsIArray getBindingURLs (in nsIDOMElement aElement); */
  NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval) = 0;

  /* unsigned long long getContentState (in nsIDOMElement aElement); */
  NS_IMETHOD GetContentState(nsIDOMElement *aElement, uint64_t *_retval) = 0;

  /* void setContentState (in nsIDOMElement aElement, in unsigned long long aState); */
  NS_IMETHOD SetContentState(nsIDOMElement *aElement, uint64_t aState) = 0;

  /* nsIDOMFontFaceList getUsedFontFaces (in nsIDOMRange aRange); */
  NS_IMETHOD GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval) = 0;

  /* void addPseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
  NS_IMETHOD AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) = 0;

  /* void removePseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
  NS_IMETHOD RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) = 0;

  /* bool hasPseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
  NS_IMETHOD HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval) = 0;

  /* void clearPseudoClassLocks (in nsIDOMElement aElement); */
  NS_IMETHOD ClearPseudoClassLocks(nsIDOMElement *aElement) = 0;

  /* void parseStyleSheet (in nsIDOMCSSStyleSheet aSheet, in DOMString aInput); */
  NS_IMETHOD ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput) = 0;

  /* void scrollElementIntoView (in nsIDOMElement aElement); */
  NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inIDOMUtils, INIDOMUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INIDOMUTILS \
  NS_IMETHOD GetAllStyleSheets(nsIDOMDocument *aDoc, uint32_t *aLength, nsISupports * **aSheets) override; \
  NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval) override; \
  NS_IMETHOD GetRuleLine(nsIDOMCSSRule *aRule, uint32_t *_retval) override; \
  NS_IMETHOD GetRuleColumn(nsIDOMCSSRule *aRule, uint32_t *_retval) override; \
  NS_IMETHOD GetCSSLexer(const nsAString & aText, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetSelectorCount(nsIDOMCSSStyleRule *aRule, uint32_t *_retval) override; \
  NS_IMETHOD GetSelectorText(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, nsAString & _retval) override; \
  NS_IMETHOD GetSpecificity(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, uint64_t *_retval) override; \
  NS_IMETHOD SelectorMatchesElement(nsIDOMElement *aElement, nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, const nsAString & aPseudo, bool *_retval) override; \
  NS_IMETHOD IsInheritedProperty(const nsAString & aPropertyName, bool *_retval) override; \
  NS_IMETHOD GetCSSPropertyNames(uint32_t aFlags, uint32_t *aCount, char16_t * **aProps) override; \
  NS_IMETHOD GetCSSValuesForProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues) override; \
  NS_IMETHOD ColorNameToRGB(const nsAString & aColorName, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD RgbToColorName(uint8_t aR, uint8_t aG, uint8_t aB, nsAString & _retval) override; \
  NS_IMETHOD ColorToRGBA(const nsAString & aColorString, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD IsValidCSSColor(const nsAString & aColorString, bool *_retval) override; \
  NS_IMETHOD CssPropertyIsValid(const nsAString & aPropertyName, const nsAString & aPropertyValue, bool *_retval) override; \
  NS_IMETHOD GetSubpropertiesForCSSProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues) override; \
  NS_IMETHOD CssPropertyIsShorthand(const nsAString & aProperty, bool *_retval) override; \
  NS_IMETHOD CssPropertySupportsType(const nsAString & aProperty, uint32_t type, bool *_retval) override; \
  NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval) override; \
  NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval) override; \
  NS_IMETHOD GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval) override; \
  NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval) override; \
  NS_IMETHOD GetContentState(nsIDOMElement *aElement, uint64_t *_retval) override; \
  NS_IMETHOD SetContentState(nsIDOMElement *aElement, uint64_t aState) override; \
  NS_IMETHOD GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval) override; \
  NS_IMETHOD AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) override; \
  NS_IMETHOD RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) override; \
  NS_IMETHOD HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval) override; \
  NS_IMETHOD ClearPseudoClassLocks(nsIDOMElement *aElement) override; \
  NS_IMETHOD ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput) override; \
  NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INIDOMUTILS(_to) \
  NS_IMETHOD GetAllStyleSheets(nsIDOMDocument *aDoc, uint32_t *aLength, nsISupports * **aSheets) override { return _to GetAllStyleSheets(aDoc, aLength, aSheets); } \
  NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval) override { return _to GetCSSStyleRules(aElement, aPseudo, _retval); } \
  NS_IMETHOD GetRuleLine(nsIDOMCSSRule *aRule, uint32_t *_retval) override { return _to GetRuleLine(aRule, _retval); } \
  NS_IMETHOD GetRuleColumn(nsIDOMCSSRule *aRule, uint32_t *_retval) override { return _to GetRuleColumn(aRule, _retval); } \
  NS_IMETHOD GetCSSLexer(const nsAString & aText, JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetCSSLexer(aText, cx, _retval); } \
  NS_IMETHOD GetSelectorCount(nsIDOMCSSStyleRule *aRule, uint32_t *_retval) override { return _to GetSelectorCount(aRule, _retval); } \
  NS_IMETHOD GetSelectorText(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, nsAString & _retval) override { return _to GetSelectorText(aRule, aSelectorIndex, _retval); } \
  NS_IMETHOD GetSpecificity(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, uint64_t *_retval) override { return _to GetSpecificity(aRule, aSelectorIndex, _retval); } \
  NS_IMETHOD SelectorMatchesElement(nsIDOMElement *aElement, nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, const nsAString & aPseudo, bool *_retval) override { return _to SelectorMatchesElement(aElement, aRule, aSelectorIndex, aPseudo, _retval); } \
  NS_IMETHOD IsInheritedProperty(const nsAString & aPropertyName, bool *_retval) override { return _to IsInheritedProperty(aPropertyName, _retval); } \
  NS_IMETHOD GetCSSPropertyNames(uint32_t aFlags, uint32_t *aCount, char16_t * **aProps) override { return _to GetCSSPropertyNames(aFlags, aCount, aProps); } \
  NS_IMETHOD GetCSSValuesForProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues) override { return _to GetCSSValuesForProperty(aProperty, aLength, aValues); } \
  NS_IMETHOD ColorNameToRGB(const nsAString & aColorName, JSContext* cx, JS::MutableHandleValue _retval) override { return _to ColorNameToRGB(aColorName, cx, _retval); } \
  NS_IMETHOD RgbToColorName(uint8_t aR, uint8_t aG, uint8_t aB, nsAString & _retval) override { return _to RgbToColorName(aR, aG, aB, _retval); } \
  NS_IMETHOD ColorToRGBA(const nsAString & aColorString, JSContext* cx, JS::MutableHandleValue _retval) override { return _to ColorToRGBA(aColorString, cx, _retval); } \
  NS_IMETHOD IsValidCSSColor(const nsAString & aColorString, bool *_retval) override { return _to IsValidCSSColor(aColorString, _retval); } \
  NS_IMETHOD CssPropertyIsValid(const nsAString & aPropertyName, const nsAString & aPropertyValue, bool *_retval) override { return _to CssPropertyIsValid(aPropertyName, aPropertyValue, _retval); } \
  NS_IMETHOD GetSubpropertiesForCSSProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues) override { return _to GetSubpropertiesForCSSProperty(aProperty, aLength, aValues); } \
  NS_IMETHOD CssPropertyIsShorthand(const nsAString & aProperty, bool *_retval) override { return _to CssPropertyIsShorthand(aProperty, _retval); } \
  NS_IMETHOD CssPropertySupportsType(const nsAString & aProperty, uint32_t type, bool *_retval) override { return _to CssPropertySupportsType(aProperty, type, _retval); } \
  NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval) override { return _to IsIgnorableWhitespace(aDataNode, _retval); } \
  NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval) override { return _to GetParentForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_IMETHOD GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval) override { return _to GetChildrenForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval) override { return _to GetBindingURLs(aElement, _retval); } \
  NS_IMETHOD GetContentState(nsIDOMElement *aElement, uint64_t *_retval) override { return _to GetContentState(aElement, _retval); } \
  NS_IMETHOD SetContentState(nsIDOMElement *aElement, uint64_t aState) override { return _to SetContentState(aElement, aState); } \
  NS_IMETHOD GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval) override { return _to GetUsedFontFaces(aRange, _retval); } \
  NS_IMETHOD AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) override { return _to AddPseudoClassLock(aElement, aPseudoClass); } \
  NS_IMETHOD RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) override { return _to RemovePseudoClassLock(aElement, aPseudoClass); } \
  NS_IMETHOD HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval) override { return _to HasPseudoClassLock(aElement, aPseudoClass, _retval); } \
  NS_IMETHOD ClearPseudoClassLocks(nsIDOMElement *aElement) override { return _to ClearPseudoClassLocks(aElement); } \
  NS_IMETHOD ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput) override { return _to ParseStyleSheet(aSheet, aInput); } \
  NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) override { return _to ScrollElementIntoView(aElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INIDOMUTILS(_to) \
  NS_IMETHOD GetAllStyleSheets(nsIDOMDocument *aDoc, uint32_t *aLength, nsISupports * **aSheets) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllStyleSheets(aDoc, aLength, aSheets); } \
  NS_IMETHOD GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCSSStyleRules(aElement, aPseudo, _retval); } \
  NS_IMETHOD GetRuleLine(nsIDOMCSSRule *aRule, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRuleLine(aRule, _retval); } \
  NS_IMETHOD GetRuleColumn(nsIDOMCSSRule *aRule, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRuleColumn(aRule, _retval); } \
  NS_IMETHOD GetCSSLexer(const nsAString & aText, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCSSLexer(aText, cx, _retval); } \
  NS_IMETHOD GetSelectorCount(nsIDOMCSSStyleRule *aRule, uint32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectorCount(aRule, _retval); } \
  NS_IMETHOD GetSelectorText(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectorText(aRule, aSelectorIndex, _retval); } \
  NS_IMETHOD GetSpecificity(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, uint64_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpecificity(aRule, aSelectorIndex, _retval); } \
  NS_IMETHOD SelectorMatchesElement(nsIDOMElement *aElement, nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, const nsAString & aPseudo, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectorMatchesElement(aElement, aRule, aSelectorIndex, aPseudo, _retval); } \
  NS_IMETHOD IsInheritedProperty(const nsAString & aPropertyName, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsInheritedProperty(aPropertyName, _retval); } \
  NS_IMETHOD GetCSSPropertyNames(uint32_t aFlags, uint32_t *aCount, char16_t * **aProps) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCSSPropertyNames(aFlags, aCount, aProps); } \
  NS_IMETHOD GetCSSValuesForProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCSSValuesForProperty(aProperty, aLength, aValues); } \
  NS_IMETHOD ColorNameToRGB(const nsAString & aColorName, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ColorNameToRGB(aColorName, cx, _retval); } \
  NS_IMETHOD RgbToColorName(uint8_t aR, uint8_t aG, uint8_t aB, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RgbToColorName(aR, aG, aB, _retval); } \
  NS_IMETHOD ColorToRGBA(const nsAString & aColorString, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ColorToRGBA(aColorString, cx, _retval); } \
  NS_IMETHOD IsValidCSSColor(const nsAString & aColorString, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsValidCSSColor(aColorString, _retval); } \
  NS_IMETHOD CssPropertyIsValid(const nsAString & aPropertyName, const nsAString & aPropertyValue, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CssPropertyIsValid(aPropertyName, aPropertyValue, _retval); } \
  NS_IMETHOD GetSubpropertiesForCSSProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubpropertiesForCSSProperty(aProperty, aLength, aValues); } \
  NS_IMETHOD CssPropertyIsShorthand(const nsAString & aProperty, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CssPropertyIsShorthand(aProperty, _retval); } \
  NS_IMETHOD CssPropertySupportsType(const nsAString & aProperty, uint32_t type, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CssPropertySupportsType(aProperty, type, _retval); } \
  NS_IMETHOD IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsIgnorableWhitespace(aDataNode, _retval); } \
  NS_IMETHOD GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_IMETHOD GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildrenForNode(aNode, aShowingAnonymousContent, _retval); } \
  NS_IMETHOD GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBindingURLs(aElement, _retval); } \
  NS_IMETHOD GetContentState(nsIDOMElement *aElement, uint64_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentState(aElement, _retval); } \
  NS_IMETHOD SetContentState(nsIDOMElement *aElement, uint64_t aState) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentState(aElement, aState); } \
  NS_IMETHOD GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsedFontFaces(aRange, _retval); } \
  NS_IMETHOD AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddPseudoClassLock(aElement, aPseudoClass); } \
  NS_IMETHOD RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePseudoClassLock(aElement, aPseudoClass); } \
  NS_IMETHOD HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPseudoClassLock(aElement, aPseudoClass, _retval); } \
  NS_IMETHOD ClearPseudoClassLocks(nsIDOMElement *aElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearPseudoClassLocks(aElement); } \
  NS_IMETHOD ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseStyleSheet(aSheet, aInput); } \
  NS_IMETHOD ScrollElementIntoView(nsIDOMElement *aElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollElementIntoView(aElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inDOMUtils : public inIDOMUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INIDOMUTILS

  inDOMUtils();

private:
  ~inDOMUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(inDOMUtils, inIDOMUtils)

inDOMUtils::inDOMUtils()
{
  /* member initializers and constructor code */
}

inDOMUtils::~inDOMUtils()
{
  /* destructor code */
}

/* void getAllStyleSheets (in nsIDOMDocument aDoc, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out nsISupports aSheets); */
NS_IMETHODIMP inDOMUtils::GetAllStyleSheets(nsIDOMDocument *aDoc, uint32_t *aLength, nsISupports * **aSheets)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupportsArray getCSSStyleRules (in nsIDOMElement aElement, [optional] in DOMString aPseudo); */
NS_IMETHODIMP inDOMUtils::GetCSSStyleRules(nsIDOMElement *aElement, const nsAString & aPseudo, nsISupportsArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getRuleLine (in nsIDOMCSSRule aRule); */
NS_IMETHODIMP inDOMUtils::GetRuleLine(nsIDOMCSSRule *aRule, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getRuleColumn (in nsIDOMCSSRule aRule); */
NS_IMETHODIMP inDOMUtils::GetRuleColumn(nsIDOMCSSRule *aRule, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getCSSLexer (in DOMString aText); */
NS_IMETHODIMP inDOMUtils::GetCSSLexer(const nsAString & aText, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getSelectorCount (in nsIDOMCSSStyleRule aRule); */
NS_IMETHODIMP inDOMUtils::GetSelectorCount(nsIDOMCSSStyleRule *aRule, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getSelectorText (in nsIDOMCSSStyleRule aRule, in unsigned long aSelectorIndex); */
NS_IMETHODIMP inDOMUtils::GetSelectorText(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long long getSpecificity (in nsIDOMCSSStyleRule aRule, in unsigned long aSelectorIndex); */
NS_IMETHODIMP inDOMUtils::GetSpecificity(nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, uint64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool selectorMatchesElement (in nsIDOMElement aElement, in nsIDOMCSSStyleRule aRule, in unsigned long aSelectorIndex, [optional] in DOMString aPseudo); */
NS_IMETHODIMP inDOMUtils::SelectorMatchesElement(nsIDOMElement *aElement, nsIDOMCSSStyleRule *aRule, uint32_t aSelectorIndex, const nsAString & aPseudo, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isInheritedProperty (in AString aPropertyName); */
NS_IMETHODIMP inDOMUtils::IsInheritedProperty(const nsAString & aPropertyName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCSSPropertyNames ([optional] in unsigned long aFlags, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out wstring aProps); */
NS_IMETHODIMP inDOMUtils::GetCSSPropertyNames(uint32_t aFlags, uint32_t *aCount, char16_t * **aProps)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCSSValuesForProperty (in AString aProperty, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out wstring aValues); */
NS_IMETHODIMP inDOMUtils::GetCSSValuesForProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval colorNameToRGB (in DOMString aColorName); */
NS_IMETHODIMP inDOMUtils::ColorNameToRGB(const nsAString & aColorName, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString rgbToColorName (in octet aR, in octet aG, in octet aB); */
NS_IMETHODIMP inDOMUtils::RgbToColorName(uint8_t aR, uint8_t aG, uint8_t aB, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval colorToRGBA (in DOMString aColorString); */
NS_IMETHODIMP inDOMUtils::ColorToRGBA(const nsAString & aColorString, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isValidCSSColor (in AString aColorString); */
NS_IMETHODIMP inDOMUtils::IsValidCSSColor(const nsAString & aColorString, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool cssPropertyIsValid (in AString aPropertyName, in AString aPropertyValue); */
NS_IMETHODIMP inDOMUtils::CssPropertyIsValid(const nsAString & aPropertyName, const nsAString & aPropertyValue, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSubpropertiesForCSSProperty (in AString aProperty, [optional] out unsigned long aLength, [array, size_is (aLength), retval] out wstring aValues); */
NS_IMETHODIMP inDOMUtils::GetSubpropertiesForCSSProperty(const nsAString & aProperty, uint32_t *aLength, char16_t * **aValues)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool cssPropertyIsShorthand (in AString aProperty); */
NS_IMETHODIMP inDOMUtils::CssPropertyIsShorthand(const nsAString & aProperty, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool cssPropertySupportsType (in AString aProperty, in unsigned long type); */
NS_IMETHODIMP inDOMUtils::CssPropertySupportsType(const nsAString & aProperty, uint32_t type, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isIgnorableWhitespace (in nsIDOMCharacterData aDataNode); */
NS_IMETHODIMP inDOMUtils::IsIgnorableWhitespace(nsIDOMCharacterData *aDataNode, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode getParentForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
NS_IMETHODIMP inDOMUtils::GetParentForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList getChildrenForNode (in nsIDOMNode aNode, in boolean aShowingAnonymousContent); */
NS_IMETHODIMP inDOMUtils::GetChildrenForNode(nsIDOMNode *aNode, bool aShowingAnonymousContent, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIArray getBindingURLs (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::GetBindingURLs(nsIDOMElement *aElement, nsIArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long long getContentState (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::GetContentState(nsIDOMElement *aElement, uint64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setContentState (in nsIDOMElement aElement, in unsigned long long aState); */
NS_IMETHODIMP inDOMUtils::SetContentState(nsIDOMElement *aElement, uint64_t aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMFontFaceList getUsedFontFaces (in nsIDOMRange aRange); */
NS_IMETHODIMP inDOMUtils::GetUsedFontFaces(nsIDOMRange *aRange, nsIDOMFontFaceList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addPseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
NS_IMETHODIMP inDOMUtils::AddPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
NS_IMETHODIMP inDOMUtils::RemovePseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool hasPseudoClassLock (in nsIDOMElement aElement, in DOMString aPseudoClass); */
NS_IMETHODIMP inDOMUtils::HasPseudoClassLock(nsIDOMElement *aElement, const nsAString & aPseudoClass, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearPseudoClassLocks (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::ClearPseudoClassLocks(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void parseStyleSheet (in nsIDOMCSSStyleSheet aSheet, in DOMString aInput); */
NS_IMETHODIMP inDOMUtils::ParseStyleSheet(nsIDOMCSSStyleSheet *aSheet, const nsAString & aInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollElementIntoView (in nsIDOMElement aElement); */
NS_IMETHODIMP inDOMUtils::ScrollElementIntoView(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define IN_DOMUTILS_CONTRACTID "@mozilla.org/inspector/dom-utils;1"

#endif /* __gen_inIDOMUtils_h__ */
