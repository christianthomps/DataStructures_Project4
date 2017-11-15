#include <string>
#include <fstream>
#include <iostream>

using namespace std;

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
  void Print() const;
  //void PrintTree(TreeNode<ItemType>* tree) const;
  void PreOrderPrint(ofstream& outFile) const;
  void InOrderPrint(ofstream& outFile) const;
  void PostOrderPrint(ofstream& outFile) const;
  void Ancestors(ItemType value);
  TreeType<ItemType> MakeTree(ItemType arry[]);
  TreeType<ItemType> MirrorImage();
 private:
  ItemType PtrToSuccessor(ItemType*& tree);
  TreeNode<ItemType>* root;
  QueType<ItemType> preQue;
  QueType<ItemType> inQue;
  QueType<ItemType> postQue;
};

