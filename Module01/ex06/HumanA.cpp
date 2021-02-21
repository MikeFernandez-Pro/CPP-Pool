/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 22:28:53 by user42            #+#    #+#             */
/*   Updated: 2020/09/25 13:04:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string pname, Weapon &pWeapon) : _name(pname) , _weaponType(pWeapon)
{
	std::cout << "\033[1;32mBob is created!\033[0;m" << std::endl << std::endl;
}

HumanA::~HumanA()
{
	std::cout << std::endl << "\033[1;31mBob is destroyed!\033[0;m" << std::endl << std::endl;
	std::cout << "----------------------------" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name  << " attacks with his " << this->_weaponType.getType() << std::endl;
}
