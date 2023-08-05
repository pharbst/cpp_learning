/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:36:46 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/05 12:49:52 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noname"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat& ref) : _name(ref.getName()), _grade(ref.getGrade()) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
	if (this == &ref)
		return *this;
	*this = ref;
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

const std::string&	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::incrementGrade() {
	if (_grade < 2)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade > 149)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::changeGrade(int i) {
	if (_grade - i < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade - i > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade -= i;
}

void	Bureaucrat::signForm(AForm& toSign) {
	try {
		toSign.beSigned(*this);
		std::cout << getName() << " signed the Form: " << toSign.getName() << std::endl;
	}
	catch(std::exception& e) {
		std::cout << this->getName() << " couldn`t sign" << toSign.getName() << " because " << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src) {
	os << "Name:	" << src.getName() << " ";
	os << "Level:	" << src.getGrade();
	return os;
}
