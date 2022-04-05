/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:36:56 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/05 13:37:14 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	std::string	cmd;

	while (true)
	{
		if (!std::cin)
			break;
		std::getline(std::cin, cmd);
		if (!std::cin)
			break;
		if (cmd =="ADD")
			pb.addContact();
		else if (cmd == "SEARCH")
			pb.displayContacts();
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}
