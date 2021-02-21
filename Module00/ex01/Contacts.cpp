/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 13:30:18 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 21:05:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"


Contacts::Contacts( void )
{
}


Contacts::~Contacts( void )
{
}


std::string	Contacts::getInfos(int i) const
{
	return (this->_infos[i]);
}


void	Contacts::setInfos(std::string infos, int i)
{
	this->_infos[i] = infos;
}