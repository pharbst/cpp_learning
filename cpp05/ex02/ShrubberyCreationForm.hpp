/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:36:49 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/05 13:00:13 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>
#include <string>

class ShrubberyCreationForm : public AForm{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& ref);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat& executer) const;
};

#endif