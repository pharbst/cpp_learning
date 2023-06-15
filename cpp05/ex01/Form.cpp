/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:13:20 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/15 23:34:17 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("noname"), _signed(false), _signGrade(150), _execGrade(150) {
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1)
		throw Form::GradeTooHigh();
	else if (_signGrade > 150)
		throw Form::GradeTooLow();
	else if (_execGrade < 1)
		throw Form::GradeTooHigh();
	else if (_execGrade > 150)
		throw Form::GradeTooLow();
}

Form::Form(const Form& ref) {
	*this = ref;
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
		throw Form::GradeTooLow();
	else
		_signed = true;
}
