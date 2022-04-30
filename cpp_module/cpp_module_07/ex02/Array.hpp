/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:23:24 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/30 16:01:38 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "stdlib.h"
#include <new>
#include <stdexcept>

template<typename T>
class Array
{
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array<T> &copy);
	~Array(void);

	Array &operator=(const Array<T> &other);
	T &operator[](int idx);
	const T &operator[](int idx) const;

	unsigned int size(void) const;

private:
	unsigned int _n;
	T *_array;
};

#include "Array.tpp"

#endif
