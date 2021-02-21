/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:21:55 by user42            #+#    #+#             */
/*   Updated: 2020/10/18 13:29:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* moi = new Character("moi");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	moi->equip(tmp);
	tmp = src->createMateria("cure");
	moi->equip(tmp);
	ICharacter* bob = new Character("bob");
	moi->use(0, *bob);
	moi->use(1, *bob);
	delete bob;
	delete moi;
	delete src;
	return 0;
}


/*
int main() {

	IMateriaSource* src = new MateriaSource();

	std::cout << "\033[1;33m" << "TEST EQUIP 4 MATERIA A LA SOURCE" << "\033[0;m" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	std::cout << "\033[1;33m" << "TEST AJOUT 5EME MATERIA" << "\033[0;m" << std::endl;
	Cure *test = new Cure();
	src->learnMateria(test);
	delete test;
	
	ICharacter* Mage = new Character("Gandalf");
	ICharacter* Sauron = new Character("Sauron");
	AMateria* tmp;
	AMateria* tmp2;

	std::cout << "\033[1;33m" << "TEST UTILISATION AJOUT D'UNE MATERIA" << "\033[0;m" << std::endl;
	Mage->use(2, *Sauron);


	std::cout << "\033[1;33m" << "TEST EQUIPEMENT DE 4 MATERIA" << "\033[0;m" << std::endl;
	tmp2 = src->createMateria("ice");
	std::cout << "\033[1;36m" << "TEST XP MATERIA 0 :" << 	tmp2->get_XP() << "\033[0;m" << std::endl;
	Mage->equip(tmp2);
	tmp = src->createMateria("cure");
	Mage->equip(tmp);
	tmp = src->createMateria("cure");
	Mage->equip(tmp);
	std::cout << "\033[1;33m" << "TEST EQUIPEMENT MATERIA DEJA EXISTANTE" << "\033[0;m" << std::endl;
	Mage->equip(tmp);
	tmp = src->createMateria("cure");
	Mage->equip(tmp);
	std::cout << "\033[1;33m" << "TEST CREATION MATERIA DE TYPE INEXISTANT" << "\033[0;m" << std::endl;
	tmp = src->createMateria("Bonjour");
	Mage->equip(tmp);
	std::cout << "\033[1;33m" << "TEST EQUIPEMENT 5EME MATERIA SUR PERSONNAGE" << "\033[0;m" << std::endl;
	AMateria *tmp3 = src->createMateria("cure");
	Mage->equip(tmp3);
	delete tmp3;


	std::cout << "\033[1;33m" << "TEST AFFICHAGE NOM" << "\033[0;m" << std::endl;
	std::cout << Mage->getName() << std::endl;

	std::cout << "\033[1;33m" << "TEST DES 4 MATERIA AVEC USE" << "\033[0;m" << std::endl;
	
	Mage->use(0, *Sauron);
	std::cout << "\033[1;36m" << "XP MATERIA = " << 	tmp2->get_XP() << "\033[0;m" << std::endl;
	tmp2->get_XP();
	Mage->use(1, *Sauron);
	Mage->use(2, *Sauron);
	Mage->use(3, *Sauron);
	std::cout << "\033[1;33m" << "TEST UNE MATERIA NON ATTRIBUEE" << std::endl;
	Mage->use(4, *Sauron);

	std::cout << "\033[1;33m" << "TEST UNEQUIP MATERIA 0" << "\033[0;m" << std::endl;
	Mage->unequip(0);
	std::cout << "\033[1;33m" << "TEST USE MATERIA 0" << "\033[0;m" << std::endl;
	Mage->use(0, *Sauron);
	std::cout << "\033[1;33m" << "TEST UNEQUIP MATERIA 5" << "\033[0;m" << std::endl;
	Mage->unequip(5);
	std::cout << "\033[1;33m" << "TEST UNEQUIP TOUTES LES MATERIAS" << "\033[0;m" << std::endl;
	Mage->unequip(4);
	Mage->unequip(3);
	Mage->unequip(2);
	Mage->unequip(1);
	std::cout << "\033[1;33m" << "TEST UNEQUIP MATERIA DEJA UNEQUIP" << "\033[0;m" << std::endl;
	Mage->unequip(1);


	delete Sauron;
	delete Mage;
	delete src;
	return 0; 
}*/