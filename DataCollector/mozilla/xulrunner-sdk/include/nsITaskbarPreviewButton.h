/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITaskbarPreviewButton.idl
 */

#ifndef __gen_nsITaskbarPreviewButton_h__
#define __gen_nsITaskbarPreviewButton_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIContainer; /* forward declaration */


/* starting interface:    nsITaskbarPreviewButton */
#define NS_ITASKBARPREVIEWBUTTON_IID_STR "ced8842d-fe37-4767-9a8e-fdfa56510c75"

#define NS_ITASKBARPREVIEWBUTTON_IID \
  {0xced8842d, 0xfe37, 0x4767, \
    { 0x9a, 0x8e, 0xfd, 0xfa, 0x56, 0x51, 0x0c, 0x75 }}

class NS_NO_VTABLE nsITaskbarPreviewButton : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITASKBARPREVIEWBUTTON_IID)

  /* attribute DOMString tooltip; */
  NS_IMETHOD GetTooltip(nsAString & aTooltip) = 0;
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) = 0;

  /* attribute boolean dismissOnClick; */
  NS_IMETHOD GetDismissOnClick(bool *aDismissOnClick) = 0;
  NS_IMETHOD SetDismissOnClick(bool aDismissOnClick) = 0;

  /* attribute boolean hasBorder; */
  NS_IMETHOD GetHasBorder(bool *aHasBorder) = 0;
  NS_IMETHOD SetHasBorder(bool aHasBorder) = 0;

  /* attribute boolean disabled; */
  NS_IMETHOD GetDisabled(bool *aDisabled) = 0;
  NS_IMETHOD SetDisabled(bool aDisabled) = 0;

  /* attribute imgIContainer image; */
  NS_IMETHOD GetImage(imgIContainer * *aImage) = 0;
  NS_IMETHOD SetImage(imgIContainer *aImage) = 0;

  /* attribute boolean visible; */
  NS_IMETHOD GetVisible(bool *aVisible) = 0;
  NS_IMETHOD SetVisible(bool aVisible) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaskbarPreviewButton, NS_ITASKBARPREVIEWBUTTON_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITASKBARPREVIEWBUTTON \
  NS_IMETHOD GetTooltip(nsAString & aTooltip) override; \
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) override; \
  NS_IMETHOD GetDismissOnClick(bool *aDismissOnClick) override; \
  NS_IMETHOD SetDismissOnClick(bool aDismissOnClick) override; \
  NS_IMETHOD GetHasBorder(bool *aHasBorder) override; \
  NS_IMETHOD SetHasBorder(bool aHasBorder) override; \
  NS_IMETHOD GetDisabled(bool *aDisabled) override; \
  NS_IMETHOD SetDisabled(bool aDisabled) override; \
  NS_IMETHOD GetImage(imgIContainer * *aImage) override; \
  NS_IMETHOD SetImage(imgIContainer *aImage) override; \
  NS_IMETHOD GetVisible(bool *aVisible) override; \
  NS_IMETHOD SetVisible(bool aVisible) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITASKBARPREVIEWBUTTON(_to) \
  NS_IMETHOD GetTooltip(nsAString & aTooltip) override { return _to GetTooltip(aTooltip); } \
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) override { return _to SetTooltip(aTooltip); } \
  NS_IMETHOD GetDismissOnClick(bool *aDismissOnClick) override { return _to GetDismissOnClick(aDismissOnClick); } \
  NS_IMETHOD SetDismissOnClick(bool aDismissOnClick) override { return _to SetDismissOnClick(aDismissOnClick); } \
  NS_IMETHOD GetHasBorder(bool *aHasBorder) override { return _to GetHasBorder(aHasBorder); } \
  NS_IMETHOD SetHasBorder(bool aHasBorder) override { return _to SetHasBorder(aHasBorder); } \
  NS_IMETHOD GetDisabled(bool *aDisabled) override { return _to GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) override { return _to SetDisabled(aDisabled); } \
  NS_IMETHOD GetImage(imgIContainer * *aImage) override { return _to GetImage(aImage); } \
  NS_IMETHOD SetImage(imgIContainer *aImage) override { return _to SetImage(aImage); } \
  NS_IMETHOD GetVisible(bool *aVisible) override { return _to GetVisible(aVisible); } \
  NS_IMETHOD SetVisible(bool aVisible) override { return _to SetVisible(aVisible); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITASKBARPREVIEWBUTTON(_to) \
  NS_IMETHOD GetTooltip(nsAString & aTooltip) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTooltip(aTooltip); } \
  NS_IMETHOD SetTooltip(const nsAString & aTooltip) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTooltip(aTooltip); } \
  NS_IMETHOD GetDismissOnClick(bool *aDismissOnClick) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDismissOnClick(aDismissOnClick); } \
  NS_IMETHOD SetDismissOnClick(bool aDismissOnClick) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDismissOnClick(aDismissOnClick); } \
  NS_IMETHOD GetHasBorder(bool *aHasBorder) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasBorder(aHasBorder); } \
  NS_IMETHOD SetHasBorder(bool aHasBorder) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHasBorder(aHasBorder); } \
  NS_IMETHOD GetDisabled(bool *aDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisabled(aDisabled); } \
  NS_IMETHOD SetDisabled(bool aDisabled) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisabled(aDisabled); } \
  NS_IMETHOD GetImage(imgIContainer * *aImage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_IMETHOD SetImage(imgIContainer *aImage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImage(aImage); } \
  NS_IMETHOD GetVisible(bool *aVisible) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisible(aVisible); } \
  NS_IMETHOD SetVisible(bool aVisible) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisible(aVisible); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaskbarPreviewButton : public nsITaskbarPreviewButton
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITASKBARPREVIEWBUTTON

  nsTaskbarPreviewButton();

private:
  ~nsTaskbarPreviewButton();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsTaskbarPreviewButton, nsITaskbarPreviewButton)

nsTaskbarPreviewButton::nsTaskbarPreviewButton()
{
  /* member initializers and constructor code */
}

nsTaskbarPreviewButton::~nsTaskbarPreviewButton()
{
  /* destructor code */
}

/* attribute DOMString tooltip; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetTooltip(nsAString & aTooltip)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetTooltip(const nsAString & aTooltip)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean dismissOnClick; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetDismissOnClick(bool *aDismissOnClick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetDismissOnClick(bool aDismissOnClick)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hasBorder; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetHasBorder(bool *aHasBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetHasBorder(bool aHasBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean disabled; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetDisabled(bool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute imgIContainer image; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetImage(imgIContainer * *aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetImage(imgIContainer *aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean visible; */
NS_IMETHODIMP nsTaskbarPreviewButton::GetVisible(bool *aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTaskbarPreviewButton::SetVisible(bool aVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITaskbarPreviewButton_h__ */
