/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:50:43 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/15 15:26:04 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotonomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

using Form = AForm;

class Intern {
	public:
		Intern();
		Intern(const Intern& ref);
		Intern& operator=(const Intern& ref);
		~Intern();

		Form*	makeForm(std::string name, std::string target);
}

#endif