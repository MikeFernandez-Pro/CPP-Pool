/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:34:48 by user42            #+#    #+#             */
/*   Updated: 2020/09/27 22:49:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const int Fixed::_Bits = 8;


Fixed::Fixed( void ) : _Value(0)
{
}


Fixed::Fixed( Fixed const & src )
{
	*this = src;
}


Fixed::Fixed( int const pValue ) 
{
    this->_Value = pValue << this->_Bits;
}

Fixed::Fixed( float const pValue )
{
    this->_Value = roundf(pValue * (1 << this->_Bits));
}


Fixed::~Fixed( void )
{
}

int			Fixed::getRawBits( void ) const
{
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
	if (this != &rhs)
		this->_Value = rhs.getRawBits();
	return ( *this );
}


Fixed		Fixed::operator+( Fixed const &rhs ) const
{
	return Fixed((this->toFloat() + rhs.toFloat()));
}


Fixed		Fixed::operator-( Fixed const &rhs ) const
{
	return Fixed((this->toFloat() - rhs.toFloat()));
}


Fixed		Fixed::operator*( Fixed const &rhs ) const
{
	return Fixed((this->toFloat() * rhs.toFloat()));
}


Fixed		Fixed::operator/( Fixed const &rhs ) const
{
	return Fixed((this->toFloat() / rhs.toFloat()));
}


bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->_Value > rhs._Value);
}


bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->_Value >= rhs._Value);
}


bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->_Value < rhs._Value);
}


bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->_Value <= rhs._Value);
}


bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->_Value == rhs._Value);
}


bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->_Value != rhs._Value);
}


Fixed &Fixed::operator++(void) 
{
    this->_Value += 1;
    return (*this);
}

Fixed &Fixed::operator--(void) 
{
    this->_Value -= 1;
    return (*this);
}

Fixed Fixed::operator++(int) 
{
	Fixed obj(*this);
    this->_Value += 1;
    return (obj);
}

Fixed Fixed::operator--(int) 
{
	Fixed obj(*this);
    this->_Value -= 1;
    return (obj);
}


const Fixed  &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}


const Fixed  &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}


Fixed  &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}


Fixed  &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}


std::ostream &	operator<<( std::ostream &o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return ( o );
}
