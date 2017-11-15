#include<iostream>
using namespace std;
#include "TreeType.h"
struct TreeNode
{
  ItemType info;
  TreeNode<ItemType>* left;
  TreeNode<ItemType>* right;
};

template <class ItemType>
bool TreeType::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
  TreeNode<ItemType>* location;
  try
    {
      location = new TreeNode<ItemType>;
      delete location;
      return false;
    }
  catch(std::bad_alloc exception)
    {
      return true;
    }
}

template <class ItemType>
bool TreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}

int CountNodes(TreeNode<ItemType>* tree);

template <class ItemType>
int CountNodes(TreeNode<ItemType>* tree);

template <class ItemType>
int TreeType::GetLength() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
  return CountNodes(root);
}

template <class ItemType>
int CountNodes(TreeNode<ItemType>* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else 
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template <class ItemType>
void Retrieve(TreeNode<ItemType>* tree, 
	      ItemType& item, bool& found);

ItemType TreeType::GetItem(ItemType item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
  return item;
}

template <class ItemType>
void Retrieve(TreeNode<ItemType>* tree, 
	      ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)      
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.
  else
    {
      item = tree->info;                 // item is found.
      found = true;
    }
} 

template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item);

template <class ItemType>
void TreeType::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}

template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
    {// Insertion place found.
      tree = new TreeNode<ItemType>;
      tree->right = NULL;
      tree->left = NULL;
      tree->info = item;
    }
  else if (item < tree->info)
    Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
}


template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree);

template <class ItemType>
void TreeType::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
  bool found = false;
  GetItem(item, found);
  if (found)
    Delete(root, item);
  else
    cout << item << "is not in tree\n";
}

template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}   

template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);

template <class ItemType>
TreeNode<ItemType>* PtrToSuccessor(TreeNode<ItemType>*& tree);

template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
{
  ItemType data;
  TreeNode<ItemType>* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL)
    {
      tree = tree->right;
      delete tempPtr;
    }
  else if (tree->right == NULL)
    {
      tree = tree->left;
      delete tempPtr;
    }
  else
    {
      //GetPredecessor(tree->left, data);
      tree->info = data;
      Delete(tree->left, data);  // Delete predecessor node.
    }
}

template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

template <class ItemType>
TreeNode<ItemType>* PtrToSuccessor(TreeNode<ItemType> *& tree){
  TreeNode<ItemType> ptr = tree;
  while(ptr->left != NULL)
    ptr = ptr->left;
  return ptr;
}

template <class ItemType>
void PrintTree(TreeNode<ItemType>* tree) 
// Prints info member of items in tree in sorted order on screen.
{
  if (tree != NULL)
    {
      PrintTree(tree->left);   // Print left subtree.
      cout << tree->info<<"  ";
      PrintTree(tree->right);  // Print right subtree.
    }
}

template <class ItemType>
void TreeType::Print() const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root);
}

TreeType::TreeType()
{
  root = NULL;
}

template <class ItemType>
void Destroy(TreeNode<ItemType>*& tree);

TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}


void Destroy(TreeNode<ItemType>*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
    {
      Destroy(tree->left);
      Destroy(tree->right);
      delete tree;
    }
}

template <class ItemType>
void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}

template <class ItemType>
void CopyTree(TreeNode<ItemType>*& copy, 
	      const TreeNode<ItemType>* originalTree);

template <class ItemType>
TreeType::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
//  into root.
{
  CopyTree(root, originalTree.root);
}

template <class ItemType>
void TreeType::operator= 
(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
// into root.
{
  {
    if (&originalTree == this)
      return;             // Ignore assigning self to self
    Destroy(root);      // Deallocate existing tree nodes
    CopyTree(root, originalTree.root);
  }

}

template <class ItemType>
void CopyTree(TreeNode<ItemType>*& copy, 
	      const TreeNode<ItemType>* originalTree)
// Post: copy is the root of a tree that is a duplicate 
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
    {
      copy = new TreeNode<ItemType>;
      copy->info = originalTree->info;
      CopyTree(copy->left, originalTree->left);
      CopyTree(copy->right, originalTree->right);
    }
}
// Function prototypes for auxiliary functions.

template <class ItemType>
void PreOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in preorder.

template <class ItemType>
void InOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in inorder.

