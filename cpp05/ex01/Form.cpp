/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:13:20 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/18 17:10:42 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("noname"), _signed(false), _signGrade(150), _execGrade(150) {
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150)
		throw Form::GradeTooLowException();
	else if (_execGrade < 1)
		throw Form::GradeTooHighException();
	else if (_execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& ref) : _name(ref._name), _signGrade(ref._signGrade), _execGrade(ref._execGrade) {
	_signed = false;
}

Form& Form::operator=(const Form& ref) {
	if (this == &ref)
		return *this;
	*this = ref;
	return *this;
}

Form::~Form() {
}

void	Form::beSigned(const Bureaucrat& randy) {
	if (randy.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::string	Form::getName() const {
	return _name;
}

int	Form::getSignGrade() const {
	return _signGrade;
}

int	Form::getExecGrade() const {
	return _execGrade;
}

std::ostream&	operator<<(std::ostream& os, const Form& src) {
	os << "Name: " << src.getName() << " ";
	os << "Sign Grade: " << src.getSignGrade() << " ";
	os << "Exec Grade: " << src.getExecGrade();
	return os;
}
