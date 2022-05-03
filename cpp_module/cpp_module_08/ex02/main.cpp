/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:08:06 by ccartman          #+#    #+#             */
/*   Updated: 2022/05/03 15:34:42 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

static int test_mutant(void);

static int test_vector(void);

static int test_list(void);

static void test_my(void);

static void test_my_list(void);

int main(void)
{

	test_mutant();
	test_vector();
	test_list();
	
	std::cout << std::endl;
	test_my();
	test_my_list();

	return 0;
}

static int test_mutant(void)
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << "   ";

	mstack.pop();

	std::cout << mstack.size() << "   ";

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	return 0;
}

static int test_vector(void)
{
	std::vector<int> v;

	v.push_back(5);
	v.push_back(17);

	std::cout << v.back() << "   ";

	v.pop_back();

	std::cout << v.size() << "   ";

	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	v.push_back(0);

	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	return 0;
}

static int test_list(void)
{
	std::list<int> v;

	v.push_back(5);
	v.push_back(17);

	std::cout << v.back() << "   ";

	v.pop_back();

	std::cout << v.size() << "   ";

	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	v.push_back(0);

	std::list<int>::iterator it = v.begin();
	std::list<int>::iterator ite = v.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	return 0;
}

static void test_my(void)
{
	MutantStack<double> mstack;

	mstack.push(5.1);
	mstack.push(17.2);
	mstack.pop();
	mstack.push(3.1);
	mstack.push(5.2);
	mstack.push(737.0);
	mstack.push(0.9);

	MutantStack<double>::reverse_iterator it = mstack.rbegin();
	MutantStack<double>::reverse_iterator ite = mstack.rend();

	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	
}

static void test_my_list(void)
{
	std::list<double> l;

	l.push_back(5.1);
	l.push_back(17.2);
	l.pop_back();
	l.push_back(3.1);
	l.push_back(5.2);
	l.push_back(737.0);
	l.push_back(0.9);

	std::list<double>::reverse_iterator it = l.rbegin();
	std::list<double>::reverse_iterator ite = l.rend();

	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}
