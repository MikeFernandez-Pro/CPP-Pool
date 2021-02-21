/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:05:19 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 15:53:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class	Character
{

	public:

		Character(std::string const & name);
		Character( Character const & src );
		virtual ~Character( void );
		Character &	operator=( Character const & rhs );

		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		std::string const	&getName() const;
		int					getAP() const;
		bool				getWeapon() const;
		std::string const	&getWeaponName() const;

	private :

		std::string _name;
		int			_ap;
		AWeapon		*_weapon;

		Character( void ) {}

};

std::ostream &	operator<<( std::ostream & o, Character const & rhs );

#endif