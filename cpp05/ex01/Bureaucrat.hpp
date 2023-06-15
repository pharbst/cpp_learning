/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:32:46 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/15 23:38:23 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAt_HPP
# define BUREAUCRAt_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat& ref);
		Bureaucrat& operator=(const Bureaucrat& ref);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				changeGrade(int i);
		void				signForm(Form& toSign);

		class GradeTooHigh : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLow : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);

#endif
