/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContentSecurityPolicy.idl
 */

#ifndef __gen_nsIContentSecurityPolicy_h__
#define __gen_nsIContentSecurityPolicy_h__


#ifndef __gen_nsISerializable_h__
#include "nsISerializable.h"
#endif

#ifndef __gen_nsIContentPolicy_h__
#include "nsIContentPolicy.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIURI; /* forward declaration */

typedef uint16_t  CSPDirective;


/* starting interface:    nsIContentSecurityPolicy */
#define NS_ICONTENTSECURITYPOLICY_IID_STR "059b94e3-45c2-4794-ac2a-5b66a66b5967"

#define NS_ICONTENTSECURITYPOLICY_IID \
  {0x059b94e3, 0x45c2, 0x4794, \
    { 0xac, 0x2a, 0x5b, 0x66, 0xa6, 0x6b, 0x59, 0x67 }}

class nsIContentSecurityPolicy : public nsISerializable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTSECURITYPOLICY_IID)

  enum {
    NO_DIRECTIVE = 0U,
    DEFAULT_SRC_DIRECTIVE = 1U,
    SCRIPT_SRC_DIRECTIVE = 2U,
    OBJECT_SRC_DIRECTIVE = 3U,
    STYLE_SRC_DIRECTIVE = 4U,
    IMG_SRC_DIRECTIVE = 5U,
    MEDIA_SRC_DIRECTIVE = 6U,
    FRAME_SRC_DIRECTIVE = 7U,
    FONT_SRC_DIRECTIVE = 8U,
    CONNECT_SRC_DIRECTIVE = 9U,
    REPORT_URI_DIRECTIVE = 10U,
    FRAME_ANCESTORS_DIRECTIVE = 11U,
    REFLECTED_XSS_DIRECTIVE = 12U,
    BASE_URI_DIRECTIVE = 13U,
    FORM_ACTION_DIRECTIVE = 14U,
    REFERRER_DIRECTIVE = 15U,
    WEB_MANIFEST_SRC_DIRECTIVE = 16U
  };

  /* AString getPolicy (in unsigned long index); */
  NS_IMETHOD GetPolicy(uint32_t index, nsAString & _retval) = 0;

  /* readonly attribute unsigned long policyCount; */
  NS_IMETHOD GetPolicyCount(uint32_t *aPolicyCount) = 0;

  /* bool getReferrerPolicy (out unsigned long policy); */
  NS_IMETHOD GetReferrerPolicy(uint32_t *policy, bool *_retval) = 0;

  /* void removePolicy (in unsigned long index); */
  NS_IMETHOD RemovePolicy(uint32_t index) = 0;

  /* void appendPolicy (in AString policyString, in boolean reportOnly); */
  NS_IMETHOD AppendPolicy(const nsAString & policyString, bool reportOnly) = 0;

  /* boolean getAllowsInlineScript (out boolean shouldReportViolations); */
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval) = 0;

  /* boolean getAllowsEval (out boolean shouldReportViolations); */
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolations, bool *_retval) = 0;

  /* boolean getAllowsInlineStyle (out boolean shouldReportViolations); */
  NS_IMETHOD GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval) = 0;

  /* boolean getAllowsNonce (in AString aNonce, in unsigned long aContentType, out boolean shouldReportViolation); */
  NS_IMETHOD GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval) = 0;

  /* boolean getAllowsHash (in AString aContent, in unsigned short aContentType, out boolean shouldReportViolation); */
  NS_IMETHOD GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval) = 0;

  /* void logViolationDetails (in unsigned short violationType, in AString sourceFile, in AString scriptSample, in int32_t lineNum, [optional] in AString nonce, [optional] in AString content); */
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content) = 0;

  enum {
    VIOLATION_TYPE_INLINE_SCRIPT = 1U,
    VIOLATION_TYPE_EVAL = 2U,
    VIOLATION_TYPE_INLINE_STYLE = 3U,
    VIOLATION_TYPE_NONCE_SCRIPT = 4U,
    VIOLATION_TYPE_NONCE_STYLE = 5U,
    VIOLATION_TYPE_HASH_SCRIPT = 6U,
    VIOLATION_TYPE_HASH_STYLE = 7U
  };

  /* void setRequestContext (in nsIURI selfURI, in nsIURI referrer, in nsIChannel aChannel); */
  NS_IMETHOD SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIChannel *aChannel) = 0;

  /* boolean permitsAncestry (in nsIDocShell docShell); */
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval) = 0;

  /* boolean permits (in nsIURI aURI, in CSPDirective aDir, in boolean aSpecific); */
  NS_IMETHOD Permits(nsIURI *aURI, CSPDirective aDir, bool aSpecific, bool *_retval) = 0;

  /* short shouldLoad (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra); */
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval) = 0;

 // nsIObserver topic to fire when the policy encounters a violation.
