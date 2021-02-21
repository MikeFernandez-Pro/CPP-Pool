/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:30:51 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 15:06:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap( void )
{
	this->_HitPoints = 60;
	this->_MaxHitPoints = 60;
	this->_EnergyPoints = 120;
	this->_MaxEnergyPoints = 120;
	this->_Level = 1;
	this->_Name = "Default";
	this->_MeleeAttackDamage = 60;
	this->_RangedAttackDamage = 5;
	this->_ArmorDamageReduction = 0;
	srand(time(NULL));
	std::cout <<"NINJ4-TP < \033[1;37m" << _Name << "> arrive en bondissant depuis un toit." << "\033[0;m" << std::endl;
}


NinjaTrap::NinjaTrap( std::string pName) : ClapTrap(pName)
{
	this->_HitPoints = 60;
	this->_MaxHitPoints = 60;
	this->_EnergyPoints = 120;
	this->_MaxEnergyPoints = 120;
	this->_Level = 1;
	this->_Name = pName;
	this->_MeleeAttackDamage = 60;
	this->_RangedAttackDamage = 5;
	this->_ArmorDamageReduction = 0;
	srand(time(NULL));
	std::cout <<"NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > arrive en bondissant depuis un toit." << "\033[0;m" << std::endl;
}


NinjaTrap::NinjaTrap( NinjaTrap const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


NinjaTrap::~NinjaTrap( void )
{
	std::cout <<"NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > s'en va sautant de toit en toit !" << std::endl;
}


NinjaTrap &	NinjaTrap::operator=( NinjaTrap const & rhs )
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


void	NinjaTrap::rangedAttack(std::string const & target)
{
	int reduction =  this->_RangedAttackDamage * ((float)this->_ArmorDamageReduction / 100);
	int damages =  this->_RangedAttackDamage - reduction;
	std::cout <<  "NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > attaque <" << target
	<< "> à distance, causant <" << damages << "> points de dégâts !" << std::endl;
}


void	NinjaTrap::meleeAttack(std::string const & target)
{
	int reduction =  this->_MeleeAttackDamage * ((float)this->_ArmorDamageReduction / 100);
	int damages =  this->_MeleeAttackDamage - reduction;
	std::cout <<  "NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > attaque <" << target
	<< "> au corps à corps, causant <" << damages << "> points de dégâts !" << std::endl;
}


void	NinjaTrap::takeDamage(unsigned int amount)
{
	int damages = amount - (amount * ((float)this->_ArmorDamageReduction / 100));
	int reduction = amount - damages;

	if (damages == 0)
		return;
	this->_HitPoints = (this->_HitPoints - damages > 0) ? this->_HitPoints -= damages : 0;
	if (this->_HitPoints > 0)
		std::cout <<  "NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > subit <" << damages
		<< "> points de dégâts, son armure le protège de <" << reduction << "> points de dégats !"<< std::endl;
	else
		std::cout <<  "NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints
		<< "\033[0;m) > est vaincu mais vous pouvez toujours continuer le frapper !"<< std::endl;
	
}


void	NinjaTrap::beRepaired(unsigned int amount)
{
	this->_HitPoints = (this->_HitPoints + amount > 100) ? 100 : this->_HitPoints + amount;
	std::cout <<  "NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > se soigne de <" << amount
	<< "> points de vie !" << std::endl;
}


void		NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	std::cout <<  "NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > regarde son ami " << target.getName() << " le CL4P-TP partir." << std::endl;
}


void		NinjaTrap::ninjaShoebox(FragTrap &target)
{
	std::cout <<  "NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > regarde son ami " << target.getName() << " le FR4G-TP partir." << std::endl;
}


void		NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	std::cout <<  "NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > regarde son ami " << target.getName() << " le SC4V-TP partir." << std::endl;
}


void		NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	std::cout <<  "NINJ4-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > regarde son ami " << target.getName() << " le NINJ4-TP partir." << std::endl;
}

