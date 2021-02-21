/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:21:37 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:16:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(Ice const & src)
{
	Ice::operator=(src);
}

Ice::~Ice()
{

}

Ice &					Ice::operator=( Ice const & rhs)
{
	if (this != &rhs)
	{
		AMateria::operator=(rhs);
	}
	return (*this);
}

AMateria*				Ice::clone() const
{
	return (new Ice(*this));
}