#define CSP_VIOLATION_TOPIC "csp-on-violate-policy"
  /* AString toJSON (); */
  NS_IMETHOD ToJSON(nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentSecurityPolicy, NS_ICONTENTSECURITYPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTSECURITYPOLICY \
  NS_IMETHOD GetPolicy(uint32_t index, nsAString & _retval) override; \
  NS_IMETHOD GetPolicyCount(uint32_t *aPolicyCount) override; \
  NS_IMETHOD GetReferrerPolicy(uint32_t *policy, bool *_retval) override; \
  NS_IMETHOD RemovePolicy(uint32_t index) override; \
  NS_IMETHOD AppendPolicy(const nsAString & policyString, bool reportOnly) override; \
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval) override; \
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolations, bool *_retval) override; \
  NS_IMETHOD GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval) override; \
  NS_IMETHOD GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval) override; \
  NS_IMETHOD GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval) override; \
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content) override; \
  NS_IMETHOD SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIChannel *aChannel) override; \
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval) override; \
  NS_IMETHOD Permits(nsIURI *aURI, CSPDirective aDir, bool aSpecific, bool *_retval) override; \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval) override; \
  NS_IMETHOD ToJSON(nsAString & _retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTSECURITYPOLICY(_to) \
  NS_IMETHOD GetPolicy(uint32_t index, nsAString & _retval) override { return _to GetPolicy(index, _retval); } \
  NS_IMETHOD GetPolicyCount(uint32_t *aPolicyCount) override { return _to GetPolicyCount(aPolicyCount); } \
  NS_IMETHOD GetReferrerPolicy(uint32_t *policy, bool *_retval) override { return _to GetReferrerPolicy(policy, _retval); } \
  NS_IMETHOD RemovePolicy(uint32_t index) override { return _to RemovePolicy(index); } \
  NS_IMETHOD AppendPolicy(const nsAString & policyString, bool reportOnly) override { return _to AppendPolicy(policyString, reportOnly); } \
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval) override { return _to GetAllowsInlineScript(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolations, bool *_retval) override { return _to GetAllowsEval(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval) override { return _to GetAllowsInlineStyle(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval) override { return _to GetAllowsNonce(aNonce, aContentType, shouldReportViolation, _retval); } \
  NS_IMETHOD GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval) override { return _to GetAllowsHash(aContent, aContentType, shouldReportViolation, _retval); } \
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content) override { return _to LogViolationDetails(violationType, sourceFile, scriptSample, lineNum, nonce, content); } \
  NS_IMETHOD SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIChannel *aChannel) override { return _to SetRequestContext(selfURI, referrer, aChannel); } \
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval) override { return _to PermitsAncestry(docShell, _retval); } \
  NS_IMETHOD Permits(nsIURI *aURI, CSPDirective aDir, bool aSpecific, bool *_retval) override { return _to Permits(aURI, aDir, aSpecific, _retval); } \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval) override { return _to ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, _retval); } \
  NS_IMETHOD ToJSON(nsAString & _retval) override { return _to ToJSON(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTSECURITYPOLICY(_to) \
  NS_IMETHOD GetPolicy(uint32_t index, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPolicy(index, _retval); } \
  NS_IMETHOD GetPolicyCount(uint32_t *aPolicyCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPolicyCount(aPolicyCount); } \
  NS_IMETHOD GetReferrerPolicy(uint32_t *policy, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrerPolicy(policy, _retval); } \
  NS_IMETHOD RemovePolicy(uint32_t index) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePolicy(index); } \
  NS_IMETHOD AppendPolicy(const nsAString & policyString, bool reportOnly) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendPolicy(policyString, reportOnly); } \
  NS_IMETHOD GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsInlineScript(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsEval(bool *shouldReportViolations, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsEval(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsInlineStyle(shouldReportViolations, _retval); } \
  NS_IMETHOD GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsNonce(aNonce, aContentType, shouldReportViolation, _retval); } \
  NS_IMETHOD GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsHash(aContent, aContentType, shouldReportViolation, _retval); } \
  NS_IMETHOD LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LogViolationDetails(violationType, sourceFile, scriptSample, lineNum, nonce, content); } \
  NS_IMETHOD SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIChannel *aChannel) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRequestContext(selfURI, referrer, aChannel); } \
  NS_IMETHOD PermitsAncestry(nsIDocShell *docShell, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PermitsAncestry(docShell, _retval); } \
  NS_IMETHOD Permits(nsIURI *aURI, CSPDirective aDir, bool aSpecific, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Permits(aURI, aDir, aSpecific, _retval); } \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, _retval); } \
  NS_IMETHOD ToJSON(nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ToJSON(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentSecurityPolicy : public nsIContentSecurityPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTSECURITYPOLICY

  nsContentSecurityPolicy();

private:
  ~nsContentSecurityPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContentSecurityPolicy, nsIContentSecurityPolicy)

nsContentSecurityPolicy::nsContentSecurityPolicy()
{
  /* member initializers and constructor code */
}

nsContentSecurityPolicy::~nsContentSecurityPolicy()
{
  /* destructor code */
}

/* AString getPolicy (in unsigned long index); */
NS_IMETHODIMP nsContentSecurityPolicy::GetPolicy(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long policyCount; */
NS_IMETHODIMP nsContentSecurityPolicy::GetPolicyCount(uint32_t *aPolicyCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool getReferrerPolicy (out unsigned long policy); */
NS_IMETHODIMP nsContentSecurityPolicy::GetReferrerPolicy(uint32_t *policy, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePolicy (in unsigned long index); */
NS_IMETHODIMP nsContentSecurityPolicy::RemovePolicy(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendPolicy (in AString policyString, in boolean reportOnly); */
NS_IMETHODIMP nsContentSecurityPolicy::AppendPolicy(const nsAString & policyString, bool reportOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsInlineScript (out boolean shouldReportViolations); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsInlineScript(bool *shouldReportViolations, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsEval (out boolean shouldReportViolations); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsEval(bool *shouldReportViolations, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsInlineStyle (out boolean shouldReportViolations); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsInlineStyle(bool *shouldReportViolations, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsNonce (in AString aNonce, in unsigned long aContentType, out boolean shouldReportViolation); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsNonce(const nsAString & aNonce, uint32_t aContentType, bool *shouldReportViolation, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAllowsHash (in AString aContent, in unsigned short aContentType, out boolean shouldReportViolation); */
NS_IMETHODIMP nsContentSecurityPolicy::GetAllowsHash(const nsAString & aContent, uint16_t aContentType, bool *shouldReportViolation, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void logViolationDetails (in unsigned short violationType, in AString sourceFile, in AString scriptSample, in int32_t lineNum, [optional] in AString nonce, [optional] in AString content); */
NS_IMETHODIMP nsContentSecurityPolicy::LogViolationDetails(uint16_t violationType, const nsAString & sourceFile, const nsAString & scriptSample, int32_t lineNum, const nsAString & nonce, const nsAString & content)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRequestContext (in nsIURI selfURI, in nsIURI referrer, in nsIChannel aChannel); */
NS_IMETHODIMP nsContentSecurityPolicy::SetRequestContext(nsIURI *selfURI, nsIURI *referrer, nsIChannel *aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean permitsAncestry (in nsIDocShell docShell); */
NS_IMETHODIMP nsContentSecurityPolicy::PermitsAncestry(nsIDocShell *docShell, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean permits (in nsIURI aURI, in CSPDirective aDir, in boolean aSpecific); */
NS_IMETHODIMP nsContentSecurityPolicy::Permits(nsIURI *aURI, CSPDirective aDir, bool aSpecific, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short shouldLoad (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra); */
NS_IMETHODIMP nsContentSecurityPolicy::ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString toJSON (); */
NS_IMETHODIMP nsContentSecurityPolicy::ToJSON(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentSecurityPolicy_h__ */
