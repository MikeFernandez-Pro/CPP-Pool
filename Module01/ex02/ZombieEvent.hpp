/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:53:48 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 13:21:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_H
# define ZOMBIEEVENT_H

#include "Zombie.hpp"
#include "stdlib.h"

class	ZombieEvent {

public:

	ZombieEvent(int pnbZombies);
	~ZombieEvent();

	void	setZombieType(Zombie *Zombie);
	Zombie	*newZombie(std::string name);
	Zombie	*randomChump(Zombie *Zombies);
	void	CreateParty(void);

private :

		int	_nbZombies;
		std::string _types[10];
		std::string _names[10];
};

#endif