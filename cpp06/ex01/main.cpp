/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:51:15 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/20 16:02:16 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	int		data[] = {42, 21, 84, 168, 336, 672, 1344, 2688};
	int*	ptr = data;
	std::cout << "Original ptr:     " << ptr << std::endl;
	for (int i = 0; i < 8; i++) {
        std::cout << "Element " << i << ": " << ptr[i] << std::endl;
    }
	Serializer	ser;
	uintptr_t	serialized = ser.serialize(ptr);
	std::cout << "Serialized: " << serialized << std::endl;
	int*	deserialized = reinterpret_cast<int*>(ser.deserialize(serialized));
	std::cout << "Deserialized ptr: " << deserialized << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << "Element " << i << ": " << deserialized[i] << std::endl;
	}
	return 0;
}
