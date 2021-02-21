/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:58:20 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 15:48:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Creature.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	return 0;
}
/*
int main()
{
	Sorcerer gandalf("Gandalf", "the White");

	Victim frodon("Frodo");
	Peon sam("Sam");
	Creature smeagol("Smeagol");
	
	std::cout << gandalf << frodon << sam << smeagol;

	gandalf.polymorph(frodon);
	gandalf.polymorph(sam);
	gandalf.polymorph(smeagol);

	return 0;
}*/