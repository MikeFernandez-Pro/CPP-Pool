/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:18:44 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 21:19:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"


Squad::Squad( void )
{
}


Squad::Squad( Squad const & src )
{
	Squad::operator=(src);
}


Squad::~Squad( void )
{
	for (unsigned int i = 0; i < this->_Units.size(); i++)
	{
		delete (this->_Units[i]);
		this->_Units[i] = NULL;
	}
}

Squad &	Squad::operator=( Squad const & rhs )
{
	std::vector<ISpaceMarine*>::const_iterator it = this->_Units.end();
	while (it != this->_Units.begin())
	{
		delete (*it);
		this->_Units.pop_back();
		--it;
	}
	for (unsigned int i = 0; i < rhs._Units.size(); i++)
		this->_Units.push_back(rhs._Units[i]->clone());
	return (*this);
}

int Squad::getCount() const
{
	return (this->_Units.size());
}


ISpaceMarine* Squad::getUnit(int N) const
{
	if (this->getCount() <= 0 || this->getCount() < N || N < 0)
		return NULL;
	return (this->_Units[N]);
}


int Squad::push(ISpaceMarine *ptr)
{
	unsigned int i = -1;
	if (ptr == NULL)
		return 0;
	while (++i < this->_Units.size())
	{
		if (ptr == this->_Units[i])
			return (0);
	}
	this->_Units.push_back(ptr);
	return (1);
}
