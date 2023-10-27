/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peter <peter@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:52:27 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/27 15:22:37 by peter            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <list>
#include <cstdint>

int*		ParseInput(char **argv, int elements);
bool		isNumber(char *str);
uint64_t	getTime();
void		timer(int elements, const std::string& container);

int	main(int argc, char **argv) {

	if (argc < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}

	// parse the shit
	int		elements = argc - 1;
	timer(elements, "something");
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

	timer(elements, "something");
	// {
	// 	timer();
	// 	PmergeMe<std::vector<int> >	VectorMerge;
	// 	VectorMerge.sort(input);
	// 	timer(elements);
	// }

	// {
	// 	timer();
	// 	PmergeMe<std::list<int> >	ListMerge;
	// 	ListMerge.sort();
	// 	timer(elements);
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

uint64_t	getTime() {
	uint64_t	time;
	timeval		timestamp;

	gettimeofday(&timestamp, NULL);
	time = static_cast<uint64_t>(timestamp.tv_sec) * 1000000 + static_cast<uint64_t>(timestamp.tv_usec);
	return time;
}

void		timer(int elements, const std::string& container) {
	static uint64_t	start = 0;
	if (start == 0)
		start = getTime();
	else {
		static uint64_t	end = getTime();
		std::cout << "Time to process a range of " << elements << " elements with " << container << " : " << (end - start) << " us" << std::endl;
		start = 0;
	}
}
