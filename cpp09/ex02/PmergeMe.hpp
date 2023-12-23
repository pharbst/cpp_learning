/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:28:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/12/23 17:21:57 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>

template <typename chainContainer, typename pairContainer>
class PmergeMe {
public:
	chainContainer sort(int* input, int elements) {
		pairContainer pairs = mergeSort(getPairs(input, elements));
		createChains(pairs, elements);
		insertionSort();
		// std::cout << "comparisons: " << compare << std::endl;
		// std::cout << "expected around: " << elements * log2(elements) << std::endl;
		return mainChain;
	}
	PmergeMe() : compare(0) {}
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
				pend.push_back(input[i]);
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
		subarray1 = mergeSort(subarray1);
		subarray2 = mergeSort(subarray2);
		typename pairContainer::const_iterator it1 = subarray1.begin();
		typename pairContainer::const_iterator it2 = subarray2.begin();
		while (it1 != subarray1.end() && it2 != subarray2.end()) {
			compare++;
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

	void createChains(const pairContainer& pairs, int elements) {
		typename pairContainer::const_iterator it = pairs.begin();
		for (int i = 0; it != pairs.end(); ++it, ++i) {
			mainChain.push_back(it->first);
			pend.push_back(it->second);
		}
		if (pend[0] != 0 && elements % 2 == 1)
		{
			typename chainContainer::iterator pendBegin = pend.begin();
			std::advance(pendBegin, 1);
			std::rotate(pend.begin(), pendBegin, pend.end());
		}
	}

	void insertionSort() {
		unsigned int	j2 = 0;
		unsigned int	j1 = 0;
		unsigned int	j = 1;
		unsigned int	size = pend.size() - 1;
		mainChain.insert(mainChain.begin(), pend[0]);
		while (size >= j) {
			insert(j, j1);
			j2 = j1;
			j1 = j;
			j = j1 + 2 * j2;
		}
		if (j > size)
			insert(size, j1);
	}

	void insert(int j, int j1) {
		int	magicNum = j + j1 + 1;
		while (j > j1) {
			typename chainContainer::iterator chunkStart = mainChain.begin();
			typename chainContainer::iterator chunkEnd = chunkStart + magicNum;
			typename chainContainer::iterator chunkMid = chunkStart + magicNum / 2;
			while (chunkEnd - chunkStart > 1)
			{
				compare++;
				if (pend[j] <= *chunkMid)
					chunkEnd = chunkMid;
				else
					chunkStart = chunkMid;
				chunkMid = chunkStart + (chunkEnd - chunkStart) / 2;
			}
			compare++;
			if (pend[j] <= *chunkMid)
				mainChain.insert(chunkMid, pend[j]);
			else
				mainChain.insert(chunkMid + 1, pend[j]);
			j--;
		}
	}

	int compare;
	chainContainer pend;
	chainContainer mainChain;
};

#endif