template <class ItemType>
void PostOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in postorder.


template <class ItemType>
void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
  switch (order)
    { 
    case PRE_ORDER:    preQue.MakeEmpty();
      PreOrder(root, preQue);
      break;
    case IN_ORDER:     inQue.MakeEmpty();
      InOrder(root, inQue);
      break;
    case POST_ORDER:  postQue.MakeEmpty();
      PostOrder(root, postQue);
      break;
    }
}


template <class ItemType>
void PreOrder(TreeNode<ItemType>* tree, QueType<ItemType>& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
    {
      preQue.Enqueue(tree->info);
      PreOrderPrint(tree->left, preQue);
      PreOrderPrint(tree->right, preQue);
    }
}

template <class ItemType>
void InOrder(TreeNode<ItemType>* tree  QueType<ItemType>& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
    {
      InOrder(tree->left, inQue);
      inQue.Enqueue(tree->info);
      InOrder(tree->right, inQue);
    }
}

template <class ItemType>
void PostOrder(TreeNode<ItemType>* tree, QueType<ItemType>& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
    {
      PostOrder(tree->left, postQue);
      PostOrder(tree->right, postQue);
      postQue.Enqueue(tree->info);
    }
}

template <class ItemType>
void InOrderPrintHelp(TreeNode<ItemType>* tree, ofstream& outFile){
  if(tree != null){
    InOrderPrintHelp(tree->left);   // Print left subtree.
    outFile << tree->info;
    InOrderPrintHelp(tree->right);   // Print right subtree.
  }
}

template <class ItemType>
void PreOrderPrintHelp(TreeNode<ItemType>* tree, ofstream& outFile){
  if(tree != NULL){
    outFile << tree->info;
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
  }
}

template <class ItemType>
void PostOrderPrintHelp(TreeNode<ItemType>* tree, ofstream& outFile){
  if(tree != NULL){
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    outFile << tree->info;
  }
}

template <class ItemType>
void PreOrderPrint() const{
  PreOrderPrintHelp(root, cout);
}

template <class ItemType>
void PostOrderPrint() const{
  PostOrderPrintHelp(root, cout);
}

template <class ItemType>
void InOrderPrint() const{
  InOrderPrintHelp(root, cout);
}



template <class ItemType>
void TreeType<ItemType>::Ancestors(ItemType value){
  TreeNode<ItemType>* ptr = root;
  QueType<ItemType> que;

  //Case:IN Tree
  while(ptr->info != value)
    {
      que.Enqueue(ptr->info);
      
      if(value > ptr->info)
	{
	  ptr = ptr->right;
	}
      else if(value < ptr->info)
	{
	  ptr = prt->left;
	}
      if(ptr = NULL)
	{
	  //fuck my shit up
	}
    }
  //haven't implemented
  //que.print();
  cout << "Ancestors: ";
  while(!que.IsEmpty())
    {
      cout << que.Dequeue();
    }
    //Add case: not in tree
}

template <class ItemType>
TreeType<ItemType> TreeType::MakeTree(ItemType[] arry)
{
  int length = sizeof(arry);
  MakeTreeHelp(0, length, arry);
}

template <class ItemType>
TreeNode<ItemType>* TreeType::MakeTreeHelp(int start, int end, ItemType[] arry)
{
  int mid = (start + end)/2;
  TreeNode<ItemType>* ptr = new TreeNode<ItemType>;
  ptr->info = arry[mid];
  if(start < end)
    {
      ptr->left = MakeTreeHelp(start, mid-1, arry);
      ptr->right = MakeTreeHelp(mid+1, end, arry);
    }
  return ptr;
}

TreeType<ItemType> TreeType<ItemType>::MirrorImage();

template <class ItemType>
ItemType TreeType::GetNextItem(OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true; 
//       otherwise finished is false.
{
  finished = false;
  ItemType item;
  switch (order)
    {
    case PRE_ORDER  : preQue.Dequeue(item);
      if (preQue.IsEmpty())
	finished = true;
      break;
    case IN_ORDER   : inQue.Dequeue(item);
      if (inQue.IsEmpty())
	finished = true;
      break;
    case  POST_ORDER: postQue.Dequeue(item);
      if (postQue.IsEmpty())
	finished = true;
      break;
    }
  return item;
}




