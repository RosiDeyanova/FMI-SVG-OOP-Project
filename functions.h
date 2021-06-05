#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
#include "Vector.h"
#include "String.h"
using namespace std;

String getType(String word) 
{
	String type;
	for (size_t i = 0; i < word.length(); i++)
	{
		while (word[i]!='=')
		{
			type = type + word[i];
		}
	}

	return type;
}
String getInfo(String word) {
	String info;
	return info;
}

Rectangle constructRectangle(Vector<String> words)
{
	Rectangle rec;
	int counter = 0;//counts the "
	String insideInfo;
	for (size_t i = 0; i < words.getSize(); i++) //goes through every element in vector words
	{
		for (size_t j = 0; j < words[i].length(); j++) //goes through every char* in words[i]
		{
			if (words[i][0] == 'x' && words[i][1] == '=') //checks if the char* starts with x=
			{
				j += 3; //skipping the ="
				while (words[i][j] != '"') //gets the info between the " .... "
				{
					insideInfo = insideInfo + words[i][j];
					j++;
				}
				rec.setX(insideInfo.Int_Parse(insideInfo.getString())); //parses the info from String to int
				insideInfo.empty(); //empties the String
			}   //fills up the x
			if (words[i][0] == 'y' && words[i][1] == '=')
			{
				j += 3; //skipping the ="
				while (words[i][j] != '"')
				{
					insideInfo = insideInfo + words[i][j];
					j++;
				}
				rec.setY(insideInfo.Int_Parse(insideInfo.getString()));
				insideInfo.empty();
			} //fills up the y
			if ()
		}

	}


	return rec;
}
void recogniseShape(Vector<String> words)
{
	Vector<Shape*>shapes;
	if (words[0] == "<rect")
	{
		Rectangle rec = constructRectangle(words);
		shapes.push_back(&rec);
	}
	else if (words[0] == "<circle") {}
	else if (words[0] == "<line") {}

}

//checks the first element of every vector and calls function constructRec, constructCir, constructLine and then they will be pushed into a vector
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
			recogniseShape(words);
		}
		MyFile.close();
		std::cout << "\nSuccessfully opened " << std::endl;

	}
};
//add in open command
