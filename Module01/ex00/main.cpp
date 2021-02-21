/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:09:57 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 13:06:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheStack(void)
{
	Pony Oliver("Oliver", "Black", "Purebred", 1.75, 61.5, "Carrot", "Everybody");
	Oliver.Actions("apple juice", "petit croissant", "el famoso Pascal the rabbit");
}

void	ponyOnTheHeap(void)
{
	Pony *Jordan = new Pony("Jordan", "White", "Welsh", 1.62, 30.6, "Bone", "No one");
	Jordan->Actions("milk", "pancake with chocolate", "Cindy the pinguin");
	delete (Jordan);
}

int	main(void)
{
	ponyOnTheStack();
	std::cout << std::endl << "--------------------" << std::endl << std::endl;
	ponyOnTheHeap();
	return (0);
}
