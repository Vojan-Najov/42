/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:50:26 by ccartman          #+#    #+#             */
/*   Updated: 2022/05/02 19:36:08 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <new>
#include <stdlib.h>
#include <stdexcept>
#include <limits>


Span::Span(void) : capacity(0), lst() {}

Span::Span(unsigned int n) : capacity(n), lst() {}

Span::Span(const Span &copy) : capacity(copy.capacity), lst(copy.lst) {}

Span::~Span(void) {}

Span & Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	
	capacity = other.capacity;
	lst = other.lst;
		
	return *this;
}

void Span::addNumber(int number)
{
	if (lst.size() < capacity)
	{
		std::list<int> tmp (1, number);
		lst.merge(tmp);
	}
	else
		throw std::out_of_range("Span: no space left");
}

int Span::shortestSpan(void) const
{
	if (lst.size() < 2)
		throw std::range_error("Span: no span can be found");
	
	int ss = std::numeric_limits<int>::max();
	std::list<int>::const_iterator it = --lst.end();
	while (it != lst.begin())
	{
		int tmp = *it--;
		tmp -= *it;
		ss = tmp < ss ? tmp : ss;
	}
	return ss;
}

int Span::longestSpan(void) const
{
	if (lst.size() < 2)
		throw std::range_error("Span: no span can be found");

	return lst.back() - lst.front();
}
