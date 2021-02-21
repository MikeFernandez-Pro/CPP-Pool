/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 20:07:52 by user42            #+#    #+#             */
/*   Updated: 2020/10/26 11:10:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <vector>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
#include <limits.h>
#include <map>

class	Span
{

	public:

		Span(unsigned int const & N);
		Span( Span const & src );
		virtual ~Span( void ) {}
		Span &	operator=( Span const & rhs );
		void	addNumber(int const & nb);
		unsigned int	shortestSpan( void );
		unsigned int	longestSpan( void );

		class BadInitializationException : public std::exception
		{

			public:
				BadInitializationException( void ) {}
				BadInitializationException( BadInitializationException const & src );
				virtual ~BadInitializationException( void ) throw() {}
				BadInitializationException &	operator=( BadInitializationException const & rhs );
				virtual const char* what() const throw();
		};

		class ContainerFullException : public std::exception
		{

			public:
				ContainerFullException( void ) {}
				ContainerFullException( ContainerFullException const & src );
				virtual ~ContainerFullException( void ) throw() {}
				ContainerFullException &	operator=( ContainerFullException const & rhs );
				virtual const char* what() const throw();
		};

		class ContainerNotFullEnoughException : public std::exception
		{

			public:
				ContainerNotFullEnoughException( void ) {}
				ContainerNotFullEnoughException( ContainerNotFullEnoughException const & src );
				virtual ~ContainerNotFullEnoughException( void ) throw() {}
				ContainerNotFullEnoughException &	operator=( ContainerNotFullEnoughException const & rhs );
				virtual const char* what() const throw();
		};


	private :

	std::vector<int>	_container;
	unsigned int	_N;

	Span( void ) {}

};

#endif