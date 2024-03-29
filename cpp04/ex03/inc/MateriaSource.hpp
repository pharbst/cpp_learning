/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:32:35 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/07 17:40:14 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	private:
		AMateria*	_inventory[4];
	public:
		MateriaSource();
		~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);
};

#endif
