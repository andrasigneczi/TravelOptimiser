/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIEditor.idl
 */

#ifndef __gen_nsIEditor_h__
#define __gen_nsIEditor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIAtom; /* forward declaration */

class nsIContent; /* forward declaration */

class nsISelection; /* forward declaration */

class nsISelectionController; /* forward declaration */

class nsIDocumentStateListener; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsITransactionManager; /* forward declaration */

class nsITransaction; /* forward declaration */

class nsIEditorObserver; /* forward declaration */

class nsIEditActionListener; /* forward declaration */

class nsIInlineSpellChecker; /* forward declaration */

class nsITransferable; /* forward declaration */


/* starting interface:    nsIEditor */
#define NS_IEDITOR_IID_STR "094be624-f0bf-400f-89e2-6a84baab9474"

#define NS_IEDITOR_IID \
  {0x094be624, 0xf0bf, 0x400f, \
    { 0x89, 0xe2, 0x6a, 0x84, 0xba, 0xab, 0x94, 0x74 }}

class nsIEditor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITOR_IID)

   typedef short EDirection;
  typedef short EStripWrappers;
  enum {
    eNone = 0,
    eNext = 1,
    ePrevious = 2,
    eNextWord = 3,
    ePreviousWord = 4,
    eToBeginningOfLine = 5,
    eToEndOfLine = 6,
    eStrip = 0,
    eNoStrip = 1
  };

  /* readonly attribute nsISelection selection; */
  NS_IMETHOD GetSelection(nsISelection * *aSelection) = 0;

  /* [noscript] void finalizeSelection (); */
  NS_IMETHOD FinalizeSelection(void) = 0;

  /* [noscript] void init (in nsIDOMDocument doc, in nsIContent aRoot, in nsISelectionController aSelCon, in unsigned long aFlags, in AString initialValue); */
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags, const nsAString & initialValue) = 0;

  /* void setAttributeOrEquivalent (in nsIDOMElement element, in AString sourceAttrName, in AString sourceAttrValue, in boolean aSuppressTransaction); */
  NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction) = 0;

  /* void removeAttributeOrEquivalent (in nsIDOMElement element, in DOMString sourceAttrName, in boolean aSuppressTransaction); */
  NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction) = 0;

  /* void postCreate (); */
  NS_IMETHOD PostCreate(void) = 0;

  /* void preDestroy (in boolean aDestroyingFrames); */
  NS_IMETHOD PreDestroy(bool aDestroyingFrames) = 0;

  /* attribute unsigned long flags; */
  NS_IMETHOD GetFlags(uint32_t *aFlags) = 0;
  NS_IMETHOD SetFlags(uint32_t aFlags) = 0;

  /* attribute string contentsMIMEType; */
  NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) = 0;
  NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) = 0;

  /* readonly attribute boolean isDocumentEditable; */
  NS_IMETHOD GetIsDocumentEditable(bool *aIsDocumentEditable) = 0;

  /* readonly attribute boolean isSelectionEditable; */
  NS_IMETHOD GetIsSelectionEditable(bool *aIsSelectionEditable) = 0;

  /* readonly attribute nsIDOMDocument document; */
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) = 0;

  /* readonly attribute nsIDOMElement rootElement; */
  NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) = 0;

  /* readonly attribute nsISelectionController selectionController; */
  NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) = 0;

  /* void deleteSelection (in short action, in short stripWrappers); */
  NS_IMETHOD DeleteSelection(int16_t action, int16_t stripWrappers) = 0;

  /* readonly attribute boolean documentIsEmpty; */
  NS_IMETHOD GetDocumentIsEmpty(bool *aDocumentIsEmpty) = 0;

  /* readonly attribute boolean documentModified; */
  NS_IMETHOD GetDocumentModified(bool *aDocumentModified) = 0;

  /* attribute ACString documentCharacterSet; */
  NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) = 0;
  NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) = 0;

  /* void resetModificationCount (); */
  NS_IMETHOD ResetModificationCount(void) = 0;

  /* long getModificationCount (); */
  NS_IMETHOD GetModificationCount(int32_t *_retval) = 0;

  /* void incrementModificationCount (in long aModCount); */
  NS_IMETHOD IncrementModificationCount(int32_t aModCount) = 0;

  /* attribute nsITransactionManager transactionManager; */
  NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) = 0;
  NS_IMETHOD SetTransactionManager(nsITransactionManager *aTransactionManager) = 0;

  /* void doTransaction (in nsITransaction txn); */
  NS_IMETHOD DoTransaction(nsITransaction *txn) = 0;

  /* void enableUndo (in boolean enable); */
  NS_IMETHOD EnableUndo(bool enable) = 0;

  /* readonly attribute long numberOfUndoItems; */
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) = 0;

  /* readonly attribute long numberOfRedoItems; */
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) = 0;

  /* void undo (in unsigned long count); */
  NS_IMETHOD Undo(uint32_t count) = 0;

  /* void canUndo (out boolean isEnabled, out boolean canUndo); */
  NS_IMETHOD CanUndo(bool *isEnabled, bool *canUndo) = 0;

  /* void redo (in unsigned long count); */
  NS_IMETHOD Redo(uint32_t count) = 0;

  /* void canRedo (out boolean isEnabled, out boolean canRedo); */
  NS_IMETHOD CanRedo(bool *isEnabled, bool *canRedo) = 0;

  /* void beginTransaction (); */
  NS_IMETHOD BeginTransaction(void) = 0;

  /* void endTransaction (); */
  NS_IMETHOD EndTransaction(void) = 0;

  /* void beginPlaceHolderTransaction (in nsIAtom name); */
  NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) = 0;

  /* void endPlaceHolderTransaction (); */
  NS_IMETHOD EndPlaceHolderTransaction(void) = 0;

  /* boolean shouldTxnSetSelection (); */
  NS_IMETHOD ShouldTxnSetSelection(bool *_retval) = 0;

  /* void setShouldTxnSetSelection (in boolean should); */
  NS_IMETHOD SetShouldTxnSetSelection(bool should) = 0;

  /* nsIInlineSpellChecker getInlineSpellChecker (in boolean autoCreate); */
  NS_IMETHOD GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval) = 0;

  /* void syncRealTimeSpell (); */
  NS_IMETHOD SyncRealTimeSpell(void) = 0;

  /* void setSpellcheckUserOverride (in boolean enable); */
  NS_IMETHOD SetSpellcheckUserOverride(bool enable) = 0;

  /* void cut (); */
  NS_IMETHOD Cut(void) = 0;

  /* boolean canCut (); */
  NS_IMETHOD CanCut(bool *_retval) = 0;

  /* void copy (); */
  NS_IMETHOD Copy(void) = 0;

  /* boolean canCopy (); */
  NS_IMETHOD CanCopy(bool *_retval) = 0;

  /* boolean canDelete (); */
  NS_IMETHOD CanDelete(bool *_retval) = 0;

  /* void paste (in long aSelectionType); */
  NS_IMETHOD Paste(int32_t aSelectionType) = 0;

  /* void pasteTransferable (in nsITransferable aTransferable); */
  NS_IMETHOD PasteTransferable(nsITransferable *aTransferable) = 0;

  /* boolean canPaste (in long aSelectionType); */
  NS_IMETHOD CanPaste(int32_t aSelectionType, bool *_retval) = 0;

  /* boolean canPasteTransferable ([optional] in nsITransferable aTransferable); */
  NS_IMETHOD CanPasteTransferable(nsITransferable *aTransferable, bool *_retval) = 0;

  /* void selectAll (); */
  NS_IMETHOD SelectAll(void) = 0;

  /* void beginningOfDocument (); */
  NS_IMETHOD BeginningOfDocument(void) = 0;

  /* void endOfDocument (); */
  NS_IMETHOD EndOfDocument(void) = 0;

  /* void setAttribute (in nsIDOMElement aElement, in AString attributestr, in AString attvalue); */
  NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) = 0;

  /* boolean getAttributeValue (in nsIDOMElement aElement, in AString attributestr, out AString resultValue); */
  NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval) = 0;

  /* void removeAttribute (in nsIDOMElement aElement, in AString aAttribute); */
  NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) = 0;

  /* void cloneAttribute (in AString aAttribute, in nsIDOMNode aDestNode, in nsIDOMNode aSourceNode); */
  NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) = 0;

  /* void cloneAttributes (in nsIDOMNode destNode, in nsIDOMNode sourceNode); */
  NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) = 0;

  /* nsIDOMNode createNode (in AString tag, in nsIDOMNode parent, in long position); */
  NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval) = 0;

  /* void insertNode (in nsIDOMNode node, in nsIDOMNode parent, in long aPosition); */
  NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition) = 0;

  /* void splitNode (in nsIDOMNode existingRightNode, in long offset, out nsIDOMNode newLeftNode); */
  NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode) = 0;

  /* void joinNodes (in nsIDOMNode leftNode, in nsIDOMNode rightNode, in nsIDOMNode parent); */
  NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) = 0;

  /* void deleteNode (in nsIDOMNode child); */
  NS_IMETHOD DeleteNode(nsIDOMNode *child) = 0;

  /* [notxpcom] boolean outputsMozDirty (); */
  NS_IMETHOD_(bool) OutputsMozDirty(void) = 0;

  /* void markNodeDirty (in nsIDOMNode node); */
  NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) = 0;

  /* void switchTextDirection (); */
  NS_IMETHOD SwitchTextDirection(void) = 0;

  /* AString outputToString (in AString formatType, in unsigned long flags); */
  NS_IMETHOD OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval) = 0;

  /* void outputToStream (in nsIOutputStream aStream, in AString formatType, in ACString charsetOverride, in unsigned long flags); */
  NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags) = 0;

  /* void addEditorObserver (in nsIEditorObserver observer); */
  NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) = 0;

  /* void removeEditorObserver (in nsIEditorObserver observer); */
  NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) = 0;

  /* void addEditActionListener (in nsIEditActionListener listener); */
  NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) = 0;

  /* void removeEditActionListener (in nsIEditActionListener listener); */
  NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) = 0;

  /* void addDocumentStateListener (in nsIDocumentStateListener listener); */
  NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) = 0;

  /* void removeDocumentStateListener (in nsIDocumentStateListener listener); */
  NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) = 0;

  /* void dumpContentTree (); */
  NS_IMETHOD DumpContentTree(void) = 0;

  /* void debugDumpContent (); */
  NS_IMETHOD DebugDumpContent(void) = 0;

  /* void debugUnitTests (out long outNumTests, out long outNumTestsFailed); */
  NS_IMETHOD DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed) = 0;

  /* [notxpcom] boolean isModifiableNode (in nsIDOMNode aNode); */
  NS_IMETHOD_(bool) IsModifiableNode(nsIDOMNode *aNode) = 0;

  /* attribute boolean suppressDispatchingInputEvent; */
  NS_IMETHOD GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent) = 0;
  NS_IMETHOD SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent) = 0;

  /* [noscript] readonly attribute boolean isInEditAction; */
  NS_IMETHOD GetIsInEditAction(bool *aIsInEditAction) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditor, NS_IEDITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITOR \
  NS_IMETHOD GetSelection(nsISelection * *aSelection) override; \
  NS_IMETHOD FinalizeSelection(void) override; \
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags, const nsAString & initialValue) override; \
  NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction) override; \
  NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction) override; \
  NS_IMETHOD PostCreate(void) override; \
  NS_IMETHOD PreDestroy(bool aDestroyingFrames) override; \
  NS_IMETHOD GetFlags(uint32_t *aFlags) override; \
  NS_IMETHOD SetFlags(uint32_t aFlags) override; \
  NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) override; \
  NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) override; \
  NS_IMETHOD GetIsDocumentEditable(bool *aIsDocumentEditable) override; \
  NS_IMETHOD GetIsSelectionEditable(bool *aIsSelectionEditable) override; \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override; \
  NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) override; \
  NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) override; \
  NS_IMETHOD DeleteSelection(int16_t action, int16_t stripWrappers) override; \
  NS_IMETHOD GetDocumentIsEmpty(bool *aDocumentIsEmpty) override; \
  NS_IMETHOD GetDocumentModified(bool *aDocumentModified) override; \
  NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) override; \
  NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) override; \
  NS_IMETHOD ResetModificationCount(void) override; \
  NS_IMETHOD GetModificationCount(int32_t *_retval) override; \
  NS_IMETHOD IncrementModificationCount(int32_t aModCount) override; \
  NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) override; \
  NS_IMETHOD SetTransactionManager(nsITransactionManager *aTransactionManager) override; \
  NS_IMETHOD DoTransaction(nsITransaction *txn) override; \
  NS_IMETHOD EnableUndo(bool enable) override; \
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) override; \
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) override; \
  NS_IMETHOD Undo(uint32_t count) override; \
  NS_IMETHOD CanUndo(bool *isEnabled, bool *canUndo) override; \
  NS_IMETHOD Redo(uint32_t count) override; \
  NS_IMETHOD CanRedo(bool *isEnabled, bool *canRedo) override; \
  NS_IMETHOD BeginTransaction(void) override; \
  NS_IMETHOD EndTransaction(void) override; \
  NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) override; \
  NS_IMETHOD EndPlaceHolderTransaction(void) override; \
  NS_IMETHOD ShouldTxnSetSelection(bool *_retval) override; \
  NS_IMETHOD SetShouldTxnSetSelection(bool should) override; \
  NS_IMETHOD GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval) override; \
  NS_IMETHOD SyncRealTimeSpell(void) override; \
  NS_IMETHOD SetSpellcheckUserOverride(bool enable) override; \
  NS_IMETHOD Cut(void) override; \
  NS_IMETHOD CanCut(bool *_retval) override; \
  NS_IMETHOD Copy(void) override; \
  NS_IMETHOD CanCopy(bool *_retval) override; \
  NS_IMETHOD CanDelete(bool *_retval) override; \
  NS_IMETHOD Paste(int32_t aSelectionType) override; \
  NS_IMETHOD PasteTransferable(nsITransferable *aTransferable) override; \
  NS_IMETHOD CanPaste(int32_t aSelectionType, bool *_retval) override; \
  NS_IMETHOD CanPasteTransferable(nsITransferable *aTransferable, bool *_retval) override; \
  NS_IMETHOD SelectAll(void) override; \
  NS_IMETHOD BeginningOfDocument(void) override; \
  NS_IMETHOD EndOfDocument(void) override; \
  NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) override; \
  NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval) override; \
  NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) override; \
  NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) override; \
  NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) override; \
  NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval) override; \
  NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition) override; \
  NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode) override; \
  NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) override; \
  NS_IMETHOD DeleteNode(nsIDOMNode *child) override; \
  NS_IMETHOD_(bool) OutputsMozDirty(void) override; \
  NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) override; \
  NS_IMETHOD SwitchTextDirection(void) override; \
  NS_IMETHOD OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval) override; \
  NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags) override; \
  NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) override; \
  NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) override; \
  NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) override; \
  NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) override; \
  NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) override; \
  NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) override; \
  NS_IMETHOD DumpContentTree(void) override; \
  NS_IMETHOD DebugDumpContent(void) override; \
  NS_IMETHOD DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed) override; \
  NS_IMETHOD_(bool) IsModifiableNode(nsIDOMNode *aNode) override; \
  NS_IMETHOD GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent) override; \
  NS_IMETHOD SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent) override; \
  NS_IMETHOD GetIsInEditAction(bool *aIsInEditAction) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITOR(_to) \
  NS_IMETHOD GetSelection(nsISelection * *aSelection) override { return _to GetSelection(aSelection); } \
  NS_IMETHOD FinalizeSelection(void) override { return _to FinalizeSelection(); } \
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags, const nsAString & initialValue) override { return _to Init(doc, aRoot, aSelCon, aFlags, initialValue); } \
  NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction) override { return _to SetAttributeOrEquivalent(element, sourceAttrName, sourceAttrValue, aSuppressTransaction); } \
  NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction) override { return _to RemoveAttributeOrEquivalent(element, sourceAttrName, aSuppressTransaction); } \
  NS_IMETHOD PostCreate(void) override { return _to PostCreate(); } \
  NS_IMETHOD PreDestroy(bool aDestroyingFrames) override { return _to PreDestroy(aDestroyingFrames); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) override { return _to GetFlags(aFlags); } \
  NS_IMETHOD SetFlags(uint32_t aFlags) override { return _to SetFlags(aFlags); } \
  NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) override { return _to GetContentsMIMEType(aContentsMIMEType); } \
  NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) override { return _to SetContentsMIMEType(aContentsMIMEType); } \
  NS_IMETHOD GetIsDocumentEditable(bool *aIsDocumentEditable) override { return _to GetIsDocumentEditable(aIsDocumentEditable); } \
  NS_IMETHOD GetIsSelectionEditable(bool *aIsSelectionEditable) override { return _to GetIsSelectionEditable(aIsSelectionEditable); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override { return _to GetDocument(aDocument); } \
  NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) override { return _to GetRootElement(aRootElement); } \
  NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) override { return _to GetSelectionController(aSelectionController); } \
  NS_IMETHOD DeleteSelection(int16_t action, int16_t stripWrappers) override { return _to DeleteSelection(action, stripWrappers); } \
  NS_IMETHOD GetDocumentIsEmpty(bool *aDocumentIsEmpty) override { return _to GetDocumentIsEmpty(aDocumentIsEmpty); } \
  NS_IMETHOD GetDocumentModified(bool *aDocumentModified) override { return _to GetDocumentModified(aDocumentModified); } \
  NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) override { return _to GetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) override { return _to SetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_IMETHOD ResetModificationCount(void) override { return _to ResetModificationCount(); } \
  NS_IMETHOD GetModificationCount(int32_t *_retval) override { return _to GetModificationCount(_retval); } \
  NS_IMETHOD IncrementModificationCount(int32_t aModCount) override { return _to IncrementModificationCount(aModCount); } \
  NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) override { return _to GetTransactionManager(aTransactionManager); } \
  NS_IMETHOD SetTransactionManager(nsITransactionManager *aTransactionManager) override { return _to SetTransactionManager(aTransactionManager); } \
  NS_IMETHOD DoTransaction(nsITransaction *txn) override { return _to DoTransaction(txn); } \
  NS_IMETHOD EnableUndo(bool enable) override { return _to EnableUndo(enable); } \
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) override { return _to GetNumberOfUndoItems(aNumberOfUndoItems); } \
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) override { return _to GetNumberOfRedoItems(aNumberOfRedoItems); } \
  NS_IMETHOD Undo(uint32_t count) override { return _to Undo(count); } \
  NS_IMETHOD CanUndo(bool *isEnabled, bool *canUndo) override { return _to CanUndo(isEnabled, canUndo); } \
  NS_IMETHOD Redo(uint32_t count) override { return _to Redo(count); } \
  NS_IMETHOD CanRedo(bool *isEnabled, bool *canRedo) override { return _to CanRedo(isEnabled, canRedo); } \
  NS_IMETHOD BeginTransaction(void) override { return _to BeginTransaction(); } \
  NS_IMETHOD EndTransaction(void) override { return _to EndTransaction(); } \
  NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) override { return _to BeginPlaceHolderTransaction(name); } \
  NS_IMETHOD EndPlaceHolderTransaction(void) override { return _to EndPlaceHolderTransaction(); } \
  NS_IMETHOD ShouldTxnSetSelection(bool *_retval) override { return _to ShouldTxnSetSelection(_retval); } \
  NS_IMETHOD SetShouldTxnSetSelection(bool should) override { return _to SetShouldTxnSetSelection(should); } \
  NS_IMETHOD GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval) override { return _to GetInlineSpellChecker(autoCreate, _retval); } \
  NS_IMETHOD SyncRealTimeSpell(void) override { return _to SyncRealTimeSpell(); } \
  NS_IMETHOD SetSpellcheckUserOverride(bool enable) override { return _to SetSpellcheckUserOverride(enable); } \
  NS_IMETHOD Cut(void) override { return _to Cut(); } \
  NS_IMETHOD CanCut(bool *_retval) override { return _to CanCut(_retval); } \
  NS_IMETHOD Copy(void) override { return _to Copy(); } \
  NS_IMETHOD CanCopy(bool *_retval) override { return _to CanCopy(_retval); } \
  NS_IMETHOD CanDelete(bool *_retval) override { return _to CanDelete(_retval); } \
  NS_IMETHOD Paste(int32_t aSelectionType) override { return _to Paste(aSelectionType); } \
  NS_IMETHOD PasteTransferable(nsITransferable *aTransferable) override { return _to PasteTransferable(aTransferable); } \
  NS_IMETHOD CanPaste(int32_t aSelectionType, bool *_retval) override { return _to CanPaste(aSelectionType, _retval); } \
  NS_IMETHOD CanPasteTransferable(nsITransferable *aTransferable, bool *_retval) override { return _to CanPasteTransferable(aTransferable, _retval); } \
  NS_IMETHOD SelectAll(void) override { return _to SelectAll(); } \
  NS_IMETHOD BeginningOfDocument(void) override { return _to BeginningOfDocument(); } \
  NS_IMETHOD EndOfDocument(void) override { return _to EndOfDocument(); } \
  NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) override { return _to SetAttribute(aElement, attributestr, attvalue); } \
  NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval) override { return _to GetAttributeValue(aElement, attributestr, resultValue, _retval); } \
  NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) override { return _to RemoveAttribute(aElement, aAttribute); } \
  NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) override { return _to CloneAttribute(aAttribute, aDestNode, aSourceNode); } \
  NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) override { return _to CloneAttributes(destNode, sourceNode); } \
  NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval) override { return _to CreateNode(tag, parent, position, _retval); } \
  NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition) override { return _to InsertNode(node, parent, aPosition); } \
  NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode) override { return _to SplitNode(existingRightNode, offset, newLeftNode); } \
  NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) override { return _to JoinNodes(leftNode, rightNode, parent); } \
  NS_IMETHOD DeleteNode(nsIDOMNode *child) override { return _to DeleteNode(child); } \
  NS_IMETHOD_(bool) OutputsMozDirty(void) override { return _to OutputsMozDirty(); } \
  NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) override { return _to MarkNodeDirty(node); } \
  NS_IMETHOD SwitchTextDirection(void) override { return _to SwitchTextDirection(); } \
  NS_IMETHOD OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval) override { return _to OutputToString(formatType, flags, _retval); } \
  NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags) override { return _to OutputToStream(aStream, formatType, charsetOverride, flags); } \
  NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) override { return _to AddEditorObserver(observer); } \
  NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) override { return _to RemoveEditorObserver(observer); } \
  NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) override { return _to AddEditActionListener(listener); } \
  NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) override { return _to RemoveEditActionListener(listener); } \
  NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) override { return _to AddDocumentStateListener(listener); } \
  NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) override { return _to RemoveDocumentStateListener(listener); } \
  NS_IMETHOD DumpContentTree(void) override { return _to DumpContentTree(); } \
  NS_IMETHOD DebugDumpContent(void) override { return _to DebugDumpContent(); } \
  NS_IMETHOD DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed) override { return _to DebugUnitTests(outNumTests, outNumTestsFailed); } \
  NS_IMETHOD_(bool) IsModifiableNode(nsIDOMNode *aNode) override { return _to IsModifiableNode(aNode); } \
  NS_IMETHOD GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent) override { return _to GetSuppressDispatchingInputEvent(aSuppressDispatchingInputEvent); } \
  NS_IMETHOD SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent) override { return _to SetSuppressDispatchingInputEvent(aSuppressDispatchingInputEvent); } \
  NS_IMETHOD GetIsInEditAction(bool *aIsInEditAction) override { return _to GetIsInEditAction(aIsInEditAction); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITOR(_to) \
  NS_IMETHOD GetSelection(nsISelection * *aSelection) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(aSelection); } \
  NS_IMETHOD FinalizeSelection(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->FinalizeSelection(); } \
  NS_IMETHOD Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags, const nsAString & initialValue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(doc, aRoot, aSelCon, aFlags, initialValue); } \
  NS_IMETHOD SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttributeOrEquivalent(element, sourceAttrName, sourceAttrValue, aSuppressTransaction); } \
  NS_IMETHOD RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttributeOrEquivalent(element, sourceAttrName, aSuppressTransaction); } \
  NS_IMETHOD PostCreate(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PostCreate(); } \
  NS_IMETHOD PreDestroy(bool aDestroyingFrames) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PreDestroy(aDestroyingFrames); } \
  NS_IMETHOD GetFlags(uint32_t *aFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_IMETHOD SetFlags(uint32_t aFlags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFlags(aFlags); } \
  NS_IMETHOD GetContentsMIMEType(char * *aContentsMIMEType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentsMIMEType(aContentsMIMEType); } \
  NS_IMETHOD SetContentsMIMEType(const char * aContentsMIMEType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentsMIMEType(aContentsMIMEType); } \
  NS_IMETHOD GetIsDocumentEditable(bool *aIsDocumentEditable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDocumentEditable(aIsDocumentEditable); } \
  NS_IMETHOD GetIsSelectionEditable(bool *aIsSelectionEditable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSelectionEditable(aIsSelectionEditable); } \
  NS_IMETHOD GetDocument(nsIDOMDocument * *aDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_IMETHOD GetRootElement(nsIDOMElement * *aRootElement) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootElement(aRootElement); } \
  NS_IMETHOD GetSelectionController(nsISelectionController * *aSelectionController) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectionController(aSelectionController); } \
  NS_IMETHOD DeleteSelection(int16_t action, int16_t stripWrappers) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteSelection(action, stripWrappers); } \
  NS_IMETHOD GetDocumentIsEmpty(bool *aDocumentIsEmpty) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentIsEmpty(aDocumentIsEmpty); } \
  NS_IMETHOD GetDocumentModified(bool *aDocumentModified) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentModified(aDocumentModified); } \
  NS_IMETHOD GetDocumentCharacterSet(nsACString & aDocumentCharacterSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_IMETHOD SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentCharacterSet(aDocumentCharacterSet); } \
  NS_IMETHOD ResetModificationCount(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetModificationCount(); } \
  NS_IMETHOD GetModificationCount(int32_t *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetModificationCount(_retval); } \
  NS_IMETHOD IncrementModificationCount(int32_t aModCount) override { return !_to ? NS_ERROR_NULL_POINTER : _to->IncrementModificationCount(aModCount); } \
  NS_IMETHOD GetTransactionManager(nsITransactionManager * *aTransactionManager) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransactionManager(aTransactionManager); } \
  NS_IMETHOD SetTransactionManager(nsITransactionManager *aTransactionManager) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTransactionManager(aTransactionManager); } \
  NS_IMETHOD DoTransaction(nsITransaction *txn) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DoTransaction(txn); } \
  NS_IMETHOD EnableUndo(bool enable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableUndo(enable); } \
  NS_IMETHOD GetNumberOfUndoItems(int32_t *aNumberOfUndoItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfUndoItems(aNumberOfUndoItems); } \
  NS_IMETHOD GetNumberOfRedoItems(int32_t *aNumberOfRedoItems) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfRedoItems(aNumberOfRedoItems); } \
  NS_IMETHOD Undo(uint32_t count) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Undo(count); } \
  NS_IMETHOD CanUndo(bool *isEnabled, bool *canUndo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanUndo(isEnabled, canUndo); } \
  NS_IMETHOD Redo(uint32_t count) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Redo(count); } \
  NS_IMETHOD CanRedo(bool *isEnabled, bool *canRedo) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanRedo(isEnabled, canRedo); } \
  NS_IMETHOD BeginTransaction(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginTransaction(); } \
  NS_IMETHOD EndTransaction(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EndTransaction(); } \
  NS_IMETHOD BeginPlaceHolderTransaction(nsIAtom *name) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginPlaceHolderTransaction(name); } \
  NS_IMETHOD EndPlaceHolderTransaction(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EndPlaceHolderTransaction(); } \
  NS_IMETHOD ShouldTxnSetSelection(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldTxnSetSelection(_retval); } \
  NS_IMETHOD SetShouldTxnSetSelection(bool should) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetShouldTxnSetSelection(should); } \
  NS_IMETHOD GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInlineSpellChecker(autoCreate, _retval); } \
  NS_IMETHOD SyncRealTimeSpell(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SyncRealTimeSpell(); } \
  NS_IMETHOD SetSpellcheckUserOverride(bool enable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpellcheckUserOverride(enable); } \
  NS_IMETHOD Cut(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Cut(); } \
  NS_IMETHOD CanCut(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCut(_retval); } \
  NS_IMETHOD Copy(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Copy(); } \
  NS_IMETHOD CanCopy(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanCopy(_retval); } \
  NS_IMETHOD CanDelete(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanDelete(_retval); } \
  NS_IMETHOD Paste(int32_t aSelectionType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->Paste(aSelectionType); } \
  NS_IMETHOD PasteTransferable(nsITransferable *aTransferable) override { return !_to ? NS_ERROR_NULL_POINTER : _to->PasteTransferable(aTransferable); } \
  NS_IMETHOD CanPaste(int32_t aSelectionType, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPaste(aSelectionType, _retval); } \
  NS_IMETHOD CanPasteTransferable(nsITransferable *aTransferable, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPasteTransferable(aTransferable, _retval); } \
  NS_IMETHOD SelectAll(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_IMETHOD BeginningOfDocument(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginningOfDocument(); } \
  NS_IMETHOD EndOfDocument(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->EndOfDocument(); } \
  NS_IMETHOD SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAttribute(aElement, attributestr, attvalue); } \
  NS_IMETHOD GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttributeValue(aElement, attributestr, resultValue, _retval); } \
  NS_IMETHOD RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAttribute(aElement, aAttribute); } \
  NS_IMETHOD CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneAttribute(aAttribute, aDestNode, aSourceNode); } \
  NS_IMETHOD CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneAttributes(destNode, sourceNode); } \
  NS_IMETHOD CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateNode(tag, parent, position, _retval); } \
  NS_IMETHOD InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition) override { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertNode(node, parent, aPosition); } \
  NS_IMETHOD SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SplitNode(existingRightNode, offset, newLeftNode); } \
  NS_IMETHOD JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->JoinNodes(leftNode, rightNode, parent); } \
  NS_IMETHOD DeleteNode(nsIDOMNode *child) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteNode(child); } \
  NS_IMETHOD_(bool) OutputsMozDirty(void) override; \
  NS_IMETHOD MarkNodeDirty(nsIDOMNode *node) override { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkNodeDirty(node); } \
  NS_IMETHOD SwitchTextDirection(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SwitchTextDirection(); } \
  NS_IMETHOD OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OutputToString(formatType, flags, _retval); } \
  NS_IMETHOD OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags) override { return !_to ? NS_ERROR_NULL_POINTER : _to->OutputToStream(aStream, formatType, charsetOverride, flags); } \
  NS_IMETHOD AddEditorObserver(nsIEditorObserver *observer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEditorObserver(observer); } \
  NS_IMETHOD RemoveEditorObserver(nsIEditorObserver *observer) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEditorObserver(observer); } \
  NS_IMETHOD AddEditActionListener(nsIEditActionListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEditActionListener(listener); } \
  NS_IMETHOD RemoveEditActionListener(nsIEditActionListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEditActionListener(listener); } \
  NS_IMETHOD AddDocumentStateListener(nsIDocumentStateListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDocumentStateListener(listener); } \
  NS_IMETHOD RemoveDocumentStateListener(nsIDocumentStateListener *listener) override { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDocumentStateListener(listener); } \
  NS_IMETHOD DumpContentTree(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpContentTree(); } \
  NS_IMETHOD DebugDumpContent(void) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugDumpContent(); } \
  NS_IMETHOD DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed) override { return !_to ? NS_ERROR_NULL_POINTER : _to->DebugUnitTests(outNumTests, outNumTestsFailed); } \
  NS_IMETHOD_(bool) IsModifiableNode(nsIDOMNode *aNode) override; \
  NS_IMETHOD GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuppressDispatchingInputEvent(aSuppressDispatchingInputEvent); } \
  NS_IMETHOD SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSuppressDispatchingInputEvent(aSuppressDispatchingInputEvent); } \
  NS_IMETHOD GetIsInEditAction(bool *aIsInEditAction) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInEditAction(aIsInEditAction); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditor : public nsIEditor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITOR

  nsEditor();

