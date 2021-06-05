
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
	Vector<Shape*> shapes;
	char command[64];// = "open test.txt";
	while (true) {
		cin.getline(command, 64);
		ofstream outputstream;
		ifstream inputstream;

		//command line
		if (strncmp(command, "open", 4) == 0)
		{

			strcpy_s(console_input, strlen(command) - 4, &(command[5]));

			inputstream.open(console_input);
			cout << "Your file is open.";
			int maxSize = 16;
			char* hexarray = new char[maxSize];
			shapes = openFile(console_input, shapes);


			delete[] hexarray;
		}
		else if (strncmp(command, "close", 5) == 0)
		{
			inputstream.close();
			cout << "Your file is closed.";
		}
		else if (strncmp(command, "save", 4) == 0)
		{
			cout << "Successfully saved";
		}
		else if (strncmp(command, "saveas", 6) == 0)
		{
			cout << "is in saveas command";
		}
		else if (strncmp(command, "exit", 4) == 0)
		{
			cout << "Exiting the program...";
			exit(0);
		}
		else if (strncmp(command, "help", 4) == 0)
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

		//functional commands
		else if (strncmp(command, "print", 5) == 0)
		{
			for (size_t i = 0; i < shapes.getSize(); i++)
			{
				cout << i + 1 << ". ";
				shapes[i]->print();
			}
		}
		else if (strncmp(command, "create", 6) == 0)
		{
			strcpy_s(console_input, strlen(command) - 6, &(command[7]));
			String input = console_input;
			Vector<String> input_shape;
			input_shape = input.tokenize(' ', false);
			if (input_shape[0] == "rectangle")
			{
				char* name = (input_shape[0].getString());
				int x = input_shape[1].Int_Parse(input_shape[1].getString());
				int y = input_shape[2].Int_Parse(input_shape[2].getString());
				int width = input_shape[3].Int_Parse(input_shape[3].getString());
				int height = input_shape[4].Int_Parse(input_shape[4].getString());
				char* color = input_shape[5].getString();
				shapes.push_back(new Rectangle(name, x, y, width, height, color));
				cout << "Successfully created rectangle (" << shapes.getSize() << ")"<<endl;
			}
			else if (input_shape[0] == "circle")
			{
				char* name = (input_shape[0].getString());
				int x = input_shape[1].Int_Parse(input_shape[1].getString());
				int y = input_shape[2].Int_Parse(input_shape[2].getString());
				int r = input_shape[3].Int_Parse(input_shape[3].getString());
				char* color = input_shape[4].getString();
				shapes.push_back(new Circle(name, x, y, color, r));
				cout << "Successfully created circle (" << shapes.getSize() << ")"<<endl;
			}
			else if (input_shape[0] == "line")
			{
				char* name = (input_shape[0].getString());
				int x = input_shape[1].Int_Parse(input_shape[1].getString());
				int y = input_shape[2].Int_Parse(input_shape[2].getString());
				int x2 = input_shape[3].Int_Parse(input_shape[3].getString());
				int y2 = input_shape[4].Int_Parse(input_shape[4].getString());
				char* color = input_shape[5].getString();
				shapes.push_back(new Line(name, x, y, color, x2, y2));
				cout << "Successfully created line (" << shapes.getSize() << ")"<<endl;
			}
			//take console_input, put it in a vector, check the first element and call a constructor then add it to the shapes vector



		}
		else if (strncmp(command, "erase", 5) == 0)
		{
			strcpy_s(console_input, strlen(command) - 5, &(command[6]));
			String input = console_input;
			int position = input.Int_Parse(input.getString());
			shapes.eraseAt(max(position - 1, 0));

		}
		else if (strncmp(command, "translate", 9) == 0)
		{
			//check if second word is a number, if not go trough all shapes and translate them, if it is, translate only this shape
			strcpy_s(console_input, strlen(command) - 9, &(command[10]));
			String input = console_input;
			Vector<String> input_shape;
			input_shape = input.tokenize(' ', false);
			if (input_shape[0][0] >= '1' && input_shape[0][0] <= '9')//checking if the second word is a number
			{
				int x = shapes[input_shape[0].Int_Parse(input_shape[0].getString()) - 1]->getX();
				int y = shapes[input_shape[0].Int_Parse(input_shape[0].getString()) - 1]->getY();
				String addedX = checkTranslation(input_shape[2]).getString();
				String addedY = checkTranslation(input_shape[1]).getString();

				int num = input_shape[0].Int_Parse(input_shape[0].getString());
				shapes[num-1]->setX(x + addedX.Int_Parse(addedX.getString()));
				shapes[num-1]->setY(y + addedY.Int_Parse(addedY.getString()));


			}
			else
			{
				String addedX = checkTranslation(input_shape[1]).getString();
				String addedY = checkTranslation(input_shape[0]).getString();
				for (size_t i = 0; i < shapes.getSize(); i++)
				{
					int x = shapes[i]->getX();
					int y = shapes[i]->getY();
					shapes[i]->setX(x + addedX.Int_Parse(addedX.getString()));
					shapes[i]->setY(y + addedY.Int_Parse(addedY.getString()));
				}
			
			}

		}
	}
}

