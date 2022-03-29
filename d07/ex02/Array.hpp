#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
	Array<T>(void) : _size(0)
	{
		this->_array = nullptr;
	}

	Array<T>(unsigned int n) : _size(n)
	{
		this->_array = new T[n];
	}

	Array<T>(Array<T> const &src)
	{
		*this = src;
	}

	Array &operator=(Array<T> const &src)
	{
		if (this->_array != NULL)
			delete[] this->_array;

		this->_size = src.size();
		this->_array = new T[this->_size];
		for (int i = 0; i < this->_size; i++)
		{
			this->_array[i] = src[i];
		}
		return *this;
	}

	T &operator[](int n)
	{
		if (this->_size <= static_cast<unsigned int>(n))
		{
			throw Array<T>::Limit();
		}
		else
			return this->_array[n];
	}

		void *operator new(size_t t)
		{
			return new T[t];
		}

		unsigned int size()
		{
			return this->_size;
		}
		class Limit : public std::exception
		{
		public:
			virtual ~Limit() throw() { }
			Limit() {} 
			Limit(Limit const &src)
			{
				*this = src;
			}
			Limit &operator=(Limit const &src)
			{
				*this = src;
				return (*this);
			}
			virtual const char *what() const throw()
			{
				return "Out of bound";
			}
		};

	private:
		T *_array;
		unsigned int _size;
};

#endif
