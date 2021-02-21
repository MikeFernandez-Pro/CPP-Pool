/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:51:34 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 15:46:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include <iostream>
#include "Victim.hpp"

class	Peon : public Victim
{
	public:

		Peon( std::string pName );
		Peon( Peon const & src );
		virtual ~Peon( void );
		Peon &	operator=( Peon const & rhs );
		virtual void      getPolymorphed() const;

	private :

		std::string _Name;

		Peon( void ) {}
};

#endif