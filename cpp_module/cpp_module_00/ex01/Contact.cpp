/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:07 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/05 14:00:00 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

static std::string truncate(std::string str);

Contact::Contact(std::string firstName, std::string lastName, \
                 std::string nickName, std::string phoneNumber, \
				 std::string darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickName = nickName;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

void Contact::printInfo(int idx)
{
	std::cout << std::setw(10) << idx << '|';
	std::cout << std::setw(10) << truncate(_firstName) << '|'; 
	std::cout << std::setw(10) << truncate(_lastName) << '|';
	std::cout << std::setw(10) << truncate(_nickName) << std::endl;
}

void Contact::print(void)
{
	std::cout << "First name    : " << _firstName << '\n';
	std::cout << "Last name     : " << _lastName << '\n';
	std::cout << "Nickname      : " << _nickName << '\n';
	std::cout << "Phone number  : " << _phoneNumber << '\n';
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}

static std::string truncate(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	return str;
}
