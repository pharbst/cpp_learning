/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:28:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/29 01:38:24 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

template <typename chainContainer, typename pairContainer>
class	PmergeMe {
	public:
		void	sort(int* input, int elements) {
			sortPairs(input, elements);
			
		}
		PmergeMe() {};
		~PmergeMe() {};
	private:
		PmergeMe(const PmergeMe& ref) {};
		PmergeMe&	operator=(const PmergeMe& ref) {};

		void	sortPairs(int* input, int elements) {
			for (int i = 0; i < elements; i += 2)
				if (i + 1 < elements)
					pairs.push_back(std::make_pair(input[i], input[i + 1]))
			
		}

		pairContainer		pairs;
		chainContainer		pend;
		chainContainer		mainChain;
};

int Jacobsthal(int n);

#endif


   // Group numbers in pairs and store them
    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (i + 1 < numbers.size()) {
            numberPairs.emplace_back(numbers[i], numbers[i + 1]);
        }
    }

    // Sort numberPairs by the first element
    // std::sort(numberPairs.begin(), numberPairs.end());
    std::sort(pairs.begin(), pairs.end(),
              [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                  return a.first < b.first;
              });
