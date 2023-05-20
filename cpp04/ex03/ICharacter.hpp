/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:03:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/20 18:06:02 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter();
		virtual const std::string& getName() const = 0;
		virtual AMateria* equip(AMateria* m) = 0;
		virtual AMateria* unequip(int index) = 0;
		virtual void use(int index, ICharacter& target) = 0;
};

#endif