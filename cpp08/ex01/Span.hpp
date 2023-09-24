/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:13:08 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/24 17:10:43 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class	Span {
	private:
		unsigned int		_size;
		std::vector<int>	_span;
	public:
		Span();
		Span(unsigned int);
		Span(const Span& ref);
		Span&	operator=(const Span& ref);
		~Span();

		int				operator[](unsigned int index);

		unsigned int	size() const;
		void			addNumber(int add);
		int				shortestSpan();
		int				longestSpan();

		template <typename InputIterator>
		void addNumbers(InputIterator start, InputIterator end) {
			while (start != end)
				addNumber(*(start++));
		}

		class FullSpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
