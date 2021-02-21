/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:42:37 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 17:47:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP

# include "Brain.hpp"

class Human
{
	public:
		Human(void);
		~Human(void);

		const void		*identify() const;
		const Brain		&getBrain() const;

	private:
		const Brain		_brain;
};

#endif