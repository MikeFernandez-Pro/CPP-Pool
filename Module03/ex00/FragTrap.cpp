/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:30:51 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 17:20:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap( void )
{
	this->_HitPoints = 100;
	this->_MaxHitPoints = 100;
	this->_EnergyPoints = 100;
	this->_MaxEnergyPoints = 100;
	this->_Level = 1;
	this->_Name = "Default";
	this->_MeleeAttackDamage = 30;
	this->_RangedAttackDamage = 20;
	this->_ArmorDamageReduction = 5;
	std::cout <<"FR4G-TP < \033[1;37m" << _Name << "> arrive sur la Grand-Place !" << std::endl;
}


FragTrap::FragTrap( std::string pName)
{
	this->_HitPoints = 100;
	this->_MaxHitPoints = 100;
	this->_EnergyPoints = 100;
	this->_MaxEnergyPoints = 100;
	this->_Level = 1;
	this->_Name = pName;
	this->_MeleeAttackDamage = 30;
	this->_RangedAttackDamage = 20;
	this->_ArmorDamageReduction = 5;
	srand(time(NULL));
	std::cout <<"FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > arrive sur la Grand-Place !" << std::endl;
}


FragTrap::FragTrap( FragTrap const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


FragTrap::~FragTrap( void )
{
	if (this->_Name == "Jordan")
		std::cout <<"FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > s'enfuit en courant!" << std::endl;
	else
		std::cout <<"FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > regarde son opposant partir avant de s'en aller lui aussi!" << std::endl;
}


FragTrap &	FragTrap::operator=( FragTrap const & rhs )
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


int			FragTrap::getMeleeAttackDamage(void)
{
	return (this->_MeleeAttackDamage);
}

int			FragTrap::getRangedAttackDamage(void)
{
	return (this->_RangedAttackDamage);
}

void	FragTrap::rangedAttack(std::string const & target)
{
	int reduction =  this->_RangedAttackDamage * ((float)this->_ArmorDamageReduction / 100);
	int damages =  this->_RangedAttackDamage - reduction;
	std::cout <<  "FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > attaque <" << target
	<< "> à distance, causant <" << damages << "> points de dégâts !" << std::endl;
}


void	FragTrap::meleeAttack(std::string const & target)
{
	int reduction =  this->_MeleeAttackDamage * ((float)this->_ArmorDamageReduction / 100);
	int damages =  this->_MeleeAttackDamage - reduction;
	std::cout <<  "FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > attaque <" << target
	<< "> au corps à corps, causant <" << damages << "> points de dégâts !" << std::endl;
}


void	FragTrap::takeDamage(unsigned int amount)
{
	
	int reduction = amount * ((float)this->_ArmorDamageReduction / 100);
	int damages = amount - reduction;

	if (damages == 0)
		return;
	this->_HitPoints = (this->_HitPoints - damages > 0) ? this->_HitPoints -= damages : 0;
	if (this->_HitPoints > 0)
		std::cout <<  "FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > subit <" << damages
		<< "> points de dégâts, son armure le protège de <" << reduction << "> points de dégats !"<< std::endl;
	else
		std::cout <<  "FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints
		<< "\033[0;m) > est vaincu mais vous pouvez toujours continuer le frapper !"<< std::endl;
	
}


void	FragTrap::beRepaired(unsigned int amount)
{
	this->_HitPoints = (this->_HitPoints + amount > 100) ? 100 : this->_HitPoints + amount;
	std::cout <<  "FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > se soigne de <" << amount
	<< "> points de vie !" << std::endl;
}


int		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	void	(FragTrap::*attack[2])(std::string const & target) = {&FragTrap::meleeAttack, &FragTrap::rangedAttack};
	int random = rand() % 2;

	std::string weapons[5] = {"une hachette de Viking", " un bâton \"très\" pointu", 
	"une épée pas si longue que ça", "une boule de feu", "un coup de pied la où ça fait mal"};
	if (this->_EnergyPoints >= 25)
	{
		this->_EnergyPoints -= 25;
		(this->*attack[random])(target);
		std::cout <<  "FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > utilise <" << weapons[rand() % 5]
		<< "> pour attaquer <" << target << "> et perd <25> points d'énergie !" << std::endl;
		if (random == 0)
			return (getMeleeAttackDamage());
		return (getRangedAttackDamage());
	}
	else
		std::cout <<  "FR4G-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints
		<< "\033[0;m) > n'a pas assez d'énergie pour attaquer !" << std::endl;
	return (0);
}

