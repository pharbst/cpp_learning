/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:01:42 by pharbst           #+#    #+#             */
/*   Updated: 2023/06/05 16:53:57 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>
class AMateria;

class IMateriaSource {
    public:
        virtual ~IMateriaSource();
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif
