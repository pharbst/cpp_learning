/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:52:27 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/20 20:05:08 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <list>

uint64_t	getTime();
void		timer();
void		parseArray(char **input, std::vector rawData);

int	main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	char	**input = ParseInput(argv);
	int		elements;
	for (int i = 0; input[i]; i++)
		elements++;

	{
		timer();
		PmergeMe<std::vector<int> >	VectorMerge;
		VectorMerge.sort(input);
		timer(elements);
	}

	{
		timer();
		PmergeMe<std::list<int> >	ListMerge;
		ListMerge.sort();
		timer(elements);
	}
}

void	parseArray(char **input, std::vector rawData) {
	char **argv = &input[1];
	for (int i = 0; input[i]; i++) {
		if (!isNumber(input[i]))
			throw invalidNumberException();
	}
	for (int i = 0; input[i]; i++)
		
}

bool		isNumber(char *str) {
	for (int i = 0; str[i]; i++) {
		if (std::isdigit(str[i]))
			return false;
	}
	return true;
}

uint64_t	getTime() {
	uint64_t	time;
	timeval		timestamp;

	gettimeofday(&timestamp, NULL);
	time = static_cast<uint64_t>(timestamp.tv_sec) * 1000000 + static_cast<uint64_t>(timestamp.tv_usec);
	return time;
}

void		timer(int elements, const std::string& container) {
	static uint64_t	start = 0;
	static uint64_t	end = 0;
	if (start == 0)
		start = getTime();
	else {
		end = getTime();
		std::cout << "Tiem to process a range of " << elements << " elements with " << container << " : " << (start - end) << " us"
	}
}
