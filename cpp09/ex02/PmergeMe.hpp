/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:28:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/27 17:50:10 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

template <typename Container>
class	PmergeMe {
	public:
		void	sort(int* input, int elements) {
			putInContainer(input, elements);
		}
		PmergeMe() {};
		~PmergeMe() {};
	private:
		PmergeMe(const PmergeMe& ref) {};
		PmergeMe&	operator=(const PmergeMe& ref) {};
		void	putInContainer(int* input, int elements) {
			for (int i = 0; i < elements; i++) {
				rawData.push_back(input[i]);
			}
		}
		Container	rawData;
};

#endif
