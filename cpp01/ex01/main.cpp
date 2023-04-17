/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:27:31 by pharbst           #+#    #+#             */
/*   Updated: 2023/04/17 14:27:49 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*horde = zombieHorde(5, "Horde");
	int		i = 0;

	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return (0);
}
