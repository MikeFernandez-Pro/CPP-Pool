/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 11:43:45 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 15:55:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class	PlasmaRifle : public AWeapon
{

	public:

		PlasmaRifle( void );
		PlasmaRifle(std::string const & name, int apcost, int damage);
		PlasmaRifle( PlasmaRifle const & src );
		virtual ~PlasmaRifle( void );
		PlasmaRifle &	operator=( PlasmaRifle const & rhs );

		virtual void attack() const;

	private :

};


#endif