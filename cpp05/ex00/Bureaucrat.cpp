/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:36:46 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/18 12:43:28 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noname"), _level(150) {
}

Bureaucrat::Bureaucrat(std::string name, int level) : _name(name) {
	if (level < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (level > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_level = level;
}

Bureaucrat::Bureaucrat(Bureaucrat& ref) : _name(ref.getName()), _level(ref.getGrade()) {
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
	return _level;
}

void	Bureaucrat::incrementLevel() {
	if (_level < 2)
		throw Bureaucrat::GradeTooHighException();
	else
		_level--;
}

void	Bureaucrat::decrementLevel() {
	if (_level > 149)
		throw Bureaucrat::GradeTooLowException();
	else
		_level++;
}

void	Bureaucrat::changeLevel(int i) {
	if (_level - i < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_level - i > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_level -= i;
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
