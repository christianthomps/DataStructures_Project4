#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "TreeType.h"
#include "TreeType.cpp"
#include "QueType.h"
#include "QueType.cpp"

using namespace std;
OrderType convert(string& str){
  if(str == "PRE_ORDER") return PRE_ORDER;
  else if(str == "IN_ORDER") return IN_ORDER;
  else if(str == "POST_ORDER") return POST_ORDER;
  else
    return IN_ORDER;
}
int main()
{

  string command;
  string sortString;
  OrderType sortType;
  int tempItem;
  bool found;

  ifstream inFile;
  ofstream outFile;

  inFile.open("input.txt");
  outFile.open("output.txt");

  QueType<char> que;
  TreeType<char> tree;

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
      inFile >> tempItem;
      outFile << tree.GetItem(tempItem, found) << endl;
    }

    else if(command == "PutItem"){
      inFile >> tempItem;
      tree.PutItem(tempItem);
      outFile << "Put " << tempItem << " into the tree." << endl;
    }

    else if(command == "DeleteItem"){
      inFile >> tempItem;
      tree.DeleteItem(tempItem);
      outFile << "Deleted " << tempItem << " from the tree." << endl;
    }

    else if(command == "PrintTree"){
      tree.Print();
    }

    else if(command == "ResetTree"){
      inFile >> sortString;
      sortType = convert(sortString);
      tree.ResetTree(sortType);
    }

    else if(command == "GetNextItem"){
      inFile >> sortString;
      sortType = convert(sortString);
      outFile << tree.GetNextItem(sortType, found) << endl;
    }

    else if(command == "LevelOrderPrint"){
      
    }

    else if(command == "InOrderPrint"){
      tree.InOrderPrint(outFile);
    }

    else if(command == "PreOrderPrint"){
      tree.PreOrderPrint(outFile);
    }

    else if(command == "PostOrderPrint"){
      tree.PostOrderPrint(outFile);
    }

    else if(command == "Ancestors"){
      inFile >> tempItem;
      tree.Ancestors(tempItem);
    }

    else if(command == "MakeTree"){
      
    }

  }//main while

  return 0;
}//main
