/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:14:12 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 18:19:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

#include <iostream>
#include <vector>

class	ISpaceMarine
{

	public:

		virtual		~ISpaceMarine() {}
		virtual		ISpaceMarine* clone() const = 0;
		virtual		void battleCry() const = 0;
		virtual		void rangedAttack() const = 0;
		virtual		void meleeAttack() const = 0;

};

#endif