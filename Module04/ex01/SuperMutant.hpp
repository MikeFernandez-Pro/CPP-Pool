/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:12:01 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:03:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{

	public:

		SuperMutant( void );
		SuperMutant( SuperMutant const & src );
		virtual  ~SuperMutant( void );
		SuperMutant &	operator=( SuperMutant const & rhs );
		
		virtual void	takeDamage(int);

	private :

};

#endif