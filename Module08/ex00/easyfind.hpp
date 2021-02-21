/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:54:31 by user42            #+#    #+#             */
/*   Updated: 2020/10/26 10:27:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iterator>
#include <algorithm>

template<typename T>
bool	easyfind(const T &container, const int i) 
{
	if (find (container.begin(), container.end(), i) != container.end())
			return (true);
	return (false);
}

#endif
