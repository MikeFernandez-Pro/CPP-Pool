/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:34:48 by user42            #+#    #+#             */
/*   Updated: 2020/09/28 13:25:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const int Fixed::_Bits = 8;


Fixed::Fixed( void ) : _Value(0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


Fixed::Fixed( int const pValue ) 
{
    std::cout << "Int constructor called" << std::endl;
    this->_Value = pValue << this->_Bits;

}

Fixed::Fixed( float const pValue )
{
	std::cout << "Float constructor called" << std::endl;
    this->_Value = roundf(pValue * (1 << this->_Bits));
}


Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int			Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->_Value );
}


void		Fixed::setRawBits(int const raw)
{
	this->_Value = raw;
}


float Fixed::toFloat(void) const
{
    return ((float)(this->_Value) / (1 << this->_Bits));
}


int   Fixed::toInt(void) const
{
    return ((int)(this->_Value) >> this->_Bits);
}

Fixed &		Fixed::operator=( Fixed const &rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_Value = rhs.getRawBits();
	return ( *this );
}
std::ostream &	operator<<( std::ostream &o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return ( o );
}
