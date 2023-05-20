/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:58:31 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/20 18:41:37 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Cure.hpp"

class ICharacter;

class	Ice : public AMateria{
	public:
		Ice();
		Ice(const Ice& ref);
		virtual ~Ice();
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
