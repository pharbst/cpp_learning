/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:43:16 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/28 02:45:50 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Span.hpp"

int		shortSpan(const std::vector<int>& correctSolution) {
	std::vector<int>	sortedSpan = correctSolution;
	std::sort(sortedSpan.begin(), sortedSpan.end());
	int					ret = sortedSpan[1] - sortedSpan[0];

	for (unsigned long i = 2; i < sortedSpan.size(); i++) {
		if (sortedSpan[i] - sortedSpan[i - 1] < ret)
			ret = sortedSpan[i] - sortedSpan[i - 1];
	}
	return ret;
}

void	compare(const Span& span, const std::vector<int>& correctSolution) {
	if (span.size() != correctSolution.size()) {
			std::cout << "\033[1;31mX \033[0m" << std::endl;
		std::cout << "Wrong: Size mismatch" << std::endl;
		return;
	}

	for (unsigned int i = 0; i < span.size(); i++) {
		if (span[i] != correctSolution[i]) {
			std::cout << "\033[1;31mX \033[0m" << std::endl;
			std::cout << "Wrong: Element mismatch at index " << i << std::endl;
			return;
		}
	}
	std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	//std test case | Test 1
	{
		Span span(5);
		std::vector<int> correctSolution;

		span.addNumber(3);
		span.addNumber(9);
		span.addNumber(1);
		span.addNumber(7);
		span.addNumber(42);
		correctSolution.push_back(3);
		correctSolution.push_back(9);
		correctSolution.push_back(1);
		correctSolution.push_back(7);
		correctSolution.push_back(42);

		std::cout << "Test 1: ";
		compare(span, correctSolution);
	}
	// test the addNumbers member function | Test 2
	{
		Span span(5);
		std::vector<int> correctSolution;
		int moreNumbers[] = {2, 4, 6, 8, 42};

		span.addNumbers(moreNumbers, moreNumbers + 5);
		correctSolution.push_back(2);
		correctSolution.push_back(4);
		correctSolution.push_back(6);
		correctSolution.push_back(8);
		correctSolution.push_back(42);

		std::cout << "Test 2: ";
		compare(span, correctSolution);
	}
	// test overflow | Test 3
	{
		std::cout << "Test 3: ";
		try {
			Span span(5);

			span.addNumber(3);
			span.addNumber(9);
			span.addNumber(1);
			span.addNumber(7);
			span.addNumber(42);
			span.addNumber(42);
			std::cout << "\033[1;31mX \033[0m" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			std::cout << "\033[0;32mException: " << e.what() << "\033[0m" << std::endl;
		}
	}
	// test if the Span class is able to store 100000 random integer numbers | Test 4
	{
		std::cout << "Test 4: ";
		try {
			Span				span(100000);
			int					randomNumber;
			std::vector<int>	correctSolution;

			for (int i = 0; i < 100000; i++) {
				randomNumber = std::rand();
				span.addNumber(randomNumber);
				correctSolution.push_back(randomNumber);
			}
			std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "\033[1;31mX \033[0m" << std::endl;
			std::cout << std::endl << "Exception: " << e.what() << std::endl;
		}
	}
	// test if span calculation is correct | Test 5
	{
		try {
			Span				span(10);
			std::vector<int>	correctSolution;
			int					randomNumber;
			int					minSpan;

			for (int i = 0; i < 10; i++) {
				randomNumber = std::rand();
				span.addNumber(randomNumber);
				correctSolution.push_back(randomNumber);
			}
			minSpan = span.shortestSpan();
			if (minSpan == shortSpan(correctSolution)) {
				std::cout << "Test 5: ";
				std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			}
			else {
				std::cout << "Test 5: \033[1;31mX \033[0m" << std::endl;
				std::cout << "Wrong: Span mismatch: result of span = " << minSpan << " result of vector = " << shortSpan(correctSolution) << std::endl;
			}
		}
		catch (const std::exception& e) {
			std::cout << "Test 5: \033[1;31mX \033[0m" << std::endl;
			std::cout << std::endl << "Exception: " << e.what() << std::endl;
		}
	}
	// test if span calculation is correct | Test 6
	{
		try {
			Span				span(10);
			std::vector<int>	correctSolution;
			int					randomNumber;
			int					maxSpan;

			for (int i = 0; i < 10; i++) {
				randomNumber = std::rand();
				span.addNumber(randomNumber);
				correctSolution.push_back(randomNumber);
			}
			maxSpan = span.longestSpan();
			if (maxSpan == (*std::max_element(correctSolution.begin(), correctSolution.end()) - *std::min_element(correctSolution.begin(), correctSolution.end()))) {
				std::cout << "Test 6: ";
				std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			}
			else
				std::cout << "Test 6: \033[1;31mX \033[0m" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "Test 6: \033[1;31mX \033[0m" << std::endl;
			std::cout << std::endl << "Exception: " << e.what() << std::endl;
		}
	}
	// test span exception | Test 7
	{
		Span span(5);

		std::cout << "Test 7: ";
		try {
			span.shortestSpan();
			std::cout << "\033[1;31mX \033[0m" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			std::cout << "\033[0;32mException: " << e.what() << "\033[0m" << std::endl;
		}
	}
	// test span exception | Test 8
	{
		Span span(5);

		std::cout << "Test 8: ";

		try {
			span.longestSpan();
			std::cout << "\033[1;31mX \033[0m" << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			std::cout << "\033[0;32mException: " << e.what() << "\033[0m" << std::endl;
		}
	}
	// test span exception | Test 9
	{
		try {
			Span span(5);

			std::cout << "Test 9: ";

			span.addNumber(3);
			span.shortestSpan();
			std::cout << "\033[1;31mX \033[0m" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			std::cout << "\033[0;32mException: " << e.what() << "\033[0m" << std::endl;
		}
	}
	// test span exception | Test 10
	{
		try {
			Span span(5);

			std::cout << "Test 10: ";

			span.addNumber(3);
			span.longestSpan();
			std::cout << "\033[1;31mX \033[0m" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			std::cout << "\033[0;32mException: " << e.what() << "\033[0m" << std::endl;
		}
	}
	// test span with 2 numbers | Test 11
	{
		try {
			Span span(5);

			std::cout << "Test 11: ";

			span.addNumber(3);
			span.addNumber(9);

			if (span.shortestSpan() == 6 && span.longestSpan() == 6)
				std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			else
				std::cout << "\033[1;31mX \033[0m" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "\033[1;31mX \033[0m" << std::endl;
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	// test if span calculation is done the correct way | Test 12
	{
		try {
			Span span(10);
			std::vector<int> correctSolution;
			
			std::cout << "Test 12: ";

			span.addNumber(3);
			span.addNumber(9);
			span.addNumber(1);
			span.addNumber(7);
			span.addNumber(42);
			correctSolution.push_back(3);
			correctSolution.push_back(9);
			correctSolution.push_back(1);
			correctSolution.push_back(7);
			correctSolution.push_back(42);

			if (span.shortestSpan() == shortSpan(correctSolution) && span.longestSpan() == (*std::max_element(correctSolution.begin(), correctSolution.end()) - *std::min_element(correctSolution.begin(), correctSolution.end())))
				std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			else
				std::cout << "\033[1;31mX \033[0m" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "\033[1;31mX \033[0m" << std::endl;
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	// test if size function works | Test 13
	{
		try {
			Span span(10);
			std::vector<int> correctSolution;
			
			std::cout << "Test 13: ";

			span.addNumber(3);
			span.addNumber(9);
			span.addNumber(1);
			span.addNumber(7);
			span.addNumber(42);
			correctSolution.push_back(3);
			correctSolution.push_back(9);
			correctSolution.push_back(1);
			correctSolution.push_back(7);
			correctSolution.push_back(42);

			if (span.size() == correctSolution.size())
				std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			else
				std::cout << "\033[1;31mX \033[0m" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "\033[1;31mX \033[0m" << std::endl;
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	// test with huge amount of numbers | Test 14
	{
		try {
			Span span(100000);
			std::vector<int> correctSolution;
			int randomNumber;

			std::cout << "Test 14: ";

			for (unsigned int i = 0; i < 24586; i++) {
				randomNumber = std::rand();
				span.addNumber(randomNumber);
				correctSolution.push_back(randomNumber);
			}
			if (span.size() == correctSolution.size() && span.shortestSpan() == shortSpan(correctSolution) && span.longestSpan() == (*std::max_element(correctSolution.begin(), correctSolution.end()) - *std::min_element(correctSolution.begin(), correctSolution.end())))
				std::cout << "\033[1;32m\xE2\x9C\x94\033[0m" << std::endl;
			else {
				std::cout << "\033[1;31mX \033[0m" << std::endl;
			}
		}
		catch (std::exception& e) {
			std::cout << "\033[1;31mX \033[0m" << std::endl;
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	return 0;
}