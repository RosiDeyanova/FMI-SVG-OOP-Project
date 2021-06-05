
#pragma once
#include <iostream>
#include "Vector.h"

class String
{
private:
	char* str;

	void erase();
	void copy(const String& other);
public:
	String();
	String(const char* s);
	String(char s);
	String(const String& other);
	~String();

	void print()const;
	int length()const;
	int find(char c, int lastToken);
	void empty();
	String substr(size_t startPos, size_t length);
	String toUpper(String s);
	String toLower(String s);
	String toString(size_t x);
	Vector<String> tokenize(char c, bool isReadingFromFile);
	int Int_Parse(const char* txt);
	char* getString() 
	{
		return this->str;
	}
	// Vector<String*> tokens <- вектор от показатели
	// Vector<String> tokens <- вектор от Стринг обекти ( копия )
	


	String& operator=(const String& other);
	String& operator=(const char* other);
	String& operator=(char s);


	String operator+(char s);
	String operator+(const char* s);
	String operator+(const String& other);

	char& operator[] (size_t i);

	bool operator ==(const String& other);
	bool operator !=(const String& other);
	bool operator<(const String& other);
	bool operator>(const String& other);
	bool operator<=(const String& other);
	bool operator>=(const String& other);




	friend std::ostream& operator<<(std::ostream& out, const String& s);
	friend std::istream& operator>>(std::istream& in, String& s);
};


String operator+ (char c, String s);


String String::substr(size_t startPos, size_t endPos) {

	char* retstr = new char[this->length() - startPos + 1];

	for (size_t i = 0; i < endPos - startPos; i++) 
	{
		retstr[i] = this->str[i + startPos];
	}

	retstr[endPos - startPos] = 0;
	return retstr;
}

int String::Int_Parse(const char* txt) 
{
	int sum = 0;
	bool isNegative = txt[0] == '-';
	if (isNegative)
	{
		for (size_t i = 1; i < strlen(txt); i++)
		{
			if (txt[i] < '0' || txt[i] > '9') { return INT_MIN; }
			sum += (txt[i] - '0');
			sum *= 10;
		}
	}
	else
	{
		for (size_t i = 0; i < strlen(txt); i++)
		{
			if (txt[i] < '0' || txt[i] > '9') { return INT_MIN; }
			sum += (txt[i] - '0');
			sum *= 10;
		}
	}

	if (isNegative)
	{
		return (sum / 10) * -1;
	}
	return sum / 10;
}

int String::find(char c,int lastToken)
{
	for (size_t i = lastToken; i < this->length(); i++)
	{
		if (this->str[i] == c) {
			return i;
		}
	}
	return this->length();
}

Vector<String> String::tokenize(char c, bool isReadingFromFile)
{
	Vector<String> retvec;
	// да намерим първия спейс
	// да го запазим някъде
	// да влезем в цикъл и да спамим .find докато не върне -1

	int lastToken = 0;
	if (isReadingFromFile==true)
	{
		lastToken = this->find('<', lastToken);
	}
	int endToken = 0;
	while (endToken != this->length()) {
		endToken = this->find(c, lastToken);
		if (endToken!=0)
		{
			retvec.push_back(this->substr(lastToken, endToken));
		}
		lastToken = endToken + 1;
	}

	return retvec;
}

void String::erase()
{
	delete[] this->str;
}

inline void String::empty()
{
	this->str = new char[1];
	str[0] = 0;
}

void String::copy(const String& other)
{
	this->str = new char[strlen(other.str) + 1];
	strcpy_s(this->str, strlen(other.str) + 1, other.str);
}

String::String()
{
	this->str = new char[1];
	str[0] = 0;
}

String::String(const char* s)
{
	this->str = new char[strlen(s) + 1];
	strcpy_s(this->str, strlen(s) + 1, s);
}

String::String(char s)
{
	this->str = new char[2];
	this->str[0] = s;
	this->str[1] = 0;
}

String::String(const String& other)
{
	copy(other);
}

String::~String()
{
	delete[] this->str;
}

void String::print() const
{
	std::cout << this->str;
}

int String::length() const
{
	return strlen(this->str);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		this->erase();
		copy(other);
	}
	return *this;
}

String& String::operator=(const char* other)
{
	this->erase();
	this->str = new char[strlen(other) + 1];
	strcpy_s(this->str, strlen(other) + 1, other);
	return *this;
}

String& String::operator=(char s)
{
	erase();
	this->str = new char[2];
	this->str[0] = s;
	this->str[1] = 0;
	return *this;
}

String String::operator+(char s)
{
	String result;
	result.str = new char[this->length() + 1 + 1];
	strcpy_s(result.str, this->length() + 1, this->str);
	result.str[this->length()] = s;
	result.str[this->length() + 1] = 0;
	return result;
}

String String::operator+(const char* s)
{
	String result;
	result.str = new char[this->length() + strlen(s) + 1];
	strcpy_s(result.str, this->length() + 1, this->str);
	strcat_s(result.str, this->length() + strlen(s) + 1, s);
	return result;
}

String String::operator+(const String& other)
{
	String result;
	result.str = new char[this->length() + other.length() + 1];
	strcpy_s(result.str, this->length() + 1, this->str);
	strcat_s(result.str, this->length() + other.length() + 1, other.str);

	return result;
}

char& String::operator[](size_t i)
{
	return this->str[i];
}

bool String::operator==(const String& other)
{
	if (strcmp(this->str, other.str) == 0) return true;
	return false;
}

bool String::operator!=(const String& other)
{
	if (*this == other) return false;
	return true;
}

bool String::operator<(const String& other)
{
	if (strcmp(this->str, other.str) == -1)return true;
	return false;
}

bool String::operator>(const String& other)
{
	if (strcmp(this->str, other.str) == 1)return true;
	return false;
}

bool String::operator<=(const String& other)
{
	if (strcmp(this->str, other.str) == -1 || strcmp(this->str, other.str) == 0)return true;
	return false;
}

bool String::operator>=(const String& other)
{
	if (strcmp(this->str, other.str) == 1 || strcmp(this->str, other.str) == 0)return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.str;
	return out;
}

std::istream& operator>>(std::istream& in, String& s)
{
	
	char c;
	do
	{
		c = in.get();
		if (c != '\n')
		{
			s = s + c;
		}
	} while (c != '\n');

	return in;
}

String operator+(char c, String s)
{
	String result;

	result = c;
	result = result + s;
	return result;

}

String String::toUpper(String s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 32;
	}
	return s;
}

String String::toLower(String s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
	}
	return s;
}

String String::toString(size_t x)
{
	String result;
	while (x)
	{
		if (x < 10) result = '0' + x;
		result = result + ('0' + (x % 10));
		x = x / 10;
	}
	return result;
}
