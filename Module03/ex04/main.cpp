/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 11:00:06 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 17:32:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
	FragTrap *Jordan = new FragTrap("Jordan");
	ScavTrap *Olivier = new ScavTrap("Olivier");
	NinjaTrap *Guillaume = new NinjaTrap("Guillaume");
	Olivier->takeDamage(Jordan->vaulthunter_dot_exe("Olivier"));
	Olivier->takeDamage(Jordan->vaulthunter_dot_exe("Olivier"));
	Olivier->takeDamage(Jordan->vaulthunter_dot_exe("Olivier"));
	Olivier->beRepaired(999);
	Olivier->takeDamage(Jordan->vaulthunter_dot_exe("Olivier"));
	Olivier->takeDamage(Jordan->vaulthunter_dot_exe("Olivier"));
	Guillaume->ninjaShoebox(*Jordan);
	delete (Jordan);
	Olivier->challengeNewcomer();
	SuperTrap Micha("Micha");
	Olivier->takeDamage(Micha.vaulthunter_dot_exe("Olivier"));
	Micha.ninjaShoebox(*Olivier);
	Guillaume->ninjaShoebox(*Olivier);
	delete (Olivier);
	delete (Guillaume);
	return (0);
}