/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:21:03 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/19 19:46:09 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

static const unsigned char lowest_grade = 150;
static const unsigned char highest_grade = 1;

class Bureaucrat
{
	public:
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(const std::string &name_, const int grade_ = lowest_grade);
		~Bureaucrat(void);

		const std::string &getName(void) const;
		const int &getGrade(void) const;

		Bureaucrat &operator=(const Bureaucrat &other);
		Bureaucrat &operator++(void);
		Bureaucrat operator++(int);
		Bureaucrat &operator--(void);
		Bureaucrat operator--(int);

	private:
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur);

#endif
