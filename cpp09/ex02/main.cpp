/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:52:27 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/19 10:50:18 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>

uint64_t	getTime();
void		parseArray(char **input, /*array*/);

int	main(int argc, char **argv) {
	uint64_t	start = getTime();

	if (argc < 2) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	try {
		parseArray(argv, /*array*/);
	}
	catch(std::excpetion& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	PmergeMe::vectorSort(/*array*/);
	PmergeMe::listSort(/*array*/);
}

void	parseArray(char **input) {
	char **argv = &input[1];
	for (int i = 0; input[i]; i++) {
		
	}
}

uint64_t	getTime() {
	uint64_t	time;
	timeval		timestamp;

	gettimeofday(&timestamp, NULL);
	time = static_cast<uint64_t>(timestamp.tv_sec) * 1000000 + static_cast<uint64_t>(timestamp.tv_usec);
	return time;
}
