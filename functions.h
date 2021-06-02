#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
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
			char* str = new char[1024];

			MyFile.getline(str, 1000); //gets every new line
			String string = str;
			Vector <String> words = string.tokenize(' '); //goes through every line and separates the words by space, than it pushes them into a vector

		}
		MyFile.close();
		std::cout << "\nSuccessfully opened " << std::endl;

	}
};
//add in open command