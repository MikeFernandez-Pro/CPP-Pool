/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:23:13 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 15:59:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
	
	public:

		AWeapon( void );
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon( AWeapon const & src );
		virtual ~AWeapon( void );
		AWeapon &	operator=( AWeapon const & rhs );

		std::string const &getName() const;
		int getAPCost() const;
		int getDamage() const;
		virtual void attack() const = 0;

	private:
		
		std::string			_Name;
		int					_Apcost;
		int					_Damage;
};

#endif
