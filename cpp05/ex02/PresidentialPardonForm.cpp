/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:38:48 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/14 12:33:32 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("no_target", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm(ref.getName(), 25, 5) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref) {
	if (this == &ref)
		return *this;
	*this = ref;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::action() const {
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
