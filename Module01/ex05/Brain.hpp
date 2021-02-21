/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:41:50 by user42            #+#    #+#             */
/*   Updated: 2020/10/05 17:40:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain
{
	public:
		Brain(void);
		Brain(int peggs, int pmilk, int psugar, int pvanilla);
		~Brain(void);

		const void *identify() const;

	private:
		int					_eggs;
		int					_milk;
		int					_sugar;
		int					_vanilla;
};

#endif