/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotonomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:03:15 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/05 13:05:19 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotonomyRequestForm.hpp"

RobotonomyRequestForm::RobotonomyRequestForm() : AForm("no_target", 72, 45) {
}

RobotonomyRequestForm::RobotonomyRequestForm(std::string target) : AForm(target, 72, 45) {
}

RobotonomyRequestForm::RobotonomyRequestForm(const RobotonomyRequestForm& ref) : AForm(ref.getName(), 72, 45) {
}

RobotonomyRequestForm& RobotonomyRequestForm::operator=(const RobotonomyRequestForm& ref) {
	if (this == &ref)
		return *this;
	*this = ref;
	return *this;
}

RobotonomyRequestForm::~RobotonomyRequestForm() {
}

void RobotonomyRequestForm::execute(const Bureaucrat& executer) const {
	try {
		if (!AForm::check(executer))
			throw AForm::GradeTooLowException();
		if (clock() % 2)
			std::cout << getName() << " has been robotomized!" << std::endl;
		else
			std::cout << "Robotomization failed!" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "execution failed cause of: " << e.what() << std::endl;
	}
}
