/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:03:21 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/27 16:34:11 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base *ptr;

	switch (rand() % 3)
	{
		case 0:
			ptr = new A;
			std::cout << "Generated: " << *static_cast<A *>(ptr) << '\n';
			break;
		case 1:
			ptr = new B;
			std::cout << "Generated: " << *static_cast<B *>(ptr) << '\n';
			break;
		case 2:
			ptr = new C;
			std::cout << "Generated: " << *static_cast<C *>(ptr) << '\n';
	}

	return ptr;
}

void identify(Base *p)
{
	A *a_ptr = dynamic_cast<A *>(p);
	if (a_ptr)
	{
		std::cout << "Indentified: " << *a_ptr << "\n";
		return;
	}
	B *b_ptr = dynamic_cast<B *>(p);
	if (b_ptr)
	{
		std::cout << "Indentified: " << *b_ptr << "\n";
		return;
	}
	C *c_ptr = dynamic_cast<C *>(p);
	if (c_ptr)
	{
		std::cout << "Indentified: " << *c_ptr << "\n";
		return;
	}
	std::cout << "Indentification has failed\n";
}

void identify(Base &p)
{
	try
	{
		A &a_ref = dynamic_cast<A &>(p);
		std::cout << "Indentified: " << a_ref << "\n";
		return;
	}
	catch (std::exception &e) {}
	try
	{
		B &b_ref = dynamic_cast<B &>(p);
		std::cout << "Indentified: " << b_ref << "\n";
		return;
	}
	catch (std::exception &e) {}
	try
	{
		C &c_ref = dynamic_cast<C &>(p);
		std::cout << "Indentified: " << c_ref << "\n";
		return;
	}
	catch (std::exception &e) {}
	std::cout << "Indentification has failed\n";
}

std::ostream &operator<<(std::ostream &out, const A &a)
{
	(void) a;
	out << "class 'A'" << '\n';

	return out;
}

std::ostream &operator<<(std::ostream &out, const B &b)
{
	(void) b;
	out << "class 'B'" << '\n';

	return out;
}

std::ostream &operator<<(std::ostream &out, const C &c)
{
	(void) c;
	out << "class 'C'" << '\n';

	return out;
}
