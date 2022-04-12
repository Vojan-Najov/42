/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:22:30 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/12 14:07:43 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static int readContactData(std::string *str);

void PhoneBook::addContact(void)
{
	std::string str[5];
	
	if (!readContactData(str))
		return;
	if (idx < 8)
	{
		contact[idx] = Contact(str[0], str[1], str[2], str[3], str[4]);
		++idx;
	}
	else
	{
		for (int i = 1; i < 8; ++i)
			contact[i - 1] = contact[i];
		contact[7] = Contact(str[0], str[1], str[2], str[3], str[4]);
	}
}

void PhoneBook::displayContacts(void)
{
	int n = 0;
	std::string str;

	if (idx == 0)
	{
		std::cout << "Phone book is empty" << std::endl;
		return;
	}
	for (int i = 0; i < idx; ++i)
	{
		contact[i].printInfo(i + 1);
	}
	std::cout << "Enter the contact's index" << std::endl;
	std::getline(std::cin, str);
	for (int i = 0; str[i]; ++i)
	{
		if (!isdigit(str[i]))
		{
			n = -1;
			break;
		}
		n *= 10; n += str[i] - '0';
	}
	if (1 <= n && n <= idx)
		contact[n - 1].print();
	else
		std::cout << "Wrong index" << std::endl;
}

static int readContactData(std::string *str)
{
	do
	{
		std::cout << "Enter the first name" << std::endl;
		std::getline(std::cin, str[0]);
		if (!std::cin)
			return 0;
	}
	while (str[0].empty());
	do
	{
		std::cout << "Enter the last name" << std::endl;
		std::getline(std::cin, str[1]);
		if (!std::cin)
			return 0;
	}
	while (str[1].empty());
	do
	{
		std::cout << "Enter the nickname" << std::endl;
		std::getline(std::cin, str[2]);
		if (!std::cin)
			return 0;
	}
	while (str[2].empty());
	do
	{
		std::cout << "Enter the phone number" << std::endl;
		std::getline(std::cin, str[3]);
		if (!std::cin)
			return 0;
	}
	while (str[3].empty());
	do
	{
		std::cout << "Enter the darkest secret" << std::endl;
		std::getline(std::cin, str[4]);
		if (!std::cin)
			return 0;
	}
	while (str[4].empty());
	return (1);
}
