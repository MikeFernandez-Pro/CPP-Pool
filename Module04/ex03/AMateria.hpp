/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 11:20:59 by user42            #+#    #+#             */
/*   Updated: 2020/10/10 11:23:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>

class ICharacter;
class AMateria
{
	public:
		AMateria(void);
		AMateria(AMateria const &);
		AMateria(std::string const & type);
		virtual ~AMateria(void);
		AMateria &				operator=( AMateria const &);

		std::string const & 	get_type() const;
		unsigned int 			get_XP() const;
		virtual AMateria*		clone() const = 0;
		virtual void			use(ICharacter& target);

	private:
		unsigned int 			_XP;
		std::string				_type;
};

#include "ICharacter.hpp"
#endif