private:
  ~nsEditor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsEditor, nsIEditor)

nsEditor::nsEditor()
{
  /* member initializers and constructor code */
}

nsEditor::~nsEditor()
{
  /* destructor code */
}

/* readonly attribute nsISelection selection; */
NS_IMETHODIMP nsEditor::GetSelection(nsISelection * *aSelection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void finalizeSelection (); */
NS_IMETHODIMP nsEditor::FinalizeSelection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIDOMDocument doc, in nsIContent aRoot, in nsISelectionController aSelCon, in unsigned long aFlags, in AString initialValue); */
NS_IMETHODIMP nsEditor::Init(nsIDOMDocument *doc, nsIContent *aRoot, nsISelectionController *aSelCon, uint32_t aFlags, const nsAString & initialValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttributeOrEquivalent (in nsIDOMElement element, in AString sourceAttrName, in AString sourceAttrValue, in boolean aSuppressTransaction); */
NS_IMETHODIMP nsEditor::SetAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, const nsAString & sourceAttrValue, bool aSuppressTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttributeOrEquivalent (in nsIDOMElement element, in DOMString sourceAttrName, in boolean aSuppressTransaction); */
NS_IMETHODIMP nsEditor::RemoveAttributeOrEquivalent(nsIDOMElement *element, const nsAString & sourceAttrName, bool aSuppressTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void postCreate (); */
NS_IMETHODIMP nsEditor::PostCreate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void preDestroy (in boolean aDestroyingFrames); */
NS_IMETHODIMP nsEditor::PreDestroy(bool aDestroyingFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long flags; */
NS_IMETHODIMP nsEditor::GetFlags(uint32_t *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetFlags(uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string contentsMIMEType; */
NS_IMETHODIMP nsEditor::GetContentsMIMEType(char * *aContentsMIMEType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetContentsMIMEType(const char * aContentsMIMEType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDocumentEditable; */
NS_IMETHODIMP nsEditor::GetIsDocumentEditable(bool *aIsDocumentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSelectionEditable; */
NS_IMETHODIMP nsEditor::GetIsSelectionEditable(bool *aIsSelectionEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument document; */
NS_IMETHODIMP nsEditor::GetDocument(nsIDOMDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement rootElement; */
NS_IMETHODIMP nsEditor::GetRootElement(nsIDOMElement * *aRootElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISelectionController selectionController; */
NS_IMETHODIMP nsEditor::GetSelectionController(nsISelectionController * *aSelectionController)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteSelection (in short action, in short stripWrappers); */
NS_IMETHODIMP nsEditor::DeleteSelection(int16_t action, int16_t stripWrappers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean documentIsEmpty; */
NS_IMETHODIMP nsEditor::GetDocumentIsEmpty(bool *aDocumentIsEmpty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean documentModified; */
NS_IMETHODIMP nsEditor::GetDocumentModified(bool *aDocumentModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString documentCharacterSet; */
NS_IMETHODIMP nsEditor::GetDocumentCharacterSet(nsACString & aDocumentCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetDocumentCharacterSet(const nsACString & aDocumentCharacterSet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetModificationCount (); */
NS_IMETHODIMP nsEditor::ResetModificationCount()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getModificationCount (); */
NS_IMETHODIMP nsEditor::GetModificationCount(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void incrementModificationCount (in long aModCount); */
NS_IMETHODIMP nsEditor::IncrementModificationCount(int32_t aModCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsITransactionManager transactionManager; */
NS_IMETHODIMP nsEditor::GetTransactionManager(nsITransactionManager * *aTransactionManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetTransactionManager(nsITransactionManager *aTransactionManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void doTransaction (in nsITransaction txn); */
NS_IMETHODIMP nsEditor::DoTransaction(nsITransaction *txn)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableUndo (in boolean enable); */
NS_IMETHODIMP nsEditor::EnableUndo(bool enable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numberOfUndoItems; */
NS_IMETHODIMP nsEditor::GetNumberOfUndoItems(int32_t *aNumberOfUndoItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long numberOfRedoItems; */
NS_IMETHODIMP nsEditor::GetNumberOfRedoItems(int32_t *aNumberOfRedoItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undo (in unsigned long count); */
NS_IMETHODIMP nsEditor::Undo(uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void canUndo (out boolean isEnabled, out boolean canUndo); */
NS_IMETHODIMP nsEditor::CanUndo(bool *isEnabled, bool *canUndo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void redo (in unsigned long count); */
NS_IMETHODIMP nsEditor::Redo(uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void canRedo (out boolean isEnabled, out boolean canRedo); */
NS_IMETHODIMP nsEditor::CanRedo(bool *isEnabled, bool *canRedo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginTransaction (); */
NS_IMETHODIMP nsEditor::BeginTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endTransaction (); */
NS_IMETHODIMP nsEditor::EndTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginPlaceHolderTransaction (in nsIAtom name); */
NS_IMETHODIMP nsEditor::BeginPlaceHolderTransaction(nsIAtom *name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endPlaceHolderTransaction (); */
NS_IMETHODIMP nsEditor::EndPlaceHolderTransaction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean shouldTxnSetSelection (); */
NS_IMETHODIMP nsEditor::ShouldTxnSetSelection(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setShouldTxnSetSelection (in boolean should); */
NS_IMETHODIMP nsEditor::SetShouldTxnSetSelection(bool should)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInlineSpellChecker getInlineSpellChecker (in boolean autoCreate); */
NS_IMETHODIMP nsEditor::GetInlineSpellChecker(bool autoCreate, nsIInlineSpellChecker * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void syncRealTimeSpell (); */
NS_IMETHODIMP nsEditor::SyncRealTimeSpell()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setSpellcheckUserOverride (in boolean enable); */
NS_IMETHODIMP nsEditor::SetSpellcheckUserOverride(bool enable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cut (); */
NS_IMETHODIMP nsEditor::Cut()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCut (); */
NS_IMETHODIMP nsEditor::CanCut(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copy (); */
NS_IMETHODIMP nsEditor::Copy()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canCopy (); */
NS_IMETHODIMP nsEditor::CanCopy(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canDelete (); */
NS_IMETHODIMP nsEditor::CanDelete(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void paste (in long aSelectionType); */
NS_IMETHODIMP nsEditor::Paste(int32_t aSelectionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pasteTransferable (in nsITransferable aTransferable); */
NS_IMETHODIMP nsEditor::PasteTransferable(nsITransferable *aTransferable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canPaste (in long aSelectionType); */
NS_IMETHODIMP nsEditor::CanPaste(int32_t aSelectionType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canPasteTransferable ([optional] in nsITransferable aTransferable); */
NS_IMETHODIMP nsEditor::CanPasteTransferable(nsITransferable *aTransferable, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsEditor::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginningOfDocument (); */
NS_IMETHODIMP nsEditor::BeginningOfDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endOfDocument (); */
NS_IMETHODIMP nsEditor::EndOfDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAttribute (in nsIDOMElement aElement, in AString attributestr, in AString attvalue); */
NS_IMETHODIMP nsEditor::SetAttribute(nsIDOMElement *aElement, const nsAString & attributestr, const nsAString & attvalue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getAttributeValue (in nsIDOMElement aElement, in AString attributestr, out AString resultValue); */
NS_IMETHODIMP nsEditor::GetAttributeValue(nsIDOMElement *aElement, const nsAString & attributestr, nsAString & resultValue, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAttribute (in nsIDOMElement aElement, in AString aAttribute); */
NS_IMETHODIMP nsEditor::RemoveAttribute(nsIDOMElement *aElement, const nsAString & aAttribute)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cloneAttribute (in AString aAttribute, in nsIDOMNode aDestNode, in nsIDOMNode aSourceNode); */
NS_IMETHODIMP nsEditor::CloneAttribute(const nsAString & aAttribute, nsIDOMNode *aDestNode, nsIDOMNode *aSourceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cloneAttributes (in nsIDOMNode destNode, in nsIDOMNode sourceNode); */
NS_IMETHODIMP nsEditor::CloneAttributes(nsIDOMNode *destNode, nsIDOMNode *sourceNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode createNode (in AString tag, in nsIDOMNode parent, in long position); */
NS_IMETHODIMP nsEditor::CreateNode(const nsAString & tag, nsIDOMNode *parent, int32_t position, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertNode (in nsIDOMNode node, in nsIDOMNode parent, in long aPosition); */
NS_IMETHODIMP nsEditor::InsertNode(nsIDOMNode *node, nsIDOMNode *parent, int32_t aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void splitNode (in nsIDOMNode existingRightNode, in long offset, out nsIDOMNode newLeftNode); */
NS_IMETHODIMP nsEditor::SplitNode(nsIDOMNode *existingRightNode, int32_t offset, nsIDOMNode * *newLeftNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void joinNodes (in nsIDOMNode leftNode, in nsIDOMNode rightNode, in nsIDOMNode parent); */
NS_IMETHODIMP nsEditor::JoinNodes(nsIDOMNode *leftNode, nsIDOMNode *rightNode, nsIDOMNode *parent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteNode (in nsIDOMNode child); */
NS_IMETHODIMP nsEditor::DeleteNode(nsIDOMNode *child)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean outputsMozDirty (); */
NS_IMETHODIMP_(bool) nsEditor::OutputsMozDirty()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markNodeDirty (in nsIDOMNode node); */
NS_IMETHODIMP nsEditor::MarkNodeDirty(nsIDOMNode *node)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void switchTextDirection (); */
NS_IMETHODIMP nsEditor::SwitchTextDirection()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString outputToString (in AString formatType, in unsigned long flags); */
NS_IMETHODIMP nsEditor::OutputToString(const nsAString & formatType, uint32_t flags, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void outputToStream (in nsIOutputStream aStream, in AString formatType, in ACString charsetOverride, in unsigned long flags); */
NS_IMETHODIMP nsEditor::OutputToStream(nsIOutputStream *aStream, const nsAString & formatType, const nsACString & charsetOverride, uint32_t flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEditorObserver (in nsIEditorObserver observer); */
NS_IMETHODIMP nsEditor::AddEditorObserver(nsIEditorObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEditorObserver (in nsIEditorObserver observer); */
NS_IMETHODIMP nsEditor::RemoveEditorObserver(nsIEditorObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEditActionListener (in nsIEditActionListener listener); */
NS_IMETHODIMP nsEditor::AddEditActionListener(nsIEditActionListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEditActionListener (in nsIEditActionListener listener); */
NS_IMETHODIMP nsEditor::RemoveEditActionListener(nsIEditActionListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDocumentStateListener (in nsIDocumentStateListener listener); */
NS_IMETHODIMP nsEditor::AddDocumentStateListener(nsIDocumentStateListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDocumentStateListener (in nsIDocumentStateListener listener); */
NS_IMETHODIMP nsEditor::RemoveDocumentStateListener(nsIDocumentStateListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpContentTree (); */
NS_IMETHODIMP nsEditor::DumpContentTree()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugDumpContent (); */
NS_IMETHODIMP nsEditor::DebugDumpContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void debugUnitTests (out long outNumTests, out long outNumTestsFailed); */
NS_IMETHODIMP nsEditor::DebugUnitTests(int32_t *outNumTests, int32_t *outNumTestsFailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean isModifiableNode (in nsIDOMNode aNode); */
NS_IMETHODIMP_(bool) nsEditor::IsModifiableNode(nsIDOMNode *aNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean suppressDispatchingInputEvent; */
NS_IMETHODIMP nsEditor::GetSuppressDispatchingInputEvent(bool *aSuppressDispatchingInputEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsEditor::SetSuppressDispatchingInputEvent(bool aSuppressDispatchingInputEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute boolean isInEditAction; */
NS_IMETHODIMP nsEditor::GetIsInEditAction(bool *aIsInEditAction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditor_h__ */
