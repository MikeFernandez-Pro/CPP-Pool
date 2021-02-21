/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:47:24 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:01:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"


PlasmaRifle::PlasmaRifle( void ) : AWeapon("Plasma Rifle", 5 , 21)
{
}


PlasmaRifle::PlasmaRifle(std::string const & name, int apcost, int damage) : AWeapon(name, apcost, damage)
{
}


PlasmaRifle::PlasmaRifle( PlasmaRifle const & src )
{
	this->operator=(src);
}


PlasmaRifle::~PlasmaRifle( void )
{
}


PlasmaRifle &	PlasmaRifle::operator=( PlasmaRifle const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != & rhs)
		AWeapon::operator=(rhs);
	return ( *this );
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
