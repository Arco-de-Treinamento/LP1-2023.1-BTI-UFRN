#ifndef FILE_LIB
#define FILE_LIB

void createFile(std::string fileName);
bool fileExist(std::string fileName);
std::vector<std::vector<std::string>> readFile(std::string fileName);
void updateFile(std::string fileName, std::vector<std::vector<std::string>> table);
void cleanFile(std::string fileName);
void printTable(std::string fileName);
void addItem(std::string fileName, std::string name, float price);
std::vector<std::string> getItem(std::string fileName, std::string name);
void editItem(std::string fileName, std::string oldName, std::string newName, float newPrice);
void removeItem(std::string fileName, std::string name);

#endif