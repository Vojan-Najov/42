/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:28:31 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/08 17:46:19 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

enum levels{ edebug = 0, einfo = 6, ewarning = 11, eerror = 19};

static const std::string levelstr = "DEBUG\aINFO\aWARNING\aERROR\a";

void Harl::complain( std::string level ) const
{
	void	(Harl::*fptr)(void) const;

	switch ((int) levelstr.find(level))
	{
		case edebug:
			fptr = &Harl::debug;
			break;
		case einfo:
			fptr = &Harl::info;
			break;
		case ewarning:
			fptr = &Harl::warning;
			break;
		case eerror:
			fptr = &Harl::error;
			break;
		default:
			fptr = 0;
			break;
	}
	if (fptr)
		(this->*fptr)();
}

void Harl::debug( void ) const
{
	std::cout << "I love having extra bacon for my" \
	   " 7XL-double-cheese-triple-pickle-specialketchup burger. " \
	   "I really do!" << std::endl;
}

void Harl::info( void ) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. " \
		"You didn’t put enough bacon in my burger! If you did, I wouldn’t " \
		"be asking for more!" << std::endl;
}

void Harl::warning( void ) const
{
	std::cout << "I think I deserve to have some extra bacon for free. " \
		"I’ve been coming for years whereas you started working here " \
		"since last month." << std::endl;
}

void Harl::error( void ) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}
