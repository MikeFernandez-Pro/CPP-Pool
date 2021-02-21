/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:08:12 by user42            #+#    #+#             */
/*   Updated: 2020/10/26 12:46:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span( unsigned int const & N) {
		this->_N = N;
}

Span::Span( Span const & src ) {
	this->operator=(src);
}

Span &	Span::operator=( Span const & rhs ) {
	if (this != & rhs)
	{
		this->_container = rhs._container;
		this->_N = rhs._N;
	}
	return ( *this );
}


void	Span::addNumber(int const & nb) {
	if (this->_container.size() < this->_N)
		this->_container.push_back(nb);
	else
		throw Span::ContainerFullException();
}

unsigned int		Span::longestSpan( void ) {
	if (this->_container.size() <= 1)
		throw Span::ContainerNotFullEnoughException();
	long int max = *(std::max_element(this->_container.begin(), this->_container.end()));
	long int min = *(std::min_element(this->_container.begin(), this->_container.end()));
	return (max - min);
}

unsigned int		Span::shortestSpan( void ) {
	if (this->_container.size() <= 1)
		throw Span::ContainerNotFullEnoughException();
	unsigned int min = UINT_MAX;
	sort(this->_container.begin(), this->_container.end()); 
	for (unsigned int i = 0; i < this->_container.size() -1; i++) 
		if (static_cast<unsigned int>(this->_container[i + 1] - this->_container[i]) < min) 
        	min = this->_container[i + 1] - this->_container[i]; 
   return (min);
}


Span::ContainerFullException::ContainerFullException( ContainerFullException const & src ) {
	this->operator=(src);
}


Span::ContainerFullException &	Span::ContainerFullException::operator=( ContainerFullException const & rhs ) {
	(void)rhs;
	return (*this);
}


const char* Span::ContainerFullException::what() const throw() {
	return ("\033[1;31mProblem exists : Container is full\033[0;m");
}



Span::ContainerNotFullEnoughException::ContainerNotFullEnoughException( ContainerNotFullEnoughException const & src ) {
	this->operator=(src);
}


Span::ContainerNotFullEnoughException &	Span::ContainerNotFullEnoughException::operator=( ContainerNotFullEnoughException const & rhs ) {
	(void)rhs;
	return (*this);
}


const char* Span::ContainerNotFullEnoughException::what() const throw() {
	return ("\033[1;31mProblem exists : Container needs more elements to compare\033[0;m");
}
