/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:29:19 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 12:51:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

void	ft_set_contact(Contacts *instance, int *nb_contacts)
{
	std::string champs[11] = {"First_name", "Last_name", "Nickname", "Login","Postal_address",
	"Email_address", "Phone_number", "Birthday_date", "Favorite meal", "Underwear_color", "Darkest_secret"};
	std::string cpy;	

	for(int i = 0; i < 11; i++)
	{
		std::cout << champs[i] << " : ";
		std::cin >> cpy;
		instance->setInfos(cpy, i);
	}
	(*nb_contacts)++;
	std::cout << "\033[1;36mContact ajouté.\033[0;m" << std::endl;
}
/*
void	ft_print_light (Contacts	instance, int nb_contacts) 
{
	char display[11];
	std::string cpy;
	std::string id[8] = {"0","1", "2", "3", "4", "5", "6", "7"};
	int i;
	int	k;

	std::cout << "|";
	for (int j = -1; j < 3; j++)
	{
		k = 0;
		cpy = (j == -1) ? std::to_string(nb_contacts) : instance.getInfos(j);
		for (i = 0; i < 10; i++)
			display[i] = ' ';
		display[i] = '\0';
		i = (10 - cpy.length())
		if (i < 0)
			i = 0;
		while (i < 10)
			display[i++] =  cpy[k++];
		if (display[0] != ' ')
			display[9] = '.';
		std::cout << display << "|";
	}
	std::cout << std::endl;
}*/

void	ft_print_light (Contacts	instance, int pid) 
{
	std::string id[8] = {"0","1", "2", "3", "4", "5", "6", "7"};
	char display[11];
	std::string cpy;
	int k;
	int i;

	std::cout << "|         " << pid << "|";
	for (int j = 0; j < 3; j++)
	{
		cpy = instance.getInfos(j);
		k = 0;
		for (i = 0; i < 10; i++)
			display[i] = ' ';
		display[i] = '\0';
		i = (10 - cpy.length());
		if (i < 0)
			i = 0;
		while (i < 10)
			display[i++] =  cpy[k++];
		if (display[0] != ' ')
			display[9] = '.';
		std::cout << display << "|";
	}
	std::cout << std::endl;
}

void	ft_print_contact(Contacts instance)
{
	std::string champs[11] = {"First name", "Last name", "Nickname", "Login","Postal address",
	"Email address", "Phone number", "Birthday date", "Favorite meal", "Underwear color", "Darkest secret"};
	for (int i = 0; i < 11; i++)
		std::cout << "\033[1;36m" << champs[i] << "-> " << "\033[0;m" << instance.getInfos(i) << std::endl;
}

int		main(void)
{
	Contacts	instance[8];
	int			nb_contacts;
	std::string commande;
	int			id_search;

	nb_contacts = 0;
	std::cout << "\033[1;32mBienvenu sur votre annuaire virtuel !\033[0;m" << std::endl;
	std::cout << "Commandes autorisés : \033[1;36mADD - SEARCH - EXIT" << std::endl;
	while (1)
	{
		std::cout << "\033[1;33mVeuillez indiquer une commande : \033[0;m";
		std::cin >> commande;
		if (commande.compare("EXIT") == 0)
			return (0);
		else if (commande.compare("ADD") == 0)
		{
			if (nb_contacts < 8)
				ft_set_contact(&instance[nb_contacts], &nb_contacts);
			else
				std::cout << "\033[1;31mListe de contacts pleine.\033[0;m" << std::endl;
		}
		else if (commande.compare("SEARCH") == 0)
		{
			if (nb_contacts == 0)
				std::cout << "\033[1;31m\nListe de contacts vide.\033[0;m" << std::endl;
			else
			{
				std::cout << " ___________________________________________ " << std::endl;
				std::cout << "|    \033[1;36mID\033[0;m    |  \033[1;36mPrenom\033[0;m  |   \033[1;36mNom\033[0;m    |  \033[1;36mPseudo\033[0;m  |" << std::endl;
				std::cout << "|----------|----------|----------|----------|" << std::endl;
				for (int i = 0; i < nb_contacts; i++)
					ft_print_light(instance[i], i);
				std::cout << std::endl << "Veuillez indiquer l'index du contact à rechercher ? : ";
				std::cin >> id_search;
				if (id_search >= nb_contacts || id_search < 0 )
					std::cout << "\033[1;31m\nCe contact n'existe pas.\033[0;m" << std::endl;
				else
					ft_print_contact(instance[id_search]);
			}
		}
		else
			std::cout << "\033[1;31mCeci n'est pas une commande valide.\033[0;m" << std::endl;
	}
	return (0);
}

	
