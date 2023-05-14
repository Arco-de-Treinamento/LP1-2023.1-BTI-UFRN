#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>

using namespace std;

string addFile(string text, string fileName){
  fstream file;
  string name = fileName + ".txt";

  file.open(name, ios::out | ios::app);
  file << text << endl; 
  
  file.close();
  return name; 
}

int searchFile(string fileName, string text){
  fstream file;
  file.open(fileName, ios::in);

  string temp;
  list<string> data;

  while(getline(file, temp)){
    data.push_back(temp);
  }

  for(auto i : data){
    string tempData = i;
    if(tempData == text) return 1;
  }

  return 0;
}
