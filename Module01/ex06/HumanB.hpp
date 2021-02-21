/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 22:26:48 by user42            #+#    #+#             */
/*   Updated: 2020/09/25 12:50:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class	HumanB {

public:

	HumanB(std::string pname);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon &Pweapon);

private :

	std::string _name;
	Weapon *_weaponType;
};

#endif