#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>

using namespace std;

#ifndef IO_FILE
#define IO_FILE

string createFile(map<string, double> alunos, string fileName);
void readFile(string fileName);

#endif
