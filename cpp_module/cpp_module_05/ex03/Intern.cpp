/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:49:16 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/22 22:46:14 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


const char *Intern::formTypes[] = {"shrubbery creation", \
								   "robotomy request", \
								   "presidential pardon" };

Intern::Intern(void) {}

Intern::Intern(const Intern &other) {(void) other;}

Intern::~Intern(void) {}

Intern & Intern::operator=(const Intern &other)
{
	(void) other;

	return *this;
}

Form *Intern::makeForm(const std::string &form, const std::string &target) const
{
	int	formIndex;
	Form *ptr;

	for (formIndex = 0; formIndex < undefinedFormIndex; ++formIndex)
	{
		if (form == formTypes[formIndex])
			break;
	}
	switch (formIndex)
	{
		case shrubberyCreationIndex:
			ptr = new ShrubberyCreationForm(target);
			break;
		case robotomyRequestIndex:
			ptr = new RobotomyRequestForm(target);
			break;
		case presidentialPardonIndex:
			ptr = new PresidentialPardonForm(target);
			break;
		default:
			throw std::invalid_argument("invalid form name");
	}

	return ptr;
}
