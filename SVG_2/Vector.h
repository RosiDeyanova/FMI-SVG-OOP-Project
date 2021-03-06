#pragma once
#include <iostream>

template <class T>
class Vector
{
private:
	T* data;
	size_t size;
	size_t capacity;

	void resize();
	void copy(const Vector<T>& other);
	void erase();
public:
	Vector();
	Vector(const Vector<T>& other);
	~Vector();
	Vector(size_t initialSize);

	size_t getSize()const;

	void print();
	Vector<T>& push_back(const T& New);
	Vector<T>& eraseAt(size_t n);
	Vector<T>& empty();
	
	void insertAtPos(int index, const T& element);
	bool contains(const T& element)const;

	Vector<T>& operator=(const Vector<T>& other);

	Vector<T> operator+(const Vector<T>& other)const;
	Vector<T> operator+(const T& element)const;
	Vector<T>& operator+=(const T& element);
	Vector<T>& operator+=(const Vector<T>& other);

	T& operator[](int index)const;

	bool operator==(const Vector<T>& other)const;
	bool operator!=(const Vector<T>& other)const;

};

template <class T>
std::ostream& operator << (std::ostream& stream, const Vector<T>& v);

template <class T>
void Vector<T>::resize()
{
	this->capacity = capacity * 2;
	T* newBuffer = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		newBuffer[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newBuffer;
}

template <class T>
void Vector<T>::copy(const Vector<T>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = new T[capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = other.data[i];
	}
}

template <class T>
void Vector<T>::erase()
{
	delete[] this->data;
}


template <class T>
Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 8;
	this->data = new T[capacity];
}

template <class T>
Vector<T>::Vector(const Vector<T>& other)
{
	copy(other);
}

template <class T>
Vector<T>::~Vector()
{
	erase();
}

template <class T>
Vector<T>::Vector(size_t initialSize)
{
	this->size = initialSize;
	this->capacity = initialSize;
	this->data = new T[capacity];
}

template <class T>
void Vector<T>::print()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->data[i] << " ";
	}
}




template <class T>
Vector<T>& Vector<T>::push_back(const T& New)
{
	if (this->size == this->capacity - 1) resize();

	T* newBuffer = new T[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->data[i];
	}
	newBuffer[size] = New;
	delete[] this->data;
	this->data = newBuffer;
	this->size++;

	return *this;
}

template<class T>
inline Vector<T>& Vector<T>::eraseAt(size_t n)
{
	T* newElement = new T[this->size - 1];
	for (size_t i = 0; i < n; i++)
	{
		newElement[i] = this->data[i];
	}
	for (size_t i = n; i < size; i++)
	{
		newElement[i] = this->data[i + 1];
	}
	delete[] this->data;
	this->data = newElement;
	this->size--;
	return *this;
}

template<class T>
inline Vector<T>& Vector<T>::empty()
{	this->size = 0;
	return *this;
}

template <class T>
size_t Vector<T>::getSize() const
{
	return this->size;
}


template <class T>
void Vector<T>::insertAtPos(int index, const T& element)
{
	if (this->size == this->capacity) resize();

	T* newBuffer = new T[size + 1];

	for (int i = 0; i < index - 1; i++)
	{
		newBuffer[i] = this->data[i];
	}
	newBuffer[index - 1] = element;
	for (int i = index; i < this->size + 1; i++)
	{
		newBuffer[i] = this->data[i - 1];
	}
	this->size++;
	delete[]this->data;
	this->data = newBuffer;
}

template <class T>
bool Vector<T>::contains(const T& element)const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == element) return true;
	}

	return false;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const
{
	Vector<T> result(*this);
	for (int i = 0; i < other.size; i++)
	{
		result.push_back(other.data[i]);
	}
	return result;
}

template <class T>
Vector<T> Vector<T>::operator+(const T& element) const
{
	Vector<T> result(*this);
	result.push_back(element);
	return result;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const T& element)
{
	this->push_back(element);
	return *this;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other)
{
	*this = *this + other;
	return *this;
}

template <class T>
T& Vector<T>::operator[](int index) const
{
	return this->data[index];
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& other)const
{
	if (this->size == other.size)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (!contains(other.data[i])) return false;
		}
		for (int i = 0; i < this->size; i++)
		{
			if (!other.contains(this->data[i])) return false;
		}
		return true;
	}
	return false;
}

template <class T>
bool Vector<T>::operator!=(const Vector<T>& other)const
{
	return !(*this == other);
}

template <class T>
std::ostream& operator << (std::ostream& stream, const Vector<T>& v)
{

	stream << "[ ";
	for (size_t i = 0; i < v.getSize(); ++i)
	{
		std::cout << v[i] << " ";
	}
	stream << "]";

	return stream;
}