/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\inIDeepTreeWalker.idl
 */

#ifndef __gen_inIDeepTreeWalker_h__
#define __gen_inIDeepTreeWalker_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class nsIDOMNodeFilter; /* forward declaration */


/* starting interface:    inIDeepTreeWalker */
#define INIDEEPTREEWALKER_IID_STR "6657e8eb-b646-48e7-993e-cfa6e96415b4"

#define INIDEEPTREEWALKER_IID \
  {0x6657e8eb, 0xb646, 0x48e7, \
    { 0x99, 0x3e, 0xcf, 0xa6, 0xe9, 0x64, 0x15, 0xb4 }}

class NS_NO_VTABLE inIDeepTreeWalker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(INIDEEPTREEWALKER_IID)

  /* attribute boolean showAnonymousContent; */
  NS_IMETHOD GetShowAnonymousContent(bool *aShowAnonymousContent) = 0;
  NS_IMETHOD SetShowAnonymousContent(bool aShowAnonymousContent) = 0;

  /* attribute boolean showSubDocuments; */
  NS_IMETHOD GetShowSubDocuments(bool *aShowSubDocuments) = 0;
  NS_IMETHOD SetShowSubDocuments(bool aShowSubDocuments) = 0;

  /* attribute boolean showDocumentsAsNodes; */
  NS_IMETHOD GetShowDocumentsAsNodes(bool *aShowDocumentsAsNodes) = 0;
  NS_IMETHOD SetShowDocumentsAsNodes(bool aShowDocumentsAsNodes) = 0;

  /* void init (in nsIDOMNode aRoot, in unsigned long aWhatToShow); */
  NS_IMETHOD Init(nsIDOMNode *aRoot, uint32_t aWhatToShow) = 0;

  /* readonly attribute nsIDOMNode root; */
  NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) = 0;

  /* readonly attribute unsigned long whatToShow; */
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) = 0;

  /* readonly attribute nsIDOMNodeFilter filter; */
  NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) = 0;

  /* attribute nsIDOMNode currentNode; */
  NS_IMETHOD GetCurrentNode(nsIDOMNode * *aCurrentNode) = 0;
  NS_IMETHOD SetCurrentNode(nsIDOMNode *aCurrentNode) = 0;

  /* nsIDOMNode parentNode (); */
  NS_IMETHOD ParentNode(nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode firstChild (); */
  NS_IMETHOD FirstChild(nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode lastChild (); */
  NS_IMETHOD LastChild(nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode previousSibling (); */
  NS_IMETHOD PreviousSibling(nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode nextSibling (); */
  NS_IMETHOD NextSibling(nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode previousNode (); */
  NS_IMETHOD PreviousNode(nsIDOMNode * *_retval) = 0;

  /* nsIDOMNode nextNode (); */
  NS_IMETHOD NextNode(nsIDOMNode * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(inIDeepTreeWalker, INIDEEPTREEWALKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_INIDEEPTREEWALKER \
  NS_IMETHOD GetShowAnonymousContent(bool *aShowAnonymousContent) override; \
  NS_IMETHOD SetShowAnonymousContent(bool aShowAnonymousContent) override; \
  NS_IMETHOD GetShowSubDocuments(bool *aShowSubDocuments) override; \
  NS_IMETHOD SetShowSubDocuments(bool aShowSubDocuments) override; \
  NS_IMETHOD GetShowDocumentsAsNodes(bool *aShowDocumentsAsNodes) override; \
  NS_IMETHOD SetShowDocumentsAsNodes(bool aShowDocumentsAsNodes) override; \
  NS_IMETHOD Init(nsIDOMNode *aRoot, uint32_t aWhatToShow) override; \
  NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) override; \
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) override; \
  NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) override; \
  NS_IMETHOD GetCurrentNode(nsIDOMNode * *aCurrentNode) override; \
  NS_IMETHOD SetCurrentNode(nsIDOMNode *aCurrentNode) override; \
  NS_IMETHOD ParentNode(nsIDOMNode * *_retval) override; \
  NS_IMETHOD FirstChild(nsIDOMNode * *_retval) override; \
  NS_IMETHOD LastChild(nsIDOMNode * *_retval) override; \
  NS_IMETHOD PreviousSibling(nsIDOMNode * *_retval) override; \
  NS_IMETHOD NextSibling(nsIDOMNode * *_retval) override; \
  NS_IMETHOD PreviousNode(nsIDOMNode * *_retval) override; \
  NS_IMETHOD NextNode(nsIDOMNode * *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_INIDEEPTREEWALKER(_to) \
  NS_IMETHOD GetShowAnonymousContent(bool *aShowAnonymousContent) override { return _to GetShowAnonymousContent(aShowAnonymousContent); } \
  NS_IMETHOD SetShowAnonymousContent(bool aShowAnonymousContent) override { return _to SetShowAnonymousContent(aShowAnonymousContent); } \
  NS_IMETHOD GetShowSubDocuments(bool *aShowSubDocuments) override { return _to GetShowSubDocuments(aShowSubDocuments); } \
  NS_IMETHOD SetShowSubDocuments(bool aShowSubDocuments) override { return _to SetShowSubDocuments(aShowSubDocuments); } \
  NS_IMETHOD GetShowDocumentsAsNodes(bool *aShowDocumentsAsNodes) override { return _to GetShowDocumentsAsNodes(aShowDocumentsAsNodes); } \
  NS_IMETHOD SetShowDocumentsAsNodes(bool aShowDocumentsAsNodes) override { return _to SetShowDocumentsAsNodes(aShowDocumentsAsNodes); } \
  NS_IMETHOD Init(nsIDOMNode *aRoot, uint32_t aWhatToShow) override { return _to Init(aRoot, aWhatToShow); } \
  NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) override { return _to GetRoot(aRoot); } \
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) override { return _to GetWhatToShow(aWhatToShow); } \
  NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) override { return _to GetFilter(aFilter); } \
  NS_IMETHOD GetCurrentNode(nsIDOMNode * *aCurrentNode) override { return _to GetCurrentNode(aCurrentNode); } \
  NS_IMETHOD SetCurrentNode(nsIDOMNode *aCurrentNode) override { return _to SetCurrentNode(aCurrentNode); } \
  NS_IMETHOD ParentNode(nsIDOMNode * *_retval) override { return _to ParentNode(_retval); } \
  NS_IMETHOD FirstChild(nsIDOMNode * *_retval) override { return _to FirstChild(_retval); } \
  NS_IMETHOD LastChild(nsIDOMNode * *_retval) override { return _to LastChild(_retval); } \
  NS_IMETHOD PreviousSibling(nsIDOMNode * *_retval) override { return _to PreviousSibling(_retval); } \
  NS_IMETHOD NextSibling(nsIDOMNode * *_retval) override { return _to NextSibling(_retval); } \
  NS_IMETHOD PreviousNode(nsIDOMNode * *_retval) override { return _to PreviousNode(_retval); } \
  NS_IMETHOD NextNode(nsIDOMNode * *_retval) override { return _to NextNode(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_INIDEEPTREEWALKER(_to) \
  NS_IMETHOD GetShowAnonymousContent(bool *aShowAnonymousContent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowAnonymousContent(aShowAnonymousContent); } \
  NS_IMETHOD SetShowAnonymousContent(bool aShowAnonymousContent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowAnonymousContent(aShowAnonymousContent); } \
  NS_IMETHOD GetShowSubDocuments(bool *aShowSubDocuments) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowSubDocuments(aShowSubDocuments); } \
  NS_IMETHOD SetShowSubDocuments(bool aShowSubDocuments) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowSubDocuments(aShowSubDocuments); } \
  NS_IMETHOD GetShowDocumentsAsNodes(bool *aShowDocumentsAsNodes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetShowDocumentsAsNodes(aShowDocumentsAsNodes); } \
  NS_IMETHOD SetShowDocumentsAsNodes(bool aShowDocumentsAsNodes) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShowDocumentsAsNodes(aShowDocumentsAsNodes); } \
  NS_IMETHOD Init(nsIDOMNode *aRoot, uint32_t aWhatToShow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aRoot, aWhatToShow); } \
  NS_IMETHOD GetRoot(nsIDOMNode * *aRoot) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_IMETHOD GetWhatToShow(uint32_t *aWhatToShow) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhatToShow(aWhatToShow); } \
  NS_IMETHOD GetFilter(nsIDOMNodeFilter * *aFilter) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilter(aFilter); } \
  NS_IMETHOD GetCurrentNode(nsIDOMNode * *aCurrentNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentNode(aCurrentNode); } \
  NS_IMETHOD SetCurrentNode(nsIDOMNode *aCurrentNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentNode(aCurrentNode); } \
  NS_IMETHOD ParentNode(nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ParentNode(_retval); } \
  NS_IMETHOD FirstChild(nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FirstChild(_retval); } \
  NS_IMETHOD LastChild(nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->LastChild(_retval); } \
  NS_IMETHOD PreviousSibling(nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PreviousSibling(_retval); } \
  NS_IMETHOD NextSibling(nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NextSibling(_retval); } \
  NS_IMETHOD PreviousNode(nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PreviousNode(_retval); } \
  NS_IMETHOD NextNode(nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NextNode(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class inDeepTreeWalker : public inIDeepTreeWalker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_INIDEEPTREEWALKER

  inDeepTreeWalker();

private:
  ~inDeepTreeWalker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(inDeepTreeWalker, inIDeepTreeWalker)

inDeepTreeWalker::inDeepTreeWalker()
{
  /* member initializers and constructor code */
}

inDeepTreeWalker::~inDeepTreeWalker()
{
  /* destructor code */
}

/* attribute boolean showAnonymousContent; */
NS_IMETHODIMP inDeepTreeWalker::GetShowAnonymousContent(bool *aShowAnonymousContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDeepTreeWalker::SetShowAnonymousContent(bool aShowAnonymousContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showSubDocuments; */
NS_IMETHODIMP inDeepTreeWalker::GetShowSubDocuments(bool *aShowSubDocuments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDeepTreeWalker::SetShowSubDocuments(bool aShowSubDocuments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean showDocumentsAsNodes; */
NS_IMETHODIMP inDeepTreeWalker::GetShowDocumentsAsNodes(bool *aShowDocumentsAsNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDeepTreeWalker::SetShowDocumentsAsNodes(bool aShowDocumentsAsNodes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in nsIDOMNode aRoot, in unsigned long aWhatToShow); */
NS_IMETHODIMP inDeepTreeWalker::Init(nsIDOMNode *aRoot, uint32_t aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode root; */
NS_IMETHODIMP inDeepTreeWalker::GetRoot(nsIDOMNode * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long whatToShow; */
NS_IMETHODIMP inDeepTreeWalker::GetWhatToShow(uint32_t *aWhatToShow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNodeFilter filter; */
NS_IMETHODIMP inDeepTreeWalker::GetFilter(nsIDOMNodeFilter * *aFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMNode currentNode; */
NS_IMETHODIMP inDeepTreeWalker::GetCurrentNode(nsIDOMNode * *aCurrentNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP inDeepTreeWalker::SetCurrentNode(nsIDOMNode *aCurrentNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode parentNode (); */
NS_IMETHODIMP inDeepTreeWalker::ParentNode(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode firstChild (); */
NS_IMETHODIMP inDeepTreeWalker::FirstChild(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode lastChild (); */
NS_IMETHODIMP inDeepTreeWalker::LastChild(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode previousSibling (); */
NS_IMETHODIMP inDeepTreeWalker::PreviousSibling(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode nextSibling (); */
NS_IMETHODIMP inDeepTreeWalker::NextSibling(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode previousNode (); */
NS_IMETHODIMP inDeepTreeWalker::PreviousNode(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode nextNode (); */
NS_IMETHODIMP inDeepTreeWalker::NextNode(nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_inIDeepTreeWalker_h__ */
