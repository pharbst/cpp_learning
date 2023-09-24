/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:43:16 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/24 17:30:54 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Span.hpp"


int getRandomInt(int min, int max) {

}

int main() {
	//std test case
	{
		Span span(5);

		span.addNumber(3);
		span.addNumber(9);
		span.addNumber(1);
		span.addNumber(7);
		span.addNumber(42);

		for (unsigned int i = 0; i < span.size(); i++) {
			std::cout << span[i];
			if (i < span.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << "3, 9, 1, 7, 42" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// test the addNumbers member function
	{
		Span span(5);
		int moreNumbers[] = {2, 4, 6, 8, 42};

		span.addNumbers(moreNumbers, moreNumbers + 5);

		for (unsigned int i = 0; i < span.size(); i++) {
			std::cout << span[i];
			if (i < span.size() - 1)
				std::cout << ", ";
		}
		std::cout << std::endl << "2, 4, 6, 8, 42" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// test overflow
	{
		try {
			Span span(5);

			span.addNumber(3);
			span.addNumber(9);
			span.addNumber(1);
			span.addNumber(7);
			span.addNumber(42);
			span.addNumber(42); // Should throw FullSpanException
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << "Correct when exception got caught" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	// test if the Span class is able to store 100000 random integer numbers and calculate spans
	{
		try {
			Span span(100000);
			
			for (int i = 0; i < 100000; ++i) {
				span.addNumber(getRandomInt(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()));
			}
			for (unsigned int i = 0; i < span.size(); i++) {
				std::cout << span[i];
				if (i < span.size() - 1)
					std::cout << ", ";
			}
		}
		catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	// try {

	// 	// Try to add more numbers than the maximum allowed
	// 	span.addNumber(10); // Should throw FullSpanException

	// 	// Calculate and display the shortest span
	// 	int shortest = span.shortestSpan();
	// 	std::cout << "Shortest span: " << shortest << std::endl;

	// 	// Calculate and display the longest span
	// 	int longest = span.longestSpan();
	// 	std::cout << "Longest span: " << longest << std::endl;
		
	// 	// Additional test cases
	// 	// Test adding 100,000 integers
	// 	Span largeSpan(100000);
	// 	for (int i = 0; i < 100000; ++i) {
	// 		largeSpan.addNumber(getRandomInt(std::numeric_limits<int>::min(), std::numeric_limits<int>::max()));
	// 	}

	// 	// Try shortestSpan with a Span containing only one number
	// 	Span oneNumberSpan(1);
	// 	oneNumberSpan.addNumber(42);
	// 	oneNumberSpan.shortestSpan(); // Should throw NotEnoughNumbersException

	// 	// Try longestSpan with an empty Span
	// 	Span emptySpan(0);
	//    emptySpan.longestSpan(); // Should throw NotEnoughNumbersException
	// } catch (const std::exception& e) {
	// 	std::cout << "Exception caught: " << e.what() << std::endl;
	// }

	return 0;
}