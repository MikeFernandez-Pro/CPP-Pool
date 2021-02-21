/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:44:54 by user42            #+#    #+#             */
/*   Updated: 2020/10/22 13:46:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	ARRAY_HPP
#define	ARRAY_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <exception>


class OutLimitsException : public std::exception
{
	public:
		OutLimitsException() {}
		OutLimitsException(const OutLimitsException &m) {
				if (this != &m)
					this->operator=(m);
		}
		OutLimitsException& operator=(const OutLimitsException &m) {
				(void)m;
				return(*this);
		}
		virtual ~OutLimitsException(void) throw() {}
		char const *what(void) const throw(){
			return("\033[1;31mErrorOut of limits\033[0;m");
		}
};

template< typename T>
class Array
{
	public:
		Array(void) : _array(NULL), _n(0) {}
		Array(unsigned int n) : _array(new T[n]), _n(n) {}
		Array(Array const & src) : _array(NULL), _n(0) {
			Array::operator=(src);
		}
		virtual ~Array(void){
			delete[] this->_array;
		}
		Array &				operator=( Array const & src){
			if (this->_array != NULL)
				delete[] this->_array;
			this->_n = src._n;
			if (this->_n == 0)
				this->_array = NULL;
			else{
				this->_array = new T[this->_n];
				for (size_t i = 0; i < this->_n; i++){
					this->_array[i] = src._array[i];
				}
			}
			return (*this);
		}
		T &					operator[](unsigned long i) const{
			if (i >= this->_n || i < 0)
				throw (OutLimitsException());
			return (this->_array[i]);
		}
		size_t				size() const{
			return (this->_n);
		}
	

	private:
		T*		_array;
		size_t	_n;
};

template<typename T>
const T *	const	copy(const Array<T> & src, size_t j)
{
	try{
		src.operator[](0);
	} 
	catch (std::exception &e){
	}
	T* array = new T[j];
		for (size_t i = 0; i < j; i++){
			array[i] = src[i];
		}
	return (array);
}

template<typename T>
class Array<const T>
{
	public:
		Array(void) : _array(NULL), _n(0) {}
		Array(unsigned int n) : _array(new T[n]), _n(n) {}
		Array(Array<T> const & src) : _array(copy(src, src.size())), _n(src.size()){}

		virtual ~Array(void){
			delete[] this->_array;
		}

		Array &				operator=( Array const & src){
			(void)src;
			return (*this);
		}
		const T &					operator[](unsigned long i) const{
			if (i >= this->_n || i < 0)
				throw (OutLimitsException());
			return (this->_array[i]);
		}
		size_t				size() const{
			return (this->_n);
		}
	

	private:
		const T*		const _array;
		size_t	_n;
};

#endif
