/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:42:32 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 17:40:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	this->_eggs = 3;
	this->_milk = 1;
	this->_sugar = 150;
	this->_vanilla = 3;
}

Brain::Brain(int peggs, int pmilk, int psugar, int pvanilla)
{
	this->_eggs = peggs;
	this->_milk = pmilk;
	this->_sugar = psugar;
	this->_vanilla = pvanilla;
}

Brain::~Brain()
{
}

const void			*Brain::identify() const
{
	return (this);
}