/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:49:22 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/07 17:50:27 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string	_type;
	public:
		AMateria(const std::string& type);
		virtual ~AMateria();
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		std::string&	getType();
};

#endif
