/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:49:59 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:01:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"


PowerFist::PowerFist( void ) : AWeapon("Power Fist", 8, 50)
{
}


PowerFist::PowerFist(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage)
{
}

PowerFist::PowerFist( PowerFist const & src )
{
	this->operator=(src);
}


PowerFist::~PowerFist( void )
{
}


PowerFist &	PowerFist::operator=( PowerFist const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != & rhs)
		AWeapon::operator=(rhs);
	return ( *this );
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM ! *" << std::endl;
}
