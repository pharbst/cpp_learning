/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:36:23 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/14 12:31:16 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <ctime>
# include "AForm.hpp"
# include <fstream>
# include "Bureaucrat.hpp"


class PresidentialPardonForm : public AForm{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& ref);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& ref);
		~PresidentialPardonForm();

		virtual void action() const;
};

#endif
