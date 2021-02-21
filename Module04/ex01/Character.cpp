/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:10:00 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:00:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character(std::string const & pname)
{
	this->_name = pname;
	this->_ap = 40;
	this->_weapon = NULL;
}

Character::Character( Character const & src )
{
	this->operator=(src);
}


Character::~Character( void )
{
}


Character &	Character::operator=( Character const & rhs )
{
	if (this != & rhs)
	{
		this->_name = rhs._name;
		this->_ap = rhs._ap;
		this->_weapon = rhs._weapon;
	}
	return ( *this );
}


void Character::recoverAP()
{
	std::cout << "\033[1;32m" << this->_name << " recover 10 Action Points!" << "\033[0;m" << std::endl;
	this->_ap = (this->_ap + 10 > 40) ? 40 : this->_ap + 10;
}


void Character::equip(AWeapon *pweapon)
{
		this->_weapon = pweapon;
}

void Character::attack(Enemy * penemy)
{
	if (this->_ap - this->_weapon->getAPCost() <= 0)
	{
		std::cout << "\033[1;31m" << this->_name << " needs more action points to attack "
		<< " with a " << this->_weapon->getName() << "\033[0;m" << std::endl;
		return;
	}
	if (!this->_weapon || penemy->getHP() == -1 || this->_weapon->getDamage() == -1)
		return;
	this->_ap -= this->_weapon->getAPCost();
	std::cout << "\033[1;31m" << this->_name << " attack " << penemy->getType() << " with a "
	<< this->_weapon->getName() << "\033[0;m" << std::endl;
	this->_weapon->attack();
	penemy->takeDamage(this->_weapon->getDamage());
	if (penemy->getHP() <= 0)
		delete (penemy);
}


std::string const  &Character::getName() const
{
	return(this->_name);
}

int					Character::getAP() const
{
	return (this->_ap);
}


bool				Character::getWeapon() const
{
	if (this->_weapon == NULL)
		return (0);
	return (1);
}

std::string const	&Character::getWeaponName() const
{
	return (this->_weapon->getName());
}


std::ostream &	operator<<( std::ostream &o, Character const & rhs )
{
	if (rhs.getWeapon() == 0)
		o << "\033[1;34m" << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << "\033[0;m" << std::endl;
	else
		o << "\033[1;34m" << rhs.getName() << " has " << rhs.getAP() << " AP and carries a " << rhs.getWeaponName() << "\033[0;m" << std::endl;
	return (o);
}