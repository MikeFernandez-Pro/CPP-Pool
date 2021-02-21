/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:53:53 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 13:19:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(int	pnbZombies) 
{
	std::string ptypes[10] = {"Nostalgique", "Négligé",
	"Sans yeux", "Moustachu", "Publicitaire", "Pacifiste",
	"Colossale", "Magicien", "Nageur", "Flibustier"};
	std::string pnames[10] = {"Gustave", "Steve", "Cunégond",
	"Charles-Antoine", "Elisabeth", "Brittany", "Pascal",
	"Dimitri", "Chantal", "Dominique"};

	this->_nbZombies = pnbZombies;
	for (int i = 0; i < 10; i++)
		this->_types[i] = ptypes[i];
	for (int i = 0; i < 10; i++)
		this->_names[i] = pnames[i];
	
	std::cout << "The ZombieParty is created !" << std::endl << std::endl;;
	srand(time(NULL));
	CreateParty();
}


ZombieEvent::~ZombieEvent()
{
	std::cout << "The ZombieParty is destroyed !" << std::endl;
}


void	ZombieEvent::setZombieType(Zombie *Zombie)
{
	Zombie->setType(this->_types[rand() % 10]);
}


Zombie	*ZombieEvent::newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	this->setZombieType(newZombie);
	return (newZombie);
}


Zombie	*ZombieEvent::randomChump(Zombie *Zombies)
{
	Zombies = this->newZombie(this->_names[rand() % 10]);
	return (Zombies);
}


void	ZombieEvent::CreateParty(void)
{
	Zombie *Zombies[this->_nbZombies];
	
	for (int i = 0; i < this->_nbZombies; i++)
		Zombies[i] = this->randomChump(Zombies[i]);
	std::cout << std::endl ;
	for (int i = 0; i < this->_nbZombies; i++)
		delete (Zombies[i]);
	std::cout << std::endl;
}