/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:36:49 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/05 13:04:54 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("no_target", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref.getName(), 145, 137) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) {
	if (this == &ref)
		return *this;
	*this = ref;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(const Bureaucrat& executer) const {
	try {
		if (!AForm::check(executer))
			throw AForm::GradeTooLowException();
		std::string	FileName = getName() + "_shrubbery";
		std::ofstream	fileOut(FileName.c_str());
		if (!fileOut.is_open())
			throw std::exception();
		fileOut << "       _-_" << std::endl;
		fileOut << "    /~~   ~~\\" << std::endl;
		fileOut << " /~~         ~~\\" << std::endl;
		fileOut << "{               }" << std::endl;
		fileOut << " \\  _-     -_  /" << std::endl;
		fileOut << "   ~  \\\\ //  ~" << std::endl;
		fileOut << "_- -   | | _- _" << std::endl;
		fileOut << "  _ -  | |   -_" << std::endl;
		fileOut << "      // \\\\" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "execution failed cause of: " << e.what() << std::endl;
	}
}
