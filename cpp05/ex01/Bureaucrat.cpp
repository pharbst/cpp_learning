/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:36:46 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/15 23:43:12 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noname"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHigh();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLow();
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
		throw Bureaucrat::GradeTooHigh();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (_grade > 149)
		throw Bureaucrat::GradeTooLow();
	else
		_grade++;
}

void	Bureaucrat::changeGrade(int i) {
	if (_grade - i < 1)
		throw Bureaucrat::GradeTooHigh();
	else if (_grade - i > 150)
		throw Bureaucrat::GradeTooLow();
	else
		_grade -= i;
}

void	signForm(Form& toSign) {
	try {
		
	}
	catch(std::exception& e) {
		std::cout << 
	}
}

const char	*Bureaucrat::GradeTooHigh::what() const throw() {
	return "Grade too high";
}

const char	*Bureaucrat::GradeTooLow::what() const throw() {
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src) {
	os << "Name:	" << src.getName() << " ";
	os << "Level:	" << src.getGrade();
	return os;
}
