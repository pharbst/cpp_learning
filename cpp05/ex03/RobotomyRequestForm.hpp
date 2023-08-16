/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 01:03:20 by pharbst           #+#    #+#             */
/*   Updated: 2023/08/14 12:32:34 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyREQUESTFORM_HPP
# define RobotomyREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>


class RobotomyRequestForm : public AForm{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& ref);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
		~RobotomyRequestForm();

		virtual void action() const;
};

#endif