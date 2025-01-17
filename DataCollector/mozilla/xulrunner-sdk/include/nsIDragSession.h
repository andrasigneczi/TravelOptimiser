/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDragSession.idl
 */

#ifndef __gen_nsIDragSession_h__
#define __gen_nsIDragSession_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsITransferable_h__
#include "nsITransferable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsSize.h"
class nsIDOMDocument; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMDataTransfer; /* forward declaration */


/* starting interface:    nsIDragSession */
#define NS_IDRAGSESSION_IID_STR "25bce737-73f0-43c7-bc20-c71044a73c5a"

#define NS_IDRAGSESSION_IID \
  {0x25bce737, 0x73f0, 0x43c7, \
    { 0xbc, 0x20, 0xc7, 0x10, 0x44, 0xa7, 0x3c, 0x5a }}

class NS_NO_VTABLE nsIDragSession : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDRAGSESSION_IID)

  /* attribute boolean canDrop; */
  NS_IMETHOD GetCanDrop(bool *aCanDrop) = 0;
  NS_IMETHOD SetCanDrop(bool aCanDrop) = 0;

  /* attribute boolean onlyChromeDrop; */
  NS_IMETHOD GetOnlyChromeDrop(bool *aOnlyChromeDrop) = 0;
  NS_IMETHOD SetOnlyChromeDrop(bool aOnlyChromeDrop) = 0;

  /* attribute unsigned long dragAction; */
  NS_IMETHOD GetDragAction(uint32_t *aDragAction) = 0;
  NS_IMETHOD SetDragAction(uint32_t aDragAction) = 0;

  /* [noscript] attribute nsSize targetSize; */
  NS_IMETHOD GetTargetSize(nsSize *aTargetSize) = 0;
  NS_IMETHOD SetTargetSize(nsSize aTargetSize) = 0;

  /* readonly attribute unsigned long numDropItems; */
  NS_IMETHOD GetNumDropItems(uint32_t *aNumDropItems) = 0;

  /* readonly attribute nsIDOMDocument sourceDocument; */
  NS_IMETHOD GetSourceDocument(nsIDOMDocument * *aSourceDocument) = 0;

  /* readonly attribute nsIDOMNode sourceNode; */
  NS_IMETHOD GetSourceNode(nsIDOMNode * *aSourceNode) = 0;

  /* attribute nsIDOMDataTransfer dataTransfer; */
  NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) = 0;
  NS_IMETHOD SetDataTransfer(nsIDOMDataTransfer *aDataTransfer) = 0;

  /* void getData (in nsITransferable aTransferable, in unsigned long aItemIndex); */
  NS_IMETHOD GetData(nsITransferable *aTransferable, uint32_t aItemIndex) = 0;

  /* boolean isDataFlavorSupported (in string aDataFlavor); */
  NS_IMETHOD IsDataFlavorSupported(const char * aDataFlavor, bool *_retval) = 0;

  /* void userCancelled (); */
  NS_IMETHOD UserCancelled(void) = 0;

  /* void dragEventDispatchedToChildProcess (); */
  NS_IMETHOD DragEventDispatchedToChildProcess(void) = 0;

  /* void updateDragEffect (); */
  NS_IMETHOD UpdateDragEffect(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDragSession, NS_IDRAGSESSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDRAGSESSION \
  NS_IMETHOD GetCanDrop(bool *aCanDrop) override; \
  NS_IMETHOD SetCanDrop(bool aCanDrop) override; \
  NS_IMETHOD GetOnlyChromeDrop(bool *aOnlyChromeDrop) override; \
  NS_IMETHOD SetOnlyChromeDrop(bool aOnlyChromeDrop) override; \
  NS_IMETHOD GetDragAction(uint32_t *aDragAction) override; \
  NS_IMETHOD SetDragAction(uint32_t aDragAction) override; \
  NS_IMETHOD GetTargetSize(nsSize *aTargetSize) override; \
  NS_IMETHOD SetTargetSize(nsSize aTargetSize) override; \
  NS_IMETHOD GetNumDropItems(uint32_t *aNumDropItems) override; \
  NS_IMETHOD GetSourceDocument(nsIDOMDocument * *aSourceDocument) override; \
  NS_IMETHOD GetSourceNode(nsIDOMNode * *aSourceNode) override; \
  NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) override; \
  NS_IMETHOD SetDataTransfer(nsIDOMDataTransfer *aDataTransfer) override; \
  NS_IMETHOD GetData(nsITransferable *aTransferable, uint32_t aItemIndex) override; \
  NS_IMETHOD IsDataFlavorSupported(const char * aDataFlavor, bool *_retval) override; \
  NS_IMETHOD UserCancelled(void) override; \
  NS_IMETHOD DragEventDispatchedToChildProcess(void) override; \
  NS_IMETHOD UpdateDragEffect(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDRAGSESSION(_to) \
  NS_IMETHOD GetCanDrop(bool *aCanDrop) override { return _to GetCanDrop(aCanDrop); } \
  NS_IMETHOD SetCanDrop(bool aCanDrop) override { return _to SetCanDrop(aCanDrop); } \
  NS_IMETHOD GetOnlyChromeDrop(bool *aOnlyChromeDrop) override { return _to GetOnlyChromeDrop(aOnlyChromeDrop); } \
  NS_IMETHOD SetOnlyChromeDrop(bool aOnlyChromeDrop) override { return _to SetOnlyChromeDrop(aOnlyChromeDrop); } \
  NS_IMETHOD GetDragAction(uint32_t *aDragAction) override { return _to GetDragAction(aDragAction); } \
  NS_IMETHOD SetDragAction(uint32_t aDragAction) override { return _to SetDragAction(aDragAction); } \
  NS_IMETHOD GetTargetSize(nsSize *aTargetSize) override { return _to GetTargetSize(aTargetSize); } \
  NS_IMETHOD SetTargetSize(nsSize aTargetSize) override { return _to SetTargetSize(aTargetSize); } \
  NS_IMETHOD GetNumDropItems(uint32_t *aNumDropItems) override { return _to GetNumDropItems(aNumDropItems); } \
  NS_IMETHOD GetSourceDocument(nsIDOMDocument * *aSourceDocument) override { return _to GetSourceDocument(aSourceDocument); } \
  NS_IMETHOD GetSourceNode(nsIDOMNode * *aSourceNode) override { return _to GetSourceNode(aSourceNode); } \
  NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) override { return _to GetDataTransfer(aDataTransfer); } \
  NS_IMETHOD SetDataTransfer(nsIDOMDataTransfer *aDataTransfer) override { return _to SetDataTransfer(aDataTransfer); } \
  NS_IMETHOD GetData(nsITransferable *aTransferable, uint32_t aItemIndex) override { return _to GetData(aTransferable, aItemIndex); } \
  NS_IMETHOD IsDataFlavorSupported(const char * aDataFlavor, bool *_retval) override { return _to IsDataFlavorSupported(aDataFlavor, _retval); } \
  NS_IMETHOD UserCancelled(void) override { return _to UserCancelled(); } \
  NS_IMETHOD DragEventDispatchedToChildProcess(void) override { return _to DragEventDispatchedToChildProcess(); } \
  NS_IMETHOD UpdateDragEffect(void) override { return _to UpdateDragEffect(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDRAGSESSION(_to) \
  NS_IMETHOD GetCanDrop(bool *aCanDrop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanDrop(aCanDrop); } \
  NS_IMETHOD SetCanDrop(bool aCanDrop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCanDrop(aCanDrop); } \
  NS_IMETHOD GetOnlyChromeDrop(bool *aOnlyChromeDrop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnlyChromeDrop(aOnlyChromeDrop); } \
  NS_IMETHOD SetOnlyChromeDrop(bool aOnlyChromeDrop) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnlyChromeDrop(aOnlyChromeDrop); } \
  NS_IMETHOD GetDragAction(uint32_t *aDragAction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDragAction(aDragAction); } \
  NS_IMETHOD SetDragAction(uint32_t aDragAction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDragAction(aDragAction); } \
  NS_IMETHOD GetTargetSize(nsSize *aTargetSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetSize(aTargetSize); } \
  NS_IMETHOD SetTargetSize(nsSize aTargetSize) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTargetSize(aTargetSize); } \
  NS_IMETHOD GetNumDropItems(uint32_t *aNumDropItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumDropItems(aNumDropItems); } \
  NS_IMETHOD GetSourceDocument(nsIDOMDocument * *aSourceDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceDocument(aSourceDocument); } \
  NS_IMETHOD GetSourceNode(nsIDOMNode * *aSourceNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceNode(aSourceNode); } \
  NS_IMETHOD GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataTransfer(aDataTransfer); } \
  NS_IMETHOD SetDataTransfer(nsIDOMDataTransfer *aDataTransfer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDataTransfer(aDataTransfer); } \
  NS_IMETHOD GetData(nsITransferable *aTransferable, uint32_t aItemIndex) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aTransferable, aItemIndex); } \
  NS_IMETHOD IsDataFlavorSupported(const char * aDataFlavor, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDataFlavorSupported(aDataFlavor, _retval); } \
  NS_IMETHOD UserCancelled(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UserCancelled(); } \
  NS_IMETHOD DragEventDispatchedToChildProcess(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DragEventDispatchedToChildProcess(); } \
  NS_IMETHOD UpdateDragEffect(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateDragEffect(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDragSession : public nsIDragSession
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDRAGSESSION

  nsDragSession();

private:
  ~nsDragSession();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDragSession, nsIDragSession)

nsDragSession::nsDragSession()
{
  /* member initializers and constructor code */
}

nsDragSession::~nsDragSession()
{
  /* destructor code */
}

/* attribute boolean canDrop; */
NS_IMETHODIMP nsDragSession::GetCanDrop(bool *aCanDrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDragSession::SetCanDrop(bool aCanDrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean onlyChromeDrop; */
NS_IMETHODIMP nsDragSession::GetOnlyChromeDrop(bool *aOnlyChromeDrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDragSession::SetOnlyChromeDrop(bool aOnlyChromeDrop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long dragAction; */
NS_IMETHODIMP nsDragSession::GetDragAction(uint32_t *aDragAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDragSession::SetDragAction(uint32_t aDragAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsSize targetSize; */
NS_IMETHODIMP nsDragSession::GetTargetSize(nsSize *aTargetSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDragSession::SetTargetSize(nsSize aTargetSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long numDropItems; */
NS_IMETHODIMP nsDragSession::GetNumDropItems(uint32_t *aNumDropItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument sourceDocument; */
NS_IMETHODIMP nsDragSession::GetSourceDocument(nsIDOMDocument * *aSourceDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode sourceNode; */
NS_IMETHODIMP nsDragSession::GetSourceNode(nsIDOMNode * *aSourceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMDataTransfer dataTransfer; */
NS_IMETHODIMP nsDragSession::GetDataTransfer(nsIDOMDataTransfer * *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDragSession::SetDataTransfer(nsIDOMDataTransfer *aDataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getData (in nsITransferable aTransferable, in unsigned long aItemIndex); */
NS_IMETHODIMP nsDragSession::GetData(nsITransferable *aTransferable, uint32_t aItemIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isDataFlavorSupported (in string aDataFlavor); */
NS_IMETHODIMP nsDragSession::IsDataFlavorSupported(const char * aDataFlavor, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void userCancelled (); */
NS_IMETHODIMP nsDragSession::UserCancelled()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dragEventDispatchedToChildProcess (); */
NS_IMETHODIMP nsDragSession::DragEventDispatchedToChildProcess()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateDragEffect (); */
NS_IMETHODIMP nsDragSession::UpdateDragEffect()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif



#endif /* __gen_nsIDragSession_h__ */
