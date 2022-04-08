/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:42:02 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/08 18:22:27 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cerr << "One argument are expected" << std::endl;
		return (1);
	}
	if (!argv[1])
		harl.complain("notExist");
	else
		harl.complain(std::string(argv[1]));
				
	return (0);
}
