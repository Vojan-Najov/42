/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:06:55 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/22 17:20:01 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("RobotomyRequestForm", 72, 45),
	  target("Notarget") {}


RobotomyRequestForm::RobotomyRequestForm(const std::string &target_)
	: Form("RobotomyRequestForm", 72, 45),
	  target(target_) {}

RobotomyRequestForm::RobotomyRequestForm
								(const RobotomyRequestForm &other)
	: Form(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator=
										(const RobotomyRequestForm &other)
{
	(void) other;

	return *this;
}

void RobotomyRequestForm::executeForm(void) const
{
	std::cout << "\a";
	srand(time(0));
	if (rand() % 2)
		std::cout << target << " has been robotomized.";
	else
		std::cout << "Robotomy failed.";
	std::cout << std::endl;

}
