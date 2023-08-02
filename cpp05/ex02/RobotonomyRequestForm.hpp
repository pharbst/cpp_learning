/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotonomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:03:20 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/03 01:05:08 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTONOMYREQUESTFORM_HPP
# define ROBOTONOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotonomyRequestForm : public AForm{
	public:
		RobotonomyRequestForm();
		RobotonomyRequestForm(std::string target);
		RobotonomyRequestForm(const RobotonomyRequestForm& ref);
		RobotonomyRequestForm& operator=(const RobotonomyRequestForm& ref);
		~RobotonomyRequestForm();

		void execute(const Bureaucrat& executer) const;
};

#endif