/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:16:33 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:07:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class	TacticalMarine : public ISpaceMarine
{
	
	public:

		TacticalMarine( void );
		TacticalMarine( TacticalMarine const & src );
		virtual ~TacticalMarine( void );
		TacticalMarine &	operator=( TacticalMarine const & rhs );

		virtual		ISpaceMarine* clone() const;
		virtual		void battleCry() const;
		virtual		void rangedAttack() const;
		virtual		void meleeAttack() const;

	private :

};

#endif