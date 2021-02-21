/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Creature.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:56:40 by user42            #+#    #+#             */
/*   Updated: 2020/10/07 10:42:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Creature.hpp"

Creature::Creature( std::string pName )
{
	this->_Name = pName;
	std::cout << "A random Creature called " << this->_Name << " just appeared!" << std::endl;
}


Creature::Creature( Creature const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


Creature::~Creature( void )
{
	std::cout << "Creature " << this->_Name << " just died consumed in the molten lava!" << std::endl;
}


Creature &	Creature::operator=( Creature const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != & rhs)
	{
		this->_Name = rhs._Name;
	}
	return ( *this );
}

std::string	Creature::getName( void ) const
{
	return ( this->_Name );
}

void		Creature::getPolymorphed() const
{
	std::cout << this->_Name << " has been turned into Gollum!" << std::endl;
}

std::ostream &	operator<<( std::ostream &o, Creature const & rhs )
{
	o << "I'm " << rhs.getName() << " and I love my Precious one!" << std::endl;
	return (o);
}