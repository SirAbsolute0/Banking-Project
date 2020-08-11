#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//User data structure
struct data
{
	int age = 0, ID = 0, SSN = 0;
	string name = "default";
	float money = 0;
	data* next = nullptr;
};

//All function prototyes
int menu();
void input(data*);
void newUser(data*);
void updateData(data*);
void displayAll(data*);
void deleteNode(data*);
void transaction(data*);