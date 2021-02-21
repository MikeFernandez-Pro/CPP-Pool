/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:13:12 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:03:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"


SuperMutant::SuperMutant( void ) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Break everything !" << std::endl;
}

SuperMutant::SuperMutant( SuperMutant const & src )
{
	this->operator=(src);
}


SuperMutant::~SuperMutant( void )
{
	std::cout << "Aaargh ..." << std::endl;
}


SuperMutant &	SuperMutant::operator=( SuperMutant const & rhs )
{
	(void)rhs;
	return ( *this );
}

void		SuperMutant::takeDamage(int damages)
{
	Enemy::takeDamage(damages - 3);
}
