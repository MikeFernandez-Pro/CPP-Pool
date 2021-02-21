/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:00:05 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:01:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"


Enemy::Enemy( void )
{
	this->_hp = 0;
	this->_type = "Elegant";
}


Enemy::Enemy(int hp, std::string const & type)
{
	this->_hp = hp;
	this->_type = type;
}


Enemy::Enemy( Enemy const & src )
{
	this->operator=(src);
}


Enemy::~Enemy( void )
{
	this->_hp = -1;
}


Enemy &	Enemy::operator=( Enemy const & rhs )
{
	if (this != & rhs)
	{
		this->_hp = rhs._hp;
		this->_type = rhs._type;
	}
	return ( *this );
}


std::string const & Enemy::getType() const
{
	return (this->_type);
}


int Enemy::getHP() const
{
	return (this->_hp);
}


void Enemy::takeDamage(int damages)
{
	if (damages < 0)
		return;
	this->_hp = (this->_hp - damages >= 0) ? this->_hp - damages : 0;
}
