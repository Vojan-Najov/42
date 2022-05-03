/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:43:21 by ccartman          #+#    #+#             */
/*   Updated: 2022/05/03 15:29:03 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void);
	MutantStack(const MutantStack &copy);
	~MutantStack(void);

	MutantStack &operator=(const MutantStack &other);

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	inline iterator begin(void);
	inline iterator end(void);
	inline const_iterator begin(void) const;
	inline const_iterator end(void) const;
	inline reverse_iterator rbegin(void);
	inline reverse_iterator rend(void);
	inline const_reverse_iterator rbegin(void) const;
	inline const_reverse_iterator rend(void) const;

};

#include "MutantStack.tpp"

#endif
