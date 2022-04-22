/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:06:55 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/22 17:21:28 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <unistd.h>

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("PresidentialPardonForm", 25, 5),
	  target("Notarget") {}


PresidentialPardonForm::PresidentialPardonForm(const std::string &target_)
	: Form("PresidentialPardonForm", 25, 5),
	  target(target_) {}

PresidentialPardonForm::PresidentialPardonForm
								(const PresidentialPardonForm &other)
	: Form(other), target(other.target) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator=
										(const PresidentialPardonForm &other)
{
	(void) other;

	return *this;
}

void PresidentialPardonForm::executeForm(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox";
	std::cout << std::endl;

}
