/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:56:40 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 15:43:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"


Victim::Victim( std::string pName )
{
	this->_Name = pName;
	std::cout << "Some random victim called " << this->_Name << " just appeared!" << std::endl;
}


Victim::Victim( Victim const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


Victim::~Victim( void )
{
	std::cout << "Victim " << this->_Name << " just died for no apparent reason!" << std::endl;
}


Victim &	Victim::operator=( Victim const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != & rhs)
	{
		this->_Name = rhs._Name;
	}
	return ( *this );
}

std::string	Victim::getName( void ) const
{
	return ( this->_Name );
}

void		Victim::getPolymorphed() const
{
	std::cout << this->_Name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &	operator<<( std::ostream &o, Victim const & rhs )
{
	o << "I'm " << rhs.getName() << " and I like otters!" << std::endl;
	return (o);
}