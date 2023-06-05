/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:27:28 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/05 16:48:00 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& src);
		MateriaSource & operator=(const MateriaSource& src);
		virtual ~MateriaSource();

		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);
	private:
		AMateria* _materia[4];
};

#endif
