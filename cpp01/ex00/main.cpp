/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:41:35 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/16 12:19:28 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie* zombie = newZombie("Carl");
	zombie->announce();
	randomChump("Bob");
	delete zombie;
	// zombie->announce();
	return (0);
}