/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:27:09 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/11 07:51:56 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Program use:\n\033[0;33m./harlFilter <level>", 0);
	Harl harl;
	harl.complain(argv[1]);
	return (0);
}
