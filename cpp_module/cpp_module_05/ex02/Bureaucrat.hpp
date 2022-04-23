/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:21:03 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/23 12:53:23 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

const int lowest_grade = 150;
const int highest_grade = 1;
class Form;

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
		int getGrade(void) const;
		void signForm(Form &form) const;
		void executeForm(const Form &form) const;

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
