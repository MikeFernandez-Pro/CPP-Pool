/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:41:33 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:04:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"


int main()
{
	Character* moi = new Character("moi");
	std::cout << *moi;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	moi->equip(pr);
	std::cout << *moi;
	moi->equip(pf);
	moi->attack(b);
	std::cout << *moi;
	moi->equip(pr);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;

	return 0;
}

/*
int main()
{
	Character* SpaceMarine = new Character("SpaceMarine");
	std::cout << *SpaceMarine;
	Enemy* Scorpion = new RadScorpion();
	Enemy* Mutant = new SuperMutant();
	AWeapon* rifle = new PlasmaRifle();
	AWeapon* powerfist = new PowerFist();

	SpaceMarine->equip(rifle);
	std::cout << *SpaceMarine;
	SpaceMarine->equip(powerfist);
	SpaceMarine->attack(Scorpion);
	std::cout << *SpaceMarine;
	SpaceMarine->equip(rifle);
	std::cout << *SpaceMarine;
	SpaceMarine->attack(Scorpion);
	std::cout << *SpaceMarine;
	SpaceMarine->attack(Scorpion);
	std::cout << *SpaceMarine;
	SpaceMarine->equip(powerfist);
	SpaceMarine->attack(Mutant);
	std::cout << *SpaceMarine;
	SpaceMarine->attack(Mutant);
	std::cout << *SpaceMarine;
	SpaceMarine->attack(Mutant);
	std::cout << *SpaceMarine;
	SpaceMarine->recoverAP();
	std::cout << *SpaceMarine;
	SpaceMarine->recoverAP();
	std::cout << *SpaceMarine;
	SpaceMarine->attack(Mutant);
	std::cout << *SpaceMarine;
	SpaceMarine->attack(Mutant);
	std::cout << *SpaceMarine;
	
	return 0;
}*/
