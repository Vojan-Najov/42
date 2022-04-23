/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:38:37 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/23 12:41:23 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(void);
		Form(const std::string &name_, \
			 const int gradeToSign_ = highest_grade, \
			 const int gradeToExecute_ = highest_grade, \
			 bool sign_ = false);
		Form(const Form &other);
		virtual ~Form(void);

		const std::string &getName(void) const;
		bool getSign(void) const;
		int getGradeToSign(void) const;
		int getGradeToExecute(void) const;
		void beSigned(const Bureaucrat &bur);
		void execute(Bureaucrat const &executor) const;

	private:
		const std::string name;
		bool sign;
		const int gradeToSign;
		const int gradeToExecute;
		Form &operator=(const Form &other);
		virtual void executeForm(void) const = 0;
		class GradeToHighException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class GradeToLowException : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
		class ExecuteNotSignedForm : public std::exception {
			public:
				virtual const char *what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
