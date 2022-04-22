/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:06:55 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/22 16:20:55 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("ShrubberyCreationForm", 145, 137),
	  target("Notarget_shrubbery") {}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target_)
	: Form("ShrubberyCreationForm", 145, 137),
	  target(target_ + "_shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm
								(const ShrubberyCreationForm &other)
	: Form(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=
										(const ShrubberyCreationForm &other)
{
	(void) other;

	return *this;
}

void ShrubberyCreationForm::executeForm(void) const
{
	std::ofstream ofs(target);

	if (!ofs.is_open())
	{
		std::cerr << "ShrubberyCreationForm: ";
		std::cerr << "Can't open the file Notarget_shrubbery" << std::endl;
	}
	ofs << "  oxoxoo    ooxoo \n";
	ofs << "  ooxoxo oo  oxoxooo\n";
	ofs << " oooo xxoxoo ooo ooox\n";
	ofs << " oxo o oxoxo  xoxxoxo\n";
	ofs << "  oxo xooxoooo o ooo\n";
	ofs << "    ooo\\oo\\  /o/o\n";
	ofs << "        \\  \\/ /\n";
	ofs << "         |   /\n";
	ofs << "         |  |\n";
	ofs << "         | D|\n";
	ofs << "         |  |\n";
	ofs << "         |  |\n";
	ofs << "  ______/____\\____\n";
	ofs.close();
}
