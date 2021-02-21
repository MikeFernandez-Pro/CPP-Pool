/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:21:08 by user42            #+#    #+#             */
/*   Updated: 2020/10/16 16:15:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		
		Character(std::string);
		Character(Character const &);
		virtual ~Character(void);
		Character &				operator=( Character const &);

		virtual std::string const & 	getName() const;
		virtual void 					equip(AMateria* m);
		virtual void 					unequip(int idx);
		virtual void 					use(int idx, ICharacter& target);

	private:
		std::string				_name;
		int						_nbMateria;
		AMateria *				_inventory[4];
		
		Character(void) {}
};

void							suppr_materia(AMateria **);

#endif
