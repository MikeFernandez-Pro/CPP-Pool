/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:53:56 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 21:19:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}


Zombie::Zombie(std::string pName)
{
	this->_name = pName;
}


Zombie::~Zombie()
{
	std::cout << "Zombie has been destroyed !" << std::endl;
}


void	Zombie::advert() const
{
	std::cout << "<" << this->_name << " (" << this->_type
	<< ")> Braiiiiiiinnnssss ..." << std::endl;
}


void	Zombie::setType(std::string pType)
{
	this->_type = pType;
	advert();
}
