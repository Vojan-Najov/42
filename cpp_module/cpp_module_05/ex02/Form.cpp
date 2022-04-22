/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 21:42:54 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/22 16:18:53 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("Noname Form"), sign(false), \
			gradeToSign(highest_grade), gradeToExecute(highest_grade) {}

Form::Form(const std::string &name_, const int gradeToSign_, \
								const int gradeToExecute_, const bool sign_)
	: name(name_), sign(sign_), \
	  gradeToSign(gradeToSign_), \
	  gradeToExecute(gradeToExecute_)
{
	if (gradeToSign_ > lowest_grade || gradeToExecute_ > lowest_grade)
		throw GradeToLowException();
	else if (gradeToSign_ < highest_grade ||  gradeToExecute_ < highest_grade)
		throw GradeToHighException();
}

Form::Form(const Form &other) : name(other.name), sign(other.sign), \
		gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form::~Form(void) {}

Form &Form::operator=(const Form &other)
{
	sign = other.sign;

	return *this;
}

const std::string &Form::getName(void) const
{
	return name;
}

bool Form::getSign(void) const
{
	return sign;
}

int Form::getGradeToSign(void) const
{
	return gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (sign)
		return ;
	if (bur.getGrade() <= gradeToSign)
		sign = true;
	else 
		throw GradeToLowException();
}

const char *Form::GradeToHighException::what(void) const throw()
{
	return "The grade exceeded the maximum value for Form";
}

const char *Form::GradeToLowException::what(void) const throw()
{
	return "The grade exceeded the minimum value for Form";
}

const char *Form::ExecuteNotSignedForm::what(void) const throw()
{
	return "The form not signed";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << ", grade " << form.getGradeToSign();
	out << " to sign, " << form.getGradeToExecute() << " to execute. ";
	out << "Status: " << (form.getSign() ? "signed" : "not signed.");

	return out;
}

void Form::execute(const Bureaucrat &executor) const
{
	if (!sign)
		throw ExecuteNotSignedForm();
	if (gradeToExecute < executor.getGrade())
		throw GradeToLowException();
	executeForm();
}
