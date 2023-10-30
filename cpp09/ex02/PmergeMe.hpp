/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:28:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/30 15:57:41 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>

template <typename chainContainer, typename pairContainer>
class	PmergeMe {
	public:
		void	sort(int* input, int elements) {
			pairContainer	pairs = mergeSort(getPairs(input, elements));
			createChains(pairs);
			insertionSort();
			for (unsigned long i = 0; i < mainChain.size(); i++) {
				std::cout << mainChain[i].second << ", ";
			}
			std::cout << std::endl;
		}
		PmergeMe() {};
		~PmergeMe() {};
	private:
		PmergeMe(const PmergeMe& ref) {
			(void) ref;
		};
		PmergeMe&	operator=(const PmergeMe& ref) {
			(void) ref;
		};

		pairContainer&	getPairs(int* input, int elements) {
			pairContainer	pairs;
			for (int i = 0; i < elements; i += 2) {
				if (i + 1 < elements) {
					if (input[i] > input[i + 1])
						pairs.push_back(std::make_pair(input[i], input[i + 1]));
					else
						pairs.push_back(std::make_pair(input[i + 1], input[i]));
				}
				else if (i < elements)
					pend.push_back(std::make_pair(std::make_pair('b', elements), input[i]));
			}
			return pairs;
		}
		pairContainer&	mergeSort(const pairContainer& array) {
			if (array.size() <= 1) {
				pairContainer	merged;
				merged.push_back(array[0]);
				return merged;
			}
			pairContainer	subarray1 = mergeSort(pairContainer(array.begin(), array.begin() + array.size() / 2));
			pairContainer	subarray2 = mergeSort(pairContainer(array.begin() + array.size() / 2 + 1, array.end()));
			pairContainer	merged;
			typename pairContainer::iterator	It1 = subarray1.begin();
			typename pairContainer::iterator	It2 = subarray2.begin();
			while (It1 != subarray1.end() && It2 != subarray2.end()) {
				if (It1.first() < It2.first()) {
					merged.push_back(*It1);
					It1++;
				}
				else {
					merged.push_back(*It2);
					It2++;
				}	
			}
			merged.insert(merged.end(), It1, subarray1.end());
			merged.insert(merged.end(), It2, subarray2.end());
			return merged;
		}
		void	createChains(pairContainer& pairs) {
			for (unsigned long i = 0; i < pairs.size(); i++) {
				mainChain.push_back(std::make_pair(std::make_pair('a', i), pairs[i].first()));
				pend.push_back(std::make_pair(std::make_pair('b', i), pairs[i].second()));
			}
			std::rotate(pend.begin(), pend.begin() + 1, pend.end());
		}
		void	insertionSort() {
			unsigned int	j2 = 0;
			unsigned int	j1 = 0;
			unsigned int	j = 1;
			while (pend.size() >= 1) {
				insert(j, j1);
				j2 = j1;
				j1 = j;
				j = j1 + 2 * j2;
			}
		}
		void	insert(unsigned int j, unsigned int j1) {
			while (j > j1) {
				for (int i = 0; pend[j].first().second() < mainChain[i].first().second() && mainChain[i].first().first() != 'a'; i++) {
					if (mainChain[i].second() > pend[j].second)
						mainChain.insert(mainChain.begin() + i);
				}
				j--;
			}
		}

		chainContainer		pend;
		chainContainer		mainChain;
};

#endif
