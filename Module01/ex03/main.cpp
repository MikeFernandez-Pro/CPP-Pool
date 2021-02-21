/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:52:39 by user42            #+#    #+#             */
/*   Updated: 2020/10/06 11:31:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main(void)
{
	int nbZombies;

	std::cout << "Vous pouvez créer une horde de un a vingt zombies. " << std::endl;
	std::cout << "Combien de Zombies voulez-vous ajouter a votre horde?";
	std::cin >> nbZombies;
	std::cout << std::endl;
	if (nbZombies <= 0)
	{
		std::cout << "Désolé mais ceci ne ressemble pas a une horde." << std::endl;
		return (0);
	}
	else if (nbZombies > 20)
	{
		std::cout << "Désolé mais il y a aura peu trop de monde." << std::endl;
		return (0);
	}
	ZombieHorde zombieParty(nbZombies);
	return 0;
}