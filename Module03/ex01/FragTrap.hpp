/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:31:05 by user42            #+#    #+#             */
/*   Updated: 2020/10/12 16:02:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <stdlib.h>
class	FragTrap
{

	public:

		FragTrap(void);
		FragTrap(std::string pName);
		FragTrap(FragTrap const & src);
		virtual ~FragTrap(void );
		FragTrap &	operator=(FragTrap const & rhs);

		int			getMeleeAttackDamage(void);
		int			getRangedAttackDamage(void);
	
		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int		vaulthunter_dot_exe(std::string const & target);

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