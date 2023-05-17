/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:16:54 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 08:52:47 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & ref);
		ClapTrap& operator = (ClapTrap const & ref);
		~ClapTrap();
		
		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void gainEnergy(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHitpoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		unsigned int	getRepairStrength(void) const;
		
	private:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		unsigned int	_maxHitpoints;
		unsigned int	_repairStrength;
};

std::ostream& operator << (std::ostream& out, ClapTrap const & ref);

#endif