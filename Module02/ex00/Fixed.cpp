/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:34:48 by user42            #+#    #+#             */
/*   Updated: 2020/09/27 11:32:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_Bits = 8;

Fixed::Fixed( void ) : _Integer (0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int			Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->_Integer);
}

void		Fixed::setRawBits(int const raw)
{
	this->_Integer = raw;
}

Fixed &		Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	this->_Integer = rhs.getRawBits();
	return ( *this );
}
std::ostream &	operator<<( std::ostream &o, Fixed const & rhs )
{
	o << rhs.getRawBits();
	return ( o );
}
