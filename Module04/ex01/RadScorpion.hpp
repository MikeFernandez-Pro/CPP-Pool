/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:02:21 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:03:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy
{

	public:

		RadScorpion( void );
		RadScorpion( RadScorpion const & src );
		virtual  ~RadScorpion( void );
		RadScorpion &	operator=( RadScorpion const & rhs );

	private :

};

#endif