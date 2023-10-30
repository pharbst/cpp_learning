/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:52:27 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/30 16:10:58 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <list>

int*		ParseInput(char **argv, int elements);
bool		isNumber(char *str);
unsigned long	getTime();
void		timer(int elements, const std::string& container);

int	main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	// parse the shit
	int		elements = argc - 1;
	int*	input = ParseInput(argv, elements);
	if (!input)
		return 1;

	// printing statement has to be changed for subject later
	for (int i = 0; i < elements; i++) {
		std::cout << input[i];
		if (elements - 1 != i)
			std::cout << ", ";
	}
	std::cout << std::endl;

	{
		timer(elements, "std[vector]");
		PmergeMe<std::vector<std::pair<std::pair<char, int >, int> >, std::vector<std::pair<int, int> > >	VectorMerge;
		VectorMerge.sort(input, elements);
		timer(elements, "std[vector]");
	}

	// {
	// 	timer(elements, "std[list]");
	// 	PmergeMe<std::list<int>, std::list<std::pair<int, int> > >	ListMerge;
	// 	ListMerge.sort(input, elements);
	// 	timer(elements, "std[list]");
	// }
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
	for (int i = 0; str[i]; i++) {
		if (std::isdigit(str[i]))
			return false;
	}
	return true;
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
		static unsigned long	end = getTime();
		std::cout << "Time to process a range of " << elements << " elements with " << container << " : " << (end - start) << " us" << std::endl;
		start = 0;
	}
}
