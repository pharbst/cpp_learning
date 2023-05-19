/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:33:44 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 16:53:31 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat(void);
		Cat(Cat const &old);
		Cat& operator=(const Cat& old);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;
};

#endif