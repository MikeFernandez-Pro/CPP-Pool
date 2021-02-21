/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 18:10:24 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 18:35:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

typedef struct		s_squad
{
	ISpaceMarine	*unit;
	struct s_squad	*next;
}					t_squad;


class	Squad : public ISquad
{

	public:

		Squad( void );
		Squad( Squad const & src );
		virtual ~Squad( void );
		Squad &	operator=( Squad const & rhs );

		virtual		int getCount() const;
		virtual		ISpaceMarine* getUnit(int) const;
		virtual		int push(ISpaceMarine*);

	private :

		std::vector<ISpaceMarine*>	_Units;

};

#endif