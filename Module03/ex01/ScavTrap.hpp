/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:31:05 by user42            #+#    #+#             */
/*   Updated: 2020/10/08 12:52:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <stdlib.h>

class	ScavTrap
{

	public:

		ScavTrap(void);
		ScavTrap(std::string pName);
		ScavTrap(ScavTrap const & src);
		virtual ~ScavTrap(void );
		ScavTrap &	operator=(ScavTrap const & rhs);

		int			getMeleeAttackDamage(void);
		int			getRangedAttackDamage(void);
	
		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer(void);

	private :
	
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