/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:03:47 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/20 17:53:26 by pharbst          ###   ########.fr       */
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
		AMateria* equip(AMateria* m);
		AMateria* unequip(int index);
		void use(int index, ICharacter& target);

	private:
		std::string _name;
		AMateria* _inventory[4];
};

#endif