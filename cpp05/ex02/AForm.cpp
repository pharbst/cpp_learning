/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:13:20 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/18 17:10:42 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("noname"), _signed(false), _signGrade(150), _execGrade(150) {
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signGrade > 150)
		throw AForm::GradeTooLowException();
	else if (_execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& ref) : _name(ref._name), _signGrade(ref._signGrade), _execGrade(ref._execGrade) {
	_signed = false;
}

AForm& AForm::operator=(const AForm& ref) {
	if (this == &ref)
		return *this;
	*this = ref;
	return *this;
}

AForm::~AForm() {
}

void	AForm::beSigned(const Bureaucrat& randy) {
	try {
		if (randy.getGrade() > _signGrade)
			throw AForm::GradeTooLowException();
		else
			_signed = true;
	}
	catch(std::exception& e) {
		std::cout << "signing failed: " << e.what() << std::endl;
	}
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char	*AForm::NotSignedException::what() const throw() {
	return "Form not signed";
}

std::string	AForm::getName() const {
	return _name;
}

int	AForm::getSignGrade() const {
	return _signGrade;
}

int	AForm::getExecGrade() const {
	return _execGrade;
}

void	AForm::execute(const Bureaucrat& executer) const {
	if (executer.getGrade() > _execGrade)
		throw GradeTooLowException();
	if (!_signed)
		throw NotSignedException();
	this->action();
}

std::ostream&	operator<<(std::ostream& os, const AForm& src) {
	os << "Name: " << src.getName() << " ";
	os << "Sign Grade: " << src.getSignGrade() << " ";
	os << "Exec Grade: " << src.getExecGrade();
	return os;
}
