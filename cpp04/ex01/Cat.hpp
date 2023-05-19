/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:33:44 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 15:02:27 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <cstring>

class Cat : public Animal{
	public:
		Cat(void);
		Cat(const Cat& ref);
		Cat& operator=(const Cat& ref);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;
		void	PrintIdeas(void) const;

	private:
		Brain*	_brain;
};

#endif