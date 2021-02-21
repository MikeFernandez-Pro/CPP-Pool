/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:56:25 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 15:41:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"


Sorcerer::Sorcerer( std::string pName, std::string pTitle )
{
	this->_Name = pName;
	this->_Title = pTitle;
	std::cout << this->_Name << ", " << this->_Title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer( Sorcerer const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


Sorcerer::~Sorcerer( void )
{
	std::cout << this->_Name << ", " << this->_Title << ", is dead. Consequences will never be the same!" << std::endl;
}


Sorcerer &	Sorcerer::operator=( Sorcerer const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != & rhs)
	{
		this->_Name = rhs._Name;
		this->_Title = rhs._Title;
	}
	return ( *this );
}


std::string		Sorcerer::getName( void ) const
{
	return ( this->_Name );
}


std::string		Sorcerer::getTitle( void ) const
{
	return ( this->_Title );
}

void 		Sorcerer::polymorph( Victim const & pVictim) const
{
	pVictim.getPolymorphed();
}


void 		Sorcerer::polymorph( Creature const & pCreature) const
{
	pCreature.getPolymorphed();
}


std::ostream &	operator<<( std::ostream &o, Sorcerer const & rhs )
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle()
	<< ", and i like ponies!" << std::endl;
	return (o);
}