/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:41:30 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/30 15:45:16 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename T>
T increment(T &x)
{
	++x;
	return x;
}

template<typename T>
int decrement(T &x)
{
	x -= 1;
	return 1;
}

int main(void)
{
	int tab[] = {0, 1, 2, 3, 4};
	float tabf[] = {0.1f, 1.1f, 2.1f, 3.1f, 4.1f};

	std::cout << "before iter:\n";
	for (int i = 0; i < 5; ++i)
		std::cout << tab[i] << ' ';
	std::cout << '\n';
	iter(tab, 5, increment<int>);
	std::cout << "after iter:\n";
	for (int i = 0; i < 5; ++i)
		std::cout << tab[i] << ' ';
	std::cout << '\n';
	std::cout << "before iter:\n";
	for (int i = 0; i < 5; ++i)
		std::cout << tabf[i] << ' ';
	std::cout << '\n';
	iter(tabf, 5, decrement<float>);
	std::cout << "after iter:\n";
	for (int i = 0; i < 5; ++i)
		std::cout << tabf[i] << ' ';
	std::cout << '\n';

	return 0;
}
