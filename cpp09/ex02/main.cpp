/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peter <peter@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:52:27 by pharbst           #+#    #+#             */
/*   Updated: 2023/11/24 09:55:25 by peter            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <deque>

int*		ParseInput(char **argv, int elements);
bool		isNumber(char *str);
unsigned long	getTime();
void		timer(int elements, const std::string& container);

int	main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "Error during parsing: make sure to use the right format for parsing ./PmergeMe 1 2 3 4 5 6 without \"\"" << std::endl;
		return 1;
	}

	// parse the shit
	unsigned int	elements = argc - 1;
	int*			input = ParseInput(argv, elements);
	if (!input) {
		std::cout << "Error during parsing: make sure to use the right format for parsing ./PmergeMe 1 2 3 4 5 6 without \"\"" << std::endl;
		return 1;
	}

	// printing statement has to be changed for subject later
	std::cout << std::endl << std::endl;
	std::cout << "before: ";
	for (unsigned int i = 0; i < elements; i++) {
		std::cout << input[i];
		if (elements - 1 != i)
			std::cout << ", ";
	}
	std::cout << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;

	{
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >	VectorMerge;
		std::vector<int>	result = VectorMerge.sort(input, elements);
		std::cout << "after:  ";
		for (std::vector<int>::iterator it = result.begin(); it != result.end(); it++) {
			std::cout << *it;
			if (it + 1 != result.end())
				std::cout << ", ";
			else
				std::cout << std::endl;
		}
	}
	{
		timer(elements, "std[vector]");
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > >	VectorMerge;
		std::vector<int>	result = VectorMerge.sort(input, elements);
		timer(elements, "std[vector]");
	}

	{
		timer(elements, "std[deque]");
		PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > >	DequeMerge;
		DequeMerge.sort(input, elements);
		timer(elements, "std[deque] ");
	}
	delete input;
	return 0;
}

int*	ParseInput(char **argv, int elements) {
	argv++;
	for (int i = 0; argv[i]; i++) {
		if (isNumber(argv[i]))
			return NULL;
	}
	int*		input = new int[elements];
	for (int i = 0; argv[i]; i++) {
		input[i] = std::atoi(argv[i]);
	}
	return input;
}

bool		isNumber(char *str) {
	std::string tmp = str;
	if (tmp.length() == 0)
		return true;
	for (int i = 0; str[i]; i++) {
		if (!std::isdigit(str[i]))
			return true;
	}
	return false;
}

unsigned long	getTime() {
	unsigned long	time;
	timeval		timestamp;

	gettimeofday(&timestamp, NULL);
	time = static_cast<unsigned long>(timestamp.tv_sec) * 1000000 + static_cast<unsigned long>(timestamp.tv_usec);
	return time;
}

void		timer(int elements, const std::string& container) {
	static unsigned long	start = 0;
	if (start == 0)
		start = getTime();
	else {
		unsigned long	end = getTime();
		std::cout << "Time to process a range of " << elements << " elements with " << container << " : " << (end - start) << " us" << std::endl;
		start = 0;
	}
}
