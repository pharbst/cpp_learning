/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:28:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/20 19:36:21 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

template <typename Container>
class	PmergeMe {
	public:
		sort(char **inputArray);
		PmergeMe();
		~PmergeMe();
	private:
		PmergeMe(const PmergeMe& ref);
		PmergeMe&	operator=(const PmergeMe& ref);
		static	Container	rawData;
};

#endif
