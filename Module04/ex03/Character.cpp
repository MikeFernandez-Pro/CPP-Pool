/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:21:04 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:15:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character(std::string name)
{
	this->_name = name;
	this->_nbMateria = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

Character::Character(Character const & src)
{
	Character::operator=(src);
}

Character::~Character()
{
	suppr_materia(this->_inventory);
}

Character &					Character::operator=( Character const & rhs)
{
	this->_name = rhs._name;
	this->_nbMateria = rhs._nbMateria;
	suppr_materia(this->_inventory);
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i]= rhs._inventory[i]->clone();
	return (*this);
}

std::string const & 		Character::getName() const
{
	return (this->_name);
}

void 						Character::equip(AMateria* m)
{
	if (this->_nbMateria == 4)
		return ;
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] == m)
			return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == 0){
			this->_inventory[i] = m; 
			break ;
		}
	}
	
	this->_nbMateria += 1;
}

void 						Character::unequip(int idx)
{
	if (idx > 3 || idx < 0 || this->_inventory[idx] == 0)
		return ;
	this->_inventory[idx] = 0;
	this->_nbMateria -= 1;
}

void 						Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || this->_inventory[idx] == 0)
		return ;
	this->_inventory[idx]->use(target);
}

void							suppr_materia(AMateria **inventory)
{
	for (int i = 0; i < 4; i++){
		delete inventory[i];
		inventory[i] = 0;
	}
}