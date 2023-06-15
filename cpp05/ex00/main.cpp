/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:49:42 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/15 21:01:32 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "expect: Grade too low" << std::endl;
	try {
		Bureaucrat	Herbert("Herbert", 200);
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "expect: Grade too high" << std::endl;
	try {
		Bureaucrat	Herbert("Herbert", 0);
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "expect: Grade too high" << std::endl;
	try {
		Bureaucrat	Herbert("Herbert", -200);
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "expect: Grade too low" << std::endl;
	try {
		Bureaucrat	Herbert("Herbert", 150);
		Herbert.decrementLevel();
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "expect: Grade too high" << std::endl;
	try {
		Bureaucrat	Herbert("Herbert", 1);
		Herbert.incrementLevel();
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "expect: Herbert 70" << std::endl;
	try {
		Bureaucrat	Herbert("Herbert", 50);
		Herbert.changeLevel(-20);
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "expect: Herbert 30" << std::endl;
	try {
		Bureaucrat	Herbert("Herbert", 50);
		Herbert.changeLevel(20);
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "expect: Grade too high" << std::endl;
	try {
		Bureaucrat	Herbert("Herbert", 50);
		Herbert.changeLevel(50);
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "expect: Grade too low" << std::endl;
	try {
		Bureaucrat	Herbert("Herbert", 50);
		Herbert.changeLevel(-101);
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "increment Herbert from lv 50" << std::endl;
	try {
		Bureaucrat Herbert("Herbert", 50);
		std::cout << Herbert << std::endl;
		Herbert.incrementLevel();
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "decrement Herbert from lv 50" << std::endl;
	try {
		Bureaucrat Herbert("Herbert", 50);
		std::cout << Herbert << std::endl;
		Herbert.decrementLevel();
		std::cout << Herbert << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}