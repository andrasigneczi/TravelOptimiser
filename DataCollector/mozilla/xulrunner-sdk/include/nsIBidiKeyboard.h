/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBidiKeyboard.idl
 */

#ifndef __gen_nsIBidiKeyboard_h__
#define __gen_nsIBidiKeyboard_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBidiKeyboard */
#define NS_IBIDIKEYBOARD_IID_STR "288dae24-76e2-43a3-befe-9d9fabe8014e"

#define NS_IBIDIKEYBOARD_IID \
  {0x288dae24, 0x76e2, 0x43a3, \
    { 0xbe, 0xfe, 0x9d, 0x9f, 0xab, 0xe8, 0x01, 0x4e }}

class NS_NO_VTABLE nsIBidiKeyboard : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBIDIKEYBOARD_IID)

  /* void reset (); */
  NS_IMETHOD Reset(void) = 0;

  /* boolean isLangRTL (); */
  NS_IMETHOD IsLangRTL(bool *_retval) = 0;

  /* readonly attribute boolean haveBidiKeyboards; */
  NS_IMETHOD GetHaveBidiKeyboards(bool *aHaveBidiKeyboards) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBidiKeyboard, NS_IBIDIKEYBOARD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBIDIKEYBOARD \
  NS_IMETHOD Reset(void) override; \
  NS_IMETHOD IsLangRTL(bool *_retval) override; \
  NS_IMETHOD GetHaveBidiKeyboards(bool *aHaveBidiKeyboards) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBIDIKEYBOARD(_to) \
  NS_IMETHOD Reset(void) override { return _to Reset(); } \
  NS_IMETHOD IsLangRTL(bool *_retval) override { return _to IsLangRTL(_retval); } \
  NS_IMETHOD GetHaveBidiKeyboards(bool *aHaveBidiKeyboards) override { return _to GetHaveBidiKeyboards(aHaveBidiKeyboards); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBIDIKEYBOARD(_to) \
  NS_IMETHOD Reset(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Reset(); } \
  NS_IMETHOD IsLangRTL(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLangRTL(_retval); } \
  NS_IMETHOD GetHaveBidiKeyboards(bool *aHaveBidiKeyboards) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHaveBidiKeyboards(aHaveBidiKeyboards); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBidiKeyboard : public nsIBidiKeyboard
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBIDIKEYBOARD

  nsBidiKeyboard();

private:
  ~nsBidiKeyboard();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsBidiKeyboard, nsIBidiKeyboard)

nsBidiKeyboard::nsBidiKeyboard()
{
  /* member initializers and constructor code */
}

nsBidiKeyboard::~nsBidiKeyboard()
{
  /* destructor code */
}

/* void reset (); */
NS_IMETHODIMP nsBidiKeyboard::Reset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLangRTL (); */
NS_IMETHODIMP nsBidiKeyboard::IsLangRTL(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean haveBidiKeyboards; */
NS_IMETHODIMP nsBidiKeyboard::GetHaveBidiKeyboards(bool *aHaveBidiKeyboards)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBidiKeyboard_h__ */
