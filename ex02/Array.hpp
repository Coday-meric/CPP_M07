//
// Created by aymeric on 20/09/23.
//

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <iostream>

template<typename T>
class Array {
private:
	T* _arr;
	unsigned int _size;
public:
	Array() : _arr(new T()), _size(0) {};

	Array(unsigned int nbr_elem) : _arr(new T[nbr_elem]), _size(nbr_elem) {};

	Array(Array const &src) : _arr(new T[src.size()]), _size(src.size()) {
		int i = 0;
		while (i < this->_size) {
			this->_arr[i] = src._arr[i];
			i++;
		}
	};

	~Array(){
		delete [] this->_arr;
	}

	Array &operator=(Array const &rhs) {
		if (this != &rhs) {
			delete[] this->_arr;
			this->_size = rhs.size();
			this->_arr = new T[rhs.size()];
			int i = 0;
			while (i < this->_size) {
				this->_arr[i] = rhs._arr[i];
				i++;
			}
		}
		return *this;
	};

	T &operator[](unsigned int nb) const {
		if (nb >= this->_size)
			throw OverflowIndex();
		return (this->_arr[nb]);
	};

	unsigned int size() const {
		return (this->_size);
	};

	class OverflowIndex : public std::exception {
	public:
		virtual const char *what() const throw() { return "Index is out of bounds"; }
	};
};

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
	for ( unsigned int i( 0 ); i < arr.size(); i++ )
		out << arr[i] << " ";
	return out;
}


#endif //ARRAY_HPP
