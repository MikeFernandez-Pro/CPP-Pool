/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:29:48 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:06:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class	AssaultTerminator : public ISpaceMarine
{
	
	public:

		AssaultTerminator( void );
		AssaultTerminator( AssaultTerminator const & src );
		virtual ~AssaultTerminator( void );
		AssaultTerminator &	operator=( AssaultTerminator const & rhs );

		virtual		ISpaceMarine* clone() const;
		virtual		void battleCry() const;
		virtual		void rangedAttack() const;
		virtual		void meleeAttack() const;

	private :

};

#endif