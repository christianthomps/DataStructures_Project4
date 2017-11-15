#include <string>
#include <fstream>
//typedef int ItemType;
struct TreeNode;
#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};
class TreeType
{
 public:
  TreeType();                     // constructor
  ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree); 
  void operator=(const TreeType& originalTree);
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
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};

