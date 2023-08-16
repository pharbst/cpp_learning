/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:05:44 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/15 15:08:13 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& ref) {
	*this = ref;
}

Intern& Intern::operator=(const Intern& ref) {
	(void)ref;
	return (*this);
}

Intern::~Intern() {}

Form*	Intern::makeForm(std::string name, std::string target) {
	switch (name) {
		case "robotomy request":
			return (new RobotomyRequestForm(target));
		case "presidential pardon":
			return (new PresidentialPardonForm(target));
		case "shrubbery creation":
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Form not found" << std::endl;
			return (NULL);
	}
}
