/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:31:55 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 21:05:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator( void )
{
	std::cout << "* teleports from space *" << std::endl;
}


AssaultTerminator::AssaultTerminator( AssaultTerminator const & src )
{
	*this = src;
}


AssaultTerminator::~AssaultTerminator( void )
{
	std::cout << "I’ll be back ..." << std::endl;
}


AssaultTerminator &	AssaultTerminator::operator=( AssaultTerminator const & rhs )
{
	(void)rhs;
	return ( *this );
}


ISpaceMarine* 	AssaultTerminator::clone() const
{
	return (new AssaultTerminator(*this));
}


void 			AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. Purify it!" << std::endl;
}


void 			AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}


void 			AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}