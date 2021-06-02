
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Vector.h"
#include "String.h"
#include "functions.h"
using namespace std;


int main()
{
	char console_input[120];
	char command[64] = "open test.txt";
	//cin.getline(command, 64);
	ofstream outputstream;
	ifstream inputstream;

		if (strncmp(command, "open", 4) == 0)
		{
		
			strcpy_s(console_input, strlen(command) - 4, &(command[5]));
	
			inputstream.open(console_input);
			cout << "Your file is open.";
			int maxSize = 16;
			char* hexarray = new char[maxSize];
			openFile(console_input);


			delete[] hexarray;
		}
		if (strncmp(command, "close", 5) == 0)
		{
			inputstream.close();
			cout << "Your file is closed.";
		}
		if (strncmp(command, "save", 4) == 0)
		{
			cout << "Successfully saved";
		}
		if (strncmp(command, "saveas", 6) == 0)
		{
			cout << "is in saveas command";
		}
		if (strncmp(command, "exit", 4) == 0)
		{
			cout << "Exiting the program...";
			exit(0);
		}
		if (strncmp(command, "help", 4) == 0)
		{
			std::cout << "The following commands are supported:" << std::endl
				<< "open <file>" << std::endl
				<< "close" << std::endl
				<< "save" << std::endl
				<< "saveas <file>" << std::endl
				<< "help" << std::endl
				<< "exit" << std::endl
				<< "print" << std::endl
				<< "create <figure>" << std::endl
				<< "erase <n>" << std::endl
				<< "translate vertical=<n> horizontal=<p>" << std::endl
				<< "within <option>" << std::endl;
		}
	
}

