/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:42:34 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 17:40:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Human.hpp"

Human::Human()
{
}

Human::~Human()
{
}

const void *Human::identify() const
{
	return this->_brain.identify();
}

const Brain			&Human::getBrain() const
{
	return this->_brain;
}