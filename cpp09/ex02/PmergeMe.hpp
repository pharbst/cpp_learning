/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:28:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/30 16:38:30 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

template <typename chainContainer, typename pairContainer>
class PmergeMe {
public:
	void sort(int* input, int elements) {
		pairContainer pairs = mergeSort(getPairs(input, elements));
		createChains(pairs);
		insertionSort();
		for (typename chainContainer::const_iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
			std::cout << it->second << ", ";
		}
		std::cout << std::endl;
	}
	PmergeMe() {}
	~PmergeMe() {}

private:
	PmergeMe(const PmergeMe& ref) {
		(void) ref;
	}
	PmergeMe& operator=(const PmergeMe& ref) {
		(void) ref;
		return *this;
	}

	pairContainer getPairs(int* input, int elements) {
		pairContainer pairs;
		for (int i = 0; i < elements; i += 2) {
			if (i + 1 < elements) {
				if (input[i] > input[i + 1])
					pairs.push_back(std::make_pair(input[i], input[i + 1]));
				else
					pairs.push_back(std::make_pair(input[i + 1], input[i]));
			}
			else if (i < elements)
				pend.push_back(std::make_pair(std::make_pair('b', i), input[i]));
		}
		return pairs;
	}

	pairContainer mergeSort(const pairContainer& array) {
		if (array.size() <= 1) {
			pairContainer merged;
			merged.push_back(array[0]);
			return merged;
		}
		pairContainer subarray1(array.begin(), array.begin() + array.size() / 2);
		pairContainer subarray2(array.begin() + array.size() / 2, array.end());
		pairContainer merged;
		typename pairContainer::const_iterator it1 = subarray1.begin();
		typename pairContainer::const_iterator it2 = subarray2.begin();
		while (it1 != subarray1.end() && it2 != subarray2.end()) {
			if (it1->first < it2->first) {
				merged.push_back(*it1);
				++it1;
			}
			else {
				merged.push_back(*it2);
				++it2;
			}
		}
		while (it1 != subarray1.end()) {
			merged.push_back(*it1);
			++it1;
		}
		while (it2 != subarray2.end()) {
			merged.push_back(*it2);
			++it2;
		}
		return merged;
	}

	void createChains(const pairContainer& pairs) {
		typename pairContainer::const_iterator it = pairs.begin();
		for (int i = 0; it != pairs.end(); ++it, ++i) {
			mainChain.push_back(std::make_pair(std::make_pair('a', i), it->first));
			pend.push_back(std::make_pair(std::make_pair('b', i), it->second));
		}
		typename chainContainer::iterator pendBegin = pend.begin();
		std::advance(pendBegin, 1);
		std::rotate(pend.begin(), pendBegin, pend.end());
	}

	void insertionSort() {
		int j2 = 0;
		int j1 = 0;
		int j = 1;
		while (pend.size() >= 1) {
			insert(j, j1);
			j2 = j1;
			j1 = j;
			j = j1 + 2 * j2;
		}
	}

	void insert(int j, int j1) {
		while (j > j1) {
			std::cout << "debug" << std::endl;
			for (typename chainContainer::iterator it = mainChain.begin(); it != mainChain.end(); ++it) {
				if (it->first.second < pend[j].first.second && it->first.first != 'a') {
					if (it->second > pend[j].second) {
						mainChain.insert(it, pend[j]);
						break;
					}
				}
			}
			--j;
		}
	}

	chainContainer pend;
	chainContainer mainChain;
};

#endif
