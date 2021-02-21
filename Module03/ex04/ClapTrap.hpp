/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:31:05 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 19:33:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <stdlib.h>

class	ClapTrap
{

	public :

		ClapTrap(void);
		ClapTrap(std::string pName);
		ClapTrap(ClapTrap const & src);
		virtual ~ClapTrap(void );
		ClapTrap &	operator=(ClapTrap const & rhs);

		int			getMeleeAttackDamage(void);
		int			getRangedAttackDamage(void);
		std::string getName(void);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer(void);

	protected :
	
	int			_HitPoints;
	int			_MaxHitPoints;
	int			_EnergyPoints;
	int			_MaxEnergyPoints;
	int			_Level;
	std::string _Name;
	int			_MeleeAttackDamage;
	int			_RangedAttackDamage;
	int			_ArmorDamageReduction;
	
};

#endif