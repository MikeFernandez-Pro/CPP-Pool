/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 22:30:04 by user42            #+#    #+#             */
/*   Updated: 2020/09/25 13:01:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string pname) : _name(pname)
{
	std::cout << std::endl << "\033[1;32mJim is created!\033[0;m" << std::endl << std::endl;
}

HumanB::~HumanB()
{
	std::cout << std::endl << "\033[1;31mJim is destroyed!\033[0;m" << std::endl;
}

void	HumanB::attack()
{
	std::cout << this->_name << " attack with his " << this->_weaponType->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &pWeapon)
{
	this->_weaponType = &pWeapon;
}