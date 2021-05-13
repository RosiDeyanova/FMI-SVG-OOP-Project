
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Vector.h"
using namespace std;

void getFileInfo(const char* text) 
{
		

}

int main()
{
	char file[120];
	char command[64];
	char* text[1024];
	cin.getline(command, 64);
	ofstream outputstream;
	ifstream inputstream;
	

		if (strncmp(command, "open", 4) == 0)
		{
		
			strcpy_s(file, strlen(command) - 4, &(command[5]));
	
			inputstream.open(file);
			cout << "Your file is open.";
			int maxSize = 16;
			char* hexarray = new char[maxSize];
			Vector<char*>ne6to;

			while (!inputstream.eof())
			{
				

					inputstream.get(hexarray, maxSize, 'rect');
			}


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

