
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
using namespace std;

void openFile(const char* input_file_name)
{
	
	ifstream MyFile;
	MyFile.open(input_file_name);

	if (MyFile.is_open())
	{
		while (!MyFile.eof())
		{
			//Vector<Shape>shapes;
			//char str[1000];
			char* str = new char[1024];
			char* word = new char[100];
			//Vector <char*> words;
			MyFile.getline(str, 1000);

			for (size_t i = 0; i < strlen(str); i++)
			{
				while (str[i] != 32)
				{
					int len = strlen(word) + sizeof(char);
					char* new_str = new char[len];
					strcpy_s(new_str, len, word + str[i]);
					word = new_str;

				}

				int len = strlen(word) + 1;
				char* new_str = new char[len];
				strcpy_s(new_str, len, word + '\0');
				word = new_str;
			}

			delete[] word;
			delete[] str;
		}
			MyFile.close();
			std::cout << "\nSuccessfully opened " << std::endl;
			
	}
};
//add in open command


int main()
{
	String s = "Hello this is Hot Garbage!";
	Vector<String> strvector = s.tokenize(' ');
	for (size_t i = 0; i < strvector.getSize(); i++)
	{
		std::cout << strvector[i] << " ";
	}

	
	std::cout << std::endl;
	//String sub = s.substr(2, 4);
	
	//std::cout << sub << std::endl;
	char console_input[120];
	char command[64] = "open test.txt";
	//cin.getline(command, 64);
	ofstream outputstream;
	ifstream inputstream;
	
	//cin >> command;
	//command line
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

