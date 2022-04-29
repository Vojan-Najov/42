/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:36:14 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/29 22:44:37 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename R>
void iter(const T array[], unsigned int size,  R (*f_ptr)(const T &))
{
	for (unsigned int i = 0; i < size; ++i)
		(*f_ptr)(array[i]);
}

template <typename T, typename R>
void iter(T array[], unsigned int size,  R (*f_ptr)(T &))
{
	for (unsigned int i = 0; i < size; ++i)
		(*f_ptr)(array[i]);
}

template <typename T>
void iter(const T array[], unsigned int size,  void (*f_ptr)(const T &))
{
	for (unsigned int i = 0; i < size; ++i)
		(*f_ptr)(array[i]);
}

template <typename T>
void iter(T array[], unsigned int size,  void (*f_ptr)(T &))
{
	for (unsigned int i = 0; i < size; ++i)
		(*f_ptr)(array[i]);
}

#endif
