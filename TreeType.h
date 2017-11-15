#include <string>
#include <fstream>
//typedef int ItemType;
template <class ItemType>
struct TreeNode;
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class ItemType>
class TreeType
{
 public:
  TreeType();                     // constructor
  ~TreeType();                    // destructor
  TreeType(const TreeType<ItemType>& originalTree); 
  void operator=(const TreeType<ItemType>& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const; 
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  ItemType GetNextItem(OrderType order, bool& finished);
  void PrintTree() const;
  void PreOrderPrint() const;
  void InOrderPrint() const;
  void PostOrderPrint() const;
  void Ancestors(ItemType value) const;
  TreeType<ItemType> MakeTree(ItemType[] arry);
  TreeType<ItemType> MirrorImage();
 private:
  ItemType PtrToSuccessor(ItemType*& tree);
  TreeNode<ItemType>* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

