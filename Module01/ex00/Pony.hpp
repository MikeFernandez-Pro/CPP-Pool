/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 23:40:11 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 12:00:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class Pony 
{

	public:

		Pony(std::string pName,std::string pCol, std::string pRace,
		float pSize, float pWeight, std::string pFav, std::string pBest);
		~Pony();
	
		void Actions(std::string pDrink, std::string pFood, std::string pEnemy) const;

	private:
		std::string	_Name;
		std::string	_Color;
		std::string	_Race;
		float		_Size;
		float		_Weight;
		std::string	_FavoriteToy;
		std::string	_BestFriend;
};

#endif