/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:52:39 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 13:21:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main(void)
{
	int nbZombies;

	std::cout << "Vous pouvez inviter entre un et vingt zombies à votre fête. " << std::endl;
	std::cout << "Combien de Zombies voulez-vous inviter à la \"Party\"?";
	std::cin >> nbZombies;
	std::cout << std::endl;
	if (nbZombies <= 0)
	{
		std::cout << "Désolé vous serez seul à votre fête.. (Comme d\'habitude)." << std::endl;
		return (0);
	}
	else if (nbZombies > 20)
	{
		std::cout << "Désolé mais il y a aura peu trop de monde." << std::endl;
		return (0);
	}
	ZombieEvent zombieParty(nbZombies);
	return 0;
}