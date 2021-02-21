/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:30:51 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 15:06:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap( void )
{
	this->_HitPoints = FragTrap::_HitPoints;
	this->_MaxHitPoints = FragTrap::_MaxHitPoints;
	this->_EnergyPoints = NinjaTrap::_EnergyPoints;
	this->_MaxEnergyPoints = NinjaTrap::_MaxEnergyPoints;
	this->_Level = 1;
	this->_MeleeAttackDamage = NinjaTrap::_MeleeAttackDamage;
	this->_RangedAttackDamage = FragTrap::_RangedAttackDamage;
	this->_ArmorDamageReduction = FragTrap::_ArmorDamageReduction;
	srand(time(NULL));
	std::cout <<"SUP3R-TP < \033[1;37m" << _Name << "> arrive en volant." << "\033[0;m" << std::endl;
}


SuperTrap::SuperTrap( std::string pName) : ClapTrap(pName), FragTrap(pName), NinjaTrap(pName)
{
	this->_HitPoints = FragTrap::_HitPoints;
	this->_MaxHitPoints = FragTrap::_MaxHitPoints;
	this->_EnergyPoints = NinjaTrap::_EnergyPoints;
	this->_MaxEnergyPoints = NinjaTrap::_MaxEnergyPoints;
	this->_Level = 1;
	this->_MeleeAttackDamage = NinjaTrap::_MeleeAttackDamage;
	this->_RangedAttackDamage = FragTrap::_RangedAttackDamage;
	this->_ArmorDamageReduction = FragTrap::_ArmorDamageReduction;
	srand(time(NULL));
	std::cout <<"SUP3R-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > arrive en volant." << "\033[0;m" << std::endl;
}


SuperTrap::SuperTrap( SuperTrap const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


SuperTrap::~SuperTrap( void )
{
	std::cout <<"SUP3R-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > s'envole vers d'autres cieux !" << std::endl;
}


SuperTrap &	SuperTrap::operator=( SuperTrap const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != & rhs)
	{
		this->_HitPoints = rhs._HitPoints;
		this->_MaxHitPoints = rhs._MaxHitPoints;
		this->_EnergyPoints = rhs._EnergyPoints;
		this->_MaxEnergyPoints = rhs._MaxEnergyPoints;
		this->_Level = rhs._Level;
		this->_Name = rhs._Name;
		this->_MeleeAttackDamage =  rhs._MeleeAttackDamage;
		this->_RangedAttackDamage =  rhs._RangedAttackDamage;
		this->_ArmorDamageReduction = rhs._ArmorDamageReduction;
	}
	return ( *this );
}


void	SuperTrap::rangedAttack(std::string const & target)
{
	int reduction =  this->_RangedAttackDamage * ((float)this->_ArmorDamageReduction / 100);
	int damages =  this->_RangedAttackDamage - reduction;
	std::cout <<  "SUP3R-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > attaque <" << target
	<< "> à distance, causant <" << damages << "> points de dégâts !" << std::endl;
}


void	SuperTrap::meleeAttack(std::string const & target)
{
	int reduction =  this->_MeleeAttackDamage * ((float)this->_ArmorDamageReduction / 100);
	int damages =  this->_MeleeAttackDamage - reduction;
	std::cout <<  "SUP3R-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > attaque <" << target
	<< "> au corps à corps, causant <" << damages << "> points de dégâts !" << std::endl;
}


void	SuperTrap::takeDamage(unsigned int amount)
{
	int damages = amount - (amount * ((float)this->_ArmorDamageReduction / 100));
	int reduction = amount - damages;

	if (damages == 0)
		return;
	this->_HitPoints = (this->_HitPoints - damages > 0) ? this->_HitPoints -= damages : 0;
	if (this->_HitPoints > 0)
		std::cout <<  "SUP3R-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > subit <" << damages
		<< "> points de dégâts, son armure le protège de <" << reduction << "> points de dégats !"<< std::endl;
	else
		std::cout <<  "SUP3R-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints
		<< "\033[0;m) > est vaincu mais vous pouvez toujours continuer le frapper !"<< std::endl;
	
}


void	SuperTrap::beRepaired(unsigned int amount)
{
	this->_HitPoints = (this->_HitPoints + amount > 100) ? 100 : this->_HitPoints + amount;
	std::cout <<  "SUP3R-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > se soigne de <" << amount
	<< "> points de vie !" << std::endl;
}