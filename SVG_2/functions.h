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

String getType(String& word)
{
	String type;
	for (size_t i = 0; i < word.length(); i++)
	{
		while (word[i] != '=')
		{
			type = type + word[i];
			i++;
		}
		break;
	}

	return type;
}
String getInfo(String& word, const String& type) {
	String info;
	for (size_t i = type.length() + 2; i < word.length(); i++)
	{
		while (word[i] != '"')
		{
			info = info + word[i];
			i++;
		}
		break;
	}

	return info;
}
Rectangle* constructRectangle(Vector<String>& words)
{
	Rectangle* rec = new Rectangle();
	for (size_t i = 1; i < words.getSize() - 1; i++) //goes through every element in vector words
	{
		String type = getType(words[i]);
		if (type == "x")
		{
			String insideInfo = getInfo(words[i], type);
			rec->setX(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}   //fills up the x
		else if (type == "y")
		{
			String insideInfo = getInfo(words[i], type);
			rec->setY(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}
		else if (type == "fill")
		{
			String insideInfo = getInfo(words[i], type);
			char* color = insideInfo.getString();
			rec->setColor(color);
		}
		else if (type == "width")
		{
			String insideInfo = getInfo(words[i], type);
			rec->setWidth(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}
		else if (type == "height")
		{
			String insideInfo = getInfo(words[i], type);
			rec->setHeight(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}

	}
	return rec;
}
Circle* constructCircle(Vector<String>& words)
{
	Circle* cir = new Circle();
	for (size_t i = 1; i < words.getSize() - 1; i++) //goes through every element in vector words
	{
		String type = getType(words[i]);
		if (type == "x")
		{
			String insideInfo = getInfo(words[i], type);
			cir->setX(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}   //fills up the x
		else if (type == "y")
		{
			String insideInfo = getInfo(words[i], type);
			cir->setY(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}
		else if (type == "fill")
		{
			String insideInfo = getInfo(words[i], type);
			char* color = insideInfo.getString();
			cir->setColor(color);
		}
		else if (type == "r")
		{
			String insideInfo = getInfo(words[i], type);
			cir->setR(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}

	}
	return cir;
}
Line* constructLine(Vector<String>& words)
{
	Line* line = new Line();
	for (size_t i = 1; i < words.getSize() - 1; i++) //goes through every element in vector words
	{
		String type = getType(words[i]);
		if (type == "x")
		{
			String insideInfo = getInfo(words[i], type);
			line->setX(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}   //fills up the x
		else if (type == "y")
		{
			String insideInfo = getInfo(words[i], type);
			line->setY(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}
		else if (type == "fill")
		{
			String insideInfo = getInfo(words[i], type);
			char* color = insideInfo.getString();
			line->setColor(color);
		}
		else if (type == "x2")
		{
			String insideInfo = getInfo(words[i], type);
			line->setX2(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}
		else if (type == "y2")
		{
			String insideInfo = getInfo(words[i], type);
			line->setY2(insideInfo.toInt(insideInfo.getString())); //parses the info from String to int
		}

	}
	return line;
}
Shape* recogniseShape(Vector<String>& words)
{
	if (words[0] == "<rect")
	{
		Rectangle* rec = constructRectangle(words);
		return rec;
	}
	else if (words[0] == "<circle")
	{
		Circle* cir = constructCircle(words);
		return cir;
	}
	else if (words[0] == "<line")
	{
		Line* line = constructLine(words);
		return line;
	}

}

//checks the first element of every vector and calls function constructRec, constructCir, constructLine and then they will be pushed into a vector
Vector<Shape*> openFile(const char* input_file_name, Vector<Shape*>shapes)
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
			Vector <String> words = string.tokenize(' ',true); //goes through every line and separates the words by space, than it pushes them into a vector
			String firstWord = words[0];
			if (firstWord == "<rect" || firstWord == "<circle" || firstWord == "<line")
			{
				Shape* rec = recogniseShape(words);
				shapes.push_back(rec); //pushes all shapes into a vector
			}

		}

		MyFile.close();
		std::cout << "\nSuccessfully opened " << std::endl;
		return shapes;

	}
};
//add in open command

String checkTranslation(String word) 
{
	String info;
	for (size_t i = 0; i < word.length(); i++)
	{
		if (word[i-1]=='=')
		{
			while (i<word.length())
			{
				info = info + word[i];
				i++;
			}
		}
	}
	return info;
}

void save(Vector<Shape*>& shapes, const char* filename)
{
	std::ofstream out;
	out.open(filename);

	out << "< ? xml version = \"1.0\" standalone = \"no\" ? >" << std::endl
		<< "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"" << std::endl
		<< "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl
		<< "<svg>" << std::endl;

	for (size_t i = 0; i < shapes.getSize(); i++)
	{
		shapes[i]->writeOut(out);
	}

	out << "</svg>" << std::endl;
	out.close();
}