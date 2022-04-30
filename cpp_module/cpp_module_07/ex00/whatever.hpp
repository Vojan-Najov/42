/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:50:54 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/30 15:33:43 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &a, T &b)
{
	T tmp = a;

	a = b;
	b = tmp;
}

template<typename T>
const T &min(const T &first, const T &second)
{
	return first < second ? first : second;
}

template<typename T>
const T &max(const T &first, const T &second)
{
	return first > second ? first : second;
}

template<typename T>
T &min(T &first, T &second)
{
	return first < second ? first : second;
}

template<typename T>
T &max(T &first, T &second)
{
	return first > second ? first : second;
}

#endif
