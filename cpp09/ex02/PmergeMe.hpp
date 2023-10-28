/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:28:17 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/28 09:06:28 by pharbst          ###   ########.fr       */
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
			if (std::is_sorted(rawData.begin(), rawData.end()))
				return ;
			if (rawData.size() > 8)
				splitSort();
			else
				insertionSort();
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
		void	splitSort() {
			int	size = rawData.size();
			
		}
		Container& split(Container& array) {
			Container	firstSubarray(array.begin(), array.begin() + (array.size() / 2));
			Container	secondSubarray(array.begin() + (array.size() / 2), array.end());
			if (firstSubarray.size() > 8)
				firstSubarray = split(firstSubarray);
			else
				firstSubarray = insertion(firstSubarray);
			if (secondSubarray.size() > 8)
				secondSubarray = split(secondSubarray);
			else
				secondSubarray = insertion(secondSubarray);

			typename Container::iterator	leftIt = firstSubarray.begin();
			typename Container::iterator	rightIt = secondSubarray.begin();
			
			Container	merged;
			while (leftIt != firstSubarray.end() && rightIt != secondSubarray.end()) {
				if (*leftIt < *rightIt) {
					merged.push_back(*leftIt);
					leftIt++;
				}
				else {
					merged.push_back(*rightIt);
					rightIt++;
				}
			}

			while (leftIt != firstSubarray.end()) {
				merged.push_back(*leftIt);
				++leftIt;
			}

			while (rightIt != secondSubarray.end()) {
				merged.push_back(*rightIt);
				++rightIt;
			}
			return merged;
		}
		Container& insertion(Container& subarray) {
			int i = 1;
			while (!std::is_sorted(rawData.begin(), rawData.end())) {
				int key = subarray[i];
				int j = i - 1;
				while (j >= 0 && subarray[j] > key) {
					subarray[j + 1] == subarray[j];
					j--;
				}
				subarray[j + 1] = key;
				i++;
			}
			return subarray;
		}
		void	insertionSort() {
			int i = 1;
			while (!std::is_sorted(rawData.begin(), rawData.end())) {
				int key = *std::next(rawData.begin(), i);
				int j = i - 1;
				while (j >= 0 && rawData[j] > key) {
					rawData[j + 1] = rawData[j];
					j--;
				}
				rawData[j + 1] = key;
				i++;
			}
			return ;
		}
		Container	rawData;
};

#endif
