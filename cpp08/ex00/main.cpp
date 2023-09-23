/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:41:10 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/23 18:52:35 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stdexcept>
#include "Easyfind.hpp"

int main() {
    try {
        // Test with a vector of integers
        std::vector<int> vecInt;
        vecInt.push_back(10);
        vecInt.push_back(20);
        vecInt.push_back(30);
        vecInt.push_back(40);
        vecInt.push_back(50);

        int target1 = 30;
        int target2 = 60; // Value not in the container

        unsigned long index1 = easyfind(vecInt, target1);
        std::cout << "Target " << target1 << " found in vecInt at index: " << index1 << std::endl;

        unsigned long index2 = easyfind(vecInt, target2); // Should throw an exception
        std::cout << "Target " << target2 << " found in vecInt at index: " << index2 << std::endl;

    } catch (const TargetNotFoundException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Test with a list of strings
        std::list<std::string> listStr;
        listStr.push_back("apple");
        listStr.push_back("banana");
        listStr.push_back("cherry");
        listStr.push_back("date");

        std::string target3 = "banana";
        std::string target4 = "grape"; // Value not in the container

        unsigned long index3 = easyfind(listStr, target3);
        std::cout << "Target " << target3 << " found in listStr at index: " << index3 << std::endl;

        unsigned long index4 = easyfind(listStr, target4); // Should throw an exception
        std::cout << "Target " << target4 << " found in listStr at index: " << index4 << std::endl;

    } catch (const TargetNotFoundException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Add more tests with different container types and sizes as needed

    return 0;
}

