/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:53:53 by user42            #+#    #+#             */
/*   Updated: 2020/10/06 10:38:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int	pnbZombies)
{
	std::string ptypes[10] = {"Nostalgique", "Négligé",
	"Sans yeux", "Moustachu", "Publicitaire", "Pacifiste",
	"Colossale", "Magicien", "Nageur", "Flibustier"};	
	std::string pnames[10] = {"Gustave", "Steve", "Cunégond",
	"Charles-Antoine", "Elisabeth", "Brittany", "Pascal",
	"Dimitri", "Chantal", "Dominique"};
	
	std::cout << "The ZombieHorde is created !" << std::endl << std::endl;
	this-> _nbZombies = pnbZombies;
	for (int i = 0; i < 10; i++)
		this->_types[i] = ptypes[i];
	for (int i = 0; i < 10; i++)
		this->_names[i] = pnames[i];
	srand(time(NULL));
	CreateParty();
}

ZombieHorde::~ZombieHorde()
{
	std::cout << std::endl ;
	for (int i = 0; i < this->_nbZombies; i++)
		delete (_Zombies[i]);
	std::cout << "The ZombieHorde is destroyed !" << std::endl;
}

void	ZombieHorde::setZombieType(Zombie *Zombie)
{
	Zombie->setType(this->_types[rand() % 10]);
}

Zombie	*ZombieHorde::newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	setZombieType(newZombie);
	return (newZombie);
}

Zombie	*ZombieHorde::randomChump(Zombie *Zombies)
{
	Zombies = newZombie(this->_names[rand() % 10]);
	Zombies->announce();
	return (Zombies);
}

void	ZombieHorde::CreateParty(void)
{
	this->_Zombies = new Zombie*[this->_nbZombies];
	for (int i = 0; i < this->_nbZombies; i++)
	{
		this->_Zombies[i] = randomChump(this->_Zombies[i]);
		
	}
}

void	ZombieHorde::announce()
{
	 for (int i = 0; i < _nbZombies; i++)
        _Zombies[i]->announce();
}