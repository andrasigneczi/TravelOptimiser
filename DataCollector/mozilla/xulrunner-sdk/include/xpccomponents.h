/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\xpccomponents.idl
 */

#ifndef __gen_xpccomponents_h__
#define __gen_xpccomponents_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"
class xpcIJSWeakReference; /* forward declaration */

class nsIAddonInterposition; /* forward declaration */

class nsIClassInfo; /* forward declaration */

class nsIComponentManager; /* forward declaration */

class nsICycleCollectorListener; /* forward declaration */

class nsIJSCID; /* forward declaration */

class nsIJSIID; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIStackFrame; /* forward declaration */


/* starting interface:    nsIXPCComponents_InterfacesByID */
#define NS_IXPCCOMPONENTS_INTERFACESBYID_IID_STR "f235ef76-9919-478b-aa0f-282d994ddf76"

#define NS_IXPCCOMPONENTS_INTERFACESBYID_IID \
  {0xf235ef76, 0x9919, 0x478b, \
    { 0xaa, 0x0f, 0x28, 0x2d, 0x99, 0x4d, 0xdf, 0x76 }}

class NS_NO_VTABLE nsIXPCComponents_InterfacesByID : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_INTERFACESBYID_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_InterfacesByID, NS_IXPCCOMPONENTS_INTERFACESBYID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_INTERFACESBYID \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_INTERFACESBYID(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_INTERFACESBYID(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_InterfacesByID : public nsIXPCComponents_InterfacesByID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_INTERFACESBYID

  nsXPCComponents_InterfacesByID();

private:
  ~nsXPCComponents_InterfacesByID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_InterfacesByID, nsIXPCComponents_InterfacesByID)

nsXPCComponents_InterfacesByID::nsXPCComponents_InterfacesByID()
{
  /* member initializers and constructor code */
}

nsXPCComponents_InterfacesByID::~nsXPCComponents_InterfacesByID()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Interfaces */
#define NS_IXPCCOMPONENTS_INTERFACES_IID_STR "b8c31bba-79db-4a1d-930d-4cdd68713f9e"

#define NS_IXPCCOMPONENTS_INTERFACES_IID \
  {0xb8c31bba, 0x79db, 0x4a1d, \
    { 0x93, 0x0d, 0x4c, 0xdd, 0x68, 0x71, 0x3f, 0x9e }}

class NS_NO_VTABLE nsIXPCComponents_Interfaces : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_INTERFACES_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Interfaces, NS_IXPCCOMPONENTS_INTERFACES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_INTERFACES \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_INTERFACES(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_INTERFACES(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Interfaces : public nsIXPCComponents_Interfaces
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_INTERFACES

  nsXPCComponents_Interfaces();

private:
  ~nsXPCComponents_Interfaces();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_Interfaces, nsIXPCComponents_Interfaces)

nsXPCComponents_Interfaces::nsXPCComponents_Interfaces()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Interfaces::~nsXPCComponents_Interfaces()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Classes */
#define NS_IXPCCOMPONENTS_CLASSES_IID_STR "978ff520-d26c-11d2-9842-006008962422"

#define NS_IXPCCOMPONENTS_CLASSES_IID \
  {0x978ff520, 0xd26c, 0x11d2, \
    { 0x98, 0x42, 0x00, 0x60, 0x08, 0x96, 0x24, 0x22 }}

class NS_NO_VTABLE nsIXPCComponents_Classes : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_CLASSES_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Classes, NS_IXPCCOMPONENTS_CLASSES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_CLASSES \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_CLASSES(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_CLASSES(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Classes : public nsIXPCComponents_Classes
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_CLASSES

  nsXPCComponents_Classes();

private:
  ~nsXPCComponents_Classes();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_Classes, nsIXPCComponents_Classes)

nsXPCComponents_Classes::nsXPCComponents_Classes()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Classes::~nsXPCComponents_Classes()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_ClassesByID */
#define NS_IXPCCOMPONENTS_CLASSESBYID_IID_STR "336a9590-4d19-11d3-9893-006008962422"

#define NS_IXPCCOMPONENTS_CLASSESBYID_IID \
  {0x336a9590, 0x4d19, 0x11d3, \
    { 0x98, 0x93, 0x00, 0x60, 0x08, 0x96, 0x24, 0x22 }}

class NS_NO_VTABLE nsIXPCComponents_ClassesByID : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_CLASSESBYID_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_ClassesByID, NS_IXPCCOMPONENTS_CLASSESBYID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_CLASSESBYID \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_CLASSESBYID(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_CLASSESBYID(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_ClassesByID : public nsIXPCComponents_ClassesByID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_CLASSESBYID

  nsXPCComponents_ClassesByID();

private:
  ~nsXPCComponents_ClassesByID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_ClassesByID, nsIXPCComponents_ClassesByID)

nsXPCComponents_ClassesByID::nsXPCComponents_ClassesByID()
{
  /* member initializers and constructor code */
}

nsXPCComponents_ClassesByID::~nsXPCComponents_ClassesByID()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Results */
#define NS_IXPCCOMPONENTS_RESULTS_IID_STR "2fc229a0-5860-11d3-9899-006008962422"

#define NS_IXPCCOMPONENTS_RESULTS_IID \
  {0x2fc229a0, 0x5860, 0x11d3, \
    { 0x98, 0x99, 0x00, 0x60, 0x08, 0x96, 0x24, 0x22 }}

class NS_NO_VTABLE nsIXPCComponents_Results : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_RESULTS_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Results, NS_IXPCCOMPONENTS_RESULTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_RESULTS \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_RESULTS(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_RESULTS(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Results : public nsIXPCComponents_Results
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_RESULTS

  nsXPCComponents_Results();

private:
  ~nsXPCComponents_Results();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_Results, nsIXPCComponents_Results)

nsXPCComponents_Results::nsXPCComponents_Results()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Results::~nsXPCComponents_Results()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_ID */
#define NS_IXPCCOMPONENTS_ID_IID_STR "7994a6e0-e028-11d3-8f5d-0010a4e73d9a"

#define NS_IXPCCOMPONENTS_ID_IID \
  {0x7994a6e0, 0xe028, 0x11d3, \
    { 0x8f, 0x5d, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIXPCComponents_ID : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_ID_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_ID, NS_IXPCCOMPONENTS_ID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_ID \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_ID(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_ID(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_ID : public nsIXPCComponents_ID
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_ID

  nsXPCComponents_ID();

private:
  ~nsXPCComponents_ID();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_ID, nsIXPCComponents_ID)

nsXPCComponents_ID::nsXPCComponents_ID()
{
  /* member initializers and constructor code */
}

nsXPCComponents_ID::~nsXPCComponents_ID()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Exception */
#define NS_IXPCCOMPONENTS_EXCEPTION_IID_STR "5bf039c0-e028-11d3-8f5d-0010a4e73d9a"

#define NS_IXPCCOMPONENTS_EXCEPTION_IID \
  {0x5bf039c0, 0xe028, 0x11d3, \
    { 0x8f, 0x5d, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIXPCComponents_Exception : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_EXCEPTION_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Exception, NS_IXPCCOMPONENTS_EXCEPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_EXCEPTION \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_EXCEPTION(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_EXCEPTION(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Exception : public nsIXPCComponents_Exception
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_EXCEPTION

  nsXPCComponents_Exception();

private:
  ~nsXPCComponents_Exception();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_Exception, nsIXPCComponents_Exception)

nsXPCComponents_Exception::nsXPCComponents_Exception()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Exception::~nsXPCComponents_Exception()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Constructor */
#define NS_IXPCCOMPONENTS_CONSTRUCTOR_IID_STR "88655640-e028-11d3-8f5d-0010a4e73d9a"

#define NS_IXPCCOMPONENTS_CONSTRUCTOR_IID \
  {0x88655640, 0xe028, 0x11d3, \
    { 0x8f, 0x5d, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIXPCComponents_Constructor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_CONSTRUCTOR_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Constructor, NS_IXPCCOMPONENTS_CONSTRUCTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_CONSTRUCTOR \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_CONSTRUCTOR(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_CONSTRUCTOR(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Constructor : public nsIXPCComponents_Constructor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_CONSTRUCTOR

  nsXPCComponents_Constructor();

private:
  ~nsXPCComponents_Constructor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_Constructor, nsIXPCComponents_Constructor)

nsXPCComponents_Constructor::nsXPCComponents_Constructor()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Constructor::~nsXPCComponents_Constructor()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCConstructor */
#define NS_IXPCCONSTRUCTOR_IID_STR "c814ca20-e0dc-11d3-8f5f-0010a4e73d9a"

#define NS_IXPCCONSTRUCTOR_IID \
  {0xc814ca20, 0xe0dc, 0x11d3, \
    { 0x8f, 0x5f, 0x00, 0x10, 0xa4, 0xe7, 0x3d, 0x9a }}

class NS_NO_VTABLE nsIXPCConstructor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCONSTRUCTOR_IID)

  /* readonly attribute nsIJSCID classID; */
  NS_IMETHOD GetClassID(nsIJSCID * *aClassID) = 0;

  /* readonly attribute nsIJSIID interfaceID; */
  NS_IMETHOD GetInterfaceID(nsIJSIID * *aInterfaceID) = 0;

  /* readonly attribute string initializer; */
  NS_IMETHOD GetInitializer(char * *aInitializer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCConstructor, NS_IXPCCONSTRUCTOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCONSTRUCTOR \
  NS_IMETHOD GetClassID(nsIJSCID * *aClassID) override; \
  NS_IMETHOD GetInterfaceID(nsIJSIID * *aInterfaceID) override; \
  NS_IMETHOD GetInitializer(char * *aInitializer) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCONSTRUCTOR(_to) \
  NS_IMETHOD GetClassID(nsIJSCID * *aClassID) override { return _to GetClassID(aClassID); } \
  NS_IMETHOD GetInterfaceID(nsIJSIID * *aInterfaceID) override { return _to GetInterfaceID(aInterfaceID); } \
  NS_IMETHOD GetInitializer(char * *aInitializer) override { return _to GetInitializer(aInitializer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCONSTRUCTOR(_to) \
  NS_IMETHOD GetClassID(nsIJSCID * *aClassID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassID(aClassID); } \
  NS_IMETHOD GetInterfaceID(nsIJSIID * *aInterfaceID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaceID(aInterfaceID); } \
  NS_IMETHOD GetInitializer(char * *aInitializer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInitializer(aInitializer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCConstructor : public nsIXPCConstructor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCONSTRUCTOR

  nsXPCConstructor();

private:
  ~nsXPCConstructor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCConstructor, nsIXPCConstructor)

nsXPCConstructor::nsXPCConstructor()
{
  /* member initializers and constructor code */
}

nsXPCConstructor::~nsXPCConstructor()
{
  /* destructor code */
}

/* readonly attribute nsIJSCID classID; */
NS_IMETHODIMP nsXPCConstructor::GetClassID(nsIJSCID * *aClassID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIJSIID interfaceID; */
NS_IMETHODIMP nsXPCConstructor::GetInterfaceID(nsIJSIID * *aInterfaceID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string initializer; */
NS_IMETHODIMP nsXPCConstructor::GetInitializer(char * *aInitializer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_utils_Sandbox */
#define NS_IXPCCOMPONENTS_UTILS_SANDBOX_IID_STR "4f8ae0dc-d266-4a32-875b-6a9de71a8ce9"

#define NS_IXPCCOMPONENTS_UTILS_SANDBOX_IID \
  {0x4f8ae0dc, 0xd266, 0x4a32, \
    { 0x87, 0x5b, 0x6a, 0x9d, 0xe7, 0x1a, 0x8c, 0xe9 }}

class NS_NO_VTABLE nsIXPCComponents_utils_Sandbox : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_UTILS_SANDBOX_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_utils_Sandbox, NS_IXPCCOMPONENTS_UTILS_SANDBOX_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_UTILS_SANDBOX \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_UTILS_SANDBOX(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_UTILS_SANDBOX(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_utils_Sandbox : public nsIXPCComponents_utils_Sandbox
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_UTILS_SANDBOX

  nsXPCComponents_utils_Sandbox();

private:
  ~nsXPCComponents_utils_Sandbox();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_utils_Sandbox, nsIXPCComponents_utils_Sandbox)

nsXPCComponents_utils_Sandbox::nsXPCComponents_utils_Sandbox()
{
  /* member initializers and constructor code */
}

nsXPCComponents_utils_Sandbox::~nsXPCComponents_utils_Sandbox()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


/* starting interface:    ScheduledGCCallback */
#define SCHEDULEDGCCALLBACK_IID_STR "71000535-b0fd-44d1-8ce0-909760e3953c"

#define SCHEDULEDGCCALLBACK_IID \
  {0x71000535, 0xb0fd, 0x44d1, \
    { 0x8c, 0xe0, 0x90, 0x97, 0x60, 0xe3, 0x95, 0x3c }}

class NS_NO_VTABLE ScheduledGCCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(SCHEDULEDGCCALLBACK_IID)

  /* void callback (); */
  NS_IMETHOD Callback(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(ScheduledGCCallback, SCHEDULEDGCCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_SCHEDULEDGCCALLBACK \
  NS_IMETHOD Callback(void) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_SCHEDULEDGCCALLBACK(_to) \
  NS_IMETHOD Callback(void) override { return _to Callback(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_SCHEDULEDGCCALLBACK(_to) \
  NS_IMETHOD Callback(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Callback(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public ScheduledGCCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_SCHEDULEDGCCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(_MYCLASS_, ScheduledGCCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void callback (); */
NS_IMETHODIMP _MYCLASS_::Callback()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents_Utils */
#define NS_IXPCCOMPONENTS_UTILS_IID_STR "e04a4a58-2b5e-4a74-941a-0d344b057c5a"

#define NS_IXPCCOMPONENTS_UTILS_IID \
  {0xe04a4a58, 0x2b5e, 0x4a74, \
    { 0x94, 0x1a, 0x0d, 0x34, 0x4b, 0x05, 0x7c, 0x5a }}

class NS_NO_VTABLE nsIXPCComponents_Utils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_UTILS_IID)

  /* [implicit_jscontext] void reportError (in jsval error); */
  NS_IMETHOD ReportError(JS::HandleValue error, JSContext* cx) = 0;

  /* readonly attribute nsIXPCComponents_utils_Sandbox Sandbox; */
  NS_IMETHOD GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox) = 0;

  /* [implicit_jscontext,optional_argc] jsval evalInSandbox (in AString source, in jsval sandbox, [optional] in jsval version, [optional] in AUTF8String filename, [optional] in long lineNo); */
  NS_IMETHOD EvalInSandbox(const nsAString & source, JS::HandleValue sandbox, JS::HandleValue version, const nsACString & filename, int32_t lineNo, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval getSandboxAddonId (in jsval sandbox); */
  NS_IMETHOD GetSandboxAddonId(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval getSandboxMetadata (in jsval sandbox); */
  NS_IMETHOD GetSandboxMetadata(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] void setSandboxMetadata (in jsval sandbox, in jsval metadata); */
  NS_IMETHOD SetSandboxMetadata(JS::HandleValue sandbox, JS::HandleValue metadata, JSContext* cx) = 0;

  /* [implicit_jscontext,optional_argc] jsval import (in AUTF8String aResourceURI, [optional] in jsval targetObj); */
  NS_IMETHOD Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

  /* boolean isModuleLoaded (in AUTF8String aResourceURI); */
  NS_IMETHOD IsModuleLoaded(const nsACString & aResourceURI, bool *_retval) = 0;

  /* void unload (in AUTF8String registryLocation); */
  NS_IMETHOD Unload(const nsACString & registryLocation) = 0;

  /* [implicit_jscontext] void importGlobalProperties (in jsval aPropertyList); */
  NS_IMETHOD ImportGlobalProperties(JS::HandleValue aPropertyList, JSContext* cx) = 0;

  /* [implicit_jscontext] xpcIJSWeakReference getWeakReference (in jsval obj); */
  NS_IMETHOD GetWeakReference(JS::HandleValue obj, JSContext* cx, xpcIJSWeakReference * *_retval) = 0;

  /* void forceGC (); */
  NS_IMETHOD ForceGC(void) = 0;

  /* void forceCC ([optional] in nsICycleCollectorListener aListener); */
  NS_IMETHOD ForceCC(nsICycleCollectorListener *aListener) = 0;

  /* void finishCC (); */
  NS_IMETHOD FinishCC(void) = 0;

  /* void ccSlice (in long long budget); */
  NS_IMETHOD CcSlice(int64_t budget) = 0;

  /* long getMaxCCSliceTimeSinceClear (); */
  NS_IMETHOD GetMaxCCSliceTimeSinceClear(int32_t *_retval) = 0;

  /* void clearMaxCCTime (); */
  NS_IMETHOD ClearMaxCCTime(void) = 0;

  /* void forceShrinkingGC (); */
  NS_IMETHOD ForceShrinkingGC(void) = 0;

  /* void schedulePreciseGC (in ScheduledGCCallback callback); */
  NS_IMETHOD SchedulePreciseGC(ScheduledGCCallback *callback) = 0;

  /* void schedulePreciseShrinkingGC (in ScheduledGCCallback callback); */
  NS_IMETHOD SchedulePreciseShrinkingGC(ScheduledGCCallback *callback) = 0;

  /* void unlinkGhostWindows (); */
  NS_IMETHOD UnlinkGhostWindows(void) = 0;

  /* [implicit_jscontext] jsval nondeterministicGetWeakMapKeys (in jsval aMap); */
  NS_IMETHOD NondeterministicGetWeakMapKeys(JS::HandleValue aMap, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval getJSTestingFunctions (); */
  NS_IMETHOD GetJSTestingFunctions(JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval callFunctionWithAsyncStack (in jsval function, in nsIStackFrame stack, in AString asyncCause); */
  NS_IMETHOD CallFunctionWithAsyncStack(JS::HandleValue function, nsIStackFrame *stack, const nsAString & asyncCause, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval getGlobalForObject (in jsval obj); */
  NS_IMETHOD GetGlobalForObject(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] boolean isProxy (in jsval vobject); */
  NS_IMETHOD IsProxy(JS::HandleValue vobject, JSContext* cx, bool *_retval) = 0;

  /* [implicit_jscontext] jsval exportFunction (in jsval vfunction, in jsval vscope, [optional] in jsval voptions); */
  NS_IMETHOD ExportFunction(JS::HandleValue vfunction, JS::HandleValue vscope, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval createObjectIn (in jsval vobj, [optional] in jsval voptions); */
  NS_IMETHOD CreateObjectIn(JS::HandleValue vobj, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] void makeObjectPropsNormal (in jsval vobj); */
  NS_IMETHOD MakeObjectPropsNormal(JS::HandleValue vobj, JSContext* cx) = 0;

  /* bool isDeadWrapper (in jsval obj); */
  NS_IMETHOD IsDeadWrapper(JS::HandleValue obj, bool *_retval) = 0;

  /* bool isCrossProcessWrapper (in jsval obj); */
  NS_IMETHOD IsCrossProcessWrapper(JS::HandleValue obj, bool *_retval) = 0;

  /* ACString getCrossProcessWrapperTag (in jsval obj); */
  NS_IMETHOD GetCrossProcessWrapperTag(JS::HandleValue obj, nsACString & _retval) = 0;

  /* [implicit_jscontext] void recomputeWrappers ([optional] in jsval vobj); */
  NS_IMETHOD RecomputeWrappers(JS::HandleValue vobj, JSContext* cx) = 0;

  /* [implicit_jscontext] void setWantXrays (in jsval vscope); */
  NS_IMETHOD SetWantXrays(JS::HandleValue vscope, JSContext* cx) = 0;

  /* [implicit_jscontext] void forcePermissiveCOWs (); */
  NS_IMETHOD ForcePermissiveCOWs(JSContext* cx) = 0;

  /* [implicit_jscontext] void skipCOWCallableChecks (); */
  NS_IMETHOD SkipCOWCallableChecks(JSContext* cx) = 0;

  /* [implicit_jscontext] void forcePrivilegedComponentsForScope (in jsval vscope); */
  NS_IMETHOD ForcePrivilegedComponentsForScope(JS::HandleValue vscope, JSContext* cx) = 0;

  /* [implicit_jscontext] jsval getComponentsForScope (in jsval vscope); */
  NS_IMETHOD GetComponentsForScope(JS::HandleValue vscope, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] void dispatch (in jsval runnable, [optional] in jsval scope); */
  NS_IMETHOD Dispatch(JS::HandleValue runnable, JS::HandleValue scope, JSContext* cx) = 0;

  /* [implicit_jscontext] attribute boolean strict; */
  NS_IMETHOD GetStrict(JSContext* cx, bool *aStrict) = 0;
  NS_IMETHOD SetStrict(JSContext* cx, bool aStrict) = 0;

  /* [implicit_jscontext] attribute boolean werror; */
  NS_IMETHOD GetWerror(JSContext* cx, bool *aWerror) = 0;
  NS_IMETHOD SetWerror(JSContext* cx, bool aWerror) = 0;

  /* [implicit_jscontext] attribute boolean strict_mode; */
  NS_IMETHOD GetStrict_mode(JSContext* cx, bool *aStrict_mode) = 0;
  NS_IMETHOD SetStrict_mode(JSContext* cx, bool aStrict_mode) = 0;

  /* [implicit_jscontext] attribute boolean ion; */
  NS_IMETHOD GetIon(JSContext* cx, bool *aIon) = 0;
  NS_IMETHOD SetIon(JSContext* cx, bool aIon) = 0;

  /* [implicit_jscontext] void setGCZeal (in long zeal); */
  NS_IMETHOD SetGCZeal(int32_t zeal, JSContext* cx) = 0;

  /* [implicit_jscontext] void nukeSandbox (in jsval obj); */
  NS_IMETHOD NukeSandbox(JS::HandleValue obj, JSContext* cx) = 0;

  /* [implicit_jscontext] void blockScriptForGlobal (in jsval global); */
  NS_IMETHOD BlockScriptForGlobal(JS::HandleValue global, JSContext* cx) = 0;

  /* [implicit_jscontext] void unblockScriptForGlobal (in jsval global); */
  NS_IMETHOD UnblockScriptForGlobal(JS::HandleValue global, JSContext* cx) = 0;

  /* bool isXrayWrapper (in jsval obj); */
  NS_IMETHOD IsXrayWrapper(JS::HandleValue obj, bool *_retval) = 0;

  /* [implicit_jscontext] jsval waiveXrays (in jsval aVal); */
  NS_IMETHOD WaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval unwaiveXrays (in jsval aVal); */
  NS_IMETHOD UnwaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] string getClassName (in jsval aObj, in bool aUnwrap); */
  NS_IMETHOD GetClassName(JS::HandleValue aObj, bool aUnwrap, JSContext* cx, char * *_retval) = 0;

  /* nsIClassInfo getDOMClassInfo (in AString aClassName); */
  NS_IMETHOD GetDOMClassInfo(const nsAString & aClassName, nsIClassInfo * *_retval) = 0;

  /* [implicit_jscontext] jsval getIncumbentGlobal ([optional] in jsval callback); */
  NS_IMETHOD GetIncumbentGlobal(JS::HandleValue callback, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] nsISupports generateXPCWrappedJS (in jsval obj, [optional] in jsval scope); */
  NS_IMETHOD GenerateXPCWrappedJS(JS::HandleValue obj, JS::HandleValue scope, JSContext* cx, nsISupports * *_retval) = 0;

  /* PRTime getWatchdogTimestamp (in AString aCategory); */
  NS_IMETHOD GetWatchdogTimestamp(const nsAString & aCategory, PRTime *_retval) = 0;

  /* [implicit_jscontext] jsval getJSEngineTelemetryValue (); */
  NS_IMETHOD GetJSEngineTelemetryValue(JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext] jsval cloneInto (in jsval value, in jsval scope, [optional] in jsval options); */
  NS_IMETHOD CloneInto(JS::HandleValue value, JS::HandleValue scope, JS::HandleValue options, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* nsIPrincipal getWebIDLCallerPrincipal (); */
  NS_IMETHOD GetWebIDLCallerPrincipal(nsIPrincipal * *_retval) = 0;

  /* [implicit_jscontext] nsIPrincipal getObjectPrincipal (in jsval obj); */
  NS_IMETHOD GetObjectPrincipal(JS::HandleValue obj, JSContext* cx, nsIPrincipal * *_retval) = 0;

  /* [implicit_jscontext] ACString getCompartmentLocation (in jsval obj); */
  NS_IMETHOD GetCompartmentLocation(JS::HandleValue obj, JSContext* cx, nsACString & _retval) = 0;

  /* [implicit_jscontext] void setAddonInterposition (in ACString addonId, in nsIAddonInterposition interposition); */
  NS_IMETHOD SetAddonInterposition(const nsACString & addonId, nsIAddonInterposition *interposition, JSContext* cx) = 0;

  /* [implicit_jscontext] void setAddonCallInterposition (in jsval target); */
  NS_IMETHOD SetAddonCallInterposition(JS::HandleValue target, JSContext* cx) = 0;

  /* double now (); */
  NS_IMETHOD Now(double *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents_Utils, NS_IXPCCOMPONENTS_UTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS_UTILS \
  NS_IMETHOD ReportError(JS::HandleValue error, JSContext* cx) override; \
  NS_IMETHOD GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox) override; \
  NS_IMETHOD EvalInSandbox(const nsAString & source, JS::HandleValue sandbox, JS::HandleValue version, const nsACString & filename, int32_t lineNo, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetSandboxAddonId(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetSandboxMetadata(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD SetSandboxMetadata(JS::HandleValue sandbox, JS::HandleValue metadata, JSContext* cx) override; \
  NS_IMETHOD Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD IsModuleLoaded(const nsACString & aResourceURI, bool *_retval) override; \
  NS_IMETHOD Unload(const nsACString & registryLocation) override; \
  NS_IMETHOD ImportGlobalProperties(JS::HandleValue aPropertyList, JSContext* cx) override; \
  NS_IMETHOD GetWeakReference(JS::HandleValue obj, JSContext* cx, xpcIJSWeakReference * *_retval) override; \
  NS_IMETHOD ForceGC(void) override; \
  NS_IMETHOD ForceCC(nsICycleCollectorListener *aListener) override; \
  NS_IMETHOD FinishCC(void) override; \
  NS_IMETHOD CcSlice(int64_t budget) override; \
  NS_IMETHOD GetMaxCCSliceTimeSinceClear(int32_t *_retval) override; \
  NS_IMETHOD ClearMaxCCTime(void) override; \
  NS_IMETHOD ForceShrinkingGC(void) override; \
  NS_IMETHOD SchedulePreciseGC(ScheduledGCCallback *callback) override; \
  NS_IMETHOD SchedulePreciseShrinkingGC(ScheduledGCCallback *callback) override; \
  NS_IMETHOD UnlinkGhostWindows(void) override; \
  NS_IMETHOD NondeterministicGetWeakMapKeys(JS::HandleValue aMap, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetJSTestingFunctions(JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD CallFunctionWithAsyncStack(JS::HandleValue function, nsIStackFrame *stack, const nsAString & asyncCause, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetGlobalForObject(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD IsProxy(JS::HandleValue vobject, JSContext* cx, bool *_retval) override; \
  NS_IMETHOD ExportFunction(JS::HandleValue vfunction, JS::HandleValue vscope, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD CreateObjectIn(JS::HandleValue vobj, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD MakeObjectPropsNormal(JS::HandleValue vobj, JSContext* cx) override; \
  NS_IMETHOD IsDeadWrapper(JS::HandleValue obj, bool *_retval) override; \
  NS_IMETHOD IsCrossProcessWrapper(JS::HandleValue obj, bool *_retval) override; \
  NS_IMETHOD GetCrossProcessWrapperTag(JS::HandleValue obj, nsACString & _retval) override; \
  NS_IMETHOD RecomputeWrappers(JS::HandleValue vobj, JSContext* cx) override; \
  NS_IMETHOD SetWantXrays(JS::HandleValue vscope, JSContext* cx) override; \
  NS_IMETHOD ForcePermissiveCOWs(JSContext* cx) override; \
  NS_IMETHOD SkipCOWCallableChecks(JSContext* cx) override; \
  NS_IMETHOD ForcePrivilegedComponentsForScope(JS::HandleValue vscope, JSContext* cx) override; \
  NS_IMETHOD GetComponentsForScope(JS::HandleValue vscope, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD Dispatch(JS::HandleValue runnable, JS::HandleValue scope, JSContext* cx) override; \
  NS_IMETHOD GetStrict(JSContext* cx, bool *aStrict) override; \
  NS_IMETHOD SetStrict(JSContext* cx, bool aStrict) override; \
  NS_IMETHOD GetWerror(JSContext* cx, bool *aWerror) override; \
  NS_IMETHOD SetWerror(JSContext* cx, bool aWerror) override; \
  NS_IMETHOD GetStrict_mode(JSContext* cx, bool *aStrict_mode) override; \
  NS_IMETHOD SetStrict_mode(JSContext* cx, bool aStrict_mode) override; \
  NS_IMETHOD GetIon(JSContext* cx, bool *aIon) override; \
  NS_IMETHOD SetIon(JSContext* cx, bool aIon) override; \
  NS_IMETHOD SetGCZeal(int32_t zeal, JSContext* cx) override; \
  NS_IMETHOD NukeSandbox(JS::HandleValue obj, JSContext* cx) override; \
  NS_IMETHOD BlockScriptForGlobal(JS::HandleValue global, JSContext* cx) override; \
  NS_IMETHOD UnblockScriptForGlobal(JS::HandleValue global, JSContext* cx) override; \
  NS_IMETHOD IsXrayWrapper(JS::HandleValue obj, bool *_retval) override; \
  NS_IMETHOD WaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD UnwaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetClassName(JS::HandleValue aObj, bool aUnwrap, JSContext* cx, char * *_retval) override; \
  NS_IMETHOD GetDOMClassInfo(const nsAString & aClassName, nsIClassInfo * *_retval) override; \
  NS_IMETHOD GetIncumbentGlobal(JS::HandleValue callback, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GenerateXPCWrappedJS(JS::HandleValue obj, JS::HandleValue scope, JSContext* cx, nsISupports * *_retval) override; \
  NS_IMETHOD GetWatchdogTimestamp(const nsAString & aCategory, PRTime *_retval) override; \
  NS_IMETHOD GetJSEngineTelemetryValue(JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD CloneInto(JS::HandleValue value, JS::HandleValue scope, JS::HandleValue options, JSContext* cx, JS::MutableHandleValue _retval) override; \
  NS_IMETHOD GetWebIDLCallerPrincipal(nsIPrincipal * *_retval) override; \
  NS_IMETHOD GetObjectPrincipal(JS::HandleValue obj, JSContext* cx, nsIPrincipal * *_retval) override; \
  NS_IMETHOD GetCompartmentLocation(JS::HandleValue obj, JSContext* cx, nsACString & _retval) override; \
  NS_IMETHOD SetAddonInterposition(const nsACString & addonId, nsIAddonInterposition *interposition, JSContext* cx) override; \
  NS_IMETHOD SetAddonCallInterposition(JS::HandleValue target, JSContext* cx) override; \
  NS_IMETHOD Now(double *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS_UTILS(_to) \
  NS_IMETHOD ReportError(JS::HandleValue error, JSContext* cx) override { return _to ReportError(error, cx); } \
  NS_IMETHOD GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox) override { return _to GetSandbox(aSandbox); } \
  NS_IMETHOD EvalInSandbox(const nsAString & source, JS::HandleValue sandbox, JS::HandleValue version, const nsACString & filename, int32_t lineNo, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return _to EvalInSandbox(source, sandbox, version, filename, lineNo, cx, _argc, _retval); } \
  NS_IMETHOD GetSandboxAddonId(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetSandboxAddonId(sandbox, cx, _retval); } \
  NS_IMETHOD GetSandboxMetadata(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetSandboxMetadata(sandbox, cx, _retval); } \
  NS_IMETHOD SetSandboxMetadata(JS::HandleValue sandbox, JS::HandleValue metadata, JSContext* cx) override { return _to SetSandboxMetadata(sandbox, metadata, cx); } \
  NS_IMETHOD Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return _to Import(aResourceURI, targetObj, cx, _argc, _retval); } \
  NS_IMETHOD IsModuleLoaded(const nsACString & aResourceURI, bool *_retval) override { return _to IsModuleLoaded(aResourceURI, _retval); } \
  NS_IMETHOD Unload(const nsACString & registryLocation) override { return _to Unload(registryLocation); } \
  NS_IMETHOD ImportGlobalProperties(JS::HandleValue aPropertyList, JSContext* cx) override { return _to ImportGlobalProperties(aPropertyList, cx); } \
  NS_IMETHOD GetWeakReference(JS::HandleValue obj, JSContext* cx, xpcIJSWeakReference * *_retval) override { return _to GetWeakReference(obj, cx, _retval); } \
  NS_IMETHOD ForceGC(void) override { return _to ForceGC(); } \
  NS_IMETHOD ForceCC(nsICycleCollectorListener *aListener) override { return _to ForceCC(aListener); } \
  NS_IMETHOD FinishCC(void) override { return _to FinishCC(); } \
  NS_IMETHOD CcSlice(int64_t budget) override { return _to CcSlice(budget); } \
  NS_IMETHOD GetMaxCCSliceTimeSinceClear(int32_t *_retval) override { return _to GetMaxCCSliceTimeSinceClear(_retval); } \
  NS_IMETHOD ClearMaxCCTime(void) override { return _to ClearMaxCCTime(); } \
  NS_IMETHOD ForceShrinkingGC(void) override { return _to ForceShrinkingGC(); } \
  NS_IMETHOD SchedulePreciseGC(ScheduledGCCallback *callback) override { return _to SchedulePreciseGC(callback); } \
  NS_IMETHOD SchedulePreciseShrinkingGC(ScheduledGCCallback *callback) override { return _to SchedulePreciseShrinkingGC(callback); } \
  NS_IMETHOD UnlinkGhostWindows(void) override { return _to UnlinkGhostWindows(); } \
  NS_IMETHOD NondeterministicGetWeakMapKeys(JS::HandleValue aMap, JSContext* cx, JS::MutableHandleValue _retval) override { return _to NondeterministicGetWeakMapKeys(aMap, cx, _retval); } \
  NS_IMETHOD GetJSTestingFunctions(JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetJSTestingFunctions(cx, _retval); } \
  NS_IMETHOD CallFunctionWithAsyncStack(JS::HandleValue function, nsIStackFrame *stack, const nsAString & asyncCause, JSContext* cx, JS::MutableHandleValue _retval) override { return _to CallFunctionWithAsyncStack(function, stack, asyncCause, cx, _retval); } \
  NS_IMETHOD GetGlobalForObject(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetGlobalForObject(obj, cx, _retval); } \
  NS_IMETHOD IsProxy(JS::HandleValue vobject, JSContext* cx, bool *_retval) override { return _to IsProxy(vobject, cx, _retval); } \
  NS_IMETHOD ExportFunction(JS::HandleValue vfunction, JS::HandleValue vscope, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval) override { return _to ExportFunction(vfunction, vscope, voptions, cx, _retval); } \
  NS_IMETHOD CreateObjectIn(JS::HandleValue vobj, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval) override { return _to CreateObjectIn(vobj, voptions, cx, _retval); } \
  NS_IMETHOD MakeObjectPropsNormal(JS::HandleValue vobj, JSContext* cx) override { return _to MakeObjectPropsNormal(vobj, cx); } \
  NS_IMETHOD IsDeadWrapper(JS::HandleValue obj, bool *_retval) override { return _to IsDeadWrapper(obj, _retval); } \
  NS_IMETHOD IsCrossProcessWrapper(JS::HandleValue obj, bool *_retval) override { return _to IsCrossProcessWrapper(obj, _retval); } \
  NS_IMETHOD GetCrossProcessWrapperTag(JS::HandleValue obj, nsACString & _retval) override { return _to GetCrossProcessWrapperTag(obj, _retval); } \
  NS_IMETHOD RecomputeWrappers(JS::HandleValue vobj, JSContext* cx) override { return _to RecomputeWrappers(vobj, cx); } \
  NS_IMETHOD SetWantXrays(JS::HandleValue vscope, JSContext* cx) override { return _to SetWantXrays(vscope, cx); } \
  NS_IMETHOD ForcePermissiveCOWs(JSContext* cx) override { return _to ForcePermissiveCOWs(cx); } \
  NS_IMETHOD SkipCOWCallableChecks(JSContext* cx) override { return _to SkipCOWCallableChecks(cx); } \
  NS_IMETHOD ForcePrivilegedComponentsForScope(JS::HandleValue vscope, JSContext* cx) override { return _to ForcePrivilegedComponentsForScope(vscope, cx); } \
  NS_IMETHOD GetComponentsForScope(JS::HandleValue vscope, JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetComponentsForScope(vscope, cx, _retval); } \
  NS_IMETHOD Dispatch(JS::HandleValue runnable, JS::HandleValue scope, JSContext* cx) override { return _to Dispatch(runnable, scope, cx); } \
  NS_IMETHOD GetStrict(JSContext* cx, bool *aStrict) override { return _to GetStrict(cx, aStrict); } \
  NS_IMETHOD SetStrict(JSContext* cx, bool aStrict) override { return _to SetStrict(cx, aStrict); } \
  NS_IMETHOD GetWerror(JSContext* cx, bool *aWerror) override { return _to GetWerror(cx, aWerror); } \
  NS_IMETHOD SetWerror(JSContext* cx, bool aWerror) override { return _to SetWerror(cx, aWerror); } \
  NS_IMETHOD GetStrict_mode(JSContext* cx, bool *aStrict_mode) override { return _to GetStrict_mode(cx, aStrict_mode); } \
  NS_IMETHOD SetStrict_mode(JSContext* cx, bool aStrict_mode) override { return _to SetStrict_mode(cx, aStrict_mode); } \
  NS_IMETHOD GetIon(JSContext* cx, bool *aIon) override { return _to GetIon(cx, aIon); } \
  NS_IMETHOD SetIon(JSContext* cx, bool aIon) override { return _to SetIon(cx, aIon); } \
  NS_IMETHOD SetGCZeal(int32_t zeal, JSContext* cx) override { return _to SetGCZeal(zeal, cx); } \
  NS_IMETHOD NukeSandbox(JS::HandleValue obj, JSContext* cx) override { return _to NukeSandbox(obj, cx); } \
  NS_IMETHOD BlockScriptForGlobal(JS::HandleValue global, JSContext* cx) override { return _to BlockScriptForGlobal(global, cx); } \
  NS_IMETHOD UnblockScriptForGlobal(JS::HandleValue global, JSContext* cx) override { return _to UnblockScriptForGlobal(global, cx); } \
  NS_IMETHOD IsXrayWrapper(JS::HandleValue obj, bool *_retval) override { return _to IsXrayWrapper(obj, _retval); } \
  NS_IMETHOD WaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval) override { return _to WaiveXrays(aVal, cx, _retval); } \
  NS_IMETHOD UnwaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval) override { return _to UnwaiveXrays(aVal, cx, _retval); } \
  NS_IMETHOD GetClassName(JS::HandleValue aObj, bool aUnwrap, JSContext* cx, char * *_retval) override { return _to GetClassName(aObj, aUnwrap, cx, _retval); } \
  NS_IMETHOD GetDOMClassInfo(const nsAString & aClassName, nsIClassInfo * *_retval) override { return _to GetDOMClassInfo(aClassName, _retval); } \
  NS_IMETHOD GetIncumbentGlobal(JS::HandleValue callback, JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetIncumbentGlobal(callback, cx, _retval); } \
  NS_IMETHOD GenerateXPCWrappedJS(JS::HandleValue obj, JS::HandleValue scope, JSContext* cx, nsISupports * *_retval) override { return _to GenerateXPCWrappedJS(obj, scope, cx, _retval); } \
  NS_IMETHOD GetWatchdogTimestamp(const nsAString & aCategory, PRTime *_retval) override { return _to GetWatchdogTimestamp(aCategory, _retval); } \
  NS_IMETHOD GetJSEngineTelemetryValue(JSContext* cx, JS::MutableHandleValue _retval) override { return _to GetJSEngineTelemetryValue(cx, _retval); } \
  NS_IMETHOD CloneInto(JS::HandleValue value, JS::HandleValue scope, JS::HandleValue options, JSContext* cx, JS::MutableHandleValue _retval) override { return _to CloneInto(value, scope, options, cx, _retval); } \
  NS_IMETHOD GetWebIDLCallerPrincipal(nsIPrincipal * *_retval) override { return _to GetWebIDLCallerPrincipal(_retval); } \
  NS_IMETHOD GetObjectPrincipal(JS::HandleValue obj, JSContext* cx, nsIPrincipal * *_retval) override { return _to GetObjectPrincipal(obj, cx, _retval); } \
  NS_IMETHOD GetCompartmentLocation(JS::HandleValue obj, JSContext* cx, nsACString & _retval) override { return _to GetCompartmentLocation(obj, cx, _retval); } \
  NS_IMETHOD SetAddonInterposition(const nsACString & addonId, nsIAddonInterposition *interposition, JSContext* cx) override { return _to SetAddonInterposition(addonId, interposition, cx); } \
  NS_IMETHOD SetAddonCallInterposition(JS::HandleValue target, JSContext* cx) override { return _to SetAddonCallInterposition(target, cx); } \
  NS_IMETHOD Now(double *_retval) override { return _to Now(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS_UTILS(_to) \
  NS_IMETHOD ReportError(JS::HandleValue error, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReportError(error, cx); } \
  NS_IMETHOD GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSandbox(aSandbox); } \
  NS_IMETHOD EvalInSandbox(const nsAString & source, JS::HandleValue sandbox, JS::HandleValue version, const nsACString & filename, int32_t lineNo, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EvalInSandbox(source, sandbox, version, filename, lineNo, cx, _argc, _retval); } \
  NS_IMETHOD GetSandboxAddonId(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSandboxAddonId(sandbox, cx, _retval); } \
  NS_IMETHOD GetSandboxMetadata(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSandboxMetadata(sandbox, cx, _retval); } \
  NS_IMETHOD SetSandboxMetadata(JS::HandleValue sandbox, JS::HandleValue metadata, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSandboxMetadata(sandbox, metadata, cx); } \
  NS_IMETHOD Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Import(aResourceURI, targetObj, cx, _argc, _retval); } \
  NS_IMETHOD IsModuleLoaded(const nsACString & aResourceURI, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsModuleLoaded(aResourceURI, _retval); } \
  NS_IMETHOD Unload(const nsACString & registryLocation) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Unload(registryLocation); } \
  NS_IMETHOD ImportGlobalProperties(JS::HandleValue aPropertyList, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportGlobalProperties(aPropertyList, cx); } \
  NS_IMETHOD GetWeakReference(JS::HandleValue obj, JSContext* cx, xpcIJSWeakReference * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWeakReference(obj, cx, _retval); } \
  NS_IMETHOD ForceGC(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceGC(); } \
  NS_IMETHOD ForceCC(nsICycleCollectorListener *aListener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceCC(aListener); } \
  NS_IMETHOD FinishCC(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FinishCC(); } \
  NS_IMETHOD CcSlice(int64_t budget) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CcSlice(budget); } \
  NS_IMETHOD GetMaxCCSliceTimeSinceClear(int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMaxCCSliceTimeSinceClear(_retval); } \
  NS_IMETHOD ClearMaxCCTime(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearMaxCCTime(); } \
  NS_IMETHOD ForceShrinkingGC(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceShrinkingGC(); } \
  NS_IMETHOD SchedulePreciseGC(ScheduledGCCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SchedulePreciseGC(callback); } \
  NS_IMETHOD SchedulePreciseShrinkingGC(ScheduledGCCallback *callback) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SchedulePreciseShrinkingGC(callback); } \
  NS_IMETHOD UnlinkGhostWindows(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnlinkGhostWindows(); } \
  NS_IMETHOD NondeterministicGetWeakMapKeys(JS::HandleValue aMap, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NondeterministicGetWeakMapKeys(aMap, cx, _retval); } \
  NS_IMETHOD GetJSTestingFunctions(JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSTestingFunctions(cx, _retval); } \
  NS_IMETHOD CallFunctionWithAsyncStack(JS::HandleValue function, nsIStackFrame *stack, const nsAString & asyncCause, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CallFunctionWithAsyncStack(function, stack, asyncCause, cx, _retval); } \
  NS_IMETHOD GetGlobalForObject(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalForObject(obj, cx, _retval); } \
  NS_IMETHOD IsProxy(JS::HandleValue vobject, JSContext* cx, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsProxy(vobject, cx, _retval); } \
  NS_IMETHOD ExportFunction(JS::HandleValue vfunction, JS::HandleValue vscope, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ExportFunction(vfunction, vscope, voptions, cx, _retval); } \
  NS_IMETHOD CreateObjectIn(JS::HandleValue vobj, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateObjectIn(vobj, voptions, cx, _retval); } \
  NS_IMETHOD MakeObjectPropsNormal(JS::HandleValue vobj, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MakeObjectPropsNormal(vobj, cx); } \
  NS_IMETHOD IsDeadWrapper(JS::HandleValue obj, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsDeadWrapper(obj, _retval); } \
  NS_IMETHOD IsCrossProcessWrapper(JS::HandleValue obj, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCrossProcessWrapper(obj, _retval); } \
  NS_IMETHOD GetCrossProcessWrapperTag(JS::HandleValue obj, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrossProcessWrapperTag(obj, _retval); } \
  NS_IMETHOD RecomputeWrappers(JS::HandleValue vobj, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RecomputeWrappers(vobj, cx); } \
  NS_IMETHOD SetWantXrays(JS::HandleValue vscope, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWantXrays(vscope, cx); } \
  NS_IMETHOD ForcePermissiveCOWs(JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForcePermissiveCOWs(cx); } \
  NS_IMETHOD SkipCOWCallableChecks(JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SkipCOWCallableChecks(cx); } \
  NS_IMETHOD ForcePrivilegedComponentsForScope(JS::HandleValue vscope, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ForcePrivilegedComponentsForScope(vscope, cx); } \
  NS_IMETHOD GetComponentsForScope(JS::HandleValue vscope, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComponentsForScope(vscope, cx, _retval); } \
  NS_IMETHOD Dispatch(JS::HandleValue runnable, JS::HandleValue scope, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Dispatch(runnable, scope, cx); } \
  NS_IMETHOD GetStrict(JSContext* cx, bool *aStrict) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStrict(cx, aStrict); } \
  NS_IMETHOD SetStrict(JSContext* cx, bool aStrict) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStrict(cx, aStrict); } \
  NS_IMETHOD GetWerror(JSContext* cx, bool *aWerror) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWerror(cx, aWerror); } \
  NS_IMETHOD SetWerror(JSContext* cx, bool aWerror) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWerror(cx, aWerror); } \
  NS_IMETHOD GetStrict_mode(JSContext* cx, bool *aStrict_mode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStrict_mode(cx, aStrict_mode); } \
  NS_IMETHOD SetStrict_mode(JSContext* cx, bool aStrict_mode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStrict_mode(cx, aStrict_mode); } \
  NS_IMETHOD GetIon(JSContext* cx, bool *aIon) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIon(cx, aIon); } \
  NS_IMETHOD SetIon(JSContext* cx, bool aIon) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIon(cx, aIon); } \
  NS_IMETHOD SetGCZeal(int32_t zeal, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGCZeal(zeal, cx); } \
  NS_IMETHOD NukeSandbox(JS::HandleValue obj, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->NukeSandbox(obj, cx); } \
  NS_IMETHOD BlockScriptForGlobal(JS::HandleValue global, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BlockScriptForGlobal(global, cx); } \
  NS_IMETHOD UnblockScriptForGlobal(JS::HandleValue global, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnblockScriptForGlobal(global, cx); } \
  NS_IMETHOD IsXrayWrapper(JS::HandleValue obj, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsXrayWrapper(obj, _retval); } \
  NS_IMETHOD WaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->WaiveXrays(aVal, cx, _retval); } \
  NS_IMETHOD UnwaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->UnwaiveXrays(aVal, cx, _retval); } \
  NS_IMETHOD GetClassName(JS::HandleValue aObj, bool aUnwrap, JSContext* cx, char * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassName(aObj, aUnwrap, cx, _retval); } \
  NS_IMETHOD GetDOMClassInfo(const nsAString & aClassName, nsIClassInfo * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDOMClassInfo(aClassName, _retval); } \
  NS_IMETHOD GetIncumbentGlobal(JS::HandleValue callback, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIncumbentGlobal(callback, cx, _retval); } \
  NS_IMETHOD GenerateXPCWrappedJS(JS::HandleValue obj, JS::HandleValue scope, JSContext* cx, nsISupports * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateXPCWrappedJS(obj, scope, cx, _retval); } \
  NS_IMETHOD GetWatchdogTimestamp(const nsAString & aCategory, PRTime *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWatchdogTimestamp(aCategory, _retval); } \
  NS_IMETHOD GetJSEngineTelemetryValue(JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSEngineTelemetryValue(cx, _retval); } \
  NS_IMETHOD CloneInto(JS::HandleValue value, JS::HandleValue scope, JS::HandleValue options, JSContext* cx, JS::MutableHandleValue _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneInto(value, scope, options, cx, _retval); } \
  NS_IMETHOD GetWebIDLCallerPrincipal(nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWebIDLCallerPrincipal(_retval); } \
  NS_IMETHOD GetObjectPrincipal(JS::HandleValue obj, JSContext* cx, nsIPrincipal * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObjectPrincipal(obj, cx, _retval); } \
  NS_IMETHOD GetCompartmentLocation(JS::HandleValue obj, JSContext* cx, nsACString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompartmentLocation(obj, cx, _retval); } \
  NS_IMETHOD SetAddonInterposition(const nsACString & addonId, nsIAddonInterposition *interposition, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAddonInterposition(addonId, interposition, cx); } \
  NS_IMETHOD SetAddonCallInterposition(JS::HandleValue target, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAddonCallInterposition(target, cx); } \
  NS_IMETHOD Now(double *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Now(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents_Utils : public nsIXPCComponents_Utils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS_UTILS

  nsXPCComponents_Utils();

private:
  ~nsXPCComponents_Utils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents_Utils, nsIXPCComponents_Utils)

nsXPCComponents_Utils::nsXPCComponents_Utils()
{
  /* member initializers and constructor code */
}

nsXPCComponents_Utils::~nsXPCComponents_Utils()
{
  /* destructor code */
}

/* [implicit_jscontext] void reportError (in jsval error); */
NS_IMETHODIMP nsXPCComponents_Utils::ReportError(JS::HandleValue error, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_utils_Sandbox Sandbox; */
NS_IMETHODIMP nsXPCComponents_Utils::GetSandbox(nsIXPCComponents_utils_Sandbox * *aSandbox)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] jsval evalInSandbox (in AString source, in jsval sandbox, [optional] in jsval version, [optional] in AUTF8String filename, [optional] in long lineNo); */
NS_IMETHODIMP nsXPCComponents_Utils::EvalInSandbox(const nsAString & source, JS::HandleValue sandbox, JS::HandleValue version, const nsACString & filename, int32_t lineNo, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getSandboxAddonId (in jsval sandbox); */
NS_IMETHODIMP nsXPCComponents_Utils::GetSandboxAddonId(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getSandboxMetadata (in jsval sandbox); */
NS_IMETHODIMP nsXPCComponents_Utils::GetSandboxMetadata(JS::HandleValue sandbox, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setSandboxMetadata (in jsval sandbox, in jsval metadata); */
NS_IMETHODIMP nsXPCComponents_Utils::SetSandboxMetadata(JS::HandleValue sandbox, JS::HandleValue metadata, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] jsval import (in AUTF8String aResourceURI, [optional] in jsval targetObj); */
NS_IMETHODIMP nsXPCComponents_Utils::Import(const nsACString & aResourceURI, JS::HandleValue targetObj, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isModuleLoaded (in AUTF8String aResourceURI); */
NS_IMETHODIMP nsXPCComponents_Utils::IsModuleLoaded(const nsACString & aResourceURI, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unload (in AUTF8String registryLocation); */
NS_IMETHODIMP nsXPCComponents_Utils::Unload(const nsACString & registryLocation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void importGlobalProperties (in jsval aPropertyList); */
NS_IMETHODIMP nsXPCComponents_Utils::ImportGlobalProperties(JS::HandleValue aPropertyList, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] xpcIJSWeakReference getWeakReference (in jsval obj); */
NS_IMETHODIMP nsXPCComponents_Utils::GetWeakReference(JS::HandleValue obj, JSContext* cx, xpcIJSWeakReference * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceGC (); */
NS_IMETHODIMP nsXPCComponents_Utils::ForceGC()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceCC ([optional] in nsICycleCollectorListener aListener); */
NS_IMETHODIMP nsXPCComponents_Utils::ForceCC(nsICycleCollectorListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finishCC (); */
NS_IMETHODIMP nsXPCComponents_Utils::FinishCC()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ccSlice (in long long budget); */
NS_IMETHODIMP nsXPCComponents_Utils::CcSlice(int64_t budget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getMaxCCSliceTimeSinceClear (); */
NS_IMETHODIMP nsXPCComponents_Utils::GetMaxCCSliceTimeSinceClear(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearMaxCCTime (); */
NS_IMETHODIMP nsXPCComponents_Utils::ClearMaxCCTime()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceShrinkingGC (); */
NS_IMETHODIMP nsXPCComponents_Utils::ForceShrinkingGC()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void schedulePreciseGC (in ScheduledGCCallback callback); */
NS_IMETHODIMP nsXPCComponents_Utils::SchedulePreciseGC(ScheduledGCCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void schedulePreciseShrinkingGC (in ScheduledGCCallback callback); */
NS_IMETHODIMP nsXPCComponents_Utils::SchedulePreciseShrinkingGC(ScheduledGCCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlinkGhostWindows (); */
NS_IMETHODIMP nsXPCComponents_Utils::UnlinkGhostWindows()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval nondeterministicGetWeakMapKeys (in jsval aMap); */
NS_IMETHODIMP nsXPCComponents_Utils::NondeterministicGetWeakMapKeys(JS::HandleValue aMap, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getJSTestingFunctions (); */
NS_IMETHODIMP nsXPCComponents_Utils::GetJSTestingFunctions(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval callFunctionWithAsyncStack (in jsval function, in nsIStackFrame stack, in AString asyncCause); */
NS_IMETHODIMP nsXPCComponents_Utils::CallFunctionWithAsyncStack(JS::HandleValue function, nsIStackFrame *stack, const nsAString & asyncCause, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getGlobalForObject (in jsval obj); */
NS_IMETHODIMP nsXPCComponents_Utils::GetGlobalForObject(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] boolean isProxy (in jsval vobject); */
NS_IMETHODIMP nsXPCComponents_Utils::IsProxy(JS::HandleValue vobject, JSContext* cx, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval exportFunction (in jsval vfunction, in jsval vscope, [optional] in jsval voptions); */
NS_IMETHODIMP nsXPCComponents_Utils::ExportFunction(JS::HandleValue vfunction, JS::HandleValue vscope, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval createObjectIn (in jsval vobj, [optional] in jsval voptions); */
NS_IMETHODIMP nsXPCComponents_Utils::CreateObjectIn(JS::HandleValue vobj, JS::HandleValue voptions, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void makeObjectPropsNormal (in jsval vobj); */
NS_IMETHODIMP nsXPCComponents_Utils::MakeObjectPropsNormal(JS::HandleValue vobj, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isDeadWrapper (in jsval obj); */
NS_IMETHODIMP nsXPCComponents_Utils::IsDeadWrapper(JS::HandleValue obj, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isCrossProcessWrapper (in jsval obj); */
NS_IMETHODIMP nsXPCComponents_Utils::IsCrossProcessWrapper(JS::HandleValue obj, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getCrossProcessWrapperTag (in jsval obj); */
NS_IMETHODIMP nsXPCComponents_Utils::GetCrossProcessWrapperTag(JS::HandleValue obj, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void recomputeWrappers ([optional] in jsval vobj); */
NS_IMETHODIMP nsXPCComponents_Utils::RecomputeWrappers(JS::HandleValue vobj, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setWantXrays (in jsval vscope); */
NS_IMETHODIMP nsXPCComponents_Utils::SetWantXrays(JS::HandleValue vscope, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void forcePermissiveCOWs (); */
NS_IMETHODIMP nsXPCComponents_Utils::ForcePermissiveCOWs(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void skipCOWCallableChecks (); */
NS_IMETHODIMP nsXPCComponents_Utils::SkipCOWCallableChecks(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void forcePrivilegedComponentsForScope (in jsval vscope); */
NS_IMETHODIMP nsXPCComponents_Utils::ForcePrivilegedComponentsForScope(JS::HandleValue vscope, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getComponentsForScope (in jsval vscope); */
NS_IMETHODIMP nsXPCComponents_Utils::GetComponentsForScope(JS::HandleValue vscope, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void dispatch (in jsval runnable, [optional] in jsval scope); */
NS_IMETHODIMP nsXPCComponents_Utils::Dispatch(JS::HandleValue runnable, JS::HandleValue scope, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute boolean strict; */
NS_IMETHODIMP nsXPCComponents_Utils::GetStrict(JSContext* cx, bool *aStrict)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXPCComponents_Utils::SetStrict(JSContext* cx, bool aStrict)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute boolean werror; */
NS_IMETHODIMP nsXPCComponents_Utils::GetWerror(JSContext* cx, bool *aWerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXPCComponents_Utils::SetWerror(JSContext* cx, bool aWerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute boolean strict_mode; */
NS_IMETHODIMP nsXPCComponents_Utils::GetStrict_mode(JSContext* cx, bool *aStrict_mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXPCComponents_Utils::SetStrict_mode(JSContext* cx, bool aStrict_mode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute boolean ion; */
NS_IMETHODIMP nsXPCComponents_Utils::GetIon(JSContext* cx, bool *aIon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXPCComponents_Utils::SetIon(JSContext* cx, bool aIon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setGCZeal (in long zeal); */
NS_IMETHODIMP nsXPCComponents_Utils::SetGCZeal(int32_t zeal, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void nukeSandbox (in jsval obj); */
NS_IMETHODIMP nsXPCComponents_Utils::NukeSandbox(JS::HandleValue obj, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void blockScriptForGlobal (in jsval global); */
NS_IMETHODIMP nsXPCComponents_Utils::BlockScriptForGlobal(JS::HandleValue global, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void unblockScriptForGlobal (in jsval global); */
NS_IMETHODIMP nsXPCComponents_Utils::UnblockScriptForGlobal(JS::HandleValue global, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isXrayWrapper (in jsval obj); */
NS_IMETHODIMP nsXPCComponents_Utils::IsXrayWrapper(JS::HandleValue obj, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval waiveXrays (in jsval aVal); */
NS_IMETHODIMP nsXPCComponents_Utils::WaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval unwaiveXrays (in jsval aVal); */
NS_IMETHODIMP nsXPCComponents_Utils::UnwaiveXrays(JS::HandleValue aVal, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] string getClassName (in jsval aObj, in bool aUnwrap); */
NS_IMETHODIMP nsXPCComponents_Utils::GetClassName(JS::HandleValue aObj, bool aUnwrap, JSContext* cx, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIClassInfo getDOMClassInfo (in AString aClassName); */
NS_IMETHODIMP nsXPCComponents_Utils::GetDOMClassInfo(const nsAString & aClassName, nsIClassInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getIncumbentGlobal ([optional] in jsval callback); */
NS_IMETHODIMP nsXPCComponents_Utils::GetIncumbentGlobal(JS::HandleValue callback, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsISupports generateXPCWrappedJS (in jsval obj, [optional] in jsval scope); */
NS_IMETHODIMP nsXPCComponents_Utils::GenerateXPCWrappedJS(JS::HandleValue obj, JS::HandleValue scope, JSContext* cx, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRTime getWatchdogTimestamp (in AString aCategory); */
NS_IMETHODIMP nsXPCComponents_Utils::GetWatchdogTimestamp(const nsAString & aCategory, PRTime *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getJSEngineTelemetryValue (); */
NS_IMETHODIMP nsXPCComponents_Utils::GetJSEngineTelemetryValue(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval cloneInto (in jsval value, in jsval scope, [optional] in jsval options); */
NS_IMETHODIMP nsXPCComponents_Utils::CloneInto(JS::HandleValue value, JS::HandleValue scope, JS::HandleValue options, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPrincipal getWebIDLCallerPrincipal (); */
NS_IMETHODIMP nsXPCComponents_Utils::GetWebIDLCallerPrincipal(nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIPrincipal getObjectPrincipal (in jsval obj); */
NS_IMETHODIMP nsXPCComponents_Utils::GetObjectPrincipal(JS::HandleValue obj, JSContext* cx, nsIPrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] ACString getCompartmentLocation (in jsval obj); */
NS_IMETHODIMP nsXPCComponents_Utils::GetCompartmentLocation(JS::HandleValue obj, JSContext* cx, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setAddonInterposition (in ACString addonId, in nsIAddonInterposition interposition); */
NS_IMETHODIMP nsXPCComponents_Utils::SetAddonInterposition(const nsACString & addonId, nsIAddonInterposition *interposition, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setAddonCallInterposition (in jsval target); */
NS_IMETHODIMP nsXPCComponents_Utils::SetAddonCallInterposition(JS::HandleValue target, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double now (); */
NS_IMETHODIMP nsXPCComponents_Utils::Now(double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponentsBase */
#define NS_IXPCCOMPONENTSBASE_IID_STR "eeeada2f-86c0-4609-b2bf-4bf2351b1ce6"

#define NS_IXPCCOMPONENTSBASE_IID \
  {0xeeeada2f, 0x86c0, 0x4609, \
    { 0xb2, 0xbf, 0x4b, 0xf2, 0x35, 0x1b, 0x1c, 0xe6 }}

class NS_NO_VTABLE nsIXPCComponentsBase : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTSBASE_IID)

  /* readonly attribute nsIXPCComponents_Interfaces interfaces; */
  NS_IMETHOD GetInterfaces(nsIXPCComponents_Interfaces * *aInterfaces) = 0;

  /* readonly attribute nsIXPCComponents_InterfacesByID interfacesByID; */
  NS_IMETHOD GetInterfacesByID(nsIXPCComponents_InterfacesByID * *aInterfacesByID) = 0;

  /* readonly attribute nsIXPCComponents_Results results; */
  NS_IMETHOD GetResults(nsIXPCComponents_Results * *aResults) = 0;

  /* boolean isSuccessCode (in nsresult result); */
  NS_IMETHOD IsSuccessCode(nsresult result, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponentsBase, NS_IXPCCOMPONENTSBASE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTSBASE \
  NS_IMETHOD GetInterfaces(nsIXPCComponents_Interfaces * *aInterfaces) override; \
  NS_IMETHOD GetInterfacesByID(nsIXPCComponents_InterfacesByID * *aInterfacesByID) override; \
  NS_IMETHOD GetResults(nsIXPCComponents_Results * *aResults) override; \
  NS_IMETHOD IsSuccessCode(nsresult result, bool *_retval) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTSBASE(_to) \
  NS_IMETHOD GetInterfaces(nsIXPCComponents_Interfaces * *aInterfaces) override { return _to GetInterfaces(aInterfaces); } \
  NS_IMETHOD GetInterfacesByID(nsIXPCComponents_InterfacesByID * *aInterfacesByID) override { return _to GetInterfacesByID(aInterfacesByID); } \
  NS_IMETHOD GetResults(nsIXPCComponents_Results * *aResults) override { return _to GetResults(aResults); } \
  NS_IMETHOD IsSuccessCode(nsresult result, bool *_retval) override { return _to IsSuccessCode(result, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTSBASE(_to) \
  NS_IMETHOD GetInterfaces(nsIXPCComponents_Interfaces * *aInterfaces) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfaces(aInterfaces); } \
  NS_IMETHOD GetInterfacesByID(nsIXPCComponents_InterfacesByID * *aInterfacesByID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterfacesByID(aInterfacesByID); } \
  NS_IMETHOD GetResults(nsIXPCComponents_Results * *aResults) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResults(aResults); } \
  NS_IMETHOD IsSuccessCode(nsresult result, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSuccessCode(result, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponentsBase : public nsIXPCComponentsBase
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTSBASE

  nsXPCComponentsBase();

private:
  ~nsXPCComponentsBase();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponentsBase, nsIXPCComponentsBase)

nsXPCComponentsBase::nsXPCComponentsBase()
{
  /* member initializers and constructor code */
}

nsXPCComponentsBase::~nsXPCComponentsBase()
{
  /* destructor code */
}

/* readonly attribute nsIXPCComponents_Interfaces interfaces; */
NS_IMETHODIMP nsXPCComponentsBase::GetInterfaces(nsIXPCComponents_Interfaces * *aInterfaces)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_InterfacesByID interfacesByID; */
NS_IMETHODIMP nsXPCComponentsBase::GetInterfacesByID(nsIXPCComponents_InterfacesByID * *aInterfacesByID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_Results results; */
NS_IMETHODIMP nsXPCComponentsBase::GetResults(nsIXPCComponents_Results * *aResults)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSuccessCode (in nsresult result); */
NS_IMETHODIMP nsXPCComponentsBase::IsSuccessCode(nsresult result, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXPCComponents */
#define NS_IXPCCOMPONENTS_IID_STR "aa28aaf6-70ce-4b03-9514-afe43c7dfda8"

#define NS_IXPCCOMPONENTS_IID \
  {0xaa28aaf6, 0x70ce, 0x4b03, \
    { 0x95, 0x14, 0xaf, 0xe4, 0x3c, 0x7d, 0xfd, 0xa8 }}

class NS_NO_VTABLE nsIXPCComponents : public nsIXPCComponentsBase {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCCOMPONENTS_IID)

  /* readonly attribute nsIXPCComponents_Classes classes; */
  NS_IMETHOD GetClasses(nsIXPCComponents_Classes * *aClasses) = 0;

  /* readonly attribute nsIXPCComponents_ClassesByID classesByID; */
  NS_IMETHOD GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID) = 0;

  /* readonly attribute nsIStackFrame stack; */
  NS_IMETHOD GetStack(nsIStackFrame * *aStack) = 0;

  /* readonly attribute nsIComponentManager manager; */
  NS_IMETHOD GetManager(nsIComponentManager * *aManager) = 0;

  /* readonly attribute nsIXPCComponents_Utils utils; */
  NS_IMETHOD GetUtils(nsIXPCComponents_Utils * *aUtils) = 0;

  /* readonly attribute nsIXPCComponents_ID ID; */
  NS_IMETHOD GetID(nsIXPCComponents_ID * *aID) = 0;

  /* readonly attribute nsIXPCComponents_Exception Exception; */
  NS_IMETHOD GetException(nsIXPCComponents_Exception * *aException) = 0;

  /* readonly attribute nsIXPCComponents_Constructor Constructor; */
  NS_IMETHOD GetConstructor(nsIXPCComponents_Constructor * *aConstructor) = 0;

  /* [implicit_jscontext] readonly attribute jsval lastResult; */
  NS_IMETHOD GetLastResult(JSContext* cx, JS::MutableHandleValue aLastResult) = 0;

  /* [implicit_jscontext] attribute jsval returnCode; */
  NS_IMETHOD GetReturnCode(JSContext* cx, JS::MutableHandleValue aReturnCode) = 0;
  NS_IMETHOD SetReturnCode(JSContext* cx, JS::HandleValue aReturnCode) = 0;

  /* [deprecated,implicit_jscontext] void reportError (in jsval error); */
  NS_IMETHOD ReportError(JS::HandleValue error, JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCComponents, NS_IXPCCOMPONENTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCCOMPONENTS \
  NS_IMETHOD GetClasses(nsIXPCComponents_Classes * *aClasses) override; \
  NS_IMETHOD GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID) override; \
  NS_IMETHOD GetStack(nsIStackFrame * *aStack) override; \
  NS_IMETHOD GetManager(nsIComponentManager * *aManager) override; \
  NS_IMETHOD GetUtils(nsIXPCComponents_Utils * *aUtils) override; \
  NS_IMETHOD GetID(nsIXPCComponents_ID * *aID) override; \
  NS_IMETHOD GetException(nsIXPCComponents_Exception * *aException) override; \
  NS_IMETHOD GetConstructor(nsIXPCComponents_Constructor * *aConstructor) override; \
  NS_IMETHOD GetLastResult(JSContext* cx, JS::MutableHandleValue aLastResult) override; \
  NS_IMETHOD GetReturnCode(JSContext* cx, JS::MutableHandleValue aReturnCode) override; \
  NS_IMETHOD SetReturnCode(JSContext* cx, JS::HandleValue aReturnCode) override; \
  NS_IMETHOD ReportError(JS::HandleValue error, JSContext* cx) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCCOMPONENTS(_to) \
  NS_IMETHOD GetClasses(nsIXPCComponents_Classes * *aClasses) override { return _to GetClasses(aClasses); } \
  NS_IMETHOD GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID) override { return _to GetClassesByID(aClassesByID); } \
  NS_IMETHOD GetStack(nsIStackFrame * *aStack) override { return _to GetStack(aStack); } \
  NS_IMETHOD GetManager(nsIComponentManager * *aManager) override { return _to GetManager(aManager); } \
  NS_IMETHOD GetUtils(nsIXPCComponents_Utils * *aUtils) override { return _to GetUtils(aUtils); } \
  NS_IMETHOD GetID(nsIXPCComponents_ID * *aID) override { return _to GetID(aID); } \
  NS_IMETHOD GetException(nsIXPCComponents_Exception * *aException) override { return _to GetException(aException); } \
  NS_IMETHOD GetConstructor(nsIXPCComponents_Constructor * *aConstructor) override { return _to GetConstructor(aConstructor); } \
  NS_IMETHOD GetLastResult(JSContext* cx, JS::MutableHandleValue aLastResult) override { return _to GetLastResult(cx, aLastResult); } \
  NS_IMETHOD GetReturnCode(JSContext* cx, JS::MutableHandleValue aReturnCode) override { return _to GetReturnCode(cx, aReturnCode); } \
  NS_IMETHOD SetReturnCode(JSContext* cx, JS::HandleValue aReturnCode) override { return _to SetReturnCode(cx, aReturnCode); } \
  NS_IMETHOD ReportError(JS::HandleValue error, JSContext* cx) override { return _to ReportError(error, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCCOMPONENTS(_to) \
  NS_IMETHOD GetClasses(nsIXPCComponents_Classes * *aClasses) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClasses(aClasses); } \
  NS_IMETHOD GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassesByID(aClassesByID); } \
  NS_IMETHOD GetStack(nsIStackFrame * *aStack) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStack(aStack); } \
  NS_IMETHOD GetManager(nsIComponentManager * *aManager) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManager(aManager); } \
  NS_IMETHOD GetUtils(nsIXPCComponents_Utils * *aUtils) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUtils(aUtils); } \
  NS_IMETHOD GetID(nsIXPCComponents_ID * *aID) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetID(aID); } \
  NS_IMETHOD GetException(nsIXPCComponents_Exception * *aException) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetException(aException); } \
  NS_IMETHOD GetConstructor(nsIXPCComponents_Constructor * *aConstructor) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConstructor(aConstructor); } \
  NS_IMETHOD GetLastResult(JSContext* cx, JS::MutableHandleValue aLastResult) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastResult(cx, aLastResult); } \
  NS_IMETHOD GetReturnCode(JSContext* cx, JS::MutableHandleValue aReturnCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnCode(cx, aReturnCode); } \
  NS_IMETHOD SetReturnCode(JSContext* cx, JS::HandleValue aReturnCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReturnCode(cx, aReturnCode); } \
  NS_IMETHOD ReportError(JS::HandleValue error, JSContext* cx) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ReportError(error, cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCComponents : public nsIXPCComponents
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCCOMPONENTS

  nsXPCComponents();

private:
  ~nsXPCComponents();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsXPCComponents, nsIXPCComponents)

nsXPCComponents::nsXPCComponents()
{
  /* member initializers and constructor code */
}

nsXPCComponents::~nsXPCComponents()
{
  /* destructor code */
}

/* readonly attribute nsIXPCComponents_Classes classes; */
NS_IMETHODIMP nsXPCComponents::GetClasses(nsIXPCComponents_Classes * *aClasses)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_ClassesByID classesByID; */
NS_IMETHODIMP nsXPCComponents::GetClassesByID(nsIXPCComponents_ClassesByID * *aClassesByID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIStackFrame stack; */
NS_IMETHODIMP nsXPCComponents::GetStack(nsIStackFrame * *aStack)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIComponentManager manager; */
NS_IMETHODIMP nsXPCComponents::GetManager(nsIComponentManager * *aManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_Utils utils; */
NS_IMETHODIMP nsXPCComponents::GetUtils(nsIXPCComponents_Utils * *aUtils)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_ID ID; */
NS_IMETHODIMP nsXPCComponents::GetID(nsIXPCComponents_ID * *aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_Exception Exception; */
NS_IMETHODIMP nsXPCComponents::GetException(nsIXPCComponents_Exception * *aException)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCComponents_Constructor Constructor; */
NS_IMETHODIMP nsXPCComponents::GetConstructor(nsIXPCComponents_Constructor * *aConstructor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval lastResult; */
NS_IMETHODIMP nsXPCComponents::GetLastResult(JSContext* cx, JS::MutableHandleValue aLastResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval returnCode; */
NS_IMETHODIMP nsXPCComponents::GetReturnCode(JSContext* cx, JS::MutableHandleValue aReturnCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXPCComponents::SetReturnCode(JSContext* cx, JS::HandleValue aReturnCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [deprecated,implicit_jscontext] void reportError (in jsval error); */
NS_IMETHODIMP nsXPCComponents::ReportError(JS::HandleValue error, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_xpccomponents_h__ */
