#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "TreeType.h"
#include "QueType.h"

using namespace std;

int main()
{

  string command;
  string sortType;
  int tempItem;
  bool found;

  ifstream inFile;
  ofstream outFile;

  inFile.open("input.txt");
  outFile.open("output.txt");

  QueType<ItemType> que;
  TreeType<ItemType> tree;

  while(true){

    if(command == "Quit"){
      break;
    }

    else if(command == "MakeEmpty"){
      tree.MakeEmpty();
    }

    else if(command == "IsEmpty"){
      if(tree.IsEmpty()){
	outFile << "The tree is empty" << endl;
      }
      else{
	outFile << "The tree is not empty" << endl;
      }    
    }

    else if(command == "IsFull"){
       if(tree.IsFull()){
	outFile << "The tree is full" << endl;
      }
      else{
	outFile << "The tree is not full" << endl;
      }
    }

    else if(command == "GetLength"){
      outFile << tree.GetLength() << endl;
    }

    else if(command == "GetItem"){
      cin >> tempItem;
      outFile << GetItem(tree, tempItem, found) << endl;
    }

    else if(command == "PutItem"){
      cin >> tempItem;
      tree.PutItem(tempItem);
      outFile << "Put " << tempItem << " into the tree." << endl;
    }

    else if(command == "DeleteItem"){
      cin >> tempItem;
      tree.DeleteItem(tempItem);
      outFile << "Deleted " << tempItem << " from the tree." << endl;
    }

    else if(command == "PrintTree"){
      PrintTree(tree);
    }

    else if(command == "ResetTree"){
      cin >> sortType;
      tree.ResetTree(sortType);
    }

    else if(command == "GetNextItem"){
      cin << sortType;
      outFile << tree.GetNextItem(sortType, found) << endl;
    }

    else if(command == "LevelOrderPrint"){
      
    }

    else if(command == "InOrderPrint"){
      outFile << tree.InOrderPrint() << endl;
    }

    else if(command == "PreOrderPrint"){
      outFile << tree.PreOrderPrint() << endl;
    }

    else if(command == "PostOrderPrint"){
      outFile << tree.PostOrderPrint() << endl;
    }

    else if(command == "Ancestors"){
      cin << tempItem;
      outFile << tree.Ancestors(tempItem) << endl;
    }

    else if(command == "MakeTree"){
      
    }

  }//main while


}//main
