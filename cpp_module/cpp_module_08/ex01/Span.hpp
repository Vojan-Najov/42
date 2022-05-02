/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:51:03 by ccartman          #+#    #+#             */
/*   Updated: 2022/05/02 19:36:20 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <list>
#include <iterator>

class Span
{
public:
	Span(void);
	Span(unsigned int n);
	Span(const Span &copy);
	~Span(void);

	Span &operator=(const Span &other);

	void addNumber(int number);
	template <class InputIterator>
	void addNumber(InputIterator first, InputIterator last)
	{
		if (last - first > static_cast<long>(capacity - lst.size()))
			throw std::out_of_range("Span: no space left");
		lst.insert(lst.end(), first, last);
		lst.sort();
	}
	int	longestSpan(void) const;
	int shortestSpan(void) const;

private:
	unsigned int capacity;
	std::list<int> lst;
};

#endif
