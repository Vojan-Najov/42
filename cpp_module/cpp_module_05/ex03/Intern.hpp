/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:43:41 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/23 22:54:22 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Intern
{
public:
	Intern(void);
	Intern(const Intern &other);
	~Intern(void);

	Intern &operator=(const Intern &other);
		
	Form *makeForm(const std::string &form, const std::string &target) const;

private:
	enum formIndexes
	{
		shrubberyCreationIndex,
		robotomyRequestIndex,
		presidentialPardonIndex,
		undefinedFormIndex
	};
	static const char *formTypes[];
};

#endif
