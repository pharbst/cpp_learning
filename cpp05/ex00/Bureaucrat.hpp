/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:32:46 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/15 21:13:20 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAt_HPP
# define BUREAUCRAt_HPP

# include <iostream>
# include <fstream>

class Bureaucrat {
	private:
		const std::string _name;
		int			_level;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int level);
		Bureaucrat(Bureaucrat& ref);
		Bureaucrat& operator=(const Bureaucrat& ref);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getLevel() const;
		void				incrementLevel();
		void				decrementLevel();
		void				changeLevel(int i);

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
