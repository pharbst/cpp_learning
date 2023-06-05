/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:03:47 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/05 15:20:17 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>

class	Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		virtual ~Character();

		const std::string& getName() const;
		void equip(AMateria* m);
		void unequip(int index);
		void use(int index, ICharacter& target);

	private:
		void	addFloor(AMateria* m);
		void	removeFloor(AMateria* m);
		std::string _name;
		AMateria* _inventory[4];
		AMateria* _floor[20];
};

#endif