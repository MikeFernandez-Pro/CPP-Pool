/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:35:29 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 21:27:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	return 0;
}

/*
int main()
{
	ISpaceMarine* pat = new TacticalMarine;
	ISpaceMarine* fred = new AssaultTerminator;

	std::cout << "\033[1;33m" << "TEST CLONE : " << "\033[0;m" << std::endl << std::endl;
	ISpaceMarine* bob = pat->clone();
	bob->battleCry();
	ISpaceMarine* jim = fred->clone();
	jim->battleCry();
	std::cout << std::endl;
	delete pat;
	delete fred;
	
	std::cout << std::endl << "\033[1;33m" << " CREATION SQUAD : " << "\033[0;m" << std::endl << std::endl;
	Squad	*vlc = new Squad;
	std::cout <<  "Squad size = " << vlc->getCount() << std::endl;
	vlc->push(bob);
	std::cout <<  "Squad size = " << vlc->getCount() << std::endl;
	vlc->push(jim);
	std::cout <<  "Squad size = " << vlc->getCount() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST PUSH SQUAD DEJA PRESENTE: " << "\033[0;m" << std::endl << std::endl;
	vlc->push(jim);
	std::cout <<  "Squad size = " << vlc->getCount() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST PUSH NULL : " << "\033[0;m" << std::endl << std::endl;
	vlc->push(NULL);
	std::cout <<  "Squad size = " << vlc->getCount() << std::endl;

	std::cout << std::endl << "\033[1;33m" << "TEST SQUAD : " << "\033[0;m" << std::endl;
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		std::cout << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << std::endl << "\033[1;33m" << "REMOVE SQUADS : " << "\033[0;m" << std::endl << std::endl;
	
	delete vlc;

	return 0;
}*/