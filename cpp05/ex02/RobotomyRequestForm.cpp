/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:03:15 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/14 12:33:41 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("no_target", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref.getName(), 72, 45) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref) {
	if (this == &ref)
		return *this;
	*this = ref;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::action() const {
	if (clock() % 2)
		std::cout << getName() << " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomization failed!" << std::endl;
}
