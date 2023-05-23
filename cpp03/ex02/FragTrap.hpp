/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:41:12 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/23 19:03:39 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap{
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap& ref);
		FragTrap& operator = (FragTrap const & ref);
		~FragTrap();

		void attack(void);
		void highFivesGuys(void);
};

#endif