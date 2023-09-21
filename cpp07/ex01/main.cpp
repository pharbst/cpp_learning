/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:10:54 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/21 17:16:21 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Iter.hpp"

void	print(std::string str) {
	std::cout << str << std::endl;
}

int main(void) {
	std::string array[5] = {"Hello", "World", "!", "How", "are you?"};
	iter(array, 5, print);
	return 0;
}
