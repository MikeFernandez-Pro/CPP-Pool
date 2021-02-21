/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:31:05 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 14:06:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	NinjaTrap : public virtual ClapTrap
{

	public :

		NinjaTrap(void);
		NinjaTrap(std::string pName);
		NinjaTrap(NinjaTrap const & src);
		virtual ~NinjaTrap(void );
		NinjaTrap &	operator=(NinjaTrap const & rhs);
	
		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		void		ninjaShoebox(ClapTrap &target);
    	void		ninjaShoebox(FragTrap &target);
		void		ninjaShoebox(ScavTrap &target);
		void		ninjaShoebox(NinjaTrap &target);

	protected :

};

#endif