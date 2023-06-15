/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:39:32 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/15 23:30:06 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"

// class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& ref);
		Form&	operator=(const Form& ref);
		~Form();

		void	beSigned(const Bureaucrat& randy);
		
		class GradeTooLow : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHigh : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& src);

#endif
