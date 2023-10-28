/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 02:28:42 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/29 01:31:26 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int Jacobsthal(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}
