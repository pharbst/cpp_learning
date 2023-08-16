/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:05:44 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/16 08:13:59 by pharbst          ###   ########.fr       */
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

static AForm *CreateRobotomyRequest(std::string target) {
	return new RobotomyRequestForm(target);
}

static AForm *CreateShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

static AForm *CreatePardon(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string name, std::string target) {
	std::string	Forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	 AForm *(*List[])(const std::string target) = {CreateRobotomyRequest, CreateShrubbery, CreatePardon};
	for (int i = 0; i < 3; i++) {
		if (name == Forms[i]) {
			std::cout << "Intern creates Form " << name << std::endl;
			return (List[i])(target);
		}
	}
	return NULL;
}
