/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:35:41 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 14:36:01 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
	std::cout << "------------------- My Tests -------------------\n";
	Point a(0.1, 20.);
	Point b(0.1, 0.1);
	Point c(10, 0);
	Point point(1, 1);

	std::cout << bsp(a, b, c, point) << std::endl;
	point = Point(0.1, 1);
	std::cout << bsp(a, b, c, point) << std::endl;


	a = Point(10, 0);
	b = Point(0, 0);
	c = Point(0, 10);

	point = Point(0, 0);
	std::cout << bsp(a, b, c, point) << std::endl;
	point = Point(10, 0);
	std::cout << bsp(a, b, c, point) << std::endl;
	point = Point(0, 10);
	std::cout << bsp(a, b, c, point) << std::endl;
	point = Point(1, 1);
	std::cout << bsp(a, b, c, point) << std::endl;
	point = Point(0, 4.011);
	std::cout << bsp(a, b, c, point) << std::endl;
	point = Point(6.733, 0);
	std::cout << bsp(a, b, c, point) << std::endl;
	point = Point(5, 5);
	std::cout << bsp(a, b, c, point) << std::endl;
	point = Point(5, 4.5);
	std::cout << bsp(a, b, c, point) << std::endl;

	return (0);
}
