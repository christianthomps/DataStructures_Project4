#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include "TreeType.h"
#include "TreeType.cpp"
#include "QueType.h"
#include "QueType.cpp"
//
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

  string line;
  string command;
  string sortString;
  OrderType sortType;
  char tempItem;
  bool found;

  ifstream inFile;
  ofstream outFile;

  inFile.open("input.txt");
  outFile.open("output.txt");

  QueType<char> que;
  TreeType<char> tree;

  while(getline(inFile, line)){
    stringstream ss(line);
    ss >> command;

    if(command == "Quit"){
      break;
    }

    else if(command == "MakeEmpty"){
      tree.MakeEmpty();
      outFile << endl;

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
      ss >> tempItem;
      outFile << tree.GetItem(tempItem, found) << endl;
    }

    else if(command == "PutItem"){
      ss >> tempItem;
      tree.PutItem(tempItem);
      outFile << "Put " << tempItem << " into the tree." << endl;
    }

    else if(command == "DeleteItem"){
      ss >> tempItem;
      tree.DeleteItem(tempItem);
      outFile << "Deleted " << tempItem << " from the tree." << endl;
    }

    else if(command == "PrintTree"){
      tree.Print(outFile);
      outFile << endl;

    }

    else if(command == "ResetTree"){
      ss >> sortString;
      sortType = convert(sortString);
      tree.ResetTree(sortType);
      outFile << endl;

    }

    else if(command == "GetNextItem"){
      ss >> sortString;
      sortType = convert(sortString);
      outFile << tree.GetNextItem(sortType, found) << endl;
    }

    else if(command == "LevelOrderPrint"){
      tree.LevelOrderPrint(outFile);
      outFile << endl;
    }

    else if(command == "InOrderPrint"){
      tree.InOrderPrint(outFile);
      outFile << endl;

    }

    else if(command == "PreOrderPrint"){
      tree.PreOrderPrint(outFile);
      outFile << endl;

    }

    else if(command == "PostOrderPrint"){
      tree.PostOrderPrint(outFile);
      outFile << endl;

    }

    else if(command == "Ancestors"){
      ss >> tempItem;
      tree.Ancestors(tempItem, outFile);
      outFile << endl;

    }

    else if(command == "MakeTree"){
      int count = 0;
      char a[100];
      while(ss >> tempItem)
	{
	  a[count] = tempItem;
	  count++;
	}
      tree.MakeTree(a, count);
      outFile << endl;

    }

    else if(command == "MirrorImage")
      {
	tree = tree.MirrorImage();
	outFile << endl;
      }

    else
      {
	outFile << "Command not recognized." << endl;
      }

  }//main while

  return 0;
}//main
