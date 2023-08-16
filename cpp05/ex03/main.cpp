/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:07:02 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/15 15:12:18 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotonomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern someRandomIntern;
	AForm *Formular[3];

	Formular[0] = someRandomIntern.makeForm("shrubbery creation", "Home");
	Formular[1] = someRandomIntern.makeForm("robotomy request", "R2D2");
	Formular[2] = someRandomIntern.makeForm("presidential pardon", "noone");

	Bureaucrat Larry("Larry", 150);
	Bureaucrat Ulli("Ulli", 90);
	Bureaucrat Herta("Herta", 50);
	Bureaucrat Jürgen("Jürgen", 30);
	Bureaucrat Ute("Ute", 20);

	std::cout << "Bureaucrats created" << std::endl;
	Formular[0]->execute(Ulli);
	std::cout << "Ulli tryed to execute Shrubbery" << std::endl;
	Formular[0]->beSigned(Larry);
	std::cout << "Larry tryed to sign shrubbery" << std::endl;
	Formular[0]->beSigned(Ulli);
	std::cout << "Ulli tryed to sign shrubbery" << std::endl;
	Formular[0]->execute(Larry);
	std::cout << "Larry tryed to execute Shrubbery" << std::endl;
	Formular[0]->execute(Ulli);
	std::cout << "Ulli tryed to execute Shrubbery" << std::endl;

	Formular[1]->execute(Ulli);
	std::cout << "Ulli tryed to execute Robotonomy" << std::endl;
	Formular[1]->beSigned(Larry);
	std::cout << "Larry tryed to sign Robotonomy" << std::endl;
	Formular[1]->beSigned(Ulli);\
	std::cout << "Ulli tryed to sign Robotonomy" << std::endl;
	Formular[1]->beSigned(Herta);
	std::cout << "Herta tryed to sign Robotonomy" << std::endl;
	Formular[1]->execute(Larry);
	std::cout << "Larry tryed to execute Robotonomy" << std::endl;
	Formular[1]->execute(Ulli);
	std::cout << "Ulli tryed to execute Robotonomy" << std::endl;
	Formular[1]->execute(Herta);
	std::cout << "Herta tryed to execute Robotonomy" << std::endl;
	Formular[1]->execute(Jürgen);
	std::cout << "Jürgen tryed to execute Robotonomy" << std::endl;
	Formular[1]->execute(Ute);
	std::cout << "Ute tryed to execute Robotonomy" << std::endl;

	Formular[2]->execute(Ulli);
	std::cout << "Ulli tryed to execute Presidential" << std::endl;
	Formular[2]->beSigned(Larry);
	std::cout << "Larry tryed to sign Presidential" << std::endl;
	Formular[2]->beSigned(Ulli);
	std::cout << "Ulli tryed to sign Presidential" << std::endl;
	Formular[2]->beSigned(Herta);
	std::cout << "Herta tryed to sign Presidential" << std::endl;
	Formular[2]->execute(Larry);
	std::cout << "Larry tryed to execute Presidential" << std::endl;
	Formular[2]->execute(Ulli);
	std::cout << "Ulli tryed to execute Presidential" << std::endl;
	Formular[2]->execute(Herta);
	std::cout << "Herta tryed to execute Presidential" << std::endl;
	Formular[2]->execute(Jürgen);
	std::cout << "Jürgen tryed to execute Presidential" << std::endl;
	Formular[2]->execute(Ute);
	std::cout << "Ute tryed to execute Presidential" << std::endl;
	
	return 0;
}
