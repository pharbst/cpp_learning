/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:14:42 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/15 01:23:52 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>

class	RPN {
	private:
		static std::stack<double>	_stack;
		static bool	isOperator(std::string token);

		class InvalidExpressionException : public std::exception {
			virtual const char* what() const throw();
		};
		class DivisionByZeroException : public std::exception {
			virtual const char* what() const throw();
		};
		class StackNotEmptyException : public std::exception {
			virtual const char* what() const throw();
		};

		RPN();
		RPN(RPN const &src);
		RPN &operator=(RPN const &src);
		~RPN();
	public:
		static int		calculate(std::string str);
};

#endif