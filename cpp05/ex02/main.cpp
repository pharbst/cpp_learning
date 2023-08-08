/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:07:02 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/08 18:53:23 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotonomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Fix the concrete classes
// write a function in the Aform base class
// to call the execute functions of the concrete classes
// its prettier

// rename the execute functions of the derived classes and implement the execute function
// in the base class and call the action function of the derived class also add the not signed exception to the base classw

int main(void) {
	AForm *Formular[3];

	Formular[0] = new ShrubberyCreationForm("Home");
	Formular[1] = new RobotonomyRequestForm("Pfff");
	Formular[2] = new PresidentialPardonForm("Your moma");

	Bureaucrat Larry("Larry", 150);
	Bureaucrat Ulli("Ulli", 90);
	Bureaucrat Herta("Herta", 50);
	Bureaucrat Jürgen("Jürgen", 30);
	Bureaucrat Ute("Ute", 20);

	Formular[0]->execute(Ulli);
	Formular[0]->beSigned(Ulli);
	Formular[0]->execute(Larry);
	Formular[0]->execute(Ulli);

	// Formular[1]->beSigned(Ulli);
	// Formular[1]->beSigned(Herta);
	
	return 0;
}
