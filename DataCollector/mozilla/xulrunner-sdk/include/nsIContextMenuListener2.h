/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContextMenuListener2.idl
 */

#ifndef __gen_nsIContextMenuListener2_h__
#define __gen_nsIContextMenuListener2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEvent; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class imgIContainer; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIContextMenuInfo; /* forward declaration */


/* starting interface:    nsIContextMenuListener2 */
#define NS_ICONTEXTMENULISTENER2_IID_STR "7fb719b3-d804-4964-9596-77cf924ee314"

#define NS_ICONTEXTMENULISTENER2_IID \
  {0x7fb719b3, 0xd804, 0x4964, \
    { 0x95, 0x96, 0x77, 0xcf, 0x92, 0x4e, 0xe3, 0x14 }}

class NS_NO_VTABLE nsIContextMenuListener2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTEXTMENULISTENER2_IID)

  enum {
    CONTEXT_NONE = 0U,
    CONTEXT_LINK = 1U,
    CONTEXT_IMAGE = 2U,
    CONTEXT_DOCUMENT = 4U,
    CONTEXT_TEXT = 8U,
    CONTEXT_INPUT = 16U,
    CONTEXT_BACKGROUND_IMAGE = 32U
  };

  /* void onShowContextMenu (in unsigned long aContextFlags, in nsIContextMenuInfo aUtils); */
  NS_IMETHOD OnShowContextMenu(uint32_t aContextFlags, nsIContextMenuInfo *aUtils) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContextMenuListener2, NS_ICONTEXTMENULISTENER2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTEXTMENULISTENER2 \
  NS_IMETHOD OnShowContextMenu(uint32_t aContextFlags, nsIContextMenuInfo *aUtils) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTEXTMENULISTENER2(_to) \
  NS_IMETHOD OnShowContextMenu(uint32_t aContextFlags, nsIContextMenuInfo *aUtils) override { return _to OnShowContextMenu(aContextFlags, aUtils); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTEXTMENULISTENER2(_to) \
  NS_IMETHOD OnShowContextMenu(uint32_t aContextFlags, nsIContextMenuInfo *aUtils) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OnShowContextMenu(aContextFlags, aUtils); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContextMenuListener2 : public nsIContextMenuListener2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTEXTMENULISTENER2

  nsContextMenuListener2();

private:
  ~nsContextMenuListener2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContextMenuListener2, nsIContextMenuListener2)

nsContextMenuListener2::nsContextMenuListener2()
{
  /* member initializers and constructor code */
}

nsContextMenuListener2::~nsContextMenuListener2()
{
  /* destructor code */
}

/* void onShowContextMenu (in unsigned long aContextFlags, in nsIContextMenuInfo aUtils); */
NS_IMETHODIMP nsContextMenuListener2::OnShowContextMenu(uint32_t aContextFlags, nsIContextMenuInfo *aUtils)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContextMenuInfo */
#define NS_ICONTEXTMENUINFO_IID_STR "2f977d56-5485-11d4-87e2-0010a4e75ef2"

#define NS_ICONTEXTMENUINFO_IID \
  {0x2f977d56, 0x5485, 0x11d4, \
    { 0x87, 0xe2, 0x00, 0x10, 0xa4, 0xe7, 0x5e, 0xf2 }}

