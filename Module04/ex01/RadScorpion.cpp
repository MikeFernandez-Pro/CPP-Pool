/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:03:01 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:03:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"


RadScorpion::RadScorpion( void ) : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion( RadScorpion const & src )
{
	this->operator=(src);
}


RadScorpion::~RadScorpion( void )
{
	std::cout << "* SPROTCH *" << std::endl;
}


RadScorpion &	RadScorpion::operator=( RadScorpion const & rhs )
{
	(void)rhs;
	return ( *this );
}