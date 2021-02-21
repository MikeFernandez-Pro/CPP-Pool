/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 22:23:20 by user42            #+#    #+#             */
/*   Updated: 2020/09/25 11:56:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WEAPON_H
# define WEAPON_H

class	Weapon {

public:

	Weapon();
	Weapon(std::string pweapon);
	~Weapon();

	std::string	getType();
	void		setType(std::string);

private :

	std::string _type;	
};

#endif