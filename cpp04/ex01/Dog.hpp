/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:30:15 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 15:03:47 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <cstring>

class Dog : public Animal{
	public:
		Dog(void);
		Dog(const Dog& ref);
		Dog& operator=(const Dog& ref);
		virtual ~Dog(void);

		virtual void	makeSound(void) const;
		void	PrintIdeas(void) const;
		void	importIdea(int i, std::string idea);

	private:
		Brain*	_brain;
};

#endif