/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:01:53 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/22 22:53:27 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat bob("Bob", 70);

	Form *sh = intern.makeForm("shrubbery creation", "example1");
	Form *rb = intern.makeForm("robotomy request", "example2");
	Form *pr = intern.makeForm("presidential pardon", "example3");
	bob.signForm(*sh);
	bob.signForm(*rb);
	bob.signForm(*pr);

	try {
		Form *tmp = intern.makeForm("abracadabra", "example4");
		bob.signForm(*tmp);
		delete tmp;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	delete sh;
	delete rb;
	delete pr;

	return 0;
}
