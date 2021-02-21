/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 22:28:06 by user42            #+#    #+#             */
/*   Updated: 2020/09/25 12:41:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class	HumanA {

public:

	HumanA(std::string pname, Weapon &_weaponType);
	~HumanA();

	void	attack();
	void	setWeapon(Weapon pWeapon);

private :

	std::string _name; 
	Weapon &_weaponType;
};

#endif