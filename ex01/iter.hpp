//
// Created by aymeric on 20/09/23.
//

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename T >
void    iter( T *arr, size_t size, void (*f)(T &) )
{
	for ( size_t i = 0; i < size; i++ )
		f( arr[i] );
}

template < typename T >
void    print( T &i )
{
	std::cout << i << std::endl;
}

#endif //ITER_HPP
