#ifndef TreeType_H
#define TreeType_H

#include <string>
#include <fstream>
#include <iostream>
#include "QueType.cpp"
#include "QueType.h"

using namespace std;

template <class ItemType>
struct TreeNode;

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
  TreeNode<ItemType>* GetRoot();
  void SetRoot(TreeNode<ItemType>* node);
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order); 
  ItemType GetNextItem(OrderType order, bool& finished);
  void Print(ofstream& outfile) const;
  //void PrintTree(TreeNode<ItemType>* tree) const;
  void PreOrderPrint(ofstream& outFile) const;
  void InOrderPrint(ofstream& outFile) const;
  void PostOrderPrint(ofstream& outFile) const;
  void Ancestors(ItemType value, ofstream& outfile);
  void MakeTree(ItemType arry[], int length);
  TreeType<ItemType> MirrorImage();
  void LevelOrderPrint(ofstream& outfile);
 private:
  ItemType PtrToSuccessor(ItemType*& tree);
  TreeNode<ItemType>* root;
  QueType<ItemType> preQue;
  QueType<ItemType> inQue;
  QueType<ItemType> postQue;
};

#endif
