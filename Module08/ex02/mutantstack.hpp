/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 19:07:43 by user42            #+#    #+#             */
/*   Updated: 2020/10/25 22:28:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <deque>
#include <vector>

template<class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
    public:
		
        MutantStack(): std::stack<T, Container>() {}
        MutantStack(const MutantStack<T, Container> &obj): std::stack<T, Container>(obj) { this->operator=(obj); }
        virtual ~MutantStack() {}
        MutantStack<T, Container> &operator=(const MutantStack<T> &obj) {
            if (this != &obj)
                this->c = obj.c;
            return (*this);
        }

        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator				begin() { return (this->c.begin()); }

        const_iterator			begin() const { return (this->c.begin()); }

        iterator				end() { return (this->c.end()); }

        const_iterator			end() const { return (this->c.end()); }

        reverse_iterator		rbegin() { return (this->c.rbegin()); }

        const_reverse_iterator	rbegin() const { return (this->c.rbegin()); }

        reverse_iterator		rend() { return (this->c.rend()); }

        const_reverse_iterator	rend() const { return (this->c.rend()); }
		
		bool					empty(){ return (this->c.empty()); }

		size_t					size(){ return (this->c.size()); }

		void					push(const T &element) { this->c.push_back(element); }

		void					pop() { this->c.pop_back(); }

		T &						top() { return (*(this->c.end() - 1)); }
 
		const T	&				top()	const { return (*(this->c.end() - 1)); }

};

#endif