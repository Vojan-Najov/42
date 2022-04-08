/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:28:31 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/08 19:40:36 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

enum levels{ edebug = 0, einfo = 6, ewarning = 11, eerror = 19};

static const std::string levelstr = "DEBUG\aINFO\aWARNING\aERROR\a";

void Harl::complain( std::string level ) const
{
	//void	(Harl::*fptr)(void) const;

	switch ((int) levelstr.find(level))
	{
		case edebug:
			debug();
		case einfo:
			info();
		case ewarning:
			warning();
		case eerror:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant " \
							"problems ]";
			std::cout << std::endl;
			break;
	}
}

void Harl::debug( void ) const
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my" \
	   " 7XL-double-cheese-triple-pickle-specialketchup burger.\n" \
	   "I really do!\n" << std::endl;
}

void Harl::info( void ) const
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more" \
	   " money.\n" \
		"You didn’t put enough bacon in my burger! If you did, I wouldn’t " \
		"be asking for more!\n" << std::endl;
}

void Harl::warning( void ) const
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon " \
		"for free.\nI’ve been coming for years whereas you started working " \
		"here since last month.\n" << std::endl;
}

void Harl::error( void ) const
{
	std::cout << "[ ERROR ]\n" \
		"This is unacceptable! I want to speak to the manager now.\n";
	std::cout << std::endl;
}
