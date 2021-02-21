/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:20:43 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:14:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->_XP = 0;
	this->_type = "NULL";
}

AMateria::AMateria(AMateria const & src)
{
	this->operator=(src);
}

AMateria::AMateria(std::string const & type){
	this->_XP = 0;
	this->_type = type;
}

AMateria::~AMateria()
{
}

AMateria &					AMateria::operator=( AMateria const & rhs)
{
	if (&rhs != this)
	{
		this->_XP = rhs._XP;
		this->_type = rhs._type;
	}
	return (*this);
}

std::string const & 		AMateria::get_type() const
{
	return (this->_type);
}

unsigned int 				AMateria::get_XP() const{
	return (this->_XP);
}

void						AMateria::use(ICharacter& target)
{
	this->_XP += 10;
	if (this->get_type() == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->get_type() == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	else
		return ;
}