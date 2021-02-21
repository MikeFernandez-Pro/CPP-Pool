/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:08:22 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:06:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad
{
	public:

		virtual		~ISquad() {}
		virtual		int getCount() const = 0;
		virtual		ISpaceMarine* getUnit(int) const = 0;
		virtual		int push(ISpaceMarine*) = 0;

};

#endif