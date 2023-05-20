/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:01:47 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/20 16:59:14 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "Ice.hpp"

class	Cure : public AMateria{
	public:
		Cure();
		Cure(const Cure& ref);
		virtual ~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
		
	private:
		std::string _type;
};

#endif