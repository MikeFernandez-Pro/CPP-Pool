/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 22:30:18 by user42            #+#    #+#             */
/*   Updated: 2020/09/25 11:59:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon()
{
}

Weapon::Weapon(std::string pweapon) : _type(pweapon)
{
}

Weapon::~Weapon()
{
}

std::string	Weapon::getType()
{
	std::string &ref = this->_type; // const
	return (ref);
}

void	Weapon::setType(std::string ptype)
{
	this->_type = ptype;
}