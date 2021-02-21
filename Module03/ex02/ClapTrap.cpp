/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:30:51 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 15:06:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
	this->_HitPoints = 100;
	this->_MaxHitPoints = 100;
	this->_EnergyPoints = 50;
	this->_MaxEnergyPoints = 50;
	this->_Level = 1;
	this->_Name = "Default";
	this->_MeleeAttackDamage = 20;
	this->_RangedAttackDamage = 15;
	this->_ArmorDamageReduction = 3;
	srand(time(NULL));
	std::cout <<"CL4P-TP < \033[1;37m" << _Name << "> sort de sa cachette !" << "\033[0;m" << std::endl;
}


ClapTrap::ClapTrap( std::string pName)
{
	this->_HitPoints = 100;
	this->_MaxHitPoints = 100;
	this->_EnergyPoints = 50;
	this->_MaxEnergyPoints = 50;
	this->_Level = 1;
	this->_Name = pName;
	this->_MeleeAttackDamage = 20;
	this->_RangedAttackDamage = 15;
	this->_ArmorDamageReduction = 3;
	srand(time(NULL));
	std::cout <<"CL4P-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > sort de sa cachette !" << "\033[0;m" << std::endl;
}


ClapTrap::ClapTrap( ClapTrap const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


ClapTrap::~ClapTrap( void )
{
	std::cout <<"CL4P-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > a disparu sans laisser de trace !" << std::endl;
}


ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs )
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


int			ClapTrap::getMeleeAttackDamage(void)
{
	return (this->_MeleeAttackDamage);
}

int			ClapTrap::getRangedAttackDamage(void)
{
	return (this->_RangedAttackDamage);
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	int reduction =  this->_RangedAttackDamage * ((float)this->_ArmorDamageReduction / 100);
	int damages =  this->_RangedAttackDamage - reduction;
	std::cout <<  "CL4P-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > attaque <" << target
	<< "> à distance, causant <" << damages << "> points de dégâts !" << std::endl;
}


void	ClapTrap::meleeAttack(std::string const & target)
{
	int reduction =  this->_MeleeAttackDamage * ((float)this->_ArmorDamageReduction / 100);
	int damages =  this->_MeleeAttackDamage - reduction;
	std::cout <<  "CL4P-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > attaque <" << target
	<< "> au corps à corps, causant <" << damages << "> points de dégâts !" << std::endl;
}


void	ClapTrap::takeDamage(unsigned int amount)
{
	
	//std::cout << "here" << this->_ArmorDamageReduction / 100 << "et " << reduction << std::endl;
	int damages = amount - (amount * ((float)this->_ArmorDamageReduction / 100));
	int reduction = amount - damages;

	if (damages == 0)
		return;
	this->_HitPoints = (this->_HitPoints - damages > 0) ? this->_HitPoints -= damages : 0;
	if (this->_HitPoints > 0)
		std::cout <<  "CL4P-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > subit <" << damages
		<< "> points de dégâts, son armure le protège de <" << reduction << "> points de dégats !"<< std::endl;
	else
		std::cout <<  "CL4P-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
		<< "\033[0;m-\033[1;33m" << this->_EnergyPoints
		<< "\033[0;m) > est vaincu mais vous pouvez toujours continuer le frapper !"<< std::endl;
	
}


void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_HitPoints = (this->_HitPoints + amount > 100) ? 100 : this->_HitPoints + amount;
	std::cout <<  "CL4P-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > se soigne de <" << amount
	<< "> points de vie !" << std::endl;
}

void	ClapTrap::challengeNewcomer(void)
{
	bool			valid = 0;
	int				choice;
	std::string		challenges[5] = {"Riverwood", "le Bourg Palette", "la maison de tio Paco", "les terres de feu", "un bain chaud bien mérité"};

	std::cout <<  "CL4P-TP < \033[1;37m" << this->_Name << "\033[0;m(\033[1;31m" << this->_HitPoints
	<< "\033[0;m-\033[1;33m" << this->_EnergyPoints << "\033[0;m) > active la fonction challenge de son compagnon virtuelle." << std::endl;
	std::cout << std::endl << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Hola " << this->_Name << ", prêt pour de nouvelles aventures?" << std::endl;
	std::cout << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Dis moi, où nous menera notre prochaine destination ?" << std::endl << std::endl;
	std::cout << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Nous pourrions nous diriger vers Riverwood afin que tu devienne enfin un guerrier accompli : \033[1;31m0\033[0;m" << std::endl;
	std::cout << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Ou bien au Bourg Palette afin de devenir le meilleur dresseur de tous les temps : \033[1;31m1\033[0;m" << std::endl;
	std::cout << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Et pourquoi pas à la maison de mon oncle Paco? Il fait d'excellents mojitos ! : \033[1;31m2\033[0;m" << std::endl;
	std::cout << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Où peut être as-tu encore soif de sang et souhaiterais affronter le terrible seigneur Ragnaros des terres de feu ? : \033[1;31m3\033[0;m" << std::endl;
	std::cout << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Sinon on peut tout aussi bien rentrez à la maison  prendre un bon bain chaud bien mérité : \033[1;31m4\033[0;m" << std::endl;
	std::cout << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Quel est ton choix : ";
	while (valid != 1)
	{
		std::cin >> choice;
		if (choice >= 0 && choice < 5)
			valid = 1;
		else 
			std::cout << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Désolé mais cette destination n'existe pas, choisis-en une autre" << std::endl;
	}
	std::cout << std::endl << "Acolyte\033[1;37m" << " - < Sandy >" << "\033[0;m" << " - Très bon choix ! Dans ce cas là, en route pour \033[1;36m < " << challenges[choice] << " >\033[0;m !" << std::endl << std::endl;
}
