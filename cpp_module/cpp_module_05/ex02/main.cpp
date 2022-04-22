/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:01:53 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/22 17:34:36 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		Bureaucrat bob("Bob", 140);
		Bureaucrat joe("Joe", 20);
		ShrubberyCreationForm sh("Luka");

		bob.signForm(sh);
		try {
			sh.execute(bob);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		sh.execute(joe);
	}
	std::cout << std::endl;
	{
		Bureaucrat bob("Bob", 70);
		Bureaucrat joe("Joe", 40);
		RobotomyRequestForm rb("Luka");

		bob.signForm(rb);
		try {
			rb.execute(bob);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		rb.execute(joe);
	}
	std::cout << std::endl;
	{
		Bureaucrat bob("Bob", 20);
		Bureaucrat joe("Joe", 4);
		PresidentialPardonForm rb("Luka");

		bob.signForm(rb);
		try {
			rb.execute(bob);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		rb.execute(joe);
	}
	std::cout << std::endl;
	{
		Bureaucrat bob("Bob", 20);
		PresidentialPardonForm rb("Luka");

		try {
			rb.execute(bob);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat bob("Bob", 20);
		Bureaucrat joe("Joe", 4);
		PresidentialPardonForm rb("Luka");
		
		bob.executeForm(rb);
		bob.signForm(rb);
		bob.executeForm(rb);
		joe.executeForm(rb);
	}
	return 0;
}
