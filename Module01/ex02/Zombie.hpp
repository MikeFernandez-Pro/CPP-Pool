/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:53:50 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 21:21:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie 
{

	public:
	
		Zombie();
		Zombie(std::string pName);
		~Zombie();

		void	setType(std::string pType);
		void	advert() const;

	private:

		std::string _name;
		std::string	_type;
};

#endif