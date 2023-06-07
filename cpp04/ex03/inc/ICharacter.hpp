/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:49:22 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/07 17:00:52 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class ICharacter {
	public:
		virtual	~ICharacter() {}
		virtual	const std::string&	getName() const = 0;
		virtual	void				equip(AMateria* m) = 0;
		virtual	void				unequip(int inx) = 0;
		virtual	void				use(int idx, ICharacter& target) = 0;
};

#endif