class NS_NO_VTABLE nsIContextMenuInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTEXTMENUINFO_IID)

  /* readonly attribute nsIDOMEvent mouseEvent; */
  NS_IMETHOD GetMouseEvent(nsIDOMEvent * *aMouseEvent) = 0;

  /* readonly attribute nsIDOMNode targetNode; */
  NS_IMETHOD GetTargetNode(nsIDOMNode * *aTargetNode) = 0;

  /* readonly attribute AString associatedLink; */
  NS_IMETHOD GetAssociatedLink(nsAString & aAssociatedLink) = 0;

  /* readonly attribute imgIContainer imageContainer; */
  NS_IMETHOD GetImageContainer(imgIContainer * *aImageContainer) = 0;

  /* readonly attribute nsIURI imageSrc; */
  NS_IMETHOD GetImageSrc(nsIURI * *aImageSrc) = 0;

  /* readonly attribute imgIContainer backgroundImageContainer; */
  NS_IMETHOD GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer) = 0;

  /* readonly attribute nsIURI backgroundImageSrc; */
  NS_IMETHOD GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContextMenuInfo, NS_ICONTEXTMENUINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTEXTMENUINFO \
  NS_IMETHOD GetMouseEvent(nsIDOMEvent * *aMouseEvent) override; \
  NS_IMETHOD GetTargetNode(nsIDOMNode * *aTargetNode) override; \
  NS_IMETHOD GetAssociatedLink(nsAString & aAssociatedLink) override; \
  NS_IMETHOD GetImageContainer(imgIContainer * *aImageContainer) override; \
  NS_IMETHOD GetImageSrc(nsIURI * *aImageSrc) override; \
  NS_IMETHOD GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer) override; \
  NS_IMETHOD GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTEXTMENUINFO(_to) \
  NS_IMETHOD GetMouseEvent(nsIDOMEvent * *aMouseEvent) override { return _to GetMouseEvent(aMouseEvent); } \
  NS_IMETHOD GetTargetNode(nsIDOMNode * *aTargetNode) override { return _to GetTargetNode(aTargetNode); } \
  NS_IMETHOD GetAssociatedLink(nsAString & aAssociatedLink) override { return _to GetAssociatedLink(aAssociatedLink); } \
  NS_IMETHOD GetImageContainer(imgIContainer * *aImageContainer) override { return _to GetImageContainer(aImageContainer); } \
  NS_IMETHOD GetImageSrc(nsIURI * *aImageSrc) override { return _to GetImageSrc(aImageSrc); } \
  NS_IMETHOD GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer) override { return _to GetBackgroundImageContainer(aBackgroundImageContainer); } \
  NS_IMETHOD GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc) override { return _to GetBackgroundImageSrc(aBackgroundImageSrc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTEXTMENUINFO(_to) \
  NS_IMETHOD GetMouseEvent(nsIDOMEvent * *aMouseEvent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMouseEvent(aMouseEvent); } \
  NS_IMETHOD GetTargetNode(nsIDOMNode * *aTargetNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetNode(aTargetNode); } \
  NS_IMETHOD GetAssociatedLink(nsAString & aAssociatedLink) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAssociatedLink(aAssociatedLink); } \
  NS_IMETHOD GetImageContainer(imgIContainer * *aImageContainer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageContainer(aImageContainer); } \
  NS_IMETHOD GetImageSrc(nsIURI * *aImageSrc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageSrc(aImageSrc); } \
  NS_IMETHOD GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBackgroundImageContainer(aBackgroundImageContainer); } \
  NS_IMETHOD GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBackgroundImageSrc(aBackgroundImageSrc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContextMenuInfo : public nsIContextMenuInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTEXTMENUINFO

  nsContextMenuInfo();

private:
  ~nsContextMenuInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsContextMenuInfo, nsIContextMenuInfo)

nsContextMenuInfo::nsContextMenuInfo()
{
  /* member initializers and constructor code */
}

nsContextMenuInfo::~nsContextMenuInfo()
{
  /* destructor code */
}

/* readonly attribute nsIDOMEvent mouseEvent; */
NS_IMETHODIMP nsContextMenuInfo::GetMouseEvent(nsIDOMEvent * *aMouseEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode targetNode; */
NS_IMETHODIMP nsContextMenuInfo::GetTargetNode(nsIDOMNode * *aTargetNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString associatedLink; */
NS_IMETHODIMP nsContextMenuInfo::GetAssociatedLink(nsAString & aAssociatedLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute imgIContainer imageContainer; */
NS_IMETHODIMP nsContextMenuInfo::GetImageContainer(imgIContainer * *aImageContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI imageSrc; */
NS_IMETHODIMP nsContextMenuInfo::GetImageSrc(nsIURI * *aImageSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute imgIContainer backgroundImageContainer; */
NS_IMETHODIMP nsContextMenuInfo::GetBackgroundImageContainer(imgIContainer * *aBackgroundImageContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI backgroundImageSrc; */
NS_IMETHODIMP nsContextMenuInfo::GetBackgroundImageSrc(nsIURI * *aBackgroundImageSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContextMenuListener2_h__ */
